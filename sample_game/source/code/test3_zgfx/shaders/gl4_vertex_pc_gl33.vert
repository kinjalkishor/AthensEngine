#version 460 core

layout(location = 0) in vec4 vs_in_pos_l;
layout(location = 1) in vec4 vs_in_vcolor;

uniform mat4 g_wvp;

out VS_OUTPUT {
	vec4 vcolor; 
} vs_out;

void main() {
	// Transform to homogeneous clip space.
	gl_Position = vs_in_pos_l * g_wvp;
	

	gl_Position.z = gl_Position.z * 2.0 - gl_Position.w;
	// Correct clip coordinates for vk and glClipControl in GL4.4
	//gl_Position.y = -gl_Position.y; 

	vs_out.vcolor = vs_in_vcolor;
}
