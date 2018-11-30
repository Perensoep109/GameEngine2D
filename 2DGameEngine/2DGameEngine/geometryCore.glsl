#version 440 core

    layout(points) in;
    layout(triangle_strip, max_vertices = 5) out;

	in int objectAmount;

	in ObjectInput
	{
		vec2[256] objectData;
	} objectInput[];

	void createQuad(vec4 position)
	{
		gl_Position = position + vec4(-0.1, 0.1, 0.0, 0.0);
        EmitVertex();

        gl_Position = position + vec4(0.1, 0.1, 0.0, 0.0);
        EmitVertex();

        gl_Position = position + vec4(0.1, -0.1, 0.0, 0.0);
        EmitVertex();

        gl_Position = position + vec4(-0.1, -0.1, 0.0, 0.0);
        EmitVertex();

        gl_Position = position + vec4(-0.1, 0.1, 0.0, 0.0);
        EmitVertex();

        EndPrimitive();
	}

    void main()
    {
        for(int i = 0; i < objectAmount; i++)
		{
			//Render all the objects that are in this shader
			//createQuad(objectInput[0].objectData[i]);
		}
    }