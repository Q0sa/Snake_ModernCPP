#pragma once

#include "Apple.h"


void Apple::QueueAppleForRendering(Renderer& renderer) noexcept
{
	renderer.PushRectEntryToRenderQueue(pos, _COLOR_GREEN);
} //remove the middle man of a que and just directly render it

void Apple::SetRandomPosition(const SDL_Point& window_bounds) noexcept {

	pos = SDL_Point((rand() % window_bounds.x / _RENDER_SIZE) * _RENDER_SIZE,
		            (rand() % window_bounds.y / _RENDER_SIZE) * _RENDER_SIZE);

}

SDL_Point Apple::GetPosition() const noexcept {

	return pos;

}

