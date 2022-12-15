#pragma once

#include "RenderManager.h"

void  RenderManager::ClearRenderQueue()
{

	render_queue.clear();

}


void RenderManager::PushRectEntryToRenderQueue(const Rectangle& rect, const Color& color, const Transform& trans)
{
	render_queue.push_back({ rect, color, trans });
}