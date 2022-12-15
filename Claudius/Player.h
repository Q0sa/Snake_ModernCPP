#pragma once		
#include "Transform.h"
#include "Color.h"
#include "Rectangle.h"
#include "SDL_keycode.h"
#include "RenderManager.h"


class Player
{

public:

	Player();

	struct PlayerPart
	{
		Transform trans;
		Color color;
		Rectangle rect;
	};

	static const int player_size = 50;
	PlayerPart parts[player_size];
	
	Transform trans;
	Color color;
	Rectangle rect;


	void InputToMovementDirection(SDL_Keycode key);
	
	void QueueSnakeForRendering(RenderManager& renderManager);		
	void Update();
	void ResetPlayer();


	int player_score = 0;

private:

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


	bool new_snake = false;

	float x_array_difference[player_size] = {};
	float y_array_difference[player_size] = {};

	bool isInputNotOppositeOfMoveDirection(const SDL_Keycode& direction_input, const MOVE_DIRECTION& current_movement_direction);
	void Movement();
};