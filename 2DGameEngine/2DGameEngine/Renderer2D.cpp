#include "GameObjectManager.h"
#include <array>


Renderer2D::Renderer2D(Shader* _mainShaderProgram, Shader* _gameObjectShader, Window* _mainWindow, Camera* _mainCamera)
{
	this->mainShader = _mainShaderProgram;
	this->gameObjectShader = _gameObjectShader;
	this->mainWindow = _mainWindow;
	this->mainCamera = _mainCamera;

	setupMainRender();
	setupGameObjectRender();
}

Renderer2D::~Renderer2D()
{
	delete this->mainWindow;
	delete this->mainShader;
	delete this->mainCamera;

	deleteGameObjectRendering();
}

//Functions
#pragma region Rendering
void Renderer2D::setupMainRender()
{
	this->quadVAO = createQuadVAO(64, 64);
}

void Renderer2D::renderGame()
{
	renderFrame();
}

void Renderer2D::renderFrame()
{
	//Actual drawing
	glClearColor(this->clearR, this->clearG, this->clearB, this->clearA);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	this->renderGameObjects();

	this->mainWindow->refreshWindow();
	glfwPollEvents();
}

//==General Data Creation==
GLuint Renderer2D::createQuadVAO(int tileWidth, int tileHeight)
{
	//Variables
	GLuint returnVAO;

	float quadVertices[] = {
		-tileWidth / 2, tileHeight / 2,
		tileWidth / 2 , -tileHeight / 2,
		-tileWidth / 2, -tileHeight / 2,

		-tileWidth / 2, tileHeight / 2,
		tileWidth / 2, -tileHeight / 2,
		tileWidth / 2, tileHeight / 2
	};

	//Create array:
	glGenVertexArrays(1, &returnVAO);
	glGenBuffers(1, &quadVBO);

	glBindVertexArray(returnVAO);
	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), NULL);

	return returnVAO;
}

#pragma region Tilemap rendering

#pragma endregion

#pragma endregion

#pragma region Getters & Setters
//Getters
float Renderer2D::getClearR()
{
	return this->clearR;
}

float Renderer2D::getClearG()
{
	return this->clearG;
}

float Renderer2D::getClearB()
{
	return this->clearB;
}

float Renderer2D::getClearA()
{
	return this->clearA;
}

//Setters
void Renderer2D::setBackgroundColor(float R, float G, float B, float A)
{
	this->clearR = R;
	this->clearG = G;
	this->clearB = B;
	this->clearA = A;
}

#pragma endregion