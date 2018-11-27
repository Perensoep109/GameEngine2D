#version 440
in vec2 pos;

vec4 gl_Position;

void main()
{
    gl_Position = vec4(pos, 0.0, 1.0);
}