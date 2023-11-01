#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 vertexColor;

//uniform mat4 world;
//uniform mat4 view;
//uniform mat4 proj;

uniform mat4 wvp;

out vec4 fragmentColor;

void main()
{
	//gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
	//gl_Position = proj * view * world * vec4(aPos, 1.0);
	gl_Position = wvp * vec4(aPos, 1.0);

	// End of OpenGL vertex shader
	// Correct for OpenGL clip coordinates
	// or glClipControl(GL_LOWER_LEFT, GL_ZERO_TO_ONE) in setup()
	//gl_Position.z = gl_Position.z * 2.0 - gl_Position.w;

	// End of Vulkan vertex shader
	// Correct for Vulkan clip coordinates
	// with glClipControl(GL_UPPER_LEFT, GL_ZERO_TO_ONE) for GL4.4
	gl_Position.y = -gl_Position.y; 

	fragmentColor = vertexColor;
}
