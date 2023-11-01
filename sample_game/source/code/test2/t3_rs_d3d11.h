#pragma once

// FONT RENDERING NOT DONE
//#include <SpriteFont.h> // from DirectXTK
//std::unique_ptr<SpriteBatch> spriteBatch;
//std::unique_ptr<SpriteFont> spriteFont;
// rastertek tutorials
// Hieroglyph3
// learnopengl
// FW1FontWrapper
// D3D12: mini engine in DirectX samples


//cbuffer cbPerObject : register(b0) {
//	float4		g_vObjectColor			: packoffset( c0 );
//};
//cbuffer cbPerFrame : register(b1) {
//	float3		g_vLightDir				: packoffset( c0 );
//	float		g_fAmbient				: packoffset( c0.w );
//};
//Texture2D<float4> Texture2 : register(t1);

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


////#include <wrl.h>
//#include <wrl/client.h>
//using Microsoft::WRL::ComPtr;
// For RoInitializeWrapper required for CreateWICTextureFromFile
#pragma comment(lib, "runtimeobject.lib")

//=====================================
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXMath.h"
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXPackedVector.h"
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXColors.h"
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXCollision.h"

// For textures
#include "d3dxlib/DDSTextureLoader/DDSTextureLoader11.h"
#include "d3dxlib/WICTextureLoader/WICTextureLoader11.h"
// Add DDSTextureLoader11.cpp to project also
//------------------------------------

#include "base_gmath.h"

#include "t3_rs_irenderer.h"

#include "base_win_util.h"

#include <vector>
#include "base_std_cont.h"


inline bool d3d11_compile_shader_from_file(const char* shader_filename, const char* sh_entry_point, const char* shader_model, ID3DBlob*& out_blob) {
    if (!shader_filename || !sh_entry_point || !shader_model) {
		eprintfln("Null pointer passed.");
		return false; 
		//return E_INVALIDARG;
    }

	//-----------
	if (!(is_file_exists(shader_filename))) {
		eprintfln("Cannot find shader file: %s", shader_filename);
		return false;
	}

	sdf::wstring_st<MAX_STR_PATH_OS> shader_file_namew;
	sdf::string_st_wcs_from_mbs(shader_file_namew, shader_filename, sdf::strfz_len(shader_filename));
	
	
    UINT shader_flags = D3DCOMPILE_ENABLE_STRICTNESS;
#ifdef _DEBUG
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
    //hr = D3DCompileFromFile(shader_file_namew.c_str(), nullptr, nullptr, sh_entry_point, shader_model, shader_flags, 0, &out_blob, &compilation_errors);
    hr = D3DCompileFromFile(shader_file_namew.c_str(), defines, D3D_COMPILE_STANDARD_FILE_INCLUDE, sh_entry_point, shader_model, shader_flags, 0, &out_blob, &compilation_errors);

    if (FAILED(hr)) {
        if (compilation_errors) {
			eprintfln("Shader File compile error: %s", shader_filename);
			//OutputDebugStringA(rcast<const char*>(compilation_errors->GetBufferPointer()));
			//MessageBoxA(0, (char*)compilation_errors->GetBufferPointer(), 0, 0);
			//MessageBoxA(0, rcast<const char*>(compilation_errors->GetBufferPointer()), 0, 0);
			sdf::wstring_st<1024> wmsg;
			sdf::string_st_wcs_from_mbs(wmsg, 
				rcast<const char*>(compilation_errors->GetBufferPointer()), sdf::strfz_len(rcast<const char*>(compilation_errors->GetBufferPointer())));
			if (!wmsg.empty()) { fm_msg_box_ok_w(wmsg.c_str()); }
			//eprintfln("%s", rcast<const char*>(compilation_errors->GetBufferPointer()));
			compilation_errors->Release();
        }
        return false;
    }

	com_release(compilation_errors);
    return true;
}


