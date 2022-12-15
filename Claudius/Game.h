#pragma once

#include <string>
#include <vector>
#include "Apple.h"
#include "Player.h"
#include "RenderManager.h"


class Game
{

public:

	Game();

	void Update();
	
	int GetGameWidth();
	int GetGameHeight();
	const char* GetGameTitle();

	void ClearRenderManager();
	void PassInputToPlayer(SDL_Keycode key);

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