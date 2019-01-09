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
	glGenBuffers(1, &matBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, matBuffer);
	glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(float) * MAX_INSTANCES, NULL, GL_STREAM_DRAW);
}

void Renderer2D::updateBufferData(int objectAmount)
{
	std::vector<glm::mat4>* matData = new std::vector<glm::mat4>();

	for (int i = 0; i < objectAmount; i++)
	{
		matData->push_back(*GameObjectManager::renderObjects->at(i)->getInstanceMatrix());
	}

	glBindBuffer(GL_ARRAY_BUFFER, matBuffer);
	glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(float) * MAX_INSTANCES, NULL, GL_STREAM_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, objectAmount * sizeof(float) * 16, &matData->front());
}

void Renderer2D::setAttributes()
{
	GLsizei vec4Size = sizeof(glm::vec4);
	glBindVertexArray(this->quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, matBuffer);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)0);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)(vec4Size));
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)(2 * vec4Size));
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)(3 * vec4Size));

	glVertexAttribDivisor(0, 0);
	glVertexAttribDivisor(1, 1);
	glVertexAttribDivisor(2, 1);
	glVertexAttribDivisor(3, 1);
	glVertexAttribDivisor(4, 1);

	glBindVertexArray(0);

	/*
	GLsizei vec4Size = sizeof(glm::vec4);
	glBindVertexArray(this->quadVAO);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)0);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)(vec4Size));
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)(2 * vec4Size));
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * vec4Size, (void*)(3 * vec4Size));

	glVertexAttribDivisor(1, 1);
	glVertexAttribDivisor(2, 1);
	glVertexAttribDivisor(3, 1);
	glVertexAttribDivisor(4, 1);

	glBindVertexArray(0);
	*/
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