#pragma once
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "libs.h"

//Component includes
#include "Window.h"
#include "Renderer2D.h"
#include "SceneManager.h"

class Game;

class GameManager
{
private:
	//Private components
	Game* focussedGame;
	
	

	//Initialize functions
	void initGLFW();
	void initWindow();
	void initGLEW();
	void initOpenGLOptions();
	void initSceneManager();
	void initRenderer();

	//Callbacks
	static void glfwErrorCallback(int id, const char* description);
	static void APIENTRY OpenGLErrorMessageCallBack(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
	void keyInputCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

protected:
	//Components
	SceneManager* sceneManager;
	Window* gameWindow;
	Renderer2D* gameRenderer;

	bool endNextFrame;
public:
	GameManager(Game* game);
	~GameManager();

#pragma region Scene management

	void activateScene(std::string sceneToActivate, bool reload);

#pragma endregion

	void setup();
	void start();
	void update();
	void draw();
};

#pragma region Input management
//======Input management=====//
class InputSingleton
{
private:
	InputSingleton(void)
	{
	}

	InputSingleton(InputSingleton const&);
	void operator=(InputSingleton const&);

public:
	static InputSingleton& getInstance()
	{
		static InputSingleton instance;
		return instance;
	}

	static void static_keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		getInstance().keyCallback(key, scancode, action, mods);
	}

	void keyCallback(int key, int scancode, int action, int mods)
	{
		//Keyboard output
		std::cout << key << "\n";
	}
};

const struct KeyInput
{
public:
	int key, scancode, action, mods;

	KeyInput(int key, int scancode, int action, int mods)
	{
		this->key = key;
		this->scancode = scancode;
		this->action = action;
		this->mods = mods;
	}
};

#pragma endregion

#endif // !GAMEMANAGER_H