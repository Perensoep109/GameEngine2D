#pragma once
#include <unordered_map>
#include <string>
#include "Scene.h"
class SceneManager
{
private:
#pragma region Private variables
	//Scene pool management variables
	std::unordered_map<std::string, Scene*>* sceneMap;
	std::unordered_map<std::string, Scene*>::iterator sceneMapIterator;
	std::string activeSceneName;


#pragma endregion

#pragma region Private functions
	//Scene loading
	Scene* loadScene(std::string sceneFileName);
	void unloadScene();
#pragma endregion


public:
	SceneManager();
	~SceneManager();

	//Scene pool interaction:
	void addScene(Scene* sceneToAdd);
	void removeScene(std::string sceneName);
	void removeAllScenes();
	void activateScene(std::string sceneName);
	void deactivateScene(std::string sceneName);
	void deactivateScene(std::string sceneName, std::string newActiveScene);

	//Active scene methods
	void updateActiveScene();

#pragma region Getters / Setters
	//==Getters==//
	Scene* getScene(std::string sceneName);
	Scene* getActiveScene();

	//==Setters==//
#pragma endregion

};

