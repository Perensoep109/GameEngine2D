#pragma once
#include <glew.h>
#include <unordered_map>
class Scene;

namespace RSCM 
{
	//Global resource manager
	extern RSCM::ResourceManager resourceManager;

	bool imgLoadFromFile(const char* fileName, int &imageWidth, int &imageHeight, GLuint &id);
	static Scene* sceneLoadFromFile(const char* fileName);

	//===Classes===//
	class ResourceManager
	{
	private:
		//===Fields===//
		//==Private==//
		std::unordered_map<BaseResource*, std::string> resourceMap;
		std::unordered_map<BaseResource*, std::string>::iterator mapIterator;

		//===Functions===//
		//==Private==//

	public:
		//===Fields===//
		//==Public==//

		//===Functions===//
		//==Public==//

	};

	class BaseResource
	{
	private:
		//===Fields===//
		//==Private==//
		const char* key;

		//==Functions==//
		//==Private==//

	public:
		//===Fields===//
		//==Public==//

		//===Functions===//
		//==Public==//
		//=Constructors=//
		BaseResource(const char* key)
		{
			this->key = key;
		}

		//==Getters & Setters==//
		//=Getters=//
		const char* getKey();

		//=Setters=//

	};
}

