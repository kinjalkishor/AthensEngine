
#version 460 core

// texture sampler
uniform sampler2D g_sam_trilinear;

in VS_OUTPUT {
    vec4 vcolor; 
	vec2 tex0;
} ps_in;

out vec4 ps_out_color;


void main() {
	//ps_out_color = ps_in.vcolor;
	//ps_out_color =  texture(g_sam_trilinear, ps_in.tex0) * ps_in.vcolor;
	
	vec3 tex_color = texture(g_sam_trilinear, ps_in.tex0).rgb;
	vec3 diffuse = ps_in.vcolor.rgb * tex_color;
	ps_out_color = vec4(diffuse, ps_in.vcolor.a);
}


