#pragma once		
#include "SDL_keycode.h"
#include "RenderManager.h"
#include <vector>
#include <ranges>
#include <algorithm>
#include <cmath>



class Player
{

public:
	
	Player() noexcept;

	struct PlayerPart
	{

		 SDL_Point pos;

	};
	
	enum class SNAKE_PART_TYPE { HEAD, NEW_PART};

	void AddSnakePart(const SNAKE_PART_TYPE& part_type) noexcept;

	void Movement();

	void HandleInput(SDL_Keycode key) noexcept;
	
	void QueueSnakeForRendering(RenderManager& renderManager) const noexcept;
	void ResetPlayer() noexcept;


	SDL_Point &GetSnakeHeadPosition() noexcept;
	std::vector<SDL_Point> GetSnakeBodyPositions() const noexcept;
	SDL_Point& GetSnakeTailPosition() noexcept;


	
private:


	SDL_Keycode active_valid_input = {};

	int size = {};
	int movement_speed = {};
	int starting_x = {};
	int starting_y = {};

	std::vector <PlayerPart> snake_body = {};

	bool isInputNotOppositeOfMoveDirection(const SDL_Keycode& direction_input) const noexcept;

	void MoveHeadPos(const SDL_Point& pos) noexcept;

	PlayerPart &GetHead() noexcept;
	PlayerPart& GetTail() noexcept;

	void MoveSnakeBody();



};