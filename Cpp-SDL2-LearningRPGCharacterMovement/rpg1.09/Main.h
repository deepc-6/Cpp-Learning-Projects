#pragma once
#include "SDL_Setup.h"
#include "Sprite.h"
#include <math.h>

class CMain
{
private:
	bool running;
	int screenWidth, screenHeight;
	CSDL_Setup *csdl_setup; 
	CSprite *grass;
	CSprite *bob;
	int timeCheck;
	int MouseX, MouseY;
	bool follow;
	int followPointX, followPointY;
	float distance;
	bool stopAnimation;
	
public:
	CMain(int passed_screenWidth, int passed_screenHeight);
	~CMain();

	double GetDistance(int X1, int Y1, int X2, int Y2);

	void GameLoop();
};

