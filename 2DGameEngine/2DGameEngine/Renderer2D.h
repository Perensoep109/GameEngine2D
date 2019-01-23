#pragma once
#include "Window.h"
#include "Shader.h"
#include "Scene.h"
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
	Window* mainWindow;

	//Rendering functions:
#pragma region Rendering functions
	//General quad type
	GLuint quadVAO, quadVBO;

	//Instanced rendering functions
	void setupMainRender();

	//Create data
	GLuint createQuadVAO(int tileWidth, int tileHeight);
#pragma endregion

#pragma region Scene rendering
	//==Private==//
	//Fields
	Scene* currentScene;

	//Functions
	void setupSceneRender();
	void renderScene();
	void endSceneRender();
	void deleteSceneRender();

#pragma endregion

#pragma region Gameobject rendering
	//Variables
	GLuint posBuffer;
	const int MAX_INSTANCES = 1000;
	const int INSTANCE_DATA_LENGTH_F = sizeof(glm::vec4);
	const int INSTANCE_DATA_LENGTH_B = INSTANCE_DATA_LENGTH_F * sizeof(float);

	//==Shaders==//
	Shader* gameObjectShader;

	//==Functions==
	//Main functions
	void setupGameObjectRender();
	void renderGameObjects(std::vector<GameObject*>* gameObjects);
	void sendToGameObjectShader();
	void updateBufferData(int objectsToRender, std::vector<GameObject*>* gameObjects);
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
	Renderer2D(Window* renderTarget);
	~Renderer2D();

	void renderGame();

	//Setters
	void setCurrentScene(Scene* newScene);
	void setBackgroundColor(float R, float G, float B, float A);

	//Getters
	Scene* getCurrentScene();
	float getClearR();
	float getClearG();
	float getClearB();
	float getClearA();
};

