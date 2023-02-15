#include "Renderer.h"

Renderer::Renderer(const Window& window) {

	SDL_Renderer* temp = SDL_CreateRenderer(window.GetPointer(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	if (temp == nullptr)
		throw SDL_InitError();

	renderer = std::unique_ptr<SDL_Renderer, SDL_Destroyer>(temp);
}



void Renderer::Present() noexcept {

	SDL_SetRenderDrawColor(renderer.get(), _COLOR_CLEAR.r, _COLOR_CLEAR.g, _COLOR_CLEAR.b, _COLOR_CLEAR.a);

	SDL_RenderClear(renderer.get());

	SDL_RenderPresent(renderer.get());

	SDL_Delay(_RENDER_DELAY);

}


void Renderer::Render(const SDL_Color& in_color, const SDL_Point& in_position) const noexcept {

	SDL_SetRenderDrawColor(renderer.get(), in_color.r, in_color.g, in_color.b, in_color.a);

	const SDL_Rect temp = SDL_Rect{ in_position.x, in_position.y, _RENDER_SIZE.x, _RENDER_SIZE.y };

	SDL_RenderFillRect(renderer.get(), &temp );

}

