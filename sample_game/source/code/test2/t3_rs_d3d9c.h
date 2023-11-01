#pragma once

#include "base_gmath.h"

#include "t3_rs_irenderer.h"

#include "t2_rs_d3d9_hdr.h"

#include "base_win_util.h"

#include <vector>
#include "base_std_cont.h"

#include "t2_rs_load_geometry.h"


//#include <string>
//#include <sstream>

inline D3DMATRIX* pD3DMATRIX_from_mat4(gm::mat4& ma) { return rcast<D3DMATRIX*>(ma.data()); }


inline void create_input_element_desc(sdf::span<rs_input_element_desc> iedesc, sdr::vector<D3DVERTEXELEMENT9>& input_elems) {
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

inline void load_shaders_file(IDirect3DDevice9* m_device, const char* shader_filename, ID3DXEffect*& shader_fx) {
	if (!(is_file_exists(shader_filename))) {
		eprintfln("Cannot find shader file: %s", shader_filename);
		return;
	}

	sdf::wstring_st<MAX_STR_PATH_OS> shader_file_namew;
	sdf::string_st_wcs_from_mbs(shader_file_namew, shader_filename, sdf::strfz_len(shader_filename));

	// Create the FX from a .fx file.
	DWORD shaderFlags = 0;
#if defined(DEBUG) || defined(_DEBUG)
	shaderFlags |= D3DXSHADER_DEBUG;
	shaderFlags |= D3DXSHADER_SKIPOPTIMIZATION;
#endif
	ID3DXBuffer* compilation_errors = 0;
	HRESULT hr = S_OK;
	hr = D3DXCreateEffectFromFileW(m_device, shader_file_namew.c_str(), nullptr, nullptr, shaderFlags, nullptr, &shader_fx, &compilation_errors);
	if (FAILED(hr)) {
		if (compilation_errors) {
			eprintfln("Shader File compile error: %s", shader_filename);
			//MessageBoxA(0, (char*)compilation_errors->GetBufferPointer(), 0, 0);
			//MessageBoxA(0, rcast<const char*>(compilation_errors->GetBufferPointer()), 0, 0);
			sdf::wstring_st<1024> wmsg;
			sdf::string_st_wcs_from_mbs(wmsg, 
				rcast<const char*>(compilation_errors->GetBufferPointer()), sdf::strfz_len(rcast<const char*>(compilation_errors->GetBufferPointer())));
			if (!wmsg.empty()) { fm_msg_box_ok_w(wmsg.c_str()); }
			//eprintfln("%s", rcast<const char*>(compilation_errors->GetBufferPointer()));
			compilation_errors->Release();
		}
	} 
}

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

inline void create_texture(IDirect3DDevice9* m_device, const char* tex_file_name, IDirect3DTexture9*& tex) {
	sdf::wstring_st<MAX_STR_PATH_OS> tex_file_namew;
	sdf::string_st_wcs_from_mbs(tex_file_namew, tex_file_name, sdf::strfz_len(tex_file_name));
	HRESULT hr = D3DXCreateTextureFromFileW(m_device, tex_file_namew.c_str(), &tex);
	if (FAILED(hr)) { eprintfln("D3DXCreateTextureFromFileW: Cannot Load File: %s", tex_file_name); }		
}

inline void create_vertex_buffer(IDirect3DDevice9* m_device, UINT vb_size_bytes, const void* vb_data, IDirect3DVertexBuffer9*& vb) {
	//UINT vb_size_bytes = vertices_vec.size() * sizeof(vertex_pc);		
	m_device->CreateVertexBuffer(vb_size_bytes, D3DUSAGE_WRITEONLY, 0, D3DPOOL_MANAGED, &vb, nullptr);	
	// Fill the buffers with the vertices data.
	void* vertices = nullptr;		
	vb->Lock(0, 0, (void**)&vertices, 0);
	memcpy(vertices, vb_data, vb_size_bytes);
	vb->Unlock();		
}

// can be set for 16 bit indices by type_parameter taking D3DFMT_INDEX16
inline void create_index_buffer(IDirect3DDevice9* m_device, UINT ib_size_bytes, const void* ib_data, IDirect3DIndexBuffer9*& ib) {
	//UINT ib_size_bytes = indices_vec.size() * sizeof(uint);
	m_device->CreateIndexBuffer(ib_size_bytes, D3DUSAGE_WRITEONLY, D3DFMT_INDEX32, D3DPOOL_MANAGED, &ib, nullptr);  
	// Fill the buffers with the indices data.
	void* indices = nullptr;
	ib->Lock(0, 0, (void**)&indices, 0);
	memcpy(indices, ib_data, ib_size_bytes);
	ib->Unlock();  		
}	

inline void draw_indexed(IDirect3DDevice9* m_device, isz num_vertices, isz num_indices) {
	// num_triangles should be stored separately with model for performance.
	// Calculated here for simplicity as other graphics API do not use num_indices.
	int num_triangles = num_indices/3;
	m_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, num_vertices, 0, num_triangles);
}

