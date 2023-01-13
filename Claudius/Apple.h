#pragma once


#include "RenderManager.h"



class Apple
{
public:

	Apple() noexcept;

	void QueueAppleForRendering(RenderManager& renderManager) noexcept;
	void SetRandomPosition(const SDL_Point& window_bounds) noexcept;

	SDL_Point GetPosition() noexcept;

private:

	SDL_Color color = {};
	SDL_Point pos = {};

	int size = {};

};