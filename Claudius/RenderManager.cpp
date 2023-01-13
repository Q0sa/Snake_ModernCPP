#pragma once

#include "RenderManager.h"


void  RenderManager::ClearRenderQueue() noexcept
{
	render_queue.clear();
}


void RenderManager::PushRectEntryToRenderQueue(const SDL_Point& pos, const SDL_Color& color) noexcept
{

	render_queue.push_back({ pos, color });

}

void RenderManager::RenderCurrentFrame( Renderer& renderer) noexcept {

	
	renderer.SetRenderColor(SDL_Color(0, 0, 0, 0));
	renderer.ClearRenderer();

	RenderQueueToRects(renderer);
	
	renderer.Present();

}



void RenderManager::RenderQueueToRects(Renderer& renderer) noexcept {

	for (auto&& entry : render_queue)
	{

		renderer.SetRenderColor(entry.color);

		const SDL_Rect temp = renderer.CreateRect(entry.pos, SDL_Point(10, 10));

		renderer.FillRect(temp);

	}

}

