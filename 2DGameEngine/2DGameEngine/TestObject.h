#pragma once
#include "Renderable2D.h"
class TestOBJ
	: public Renderable2D
{
public:
	TestOBJ()
	{
		this->setSprite("Graphics/TestSprite.bmp");
		std::cout << "Created test object" << "\n";
	}

	void update()
	{
		std::cout << "Updated test object" << "\n";
	}
};