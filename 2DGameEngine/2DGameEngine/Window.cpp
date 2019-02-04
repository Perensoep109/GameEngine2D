#include "Window.h"

#pragma region Constructors / Deconstructors

//====Properties====
/*
	Base window constructor, this function starts with assigning all the variables,
*/

glm::ivec2* Window::windowSize = new glm::ivec2(0.f, 0.f);
glm::ivec2* Window::lastWindowSize = new glm::ivec2(0.f, 0.f);
bool Window::recalcProj = false;

Window::Window(int windowWidth, int windowHeight, const char* windowTitle, bool resizable, bool fullScreen)
{
	//==Set properties==
	this->windowResizeable = resizable;
	this->windowState = true;
	this->windowSize = new glm::ivec2(windowWidth, windowHeight);
	this->lastWindowSize = windowSize;
	this->windowTitle = windowTitle;

	//==Set display==
	this->ProjectionMatrix = glm::mat4(1.f);
	this->nearPlane = -1.f;
	this->farPlane = 100.f;

	//==Setup window==
	//Set GLFW settings
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_RESIZABLE, resizable);

	//Create window
	this->window = glfwCreateWindow(this->windowSize->x, this->windowSize->y, this->windowTitle, NULL, NULL);

	//Check if window has been created
	if (this->window == nullptr)
	{
		std::cout << "Error, GLFW window has failed to initialize" << "\n";
		glfwTerminate();
	}

	//Calculate projection matrix
	calculateProjMat();

	//Set full screen
	if(fullScreen)
		toggleFullScreen(fullScreen);

	//Window callbacks:
	glfwSetFramebufferSizeCallback(this->window, Window::framebuffer_resize_callback);

	//Focus on this window
	glfwMakeContextCurrent(this->window);

	std::cout << "Window sucessfully initialised" << "\n";
}

Window::~Window()
{
	delete this->window;
}

#pragma endregion

#pragma region Private functions

//==Display==
//This function re calculates the projection matrix based on the current projection mode. (Orthographic or perspective)
void Window::calculateProjMat()
{
	this->ProjectionMatrix = Math::Matrix::calcOrtho(0, this->windowSize->x, 0, this->windowSize->y, this->nearPlane, this->farPlane);

	Window::recalcProj = false;
	std::cout << "Recalculated projection matrix" << "\n";
}

#pragma endregion

#pragma region Static functions

//==Properties==
//Update the framebuffer size, so that the window can be resized.
void Window::framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH)
{
	glViewport(0, 0, fbW, fbH);

	Window::windowSize->x = fbW;
	Window::windowSize->y = fbH;
	Window::recalcProj = true;
}

#pragma endregion

#pragma region Public functions
//====Window====

//Set the current OpenGL context to this window
void Window::focusWindow()
{
	glfwMakeContextCurrent(this->window);
}

//This function closes the window (by completely removing it from memory)
void Window::closeWindow()
{
	glfwDestroyWindow(this->window);
	delete this;
}

//Flip the framebuffer, from the old currently drawn frame, to the new frame
void Window::refreshWindow()
{	
	glfwSwapBuffers(this->window);
}

//====Display====

//Toggle the window fullscreen state.
//If the new mode is fullscreen. The old window size gets saved, for the moment the screen gets put back into windowed. 
//After this happens, re calculate the projection matrix
void Window::toggleFullScreen(bool state)
{
	//Create an empty screensize
	glm::ivec2 *newScreenSize = new glm::ivec2(0.0f);

	//Switch the state
	this->windowFullscreen = state;

	//If the screen switches to full screen, save the state
	if (state)
		this->lastWindowSize = this->windowSize;

	//Get the new screen size
	GLFWmonitor* currentMonitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(currentMonitor);

	if (state)
	{
		glfwSetWindowMonitor(window, currentMonitor, 0, 0, mode->width, mode->height, mode->refreshRate);
		newScreenSize->x = mode->width;
		newScreenSize->y = mode->height;
	}
	else
	{
		newScreenSize = this->lastWindowSize;
		glfwSetWindowMonitor(window, currentMonitor, 0, 0, newScreenSize->x, newScreenSize->y, mode->refreshRate);
	}

	this->windowSize = newScreenSize;

	//Recalculate the projection matrix
	this->calculateProjMat();
	std::cout << "Toggled" << "\n";
}

#pragma endregion

#pragma region Getters / Setters

#pragma region Getters

//==Getters==//
//==Properties==
bool Window::getWindowState()
{
	return this->windowState;
}

bool Window::getResizeable()
{
	return this->windowResizeable;
}

const char* Window::getWindowTitle()
{
	return this->windowTitle;
}

//==Window==
GLFWwindow* Window::getWindow()
{
	return this->window;
}

//Get size
int Window::getWindowWidth()
{
	return this->windowSize->x;
}

int Window::getWindowHeight()
{
	return this->windowSize->y;
}

glm::ivec2* Window::getWindowSize()
{
	return this->windowSize;
}

//==Display==
bool Window::getFullscreen()
{
	return this->windowFullscreen;
}

//Get display
glm::mat4 Window::getProjectionMatrix()
{
	if (recalcProj)
		calculateProjMat();

	return this->ProjectionMatrix;
}

float Window::getFov()
{
	return this->displayFov;
}

#pragma endregion

#pragma region Setters

//==Properties==
void Window::setWindowTitle(const char* newTitle)
{
	this->windowTitle = newTitle;
}

//==Window==
//Set window size
void Window::setWindowWidth(int newWidth)
{
	this->windowSize->x = newWidth;
}

void Window::setWindowHeight(int newHeight)
{
	this->windowSize->y = newHeight;
}

void Window::setWindowSize(glm::ivec2* newSize)
{
	this->windowSize = newSize;
}

//==Display==
void Window::setNearPlane(float newNearPlane)
{
	this->nearPlane = newNearPlane;
}

void Window::setFarPlane(float newFarPlane)
{
	this->farPlane = newFarPlane;
}

#pragma endregion

#pragma endregion