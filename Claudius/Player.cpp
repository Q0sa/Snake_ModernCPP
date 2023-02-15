
#include "Player.h"
#include <ranges>
#include <algorithm>
#include <cmath>


Player::Player() noexcept 
{
	
	//AddSnakePart(SNAKE_PART_TYPE::HEAD);
	AddSnakePart(SNAKE_PART_TYPE::NEW_PART);

}


void Player::Render(const Renderer& renderer) const noexcept
{

	for (auto& part : snake_body) {

		renderer.Render(_COLOR_GREEN, part); //value should be in essential file header thing

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

			snake_body.front() += _MOVEMENT_UP;
			break;

		case SDLK_DOWN:

			snake_body.front() += _MOVEMENT_DOWN;

			break;

		case SDLK_RIGHT:

			snake_body.front() += _MOVEMENT_RIGHT;

			break;

		case SDLK_LEFT:

			snake_body.front() += _MOVEMENT_LEFT;

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


void Player::MoveSnakeBody() {

	std::shift_right(snake_body.begin(), snake_body.end(), 1);

}


void Player::AddSnakePart(const SNAKE_PART_TYPE& part_type) noexcept{

	switch (part_type)
	{
	case SNAKE_PART_TYPE::HEAD:

		//snake_body.push_back();

		break;

	case SNAKE_PART_TYPE::NEW_PART:
		
		snake_body.push_back(snake_body.back());
		
		
		break;

	default:
		return;
		
	}
	

}

void Player::ResetPlayer() noexcept
{
	active_valid_input = {};

	snake_body.clear();

	AddSnakePart(SNAKE_PART_TYPE::HEAD);
	AddSnakePart(SNAKE_PART_TYPE::NEW_PART);

}

const SDL_Point& Player::GetHead() const noexcept {

	return snake_body.front();

}

const std::vector<SDL_Point> &Player::GetSnakeBodyPositions() const noexcept {

	return snake_body;

}

bool Player::PlayerIsSelfColliding() const noexcept { //MOVE TO SNAKE

	for (const SDL_Point& pos : snake_body | std::views::drop(2))
	{

		if (snake_body.front() == pos)
			return true;

	}

	return false;

}

