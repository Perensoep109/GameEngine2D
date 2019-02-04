#pragma once
#include "Window.h"
#include "Shader.h"
#include "Scene.h"
#include "Renderable2D.h"
#include <vector>

class Scene;
class SceneManager;
class Renderer2D
{
private:
	//Fields
	glm::mat4* ViewMatrix;

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
	//===Fields===//
	GLuint posBuffer;
	const int MAX_INSTANCES = 100000;
	const int INSTANCE_DATA_LENGTH_F = sizeof(glm::vec3);
	const int INSTANCE_DATA_LENGTH_B = INSTANCE_DATA_LENGTH_F * sizeof(float);
	int batchAmount, currentBatch;

	//===Shaders===//
	Shader* gameObjectShader;

	//===Functions===//
	//==Main functions==//
	void setupGameObjectRender();
	void renderGameObjects(std::vector<GameObject*>* gameObjects);
	void sendToGameObjectShader();
	void deleteGameObjectRendering();
	void endGameObjectRender();

	//=Buffer management=//
	void updateBufferData(int objectsToRender, std::vector<GameObject*>* gameObjects);
	void createBuffers();
	void setAttributes();

	//=Object filtering=//
	std::vector<GameObject*>* clipGameObjects(std::vector<GameObject*>* gameObjects);
	std::vector<GameObject*>* filterGameObjects(std::vector<GameObject*>* gameObjects);
	std::vector<GameObject*>* batchGameObjects(std::vector<GameObject*>* gameObjects);

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

	//Getters
	Scene* getCurrentScene();
};

