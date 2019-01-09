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
	GameObjectManager::deletePool();
	delete this->gameRenderer;
}

#pragma region Game Loop

void Game::start()
{
	//testObject = new TestOBJ(new glm::vec2(10.f, 10.f));
	int objectAmount = 2;
	testObject = new TestOBJ*[objectAmount];

	for (int i = 0; i < objectAmount; i++)
	{
		testObject[i] = new TestOBJ(new glm::vec2(0, 0));
	}

	while (!this->gameWindow->getWindowShouldClose())
	{
		update();

		render();
	}
}

void Game::update()
{
	this->gameWindow->updateProjMatrix();

	if (glfwGetKey(this->gameWindow->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		this->gameWindow->close();
	}

	if (glfwGetKey(this->gameWindow->window, GLFW_KEY_F1) == GLFW_PRESS)
	{
		GameObjectManager::createObject(new TestOBJ(new glm::vec2(-10.f, 0.f)));
	}
}

void Game::render()
{
	this->gameRenderer->renderGame();
}

#pragma endregion

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
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(OpenGLErrorMessageCallBack, 0);

	//glEnable(GL_CULL_FACE);

	//glCullFace(GL_BACK);
	//glFrontFace(GL_CCW);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Game::initShaders()
{
	this->gameObjectShader = new Shader(4, 4, "GameObjectVertexCore.glsl", "GameObjectFragmentCore.glsl");
}

void Game::initCamera()
{
	this->gameCamera = new Camera(new glm::vec3(0, 0, 0));
}

void Game::initRenderer()
{
	this->gameRenderer = new Renderer2D(this->mainShader, this->gameObjectShader, this->gameWindow, this->gameCamera);
	this->gameRenderer->setBackgroundColor(90.f / 255, 130.f / 255, 180.f / 255, 0.f);
}
#pragma endregion

#pragma region Callbacks

void Game::glfwErrorCallback(int id, const char* description)
{
	std::cout << description << "\n";
}

void APIENTRY Game::OpenGLErrorMessageCallBack(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
		(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
		type, severity, message);
}

#pragma endregion