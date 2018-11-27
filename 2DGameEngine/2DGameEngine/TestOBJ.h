#pragma once
#include "Renderable2D.h"
class TestOBJ
	: public Renderable2D
{
public:
	TestOBJ()
	{
		std::cout << "Created test object" << "\n";
	}
};