//------------
//using d3d11_buffer = rs_com_raii<ID3D11Buffer>;
//using d3d11_input_layout = rs_com_raii<ID3D11InputLayout>;
using d3d11_rasterizer_state = rs_com_raii<ID3D11RasterizerState>;
//using d3d11_texture = rs_com_raii<ID3D11ShaderResourceView>;
//using d3d11_sampler_state = rs_com_raii<ID3D11SamplerState>;
//
//using d3d11_blob = rs_com_raii<ID3DBlob>;
//using d3d11_vs_shader = rs_com_raii<ID3D11VertexShader>;
//using d3d11_ps_shader = rs_com_raii<ID3D11PixelShader>;


//--------------
//class d3d11_model {
//public:		
//	ID3D11Buffer* m_vb = nullptr;
//	ID3D11Buffer* m_ib = nullptr;		
//	isz num_vertices = 0;
//	isz num_indices = 0;
//
//	ID3D11InputLayout* m_input_layout = nullptr;
//	ID3D11ShaderResourceView* m_tex = nullptr;	
//
//	uint vstride = 0;
//
//	~d3d11_model() {
//		com_release(m_vb);
//		com_release(m_ib);
//	}
//};


//------------------------
class rd3d11 : public irenderer {
public:
	//-------------
	//ID3D11Device* m_device = nullptr;
	//ID3D11DeviceContext* m_device_context = nullptr;
	//IDXGISwapChain* m_swap_chain = nullptr;
	
	ID3D11RenderTargetView* m_render_target = nullptr;
	ID3D11DepthStencilView* m_depth_stencil = nullptr;	//m_pDepthStencilView

	ID3D11Texture2D* m_back_buffer = nullptr;

	//-------------
	ID3D11Device5*           m_device;
	ID3D11DeviceContext4*    m_device_context;
	IDXGISwapChain4*         m_swap_chain;

	//ID3D11RenderTargetView1* m_render_target; //pointer to back buffer
	//ID3D11RenderTargetView*  m_render_target0 = nullptr;
	//---
	ID3D11Texture2D* m_depth_stencil_buffer = nullptr;	//m_pDepthStencil

	// In full-screen mode, there is a dedicated front buffer; in windowed mode, the desktop is the front buffer.
	// If you create a swap chain with one buffer, specifying DXGI_SWAP_EFFECT_SEQUENTIAL does not cause the contents 
	// of the single buffer to be swapped with the front buffer.
	UINT m_back_buffer_count = 1; //2 for DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL else 1;
	DXGI_FORMAT m_back_buffer_format = DXGI_FORMAT_R8G8B8A8_UNORM;	//DXGI_FORMAT_B8G8R8A8_UNORM;
	DXGI_FORMAT m_depth_stencil_format = DXGI_FORMAT_D24_UNORM_S8_UINT;

	D3D11_RASTERIZER_DESC m_rs_desc = {};
	d3d11_rasterizer_state m_rast_state;

	//d3d11_texture m_default_tex;
	//d3d11_sampler_state m_sampler_anisotropic;


	void deinit_r() {
		com_release(m_depth_stencil_buffer);
		com_release(m_depth_stencil);		
		com_release(m_render_target);
		com_release(m_swap_chain);	
		if (m_device_context) { m_device_context->ClearState(); }
		com_release(m_device_context);
		com_release(m_device);
	}

	bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) {	
		//set_viewport(0.0f, 0.0f, width, height);
		if (!hwnd) { eprintfln("Window Handle passed is null."); }
		//m_render_window = hwnd;
		sys_win_title_append(hwnd, " : Direct3D11");
		m_aspect_ratio = sdf::get_aspect_ratio(width, height);

		//------------
		// Create the device and device context.
		UINT device_flags = 0;
    #if defined(DEBUG) || defined(_DEBUG)  
		device_flags |= D3D11_CREATE_DEVICE_DEBUG;
	#endif
		// This flag adds support for surfaces with a color-channel ordering different
        // from the API default. This is required to interop with Direct2D/DirectWrite.
        device_flags |= D3D11_CREATE_DEVICE_BGRA_SUPPORT;

		D3D_DRIVER_TYPE md3dDriverType = D3D_DRIVER_TYPE_HARDWARE;

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

		// Set or cast current device & device_context from temp_device & temp_device_context.
		// Same device type as temp_device D3D 11.0
		//m_device = temp_device0;
		//m_device_context = temp_device_context0;
		// For device types higher than temp_device D3D 11.0 (11.1 onwards)
		temp_device0->QueryInterface(IID_PPV_ARGS(&m_device));
		temp_device_context0->QueryInterface(IID_PPV_ARGS(&m_device_context));
		temp_device0 = nullptr;
		temp_device_context0 = nullptr;


		// Check MSAA quality support for our back buffer format.
		// All Direct3D 11 capable devices support 4X MSAA target formats.		
		// FEATURE_LEVEL_11_0 devices are required to support 4x MSAA for all render target formats, 
		// and 8x MSAA for all render target formats except R32G32B32A32 formats.
		// D3D11_MAX_MULTISAMPLE_SAMPLE_COUNT in d3d11.h is 32
		// TODO: Check 4x, 8x, 16x, 32x support. Only 4x checked for now.
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
        scd1.Width = width;
        scd1.Height = height;
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
        dxgiFactory->CreateSwapChainForHwnd(
            m_device,
            hwnd,
            &scd1,
            &scd1_fs,
            nullptr,
			&swapChain1
			);

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
		resize(width, height);

		create_render_state();
			//init_fonts();

			//init_default_texture();


		//------------
		return true;
	}

	void get_back_buffer_dim(int& width, int& height) {
		// If want to use back_buffer width and height.
        D3D11_TEXTURE2D_DESC rt_back_buffer_desc = {};
		m_back_buffer->GetDesc(&rt_back_buffer_desc);
		width = rt_back_buffer_desc.Width;
		height = rt_back_buffer_desc.Height;
	}

	void resize(int width, int height) {
		//if (m_swap_chain) {

		// Clear the previous window size specific context.
		m_device_context->OMSetRenderTargets(0, nullptr, nullptr);
		// Release the old views, as they hold references to the swap chain's buffers we
		// will be destroying. Also release the old depth/stencil buffer.		
		com_release(m_render_target);
		//-com_release(m_back_buffer);
		com_release(m_depth_stencil);
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
		m_swap_chain->ResizeBuffers(m_back_buffer_count, width, height, m_back_buffer_format, 0);

		//} 
		// TO_CHECK: If the swap chain already exists, resize it, otherwise create one. For fullscreen maybe.
		//else { create_swap_chain(); }

		//------------
		// A swap chain is present or created at this point.
		// Obtain the backbuffer for this window which will be the final 3D rendertarget.
		m_back_buffer = nullptr;
		//m_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer))
		m_swap_chain->GetBuffer(0, IID_PPV_ARGS(&m_back_buffer));
		m_device->CreateRenderTargetView(m_back_buffer, nullptr, &m_render_target);
		com_release(m_back_buffer);

		// Get back_buffer width and height. Use if needed.
		//int w, h;
		//get_back_buffer_dim(w, h);
		
		// Create the depth/stencil buffer and view.
		D3D11_TEXTURE2D_DESC depth_stencil_desc = {};	
		depth_stencil_desc.Width     = width;
		depth_stencil_desc.Height    = height;
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
		m_device->CreateDepthStencilView(m_depth_stencil_buffer, &depth_stencil_view_desc, &m_depth_stencil);
		////m_device->CreateDepthStencilView(m_depth_stencil_buffer, nullptr, &m_depth_stencil);


		// Bind the render target view and depth/stencil view to the pipeline.
		m_device_context->OMSetRenderTargets(1, &m_render_target, m_depth_stencil);
		//m_device_context->OMSetRenderTargets(1, &m_render_target0, m_depth_stencil);
		//m_render_target0.As(&m_render_target);

		//------------
		// Set the viewport transform.
		D3D11_VIEWPORT vp = {};
		vp.TopLeftX = 0.0f;
		vp.TopLeftY = 0.0f;
		vp.Width    = scast<float>(width);		//scast<float>(rt_back_buffer_desc.Width);
		vp.Height   = scast<float>(height);		//scast<float>(rt_back_buffer_desc.Height);
		vp.MinDepth = D3D11_MIN_DEPTH;			//0.0f;
		vp.MaxDepth = D3D11_MAX_DEPTH;			//1.0f;
		m_device_context->RSSetViewports(1, &vp);
		
		// If changed again in resize.
		//set_rs_anitialiasing();

		m_aspect_ratio = sdf::get_aspect_ratio(width, height);

		mat_proj = set_projection_matrix();
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
		// Show the frame on the primary surface.
		// For the bit-block transfer (bitblt) model (DXGI_SWAP_EFFECT_DISCARD or DXGI_SWAP_EFFECT_SEQUENTIAL), values are:
		// 0 - The presentation occurs immediately, there is no synchronization.
		// 1 through 4 - Synchronize presentation after the nth vertical blank.
		// For the flip model (DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL), values are:
		// 0 - Cancel the remaining time on the previously presented frame and discard this frame if a newer frame is queued.
		// 1 through 4 - Synchronize presentation for at least n vertical blanks.

		m_swap_chain->Present(0, 0);
	}


	//-----------------------------------------------------------
	void clear_render_target(const gm::color4& color_rgba) {
		//float clear_color[4] = {0.0f, 1.0f, 1.0f, 1.0f};
		//m_device_context->ClearRenderTargetView(m_render_target, clear_color);
		m_device_context->ClearRenderTargetView(m_render_target, color_rgba.data());
	}
	void clear_depth_stencil(bool clear_depth, bool clear_stencil, float depth, uint stencil) {
		uint clear_flag = 0;
		if (clear_depth) { clear_flag |= D3D11_CLEAR_DEPTH; }
		if (clear_stencil) { clear_flag |= D3D11_CLEAR_STENCIL; }    
		//m_device_context->ClearDepthStencilView(m_depth_stencil, D3D11_CLEAR_DEPTH|D3D11_CLEAR_STENCIL, 1.0f, 0);
		m_device_context->ClearDepthStencilView(m_depth_stencil, clear_flag, depth, stencil);
	}
	void clear_screen_buffers() {
		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);
	}

	//-----------------------------------------------------------
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
		m_device->CreateRasterizerState(&m_rs_desc, &m_rast_state.data);
		m_device_context->RSSetState(m_rast_state.data);
	}

	//-----------------------------------------------------------
	void set_rs_fillmode(rs_fill_mode_e fill_mode) {
		switch (fill_mode) {
			case rs_fill_mode_e::fill_solid: m_rs_desc.FillMode = D3D11_FILL_SOLID; break;
			case rs_fill_mode_e::fill_wireframe: m_rs_desc.FillMode = D3D11_FILL_WIREFRAME; break;
			default: m_rs_desc.FillMode = D3D11_FILL_SOLID; break;
		}
		m_device->CreateRasterizerState(&m_rs_desc, &m_rast_state.data);
		m_device_context->RSSetState(m_rast_state.data);
	} 

	//---------------------------
	//void set_primitive_topology() {
};


