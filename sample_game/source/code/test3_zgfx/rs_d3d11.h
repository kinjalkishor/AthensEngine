#pragma once

//------------------------------------
#include <d3d11.h>
#include <d3d11_4.h>
//#include <dxgi.h>
#include <dxgi1_6.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dxguid.lib")
// For using Windows Imaging Component (WIC)
#pragma comment(lib, "uuid.lib")
//#pragma comment(lib,"windowscodecs.lib")

// for compiling shader files, D3DCompileFromFile
#include <D3Dcompiler.h>
//#include <D3Dcommon.h>

#pragma comment(lib, "d3dcompiler.lib")


// For D3D11TextureLoader
////#include <wrl.h>
//#include <wrl/client.h>
//using Microsoft::WRL::ComPtr;
// For RoInitializeWrapper required for CreateWICTextureFromFile
//#pragma comment(lib, "runtimeobject.lib")

//=====================================
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXMath.h"
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXPackedVector.h"
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXColors.h"
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXCollision.h"

// For textures
#include "d3dxlib/TextureLoader/DDSTextureLoader11.h"
#include "d3dxlib/TextureLoader/WICTextureLoader11.h"
// Add DDSTextureLoader11.cpp to project also
//------------------------------------


#include "rs_irenderer.h"

inline bool compile_shader_from_file(const char* shader_filename, const char* sh_entry_point, const char* shader_model, ID3DBlob*& out_blob) {
  //  if (!shader_model) {
		//eprintfln("Null pointer passed.");
		//return false; 
		////return E_INVALIDARG;
  //  }

	//-----------
	if (!(is_file_exists(shader_filename))) {
		eprintfln("Cannot find shader file: %s", shader_filename);
		return false;
	}

	wchar_t shader_file_namew[MAX_PATH_OS] = {};
	sdf::strf_assign_mbs(shader_file_namew, sdf::strz_cap(shader_file_namew), shader_filename, sdf::strfz_len(shader_filename));	
	
	// Compile shader.
    UINT shader_flags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined(_DEBUG)
    // Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
    // Setting this flag improves the shader debugging experience, but still allows 
    // the shaders to be optimized and to run exactly the way they will run in 
    // the release configuration of this program.
    shader_flags |= D3DCOMPILE_DEBUG;
    // Disable optimizations to further improve shader debugging
    shader_flags |= D3DCOMPILE_SKIP_OPTIMIZATION;
#endif

    const D3D_SHADER_MACRO defines[] = {
		{"EXAMPLE_DEFINE", "1"},
		{nullptr, nullptr},
    };

    ID3DBlob* compilation_errors = nullptr;    
	HRESULT hr = S_OK;
    //hr = D3DCompileFromFile(shader_file_namew, nullptr, nullptr, sh_entry_point, shader_model, shader_flags, 0, &out_blob, &compilation_errors);
    hr = D3DCompileFromFile(shader_file_namew, defines, D3D_COMPILE_STANDARD_FILE_INCLUDE, 
		sh_entry_point, shader_model, shader_flags, 0, &out_blob, &compilation_errors);

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
        return false;
    }

	com_release(compilation_errors);
    return true;
}

inline void load_vertex_shader_file(ID3D11Device* m_device, const char* shader_filename, ID3DBlob*& shader_blob, ID3D11VertexShader*& vs_shader) {
	HRESULT hr = 0;
	bool success = false;
	success = compile_shader_from_file(shader_filename, "VS", "vs_5_0", shader_blob);
	hr = m_device->CreateVertexShader(shader_blob->GetBufferPointer(), shader_blob->GetBufferSize(), nullptr, &vs_shader);
	if (FAILED(hr)) { 
		printfln("CreateVertexShader failed"); 
	}
}

inline void load_pixel_shader_file(ID3D11Device* m_device, const char* shader_filename, ID3DBlob*& shader_blob, ID3D11PixelShader*& ps_shader) {
	HRESULT hr = 0;
	bool success = false;
	success = compile_shader_from_file(shader_filename, "PS", "ps_5_0", shader_blob);
	hr = m_device->CreatePixelShader(shader_blob->GetBufferPointer(), shader_blob->GetBufferSize(), nullptr, &ps_shader);		
	if (FAILED(hr)) { 
		printfln("CreatePixelShader failed"); 
	}
}


inline void load_shader_bytecode_file_to_blob(const char* shader_bytecode_filename, ID3DBlob*& out_blob) {
	wchar_t shader_bytecode_filenamew[MAX_PATH_OS] = {};
	sdf::strf_assign_mbs(shader_bytecode_filenamew, sdf::strz_cap(shader_bytecode_filenamew), 
		shader_bytecode_filename, sdf::strfz_len(shader_bytecode_filename));	

	HRESULT hr = S_OK;
	//sdr::vector<char> vs_shader_blob;
	//sdf::read_binary_file(vs_shader_blob, shader_bytecode_filename);
	//in.read((char*)vs_blob->GetBufferPointer(), vs_size);
	hr = D3DReadFileToBlob(shader_bytecode_filenamew, &out_blob);
}

inline void load_vertex_shader_bytecode(ID3D11Device* m_device, const char* shader_bytecode_filename, ID3DBlob*& shader_blob, ID3D11VertexShader*& vs_shader) {
	HRESULT hr = 0;
	bool success = false;
	//success = compile_shader_from_file(shader_filename, "VS", "vs_5_0", shader_blob);
	load_shader_bytecode_file_to_blob(shader_bytecode_filename, shader_blob);
	hr = m_device->CreateVertexShader(shader_blob->GetBufferPointer(), shader_blob->GetBufferSize(), nullptr, &vs_shader);
	if (FAILED(hr)) { 
		printfln("CreateVertexShader failed"); 
	}
}

inline void load_pixel_shader_bytecode(ID3D11Device* m_device, const char* shader_bytecode_filename, ID3DBlob*& shader_blob, ID3D11PixelShader*& ps_shader) {
	HRESULT hr = 0;
	bool success = false;
	//success = compile_shader_from_file(shader_filename, "PS", "ps_5_0", shader_blob);
	load_shader_bytecode_file_to_blob(shader_bytecode_filename, shader_blob);
	hr = m_device->CreatePixelShader(shader_blob->GetBufferPointer(), shader_blob->GetBufferSize(), nullptr, &ps_shader);		
	if (FAILED(hr)) { 
		printfln("CreatePixelShader failed"); 
	}
}

inline void load_vertex_shader_bytecode_or_file(ID3D11Device* m_device, const char* shader_bytecode_filename, const char* shader_filename, 
	ID3DBlob*& shader_blob, ID3D11VertexShader*& vs_shader) {
	if (is_file_exists(shader_bytecode_filename)) {
		load_vertex_shader_bytecode(m_device, shader_bytecode_filename, shader_blob, vs_shader);
	} else if (is_file_exists(shader_filename)) {
		load_vertex_shader_file(m_device, shader_filename, shader_blob, vs_shader);
	} else {
		eprintfln("Cannot find shader file: %s", shader_filename);
	}
}

inline void load_pixel_shader_bytecode_or_file(ID3D11Device* m_device, const char* shader_bytecode_filename, const char* shader_filename, 
	ID3DBlob*& shader_blob, ID3D11PixelShader*& ps_shader) {
	if (is_file_exists(shader_bytecode_filename)) {
		load_pixel_shader_bytecode(m_device, shader_bytecode_filename, shader_blob, ps_shader);
	} else if (is_file_exists(shader_filename)) {
		load_pixel_shader_file(m_device, shader_filename, shader_blob, ps_shader);
	} else {
		eprintfln("Cannot find shader file: %s", shader_filename);
	}
}
//------------------------------

inline void create_vertex_buffer(ID3D11Device* m_device, UINT vb_size_bytes, const void* sys_mem_data, ID3D11Buffer*& vb) {
	// Create the vertex buffer.
	//UINT vb_size_bytes = vertices_vec.size() * sizeof(vertex_type);
	D3D11_BUFFER_DESC vbd = {};
	vbd.ByteWidth = vb_size_bytes;
	vbd.Usage = D3D11_USAGE_DEFAULT; //D3D11_USAGE_IMMUTABLE;
	vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vbd.CPUAccessFlags = 0;
	vbd.MiscFlags = 0;
	vbd.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA vInitData = {};
	vInitData.pSysMem = sys_mem_data;
	m_device->CreateBuffer(&vbd, &vInitData, &vb);	
}

inline void create_index_buffer(ID3D11Device* m_device, UINT ib_size_bytes, const void* sys_mem_data, ID3D11Buffer*& ib) {
	// Create the index buffer. 
	//UINT ib_size_bytes = indices_vec.size() * sizeof(index_type_uint);
	D3D11_BUFFER_DESC ibd = {};
	ibd.ByteWidth = ib_size_bytes;
	ibd.Usage = D3D11_USAGE_DEFAULT; //D3D11_USAGE_IMMUTABLE;
    ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	ibd.CPUAccessFlags = 0;
	ibd.MiscFlags = 0;
	ibd.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA iInitData = {};
    iInitData.pSysMem = sys_mem_data;
    m_device->CreateBuffer(&ibd, &iInitData, &ib);	
}

