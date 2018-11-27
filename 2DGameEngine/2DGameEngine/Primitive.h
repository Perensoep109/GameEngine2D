#pragma once
#include <vector>
#include "Vertex.h"

class Primitive
{
private:
	std::vector<Vertex*> verticesList;
	std::vector<GLuint*> indices;

public:
	Primitive() {}
	virtual ~Primitive() {}

	//Functions
	void set(Vertex** vertices, const unsigned nrOfVertices, GLuint** indices, const unsigned nrOfIndices)
	{
		for (size_t i = 0; i < nrOfVertices; i++)
		{
			this->verticesList.push_back(vertices[i]);
		}

		for (size_t i = 0; i < nrOfIndices; i++)
		{
			this->indices.push_back(indices[i]);
		}
	}

	inline Vertex** getVertices() { return this->verticesList.data(); };
	inline GLuint** getIndices() { return this->indices.data(); };
	inline const unsigned getNrOfVertices() { return this->verticesList.size(); };
	inline const unsigned getNrOfIndices() { return this->indices.size(); };
};

class PQuad
	: public Primitive
{
public:
	PQuad()
		: Primitive()
	{
		Vertex* vertices[4];
		vertices[0] = new Vertex(glm::vec3(-0.5f, 0.5f, 0.f), glm::vec2(0.f, 1.f), glm::vec3(0.f, 0.f, 1.f));
		vertices[1] = new Vertex(glm::vec3(-0.5f, -0.5f, 0.f), glm::vec2(0.f, 0.f), glm::vec3(0.f, 0.f, 1.f));
		vertices[2] = new Vertex(glm::vec3(0.5f, -0.5f, 0.f), glm::vec2(1.f, 0.f), glm::vec3(0.f, 0.f, 1.f));
		vertices[3] = new Vertex(glm::vec3(0.5f, 0.5f, 0.f), glm::vec2(1.f, 1.f), glm::vec3(0.f, 0.f, 1.f));

		unsigned nrOfVertices = 4;

		GLuint* indices[6];
		indices[0] = new GLuint(0);
		indices[1] = new GLuint(1);
		indices[2] = new GLuint(2);
		indices[3] = new GLuint(0);
		indices[4] = new GLuint(2);
		indices[5] = new GLuint(3);


		unsigned nrOfIndices = 6;

		this->set(vertices, nrOfVertices, indices, nrOfIndices);

		std::cout << "Quad created!" << "\n";
	}
};