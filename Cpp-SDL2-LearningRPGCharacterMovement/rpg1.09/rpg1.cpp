#include "Main.h"

int main(int argc, char *argv[])
{
	CMain *cmain = new CMain(1020,800);
	cmain->GameLoop();

	cmain = nullptr;
	return 0;
}