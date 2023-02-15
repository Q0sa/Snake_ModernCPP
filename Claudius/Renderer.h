#pragma once
#include "Window.h"


class Renderer {
public:

	Renderer(const Window& window);
	
	void Present() noexcept;

	void Render(const SDL_Color& in_color, const SDL_Point& in_position) const noexcept;

private:
	
	std::unique_ptr<SDL_Renderer, SDL_Destroyer> renderer;

};