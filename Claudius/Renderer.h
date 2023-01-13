#pragma once
#include "Window.h"
#include "Color.h"
#include "Vector2.h"
class Renderer {
public:
	Renderer(const Window& window);

	void SetRenderColor(const Color& color) noexcept;
	void ClearRenderer() noexcept;
	void FillRect(const SDL_Rect& rect) noexcept;

	void Present() noexcept;
	
	SDL_Rect CreateRect(const Vector2& pos, const Vector2& size) noexcept;

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