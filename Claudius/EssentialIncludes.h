#pragma once
#include <stdexcept>
#include <codeanalysis\warnings.h>

#pragma warning(push)

#pragma warning(disable:ALL_CODE_ANALYSIS_WARNINGS)

#include "SDL.h"

#pragma warning(pop)


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

constexpr SDL_Point _DIMENSIONS (1250, 700);

constexpr auto _RENDER_DELAY = 50;
constexpr SDL_Point _RENDER_SIZE (10, 10);

constexpr SDL_Point _APPLE_START_POS (320, 500);
constexpr SDL_Point _PLAYER_START_POS (300, 300);

constexpr auto _MOVEMENT_SPEED = 10;
constexpr SDL_Point _MOVEMENT_UP (0, -_MOVEMENT_SPEED);
constexpr SDL_Point _MOVEMENT_DOWN (0, _MOVEMENT_SPEED);
constexpr SDL_Point _MOVEMENT_LEFT (-_MOVEMENT_SPEED, 0);
constexpr SDL_Point _MOVEMENT_RIGHT (_MOVEMENT_SPEED, 0);

constexpr SDL_Color _COLOR_CLEAR (0, 0, 0, 0);
constexpr SDL_Color _COLOR_GREEN (0, 255, 0, 255);
constexpr SDL_Color _COLOR_RED (255, 0, 0, 255);