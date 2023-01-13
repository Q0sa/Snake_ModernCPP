#include "Window.h"

Window::Window(std::string_view window_title, const unsigned int width, const unsigned int height) {

	SDL_Window* temp = SDL_CreateWindow(window_title.data(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WindowFlags::SDL_WINDOW_SHOWN);

	if (temp == nullptr)
	{
		std::cout << SDL_GetError() << "\n";
		Window_Destroyer(temp);

		throw;

	}

	window = std::unique_ptr<SDL_Window, Window_Destroyer>(temp);
	
	
}

SDL_Window* Window::GetPointer() const noexcept {

	return window.get();

}