#pragma once		
#include "SDL_keycode.h"
#include "Renderer.h"
#include <vector>



class Player
{

public:
	
	Player() noexcept;

	struct PlayerPart
	{

		SDL_Point pos = { 0, 0 };

	};// make this just a posiion thing
	
	enum class SNAKE_PART_TYPE { HEAD, NEW_PART};

	void AddSnakePart(const SNAKE_PART_TYPE& part_type) noexcept;

	void Movement();

	void HandleInput(SDL_Keycode key) noexcept;
	
	void QueueSnakeForRendering(Renderer& renderer) const noexcept;
	void ResetPlayer() noexcept;


	SDL_Point &GetSnakeHeadPosition() noexcept;
	std::vector<SDL_Point> GetSnakeBodyPositions() const noexcept;
	SDL_Point& GetSnakeTailPosition() noexcept;


	
private:


	SDL_Keycode active_valid_input{};

	int size = 0; //should be removed
	int movement_speed = 0;
	int starting_x = 0; //sdl_point?
	int starting_y = 0;

	std::vector <PlayerPart> snake_body = {};

	bool isInputNotOppositeOfMoveDirection(const SDL_Keycode& direction_input) const noexcept;

	void MoveHeadPos(const SDL_Point& pos) noexcept;

	PlayerPart &GetHead() noexcept;
	PlayerPart& GetTail() noexcept;

	void MoveSnakeBody();



};