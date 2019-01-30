#include "SceneObjectManager.h"
#include <iostream>
#include <string>

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
		this->gameObjectTypes->push_back(typeName);
	}
}

void SceneObjectManager::addObjectType(GameObject* object)
{
	//Scan through all the paramenter object its types. If a type does NOT exist, add it to the list.
	std::vector<const char*>* objectTypes = object->getObjectTypes();
	for (int i = 0; i < objectTypes->size(); i++)
	{
		this->gameObjectMapIterator = this->gameObjectMap->find(objectTypes->at(i));

		if (this->gameObjectMap->end() == this->gameObjectMapIterator)
		{
			//Add this object type, it does not exist yet.
			this->gameObjectMap->insert({ objectTypes->at(i), new std::vector<GameObject*>()});
			std::cout << "Added new object type: " << objectTypes->at(i) << "\n";
		}
	}
}

void SceneObjectManager::removeObjectType(const char* typeName)
{
	if (typeName != nullptr)
	{
		if (this->containsType(typeName))
		{
			this->gameObjectMap->erase(typeName);
			removeObjectsOfType(typeName);
		}
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
	std::vector<GameObject*>* objectVector;
	for (int i = 0; i < objectTypes->size(); i++)
	{
		if ((objectVector = this->getObjectTypeVector(objectTypes->at(i))) == nullptr)
		{
			//Add the new object type, this type does not exist yet
			this->addObjectType(objectToAdd);
			this->getObjectTypeVector(objectTypes->at(i))->push_back(objectToAdd);
			std::cout << "Added new object type: " << objectTypes->at(i) << "\n";
		}
		else
		{
			this->getObjectTypeVector(objectTypes->at(i))->push_back(objectToAdd);
		}
	}
}

void SceneObjectManager::removeObject(const char* objectName)
{
	if (containsObject(objectName))
	{
		//GameObject* object;
		//this->getObjectTypeVector(this->)
	}
}

void SceneObjectManager::removeObjectsOfType(const char * typeName)
{
	if (containsType(typeName))
	{
		this->gameObjectMap->erase(this->gameObjectMapIterator->first);
	}
}

void SceneObjectManager::removeAllObjects()
{
	/*

	An algorithm that iterates through every object type, removes all the entries in the list. 

	*/

	for (int i = 0; i < this->gameObjectMap->size(); i++)
	{
		
	}
}

bool SceneObjectManager::containsType(const char* typeName)
{
	this->gameObjectMapIterator = gameObjectMap->find(typeName);

	if(this->gameObjectMapIterator == this->gameObjectMap->end())
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

//===Converters===//
std::string* SceneObjectManager::toString()
{
	return new std::string("Amount of game objects: " + std::to_string(this->gameObjectMap->at(this->gameObjectMap->find("GameObject")->first)->size()) + "\n" + 
		"Amount of game object types: " + std::to_string(this->gameObjectMap->size()) + "\n"
	);
}