#pragma once
#include <vector>
class GameObject
{
private:
	std::vector<const char*>* objectTypes;
	const char* objectName;

protected:
	void addObjectType(const char* objectType);

	//===Virtual Functions===//
	virtual void onCreate() {};
	virtual void onDeath() {};

public:
	//===Constructors & Deconstructors===//
	//==Constructors==//
	GameObject();
	GameObject(const char* objectName);

	//==Deconstructors==//
	~GameObject();

	//===Functions===//
	bool typeOf(const char* type);

	//===Getters & Setters===//
	//==Getters==//
	std::vector<const char*>* getObjectTypes();
	const char* getObjectName();

	//==Setters==//
	void setObjectName(const char* newName);
};

