#include <iostream>
#include <SDL.h>

int main(int argc, char* argv[])
{
	const Uint8 *keyState;
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1020, 800, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_Surface* sBackground = SDL_LoadBMP("mario.bmp");
	SDL_Texture *tBackground = SDL_CreateTextureFromSurface(renderTarget, sBackground);

	SDL_Surface *sPlayer = SDL_LoadBMP("koopa.bmp");
	SDL_SetColorKey(sPlayer, SDL_TRUE, SDL_MapRGB(sPlayer->format, 0x00, 0xff, 0xff));
	SDL_Texture *tPlayer = SDL_CreateTextureFromSurface(renderTarget, sPlayer);
	SDL_Rect rPlayer = { 400, 764 - sPlayer->h, sPlayer->w, sPlayer->h };

	SDL_Surface *sEnemy = SDL_LoadBMP("gumba.bmp");
	SDL_SetColorKey(sEnemy, SDL_TRUE, SDL_MapRGB(sEnemy->format, 0x00, 0xff, 0xff));
	SDL_Texture *tEnemy = SDL_CreateTextureFromSurface(renderTarget, sEnemy);	
	SDL_Rect rEnemy = {0, 764 - sEnemy->h, sEnemy->w, sEnemy->h};

	bool EnemyMovingLeft = true;

	SDL_Surface *sBlock = SDL_LoadBMP("block.bmp");
	SDL_SetColorKey(sBlock, SDL_TRUE, SDL_MapRGB(sBlock->format, 0x00, 0xff, 0xff));
	SDL_Texture *tBlock = SDL_CreateTextureFromSurface(renderTarget, sBlock);
	SDL_Rect rBlock = { 200, 764 - sBlock->h, sBlock->w, sBlock->h };

	bool isRunning = true;
	SDL_Event ev;

	while (isRunning)
	{
		while (SDL_PollEvent(&ev) != 0)
		{	//Controls
			keyState = SDL_GetKeyboardState(NULL);
			if (ev.type == SDL_QUIT)
				isRunning = false;
			else if (keyState[SDL_SCANCODE_ESCAPE])
				isRunning = false;
			else if (keyState[SDL_SCANCODE_A])
				rPlayer.x -= 10;
			else if (keyState[SDL_SCANCODE_D])			
				rPlayer.x += 10;
		}
		//Boundary
		if (rPlayer.x < 0)
			rPlayer.x = 0;
		if (rPlayer.x + rPlayer.w >= 1020)
			rPlayer.x = 1020 - rPlayer.w;
		if (rEnemy.x < 0)
			rEnemy.x = 0;
		if (rEnemy.x + rEnemy.w >= 1020)
			rEnemy.x = 1020 - rEnemy.w;

		if (EnemyMovingLeft)
		{
			rEnemy.x -= 1;
		}
		else if (!EnemyMovingLeft)
		{
			rEnemy.x += 1;
		}
		
		if (rEnemy.x <= 0)
			EnemyMovingLeft = false;
		else if (rEnemy.x + rEnemy.w >= 1020)
			EnemyMovingLeft = true;
		
		//Collision
		if (rPlayer.x - 20 == rEnemy.x)
			rEnemy.x += 50;
		else if (rPlayer.x + 10 == rEnemy.x)
			rEnemy.x -= 20;
		
		//Draw
		SDL_RenderClear(renderTarget);
		SDL_RenderCopy(renderTarget, tBackground, NULL, NULL);
		SDL_RenderCopy(renderTarget, tEnemy, NULL, &rEnemy);
		SDL_RenderCopy(renderTarget, tPlayer, NULL, &rPlayer);
		SDL_RenderCopy(renderTarget, tBlock, NULL, &rBlock);
		SDL_RenderPresent(renderTarget);
	}

	//Cleanup
	SDL_DestroyWindow(window);
	SDL_FreeSurface(sBackground);
	SDL_DestroyTexture(tBackground);
	SDL_FreeSurface(sPlayer);
	SDL_DestroyTexture(tPlayer);
	SDL_FreeSurface(sEnemy);
	SDL_DestroyTexture(tEnemy);
	SDL_FreeSurface(sBlock);
	SDL_DestroyTexture(tBlock);
	SDL_DestroyRenderer(renderTarget);
	window = nullptr;
	sBackground = sPlayer = sEnemy = sBlock = nullptr;
	tBackground = tPlayer = tEnemy = tBlock = nullptr;
	renderTarget = nullptr;

	SDL_Quit();

	return 0;
}