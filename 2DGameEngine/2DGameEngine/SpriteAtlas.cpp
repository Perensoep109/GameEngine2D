#include "SpriteAtlas.h"
#include <SOIL2.h>
#include <iostream>

#pragma region Constructors & Deconstructors

SpriteAtlas::SpriteAtlas(const char * fileName, int spriteWidth, int spriteHeight)
{
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;

	loadFromFile(fileName);
}

SpriteAtlas::~SpriteAtlas()
{
}

#pragma endregion

#pragma region Functions
#pragma region Private

void SpriteAtlas::loadFromFile(const char* fileName)
{
	//Load from file
	if (this->ID)
	{
		glDeleteTextures(1, &this->ID);
	}

	unsigned char* image = nullptr;

	image = SOIL_load_image(fileName, &this->spriteWidth, &this->spriteHeight, NULL, SOIL_LOAD_RGBA);

	glGenTextures(1, &this->ID);
	glBindTexture(GL_TEXTURE_2D, this->ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	if (image != nullptr)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->spriteWidth, this->spriteHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
		glActiveTexture(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		SOIL_free_image_data(image);
	}
	else
	{
		std::cout << "Error, loading sprite from file failed: " << fileName << "\n";
	}
}

#pragma endregion

#pragma region Public

#pragma region Getters & Setters
//==Getters==//
int SpriteAtlas::getAtlasWidth()
{
	return this->atlasWidth;
}

int SpriteAtlas::getAtlasHeight()
{
	return this->atlasHeight;
}

int SpriteAtlas::getSpriteWidth()
{
	return this->spriteWidth;
}

int SpriteAtlas::getSpriteHeight()
{
	return this->spriteHeight;
}

GLuint SpriteAtlas::getID()
{
	return GLuint();
}

//==Setters==//

#pragma endregion


#pragma endregion
#pragma endregion
