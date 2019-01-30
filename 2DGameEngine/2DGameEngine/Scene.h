#pragma once

#include "SceneObjectManager.h"
#include "SceneComponent.h"
#include <vector>

class Camera;

class Scene
{
private:
#pragma region Private variables
	float* backgroundColor;
	const char* sceneName;
#pragma endregion

#pragma region Private functions

	//==Scene loading==//
	void loadScene();
	void unloadScene();

#pragma endregion

protected:
#pragma region Protected variables
	//Scene components
	Camera* sceneCamera;
	SceneObjectManager* sceneObjectManager;
	std::vector<SceneComponent*>* sceneComponents;
	
	//Scene variables
	bool isActive;
#pragma endregion


#pragma region Protected functions

#pragma endregion

public:
	Scene(const char* sceneName);
	~Scene();

#pragma region Public variables
	
#pragma endregion

#pragma region Public functions
	//Abstract functions
	virtual void initScene() = 0;
	virtual void startScene() = 0;
	virtual void updateScene() = 0;
	virtual void reloadScene() = 0;

	//Input
	void keyboardInput(int key, int scancode, int action, int mods);

	//Set scene state
	void activate();
	void deactivate();
#pragma endregion


#pragma region Getters & Setters
	//Getters
	bool getActive();
	const char* getSceneName();
	Camera* getCamera();
	float* getBackground();

	//Get scene game objects
	std::vector<GameObject*>* getObjectsOfType(const char* typeName);

	//Setters
	void setBackground(float R, float G, float B, float A);

#pragma endregion

};

