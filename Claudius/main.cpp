#include "Game.h"

#undef main

int main()
{
	try {

		SDL_Init(SDL_INIT_EVERYTHING);

		Game{}.Enter();

	}
	catch (const SDL_InitError& initError) {
	
		throw initError;

	}
	catch (const std::exception& excep) {

		throw excep;

	}
	catch (...) {
	
		std::cout << "Unknown exception has occured!\n";
		return -1;
	}

	return 0;
}
