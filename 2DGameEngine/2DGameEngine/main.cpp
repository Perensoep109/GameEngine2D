#include "libs.h"
#include "Game.h"

int main()
{
	bool autoClose = false;

	Game* game = new Game();

	delete game;

	if(!autoClose)
		system("PAUSE");

	return 0;
}