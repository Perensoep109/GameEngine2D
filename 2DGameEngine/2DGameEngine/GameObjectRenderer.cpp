#include "Renderer2D.h"
#include "GameObjectManager.h"
#include <gtc\type_ptr.hpp>

void Renderer2D::setupGameObjectRender()
{
	createBuffers();
	setAttributes();
}

void Renderer2D::renderGameObjects()
{
	int objectAmount = GameObjectManager::getRenderObjectAmount();

	//Check if there are objects to be rendered
	if (objectAmount == 0)
		return;

	this->gameObjectShader->use();

	//Update
	updateBufferData(objectAmount);

	sendToGameObjectShader();
	
	glBindVertexArray(this->quadVAO);
	glDrawArraysInstanced(GL_TRIANGLES, 0, 6, objectAmount);

	this->gameObjectShader->unuse();

	endGameObjectRender();
}

void Renderer2D::sendToGameObjectShader()
{
	glUniformMatrix4fv(glGetUniformLocation(gameObjectShader->id, "ProjectionMatrix"), 1, false, glm::value_ptr(*this->mainWindow->getProjectionMatrix()));
}

void Renderer2D::createBuffers()
{
	glGenBuffers(1, &posBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(float) * MAX_INSTANCES, NULL, GL_STREAM_DRAW);
}

void Renderer2D::updateBufferData(int objectAmount)
{
	std::vector<glm::vec2>* posData = new std::vector<glm::vec2>();

	for (int i = 0; i < objectAmount; i++)
	{
		posData->push_back(*GameObjectManager::renderObjects->at(i)->getPosition());
	}

	glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(float) * MAX_INSTANCES, NULL, GL_STREAM_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, objectAmount * sizeof(float) * 4, &posData->front());
}

void Renderer2D::setAttributes()
{
	glBindVertexArray(this->quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

	glVertexAttribDivisor(0, 0);
	glVertexAttribDivisor(1, 1);
}

#pragma region Memory cleaning

void Renderer2D::deleteGameObjectRendering()
{
	
}

void Renderer2D::endGameObjectRender()
{
	glBindVertexArray(0);
}

#pragma endregion