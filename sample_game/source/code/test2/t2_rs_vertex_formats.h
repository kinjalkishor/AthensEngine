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
*/