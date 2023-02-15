#pragma once		
#include "Renderer.h"
#include <vector>



class Player
{

public:
	
	Player() noexcept;


	enum class SNAKE_PART_TYPE { HEAD, NEW_PART};

	void AddSnakePart(const SNAKE_PART_TYPE& part_type) noexcept;

	void Movement();

	void HandleInput(SDL_Keycode key) noexcept;
	
	void Render(const Renderer& renderer) const noexcept;
	void ResetPlayer() noexcept;

	const std::vector<SDL_Point> &GetSnakeBodyPositions() const noexcept;
	const SDL_Point& GetHead() const noexcept;

	bool PlayerIsSelfColliding() const noexcept;

private:


	SDL_Keycode active_valid_input{};

	std::vector <SDL_Point> snake_body = { SDL_Point(_PLAYER_START_POS) };

	bool isInputNotOppositeOfMoveDirection(const SDL_Keycode& direction_input) const noexcept;

	void MoveSnakeBody();



};