#pragma once

#include <string>
#include <vector>
#include "SDL.h"
#include "Window.h"
#include "Renderer.h"
#include "Apple.h"
#include "Player.h"
#include "RenderManager.h"


class Game
{

public:

	Game() noexcept;

	void Enter();

private:

	struct WindowConfig {
	    int width = {};
	    int height = {};
		std::string_view title = {};
	};

	WindowConfig window_config = {};

	Player player = {};
	Apple apple = {};

	bool running = {};

	void CheckCollisions() noexcept;
	
	void UpdatePlayerInput(SDL_Keycode key) noexcept;
	void InputEventCheck() noexcept;
	void QueueGameObjectsForRendering(RenderManager& render_manager) noexcept;
	 
	bool PlayerIsSelfColliding() noexcept;
	bool PlayerIsOutOfBounds() noexcept;
	bool PlayerIsEatingApple() noexcept;
};