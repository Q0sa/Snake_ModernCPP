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

	const std::vector<Vector2Int> &GetSnakeBodyPositions() const noexcept;
	const Vector2Int& GetHead() const noexcept;

    bool IsSelfColliding() const noexcept;

private:

	Vector2Int current_movement = _MOVE_NONE;

	std::vector <Vector2Int> snake_body = { _PLAYER_START_POS };

};