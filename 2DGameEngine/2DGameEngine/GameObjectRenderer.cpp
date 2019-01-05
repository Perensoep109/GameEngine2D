#include "Renderer2D.h"
#include "GameObjectManager.h"
#include <gtc\type_ptr.hpp>

void Renderer2D::setupGameObjectRender()
{
}

void Renderer2D::renderGameObjects()
{
	int objectAmount = GameObjectManager::getRenderObjectAmount();

	//Check if there are objects to be rendered
	if (objectAmount == 0)
		return;

	this->gameObjectShader->use();

	//Update
	updateGameObjectRender(objectAmount);

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

void Renderer2D::updateGameObjectRender(int objectsToRender)
{
	//Variables

	//Assemble all objects their instance matrices
	std::vector<glm::vec4>* xs = new std::vector<glm::vec4>();
	std::vector<glm::vec4>* ys = new std::vector<glm::vec4>();
	std::vector<glm::vec4>* zs = new std::vector<glm::vec4>();
	std::vector<glm::vec4>* ws = new std::vector<glm::vec4>();
	
	//Assemble all data
	assembleVBOData(objectsToRender, xs, ys, zs, ws);

	//Then buffer this data
	glBindVertexArray(this->quadVAO);
	
	//Location = 1, instance matrix X row
	glEnableVertexAttribArray(1);
	glGenBuffers(1, &this->instanceMatXRow);
	glBindBuffer(GL_ARRAY_BUFFER, this->instanceMatXRow);
	glBufferData(GL_ARRAY_BUFFER, xs->size() * sizeof(glm::vec4) * 4, xs->data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, this->instanceMatXRow);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), NULL);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glVertexAttribDivisor(1, 1);

	//Location = 2, instance matrix Y row
	glEnableVertexAttribArray(2);
	glGenBuffers(1, &this->instanceMatYRow);
	glBindBuffer(GL_ARRAY_BUFFER, this->instanceMatYRow);
	glBufferData(GL_ARRAY_BUFFER, ys->size() * sizeof(glm::vec4) * 4, ys->data(), GL_DYNAMIC_DRAW);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), NULL);
	glVertexAttribDivisor(2, 1);

	//Location = 3, instance matrix Z row
	glEnableVertexAttribArray(3);
	glGenBuffers(1, &this->instanceMatZRow);//
	glBindBuffer(GL_ARRAY_BUFFER, this->instanceMatZRow);
	glBufferData(GL_ARRAY_BUFFER, zs->size() * sizeof(glm::vec4) * 4, zs->data(), GL_DYNAMIC_DRAW);
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), NULL);
	glVertexAttribDivisor(3, 1);

	//Location = 4, instance matrix W row
	glEnableVertexAttribArray(4);
	glGenBuffers(1, &this->instanceMatWRow);//
	glBindBuffer(GL_ARRAY_BUFFER, this->instanceMatWRow);
	glBufferData(GL_ARRAY_BUFFER, ws->size() * sizeof(glm::vec4) * 4, ws->data(), GL_DYNAMIC_DRAW);
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), NULL);
	glVertexAttribDivisor(4, 1);
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
	glDeleteBuffers(1, &instanceMatXRow);
	glDeleteBuffers(1, &instanceMatYRow);
	glDeleteBuffers(1, &instanceMatZRow);
	glDeleteBuffers(1, &instanceMatWRow);
	glBindVertexArray(0);
}

#pragma endregion