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
	void initRenderer();

	//Callbacks
	static void glfwErrorCallback(int id, const char* description);

	//Components
	Window* gameWindow;
	Renderer2D* gameRenderer;
	Camera* gameCamera;

	//Shaders
	Shader* mainShader;

	TestOBJ* testObject;

	GLuint VBO, VAO;
public:
	Game();
	~Game();

	void start();
	void update();
	void render();

#pragma region Temporary code

#pragma endregion

};