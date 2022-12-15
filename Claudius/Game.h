#pragma once

#include <string>
#include <vector>
#include "Apple.h"
#include "Player.h"
#include "RenderManager.h"


class Game
{

public:

	Game() noexcept;

	void Update();
	
	int GetGameWidth() noexcept;
	int GetGameHeight() noexcept;
	const char* GetGameTitle() noexcept;

	void ClearRenderManager() noexcept;
	void PassInputToPlayer(SDL_Keycode key) noexcept;

	std::vector<RenderManager::RenderEntry> GetRenderQueue();

private:

	struct WindowConfig {
		int width = {};
		int height = {};
		const char* title = {};
	};

	WindowConfig windowConfig = {};

	Player player_obj = {};
	Apple apple_obj = {};

	RenderManager render_manager = {};

	void QueueGameObjectsForRendering();
};