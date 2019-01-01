#include "GameObjectManager.h"
#include <array>


Renderer2D::Renderer2D(Shader* _mainShaderProgram, Shader* _gameObjectShader, Window* _mainWindow, Camera* _mainCamera)
{
	this->mainShader = _mainShaderProgram;
	this->gameObjectShader = _gameObjectShader;
	this->mainWindow = _mainWindow;
	this->mainCamera = _mainCamera;

	setupGameObjectRender();
}

Renderer2D::~Renderer2D()
{
	delete this->mainWindow;
	delete this->mainShader;
	delete this->gameObjectShader;
	delete this->mainCamera;

	//Clear VAO's
	glDeleteVertexArrays(1, &quadVAO);
	glDeleteBuffers(1, &quadVBO);
}

//Functions
#pragma region Rendering

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

	this->mainWindow->swapBuffers();
	glfwPollEvents();
}

#pragma region Game object rendering

void Renderer2D::setupGameObjectRender()
{
	//Create the quad VAO
	this->quadVAO = createQuadVAO();

	setAttributes();
}

void Renderer2D::updateGameObjectRender(int objectsToRender)
{
	//Generate a new VBO, buffered with the amount of floats that the VBO will hold
	instanceVBO = createEmptyVBO(objectsToRender * INSTANCE_DATA_LENGTH);

	std::vector<float>* vboData = generateVBOData(objectsToRender, INSTANCE_DATA_LENGTH);

	/*
	
		GENERAL IDEA OF WHAT I'M ATTEMPTING TO DO:
		Instanced rendering, buffer 20 floats to the Vertex shader, these floats will be buffered through the store function
		These functions write to a pseudo buffer, I first create a float array the size of: renderamount * sizeof(float) * amountOfBufferedFloats

		Once the array of floats is filled up, write the array to the VBO.
		Attrib divise the VBO to setup the instanced rendering

		Also setup interleaving
	
		Also bind the quadVBO, this VBO holds the quad mesh.
	*/

	glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * INSTANCE_DATA_LENGTH * objectsToRender, 0, GL_STREAM_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vboData), vboData);
}

void Renderer2D::renderGameObjects()
{
	this->gameObjectShader->use();

	//Send view and projection matrix to the shader
	sendToGameObjectShader(); 
	
	//Update
	int objectAmount = GameObjectManager::getRenderObjectAmount();
	updateGameObjectRender(objectAmount);
	
	//Draw
	glBindVertexArray(this->quadVAO);
	glDrawArraysInstanced(GL_TRIANGLES, 0, 6, objectAmount);

	//Reset & Exit
	glDeleteBuffers(1, &instanceVBO);
	glBindVertexArray(0);
	this->gameObjectShader->unuse();
}

void Renderer2D::sendToGameObjectShader()
{
	gameObjectShader->setMat4fv(*this->mainWindow->getProjectionMatrix(), "ProjectionMatrix");
	gameObjectShader->setMat4fv(*this->mainCamera->getViewMatrix(), "ViewMatrix");
}

//Auxiliary functions:
GLuint Renderer2D::createQuadVAO()
{
	//Variables
	GLuint returnVAO;

	float quadVertices[] = {
		0.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,

		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
	};

	//Create array:
	glGenVertexArrays(1, &returnVAO);
	glGenBuffers(1, &quadVBO);

	glBindVertexArray(returnVAO);
	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);

	return returnVAO;
}

//Create an empty VBO at the max size of floatCount x 4
GLuint Renderer2D::createEmptyVBO(int floatCount)
{
	GLuint returnVBO;

	//Create VBO
	glGenBuffers(1, &returnVBO);
	glBindBuffer(GL_ARRAY_BUFFER, returnVBO);
	glBufferData(GL_ARRAY_BUFFER, floatCount * 4, 0, GL_STREAM_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return returnVBO;
}

std::vector<float>* Renderer2D::generateVBOData(int objectsToRender, int amountOfFloats)
{
	std::vector<float>* returnVector = new std::vector<float>();

	for (int i = 0; i < objectsToRender; i++)
	{
		storeVec2Data(GameObjectManager::renderObjects->at(i)->getPosition(), returnVector);
		storeMatrixData(GameObjectManager::renderObjects->at(i)->getInstanceMatrix(), returnVector);
	}

	return returnVector;
}

//Store data in VBO
void Renderer2D::storeMatrixData(glm::mat4* matrix, std::vector<float>* vboData)
{
	for (int x = 0; x < 3; x++)
	{
		glm::vec4 tempVec = matrix[x][0];
		for (int y = 0; y < 3; y++)
		{
			vboData->push_back(tempVec[y]);
		}
	}
}

void Renderer2D::storeVec2Data(glm::vec2* vec2, std::vector<float>* vboData)
{
	vboData->push_back(vec2->x);
	vboData->push_back(vec2->y);
}

void Renderer2D::setAttributes()
{
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

	//Location 1: (Instance matrix)
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(1 * sizeof(glm::vec4) - sizeof(glm::vec2)));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(glm::vec4) - sizeof(glm::vec2)));

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(3 * sizeof(glm::vec4) - sizeof(glm::vec2)));

	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(4 * sizeof(glm::vec4) - sizeof(glm::vec2)));

	//Divide the attributes into instances (not into vertices)
	glVertexAttribDivisor(0, 0);
	glVertexAttribDivisor(1, 1);
	glVertexAttribDivisor(2, 1);
	glVertexAttribDivisor(3, 1);
	glVertexAttribDivisor(4, 1);
}

#pragma endregion

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