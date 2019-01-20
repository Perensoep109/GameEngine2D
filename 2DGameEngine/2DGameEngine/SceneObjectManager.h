#pragma once
#include <unordered_map>;
#include <vector>

class GameObject;
class SceneObjectManager
{
private:
	//==Fields==//
	std::unordered_map<const char*, std::vector<GameObject*>>* gameObjectMap;
	std::unordered_map<const char*, std::vector<GameObject*>>::iterator gameObjectMapIterator;

	//==Private functions==//
	void addObjectType(const char* typeName);
	void removeObjectType(const char* typeName);
public:
	SceneObjectManager();
	~SceneObjectManager();

	//==Public functions==//
	void addObject(GameObject* objectToAdd);
	void removeObject();

	//==Getters & Setters==//
	//Getters
	GameObject* getObject(const char* objectName);
	std::vector<GameObject*>* getObjectsOfType(const char* typeName);

	//Setters
};