inline void create_constant_buffer(ID3D11Device* m_device, UINT cb_size_bytes, ID3D11Buffer*& buffer) {
	// Create the constant buffer
	// Assert that the constant buffer remains 16-byte aligned.
	//static_assert((sizeof(cb_struct_mat4) % 16) == 0, "Constant Buffer size must be 16-byte aligned");
	fm_assert_m((cb_size_bytes % 16) == 0, "Constant Buffer size must be 16-byte aligned");
	//UINT cb_size_bytes = sizeof(cb_struct_mat4);
	D3D11_BUFFER_DESC cbd = {};
	cbd.ByteWidth = cb_size_bytes;
	cbd.Usage = D3D11_USAGE_DEFAULT;	    
	cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cbd.CPUAccessFlags = 0;
	cbd.MiscFlags = 0;
	cbd.StructureByteStride = 0;
    m_device->CreateBuffer(&cbd, nullptr, &buffer);        
}
inline void upload_constant_buffer(ID3D11DeviceContext* m_device_context, ID3D11Buffer* constant_buffers, UINT num_buffers, const void* src_data) {
	m_device_context->UpdateSubresource(constant_buffers, 0, nullptr, src_data, 0, 0);
	m_device_context->VSSetConstantBuffers(0, num_buffers, &constant_buffers);
}

inline void create_texture(ID3D11Device* m_device, const char* tex_file_name, ID3D11ShaderResourceView*& tex) {
	// Check if DDS texture.
	char filename_ext[8];
	get_filename_ext(filename_ext, tex_file_name);
	bool tex_is_dds = sdf::strfz_ci_equals(filename_ext, "dds");

	// Create texture.		
	wchar_t tex_file_namew[256] = {};
	sdf::strf_assign_mbs(tex_file_namew, sdf::strz_cap(tex_file_namew), tex_file_name, sdf::strfz_len(tex_file_name));

	if (tex_is_dds) {
		HRESULT hr = DirectX::CreateDDSTextureFromFile(m_device, tex_file_namew, nullptr,  &tex);
		if (FAILED(hr)) { eprintfln("DirectX::CreateDDSTextureFromFile: Cannot Load File: %s", tex_file_name); }
	} else {
		// The library assumes that the client code will have already called CoInitialize, CoInitializeEx,(UWP) or Windows::Foundation::Initialize 
		// (WIndows10 Desktop) as needed by the application before calling any Windows Imaging Component functionality.
		// For CreateWICTextureFromFile. Code runs without this also.
		//Microsoft::WRL::Wrappers::RoInitializeWrapper initialize(RO_INIT_MULTITHREADED);
		//if (FAILED(initialize)) {}
		HRESULT hr = DirectX::CreateWICTextureFromFile(m_device, tex_file_namew, nullptr,  &tex);
		if (FAILED(hr)) { eprintfln("DirectX::CreateWICTextureFromFile: Cannot Load File: %s", tex_file_name); }
	}
}


void create_sampler_state(ID3D11Device* m_device, ID3D11SamplerState*& sampler_state, rs_texture_filter_e filtering, int anisotropic_quality) {
	D3D11_SAMPLER_DESC samplerDesc = {};
	switch (filtering) {
		case rs_texture_filter_e::texf_bilinear: samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR; break;
		case rs_texture_filter_e::texf_anisotropic: samplerDesc.Filter = D3D11_FILTER_ANISOTROPIC; break;			
	}
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.MipLODBias = 0.0f;
	samplerDesc.MaxAnisotropy = anisotropic_quality;
	samplerDesc.ComparisonFunc = D3D11_COMPARISON_NEVER; //D3D11_COMPARISON_ALWAYS
	gm::color4 border_color(1.0f, 1.0f, 1.0f, 1.0f);
	for_range (i, 0, border_color.size()) { samplerDesc.BorderColor[i] = border_color[i]; }
	samplerDesc.MinLOD = 0.0f;
	samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;			
	m_device->CreateSamplerState(&samplerDesc, &sampler_state);
}

//-------------------------
class wm_rd3d11_fl : public wm_irenderer {
public:
	ID3D11Device* m_device = nullptr;
	ID3D11DeviceContext* m_device_context = nullptr;
	IDXGISwapChain* m_swap_chain = nullptr;
	ID3D11Texture2D* m_depth_stencil_buffer = nullptr;
	ID3D11RenderTargetView* m_render_target_view = nullptr;
	ID3D11DepthStencilView* m_depth_stencil_view = nullptr;

	UINT m_back_buffer_count = 1;

	bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { 
		set_init_params(hwnd, width, height, " : Direct3D11_fl");

		D3D_DRIVER_TYPE md3dDriverType = D3D_DRIVER_TYPE_HARDWARE;

		// Create the device and device context.
		UINT createDeviceFlags = 0;
	#if defined(DEBUG) || defined(_DEBUG)  
		createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
	#endif

		D3D_FEATURE_LEVEL featureLevel;
		HRESULT hr = D3D11CreateDevice(
				0,                 // default adapter
				md3dDriverType,
				0,                 // no software device
				createDeviceFlags, 
				0, 0,              // default feature level array
				D3D11_SDK_VERSION,
				&m_device,
				&featureLevel,
				&m_device_context);

		if (FAILED(hr)) {
			MessageBox(0, L"D3D11CreateDevice Failed.", 0, 0);
			return false;
		}

		if (featureLevel != D3D_FEATURE_LEVEL_11_0) {
			MessageBox(0, L"Direct3D Feature Level 11 unsupported.", 0, 0);
			return false;
		}

		// Fill out a DXGI_SWAP_CHAIN_DESC to describe our swap chain.
		DXGI_SWAP_CHAIN_DESC sd = {};
		sd.BufferDesc.Width  = m_client_width;
		sd.BufferDesc.Height = m_client_height;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

		sd.SampleDesc.Count   = curr_msaa_sample_count;
		sd.SampleDesc.Quality = curr_msaa_sample_quality;

		sd.BufferUsage  = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.BufferCount  = m_back_buffer_count;
		sd.OutputWindow = m_render_window;
		sd.Windowed     = !fullscreen;
		sd.SwapEffect   = DXGI_SWAP_EFFECT_DISCARD;
		sd.Flags        = 0;

		// To correctly create the swap chain, we must use the IDXGIFactory that was
		// used to create the device.  If we tried to use a different IDXGIFactory instance
		// (by calling CreateDXGIFactory), we get an error: "IDXGIFactory::CreateSwapChain: 
		// This function is being called with a device from a different IDXGIFactory."
		IDXGIDevice* dxgiDevice = nullptr;
		m_device->QueryInterface(__uuidof(IDXGIDevice), (void**)&dxgiDevice);
	      
		IDXGIAdapter* dxgiAdapter = nullptr;
		dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&dxgiAdapter);

