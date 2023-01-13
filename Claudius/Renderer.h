#pragma once
#include "Window.h"

class Renderer {
public:
	Renderer(const Window& window);

	void SetRenderColor(const SDL_Color& color) noexcept;
	void ClearRenderer() noexcept;
	void FillRect(const SDL_Rect& rect) noexcept;

	void Present() noexcept;
	
	SDL_Rect CreateRect(const SDL_Point& pos, const SDL_Point& size) noexcept;

	SDL_Renderer* GetPointer() noexcept;



private:

	struct Renderer_Destroyer {
		void operator()(SDL_Renderer* render_ptr) const noexcept {
			if (render_ptr)
				SDL_DestroyRenderer(render_ptr);

		}
	};

	std::unique_ptr<SDL_Renderer, Renderer_Destroyer> renderer;
};