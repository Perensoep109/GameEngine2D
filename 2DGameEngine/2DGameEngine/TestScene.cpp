#include "TestScene.h"
#include <iostream>
#include <glfw3.h>


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


}

void TestScene::updateScene()
{
	std::cout << "Updated active scene" << "\n";

	//if()
}
