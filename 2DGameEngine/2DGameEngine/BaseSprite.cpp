#include "BaseSprite.h"
/*
BaseSprite2D::BaseSprite2D(BaseSprite2D::SpriteMode spriteMode)
{
	this->spriteMode = spriteMode;
}

BaseSprite2D::~BaseSprite2D()
{
	delete this->filePath;
}

void BaseSprite2D::bind(const GLint textureUnit)
{
	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_2D, this->id);
}

void BaseSprite2D::unbind()
{
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

#pragma region Sprite loading

void BaseSprite2D::setSprite(const char* fileName)
{
	loadFromFile(fileName);
}

void BaseSprite2D::loadFromFile(const char* fileName)
{
	//Load from file
	if (this->id)
	{
		glDeleteTextures(1, &this->id);
	}

	unsigned char* image = nullptr;

	image = SOIL_load_image(fileName, &this->spriteWidth, &this->spriteHeight, NULL, SOIL_LOAD_RGBA);

	glGenTextures(1, &this->id);
	glBindTexture(GL_TEXTURE_2D, this->id);

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

#pragma region Checkers
bool BaseSprite2D::isInAtlas()
{
	return this->spriteMode == SpriteMode::InAtlas ? true : false;
}

bool BaseSprite2D::isSingle()
{
	return this->spriteMode == SpriteMode::Single ? true : false;
}

bool BaseSprite2D::isAnimation()
{
	return this->spriteMode == SpriteMode::Animation ? true : false;
}

#pragma endregion

#pragma region Getters & Setters
BaseSprite2D::SpriteMode BaseSprite2D::getSpriteMode()
{
	return this->spriteMode;
}

glm::ivec2 BaseSprite2D::getDimensions()
{
	return glm::ivec2(this->spriteWidth, this->spriteHeight);
}
#pragma endregion
*/