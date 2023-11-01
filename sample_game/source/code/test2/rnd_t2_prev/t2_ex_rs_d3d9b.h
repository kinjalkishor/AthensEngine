#pragma once

#include "t2_rs_d3d9bc_hdr.h"

#include "../base_gmath_colors.h"

//------------------------
class rs_material {
public:
	gm::color4		diffuse;        // Diffuse color RGBA
    gm::color4		ambient;        // Ambient color RGB
    gm::color4		specular;       // Specular shininess
    gm::color4		emissive;       // Emissive color RGB
    float			power;          // Sharpness if specular highlight

	rs_material() 
		: diffuse(gm::color4::k_zero()), ambient(gm::color4::k_zero()), 
		  specular(gm::color4::k_zero()), emissive(gm::color4::k_zero()), power(0.0f) {}
	~rs_material() {}
	rs_material(const gm::color4& a, const gm::color4& d, const gm::color4& s, const gm::color4& e, float p)
		: diffuse(d), ambient(a), specular(s), emissive(e), power(p) {}   
};

//inline const rs_material k_rs_material_white = rs_material_from_color4(gm::cc::white);

inline rs_material rs_material_from_color4(gm::color4 ca) {
	return rs_material(ca, ca, ca, gm::cc::black, 2.0f);
}

//-------------------------------
class rs_light_directional {
public:
	gm::color4 ambient = gm::cc::white;
	gm::color4 diffuse = gm::cc::white;
	gm::color4 specular = gm::cc::white;
	gm::vec3 direction = gm::vec3(1.0f, -1.0f, 0.0f);;
	float pad = 0.0f;

	rs_light_directional() {}
	~rs_light_directional() {}

	rs_light_directional(const gm::color4& a, const gm::color4& d, const gm::color4& s, const gm::vec3& dir) 
		: ambient(a), diffuse(d), specular(s), direction(dir)
	{}

	rs_light_directional(const gm::color4& color_a, const gm::vec3& direction_a) {
		ambient   = color_a * 0.4f;
		diffuse   = color_a;
		specular  = color_a * 0.6f;
		direction = direction_a;		
	}
};

class rs_light_point {
public:
	gm::color4 ambient = gm::cc::white;
	gm::color4 diffuse = gm::cc::white;
	gm::color4 specular = gm::cc::white;
	gm::vec3 position = gm::vec3(0.0f, 0.0f, -2.0f);
	float range = 1000.0f;
	gm::vec3 attenuation = gm::vec3(1.0f, 0.0f, 0.0f);
	float falloff = 1.0f;

	rs_light_point() {}
	~rs_light_point() {}

	rs_light_point(const gm::color4& color_a, const gm::vec3& position_a) {
		ambient   = color_a * 0.4f;
		diffuse   = color_a;
		specular  = color_a * 0.6f;
		position  = position_a;
		range        = 1000.0f;
		falloff      = 1.0f;
		attenuation[0] = 1.0f;
		attenuation[1] = 0.0f;
		attenuation[2] = 0.0f;
	}
};

class rs_light_spot {
public:
	gm::color4 ambient = gm::cc::white;
	gm::color4 diffuse = gm::cc::white;       
    gm::color4 specular = gm::cc::white;       
    gm::vec3 direction = gm::vec3(1.0f, -1.0f, 0.0f);;
	float pad = 0.0f;
    gm::vec3 position = gm::vec3(0.0f, 0.0f, -2.0f);
    float range = 1000.0f;
	gm::vec3 attenuation = gm::vec3(1.0f, 0.0f, 0.0f);
	float falloff = 1.0f;
    float theta = 0.5f;           
    float phi = 0.7f;       
	gm::vec2 pad2 = gm::vec2::k_zero();

	rs_light_spot() {}
	~rs_light_spot() {}

	rs_light_spot(const gm::color4& color_a, const gm::vec3& direction_a, const gm::vec3& position_a) {
		ambient   = color_a * 0.4f;
		diffuse   = color_a;
		specular  = color_a * 0.6f;
		position  = position_a;
		direction = direction_a;
		range        = 1000.0f;
		falloff      = 1.0f;
		attenuation[0] = 1.0f;
		attenuation[1] = 0.0f;
		attenuation[2] = 0.0f;
		theta        = 0.5f;
		phi          = 0.7f;
	}
};

