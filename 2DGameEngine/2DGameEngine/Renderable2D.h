#pragma once
#include "ActiveObject.h"
#include "Sprite.h"
class Renderable2D
	: public ActiveObject
{
protected:
	Sprite2D* sprite;

private:
	float renderLayer = 1.f;

public:
	Renderable2D();
	Renderable2D(const char* fileName);
	~Renderable2D();

	//Public fields:
	bool shouldRender = true;
	
	void draw();
	void setSprite(const char* fileName);
};