class rd3d11_tri_color : public rd3d11  {
public:		

	ID3D11InputLayout* m_input_layout;

	ID3D11Buffer* triangle_m_vb = nullptr;
	ID3D11Buffer* triangle_m_ib = nullptr;		
	int64 tri_num_vertices = 0;
	int64 tri_num_indices = 0;

	gm::mat4 mat_world_tri = gm::mat4::k_identity();

	ID3D11VertexShader* vs_shader = nullptr;
    ID3DBlob* vs_blob = nullptr;
	ID3D11PixelShader* ps_shader = nullptr;
    ID3DBlob* ps_blob = nullptr;

	ID3D11Buffer* cbuffer_wvp = nullptr;

	void cleanup() {
		com_release(cbuffer_wvp);
		com_release(vs_blob);
		com_release(ps_blob);
		com_release(vs_shader);
		com_release(ps_shader);

		com_release(triangle_m_vb);
		com_release(triangle_m_ib);
		com_release(m_input_layout);	
	}	

	void setup() {	
		set_rs_culling(rs_cull_mode_e::cull_ccw);
		// Set Render Pipeline state.
		//m_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); // default in d3d
		//m_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW); // default in OpenGL
		//m_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);


		// Create vertex declaration for expressing the data layout. Conceptually, the vertex declaration is a way of 
		// programming the vertex direct memory access (DMA) and the tessellator engine of the graphics pipe.
		D3D11_INPUT_ELEMENT_DESC vertex_elements_pc[] = {
			{"POSITION",	0, DXGI_FORMAT_R32G32B32_FLOAT,		0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0},
			{"COLOR",		0, DXGI_FORMAT_R32G32B32A32_FLOAT,	0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0},
		};
		UINT num_vertex_elements_pc = sdf::arr_cap(vertex_elements_pc);


		// Load shaders before CreateVertexDeclaration or CreateInputLayout
		//load_shaders_file(RS_SHADER_PATH2("d3d11_vertex_pc.fx"), shader_vs, shader_ps);		

		HRESULT hr = 0;
		bool success = false;

	#if 1
		const char* shader_filename = RS_SHADER_PATH("d3d11_vertex_pc.fx");		

		success = d3d11_compile_shader_from_file(shader_filename, "VS", "vs_5_0", vs_blob);
		hr = m_device->CreateVertexShader(vs_blob->GetBufferPointer(), vs_blob->GetBufferSize(), nullptr, &vs_shader);
		if (FAILED(hr)) { 
			eprintfln("CreateVertexShader failed"); 
			vs_blob->Release(); 
		}
		
		// After vertex shader init.
		// Create the input layout.
		m_device->CreateInputLayout(vertex_elements_pc, num_vertex_elements_pc, vs_blob->GetBufferPointer(), vs_blob->GetBufferSize(), &m_input_layout);		


		success = d3d11_compile_shader_from_file(shader_filename, "PS", "ps_5_0", ps_blob);
		hr = m_device->CreatePixelShader(ps_blob->GetBufferPointer(), ps_blob->GetBufferSize(), nullptr, &ps_shader);		
		if (FAILED(hr)) { 
			eprintfln("CreatePixelShader failed"); 
			ps_blob->Release(); 
		}
	#else
		#if 0	
			size_t vs_shader_blob_len = 0;
			char* vs_shader_blob = sdf::read_binary_file_c(RS_SHADER_PATH2("d3d11_tut/shaders_cso/d3d11_vertex_pc_vs.cso"), vs_shader_blob_len);
			hr = m_device->CreateVertexShader(vs_shader_blob, vs_shader_blob_len, nullptr, &vs_shader);	

			m_device->CreateInputLayout(vertex_elements_pc, num_vertex_elements_pc, vs_shader_blob, vs_shader_blob_len, &m_input_layout);

			free(vs_shader_blob);

			size_t ps_shader_blob_len = 0;
			char* ps_shader_blob = sdf::read_binary_file_c(RS_SHADER_PATH2("d3d11_tut/shaders_cso/d3d11_vertex_pc_ps.cso"), ps_shader_blob_len);
			hr = m_device->CreatePixelShader(ps_shader_blob, ps_shader_blob_len, nullptr, &ps_shader);	

			free(ps_shader_blob);
		#else
			sdr::vector<char> vs_shader_blob;
			sdf::read_binary_file(vs_shader_blob, RS_SHADER_PATH2("d3d11_tut/shaders_cso/d3d11_vertex_pc_vs.cso"));
			hr = m_device->CreateVertexShader(vs_shader_blob.data(), vs_shader_blob.size(), nullptr, &vs_shader);	

			m_device->CreateInputLayout(vertex_elements_pc, num_vertex_elements_pc, vs_shader_blob.data(), vs_shader_blob.size(), &m_input_layout);

			sdr::vector<char> ps_shader_blob;
			sdf::read_binary_file(ps_shader_blob, RS_SHADER_PATH2("d3d11_tut/shaders_cso/d3d11_vertex_pc_ps.cso"));
			hr = m_device->CreatePixelShader(ps_shader_blob.data(), ps_shader_blob.size(), nullptr, &ps_shader);	
		#endif
	#endif

		
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
		CD3D11_BUFFER_DESC vbd(vb_size_bytes, D3D11_BIND_VERTEX_BUFFER);
		D3D11_SUBRESOURCE_DATA vInitData = {};
		vInitData.pSysMem = vertices_vec.data();
		m_device->CreateBuffer(&vbd, &vInitData, &triangle_m_vb);

		// Enable if using index buffers.
		// Create the index buffer. 
		UINT ib_size_bytes = indices_vec.size() * sizeof(uint);
		CD3D11_BUFFER_DESC ibd(ib_size_bytes, D3D11_BIND_INDEX_BUFFER);
		D3D11_SUBRESOURCE_DATA iInitData = {};
		iInitData.pSysMem = indices_vec.data();
		m_device->CreateBuffer(&ibd, &iInitData, &triangle_m_ib);			

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);

