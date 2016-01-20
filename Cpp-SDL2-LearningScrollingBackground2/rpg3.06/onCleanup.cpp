#include "game.h"

void game::onCleanup()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(bg);
	SDL_DestroyTexture(player);
	SDL_DestroyTexture(ground);
	SDL_DestroyTexture(tree1);
	SDL_DestroyTexture(tree2);
	SDL_DestroyTexture(tree3);
	window = nullptr;
	renderer = nullptr;
	bg = nullptr;
	player = nullptr;
	ground = nullptr;
	tree1 = nullptr;
	tree2 = nullptr;
	tree3 = nullptr;
	IMG_Quit();
	SDL_Quit();
}