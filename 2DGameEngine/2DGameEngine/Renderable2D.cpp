#include "Renderable2D.h"
#pragma region Constructors / Deconstructor
Renderable2D::Renderable2D(const char* fileName, glm::vec2* _position, glm::ivec2* _spriteDim)
	: GameObject(OBJ_TYPE::Renderable2DE)
{
	this->position = _position;
	this->spriteDim = _spriteDim;
	this->InstanceMatrix = new glm::mat4(1.f);
	//scaleToSprite();
	*this->InstanceMatrix = glm::scale(*this->InstanceMatrix, glm::vec3(100.f, 100.f, 10.f));
	*this->InstanceMatrix = glm::translate(*this->InstanceMatrix, glm::vec3(*this->position, 10.0f));
}

Renderable2D::~Renderable2D()
{
	delete this->spriteDim;
	delete this->position;
	delete this->InstanceMatrix;
}

#pragma endregion

#pragma region Private functions
void Renderable2D::scaleToSprite()
{
	*this->InstanceMatrix = glm::translate(*this->InstanceMatrix, glm::vec3(0.5f * this->spriteDim->x, 0.5f * this->spriteDim->y, 0.0f));
	*this->InstanceMatrix = glm::rotate(*this->InstanceMatrix, this->rotation, glm::vec3(1.f, 0.f, 0.f));
	*this->InstanceMatrix = glm::translate(*this->InstanceMatrix, glm::vec3(0.5f * this->spriteDim->x, -0.5f * this->spriteDim->y, -0.0f));
	*this->InstanceMatrix = glm::scale(*this->InstanceMatrix, glm::vec3(this->spriteDim->x, this->spriteDim->y, 1.0f));
}
#pragma endregion

#pragma region Protected functions

#pragma endregion

#pragma region Setters
void Renderable2D::rotate(float angle)
{
	this->rotation += angle;
	*this->InstanceMatrix = glm::rotate(*this->InstanceMatrix, this->rotation, glm::vec3(0.f, 0.f, 1.f));
}

void Renderable2D::setLayer(float newLayer)
{
	this->renderLayer = newLayer;
}
#pragma endregion

#pragma region Getters
glm::vec2* Renderable2D::getPosition()
{
	return this->position;
}

float Renderable2D::getRotation()
{
	return this->rotation;
}

float Renderable2D::getLayer()
{
	return this->renderLayer;
}
glm::mat4* Renderable2D::getInstanceMatrix()
{
	return this->InstanceMatrix;
}
#pragma endregion