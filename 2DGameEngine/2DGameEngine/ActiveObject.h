#pragma once
#include "GameObject.h"
class ActiveObject
	: public GameObject
{
public:
	//Overidable methods:
	virtual void update() = 0;
};

