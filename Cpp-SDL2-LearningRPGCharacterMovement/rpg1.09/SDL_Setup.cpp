#include "SDL_Setup.h"

CSDL_Setup::CSDL_Setup(bool *running, int screenWidth, int screenHeight)
{
	window = nullptr;
	renderer = nullptr;
	event = nullptr;

	//Initializing SDL Mode
	SDL_Init(SDL_INIT_VIDEO);

	//Window Creation
	window = SDL_CreateWindow("RPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << SDL_GetError << std::endl;
		*running = false;
	}

	//Renderer Creation
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		std::cout << SDL_GetError << std::endl;
		*running = false;
	}
	event = new SDL_Event();
}

CSDL_Setup::~CSDL_Setup()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	window = nullptr;
	renderer = nullptr;
	event = nullptr;
}

SDL_Renderer *CSDL_Setup::GetRenderer()
{
	return renderer;
}
SDL_Event *CSDL_Setup::GetEvent()
{
	return event;
}

void CSDL_Setup::Begin()
{
	SDL_PollEvent(event);
	SDL_RenderClear(renderer);
}
void CSDL_Setup::End()
{
	SDL_RenderPresent(renderer);
}
