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

SDL_Renderer* Renderer::GetPointer() noexcept {

	return renderer.get();

}

void Renderer::SetRenderColor(const Color& color) noexcept {

	SDL_SetRenderDrawColor(renderer.get(), color.r, color.g, color.b, color.a);

}

SDL_Rect Renderer::CreateRect(const Vector2& pos, const Vector2& size) noexcept {

	return SDL_Rect{ pos.x,
				     pos.y,
				     size.x,
				     size.y };

}

void Renderer::FillRect(const SDL_Rect& rect) noexcept {

	SDL_RenderFillRect(renderer.get(), &rect);

}

void Renderer::Present() noexcept {

	SDL_RenderPresent(renderer.get());

}

void Renderer::ClearRenderer() noexcept {

	SDL_RenderClear(renderer.get());

}