		IDXGIFactory* dxgiFactory = nullptr;
		dxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&dxgiFactory);

		dxgiFactory->CreateSwapChain(m_device, &sd, &m_swap_chain);
	
		com_release(dxgiDevice);
		com_release(dxgiAdapter);
		com_release(dxgiFactory);

		// The remaining steps that need to be carried out for d3d creation
		// also need to be executed every time the window is resized. So
		// just call the OnResize method here to avoid code duplication.	
		resize_internal();

		return true;
	}	

	void resize_internal() {
		//assert(m_device_context);
		//assert(m_device);
		//assert(m_swap_chain);

		// Release the old views, as they hold references to the buffers we
		// will be destroying.  Also release the old depth/stencil buffer.
		com_release(m_render_target_view);
		com_release(m_depth_stencil_view);
		com_release(m_depth_stencil_buffer);


		// Resize the swap chain and recreate the render target view.
		m_swap_chain->ResizeBuffers(m_back_buffer_count, m_client_width, m_client_height, DXGI_FORMAT_R8G8B8A8_UNORM, 0);
		ID3D11Texture2D* backBuffer = nullptr;
		m_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer));
		m_device->CreateRenderTargetView(backBuffer, 0, &m_render_target_view);
		com_release(backBuffer);


		// Get back_buffer width and height. Use if needed.
		// If want to use back_buffer width and height.
		//int w, h;
		//D3D11_TEXTURE2D_DESC rt_back_buffer_desc = {};
		//m_back_buffer->GetDesc(&rt_back_buffer_desc);
		//w = rt_back_buffer_desc.Width;
		//h = rt_back_buffer_desc.Height;


		// Create the depth/stencil buffer and view.
		D3D11_TEXTURE2D_DESC depthStencilDesc = {};
	
		depthStencilDesc.Width     = m_client_width;
		depthStencilDesc.Height    = m_client_height;
		depthStencilDesc.MipLevels = 1;
		depthStencilDesc.ArraySize = 1;
		depthStencilDesc.Format    = DXGI_FORMAT_D24_UNORM_S8_UINT;

		depthStencilDesc.SampleDesc.Count   = curr_msaa_sample_count;
		depthStencilDesc.SampleDesc.Quality = curr_msaa_sample_quality;	

		depthStencilDesc.Usage          = D3D11_USAGE_DEFAULT;
		depthStencilDesc.BindFlags      = D3D11_BIND_DEPTH_STENCIL;
		depthStencilDesc.CPUAccessFlags = 0; 
		depthStencilDesc.MiscFlags      = 0;

		m_device->CreateTexture2D(&depthStencilDesc, nullptr, &m_depth_stencil_buffer);
		m_device->CreateDepthStencilView(m_depth_stencil_buffer, nullptr, &m_depth_stencil_view);


		// Bind the render target view and depth/stencil view to the pipeline.
		m_device_context->OMSetRenderTargets(1, &m_render_target_view, m_depth_stencil_view);
	

		// Set the viewport transform.
		D3D11_VIEWPORT mScreenViewport = {};
		mScreenViewport.TopLeftX = 0.0f;
		mScreenViewport.TopLeftY = 0.0f;
		mScreenViewport.Width    = static_cast<float>(m_client_width);
		mScreenViewport.Height   = static_cast<float>(m_client_height);
		mScreenViewport.MinDepth = 0.0f;
		mScreenViewport.MaxDepth = 1.0f;

		m_device_context->RSSetViewports(1, &mScreenViewport);

		mat_proj = get_proj_matrix();
	}

	void deinit_r() {
		// Restore all default settings.
		if (m_device_context) { m_device_context->ClearState(); }
		com_release(m_render_target_view);
		com_release(m_depth_stencil_view);
		com_release(m_swap_chain);
		com_release(m_depth_stencil_buffer);
		com_release(m_device_context);
		com_release(m_device);
	}

	void render(float dt) {
		m_device_context->ClearRenderTargetView(m_render_target_view, gm::color4(1.0, 0.0, 0.0, 1.0).data());
		m_device_context->ClearDepthStencilView(m_depth_stencil_view, D3D11_CLEAR_DEPTH|D3D11_CLEAR_STENCIL, 1.0f, 0);
	}
	void swap_buffers() {
		m_swap_chain->Present(0, 0);
	}
};

//-------------------------
// MS tutorials
class wm_rd3d11_dsc : public wm_irenderer {
public:	
	
	ID3D11Device*           m_device = nullptr;
	ID3D11DeviceContext*    m_device_context = nullptr;
	IDXGISwapChain*         m_swap_chain = nullptr;
	ID3D11RenderTargetView* m_render_target_view = nullptr;
	ID3D11DepthStencilView* m_depth_stencil_view = nullptr;

	bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { 
		set_init_params(hwnd, width, height, " : Direct3D11_dsc");

		D3D_DRIVER_TYPE g_driverType = D3D_DRIVER_TYPE_HARDWARE;

		UINT createDeviceFlags = 0;
	#ifdef _DEBUG
		createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
	#endif

		D3D_DRIVER_TYPE driverTypes[] = {
			D3D_DRIVER_TYPE_HARDWARE,
			D3D_DRIVER_TYPE_WARP,
			D3D_DRIVER_TYPE_REFERENCE,
		};
		UINT numDriverTypes = sdf::size(driverTypes);

		D3D_FEATURE_LEVEL feature_level = D3D_FEATURE_LEVEL_11_0;
		D3D_FEATURE_LEVEL featureLevels[] = {
			D3D_FEATURE_LEVEL_11_0,
			D3D_FEATURE_LEVEL_10_1,
			D3D_FEATURE_LEVEL_10_0,
		};
		UINT numFeatureLevels = sdf::size(featureLevels);

		DXGI_SWAP_CHAIN_DESC sd = {};
		ZeroMemory(&sd, sizeof(sd));
		sd.BufferCount = 1;
		sd.BufferDesc.Width = m_client_width;
		sd.BufferDesc.Height = m_client_height;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.OutputWindow = m_render_window;
		sd.SampleDesc.Count = curr_msaa_sample_count;
		sd.SampleDesc.Quality = curr_msaa_sample_quality;
		sd.Windowed = !fullscreen;

		HRESULT hr = S_OK;
		for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++) {
			g_driverType = driverTypes[driverTypeIndex];
			hr = D3D11CreateDeviceAndSwapChain(nullptr, g_driverType, nullptr, createDeviceFlags, featureLevels, numFeatureLevels,
					D3D11_SDK_VERSION, &sd, &m_swap_chain, &m_device, &feature_level, &m_device_context);
			if (SUCCEEDED(hr)) {
				break;
			}
		}
		if (FAILED(hr)) { return false; }

		// Create a render target view
		ID3D11Texture2D* pBackBuffer = nullptr;
		hr = m_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
		if (FAILED(hr)) { return false; }

		hr = m_device->CreateRenderTargetView(pBackBuffer, nullptr, &m_render_target_view);
		pBackBuffer->Release();
		if (FAILED(hr)) { return false; }

		m_device_context->OMSetRenderTargets(1, &m_render_target_view, nullptr);

		// Setup the viewport
		D3D11_VIEWPORT vp = {};
		vp.Width = (float)m_client_width;
		vp.Height = (float)m_client_height;
		vp.MinDepth = 0.0f;
		vp.MaxDepth = 1.0f;
		vp.TopLeftX = 0;
		vp.TopLeftY = 0;
		m_device_context->RSSetViewports(1, &vp);

		resize_internal();

		return true;
	}

	void deinit_r() {
		// Restore all default settings.
		if (m_device_context) { m_device_context->ClearState(); }
		com_release(m_render_target_view);
		com_release(m_depth_stencil_view);
		com_release(m_swap_chain);
		//com_release(m_depth_stencil_buffer);
		com_release(m_device_context);
		com_release(m_device);
	}


	void resize_internal() {
		mat_proj = get_proj_matrix();
	}

	void render(float dt) {
		m_device_context->ClearRenderTargetView(m_render_target_view, gm::color4(1.0, 0.0, 0.0, 1.0).data());
		m_device_context->ClearDepthStencilView(m_depth_stencil_view, D3D11_CLEAR_DEPTH|D3D11_CLEAR_STENCIL, 1.0f, 0);
	}
	void swap_buffers() {
		m_swap_chain->Present(0, 0);
	}
};


//-------------------------
#include <wrl.h>
//#include <wrl/client.h>
using Microsoft::WRL::ComPtr;
class wm_rd3d11_wrl : public wm_irenderer {
public:

	//-------------
	//ID3D11Device* m_device = nullptr;
	//ID3D11DeviceContext* m_device_context = nullptr;
	//IDXGISwapChain* m_swap_chain = nullptr;

	ComPtr<ID3D11Device5> m_device;
	ComPtr<ID3D11DeviceContext4> m_device_context;
	ComPtr<IDXGISwapChain4> m_swap_chain;
	//---
	
	ComPtr<ID3D11Texture2D> m_depth_stencil_buffer;

	ComPtr<ID3D11RenderTargetView> m_render_target_view;
	ComPtr<ID3D11DepthStencilView> m_depth_stencil_view;


	//-------------
	//ID3D11RenderTargetView1* m_render_target_view = nullptr; //pointer to back buffer
	//ID3D11RenderTargetView*  m_render_target_view0 = nullptr;

	
	//---
	// In full-screen mode, there is a dedicated front buffer; in windowed mode, the desktop is the front buffer.
	// If you create a swap chain with one buffer, specifying DXGI_SWAP_EFFECT_SEQUENTIAL does not cause the contents 
	// of the single buffer to be swapped with the front buffer.
	//2 for DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL else 1;
	UINT m_back_buffer_count = 1;

	DXGI_FORMAT m_back_buffer_format = DXGI_FORMAT_R8G8B8A8_UNORM;	//DXGI_FORMAT_B8G8R8A8_UNORM;
	DXGI_FORMAT m_depth_stencil_format = DXGI_FORMAT_D24_UNORM_S8_UINT;

	D3D11_RASTERIZER_DESC m_rs_desc = {};
	ComPtr<ID3D11RasterizerState> m_rast_state;
	
	//ID3D11SamplerState* m_sampler_anisotropic = nullptr;


	bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { 
		set_init_params(hwnd, width, height, " : Direct3D11");

		D3D_DRIVER_TYPE md3dDriverType = D3D_DRIVER_TYPE_HARDWARE;

		// Create the device and device context.
		UINT device_flags = 0;
    #if defined(DEBUG) || defined(_DEBUG)  
		device_flags |= D3D11_CREATE_DEVICE_DEBUG;
	#endif
		// This flag adds support for surfaces with a color-channel ordering different
        // from the API default. This is required to interop with Direct2D/DirectWrite.
        device_flags |= D3D11_CREATE_DEVICE_BGRA_SUPPORT;

		D3D_FEATURE_LEVEL curr_featureLevel;
		static const D3D_FEATURE_LEVEL feature_levels_arr [] = {
            D3D_FEATURE_LEVEL_11_1,
        };    
		UINT num_feature_levels_arr = scast<UINT>(sdf::size(feature_levels_arr));

		//------------
		ComPtr<ID3D11Device> temp_device0;
        ComPtr<ID3D11DeviceContext> temp_device_context0;

		HRESULT hr = S_OK;
		hr = D3D11CreateDevice(
				nullptr,					// default adapter
				md3dDriverType,
				nullptr,					// no software device
				device_flags, 
				feature_levels_arr, 
				num_feature_levels_arr,		// default feature level array
				D3D11_SDK_VERSION,
				&temp_device0,
				&curr_featureLevel,
				temp_device_context0.GetAddressOf());


		if (FAILED(hr)) {
			//-com_release(temp_device_context0);
			//-com_release(temp_device0);					
			eprintfln("D3D11CreateDevice Failed.");
			return false;
		}

		if (curr_featureLevel != D3D_FEATURE_LEVEL_11_1) {
			//-com_release(temp_device_context0);
			//-com_release(temp_device0);	
			eprintfln("Direct3D Feature Level 11.1 unsupported.");
			return false;
		}


		// Create Swap chain.
		// Set or cast current device & device_context from temp_device & temp_device_context.
		// Same device type as temp_device D3D 11.0
		//m_device = temp_device0;
		//m_device_context = temp_device_context0;
		// For device types higher than temp_device D3D 11.0 (11.1 onwards)
		//temp_device0->QueryInterface(IID_PPV_ARGS(&m_device));
		temp_device0.As(&m_device);
		//temp_device_context0->QueryInterface(IID_PPV_ARGS(&m_device_context));
		temp_device_context0.As(&m_device_context);
		temp_device0.Reset();
		temp_device_context0.Reset();

		//------------
		// To correctly create the swap chain, we must use the IDXGIFactory that was
		// used to create the device. If we tried to use a different IDXGIFactory instance
		// (by calling CreateDXGIFactory), we get an error: "IDXGIFactory::CreateSwapChain: 
		// This function is being called with a device from a different IDXGIFactory."
		// Retrieve the underlying DXGI Device from the D3D Device.
		//IDXGIDevice* dxgiDevice = nullptr;
		ComPtr<IDXGIDevice4> dxgiDevice;
		//m_device->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&dxgiDevice));	      
		//m_device->QueryInterface(IID_PPV_ARGS(&dxgiDevice));	
		m_device.As(&dxgiDevice);	
		// Identify the physical adapter (GPU or card) this device is running on.
		//IDXGIAdapter* dxgiAdapter = nullptr;
		ComPtr<IDXGIAdapter4> dxgiAdapter;
		// GetAdapter func can be called instead of Get Parent for same result. Doesn't take IDXGIAdapter4* ptr.
		////dxgiDevice->GetAdapter(&dxgiAdapter);
		//dxgiDevice->GetParent(__uuidof(IDXGIAdapter), reinterpret_cast<void**>(&dxgiAdapter));
		dxgiDevice->GetParent(IID_PPV_ARGS(&dxgiAdapter));
		// Obtain the factory object that created it.
		//IDXGIFactory* dxgiFactory = nullptr;
		ComPtr<IDXGIFactory7> dxgiFactory;
		//dxgiAdapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&dxgiFactory));
		dxgiAdapter->GetParent(IID_PPV_ARGS(&dxgiFactory));


		//--------------------------------
		// SwapChain1
		// Create a descriptor for the swap chain.
        DXGI_SWAP_CHAIN_DESC1 scd1 = {};
        scd1.Width = m_client_width;
        scd1.Height = m_client_height;
        scd1.Format = m_back_buffer_format;
        scd1.Stereo = FALSE;
        scd1.SampleDesc.Count = curr_msaa_sample_count;
        scd1.SampleDesc.Quality = curr_msaa_sample_quality;
        scd1.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;		
        scd1.BufferCount = m_back_buffer_count;
        scd1.Scaling = DXGI_SCALING_STRETCH;
        scd1.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;	
        scd1.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
        scd1.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;    // allow full-screen switching	

        DXGI_SWAP_CHAIN_FULLSCREEN_DESC scd1_fs = {};
        scd1_fs.RefreshRate.Numerator = 60;
        scd1_fs.RefreshRate.Denominator = 1;
        scd1_fs.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
        scd1_fs.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
        scd1_fs.Windowed = !(fullscreen);


		ComPtr<IDXGISwapChain1> swapChain1;
        // Create a SwapChain from a Win32 window.
        hr = dxgiFactory->CreateSwapChainForHwnd(
            m_device.Get(),
            m_render_window,
            &scd1,
            &scd1_fs,
            nullptr,
			&swapChain1
			);

		if (FAILED(hr)) {			
			if (m_device_context) { m_device_context->ClearState(); }
			//-com_release(m_swap_chain);	
			//-com_release(m_device_context);
			//-com_release(m_device);	
			eprintfln("Cannot Create D3D11 SwapChain.");
			return false;
		}	

		//swapChain1->QueryInterface(IID_PPV_ARGS(&m_swap_chain));
		swapChain1.As(&m_swap_chain);


		//--------------------------------
		//-com_release(dxgiDevice);
		//-com_release(dxgiAdapter);
		//-com_release(dxgiFactory);

		//---
		// Do not support exclusive fullscreen mode and prevent DXGI from responding to the
		// ALT+ENTER shortcut by blocking it.
		//dxgiFactory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_ALT_ENTER);

		// The remaining steps that need to be carried out for d3d creation also need to be executed every
		//  time the window is resized. So just call the onResize method here to avoid code duplication.	
		resize_internal();

		create_render_state();
		set_primitive_topology();

		return true;
	}


	void resize_internal() {
		//if (m_swap_chain) {

		// Clear the previous window size specific context.
		m_device_context->OMSetRenderTargets(0, nullptr, nullptr);
		// Release the old views, as they hold references to the swap chain's buffers we
		// will be destroying. Also release the old depth/stencil buffer.		
		m_render_target_view.Reset();
		//-com_release(m_back_buffer);
		m_depth_stencil_view.Reset();
		m_depth_stencil_buffer.Reset();
		// After releasing references to these resources, we need to call Flush() to ensure that Direct3D also 
		// releases any references it might still have to the same resources - such as pipeline bindings.
		//-m_device_context->Flush();		


		// Preserve the existing buffer count, width, height and format.
		// Set BufferCount to 0 to preserve the existing setting. 
		// Automatically choose the width and height to match the client rect for HWNDs.
		// Width and height of the swap chain, set to 0 to match the screen resolution.
		// DXGI_FORMAT_UNKNOWN tells DXGI to retain the current back buffer format.        
        ////m_swap_chain->ResizeBuffers(0, 0, 0, DXGI_FORMAT_UNKNOWN, 0);

		// Resize the swap chain and recreate the render target view.
		m_swap_chain->ResizeBuffers(m_back_buffer_count, m_client_width, m_client_height, m_back_buffer_format, 0);

		//} 
		// TO_CHECK: If the swap chain already exists, resize it, otherwise create one. For fullscreen maybe.
		//else { create_swap_chain(); }

		//------------
		// A swap chain is present or created at this point.
		// Obtain the backbuffer for this window which will be the final 3D rendertarget.
		ComPtr<ID3D11Texture2D> m_back_buffer;
		//m_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&m_back_buffer))
		m_swap_chain->GetBuffer(0, IID_PPV_ARGS(&m_back_buffer));
		m_device->CreateRenderTargetView(m_back_buffer.Get(), nullptr, m_render_target_view.GetAddressOf());
		//-com_release(m_back_buffer);


		// Get back_buffer width and height. Use if needed.
		// If want to use back_buffer width and height.
		//int w, h;
		//D3D11_TEXTURE2D_DESC rt_back_buffer_desc = {};
		//m_back_buffer->GetDesc(&rt_back_buffer_desc);
		//w = rt_back_buffer_desc.Width;
		//h = rt_back_buffer_desc.Height;

		
		// Create the depth/stencil buffer and view.
		D3D11_TEXTURE2D_DESC depth_stencil_desc = {};	
		depth_stencil_desc.Width     = m_client_width;
		depth_stencil_desc.Height    = m_client_height;
		depth_stencil_desc.MipLevels = 1;	// mipLevels: Use a single mipmap level.
		depth_stencil_desc.ArraySize = 1;	// arraySize: This depth stencil view has only one texture.
		depth_stencil_desc.Format    = m_depth_stencil_format;
		// Must match swap chain MSAA values. 
		depth_stencil_desc.SampleDesc.Count   = curr_msaa_sample_count;
		depth_stencil_desc.SampleDesc.Quality = curr_msaa_sample_quality;
		depth_stencil_desc.Usage          = D3D11_USAGE_DEFAULT;
		depth_stencil_desc.BindFlags      = D3D11_BIND_DEPTH_STENCIL;
		depth_stencil_desc.CPUAccessFlags = 0; 
		depth_stencil_desc.MiscFlags      = 0;
		m_device->CreateTexture2D(&depth_stencil_desc, nullptr, &m_depth_stencil_buffer);

		// Create the depth stencil view
		D3D11_DEPTH_STENCIL_VIEW_DESC depth_stencil_view_desc = {};
        depth_stencil_view_desc.Format = depth_stencil_desc.Format;
        depth_stencil_view_desc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		depth_stencil_view_desc.Flags = 0; //0 for not read only
        depth_stencil_view_desc.Texture2D.MipSlice = 0;
		m_device->CreateDepthStencilView(m_depth_stencil_buffer.Get(), &depth_stencil_view_desc, &m_depth_stencil_view);
		////m_device->CreateDepthStencilView(m_depth_stencil_buffer, nullptr, &m_depth_stencil);


		// Bind the render target view and depth/stencil view to the pipeline.
		m_device_context->OMSetRenderTargets(1, m_render_target_view.GetAddressOf(), m_depth_stencil_view.Get());
		//m_device_context->OMSetRenderTargets(1, &m_render_target_view0, m_depth_stencil_view);
		//m_render_target0.As(&m_render_target_view);

		//------------
		// Set the viewport transform.
		D3D11_VIEWPORT vp = {};
		vp.TopLeftX = 0.0f;
		vp.TopLeftY = 0.0f;
		vp.Width    = scast<float>(m_client_width);		//scast<float>(rt_back_buffer_desc.Width);
		vp.Height   = scast<float>(m_client_height);		//scast<float>(rt_back_buffer_desc.Height);
		vp.MinDepth = D3D11_MIN_DEPTH;			//0.0f;
		vp.MaxDepth = D3D11_MAX_DEPTH;			//1.0f;
		m_device_context->RSSetViewports(1, &vp);


		//set_rs_anitialiasing();
		
		mat_proj = get_proj_matrix();
	}

