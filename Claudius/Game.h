#pragma once

#include <string>
#include <vector>
#include "Apple.h"
#include "Player.h"
#include "RenderManager.h"

//struct RenderManager;

class Game
{

public:
	//Teemu Code Begin.

	// float timer; <- can be used in delta time
	// float updateInterval; <- check Game.h

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