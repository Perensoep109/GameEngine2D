#pragma once
#include "Scene.h"
#include "Ball.h"
class TestScene :
	public Scene
{
private:
	Ball* ball;
	glm::vec2 direction;
	glm::vec2 position;
	float speed;

public:
	TestScene();
	~TestScene();

#pragma region Inherited virtual functions
	void initScene();
	void startScene();
	void updateScene();
	void reloadScene();
#pragma endregion
};

