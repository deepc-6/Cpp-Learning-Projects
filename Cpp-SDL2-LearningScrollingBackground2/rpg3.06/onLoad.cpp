#include "game.h"

bool game::onLoad()
{
	bg = IMG_LoadTexture(renderer, "data/grass.bmp");
	if (bg == NULL)
	{
		std::cout << SDL_GetError << std::endl;
		running = false;
	}
	SDL_QueryTexture(bg, NULL, NULL, &screenWidth, &screenHeight);
	bgrect.x = 0; bgrect.y = 0; bgrect.w = screenWidth; bgrect.h = screenHeight;

	player = IMG_LoadTexture(renderer, "data/car2.png");
	if (player == NULL)
	{
		std::cout << SDL_GetError << std::endl;
		running = false;
	}
	SDL_QueryTexture(player, NULL, NULL, &playerWidth, &playerHeight);
	playerrect.x = 500; playerrect.y = 1080-183; playerrect.w = 400; playerrect.h = 183;

	enemy = IMG_LoadTexture(renderer, "data/carpolice.png");
	if (enemy == NULL)
	{
		std::cout << SDL_GetError << std::endl;
		running = false;
	}
	SDL_QueryTexture(enemy, NULL, NULL, &playerWidth, &playerHeight);
	enemyrect.x = 100; enemyrect.y = 1080 - 180; enemyrect.w = 300; enemyrect.h = 180;
	
	ground = IMG_LoadTexture(renderer, "data/ground.bmp");
	if (ground == NULL)
	{
		std::cout << SDL_GetError << std::endl;
		running = false;
	}
	SDL_QueryTexture(ground, NULL, NULL, &groundWidth, &groundHeight);
	groundrect.x = 0; groundrect.y = 1080 - 64 - 100; groundrect.w = 64; groundrect.h = 64;

	tree1 = IMG_LoadTexture(renderer, "data/tree.png");
	if (tree1 == NULL)
	{
		std::cout << SDL_GetError << std::endl;
		running = false;
	}
	SDL_QueryTexture(tree1, NULL, NULL, &treeWidth, &treeHeight);
	treerect1.x = 400; treerect1.y = 1080 - 328 - 60; treerect1.w = 256; treerect1.h = 328;

	tree2 = IMG_LoadTexture(renderer, "data/tree.png");
	if (tree2 == NULL)
	{
		std::cout << SDL_GetError << std::endl;
		running = false;
	}
	SDL_QueryTexture(tree2, NULL, NULL, &treeWidth, &treeHeight);
	treerect2.x = 600; treerect2.y = 1080 - 164 - 80; treerect2.w = 128; treerect2.h = 164;

	tree3 = IMG_LoadTexture(renderer, "data/tree.png");
	if (tree3 == NULL)
	{
		std::cout << SDL_GetError << std::endl;
		running = false;
	}
	SDL_QueryTexture(tree3, NULL, NULL, &treeWidth, &treeHeight);
	treerect3.x = 800; treerect3.y = 1080 - 256 - 70; treerect3.w = 200; treerect3.h = 256;

	return true;
}