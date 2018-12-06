#include "Game.h"

Game::Game()
{
	initGLFW();
	initWindow();
	initGLEW();
	initOpenGLOptions();
	initShaders();
	initRenderer();

	start();
}


Game::~Game()
{
	delete gameWindow;
	GameObjectManager::deletePool();
}

void Game::start()
{
	for (int i = 0; i < 20; i++)
	{
		GameObjectManager::createObject(new TestOBJ(new glm::vec3(0.f, 0.f, 0.f)));
	}

	while (!this->gameWindow->getWindowShouldClose())
	{
		//Update input
		glfwPollEvents();

		//update();

		render();
	}
}

void Game::update()
{
	if (glfwGetKey(this->gameWindow->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		this->gameWindow->close();
	}
}	

void Game::render()
{
	this->gameRenderer->renderGame();
}

#pragma region Initializers

void Game::initGLFW()
{
	glfwSetErrorCallback(&Game::glfwErrorCallback);

	//Initialize GLFW
	if (glfwInit() == GL_FALSE)
	{
		std::cout << "Error, GLFW did not initialize" << "\n";
		glfwTerminate();
	}
}

void Game::initWindow()
{
	//Initialize the window
	this->gameWindow = new Window("Title", true, true, 4, 4);
}

void Game::initGLEW()
{
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		std::cout << "Error, Glew did not initialize. Did you create a window before GLEW initializes?" << "\n";
	}
}

void Game::initOpenGLOptions()
{
	//OpenGL Options
	glEnable(GL_DEPTH_TEST);

	//glEnable(GL_CULL_FACE);

	//glCullFace(GL_BACK);
	//glFrontFace(GL_CCW);

	glPointSize(10);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Game::initShaders()
{
	this->mainShader = new Shader(4, 4,"vertexCore.glsl", "fragmentCore.glsl", "geometryCore.glsl");
}

void Game::initRenderer()
{
	this->gameRenderer = new Renderer2D(this->mainShader, this->gameWindow, this->gameCamera);
}

#pragma endregion

#pragma region Callbacks

void Game::glfwErrorCallback(int id, const char* description)
{
	std::cout << description << "\n";
}

#pragma endregion