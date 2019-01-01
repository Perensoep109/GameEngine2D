#include "GameObjectManager.h"
#include <typeinfo>

std::unordered_map<int, GameObject*>*::GameObjectManager::gameObjects = new std::unordered_map<int, GameObject*>();
std::vector<Renderable2D*>*::GameObjectManager::renderObjects = new std::vector<Renderable2D*>();

void GameObjectManager::createObject(GameObject* gameObject)
{
	//Check if the object pool exists:
	GameObjectManager::checkError();
	GameObjectManager::insertObject(gameObject);

	if (gameObject->typeOf(OBJ_TYPE::Renderable2DE))
	{
		renderObjects->push_back((Renderable2D*)gameObject);
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

bool GameObjectManager::insertObject(GameObject* gameObject)
{
	if (GameObjectManager::gameObjects->insert({ gameObject->getID(), gameObject }).second == true)
	{
		//This object already exists, generate a new object ID
		gameObject->generateID();
		std::cout << "ID already exists! ID: " << gameObject->getID() << "\n";

		GameObjectManager::insertObject(gameObject);
	}
	return true;
}

int GameObjectManager::getRenderObjectAmount()
{
	return renderObjects->size();
}