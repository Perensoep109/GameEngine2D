#include "Window.h"

#pragma region Constructors / Deconstructors

//====Properties====
/*
	Base window constructor, this function starts with assigning all the variables,
*/

Window::Window(int windowWidth, int windowHeight, const char* windowTitle, bool resizable, WProjMode projectionMode)
{
	//==Set properties==
	this->windowResizeable = resizable;
	this->windowState = true;
	this->windowSize = new glm::ivec2(windowWidth, windowHeight);
	this->windowTitle = windowTitle;
	this->windowFullscreen = false;

	//==Set display==
	this->ProjectionMatrix = new glm::mat4(1.f);
	this->nearPlane = -1.f;
	this->farPlane = 100.f;

	//==Setup window==
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_RESIZABLE, resizable);

	this->window = glfwCreateWindow(this->windowSize->x, this->windowSize->y, this->windowTitle, NULL, NULL);

	//Check if window has been created
	if (this->window == nullptr)
	{
		std::cout << "Error, GLFW window has failed to initialize" << "\n";
		glfwTerminate();
	}

	//Window callbacks:
	glfwSetFramebufferSizeCallback(this->window, Window::framebuffer_resize_callback);

	//Focus on this window
	glfwMakeContextCurrent(this->window);

	//Calculate the projection matrix
	calculateProjMat();

	std::cout << "Window sucessfully initialised" << "\n";
}

Window::~Window()
{
	delete this->ProjectionMatrix;
	delete this->window;
}

#pragma endregion

#pragma region Private functions

//==Display==
//This function re calculates the projection matrix based on the current projection mode. (Orthographic or perspective)
void Window::calculateProjMat(float FOV)
{
	if (this->windowProjectionmode == WPerspective)
	{
		*this->ProjectionMatrix = glm::perspective(
			glm::radians(FOV),
			static_cast<float>(this->windowSize->x / this->windowSize->y),
			this->nearPlane,
			this->farPlane
		);
	}
	else
	{
		*this->ProjectionMatrix = glm::ortho(
			0, (int)this->windowSize->x,
			0, (int)this->windowSize->y,
			(int)this->nearPlane,
			(int)this->farPlane);
	}
}

#pragma endregion

#pragma region Static functions

//==Properties==
//Update the framebuffer size, so that the window can be resized.
void Window::framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH)
{
	glViewport(0, 0, fbW, fbH);
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
	GLFWmonitor* currentMonitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(currentMonitor);
	this->lastWindowSize = windowSize;

	if (state)
	{
		glfwSetWindowMonitor(window, currentMonitor, 0, 0, mode->width, mode->height, mode->refreshRate);
		windowSize->x = mode->width;
		windowSize->y = mode->height;
	}
	else
	{
		glfwSetWindowMonitor(window, currentMonitor, 0, 0, lastWindowSize->x, lastWindowSize->y, mode->refreshRate);
		windowSize = lastWindowSize;
	}

	this->calculateProjMat();
}

//Switch the rendering projection mode, from the old version to the new version, if the WOrtho mode is selected, FOV is not used.
void Window::switchProjectionMode(WProjMode newMode, float fov)
{
	this->windowProjectionmode = newMode;

	this->calculateProjMat();
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
glm::mat4* Window::getProjectionMatrix()
{
	return this->ProjectionMatrix;
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