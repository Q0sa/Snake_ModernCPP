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

	void InputToMovement(SDL_Keycode key) noexcept;
	
	void QueueSnakeForRendering(RenderManager& renderManager);		
	void Update();
	void ResetPlayer();

	
	int GetSnakeSize() noexcept;

	Vector2 GetSnakeHeadPosition();
	Vector2 GetSnakePartPostion(const int& index);



private:
	
	struct PlayerPart
	{
		//Transform trans;
		Vector2 pos;
		Color color;
		//Rectangle rect;
	};
	/*Vector2 pos;
	Color color;*/
	//Rectangle rect;

	//enum class MOVE_DIRECTION
	//{

	//	NONE,
	//	UP,
	//	DOWN,
	//	LEFT,
	//	RIGHT

	//};

	//MOVE_DIRECTION move_direction = {};
	SDL_Keycode last_valid_input = {};

	int size = {};
	float movement_speed = {};
	float starting_x = {};
	float starting_y = {};

	std::vector <PlayerPart> snake_body = {};

	void Movement();
	bool isInputNotOppositeOfMoveDirection(const SDL_Keycode& direction_input) noexcept;
	Vector2 GetNewBodyPosition(const Vector2& last_part_pos, const Vector2& before_last_part_pos );

	PlayerPart GetHead();
	void MoveSnakeBody();


};