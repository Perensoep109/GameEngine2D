#pragma once
#include "Window.h"
#include "Shader.h"
#include "Camera.h"
#include <vector>

class Renderer2D
{
private:
	//Fields
	float clearR = 0.f, clearG = 0.f, clearB = 0.f, clearA = 0.f;

	//Components:
	Shader* mainShader;
	Shader* gameObjectShader;
	Shader* tileMapShader;
	Window* mainWindow;
	Camera* mainCamera;

	//Rendering functions:
#pragma region Rendering functions
	//Instanced rendering functions
	void setupMainRender();

	//Create data
	GLuint createQuadVAO(int tileWidth, int tileHeight);

#pragma region Store data
	//Matrices
	void storeMat4Data(glm::mat4* matrix, std::vector<float>* vboData);													//Store data non interleaved
	void storeMat4Data(glm::mat4* matrix, std::vector<float>* vboData, int objectAmount, int currentObject = 0);		//Store data interleaved

	//Vectors:
	void storeVec2Data(glm::vec2* vec2, std::vector<float>* vboData);
	void storeVec3Data(glm::vec3* vec3, std::vector<float>* vboData);
	void storeVec4Data(glm::vec4* vec4, std::vector<float>* vboData);
#pragma endregion

#pragma region Gameobject rendering
	//Variables
	GLuint quadVAO, quadVBO;
	GLuint posBuffer;
	const int MAX_INSTANCES = 1000;
	const int INSTANCE_DATA_LENGTH_F = sizeof(glm::vec4);
	const int INSTANCE_DATA_LENGTH_B = INSTANCE_DATA_LENGTH_F * sizeof(float);

	//==Functions==
	//Main functions
	void setupGameObjectRender();
	void renderGameObjects();
	void sendToGameObjectShader();
	void updateBufferData(int objectsToRender);
	void createBuffers();
	void setAttributes();
	void deleteGameObjectRendering();
	void endGameObjectRender();
#pragma endregion

#pragma region Tilemap rendering

#pragma endregion

#pragma endregion

	void renderFrame();
public:
	Renderer2D(Shader* mainShaderProgram, Shader* gameObjectShader, Window* mainWindow, Camera* mainCamera);
	~Renderer2D();

	void renderGame();

	//Setters
	void setBackgroundColor(float R, float G, float B, float A);

	//Getters
	float getClearR();
	float getClearG();
	float getClearB();
	float getClearA();
};

