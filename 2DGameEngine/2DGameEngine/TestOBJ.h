#pragma once
#include "GameObject.h"

class TestOBJ
	: public GameObject
{

public:
	TestOBJ()
	{
		this->setObjectType("TestObject");
	}
};