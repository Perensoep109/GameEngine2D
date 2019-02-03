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
		//Clear the screen
		float* clearColors = this->currentScene->getBackground();
		glClearColor(clearColors[0], clearColors[1], clearColors[2], clearColors[3]);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		//Render scene game objects
		//Filter game objects
		this->renderGameObjects(this->currentScene->getObjectsOfType("Renderable2D"));
	}
	else
	{
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
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