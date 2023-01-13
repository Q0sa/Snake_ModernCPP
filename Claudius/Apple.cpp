#pragma once

#include <iostream>
#include "Apple.h"

Apple::Apple() noexcept :
	size(10),
	pos(SDL_Point(320, 500))
{


}


void Apple::QueueAppleForRendering(RenderManager& renderManager) noexcept
{
	renderManager.PushRectEntryToRenderQueue(pos, SDL_Color(255, 0, 0, 0));
}

void Apple::SetRandomPosition(const SDL_Point& window_bounds) noexcept {

	pos = SDL_Point((rand() % window_bounds.x / size) * size,
		            (rand() % window_bounds.y / size) * size);

}

SDL_Point Apple::GetPosition() const noexcept {

	return pos;

}

