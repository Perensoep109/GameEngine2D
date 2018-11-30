#version 440
in vec2 pos;

vec4 gl_Position;

//Uniforms
uniform int in_objectAmount;

//Matrices
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

//Outputs
out ObjectOutput
{
	vec3[256] out_objectData;
	float out_objectRotation;
	int out_objectAmount;
} out_data;

void main()
{
    gl_Position = ViewMatrix * ProjectionMatrix * vec4(pos, 0.0, 1.0);
	out_data.out_objectAmount = in_objectAmount;
}