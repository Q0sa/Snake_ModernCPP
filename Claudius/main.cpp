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
		return -1;
	}



	//add excpetion handling with try catch (use multiple catches)

	//init error & std::exception
	// if unknow use ...

	return 0;
}
