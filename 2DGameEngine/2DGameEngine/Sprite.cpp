#include "Sprite.h"

Sprite2D::Sprite2D(void)
{
}

Sprite2D::Sprite2D(const char* fileName)
{
	setSprite(fileName);
}

Sprite2D::~Sprite2D()
{
	delete this->filePath;
}

const char* Sprite2D::getSprite()
{
	return nullptr;
}

void Sprite2D::bind(const GLint textureUnit)
{
	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_2D, this->id);
}

void Sprite2D::unbind()
{
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Sprite2D::setSprite(const char* fileName)
{
	loadSprite(fileName);
}

void Sprite2D::loadSprite(const char* fileName)
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
	//ERROR         ^^^^^^
	GLenum err;
	err = glGetError();
	if (err == GL_NO_ERROR) return;
	std::cout << "OpenGL error: " << err << "\n";
	printf("Error: %s\n", glewGetErrorString(err));
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