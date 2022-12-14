#include "Player.h"
#include <cmath>
#include "RenderManager.h"
#include <iostream>

void Player::Initialize()
{
	color.SetColor(0,255,0,0);
	rect.SetBounds(0, 0, size, size);
	trans.SetPosition(starting_x, starting_y);
	player_score = 0;

	for (int i = 0; i < player_size; i++)
	{
		parts[i].color.SetColor(255, 0, 0, 0);
		parts[i].rect.SetBounds(0, 0, size, size);
		parts[i].trans.SetPosition(trans.GetX(), trans.GetY());
	}
}

void Player::QueueSnakeForRendering(RenderManager& renderManager)
{
	renderManager.PushRectEntryToRenderQueue(rect, color, trans);

	for (int i = 0; i < player_score; i++)
	{
		renderManager.PushRectEntryToRenderQueue(parts[i].rect, parts[i].color, parts[i].trans);
	}
}

void Player::Update()
{
	x_array_difference[0] = trans.GetX() - parts[0].trans.GetX();
	y_array_difference[0] = trans.GetY() - parts[0].trans.GetY();

	for (int i = 1; i < (player_size - 1); i++)
	{
			x_array_difference[i] = parts[i].trans.GetX() - parts[i + 1].trans.GetX();
			y_array_difference[i] = parts[i].trans.GetY() - parts[i + 1].trans.GetY();
	}

	Movement();

}

void Player::Movement() {

	switch (move_direction)
	{

	case Player::MOVE_DIRECTION::NONE:
		break;
	case Player::MOVE_DIRECTION::UP:
		trans.ChangePosition(0, -movement_speed);
		parts[0].trans.ChangePosition(x_array_difference[0], y_array_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].trans.ChangePosition(x_array_difference[i - 1], y_array_difference[i - 1]);
		}

		break;

	case Player::MOVE_DIRECTION::DOWN:
		trans.ChangePosition(0, movement_speed);
		parts[0].trans.ChangePosition(x_array_difference[0], y_array_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].trans.ChangePosition(x_array_difference[i - 1], y_array_difference[i - 1]);
		}

		break;

	case Player::MOVE_DIRECTION::LEFT:
		trans.ChangePosition(-movement_speed, 0);
		parts[0].trans.ChangePosition(x_array_difference[0], y_array_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].trans.ChangePosition(x_array_difference[i - 1], y_array_difference[i - 1]);
		}

		break;

	case Player::MOVE_DIRECTION::RIGHT:
		trans.ChangePosition(movement_speed, 0);
		parts[0].trans.ChangePosition(x_array_difference[0], y_array_difference[0]);

		for (int i = 1; i < player_size; i++)
		{
			parts[i].trans.ChangePosition(x_array_difference[i - 1], y_array_difference[i - 1]);
		}

		break;

	default:
		break;
	}

}

void Player::InputToMovementDirection(SDL_Keycode key)
{

	switch (key)
	{
	case SDLK_UP:
		
		if (isInputNotOppositeOfMoveDirection(key, move_direction))
			move_direction = MOVE_DIRECTION::UP;
		
		break;

	case SDLK_DOWN:
		
		if(isInputNotOppositeOfMoveDirection(key, move_direction))
			move_direction = MOVE_DIRECTION::DOWN;
		
		break;

	case SDLK_RIGHT: 
		
		if (isInputNotOppositeOfMoveDirection(key, move_direction))
			move_direction = MOVE_DIRECTION::RIGHT;
		
		break;

	case SDLK_LEFT: 
		
		if (isInputNotOppositeOfMoveDirection(key, move_direction))
			move_direction = MOVE_DIRECTION::LEFT;

		break;

	default:
		break;
	}
}

bool Player::isInputNotOppositeOfMoveDirection(const SDL_Keycode& direction_input, const MOVE_DIRECTION& current_movement_direction) {

	if (current_movement_direction == MOVE_DIRECTION::NONE) return true;

	switch (direction_input)
	{
	case SDLK_UP:

		return current_movement_direction != MOVE_DIRECTION::DOWN;

	case SDLK_DOWN:

		return current_movement_direction != MOVE_DIRECTION::UP;

	case SDLK_RIGHT:

		return current_movement_direction != MOVE_DIRECTION::LEFT;

	case SDLK_LEFT:

		return current_movement_direction != MOVE_DIRECTION::RIGHT;

	
	default:
		return false;
	}

}

void Player::ResetPlayer()
{
	player_score = 0;
	move_direction = MOVE_DIRECTION::NONE;

	trans.SetPosition(starting_x, starting_y);
}