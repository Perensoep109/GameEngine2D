#include "Renderer2D.h"
#include <gtc\type_ptr.hpp>

#pragma region Setup

void Renderer2D::setupGameObjectRender()
{
	batchAmount = 0;
	currentBatch = 0;

	createBuffers();
	setAttributes();
	this->gameObjectShader = new Shader(4, 4, "gameObjectVertexCore.glsl", "gameObjectFragmentCore.glsl");
}

void Renderer2D::createBuffers()
{
	glGenBuffers(1, &posBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->posBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * MAX_INSTANCES, NULL, GL_STREAM_DRAW);

}

void Renderer2D::setAttributes()
{
	glBindVertexArray(this->quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glVertexAttribDivisor(0, 0);
	glVertexAttribDivisor(1, 1);
}

#pragma endregion

#pragma region Functions
#pragma region Manage buffering
void Renderer2D::updateBufferData(int objectsToRender, std::vector<GameObject*>* gameObjects)
{
	//Write all data to the pos buffer
	std::vector<float>* posData = new std::vector<float>();

	for (int i = 0; i < objectsToRender; i++)
	{
		Renderable2D* curObj = static_cast<Renderable2D*>(gameObjects->at(i));
		glm::vec2* curData = curObj->getPosition();
		posData->push_back(curData->x);
		posData->push_back(curData->y);
		posData->push_back(0.f);
	}

	//Buffer data
	glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(float) * MAX_INSTANCES, NULL, GL_STREAM_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, objectsToRender * sizeof(float) * 3, posData->data());

	//Clean memory
	delete posData;
}
#pragma endregion

#pragma region Manage filtering

std::vector<GameObject*>* Renderer2D::clipGameObjects(std::vector<GameObject*>* gameObjects)
{
	return gameObjects;
}

std::vector<GameObject*>* Renderer2D::filterGameObjects(std::vector<GameObject*>* gameObjects)
{
	return gameObjects;
}

std::vector<GameObject*>* Renderer2D::batchGameObjects(std::vector<GameObject*>* gameObjects)
{
	return gameObjects;
}

#pragma endregion


void Renderer2D::sendToGameObjectShader()
{
	//glUniformMatrix4fv(glGetUniformLocation(gameObjectShader->id, "ProjectionMatrix"), 1, false, glm::value_ptr(this->mainWindow->getProjectionMatrix()));
	this->gameObjectShader->setMat4fv(this->mainWindow->getProjectionMatrix(), "ProjectionMatrix", false);
	this->gameObjectShader->setMat4fv(*this->ViewMatrix, "ViewMatrix", false);
}

void Renderer2D::deleteGameObjectRendering()
{

}

#pragma endregion

void Renderer2D::renderGameObjects(std::vector<GameObject*>* gameObjects)
{
	//Check if a proper set of objects is in here
	if (gameObjects == nullptr)
		return;

	int objectAmount = gameObjects->size();

	//Check if there are objects to be rendered
	if (objectAmount == 0)
		return;

	//Filter all the game objects
	gameObjects = clipGameObjects(gameObjects);
	gameObjects = batchGameObjects(gameObjects);

	this->gameObjectShader->use();

	//Update
	updateBufferData(objectAmount, gameObjects);

	sendToGameObjectShader();

	glBindVertexArray(this->quadVAO);
	glDrawArraysInstanced(GL_TRIANGLES, 0, 6, objectAmount);

	this->gameObjectShader->unuse();
}
