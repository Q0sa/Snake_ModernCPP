#include "Player.h"
#include <cmath>
#include "RenderManager.h"
#include <iostream>


Player::Player()  :
	size(10),
	movement_speed(10.0f),
	starting_x(300.0f),
	starting_y(300.0f)
{
	//rect.SetBounds(0, 0, size, size),
	//trans.SetPosition(starting_x, starting_y);


	AddSnakePart(SNAKE_PART_TYPE::HEAD);


}


void Player::QueueSnakeForRendering(RenderManager& renderManager)
{

	for (auto& part : snake_body) {

		renderManager.PushRectEntryToRenderQueue(part.pos, part.color);

	}
	
}

//void Player::Update()
//{
//	
//	Movement();
//
//}
//
//void Player::Movement() {
//
//	switch (move_direction)
//	{
//
//	case Player::MOVE_DIRECTION::NONE:
//		break;
//
//	case Player::MOVE_DIRECTION::UP:
//		trans.ChangePosition(0, -movement_speed);
//		MoveSnakeBody();
//
//
//		break;
//
//	case Player::MOVE_DIRECTION::DOWN:
//		trans.ChangePosition(0, movement_speed);
//		MoveSnakeBody();
//
//
//		break;
//
//	case Player::MOVE_DIRECTION::LEFT:
//		trans.ChangePosition(-movement_speed, 0);
//		MoveSnakeBody();
//
//
//		break;
//
//	case Player::MOVE_DIRECTION::RIGHT:
//
//		trans.ChangePosition(movement_speed, 0);
//		MoveSnakeBody();
//
//		break;
//
//	default:
//		break;
//	}
//
//}

void Player::InputToMovement(SDL_Keycode key) noexcept
{

	if (key != SDLK_UNKNOWN)
		last_valid_input = key;

	if (isInputNotOppositeOfMoveDirection(key)) {
		switch (key)
		{
		case SDLK_UP:

			MoveHeadPos(Vector2(0, -movement_speed));


			break;

		case SDLK_DOWN:

			MoveHeadPos(Vector2(0, movement_speed));

			break;

		case SDLK_RIGHT:

			MoveHeadPos(Vector2(movement_speed, 0));

			break;

		case SDLK_LEFT:

			MoveHeadPos(Vector2( -movement_speed, 0));

			break;

		default:
			break;
		}
	}
	MoveSnakeBody();
	std::cout << GetSnakeHeadPosition().x << " " << GetSnakeHeadPosition().y << "\n";
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

void Player::MoveHeadPos(const Vector2& move_amount) {

	snake_body.front().pos = GetHead().pos + move_amount;

}

void Player::MoveSnakeBody() {

	std::shift_right(snake_body.begin(), snake_body.end(), 1);

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

Player::PlayerPart &Player::GetHead() {

	return snake_body.front();

}

Vector2 &Player::GetSnakeHeadPosition() {

	return GetHead().pos;

}


Vector2 Player::GetSnakePartPostion(const int& index) {

	return snake_body.at(index).pos;

}

//Vector2 Player::GetNewBodyPosition(const Vector2& last_part_pos, const Vector2& before_last_part_pos) {
//
//	return last_part_pos + (last_part_pos - before_last_part_pos);
//
//}