
// Constant Buffer Variables
cbuffer constant_buffer : register(b0)
{
	matrix wvp;
}

//--------------------------------------------------------------------------------------
struct VS_OUTPUT
{
    float4 pos : SV_POSITION;
	float4 color : COLOR0;
};

//------------------
// Vertex Shader
//------------------
VS_OUTPUT VS(float4 pos : POSITION, float4 color : COLOR0)
{
    VS_OUTPUT output = (VS_OUTPUT)0;
    output.pos = mul(pos, wvp);
	output.color = color;
    return output;
}

//------------------
// Pixel Shader
//------------------
float4 PS(VS_OUTPUT input) : SV_Target
{
	return input.color;
}
