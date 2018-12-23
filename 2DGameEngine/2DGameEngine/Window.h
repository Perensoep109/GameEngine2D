#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include<glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <iostream>
//#include "Camera.h"

class Window
{
private:
	//Private variables
	int fbW = 0, fbH = 0;
	float fov, nearPlane, farPlane;
	bool fullscreen;

	//References
	glm::vec2 centerOfScreen = glm::vec2(this->fbW / 2, this->fbH / 2);

	//Projection matrix
	glm::mat4* ProjectionMatrix = new glm::mat4(1.f);

	//Private functies
	void initMatrices();

	//Static functions
	static void framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH);
	static void mouse_callback(GLFWwindow* window, double xPos, double yPos);

public:
	//Public variables
	bool shouldClose = false;

	//Constructots / Destructors
	Window();
	Window(const char* title, const bool resizable, const bool _fullscreen, const int GL_MAJOR, const int GL_MINOR, const glm::ivec2 wDim = glm::ivec2(640, 480));
	~Window();

	GLFWwindow* window;

	//Functions
	void close();
	void toggleFullscreen(GLFWwindow* window);
	void updateProjMatrix();
	void swapBuffers();
	void update();
	//void setReferences(Camera* cam);

	//Input 
	//void keyboardInput();

#pragma region Accessors
	glm::ivec2 getSize();
	bool getWindowShouldClose();
	glm::mat4* getProjectionMatrix();

	//Framebuffer
	int getFBW(), getFBH();
#pragma endregion
};

#endif // !WINDOW_H