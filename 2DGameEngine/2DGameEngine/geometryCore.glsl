#version 440 core

    layout(points) in;
    layout(triangle_strip, max_vertices = 5) out;

	in ObjectInput
	{
		vec2 in_objectData[];
		float in_objectRotation;
		int in_objectAmount;
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
        for(int i = 0; i < objectInput[0].in_objectAmount; i++)
		{
			
		}
    }