//==============================================================================
//------------------------
inline D3DXVECTOR3 D3DXVECTOR3_from_vec3(const gm::vec3& a) {
	return D3DXVECTOR3(a.x, a.y, a.z);
}

inline D3DCOLORVALUE D3DCOLORVALUE_from_color4(const gm::color4& ca) {
	return D3DCOLORVALUE(ca.r, ca.g, ca.b, ca.a);
}
inline D3DMATERIAL9 D3DMATERIAL9_from_rs_material(const rs_material& m) {
	return D3DMATERIAL9(D3DCOLORVALUE_from_color4(m.diffuse), D3DCOLORVALUE_from_color4(m.ambient), 
		D3DCOLORVALUE_from_color4(m.specular), D3DCOLORVALUE_from_color4(m.emissive), m.power);
}

//--------------------------
inline D3DLIGHT9 D3DLIGHT9_from_rs_light_directional(const rs_light_directional& lt) {
	D3DLIGHT9 temp = {};
	temp.Type = D3DLIGHT_DIRECTIONAL;
	temp.Ambient   = D3DCOLORVALUE_from_color4(lt.ambient);
	temp.Diffuse   = D3DCOLORVALUE_from_color4(lt.diffuse);
	temp.Specular  = D3DCOLORVALUE_from_color4(lt.specular);
	temp.Direction = D3DXVECTOR3_from_vec3(lt.direction);		
	return temp;
}

inline D3DLIGHT9 D3DLIGHT9_from_rs_light_point(const rs_light_point& lt) {
	D3DLIGHT9 temp = {};
	temp.Type      = D3DLIGHT_POINT;
	temp.Ambient   = D3DCOLORVALUE_from_color4(lt.ambient);
	temp.Diffuse   = D3DCOLORVALUE_from_color4(lt.diffuse);
	temp.Specular  = D3DCOLORVALUE_from_color4(lt.specular);
	temp.Position  = D3DXVECTOR3_from_vec3(lt.position);		
	temp.Range        = lt.range;
	temp.Falloff      = lt.falloff;
	temp.Attenuation0 = lt.attenuation[0];
	temp.Attenuation1 = lt.attenuation[1];
	temp.Attenuation2 = lt.attenuation[2];
	return temp;
}

inline D3DLIGHT9 D3DLIGHT9_from_rs_light_spot(const rs_light_spot& lt) {
	D3DLIGHT9 temp = {};
	temp.Type      = D3DLIGHT_SPOT;
	temp.Ambient   = D3DCOLORVALUE_from_color4(lt.ambient);
	temp.Diffuse   = D3DCOLORVALUE_from_color4(lt.diffuse);
	temp.Specular  = D3DCOLORVALUE_from_color4(lt.specular);
	temp.Position  = D3DXVECTOR3_from_vec3(lt.position);
	temp.Direction = D3DXVECTOR3_from_vec3(lt.direction);	
	temp.Range        = lt.range;
	temp.Falloff      = lt.falloff;
	temp.Attenuation0 = lt.attenuation[0];
	temp.Attenuation1 = lt.attenuation[1];
	temp.Attenuation2 = lt.attenuation[2];
	temp.Theta        = lt.theta;
	temp.Phi          = lt.phi;
	return temp;
}
//--------------------------




//------------------------


struct d3d9b_tex_filtering {
	rs_texture_filter_e filtering_mode = rs_texture_filter_e::texf_bilinear;
	uint tex_wrapping = 0;
	uint min_filter = 0;
	uint mag_filter = 0;
	uint mip_filter = 0;
	//bool enable_anisotropic_filtering = false;
	uint anisotropic_quality = 8;
};

inline d3d9b_tex_filtering create_d3d9b_tex_filtering(rs_texture_filter_e filtering_mode) {
	d3d9b_tex_filtering tex_filtering;
	tex_filtering.filtering_mode = filtering_mode;
	switch (tex_filtering.filtering_mode) {
		case rs_texture_filter_e::texf_point: 
			tex_filtering.min_filter = D3DTEXF_POINT; tex_filtering.mag_filter = D3DTEXF_POINT; tex_filtering.mip_filter = D3DTEXF_POINT;
			break;
		case rs_texture_filter_e::texf_bilinear:
			tex_filtering.min_filter = D3DTEXF_LINEAR; tex_filtering.mag_filter = D3DTEXF_LINEAR; tex_filtering.mip_filter = D3DTEXF_LINEAR;
			break;
		case rs_texture_filter_e::texf_trilinear:
			tex_filtering.min_filter = D3DTEXF_LINEAR; tex_filtering.mag_filter = D3DTEXF_LINEAR; tex_filtering.mip_filter = D3DTEXF_LINEAR;
			break;
		case rs_texture_filter_e::texf_anisotropic:
			tex_filtering.min_filter = D3DTEXF_ANISOTROPIC; tex_filtering.mag_filter = D3DTEXF_ANISOTROPIC; tex_filtering.mip_filter = D3DTEXF_ANISOTROPIC;				
			break;
	}		
	return tex_filtering;
}

