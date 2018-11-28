#include "Camera.h"



Camera::Camera()
{
}


Camera::~Camera()
{
}

float* Camera::getSpeed()
{
	return this->speed;
}

glm::mat4* Camera::getViewMatrix()
{
	this->ViewMatrix = glm::lookAt(this->position, this->position + this->front);
	return this->ViewMatrix;
}

void Camera::setSpeed(float* newSpeed)
{
	this->speed = newSpeed;
}

void Camera::setPosition(glm::vec3* _position)
{
	this->position = _position;
}
