#include "GameObjectManager.h"
#include <typeinfo>

std::unordered_map<int, GameObject*>*::GameObjectManager::gameObjects = new std::unordered_map<int, GameObject*>();
std::list<int>* renderObjects = new std::list<int>();

void GameObjectManager::createObject(GameObject* gameObject)
{
	//Check if the object pool exists:
	GameObjectManager::checkError();
	
	if (GameObjectManager::gameObjects->insert({ gameObject->getID(), gameObject }).second == false)
	{
		//This object already exists, generate a new object ID
		gameObject->generateID();
		GameObjectManager::createObject(gameObject);
	}

	//Add this object to the renderable list if it is a renderable type
	const std::type_info& typeInfo = typeid(*gameObject);

	if (typeInfo == typeid(Renderable2D))
	{
		//This object is a renderable, add the key to the renderobjects list
		std::cout << "Renderable created! Adding it to the render key list ID: " << gameObject->getID() << "\n";
		renderObjects->push_back(gameObject->getID());
	}
}



void GameObjectManager::destroyObject(int objectID)
{
	//Check if the object pool exists:
	GameObjectManager::checkError();

	GameObjectManager::gameObjects->erase(objectID);
}



void GameObjectManager::destroyObject(GameObject* gameObject)
{	
	GameObjectManager::destroyObject(gameObject->getID());
}



void GameObjectManager::clearPool()
{
	//Check if the object pool exists:
	GameObjectManager::checkError();

	GameObjectManager::gameObjects->clear();
}



void GameObjectManager::deletePool()
{
	GameObjectManager::checkError();

	delete gameObjects;
}



void GameObjectManager::checkError()
{
	if (gameObjects == nullptr)
		throw "Interaction with non existant object pool";
}