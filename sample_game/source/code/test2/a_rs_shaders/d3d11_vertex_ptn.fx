
cbuffer cb_per_object : register(b0) {
	matrix g_wvp;
}


Texture2D g_tex : register(t0);


SamplerState g_sam_anisotropic : register(s0);
//SamplerState g_sam_trilinear : register(s1);



struct VS_INPUT {
    float4 pos_l : POSITION; 
	float2 tex0 : TEXCOORD0;
	float3 norm_l : NORMAL;	
};

struct VS_OUTPUT {
    float4 pos_h : SV_POSITION;
	float2 tex0 : TEXCOORD0;
	float3 norm_w : NORMAL;	
};


VS_OUTPUT VS(VS_INPUT vs_in) {
   // Zero out our output.
    VS_OUTPUT vs_out = (VS_OUTPUT)0;
	
	// Transform to homogeneous clip space.
	vs_out.pos_h = mul(vs_in.pos_l, g_wvp);
	
	vs_out.norm_w = vs_in.norm_l;
	
	// Pass on texture coordinates to be interpolated in rasterization.
	vs_out.tex0 = vs_in.tex0;
	
    return vs_out;
}

float4 PS(VS_OUTPUT ps_in) : SV_Target {
	float4 tex_color = g_tex.Sample(g_sam_anisotropic, ps_in.tex0);
	
	//return tex_color;
	float4 diffuse = tex_color;
	return diffuse;
}


