#pragma once
#include "Renderable2D.h"
#include <glm.hpp>

class TestOBJ
	: public Renderable2D
{
private:

public:
	TestOBJ(glm::vec2* position)
	{
		this->position = position;
		this->addObjectType("TestObject");
	}
};