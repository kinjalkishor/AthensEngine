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

#include "t2_rs_irenderer.h"

//-----------------------------
inline D3DMATRIX* pD3DMATRIX_from_mat4(gm::mat4& ma) { return rcast<D3DMATRIX*>(ma.data()); }


inline void d3d9_create_input_element_desc(sdf::span<rs_input_element_desc> iedesc, sdr::vector<D3DVERTEXELEMENT9>& input_elems) {
	constexpr int size_float = 4;
	BYTE vd_usage = 0;
	BYTE vd_type = 0;
	uint curr_aligned_byte_offset = 0;
	uint next_aligned_byte_offset = 0;
	for_range (i, 0, iedesc.size()) {
		if (sdf::strfz_equals(iedesc[i].semantic_name, "POSITION")) {
			vd_usage = D3DDECLUSAGE_POSITION;
		} else if (sdf::strfz_equals(iedesc[i].semantic_name, "COLOR")) {
			vd_usage = D3DDECLUSAGE_COLOR;
		} else if (sdf::strfz_equals(iedesc[i].semantic_name, "TEXCOORD")) {
			vd_usage = D3DDECLUSAGE_TEXCOORD;
		} else if (sdf::strfz_equals(iedesc[i].semantic_name, "NORMAL")) {
			vd_usage = D3DDECLUSAGE_NORMAL;
		} else if (sdf::strfz_equals(iedesc[i].semantic_name, "TANGENT")) {
			vd_usage = D3DDECLUSAGE_TANGENT;
		} else if (sdf::strfz_equals(iedesc[i].semantic_name, "BINORMAL")) {
			vd_usage = D3DDECLUSAGE_BINORMAL;
		}
		else {
			eprintfln("Wrong Semantic Name: %s", iedesc[i].semantic_name);
		}


		switch(iedesc[i].format) {
			case rs_rdfmt_e::R32G32B32A32_FLOAT: vd_type = D3DDECLTYPE_FLOAT4; next_aligned_byte_offset += 4*size_float; break;
			case rs_rdfmt_e::R32G32B32_FLOAT: vd_type = D3DDECLTYPE_FLOAT3; next_aligned_byte_offset += 3*size_float; break;
			case rs_rdfmt_e::R32G32_FLOAT: vd_type = D3DDECLTYPE_FLOAT2; next_aligned_byte_offset += 2*size_float; break;
			default: vd_type = D3DDECLTYPE_UNUSED; break;
		}
		input_elems.push_back({0, scast<WORD>(curr_aligned_byte_offset), vd_type, D3DDECLMETHOD_DEFAULT, vd_usage, 0});
		curr_aligned_byte_offset = next_aligned_byte_offset;
	}

	input_elems.push_back(D3DDECL_END());
}

//-----------------------------
inline void D3DXFONT_DESC_from_logfont(const LOGFONTW& lf, D3DXFONT_DESCW& d3dx_font_desc) {		
	d3dx_font_desc.Height = lf.lfHeight;
	d3dx_font_desc.Width = lf.lfWidth;
	d3dx_font_desc.Weight = lf.lfWeight;
	d3dx_font_desc.MipLevels = 0; //1
	d3dx_font_desc.Italic = lf.lfItalic;
	d3dx_font_desc.CharSet = lf.lfCharSet;
	d3dx_font_desc.OutputPrecision = lf.lfOutPrecision;
	d3dx_font_desc.Quality = lf.lfQuality;
	d3dx_font_desc.PitchAndFamily = lf.lfPitchAndFamily;
	wcsncpy(d3dx_font_desc.FaceName, lf.lfFaceName, LF_FACESIZE-1);
}
//------------------------
using d3d9_input_layout = rs_com_raii<IDirect3DVertexDeclaration9>;
using d3d9_texture = rs_com_raii<IDirect3DTexture9>;
using d3d9_shader = rs_com_raii<ID3DXEffect>;
using d3d9_font = rs_com_raii<ID3DXFont>;
using d3dx9_mesh = rs_com_raii<ID3DXMesh>;