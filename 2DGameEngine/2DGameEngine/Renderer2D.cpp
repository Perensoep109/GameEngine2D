#include "Renderer2D.h"
#include <array>


Renderer2D::Renderer2D(Window* renderTarget)
{
	this->mainWindow = renderTarget;

	setupMainRender();
	setupGameObjectRender();
}

Renderer2D::~Renderer2D()
{
	delete this->mainWindow;
	delete this->mainShader;

	deleteGameObjectRendering();
}

//Functions
#pragma region Rendering
void Renderer2D::setupMainRender()
{
	this->quadVAO = createQuadVAO(9, 9);
}

void Renderer2D::renderGame()
{
	this->ViewMatrix = this->currentScene->getCamera()->getViewMatrix();
	renderFrame();
}

void Renderer2D::renderFrame()
{
	this->renderScene();

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

#pragma endregion