#include "Scene.h"
#include <iostream>

Scene::Scene(const char* sceneName)
{
	this->sceneName = sceneName;

	this->sceneObjectManager = new SceneObjectManager();
	this->sceneCamera = new Camera(new glm::vec3(0.f, 0.f, 0.f));
	this->backgroundColor = new float[4] {0.f, 0.f, 0.f, 1.f};
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

const char* Scene::getSceneName()
{
	return this->sceneName;
}

Camera* Scene::getCamera()
{
	return this->sceneCamera;
}

float* Scene::getBackground()
{
	return this->backgroundColor;
}

std::vector<GameObject*>* Scene::getObjectsOfType(const char* typeName)
{
	return this->sceneObjectManager->getObjectsOfType(typeName);
}

//==Setters==//
void Scene::setBackground(float R, float G, float B, float A)
{
	if (R > 1.f)
		this->backgroundColor[0] = R / 255.f;
	else
		this->backgroundColor[0] = R;

	if (G > 1.f)
		this->backgroundColor[1] = G / 255.f;
	else
		this->backgroundColor[1] = G;

	if(B > 1.f)
		this->backgroundColor[2] = B / 255.f;
	else
		this->backgroundColor[2] = B;

	if (A > 1.f)
		this->backgroundColor[3] = A / 255.f;
	else
		this->backgroundColor[3] = A;
}
#pragma endregion