#include "game.h"

game::game()
{
	window = nullptr;
	renderer = nullptr;
	bg = nullptr;
	player = nullptr;
	ground = nullptr;
	tree1 = nullptr;
	tree2 = nullptr;
	tree3 = nullptr;
	running = true;
	currentFrame = 0;
	amountFrameX = 0;
	amountFrameY = 0;
	position = 0;
}

int game::onExecute()
{	
	if (onInit() == false)
		return -1;
	if (onLoad() == false)
		return -1;
	while (running)
	{		
		while (SDL_PollEvent(&event))
		{
			onEvent();
		}
		onLoop();
		onRender();
	}
	onCleanup();
	return 0;
}

int main(int argc, char *argv[])
{
	game game;
	return game.onExecute();	
}

void game::SetUpAnimation(int passed_amountX, int passed_amountY)
{
	amountFrameX = passed_amountX;
	amountFrameY = passed_amountY;
}

void game::PlayAnimation(int BeginFrame, int EndFrame, int Row, float Speed)
{
	if (animationDelay + Speed <SDL_GetTicks())
	{
		if (EndFrame <= currentFrame)
			currentFrame = BeginFrame;
		else
			currentFrame++;

		croprect.x = currentFrame * playerWidth / amountFrameX;
		croprect.y = Row * (playerHeight / amountFrameY);
		croprect.w = playerWidth / amountFrameX;
		croprect.h = playerHeight / amountFrameY;

		animationDelay = SDL_GetTicks();
	}
}

SDL_Renderer *game::GetRenderer()
{
	return renderer;
}