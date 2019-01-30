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
	this->matBuffers = new std::array<GLuint, 4>();

	for (int i = 0; i < 4; i++)
	{
		glGenBuffers(1, &matBuffers->at(i));
		glBindBuffer(GL_ARRAY_BUFFER, this->matBuffers->at(0));
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 4 * MAX_INSTANCES, NULL, GL_STREAM_DRAW);
	}
}

void Renderer2D::setAttributes()
{
	glBindVertexArray(this->quadVAO);

	glBindBuffer(GL_ARRAY_BUFFER, this->matBuffers->at(0));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, this->matBuffers->at(1));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, this->matBuffers->at(2));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, this->matBuffers->at(3));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);

	glVertexAttribDivisor(0, 0);
	glVertexAttribDivisor(1, 1);
	glVertexAttribDivisor(2, 1);
	glVertexAttribDivisor(3, 1);
	glVertexAttribDivisor(4, 1);
}

#pragma endregion

#pragma region Functions
#pragma region Manage buffering
void Renderer2D::updateBufferData(int objectsToRender, std::vector<GameObject*>* gameObjects)
{
	for (int i = 0; i < objectsToRender; i++)
	{
		Renderable2D* curObj = static_cast<Renderable2D*>(gameObjects->at(i));
		std::array<float, 16>* curMatData = curObj->getInstanceMat();
		float data[4];

		for (int j = 0; j < 4; j++)
		{
			for (int n = 0; n < 4; n++)
			{
				//Copy the column to buffer into one
				data[n] = curMatData->at(n + j);
			}
			glBindBuffer(GL_ARRAY_BUFFER, this->matBuffers->at(j));
			glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(float) * MAX_INSTANCES, NULL, GL_STREAM_DRAW);
			glBufferSubData(GL_ARRAY_BUFFER, 0, objectsToRender * sizeof(float) * 4, data);
		}
	}
}
#pragma endregion

#pragma region Manage batching

void Renderer2D::batchGameObjects(int objectAmount)
{
	//Check if batching is required
	if (objectAmount <= MAX_INSTANCES)
		return;

	//Start batching
	
}

#pragma endregion


void Renderer2D::sendToGameObjectShader()
{
	//glUniformMatrix4fv(glGetUniformLocation(gameObjectShader->id, "ProjectionMatrix"), 1, false, glm::value_ptr(this->mainWindow->getProjectionMatrix()));
	this->gameObjectShader->setMat4fv(this->mainWindow->getProjectionMatrix(), "ProjectionMatrix", false);
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

	//Batch all the objects into batches of 1000 objects max.
	batchGameObjects(objectAmount);

	this->gameObjectShader->use();

	//Update
	updateBufferData(objectAmount, gameObjects);

	sendToGameObjectShader();

	glBindVertexArray(this->quadVAO);
	glDrawArraysInstanced(GL_TRIANGLES, 0, 6, objectAmount);

	this->gameObjectShader->unuse();
}
