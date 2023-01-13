#pragma once		
#include "Color.h"
#include "Vector2.h"
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
		//Transform trans;
		Vector2 pos;
		//Rectangle rect;
	};
	
	enum class SNAKE_PART_TYPE { HEAD, NEW_PART};

	void AddSnakePart(const SNAKE_PART_TYPE& part_type);

	void Movement();

	void HandleInput(SDL_Keycode key) noexcept;
	
	void QueueSnakeForRendering(RenderManager& renderManager) noexcept;
	//void Update();
	void ResetPlayer();

	
	int GetSnakeSize() noexcept;

	Vector2 &GetSnakeHeadPosition() noexcept;
	std::vector<Vector2> GetSnakeBodyPositions() noexcept;
	Vector2& GetSnakeTailPosition() noexcept;



private:


	SDL_Keycode active_valid_input = {};

	int size = {};
	int movement_speed = {};
	int starting_x = {};
	int starting_y = {};

	std::vector <PlayerPart> snake_body = {};

	bool isInputNotOppositeOfMoveDirection(const SDL_Keycode& direction_input) noexcept;

	void MoveHeadPos(const Vector2& pos) noexcept;

	PlayerPart &GetHead() noexcept;
	PlayerPart& GetTail() noexcept;

	void MoveSnakeBody();



};