#include "game.h"

bool game::onInit()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << SDL_GetError << std::endl;
		return false;
	}

	window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
	if (window == NULL)
	{
		std::cout << SDL_GetError << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		std::cout << SDL_GetError << std::endl;
		return false;
	}
	SDL_GetRendererOutputSize(renderer, &screenWidth, &screenHeight);
	displayrect.w = screenWidth; displayrect.h = screenHeight; displayrect.x = displayrect.y = 0;

	scrollLeft = scrollRight = 0;

	return true;
}