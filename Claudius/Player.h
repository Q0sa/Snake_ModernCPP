#pragma once		
#include "Transform.h"
#include "Color.h"
#include "Rectangle.h"
#include "SDL_keycode.h"

struct RenderManager;

struct Player
{
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

	enum class MOVE_DIRECTION
	{

		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT

	};

	MOVE_DIRECTION move_direction = {};

	void InputToMovementDirection(SDL_Keycode key);
	bool isInputNotOppositeOfMoveDirection(const SDL_Keycode& direction_input, const MOVE_DIRECTION& current_movement_direction);
	void Movement();
	
	void Initialize();
	void QueueSnakeForRendering(RenderManager& renderManager);		
	void Update();
	void ResetPlayer();

	int size = 10;
	const float movement_speed = 10.0f;
	const float starting_x = 300.0f;
	const float starting_y = 300.0f;


	bool new_snake = false;

	float x_array_difference[player_size] = {};
	float y_array_difference[player_size] = {};

	int player_score = 0;
};