#include "Renderer2D.h"

//=========SCENE RENDERER=========//
//==Functions==//
void Renderer2D::setupSceneRender()
{

}

void Renderer2D::renderScene()
{
	if (this->currentScene != nullptr)
	{
		
	}
	else
	{
		std::cout << "No scene is selected" << "\n";
	}
}

void Renderer2D::endSceneRender()
{

}

void Renderer2D::deleteSceneRender()
{

}

//Getters & Setters
//==Getters==//

//==Setters==//
void Renderer2D::setCurrentScene(Scene* newScene)
{
	this->currentScene = newScene;
}