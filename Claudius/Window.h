#pragma once

#include "SDL_render.h"
#include <iostream>
#include <memory>
#include <string>

class Window {
public:

	Window(std::string_view window_title, const int width, const int height);

	SDL_Window* GetPointer() const noexcept;

private:
	
	struct Window_Destroyer{
		void operator()(SDL_Window* window_ptr) const noexcept {
			if (window_ptr) 
				SDL_DestroyWindow(window_ptr);
			
		}
	};

	std::unique_ptr<SDL_Window, Window_Destroyer> window;

};