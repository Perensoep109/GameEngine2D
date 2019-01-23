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
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(10.f, 0.f, 0.f)));
	/*
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(10.f, 25.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(430.f, 150.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(0.f, 35.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(600.f, 0.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(0.f, 400.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(123.f, 350.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(321.f, 400.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(750.f, 10.f, 0.f)));
	this->sceneObjectManager->addObject(new TestOBJ(new glm::vec3(700.f, 30.f, 0.f)));
	*/
//	this->sceneObjectManager->removeObject();
}

void TestScene::updateScene()
{
	std::cout << "Updated active scene" << "\n";

	//if()
}
