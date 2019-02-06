#pragma once
#include <glew.h>
class SpriteAtlas
{
private:
	//===Fields===//
	//Dimensions
	int atlasWidth, atlasHeight;
	int spriteWidth, spriteHeight;

	GLuint ID;

	//===Functions===//
	//==Private==//
	//=Image loading=//
	void loadFromFile(const char* fileName);

public:
	SpriteAtlas(const char* fileName, int spriteWidth, int spriteHeight);
	~SpriteAtlas();

	//===Getters & Setters===//
	//==Getters==//
	int getAtlasWidth();
	int getAtlasHeight();
	int getSpriteWidth();
	int getSpriteHeight();

	GLuint getID();

	//==Setters==//
		
};

