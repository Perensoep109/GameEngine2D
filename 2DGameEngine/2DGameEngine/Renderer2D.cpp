#include "Renderer2D.h"



Renderer2D::Renderer2D(Shader* mainShaderProgram, Window* mainWindow)
{
	this->mainShader = mainShaderProgram;
	this->mainWindow = mainWindow;
}

Renderer2D::~Renderer2D()
{
	delete this->mainWindow;
	delete this->mainShader;
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
}

void Renderer2D::renderGame()
{
	renderFrame();
}

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