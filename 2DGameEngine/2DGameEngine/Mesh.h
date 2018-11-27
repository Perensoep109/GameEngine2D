#pragma once

#include "Mesh.h"
#include "Shader.h"
#include "Vertex.h"
#include "Primitive.h"
#include <gtc/matrix_transform.hpp>
#include <vector>
#include <iostream>

class Mesh
{
private:
	//Fields
	unsigned int VAO, VBO, EBO;
		
	//Functions:
	void setupMesh();

public:
	//Fields
	std::vector<Vertex*> vertices;
	std::vector<GLuint*> indices;

	glm::mat4 ModelMatrix;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	Mesh();
	Mesh(Primitive* primitiveType);
	~Mesh();
};

