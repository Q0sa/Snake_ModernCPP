#pragma once

#include "Rectangle.h"
#include "Color.h"
#include "Transform.h"

struct RenderManager;

class Apple
{
public:

	Apple() noexcept;

	void QueueAppleForRendering(RenderManager& renderManager);
	void SetRandomPosition();

	Vector2 GetPosition();

private:

	Rectangle rect;
	Color color;
	Transform trans;

	int size = {};

	Vector2 GenerateRandomPosition();
};