#include "Renderable2D.h"

Renderable2D::Renderable2D()
{
	this->sprite = new Sprite2D();
}

Renderable2D::Renderable2D(const char* fileName)
{
	this->sprite = new Sprite2D(fileName);
}


Renderable2D::~Renderable2D()
{
	delete this->sprite;
}

void Renderable2D::draw()
{
	
}

void Renderable2D::setSprite(const char* fileName)
{
	this->sprite->setSprite(fileName);
}
