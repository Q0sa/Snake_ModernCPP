#pragma once

#include "SDL_render.h"
#include "SDL_rect.h"
#include "Renderer.h"

#include <vector>


struct SDL_Renderer;

class RenderManager
{
public:


	struct RenderEntry
	{
		SDL_Point pos{};
		SDL_Color color{};
	};


	void PushRectEntryToRenderQueue( const SDL_Point& pos, const SDL_Color& color ) noexcept;
	
	void RenderCurrentFrame(Renderer& renderer ) noexcept;
	void ClearRenderQueue() noexcept;



private:
	void RenderQueueToRects(Renderer& renderer) noexcept;

	std::vector<RenderEntry> render_queue = {};
	
};
