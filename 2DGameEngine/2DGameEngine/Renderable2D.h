#pragma once
#include "GameObject.h"
#include "Sprite.h"
class Renderable2D
	: public GameObject
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
	
	//Setters
	void setSprite(const char* fileName);
	void setLayer(float newLayer);


	//Accessors
	glm::vec3* getPosition();
	float getRotation();
	float getLayer();
};