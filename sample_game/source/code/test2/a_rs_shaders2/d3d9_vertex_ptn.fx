
uniform extern float4x4 g_mat_wvp;

uniform extern texture g_tex;
sampler texs = sampler_state {
	Texture = <g_tex>;
	MinFilter = Anisotropic;
	MagFilter = Anisotropic;
	MipFilter = Anisotropic;
	MaxAnisotropy = 8;
	AddressU  = WRAP;
    AddressV  = WRAP;
};


struct VS_INPUT {
	float4 pos_l : POSITION0; 
	float2 tex0 : TEXCOORD0;
	float3 norm_l : NORMAL0;		
};


struct VS_OUTPUT {
    float4 pos_h : POSITION0;
    float4 vcolor : COLOR0;
	float2 tex0 : TEXCOORD0;
	//float3 norm_w : NORMAL0;
};


VS_OUTPUT VS(VS_INPUT vs_in) {
	// Zero out our output.
	VS_OUTPUT vs_out = (VS_OUTPUT)0;
	
	// Transform to homogeneous clip space.
	vs_out.pos_h = mul(vs_in.pos_l, g_mat_wvp);
	
	//vs_out.norm_w = vs_in.norm_l;
	
	// Just pass the vertex color into the pixel shader.
	//vs_out.vcolor = vs_in.vcolor;
	vs_out.vcolor = float4(1.0, 1.0, 1.0, 1.0);
	
	// Pass on texture coordinates to be interpolated in rasterization.
	vs_out.tex0 = vs_in.tex0;
	 
    return vs_out;
}


float4 PS(VS_OUTPUT ps_in) : COLOR {
    //return ps_in.vcolor;
	
	float3 tex_color = tex2D(texs, ps_in.tex0).rgb;
	float3 diffuse = ps_in.vcolor.rgb * tex_color;
    return float4(diffuse, ps_in.vcolor.a); 
}

technique shader_tech {
    pass P0 {
        // Specify the vertex and pixel shader associated with this pass.
        vertexShader = compile vs_2_0 VS();
        pixelShader  = compile ps_2_0 PS();
    }
}
