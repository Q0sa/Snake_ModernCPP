#pragma once

#include "EssentialIncludes.h"
//#include "SDL_render.h"
#include <iostream>
#include <memory>
#include <string>

class Window {
public:

	Window(std::string_view title, unsigned int width, unsigned int height);

	SDL_Window* GetPointer() const noexcept;

private:
	
	std::unique_ptr<SDL_Window, SDL_Destroyer> window;

};