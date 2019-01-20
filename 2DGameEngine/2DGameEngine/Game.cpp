#include "Game.h"
#include "TestScene.h"

Game::Game()
	: GameManager(this)
{}

Game::~Game()
{
	delete this;
}

//=====Game loop functions=====
//The first function that gets called
void Game::start()
{
	this->sceneManager->addScene(new TestScene());
	this->activateScene("TestScene");
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