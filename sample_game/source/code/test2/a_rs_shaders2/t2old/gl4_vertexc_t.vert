#version 460 core

layout(std140, binding = 0) uniform cb_per_object
{
    mat4 g_wvp;
};

layout(location = 0) in vec4 vs_in_pos_l;
layout(location = 1) in vec4 vs_in_vcolor;


out VS_OUTPUT
{
	vec4 vcolor; 
} vs_out;

void main()
{
	// Transform to homogeneous clip space.
	gl_Position = vs_in_pos_l * g_wvp;

	// Correct clip coordinates for vk and glClipControl in GL4.4
	gl_Position.y = -gl_Position.y; 

	vs_out.vcolor = vs_in_vcolor;
}
