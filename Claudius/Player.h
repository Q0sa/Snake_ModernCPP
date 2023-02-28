#pragma once		
#include "Renderer.h"
#include <vector>
#include <algorithm>



class Player
{

public:

	void AddSnakePart() noexcept;

	void Move();

	void HandleInput(SDL_Keycode key) noexcept;
	
	void Render(const Renderer& renderer) const noexcept;

	const std::vector<SDL_Point> &GetSnakeBodyPositions() const noexcept;
	const SDL_Point& GetHead() const noexcept;

    bool IsSelfColliding() const noexcept;

private:

	SDL_Point current_movement = _MOVE_NONE;

	std::vector <SDL_Point> snake_body = { SDL_Point(_PLAYER_START_POS) };

};