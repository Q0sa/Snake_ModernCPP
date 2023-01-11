#include "Renderer.h"

Renderer::Renderer(const Window& window) {


	SDL_Renderer* temp = SDL_CreateRenderer(window.GetPointer(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	if (temp == nullptr)
	{
		std::cout << SDL_GetError() << "\n";

		SDL_DestroyRenderer(temp);

		throw;
	}

	renderer = std::unique_ptr<SDL_Renderer, Renderer_Destroyer>(temp);


}