inline void set_texture(ID3DXEffect* shader_fx, const D3DXHANDLE& htex, IDirect3DTexture9* tex) {
	shader_fx->SetTexture(htex, tex); 
}

using d3d9_input_layout = rs_com_raii<IDirect3DVertexDeclaration9>;
using d3d9_texture = rs_com_raii<IDirect3DTexture9>;
using d3d9_shader = rs_com_raii<ID3DXEffect>;
using d3d9_font = rs_com_raii<ID3DXFont>;
using d3dx9_mesh = rs_com_raii<ID3DXMesh>;



//-----------------

class rd3d9c : public irenderer {
public:
	IDirect3DDevice9* m_device = nullptr; 

	//IDirect3D9* m_d3d9_obj;
	D3DPRESENT_PARAMETERS m_d3dpp = {};
	//d3d9_texture m_default_tex;
	//D3DMATERIAL9 m_default_mtrl;
	d3d9_font m_font;
	//---------------------	

	void deinit_r() {
		com_release(m_device);
	}

	bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) {	
		if (!hwnd) { eprintfln("Window Handle passed is null."); }		
		sys_win_title_append(hwnd, " : Direct3D9c");
		m_aspect_ratio = sdf::get_aspect_ratio(width, height);
		//set_viewport(0.0f, 0.0f, width, height);
		//m_render_window = hwnd;
		//m_width = width;
		//m_height = height;

		//------------
		// Create the IDirect3D9 object.		
		IDirect3D9* m_d3d9_obj = Direct3DCreate9(D3D_SDK_VERSION);
		if (!m_d3d9_obj) {
			eprintfln("Direct3DCreate9 Failed. Cannot Create D3D9 Object.");
			return false;
		}
		
		// Check for hardware vp.
		D3DDEVTYPE  device_type = D3DDEVTYPE_HAL;
		// Verify hardware support for specified formats in windowed and full screen modes.	
		D3DDISPLAYMODE mode = {};

		D3DFORMAT AdapterFormat = D3DFMT_A8R8G8B8;	//D3DFMT_X8R8G8B8;
		D3DFORMAT BackBufferFormat = D3DFMT_A8R8G8B8; //D3DFMT_X8R8G8B8;
		D3DFORMAT AutoDepthStencilFormat = D3DFMT_D24S8;

		m_d3d9_obj->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &mode);
		m_d3d9_obj->CheckDeviceType(D3DADAPTER_DEFAULT, device_type, mode.Format, mode.Format, true);
		m_d3d9_obj->CheckDeviceType(D3DADAPTER_DEFAULT, device_type, AdapterFormat, BackBufferFormat, false);

		// Check for requested vertex processing and pure device.
		D3DCAPS9 caps = {};
		m_d3d9_obj->GetDeviceCaps(D3DADAPTER_DEFAULT, device_type, &caps);	
		//DWORD mRequestedVP;
		//mRequestedVP = D3DCREATE_HARDWARE_VERTEXPROCESSING;
		DWORD devBehaviorFlags = 0;
		// HW T&L supported.
		if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) {
			//devBehaviorFlags |= mRequestedVP;
			devBehaviorFlags = D3DCREATE_HARDWARE_VERTEXPROCESSING;
		} else {
			eprintfln("Cannot Create D3D9 Hardware vertex Processing.");
			return false;
			//devBehaviorFlags = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
		}		

		// A pure device does not save the current state (during state changes), which often improves performance; this device also requires hardware vertex processing.
		// One drawback of a pure device is that it does not support all Get* API calls; this means you can not use a pure device to query the pipeline state. 
		// This makes it more difficult to debug while running an application.
		// If pure device and HW T&L supported
		//if (caps.DevCaps & D3DDEVCAPS_PUREDEVICE &&
		//	devBehaviorFlags & D3DCREATE_HARDWARE_VERTEXPROCESSING) {
		//		devBehaviorFlags |= D3DCREATE_PUREDEVICE;
		//}


		D3DMULTISAMPLE_TYPE multi_sample_type = D3DMULTISAMPLE_NONE;
		DWORD num_quality_levels = 0;
		D3DFORMAT SurfaceFormat = D3DFMT_R8G8B8;
		// Check for Full-scene antialiasing
		if (SUCCEEDED(m_d3d9_obj->CheckDeviceMultiSampleType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
				SurfaceFormat, !(fullscreen), D3DMULTISAMPLE_4_SAMPLES, &num_quality_levels))) {
			multi_sample_type = D3DMULTISAMPLE_4_SAMPLES;			
		} else {
			multi_sample_type = D3DMULTISAMPLE_NONE;
			num_quality_levels = 0;
		}

		// Fill out the D3DPRESENT_PARAMETERS structure. 
		//D3DPRESENT_PARAMETERS m_d3dpp = {};
		m_d3dpp.BackBufferWidth            = width;
		m_d3dpp.BackBufferHeight           = height;
		m_d3dpp.BackBufferFormat           = BackBufferFormat; //D3DFMT_UNKNOWN
		m_d3dpp.BackBufferCount            = 1;
		m_d3dpp.MultiSampleType            = multi_sample_type; //D3DMULTISAMPLE_NONE;
		m_d3dpp.MultiSampleQuality         = num_quality_levels; //0;
		m_d3dpp.SwapEffect                 = D3DSWAPEFFECT_DISCARD; 
		m_d3dpp.hDeviceWindow              = hwnd;
		m_d3dpp.Windowed                   = !(fullscreen);
		m_d3dpp.EnableAutoDepthStencil     = true; 
		m_d3dpp.AutoDepthStencilFormat     = AutoDepthStencilFormat; //D3DFMT_D24S8;
		m_d3dpp.Flags                      = 0;
		m_d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT; //60;
		m_d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;


		HRESULT hr = S_OK;
		// Create the device.		
		hr = m_d3d9_obj->CreateDevice(
			D3DADAPTER_DEFAULT,		// primary adapter
			device_type,			// device type
			hwnd,					// window associated with device
			devBehaviorFlags,       // vertex processing
			&m_d3dpp,				// present parameters
			&m_device);				// return created device

		if (FAILED(hr)) {			
			com_release(m_d3d9_obj);
			eprintfln("Cannot Create D3D9 device.");
			return false;
		}		

		// done with d3d9 object
		com_release(m_d3d9_obj); 
	

			//set_rs_anitialiasing();
			//resize(width, height);
			//init_fonts();

			//init_default_texture();
			//init_default_material();

		return true;
	}	

	
	// Default setup, cleanup, render func.
	void setup() {}
	void cleanup() {}	

	void render(float dt) {		
		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

		m_device->BeginScene();
		// Render here
		m_device->EndScene();
	}

	void swap_buffers() {
		// Swap the back and front buffers.
		m_device->Present(nullptr, nullptr, nullptr, nullptr);
	}

	//-----------------------------------------------------------
	void clear_render_target(const gm::color4& color_rgba) {
		m_device->Clear(0, nullptr, D3DCLEAR_TARGET, gm::argb_from_color4(color_rgba), 1.0f, 0);
	}
	void clear_depth_stencil(bool clear_depth, bool clear_stencil, float depth, uint stencil) {
		uint clear_flag = 0;
		if (clear_depth) { clear_flag |= D3DCLEAR_ZBUFFER; }
		if (clear_stencil) { clear_flag |= D3DCLEAR_STENCIL; }    
		m_device->Clear(0, nullptr, clear_flag, 0x00FFFFFF, depth, stencil);
	}
	void clear_screen_buffers() {
		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);
	}

	//-----------------------------------------------------------
	

	//-----------------------------------------------------------
	void set_rs_culling(rs_cull_mode_e cullmode_back_face) {
		//m_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		// Default cull mode is D3DCULL_CCW for D3D9, culling refering to back face culling.
		// A front face is one in which vertices are defined in clockwise order. Back faces having CCW are culled.
		// In OpenGL CCW is frontface by default. Use glFrontFace(GL_CW) to specify CCW as backface like D3D9. 
		//m_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); 
		////m_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW); 
		switch (cullmode_back_face) {
			case rs_cull_mode_e::cull_none: m_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); break;
			case rs_cull_mode_e::cull_cw: m_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW); break;
			case rs_cull_mode_e::cull_ccw: m_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); break;
			default: m_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); break;
		}
	}	

	void set_rs_fillmode(rs_fill_mode_e fill_mode) {
		switch (fill_mode) {
			case rs_fill_mode_e::fill_solid: m_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID); break;
			case rs_fill_mode_e::fill_wireframe: m_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME); break;
			//case rs_fill_mode_e::fill_point: m_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_POINT); break;
			default: m_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID); break;
		}	
	}


	//---------------------------------------------------------
	

	

	//void set_texture_null(ID3DXEffect* shader_fx, const D3DXHANDLE& htex) {
	//	shader_fx->SetTexture(htex, nullptr); 
	//}

	//void init_default_texture() {
	//	create_texture(m_default_texture_file, m_default_tex.data);
	//}

	//-----------------------------------------------
	void create_input_layout(sdf::span<rs_input_element_desc> iedesc, IDirect3DVertexDeclaration9*& input_layout) {
		sdr::vector<D3DVERTEXELEMENT9> input_elements;
		create_input_element_desc(iedesc, input_elements);
		m_device->CreateVertexDeclaration(input_elements.data(), &input_layout);	
	}



	//-----------------------------------------------------------	
	void init_fonts() {
		LOGFONTW lf = {};
		create_log_font(lf);
		D3DXFONT_DESCW d3dx_font_desc = {};
		D3DXFONT_DESC_from_logfont(lf, d3dx_font_desc);
		// Create an ID3DXFont based on logfont.
		D3DXCreateFontIndirectW(m_device, &d3dx_font_desc, &m_font.data);	
	}
	
	void draw_font(const char* text, const gm::color4& color_rgba) {
		sdf::wstring_st<255> wtext;
		sdf::string_st_wcs_from_mbs(wtext, text, sdf::strfz_len(text));
		int fw = 640;
		int fh = 360;

		//RECT formatRect;
		//GetClientRect(mhMainWnd, &formatRect);
		//mFont->DrawTextW(0, L"Hello Direct3D", -1, &formatRect, DT_CENTER | DT_VCENTER, D3DCOLOR_XRGB(255, 0, 0));

		// Display font
		// We specify DT_NOCLIP, so we do not care about width/height of the rect.
		RECT rect = {0, 0, fw, fh};
		// Count: size of string or -1 indicates null terminating string. 
		// pRect: rectangle text is to be formatted to in windows coords
		m_font.data->DrawTextW(nullptr, wtext.c_str(), wtext.size(), &rect, DT_TOP | DT_LEFT, gm::argb_from_color4(color_rgba));	
		//m_font.data->DrawTextW(nullptr, wtext.c_str(), -1, &rect, DT_CENTER | DT_VCENTER, D3DCOLOR_XRGB(255, 0, 0));
		//m_font.data->DrawTextW(nullptr, wtext.c_str(), -1, &rect, DT_NOCLIP, D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));	
	}


	//enable fullscreen
