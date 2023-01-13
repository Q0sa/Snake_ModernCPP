#pragma once

#include <iostream>
#include "Apple.h"

Apple::Apple() noexcept :
	size(10),
	pos(320, 500)
{


}


void Apple::QueueAppleForRendering(RenderManager& renderManager) noexcept
{
	renderManager.PushRectEntryToRenderQueue(pos, Color(255, 0, 0, 0));
}

void Apple::SetRandomPosition(const Vector2& window_bounds) noexcept {

	pos = Vector2((rand() % window_bounds.x / size) * size,
		          (rand() % window_bounds.y / size) * size);

}

Vector2 Apple::GetPosition() noexcept {

	return pos;

}

