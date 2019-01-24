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
	std::cout << "Initialized test scene 1 scene \n";
	startScene();
}

void TestScene::startScene()
{
	this->sceneObjectManager->addObject(ball = new TestOBJ(new glm::vec2(320.f, 240.f)));
}

void TestScene::updateScene()
{
	//Move ball:
	this->ball->setPosition = *this->ball->getPosition() + glm::vec2(0.1f, 0.f);
}
