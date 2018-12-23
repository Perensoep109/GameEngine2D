#version 440

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aOffset; //Offset of this instance, from the first instance in the array

out vec3 fColor;

//Matrices:
uniform mat4 ProjectionMatrix;
uniform mat4 ViewMatrix;

void main()
{
	gl_Position = vec4(aPos + aOffset, 0.0, 1.0);
	fColor = aColor;
}