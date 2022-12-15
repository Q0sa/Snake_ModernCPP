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
	

	for (int i = 0; i < playerObj.GetSnakeSize(); i++)
	{
		if (playerObj.GetSnakeHeadPosition() == playerObj.GetSnakePartPostion(i))
		{
			playerObj.ResetPlayer();
		}
	}

	if (playerObj.GetSnakeHeadPosition().x > windowConfig.width || playerObj.GetSnakeHeadPosition().x < 0)
	{
		playerObj.ResetPlayer();
	}

	if (playerObj.GetSnakeHeadPosition().y > windowConfig.height || playerObj.GetSnakeHeadPosition().y < 0)
	{
		playerObj.ResetPlayer();
	}

	if (playerObj.GetSnakeHeadPosition() == appleObj.GetPosition())
	{
		playerObj.AddSnakePart(Player::SNAKE_PART_TYPE::NEW_PART);
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


