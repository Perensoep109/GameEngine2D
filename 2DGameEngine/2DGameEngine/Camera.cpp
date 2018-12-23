#include "Camera.h"



Camera::Camera(glm::vec3* camPos)
{
	this->front = new glm::vec3(0.f, 0.f, -1.f);
	this->position = camPos;
	this->ViewMatrix = new glm::mat4();
}


Camera::~Camera()
{
	delete this->front;
	delete this->position;
	delete this->speed;
	delete this->ViewMatrix;
}

//Functions


float* Camera::getSpeed()
{
	return this->speed;
}

glm::mat4* Camera::getViewMatrix()
{
	*this->ViewMatrix = glm::lookAt(*this->position, *this->position + glm::vec3(0.f, 0.f, 1.f), glm::vec3(glm::vec3(0.f, 1.f, 0.f)));
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
