#include <direct.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"

#include "DynTempQueue.h"

int main()
{
	Game::Instance()->init();

	while (Game::Instance()->isRunning())
	{
		Game::Instance()->output();
		Game::Instance()->input();
		Game::Instance()->update();
	}
	return 0;
}