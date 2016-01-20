#pragma once
#include "stdafx.h"

class CSprite
{
private:
	SDL_Renderer *renderer;
	SDL_Texture *image;
	SDL_Rect rect;
	SDL_Rect croprect;
	int imgWidth, imgHeight;
	int currentFrame;
	int animationDelay;
	float X_pos, Y_pos;
	float Origin_X, Origin_Y;
	int MouseX, MouseY;
	int amountFrameX, amountFrameY;
public:
	CSprite(SDL_Renderer *passed_renderer, std::string FilePath, int x, int y, int w, int h);
	~CSprite();

	void Draw();
	void SetX(float X);
	void SetY(float Y);
	void SetPosition(float X, float Y);
	float GetX();
	float GetY();
	int GetWidth();
	int GetHeight();
	void SetWidth(int W);
	void SetHeight(int H);
	void SetOrigin(float X, float Y);
	void PlayAnimation(int BeginFrame, int EndFrame, int Row, float Speed);
	void SetUpAnimation(int passed_amountX, int passed_amountY);
};

