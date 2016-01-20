#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"

int main(int argc, char** argv)
{
	SDL_Window *window = nullptr;
	SDL_Renderer *renderTarget = nullptr;
	SDL_Texture *background = nullptr;

	int currentTime = 0;
	int prevTime = 0;
	float delta = 0.0f;
	const Uint8 *keyState;
	SDL_Rect camerRect = {0, 0, 1020, 800};
	int levelWidth, levelHeight;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	Player player1(renderTarget, "image.png", 100, 100, 3, 4);
	Player player2(renderTarget, "image.png", 600, 400, 3, 4);

	background = IMG_LoadTexture(renderTarget, "rect.png");
	SDL_QueryTexture(background, NULL, NULL, &levelWidth, &levelHeight);

	bool isRunning = true;
	SDL_Event ev;
		
	while (isRunning)
	{
		prevTime = currentTime;
		currentTime = SDL_GetTicks();
		delta = (currentTime - prevTime) / 1000.0f;

		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_QUIT)
				isRunning = false;
			if (ev.key.keysym.sym == SDLK_ESCAPE)
				isRunning = false;
		}

		keyState = SDL_GetKeyboardState(NULL);

		player1.Update(delta, keyState);
		player2.Update(delta, keyState);

		camerRect.x = player1.GetoriginX() - 510;
		camerRect.y = player1.GetoriginY() - 400;
		
		if (camerRect.x < 0)
			camerRect.x = 0;
		if (camerRect.y < 0)
			camerRect.y = 0;

		if (camerRect.x + camerRect.w >= levelWidth)
			camerRect.x = levelWidth - 1020;
		if (camerRect.y + camerRect.h >= levelHeight)
			camerRect.y = levelHeight - 800;

		player1.IntersectsWith(player2);
		player2.IntersectsWith(player1);

		SDL_RenderClear(renderTarget);
		SDL_RenderCopy(renderTarget, background, &camerRect, NULL);
		player1.Draw(renderTarget, camerRect);
		player2.Draw(renderTarget, camerRect);
		SDL_RenderPresent(renderTarget);
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderTarget);
	SDL_DestroyTexture(background);

	background = nullptr;
	window = nullptr;
	renderTarget = nullptr;
	
	IMG_Quit();
	SDL_Quit();

	return 0;
}