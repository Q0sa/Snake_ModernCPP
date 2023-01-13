#pragma once

#include <iostream>
#include "Apple.h"
#include "RenderManager.h"

Apple::Apple() noexcept :
	size(10),
	color(0, 255, 0, 0)
{

	SetRandomPosition();

}


void Apple::QueueAppleForRendering(RenderManager& renderManager)
{
	renderManager.PushRectEntryToRenderQueue(pos, color);
}

void Apple::SetRandomPosition() {

	pos = GenerateRandomPosition();

}

Vector2 Apple::GenerateRandomPosition() {

	return Vector2((rand() % 125) * 10, (rand() % 70) * 10);

}

Vector2 Apple::GetPosition() {

	return pos;

}

