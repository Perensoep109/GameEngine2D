#include "SceneManager.h"
#include <iostream>


SceneManager::SceneManager()
{
	this->sceneMap = new std::unordered_map<std::string, Scene*>();
}


SceneManager::~SceneManager()
{
	this->removeAllScenes();
	delete this->sceneMap;
}

#pragma region Public functions

//==Scene pool interaction functions==//
void SceneManager::addScene(Scene* sceneToAdd)
{
	this->sceneMap->insert({sceneToAdd->getSceneName(), sceneToAdd});
}

Scene* SceneManager::getScene(std::string sceneName)
{
	this->sceneMapIterator = this->sceneMap->find(sceneName);

	if (sceneMapIterator == sceneMap->end())
	{
		std::cout << "Scene: " << sceneName << " does not exist!" << "\n";
		return nullptr;
	}

	return this->sceneMap->at(this->sceneMapIterator->first);
}

void SceneManager::removeScene(std::string sceneName)
{
	this->sceneMap->erase(sceneName);
}

void SceneManager::removeAllScenes()
{
	this->sceneMap->clear();
}

void SceneManager::activateScene(std::string sceneName, bool reload)
{
	if (sceneMap->find(sceneName) != sceneMap->end())
		this->activeSceneName = sceneName;
	else
	{
		std::cout << "Scene cannot be found, scene: " << sceneName << " does not exist." << "\n";
		return;
	}

	if (reload)
		this->getActiveScene()->reloadScene();
}

void SceneManager::deactivateScene(std::string sceneName)
{
	this->activeSceneName = "";
}

void SceneManager::deactivateScene(std::string sceneName, std::string newActiveScene, bool reload)
{
	this->activateScene(newActiveScene, reload);
}

void SceneManager::updateActiveScene()
{
	//this->getActiveScene()->updateScene();
}

#pragma endregion

#pragma region Getters & Setters

Scene* SceneManager::getActiveScene()
{
	return this->getScene(this->activeSceneName);
}

#pragma endregion
