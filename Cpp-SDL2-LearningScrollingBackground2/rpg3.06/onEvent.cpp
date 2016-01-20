#include "game.h"

void game::onEvent()
{	
	if (event.type == SDL_QUIT)
	{
		running = false;
	}
	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			running = false;
			break;
		case SDLK_a:
			scrollLeft = true;
			PlayAnimation(0, 3, 1, 200);
			break;
		case SDLK_d:
			scrollRight = true;
			PlayAnimation(0, 3, 2, 200);
			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:
		switch (event.key.keysym.sym)
		{
		case SDLK_a:
			scrollLeft = false;
			PlayAnimation(1, 3, 1, 1);
			break;
		case SDLK_d:
			scrollRight = false;
			PlayAnimation(1, 3, 2, 1);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}