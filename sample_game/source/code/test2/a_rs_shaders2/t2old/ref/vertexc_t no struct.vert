#version 460 core

//uniform mat4 world;
//uniform mat4 view;
//uniform mat4 proj;

//uniform mat4 wvp;

// one vec4/float4 takes one location
//layout (std140) uniform cb_mat_wvp
layout(std140, binding = 0) uniform cb_mat_wvp
{
    mat4 wvp;
};

layout(location = 0) in vec3 pos;
layout(location = 1) in vec4 in_vcolor;

// OpenGL does not allow input blocks in vertex shaders
//layout(location = 0) in VS_INPUT
//{
//    vec3 pos; 		//location 0
//    vec4 vcolor; 	//location 1
//} vs_in;

//out vec4 out_vcolor;
out VS_OUTPUT
{
    vec4 vcolor; //send color to next stage
} sh_out;

void main()
{
	//VS_OUTPUT sh_out;

	//gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);
	//gl_Position = proj * view * world * vec4(pos, 1.0);
	gl_Position = wvp * vec4(pos, 1.0);

	// End of OpenGL vertex shader
	// Correct for OpenGL clip coordinates
	// or glClipControl(GL_LOWER_LEFT, GL_ZERO_TO_ONE) in setup()
	//gl_Position.z = gl_Position.z * 2.0 - gl_Position.w;

	// End of Vulkan vertex shader
	// Correct for Vulkan clip coordinates
	// with glClipControl(GL_UPPER_LEFT, GL_ZERO_TO_ONE) for GL4.4
	gl_Position.y = -gl_Position.y; 

	//out_vcolor = in_vcolor;
	sh_out.vcolor = in_vcolor;
}