#if 0
	void D3DApp::enableFullScreenMode(bool enable)
	{
		// Switch to fullscreen mode.
		if( enable )
		{
			// Are we already in fullscreen mode?
			if( !md3dPP.Windowed ) 
				return;

			int width  = GetSystemMetrics(SM_CXSCREEN);
			int height = GetSystemMetrics(SM_CYSCREEN);

			md3dPP.BackBufferFormat = D3DFMT_X8R8G8B8;
			md3dPP.BackBufferWidth  = width;
			md3dPP.BackBufferHeight = height;
			md3dPP.Windowed         = false;

			// Change the window style to a more fullscreen friendly style.
			SetWindowLongPtr(mhMainWnd, GWL_STYLE, WS_POPUP);

			// If we call SetWindowLongPtr, MSDN states that we need to call
			// SetWindowPos for the change to take effect.  In addition, we 
			// need to call this function anyway to update the window dimensions.
			SetWindowPos(mhMainWnd, HWND_TOP, 0, 0, width, height, SWP_NOZORDER | SWP_SHOWWINDOW);	
		}
		// Switch to windowed mode.
		else
		{
			// Are we already in windowed mode?
			if( md3dPP.Windowed ) 
				return;

			RECT R = {0, 0, 800, 600};
			AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW, false);
			md3dPP.BackBufferFormat = D3DFMT_UNKNOWN;
			md3dPP.BackBufferWidth  = 800;
			md3dPP.BackBufferHeight = 600;
			md3dPP.Windowed         = true;
	
			// Change the window style to a more windowed friendly style.
			SetWindowLongPtr(mhMainWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);

			// If we call SetWindowLongPtr, MSDN states that we need to call
			// SetWindowPos for the change to take effect.  In addition, we 
			// need to call this function anyway to update the window dimensions.
			SetWindowPos(mhMainWnd, HWND_TOP, 100, 100, R.right, R.bottom, SWP_NOZORDER | SWP_SHOWWINDOW);
		}

		// Reset the device with the changes.
		onLostDevice();
		HR(gd3dDevice->Reset(&md3dPP));
		onResetDevice();
	}

	bool D3DApp::isDeviceLost()
{
	// Get the state of the graphics device.
	HRESULT hr = gd3dDevice->TestCooperativeLevel();

	// If the device is lost and cannot be reset yet then
	// sleep for a bit and we'll try again on the next 
	// message loop cycle.
	if( hr == D3DERR_DEVICELOST )
	{
		Sleep(20);
		return true;
	}
	// Driver error, exit.
	else if( hr == D3DERR_DRIVERINTERNALERROR )
	{
		MessageBox(0, "Internal Driver Error...Exiting", 0, 0);
		PostQuitMessage(0);
		return true;
	}
	// The device is lost but we can reset and restore it.
	else if( hr == D3DERR_DEVICENOTRESET )
	{
		onLostDevice();
		HR(gd3dDevice->Reset(&md3dPP));
		onResetDevice();
		return false;
	}
	else
		return false;
}
#endif
};


