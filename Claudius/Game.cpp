// 2019-12-05 Teemu Laiho

#include "Game.h"
#include "RenderManager.h"
#include <iostream>

Game::Game() : 
	windowConfig({ 1250, 700, "Snake"}),
	apple_obj(),
	player_obj()
{

}


void Game::Update()
{

	player_obj.Update();
	

	for (int i = 0; i < player_obj.GetSnakeSize(); i++)
	{
		if (player_obj.GetSnakeHeadPosition() == player_obj.GetSnakePartPostion(i))
		{
			player_obj.ResetPlayer();
		}
	}

	if (player_obj.GetSnakeHeadPosition().x > windowConfig.width || player_obj.GetSnakeHeadPosition().x < 0)
	{
		player_obj.ResetPlayer();
	}

	if (player_obj.GetSnakeHeadPosition().y > windowConfig.height || player_obj.GetSnakeHeadPosition().y < 0)
	{
		player_obj.ResetPlayer();
	}

	if (player_obj.GetSnakeHeadPosition() == apple_obj.GetPosition())
	{
		player_obj.AddSnakePart(Player::SNAKE_PART_TYPE::NEW_PART);
		apple_obj.SetRandomPosition();
	}

	QueueGameObjectsForRendering();

}

void Game::QueueGameObjectsForRendering()
{
	player_obj.QueueSnakeForRendering(render_manager);
	apple_obj.QueueAppleForRendering(render_manager);
}

void Game::ClearRenderManager() {

	render_manager.ClearRenderQueue();

}

std::vector<RenderManager::RenderEntry> Game::GetRenderQueue()
{
	return render_manager.render_queue;
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
	player_obj.InputToMovementDirection(key);
}


