#include "SDL.h"
#include "RenderManager.h"
#include "Game.h"
#include "Transform.h"
#include <cassert>
#include <iostream>

#undef main


int main()
{

	srand(time(nullptr));

	bool running = true;
	
	Game game = {};
	

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow(game.GetGameTitle(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		game.GetGameWidth(),
		game.GetGameHeight(),
		SDL_WindowFlags::SDL_WINDOW_SHOWN);

	if (window == nullptr)
	{
		std::cout << SDL_GetError() << "\n";
		SDL_DestroyWindow(window);

		return -1;
		
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		std::cout << SDL_GetError() << "\n";

		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);

		return -1;
	
	}
	
	
	while (running)
	{
		SDL_Event user_event = {};
		while (SDL_PollEvent(&user_event))
		{
			switch (user_event.type)
			{

			case SDL_KEYDOWN: game.PassInputToPlayer(user_event.key.keysym.sym);
				break;

			case SDL_QUIT: running = false;
				break;


			default: break;
			}
		}

		game.Update();

        SDL_SetRenderDrawColor(renderer,0,0,0,0);
		SDL_RenderClear(renderer);
		
		for (auto&& entry : game.GetRenderQueue())
		{
			SDL_SetRenderDrawColor(renderer, entry.color.r, entry.color.g, entry.color.b, entry.color.a);
			SDL_Rect rect{ static_cast<int>(entry.trans.position.x),
						   static_cast<int>(entry.trans.position.y),
						   entry.rect.w,
						   entry.rect.h };
			
			SDL_RenderFillRect(renderer, &rect);  
		}
		SDL_RenderPresent(renderer);

		game.ClearRenderManager();

		SDL_Delay(1000 / 20); 
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return 0;
}
