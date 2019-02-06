#include "Game.h"

GameManager::GameManager(Game* game)
{
	this->focussedGame = game;

	setup();
	start();
}


GameManager::~GameManager()
{
	delete this->gameRenderer;
}

#pragma region Game Loop
void GameManager::setup()
{
	initGLFW();
	initWindow();
	initGLEW();
	initOpenGLOptions();
	initSceneManager();
	initRenderer();

	endNextFrame = false;
}

//======Game management functions======//
void GameManager::start()
{
	this->focussedGame->start();

	while (!this->endNextFrame)
	{
		update();

		draw();
	}
}

void GameManager::update()
{
	this->focussedGame->update();
	if (glfwGetKey(this->gameWindow->getWindow(), GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		this->sceneManager->updateActiveScene();
	}
}

void GameManager::draw()
{
	this->focussedGame->draw();
}

//Scene management functions//

void GameManager::activateScene(std::string sceneToActivate, bool reload)
{
	this->sceneManager->activateScene(sceneToActivate, reload);
	this->gameRenderer->setCurrentScene(this->sceneManager->getScene(sceneToActivate));
}

#pragma endregion

#pragma region Initializers

void GameManager::initGLFW()
{
	glfwSetErrorCallback(&GameManager::glfwErrorCallback);

	//Initialize GLFW
	if (glfwInit() == GL_FALSE)
	{
		std::cout << "Error, GLFW did not initialize" << "\n";
		glfwTerminate();
	}
}

void GameManager::initWindow()
{
	//Initialize the window
	this->gameWindow = new Window(640, 480, "Game Engine", true, false);
}

void GameManager::initGLEW()
{
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		std::cout << "Error, Glew did not initialize. Did you create a window before GLEW initializes?" << "\n";
	}
}

void GameManager::initOpenGLOptions()
{
	//OpenGL Options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(OpenGLErrorMessageCallBack, 0);
	//glfwSetKeyCallback(this->gameWindow->getWindow(), Input);

	//glEnable(GL_CULL_FACE);

	//glCullFace(GL_BACK);
	//glFrontFace(GL_CCW);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void GameManager::initSceneManager()
{
	this->sceneManager = new SceneManager();
}

void GameManager::initRenderer()
{
	this->gameRenderer = new Renderer2D(this->gameWindow);
}
#pragma endregion

#pragma region Callbacks

void GameManager::glfwErrorCallback(int id, const char* description)
{
	std::cout << description << "\n";
}

void APIENTRY GameManager::OpenGLErrorMessageCallBack(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
		(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
		type, severity, message);
}

#pragma endregion