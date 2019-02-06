#include "AtlasSprite2D.h"



AtlasSprite2D::AtlasSprite2D(SpriteAtlas* parentSpriteAtlas, int atlasIndex)
{
}

AtlasSprite2D::~AtlasSprite2D()
{
	delete this->spriteAtlas;
}

#pragma region Functions
#pragma region Getters & Setters
//===Getters & Setters===//
//==Getters==//
int AtlasSprite2D::getAtlasIndex()
{
	return this->atlasIndex;
}

SpriteAtlas* AtlasSprite2D::getSpriteAtlas()
{
	return this->spriteAtlas;
}

//==Setters==//
#pragma endregion

#pragma endregion
