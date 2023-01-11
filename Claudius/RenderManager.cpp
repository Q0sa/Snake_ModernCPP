#pragma once

#include "RenderManager.h"

void  RenderManager::ClearRenderQueue() noexcept
{
	render_queue.clear();
}


void RenderManager::PushRectEntryToRenderQueue(const Rectangle& rect, const Color& color, const Transform& trans)
{
	//Remove rect input, only have color and change Transform to Vector2Int

	render_queue.push_back({ rect, color, trans });
}