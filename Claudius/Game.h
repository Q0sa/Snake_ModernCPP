#pragma once

#include <string>
#include <vector>
#include "KeyCode.h"
#include "Apple.h"
#include "Player.h"
#include "RenderManager.h"

//struct RenderManager;

class Game
{
	Player playerOne;
	Apple apple;

	RenderManager renderManager = {};

	void QueueGameObjectsForRendering();
public:
	//Teemu Code Begin.

	// float timer; <- can be used in delta time
	// float updateInterval; <- check Game.h

	int width;
	int height;

	Game();
	~Game();

	bool Enter(int& width, int& height, std::string& title);
	void Update();
	
	void ClearRenderManager();

	std::vector<RenderManager::RenderEntry> GetRenderQueue();

	void OnKeyDown(KeyCode key);
};