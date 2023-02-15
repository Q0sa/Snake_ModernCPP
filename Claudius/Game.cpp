#pragma once

#include <ranges>
#include "SDL.h"
#include "Game.h"
#include "Window.h" // look into removing this
#include "Renderer.h"


void Game::Enter() {

	SDL_Init(SDL_INIT_EVERYTHING);

	Run();

}

void Game::Run() {

	while (running)
	{

		InputEventCheck();

		player.Movement();  

		CheckCollisions();  

		Render();

	}

	SDL_Quit();

}

void Game::CheckCollisions() noexcept
{


	if (PlayerIsSelfColliding() || PlayerIsOutOfBounds())
		player.ResetPlayer();


	if (PlayerIsEatingApple())
	{
		player.AddSnakePart(Player::SNAKE_PART_TYPE::NEW_PART);
		apple.SetRandomPosition(_DIMENSIONS);
	}


}

bool Game::PlayerIsSelfColliding() noexcept { //MOVE TO SNAKE

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


	if (player_head_pos.x > _DIMENSIONS.x || player_head_pos.x < 0 ||
		player_head_pos.y > _DIMENSIONS.y || player_head_pos.y < 0)
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

void Game::Render() noexcept
{
	player.Render(renderer);
	apple.Render(renderer);

	renderer.Present();
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


