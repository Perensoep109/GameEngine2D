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

	void activateScene(std::string sceneToActivate);

#pragma endregion

	void setup();
	void start();
	void update();
	void draw();
};

#endif // !GAMEMANAGER_H