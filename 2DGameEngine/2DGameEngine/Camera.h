#pragma once
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<glfw3.h>
class Camera
{
	class Renderable2D;
private:
	//===Fields===//
	//==Private==//
	glm::vec3* front;
	glm::vec3* position;
	glm::mat4* ViewMatrix;

	float* speed;

public:
	//===Constructors & Deconstructors===//
	Camera(glm::vec3* camPos);
	~Camera();

	//===Functions===//
	void followGameObject(Renderable2D objectToFollow);
	void move(glm::vec3* direction);

	//==Getters & Setters==//
	//=Getters=//
	float* getSpeed();
	glm::mat4* getViewMatrix();

	//=Setters=//
	void setSpeed(float* newSpeed);
	void setPosition(glm::vec3* position);
};

