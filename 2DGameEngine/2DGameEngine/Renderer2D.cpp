#include "GameObjectManager.h"
#include <array>


Renderer2D::Renderer2D(Shader* _mainShaderProgram, Window* _mainWindow, Camera* _mainCamera)
{
	this->mainShader = _mainShaderProgram;
	this->mainWindow = _mainWindow;
	this->mainCamera = _mainCamera;

	int index = 0;
	float offset = 0.1f;
	for (int y = -height; y < height; y += 2)
	{
		for (int x = -width; x < width; x += 2)
		{
			glm::vec2 translation;
			translation.x = (float)x / 10.0f + offset;
			translation.y = (float)y / 10.0f + offset;
			translations[index++] = translation;
		}
	}

	setupFrameRender();
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
	//Actual drawing
	glClearColor(this->clearR, this->clearG, this->clearB, this->clearA);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	mainShader->use();
	//sendToShader();

	//checkGLError();

	glBindVertexArray(quadVAO);
	glDrawArraysInstanced(GL_TRIANGLES, 0, 6, objectAmount); // 100 triangles of 6 vertices each
	glBindVertexArray(0);

	this->mainWindow->swapBuffers();
	glfwPollEvents();
}

void Renderer2D::setupFrameRender()
{
	//Create instance VBO
	glGenBuffers(1, &instanceVBO);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * objectAmount, &translations[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Setup vertex data
	float quadVertices[] = {
		// positions     // colors
		-0.05f,  0.05f,  1.0f, 0.0f, 0.0f,
		 0.05f, -0.05f,  0.0f, 1.0f, 0.0f,
		-0.05f, -0.05f,  0.0f, 0.0f, 1.0f,

		-0.05f,  0.05f,  1.0f, 0.0f, 0.0f,
		 0.05f, -0.05f,  0.0f, 1.0f, 0.0f,
		 0.05f,  0.05f,  0.0f, 1.0f, 1.0f
	};

	//Setup quad data
	glGenVertexArrays(1, &quadVAO);
	glGenBuffers(1, &quadVBO);
	glBindVertexArray(quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));

	//Setup instance data
	glGenBuffers(1, &instanceVBO);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * objectAmount, &translations[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO); // this attribute comes from a different vertex buffer
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glVertexAttribDivisor(2, 1); // tell OpenGL this is an instanced vertex attribute.
}

void Renderer2D::sendToShader()
{
	glm::mat4 tempMatrix = *this->mainWindow->getProjectionMatrix();
	glm::mat4 tempMatrix1 = *this->mainCamera->getViewMatrix();

	this->mainShader->setMat4fv(tempMatrix, "ProjectionMatrix");
	this->mainShader->setMat4fv(tempMatrix1, "ViewMatrix");
}

void Renderer2D::checkGLError()
{
	GLenum err;
	err = glGetError();
	if (err == GL_NO_ERROR)
	{
		std::cout << "No error was found\n";
		return;
	}
	std::cout << "OpenGL error: " << err << "\n";
	printf("Error: %s\n", glewGetErrorString(err));
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