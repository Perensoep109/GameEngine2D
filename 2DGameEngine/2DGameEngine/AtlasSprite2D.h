#pragma once
#include "BaseSprite.h"
//===Forward declarations===//
class SpriteAtlas;

class AtlasSprite2D
{
private:
	//===Fields===//
	//==Private==//
	int atlasIndex;
	SpriteAtlas* spriteAtlas;

	//===Functions===//
	//==Private==//

public:
	//===Fields===//
	//==Public==//


	//===Constructors & Deconstructors===//
	AtlasSprite2D(SpriteAtlas* parentSpriteAtlas, int atlasIndex);
	~AtlasSprite2D();

	//===Functions===//
	//==Public==//


	//===Getters & Setters===//
	//==Getters==//
	int getAtlasIndex();
	SpriteAtlas* getSpriteAtlas();

	//==Setters==//

};

