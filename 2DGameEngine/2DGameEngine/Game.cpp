#include "Game.h"
#include "TestScene.h"
#include "SpriteAtlas.h"
#include "Scene2.h"

Game::Game()
	: GameManager(this)
{
	this->temp = true;
	this->temp2 = false;
}

Game::~Game()
{
	delete this->sceneManager;
}

//=====Game loop functions=====//
//The first function that gets called
void Game::start()
{
	this->sceneManager->addScene(new TestScene());
	this->activateScene("TestScene", false);
	SpriteAtlas* temp = new SpriteAtlas("Graphics/TestSpriteAtlas.png", 64, 64);
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

	if (glfwGetKey(this->gameWindow->getWindow(), GLFW_KEY_F2) == GLFW_PRESS)
	{
		if (!temp2)
		{
			this->temp = !this->temp;

			if (temp)
			{
				this->activateScene("Scene2", true);
			}
			else
			{
				this->activateScene("TestScene", true);
			}
		}
		this->temp2 = true;
	}
	else
		this->temp2 = false;
}

//This function renders every frame
void Game::draw()
{
	this->gameRenderer->renderGame();
}