#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
//#include "GameObjectManager.h"
#endif // !GAMEOBJECT_H

class GameObjectManager;

enum OBJ_TYPE
{
	Renderable2DE
};

class GameObject
{
private:
	int objectID = 0;
	OBJ_TYPE objectType;
	

public:
	GameObject(OBJ_TYPE);
	~GameObject();

	int getID();

	//Functions
	int generateID();

	bool typeOf(OBJ_TYPE type);
};