#pragma once

#include "RenderManager.h"

void  RenderManager::ClearRenderQueue()
{

	renderQueue.clear();

}


void RenderManager::PushRectEntryToRenderQueue(const Rectangle& rect, const Color& color, const Transform& trans)
{
	renderQueue.push_back({ rect, color, trans });
}