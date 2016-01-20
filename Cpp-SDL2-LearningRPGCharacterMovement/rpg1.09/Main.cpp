#include "Main.h"

CMain::CMain(int passed_screenWidth, int passed_screenHeight)
{
	running = true;	
	grass = nullptr;
	bob = nullptr;

	screenWidth = passed_screenWidth;
	screenHeight = passed_screenHeight;

	csdl_setup = new CSDL_Setup(&running, screenWidth, screenHeight);
	grass = new CSprite(csdl_setup->GetRenderer(), "data/grass.bmp", 0, 0, screenWidth, screenHeight);
	bob = new CSprite(csdl_setup->GetRenderer(), "data/tom.png", 300, 200, 100, 120);
	
	bob->SetUpAnimation(4,4);
	bob->SetOrigin(bob->GetWidth()/2.0f, bob->GetHeight());

	timeCheck = SDL_GetTicks();
	MouseX = 0;
	MouseY = 0;
	distance = 0;

	follow = false;
	stopAnimation = false;
}

CMain::~CMain()
{	
	csdl_setup = nullptr;
	grass = nullptr;
	bob = nullptr;
}

double CMain::GetDistance(int X1, int Y1, int X2, int Y2)
{
	double differenceX = X1 - X2;
	double differenceY = Y1 - Y2;
	double distance = sqrt((differenceX * differenceX) + (differenceY * differenceY));
	return distance;
}

void CMain::GameLoop()
{
	while ((running) && (csdl_setup->GetEvent()->type != SDL_QUIT))
	{
		csdl_setup->Begin();

		SDL_GetMouseState(&MouseX, &MouseY);

		grass->Draw();
		bob->Draw();

		float angle = atan2(followPointY - bob->GetY(), followPointX - bob->GetX());
		angle = (angle * (180 / 3.14)) + 180;
		
		if (!stopAnimation)
		{
			//Up
			if (angle > 45 && angle <= 135)
			{
				if (distance > 3)
					bob->PlayAnimation(0, 3, 3, 200);
				else
					bob->PlayAnimation(1, 1, 3, 200);
			}
			//Right
			if (angle > 135 && angle <= 225)
			{
				if (distance > 3)
					bob->PlayAnimation(0, 3, 2, 200);
				else
					bob->PlayAnimation(1, 1, 2, 200);
			}
			//Down
			if (angle > 225 && angle <= 315)
			{
				if (distance > 3)
					bob->PlayAnimation(0, 3, 0, 200);
				else
					bob->PlayAnimation(1, 1, 0, 200);
			}
			//Left
			if ((angle > 315 && angle <= 360) || (angle >= 0 && angle <= 45))
			{
				if (distance > 3)
					bob->PlayAnimation(0, 3, 1, 200);
				else
					bob->PlayAnimation(1, 1, 1, 200);
			}
		}
		if (csdl_setup->GetEvent()->type == SDL_MOUSEBUTTONDOWN || csdl_setup->GetEvent()->type == SDL_MOUSEMOTION)
		{
			if (csdl_setup->GetEvent()->button.button == SDL_BUTTON_RIGHT)
			{
				followPointX = MouseX;
				followPointY = MouseY;
				follow = true;
			}
		}

		if ((timeCheck < SDL_GetTicks()) && (follow))
		{
			SDL_GetMouseState(&MouseX, &MouseY);
			distance = GetDistance(bob->GetX(), bob->GetY(), followPointX, followPointY);

			if (distance == 0)
				stopAnimation = true;
			else
				stopAnimation = false;

			if (distance > 3)
			{
				if (bob->GetX() > followPointX)
				{
					bob->SetX(bob->GetX() - ((bob->GetX() - followPointX) / distance) * 2);
				}
				if (bob->GetX() < followPointX)
				{
					bob->SetX(bob->GetX() - ((bob->GetX() - followPointX) / distance) * 2);
				}
				if (bob->GetY() > followPointY)
				{
					bob->SetY(bob->GetY() - ((bob->GetY() - followPointY) / distance) * 2);
				}
				if (bob->GetY() < followPointY)
				{
					bob->SetY(bob->GetY() - ((bob->GetY() - followPointY) / distance) * 2);
				}
			}
			timeCheck = SDL_GetTicks();
		}

		csdl_setup->End();
	}
}
