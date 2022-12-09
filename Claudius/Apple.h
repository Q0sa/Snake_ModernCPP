#pragma once

#include "KeyCode.h"
#include "Rectangle.h"
#include "Color.h"
#include "Transform.h"

struct RenderManager; //<- Kinda like #include "RenderManager.h", not exactly. Can't use functions. Google forward declaration.

struct Apple
{

	Apple();
	void Render(RenderManager& renderManager);
	void Initialize(unsigned int width, unsigned int height);

	Rectangle rect;
	Color color;
	Transform trans;

	bool new_apple = false;
};