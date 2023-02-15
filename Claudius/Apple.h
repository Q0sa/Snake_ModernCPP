#pragma once

#include "Renderer.h"

class Apple
{
public:

	Apple() noexcept;

	void QueueAppleForRendering(const Renderer& renderer) noexcept;
	void SetRandomPosition(const SDL_Point& window_bounds) noexcept;

	SDL_Point GetPosition() const noexcept;

private:

	SDL_Color color = {0, 0, 0, 0};
	SDL_Point pos = { 0, 0 };

	int size = 0;

};