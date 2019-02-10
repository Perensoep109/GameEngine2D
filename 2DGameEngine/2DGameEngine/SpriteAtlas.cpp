#include "SpriteAtlas.h"
#include <SOIL2.h>
#include <iostream>

#pragma region Constructors & Deconstructors

SpriteAtlas::SpriteAtlas(const char* fileName, const char* resourceName, int spriteWidth, int spriteHeight)
	: RSCM::BaseResource(resourceName)
{
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;

	//Check if the spritesheet has loaded
	if (RSCM::imgLoadFromFile(fileName, this->atlasWidth, this->atlasHeight, this->ID) == false)
	{
		std::cout << "Error creating spritesheet, no image at data path";
		delete this;
		return;
	}

	//Spritesheet has loaded correctly
	this->spriteAmount = (this->atlasWidth / this->spriteWidth) * (this->atlasHeight / this->spriteWidth);
}

SpriteAtlas::~SpriteAtlas()
{
}

#pragma endregion

#pragma region Functions
#pragma region Private

#pragma endregion

#pragma region Public

void SpriteAtlas::bind(const GLint textureUnit)
{
	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_2D, this->ID);
}

void SpriteAtlas::unbind()
{
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

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
	return this->ID;
}

int SpriteAtlas::getSpriteAmount()
{
	return this->spriteAmount;
}

//==Setters==//

#pragma endregion


#pragma endregion
#pragma endregion