class rd3d9c_tri_color : public rd3d9c  {
public:	
	IDirect3DVertexDeclaration9* m_input_layout = nullptr;

	IDirect3DVertexBuffer9* triangle_m_vb = nullptr;
	IDirect3DIndexBuffer9* triangle_m_ib = nullptr;		
	int64 tri_num_vertices = 0;
	int64 tri_num_indices = 0;

	gm::mat4 mat_world_tri = gm::mat4::k_identity();

	//---
	d3d9_shader shader_fx;
	D3DXHANDLE htech = nullptr;			
	D3DXHANDLE hmat_wvp = nullptr;


	void setup() {	
		set_rs_culling(rs_cull_mode_e::cull_ccw);

		// Load shaders before CreateVertexDeclaration or CreateInputLayout
		load_shaders_file(m_device, RS_SHADER_PATH("d3d9_vertex_pc.fx"), shader_fx.data);
		// Obtain handles.
		htech = shader_fx.data->GetTechniqueByName("shader_tech");
		hmat_wvp = shader_fx.data->GetParameterByName(0, "g_mat_wvp");

		// Create vertex declaration for expressing the data layout. Conceptually, the vertex declaration is a way of 
		// programming the vertex direct memory access (DMA) and the tessellator engine of the graphics pipe.
		D3DVERTEXELEMENT9 vertex_elements_pc[] =  {
			{0, 0,  D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0},
			{0, 12, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_COLOR, 0},
			D3DDECL_END()
		};	
		m_device->CreateVertexDeclaration(vertex_elements_pc, &m_input_layout);	


		// Define data to load. Can be loaded from file also.
		vertex_pc triangle_arr_vert_c_d3d[] = {
			{-1.0, 0.0, 0.9,	1.0, 0.0, 0.0, 1.0}, // bottom-left red
			{ 0.0, 1.0, 0.9,	0.0, 1.0, 0.0, 1.0}, // top green
			{ 1.0, 0.0, 0.9,	0.0, 0.0, 1.0, 1.0}, // bottom-right blue
		};
		uint triangle_arr_ind_d3d[] = {
			0, 1, 2,
		};
		tri_num_vertices = sdf::arr_cap(triangle_arr_vert_c_d3d);
		tri_num_indices = sdf::arr_cap(triangle_arr_ind_d3d);		

		// Load data to vector.
		sdr::vector<vertex_pc> vertices_vec;
		sdr::vector<uint> indices_vec;
		vertices_vec.resize(tri_num_vertices);
		sdf::mem_copy(vertices_vec.data(), triangle_arr_vert_c_d3d, tri_num_vertices);
		indices_vec.resize(tri_num_indices);
		sdf::mem_copy(indices_vec.data(), triangle_arr_ind_d3d, tri_num_indices);


		// Create the vertex buffer. 
		UINT vb_size_bytes = vertices_vec.size() * sizeof(vertex_pc);		
		m_device->CreateVertexBuffer(vb_size_bytes, D3DUSAGE_WRITEONLY, 0, D3DPOOL_MANAGED, &triangle_m_vb, nullptr);	
		// Fill the buffers with the vertices data.
		vertex_pc* vertices = nullptr;		
		triangle_m_vb->Lock(0, 0, (void**)&vertices, 0);
		sdf::mem_copy(vertices, vertices_vec.data(), vertices_vec.size());
		triangle_m_vb->Unlock();		

		// Enable if using index buffers.
		// Create the index buffer. 
		UINT ib_size_bytes = indices_vec.size() * sizeof(uint);
		m_device->CreateIndexBuffer(ib_size_bytes, D3DUSAGE_WRITEONLY, D3DFMT_INDEX32, D3DPOOL_MANAGED, &triangle_m_ib, nullptr);  
		// Fill the buffers with the indices data.
		uint* indices = nullptr;
		triangle_m_ib->Lock(0, 0, (void**)&indices, 0);
		sdf::mem_copy(indices, indices_vec.data(), indices_vec.size());
		triangle_m_ib->Unlock();  		


		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);
		//----------------------------------------

