
cbuffer cb_per_object {
	matrix g_wvp;
	matrix W;
	matrix V;
	matrix P;
	int mode;
	float3 pad;
}

struct VS_INPUT {	
	float4 pos_l : POSITION;
	float4 vcolor : COLOR0; 
};

struct VS_OUTPUT {
    float4 pos_h : SV_POSITION;
	float4 vcolor : COLOR0;
};

VS_OUTPUT VS(VS_INPUT vs_in) {
	// Zero out our output.
    VS_OUTPUT vs_out = (VS_OUTPUT)0;
	
	// Transform to homogeneous clip space.	
	[flatten] 
	if (mode == 1) {
		// transposed matrices
		// wvp*vp
		// mul: row vector, row major
		vs_out.pos_h = mul(vs_in.pos_l, g_wvp);		
	} else if (mode == 2) {
		// transposed matrices
		// vp*w*v*p				
		vs_out.pos_h = mul(mul(mul(vs_in.pos_l, W), V), P);
	} else if (mode == 3) {
		// vp*wvp
		// mul: col vector, col major
		vs_out.pos_h = mul(g_wvp, vs_in.pos_l);
	} else if (mode == 4) {
		// p*v*w*vp
		vs_out.pos_h = mul(mul(mul(P, V), W), vs_in.pos_l);
	}
	
	// Pass the vertex color into the pixel shader.
	vs_out.vcolor = vs_in.vcolor;
	
    return vs_out;
}

float4 PS(VS_OUTPUT ps_in) : SV_Target {
	return ps_in.vcolor;
}
