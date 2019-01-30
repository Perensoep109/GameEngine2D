#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
{
	this->objectTypes = new std::vector<const char*>();
	this->objectTypes->push_back("GameObject");
}


GameObject::~GameObject()
{
	delete this->objectName; 
	delete this->objectTypes;
	std::cout << "Removed object" << "\n";
}

std::vector<const char*>* GameObject::getObjectTypes()
{
	return this->objectTypes;
}

const char* GameObject::getObjectName()
{
	return this->objectName;
}

bool GameObject::typeOf(const char* type)
{
	for (int i = 0; i < this->objectTypes->size(); i++)
	{
		if (type == this->objectTypes->at(i))
			return true;
	}
	return false;
}

void GameObject::addObjectType(const char* objectType)
{
	this->objectTypes->push_back(objectType);
}
