#pragma once
#include "Apple.h"


void Apple::Render(const Renderer& renderer) const noexcept //Is const due to its not mutating anything we are only inspecting it 
{
	renderer.Render(_COLOR_RED, pos);
} 

void Apple::SetRandomPosition(const SDL_Point& window_bounds) noexcept {

	pos = SDL_Point((rand() % window_bounds.x / _RENDER_SIZE.x) * _RENDER_SIZE.x,
		            (rand() % window_bounds.y / _RENDER_SIZE.y) * _RENDER_SIZE.y);

}

SDL_Point Apple::GetPosition() const noexcept {

	return pos;

}

