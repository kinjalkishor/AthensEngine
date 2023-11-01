
// Constant Buffer Variables
cbuffer constant_buffer : register(b0)
{
	matrix wvp;
}

//--------------------------------------------------------------------------------------
struct VS_OUTPUT
{
    float4 pos : SV_POSITION;
};

//------------------
// Vertex Shader
//------------------
VS_OUTPUT VS(float4 pos : POSITION)
{
    VS_OUTPUT output = (VS_OUTPUT)0;
    output.pos = mul(pos, wvp);
    return output;
}

//------------------
// Pixel Shader
//------------------
float4 PS(VS_OUTPUT input) : SV_Target
{
	return float4(1.0f, 1.0f, 1.0f, 1.0f);
}
