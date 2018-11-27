#include "GameObjectManager.h"
#include <random>

GameObject::GameObject()
{
	this->objectID = generateID();

	//Add this object to the list
	GameObjectManager::createObject(this);
}

GameObject::~GameObject()
{
	//Remove this object from the object manager
	GameObjectManager::destroyObject(this->objectID);
}

int GameObject::getID()
{
	return this->objectID;
}

int GameObject::generateID()
{
	return rand() % INT32_MAX;
}