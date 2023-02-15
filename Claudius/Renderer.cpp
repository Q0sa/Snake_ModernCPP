#include "Renderer.h"

Renderer::Renderer(const Window& window) {

	SDL_Renderer* temp = SDL_CreateRenderer(window.GetPointer(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	if (temp == nullptr)
		throw SDL_InitError();

	
	renderer = std::unique_ptr<SDL_Renderer, SDL_Destroyer>(temp);


}

SDL_Renderer* Renderer::GetPointer() noexcept {

	return renderer.get();

}

void Renderer::SetRenderColor(const SDL_Color& color) noexcept {

	SDL_SetRenderDrawColor(renderer.get(), color.r, color.g, color.b, color.a);

}

SDL_Rect Renderer::CreateRect(const SDL_Point& pos, const SDL_Point& size) noexcept {

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

void  Renderer::ClearRenderQueue() noexcept
{
	render_queue.clear();
}


void Renderer::PushRectEntryToRenderQueue(const SDL_Point& pos, const SDL_Color& color) noexcept
{

	render_queue.push_back({ pos, color });

}

void Renderer::RenderCurrentFrame(Renderer& renderer) noexcept {


	renderer.SetRenderColor(_COLOR_CLEAR);
	renderer.ClearRenderer();

	RenderQueueToRects(renderer);

	renderer.Present();

}



void Renderer::RenderQueueToRects(Renderer& renderer) noexcept { //this should be a function taking the rects you want to render and drawing/rendering them directly
	//in other words, make this function take the same arguments as the renderque func and use this where you use the render que func
	for (auto&& entry : render_queue)
	{

		renderer.SetRenderColor(entry.color);

		const SDL_Rect temp = renderer.CreateRect(entry.pos, SDL_Point(10, 10)); //magic values

		renderer.FillRect(temp);

	}

}

