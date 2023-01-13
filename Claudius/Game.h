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
	void CheckCollisions();
	
	
	void UpdatePlayerMovement(SDL_Keycode key) noexcept;

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

	void QueueGameObjectsForRendering(RenderManager& render_manager);
};