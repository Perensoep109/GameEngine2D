#include "Renderable2D.h"

Renderable2D::Renderable2D()
	: GameObject(OBJ_TYPE::Renderable2DE)
{
	this->sprite = new Sprite2D();
}

Renderable2D::Renderable2D(const char* fileName)
	: GameObject(OBJ_TYPE::Renderable2DE)
{
	this->sprite = new Sprite2D(fileName);
}


Renderable2D::~Renderable2D()
{
	delete this->sprite;
}

void Renderable2D::setSprite(const char* fileName)
{
	this->sprite->setSprite(fileName);
}

void Renderable2D::setLayer(float newLayer)
{
	this->renderLayer = newLayer;
}

glm::vec3* Renderable2D::getPosition()
{
	return this->position;
}

float Renderable2D::getRotation()
{
	return this->position->z;
}

float Renderable2D::getLayer()
{
	return this->renderLayer;
}
