#pragma once
#include "Apple.h"

void Apple::Render(const Renderer& renderer) const noexcept {

	renderer.Render(_COLOR_RED, pos);

} 

void Apple::SetRandomPosition(const SDL_Point& window_bounds) noexcept { 

	pos = SDL_Point((std::rand() % window_bounds.x / _RENDER_SIZE.x) * _RENDER_SIZE.x,
		            (std::rand() % window_bounds.y / _RENDER_SIZE.y) * _RENDER_SIZE.y);

}

SDL_Point Apple::GetPosition() const noexcept {

	return pos;

}

