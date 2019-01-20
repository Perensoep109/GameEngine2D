#include "Scene.h"

Scene::Scene(const char* sceneName)
{
	this->sceneName = sceneName;
}


Scene::~Scene()
{
	delete this->sceneComponents;
	delete this->sceneCamera;
	delete this->sceneObjectManager;
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
//==Setters==//


#pragma endregion