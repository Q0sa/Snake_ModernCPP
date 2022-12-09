#pragma once

#include <string>
#include <vector>
#include "KeyCode.h"
#include "Apple.h"
#include "Player.h"


struct RenderManager;
struct ResourceManager;

class Game
{
	Player playerOne;
	Apple apple;


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
	void Render(RenderManager& rendererManager);
	void OnKeyDown(KeyCode key);
};