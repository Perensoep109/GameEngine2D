#pragma once
#include "GameObject.h"
#include <glm.hpp>

class TestOBJ
	: public GameObject
{
private:
	glm::vec3* position;

public:
	TestOBJ(glm::vec3* position)
	{
		this->position = position;
		this->setObjectType("TestObject");
	}

	glm::vec3* getPosition()
	{
		return this->position;
	}
};