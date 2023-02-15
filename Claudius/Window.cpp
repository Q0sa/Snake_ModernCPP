#include "Window.h"

Window::Window(std::string_view title, unsigned int width, unsigned int height) {

	window = std::unique_ptr<SDL_Window, SDL_Destroyer>(
		SDL_CreateWindow(title.data(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WindowFlags::SDL_WINDOW_SHOWN)
	);
	
	if (window.get() == nullptr)
		throw SDL_InitError();
	
}

SDL_Window* Window::GetPointer() const noexcept {

	return window.get();

}