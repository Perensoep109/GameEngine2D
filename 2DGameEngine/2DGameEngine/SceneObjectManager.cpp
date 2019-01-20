#include "SceneObjectManager.h"

SceneObjectManager::SceneObjectManager()
{
	this->gameObjectMap = new std::unordered_map<const char*, std::vector<GameObject*>>();
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
		this->gameObjectMapIterator = gameObjectMap->find(typeName);

		if (this->gameObjectMapIterator != this->gameObjectMap->end())
		{
			//This object type does not yet exist!
			this->gameObjectMap->insert({typeName, new std::vector<GameObject*>()});
		}
	}
}

void SceneObjectManager::removeObjectType(const char* typeName)
{
}

//==Public functions==//
//Pool interaction
void SceneObjectManager::addObject(GameObject* objectToAdd)
{
}

void SceneObjectManager::removeObject()
{
}

//==Getters==//
std::vector<GameObject*>* SceneObjectManager::getObjectsOfType(const char* typeName)
{
	return nullptr;
}

GameObject* SceneObjectManager::getObject(const char* objectName)
{
	return nullptr;
}