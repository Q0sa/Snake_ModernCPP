#pragma once
#include "Window.h"
#include "Color.h"
#include "Vector2.h"
class Renderer {
public:
	Renderer(const Window& window);


	void SetRenderColor(const Color& color);
	void ClearRenderer();
	SDL_Rect CreateRect(const Vector2& pos, const Vector2& size);
	void FillRect(const SDL_Rect& rect);

	void Present();

	SDL_Renderer* GetPointer();



private:

	struct Renderer_Destroyer {
		void operator()(SDL_Renderer* render_ptr) const noexcept {
			if (render_ptr)
				SDL_DestroyRenderer(render_ptr);

		}
	};

	std::unique_ptr<SDL_Renderer, Renderer_Destroyer> renderer;
};