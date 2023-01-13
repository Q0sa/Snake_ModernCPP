#pragma once		
#include "Color.h"
#include "Vector2.h"
#include "SDL_keycode.h"
#include "RenderManager.h"
#include <vector>
#include <algorithm>


class Player
{

public:
	
	Player() ;


	
	enum class SNAKE_PART_TYPE { HEAD, NEW_PART};

	void AddSnakePart(const SNAKE_PART_TYPE& part_type);

	void Movement() noexcept;

	void HandleInput(SDL_Keycode key);
	
	void QueueSnakeForRendering(RenderManager& renderManager);		
	//void Update();
	void ResetPlayer();

	
	int GetSnakeSize() noexcept;

	Vector2 &GetSnakeHeadPosition();
	Vector2 GetSnakePartPostion(const int& index);



private:
	
	struct PlayerPart
	{
		//Transform trans;
		Vector2 pos;
		Color color;
		//Rectangle rect;
	};
	
	SDL_Keycode last_valid_input = {};

	int size = {};
	float movement_speed = {};
	float starting_x = {};
	float starting_y = {};

	std::vector <PlayerPart> snake_body = {};

	bool isInputNotOppositeOfMoveDirection(const SDL_Keycode& direction_input) noexcept;

	void MoveHeadPos(const Vector2& pos);

	PlayerPart &GetHead();
	void MoveSnakeBody();


};