#pragma once
#include "GameObject.h"
#include <glm.hpp>
class Renderable2D :
	public GameObject
{
private:

protected:
	glm::vec2* position;
	float depth;

public:
	Renderable2D();
	~Renderable2D();

	//==Getters & Setters==//
	//==Getters==//
	glm::vec2* getPosition();
	float getDepth();

	//==Setters==//
	void setDepth(float newDepth);
	void setPosition(glm::vec2 newPosition);
};

