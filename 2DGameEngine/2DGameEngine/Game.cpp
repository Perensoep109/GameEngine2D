#include "Game.h"

Game::Game()
	: GameManager(this)
{
	std::cout << "Created game" << "\n";
}

Game::~Game()
{
	delete this;
}

//=====Game loop functions=====
//The first function that gets called
void Game::start()
{
	int objectAmount = 3;
	testObject = new TestOBJ*[objectAmount];

	testObject[0] = new TestOBJ(new glm::vec2(650, 128));
	testObject[1] = new TestOBJ(new glm::vec2(400, 128));
	testObject[2] = new TestOBJ(new glm::vec2(0, 128));
	
}

//This function gets called every frame
void Game::update()
{
	if (glfwGetKey(this->gameWindow->getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		endNextFrame = true;
	}

	if (glfwGetKey(this->gameWindow->getWindow(), GLFW_KEY_F1) == GLFW_PRESS)
	{
		this->gameWindow->toggleFullScreen(!this->gameWindow->getFullscreen());
	}
}

//This function renders every frame
void Game::draw()
{
	this->gameRenderer->renderGame();
}