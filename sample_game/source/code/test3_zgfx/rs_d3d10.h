#pragma once

#include "rs_hdr_sdk_d3d10.h"

#include "rs_irenderer.h"

inline void load_shaders_file(ID3D10Device* m_device, const char* shader_filename, ID3D10Effect*& shader_fx) {
	if (!(is_file_exists(shader_filename))) {
		eprintfln("Cannot find shader file: %s", shader_filename);
		return;
	}

	wchar_t shader_file_namew[MAX_PATH_OS] = {};
	sdf::strf_assign_mbs(shader_file_namew, sdf::strz_cap(shader_file_namew), shader_filename, sdf::strfz_len(shader_filename));

	// Create the FX from a .fx file.
	UINT shader_flags = D3D10_SHADER_ENABLE_STRICTNESS;
#if defined(_DEBUG)
	shaderFlags |= D3D10_SHADER_DEBUG;
	shaderFlags |= D3D10_SHADER_SKIP_OPTIMIZATION;
#endif
 
	ID3D10Blob* compilation_errors = nullptr;
	HRESULT hr = S_OK;
	hr = D3DX10CreateEffectFromFileW(shader_file_namew, nullptr, nullptr, "fx_4_0", shader_flags, 0, m_device, 
		nullptr, nullptr, &shader_fx, &compilation_errors, nullptr);

	if (FAILED(hr)) {
		if (compilation_errors) {
			eprintfln("Shader File compile error: %s", shader_filename);
			const char* shader_err_msg = rcast<const char*>(compilation_errors->GetBufferPointer());
			//MessageBoxA(0, shader_err_msg, 0, 0);
			wchar_t wmsg[1024] = {};
			sdf::strf_assign_mbs(wmsg, sdf::strz_cap(wmsg), shader_err_msg, sdf::strfz_len(shader_err_msg));
			fm_msg_box_ok_w(wmsg);
			//eprintfln("%s", shader_err_msg);
			compilation_errors->Release();
		}
	} 
}

inline void create_font(ID3D10Device* m_device, ID3DX10Font*& m_font) {
	D3DX10_FONT_DESC fontDesc = {};
	fontDesc.Height          = 24;
	fontDesc.Width           = 0;
	fontDesc.Weight          = 0;
	fontDesc.MipLevels       = 1;
	fontDesc.Italic          = false;
	fontDesc.CharSet         = DEFAULT_CHARSET;
	fontDesc.OutputPrecision = OUT_DEFAULT_PRECIS;
	fontDesc.Quality         = DEFAULT_QUALITY;
	fontDesc.PitchAndFamily  = DEFAULT_PITCH | FF_DONTCARE;
	wcscpy(fontDesc.FaceName, L"Times New Roman");

	D3DX10CreateFontIndirect(m_device, &fontDesc, &m_font);
}

inline void draw_font(ID3D10Device* m_device, ID3DX10Font* m_font, const char* text) {
	wchar_t wstr_text[256] = {};
	sdf::strf_assign_mbs(wstr_text, sdf::strz_cap(wstr_text), text, sdf::strfz_len(text));
	// We specify DT_NOCLIP, so we do not care about width/height of the rect.
	RECT formatRect = {0, 0, 0, 0};
	m_font->DrawTextW(nullptr, wstr_text, -1, &formatRect, DT_NOCLIP, gm::argb_from_color4(gm::color4(1.0, 0.0, 0.0, 1.0)));	
}

