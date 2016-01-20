#pragma once
#include "stdafx.h"

class CSDL_Setup
{
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event *event;
public:
	CSDL_Setup(bool *running, int screenWidth, int screenHeight);
	~CSDL_Setup();

	SDL_Renderer *GetRenderer();
	SDL_Event *GetEvent();

	void Begin();
	void End();
};