		// World Matrix
		mat_world_tri = gm::mat4_translation(gm::vec3(1.25f, 0.0f, 0.0f));
		//mat_world_tri = gm::mat4_scaling(gm::vec3(2.0, 1.0, 1.0));
		// Rotating on x axis, since x axis is same while y or z can be up.
		//mat_world_tri = gm::mat4_rotation_x(mf::deg_to_rad<float>(30));

		// View Matrix
		// Position and aim the camera.
		gm::vec3 position(0.0f, 0.0f, -2.0f);
		gm::vec3 target(0.0f, 0.0f, 0.0f);
		gm::vec3 up(0.0f, 1.0f, 0.0f);
		mat_view = gm::mat4_look_at_lh(position, target, up);

		// Projection Matrix
		mat_proj = gm::mat4_perspective_fov_lh(
								mf::deg_to_rad<float>(100), //yfov
								1.777777,	//(16/9) //(float)800 / (float)600,
								0.9f,		//1.0f,
								1000.0f);
	}

	void render(float dt) {
		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

		gm::mat4 mat_wvp_temp = mat_world_tri * mat_view * mat_proj;
		D3DXMATRIX d3d_mat_wvp = *pD3DMATRIX_from_mat4(mat_wvp_temp);

		m_device->BeginScene();		

		m_device->SetVertexDeclaration(m_input_layout);	

		// Set vertex buffer
		m_device->SetStreamSource(0, triangle_m_vb, 0, sizeof(vertex_pc));

		// Enable if using index buffers.
		// Set index buffer
		m_device->SetIndices(triangle_m_ib);	

		// Setup the rendering FX
		shader_fx.data->SetTechnique(htech);
		// Begin passes.
		UINT numPasses = 0;
		shader_fx.data->Begin(&numPasses, 0);
		for(UINT i = 0; i < numPasses; ++i) {
			shader_fx.data->BeginPass(i);

			shader_fx.data->SetMatrix(hmat_wvp, &(d3d_mat_wvp));
			shader_fx.data->CommitChanges();

			int num_triangles = tri_num_indices/3;
			////m_device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, num_triangles); //vertex buffer only
			// Enable if using index buffers.		
			m_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, tri_num_vertices, 0, num_triangles);

			shader_fx.data->EndPass();
		}
		shader_fx.data->End();		

		m_device->EndScene();
	}

	void cleanup() {
		com_release(triangle_m_vb);
		com_release(triangle_m_ib);
		com_release(m_input_layout);	
	}
};