class d3d9b_model {
public:		
	IDirect3DVertexBuffer9* m_vb = nullptr;
	IDirect3DIndexBuffer9* m_ib = nullptr;		
	isz num_vertices = 0;
	isz num_indices = 0;

	IDirect3DVertexDeclaration9* m_input_layout = nullptr;
	IDirect3DTexture9* m_tex = nullptr;	
	uint vstride = 0;

	D3DMATERIAL9* m_mtrl = nullptr;

	~d3d9b_model() {
		com_release(m_vb);
		com_release(m_ib);
	}
};
//-------------------------

class rd3d9b : public irenderer {
public:

	IDirect3DDevice9* m_device = nullptr; 

	//IDirect3D9* m_d3d9_obj;
	D3DPRESENT_PARAMETERS m_d3dpp = {};

	d3d9_texture m_default_tex;
	D3DMATERIAL9 m_default_mtrl;

	d3d9_font m_font;
	

	//---------------------
	void deinit_r() {
		com_release(m_device);
	}

	bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) {	
		//set_viewport(0.0f, 0.0f, width, height);
		if (!hwnd) { eprintfln("Window Handle passed is null."); }
		//m_render_window = hwnd;
		sys_win_title_append(hwnd, " : Direct3D9b");
		m_aspect_ratio = sdf::get_aspect_ratio(width, height);

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
		m_d3dpp.AutoDepthStencilFormat     = AutoDepthStencilFormat;
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
		init_fonts();

		init_default_texture();
		init_default_material();

		return true;
	}

	// Default setup, cleanup, render func.
	void setup() {}
	void cleanup() {}	

	void render(float dt) {		
		clear(gm::color4(0.2, 0.2, 0.2, 1.0));

		m_device->BeginScene();
		// Render here
		m_device->EndScene();
	}

	void swap_buffers() {
		// Swap the back and front buffers.
		m_device->Present(nullptr, nullptr, nullptr, nullptr);
	}

	void clear_render_target(const gm::color4& color_rgba) {
		m_device->Clear(0, nullptr, D3DCLEAR_TARGET, gm::argb_from_color4(color_rgba), 1.0f, 0);
	}
	void clear_depth_stencil(bool clear_depth, bool clear_stencil, float depth, uint stencil) {
		uint clear_flag = 0;
		if (clear_depth) { clear_flag |= D3DCLEAR_ZBUFFER; }
		if (clear_stencil) { clear_flag |= D3DCLEAR_STENCIL; }    
		m_device->Clear(0, nullptr, clear_flag, 0x00FFFFFF, depth, stencil);
	}

	void clear(const gm::color4& color_rgba) {
		clear_render_target(gm::color4(0.0, 1.0, 0.0, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);
	}

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

	void set_rs_lighting(bool enable) { m_device->SetRenderState(D3DRS_LIGHTING, enable); }

	void set_rs_anitialiasing() { m_device->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, msaa_enabled); }

	//----------------
	void set_rs_fillmode(rs_fill_mode_e fill_mode) {
		switch (fill_mode) {
			case rs_fill_mode_e::fill_solid: m_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID); break;
			case rs_fill_mode_e::fill_wireframe: m_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME); break;
			//case rs_fill_mode_e::fill_point: m_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_POINT); break;
			default: m_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID); break;
		}	
	}
	void set_rs_shade_mode(int mode) {
		// Set before DrawPrimitive()
		switch (mode) {
			case D3DSHADE_FLAT: m_device->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_FLAT); break;
			case D3DSHADE_GOURAUD: m_device->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD); break;
			// Not supported.
			//case D3DSHADE_PHONG: m_device->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_PHONG); break;			
			default: m_device->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD); break;
		}
	}

	//---------------------------------------------------------
	void create_texture(const char* tex_file_name, IDirect3DTexture9*& tex) {
		sdf::wstring_st<MAX_STR_PATH_OS> tex_file_namew;
		sdf::string_st_wcs_from_mbs(tex_file_namew, tex_file_name, sdf::strfz_len(tex_file_name));
		HRESULT hr = D3DXCreateTextureFromFileW(m_device, tex_file_namew.c_str(), &tex);
		if (FAILED(hr)) { eprintfln("D3DXCreateTextureFromFileW: Cannot Load File: %s", tex_file_name); }		
	}

	void set_texture(IDirect3DTexture9* tex, const uint tex_stage) {
		m_device->SetTexture(tex_stage, tex);
	}
	void set_texture_null(const uint tex_stage) {
		m_device->SetTexture(tex_stage, nullptr);
	}

	void init_default_texture() {
		create_texture(m_default_texture_file, m_default_tex.data);
	}

	void init_default_material() {
		m_default_mtrl = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::white));
	}

	void set_light_render_state() {
		// Set lighting related render states.
		m_device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
		m_device->SetRenderState(D3DRS_SPECULARENABLE, true);
	}

	//-----------------------------------------------
	void create_vertex_buffer(UINT vb_size_bytes, const void* sys_mem_data, IDirect3DVertexBuffer9*& vb) {
		//UINT vb_size_bytes = vertices_vec.size() * sizeof(vertex_pc);		
		m_device->CreateVertexBuffer(vb_size_bytes, D3DUSAGE_WRITEONLY, 0, D3DPOOL_MANAGED, &vb, nullptr);	
		// Fill the buffers with the vertices data.
		vertex_pc* vertices = nullptr;		
		vb->Lock(0, 0, (void**)&vertices, 0);
		memcpy(vertices, sys_mem_data, vb_size_bytes);
		vb->Unlock();		
	}

	void create_index_buffer(UINT ib_size_bytes, const void* sys_mem_data, IDirect3DIndexBuffer9*& ib) {
		//UINT ib_size_bytes = indices_vec.size() * sizeof(uint);
		m_device->CreateIndexBuffer(ib_size_bytes, D3DUSAGE_WRITEONLY, D3DFMT_INDEX32, D3DPOOL_MANAGED, &ib, nullptr);  
		// Fill the buffers with the indices data.
		uint* indices = nullptr;
		ib->Lock(0, 0, (void**)&indices, 0);
		memcpy(indices, sys_mem_data, ib_size_bytes);
		ib->Unlock();  		
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
	
	void draw_font(const char* text) {
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
		m_font.data->DrawTextW(nullptr, wtext.c_str(), wtext.size(), &rect, DT_TOP | DT_LEFT, gm::argb_from_color4(m_font_color));	
		//m_font.data->DrawTextW(nullptr, wtext.c_str(), -1, &rect, DT_CENTER | DT_VCENTER, D3DCOLOR_XRGB(255, 0, 0));
		//m_font.data->DrawTextW(nullptr, wtext.c_str(), -1, &rect, DT_NOCLIP, D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));	
	}
	
	//----------------------------
	void set_sampler_state(rs_texture_filter_e filtering_mode, uint sampler) {
		d3d9b_tex_filtering tex_filtering = create_d3d9b_tex_filtering(filtering_mode);

		// Same filtering for all textures.
		if (tex_filtering.filtering_mode == rs_texture_filter_e::texf_anisotropic) {
			m_device->SetSamplerState(sampler, D3DSAMP_MAXANISOTROPY, tex_filtering.anisotropic_quality);
		}
		// Set Texture Filter States.
		m_device->SetSamplerState(sampler, D3DSAMP_MAGFILTER, tex_filtering.mag_filter);
		m_device->SetSamplerState(sampler, D3DSAMP_MINFILTER, tex_filtering.min_filter);
		m_device->SetSamplerState(sampler, D3DSAMP_MIPFILTER, tex_filtering.mip_filter);
	}
	//------------------------



	void create_model(d3d9b_model& model, const void* vertices_data, isz vertices_size, uint vertices_stride, 
		const void* indices_data, isz indices_size, uint indices_stride, IDirect3DVertexDeclaration9* input_layout, 
		IDirect3DTexture9* tex, D3DMATERIAL9* mtrl) {

		//model0.num_vertices = vertices_vec.size();
		//model0.num_indices = indices_vec.size();
		//model0.vstride = sizeof(vertex_ptn);		
		//model0.m_input_layout = m_input_layout.data;
		//create_vertex_buffer(vec_size_bytes(vertices_vec), vertices_vec.data(), model0.m_vb);
		//create_index_buffer(vec_size_bytes(indices_vec), indices_vec.data(), model0.m_ib);		
		//model0.m_tex = tex0.data;
		////model0.m_tex = m_default_tex.data;		
		//model0.m_mtrl = &mtrl0;

		model.num_vertices = vertices_size;
		model.num_indices = indices_size;
		model.vstride = vertices_stride;
		model.m_input_layout = input_layout;
		
		create_vertex_buffer(vertices_size*vertices_stride, vertices_data, model.m_vb);
		create_index_buffer(indices_size*indices_stride, indices_data, model.m_ib);		
		if (tex != nullptr) {
			model.m_tex = tex;
		} else {
			model.m_tex = m_default_tex.data;
		}

		if (mtrl != nullptr) {
			model.m_mtrl = mtrl;
		} else {
			model.m_mtrl = &m_default_mtrl;
		}
	}

	//create_model(model0, rmodel0.vertices_vec.data(), rmodel0.vertices_vec.size(), rmodel0.vstride(), 
	//	rmodel0.indices_vec.data(), rmodel0.indices_vec.size(), rmodel0.istride(), m_input_layout.data, tex0.data, &mtrl0);	
	template<class T>
	void create_model_rsmodel(d3d9b_model& model, rs_model<T> rmodel, IDirect3DVertexDeclaration9* input_layout, 
		IDirect3DTexture9* tex, D3DMATERIAL9* mtrl) {
		create_model(model, rmodel.vertices_vec.data(), rmodel.vertices_vec.size(), rmodel.vstride(), 
				rmodel.indices_vec.data(), rmodel.indices_vec.size(), rmodel.istride(), input_layout, tex, mtrl);	
	}

	void create_model_basic(d3d9b_model& model, const void* vertices_data, isz vertices_size, uint vertices_stride, 
		const void* indices_data, isz indices_size, uint indices_stride, IDirect3DVertexDeclaration9* input_layout, 
		IDirect3DTexture9* tex) {
		create_model(model, vertices_data, vertices_size, vertices_stride, indices_data, indices_size, indices_stride,
			input_layout, tex, nullptr);
	}

	void draw_model(const d3d9b_model& model) {
		set_texture(model.m_tex, 0);			
		m_device->SetMaterial(model.m_mtrl);

		m_device->SetVertexDeclaration(model.m_input_layout);

		// Set vertex buffer
		m_device->SetStreamSource(0, model.m_vb, 0, model.vstride);

		// Set index buffer
		m_device->SetIndices(model.m_ib);

		int num_triangles = model.num_indices/3;
		m_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, model.num_vertices, 0, num_triangles);
	}
};



