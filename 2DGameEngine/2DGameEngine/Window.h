#pragma once

#include<glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <iostream>

/*
	====================================================DOCUMENTATION====================================================
	====================================================DEFINITION & STRUCTURE===========================================

	==Goal of this class==
	This class wraps the GLFW window structure, to interact with this class, use the public functions and the getter &
	setter functions. The window gets created, and set into context on object creation. The window constructor can be
	overloaded to fit the users need.

	The base size of a window is 640 x 480

	The projection matrix of this window gets updated everytime the window gets resized (set to fullscreen, or the edges
	get moved) and at the creation of this object.

	The windowState boolean represents the state of the window, if it is true. The window is still alive. If not, the
	window is not alive anymore. So it does not exist.

	==Structucture==
	This screen class is structured in 3 parts, the general properties part then the window part and the display part. 
	These parts are easily recognizable. Because they're always structured in the same way.
	First the general properties part, then the window part, then the display part.

	In the screen part, the variables and functions for the actual window itself are defined. 
	In the display part, the variables & functions are made for the window situated on a screen.
	In the miscellaneous part, other variables are stored that did not fit in any other catagory. (general properties)

	=====================================================================================================================
	====================================================HELPER DATA TYPES================================================

	The helper data types for this class are WProjMode, this is an enum that represents what projection mode the window
	has to work with. Either orthographic (2D) or perspective (3D) mode. 

	=====================================================================================================================

*/

class Window
{
public:
#pragma region Helper data types

	enum WProjMode
	{
		WPerspective,
		WOrtho
	};

#pragma endregion

private:
#pragma region Fields
	//==Properties==
	bool windowState;
	const char* windowTitle;

	//==Size==
	static glm::ivec2 *windowSize;
	static glm::ivec2 *lastWindowSize;
	bool windowResizeable;

	//==Display==
	GLFWwindow* window;
	WProjMode windowProjectionmode;
	glm::mat4* ProjectionMatrix;
	bool windowFullscreen;
	float nearPlane, farPlane, displayFov;

#pragma endregion

#pragma region Private functions
	//==Display==
	void calculateProjMat();
#pragma endregion

#pragma region Static functions
	//General
	static void framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH);
#pragma endregion

public:

#pragma region Constructors / Deconstructors

	//==General==
	Window(int windowWidth = 640, int windowHeight = 480, const char* windowTitle = "Window Title", bool resizeable = true, WProjMode projectionMode = WOrtho);
	~Window();

#pragma endregion

#pragma region Public functions

	//Window
	void focusWindow();
	void closeWindow();
	void toggleFullScreen(bool state);

	//Display
	void switchProjectionMode(WProjMode newMode);
	void refreshWindow();

#pragma endregion

#pragma region Getters / Setters
	/*
		All getter & setter methods for this window class, first the window properties, then its size.
	*/

	//==Getters==
	//==Properties==
	bool getWindowState();
	bool getFullscreen();
	bool getResizeable();
	const char* getWindowTitle();

	//==Window==
	int getWindowWidth();
	int getWindowHeight();
	glm::ivec2* getWindowSize();

	//==Display==
	glm::mat4* getProjectionMatrix();
	float getFov();
	GLFWwindow* getWindow();


	//==Setters==
	//==Properties==
	void setWindowTitle(const char*);
	
	//==Window==
	void setWindowWidth(int newWidth);
	void setWindowHeight(int newHeight);
	void setWindowSize(glm::ivec2* newSize);

	//==Display==
	void setNearPlane(float newNearPlane);
	void setFarPlane(float newFarPlane);
	void setFov(float newFov);

#pragma endregion
};