class d3d9c_model {
public:		
	IDirect3DVertexBuffer9* m_vb = nullptr;
	IDirect3DIndexBuffer9* m_ib = nullptr;		
	isz num_vertices = 0;
	isz num_indices = 0;

	uint m_vstride = 0;
	IDirect3DVertexDeclaration9* m_input_layout = nullptr;

	gm::mat4 mat_world = gm::mat4::k_identity();

	IDirect3DTexture9* m_tex = nullptr;	
	//D3DXHANDLE m_htex = nullptr;		

	~d3d9c_model() {
		com_release(m_vb);
		com_release(m_ib);
	}
};
template <class T>
inline void model_load(IDirect3DDevice9* m_device, d3d9c_model& model, sdr::vector<T> vertices_vec, 
	sdr::vector<uint> indices_vec, const d3d9_input_layout& input_layout, const d3d9_texture& tex) {

	model.num_vertices = vertices_vec.size();
	model.num_indices = indices_vec.size();	
	model.m_vstride = sizeof(T);
	model.m_input_layout = input_layout.data;

	model.m_tex = tex.data;	

	create_vertex_buffer(m_device, vec_size_bytes(vertices_vec), vertices_vec.data(), model.m_vb);
	create_index_buffer(m_device, vec_size_bytes(indices_vec), indices_vec.data(), model.m_ib);
}

