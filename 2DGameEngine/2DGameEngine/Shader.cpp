#include "Shader.h"

#pragma region Constructors & Deconstructors
Shader::Shader() : versionMajor(3), versionMinor(3)
{
	glfwTerminate();
}

Shader::Shader(const int versionMajor, const int versionMinor, const char* vertexFile, const char* fragmentFile, const char* geometryFile)
	: versionMajor(versionMinor), versionMinor(versionMajor)
{
	GLuint vertexShader = 0;
	GLuint geometryShader = 0;
	GLuint fragmentShader = 0;

	vertexShader = loadShader(GL_VERTEX_SHADER, vertexFile);

	if (geometryFile != nullptr)
		geometryShader = loadShader(GL_GEOMETRY_SHADER, geometryFile);

	fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentFile);

	this->linkProgram(vertexShader, geometryShader, fragmentShader);

	//End
	glDeleteShader(vertexShader);
	glDeleteShader(geometryShader);
	glDeleteShader(fragmentShader);
}


Shader::~Shader()
{
	glDeleteProgram(this->id);
	std::cout << "Deleted shader" << "\n";
}

#pragma endregion

#pragma region Functions

std::string Shader::loadShaderSource(const char* fileName)
{
	std::string temp = "";
	std::string src = "";

	std::ifstream inFile;

	//Vertex shader
	inFile.open(fileName);

	if (inFile.is_open())
	{
		while (std::getline(inFile, temp))
			src += temp + "\n";
	}
	else
	{
		std::cout << "ERROR_LOAD_SHADER::COULD_NOT_OPEN_FILE: " << fileName << "\n";
	}

	inFile.close();

	return src;
}

GLuint Shader::loadShader(GLenum type, const char * fileName)
{
	char infoLog[512];
	GLint success;

	GLuint shader = glCreateShader(type);

	std::string src = this->loadShaderSource(fileName);
	const GLchar* GLsrc = src.c_str();
	glShaderSource(shader, 1, &GLsrc, NULL);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "Error, could not compile shader, file name: " << fileName << "\n";
		std::cout << infoLog << "\n";
	}
	return shader;
}

void Shader::linkProgram(GLuint vertexShader, GLuint geometryShader, GLuint fragmentShader)
{
	char infoLog[512];
	GLint success;

	this->id = glCreateProgram();

	glAttachShader(this->id, vertexShader);

	if (geometryShader)
		glAttachShader(this->id, geometryShader);

	glAttachShader(this->id, fragmentShader);

	glLinkProgram(this->id);

	glGetProgramiv(this->id, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(this->id, 512, NULL, infoLog);
		std::cout << "Error, shader could not be linked" << "\n";
		std::cout << infoLog << "\n";
	}

	glUseProgram(this->id);
}

void Shader::use()
{
	glUseProgram(this->id);
}

void Shader::unuse()
{
	glUseProgram(0);
}

void Shader::setVec1f(GLfloat value, const GLchar * name)
{
	this->use();

	glUniform1f(glGetUniformLocation(this->id, name), value);

	this->unuse();
}

void Shader::setVec2f(glm::fvec2 value, const GLchar* name)
{
	this->use();

	glUniform2fv(glGetUniformLocation(this->id, name), 1, glm::value_ptr(value));

	this->unuse();
}

void Shader::setVec3f(glm::fvec3 value, const GLchar* name)
{
	this->use();

	glUniform3fv(glGetUniformLocation(this->id, name), 1, glm::value_ptr(value));

	this->unuse();
}

void Shader::setVec4f(glm::fvec4 value, const GLchar* name)
{
	this->use();

	glUniform4fv(glGetUniformLocation(this->id, name), 1, glm::value_ptr(value));

	this->unuse();
}

//Set shader Matrices uniforms
void Shader::setMat3fv(glm::mat3 value, const GLchar* name, GLboolean transpose)
{
	this->use();

	glUniformMatrix3fv(glGetUniformLocation(this->id, name), 1, transpose, glm::value_ptr(value));

	this->unuse();
}

void Shader::setMat4fv(glm::mat4 value, const GLchar* name, GLboolean transpose)
{
	this->use();

	glUniformMatrix4fv(glGetUniformLocation(this->id, name), 1, transpose, glm::value_ptr(value));

	this->unuse();
}

//Set shader texture
void Shader::set1i(GLint value, const GLchar* name)
{
	this->use();

	glUniform1i(glGetUniformLocation(this->id, name), value);

	this->unuse();
}

#pragma endregion