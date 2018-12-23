#include "GameObjectManager.h"
#include <random>

GameObject::GameObject(OBJ_TYPE objectType)
{
	this->objectID = generateID();
	this->objectType = objectType;

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

bool GameObject::typeOf(OBJ_TYPE type)
{
	if (this->objectType == type)
		return true;
	return false;
}
