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
	GLuint createEmptyVBO(int floatCount);

#pragma region Gameobject rendering
	//Variables
	GLuint instanceVBO;
	GLuint quadVAO, quadVBO;
	const int MAX_INSTANCES = 1000;
	const int INSTANCE_DATA_LENGTH = 18;
	int pointer = 0;

	//==Functions==
	//Main functions
	void setupGameObjectRender();
	void updateGameObjectRender(const int objectsToRender);
	void renderGameObjects();
	void sendToGameObjectShader();
	void setAttributes();

	//Create data
	GLuint createQuadVAO();
	std::vector<float>* generateVBOData(int objectsToRender, int amountOfFloats);

	//Store data
	void storeMatrixData(glm::mat4* matrix, std::vector<float>*);
	void storeVec2Data(glm::vec2* vec2, std::vector<float>*);
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

