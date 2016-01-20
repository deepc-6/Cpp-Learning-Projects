#pragma once

#include <SDL.h>
#include <string>

class Player
{
private:
	SDL_Rect cropRect;	
	SDL_Texture *background;
	float moveSpeed;
	float frameCounter;
	int frameWidth, frameHeight, textureWidth;
	bool isActive;
	SDL_Scancode keys[4];
	int originX, originY;
	int radius;
public:	
	Player(SDL_Renderer *renderTarget, std::string filePath, int x, int y, int framesX, int framesY);
	~Player();

	void Update(float delta, const Uint8 *keyState);
	void Draw(SDL_Renderer *renderTarget, SDL_Rect cameraRect);

	bool IntersectsWith(Player &p);

	SDL_Rect positionRect;
	
	int GetoriginX();
	int GetoriginY();
	int GetRadius();
};