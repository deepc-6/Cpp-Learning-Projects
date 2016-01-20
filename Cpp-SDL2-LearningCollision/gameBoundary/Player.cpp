#include "Player.h"
#include <SDL_image.h>
#include <iostream>
#include <cmath>

Player::Player(SDL_Renderer *renderTarget, std::string filePath, int x, int y, int framesX, int framesY)
{
	SDL_Surface *surface = IMG_Load(filePath.c_str());
	if (surface == NULL)
		std::cout << SDL_GetError << std::endl;
	else
	{
		background = SDL_CreateTextureFromSurface(renderTarget, surface);
		if (background == NULL)
			std::cout << SDL_GetError << std::endl;
	}

	SDL_FreeSurface(surface);

	SDL_QueryTexture(background, NULL, NULL, &cropRect.w, &cropRect.h);

	positionRect.x = x;
	positionRect.y = y;

	textureWidth = cropRect.w;

	cropRect.w /= framesX;
	cropRect.h /= framesY;

	frameWidth = positionRect.w = cropRect.w;
	frameHeight = positionRect.h = cropRect.h;

	originX = frameWidth / 2;
	originY = frameHeight / 2;
	radius = frameWidth / 2;

	isActive = false;

	static int playerNumber = 0;
	playerNumber++;

	if (playerNumber == 1)
	{
		keys[0] = SDL_SCANCODE_W;
		keys[1] = SDL_SCANCODE_S;
		keys[2] = SDL_SCANCODE_A;
		keys[3] = SDL_SCANCODE_D;
	}
	else
	{
		keys[0] = SDL_SCANCODE_UP;
		keys[1] = SDL_SCANCODE_DOWN;
		keys[2] = SDL_SCANCODE_LEFT;
		keys[3] = SDL_SCANCODE_RIGHT;
	}
	moveSpeed = 200.0f;
}

Player::~Player()
{
	SDL_DestroyTexture(background);
}

void Player::Update(float delta, const Uint8 *keyState)
{
	isActive = true;

	if (keyState[keys[0]])
	{
		positionRect.y -= moveSpeed * delta;
		cropRect.y = frameHeight * 3;
	}
	else if (keyState[keys[1]])
	{
		positionRect.y += moveSpeed * delta;
		cropRect.y = 0;
	}
	else if (keyState[keys[2]])
	{
		positionRect.x -= moveSpeed * delta;
		cropRect.y = frameHeight;
	}
	else if (keyState[keys[3]])
	{
		positionRect.x += moveSpeed * delta;
		cropRect.y = frameHeight * 2;
	}
	else
		isActive = false;

	if (isActive)
	{
		frameCounter += delta;

		if (frameCounter >= 0.25f)
		{
			frameCounter = 0;
			cropRect.x += frameWidth;
			if (cropRect.x >= textureWidth)
				cropRect.x = 0;
		}
	}
	else
	{
		frameCounter = 0;
		cropRect.x = frameWidth;
	}

	if (positionRect.x < 0)
		positionRect.x = 0;
	if (positionRect.x + positionRect.w >= 3840)
		positionRect.x = 3840 - positionRect.w;

	if (positionRect.y < 0)
		positionRect.y = 0;
	if (positionRect.y + positionRect.h >= 2160)
		positionRect.y = 2160 - positionRect.h;
}

void Player::Draw(SDL_Renderer *renderTarget, SDL_Rect cameraRect)
{
	SDL_Rect drawingRect = { positionRect.x - cameraRect.x, positionRect.y - cameraRect.y, positionRect.w, positionRect.h };
	SDL_RenderCopy(renderTarget, background, &cropRect, &drawingRect);
}

bool Player::IntersectsWith(Player &p)
{
	if (sqrt(pow(GetoriginX() - p.GetoriginX(), 2) + pow(GetoriginY() - p.GetoriginY(), 2)) >= radius + p.GetRadius())
	{
		SDL_SetTextureColorMod(background, 255, 255, 255);
		return false;
	}
	else
	{
		SDL_SetTextureColorMod(background, 255, 0, 0);
		return true;
	}
}

int Player::GetoriginX()
{
	return positionRect.x + originX;
}
int Player::GetoriginY()
{
	return positionRect.y + originY;
}
int Player::GetRadius()
{
	return radius;
}