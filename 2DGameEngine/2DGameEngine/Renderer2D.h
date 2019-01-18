#pragma once
#include "Window.h"
#include "Shader.h"
#include "Camera.h"
#include <vector>

class Scene;
class SceneManager;
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
	Scene*  currentScene;

	//Rendering functions:
#pragma region Rendering functions
	//Instanced rendering functions
	void setupMainRender();

	//Create data
	GLuint createQuadVAO(int tileWidth, int tileHeight);
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

