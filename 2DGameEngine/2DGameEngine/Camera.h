#pragma once
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<glfw3.h>
class Camera
{
	class Renderable2D;
private:
	//Constant fields
	glm::vec3* front;

	glm::vec3* position;
	glm::mat4* ViewMatrix;

	float* speed;

public:
	Camera(glm::vec3* camPos);
	~Camera();

	//Functions
	void followGameObject(Renderable2D objectToFollow);
	void move();

	//Accessors
	float* getSpeed();
	glm::mat4* getViewMatrix();

	//Setters
	void setSpeed(float* newSpeed);
	void setPosition(glm::vec3* _position);
};