class rd3d9b_tri_color : public rd3d9b  {
public:	
	IDirect3DVertexDeclaration9* m_input_layout = nullptr;

	IDirect3DVertexBuffer9* triangle_m_vb = nullptr;
	IDirect3DIndexBuffer9* triangle_m_ib = nullptr;		
	int64 tri_num_vertices = 0;
	int64 tri_num_indices = 0;

	gm::mat4 mat_world_tri = gm::mat4::k_identity();

	void setup() {	
		// Set Render Pipeline state.
		//m_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); // default in d3d
		//m_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW); // default in OpenGL
		//m_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

		set_rs_culling(rs_cull_mode_e::cull_ccw);
		set_rs_lighting(false);

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
		m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(mat_world_tri));

		// View Matrix
		// Position and aim the camera.
		gm::vec3 position(0.0f, 0.0f, -2.0f);
		gm::vec3 target(0.0f, 0.0f, 0.0f);
		gm::vec3 up(0.0f, 1.0f, 0.0f);
		mat_view = gm::mat4_look_at_lh(position, target, up);
		m_device->SetTransform(D3DTS_VIEW, pD3DMATRIX_from_mat4(mat_view));

		// Projection Matrix
		mat_proj = gm::mat4_perspective_fov_lh(
								mf::deg_to_rad<float>(100), //yfov
								1.777777,	//(16/9) //(float)800 / (float)600,
								0.9f,		//1.0f,
								1000.0f);
		m_device->SetTransform(D3DTS_PROJECTION, pD3DMATRIX_from_mat4(mat_proj));
	}

	void render(float dt) {
		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

		m_device->BeginScene();		

		m_device->SetVertexDeclaration(m_input_layout);	

		// Set vertex buffer
		m_device->SetStreamSource(0, triangle_m_vb, 0, sizeof(vertex_pc));

		// Enable if using index buffers.
		// Set index buffer
		m_device->SetIndices(triangle_m_ib);

		int num_triangles = tri_num_indices/3;
		//m_device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, num_triangles); //vertex buffer only
		// Enable if using index buffers.		
		m_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, tri_num_vertices, 0, num_triangles);

		m_device->EndScene();
	}

	void cleanup() {
		com_release(triangle_m_vb);
		com_release(triangle_m_ib);
		com_release(m_input_layout);	
	}
};

