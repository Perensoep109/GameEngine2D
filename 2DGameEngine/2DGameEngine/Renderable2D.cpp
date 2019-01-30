#include "Renderable2D.h"
#include <gtc/matrix_access.hpp>
#include <array>


Renderable2D::Renderable2D()
	: GameObject()
{
	this->addObjectType("Renderable2D");
	this->position = new glm::vec2(0.f, 0.f);
	this->instanceMatrix = new glm::mat4(1.f);
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

std::array<float, 16>* Renderable2D::getInstanceMat()
{
	std::array<float, 16>* returnArray = new std::array<float, 16>();

	for (int i = 0; i < 4; i++)
	{
		glm::vec4 column = glm::column(*this->instanceMatrix, i);
		for (int j = 0; j < 4; j++)
		{
			returnArray->at(i * 4 + j) = column[j];
		}
	}

	return returnArray;
}

void Renderable2D::setDepth(float newDepth)
{
	this->depth = newDepth;
}

void Renderable2D::setPosition(glm::vec2 newPosition)
{
	*this->position = newPosition;
}

#pragma endregion
