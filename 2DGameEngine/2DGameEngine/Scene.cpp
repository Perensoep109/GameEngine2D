#include "Scene.h"
#include <iostream>

Scene::Scene(const char* sceneName)
{
	this->sceneName = sceneName;

	this->sceneObjectManager = new SceneObjectManager();
}


Scene::~Scene()
{
	delete this->sceneComponents;
	delete this->sceneCamera;
	delete this->sceneObjectManager;
}

void Scene::keyboardInput(int key, int scancode, int action, int mods)
{
	std::cout << key << "\n";
}

void Scene::activate()
{
	this->isActive = true;
}

void Scene::deactivate()
{
	this->isActive = false;
}

//==Scene loading==//
void Scene::loadScene()
{

}

void Scene::unloadScene()
{
	
}

#pragma region Getters & Setters
//==Getters==//
bool Scene::getActive()
{
	return this->isActive;
}

std::string Scene::getSceneName()
{
	return this->sceneName;
}

Camera* Scene::getCamera()
{
	return this->sceneCamera;
}

std::vector<GameObject*>* Scene::getObjectsOfType(const char* typeName)
{
	return this->sceneObjectManager->getObjectsOfType(typeName);
}

//==Setters==//


#pragma endregion