		// Set primitive topology
        m_device_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);


		// Create the constant buffer
		// Assert that the constant buffer remains 16-byte aligned.
		static_assert((sizeof(cb_struct_mat4_s) % 16) == 0, "Constant Buffer size must be 16-byte aligned");
		UINT cb_size_bytes = sizeof(cb_struct_mat4_s);
		D3D11_BUFFER_DESC cbd = {};
		cbd.ByteWidth = cb_size_bytes;
	    cbd.Usage = D3D11_USAGE_DEFAULT;	    
	    cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	    cbd.CPUAccessFlags = 0;
		cbd.MiscFlags = 0;
		cbd.StructureByteStride = 0;
        m_device->CreateBuffer(&cbd, nullptr, &cbuffer_wvp);        

		//// Create the constant buffer
		//// Assert that the constant buffer remains 16-byte aligned.
		//static_assert((sizeof(cb_struct_mat4) % 16) == 0, "Constant Buffer size must be 16-byte aligned");
		//UINT cb_size_bytes = sizeof(cb_struct_mat4);
		//CD3D11_BUFFER_DESC cbd(cb_size_bytes, D3D11_BIND_CONSTANT_BUFFER);
		//m_device->CreateBuffer(&cbd, nullptr, &cb_wvp.data);
		
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
		m_device_context->OMSetRenderTargets(1, &m_render_target, m_depth_stencil);
		// mFont->DrawText changes default states, input layout and primitive topology. Restore them.
		//reset_default_states();

		// You can transpose all matrices and vectors involved and multiply them in reverse order for column matrices (reversing 
		// the order is a result of the identity (A*B)^T = B^T * A^T). This gives transposed but otherwise identical results.
		//m_wvp = mat_world_tri * mat_view * mat_proj;
		//gl_shader_set_mat4_by_name(shaderProgram, "g_wvp", 1, GL_FALSE, m_wvp.data());		
		//output.pos = mul(pos, wvp); in shader column major
		//m_wvp_t = gm::mat4_transpose(m_world * m_view * m_proj); 
		//output.pos = mul(wvp, pos); in shader row major //no transpose needed
		// The D3D9/D3D10/D3D11 HLSL mul call interprets matrix arguments as column-major in all cases. 
		// The ID3DXBaseEffect::SetMatrix() call interprets its matrix argument as row-major, 
		// and transposes behind the scenes to HLSL mul's expected column-major order.
		// If column major matrices are used then transpose is not needed for mul(pos, wvp) in shader.
		gm::mat4 mat_wvp_temp = mat_world_tri * mat_view * mat_proj;

		gm::mat4 mat_wvp_temp_t = gm::mat4_transpose(mat_wvp_temp);
		//gm::mat4 mat_wvp_temp_t = mat_wvp_temp;

		// Upload mat_wvp_temp_t to shader by constant buffer cb_wvp by putting it in struct cbs_mat4_wvp.
		cb_struct_mat4_s cbs_mat4_wvp = {};
		cbs_mat4_wvp.wvp = mat_wvp_temp_t;
		m_device_context->UpdateSubresource(cbuffer_wvp, 0, nullptr, &cbs_mat4_wvp, 0, 0);
		m_device_context->VSSetConstantBuffers(0, 1, &cbuffer_wvp);

		// Set shaders and constant buffers
		m_device_context->VSSetShader(vs_shader, nullptr, 0);				
		m_device_context->PSSetShader(ps_shader, nullptr, 0);	


		m_device_context->IASetInputLayout(m_input_layout);

		// Set vertex buffer
		UINT stride = sizeof(vertex_pc);
		UINT offset = 0;
		m_device_context->IASetVertexBuffers(0, 1, &triangle_m_vb, &stride, &offset);
        // Enable if using index buffers.
		// Set index buffer
        m_device_context->IASetIndexBuffer(triangle_m_ib, DXGI_FORMAT_R32_UINT, 0);		

		// If only vertex buffer then, tri_num_indices is equal to num_vertices.
		//m_device_context->Draw(tri_num_indices, 0);
		m_device_context->DrawIndexed(tri_num_indices, 0, 0);	
	}	

	void render_orig(float dt) {
		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);
		m_device_context->OMSetRenderTargets(1, &m_render_target, m_depth_stencil);
		// mFont->DrawText changes default states, input layout and primitive topology. Restore them.
		//reset_default_states();

		m_device_context->IASetInputLayout(m_input_layout);

		// Set vertex buffer
		UINT stride = sizeof(vertex_pc);
		UINT offset = 0;
		m_device_context->IASetVertexBuffers(0, 1, &triangle_m_vb, &stride, &offset);
        // Enable if using index buffers.
		// Set index buffer
        m_device_context->IASetIndexBuffer(triangle_m_ib, DXGI_FORMAT_R32_UINT, 0);

		// You can transpose all matrices and vectors involved and multiply them in reverse order for column matrices (reversing 
		// the order is a result of the identity (A*B)^T = B^T * A^T). This gives transposed but otherwise identical results.
		//m_wvp = mat_world_tri * mat_view * mat_proj;
		//gl_shader_set_mat4_by_name(shaderProgram, "g_wvp", 1, GL_FALSE, m_wvp.data());		
		//output.pos = mul(pos, wvp); in shader column major
		//m_wvp_t = gm::mat4_transpose(m_world * m_view * m_proj); 
		//output.pos = mul(wvp, pos); in shader row major //no transpose needed
		// The D3D9/D3D10/D3D11 HLSL mul call interprets matrix arguments as column-major in all cases. 
		// The ID3DXBaseEffect::SetMatrix() call interprets its matrix argument as row-major, 
		// and transposes behind the scenes to HLSL mul's expected column-major order.
		// If column major matrices are used then transpose is not needed for mul(pos, wvp) in shader.
		gm::mat4 mat_wvp_temp = mat_world_tri * mat_view * mat_proj;

		gm::mat4 mat_wvp_temp_t = gm::mat4_transpose(mat_wvp_temp);
		//gm::mat4 mat_wvp_temp_t = mat_wvp_temp;

		// Upload mat_wvp_temp_t to shader by constant buffer cb_wvp by putting it in struct cbs_mat4_wvp.
		cb_struct_mat4_s cbs_mat4_wvp = {};
		cbs_mat4_wvp.wvp = mat_wvp_temp_t;
		m_device_context->UpdateSubresource(cbuffer_wvp, 0, nullptr, &cbs_mat4_wvp, 0, 0);

		// Set shaders and constant buffers
		m_device_context->VSSetShader(vs_shader, nullptr, 0);				
		m_device_context->PSSetShader(ps_shader, nullptr, 0);
		m_device_context->VSSetConstantBuffers(0, 1, &cbuffer_wvp);

		// If only vertex buffer then, tri_num_indices is equal to num_vertices.
		//m_device_context->Draw(tri_num_indices, 0);
		m_device_context->DrawIndexed(tri_num_indices, 0, 0);	
	}	
};