#version 440
in vec2 pos;

vec4 gl_Position;

//Matrices
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

void main()
{
    gl_Position = ViewMatrix * ProjectionMatrix * vec4(pos, 0.0, 1.0);
}