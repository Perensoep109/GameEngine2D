#include "Renderer2D.h"



Renderer2D::Renderer2D(Shader* mainShaderProgram, Window* mainWindow, Camera* mainCamera)
{
	this->mainShader = mainShaderProgram;
	this->mainWindow = mainWindow;
	this->mainCamera = mainCamera;
}

Renderer2D::~Renderer2D()
{
	delete this->mainWindow;
	delete this->mainShader;
	delete this->mainCamera;
}

//Functions:
void Renderer2D::renderFrame()
{
	sendToShader();

	glClearColor(this->clearR, this->clearG, this->clearB, this->clearA);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	//Render the rest

	//End render

	this->mainWindow->swapBuffers();
	glFlush();

	//Reset
	glBindVertexArray(0);
	glUseProgram(0);
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Renderer2D::sendToShader()
{
	this->mainShader->setMat4fv(this->mainWindow->getProjectionMatrix(), "ProjectionMatrix");
	this->mainShader->set1i(1, "objectAmount");
}

void Renderer2D::renderGame()
{
	renderFrame();
}

/*
	glPointSize(10);

	glGenBuffers(1, &VBO);

	float points[] = {
	-0.45f,  0.45f,
	 0.45f,  0.45f,
	 0.45f, -0.45f,
	-0.45f, -0.45f,
	};

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	// Create VAO
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Specify layout of point data
	GLint posAttrib = glGetAttribLocation(mainShader->id, "pos");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
	*/

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