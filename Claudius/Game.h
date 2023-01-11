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
	void Update();
	
	
	void ClearRenderManager() noexcept;
	void PassInputToPlayer(SDL_Keycode key) noexcept;



	std::vector<RenderManager::RenderEntry> GetRenderQueue();

private:

	struct WindowConfig {
		int width = {};
		int height = {};
		std::string_view title = {};
	};

	WindowConfig window_config = {};

	Player player = {};
	Apple apple = {};

	RenderManager render_manager = {};

	bool running = {};


	void QueueGameObjectsForRendering();
};