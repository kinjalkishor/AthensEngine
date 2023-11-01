#pragma once

//-----------------------------
// DXSDK_Jun10
#include <d3d10.h>
#include "DXSDK_Jun10/Include/d3dx10.h"
//#include "DXSDK_Jun10/Include/DxErr.h"

#pragma comment(lib,"DXSDK_Jun10/Lib/x64/d3d10.lib")
#pragma comment(lib,"DXSDK_Jun10/Lib/x64/d3dx10.lib")
//#pragma comment(lib, "legacy_stdio_definitions.lib")
//#pragma comment(lib,"DXSDK_Jun10/Lib/x64/DxErr.lib")
//-----------------------------


#include "t2_rs_irenderer.h"

#define HR

inline void D3DX10_FONT_DESC_from_logfont(const LOGFONTW& lf, D3DX10_FONT_DESCW& d3dx_font_desc) {		
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

inline void d3d10_create_input_element_desc(sdf::span<rs_input_element_desc> iedesc, sdr::vector<D3D10_INPUT_ELEMENT_DESC>& input_elems) {
	constexpr int size_float = 4;
	DXGI_FORMAT vformat = DXGI_FORMAT_UNKNOWN;
	uint curr_aligned_byte_offset = 0;
	uint next_aligned_byte_offset = 0;

	for_range (i, 0, iedesc.size()) {
		switch(iedesc[i].format) {
			case rs_rdfmt_e::R32G32B32A32_FLOAT: vformat = DXGI_FORMAT_R32G32B32A32_FLOAT; next_aligned_byte_offset += 4*size_float; break;
			case rs_rdfmt_e::R32G32B32_FLOAT: vformat = DXGI_FORMAT_R32G32B32_FLOAT; next_aligned_byte_offset += 3*size_float; break;
			case rs_rdfmt_e::R32G32_FLOAT: vformat = DXGI_FORMAT_R32G32_FLOAT; next_aligned_byte_offset += 2*size_float; break;
			default: vformat = DXGI_FORMAT_UNKNOWN; break;
		}
		input_elems.push_back({iedesc[i].semantic_name, 0, vformat, 0, scast<UINT>(curr_aligned_byte_offset), D3D10_INPUT_PER_VERTEX_DATA, 0});
		curr_aligned_byte_offset = next_aligned_byte_offset;
	}
}

using d3d10_input_layout = rs_com_raii<ID3D10InputLayout>;
using d3d10_rasterizer_state = rs_com_raii<ID3D10RasterizerState>;
using d3d10_buffer = rs_com_raii<ID3D10Buffer>;
using d3d10_font = rs_com_raii<ID3DX10Font>;
using d3d10_texture = rs_com_raii<ID3D10ShaderResourceView>;
using d3d10_shader = rs_com_raii<ID3D10Effect>;


class d3d10_model {
public:		
	ID3D10Buffer* m_vb = nullptr;
	ID3D10Buffer* m_ib = nullptr;		
	isz num_vertices = 0;
	isz num_indices = 0;

	ID3D10InputLayout* m_input_layout = nullptr;

	ID3D10ShaderResourceView* m_tex = nullptr;	
	ID3D10EffectShaderResourceVariable* m_htex = nullptr;

	uint vstride = 0;


	d3d10_model() {}
	~d3d10_model() {
		com_release(m_vb);
		com_release(m_ib);
	}
};


class rd3d10 : public irenderer {
public:

	bool      mMinimized  = false;
	bool      mMaximized  = false;
	bool      mResizing  = false;

	//GameTimer mTimer;
	//std::wstring mFrameStats = L"";
 
	ID3D10Device* m_device = nullptr;
	IDXGISwapChain* m_swap_chain = nullptr;
	ID3D10Texture2D* m_depth_stencil_buffer = nullptr;
	ID3D10RenderTargetView* m_render_target = nullptr;
	ID3D10DepthStencilView* m_depth_stencil = nullptr;

	d3d10_input_layout m_vertex_pc_decl;
	d3d10_input_layout m_vertex_pct_decl;
	d3d10_input_layout m_vertex_ptn_decl;

	d3d10_rasterizer_state m_rast_state;
	D3D10_RASTERIZER_DESC m_rs_desc = {};

	DXGI_FORMAT m_back_buffer_format = DXGI_FORMAT_R8G8B8A8_UNORM;	//DXGI_FORMAT_B8G8R8A8_UNORM;

	d3d10_texture m_default_tex;	

	d3d10_font m_font;


	void deinit_r() {
		if (m_device) { m_device->ClearState(); }

		com_release(m_render_target);
		com_release(m_depth_stencil);
		com_release(m_swap_chain);
		com_release(m_depth_stencil_buffer);
		com_release(m_device);
	}

	bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) {
		//set_viewport(0.0f, 0.0f, width, height);
		if (!hwnd) { eprintfln("Window Handle passed is null."); }
		//m_render_window = hwnd;
		sys_win_title_append(hwnd, " : Direct3D10");
		m_aspect_ratio = sdf::get_aspect_ratio(width, height);

		// Create the device.
		UINT device_flags = 0;
    #ifdef _DEBUG
        device_flags |= D3D10_CREATE_DEVICE_DEBUG;
    #endif
		// This flag adds support for surfaces with a color-channel ordering different
        // from the API default. It is required for compatibility with Direct2D.
        device_flags |= D3D10_CREATE_DEVICE_BGRA_SUPPORT;

		D3D10_DRIVER_TYPE md3dDriverType = D3D10_DRIVER_TYPE_HARDWARE;	

		HRESULT hr = S_OK;
		hr = D3D10CreateDevice(
				nullptr,                 // default adapter
				md3dDriverType,
				nullptr,                 // no software device
				device_flags, 
				D3D10_SDK_VERSION,
				&m_device);

		if (FAILED(hr)) {
			com_release(m_device);	
			eprintfln("D3D10CreateDevice Failed.");
			return false;
		}


		// Check MSAA quality support for our back buffer format.
		// All Direct3D 11 capable devices support 4X MSAA target formats.		
		// FEATURE_LEVEL_10_1 devices are required to support 4x MSAA for all render targets except R32G32B32A32 and R32G32B32.
		// D3D10_MAX_MULTISAMPLE_SAMPLE_COUNT in d3d10.h is 32
		const DXGI_FORMAT msaa_format = DXGI_FORMAT_R8G8B8A8_UNORM;
		HRESULT hr_msaa = m_device->CheckMultisampleQualityLevels(msaa_format, msaa_sample_count, &msaa_num_quality_levels);
		// Check if multisampling is available.
		if (FAILED(hr_msaa) || msaa_num_quality_levels==0) {
			msaa_enabled = false;
		} else {
			msaa_enabled = true;
		}

		if (msaa_enabled) {
			// 4X MSAA (or msaa_sample_count)
			curr_msaa_sample_count   = msaa_sample_count;
			curr_msaa_sample_quality = msaa_num_quality_levels-1;
		} else {
			// No MSAA multisampling.
			curr_msaa_sample_count   = 1;
			curr_msaa_sample_quality = 0;
		}


		// Fill out a DXGI_SWAP_CHAIN_DESC to describe our swap chain.
		DXGI_SWAP_CHAIN_DESC scd = {};
		scd.BufferDesc.Width  = width;
		scd.BufferDesc.Height = height;
		scd.BufferDesc.RefreshRate.Numerator = 60;
		scd.BufferDesc.RefreshRate.Denominator = 1;
		scd.BufferDesc.Format = m_back_buffer_format;
		scd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		scd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		// Swap chain MSAA values. 
		scd.SampleDesc.Count   = curr_msaa_sample_count;
		scd.SampleDesc.Quality = curr_msaa_sample_quality;
		scd.BufferUsage  = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		scd.BufferCount  = 1;
		scd.OutputWindow = hwnd;
		scd.Windowed     = !(fullscreen);
		scd.SwapEffect   = DXGI_SWAP_EFFECT_DISCARD;
		scd.Flags        = 0;


		// To correctly create the swap chain, we must use the IDXGIFactory that was
		// used to create the device. If we tried to use a different IDXGIFactory instance
		// (by calling CreateDXGIFactory), we get an error: "IDXGIFactory::CreateSwapChain: 
		// This function is being called with a device from a different IDXGIFactory."
		IDXGIDevice* dxgiDevice = 0;
		//m_device->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&dxgiDevice));	      
		m_device->QueryInterface(IID_PPV_ARGS(&dxgiDevice));	      
		IDXGIAdapter* dxgiAdapter = 0;
		//dxgiDevice->GetParent(__uuidof(IDXGIAdapter), reinterpret_cast<void**>(&dxgiAdapter));
		dxgiDevice->GetParent(IID_PPV_ARGS(&dxgiAdapter));
		IDXGIFactory* dxgiFactory = 0;
		//dxgiAdapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&dxgiFactory));
		dxgiAdapter->GetParent(IID_PPV_ARGS(&dxgiFactory));

		hr = dxgiFactory->CreateSwapChain(m_device, &scd, &m_swap_chain);
		if (FAILED(hr)) {			
			if (m_device) { m_device->ClearState(); }
			com_release(m_swap_chain);	
			com_release(m_device);	
			eprintfln("Cannot Create D3D10 SwapChain.");
			return false;
		}	
	
		com_release(dxgiDevice);
		com_release(dxgiAdapter);
		com_release(dxgiFactory);

		// The remaining steps that need to be carried out for d3d creation also need to be executed every
		//  time the window is resized. So just call the onResize method here to avoid code duplication.	
		resize(width, height);

		create_render_state();
		init_fonts();

		init_default_texture();

		return true;
	}


	void resize(int width, int height) {
		// Release the old views, as they hold references to the buffers we
		// will be destroying. Also release the old depth/stencil buffer.
		com_release(m_render_target);
		com_release(m_depth_stencil);
		com_release(m_depth_stencil_buffer);


		// Resize the swap chain and recreate the render target view.
		m_swap_chain->ResizeBuffers(1, width, height, m_back_buffer_format, 0);
		ID3D10Texture2D* backBuffer = nullptr;
		//m_swap_chain->GetBuffer(0, __uuidof(ID3D10Texture2D), reinterpret_cast<void**>(&backBuffer));
		m_swap_chain->GetBuffer(0, IID_PPV_ARGS(&backBuffer));
		m_device->CreateRenderTargetView(backBuffer, nullptr, &m_render_target);
		com_release(backBuffer);


		DXGI_FORMAT depth_stencil_format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		// Create the depth/stencil buffer and view.
		D3D10_TEXTURE2D_DESC depth_stencil_desc = {};	
		depth_stencil_desc.Width     = width;
		depth_stencil_desc.Height    = height;
		depth_stencil_desc.MipLevels = 1;
		depth_stencil_desc.ArraySize = 1;
		depth_stencil_desc.Format    = depth_stencil_format;
		// Must match swap chain MSAA values. 
		depth_stencil_desc.SampleDesc.Count   = curr_msaa_sample_count;
		depth_stencil_desc.SampleDesc.Quality = curr_msaa_sample_quality;
		depth_stencil_desc.Usage          = D3D10_USAGE_DEFAULT;
		depth_stencil_desc.BindFlags      = D3D10_BIND_DEPTH_STENCIL;
		depth_stencil_desc.CPUAccessFlags = 0; 
		depth_stencil_desc.MiscFlags      = 0;
		m_device->CreateTexture2D(&depth_stencil_desc, nullptr, &m_depth_stencil_buffer);

		// Create the depth stencil view
		D3D10_DEPTH_STENCIL_VIEW_DESC depth_stencil_view_desc = {};
        depth_stencil_view_desc.Format = depth_stencil_desc.Format;
        depth_stencil_view_desc.ViewDimension = D3D10_DSV_DIMENSION_TEXTURE2D;
        depth_stencil_view_desc.Texture2D.MipSlice = 0;
		m_device->CreateDepthStencilView(m_depth_stencil_buffer, &depth_stencil_view_desc, &m_depth_stencil);

		// Bind the render target view and depth/stencil view to the pipeline.
		m_device->OMSetRenderTargets(1, &m_render_target, m_depth_stencil);
	

		// Set the viewport transform.
		D3D10_VIEWPORT vp = {};
		vp.TopLeftX = 0;
		vp.TopLeftY = 0;
		vp.Width    = width;
		vp.Height   = height;
		vp.MinDepth = D3D10_MIN_DEPTH; //0.0f;
		vp.MaxDepth = D3D10_MAX_DEPTH; //1.0f;
		m_device->RSSetViewports(1, &vp);

		//set_rs_anitialiasing();

		m_aspect_ratio = sdf::get_aspect_ratio(width, height);
		mat_proj = set_projection_matrix();
	}

	void create_render_state() {
		m_rs_desc.FillMode = D3D10_FILL_SOLID;
        m_rs_desc.CullMode = D3D10_CULL_BACK;	//CCW with FrontCounterClockwise = false.
        m_rs_desc.FrontCounterClockwise = FALSE;
        m_rs_desc.DepthBias = D3D10_DEFAULT_DEPTH_BIAS;
        m_rs_desc.DepthBiasClamp = D3D10_DEFAULT_DEPTH_BIAS_CLAMP;
        m_rs_desc.SlopeScaledDepthBias = D3D10_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;
        m_rs_desc.DepthClipEnable = TRUE;
        m_rs_desc.ScissorEnable = FALSE;
        m_rs_desc.MultisampleEnable = msaa_enabled;	//FALSE;
        m_rs_desc.AntialiasedLineEnable = FALSE;

		m_device->CreateRasterizerState(&m_rs_desc, &m_rast_state.data);
	}
	


	// Default setup, cleanup, render func.
	void setup() {}
	void cleanup() {}	

	void render(float dt) {		
		clear_render_target(gm::color4(0.0, 1.0, 0.0, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);
	}

	void swap_buffers() {
		m_swap_chain->Present(0, 0);
	}


	//-----------------------------------------------------------
	void clear_render_target(const gm::color4& color_rgba) {
		//float clear_color[4] = {0.0f, 1.0f, 1.0f, 1.0f};
		//m_device->ClearRenderTargetView(m_render_target, clear_color);
		m_device->ClearRenderTargetView(m_render_target, color_rgba.data());
	}
	void clear_depth_stencil(bool clear_depth, bool clear_stencil, float depth, uint stencil) {
		uint clear_flag = 0;
		if (clear_depth) { clear_flag |= D3D10_CLEAR_DEPTH; }
		if (clear_stencil) { clear_flag |= D3D10_CLEAR_STENCIL; }    
		//m_device->ClearDepthStencilView(m_depth_stencil, D3D10_CLEAR_DEPTH|D3D10_CLEAR_STENCIL, 1.0f, 0);
		m_device->ClearDepthStencilView(m_depth_stencil, clear_flag, depth, stencil);
	}

	//-----------------------------------------------------------
	void set_rs_culling(rs_cull_mode_e cullmode_back_face) {
		// Default cull mode is D3DCULL_CCW for D3D9, culling refering to back face culling.
		// A front face is one in which vertices are defined in clockwise order. Back faces having CCW are culled.
		// In OpenGL CCW is frontface by default. Use glFrontFace(GL_CW) to specify CCW as backface like D3D9. 
		switch (cullmode_back_face) {
			case rs_cull_mode_e::cull_none: m_rs_desc.CullMode = D3D10_CULL_NONE; break;
			case rs_cull_mode_e::cull_cw: m_rs_desc.CullMode = D3D10_CULL_FRONT; break;
			case rs_cull_mode_e::cull_ccw: m_rs_desc.CullMode = D3D10_CULL_BACK; break;
			default: m_rs_desc.CullMode = D3D10_CULL_BACK; break; //D3DCULL_CCW
		}
		m_device->CreateRasterizerState(&m_rs_desc, &m_rast_state.data);
		m_device->RSSetState(m_rast_state.data);
	}

	void set_rs_fillmode(rs_fill_mode_e fill_mode) {
		switch (fill_mode) {
			case rs_fill_mode_e::fill_solid: m_rs_desc.FillMode = D3D10_FILL_SOLID; break;
			case rs_fill_mode_e::fill_wireframe: m_rs_desc.FillMode = D3D10_FILL_WIREFRAME; break;
			default: m_rs_desc.FillMode = D3D10_FILL_SOLID; break;
		}
		m_device->CreateRasterizerState(&m_rs_desc, &m_rast_state.data);
		m_device->RSSetState(m_rast_state.data);
	} 

	//void set_rs_anitialiasing() {
	//	m_rs_desc.MultisampleEnable = msaa_enabled;
	//	m_device->CreateRasterizerState(&m_rs_desc, &m_rast_state.data);
	//	m_device->RSSetState(m_rast_state.data);
	//}


	//-----------------------------------------------------------
	void set_primitive_topology() {
		m_device->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	}

	void load_shaders_file(const char* shader_filename, d3d10_shader& shader_fx) {
		if (!(is_file_exists(shader_filename))) {
			eprintfln("Cannot find shader file: %s", shader_filename);
			return;
		}

		sdf::wstring_st<MAX_STR_PATH_OS> shader_file_namew;
		sdf::string_st_wcs_from_mbs(shader_file_namew, shader_filename, sdf::strfz_len(shader_filename));

		// Create the FX from a .fx file.
		DWORD shaderFlags = D3D10_SHADER_ENABLE_STRICTNESS;
	#if defined(DEBUG) || defined(_DEBUG)
		shaderFlags |= D3D10_SHADER_DEBUG;
		shaderFlags |= D3D10_SHADER_SKIP_OPTIMIZATION;
	#endif
 
		ID3D10Blob* compilation_errors = 0;
		HRESULT hr = S_OK;
		hr = D3DX10CreateEffectFromFileW(shader_file_namew.c_str(), nullptr, nullptr, "fx_4_0", shaderFlags, 0, m_device, nullptr, nullptr, &shader_fx.data, &compilation_errors, nullptr);

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

	




	//-----------------------------------------------------------
	void create_texture(const char* tex_file_name, ID3D10ShaderResourceView*& tex) {
		sdf::wstring_st<MAX_STR_PATH_OS> tex_file_namew;
		sdf::string_st_wcs_from_mbs(tex_file_namew, tex_file_name, sdf::strfz_len(tex_file_name));
		HRESULT hr = D3DX10CreateShaderResourceViewFromFileW(m_device, tex_file_namew.c_str(), nullptr, nullptr, &tex, nullptr);
		if (FAILED(hr)) { eprintfln("D3DX10CreateShaderResourceViewFromFileW: Cannot Load File: %s", tex_file_name); }				
	}

	void set_texture(ID3D10ShaderResourceView* tex, ID3D10EffectShaderResourceVariable* htex) {
		htex->SetResource(tex);
	}

	void set_texture_null(ID3D10EffectShaderResourceVariable* htex) {
		htex->SetResource(nullptr);
	}


	void init_default_texture() {
		create_texture(m_default_texture_file, m_default_tex.data);		
	}



	//-----------------------------------------------------------
	void init_fonts() {
		LOGFONTW lf = {};
		create_log_font(lf);
		D3DX10_FONT_DESCW d3dx_font_desc = {};
		D3DX10_FONT_DESC_from_logfont(lf, d3dx_font_desc);
		// Create an ID3DX10Font based on logfont.
		D3DX10CreateFontIndirectW(m_device, &d3dx_font_desc, &m_font.data);	
	}

	void draw_font(const char* text) {
		sdf::wstring_st<255> wtext;
		sdf::string_st_wcs_from_mbs(wtext, text, sdf::strfz_len(text));
		int fw = 640;
		int fh = 360;

		//RECT formatRect;
		//GetClientRect(mhMainWnd, &formatRect);
		//mFont->DrawTextW(0, L"Hello Direct3D", -1, &formatRect, DT_CENTER|DT_VCENTER, D3DCOLOR_XRGB(255, 0, 0));

		// Display font
		// We specify DT_NOCLIP, so we do not care about width/height of the rect.
		RECT rect = {0, 0, fw, fh};
		// Count: size of string or -1 indicates null terminating string. 
		// pRect: rectangle text is to be formatted to in windows coords
		m_font.data->DrawTextW(nullptr, wtext.c_str(), wtext.size(), &rect, DT_TOP|DT_LEFT, gm::argb_from_color4(m_font_color));	
		//m_font.data->DrawTextW(nullptr, wtext.c_str(), -1, &rect, DT_CENTER|DT_VCENTER, D3DCOLOR_XRGB(255, 0, 0));
		//m_font.data->DrawTextW(nullptr, wtext.c_str(), -1, &rect, DT_NOCLIP, D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f));	
	}

	void reset_default_states() {
		// Restore default states, input layout and primitive topology because mFont->DrawText changes them. 
		// Note that we can restore the default states by passing null.
		m_device->OMSetDepthStencilState(nullptr, 0);
		float blendFactors[] = {0.0f, 0.0f, 0.0f, 0.0f};
		m_device->OMSetBlendState(nullptr, blendFactors, 0xffffffff);
		set_primitive_topology();
	}

	//-----------------------------
	void create_vertex_buffer(UINT vb_size_bytes, const void* sys_mem_data, ID3D10Buffer*& vb) {
		// Create the vertex buffer. 
		//UINT vb_size_bytes = vertices_vec.size() * sizeof(vertex_pc);	
		D3D10_BUFFER_DESC vbd = {};
		vbd.ByteWidth = vb_size_bytes;
		vbd.Usage = D3D10_USAGE_DEFAULT; //D3D10_USAGE_IMMUTABLE;		
		vbd.BindFlags = D3D10_BIND_VERTEX_BUFFER;
		vbd.CPUAccessFlags = 0;
		vbd.MiscFlags = 0;
		D3D10_SUBRESOURCE_DATA vInitData = {};
		vInitData.pSysMem = sys_mem_data;
		m_device->CreateBuffer(&vbd, &vInitData, &vb);	
	}

	void create_index_buffer(UINT ib_size_bytes, const void* sys_mem_data, ID3D10Buffer*& ib) {
		// Create the index buffer. 
		//UINT ib_size_bytes = indices_vec.size() * sizeof(uint);
		D3D10_BUFFER_DESC ibd = {};
		ibd.ByteWidth = ib_size_bytes;
		ibd.Usage = D3D10_USAGE_DEFAULT; //D3D10_USAGE_IMMUTABLE;		
		ibd.BindFlags = D3D10_BIND_INDEX_BUFFER;
		ibd.CPUAccessFlags = 0;
		ibd.MiscFlags = 0;
		D3D10_SUBRESOURCE_DATA iInitData = {};
		iInitData.pSysMem = sys_mem_data; 
		m_device->CreateBuffer(&ibd, &iInitData, &ib);	
	} 

	void create_model(d3d10_model& model, const void* vertices_data, isz vertices_size, uint vertices_stride, 
		const void* indices_data, isz indices_size, uint indices_stride, ID3D10InputLayout* input_layout, 
		ID3D10ShaderResourceView* tex, ID3D10EffectShaderResourceVariable* htex) {
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

		model.m_htex = htex;
	}

	template<class T>
	void create_model_rsmodel(d3d10_model& model, rs_model<T> rmodel, ID3D10InputLayout* input_layout, 
		ID3D10ShaderResourceView* tex, ID3D10EffectShaderResourceVariable* htex) {
		create_model(model, rmodel.vertices_vec.data(), rmodel.vertices_vec.size(), rmodel.vstride(), 
				rmodel.indices_vec.data(), rmodel.indices_vec.size(), rmodel.istride(), input_layout, tex, htex);	
	}

	void create_model_basic(d3d10_model& model, const void* vertices_data, isz vertices_size, uint vertices_stride, 
		const void* indices_data, isz indices_size, uint indices_stride, ID3D10InputLayout* input_layout, 
		ID3D10ShaderResourceView* tex, ID3D10EffectShaderResourceVariable* htex) {
		create_model(model, vertices_data, vertices_size, vertices_stride, indices_data, indices_size, indices_stride, 
			input_layout, tex, htex);
	}

	void draw_model_set(const d3d10_model& model) {
		set_texture(model.m_tex, model.m_htex);			

		m_device->IASetInputLayout(model.m_input_layout);

		UINT offset = 0;
		m_device->IASetVertexBuffers(0, 1, &model.m_vb, &model.vstride, &offset);
        m_device->IASetIndexBuffer(model.m_ib, DXGI_FORMAT_R32_UINT, 0);		
	}

	void draw_model(const d3d10_model& model) {
		m_device->DrawIndexed(model.num_indices, 0, 0);	
	}	
};



class rd3d10_tri_color : public rd3d10  {
public:		

	ID3D10InputLayout* m_input_layout;

	ID3D10Buffer* triangle_m_vb = nullptr;
	ID3D10Buffer* triangle_m_ib = nullptr;		
	int64 tri_num_vertices = 0;
	int64 tri_num_indices = 0;

	gm::mat4 mat_world_tri = gm::mat4::k_identity();

	d3d10_shader shader_fx;
	ID3D10EffectTechnique* htech = nullptr;			
	ID3D10EffectMatrixVariable* hmat_wvp = nullptr;

	void setup() {	
		set_rs_culling(rs_cull_mode_e::cull_ccw);

		// Load shaders before CreateVertexDeclaration or CreateInputLayout
		load_shaders_file(RS_SHADER_PATH2("d3d10_vertex_pc.fx"), shader_fx);
		// Obtain handles.
		htech = shader_fx.data->GetTechniqueByName("shader_tech");
		hmat_wvp = shader_fx.data->GetVariableByName("g_mat_wvp")->AsMatrix();

		// Create vertex declaration for expressing the data layout. Conceptually, the vertex declaration is a way of 
		// programming the vertex direct memory access (DMA) and the tessellator engine of the graphics pipe.
		D3D10_INPUT_ELEMENT_DESC vertex_elements_pc[] =  {
			{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 0,  D3D10_INPUT_PER_VERTEX_DATA, 0},
			{"COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0}
		};	
		UINT num_vertex_elements_pc = sdf::arr_cap(vertex_elements_pc);
		// Create the input layout.
		D3D10_PASS_DESC PassDesc;
		htech->GetPassByIndex(0)->GetDesc(&PassDesc);
		m_device->CreateInputLayout(vertex_elements_pc, num_vertex_elements_pc, PassDesc.pIAInputSignature, 
			PassDesc.IAInputSignatureSize, &m_input_layout);	


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

	#if 1
		// Create the vertex buffer. 
		UINT vb_size_bytes = vertices_vec.size() * sizeof(vertex_pc);	
		D3D10_BUFFER_DESC vbd = {};
		vbd.ByteWidth = vb_size_bytes;
		vbd.Usage = D3D10_USAGE_DEFAULT; //D3D10_USAGE_IMMUTABLE;		
		vbd.BindFlags = D3D10_BIND_VERTEX_BUFFER;
		vbd.CPUAccessFlags = 0;
		vbd.MiscFlags = 0;
		D3D10_SUBRESOURCE_DATA vInitData = {};
		vInitData.pSysMem = vertices_vec.data();
		m_device->CreateBuffer(&vbd, &vInitData, &triangle_m_vb);	

		// Enable if using index buffers.
		// Create the index buffer. 
		UINT ib_size_bytes = indices_vec.size() * sizeof(uint);
		D3D10_BUFFER_DESC ibd = {};
		ibd.ByteWidth = ib_size_bytes;
		ibd.Usage = D3D10_USAGE_DEFAULT; //D3D10_USAGE_IMMUTABLE;		
		ibd.BindFlags = D3D10_BIND_INDEX_BUFFER;
		ibd.CPUAccessFlags = 0;
		ibd.MiscFlags = 0;
		D3D10_SUBRESOURCE_DATA iInitData = {};
		iInitData.pSysMem = indices_vec.data(); 
		m_device->CreateBuffer(&ibd, &iInitData, &triangle_m_ib);	
	#else

		// Create the vertex buffer. 
		UINT vb_size_bytes = vertices_vec.size() * sizeof(vertex_pc);	
		CD3D10_BUFFER_DESC vbd(vb_size_bytes, D3D10_BIND_VERTEX_BUFFER);
		D3D10_SUBRESOURCE_DATA vInitData = {};
		vInitData.pSysMem = vertices_vec.data();
		m_device->CreateBuffer(&vbd, &vInitData, &triangle_m_vb);

		// Enable if using index buffers.
		// Create the index buffer. 
		UINT ib_size_bytes = indices_vec.size() * sizeof(uint);
		CD3D10_BUFFER_DESC ibd(ib_size_bytes, D3D10_BIND_INDEX_BUFFER);
		D3D10_SUBRESOURCE_DATA iInitData = {};
		iInitData.pSysMem = indices_vec.data();
		m_device->CreateBuffer(&ibd, &iInitData, &triangle_m_ib);
	#endif		

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);

		// Set primitive topology
		m_device->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		//----------------------------------------
		// World Matrix
		//mat_world_tri = gm::mat4_translation(gm::vec3(1.25f, 0.0f, 0.0f));
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
		// mFont->DrawText changes default states, input layout and primitive topology. Restore them.
		reset_default_states();

		m_device->IASetInputLayout(m_input_layout);
		// Set vertex buffer
		UINT stride = sizeof(vertex_pc);
		UINT offset = 0;
		m_device->IASetVertexBuffers(0, 1, &triangle_m_vb, &stride, &offset);
		// Enable if using index buffers.
		// Set index buffer
		m_device->IASetIndexBuffer(triangle_m_ib, DXGI_FORMAT_R32_UINT, 0);

		gm::mat4 mat_wvp_temp = mat_world_tri * mat_view * mat_proj;
		//hmat_wvp->SetMatrix(rcast<float*>(&mWVP));
		hmat_wvp->SetMatrix(mat_wvp_temp.data());

		// Begin passes.
		D3D10_TECHNIQUE_DESC techDesc = {};
		htech->GetDesc(&techDesc);
		for (UINT i = 0; i < techDesc.Passes; ++i) {
			htech->GetPassByIndex(i)->Apply(0);  
			// If only vertex buffer then, tri_num_indices is equal to num_vertices.
			//m_device->Draw(tri_num_indices, 0);
			m_device->DrawIndexed(tri_num_indices, 0, 0);
		}
	}

	void cleanup() {
		com_release(triangle_m_vb);
		com_release(triangle_m_ib);
		com_release(m_input_layout);	
	}
};


class rd3d10_color_tex : public rd3d10  {
public:	
	d3d10_input_layout m_input_layout;

	gm::mat4 model0_mat_world = gm::mat4::k_identity();
	d3d10_model model0;
	d3d10_texture tex0;

	d3d10_shader shader_fx;
	ID3D10EffectTechnique* htech;
	ID3D10EffectMatrixVariable* hmat_wvp;
	ID3D10EffectShaderResourceVariable* htex;

	void setup() {	
		set_rs_culling(rs_cull_mode_e::cull_ccw);

		load_shaders_file(RS_SHADER_PATH2("d3d10_vertex_pct.fx"), shader_fx);
		htech = shader_fx.data->GetTechniqueByName("shader_tech");
		hmat_wvp = shader_fx.data->GetVariableByName("g_mat_wvp")->AsMatrix();
		htex = shader_fx.data->GetVariableByName("g_tex")->AsShaderResource();		

		rs_input_element_desc vfmt_pc[3] = {
			{"POSITION",	rs_rdfmt_e::R32G32B32_FLOAT},
			{"COLOR",		rs_rdfmt_e::R32G32B32A32_FLOAT},
			{"TEXCOORD",	rs_rdfmt_e::R32G32_FLOAT},			
		};

		sdr::vector<D3D10_INPUT_ELEMENT_DESC> input_elements;
		d3d10_create_input_element_desc(sdf::span(vfmt_pc, sdf::arr_cap(vfmt_pc)), input_elements);

		// Create the input layout
		D3D10_PASS_DESC PassDesc;
		htech->GetPassByIndex(0)->GetDesc(&PassDesc);
		m_device->CreateInputLayout(input_elements.data(), input_elements.size(), PassDesc.pIAInputSignature, 
			PassDesc.IAInputSignatureSize, &m_input_layout.data);		
	
		
		create_texture(RS_MEDIA_PATH("tut/glitter/dog.jpg"), tex0.data);
		//create_texture(RS_MEDIA_PATH("nw_tex/checker_white.png"), tex0.data);


		// Load data to vector.
		sdr::vector<vertex_pct> vertices_vec;
		sdr::vector<uint> indices_vec;
		fill_triangle_vertex_pct(vertices_vec, indices_vec);		

		create_model_basic(model0, vertices_vec.data(), vertices_vec.size(), sizeof(decltype(vertices_vec)::value_type), 
			indices_vec.data(), indices_vec.size(), sizeof(decltype(indices_vec)::value_type), m_input_layout.data, tex0.data, htex);			

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);

		set_primitive_topology();

		//----------------------------------------

		// World Matrix
		//model0.mat_world = gm::mat4_translation(gm::vec3(1.25f, 0.0f, 0.0f));
		//model0.mat_world = gm::mat4_scaling(gm::vec3(2.0, 1.0, 1.0));
		// Rotating on x axis, since x axis is same while y or z can be up.
		//model0.mat_world = gm::mat4_rotation_x(mf::deg_to_rad<float>(30));

		m_camera.set_position(gm::vec3(0.0f, 0.0f, -3.0f));
		mat_proj = set_projection_matrix();		
	}

	void render(float dt) {
		update_camera(dt);
		mat_view = m_camera.get_view_matrix();

		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

		gm::mat4 mat_wvp_temp = model0_mat_world * mat_view * mat_proj;
		//hmat_wvp->SetMatrix(rcast<float*>(&mWVP));
		hmat_wvp->SetMatrix(mat_wvp_temp.data());			

		draw_model_set(model0);

		// Begin passes.
		D3D10_TECHNIQUE_DESC techDesc = {};
		htech->GetDesc(&techDesc);
		for (UINT i = 0; i < techDesc.Passes; ++i) {
			htech->GetPassByIndex(i)->Apply(0);  
			draw_model(model0);
		}

		draw_font("Hello World.");
		// mFont->DrawText changes default states, input layout and primitive topology. Restore them.
		reset_default_states();	
	}

	void cleanup() {		
	}
};


class rd3d10_cube : public rd3d10  {
public:	
	d3d10_input_layout m_input_layout;

	gm::mat4 model0_mat_world = gm::mat4::k_identity();
	d3d10_model model0;
	d3d10_texture tex0;

	d3d10_shader shader_fx;
	ID3D10EffectTechnique* htech;
	ID3D10EffectMatrixVariable* hmat_wvp;
	ID3D10EffectShaderResourceVariable* htex;

	void setup() {	
		set_rs_culling(rs_cull_mode_e::cull_ccw);

		load_shaders_file(RS_SHADER_PATH2("d3d10_vertex_ptn.fx"), shader_fx);
		htech = shader_fx.data->GetTechniqueByName("shader_tech");
		hmat_wvp = shader_fx.data->GetVariableByName("g_mat_wvp")->AsMatrix();
		htex = shader_fx.data->GetVariableByName("g_tex")->AsShaderResource();		

		rs_input_element_desc vfmt_pc[3] = {
			{"POSITION",	rs_rdfmt_e::R32G32B32_FLOAT},
			{"TEXCOORD",	rs_rdfmt_e::R32G32_FLOAT},
			{"NORMAL",		rs_rdfmt_e::R32G32B32_FLOAT},	
		};

		sdr::vector<D3D10_INPUT_ELEMENT_DESC> input_elements;
		d3d10_create_input_element_desc(sdf::span(vfmt_pc, sdf::arr_cap(vfmt_pc)), input_elements);

		// Create the input layout
		D3D10_PASS_DESC PassDesc;
		htech->GetPassByIndex(0)->GetDesc(&PassDesc);
		m_device->CreateInputLayout(input_elements.data(), input_elements.size(), PassDesc.pIAInputSignature, 
			PassDesc.IAInputSignatureSize, &m_input_layout.data);		
	
		
		//create_texture(RS_MEDIA_PATH("tut/glitter/dog.jpg"), tex0.data);
		create_texture(RS_MEDIA_PATH("nw_tex/checker_white.png"), tex0.data);


		// Load data to vector.
		rs_model<vertex_ptn> rmodel0;	
		fill_cube_vertex_ptn(rmodel0.vertices_vec, rmodel0.indices_vec);

		create_model_rsmodel(model0, rmodel0, m_input_layout.data, tex0.data, htex);

		rmodel0.clear_memory();	

		set_primitive_topology();


		//----------------------------------------

		// World Matrix
		//model0.mat_world = gm::mat4_translation(gm::vec3(1.25f, 0.0f, 0.0f));
		//model0.mat_world = gm::mat4_scaling(gm::vec3(2.0, 1.0, 1.0));
		// Rotating on x axis, since x axis is same while y or z can be up.
		//model0.mat_world = gm::mat4_rotation_x(mf::deg_to_rad<float>(30));

		m_camera.set_position(gm::vec3(0.0f, 3.0f, -8.0f));
		mat_proj = set_projection_matrix();		
	}

	void render(float dt) {
		update_camera(dt);
		mat_view = m_camera.get_view_matrix();

		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

		gm::mat4 mat_wvp_temp = model0_mat_world * mat_view * mat_proj;
		//hmat_wvp->SetMatrix(rcast<float*>(&mWVP));
		hmat_wvp->SetMatrix(mat_wvp_temp.data());			

		draw_model_set(model0);

		// Begin passes.
		D3D10_TECHNIQUE_DESC techDesc = {};
		htech->GetDesc(&techDesc);
		for (UINT i = 0; i < techDesc.Passes; ++i) {
			htech->GetPassByIndex(i)->Apply(0);  
			draw_model(model0);
		}

		reset_default_states();	
	}

	void cleanup() {		
	}
};