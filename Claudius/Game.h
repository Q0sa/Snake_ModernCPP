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
	
	void InputCheck() noexcept;
	void Render() const noexcept;
	 
	bool IsOutOfBounds(const SDL_Point& in_pos) const noexcept;
	bool PlayerIsEatingApple() const noexcept;
};