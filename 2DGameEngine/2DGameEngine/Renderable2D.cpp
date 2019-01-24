#include "Renderable2D.h"



Renderable2D::Renderable2D()
	: GameObject()
{
	this->addObjectType("Renderable2D");
}


Renderable2D::~Renderable2D()
{
	delete this->position;
}

#pragma region Getters & Setters

glm::vec2* Renderable2D::getPosition()
{
	return this->position;
}

float Renderable2D::getDepth()
{
	return this->depth;
}

void Renderable2D::setDepth(float newDepth)
{
	this->depth = newDepth;
}

void Renderable2D::setPosition(glm::vec2* newPosition)
{
	this->position = newPosition;
}

#pragma endregion
