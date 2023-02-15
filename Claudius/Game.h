#pragma once

#include "Apple.h"
#include "Player.h"


class Game
{

public:

	void Enter();

private:

	Player player{};
	Apple apple{};

	Window window{ _TITLE, _DIMENSIONS.x, _DIMENSIONS.y };
	Renderer renderer{ window };

	bool running = true;

	void Run();
	void CheckCollisions() noexcept;
	
	void UpdatePlayerInput(SDL_Keycode key) noexcept;
	void InputCheck() noexcept;
	void Render() noexcept;
	 
	bool PlayerIsOutOfBounds() const noexcept;
	bool PlayerIsEatingApple() noexcept;
};