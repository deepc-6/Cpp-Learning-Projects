#include "game.h"

void game::onLoop()
{	
	if (scrollRight)
		position = position + 20;
	
	if (position > 49280)
		position -= 49280;
	if (position < 0)
		position += 49280;

	//Player Movement
	SetUpAnimation(4, 4);
}