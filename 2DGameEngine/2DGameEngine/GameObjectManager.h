#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include <unordered_map>
#include "GameObject.h"
#include "Renderable2D.h"
#include "Renderer2D.h"
#include <iostream>

#endif

class GameObjectManager
{
private:
	static std::unordered_map<int, GameObject*>* gameObjects;
	static void checkError();

public:
	//Fields
	static std::vector<Renderable2D*>* renderObjects;

	//Pool interaction functions
	static void createObject(GameObject* gaeObject);
	static void destroyObject(int objectID);
	static void destroyObject(GameObject* gameObject);
	static GameObject* getObject(int objectID);

	//Deconstructor
	static void clearPool();
	static void deletePool();
};