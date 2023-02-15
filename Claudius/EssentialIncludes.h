#pragma once
#include <stdexcept>
#include <codeanalysis\warnings.h>

#pragma warning(push)

#pragma warning(disable:ALL_CODE_ANALYSIS_WARNINGS)

#include "SDL.h"

#pragma warning(pop)

//place warning suppression in here (done)

//MOVE WINDOW AND RENDERER DELETER IN HERE (done)

//All univesal vals in here as well (Delay time, window title, window width and height, basically everything that is set within the headers such as start position of snake and such) 
//Also colours

struct SDL_InitError : std::runtime_error {

	[[gsl::suppress(f.6, justification: "ctor cannot be noexcept due to the use of runtime_error")]]
	SDL_InitError() : std::runtime_error(SDL_GetError()) {}

};

struct SDL_Destroyer {
	void operator()(SDL_Window* window_ptr) const noexcept {
		if (window_ptr)
			SDL_DestroyWindow(window_ptr);

	}

	void operator()(SDL_Renderer* render_ptr) const noexcept {
		if (render_ptr)
			SDL_DestroyRenderer(render_ptr);

	}
};


constexpr auto _TITLE = "Snake";
constexpr auto _DIMENSIONS = (1250, 700);
constexpr auto _DELAY = 50;
constexpr auto _SIZE = 10;
constexpr auto _APPLE_START_POS = (320, 500);
