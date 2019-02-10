#version 440 core

//==I/O==//
in vec4 TextureCoords;
out vec4 FragColor;

//==Texture==//
uniform sampler2D spriteAtlas;

//==Functions==//
vec2 convertTexCoords(vec4 texCoords)
{
	//==Return value==//
	vec2 returnVal = vec2(0, 0);

	//==Variables==//
	ivec2 texSize = textureSize(spriteAtlas, 0);

	//==Function==//
	if(texCoords.x != 0)
		returnVal.x = texCoords.x / texSize.x;

	if(texCoords.y != 0)
		returnVal.y = texCoords.y / texSize.y;
	
	return returnVal;
}

//==Main program==//
void main()
{
    //FragColor = vec4(spriteColor, 1.0) * texture(spriteAtlas, TextureCoords);
	FragColor = texture(spriteAtlas, convertTexCoords(TextureCoords));
}