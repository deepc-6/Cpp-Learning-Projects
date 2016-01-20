#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <cstdlib>
#include <time.h>

class game
{
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *bg;
	SDL_Texture *bg1;
	SDL_Texture *bg2;
	SDL_Texture *player;
	SDL_Texture *enemy;
	SDL_Texture *ground;
	SDL_Texture *tree1;
	SDL_Texture *tree2;
	SDL_Texture *tree3;
	SDL_Event event;
	SDL_Rect bgrect;
	SDL_Rect bgrect2;
	SDL_Rect displayrect;
	SDL_Rect playerrect;
	SDL_Rect enemyrect;
	SDL_Rect groundrect;
	SDL_Rect croprect;
	SDL_Rect treerect1;
	SDL_Rect treerect2;
	SDL_Rect treerect3;
	bool running;
	int res, screenWidth, screenHeight;
	bool MoveLeft, MoveRight;
	int timeCheck;
	int amountFrameX, amountFrameY;
	int playerWidth, playerHeight;
	int enemyWidth, enemyHeight;
	int currentFrame;
	int animationDelay;
	int treeWidth, treeHeight;
	int groundWidth, groundHeight;
	bool scrollRight, scrollLeft;
	int position;
public:
	game();
	SDL_Renderer *GetRenderer();
	int onExecute();
	bool onInit();
	bool onLoad();
	void onEvent();
	void onLoop();
	void onRender();
	void onCleanup();
	void PlayAnimation(int BeginFrame, int EndFrame, int Row, float Speed);
	void SetUpAnimation(int passed_amountX, int passed_amountY);
};