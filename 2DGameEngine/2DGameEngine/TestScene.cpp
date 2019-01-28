#include "TestScene.h"
#include <iostream>
#include <glfw3.h>
#include <stdlib.h>
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
	this->speed = 10.f;
	this->sceneObjectManager->addObject(ball = new TestOBJ(new glm::vec2(320.f, 240.f)));
	direction = glm::vec2(rand() % 2, rand() % 2);
}

void TestScene::updateScene()
{
	//Move ball:
	position = *this->ball->getPosition();

	if (!(position.x > 640 || position.x < 0 || position.y > 480 || position.y < 0))
	{
		this->ball->setPosition(this->position + this->direction * this->speed);
	}
	else
	{
		direction = glm::vec2(rand() % 2, rand() % 2);
		position = glm::vec2(320.f, 240.f);
		this->ball->setPosition(this->position);
		std::cout << direction.x << "<- X Y ->" << direction.y << "\n";
	}
}
