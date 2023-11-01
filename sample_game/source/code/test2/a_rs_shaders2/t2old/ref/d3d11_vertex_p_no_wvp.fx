
//------------------
// Vertex Shader
//------------------
float4 VS(float4 pos : POSITION) : SV_POSITION
{
    return pos;
}


//------------------
// Pixel Shader
//------------------
float4 PS(float4 pos : SV_POSITION) : SV_Target
{
	return float4(1.0f, 1.0f, 1.0f, 1.0f);    //white, with Alpha = 1
}
