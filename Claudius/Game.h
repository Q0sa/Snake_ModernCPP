#pragma once

#include "Renderer.h"
#include "Apple.h"
#include "Player.h"
#include "Renderer.h"


class Game
{

public:

	Game() noexcept;

	void Enter();

private:

	struct WindowConfig {
	    int width = 0;
	    int height = 0;
		std::string_view title{};
	};

	WindowConfig window_config{};

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