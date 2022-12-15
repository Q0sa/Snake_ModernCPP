#include "Player.h"
#include <cmath>
#include "RenderManager.h"
#include <iostream>


Player::Player() :
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

	
	
	Vector2 headBodyDifference = trans.GetPosition();
	
	switch (move_direction)
	{

	case Player::MOVE_DIRECTION::UP:

		headBodyDifference.y += movement_speed;

		break;
	case Player::MOVE_DIRECTION::DOWN:
		headBodyDifference.y -= movement_speed;

		break;
	case Player::MOVE_DIRECTION::LEFT:
		headBodyDifference.x += movement_speed;

		break;
	case Player::MOVE_DIRECTION::RIGHT:
		headBodyDifference.x -= movement_speed;

		break;

	default:
		break;
	}
	
	snake_body.front().trans.SetPosition(headBodyDifference.x, headBodyDifference.y);
	
	PlayerPart tempPart1 = {};
	PlayerPart tempPart2 = snake_body.front();

	for (int i = 0; i < snake_body.size(); i++)
	{

		 tempPart1 = tempPart2;
		 tempPart2 = snake_body.at(i);
		
		snake_body.at(i) = tempPart1;

	}
	

}

void Player::AddSnakePart(const SNAKE_PART_TYPE& part_type) {

	PlayerPart newPart = {};

	newPart.color.SetColor(255, 0, 0, 0);
	newPart.rect.SetBounds(0, 0, size, size);

	Vector2 NewPartPosition = {};

	switch (part_type)
	{
	case SNAKE_PART_TYPE::HEAD:

		NewPartPosition = trans.GetPosition();

		newPart.trans.SetPosition(NewPartPosition.x, NewPartPosition.y);

		break;

	case SNAKE_PART_TYPE::NEW_PART:
		
		
		if (snake_body.size() >= 2)
			NewPartPosition = GetNewBodyPosition(snake_body.back().trans.GetPosition(),
											     snake_body.at(snake_body.size() - 2).trans.GetPosition());
		else {
			NewPartPosition = GetNewBodyPosition(snake_body.back().trans.GetPosition(),
						      trans.GetPosition());


		}

		newPart.trans.SetPosition(NewPartPosition.x, NewPartPosition.y);

		
		break;

	default:
		return;
		
	}
	
	snake_body.push_back(newPart);

}

void Player::ResetPlayer()
{
	move_direction = MOVE_DIRECTION::NONE;

	snake_body.clear();
	AddSnakePart(SNAKE_PART_TYPE::HEAD);

	trans.SetPosition(starting_x, starting_y);
}


int Player::GetSnakeSize(){

	return snake_body.size();

}

Vector2 Player::GetSnakeHeadPosition() {

	return trans.GetPosition();

}

Vector2 Player::GetSnakePartPostion(const int& index) {

	return snake_body.at(index).trans.GetPosition();

}

Vector2 Player::GetNewBodyPosition(const Vector2& last_part_pos, const Vector2& before_last_part_pos) {

	return last_part_pos + (last_part_pos - before_last_part_pos);

}