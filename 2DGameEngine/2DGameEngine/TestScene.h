#pragma once
#include "Scene.h"
class TestScene :
	public Scene
{
public:
	TestScene();
	~TestScene();

#pragma region Inherited virtual functions
	void initScene();
	void updateScene();
#pragma endregion
};

