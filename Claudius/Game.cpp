
#include "Game.h"
#include "RenderManager.h"

Game::Game() noexcept :
	window_config({ 1250, 700, "Snake"}),
	apple(),
	player()

{

}

void Game::Enter() {

	
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

void Game::CheckCollisions() noexcept
{


	if (PlayerIsSelfColliding() || PlayerIsOutOfBounds())
		player.ResetPlayer();


	if (PlayerIsEatingApple())
	{
		player.AddSnakePart(Player::SNAKE_PART_TYPE::NEW_PART);
		apple.SetRandomPosition(SDL_Point(window_config.width, window_config.height));
	}


}

bool Game::PlayerIsSelfColliding() noexcept {

	const SDL_Point player_head_pos = player.GetSnakeHeadPosition();
	
	for (const SDL_Point pos : player.GetSnakeBodyPositions() | std::views::drop(2))
	{

		if (pos.x == player_head_pos.x && pos.y == player_head_pos.y)
			return true;
		
	}

	return false;

}

bool Game::PlayerIsOutOfBounds() noexcept {

	const SDL_Point player_head_pos = player.GetSnakeHeadPosition();


	if (player_head_pos.x > window_config.width || player_head_pos.x < 0 ||
		player_head_pos.y > window_config.height || player_head_pos.y < 0)
	{
		return true;
	}

	return false;

}

bool Game::PlayerIsEatingApple() noexcept {

	const SDL_Point snake_head_pos = player.GetSnakeHeadPosition();
	const SDL_Point apple_pos = apple.GetPosition();

	if (snake_head_pos.x == apple_pos.x && snake_head_pos.y == apple_pos.y)
		return true;
	
	return false;

}

void Game::QueueGameObjectsForRendering( RenderManager& render_manager) noexcept
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