class rd3d9b_tri_color_tex : public rd3d9b  {
public:	
	d3d9_input_layout m_input_layout;

	gm::mat4 model0_mat_world = gm::mat4::k_identity();
	d3d9b_model model0;
	d3d9_texture tex0;

	void setup() {	
		set_rs_culling(rs_cull_mode_e::cull_ccw);
		set_rs_lighting(false);

		rs_input_element_desc vfmt_pc[3] = {
			{"POSITION",	rs_rdfmt_e::R32G32B32_FLOAT},
			{"COLOR",		rs_rdfmt_e::R32G32B32A32_FLOAT},
			{"TEXCOORD",	rs_rdfmt_e::R32G32_FLOAT},			
		};

		sdr::vector<D3DVERTEXELEMENT9> input_elements;
		d3d9_create_input_element_desc(sdf::span(vfmt_pc, sdf::arr_cap(vfmt_pc)), input_elements);
		m_device->CreateVertexDeclaration(input_elements.data(), &m_input_layout.data);	
		

		create_texture(RS_MEDIA_PATH("tut/glitter/dog.jpg"), tex0.data);
		//create_texture(RS_MEDIA_PATH("nw_tex/checker_white.png"), tex0.data);

		set_sampler_state(rs_texture_filter_e::texf_anisotropic, 0);


		// Load data to vector.
		sdr::vector<vertex_pct> vertices_vec;
		sdr::vector<uint> indices_vec;
		fill_triangle_vertex_pct(vertices_vec, indices_vec);		

		create_model_basic(model0, vertices_vec.data(), vertices_vec.size(), sizeof(decltype(vertices_vec)::value_type), 
			indices_vec.data(), indices_vec.size(), sizeof(decltype(indices_vec)::value_type), m_input_layout.data, tex0.data);

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);			

