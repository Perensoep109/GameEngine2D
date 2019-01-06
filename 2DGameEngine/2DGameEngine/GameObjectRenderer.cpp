#include "Renderer2D.h"
#include "GameObjectManager.h"
#include <gtc\type_ptr.hpp>

void Renderer2D::setupGameObjectRender()
{
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
	bufferData(objectAmount);

	sendToGameObjectShader();

	glBindVertexArray(this->quadVAO);
	glDrawArraysInstanced(GL_TRIANGLES, 0, 6, objectAmount);

	this->gameObjectShader->unuse();

	endGameObjectRender();
}

void Renderer2D::sendToGameObjectShader()
{
	//glUniformMatrix4fv(glGetUniformLocation(gameObjectShader->id, "ProjectionMatrix"), 1, false, glm::value_ptr(*this->mainWindow->getProjectionMatrix()));
}

void Renderer2D::bufferData(int objectsToRender)
{
	std::vector<glm::mat4>* instanceMatrices = new std::vector<glm::mat4>();

	for (int i = 0; i < objectsToRender; i++)
	{
		glm::mat4 tempMat = *GameObjectManager::renderObjects->at(i)->getInstanceMatrix();
		instanceMatrices->push_back(tempMat);
	}

	glBindVertexArray(this->quadVAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->instanceMatricesBuffer);
	glBufferData(GL_ARRAY_BUFFER, objectsToRender * sizeof(glm::mat4), &instanceMatrices[0], GL_STATIC_DRAW);
}

void Renderer2D::setAttributes()
{
	glBindVertexArray(this->quadVAO);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)0);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4)));
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(2 * sizeof(glm::vec4)));
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(3 * sizeof(glm::vec4)));

	glVertexAttribDivisor(3, 1);
	glVertexAttribDivisor(4, 1);
	glVertexAttribDivisor(5, 1);
	glVertexAttribDivisor(6, 1);

	glBindVertexArray(0);
}

void Renderer2D::assembleVBOData(int objectsToRender, std::vector<glm::vec4>* xVector, std::vector<glm::vec4>* yVector, std::vector<glm::vec4>* zVector, std::vector<glm::vec4>* wVector)
{
	for (int i = 0; i < objectsToRender; i++)
	{
		glm::mat4* tempMat = GameObjectManager::renderObjects->at(i)->getInstanceMatrix();
		xVector->push_back(tempMat[0][0]);
		yVector->push_back(tempMat[1][0]);
		zVector->push_back(tempMat[2][0]);
		wVector->push_back(tempMat[3][0]);
	}
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