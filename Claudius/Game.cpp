// 2019-12-05 Teemu Laiho

#include "Game.h"
#include "RenderManager.h"
#include <iostream>

Game::Game() : windowConfig({ 1250, 700, "Snake"})
{
	//Player test, moving two players to collide with each other.
	playerOne.Initialize();
	apple.Initialize(10, 10);
}

Game::~Game()
{
}


void Game::Update()
{
	// dt means delta time.
	// timer += dt; <- check Game.h
	// if (timer > updateInterval)
	//{
	// update snake movement
	// timer = 0.0f; or timer -= updateInterval;
	//}

	playerOne.Update();

	// Player colliding on theirself.
	for (int i = 0; i < playerOne.player_score; i++)
	{
		if (playerOne.trans.GetPosition() == playerOne.parts[i].trans.GetPosition())
		{
			playerOne.ResetPlayer();
		}
	}

	// Player going out of X bounds.
	if (playerOne.trans.GetX() > windowConfig.width || playerOne.trans.GetX() < 0)
	{
		playerOne.ResetPlayer();
	}

	// Player going out of Y bounds.
	if (playerOne.trans.GetY() > windowConfig.height || playerOne.trans.GetY() < 0)
	{
		playerOne.ResetPlayer();
	}

	// Player collide on apple.
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


