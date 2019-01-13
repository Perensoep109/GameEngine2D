#pragma once
#include "GameManager.h"
class Game :
	public GameManager
{
public:
	Game();
	~Game();

	void start();
	void update();
	void draw();

};

