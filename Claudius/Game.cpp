#pragma once

#include "Game.h"

void Game::Enter() {

	SDL_Init(SDL_INIT_EVERYTHING);

	Run();

}

void Game::Run() {

	while (running){

		InputCheck();

		player.Move();  

		CheckCollisions();  

		Render();

	}

	SDL_Quit();

}

void Game::CheckCollisions() noexcept
{

	if (player.IsSelfColliding() || IsOutOfBounds(player.GetHead()))
		player = Player();

	if (PlayerIsEatingApple())
	{
		player.AddSnakePart();
		apple.SetRandomPosition(_DIMENSIONS);
	}

}



bool Game::IsOutOfBounds(const Vector2Int& in_pos) const noexcept {

	return (in_pos.x > _DIMENSIONS.x || in_pos.x < 0 ||
			in_pos.y > _DIMENSIONS.y || in_pos.y < 0);

}


bool Game::PlayerIsEatingApple() const noexcept {

	return player.GetHead() == apple.GetPosition();

}

void Game::Render() const noexcept
{
	player.Render(renderer);
	apple.Render(renderer);

	renderer.Present();
}

void Game::InputCheck() noexcept {

	SDL_Event event = {};
	while (SDL_PollEvent(&event))
	{
		switch (event.type){

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


