#pragma once
#include "Window.h"
#include <vector>


class Renderer {
public:

	struct RenderEntry
	{
		SDL_Point pos = { 0, 0 };
		SDL_Color color = { 0, 0, 0, 0 };
	};

	Renderer(const Window& window);
	
	void PushRectEntryToRenderQueue(const SDL_Point& pos, const SDL_Color& color) noexcept;

	void RenderCurrentFrame(Renderer& renderer) noexcept;
	void ClearRenderQueue() noexcept;
	void RenderQueueToRects(Renderer& renderer) noexcept;

	void SetRenderColor(const SDL_Color& color) noexcept;
	void ClearRenderer() noexcept;
	void FillRect(const SDL_Rect& rect) noexcept;

	void Present() noexcept;
	
	SDL_Rect CreateRect(const SDL_Point& pos, const SDL_Point& size) noexcept;

	SDL_Renderer* GetPointer() noexcept;



private:

	std::vector<RenderEntry> render_queue = {};
	
	std::unique_ptr<SDL_Renderer, SDL_Destroyer> renderer;

};