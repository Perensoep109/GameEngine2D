#pragma once

#include "SceneObjectManager.h"
#include "SceneComponent.h"
#include <vector>

class Scene
{
private:
#pragma region Private variables

#pragma endregion

#pragma region Private functions

#pragma endregion

protected:
#pragma region Protected variables
	//Scene components
	SceneObjectManager* sceneObjectManager;
	std::vector<SceneComponent*> sceneComponents;
	
	//Scene variables
	const char* sceneName;
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
	virtual void initScene() = 0;
	virtual void updateScene() = 0;

	//Set scene state
	void activate();
	void deactivate();
#pragma endregion


#pragma region Getters & Setters
	//Getters
	bool getActive();
	const char* getSceneName();

	//Setters

#pragma endregion

};

