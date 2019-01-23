#pragma once

#include "SceneObjectManager.h"
#include "SceneComponent.h"
#include <vector>

class Camera;

class Scene
{
private:
#pragma region Private variables

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
	std::string sceneName;
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
	virtual void updateScene() = 0;

	//Input
	void keyboardInput(int key, int scancode, int action, int mods);

	//Set scene state
	void activate();
	void deactivate();
#pragma endregion


#pragma region Getters & Setters
	//Getters
	bool getActive();
	std::string getSceneName();
	Camera* getCamera();

	//Get scene game objects
	std::vector<GameObject*>* getObjectsOfType(const char* typeName);

	//Setters

#pragma endregion

};

