#pragma once
#include <iostream>
#include<SOIL2.h>
#include <glm.hpp>
#include <glew.h>

class BaseSprite2D
{
public:
	enum SpriteMode
	{
		InAtlas, Single, Animation
	};

protected:
	//==Fields==//
	SpriteMode spriteMode;
	int spriteWidth = 0, spriteHeight = 0;
	char* filePath;

	GLuint id;

	//Private functions
	virtual void loadFromFile(const char* fileName);
	virtual void bind(GLint textureUnit);
	virtual void unbind();


public:
	//===Constructors & Deconstructors===//
	BaseSprite2D(SpriteMode spriteMode = SpriteMode::Single);
	~BaseSprite2D();

	//====Functions====//
	//===Checkers===//
	bool isInAtlas();
	bool isSingle();
	bool isAnimation();

	//===Getters & Setters===//
	//==Getters==//
	const char* getSprite();
	glm::ivec2 getDimensions();
	SpriteMode getSpriteMode();

	//==Setters==//
	void setSprite(const char* fileName);
};

