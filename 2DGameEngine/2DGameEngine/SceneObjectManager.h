#pragma once
#include <unordered_map>
#include <vector>
#include "GameObject.h"

class SceneObjectManager
{
private:
	//==Fields==//
	std::unordered_map<const char*, std::vector<GameObject*>*>* gameObjectMap;
	std::unordered_map<const char*, std::vector<GameObject*>*>::iterator gameObjectMapIterator;

	//==Private functions==//
	void addObjectType(const char* typeName);
	void removeObjectType(const char* typeName);
	std::vector<GameObject*>* getObjectTypeVector(const char* typeName);
public:
	SceneObjectManager();
	~SceneObjectManager();

	//==Public functions==//
	void addObject(GameObject* objectToAdd);
	void removeObject(const char* objectName);
	bool containsType(const char* typeName);
	bool containsObject(const char* objectName);

	//==Getters & Setters==//
	//Getters
	GameObject* getObject(const char* objectName);
	std::vector<GameObject*>* getObjectsOfType(const char* typeName);

	//Setters
};

