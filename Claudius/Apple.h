#pragma once

#include "Renderer.h"

class Apple
{
public:

	void Render(const Renderer& renderer) const noexcept;
	void SetRandomPosition(const SDL_Point& window_bounds) noexcept;

	SDL_Point GetPosition() const noexcept;

private:

	SDL_Point pos = _APPLE_START_POS;

};