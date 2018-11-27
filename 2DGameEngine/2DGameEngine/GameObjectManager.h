#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include <unordered_map>
#include "GameObject.h"
#include "Renderable2D.h"
#include <iostream>

#endif

class GameObjectManager
{
private:
	static std::unordered_map<int, GameObject*>* gameObjects;
	static std::list<int>* renderObjects;
	static void checkError();

public:

	//Pool interaction functions
	static void createObject(GameObject* gaeObject);
	static void destroyObject(int objectID);
	static void destroyObject(GameObject* gameObject);

	//Deconstructor
	static void clearPool();
	static void deletePool();
};