inline void create_vertex_buffer(ID3D10Device* m_device, UINT vb_size_bytes, const void* sys_mem_data, ID3D10Buffer*& vb) {
	// Create the vertex buffer. 
	//UINT vb_size_bytes = vertices_vec.size() * sizeof(vertex_type);
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

inline void create_index_buffer(ID3D10Device* m_device, UINT ib_size_bytes, const void* sys_mem_data, ID3D10Buffer*& ib) {
	// Create the index buffer. 
	//UINT ib_size_bytes = indices_vec.size() * sizeof(index_type_uint);
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

inline void create_texture(ID3D10Device* m_device, const char* tex_file_name, ID3D10ShaderResourceView*& tex) {
	wchar_t tex_file_namew[256] = {};
	sdf::strf_assign_mbs(tex_file_namew, sdf::strz_cap(tex_file_namew), tex_file_name, sdf::strfz_len(tex_file_name));
	HRESULT hr = D3DX10CreateShaderResourceViewFromFileW(m_device, tex_file_namew, nullptr, nullptr, &tex, nullptr);
	if (FAILED(hr)) { eprintfln("D3DX10CreateShaderResourceViewFromFileW: Cannot Load File: %s", tex_file_name); }				
}

//-------------------------
// MS tutorials
class wm_rd3d10_dsc : public wm_irenderer {
	ID3D10Device* m_device = nullptr;
	IDXGISwapChain* m_swap_chain = nullptr;
	ID3D10Texture2D* m_depth_stencil_buffer = nullptr;
	ID3D10RenderTargetView* m_render_target_view = nullptr;
	ID3D10DepthStencilView* m_depth_stencil_view = nullptr;

	UINT m_back_buffer_count = 1;

	DXGI_FORMAT m_back_buffer_format = DXGI_FORMAT_R8G8B8A8_UNORM;	//DXGI_FORMAT_B8G8R8A8_UNORM;
	DXGI_FORMAT m_depth_stencil_format = DXGI_FORMAT_D24_UNORM_S8_UINT;	
	

	bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { 
		set_init_params(hwnd, width, height, " : Direct3D10_dsc");	

		D3D10_DRIVER_TYPE md3dDriverType = D3D10_DRIVER_TYPE_HARDWARE;

		// Create the device.
		UINT device_flags = 0;
    #ifdef _DEBUG
        device_flags |= D3D10_CREATE_DEVICE_DEBUG;
    #endif
		// This flag adds support for surfaces with a color-channel ordering different
        // from the API default. It is required for compatibility with Direct2D.
        device_flags |= D3D10_CREATE_DEVICE_BGRA_SUPPORT;

		// Fill out a DXGI_SWAP_CHAIN_DESC to describe our swap chain.
		DXGI_SWAP_CHAIN_DESC sd = {};
		sd.BufferDesc.Width  = m_client_width;
		sd.BufferDesc.Height = m_client_height;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferDesc.Format = m_back_buffer_format;
		sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

		// No multisampling.
		sd.SampleDesc.Count   = curr_msaa_sample_count;
		sd.SampleDesc.Quality = curr_msaa_sample_quality;

		sd.BufferUsage  = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.BufferCount  = m_back_buffer_count;
		sd.OutputWindow = m_render_window;
		sd.Windowed     = !fullscreen;
		sd.SwapEffect   = DXGI_SWAP_EFFECT_DISCARD;
		sd.Flags        = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH; //0;

		HRESULT hr = S_OK;
		D3D10CreateDeviceAndSwapChain(
			0,                 //default adapter
			md3dDriverType,
			0,                 // no software device
			device_flags, 
			D3D10_SDK_VERSION,
			&sd,
			&m_swap_chain,
			&m_device);


		// The remaining steps that need to be carried out for d3d creation also need to be executed every
		// time the window is resized. So just call the resize method here to avoid code duplication.	
		resize_internal();

		//set_primitive_topology();

		return true;
	}

	void resize_internal() {
		// Release the old views, as they hold references to the buffers we
		// will be destroying. Also release the old depth/stencil buffer.
		com_release(m_render_target_view);
		com_release(m_depth_stencil_view);
		com_release(m_depth_stencil_buffer);


		// Resize the swap chain and recreate the render target view.
		m_swap_chain->ResizeBuffers(m_back_buffer_count, m_client_width, m_client_height, m_back_buffer_format, 0);
		ID3D10Texture2D* m_back_buffer = nullptr;
		//m_swap_chain->GetBuffer(0, __uuidof(ID3D10Texture2D), reinterpret_cast<void**>(&backBuffer));
		m_swap_chain->GetBuffer(0, IID_PPV_ARGS(&m_back_buffer));
		m_device->CreateRenderTargetView(m_back_buffer, nullptr, &m_render_target_view);
		com_release(m_back_buffer);


		// Create the depth/stencil buffer and view.
		D3D10_TEXTURE2D_DESC depth_stencil_desc = {};	
		depth_stencil_desc.Width     = m_client_width;
		depth_stencil_desc.Height    = m_client_height;
		depth_stencil_desc.MipLevels = 1;
		depth_stencil_desc.ArraySize = 1;
		depth_stencil_desc.Format    = m_depth_stencil_format;
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
		m_device->CreateDepthStencilView(m_depth_stencil_buffer, &depth_stencil_view_desc, &m_depth_stencil_view);

		// Bind the render target view and depth/stencil view to the pipeline.
		m_device->OMSetRenderTargets(1, &m_render_target_view, m_depth_stencil_view);
	

		// Set the viewport transform.
		D3D10_VIEWPORT vp = {};
		vp.TopLeftX = 0;
		vp.TopLeftY = 0;
		vp.Width    = m_client_width;
		vp.Height   = m_client_height;
		vp.MinDepth = D3D10_MIN_DEPTH; //0.0f;
		vp.MaxDepth = D3D10_MAX_DEPTH; //1.0f;
		m_device->RSSetViewports(1, &vp);

		//set_rs_anitialiasing();
		
		mat_proj = get_proj_matrix();
	}

	void deinit_r() {
		if (m_device) { m_device->ClearState(); }
		com_release(m_render_target_view);
		com_release(m_depth_stencil_view);
		com_release(m_swap_chain);
		com_release(m_depth_stencil_buffer);
		com_release(m_device);
	}

	void setup() {}
	void cleanup() {}

	void render(float dt) {
		m_device->ClearRenderTargetView(m_render_target_view, gm::color4(1.0, 0.0, 0.0, 1.0).data());
		m_device->ClearDepthStencilView(m_depth_stencil_view, D3D10_CLEAR_DEPTH|D3D10_CLEAR_STENCIL, 1.0f, 0);
	}

	void swap_buffers() {
		m_swap_chain->Present(0, 0);
	}
};


//--------------------------
class wm_rd3d10 : public wm_irenderer {
public:
	ID3D10Device* m_device = nullptr;
	IDXGISwapChain* m_swap_chain = nullptr;
	ID3D10Texture2D* m_depth_stencil_buffer = nullptr;
	ID3D10RenderTargetView* m_render_target_view = nullptr;
	ID3D10DepthStencilView* m_depth_stencil_view = nullptr;

	UINT m_back_buffer_count = 1;

	DXGI_FORMAT m_back_buffer_format = DXGI_FORMAT_R8G8B8A8_UNORM;	//DXGI_FORMAT_B8G8R8A8_UNORM;
	DXGI_FORMAT m_depth_stencil_format = DXGI_FORMAT_D24_UNORM_S8_UINT;	

	D3D10_RASTERIZER_DESC m_rs_desc = {};
	ID3D10RasterizerState* m_rast_state = nullptr;	

	ID3DX10Font* m_font = nullptr;


	bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { 
		set_init_params(hwnd, width, height, " : Direct3D10");

		D3D10_DRIVER_TYPE md3dDriverType = D3D10_DRIVER_TYPE_HARDWARE;

		// Create the device.
		UINT device_flags = 0;
    #ifdef _DEBUG
        device_flags |= D3D10_CREATE_DEVICE_DEBUG;
    #endif
		// This flag adds support for surfaces with a color-channel ordering different
        // from the API default. It is required for compatibility with Direct2D.
        device_flags |= D3D10_CREATE_DEVICE_BGRA_SUPPORT;

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


		// Create Swap chain.
		// To correctly create the swap chain, we must use the IDXGIFactory that was
		// used to create the device. If we tried to use a different IDXGIFactory instance
		// (by calling CreateDXGIFactory), we get an error: "IDXGIFactory::CreateSwapChain: 
		// This function is being called with a device from a different IDXGIFactory."
		IDXGIDevice* dxgiDevice = nullptr;
		//m_device->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&dxgiDevice));	      
		m_device->QueryInterface(IID_PPV_ARGS(&dxgiDevice));	      
		IDXGIAdapter* dxgiAdapter = nullptr;
		//dxgiDevice->GetParent(__uuidof(IDXGIAdapter), reinterpret_cast<void**>(&dxgiAdapter));
		dxgiDevice->GetParent(IID_PPV_ARGS(&dxgiAdapter));
		IDXGIFactory* dxgiFactory = nullptr;
		//dxgiAdapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&dxgiFactory));
		dxgiAdapter->GetParent(IID_PPV_ARGS(&dxgiFactory));


		// Fill out a DXGI_SWAP_CHAIN_DESC to describe our swap chain.
		DXGI_SWAP_CHAIN_DESC scd = {};
		scd.BufferDesc.Width  = m_client_width;
		scd.BufferDesc.Height = m_client_height;
		scd.BufferDesc.RefreshRate.Numerator = 60;
		scd.BufferDesc.RefreshRate.Denominator = 1;
		scd.BufferDesc.Format = m_back_buffer_format;
		scd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		scd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		// Swap chain MSAA values. 
		scd.SampleDesc.Count   = curr_msaa_sample_count;
		scd.SampleDesc.Quality = curr_msaa_sample_quality;
		scd.BufferUsage  = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		scd.BufferCount  = m_back_buffer_count;
		scd.OutputWindow = m_render_window;
		scd.Windowed     = !(fullscreen);
		scd.SwapEffect   = DXGI_SWAP_EFFECT_DISCARD;
		scd.Flags        = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH; //0;

		
		//--------------------------------
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
		// time the window is resized. So just call the resize method here to avoid code duplication.	
		resize_internal();

		create_render_state();
		set_primitive_topology();

		return true;
	}



	void resize_internal() {
		// Clear the previous window size specific context.
		m_device->OMSetRenderTargets(0, nullptr, nullptr);
		// Release the old views, as they hold references to the buffers we
		// will be destroying. Also release the old depth/stencil buffer.
		com_release(m_render_target_view);
		com_release(m_depth_stencil_view);
		com_release(m_depth_stencil_buffer);


		// Resize the swap chain and recreate the render target view.
		m_swap_chain->ResizeBuffers(m_back_buffer_count, m_client_width, m_client_height, m_back_buffer_format, 0);		
		ID3D10Texture2D* m_back_buffer = nullptr;
		//m_swap_chain->GetBuffer(0, __uuidof(ID3D10Texture2D), reinterpret_cast<void**>(&m_back_buffer));
		m_swap_chain->GetBuffer(0, IID_PPV_ARGS(&m_back_buffer));
		m_device->CreateRenderTargetView(m_back_buffer, nullptr, &m_render_target_view);
		com_release(m_back_buffer);

		
		// Create the depth/stencil buffer and view.
		D3D10_TEXTURE2D_DESC depth_stencil_desc = {};	
		depth_stencil_desc.Width     = m_client_width;
		depth_stencil_desc.Height    = m_client_height;
		depth_stencil_desc.MipLevels = 1;
		depth_stencil_desc.ArraySize = 1;
		depth_stencil_desc.Format    = m_depth_stencil_format;
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
		m_device->CreateDepthStencilView(m_depth_stencil_buffer, &depth_stencil_view_desc, &m_depth_stencil_view);

		// Bind the render target view and depth/stencil view to the pipeline.
		m_device->OMSetRenderTargets(1, &m_render_target_view, m_depth_stencil_view);
	

		// Set the viewport transform.
		D3D10_VIEWPORT vp = {};
		vp.TopLeftX = 0;
		vp.TopLeftY = 0;
		vp.Width    = m_client_width;
		vp.Height   = m_client_height;
		vp.MinDepth = D3D10_MIN_DEPTH; //0.0f;
		vp.MaxDepth = D3D10_MAX_DEPTH; //1.0f;
		m_device->RSSetViewports(1, &vp);

		//set_rs_anitialiasing();
		
		mat_proj = get_proj_matrix();
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

		m_device->CreateRasterizerState(&m_rs_desc, &m_rast_state);
	}

	void deinit_r() {
		if (m_device) { m_device->ClearState(); }
		com_release(m_depth_stencil_buffer);
		com_release(m_render_target_view);
		com_release(m_depth_stencil_view);
		com_release(m_swap_chain);		
		com_release(m_device);
		com_release(m_font);
		com_release(m_rast_state);
	}

	void setup() {}
	void cleanup() {}

	void render(float dt) {
		clear(gm::color4(0.0, 1.0, 0.0, 1.0));
	}

	void swap_buffers() {
		// Swap the back and front buffers.
		m_swap_chain->Present(0, 0);
	}
	//-----------------------
	void clear_render_target(const gm::color4& color_rgba) {
		//float clear_color[4] = {0.0f, 1.0f, 1.0f, 1.0f};
		//m_device->ClearRenderTargetView(m_render_target_view, clear_color);
		m_device->ClearRenderTargetView(m_render_target_view, color_rgba.data());
	}
	void clear_depth_stencil(bool clear_depth, bool clear_stencil, float depth, uint stencil) {
		uint clear_flag = 0;
		if (clear_depth) { clear_flag |= D3D10_CLEAR_DEPTH; }
		if (clear_stencil) { clear_flag |= D3D10_CLEAR_STENCIL; }    
		//m_device->ClearDepthStencilView(m_depth_stencil_view, D3D10_CLEAR_DEPTH|D3D10_CLEAR_STENCIL, 1.0f, 0);
		m_device->ClearDepthStencilView(m_depth_stencil_view, clear_flag, depth, stencil);
	}
	void clear(const gm::color4& color_rgba) {
		clear_render_target(color_rgba);
		clear_depth_stencil(true, true, 1.0f, 0);
	}

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
		m_device->CreateRasterizerState(&m_rs_desc, &m_rast_state);
		m_device->RSSetState(m_rast_state);
	}

	
	void reset_default_states() {
		// Restore default states, input layout and primitive topology because mFont->DrawText changes them. 
		// Note that we can restore the default states by passing null.
		m_device->OMSetDepthStencilState(nullptr, 0);
		float blendFactors[] = {0.0f, 0.0f, 0.0f, 0.0f};
		m_device->OMSetBlendState(nullptr, blendFactors, 0xffffffff);
		set_primitive_topology();
	}

	void set_primitive_topology() {
		m_device->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	}
};



#define D3D10_TEXTURES 1

class wm_rd3d10_tri : public wm_rd3d10 {
public:
	ID3D10InputLayout* m_input_layout = nullptr;

	ID3D10Buffer* model_vb = nullptr;
	ID3D10Buffer* model_ib = nullptr;		
	int64 model_num_vertices = 0;
	int64 model_num_indices = 0;

	ID3D10Effect* shader_fx = nullptr;
	ID3D10EffectTechnique* htech = nullptr;
	ID3D10EffectMatrixVariable* hmat_wvp = nullptr;

	gm::mat4 mat_world_model = gm::mat4::k_identity();

	ID3D10ShaderResourceView* tex = nullptr;
	ID3D10EffectShaderResourceVariable* htex = nullptr;


	void setup() {
		set_rs_culling(rs_cull_mode_e::cull_ccw);

	#if !D3D10_TEXTURES
		// Load Shaders.
		load_shaders_file(m_device, RS_SHADER_PATH("d3d10_vertex_pc.fx"), shader_fx);
		// Obtain handles.
		htech = shader_fx->GetTechniqueByName("shader_tech");	
		hmat_wvp = shader_fx->GetVariableByName("g_wvp")->AsMatrix();

		// Create vertex declaration for expressing the data layout. Conceptually, the vertex declaration is a way of 
		// programming the vertex direct memory access (DMA) and the tessellator engine of the graphics pipe.
		D3D10_INPUT_ELEMENT_DESC vertex_elements_pc[] =  {
			{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0,  0, D3D10_INPUT_PER_VERTEX_DATA, 0},
			{"COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0}
		};	
		D3D10_PASS_DESC PassDesc = {};
		htech->GetPassByIndex(0)->GetDesc(&PassDesc);
		m_device->CreateInputLayout(vertex_elements_pc, sdf::size(vertex_elements_pc), 
			PassDesc.pIAInputSignature, PassDesc.IAInputSignatureSize, &m_input_layout);


		// Load data to vector.
		sdr::vector<vertex_pc> vertices_vec;
		sdr::vector<uint> indices_vec;
		fill_triangle_vertex_pc(vertices_vec, indices_vec);

		model_num_vertices = vertices_vec.size();
		model_num_indices = indices_vec.size();

		// Create the vertex buffer. 
		create_vertex_buffer(m_device, vec_size_bytes(vertices_vec), vertices_vec.data(), model_vb);
	#else
		// Load Shaders.
		load_shaders_file(m_device, RS_SHADER_PATH("d3d10_vertex_pct.fx"), shader_fx);
		// Obtain handles.
		htech = shader_fx->GetTechniqueByName("shader_tech");	
		hmat_wvp = shader_fx->GetVariableByName("g_wvp")->AsMatrix();
		htex = shader_fx->GetVariableByName("g_tex")->AsShaderResource();

		// Create vertex declaration for expressing the data layout. Conceptually, the vertex declaration is a way of 
		// programming the vertex direct memory access (DMA) and the tessellator engine of the graphics pipe.
		D3D10_INPUT_ELEMENT_DESC vertex_elements_pct[] =  {
			{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0,  0, D3D10_INPUT_PER_VERTEX_DATA, 0},
			{"COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0},
			{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,		0, 28, D3D10_INPUT_PER_VERTEX_DATA, 0}
		};	
		D3D10_PASS_DESC PassDesc = {};
		htech->GetPassByIndex(0)->GetDesc(&PassDesc);
		m_device->CreateInputLayout(vertex_elements_pct, sdf::size(vertex_elements_pct), 
			PassDesc.pIAInputSignature, PassDesc.IAInputSignatureSize, &m_input_layout);


		// Load data to vector.
		sdr::vector<vertex_pct> vertices_vec;
		sdr::vector<uint> indices_vec;
		fill_triangle_vertex_pct(vertices_vec, indices_vec);

		model_num_vertices = vertices_vec.size();
		model_num_indices = indices_vec.size();

		// Create the vertex buffer. 
		create_vertex_buffer(m_device, vec_size_bytes(vertices_vec), vertices_vec.data(), model_vb);

		// Create the texture and set filters.
		create_texture(m_device, RS_MEDIA_PATH("crate1.jpg"), tex);
	#endif

		// Create the index buffer. 
		create_index_buffer(m_device, vec_size_bytes(indices_vec), indices_vec.data(), model_ib);

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);	


		// Set WVP matrices.
		set_world_matrix_tri1(mat_world_model);
		set_view_matrix_tri1(mat_view);
		set_proj_matrix_tri1(mat_proj, m_client_width, m_client_height);

		create_font(m_device, m_font);
	}

	void cleanup() {
		com_release(m_input_layout);
		com_release(model_vb);
		com_release(model_ib);		
		com_release(shader_fx);
		com_release(tex);
	}

	

	void render(float dt) {
		clear(k_clear_color);			

		gm::mat4 mat_wvp_temp = mat_world_model * mat_view * mat_proj;

		m_device->IASetInputLayout(m_input_layout);

	#if !D3D10_TEXTURES
		// Set vertex buffer
		UINT stride = sizeof(vertex_pc);
		UINT offset = 0;
		m_device->IASetVertexBuffers(0, 1, &model_vb, &stride, &offset);
	#else
		UINT stride = sizeof(vertex_pct);
		UINT offset = 0;
		m_device->IASetVertexBuffers(0, 1, &model_vb, &stride, &offset);
		htex->SetResource(tex);
	#endif

		// Set index buffer
		m_device->IASetIndexBuffer(model_ib, DXGI_FORMAT_R32_UINT, 0);


		// Begin passes.
		D3D10_TECHNIQUE_DESC techDesc = {};
		htech->GetDesc(&techDesc);
		for (UINT i = 0; i < techDesc.Passes; ++i) {
			htech->GetPassByIndex(i)->Apply(0);

			//hmat_wvp->SetMatrix(rcast<float*>(&mat_wvp_temp[0]));
			hmat_wvp->SetMatrix(mat_wvp_temp.data());

			// Draw one triangle.
			//m_device->Draw(model_num_indices, 0);
			m_device->DrawIndexed(model_num_indices, 0, 0);
		}

		draw_font(m_device, m_font, "Hello World");
		reset_default_states();
	}

};