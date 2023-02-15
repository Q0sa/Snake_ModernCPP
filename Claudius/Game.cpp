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

		InputCheck();

		player.Movement();  

		CheckCollisions();  

		Render();

	}

	SDL_Quit();

}

void Game::CheckCollisions() noexcept
{

	if (player.PlayerIsSelfColliding() || PlayerIsOutOfBounds())
		player.ResetPlayer();


	if (PlayerIsEatingApple())
	{
		player.AddSnakePart(Player::SNAKE_PART_TYPE::NEW_PART);
		apple.SetRandomPosition(_DIMENSIONS);
	}


}



bool Game::PlayerIsOutOfBounds() const noexcept {

	const SDL_Point head_pos = player.GetHead();

	if (head_pos.x > _DIMENSIONS.x || head_pos.x < 0 ||
		head_pos.y > _DIMENSIONS.y || head_pos.y < 0)
		return true;
	
	return false;

}

bool Game::PlayerIsEatingApple() noexcept {

	if (player.GetHead() == apple.GetPosition() )
		return true;
	
	return false;

}

void Game::Render() noexcept
{
	player.Render(renderer);
	apple.Render(renderer);

	renderer.Present();
}

void Game::InputCheck() noexcept {

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


