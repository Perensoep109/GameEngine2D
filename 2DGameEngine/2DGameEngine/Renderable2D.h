#pragma once
#include "GameObject.h"
#include <glm.hpp>

class Renderable2D :
	public GameObject
{
private:
	//===Fields===//
	//==Private==//
	

	//===Functions===//
	//==Private==//

protected:
	//===Fields===//
	//==Protected==//
	glm::vec2* position;
	float depth;

	//===Functions===//
	//==Protected==//
	//=Virtual=//
	

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
	void setSprite(const char* fileName);
};