	void create_render_state() {
		m_rs_desc.FillMode = D3D11_FILL_SOLID;
        m_rs_desc.CullMode = D3D11_CULL_BACK;	//CCW with FrontCounterClockwise = false.
        m_rs_desc.FrontCounterClockwise = FALSE;
        m_rs_desc.DepthBias = D3D11_DEFAULT_DEPTH_BIAS;
        m_rs_desc.DepthBiasClamp = D3D11_DEFAULT_DEPTH_BIAS_CLAMP;
        m_rs_desc.SlopeScaledDepthBias = D3D11_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;
        m_rs_desc.DepthClipEnable = TRUE;
        m_rs_desc.ScissorEnable = FALSE;
        m_rs_desc.MultisampleEnable = msaa_enabled;	//FALSE;
        m_rs_desc.AntialiasedLineEnable = FALSE;

		m_device->CreateRasterizerState(&m_rs_desc, &m_rast_state);
	}

	void deinit_r() {		
		if (m_device_context) { m_device_context->ClearState(); }
		//-com_release(m_depth_stencil_buffer);
		//-com_release(m_render_target_view);
		//-com_release(m_depth_stencil_view);
		//-com_release(m_swap_chain);			
		//-com_release(m_device_context);
		//-com_release(m_device);
		//-com_release(m_rast_state);
	}

	void setup() {}
	void cleanup() {}

	void render(float dt) {
		m_device_context->ClearRenderTargetView(m_render_target_view.Get(), gm::color4(1.0, 0.0, 0.0, 1.0).data());
		m_device_context->ClearDepthStencilView(m_depth_stencil_view.Get(), D3D11_CLEAR_DEPTH|D3D11_CLEAR_STENCIL, 1.0f, 0);
	}

	void swap_buffers() {
		m_swap_chain->Present(0, 0);
	}	

	void set_primitive_topology() {
		m_device_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	}
};


//--------------------------
class wm_rd3d11 : public wm_irenderer {
public:

	//-------------
	//ID3D11Device* m_device = nullptr;
	//ID3D11DeviceContext* m_device_context = nullptr;
	//IDXGISwapChain* m_swap_chain = nullptr;

	ID3D11Device5* m_device = nullptr;
	ID3D11DeviceContext4* m_device_context = nullptr;
	IDXGISwapChain4* m_swap_chain = nullptr;
	//---
	
	ID3D11Texture2D* m_depth_stencil_buffer = nullptr;

	ID3D11RenderTargetView* m_render_target_view = nullptr;
	ID3D11DepthStencilView* m_depth_stencil_view = nullptr;		


	//-------------
	//ID3D11RenderTargetView1* m_render_target_view = nullptr; //pointer to back buffer
	//ID3D11RenderTargetView*  m_render_target_view0 = nullptr;

	
	//---
	// In full-screen mode, there is a dedicated front buffer; in windowed mode, the desktop is the front buffer.
	// If you create a swap chain with one buffer, specifying DXGI_SWAP_EFFECT_SEQUENTIAL does not cause the contents 
	// of the single buffer to be swapped with the front buffer.
	//2 for DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL else 1;
	UINT m_back_buffer_count = 1;

	DXGI_FORMAT m_back_buffer_format = DXGI_FORMAT_R8G8B8A8_UNORM;	//DXGI_FORMAT_B8G8R8A8_UNORM;
	DXGI_FORMAT m_depth_stencil_format = DXGI_FORMAT_D24_UNORM_S8_UINT;

	D3D11_RASTERIZER_DESC m_rs_desc = {};
	ID3D11RasterizerState* m_rast_state = nullptr;	
	
	ID3D11SamplerState* m_sampler_anisotropic = nullptr;


	bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { 
		set_init_params(hwnd, width, height, " : Direct3D11");

		D3D_DRIVER_TYPE md3dDriverType = D3D_DRIVER_TYPE_HARDWARE;

		// Create the device and device context.
		UINT device_flags = 0;
    #if defined(DEBUG) || defined(_DEBUG)  
		device_flags |= D3D11_CREATE_DEVICE_DEBUG;
	#endif
		// This flag adds support for surfaces with a color-channel ordering different
        // from the API default. This is required to interop with Direct2D/DirectWrite.
        device_flags |= D3D11_CREATE_DEVICE_BGRA_SUPPORT;

		D3D_FEATURE_LEVEL curr_featureLevel;
		static const D3D_FEATURE_LEVEL feature_levels_arr [] = {
            D3D_FEATURE_LEVEL_11_1,
        };    
		UINT num_feature_levels_arr = scast<UINT>(sdf::size(feature_levels_arr));

		//------------
		ID3D11Device* temp_device0 = nullptr;
        ID3D11DeviceContext* temp_device_context0 = nullptr;

		HRESULT hr = S_OK;
		hr = D3D11CreateDevice(
				nullptr,					// default adapter
				md3dDriverType,
				nullptr,					// no software device
				device_flags, 
				feature_levels_arr, 
				num_feature_levels_arr,		// default feature level array
				D3D11_SDK_VERSION,
				&temp_device0,
				&curr_featureLevel,
				&temp_device_context0);


		if (FAILED(hr)) {
			com_release(temp_device_context0);
			com_release(temp_device0);					
			eprintfln("D3D11CreateDevice Failed.");
			return false;
		}

		if (curr_featureLevel != D3D_FEATURE_LEVEL_11_1) {
			com_release(temp_device_context0);
			com_release(temp_device0);	
			eprintfln("Direct3D Feature Level 11.1 unsupported.");
			return false;
		}


		// Create Swap chain.
		// Set or cast current device & device_context from temp_device & temp_device_context.
		// Same device type as temp_device D3D 11.0
		//m_device = temp_device0;
		//m_device_context = temp_device_context0;
		// For device types higher than temp_device D3D 11.0 (11.1 onwards)
		temp_device0->QueryInterface(IID_PPV_ARGS(&m_device));
		temp_device_context0->QueryInterface(IID_PPV_ARGS(&m_device_context));
		temp_device0 = nullptr;
		temp_device_context0 = nullptr;

		//------------
		// To correctly create the swap chain, we must use the IDXGIFactory that was
		// used to create the device. If we tried to use a different IDXGIFactory instance
		// (by calling CreateDXGIFactory), we get an error: "IDXGIFactory::CreateSwapChain: 
		// This function is being called with a device from a different IDXGIFactory."
		// Retrieve the underlying DXGI Device from the D3D Device.
		//IDXGIDevice* dxgiDevice = nullptr;
		IDXGIDevice4* dxgiDevice = nullptr;
		//m_device->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&dxgiDevice));	      
		m_device->QueryInterface(IID_PPV_ARGS(&dxgiDevice));	
		// Identify the physical adapter (GPU or card) this device is running on.
		//IDXGIAdapter* dxgiAdapter = nullptr;
		IDXGIAdapter4* dxgiAdapter = nullptr;
		// GetAdapter func can be called instead of Get Parent for same result. Doesn't take IDXGIAdapter4* ptr.
		////dxgiDevice->GetAdapter(&dxgiAdapter);
		//dxgiDevice->GetParent(__uuidof(IDXGIAdapter), reinterpret_cast<void**>(&dxgiAdapter));
		dxgiDevice->GetParent(IID_PPV_ARGS(&dxgiAdapter));
		// Obtain the factory object that created it.
		//IDXGIFactory* dxgiFactory = nullptr;
		IDXGIFactory7* dxgiFactory = nullptr;
		//dxgiAdapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&dxgiFactory));
		dxgiAdapter->GetParent(IID_PPV_ARGS(&dxgiFactory));


		//--------------------------------
		// SwapChain1
		// Create a descriptor for the swap chain.
        DXGI_SWAP_CHAIN_DESC1 scd1 = {};
        scd1.Width = m_client_width;
        scd1.Height = m_client_height;
        scd1.Format = m_back_buffer_format;
        scd1.Stereo = FALSE;
        scd1.SampleDesc.Count = curr_msaa_sample_count;
        scd1.SampleDesc.Quality = curr_msaa_sample_quality;
        scd1.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;		
        scd1.BufferCount = m_back_buffer_count;
        scd1.Scaling = DXGI_SCALING_STRETCH;
        scd1.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;	
        scd1.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
        scd1.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;    // allow full-screen switching	

        DXGI_SWAP_CHAIN_FULLSCREEN_DESC scd1_fs = {};
        scd1_fs.RefreshRate.Numerator = 60;
        scd1_fs.RefreshRate.Denominator = 1;
        scd1_fs.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
        scd1_fs.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
        scd1_fs.Windowed = !(fullscreen);


		IDXGISwapChain1* swapChain1 = nullptr;
        // Create a SwapChain from a Win32 window.
        hr = dxgiFactory->CreateSwapChainForHwnd(
            m_device,
            m_render_window,
            &scd1,
            &scd1_fs,
            nullptr,
			&swapChain1
			);

		if (FAILED(hr)) {			
			if (m_device_context) { m_device_context->ClearState(); }
			com_release(m_swap_chain);	
			com_release(m_device_context);
			com_release(m_device);	
			eprintfln("Cannot Create D3D11 SwapChain.");
			return false;
		}	

		swapChain1->QueryInterface(IID_PPV_ARGS(&m_swap_chain));


		//--------------------------------
		com_release(dxgiDevice);
		com_release(dxgiAdapter);
		com_release(dxgiFactory);

		//---
		// Do not support exclusive fullscreen mode and prevent DXGI from responding to the
		// ALT+ENTER shortcut by blocking it.
		//dxgiFactory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_ALT_ENTER);

		// The remaining steps that need to be carried out for d3d creation also need to be executed every
		//  time the window is resized. So just call the onResize method here to avoid code duplication.	
		resize_internal();

		create_render_state();
		set_primitive_topology();

		return true;
	}


	void resize_internal() {
		//if (m_swap_chain) {

		// Clear the previous window size specific context.
		m_device_context->OMSetRenderTargets(0, nullptr, nullptr);
		// Release the old views, as they hold references to the swap chain's buffers we
		// will be destroying. Also release the old depth/stencil buffer.		
		com_release(m_render_target_view);
		//-com_release(m_back_buffer);
		com_release(m_depth_stencil_view);
		com_release(m_depth_stencil_buffer);
		// After releasing references to these resources, we need to call Flush() to ensure that Direct3D also 
		// releases any references it might still have to the same resources - such as pipeline bindings.
		//-m_device_context->Flush();		


		// Preserve the existing buffer count, width, height and format.
		// Set BufferCount to 0 to preserve the existing setting. 
		// Automatically choose the width and height to match the client rect for HWNDs.
		// Width and height of the swap chain, set to 0 to match the screen resolution.
		// DXGI_FORMAT_UNKNOWN tells DXGI to retain the current back buffer format.        
        ////m_swap_chain->ResizeBuffers(0, 0, 0, DXGI_FORMAT_UNKNOWN, 0);

		// Resize the swap chain and recreate the render target view.
		m_swap_chain->ResizeBuffers(m_back_buffer_count, m_client_width, m_client_height, m_back_buffer_format, 0);

		//} 
		// TO_CHECK: If the swap chain already exists, resize it, otherwise create one. For fullscreen maybe.
		//else { create_swap_chain(); }

		//------------
		// A swap chain is present or created at this point.
		// Obtain the backbuffer for this window which will be the final 3D rendertarget.
		ID3D11Texture2D* m_back_buffer = nullptr;
		//m_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&m_back_buffer))
		m_swap_chain->GetBuffer(0, IID_PPV_ARGS(&m_back_buffer));
		m_device->CreateRenderTargetView(m_back_buffer, nullptr, &m_render_target_view);
		com_release(m_back_buffer);


		// Get back_buffer width and height. Use if needed.
		// If want to use back_buffer width and height.
		//int w, h;
		//D3D11_TEXTURE2D_DESC rt_back_buffer_desc = {};
		//m_back_buffer->GetDesc(&rt_back_buffer_desc);
		//w = rt_back_buffer_desc.Width;
		//h = rt_back_buffer_desc.Height;

		
		// Create the depth/stencil buffer and view.
		D3D11_TEXTURE2D_DESC depth_stencil_desc = {};	
		depth_stencil_desc.Width     = m_client_width;
		depth_stencil_desc.Height    = m_client_height;
		depth_stencil_desc.MipLevels = 1;	// mipLevels: Use a single mipmap level.
		depth_stencil_desc.ArraySize = 1;	// arraySize: This depth stencil view has only one texture.
		depth_stencil_desc.Format    = m_depth_stencil_format;
		// Must match swap chain MSAA values. 
		depth_stencil_desc.SampleDesc.Count   = curr_msaa_sample_count;
		depth_stencil_desc.SampleDesc.Quality = curr_msaa_sample_quality;
		depth_stencil_desc.Usage          = D3D11_USAGE_DEFAULT;
		depth_stencil_desc.BindFlags      = D3D11_BIND_DEPTH_STENCIL;
		depth_stencil_desc.CPUAccessFlags = 0; 
		depth_stencil_desc.MiscFlags      = 0;
		m_device->CreateTexture2D(&depth_stencil_desc, nullptr, &m_depth_stencil_buffer);

		// Create the depth stencil view
		D3D11_DEPTH_STENCIL_VIEW_DESC depth_stencil_view_desc = {};
        depth_stencil_view_desc.Format = depth_stencil_desc.Format;
        depth_stencil_view_desc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		depth_stencil_view_desc.Flags = 0; //0 for not read only
        depth_stencil_view_desc.Texture2D.MipSlice = 0;
		m_device->CreateDepthStencilView(m_depth_stencil_buffer, &depth_stencil_view_desc, &m_depth_stencil_view);
		////m_device->CreateDepthStencilView(m_depth_stencil_buffer, nullptr, &m_depth_stencil);


		// Bind the render target view and depth/stencil view to the pipeline.
		m_device_context->OMSetRenderTargets(1, &m_render_target_view, m_depth_stencil_view);
		//m_device_context->OMSetRenderTargets(1, &m_render_target_view0, m_depth_stencil_view);
		//m_render_target0.As(&m_render_target_view);

		//------------
		// Set the viewport transform.
		D3D11_VIEWPORT vp = {};
		vp.TopLeftX = 0.0f;
		vp.TopLeftY = 0.0f;
		vp.Width    = scast<float>(m_client_width);		//scast<float>(rt_back_buffer_desc.Width);
		vp.Height   = scast<float>(m_client_height);		//scast<float>(rt_back_buffer_desc.Height);
		vp.MinDepth = D3D11_MIN_DEPTH;			//0.0f;
		vp.MaxDepth = D3D11_MAX_DEPTH;			//1.0f;
		m_device_context->RSSetViewports(1, &vp);


		//set_rs_anitialiasing();
		
		mat_proj = get_proj_matrix();
	}

