#pragma once
#include <glew.h>
class Scene;

namespace RSCM 
{
	//Global resource manager
//	extern RSCM::ResourceManager resourceManager;

	bool imgLoadFromFile(const char* fileName, int &imageWidth, int &imageHeight, GLuint &id);
	static Scene* sceneLoadFromFile(const char* fileName);

	//===Classes===//
	class ResourceManager
	{
	private:
		//===Fields===//
		//==Private==//

		//===Functions===//
		//==Private==//

	public:
		//===Fields===//
		//==Public==//

		//===Functions===//
		//==Public==//

	};
}

