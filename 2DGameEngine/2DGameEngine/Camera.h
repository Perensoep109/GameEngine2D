#pragma once
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<glfw3.h>
class Camera
{
private:
	//Constant fields
	glm::vec3* front = new glm::vec3(0.f, 0.f, 1.f);

	glm::vec3* position;
	glm::mat4* ViewMatrix;

	float* speed;

public:
	Camera();
	~Camera();

	//Functions

	//Accessors
	float* getSpeed();
	glm::mat4* getViewMatrix();

	//Setters
	void setSpeed(float* newSpeed);
	void setPosition(glm::vec3* _position);
};

