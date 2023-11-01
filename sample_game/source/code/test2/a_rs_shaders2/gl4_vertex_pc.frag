#version 460 core

in VS_OUTPUT
{
    vec4 vcolor;
} ps_in;

out vec4 ps_out_color;

void main()
{
	ps_out_color = ps_in.vcolor;
}
