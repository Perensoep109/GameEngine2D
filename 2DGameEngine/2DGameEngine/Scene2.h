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
			this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(i * 64, i * 64, 0)));
		}
	}

	void updateScene()
	{
		std::cout << "Updated testScene2 scene" << "\n";
	}
};
/*
#include "TestScene.h"
#include <iostream>
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
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(0.0f, 0.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(10.f, 25.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(430.f, 150.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(0.f, 35.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(600.f, 0.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(0.f, 400.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(123.f, 350.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(321.f, 400.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(750.f, 10.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(700.f, 30.f, 0.f)));

//	this->sceneObjectManager->removeObject();
}

void TestScene::updateScene()
{
	std::cout << "Updated active scene" << "\n";

	//if()
}
*/