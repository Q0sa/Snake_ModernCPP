#pragma once

#include <iostream>
#include "Apple.h"
#include "RenderManager.h"

Apple::Apple() :
	size(10),
	color(0, 255, 0, 0),
	rect(0, 0, size, size)
{

	SetRandomPosition();

}


void Apple::QueueAppleForRendering(RenderManager& renderManager)
{
	renderManager.PushRectEntryToRenderQueue(rect, color, trans);
}

void Apple::SetRandomPosition() {

	Vector2 newPosition = GenerateRandomPosition();

	trans.SetPosition(newPosition.x, newPosition.y);

}

Vector2 Apple::GenerateRandomPosition() {

	return Vector2((rand() % 125) * 10.0f, (rand() % 70) * 10.0f);

}

Vector2 Apple::GetPosition() {

	return trans.GetPosition();

}

