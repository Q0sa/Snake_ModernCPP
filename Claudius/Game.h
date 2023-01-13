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
		unsigned int width = {};
		unsigned int height = {};
		std::string_view title = {};
	};

	WindowConfig window_config = {};

	Player player = {};
	Apple apple = {};

	bool running = {};

	void CheckCollisions();
	
	void UpdatePlayerInput(SDL_Keycode key) noexcept;
	void InputEventCheck();
	void QueueGameObjectsForRendering(RenderManager& render_manager);
};