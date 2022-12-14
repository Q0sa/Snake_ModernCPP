#pragma once

#include "Rectangle.h"
#include "Color.h"
#include "Transform.h"

struct RenderManager;

struct Apple
{

	Apple();
	void QueueAppleForRendering(RenderManager& renderManager);
	void Initialize(unsigned int width, unsigned int height);

	Rectangle rect;
	Color color;
	Transform trans;

	bool new_apple = false;
};