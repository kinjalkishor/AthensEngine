
cbuffer cb_per_object {
	float4x4 g_wvp; 
};

struct VS_INPUT {	
	float4 pos_l : POSITION;
	float4 vcolor : COLOR; 
};

struct VS_OUTPUT {	
	float4 pos_h : SV_POSITION;
	float4 vcolor : COLOR;
};

VS_OUTPUT VS(VS_INPUT vs_in) {
	// Zero out our output.
	VS_OUTPUT vs_out = (VS_OUTPUT)0;

	// Transform to homogeneous clip space.
	vs_out.pos_h = mul(vs_in.pos_l, g_wvp);
	
	// Pass the vertex color into the pixel shader.
	vs_out.vcolor = vs_in.vcolor;
	 
    return vs_out;
}

float4 PS(VS_OUTPUT ps_in) : SV_Target {
    return ps_in.vcolor;
}

technique10 shader_tech {
    pass P0 {
        SetVertexShader(CompileShader(vs_4_0, VS()));
        SetGeometryShader(NULL );
        SetPixelShader(CompileShader(ps_4_0, PS()));
    }
}
