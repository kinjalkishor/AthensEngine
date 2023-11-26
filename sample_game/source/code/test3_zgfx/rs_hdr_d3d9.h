#pragma once

//-----------------------------
// path realtive to project file
#if defined(_MSC_VER)	
	// Used by d3d header
	//#pragma comment(lib, "oleaut32.lib")
	//#pragma comment(lib, "onecore.lib")

	//libcmt.lib conflicts with use of other libs warning
	#pragma comment(linker, "/NODEFAULTLIB:libcmt.lib")

	// DirectInput
	//#pragma comment(lib, "dinput8.lib")
	//#pragma comment (lib, "dxguid.lib")
#endif

// DXSDK_Jun10
#include <d3d9.h>
#pragma comment(lib,"DXSDK_Jun10/Lib/x64/d3d9.lib")

#include "DXSDK_Jun10/Include/d3dx9.h"
//#include "DXSDK_Jun10/Include/D3dx9shape.h"
#pragma comment(lib,"DXSDK_Jun10/Lib/x64/d3dx9.lib")

//#include "DXSDK_Jun10/Include/DxErr.h"
//#pragma comment(lib, "legacy_stdio_definitions.lib")
//#pragma comment(lib,"E:/osl/DXSDK_Jun10/Lib/x64/DxErr.lib")

//-----------------------------
#include "base_shared.h"

inline D3DMATRIX* pD3DMATRIX_from_mat4(gm::mat4& ma) { return rcast<D3DMATRIX*>(ma.data()); }
//-----------------------------

inline void create_font(IDirect3DDevice9* m_device, ID3DXFont*& m_font) {
	D3DXFONT_DESC fontDesc = {};
	fontDesc.Height          = 25;
	fontDesc.Width           = 12;
	fontDesc.Weight          = FW_BOLD;
	fontDesc.MipLevels       = 1;	//0; D3DX_DEFAULT;
	fontDesc.Italic          = false;
	fontDesc.CharSet         = DEFAULT_CHARSET;
	fontDesc.OutputPrecision = OUT_DEFAULT_PRECIS;
	fontDesc.Quality         = DEFAULT_QUALITY;
	fontDesc.PitchAndFamily  = DEFAULT_PITCH | FF_DONTCARE;
	wcscpy(fontDesc.FaceName, L"Times New Roman");

	D3DXCreateFontIndirectW(m_device, &fontDesc, &m_font);
}

inline void draw_font(IDirect3DDevice9* m_device, ID3DXFont* m_font, const char* text) {
	wchar_t wstr_text[256] = {};
	sdf::strf_assign_mbs(wstr_text, sdf::strz_cap(wstr_text), text, sdf::strfz_len(text));
	//RECT formatRect = {};
	//GetClientRect(m_render_window, &formatRect);

	// If we specify DT_NOCLIP, so we do not care about width/height of the rect.
	RECT formatRect = {0, 0, 0, 0};
	// Count: size of string or -1 indicates null terminating string. 
	// pRect: rectangle text is to be formatted to in windows coords
	//m_font->DrawTextW(nullptr, wstr_text, -1, &formatRect, DT_CENTER | DT_VCENTER, D3DCOLOR_COLORVALUE(1.0, 0.0, 0.0, 1.0));
	m_font->DrawTextW(nullptr, wstr_text, -1, &formatRect, DT_NOCLIP, gm::argb_from_color4(gm::color4(1.0, 0.0, 0.0, 1.0)));	
	//m_font->DrawTextW(nullptr, wstr_text, sdf::strfz_len(wstr_text), &formatRect, DT_TOP | DT_LEFT, gm::argb_from_color4(gm::color4(1.0, 0.0, 0.0, 1.0)));
}	


inline void create_vertex_buffer(IDirect3DDevice9* m_device, UINT vb_size_bytes, const void* sys_mem_data, IDirect3DVertexBuffer9*& vb) {
	//UINT vb_size_bytes = vertices_vec.size() * sizeof(vertex_type);
	m_device->CreateVertexBuffer(vb_size_bytes, D3DUSAGE_WRITEONLY, 0, D3DPOOL_MANAGED, &vb, nullptr);	
	// Fill the buffers with the vertices data.
	//vertex_pc* vertices = nullptr;		
	void* vertices = nullptr;		
	vb->Lock(0, 0, (void**)&vertices, 0);
	//sdf::mem_copy(vertices, vertices_vec.data(), vertices_vec.size());
	memcpy(vertices, sys_mem_data, vb_size_bytes);
	vb->Unlock();		
}

inline void create_index_buffer(IDirect3DDevice9* m_device, UINT ib_size_bytes, const void* sys_mem_data, IDirect3DIndexBuffer9*& ib) {
	//UINT ib_size_bytes = indices_vec.size() * sizeof(index_type_uint);
	m_device->CreateIndexBuffer(ib_size_bytes, D3DUSAGE_WRITEONLY, D3DFMT_INDEX32, D3DPOOL_MANAGED, &ib, nullptr);  
	// Fill the buffers with the indices data.
	//uint* indices = nullptr;
	void* indices = nullptr;
	ib->Lock(0, 0, (void**)&indices, 0);
	//sdf::mem_copy(indices, indices_vec.data(), indices_vec.size());
	memcpy(indices, sys_mem_data, ib_size_bytes);
	ib->Unlock();  		
}	

inline void create_texture(IDirect3DDevice9* m_device, const char* tex_file_name, IDirect3DTexture9*& tex) {
	wchar_t tex_file_namew[256] = {};
	sdf::strf_assign_mbs(tex_file_namew, sdf::strz_cap(tex_file_namew), tex_file_name, sdf::strfz_len(tex_file_name));
	HRESULT hr = D3DXCreateTextureFromFileW(m_device, tex_file_namew, &tex);
	if (FAILED(hr)) { eprintfln("D3DXCreateTextureFromFileW: Cannot Load File: %s", tex_file_name); }		
}

