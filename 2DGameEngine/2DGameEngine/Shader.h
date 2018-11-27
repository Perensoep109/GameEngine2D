#ifndef SHADER_H
#define SHADER_H

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>

class Shader
{
private:
	
	const int versionMajor, versionMinor;

	std::string loadShaderSource(const char* fileName);
	GLuint loadShader(GLenum type, const char* fileName);

	void linkProgram(GLuint vertexShader, GLuint geometryShader, GLuint fragmentShader);
public:
	GLuint id;

	//Functions
	void use();
	void unuse();

	//Set shader variables
	void setVec1f(GLfloat value, const GLchar* name);
	void setVec2f(glm::fvec2 value, const GLchar* name);
	void setVec3f(glm::fvec3 value, const GLchar* name);
	void setVec4f(glm::fvec4 value, const GLchar* name);
	void setMat3fv(glm::mat3 value, const GLchar* name, GLboolean transpose = GL_FALSE);
	void setMat4fv(glm::mat4 value, const GLchar* name, GLboolean transpose = GL_FALSE);
	void set1i(GLint value, const GLchar* name);

	Shader();
	Shader(const int versionMajor, const int versionMinor, const char* vertexFile, const char* fragmentFile, const char* geometryFile = nullptr);
	~Shader();

};

#endif SHADER_H