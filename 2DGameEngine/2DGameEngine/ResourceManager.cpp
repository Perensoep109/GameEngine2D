#include "ResourceManager.h"
#include <iostream>
#include <SOIL2.h>


//This function loads an image, 
bool RSCM::imgLoadFromFile(const char* fileName, int &imageWidth, int &imageHeight, GLuint &id)
{
	//Load from file
	if (id)
	{
		glDeleteTextures(1, &id);
	}

	unsigned char* image = nullptr;

	image = SOIL_load_image(fileName, &imageWidth, &imageHeight, NULL, SOIL_LOAD_RGBA);

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	if (image != nullptr)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, *&imageWidth, *&imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
		glActiveTexture(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		SOIL_free_image_data(image);
		return true;
	}
	else
	{
		std::cout << "Error, loading image from file failed: " << fileName << "\n";
		return false;
	}
}
