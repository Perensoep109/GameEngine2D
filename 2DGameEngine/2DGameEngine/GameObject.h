#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
//#include "GameObjectManager.h"
#endif // !GAMEOBJECT_H

class GameObjectManager;

class GameObject
{
private:
	int objectID = 0;

public:
	GameObject();
	~GameObject();

	int getID();

	//Functions
	int generateID();
};