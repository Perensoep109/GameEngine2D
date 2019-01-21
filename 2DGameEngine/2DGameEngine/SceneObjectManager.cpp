#include "SceneObjectManager.h"
#include <iostream>

SceneObjectManager::SceneObjectManager()
{
	this->gameObjectMap = new std::unordered_map<const char*, std::vector<GameObject*>*>();
	this->gameObjectMap->insert({"GameObject", new std::vector<GameObject*>()});
}

SceneObjectManager::~SceneObjectManager()
{
	delete this->gameObjectMap;
}

//==Private functions==//
void SceneObjectManager::addObjectType(const char* typeName)
{
	if (typeName != nullptr)
	{
		if (this->containsType(typeName))
			return;

		//This object type does not yet exist!
		this->gameObjectMap->insert({typeName, new std::vector<GameObject*>()});
	}
}

void SceneObjectManager::removeObjectType(const char* typeName)
{
	if (typeName != nullptr)
	{
		if(this->containsType(typeName))
			this->gameObjectMap->erase(typeName);
	}
}

std::vector<GameObject*>* SceneObjectManager::getObjectTypeVector(const char* typeName)
{
	if (this->containsType(typeName))
	{
		return this->gameObjectMap->at(gameObjectMapIterator->first);
	}
	return  nullptr;
}

//==Public functions==//
//Pool interaction
void SceneObjectManager::addObject(GameObject* objectToAdd)
{
	std::vector<const char*>* objectTypes = objectToAdd->getObjectTypes();
	for (int i = 0; i < objectTypes->size(); i++)
	{
		this->getObjectTypeVector(objectTypes->at(i))->push_back(objectToAdd);
	}
}

void SceneObjectManager::removeObject(const char* objectName)
{
	
}

bool SceneObjectManager::containsType(const char* typeName)
{
	this->gameObjectMapIterator = gameObjectMap->find(typeName);

	if(this->gameObjectMapIterator != this->gameObjectMap->end())
		return false;
	return true;
}

bool SceneObjectManager::containsObject(const char* objectName)
{
	std::vector<GameObject*>* gameObjectVector = this->gameObjectMap->at(this->gameObjectMapIterator->first);

	for (int i = 0; i < gameObjectVector->size(); i++)
	{
		if (gameObjectVector->at(i)->getObjectName() == objectName)
			return true;
	}

	return false;
}


//==Getters==//
std::vector<GameObject*>* SceneObjectManager::getObjectsOfType(const char* typeName)
{
	if(!this->containsType(typeName))
		return nullptr;
	return this->gameObjectMap->at(this->gameObjectMapIterator->first);
}

GameObject* SceneObjectManager::getObject(const char* objectName)
{
	//Filter the object name out of the complete list of game objects
	if (!this->containsType("GameObject"))
	{
		std::vector<GameObject*>* gameObjectVector = this->gameObjectMap->at(this->gameObjectMapIterator->first);

		//Filter map
		for (int i = 0; i < gameObjectVector->size(); i++)
		{
			if (gameObjectVector->at(i)->getObjectName() == objectName)
			{
				return gameObjectVector->at(i);
			}
		}
	}

	std::cout << "No game object has been found with name: " << objectName << "\n";
	return nullptr;
}