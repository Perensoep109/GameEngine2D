#pragma once
#include "Scene.h"
#include "TestOBJ.h"
class TestScene :
	public Scene
{
private:
	TestOBJ* ball;

public:
	TestScene();
	~TestScene();

#pragma region Inherited virtual functions
	void initScene();
	void startScene();
	void updateScene();
#pragma endregion
};

