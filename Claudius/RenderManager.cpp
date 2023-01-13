#pragma once

#include "RenderManager.h"


void  RenderManager::ClearRenderQueue() noexcept
{
	render_queue.clear();
}


void RenderManager::PushRectEntryToRenderQueue(const Vector2& pos, const Color& color)
{

	render_queue.push_back({ pos, color });

}

void RenderManager::RenderCurrentFrame( Renderer& renderer) {

	
	renderer.SetRenderColor(Color(0, 0, 0, 0));
	renderer.ClearRenderer();

	RenderQueueToRects(renderer);
	
	renderer.Present();

}



void RenderManager::RenderQueueToRects(Renderer& renderer) {

	for (auto&& entry : render_queue)
	{
		//SDL_SetRenderDrawColor(renderer, entry.color.r, entry.color.g, entry.color.b, entry.color.a);

		renderer.SetRenderColor(entry.color);

		SDL_Rect temp = renderer.CreateRect(entry.pos, Vector2(10, 10));

		renderer.FillRect(temp);

	}

}