		//----------------------------------------

		// World Matrix
		//model0.mat_world = gm::mat4_translation(gm::vec3(1.25f, 0.0f, 0.0f));
		//model0.mat_world = gm::mat4_scaling(gm::vec3(2.0, 1.0, 1.0));
		// Rotating on x axis, since x axis is same while y or z can be up.
		//model0.mat_world = gm::mat4_rotation_x(mf::deg_to_rad<float>(30));
		m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(model0_mat_world));

		m_camera.set_position(gm::vec3(0.0f, 0.0f, -3.0f));
		mat_proj = set_projection_matrix();
		m_device->SetTransform(D3DTS_PROJECTION, pD3DMATRIX_from_mat4(mat_proj));
		
	}


	void render(float dt) {
		update_camera(dt);
		mat_view = m_camera.get_view_matrix();
		m_device->SetTransform(D3DTS_VIEW, pD3DMATRIX_from_mat4(mat_view));

		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

		m_device->BeginScene();	
		
		draw_model(model0);

		draw_font("Hello World");

		m_device->EndScene();
	}

	void cleanup() {		
	}
};


class rd3d9b_cube : public rd3d9b  {
public:	
	d3d9_input_layout m_input_layout;

	gm::mat4 model0_mat_world = gm::mat4::k_identity();
	d3d9b_model model0;
	d3d9_texture tex0;
	D3DMATERIAL9 mtrl0;	

	D3DLIGHT9 light2;

