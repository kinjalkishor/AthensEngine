#version 460 core

//in vec4 out_vcolor;
in VS_OUTPUT
{
    vec4 vcolor; //send color to next stage
} sh_in;

out vec4 out_color;

void main()
{
	//VS_OUTPUT sh_in;
	//out_color = out_vcolor;
	out_color = sh_in.vcolor;
}
