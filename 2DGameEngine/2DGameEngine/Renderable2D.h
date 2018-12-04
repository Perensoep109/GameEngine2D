#pragma once
#include "ActiveObject.h"
#include "Sprite.h"
class Renderable2D
	: public ActiveObject
{
protected:
	Sprite2D* sprite;
	float renderLayer = 1.f;
	glm::vec3* position;

public:
	Renderable2D();
	Renderable2D(const char* fileName);
	~Renderable2D();

	//Public fields:
	bool shouldRender = true;
	
	void draw();
	void setSprite(const char* fileName);

	//Accessors
	glm::vec3* getPosition();
};