	void setup() {	
		set_rs_culling(rs_cull_mode_e::cull_ccw);
		//set_rs_lighting(false);
		set_rs_lighting(true);

		rs_input_element_desc vfmt_pc[3] = {
			{"POSITION",	rs_rdfmt_e::R32G32B32_FLOAT},
			{"TEXCOORD",	rs_rdfmt_e::R32G32_FLOAT},
			{"NORMAL",		rs_rdfmt_e::R32G32B32_FLOAT},	
		};

		sdr::vector<D3DVERTEXELEMENT9> input_elements;
		d3d9_create_input_element_desc(sdf::span(vfmt_pc, sdf::arr_cap(vfmt_pc)), input_elements);
		m_device->CreateVertexDeclaration(input_elements.data(), &m_input_layout.data);	
		

		//create_texture(RS_MEDIA_PATH("tut/glitter/dog.jpg"), tex0.data);
		create_texture(RS_MEDIA_PATH("nw_tex/checker_white.png"), tex0.data);

		set_sampler_state(rs_texture_filter_e::texf_anisotropic, 0);

		mtrl0 = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::white));

		// Load data to vector.
		rs_model<vertex_ptn> rmodel0;	
		fill_cube_vertex_ptn(rmodel0.vertices_vec, rmodel0.indices_vec);

		create_model_rsmodel(model0, rmodel0, m_input_layout.data, tex0.data, &mtrl0);

		rmodel0.clear_memory();

		
		// LIGHTS
	#if 1
		// Directional light.
		gm::vec3 ddir(1.0f, -1.0f, 0.0f);
		gm::color4 dc = gm::cc::white;
		rs_light_directional dir_light(dc, ddir);

		D3DLIGHT9 light0 = D3DLIGHT9_from_rs_light_directional(dir_light);
		m_device->SetLight(0, &light0);		
		m_device->LightEnable(0, true);
	#endif

	#if 1
		// Point light. Positioned at the origin.
		gm::vec3 ppos(0.0f, 0.0f, 0.0f);
		gm::color4 pc = gm::cc::yellow;
		rs_light_point pt_light(pc, ppos);

		D3DLIGHT9 light1 = D3DLIGHT9_from_rs_light_point(pt_light);
		m_device->SetLight(1, &light1);		
		m_device->LightEnable(1, true);
	#endif

	#if 1
		// Spot light
		gm::vec3 spos(-0.8f, 0.0f, 1.0f);
		gm::vec3 sdir(0.0f, 1.0f,  0.0f);
		gm::color4 sc = gm::cc::pale_turquoise;
		rs_light_spot spot_light(sc, spos, sdir);

		// In render also if direction changed for movable light
		//m_device->LightEnable(2, true);
		light2 = D3DLIGHT9_from_rs_light_spot(spot_light);
		m_device->SetLight(2, &light2);		
		m_device->LightEnable(2, true);
	#endif

		set_light_render_state();

		//----------------------------------------

		// World Matrix
		//model0.mat_world = gm::mat4_translation(gm::vec3(1.25f, 0.0f, 0.0f));
		//model0.mat_world = gm::mat4_scaling(gm::vec3(2.0, 1.0, 1.0));
		// Rotating on x axis, since x axis is same while y or z can be up.
		//model0.mat_world = gm::mat4_rotation_x(mf::deg_to_rad<float>(30));
		m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(model0_mat_world));

		m_camera.set_position(gm::vec3(0.0f, 3.0f, -8.0f));
		mat_proj = set_projection_matrix();
		m_device->SetTransform(D3DTS_PROJECTION, pD3DMATRIX_from_mat4(mat_proj));
		
	}


	void render(float dt) {
		// Move spot light.
		//if (get_async_key_state(VK_LEFT)) { 
		//	light2.Direction.x -= 0.5f * dt; 
		//	//print("{}", light2.Direction.x); 
		//}
		//if (get_async_key_state(VK_RIGHT)) { light2.Direction.x += 0.5f * dt; }
		//if (get_async_key_state(VK_DOWN)) { light2.Direction.y -= 0.5f * dt; }
		//if (get_async_key_state(VK_UP)) { light2.Direction.y += 0.5f * dt; }
		//m_device->SetLight(2, &light2);		
		//m_device->LightEnable(2, true);
		//-----------

		update_camera(dt);
		mat_view = m_camera.get_view_matrix();
		m_device->SetTransform(D3DTS_VIEW, pD3DMATRIX_from_mat4(mat_view));

		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

		m_device->BeginScene();	
		
		draw_model(model0);

		m_device->EndScene();
	}

	void cleanup() {		
	}
};