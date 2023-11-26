#pragma once


struct vertex_pc {
	float x, y, z;
	float r, g, b, a;		
};

struct vertex_pct {
	float x, y, z;
	float r, g, b, a;		
	float u, v; 
};

struct vertex_pctn {
	float x, y, z;
	float r, g, b, a;
	float u, v; 
	float nx, ny, nz;	
};

struct vertex_pctntb {
	float x, y, z;
	float r, g, b, a;
	float u, v; 
	float nx, ny, nz;	
	float tx, ty, tz;
	float bx, by, bz;
};


struct vertex_p {
	float x, y, z;
};
struct vertex_ptn {
	float x, y, z;
	float u, v; 
	float nx, ny, nz;	
};
struct vertex_ptntb {
	float x, y, z;
	float u, v; 
	float nx, ny, nz;	
	float tx, ty, tz;
	float bx, by, bz;
};

//=======================================================
/*
D3DVERTEXELEMENT9 vertex_elements_pc[] =  {
	{0, 0,  D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0},
	{0, 12, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_COLOR, 0},
	D3DDECL_END()
};	
m_device->CreateVertexDeclaration(vertex_elements_pc, &m_input_layout);	

// Create vertex declaration for expressing the data layout. Conceptually, the vertex declaration is a way of 
// programming the vertex direct memory access (DMA) and the tessellator engine of the graphics pipe.
D3DVERTEXELEMENT9 vertex_elements_pct[] =  {
	{0, 0,  D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0},
	{0, 12, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_COLOR, 0},
	{0, 28, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0},
	D3DDECL_END()
};	
m_device->CreateVertexDeclaration(vertex_elements_pct, &m_input_layout.data);	


Namely, when a mesh is created, a single buffer allocation is made, and several descriptor ranges (views) are created within it:
index buffer: Buffer<uint>, either R16_UINT or R32_UINT depending on how many vertices are in the mesh
position-normal-wind: StructuredBuffer<float4> (it was also ByteAddressBuffer for a while). 
XYZ part is storing the positions, the W component is storing packed normal (R8G8B8_SNORM manually packed/unpacked) 
and wind weights (R8_UNORM, manually packed/unpacked)
tangent: Buffer<float4>, with R8G8B8A8_SNORM format
UV sets: Buffer<float4>, with R16G16B16A16_FLOAT format (to support up to 2 UV sets)
Lightmap atlas UV: Buffer<float2>, with R16G16_FLOAT format
Color: Buffer<float4>, with R8G8B8A8_UNORM format (sidenote: weirdly SRGB cannot be used for buffers even in DX12)
Bone indices and weights: StructuredBuffer<Bone>, the Bone structure containing RGBA16_UINT indices and RGBA16_UNORM 
weights that the skinning shader will manually unpack

*/