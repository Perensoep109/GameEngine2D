#pragma once
#include "Window.h"
#include "Shader.h"
#include "Camera.h"

class Renderer2D
{
private:
	class GameObjectManager;
	//Fields
	float clearR = 0.f, clearG = 0.f, clearB = 0.f, clearA = 0.f;
	Shader* mainShader;
	Window* mainWindow;
	Camera* mainCamera;

	void renderFrame();
	void sendToShader();
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
};

