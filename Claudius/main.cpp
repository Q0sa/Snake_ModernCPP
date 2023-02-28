#include "Game.h"

#undef main

int main()
{
	try {

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

	}
	
	SDL_Quit();

	return 0;
}
