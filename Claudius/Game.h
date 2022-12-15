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
	
	void ClearRenderManager();

	int GetGameWidth();
	int GetGameHeight();
	const char* GetGameTitle();

	std::vector<RenderManager::RenderEntry> GetRenderQueue();

	void PassInputToPlayer(SDL_Keycode key);

private:

	struct WindowConfig {
		int width = {};
		int height = {};
		const char* title = {};
	};

	WindowConfig windowConfig = {};

	Player playerObj = {};
	Apple appleObj = {};

	RenderManager renderManager = {};

	void QueueGameObjectsForRendering();
};