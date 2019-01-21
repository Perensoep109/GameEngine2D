#include "TestScene.h"
#include <iostream>
#include <glfw3.h>
#include "TestObj.h"

TestScene::TestScene()
	: Scene("TestScene")
{
	initScene();
}


TestScene::~TestScene()
{
}

void TestScene::initScene()
{
	std::cout << "Initialized active scene \n";

	for (int i = 0; i < 12; i++)
	{
		this->sceneObjectManager->addObject(new TestOBJ());
	}
}

void TestScene::updateScene()
{
	std::cout << "Updated active scene" << "\n";

	//if()
}
