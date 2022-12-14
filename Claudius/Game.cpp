// 2019-12-05 Teemu Laiho

#include "Game.h"
#include "RenderManager.h"
#include <iostream>

Game::Game() : windowConfig({ 1250, 700, "Snake"})
{
	playerOne.Initialize();
	apple.Initialize(10, 10);
}

Game::~Game()
{
}


void Game::Update()
{
	

	playerOne.Update();

	for (int i = 0; i < playerOne.player_score; i++)
	{
		if (playerOne.trans.GetPosition() == playerOne.parts[i].trans.GetPosition())
		{
			playerOne.ResetPlayer();
		}
	}

	if (playerOne.trans.GetX() > windowConfig.width || playerOne.trans.GetX() < 0)
	{
		playerOne.ResetPlayer();
	}

	if (playerOne.trans.GetY() > windowConfig.height || playerOne.trans.GetY() < 0)
	{
		playerOne.ResetPlayer();
	}

	if (playerOne.trans.GetPosition() == apple.trans.GetPosition())
	{
		playerOne.player_score++;
		apple.trans.SetPosition((rand() % 125) * 10.0f, (rand() % 70) * 10.0f);
	}

	QueueGameObjectsForRendering();

}


void Game::QueueGameObjectsForRendering()
{
	playerOne.QueueSnakeForRendering(renderManager);
	apple.QueueAppleForRendering(renderManager);
}

void Game::ClearRenderManager() {

	renderManager.ClearRenderQueue();

}

std::vector<RenderManager::RenderEntry> Game::GetRenderQueue()
{
	return renderManager.renderQueue;
}

int Game::GetGameHeight() {

	return windowConfig.height;

}

int Game::GetGameWidth() {

	return windowConfig.width;

}

const char* Game::GetGameTitle() {

	return windowConfig.title;

}


void Game::PassInputToPlayer(SDL_Keycode key)
{
	playerOne.InputToMovementDirection(key);
}


