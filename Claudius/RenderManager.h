#pragma once

#include <vector>

struct Transform;
struct Rectangle;
struct Color;

class RenderManager
{
public:
	struct RenderEntry
	{
		const Rectangle& rect;
		const Color& color;
		const Transform& trans;
	};

	void PushRectEntryToRenderQueue(const Rectangle& rect, const Color& color, const Transform& trans);
	void ClearRenderQueue() noexcept;

	std::vector<RenderEntry> render_queue = {};

};
