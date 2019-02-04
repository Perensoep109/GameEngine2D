#pragma once
#include <glfw3.h>
#include <iostream>

static class StatGameInputManager
{
private:
	//===Fields===//
	//==Private==//
	GameInputManager* inputManager;

	//===Functions===//
	//==Public==//
	void init(GameInputManager* inputManager)
	{
		this->inputManager = inputManager;
	}

public:
	//===Functions===//
	//==Public==//
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		//StatGameInputManager::inputManager->key();
	}
};

class GameInputManager
{
public:
	//===Sub data types===//
	enum KeyMode
	{
		Down, Press, Released
	};

	//==Fields==//

	//===Constructors & Deconstructors===//
	
	//===Functions===//
	//==Public==//
	void key()
	{

	}
};

