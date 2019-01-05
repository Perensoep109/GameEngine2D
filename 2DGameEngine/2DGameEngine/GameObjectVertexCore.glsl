#version 440 core

layout (location = 0) in vec2 aVertex;
layout (location = 1) in vec4 aInstanceMatrixRowX;
layout (location = 2) in vec4 aInstanceMatrixRowY;
layout (location = 3) in vec4 aInstanceMatrixRowZ;
layout (location = 4) in vec4 aInstanceMatrixRowW;

out vec2 TextureCoords;

uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

void main()
{
	//gl_Position = ProjectionMatrix * ViewMatrix * aInstanceMatrix * vec4(aVertex.xy, 0.0, 1.0); 
	mat4 aInstanceMatrix = transpose(mat4(aInstanceMatrixRowX, aInstanceMatrixRowY, aInstanceMatrixRowZ, aInstanceMatrixRowW));
	gl_Position = ProjectionMatrix * aInstanceMatrix * vec4(aVertex.xy, 0.0, 1.0);
	TextureCoords = vec2(0, 0);
}