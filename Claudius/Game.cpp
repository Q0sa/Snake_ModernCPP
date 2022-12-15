// 2019-12-05 Teemu Laiho

#include "Game.h"
#include "RenderManager.h"
#include <iostream>

Game::Game() : 
	windowConfig({ 1250, 700, "Snake"}),
	appleObj(),
	playerObj()
{

}


void Game::Update()
{

	playerObj.Update();

	for (int i = 0; i < playerObj.player_score; i++)
	{
		if (playerObj.trans.GetPosition() == playerObj.parts[i].trans.GetPosition())
		{
			playerObj.ResetPlayer();
		}
	}

	if (playerObj.trans.GetX() > windowConfig.width || playerObj.trans.GetX() < 0)
	{
		playerObj.ResetPlayer();
	}

	if (playerObj.trans.GetY() > windowConfig.height || playerObj.trans.GetY() < 0)
	{
		playerObj.ResetPlayer();
	}

	if (playerObj.trans.GetPosition() == appleObj.GetPosition())
	{
		playerObj.player_score++;
		appleObj.SetRandomPosition();
	}

	QueueGameObjectsForRendering();

}

void Game::QueueGameObjectsForRendering()
{
	playerObj.QueueSnakeForRendering(renderManager);
	appleObj.QueueAppleForRendering(renderManager);
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
	playerObj.InputToMovementDirection(key);
}


