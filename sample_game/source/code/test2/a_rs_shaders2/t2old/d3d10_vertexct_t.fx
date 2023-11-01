
cbuffer cb_per_object
{
	float4x4 g_wvp; 
};


Texture2D g_tex;
SamplerState g_sam_trilinear
{
	Filter = MIN_MAG_MIP_LINEAR;
	AddressU = WRAP;
	AddressV = WRAP;
};
SamplerState g_sam_anisotropic
{
	Filter = ANISOTROPIC;
	MaxAnisotropy = 8;
	AddressU = WRAP;
	AddressV = WRAP;
};


struct VS_INPUT
{
	float4 pos_l : POSITION;
	float4 vcolor : COLOR; 
	float2 tex0 : TEXCOORD;
};

struct VS_OUTPUT
{
    float4 pos_h : SV_POSITION;
	float4 vcolor : COLOR;
	float2 tex0 : TEXCOORD;
};


VS_OUTPUT VS(VS_INPUT vs_in)
{
	// Zero out our output.
	VS_OUTPUT vs_out = (VS_OUTPUT)0;

	// Transform to homogeneous clip space.
	vs_out.pos_h = mul(vs_in.pos_l, g_wvp);
	
	// Pass the vertex color into the pixel shader.
	vs_out.vcolor = vs_in.vcolor;
	
	// Pass on texture coordinates to be interpolated in rasterization.
	vs_out.tex0 = vs_in.tex0;
	
    return vs_out;
}

float4 PS(VS_OUTPUT ps_in) : SV_Target
{
	//return ps_in.vcolor;
	//return g_tex.Sample(g_sam_trilinear, ps_in.tex0) * ps_in.vcolor;
	
	float3 tex_color = g_tex.Sample(g_sam_anisotropic, ps_in.tex0).rgb;
	float3 diffuse = ps_in.vcolor.rgb * tex_color;
	return float4(diffuse, ps_in.vcolor.a);
	
	
}

technique10 shader_tech
{
    pass P0
    {
        SetVertexShader(CompileShader(vs_4_0, VS()));
        SetGeometryShader(NULL );
        SetPixelShader(CompileShader(ps_4_0, PS()));
    }
}

