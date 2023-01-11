#pragma once		
#include "Transform.h"
#include "Color.h"
#include "Rectangle.h"
#include "SDL_keycode.h"
#include "RenderManager.h"
#include <vector>


class Player
{

public:
	
	Player() ;
	
	enum class SNAKE_PART_TYPE { HEAD, NEW_PART};

	void AddSnakePart(const SNAKE_PART_TYPE& part_type);

	void InputToMovementDirection(SDL_Keycode key) noexcept;
	
	void QueueSnakeForRendering(RenderManager& renderManager);		
	void Update();
	void ResetPlayer();

	
	int GetSnakeSize() noexcept;

	Vector2 GetSnakeHeadPosition();
	Vector2 GetSnakePartPostion(const int& index);



private:
	struct PlayerPart
	{
		Transform trans;
		Color color;
		Rectangle rect;
	};

	Transform trans;
	Color color;
	Rectangle rect;

	enum class MOVE_DIRECTION
	{

		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT

	};

	MOVE_DIRECTION move_direction = {};


	int size = {};
	const float movement_speed = {};
	const float starting_x = {};
	const float starting_y = {};

	std::vector <PlayerPart> snake_body = {};

	void Movement();
	bool isInputNotOppositeOfMoveDirection(const SDL_Keycode& direction_input, const MOVE_DIRECTION& current_movement_direction) noexcept;
	Vector2 GetNewBodyPosition(const Vector2& last_part_pos, const Vector2& before_last_part_pos );

	void MoveSnakeBody();


};