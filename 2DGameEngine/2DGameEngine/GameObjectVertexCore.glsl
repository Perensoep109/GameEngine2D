#version 440 core

layout (location = 0) in vec2 aVertex;
layout (location = 1) in float[4] aArr1;
layout (location = 2) in float[4] aArr2;
layout (location = 3) in float[4] aArr3;
layout (location = 4) in float[4] aArr4;

out vec2 TextureCoords;

uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

mat4 makeTransMat()
{
	mat4 returnMat;

	for(int i = 0; i < 4; i++)
	{
		returnMat[0][i] =		aArr1[i];
	}
	for(int i = 0; i < 4; i++)
	{
		returnMat[1][i] =		aArr2[i];
	}
	for(int i = 0; i < 4; i++)
	{
		returnMat[2][i] =		aArr3[i];
	}
	for(int i = 0; i < 4; i++)
	{
		returnMat[3][i] =		aArr4[i];
	}

//	returnMat[0]  =	aArr1[0]; returnMat[1]  =	aArr1[1]; returnMat[2]  =	aArr1[2]; returnMat[3]  =	aArr1[3];
//	returnMat[4]  =	aArr2[0]; returnMat[5]  =	aArr2[1]; returnMat[6]  =	aArr2[2]; returnMat[7]  =	aArr2[3];
//	returnMat[8]  =	aArr3[0]; returnMat[9]  =	aArr3[1]; returnMat[10] =	aArr3[2]; returnMat[11] =	aArr3[3];
//	returnMat[12] =	aArr4[0]; returnMat[13] =	aArr4[1]; returnMat[14] =	aArr4[2]; returnMat[15] =	aArr4[3];

	return returnMat;
}

void main()
{
	gl_Position = ProjectionMatrix * makeTransMat() * vec4(aVertex.x, aVertex.y, 0.0, 1.0);
	TextureCoords = vec2(0, 0);
}