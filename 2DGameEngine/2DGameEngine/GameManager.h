#pragma once
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "libs.h"

//Component includes
#include "Window.h"
#include "Shader.h"
#include "TestObject.h"
#include "GameObjectManager.h"
#include "Primitive.h"
#include "Renderer2D.h"

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
	void initShaders();
	void initCamera();
	void initRenderer();

	//Callbacks
	static void glfwErrorCallback(int id, const char* description);
	static void APIENTRY OpenGLErrorMessageCallBack(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

protected:
	//Components
	Window* gameWindow;
	Renderer2D* gameRenderer;
	Camera* gameCamera;

	//Shaders
	Shader* mainShader;
	Shader* gameObjectShader;

	TestOBJ** testObject;

	bool endNextFrame;
public:
	GameManager(Game* game);
	~GameManager();

	void setup();
	void start();
	void update();
	void draw();
};

#endif // !GAMEMANAGER_H