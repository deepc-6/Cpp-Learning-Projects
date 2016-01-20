#include "game.h"

void game::onRender()
{
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, bg, &bgrect, &displayrect);

	int s = position - 128;
	int e = position + (1920 * 1080) / screenHeight;
	
	for (int c = s; c < e; c++)
	{
		if (c % groundrect.w == 0)
		{
			groundrect.x = c - position;
			SDL_RenderCopy(renderer, ground, NULL, &groundrect);
		}
	}

	for (int c = s; c < e; c++)
	{
		if (c % treerect1.w == 0)
		{
			treerect1.x = c - position;
			SDL_RenderCopy(renderer, tree1, NULL, &treerect1);
		}
		if (c % treerect2.w == 0)
		{
			treerect2.x = c - position;
			SDL_RenderCopy(renderer, tree1, NULL, &treerect2);
		}
		if (c % treerect3.w == 0)
		{
			treerect3.x = c - position;
			SDL_RenderCopy(renderer, tree1, NULL, &treerect3);
		}
	}

	SDL_RenderCopy(renderer, player, NULL, &playerrect);
	
	if (position <= 2048)
		enemyrect.x = 100;
	else if (position > 2048 && position < 3072)
		enemyrect.x = 50;
	else if (position > 3072 && position < 4096)
		enemyrect.x = 25;
	else if (position > 4096 && position < 4096 + 1024)
		enemyrect.x = 12;
	else if (position > 4096 + 1024 && position < 4096 + 2048)
		enemyrect.x = 6;
	else if (position > 4096 + 2048 && position < 4096 + 3072)
		enemyrect.x = 3;

	if ((position >= 1024 && position < 4096 + 4096) || (scrollRight == false && position != 0))
	SDL_RenderCopy(renderer, enemy, NULL, &enemyrect);
	
	SDL_RenderPresent(renderer);
}