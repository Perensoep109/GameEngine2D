#include "Game.h"

Game::Game()
{
	initGLFW();
	initWindow();
	initGLEW();
	initOpenGLOptions();
	initShaders();
	initCamera();
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
	//testObject = new TestOBJ(new glm::vec3(10.f, 10.f, 0.0f));

	while (!this->gameWindow->getWindowShouldClose())
	{

		update();

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
	this->gameWindow = new Window("Title", true, false, 4, 4, glm::ivec2(800, 600));
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

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Game::initShaders()
{
	this->mainShader = new Shader(4, 4, "vertexCore.glsl", "fragmentCore.glsl");
}

void Game::initCamera()
{
	this->gameCamera = new Camera(new glm::vec3(0, 0, 0));
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