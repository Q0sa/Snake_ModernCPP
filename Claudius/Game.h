#pragma once

#include "Renderer.h"
#include "Apple.h"
#include "Player.h"


class Game
{

public:

	void Enter();

private:

	Player player{};
	Apple apple{};

	bool running = false;

	void CheckCollisions() noexcept;
	
	void UpdatePlayerInput(SDL_Keycode key) noexcept;
	void InputEventCheck() noexcept;
	void QueueGameObjectsForRendering(Renderer& render_manager) noexcept;
	 
	bool PlayerIsSelfColliding() noexcept;
	bool PlayerIsOutOfBounds() noexcept;
	bool PlayerIsEatingApple() noexcept;
};