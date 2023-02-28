#pragma once
#include "Player.h"

void Player::Render(const Renderer& renderer) const noexcept {

	std::for_each(snake_body.begin(), snake_body.end(), [&](Vector2Int part) noexcept { 	
		renderer.Render(_COLOR_GREEN, part);
	});
	
} 

void Player::HandleInput(SDL_Keycode key) noexcept {

	if (key == SDLK_UP && current_movement != _MOVE_DOWN) 
		current_movement = _MOVE_UP;

	else if (key == SDLK_DOWN && current_movement != _MOVE_UP)
		current_movement = _MOVE_DOWN;

	else if (key == SDLK_LEFT && current_movement != _MOVE_RIGHT)
		current_movement = _MOVE_LEFT;

	else if (key == SDLK_RIGHT && current_movement != _MOVE_LEFT)
		current_movement = _MOVE_RIGHT;

}

void Player::Move() {
	
	std::shift_right(snake_body.begin(), snake_body.end(), 1);
	snake_body.front() = snake_body.front() + current_movement;
	
}

void Player::AddSnakePart() noexcept{

	snake_body.push_back(snake_body.back());
		
}


const Vector2Int& Player::GetHead() const noexcept {

	return snake_body.front();

}

const std::vector<Vector2Int> &Player::GetSnakeBodyPositions() const noexcept {

	return snake_body;

}

bool Player::IsSelfColliding() const noexcept {

	return std::any_of(snake_body.begin() + 1, snake_body.end(), [&](const Vector2Int i) noexcept {
		return i == snake_body.front(); 
	});
		
}