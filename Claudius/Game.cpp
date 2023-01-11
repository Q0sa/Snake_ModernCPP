// 2019-12-05 Teemu Laiho

#include "Game.h"
#include "RenderManager.h"
#include <iostream>

Game::Game() noexcept :
	window_config({ 1250, 700, "Snake"}),
	apple(),
	player()

{

}

void Game::Enter() {

	srand(time(nullptr));


	SDL_Init(SDL_INIT_EVERYTHING);

	Window window{ window_config.title, window_config.width, window_config.height };
	Renderer renderer { window };
	
	running = true;


	while (running)
	{
		SDL_Event event = {};
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{

			case SDL_KEYDOWN: PassInputToPlayer(event.key.keysym.sym);
				break;

			case SDL_QUIT:
				SDL_Quit();
				running = false;
				break;


			default: break;
			}
		}

		Update();

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		for (auto&& entry : GetRenderQueue())
		{
			SDL_SetRenderDrawColor(renderer, entry.color.r, entry.color.g, entry.color.b, entry.color.a);
			SDL_Rect rect{ static_cast<int>(entry.trans.position.x),
						   static_cast<int>(entry.trans.position.y),
						   entry.rect.w,
						   entry.rect.h };

			SDL_RenderFillRect(renderer, &rect);
		}
		SDL_RenderPresent(renderer);

		ClearRenderManager();

		SDL_Delay(1000 / 20);
	}

	

}

void Game::Update()
{

	player.Update();
	

	for (int i = 0; i < player.GetSnakeSize(); i++)
	{
		if (player.GetSnakeHeadPosition() == player.GetSnakePartPostion(i))
		{
			player.ResetPlayer();
		}
	}

	if (player.GetSnakeHeadPosition().x > window_config.width || player.GetSnakeHeadPosition().x < 0)
	{
		player.ResetPlayer();
	}

	if (player.GetSnakeHeadPosition().y > window_config.height || player.GetSnakeHeadPosition().y < 0)
	{
		player.ResetPlayer();
	}

	if (player.GetSnakeHeadPosition() == apple.GetPosition())
	{
		player.AddSnakePart(Player::SNAKE_PART_TYPE::NEW_PART);
		apple.SetRandomPosition();
	}

	QueueGameObjectsForRendering();

}

void Game::QueueGameObjectsForRendering()
{
	player.QueueSnakeForRendering(render_manager);
	apple.QueueAppleForRendering(render_manager);
}

void Game::ClearRenderManager() noexcept {

	render_manager.ClearRenderQueue();

}

std::vector<RenderManager::RenderEntry> Game::GetRenderQueue()
{
	return render_manager.render_queue;
}






void Game::PassInputToPlayer(SDL_Keycode key) noexcept
{
	player.InputToMovementDirection(key);
}


