#include "TestScene.h"
#include <iostream>
#include <glfw3.h>
#include <stdlib.h>

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
	for (int i = 0; i < 5000; i++)
	{
		this->sceneObjectManager->addObject(ball = new Ball(glm::vec2(320.f, 240.f), 10.f));
	}
}

void TestScene::updateScene()
{
	std::vector<GameObject*>* objects = this->sceneObjectManager->getObjectsOfType("Renderable2D");

	for (int i = 0; i < objects->size(); i++)
	{
		static_cast<Ball*>(objects->at(i))->update();
	}
}

void TestScene::reloadScene()
{
	this->sceneObjectManager->removeAllObjects();
}
