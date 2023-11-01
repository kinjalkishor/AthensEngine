#version 460 core

layout(std140, binding = 0) uniform cb_per_object {
    mat4 g_wvp;
	mat4 W;
	mat4 V;
	mat4 P;
	int mode;
	vec3 pad;
};

layout(location = 0) in vec4 vs_in_pos_l;
layout(location = 1) in vec4 vs_in_vcolor;


out VS_OUTPUT {
	vec4 vcolor; 
} vs_out;

void main() {
	//gl_Position = vec4(vs_in_pos_l.x, vs_in_pos_l.y, vs_in_pos_l.z, 1.0);

	// Transform to homogeneous clip space.
	if (mode == 1) {		
		// transposed matrices
		gl_Position = vs_in_pos_l * W * V * P;
	} else if (mode == 2) {
		// transposed matrices
		gl_Position = vs_in_pos_l * g_wvp;
	}
	
	//reverse multiply if matrices are not transposed.
	

	//gl_Position.z = gl_Position.z * 2.0 - gl_Position.w;
	// Correct clip coordinates for vk and glClipControl in GL4.4
	//gl_Position.y = -gl_Position.y; 

	vs_out.vcolor = vs_in_vcolor;
}
