#include "Mesh.h"



Mesh::Mesh()
{
}

Mesh::Mesh(Primitive* primitiveType)
{
	Vertex** primVertices = primitiveType->getVertices();
	GLuint** primIndices = primitiveType->getIndices();

	for (size_t i = 0; i < primitiveType->getNrOfVertices(); i++)
	{
		this->vertices.push_back(primVertices[i]);
	}

	for (size_t i = 0; i < primitiveType->getNrOfIndices(); i++)
	{
		this->indices.push_back(primIndices[i]);
	}

	setupMesh();
}


Mesh::~Mesh()
{
	
}

void Mesh::setupMesh()
{
	//Create VAO
	glCreateVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	//Create VBO
	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size(), &vertices[0], GL_STATIC_DRAW);

	//Create EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	//Position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
	glEnableVertexAttribArray(0);

	//Texcoord
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcoord));
	glEnableVertexAttribArray(1);

	//Normal
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}