#pragma once

#include "Rectangle.h"
#include "Color.h"
#include "Transform.h"
#include "RenderManager.h"

class Apple
{
public:

	Apple() noexcept;

	void QueueAppleForRendering(RenderManager& renderManager);
	void SetRandomPosition();

	Vector2 GetPosition();

private:

	Color color;
	Vector2 pos;

	int size = {};

	Vector2 GenerateRandomPosition();
};