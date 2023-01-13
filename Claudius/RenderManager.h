#pragma once

#include "SDL_render.h"
#include "SDL_rect.h"
#include "Renderer.h"
#include "Vector2.h"
#include "Color.h"
#include <vector>


struct SDL_Renderer;

class RenderManager
{
public:


	struct RenderEntry
	{
		Vector2 pos{};
		Color color{};
	};

	std::vector<RenderEntry> render_queue = {};
	//RenderManager(const Renderer& renderer);


	void PushRectEntryToRenderQueue( const Vector2& pos, const Color& color ) noexcept;
	
	void RenderCurrentFrame(Renderer& renderer ) noexcept;
	void ClearRenderQueue() noexcept;



private:
	void RenderQueueToRects(Renderer& renderer) noexcept;

	
};
