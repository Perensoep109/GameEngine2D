#pragma once
class GameObject
{
private:
	const char* objectType;

public:
	GameObject();
	~GameObject();

	//==Getters==//
	const char* getObjectType();

	//==Setters==//
};

