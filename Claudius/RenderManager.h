#pragma once

#include <vector>

struct Transform;
struct Rectangle;
struct Color;

struct RenderManager
{

	struct RenderEntry
	{
		const Rectangle& rect;
		const Color& color;
		const Transform& trans;
	};

	void PushRectEntryToRenderQueue(const Rectangle& rect, const Color& color, const Transform& trans);
	void ClearRenderQueue();

	std::vector<RenderEntry> renderQueue = {};

};
