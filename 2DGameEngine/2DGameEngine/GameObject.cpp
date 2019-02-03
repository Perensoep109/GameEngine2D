#include "GameObject.h"
#include <iostream>

//===Constructors & Deconstructors===//
//==Constructors==//
GameObject::GameObject()
{
	this->objectTypes = new std::vector<const char*>();
	this->objectTypes->push_back("GameObject");
	this->objectName = "";

	onCreate();
}

GameObject::GameObject(const char* objectName)
{
	this->objectTypes = new std::vector<const char*>();
	this->objectTypes->push_back("GameObject");
	this->objectName = objectName;

	onCreate();
}

//==Deconstructors==//
GameObject::~GameObject()
{
	onDeath();

	delete this->objectName; 
	delete this->objectTypes;
	std::cout << "Removed object" << "\n";
}

//===Functions===//
//==Public==//
bool GameObject::typeOf(const char* type)
{
	for (int i = 0; i < this->objectTypes->size(); i++)
	{
		if (type == this->objectTypes->at(i))
			return true;
	}
	return false;
}

//==Private==//


//==Protected==//
void GameObject::addObjectType(const char* objectType)
{
	this->objectTypes->push_back(objectType);
}

#pragma region Getters & Setters
//===Getters & Setters===//
//==Getters==//
std::vector<const char*>* GameObject::getObjectTypes()
{
	return this->objectTypes;
}

const char* GameObject::getObjectName()
{
	return this->objectName;
}

//==Setters==//
void GameObject::setObjectName(const char* newName)
{
	this->objectName = newName;
}
#pragma endregion

