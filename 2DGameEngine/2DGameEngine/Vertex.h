#pragma once
#include <glm.hpp>

struct Vertex
{
	glm::vec3 position;
	glm::vec2 texcoord;
	glm::vec3 normal;

public:
	Vertex(glm::vec3 _position, glm::vec2 _texcoord, glm::vec3 _normal)
	{
		this->position = _position;
		this->texcoord = _texcoord;
		this->normal = _normal;
	}
};