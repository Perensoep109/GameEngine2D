#pragma once
#include <iostream>
#include<SOIL2.h>
#include <glew.h>
#include "Mesh.h"

class Sprite2D
{
private:
	//Fields
	int spriteWidth = 0, spriteHeight = 0;
	char* filePath;


	//OpenGL variables
	GLuint id;

	//Private functions
	void loadSprite(const char* fileName);
	void bind(GLint textureUnit);
	void unbind();


public:
	Sprite2D(void);
	Sprite2D(const char* fileName);
	~Sprite2D();
#pragma region Getters & Setters

	//Accessors
	const char* getSprite();

	//Setters
	void setSprite(const char* fileName);

#pragma endregion
};

