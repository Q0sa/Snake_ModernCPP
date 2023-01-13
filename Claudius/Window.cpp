#include "Window.h"

Window::Window(std::string_view window_title, const int width, const int height) {

	
	window = std::unique_ptr<SDL_Window, Window_Destroyer>(
		SDL_CreateWindow(window_title.data(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WindowFlags::SDL_WINDOW_SHOWN)
	);
	
	if (window.get() == nullptr)
	{
		std::cout << SDL_GetError() << "\n";

		throw;

	}
	
}

SDL_Window* Window::GetPointer() const noexcept {

	return window.get();

}