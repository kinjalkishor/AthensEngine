
cbuffer cb_per_object
{
	matrix g_wvp;
}

struct VS_INPUT
{	
	float4 pos_l : POSITION;
	float4 vcolor : COLOR0; 
};

struct VS_OUTPUT
{
    float4 pos_h : SV_POSITION;
	float4 vcolor : COLOR0;
};

VS_OUTPUT VS(VS_INPUT vs_in)
{
	// Zero out our output.
    VS_OUTPUT vs_out = (VS_OUTPUT)0;
	
	// Transform to homogeneous clip space.
	vs_out.pos_h = mul(vs_in.pos_l, g_wvp);
	
	// Pass the vertex color into the pixel shader.
	vs_out.vcolor = vs_in.vcolor;
	
    return vs_out;
}

float4 PS(VS_OUTPUT ps_in) : SV_Target
{
	return ps_in.vcolor;
}
