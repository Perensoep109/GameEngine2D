#pragma once
#include "Renderable2D.h"
class TestOBJ
	: public Renderable2D
{
public:
	TestOBJ(glm::vec3* _position)
	{
		this->setSprite("Graphics/TestSprite.bmp");
		this->position = _position;
		std::cout << "Created test object" << "\n";
	}

	void update()
	{
		std::cout << "Updated test object" << "\n";
	}
};