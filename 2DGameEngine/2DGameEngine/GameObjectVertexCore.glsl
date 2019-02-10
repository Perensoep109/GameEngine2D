#version 440 core

//===Inputs===//
layout (location = 0) in vec2 aVertex;
layout (location = 1) in vec2 aInstanceOffset;
layout (location = 5) in int aAtlasIndex;

//==Uniforms==//
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

//=Textures=//
uniform sampler2D spriteAtlas;
uniform int spriteWidth;
uniform int spriteHeight;

//===Outputs===//
out vec4 TextureCoords;

//===Functions===//
vec4 createTexCoords(int index)
{
	//==Return values==//
	vec4 returnVal = vec4(0, 0, 0, 0);

	if(index != 0)
	{
		//==Variables==//
		ivec2 texSize = textureSize(spriteAtlas, 0);
		int wAmount = texSize.x / spriteWidth;

		//=Calculate position=//
		returnVal.x = (index % wAmount) * 64;
		returnVal.y = (index / wAmount) * 64;
	}

	return returnVal;
}

//===Main program===//
void main()
{
	gl_Position = ViewMatrix * ProjectionMatrix * vec4(aVertex.x + aInstanceOffset.x, aVertex.y + aInstanceOffset.y, 0.0, 1.0);
	TextureCoords = createTexCoords(aAtlasIndex);
}