#pragma once
#include "Window.h"


class Renderer {
public:
	Renderer(const Window& window);

private:

	struct Renderer_Destroyer {
		void operator()(SDL_Renderer* render_ptr) const noexcept {
			if (render_ptr)
				SDL_DestroyRenderer(render_ptr);

		}
	};

	std::unique_ptr<SDL_Renderer, Renderer_Destroyer> renderer;
};