	void create_render_state() {
		m_rs_desc.FillMode = D3D11_FILL_SOLID;
        m_rs_desc.CullMode = D3D11_CULL_BACK;	//CCW with FrontCounterClockwise = false.
        m_rs_desc.FrontCounterClockwise = FALSE;
        m_rs_desc.DepthBias = D3D11_DEFAULT_DEPTH_BIAS;
        m_rs_desc.DepthBiasClamp = D3D11_DEFAULT_DEPTH_BIAS_CLAMP;
        m_rs_desc.SlopeScaledDepthBias = D3D11_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;
        m_rs_desc.DepthClipEnable = TRUE;
        m_rs_desc.ScissorEnable = FALSE;
        m_rs_desc.MultisampleEnable = msaa_enabled;	//FALSE;
        m_rs_desc.AntialiasedLineEnable = FALSE;

		m_device->CreateRasterizerState(&m_rs_desc, &m_rast_state);
	}

	void deinit_r() {		
		if (m_device_context) { m_device_context->ClearState(); }
		com_release(m_depth_stencil_buffer);
		com_release(m_render_target_view);
		com_release(m_depth_stencil_view);
		com_release(m_swap_chain);			
		com_release(m_device_context);
		com_release(m_device);
		com_release(m_rast_state);
	}

	void setup() {}
	void cleanup() {}

	void render(float dt) {
		clear(gm::color4(0.0, 1.0, 0.0, 1.0));
	}

	void swap_buffers() {
		// Swap the back and front buffers.
		// Show the frame on the primary surface.
		// For the bit-block transfer (bitblt) model (DXGI_SWAP_EFFECT_DISCARD or DXGI_SWAP_EFFECT_SEQUENTIAL), values are:
		// 0 - The presentation occurs immediately, there is no synchronization.
		// 1 through 4 - Synchronize presentation after the nth vertical blank.
		// For the flip model (DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL), values are:
		// 0 - Cancel the remaining time on the previously presented frame and discard this frame if a newer frame is queued.
		// 1 through 4 - Synchronize presentation for at least n vertical blanks.
		m_swap_chain->Present(0, 0);
	}
	//-----------------------
	void clear_render_target(const gm::color4& color_rgba) {
		//float clear_color[4] = {0.0f, 1.0f, 1.0f, 1.0f};
		//m_device_context->ClearRenderTargetView(m_render_target_view, clear_color);
		m_device_context->ClearRenderTargetView(m_render_target_view, color_rgba.data());
	}
	void clear_depth_stencil(bool clear_depth, bool clear_stencil, float depth, uint stencil) {
		uint clear_flag = 0;
		if (clear_depth) { clear_flag |= D3D11_CLEAR_DEPTH; }
		if (clear_stencil) { clear_flag |= D3D11_CLEAR_STENCIL; }    
		//m_device_context->ClearDepthStencilView(m_depth_stencil_view, D3D11_CLEAR_DEPTH|D3D11_CLEAR_STENCIL, 1.0f, 0);
		m_device_context->ClearDepthStencilView(m_depth_stencil_view, clear_flag, depth, stencil);
	}
	void clear(const gm::color4& color_rgba) {
		clear_render_target(color_rgba);
		clear_depth_stencil(true, true, 1.0f, 0);
	}

	//clear_all
	//clear_screen

	void set_rs_culling(rs_cull_mode_e cullmode_back_face) {
		// Default cull mode is D3DCULL_CCW for D3D9, culling refering to back face culling.
		// A front face is one in which vertices are defined in clockwise order. Back faces having CCW are culled.
		// In OpenGL CCW is frontface by default. Use glFrontFace(GL_CW) to specify CCW as backface like D3D9. 
		switch (cullmode_back_face) {
			case rs_cull_mode_e::cull_none: m_rs_desc.CullMode = D3D11_CULL_NONE; break;
			case rs_cull_mode_e::cull_cw: m_rs_desc.CullMode = D3D11_CULL_FRONT; break;
			case rs_cull_mode_e::cull_ccw: m_rs_desc.CullMode = D3D11_CULL_BACK; break;
			default: m_rs_desc.CullMode = D3D11_CULL_BACK; break; //D3DCULL_CCW
		}
		m_device->CreateRasterizerState(&m_rs_desc, &m_rast_state);
		m_device_context->RSSetState(m_rast_state);
	}
	
	void reset_default_states() {
		// Restore default states, input layout and primitive topology because mFont->DrawText changes them. 
		// Note that we can restore the default states by passing null.
		m_device_context->OMSetDepthStencilState(nullptr, 0);
		float blendFactors[] = {0.0f, 0.0f, 0.0f, 0.0f};
		m_device_context->OMSetBlendState(nullptr, blendFactors, 0xffffffff);
		set_primitive_topology();
	}

	void set_primitive_topology() {
		m_device_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	}

	void bind_rtv_and_dsv_to_oms_of_pipeline() {
		// Bind the render target view and depth/stencil view to the pipeline.
		// Bind one or more render targets atomically and the depth-stencil buffer to the output-merger stage.
		m_device_context->OMSetRenderTargets(1, &m_render_target_view, m_depth_stencil_view);
	}
};


#define D3D11_SEP_MAT_TRANSPOSED 1

class wm_rd3d11_tri_sep_mat : public wm_rd3d11 {
public:
	ID3D11InputLayout* m_input_layout;

	ID3D11Buffer* model_vb = nullptr;
	ID3D11Buffer* model_ib = nullptr;		
	int64 model_num_vertices = 0;
	int64 model_num_indices = 0;

	ID3D11VertexShader* vs_shader = nullptr;
    ID3DBlob* vs_blob = nullptr;
	ID3D11PixelShader* ps_shader = nullptr;
    ID3DBlob* ps_blob = nullptr;

	ID3D11Buffer* cbuffer_wvp = nullptr;

	gm::mat4 mat_world_model = gm::mat4::k_identity();


	struct cb_per_object_ex2_s {
		gm::mat4 wvp;
		gm::mat4 W;
		gm::mat4 V;
		gm::mat4 P;
		int mode;
		float pad[3];
	};
	ID3D11Buffer* buffer_per_object = nullptr;

	void setup() {
		set_rs_culling(rs_cull_mode_e::cull_ccw);

		// Load Shaders.
		const char* shader_filename = RS_SHADER_PATH("d3d11_vertex_pc_sep_wvp.fx");		
		load_vertex_shader_file(m_device, shader_filename, vs_blob, vs_shader);
		load_pixel_shader_file(m_device, shader_filename, ps_blob, ps_shader);	


		// Create vertex declaration for expressing the data layout. Conceptually, the vertex declaration is a way of 
		// programming the vertex direct memory access (DMA) and the tessellator engine of the graphics pipe.
		D3D11_INPUT_ELEMENT_DESC vertex_elements_pc[] =  {
			{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0},
			{"COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0}
		};

		// After vertex shader init.
		// Create the input layout.
		m_device->CreateInputLayout(vertex_elements_pc, sdf::size(vertex_elements_pc), 
			vs_blob->GetBufferPointer(), vs_blob->GetBufferSize(), &m_input_layout);

		// Load data to vector.
		sdr::vector<vertex_pc> vertices_vec;
		sdr::vector<uint> indices_vec;
		fill_triangle_vertex_pc(vertices_vec, indices_vec);

		model_num_vertices = vertices_vec.size();
		model_num_indices = indices_vec.size();

		// Create the vertex buffer. 
		create_vertex_buffer(m_device, vec_size_bytes(vertices_vec), vertices_vec.data(), model_vb);
	
		// Create the index buffer. 
		create_index_buffer(m_device, vec_size_bytes(indices_vec), indices_vec.data(), model_ib);

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);	

		//set_primitive_topology();

		create_constant_buffer(m_device, sizeof(cb_per_object_ex2_s), buffer_per_object);

		// Set WVP matrices.
		set_world_matrix_tri1(mat_world_model);
		set_view_matrix_tri1(mat_view);
		set_proj_matrix_tri1(mat_proj, m_client_width, m_client_height);

		//create_font(m_device, m_font);
	}

	void cleanup() {
		com_release(m_input_layout);
		com_release(cbuffer_wvp);
		com_release(vs_blob);
		com_release(ps_blob);
		com_release(vs_shader);
		com_release(ps_shader);
		com_release(model_vb);
		com_release(model_ib);
		com_release(buffer_per_object);
	}
	

