#pragma once
#include "GameManager.h"
class Game :
	public GameManager
{
private:
	bool temp, temp2;
public:
	Game();
	~Game();

	void start();
	void update();
	void draw();

};

