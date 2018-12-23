#pragma once
#include "Window.h"
#include "Shader.h"
#include "Camera.h"

class Renderer2D
{
private:
	//Constants
	const int MAX_OBJECT_PER_DRAW_CALL = 256;

	//Fields
	float clearR = 0.f, clearG = 0.f, clearB = 0.f, clearA = 0.f;

	//Components:
	Shader* mainShader;
	Window* mainWindow;
	Camera* mainCamera;

	void renderFrame();
	void setupFrameRender();
	void sendToShader();
	void checkGLError();
public:
	Renderer2D(Shader* mainShaderProgram, Window* mainWindow, Camera* mainCamera);
	~Renderer2D();

	void renderGame();

	//Setters
	void setBackgroundColor(float R, float G, float B, float A);

	//Getters
	float getClearR();
	float getClearG();
	float getClearB();
	float getClearA();

	//TEMP
	int width = 10, height = 10;
	int objectAmount = width * height;
	glm::vec2 translations[10 * 10];
	GLuint instanceVBO;
	GLuint quadVAO, quadVBO;
};

