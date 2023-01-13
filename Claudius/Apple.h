#pragma once

#include "Color.h"
#include "RenderManager.h"



class Apple
{
public:

	Apple() noexcept;

	void QueueAppleForRendering(RenderManager& renderManager);
	void SetRandomPosition(const Vector2& window_bounds);

	Vector2 GetPosition();

private:

	Color color = {};
	Vector2 pos = {};

	int size = {};

};