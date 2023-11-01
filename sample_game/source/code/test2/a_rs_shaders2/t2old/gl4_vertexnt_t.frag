
#version 460 core

// texture sampler
uniform sampler2D g_sam_trilinear;

in VS_OUTPUT
{
	vec2 tex0;
    vec3 norm_w; 	
} ps_in;

out vec4 ps_out_color;


void main()
{	
	vec4 tex_color = texture(g_sam_trilinear, ps_in.tex0);
	//ps_out_color = tex_color;
	vec4 diffuse = tex_color;
	ps_out_color = diffuse;
}


