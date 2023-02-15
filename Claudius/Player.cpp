
#include "Player.h"
#include <ranges>
#include <algorithm>
#include <cmath>


Player::Player() noexcept :
	size(10),
	movement_speed(10),
	starting_x(300),
	starting_y(300)
{
	
	AddSnakePart(SNAKE_PART_TYPE::HEAD);
	AddSnakePart(SNAKE_PART_TYPE::NEW_PART);

}


void Player::QueueSnakeForRendering(Renderer& renderer) const noexcept
{

	for (auto& part : snake_body) {

		renderer.PushRectEntryToRenderQueue(part.pos, SDL_Color(0, 255, 0, 0)); //value should be in essential file header thing

	}
	
} 

void Player::HandleInput(SDL_Keycode key) noexcept {

	if (isInputNotOppositeOfMoveDirection(key)) {

		active_valid_input = key;

	}

}

void Player::Movement() 
{
	// combine handleinput and make the SDL_point be its own 
	//dedicated fixed values that is check at key down, and have movement just be the actual position moving

	//make a heading variable that is a vector, it can have five values, none or the four directions, the values should have their respectful names in the essentials header
	//remove handleInput, instead check when you recieve the input if it is valid or not (if input == up and if heading != down)
	//when entering a case, just re-assign the heading variable to correct direction
	//re-name this func to handleInput, and call MoveHeadPos only one in a movement func

		switch (active_valid_input) 
		{
		case SDLK_UP: 

			MoveHeadPos(SDL_Point(0, -movement_speed));

			break;

		case SDLK_DOWN:

			MoveHeadPos(SDL_Point(0, movement_speed));

			break;

		case SDLK_RIGHT:

			MoveHeadPos(SDL_Point(movement_speed, 0));

			break;

		case SDLK_LEFT:

			MoveHeadPos(SDL_Point( -movement_speed, 0));

			break;

		default:
			break;
		}

	MoveSnakeBody();
}

bool Player::isInputNotOppositeOfMoveDirection(const SDL_Keycode& direction_input) const noexcept {


	switch (direction_input)
	{
	case SDLK_UP:

		return active_valid_input != SDLK_DOWN;

	case SDLK_DOWN:

		return active_valid_input != SDLK_UP;

	case SDLK_RIGHT:

		return active_valid_input != SDLK_LEFT;

	case SDLK_LEFT:

		return active_valid_input != SDLK_RIGHT;

	
	default:
		return false;
	}

}

void Player::MoveHeadPos(const SDL_Point& move_amount) noexcept{

	const SDL_Point Pos_Before_Move = GetHead().pos;

	GetHead().pos = SDL_Point(Pos_Before_Move.x + move_amount.x , Pos_Before_Move.y + move_amount.y);

}

void Player::MoveSnakeBody() {

	std::shift_right(snake_body.begin(), snake_body.end(), 1);

}


void Player::AddSnakePart(const SNAKE_PART_TYPE& part_type) noexcept{

	PlayerPart newPart = {};

	
	switch (part_type)
	{
	case SNAKE_PART_TYPE::HEAD:

		newPart.pos = SDL_Point(starting_x, starting_y);

		break;

	case SNAKE_PART_TYPE::NEW_PART:
		
		newPart.pos = GetSnakeTailPosition();
		
		break;

	default:
		return;
		
	}
	
	snake_body.push_back(newPart);

}

void Player::ResetPlayer() noexcept
{
	active_valid_input = {};

	snake_body.clear();

	AddSnakePart(SNAKE_PART_TYPE::HEAD);
	AddSnakePart(SNAKE_PART_TYPE::NEW_PART);

}


Player::PlayerPart &Player::GetHead() noexcept  {

	return snake_body.front();

}

Player::PlayerPart& Player::GetTail() noexcept {

	return snake_body.back();

}

SDL_Point&Player::GetSnakeHeadPosition() noexcept {

	return GetHead().pos;

}

SDL_Point& Player::GetSnakeTailPosition() noexcept {

	return GetTail().pos;

}


std::vector<SDL_Point> Player::GetSnakeBodyPositions() const noexcept {

	std::vector<SDL_Point> part_positions = {};

	for (const PlayerPart part : snake_body | std::views::drop(1))
	{

		part_positions.push_back(part.pos);

	}

	return part_positions;

}

