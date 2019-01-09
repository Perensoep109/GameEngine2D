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
	this->quadVAO = createQuadVAO();
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

	this->mainWindow->swapBuffers();
	glfwPollEvents();
}

//==General Data Creation==
GLuint Renderer2D::createQuadVAO()
{
	//Variables
	GLuint returnVAO;

	float quadVertices[] = {
		-100.f, 100.0f,
		100.0f, -100.f,
		-100.f, -100.f,

		-100.f, 100.f,
		100.f, -100.f,
		100.f, 100.f
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

#pragma region General Data Storage

//Store matrix data into float vector
//Vectors
void Renderer2D::storeVec2Data(glm::vec2* vec2, std::vector<float>* vboData)
{
	for (int i = 0; i < 2; i++)
	{
		vboData->push_back(vec2[0][i]);
	}
}

void Renderer2D::storeVec3Data(glm::vec3* vec3, std::vector<float>* vboData)
{
	for (int i = 0; i < 3; i++)
	{
		vboData->push_back(vec3[0][i]);
	}
}

void Renderer2D::storeVec4Data(glm::vec4* vec4, std::vector<float>* vboData)
{
	for (int i = 0; i < 2; i++)
	{
		vboData->push_back(vec4[0][i]);
		//vboData->push_back(vec4[0][position + stride]);
	}
}

//Matrices
void Renderer2D::storeMat4Data(glm::mat4* matrix, std::vector<float>* vboData, int objectAmount, int currentObject)
{
	int componentJump = objectAmount * 4;
	int offset = currentObject * 4;
	for (int x = 0; x < 4; x++)
	{
		glm::vec4 tempVec = matrix[x][0];
		for (int y = 0; y < 4; y++)
		{
			vboData->at(y * componentJump + x) = tempVec[y];
		}
	}
}

void Renderer2D::storeMat4Data(glm::mat4* matrix, std::vector<float>* vboData)
{
	for (int x = 0; x < 4; x++)
	{
		glm::vec4 tempVec = matrix[x][0];
		for (int y = 0; y < 4; y++)
		{
			//vboData->at(x * 4 + y) = tempVec[y];
			vboData->push_back(tempVec[y]);
		}
	}
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