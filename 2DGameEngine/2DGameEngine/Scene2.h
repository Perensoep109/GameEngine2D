#pragma once
#include "Scene.h"
#include "TestOBJ.h"
#include <iostream>
class TestScene2
	: public Scene
{
public:
	TestScene2()
		: Scene("Scene2")
	{
		initScene();
	}


	void initScene()
	{
		std::cout << "Initialized testScene2" << "\n";
		for (int i = 0; i < 640 / 64; i++)
		{
			this->sceneObjectManager->addObject(new TestOBJ(new glm::vec2(i * 64, i * 64)));
		}

		this->setBackground(255.f, 0.f, 255.f, 255.f);
	}

	void updateScene()
	{
		
	}
};