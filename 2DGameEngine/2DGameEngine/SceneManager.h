#pragma once
#include <unordered_map>
class SceneManager
{
	class Scene;
private:
#pragma region Private variables
	//Scene pool
	std::unordered_map<const char*, Scene*>* sceneMap;


#pragma endregion


public:
	SceneManager();
	~SceneManager();

	//Scene pool interaction:
	void addScene(Scene* sceneToAdd);
	void removeScene(const char* sceneName);
	void activateScene(const char* sceneName);
	void deactivateeScene(const char* sceneName);

#pragma region Getters / Setters



#pragma endregion

};

