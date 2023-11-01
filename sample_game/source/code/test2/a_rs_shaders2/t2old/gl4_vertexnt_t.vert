#version 460 core

layout(std140, binding = 0) uniform cb_per_object
{
   mat4 g_wvp;
};

layout(location = 0) in vec4 vs_in_pos_l;
layout(location = 1) in vec2 vs_in_tex0;
layout(location = 2) in vec3 vs_in_norm_l;

out VS_OUTPUT
{
	vec2 tex0;
	vec3 norm_w; 	
} vs_out;


void main()
{
	// Transform to homogeneous clip space.
	gl_Position = vs_in_pos_l * g_wvp;

	// Correct clip coordinates for vk and glClipControl in GL4.4
	gl_Position.y = -gl_Position.y; 

	vs_out.norm_w = vs_in_norm_l;

	vs_out.tex0 = vs_in_tex0;
}


