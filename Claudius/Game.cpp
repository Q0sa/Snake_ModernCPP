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
	RenderManager render_manager { };
	
	running = true;


	while (running)
	{
		SDL_Event event = {};
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{

			case SDL_KEYDOWN: UpdatePlayerMovement(event.key.keysym.sym);
				break;

			case SDL_QUIT:
				SDL_Quit();
				running = false;
				break;


			default: break;
			}
		}

		//CheckCollisions();
		QueueGameObjectsForRendering(render_manager);

		render_manager.RenderCurrentFrame(renderer);
		render_manager.ClearRenderQueue();


		SDL_Delay(1000 / 20);
	}

	

}

void Game::CheckCollisions()
{

	//player.Update();
	

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


}

void Game::QueueGameObjectsForRendering( RenderManager& render_manager)
{
	player.QueueSnakeForRendering(render_manager);
	apple.QueueAppleForRendering(render_manager);
}


void Game::UpdatePlayerMovement(SDL_Keycode key) noexcept
{
	player.InputToMovement(key);
}


