#include "libs.h"
#include "Game.h"

int main()
{
	Game* game = new Game();

	glfwTerminate();

	delete game;

	system("PAUSE");
	return 0;
}