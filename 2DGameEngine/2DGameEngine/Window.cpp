#include "Window.h"

Window::Window()
{
	glfwTerminate();
}

Window::Window(const char* title, const bool resizable, const bool _fullscreen, const int GL_MAJOR, const int GL_MINOR, const glm::ivec2 wDim)
{
	//Set frame buffer size
	this->fbH = wDim.y;
	this->fbW = wDim.x;

	//Set variables
	this->nearPlane = -1.f;
	this->farPlane = 1.f;
	this->fov = 90.f;

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_MINOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_MAJOR);
	glfwWindowHint(GLFW_RESIZABLE, resizable);

	this->window = glfwCreateWindow(fbW, fbH, title, NULL, NULL);

	if (this->window == nullptr)
	{
		std::cout << "Error, GLFW window fail" << "\n";
		glfwTerminate();
	}

	if (_fullscreen)
		toggleFullscreen(this->window);

	//Window
	glfwGetFramebufferSize(this->window, &this->fbW, &this->fbH);
	glfwSetFramebufferSizeCallback(this->window, Window::framebuffer_resize_callback);

	//Mouse
	glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	glfwSetCursorPosCallback(this->window, Window::mouse_callback);

	//Init matrices
	this->initMatrices();

	//Update window size:
	glfwMakeContextCurrent(this->window);

	std::cout << "Window sucessfully initialized \n";
}

Window::~Window()
{
	std::cout << "Deleted window" << "\n";
}

#pragma region Callbacks

void Window::framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH)
{
	glViewport(0, 0, fbW, fbH);
}

void Window::mouse_callback(GLFWwindow* window, double xPos, double yPos)
{

}
#pragma endregion

#pragma region Functions

void Window::close()
{
	this->shouldClose = true;
	std::cout << "Closed window" << "\n";
}

void Window::toggleFullscreen(GLFWwindow* window)
{
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);

	this->fullscreen = !this->fullscreen;

	if(this->fullscreen)
		glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
	std::cout << "Toggled fullscreen \n";
}

void Window::update()
{
	this->updateProjMatrix();
}

void Window::updateProjMatrix()
{
	glfwGetFramebufferSize(this->window, &this->fbW, &this->fbH);

	*this->ProjectionMatrix = glm::ortho(0.0f, 800.f, 0.0f, 600.f, 0.1f, 100.f);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(this->window);
}

void Window::initMatrices()
{
	*this->ProjectionMatrix = glm::ortho(0.f, 10.f, 10.f, 0.f, nearPlane, farPlane);
}
#pragma endregion

#pragma region Accessors
glm::ivec2 Window::getSize()
{
	glm::ivec2 returnVec = glm::ivec2(1);

	glfwGetWindowSize(this->window, &returnVec.x, &returnVec.y);
	return returnVec;
}

bool Window::getWindowShouldClose()
{
	return this->shouldClose;
}

glm::mat4* Window::getProjectionMatrix()
{
	updateProjMatrix();

	return this->ProjectionMatrix;
}

//Framebuffer
int Window::getFBW()
{
	return this->fbW;
}

int Window::getFBH()
{
	return this->fbH;
}
#pragma endregion