#include "Player.h"
#include <cmath>
#include "RenderManager.h"
#include <iostream>


Player::Player() :
	player_score(0),
	size(10),
	movement_speed(10.0f),
	starting_x(300.0f),
	starting_y(300.0f),
	color(0, 255, 0, 0)

{
	rect.SetBounds(0, 0, size, size),
	trans.SetPosition(starting_x, starting_y);

	AddSnakePart(SNAKE_PART_TYPE::HEAD);


}


void Player::QueueSnakeForRendering(RenderManager& renderManager)
{
	renderManager.PushRectEntryToRenderQueue(rect, color, trans);

	for (int i = 0; i < snake_body.size(); i++)
	{
		renderManager.PushRectEntryToRenderQueue(snake_body.at(i).rect, snake_body.at(i).color, snake_body.at(i).trans);
	}
}

void Player::Update()
{
	
	Movement();

}

void Player::Movement() {

	switch (move_direction)
	{

	case Player::MOVE_DIRECTION::NONE:
		break;

	case Player::MOVE_DIRECTION::UP:
		trans.ChangePosition(0, -movement_speed);
		MoveSnakeBody();


		break;

	case Player::MOVE_DIRECTION::DOWN:
		trans.ChangePosition(0, movement_speed);
		MoveSnakeBody();


		break;

	case Player::MOVE_DIRECTION::LEFT:
		trans.ChangePosition(-movement_speed, 0);
		MoveSnakeBody();


		break;

	case Player::MOVE_DIRECTION::RIGHT:

		trans.ChangePosition(movement_speed, 0);
		MoveSnakeBody();

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

void Player::MoveSnakeBody() {

	snake_body.front().trans = trans;

	for (int i = 0; i < snake_body.size() - 1; i++)
	{
		//parts[i].trans.ChangePosition(x_array_difference[i - 1], y_array_difference[i - 1]);
		snake_body.at(i + 1) = snake_body.at(i);

	}

}

void Player::AddSnakePart(const SNAKE_PART_TYPE& part_type) {

	PlayerPart newPart = {};

	newPart.color.SetColor(255, 0, 0, 0);
	newPart.rect.SetBounds(0, 0, size, size);

	switch (part_type)
	{
	case SNAKE_PART_TYPE::HEAD:

		newPart.trans.SetPosition(trans.GetX(), trans.GetY());

		break;

	case SNAKE_PART_TYPE::NEW_PART:
		{
		
		Vector2 NewPartPosition = GetNewBodyPosition(snake_body.back().trans.GetPosition(),
												     snake_body.at(snake_body.size() - 1).trans.GetPosition());

		newPart.trans.SetPosition(NewPartPosition.x, NewPartPosition.y);

		break;

		}

	default:
		return;
		
	}
	
	snake_body.push_back(newPart);

}

Vector2 Player::GetNewBodyPosition(const Vector2& last_part_pos, const Vector2& before_last_part_pos) {

	return last_part_pos + (last_part_pos - before_last_part_pos);

}

void Player::ResetPlayer()
{
	player_score = 0;
	move_direction = MOVE_DIRECTION::NONE;

	snake_body.clear();
	AddSnakePart(SNAKE_PART_TYPE::HEAD);

	trans.SetPosition(starting_x, starting_y);
}