	void render(float dt) {
		clear(k_clear_color);		
		m_device_context->OMSetRenderTargets(1, &m_render_target_view, m_depth_stencil_view);				

		// Set shaders and constant buffers
		m_device_context->VSSetShader(vs_shader, nullptr, 0);				
		m_device_context->PSSetShader(ps_shader, nullptr, 0);	

		m_device_context->IASetInputLayout(m_input_layout);  

		// Set vertex buffer
		UINT stride = sizeof(vertex_pc);
		UINT offset = 0;
		m_device_context->IASetVertexBuffers(0, 1, &model_vb, &stride, &offset);

		// Set index buffer
		m_device_context->IASetIndexBuffer(model_ib, DXGI_FORMAT_R32_UINT, 0);	

		gm::mat4 mat_wvp_temp = mat_world_model * mat_view * mat_proj;
		//gm::mat4 mat_wvp_temp_t = gm::mat4_transpose(mat_wvp_temp);		

		// Upload mat_wvp_temp_t to shader by constant buffer "buffer_per_object" of type struct cb_per_object_s.
		cb_per_object_ex2_s cb_per_object = {};
	#if D3D11_SEP_MAT_TRANSPOSED
		//cb_per_object.mode = 1;
		cb_per_object.mode = 2; //seperate matrices in shader
		cb_per_object.W = gm::mat4_transpose(mat_world_model);
		cb_per_object.V = gm::mat4_transpose(mat_view);
		cb_per_object.P = gm::mat4_transpose(mat_proj);	
		cb_per_object.wvp = gm::mat4_transpose(mat_wvp_temp);
	#else
		//cb_per_object.mode = 3;
		cb_per_object.mode = 4; //seperate matrices in shader
		cb_per_object.W = mat_world_model;
		cb_per_object.V = mat_view;
		cb_per_object.P = mat_proj;	
		cb_per_object.wvp = mat_wvp_temp;
	#endif
		upload_constant_buffer(m_device_context, buffer_per_object, 1, &cb_per_object);

		// Draw one triangle.
		//m_device_context->Draw(model_num_indices, 0);
		m_device_context->DrawIndexed(model_num_indices, 0, 0);	

		//draw_font(m_device, m_font, "Hello World");
		//reset_default_states();
	}
};




//#define D3D11_TEXTURES 1

class wm_rd3d11_tri : public wm_rd3d11 {
public:
	ID3D11InputLayout* m_input_layout;

	ID3D11Buffer* model_vb = nullptr;
	ID3D11Buffer* model_ib = nullptr;		
	int64 model_num_vertices = 0;
	int64 model_num_indices = 0;

	ID3D11VertexShader* vs_shader = nullptr;
    ID3DBlob* vs_blob = nullptr;
	ID3D11PixelShader* ps_shader = nullptr;
    ID3DBlob* ps_blob = nullptr;

	ID3D11Buffer* cbuffer_wvp = nullptr;

	gm::mat4 mat_world_model = gm::mat4::k_identity();

	ID3D11ShaderResourceView* tex = nullptr;
	//ID3D11SamplerState* m_sampler_anisotropic;

	//struct cb_never_changes_s {
	//	gm::mat4 view;
	//};
	//struct cb_change_on_resize_s {
	//	gm::mat4 projection;
	//};
	//struct cb_changes_every_frame_s {
	//	gm::mat4 world;
	//	gm::color4 v_mesh_color;
	//};

	struct cb_per_object_s {
		gm::mat4 wvp;
	};
	ID3D11Buffer* buffer_per_object = nullptr;


	void setup() {
		set_rs_culling(rs_cull_mode_e::cull_ccw);

	#if !D3D11_TEXTURES
		// Load Shaders.
		const char* shader_filename = RS_SHADER_PATH("d3d11_vertex_pc.fx");	
		//load_vertex_shader_file(m_device, shader_filename, vs_blob, vs_shader);
		//load_pixel_shader_file(m_device, shader_filename, ps_blob, ps_shader);			

		// Bytecode shader loading
		//load_vertex_shader_bytecode(m_device, RS_SHADER_PATH("d3d11_tut/shaders_cso/d3d11_vertex_pc_vs.cso"), vs_blob, vs_shader);
		//load_pixel_shader_bytecode(m_device, RS_SHADER_PATH("d3d11_tut/shaders_cso/d3d11_vertex_pc_ps.cso"), ps_blob, ps_shader);	
		//load_vertex_shader_file(m_device, shader_filename, vs_blob, vs_shader);
		//load_pixel_shader_file(m_device, shader_filename, ps_blob, ps_shader);	
		load_vertex_shader_bytecode_or_file(m_device, RS_SHADER_PATH("d3d11_tut/shaders_cso/d3d11_vertex_pc_vs.cso"), 
			shader_filename, vs_blob, vs_shader);
		load_pixel_shader_bytecode_or_file(m_device, RS_SHADER_PATH("d3d11_tut/shaders_cso/d3d11_vertex_pc_ps.cso"), 
			shader_filename, ps_blob, ps_shader);


		// Create vertex declaration for expressing the data layout. Conceptually, the vertex declaration is a way of 
		// programming the vertex direct memory access (DMA) and the tessellator engine of the graphics pipe.
		D3D11_INPUT_ELEMENT_DESC vertex_elements_pc[] =  {
			{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0},
			{"COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0}
		};

		// After vertex shader init.
		// Create the input layout.
		m_device->CreateInputLayout(vertex_elements_pc, sdf::size(vertex_elements_pc), 
			vs_blob->GetBufferPointer(), vs_blob->GetBufferSize(), &m_input_layout);

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
		const char* shader_filename = RS_SHADER_PATH("d3d11_vertex_pct.fx");		
		load_vertex_shader_file(m_device, shader_filename, vs_blob, vs_shader);
		load_pixel_shader_file(m_device, shader_filename, ps_blob, ps_shader);	

		// Create vertex declaration for expressing the data layout. Conceptually, the vertex declaration is a way of 
		// programming the vertex direct memory access (DMA) and the tessellator engine of the graphics pipe.
		D3D11_INPUT_ELEMENT_DESC vertex_elements_pct[] =  {
			{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0,  0, D3D11_INPUT_PER_VERTEX_DATA, 0},
			{"COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0},
			{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,		0, 28, D3D11_INPUT_PER_VERTEX_DATA, 0}
		};	
		// After vertex shader init.
		// Create the input layout.
		m_device->CreateInputLayout(vertex_elements_pct, sdf::size(vertex_elements_pct), 
			vs_blob->GetBufferPointer(), vs_blob->GetBufferSize(), &m_input_layout);


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
		create_sampler_state(m_device, m_sampler_anisotropic, rs_texture_filter_e::texf_anisotropic, m_anisotropic_quality);
	#endif

		// Create the index buffer. 
		create_index_buffer(m_device, vec_size_bytes(indices_vec), indices_vec.data(), model_ib);

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);	

		//set_primitive_topology();

		create_constant_buffer(m_device, sizeof(cb_per_object_s), buffer_per_object);

		// Set WVP matrices.
		set_world_matrix_tri1(mat_world_model);
		set_view_matrix_tri1(mat_view);
		set_proj_matrix_tri1(mat_proj, m_client_width, m_client_height);

		//create_font(m_device, m_font);
	}

	void cleanup() {
		com_release(m_input_layout);
		com_release(cbuffer_wvp);
		com_release(vs_blob);
		com_release(ps_blob);
		com_release(vs_shader);
		com_release(ps_shader);
		com_release(model_vb);
		com_release(model_ib);
		com_release(buffer_per_object);
		com_release(tex);
	}

	

	void render(float dt) {
		clear(k_clear_color);		
		bind_rtv_and_dsv_to_oms_of_pipeline();

		// Set shaders and constant buffers
		m_device_context->VSSetShader(vs_shader, nullptr, 0);				
		m_device_context->PSSetShader(ps_shader, nullptr, 0);	

		m_device_context->IASetInputLayout(m_input_layout);  

	#if !D3D11_TEXTURES
		// Set vertex buffer
		UINT stride = sizeof(vertex_pc);
		UINT offset = 0;
		m_device_context->IASetVertexBuffers(0, 1, &model_vb, &stride, &offset);
	#else
		// Set vertex buffer
		UINT stride = sizeof(vertex_pct);
		UINT offset = 0;
		m_device_context->IASetVertexBuffers(0, 1, &model_vb, &stride, &offset);

		m_device_context->PSSetShaderResources(0, 1, &tex); 
		m_device_context->PSSetSamplers(0, 1, &m_sampler_anisotropic);
	#endif

		// Set index buffer
		m_device_context->IASetIndexBuffer(model_ib, DXGI_FORMAT_R32_UINT, 0);	

		gm::mat4 mat_wvp_temp = mat_world_model * mat_view * mat_proj;
		gm::mat4 mat_wvp_temp_t = gm::mat4_transpose(mat_wvp_temp);		

		// Upload mat_wvp_temp_t to shader by constant buffer "buffer_per_object" of type struct cb_per_object_s.
		cb_per_object_s cb_per_object = {};
		cb_per_object.wvp = mat_wvp_temp_t;
		upload_constant_buffer(m_device_context, buffer_per_object, 1, &cb_per_object);

		// Draw one triangle.
		//m_device_context->Draw(model_num_indices, 0);
		m_device_context->DrawIndexed(model_num_indices, 0, 0);	

		//draw_font(m_device, m_font, "Hello World");
		//reset_default_states();
	}


};

