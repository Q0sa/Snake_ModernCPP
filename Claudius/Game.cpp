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

		InputEventCheck();

		player.Movement();

		CheckCollisions();
		QueueGameObjectsForRendering(render_manager);

		render_manager.RenderCurrentFrame(renderer);
		render_manager.ClearRenderQueue();


		SDL_Delay(1000 / 20);
	}

	

}

void Game::CheckCollisions()
{


	if (PlayerIsSelfColliding() || PlayerIsOutOfBounds())
		player.ResetPlayer();


	if (PlayerIsEatingApple())
	{
		player.AddSnakePart(Player::SNAKE_PART_TYPE::NEW_PART);
		apple.SetRandomPosition(Vector2(window_config.width, window_config.height));
	}


}

bool Game::PlayerIsSelfColliding() noexcept {

	for (const Vector2 pos : player.GetSnakeBodyPositions() | std::views::drop(2))
	{

		if (pos == player.GetSnakeHeadPosition()) 
			return true;

	}

	return false;

}

bool Game::PlayerIsOutOfBounds() noexcept {

	const Vector2 player_head_pos = player.GetSnakeHeadPosition();

	if (player_head_pos.x > window_config.width || player_head_pos.x < 0 ||
		player_head_pos.y > window_config.height || player_head_pos.y < 0)
	{
		return true;
	}

	return false;

}

bool Game::PlayerIsEatingApple() noexcept {

	if (player.GetSnakeHeadPosition() == apple.GetPosition())
		return true;
	
	return false;

}

void Game::QueueGameObjectsForRendering( RenderManager& render_manager)
{
	player.QueueSnakeForRendering(render_manager);
	apple.QueueAppleForRendering(render_manager);
}

void Game::InputEventCheck() noexcept {

	SDL_Event event = {};
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{

		case SDL_KEYDOWN: player.HandleInput(event.key.keysym.sym);
			break;

		case SDL_QUIT:
			SDL_Quit();
			running = false;
			break;


		default: break;
		}
	}

}


