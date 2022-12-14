#pragma once

#include <string>
#include <vector>
#include "Apple.h"
#include "Player.h"
#include "RenderManager.h"


class Game
{

public:
	
	struct WindowConfig {
		int width = {};
		int height = {};
		const char* title = {};
	};



	Game();
	~Game();

	void Update();
	
	void ClearRenderManager();

	int GetGameWidth();
	int GetGameHeight();
	const char* GetGameTitle();

	std::vector<RenderManager::RenderEntry> GetRenderQueue();

	void PassInputToPlayer(SDL_Keycode key);

private:

	WindowConfig windowConfig = {};

	Player playerOne = {};
	Apple apple = {};

	RenderManager renderManager = {};

	void QueueGameObjectsForRendering();
};