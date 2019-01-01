#pragma once
#include "Renderable2D.h"
class TestOBJ
	: public Renderable2D
{
public:
	TestOBJ(glm::vec2* _position)
		: Renderable2D("Graphics/TestSprite.bmp", _position)
	{
		this->position = _position;
		std::cout << "Created test object" << "\n";
	}
};