inline void model_draw_set_buffers(IDirect3DDevice9* m_device, const d3d9c_model& model) {
	// Set vertex buffer
	m_device->SetStreamSource(0, model.m_vb, 0, model.m_vstride);
	// Enable if using index buffers.
	// Set index buffer
	m_device->SetIndices(model.m_ib);	
}
inline void model_draw_set_texture(const d3d9c_model& model, const d3d9_shader& shader_fx, const D3DXHANDLE& htex) {
	set_texture(shader_fx.data, htex, model.m_tex);
}
inline void model_draw(IDirect3DDevice9* m_device, const d3d9c_model& model) {	
	draw_indexed(m_device, model.num_vertices, model.num_indices);
}

class rd3d9c_tri_color_tex : public rd3d9c  {
public:	
	d3d9_input_layout m_input_layout;

	d3d9c_model model0;

	//---
	d3d9_shader shader_fx;
	D3DXHANDLE htech = nullptr;			
	D3DXHANDLE hmat_wvp = nullptr;

	d3d9_texture tex0;
	D3DXHANDLE htex = nullptr;


	void setup() {	
		set_rs_culling(rs_cull_mode_e::cull_ccw);

		// Load shaders before CreateVertexDeclaration or CreateInputLayout
		load_shaders_file(m_device, RS_SHADER_PATH("d3d9_vertex_pct.fx"), shader_fx.data);
		// Obtain handles.
		htech = shader_fx.data->GetTechniqueByName("shader_tech");
		hmat_wvp = shader_fx.data->GetParameterByName(0, "g_mat_wvp");
		htex = shader_fx.data->GetParameterByName(0, "g_tex");

		rs_input_element_desc vfmt_pc[3] = {
			{"POSITION",	rs_rdfmt_e::R32G32B32_FLOAT},
			{"COLOR",		rs_rdfmt_e::R32G32B32A32_FLOAT},
			{"TEXCOORD",	rs_rdfmt_e::R32G32_FLOAT},			
		};

		sdr::vector<D3DVERTEXELEMENT9> input_elements;
		create_input_element_desc(sdf::make_span(vfmt_pc, sdf::arr_cap(vfmt_pc)), input_elements);
		m_device->CreateVertexDeclaration(input_elements.data(), &m_input_layout.data);	

		create_texture(m_device, RS_MEDIA_PATH("tut/glitter/dog.jpg"), tex0.data);
		//create_texture(m_device, RS_MEDIA_PATH("nw_tex/checker_white.png"), tex0.data);

		// Load data to vector.
		sdr::vector<vertex_pct> vertices_vec;
		sdr::vector<uint> indices_vec;
		fill_triangle_vertex_pct(vertices_vec, indices_vec);	

		model0.num_vertices = vertices_vec.size();
		model0.num_indices = indices_vec.size();	
		model0.m_vstride = sizeof(vertex_pct);
		model0.m_input_layout = m_input_layout.data;
		// not using model.m_tex
		//model0.m_tex = tex0.data;

		create_vertex_buffer(m_device, vec_size_bytes(vertices_vec), vertices_vec.data(), model0.m_vb);
		create_index_buffer(m_device, vec_size_bytes(indices_vec), indices_vec.data(), model0.m_ib);	

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);
		//----------------------------------------

		// World Matrix
		model0.mat_world = gm::mat4_translation(gm::vec3(1.25f, 0.0f, 0.0f));
		//mat_world_tri = gm::mat4_scaling(gm::vec3(2.0, 1.0, 1.0));
		// Rotating on x axis, since x axis is same while y or z can be up.
		//mat_world_tri = gm::mat4_rotation_x(mf::deg_to_rad<float>(30));

		mat_view = set_view_matrix(gm::vec3(0.0f, 0.0f, -2.0f), gm::vec3(0.0f, 0.0f, 0.0f), gm::vec3(0.0f, 1.0f, 0.0f));
		mat_proj = set_projection_matrix();
	}

	

	void render(float dt) {
		clear_screen_buffers();

		gm::mat4 mat_wvp_temp = model0.mat_world * mat_view * mat_proj;
		D3DXMATRIX d3d_mat_wvp = *pD3DMATRIX_from_mat4(mat_wvp_temp);

		m_device->BeginScene();		

		m_device->SetVertexDeclaration(model0.m_input_layout);	
		// Set vertex buffer
		m_device->SetStreamSource(0, model0.m_vb, 0, model0.m_vstride);
		// Enable if using index buffers.
		// Set index buffer
		m_device->SetIndices(model0.m_ib);	

		// Setup the rendering FX
		shader_fx.data->SetTechnique(htech);
		// Begin passes.
		UINT numPasses = 0;
		shader_fx.data->Begin(&numPasses, 0);
		for(UINT i = 0; i < numPasses; ++i) {
			shader_fx.data->BeginPass(i);

			shader_fx.data->SetMatrix(hmat_wvp, &(d3d_mat_wvp));
			shader_fx.data->CommitChanges();

			set_texture(shader_fx.data, htex, tex0.data);
			//set_texture(shader_fx.data, htex, model0.m_tex);

			draw_indexed(m_device, model0.num_vertices, model0.num_indices);

			shader_fx.data->EndPass();
		}
		shader_fx.data->End();				

		m_device->EndScene();
	}	
};

