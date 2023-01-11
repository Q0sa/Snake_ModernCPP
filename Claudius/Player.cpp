#include "Player.h"
#include <cmath>
#include "RenderManager.h"
#include <iostream>


Player::Player()  :
	size(10),
	movement_speed(10.0f),
	starting_x(300.0f),
	starting_y(300.0f),
	//color(0, 255, 0, 0),
	//pos(starting_x, starting_y)

{
	//rect.SetBounds(0, 0, size, size),
	//trans.SetPosition(starting_x, starting_y);


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

void Player::InputToMovement(SDL_Keycode key) noexcept
{

	switch (key)
	{
	case SDLK_UP:
		
		if (isInputNotOppositeOfMoveDirection(key))
			pos.y -= movement_speed;
		
		break;

	case SDLK_DOWN:
		
		if(isInputNotOppositeOfMoveDirection(key))
			pos.y += movement_speed;

		break;

	case SDLK_RIGHT: 
		
		if (isInputNotOppositeOfMoveDirection(key))
			pos.x += movement_speed;

		break;

	case SDLK_LEFT: 
		
		if (isInputNotOppositeOfMoveDirection(key))
			pos.x -= movement_speed;

		break;

	default:
		break;
	}
}

bool Player::isInputNotOppositeOfMoveDirection(const SDL_Keycode& direction_input) noexcept {


	switch (direction_input)
	{
	case SDLK_UP:

		return last_valid_input != SDLK_DOWN;

	case SDLK_DOWN:

		return last_valid_input != SDLK_UP;

	case SDLK_RIGHT:

		return last_valid_input != SDLK_LEFT;

	case SDLK_LEFT:

		return last_valid_input != SDLK_RIGHT;

	
	default:
		return false;
	}

}

void Player::MoveSnakeBody() {

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


	switch (part_type)
	{
	case SNAKE_PART_TYPE::HEAD:

		newPart.color = Color(0, 255, 0, 0);
		newPart.pos = Vector2(starting_x, starting_y);

		break;

	case SNAKE_PART_TYPE::NEW_PART:
		
		
		newPart.color = Color(255, 0, 0, 0);
		newPart.pos = GetHead().pos;

		
		break;

	default:
		return;
		
	}
	
	snake_body.push_back(newPart);

}

void Player::ResetPlayer()
{
	last_valid_input = SDLK_UNKNOWN;

	snake_body.clear();
	AddSnakePart(SNAKE_PART_TYPE::HEAD);

}


int Player::GetSnakeSize() noexcept {

	return snake_body.size();

}

Player::PlayerPart Player::GetHead() {

	return snake_body.front();

}

Vector2 Player::GetSnakeHeadPosition() {

	return GetHead().pos;

}


Vector2 Player::GetSnakePartPostion(const int& index) {

	return snake_body.at(index).pos;

}

Vector2 Player::GetNewBodyPosition(const Vector2& last_part_pos, const Vector2& before_last_part_pos) {

	return last_part_pos + (last_part_pos - before_last_part_pos);

}