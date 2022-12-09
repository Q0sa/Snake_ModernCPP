#include "SDL.h"
#include "RenderManager.h"
#include "Game.h"
#include "Transform.h"

#undef main

// ResourceManager 


void RenderManager::Render(const Rectangle& rect, const Color& color, const Transform& trans)
{
	rectEntries.push_back({ rect, color, trans });
}

void RenderManager::Clear()
{
	
	rectEntries.clear();
}

KeyCode TranslateKeyCode(SDL_Keycode code)
{
	switch (code)
	{
	case SDLK_ESCAPE: return KeyCode::ESCAPE; break;
	case SDLK_SPACE: return KeyCode::SPACE; break;
	case SDLK_RETURN: return KeyCode::ENTER; break;
	case SDLK_RETURN2: return KeyCode::ENTER; break;
	case SDLK_a: return KeyCode::A; break;
	case SDLK_b: return KeyCode::B; break;
	case SDLK_c: return KeyCode::C; break;
	case SDLK_d: return KeyCode::D; break;
	case SDLK_e: return KeyCode::E; break;
	case SDLK_f: return KeyCode::F; break;
	case SDLK_g: return KeyCode::G; break;
	case SDLK_h: return KeyCode::H; break;
	case SDLK_i: return KeyCode::I; break;
	case SDLK_j: return KeyCode::J; break;
	case SDLK_k: return KeyCode::K; break;
	case SDLK_l: return KeyCode::L; break;
	case SDLK_m: return KeyCode::M; break;
	case SDLK_n: return KeyCode::N; break;
	case SDLK_o: return KeyCode::O; break;
	case SDLK_p: return KeyCode::P; break;
	case SDLK_q: return KeyCode::Q; break;
	case SDLK_r: return KeyCode::R; break;
	case SDLK_s: return KeyCode::S; break;
	case SDLK_t: return KeyCode::T; break;
	case SDLK_u: return KeyCode::U; break;
	case SDLK_v: return KeyCode::V; break;
	case SDLK_w: return KeyCode::W; break;
	case SDLK_x: return KeyCode::X; break;
	case SDLK_y: return KeyCode::Y; break;
	case SDLK_z: return KeyCode::Z; break;
	case SDLK_LEFT: return KeyCode::LEFT_ARROW; break;
	case SDLK_RIGHT: return KeyCode::RIGHT_ARROW; break;
	case SDLK_UP: return KeyCode::UP_ARROW; break;
	case SDLK_DOWN: return KeyCode::DOWN_ARROW; break;
	default: return KeyCode::INVALID; break;
	}
}

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Base", 0, 0, 0, 0, SDL_WindowFlags::SDL_WINDOW_RESIZABLE);
	if (window == nullptr)
	{
		const char* error = SDL_GetError();
		return 0;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		const char* error = SDL_GetError();
		return 0;
	}
	bool running = true;
	
	RenderManager renderManager;

	Game game;

	int width = 500;
	int height = 500;
	std::string title = "";
	game.Enter(width, height, title);
	SDL_SetWindowSize(window, width, height);
	SDL_SetWindowTitle(window, title.c_str());
	SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	
	float dt = 1.0f / 60.0f;	
	while (running)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT: running = false; break;
			case SDL_KEYDOWN: game.OnKeyDown(TranslateKeyCode(e.key.keysym.sym)); break;
			case SDL_KEYUP: game.OnKeyUp(TranslateKeyCode(e.key.keysym.sym)); break;
			}
		}

		game.Update(dt);
		game.Render(renderManager);

		SDL_SetRenderDrawColor(renderer,0,0,0,0);
		SDL_RenderClear(renderer);
		
		for (auto&& entry : renderManager.rectEntries)
		{
			SDL_SetRenderDrawColor(renderer, entry.color.r, entry.color.g, entry.color.b, entry.color.a);
			SDL_Rect rect{ static_cast<int>(entry.trans.position.x),
						   static_cast<int>(entry.trans.position.y),
						   entry.rect.w,
						   entry.rect.h };
			//SDL_RenderDrawRect(renderer, &rect);	// <- If you want to draw the "outline" of the rectangle.
			SDL_RenderFillRect(renderer, &rect);  // <- If you want to draw a "filled" rectangle. 
		}
		SDL_RenderPresent(renderer);
		renderManager.Clear();
		SDL_Delay(1000 / 20); //<- "Framerate".
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return 0;
}
