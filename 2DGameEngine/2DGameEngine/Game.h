#pragma once
#include "libs.h"

//Component includes
#include "Window.h"
#include "Shader.h"
#include "TestObject.h"
#include "GameObjectManager.h"
#include "Primitive.h"
#include "Renderer2D.h"

#include "Vertex.h"

class Game
{
private:
	//Initializers
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
	Game();
	~Game();

	void start();
	void update();
	void render();
};