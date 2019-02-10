#pragma once
#include <glew.h>
#include "ResourceManager.h"
class SpriteAtlas
	: public RSCM::BaseResource
{
private:
	//===Fields===//
	//Dimensions
	int atlasWidth, atlasHeight;
	int spriteWidth, spriteHeight;

	GLuint ID;
	int spriteAmount;

	//===Functions===//
	//==Private==//

public:
	SpriteAtlas(const char* fileName, const char* resourceName, int spriteWidth, int spriteHeight);
	~SpriteAtlas();

	//===Functions===//
	//==Public==//
	void bind(const GLint textureUnit);
	void unbind();

	//===Getters & Setters===//
	//==Getters==//
	int getAtlasWidth();
	int getAtlasHeight();
	int getSpriteWidth();
	int getSpriteHeight();
	int getSpriteAmount();

	GLuint getID();

	//==Setters==//
		
};

