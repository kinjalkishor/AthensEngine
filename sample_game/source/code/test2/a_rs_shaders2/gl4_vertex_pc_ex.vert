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
	// Transform to homogeneous clip space.
	//gl_Position = vs_in_pos_l * g_wvp;
	
	if (mode == 1) {
		// p*v*w*vp
		//vs_out.pos_h = mul(mul(mul(P, V), W), vs_in.pos_l);
		gl_Position = P * V * W * vs_in_pos_l;
	} else if (mode == 2) {
		// transposed matrices
		// vp*w*v*p				
		//vs_out.pos_h = mul(mul(mul(vs_in.pos_l, W), V), P);
		gl_Position = vs_in_pos_l * W * V * P;
	} else if (mode == 3) {
		// vp*wvp
		// mul: col vector, col major
		//vs_out.pos_h = mul(g_wvp, vs_in.pos_l);
		gl_Position = g_wvp * vs_in_pos_l;
	} else if (mode == 4) {
		// transposed matrices
		// wvp*vp
		// mul: row vector, row major
		//vs_out.pos_h = mul(vs_in.pos_l, g_wvp);
		gl_Position = vs_in_pos_l * g_wvp;
	}
	

	//gl_Position.z = gl_Position.z * 2.0 - gl_Position.w;
	// Correct clip coordinates for vk and glClipControl in GL4.4
	//gl_Position.y = -gl_Position.y; 

	vs_out.vcolor = vs_in_vcolor;
}
