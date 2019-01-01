#version 440 core

in vec2 TextureCoords;
out vec4 FragColor;

uniform sampler2D spriteAtlas;
uniform vec3 spriteColor;

void main()
{
    //FragColor = vec4(spriteColor, 1.0) * texture(spriteAtlas, TextureCoords);
	FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}