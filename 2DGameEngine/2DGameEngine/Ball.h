#pragma once
#include "Renderable2D.h"

class Ball
	: public Renderable2D
{
private:
	glm::vec2 direction, basePosition;
	float speed;

public:
	Ball(glm::vec2 pos, float speed)
		: Renderable2D()
	{
		this->basePosition = pos;
		this->speed = speed;
		*this->position = pos;

		direction = glm::vec2(rand() % 2, rand() % 2);
	}

	void onDeath()
	{

	}

	void onCreate()
	{

	}

	void update()
	{
		if (!(position->x > 640 || position->x < 0 || position->y > 480 || position->y < 0) && direction != glm::vec2(0, 0))
		{
			setPosition(*this->position + this->direction * this->speed);
		}
		else
		{
			direction = glm::vec2(rand() % 3 + -1, rand() % 3 + -1);
			setPosition(*this->position + this->direction * this->speed);
		}
	}
};