
// Constant Buffer Variables
cbuffer constant_buffer : register(b0)
{
	matrix world;
	matrix view;
	matrix proj;
}

//--------------------------------------------------------------------------------------
// From Vertex data, D3D11_INPUT_ELEMENT_DESC layout[]
// POSITION = SV_POSITION
// COLOR(for single color only)/COLOR0(preferred) = COLOR0
struct VS_OUTPUT
{
    float4 pos : SV_POSITION;
    //float4 color : COLOR0;
};

//------------------
// Vertex Shader
//------------------
//VS_OUTPUT VS(float4 pos : POSITION, float4 color : COLOR)
//VS_OUTPUT VS(float4 pos : POSITION, float4 color : COLOR0)
VS_OUTPUT VS(float4 pos : POSITION)
{
    VS_OUTPUT output = (VS_OUTPUT)0;
    //output.pos = mul(pos, world); output.pos = mul(output.pos, view); output.pos = mul(output.pos, proj);
	output.pos = mul(mul(mul(pos, world), view), proj);

	// matrix wvp = world * view * proj; output.pos = mul(pos, wvp); // wrong * does per-component hadamard product

    //output.color = color;
    return output;
}


//------------------
// Pixel Shader
//------------------
float4 PS(VS_OUTPUT input) : SV_Target
{
	return float4(1.0f, 1.0f, 1.0f, 1.0f);
    //return input.color;
}
