#version 440
in vec2 pos;

vec4 gl_Position;

//Uniforms
uniform int objectAmount;

//Matrices
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

//Outputs
out ObjectOutput
{
	int amountOfObjects;
	vec2[256] objectData;
};

void main()
{
    gl_Position = ViewMatrix * ProjectionMatrix * vec4(pos, 0.0, 1.0);
}