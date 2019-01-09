#version 440 core

layout (location = 0) in vec2 aVertex;
layout (location = 1) in mat4 aInstanceMatrix;


out vec2 TextureCoords;

uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

void main()
{
	gl_Position = ProjectionMatrix * vec4(aVertex.xy, 0.0, 1.0);
	TextureCoords = vec2(0, 0);
}