//---

#if 1

class rd3d9c_tri_color_cube : public rd3d9c  {
public:	
	d3d9_input_layout m_input_layout;

	d3d9c_model model0;

	//---
	d3d9_shader shader_fx;
	D3DXHANDLE htech = nullptr;			
	D3DXHANDLE hmat_wvp = nullptr;

	d3d9_texture tex0;
	D3DXHANDLE htex = nullptr;

	

	void setup() {	
		set_rs_culling(rs_cull_mode_e::cull_ccw);
		init_fonts();

		// Load shaders before CreateVertexDeclaration or CreateInputLayout
		load_shaders_file(m_device, RS_SHADER_PATH("d3d9_vertex_ptn.fx"), shader_fx.data);
		// Obtain handles.
		htech = shader_fx.data->GetTechniqueByName("shader_tech");
		hmat_wvp = shader_fx.data->GetParameterByName(0, "g_mat_wvp");
		htex = shader_fx.data->GetParameterByName(0, "g_tex");

		rs_input_element_desc vfmt_pc[3] = {
			{"POSITION",	rs_rdfmt_e::R32G32B32_FLOAT},
			{"TEXCOORD",	rs_rdfmt_e::R32G32_FLOAT},
			{"NORMAL",		rs_rdfmt_e::R32G32B32_FLOAT},	
		};
		create_input_layout(sdf::make_span(vfmt_pc, sdf::arr_cap(vfmt_pc)), m_input_layout.data);
		

		//create_texture(m_device, RS_MEDIA_PATH("tut/d3d_fl/tex/crate1.jpg"), tex0.data);
		create_texture(m_device, RS_MEDIA_PATH("tut/glitter/dog.jpg"), tex0.data);
		//create_texture(m_device, RS_MEDIA_PATH("nw_tex/checker_white.png"), tex0.data);

		// Load data to vector.
		sdr::vector<vertex_ptn> vertices_vec;
		sdr::vector<uint> indices_vec;
		fill_cube_vertex_ptn(vertices_vec, indices_vec);	

		model_load(m_device, model0, vertices_vec, indices_vec, m_input_layout, tex0);

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);
		//----------------------------------------

		// World Matrix
		model0.mat_world = gm::mat4_translation(gm::vec3(1.25f, 0.0f, 0.0f));
		//mat_world_tri = gm::mat4_scaling(gm::vec3(2.0, 1.0, 1.0));
		// Rotating on x axis, since x axis is same while y or z can be up.
		//mat_world_tri = gm::mat4_rotation_x(mf::deg_to_rad<float>(30));

		m_camera.set_position(gm::vec3(0.0f, 2.0f, -8.0f));
		mat_proj = set_projection_matrix();
	}

	

	void render(float dt) {
		update_camera(dt);
		mat_view = m_camera.get_view_matrix();

		clear_screen_buffers();

		gm::mat4 mat_wvp_temp = model0.mat_world * mat_view * mat_proj;
		D3DXMATRIX d3d_mat_wvp = *pD3DMATRIX_from_mat4(mat_wvp_temp);

		m_device->BeginScene();		

		// Sort models by input_layout, don't change input_layout & shader on every call.
		m_device->SetVertexDeclaration(model0.m_input_layout);	

		model_draw_set_buffers(m_device, model0);

		// Setup the rendering FX
		shader_fx.data->SetTechnique(htech);
		// Begin passes.
		UINT numPasses = 0;
		shader_fx.data->Begin(&numPasses, 0);
		for(UINT i = 0; i < numPasses; ++i) {
			shader_fx.data->BeginPass(i);

			shader_fx.data->SetMatrix(hmat_wvp, &(d3d_mat_wvp));
			shader_fx.data->CommitChanges();		

			model_draw_set_texture(model0, shader_fx, htex);
			model_draw(m_device, model0);

			shader_fx.data->EndPass();
		}
		shader_fx.data->End();		

		draw_font("Hello World", gm::color4(0.0f, 1.0f, 0.0f, 1.0f));

		m_device->EndScene();
	}	
};

#endif