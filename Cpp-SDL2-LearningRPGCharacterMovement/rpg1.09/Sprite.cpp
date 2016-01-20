#include "Sprite.h"

CSprite::CSprite(SDL_Renderer *passed_renderer, std::string FilePath, int x, int y, int w, int h)
{
	image = nullptr;
	renderer = nullptr;
	renderer = passed_renderer;

	//Loading background texture
	image = IMG_LoadTexture(renderer, FilePath.c_str());
	if (image == NULL)
		std::cout << IMG_GetError << FilePath.c_str() << std::endl;
	rect.x = x; rect.y = y; rect.w = w; rect.h = h;

	SDL_QueryTexture(image, NULL, NULL, &imgWidth, &imgHeight);

	croprect.x = 0; croprect.y = 0; croprect.w = imgWidth; croprect.h = imgHeight;

	X_pos = x;
	Y_pos = y;
	Origin_X = Origin_Y = 0;
	MouseX = 0;
	MouseY = 0;
	currentFrame = 0;
	amountFrameX = 0;
	amountFrameY = 0;
}

CSprite::~CSprite()
{
	SDL_DestroyTexture(image);
	SDL_DestroyRenderer(renderer);	
	image = nullptr; 
	renderer = nullptr;	
}

void CSprite::SetUpAnimation(int passed_amountX, int passed_amountY)
{
	amountFrameX = passed_amountX;
	amountFrameY = passed_amountY;
}

void CSprite::PlayAnimation(int BeginFrame, int EndFrame, int Row, float Speed)
{
	if (animationDelay + Speed <SDL_GetTicks())
	{
		if (EndFrame <= currentFrame)
			currentFrame = BeginFrame;
		else
			currentFrame++;

		croprect.x = currentFrame * imgWidth / amountFrameX;
		croprect.y = Row * (imgHeight / amountFrameY);
		croprect.w = imgWidth / amountFrameX;
		croprect.h = imgHeight / amountFrameY;

		animationDelay = SDL_GetTicks();
	}
}

//Display
void CSprite::Draw()
{
	SDL_RenderCopy(renderer, image, &croprect, &rect);
}

//Move Player
void CSprite::SetX(float X)
{
	X_pos = X;
	rect.x = int(X_pos - Origin_X);
}
void CSprite::SetY(float Y)
{
	Y_pos = Y;
	rect.y = int(Y_pos - Origin_Y);
}
void CSprite::SetPosition(float X, float Y)
{
	X_pos = X;
	Y_pos = Y;
	rect.x = int(X_pos - Origin_X);
	rect.y = int(Y_pos - Origin_Y);
}
float CSprite::GetX()
{
	return X_pos;
}
float CSprite::GetY()
{
	return Y_pos;
}

void CSprite::SetOrigin(float X, float Y)
{
	Origin_X = X;
	Origin_Y = Y;

	SetPosition(GetX(), GetY());
}

void CSprite::SetWidth(int W)
{
	rect.w = W;
}
void CSprite::SetHeight(int H)
{
	rect.h = H;
}
int CSprite::GetWidth()
{
	return rect.w;
}
int CSprite::GetHeight()
{
	return rect.h;
}