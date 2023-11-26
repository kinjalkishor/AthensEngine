#pragma once

//------------------------------------
//#include <d3d12.h>
//#include <D3Dcommon.h>
//#include "d3d12_agility_nuget/include/d3d12.h"

#include "directx/d3d12.h"
#include "directx/d3dcommon.h"
#include "directx/d3dx12.h"

#include <dxgi1_6.h>


#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dxguid.lib")
// For using Windows Imaging Component (WIC)
#pragma comment(lib, "uuid.lib")

// for compiling shader files, D3DCompileFromFile
#include <D3Dcompiler.h>

#pragma comment(lib, "d3dcompiler.lib")

#include <wrl.h>
//#include <wrl/client.h>
using Microsoft::WRL::ComPtr;

// For RoInitializeWrapper required for CreateWICTextureFromFile
#pragma comment(lib, "runtimeobject.lib")
//=====================================


//#include "d3dxlib/DDSTextureLoader/DDSTextureLoader12.h"
//#include "d3dxlib/WICTextureLoader/WICTextureLoader12.h"

//#include "frank_luna/DDSTextureLoader.h"
//------------------------------------

//#include "tut/d3dxlib/DirectXMath/Inc/DirectXMath.h"
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXPackedVector.h"
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXColors.h"
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXCollision.h"
//using namespace DirectX;
//using namespace DirectX::PackedVector;
//-------------------


#include "rs_irenderer.h"

//#include <shellapi.h>
#include <fstream>

#include <stdexcept>
#include <unordered_map>
//#include <vector>
//
//
#include <assert.h>
//using namespace std;
//#define ThrowIfFailed


namespace d3d12_util
{

inline UINT CalculateConstantBufferByteSize(UINT byteSize) {
	// Constant buffers must be a multiple of the minimum hardware
    // allocation size (usually 256 bytes).  So round up to nearest
    // multiple of 256.  We do this by adding 255 and then masking off
    // the lower 2 bytes which store all bits < 256.
    // Example: Suppose byteSize = 300.
    // (300 + 255) & ~255
    // 555 & ~255
    // 0x022B & ~0x00ff
    // 0x022B & 0xff00
    // 0x0200
    // 512
    //return (byteSize + 255) & ~255;

	constexpr UINT num_size = D3D12_CONSTANT_BUFFER_DATA_PLACEMENT_ALIGNMENT - 1;
	// Constant buffer size is required to be aligned.
	return (byteSize + num_size) & ~(num_size);
}

#if 0
inline Microsoft::WRL::ComPtr<ID3DBlob> LoadBinary(const std::wstring& filename) {
	std::ifstream fin(filename, std::ios::binary);

	fin.seekg(0, std::ios_base::end);
	std::ifstream::pos_type size = (int)fin.tellg();
	fin.seekg(0, std::ios_base::beg);

	ComPtr<ID3DBlob> blob;
	D3DCreateBlob(size, blob.GetAddressOf());

	fin.read((char*)blob->GetBufferPointer(), size);
	fin.close();

	return blob;
}
#endif

//static Microsoft::WRL::ComPtr<ID3DBlob> LoadBinary(const std::wstring& filename) {
inline void LoadBinary(const char* filename, ID3DBlob** out_blob) {	
	//sdf::wstring_st<MAX_PATH_OS> file_namew;
	//sdf::string_st_wcs_from_mbs(file_namew, filename, sdf::strfz_len(filename));

	//std::ifstream fin(filenamew.c_str(), std::ios::binary);
	std::ifstream fin(filename, std::ios::binary);

	fin.seekg(0, std::ios_base::end);
	std::ifstream::pos_type size = (int)fin.tellg();
	fin.seekg(0, std::ios_base::beg);

	//ComPtr<ID3DBlob> blob;
	//D3DCreateBlob(size, blob.GetAddressOf()));
	D3DCreateBlob(size, out_blob);

	//fin.read((char*)blob->GetBufferPointer(), size);
	fin.read(rcast<char*>(&out_blob), size);

	fin.close();

	//return blob;
}


inline HRESULT ReadDataFromFile(const char* filename, byte** data, UINT* size) {
    wchar_t file_namew[MAX_PATH_OS] = {};
	sdf::strf_assign_mbs(file_namew, sdf::strz_cap(file_namew), filename, sdf::strfz_len(filename));

#if WINVER >= _WIN32_WINNT_WIN8
	CREATEFILE2_EXTENDED_PARAMETERS extendedParams = {};
	extendedParams.dwSize = sizeof(CREATEFILE2_EXTENDED_PARAMETERS);
	extendedParams.dwFileAttributes = FILE_ATTRIBUTE_NORMAL;
	extendedParams.dwFileFlags = FILE_FLAG_SEQUENTIAL_SCAN;
	extendedParams.dwSecurityQosFlags = SECURITY_ANONYMOUS;
	extendedParams.lpSecurityAttributes = nullptr;
	extendedParams.hTemplateFile = nullptr;

	Microsoft::WRL::Wrappers::FileHandle file(CreateFile2(file_namew, GENERIC_READ, FILE_SHARE_READ, OPEN_EXISTING, &extendedParams));
#else
	Microsoft::WRL::Wrappers::FileHandle file(CreateFile(file_namew.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN | SECURITY_SQOS_PRESENT | SECURITY_ANONYMOUS, nullptr));
#endif
	if (file.Get() == INVALID_HANDLE_VALUE) {
		throw std::exception();
	}

	FILE_STANDARD_INFO fileInfo = {};
	if (!GetFileInformationByHandleEx(file.Get(), FileStandardInfo, &fileInfo, sizeof(fileInfo))) {
		throw std::exception();
	}

	if (fileInfo.EndOfFile.HighPart != 0) {
		throw std::exception();
	}

	*data = reinterpret_cast<byte*>(malloc(fileInfo.EndOfFile.LowPart));
	*size = fileInfo.EndOfFile.LowPart;

	if (!ReadFile(file.Get(), *data, fileInfo.EndOfFile.LowPart, nullptr, nullptr)) {
		throw std::exception();
	}

	return S_OK;
}

inline HRESULT ReadDataFromDDSFile(const char* filename, byte** data, UINT* offset, UINT* size) {
	if (FAILED(ReadDataFromFile(filename, data, size))) {
		return E_FAIL;
	}

	// DDS files always start with the same magic number.
	static const UINT DDS_MAGIC = 0x20534444;
	UINT magicNumber = *reinterpret_cast<const UINT*>(*data);
	if (magicNumber != DDS_MAGIC)
	{
		return E_FAIL;
	}

	struct DDS_PIXELFORMAT {
		UINT size;
		UINT flags;
		UINT fourCC;
		UINT rgbBitCount;
		UINT rBitMask;
		UINT gBitMask;
		UINT bBitMask;
		UINT aBitMask;
	};

	struct DDS_HEADER {
		UINT size;
		UINT flags;
		UINT height;
		UINT width;
		UINT pitchOrLinearSize;
		UINT depth;
		UINT mipMapCount;
		UINT reserved1[11];
		DDS_PIXELFORMAT ddsPixelFormat;
		UINT caps;
		UINT caps2;
		UINT caps3;
		UINT caps4;
		UINT reserved2;
	};

	auto ddsHeader = reinterpret_cast<const DDS_HEADER*>(*data + sizeof(UINT));
	if (ddsHeader->size != sizeof(DDS_HEADER) || ddsHeader->ddsPixelFormat.size != sizeof(DDS_PIXELFORMAT)) {
		return E_FAIL;
	}

	const ptrdiff_t ddsDataOffset = sizeof(UINT) + sizeof(DDS_HEADER);
	*offset = ddsDataOffset;
	*size = *size - ddsDataOffset;

	return S_OK;
}
}

// Same as d3d11_compile_shader_from_file
inline bool d3d12_compile_shader_from_file(const char* shader_filename, const char* sh_entry_point, const char* shader_model, ID3DBlob** out_blob) {
	if (!(is_file_exists(shader_filename))) {
		eprintfln("Cannot find shader file: %s", shader_filename);
		return false;
	}

    wchar_t shader_file_namew[MAX_PATH_OS] = {};
	sdf::strf_assign_mbs(shader_file_namew, sdf::strz_cap(shader_file_namew), shader_filename, sdf::strfz_len(shader_filename));

	//-----------
    if (!shader_filename || !sh_entry_point || !shader_model || !out_blob) {
       return false; 
       //return E_INVALIDARG;
    }

    *out_blob = nullptr;

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

    ID3DBlob* shader_blob = nullptr;
    ID3DBlob* compilation_errors = nullptr;    
	HRESULT hr = S_OK;
    //hr = D3DCompileFromFile(shader_file_namew.c_str(), nullptr, nullptr, sh_entry_point, shader_model, shader_flags, 0, &shader_blob, &compilation_errors);
    hr = D3DCompileFromFile(shader_file_namew, defines, D3D_COMPILE_STANDARD_FILE_INCLUDE, sh_entry_point, shader_model, shader_flags, 0, &shader_blob, &compilation_errors);

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

		if (shader_blob) { shader_blob->Release(); }
        return false;
    }

	com_release(compilation_errors);
    *out_blob = shader_blob;
    shader_blob = nullptr;
    return true;
}



class wm_rd3d12_2 : public wm_irenderer {
public: 
    //=============================================
    static const UINT FrameCount = 2;

    // Pipeline objects.
    ComPtr<ID3D12Device> m_device;
    ComPtr<IDXGISwapChain4> m_SwapChain;
    
    ComPtr<ID3D12Resource> m_renderTargets[FrameCount];
    //ID3D12Resource* m_render_target = nullptr;
    ComPtr<ID3D12CommandAllocator> m_commandAllocator; //mDirectCmdListAlloc
    ComPtr<ID3D12CommandQueue> m_CommandQueue;
    ComPtr<ID3D12DescriptorHeap> mRtvHeap;
    UINT mRtvDescriptorSize = 0;
    ComPtr<ID3D12DescriptorHeap> mDsvHeap;
    UINT mDsvDescriptorSize = 0;
    ComPtr<ID3D12PipelineState> m_pipelineState;
    ComPtr<ID3D12GraphicsCommandList> m_CommandList;

    ComPtr<IDXGIFactory4> mdxgiFactory;

    D3D12_VIEWPORT m_viewport;
    D3D12_RECT m_scissorRect;
    ComPtr<ID3D12RootSignature> m_rootSignature;

    // Synchronization objects.
    UINT m_frameIndex = 0; //mCurrBackBuffer
    HANDLE m_fenceEvent;
    ComPtr<ID3D12Fence> m_fence;
    UINT64 m_fenceValue = 0; //mCurrentFence
    
    //---
    ComPtr<ID3D12DescriptorHeap> m_cbvHeap;
    UINT m_cbvSrvDescriptorSize = 0;
    //-----------------------------
    //bool      mMinimized  = false;
    //bool      mMaximized  = false;
    //bool      mResizing  = false;

    
    // same as ComPtr<ID3D12Resource> m_renderTargets[FrameCount]
    //static const int SwapChainBufferCount = 2;
    //int mCurrBackBuffer = 0;
    //Microsoft::WRL::ComPtr<ID3D12Resource> mSwapChainBuffer[SwapChainBufferCount];

    Microsoft::WRL::ComPtr<ID3D12Resource> mDepthStencilBuffer;


	//UINT mCbvSrvUavDescriptorSize = 0;

    //// Set true to use 4X MSAA.  The default is false.
    bool      m4xMsaaState = false;    // 4X MSAA enabled
    UINT      m4xMsaaQuality = 0;      // quality level of 4X MSAA

	//D3D_DRIVER_TYPE md3dDriverType = D3D_DRIVER_TYPE_HARDWARE;
    DXGI_FORMAT mBackBufferFormat = DXGI_FORMAT_R8G8B8A8_UNORM;
    DXGI_FORMAT mDepthStencilFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;



	void deinit_r() {
        if(m_device != nullptr) {
	        FlushCommandQueue();
        }
	}

    

	bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) {
		set_init_params(hwnd, width, height, " : Direct3D12");

		//------------   
        UINT dxgiFactoryFlags = 0;

    #if defined(_DEBUG)
        // Enable the debug layer (requires the Graphics Tools "optional feature").
        // NOTE: Enabling the debug layer after device creation will invalidate the active device.
        ID3D12Debug* debugController;
        if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)))) {
            debugController->EnableDebugLayer();
            // Enable additional debug layers.
            dxgiFactoryFlags |= DXGI_CREATE_FACTORY_DEBUG;
        }
        com_release(debugController);
    #endif


        CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&mdxgiFactory));


        ComPtr<IDXGIAdapter1> hardwareAdapter;
        GetHardwareAdapter(mdxgiFactory.Get(), &hardwareAdapter);

        HRESULT hr = S_OK;
        hr = D3D12CreateDevice(
            hardwareAdapter.Get(),  // nullptr for default adapter
            D3D_FEATURE_LEVEL_12_0, //D3D_FEATURE_LEVEL_11_0,
            IID_PPV_ARGS(&m_device)
            );
        if (FAILED(hr)) {
            eprintfln("D3D12CreateDevice Failed.");
			//return false;
        }

        // Create Fence
        m_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence));

        CreateCommandObjects();        

    #ifdef _DEBUG
		LogAdapters();
	#endif


        // Check 4X MSAA quality support for our back buffer format.
		// All Direct3D 11 capable devices support 4X MSAA for all render 
		// target formats, so we only need to check quality support.
		D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS msQualityLevels;
		msQualityLevels.Format = mBackBufferFormat;
		msQualityLevels.SampleCount = 4;
		msQualityLevels.Flags = D3D12_MULTISAMPLE_QUALITY_LEVELS_FLAG_NONE;
		msQualityLevels.NumQualityLevels = 0;
		m_device->CheckFeatureSupport(D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS, &msQualityLevels, sizeof(msQualityLevels));
		m4xMsaaQuality = msQualityLevels.NumQualityLevels;
		assert(m4xMsaaQuality > 0 && "Unexpected MSAA quality level.");


        CreateSwapChain(hwnd, width, height, fullscreen);        

         // This sample does not support fullscreen transitions.
        //factory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_ALT_ENTER));

        create_rtv_descriptor_heap();
        create_dsv_descriptor_heap();

        // Do the initial resize code.
		resize(width, height);

		return true;
	}

    void CreateCommandObjects() {
		// Describe and create the command queue.
        D3D12_COMMAND_QUEUE_DESC queueDesc = {};
		queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
		queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
		m_device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&m_CommandQueue));

		m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(m_commandAllocator.GetAddressOf()));

		m_device->CreateCommandList(
			0,
			D3D12_COMMAND_LIST_TYPE_DIRECT,
			m_commandAllocator.Get(), // Associated command allocator
			nullptr,                   // Initial PipelineStateObject
			IID_PPV_ARGS(m_CommandList.GetAddressOf()));

		// Start off in a closed state.  This is because the first time we refer 
		// to the command list we will Reset it, and it needs to be closed before
		// calling Reset.
		m_CommandList->Close();
	}

    void CreateSwapChain(HWND hwnd, int width, int height, bool fullscreen) {
		// Release the previous swapchain we will be recreating.
		m_SwapChain.Reset();

        // Create a descriptor for the swap chain.
        DXGI_SWAP_CHAIN_DESC1 scd1 = {};
        scd1.Width = width;
        scd1.Height = height;
        scd1.Format = mBackBufferFormat; //DXGI_FORMAT_R8G8B8A8_UNORM;;
        scd1.Stereo = FALSE;
        scd1.SampleDesc.Count = m4xMsaaState ? 4 : 1; //curr_msaa_sample_count;
        scd1.SampleDesc.Quality = m4xMsaaState ? (m4xMsaaQuality - 1) : 0; //curr_msaa_sample_quality;
        scd1.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        scd1.BufferCount = FrameCount;
        scd1.Scaling = DXGI_SCALING_STRETCH;
        scd1.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;	
        scd1.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
        scd1.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;    // allow full-screen switching	

        DXGI_SWAP_CHAIN_FULLSCREEN_DESC scd1_fs = {};
        scd1_fs.RefreshRate.Numerator = 60;
        scd1_fs.RefreshRate.Denominator = 1;
        scd1_fs.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
        scd1_fs.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
        scd1_fs.Windowed = !(fullscreen);


        // Create a SwapChain from a Win32 window.   
        ComPtr<IDXGISwapChain1> swapChain1;
        mdxgiFactory->CreateSwapChainForHwnd(
            m_CommandQueue.Get(),        // Swap chain needs the queue so that it can force a flush on it.
            hwnd,
            &scd1,
            &scd1_fs,
            nullptr,
            &swapChain1
            );
       

        swapChain1.As(&m_SwapChain);
        m_frameIndex = m_SwapChain->GetCurrentBackBufferIndex();    
	}

    bool Get4xMsaaState() const {
		return m4xMsaaState;
	}

    void Set4xMsaaState(bool value, HWND hwnd, int width, int height, bool fullscreen) {
		if(m4xMsaaState != value) {
			m4xMsaaState = value;

			// Recreate the swapchain and buffers with new multisample settings.
			CreateSwapChain(hwnd, width, height, fullscreen);
			resize(width, height);
		}
	}



    void FlushCommandQueue() {
		// Advance the fence value to mark commands up to this fence point.
		m_fenceValue++;

		// Add an instruction to the command queue to set a new fence point.  Because we 
		// are on the GPU timeline, the new fence point won't be set until the GPU finishes
		// processing all the commands prior to this Signal().
		m_CommandQueue->Signal(m_fence.Get(), m_fenceValue);

		// Wait until the GPU has completed commands up to this fence point.
		if(m_fence->GetCompletedValue() < m_fenceValue) {
			HANDLE eventHandle = CreateEventExW(nullptr, nullptr, false, EVENT_ALL_ACCESS);

			// Fire event when GPU hits current fence.  
			m_fence->SetEventOnCompletion(m_fenceValue, eventHandle);

			// Wait until the GPU hits current fence event is fired.
			WaitForSingleObject(eventHandle, INFINITE);
			CloseHandle(eventHandle);
		}
	}

    void resize_internal() {
		assert(m_device);
		assert(mSwapChain);
		fm_assert(m_commandAllocator);
        fm_assert(m_fence);
    
		// Flush before changing any resources.
		FlushCommandQueue();    
    
		m_CommandList->Reset(m_commandAllocator.Get(), nullptr);

		// Release the previous resources we will be recreating.
		for (int i = 0; i < FrameCount; ++i) {
			m_renderTargets[i].Reset();
        }

		mDepthStencilBuffer.Reset();
	
		// Resize the swap chain.
		m_SwapChain->ResizeBuffers(
			FrameCount, 
			m_client_width, m_client_height, 
			mBackBufferFormat, 
			DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH);

		m_frameIndex = 0;
 
		CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHeapHandle(mRtvHeap->GetCPUDescriptorHandleForHeapStart());
		for (UINT i = 0; i < FrameCount; i++) {
			m_SwapChain->GetBuffer(i, IID_PPV_ARGS(&m_renderTargets[i]));
			m_device->CreateRenderTargetView(m_renderTargets[i].Get(), nullptr, rtvHeapHandle);
			rtvHeapHandle.Offset(1, mRtvDescriptorSize);
		}

		// Create the depth/stencil buffer and view.
        D3D12_RESOURCE_DESC depthStencilDesc = {};
		depthStencilDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
		depthStencilDesc.Alignment = 0;
		depthStencilDesc.Width = m_client_width;
		depthStencilDesc.Height = m_client_height;
		depthStencilDesc.DepthOrArraySize = 1;
		depthStencilDesc.MipLevels = 1;
		depthStencilDesc.Format = mDepthStencilFormat;
		depthStencilDesc.SampleDesc.Count = m4xMsaaState ? 4 : 1;
		depthStencilDesc.SampleDesc.Quality = m4xMsaaState ? (m4xMsaaQuality - 1) : 0;
		depthStencilDesc.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;
		depthStencilDesc.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;

        D3D12_CLEAR_VALUE optClear = {};
		optClear.Format = mDepthStencilFormat;
		optClear.DepthStencil.Depth = 1.0f;
		optClear.DepthStencil.Stencil = 0;

		D3D12_HEAP_PROPERTIES default_heap = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT);
		m_device->CreateCommittedResource(
			&default_heap,
			D3D12_HEAP_FLAG_NONE,
			&depthStencilDesc,
			D3D12_RESOURCE_STATE_COMMON,
			&optClear,
			IID_PPV_ARGS(mDepthStencilBuffer.GetAddressOf()));

		// Create descriptor to mip level 0 of entire resource using the format of the resource.
		m_device->CreateDepthStencilView(mDepthStencilBuffer.Get(), nullptr, DepthStencilView());

		D3D12_RESOURCE_BARRIER res_transition_barrier = CD3DX12_RESOURCE_BARRIER::Transition(mDepthStencilBuffer.Get(), D3D12_RESOURCE_STATE_COMMON, D3D12_RESOURCE_STATE_DEPTH_WRITE);
		// Transition the resource from its initial state to be used as a depth buffer.
		m_CommandList->ResourceBarrier(1, &res_transition_barrier);
	
		// Execute the resize commands.
		m_CommandList->Close();
		ID3D12CommandList* cmdsLists[] = { m_CommandList.Get() };
		m_CommandQueue->ExecuteCommandLists(_countof(cmdsLists), cmdsLists);

		// Wait until resize is complete.
		FlushCommandQueue();

		// Update the viewport transform to cover the client area.
		m_viewport.TopLeftX = 0.0f;
		m_viewport.TopLeftY = 0.0f;
		m_viewport.Width    = static_cast<float>(m_client_width);
		m_viewport.Height   = static_cast<float>(m_client_height);
		m_viewport.MinDepth = D3D12_MIN_DEPTH;
		m_viewport.MaxDepth = D3D12_MAX_DEPTH;

		m_scissorRect = { 0, 0, m_client_width, m_client_height };   

		mat_proj = get_proj_matrix();
	}


    ID3D12Resource* CurrentBackBuffer() const {
		return m_renderTargets[FrameCount].Get();
	}

    D3D12_CPU_DESCRIPTOR_HANDLE CurrentBackBufferView() const {
		return CD3DX12_CPU_DESCRIPTOR_HANDLE(
			mRtvHeap->GetCPUDescriptorHandleForHeapStart(),
			m_frameIndex,
			mRtvDescriptorSize);
	}

    D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView() const {
		return mDsvHeap->GetCPUDescriptorHandleForHeapStart();
	}


	// Default setup, cleanup, render func.
	void setup() {
        create_command_allocator();
        LoadAssets();
    }
	void cleanup() {
        OnDestroy();
    }	

    void execute_command_list() {
        // Execute the command list.
        ID3D12CommandList* ppCommandLists[] = { m_CommandList.Get() };
        m_CommandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);
    }

    void present_frame() {
        // Present the frame.
        m_SwapChain->Present(1, 0);
    }

	void render(float dt) {
		//clear_render_target(gm::color4(0.0, 1.0, 0.0, 1.0));
		//clear_depth_stencil(true, true, 1.0f, 0);

        // Record all the commands we need to render the scene into the command list.
        PopulateCommandList();

        execute_command_list();

        present_frame();

        WaitForPreviousFrame();
	}

	void swap_buffers() {
		//m_swap_chain->Present(0, 0);
	}


	//-----------------------------------------------------------
	void clear_render_target(const gm::color4& color_rgba) {
		m_CommandList->ClearRenderTargetView(CurrentBackBufferView(), color_rgba.data(), 0, nullptr);
	}
	void clear_depth_stencil(bool clear_depth, bool clear_stencil, float depth, uint stencil) {
		D3D12_CLEAR_FLAGS clear_flag = {}; //0;
		if (clear_depth) { clear_flag |= D3D12_CLEAR_FLAG_DEPTH; }
		if (clear_stencil) { clear_flag |= D3D12_CLEAR_FLAG_STENCIL; }    
		//m_CommandList->ClearDepthStencilView(DepthStencilView(), D3D12_CLEAR_FLAG_DEPTH | D3D12_CLEAR_FLAG_STENCIL, 1.0f, 0, 0, nullptr);
		m_CommandList->ClearDepthStencilView(DepthStencilView(), clear_flag, depth, stencil, 0, nullptr);
	}

    //-----------------------------------------------------------
	//util1

	void load_shaders_file(const char* shader_filename, ID3DBlob** out_vs_blob, ID3DBlob** out_ps_blob) {
        d3d12_compile_shader_from_file(shader_filename, "VSMain", "vs_5_0", out_vs_blob);
        d3d12_compile_shader_from_file(shader_filename, "PSMain", "ps_5_0", out_ps_blob);
	}


    

    //===============================
    // Update frame-based values.
    virtual void OnUpdate() {}

    // Helper function for acquiring the first available hardware adapter that supports Direct3D 12.
    // If no such adapter can be found, *ppAdapter will be set to nullptr.
    void GetHardwareAdapter(IDXGIFactory1* pFactory, IDXGIAdapter1** ppAdapter, bool requestHighPerformanceAdapter = false) {
        *ppAdapter = nullptr;

        IDXGIAdapter1* adapter = nullptr;;

        IDXGIFactory6* factory6;
        if (SUCCEEDED(pFactory->QueryInterface(IID_PPV_ARGS(&factory6)))) {
            for (
                UINT adapterIndex = 0;
                SUCCEEDED(factory6->EnumAdapterByGpuPreference(adapterIndex,
                    requestHighPerformanceAdapter == true ? DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE : DXGI_GPU_PREFERENCE_UNSPECIFIED,
                    IID_PPV_ARGS(&adapter)));
                ++adapterIndex) {

                DXGI_ADAPTER_DESC1 desc;
                adapter->GetDesc1(&desc);

                if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) {
                    // Don't select the Basic Render Driver adapter.
                    // If you want a software adapter, pass in "/warp" on the command line.
                    continue;
                }

                // Check to see whether the adapter supports Direct3D 12, but don't create the
                // actual device yet.
                if (SUCCEEDED(D3D12CreateDevice(adapter, D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr))) {
                    break;
                }
            }
        }

        if(adapter == nullptr) {
            for (UINT adapterIndex = 0; SUCCEEDED(pFactory->EnumAdapters1(adapterIndex, &adapter)); ++adapterIndex) {
                DXGI_ADAPTER_DESC1 desc;
                adapter->GetDesc1(&desc);

                if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) {
                    // Don't select the Basic Render Driver adapter.
                    // If you want a software adapter, pass in "/warp" on the command line.
                    continue;
                }

                // Check to see whether the adapter supports Direct3D 12, but don't create the
                // actual device yet.
                if (SUCCEEDED(D3D12CreateDevice(adapter, D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr))) {
                    break;
                }
            }
        }
    
        *ppAdapter = adapter;
        adapter = nullptr;

		//com_release(adapter);
		com_release(factory6);
    }



    virtual void OnDestroy() {
        // Ensure that the GPU is no longer referencing resources that are about to be
        // cleaned up by the destructor.
        WaitForPreviousFrame();

        CloseHandle(m_fenceEvent);
    }        
    
    

    void create_rtv_descriptor_heap() {
        // Describe and create a render target view (RTV) descriptor heap.
        D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
        rtvHeapDesc.NumDescriptors = FrameCount;
        rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
        rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
        rtvHeapDesc.NodeMask = 0;
        m_device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&mRtvHeap));

        mRtvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
    }

    void create_dsv_descriptor_heap() {
        D3D12_DESCRIPTOR_HEAP_DESC dsvHeapDesc = {};
		dsvHeapDesc.NumDescriptors = 1;
		dsvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
		dsvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
		dsvHeapDesc.NodeMask = 0;
		m_device->CreateDescriptorHeap(&dsvHeapDesc, IID_PPV_ARGS(mDsvHeap.GetAddressOf()));

        mDsvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_DSV);
    }

    
    void create_cbv_descriptor_heap_mat4() {
        // Describe and create a constant buffer view (CBV) descriptor heap.
        // Flags indicate that this descriptor heap can be bound to the pipeline 
        // and that descriptors contained in it can be referenced by a root table.
        D3D12_DESCRIPTOR_HEAP_DESC cbvHeapDesc = {};
        cbvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
        cbvHeapDesc.NumDescriptors = 1;
        cbvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;        
        cbvHeapDesc.NodeMask = 0;
        m_device->CreateDescriptorHeap(&cbvHeapDesc, IID_PPV_ARGS(&m_cbvHeap));

        m_cbvSrvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
    }    

    void create_command_allocator() {
        // tri_color,
        // Create frame resources.
        CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(mRtvHeap->GetCPUDescriptorHandleForHeapStart());

        // Create a RTV for each frame.
        for (UINT n = 0; n < FrameCount; n++) 
        {
            m_SwapChain->GetBuffer(n, IID_PPV_ARGS(&m_renderTargets[n]));
            m_device->CreateRenderTargetView(m_renderTargets[n].Get(), nullptr, rtvHandle);
            rtvHandle.Offset(1, mRtvDescriptorSize);
        }

        m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocator));
    }



    //=======================================
    // Load the sample assets.
    void LoadAssets() {
        // Create the command list.
        m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_commandAllocator.Get(), nullptr, IID_PPV_ARGS(&m_CommandList));

        // Command lists are created in the recording state, but there is nothing
        // to record yet. The main loop expects it to be closed, so close it now.
        m_CommandList->Close();

        // Create synchronization objects.
        {
            m_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence));
            m_fenceValue = 1;

            // Create an event handle to use for frame synchronization.
            m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
            if (m_fenceEvent == nullptr)
            {
                HRESULT_FROM_WIN32(GetLastError());
            }
        }
    }

    void PopulateCommandList() {
        // Reuse the memory associated with command recording.
        // Command list allocators can only be reset when the associated command lists have
        // finished execution on the GPU; apps should use fences to determine GPU execution progress.
        m_commandAllocator->Reset();

        // A command list can be reset after it has been added to the command queue via ExecuteCommandList.
		// Reusing the command list reuses memory.
        // However, when ExecuteCommandList() is called on a particular command 
        // list, that command list can then be reset at any time and must be before 
        // re-recording.
        m_CommandList->Reset(m_commandAllocator.Get(), m_pipelineState.Get());

        // Indicate that the back buffer will be used as a render target.
        D3D12_RESOURCE_BARRIER res_usage_barrier1 = 
            CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
        m_CommandList->ResourceBarrier(1, &res_usage_barrier1);

        CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(mRtvHeap->GetCPUDescriptorHandleForHeapStart(), m_frameIndex, mRtvDescriptorSize);

        // Record commands.
        const float clearColor[] = { 0.2f, 0.2f, 0.2f, 1.0f };
        m_CommandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);

        // Indicate that the back buffer will now be used to present.
        D3D12_RESOURCE_BARRIER res_usage_barrier2 = 
            CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
        m_CommandList->ResourceBarrier(1, &res_usage_barrier2);

        m_CommandList->Close();
    }

    void WaitForPreviousFrame() {
        // WAITING FOR THE FRAME TO COMPLETE BEFORE CONTINUING IS NOT BEST PRACTICE.
        // This is code implemented as such for simplicity. The D3D12HelloFrameBuffering
        // sample illustrates how to use fences for efficient resource usage and to
        // maximize GPU utilization.

        // Signal and increment the fence value.
        const UINT64 fence = m_fenceValue;
        m_CommandQueue->Signal(m_fence.Get(), fence);
        m_fenceValue++;

        // Wait until the previous frame is finished.
        if (m_fence->GetCompletedValue() < fence)
        {
            m_fence->SetEventOnCompletion(fence, m_fenceEvent);
            WaitForSingleObject(m_fenceEvent, INFINITE);
        }

        m_frameIndex = m_SwapChain->GetCurrentBackBufferIndex();
    }


    void LogAdapters() {
		UINT i = 0;
		IDXGIAdapter* adapter = nullptr;
		std::vector<IDXGIAdapter*> adapterList;
		while(mdxgiFactory->EnumAdapters(i, &adapter) != DXGI_ERROR_NOT_FOUND) {
			DXGI_ADAPTER_DESC desc;
			adapter->GetDesc(&desc);

			std::wstring text = L"***Adapter: ";
			text += desc.Description;
			text += L"\n";

			OutputDebugStringW(text.c_str());

			adapterList.push_back(adapter);
        
			++i;
		}

		for(size_t i = 0; i < adapterList.size(); ++i) {
			LogAdapterOutputs(adapterList[i]);
			com_release(adapterList[i]);
		}
	}

    void LogAdapterOutputs(IDXGIAdapter* adapter) {
		UINT i = 0;
		IDXGIOutput* output = nullptr;
		while(adapter->EnumOutputs(i, &output) != DXGI_ERROR_NOT_FOUND) {
			DXGI_OUTPUT_DESC desc;
			output->GetDesc(&desc);
        
			std::wstring text = L"***Output: ";
			text += desc.DeviceName;
			text += L"\n";
			OutputDebugStringW(text.c_str());

			LogOutputDisplayModes(output, mBackBufferFormat);

			com_release(output);

			++i;
		}
	}

    void LogOutputDisplayModes(IDXGIOutput* output, DXGI_FORMAT format) {
		UINT count = 0;
		UINT flags = 0;

		// Call with nullptr to get list count.
		output->GetDisplayModeList(format, flags, &count, nullptr);

		std::vector<DXGI_MODE_DESC> modeList(count);
		output->GetDisplayModeList(format, flags, &count, &modeList[0]);

		for(auto& x : modeList) {
			UINT n = x.RefreshRate.Numerator;
			UINT d = x.RefreshRate.Denominator;
			std::wstring text =
				L"Width = " + std::to_wstring(x.Width) + L" " +
				L"Height = " + std::to_wstring(x.Height) + L" " +
				L"Refresh = " + std::to_wstring(n) + L"/" + std::to_wstring(d) +
				L"\n";

			OutputDebugStringW(text.c_str());
		}
	}

    
};

// const_buffers also here
class wm_rd3d12_tri_color : public wm_rd3d12_2  {
public:		

    struct SceneConstantBuffer {
        //gm::vec4 offset;
        //float padding[60]; // Padding so the constant buffer is 256-byte aligned.

        gm::mat4 mat_wvp;
        float padding[48];
    };
    static_assert((sizeof(SceneConstantBuffer) % 256) == 0, "Constant Buffer size must be 256-byte aligned");

    gm::mat4 mat_world_tri = gm::mat4::k_identity();

    //ComPtr<ID3D12DescriptorHeap> m_cbvHeap;

    ComPtr<ID3D12Resource> m_constantBuffer;
    SceneConstantBuffer m_constantBufferData;
    UINT8* m_pCbvDataBegin = nullptr;


    // App resources.
    ComPtr<ID3D12Resource> m_vertexBuffer;
    D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;
    ComPtr<ID3D12Resource> m_indexBuffer;
    D3D12_INDEX_BUFFER_VIEW m_indexBufferView;

    int64 tri_num_vertices = 0;
	int64 tri_num_indices = 0;

    void setup() {
        create_command_allocator();
        create_cbv_descriptor_heap_mat4();
        LoadAssets();

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
        update_cbv_mat4();

        PopulateCommandList();
        execute_command_list();
        present_frame();

        //// swap the back and front buffers
        //mSwapChain->Present(0, 0);
        //m_frameIndex = (m_frameIndex + 1) % FrameCount;
        //// Wait until frame commands are complete.  This waiting is inefficient and is
        //// done for simplicity.  Later we will show how to organize our rendering code
        //// so we do not have to wait per frame.
        //FlushCommandQueue();
        WaitForPreviousFrame();
	}

    void create_root_signature_cbv() {
        #if 0
        // Without CBV
        // Create an empty root signature.
        CD3DX12_ROOT_SIGNATURE_DESC rootSignatureDesc;
        rootSignatureDesc.Init(0, nullptr, 0, nullptr, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

        ComPtr<ID3DBlob> signature;
        ComPtr<ID3DBlob> error;
        D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &signature, &error));
        m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&m_rootSignature)));

    #else

        // Create a root signature consisting of a descriptor table with a single CBV.
        D3D12_FEATURE_DATA_ROOT_SIGNATURE featureData = {};

        // This is the highest version the sample supports. If CheckFeatureSupport succeeds, the HighestVersion returned will not be greater than this.
        featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_1;

        if (FAILED(m_device->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData)))) {
            featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_0;
        }

        CD3DX12_DESCRIPTOR_RANGE1 ranges[1];
        CD3DX12_ROOT_PARAMETER1 rootParameters[1];

        ranges[0].Init(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1, 0, 0, D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC);
        rootParameters[0].InitAsDescriptorTable(1, &ranges[0], D3D12_SHADER_VISIBILITY_VERTEX);

        // Allow input layout and deny uneccessary access to certain pipeline stages.
        D3D12_ROOT_SIGNATURE_FLAGS rootSignatureFlags =
            D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT |
            D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS |
            D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS |
            D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS |
            D3D12_ROOT_SIGNATURE_FLAG_DENY_PIXEL_SHADER_ROOT_ACCESS;

        CD3DX12_VERSIONED_ROOT_SIGNATURE_DESC rootSignatureDesc;
        rootSignatureDesc.Init_1_1(_countof(rootParameters), rootParameters, 0, nullptr, rootSignatureFlags);

        ComPtr<ID3DBlob> signature;
        ComPtr<ID3DBlob> error;
        D3DX12SerializeVersionedRootSignature(&rootSignatureDesc, featureData.HighestVersion, &signature, &error);
        m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&m_rootSignature));

    #endif
    }

    void create_pipeline_state() {
        // Create the pipeline state, which includes compiling and loading shaders.
        ComPtr<ID3DBlob> vertexShader;
        ComPtr<ID3DBlob> pixelShader;

    #if defined(_DEBUG)
        // Enable better shader debugging with the graphics debugging tools.
        UINT compileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
    #else
        UINT compileFlags = 0;
    #endif

        // Without CBV
        //load_shaders_file(RS_SHADER_PATH2("d3d12_mss/02_HelloTriangle.hlsl"), &vertexShader, &pixelShader);
        load_shaders_file(RS_SHADER_PATH("d3d12_mss/05_HelloConstBuffers.hlsl"), &vertexShader, &pixelShader);


        // Define the vertex input layout.
        D3D12_INPUT_ELEMENT_DESC inputElementDescs[] = {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
            { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 }
        };

        // Describe and create the graphics pipeline state object (PSO).
        D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
        psoDesc.InputLayout = { inputElementDescs, _countof(inputElementDescs) };
        psoDesc.pRootSignature = m_rootSignature.Get();
        psoDesc.VS = CD3DX12_SHADER_BYTECODE(vertexShader.Get());
        psoDesc.PS = CD3DX12_SHADER_BYTECODE(pixelShader.Get());
        psoDesc.RasterizerState = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
        psoDesc.BlendState = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
        psoDesc.DepthStencilState.DepthEnable = FALSE;
        psoDesc.DepthStencilState.StencilEnable = FALSE;
        psoDesc.SampleMask = UINT_MAX;
        psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
        psoDesc.NumRenderTargets = 1;
        psoDesc.RTVFormats[0] = mBackBufferFormat; //DXGI_FORMAT_R8G8B8A8_UNORM;
        psoDesc.SampleDesc.Count = m4xMsaaState ? 4 : 1;
		psoDesc.SampleDesc.Quality = m4xMsaaState ? (m4xMsaaQuality - 1) : 0;
		psoDesc.DSVFormat = mDepthStencilFormat;
        m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&m_pipelineState));

    }

    void create_command_list() {
        // Create the command list.
        m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_commandAllocator.Get(), m_pipelineState.Get(), IID_PPV_ARGS(&m_CommandList));

        // Command lists are created in the recording state, but there is nothing
        // to record yet. The main loop expects it to be closed, so close it now.
        m_CommandList->Close();
    }

    void create_vb_ib_buffers() {
        // Create the vertex buffer.
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
		std::vector<vertex_pc> vertices_vec;
		std::vector<uint> indices_vec;
		vertices_vec.resize(tri_num_vertices);
		sdf::mem_copy(vertices_vec.data(), triangle_arr_vert_c_d3d, tri_num_vertices);
		indices_vec.resize(tri_num_indices);
		sdf::mem_copy(indices_vec.data(), triangle_arr_ind_d3d, tri_num_indices);

        const UINT vertexBufferSize = vertices_vec.size()*sizeof(vertex_pc);
        const UINT vertex_stride_in_bytes = sizeof(vertex_pc);
        const UINT indexBufferSize = indices_vec.size()*sizeof(uint);

        //---
            
        // Note: using upload heaps to transfer static data like vert buffers is not 
        // recommended. Every time the GPU needs it, the upload heap will be marshalled 
        // over. Please read up on Default Heap usage. An upload heap is used here for 
        // code simplicity and because there are very few verts to actually transfer.
        D3D12_HEAP_PROPERTIES upload_heap = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
        D3D12_RESOURCE_DESC res_desc1 = CD3DX12_RESOURCE_DESC::Buffer(vertexBufferSize);
        m_device->CreateCommittedResource(
            &upload_heap,
            D3D12_HEAP_FLAG_NONE,
            &res_desc1,
            D3D12_RESOURCE_STATE_GENERIC_READ,
            nullptr,
            IID_PPV_ARGS(&m_vertexBuffer));

        // Copy the triangle data to the vertex buffer.
        UINT8* pVertexDataBegin;
        CD3DX12_RANGE readRange(0, 0);        // We do not intend to read from this resource on the CPU.
        m_vertexBuffer->Map(0, &readRange, reinterpret_cast<void**>(&pVertexDataBegin));
        memcpy(pVertexDataBegin, vertices_vec.data(), vertexBufferSize);
        m_vertexBuffer->Unmap(0, nullptr);

        // Initialize the vertex buffer view.
        m_vertexBufferView.BufferLocation = m_vertexBuffer->GetGPUVirtualAddress();
        m_vertexBufferView.SizeInBytes = vertexBufferSize;
        m_vertexBufferView.StrideInBytes = vertex_stride_in_bytes;            

            
        D3D12_HEAP_PROPERTIES upload_heap_i = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
        D3D12_RESOURCE_DESC res_desc1_i = CD3DX12_RESOURCE_DESC::Buffer(vertexBufferSize);
        m_device->CreateCommittedResource(
            &upload_heap_i,
            D3D12_HEAP_FLAG_NONE,
            &res_desc1_i,
            D3D12_RESOURCE_STATE_GENERIC_READ,
            nullptr,
            IID_PPV_ARGS(&m_indexBuffer));

        // Copy the triangle data to the index buffer.
        UINT8* pIndexDataBegin;
        CD3DX12_RANGE readRange_i(0, 0);        // We do not intend to read from this resource on the CPU.
        m_indexBuffer->Map(0, &readRange_i, reinterpret_cast<void**>(&pIndexDataBegin));
        memcpy(pIndexDataBegin, indices_vec.data(), indexBufferSize);
        m_indexBuffer->Unmap(0, nullptr);
            
        // Initialize the index buffer view.
        m_indexBufferView.BufferLocation = m_indexBuffer->GetGPUVirtualAddress();            
        m_indexBufferView.SizeInBytes = indexBufferSize;
        m_indexBufferView.Format = DXGI_FORMAT_R32_UINT;
    }

    void create_cbv_buffer() {
        // Create the constant buffer.
        const UINT constantBufferSize = sizeof(SceneConstantBuffer);    // CB size is required to be 256-byte aligned.

        D3D12_HEAP_PROPERTIES upload_heap = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
        D3D12_RESOURCE_DESC res_desc1 = CD3DX12_RESOURCE_DESC::Buffer(constantBufferSize);
        m_device->CreateCommittedResource(
            &upload_heap,
            D3D12_HEAP_FLAG_NONE,
            &res_desc1,
            D3D12_RESOURCE_STATE_GENERIC_READ,
            nullptr,
            IID_PPV_ARGS(&m_constantBuffer));

        // Describe and create a constant buffer view.
        D3D12_CONSTANT_BUFFER_VIEW_DESC cbvDesc = {};
        cbvDesc.BufferLocation = m_constantBuffer->GetGPUVirtualAddress();
        cbvDesc.SizeInBytes = constantBufferSize;
        m_device->CreateConstantBufferView(&cbvDesc, m_cbvHeap->GetCPUDescriptorHandleForHeapStart());

        // Map and initialize the constant buffer. We don't unmap this until the
        // app closes. Keeping things mapped for the lifetime of the resource is okay.
        CD3DX12_RANGE readRange(0, 0);        // We do not intend to read from this resource on the CPU.
        m_constantBuffer->Map(0, &readRange, reinterpret_cast<void**>(&m_pCbvDataBegin));
        memcpy(m_pCbvDataBegin, &m_constantBufferData, sizeof(m_constantBufferData));

    }

    void create_sync_objects() {
        // Create synchronization objects and wait until assets have been uploaded to the GPU.
        m_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence));
        m_fenceValue = 1;

        // Create an event handle to use for frame synchronization.
        m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
        if (m_fenceEvent == nullptr)
        {
            HRESULT_FROM_WIN32(GetLastError());
        }

        // Wait for the command list to execute; we are reusing the same command 
        // list in our main loop but for now, we just want to wait for setup to 
        // complete before continuing.
        WaitForPreviousFrame();
    }

    // Load the sample assets.
    void LoadAssets() {    
        create_root_signature_cbv();
        create_pipeline_state();
        create_command_list();
        create_vb_ib_buffers();
        create_cbv_buffer();
        create_sync_objects();        
    }

    


    // Update frame-based values.
    void update_cbv_mat4() {
        //const float translationSpeed = 0.005f;
        //const float offsetBounds = 1.25f;
        //m_constantBufferData.offset.x += translationSpeed;
        //if (m_constantBufferData.offset.x > offsetBounds) {
        //    m_constantBufferData.offset.x = -offsetBounds;
        //}

        gm::mat4 mat_wvp_temp = mat_world_tri * mat_view * mat_proj;
		gm::mat4 mat_wvp_temp_t = gm::mat4_transpose(mat_wvp_temp);

        m_constantBufferData.mat_wvp = mat_wvp_temp_t;
        memcpy(m_pCbvDataBegin, &m_constantBufferData, sizeof(m_constantBufferData));
    }

    void PopulateCommandList()
    {
        // Command list allocators can only be reset when the associated 
        // command lists have finished execution on the GPU; apps should use 
        // fences to determine GPU execution progress.
        m_commandAllocator->Reset();

        // However, when ExecuteCommandList() is called on a particular command 
        // list, that command list can then be reset at any time and must be before 
        // re-recording.
        m_CommandList->Reset(m_commandAllocator.Get(), m_pipelineState.Get());

        // Set necessary state.
        m_CommandList->SetGraphicsRootSignature(m_rootSignature.Get());

        // CBV
        ID3D12DescriptorHeap* ppHeaps[] = { m_cbvHeap.Get() };
        m_CommandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);
        m_CommandList->SetGraphicsRootDescriptorTable(0, m_cbvHeap->GetGPUDescriptorHandleForHeapStart());

        // Set the viewport and scissor rect.  This needs to be reset whenever the command list is reset.
        m_CommandList->RSSetViewports(1, &m_viewport);
        m_CommandList->RSSetScissorRects(1, &m_scissorRect);

        // Indicate that the back buffer will be used as a render target.
        D3D12_RESOURCE_BARRIER res_usage_barrier1 = CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
        m_CommandList->ResourceBarrier(1, &res_usage_barrier1);

        //CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(mRtvHeap->GetCPUDescriptorHandleForHeapStart(), m_frameIndex, mRtvDescriptorSize);
        //m_CommandList->OMSetRenderTargets(1, &rtvHandle, FALSE, nullptr);
        // Specify the buffers we are going to render to.mCurrBackBuffer
		D3D12_CPU_DESCRIPTOR_HANDLE curr_bb_view = CurrentBackBufferView();
		D3D12_CPU_DESCRIPTOR_HANDLE dsv = DepthStencilView();
		m_CommandList->OMSetRenderTargets(1, &curr_bb_view, true, &dsv);

        // Record commands.
        //const float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
        //m_CommandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
        // Clear the back buffer and depth buffer.
		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

        m_CommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        m_CommandList->IASetVertexBuffers(0, 1, &m_vertexBufferView);
        m_CommandList->IASetIndexBuffer(&m_indexBufferView);

        //m_CommandList->DrawInstanced(3, 1, 0, 0);

        m_CommandList->DrawIndexedInstanced(tri_num_indices, 1, 0, 0, 0);

        // Indicate that the back buffer will now be used to present.
        D3D12_RESOURCE_BARRIER res_usage_barrier2 = CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
        m_CommandList->ResourceBarrier(1, &res_usage_barrier2);

        m_CommandList->Close();
    }

};



//===============================================================================================
class wm_rd3d12_tri_color_tex : public wm_rd3d12_2  {
public:		
    // textures
    ComPtr<ID3D12DescriptorHeap> m_srvHeap;
    UINT mSrvDescriptorSize = 0;

    static const UINT TextureWidth = 256;
    static const UINT TextureHeight = 256;
    static const UINT TexturePixelSize = 4;    // The number of bytes used to represent a pixel in the texture.

    ComPtr<ID3D12Resource> m_texture;

    // App resources.
    ComPtr<ID3D12Resource> m_vertexBuffer;
    D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;

    int64 tri_num_vertices = 0;
	int64 tri_num_indices = 0;

    void setup() {
        create_srv_descriptor_heap();
        create_command_allocator();
        LoadAssets();
    }

	void render(float dt) {
        PopulateCommandList();
        execute_command_list();
        present_frame();
        WaitForPreviousFrame();
	}

    void create_srv_descriptor_heap() {
        // Describe and create a shader resource view (SRV) heap for the texture.
        D3D12_DESCRIPTOR_HEAP_DESC srvHeapDesc = {};
        srvHeapDesc.NumDescriptors = 1;
        srvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
        srvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
        m_device->CreateDescriptorHeap(&srvHeapDesc, IID_PPV_ARGS(&m_srvHeap));

        mSrvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
    }

    

    // Load the sample assets.
    void LoadAssets()
    {
        // Create the root signature.
        {
            D3D12_FEATURE_DATA_ROOT_SIGNATURE featureData = {};

            // This is the highest version the sample supports. If CheckFeatureSupport succeeds, the HighestVersion returned will not be greater than this.
            featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_1;

            if (FAILED(m_device->CheckFeatureSupport(D3D12_FEATURE_ROOT_SIGNATURE, &featureData, sizeof(featureData))))
            {
                featureData.HighestVersion = D3D_ROOT_SIGNATURE_VERSION_1_0;
            }

            CD3DX12_DESCRIPTOR_RANGE1 ranges[1];
            ranges[0].Init(D3D12_DESCRIPTOR_RANGE_TYPE_SRV, 1, 0, 0, D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC);

            CD3DX12_ROOT_PARAMETER1 rootParameters[1];
            rootParameters[0].InitAsDescriptorTable(1, &ranges[0], D3D12_SHADER_VISIBILITY_PIXEL);

            D3D12_STATIC_SAMPLER_DESC sampler = {};
            sampler.Filter = D3D12_FILTER_MIN_MAG_MIP_POINT;
            sampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
            sampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
            sampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
            sampler.MipLODBias = 0;
            sampler.MaxAnisotropy = 0;
            sampler.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
            sampler.BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;
            sampler.MinLOD = 0.0f;
            sampler.MaxLOD = D3D12_FLOAT32_MAX;
            sampler.ShaderRegister = 0;
            sampler.RegisterSpace = 0;
            sampler.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;

            CD3DX12_VERSIONED_ROOT_SIGNATURE_DESC rootSignatureDesc;
            rootSignatureDesc.Init_1_1(_countof(rootParameters), rootParameters, 1, &sampler, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

            ComPtr<ID3DBlob> signature;
            ComPtr<ID3DBlob> error;
            D3DX12SerializeVersionedRootSignature(&rootSignatureDesc, featureData.HighestVersion, &signature, &error);
            m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&m_rootSignature));
        }

        // Create the pipeline state, which includes compiling and loading shaders.
        {
            ComPtr<ID3DBlob> vertexShader;
            ComPtr<ID3DBlob> pixelShader;

    #if defined(_DEBUG)
            // Enable better shader debugging with the graphics debugging tools.
            UINT compileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
    #else
            UINT compileFlags = 0;
    #endif

            load_shaders_file(RS_SHADER_PATH("d3d12_mss/03_HelloTexture.hlsl"), &vertexShader, &pixelShader);

            // Define the vertex input layout.
            D3D12_INPUT_ELEMENT_DESC inputElementDescs[] = {
                { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
                { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
                { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 28, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 }
            };

            // Describe and create the graphics pipeline state object (PSO).
            D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
            psoDesc.InputLayout = { inputElementDescs, _countof(inputElementDescs) };
            psoDesc.pRootSignature = m_rootSignature.Get();
            psoDesc.VS = CD3DX12_SHADER_BYTECODE(vertexShader.Get());
            psoDesc.PS = CD3DX12_SHADER_BYTECODE(pixelShader.Get());
            psoDesc.RasterizerState = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
            psoDesc.BlendState = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
            psoDesc.DepthStencilState.DepthEnable = FALSE;
            psoDesc.DepthStencilState.StencilEnable = FALSE;
            psoDesc.SampleMask = UINT_MAX;
            psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
            psoDesc.NumRenderTargets = 1;
            psoDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
            psoDesc.SampleDesc.Count = 1;
            m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&m_pipelineState));
        }

        // Create the command list.
        m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_commandAllocator.Get(), m_pipelineState.Get(), IID_PPV_ARGS(&m_CommandList));

        // Create the vertex buffer.
        {
            vertex_pct triangle_arr_vert_c_d3d[] = {
		        {-1.0, 0.0, 0.9,	1.0, 0.0, 0.0, 1.0,		0.0, 1.0}, // bottom-left red
		        { 0.0, 1.0, 0.9,	0.0, 1.0, 0.0, 1.0,		0.5, 0.0}, // top green
		        { 1.0, 0.0, 0.9,	0.0, 0.0, 1.0, 1.0,		1.0, 1.0}, // bottom-right blue
	        };
	        uint triangle_arr_ind_d3d[] = {
		        0, 1, 2,
	        };

	        isz tri_num_vertices = sdf::arr_cap(triangle_arr_vert_c_d3d);
	        isz tri_num_indices = sdf::arr_cap(triangle_arr_ind_d3d);		

	        // Load data to vector.
            std::vector<vertex_pct> vertices_vec;
		    std::vector<uint> indices_vec;
	        vertices_vec.resize(tri_num_vertices);
	        sdf::mem_copy(vertices_vec.data(), triangle_arr_vert_c_d3d, tri_num_vertices);
	        indices_vec.resize(tri_num_indices);
	        sdf::mem_copy(indices_vec.data(), triangle_arr_ind_d3d, tri_num_indices);

            const UINT vertexBufferSize = sizeof(triangle_arr_vert_c_d3d);

            // Note: using upload heaps to transfer static data like vert buffers is not 
            // recommended. Every time the GPU needs it, the upload heap will be marshalled 
            // over. Please read up on Default Heap usage. An upload heap is used here for 
            // code simplicity and because there are very few verts to actually transfer.
            D3D12_HEAP_PROPERTIES upload_heap = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
            D3D12_RESOURCE_DESC res_desc1 = CD3DX12_RESOURCE_DESC::Buffer(vertexBufferSize);
            m_device->CreateCommittedResource(
                &upload_heap,
                D3D12_HEAP_FLAG_NONE,
                &res_desc1,
                D3D12_RESOURCE_STATE_GENERIC_READ,
                nullptr,
                IID_PPV_ARGS(&m_vertexBuffer));

            // Copy the triangle data to the vertex buffer.
            UINT8* pVertexDataBegin;
            CD3DX12_RANGE readRange(0, 0);        // We do not intend to read from this resource on the CPU.
            m_vertexBuffer->Map(0, &readRange, reinterpret_cast<void**>(&pVertexDataBegin));
            memcpy(pVertexDataBegin, triangle_arr_vert_c_d3d, sizeof(triangle_arr_vert_c_d3d));
            m_vertexBuffer->Unmap(0, nullptr);

            // Initialize the vertex buffer view.
            m_vertexBufferView.BufferLocation = m_vertexBuffer->GetGPUVirtualAddress();
            m_vertexBufferView.StrideInBytes = sizeof(vertex_pct);
            m_vertexBufferView.SizeInBytes = vertexBufferSize;
        }

        // Note: ComPtr's are CPU objects but this resource needs to stay in scope until
        // the command list that references it has finished executing on the GPU.
        // We will flush the GPU at the end of this method to ensure the resource is not
        // prematurely destroyed.
        ComPtr<ID3D12Resource> textureUploadHeap;

        // Create the texture.
        {
            // Describe and create a Texture2D.
            D3D12_RESOURCE_DESC textureDesc = {};
            textureDesc.MipLevels = 1;
            textureDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            textureDesc.Width = TextureWidth;
            textureDesc.Height = TextureHeight;
            textureDesc.Flags = D3D12_RESOURCE_FLAG_NONE;
            textureDesc.DepthOrArraySize = 1;
            textureDesc.SampleDesc.Count = 1;
            textureDesc.SampleDesc.Quality = 0;
            textureDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

            D3D12_HEAP_PROPERTIES default_heap = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT);
            m_device->CreateCommittedResource(
                &default_heap,
                D3D12_HEAP_FLAG_NONE,
                &textureDesc,
                D3D12_RESOURCE_STATE_COPY_DEST,
                nullptr,
                IID_PPV_ARGS(&m_texture));

            const UINT64 uploadBufferSize = GetRequiredIntermediateSize(m_texture.Get(), 0, 1);

            // Create the GPU upload buffer.
            D3D12_HEAP_PROPERTIES upload_heap = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
            D3D12_RESOURCE_DESC res_desc1 = CD3DX12_RESOURCE_DESC::Buffer(uploadBufferSize);
            m_device->CreateCommittedResource(
                &upload_heap,
                D3D12_HEAP_FLAG_NONE,
                &res_desc1,
                D3D12_RESOURCE_STATE_GENERIC_READ,
                nullptr,
                IID_PPV_ARGS(&textureUploadHeap));

            // Copy data to the intermediate upload heap and then schedule a copy 
            // from the upload heap to the Texture2D.
            std::vector<UINT8> texture = GenerateTextureData();

            D3D12_SUBRESOURCE_DATA textureData = {};
            textureData.pData = &texture[0];
            textureData.RowPitch = TextureWidth * TexturePixelSize;
            textureData.SlicePitch = textureData.RowPitch * TextureHeight;

            UpdateSubresources(m_CommandList.Get(), m_texture.Get(), textureUploadHeap.Get(), 0, 0, 1, &textureData);
            D3D12_RESOURCE_BARRIER res_usage_barrier1 = CD3DX12_RESOURCE_BARRIER::Transition(m_texture.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);
            m_CommandList->ResourceBarrier(1, &res_usage_barrier1);

            // Describe and create a SRV for the texture.
            D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
            srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
            srvDesc.Format = textureDesc.Format;
            srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
            srvDesc.Texture2D.MipLevels = 1;
            m_device->CreateShaderResourceView(m_texture.Get(), &srvDesc, m_srvHeap->GetCPUDescriptorHandleForHeapStart());
        }
    
        // Close the command list and execute it to begin the initial GPU setup.
        m_CommandList->Close();
        ID3D12CommandList* ppCommandLists[] = { m_CommandList.Get() };
        m_CommandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

        // Create synchronization objects and wait until assets have been uploaded to the GPU.
        {
            m_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence));
            m_fenceValue = 1;

            // Create an event handle to use for frame synchronization.
            m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
            if (m_fenceEvent == nullptr)
            {
                HRESULT_FROM_WIN32(GetLastError());
            }

            // Wait for the command list to execute; we are reusing the same command 
            // list in our main loop but for now, we just want to wait for setup to 
            // complete before continuing.
            WaitForPreviousFrame();
        }
    }

    // Generate a simple black and white checkerboard texture.
    std::vector<UINT8> GenerateTextureData()
    {
        const UINT rowPitch = TextureWidth * TexturePixelSize;
        const UINT cellPitch = rowPitch >> 3;        // The width of a cell in the checkboard texture.
        const UINT cellHeight = TextureWidth >> 3;    // The height of a cell in the checkerboard texture.
        const UINT textureSize = rowPitch * TextureHeight;

        std::vector<UINT8> data(textureSize);
        UINT8* pData = &data[0];

        for (UINT n = 0; n < textureSize; n += TexturePixelSize)
        {
            UINT x = n % rowPitch;
            UINT y = n / rowPitch;
            UINT i = x / cellPitch;
            UINT j = y / cellHeight;

            if (i % 2 == j % 2)
            {
                pData[n] = 0x00;        // R
                pData[n + 1] = 0x00;    // G
                pData[n + 2] = 0x00;    // B
                pData[n + 3] = 0xff;    // A
            }
            else
            {
                pData[n] = 0xff;        // R
                pData[n + 1] = 0xff;    // G
                pData[n + 2] = 0xff;    // B
                pData[n + 3] = 0xff;    // A
            }
        }

        return data;
    }


    void PopulateCommandList()
    {
        // Command list allocators can only be reset when the associated 
        // command lists have finished execution on the GPU; apps should use 
        // fences to determine GPU execution progress.
        m_commandAllocator->Reset();

        // However, when ExecuteCommandList() is called on a particular command 
        // list, that command list can then be reset at any time and must be before 
        // re-recording.
        m_CommandList->Reset(m_commandAllocator.Get(), m_pipelineState.Get());

        // Set necessary state.
        m_CommandList->SetGraphicsRootSignature(m_rootSignature.Get());

        ID3D12DescriptorHeap* ppHeaps[] = { m_srvHeap.Get() };
        m_CommandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

        m_CommandList->SetGraphicsRootDescriptorTable(0, m_srvHeap->GetGPUDescriptorHandleForHeapStart());
        m_CommandList->RSSetViewports(1, &m_viewport);
        m_CommandList->RSSetScissorRects(1, &m_scissorRect);

        // Indicate that the back buffer will be used as a render target.
        D3D12_RESOURCE_BARRIER res_usage_barrier1 = 
            CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
        m_CommandList->ResourceBarrier(1, &res_usage_barrier1);

        CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(mRtvHeap->GetCPUDescriptorHandleForHeapStart(), m_frameIndex, mRtvDescriptorSize);
        m_CommandList->OMSetRenderTargets(1, &rtvHandle, FALSE, nullptr);

        // Record commands.
        const float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
        m_CommandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
        m_CommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        m_CommandList->IASetVertexBuffers(0, 1, &m_vertexBufferView);
        m_CommandList->DrawInstanced(3, 1, 0, 0);

        // Indicate that the back buffer will now be used to present.
        D3D12_RESOURCE_BARRIER res_usage_barrier2 = 
            CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
        m_CommandList->ResourceBarrier(1, &res_usage_barrier2);

        m_CommandList->Close();
    }

};


class wm_rd3d12_tri_color_bundles : public wm_rd3d12_2  {
public:	
    // Pipeline objects.
    ComPtr<ID3D12CommandAllocator> m_bundleAllocator;
    ComPtr<ID3D12GraphicsCommandList> m_bundle;


    //ComPtr<ID3D12Resource> m_texture;

    // App resources.
    ComPtr<ID3D12Resource> m_vertexBuffer;
    D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;

    int64 tri_num_vertices = 0;
	int64 tri_num_indices = 0;

    void setup() {
        create_command_allocator();
        // bundle frame resource
        m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_BUNDLE, IID_PPV_ARGS(&m_bundleAllocator));
        LoadAssets();
    }

	void render(float dt) {
        PopulateCommandList();
        execute_command_list();
        present_frame();
        WaitForPreviousFrame();
	}
   

    // Load the sample assets.
    void LoadAssets()
    {
        // Create an empty root signature.
        {
            CD3DX12_ROOT_SIGNATURE_DESC rootSignatureDesc;
            rootSignatureDesc.Init(0, nullptr, 0, nullptr, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

            ComPtr<ID3DBlob> signature;
            ComPtr<ID3DBlob> error;
            D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &signature, &error);
            m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&m_rootSignature));
        }

        // Create the pipeline state, which includes compiling and loading shaders.
        {
            ComPtr<ID3DBlob> vertexShader;
            ComPtr<ID3DBlob> pixelShader;

    #if defined(_DEBUG)
            // Enable better shader debugging with the graphics debugging tools.
            UINT compileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
    #else
            UINT compileFlags = 0;
    #endif

            load_shaders_file(RS_SHADER_PATH("d3d12_mss/04_HelloBundles.hlsl"), &vertexShader, &pixelShader);
 
            // Define the vertex input layout.
            D3D12_INPUT_ELEMENT_DESC inputElementDescs[] = {
                { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
                { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 }
            };

            // Describe and create the graphics pipeline state object (PSO).
            D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
            psoDesc.InputLayout = { inputElementDescs, _countof(inputElementDescs) };
            psoDesc.pRootSignature = m_rootSignature.Get();
            psoDesc.VS = CD3DX12_SHADER_BYTECODE(vertexShader.Get());
            psoDesc.PS = CD3DX12_SHADER_BYTECODE(pixelShader.Get());
            psoDesc.RasterizerState = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
            psoDesc.BlendState = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
            psoDesc.DepthStencilState.DepthEnable = FALSE;
            psoDesc.DepthStencilState.StencilEnable = FALSE;
            psoDesc.SampleMask = UINT_MAX;
            psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
            psoDesc.NumRenderTargets = 1;
            psoDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
            psoDesc.SampleDesc.Count = 1;
            m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&m_pipelineState));
        }

        // Create the command list.
        m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_commandAllocator.Get(), m_pipelineState.Get(), IID_PPV_ARGS(&m_CommandList));

        // Command lists are created in the recording state, but there is nothing
        // to record yet. The main loop expects it to be closed, so close it now.
        m_CommandList->Close();

        // Create the vertex buffer.
        {
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

            const UINT vertexBufferSize = sizeof(triangle_arr_vert_c_d3d);

            // Note: using upload heaps to transfer static data like vert buffers is not 
            // recommended. Every time the GPU needs it, the upload heap will be marshalled 
            // over. Please read up on Default Heap usage. An upload heap is used here for 
            // code simplicity and because there are very few verts to actually transfer.
            D3D12_HEAP_PROPERTIES upload_heap = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
            D3D12_RESOURCE_DESC res_desc1 = CD3DX12_RESOURCE_DESC::Buffer(vertexBufferSize);
            m_device->CreateCommittedResource(
                &upload_heap,
                D3D12_HEAP_FLAG_NONE,
                &res_desc1,
                D3D12_RESOURCE_STATE_GENERIC_READ,
                nullptr,
                IID_PPV_ARGS(&m_vertexBuffer));

            // Copy the triangle data to the vertex buffer.
            UINT8* pVertexDataBegin;
            CD3DX12_RANGE readRange(0, 0);        // We do not intend to read from this resource on the CPU.
            m_vertexBuffer->Map(0, &readRange, reinterpret_cast<void**>(&pVertexDataBegin));
            memcpy(pVertexDataBegin, triangle_arr_vert_c_d3d, sizeof(triangle_arr_vert_c_d3d));
            m_vertexBuffer->Unmap(0, nullptr);

            // Initialize the vertex buffer view.
            m_vertexBufferView.BufferLocation = m_vertexBuffer->GetGPUVirtualAddress();
            m_vertexBufferView.StrideInBytes = sizeof(vertex_pc);
            m_vertexBufferView.SizeInBytes = vertexBufferSize;
        }

        // Create and record the bundle.
        {
            m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_BUNDLE, m_bundleAllocator.Get(), m_pipelineState.Get(), IID_PPV_ARGS(&m_bundle));
            m_bundle->SetGraphicsRootSignature(m_rootSignature.Get());
            m_bundle->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
            m_bundle->IASetVertexBuffers(0, 1, &m_vertexBufferView);
            m_bundle->DrawInstanced(3, 1, 0, 0);
            m_bundle->Close();
        }

        // Create synchronization objects and wait until assets have been uploaded to the GPU.
        {
            m_device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence));
            m_fenceValue = 1;

            // Create an event handle to use for frame synchronization.
            m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
            if (m_fenceEvent == nullptr)
            {
                HRESULT_FROM_WIN32(GetLastError());
            }

            // Wait for the command list to execute; we are reusing the same command 
            // list in our main loop but for now, we just want to wait for setup to 
            // complete before continuing.
            WaitForPreviousFrame();
        }
    }

    void PopulateCommandList()
    {
        // Command list allocators can only be reset when the associated 
        // command lists have finished execution on the GPU; apps should use 
        // fences to determine GPU execution progress.
        m_commandAllocator->Reset();

        // However, when ExecuteCommandList() is called on a particular command 
        // list, that command list can then be reset at any time and must be before 
        // re-recording.
        m_CommandList->Reset(m_commandAllocator.Get(), m_pipelineState.Get());

        // Set necessary state.
        m_CommandList->SetGraphicsRootSignature(m_rootSignature.Get());
        m_CommandList->RSSetViewports(1, &m_viewport);
        m_CommandList->RSSetScissorRects(1, &m_scissorRect);

        // Indicate that the back buffer will be used as a render target.
        D3D12_RESOURCE_BARRIER res_usage_barrier1 = CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
        m_CommandList->ResourceBarrier(1, &res_usage_barrier1);

        CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(mRtvHeap->GetCPUDescriptorHandleForHeapStart(), m_frameIndex, mRtvDescriptorSize);
        m_CommandList->OMSetRenderTargets(1, &rtvHandle, FALSE, nullptr);

        // Record commands.
        const float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
        m_CommandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);

        // Execute the commands stored in the bundle.
        m_CommandList->ExecuteBundle(m_bundle.Get());

        // Indicate that the back buffer will now be used to present.
        D3D12_RESOURCE_BARRIER res_usage_barrier2 = CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
        m_CommandList->ResourceBarrier(1, &res_usage_barrier2);

        m_CommandList->Close();
    }


};


class wm_rd3d12_tri_const_framebuffers : public wm_rd3d12_2  {
public:	
    // In this sample we overload the meaning of FrameCount to mean both the maximum
    // number of frames that will be queued to the GPU at a time, as well as the number
    // of back buffers in the DXGI swap chain. For the majority of applications, this
    // is convenient and works well. However, there will be certain cases where an
    // application may want to queue up more frames than there are back buffers
    // available.
    // It should be noted that excessive buffering of frames dependent on user input
    // may result in noticeable latency in your app.
    //static const UINT FrameCount = 2;

    ComPtr<ID3D12CommandAllocator> m_commandAllocators[FrameCount];
    
    UINT64 m_fenceValues[FrameCount];


    // App resources.
    ComPtr<ID3D12Resource> m_vertexBuffer;
    D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;

    int64 tri_num_vertices = 0;
	int64 tri_num_indices = 0;

    void setup() {
        create_command_allocators_n();
        LoadAssets();
    }

	void render(float dt) {
        OnUpdate();
        PopulateCommandList();
        execute_command_list();
        present_frame();
        MoveToNextFrame();
	}


    void create_command_allocators_n() {
        CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(mRtvHeap->GetCPUDescriptorHandleForHeapStart());

        // Create a RTV and a command allocator for each frame.
        for (UINT n = 0; n < FrameCount; n++)
        {
            m_SwapChain->GetBuffer(n, IID_PPV_ARGS(&m_renderTargets[n]));
            m_device->CreateRenderTargetView(m_renderTargets[n].Get(), nullptr, rtvHandle);
            rtvHandle.Offset(1, mRtvDescriptorSize);

            m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocators[n]));
        }
    }

    

    // Load the sample assets.
    void LoadAssets()
    {
        // Create an empty root signature.
        {
            CD3DX12_ROOT_SIGNATURE_DESC rootSignatureDesc;
            rootSignatureDesc.Init(0, nullptr, 0, nullptr, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

            ComPtr<ID3DBlob> signature;
            ComPtr<ID3DBlob> error;
            D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &signature, &error);
            m_device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&m_rootSignature));
        }

        // Create the pipeline state, which includes compiling and loading shaders.
        {
            ComPtr<ID3DBlob> vertexShader;
            ComPtr<ID3DBlob> pixelShader;

    #if defined(_DEBUG)
            // Enable better shader debugging with the graphics debugging tools.
            UINT compileFlags = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
    #else
            UINT compileFlags = 0;
    #endif

            load_shaders_file(RS_SHADER_PATH("d3d12_mss/06_HelloFrameBuffering.hlsl"), &vertexShader, &pixelShader);

            // Define the vertex input layout.
            D3D12_INPUT_ELEMENT_DESC inputElementDescs[] = {
                { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
                { "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 }
            };

            // Describe and create the graphics pipeline state object (PSO).
            D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {};
            psoDesc.InputLayout = { inputElementDescs, _countof(inputElementDescs) };
            psoDesc.pRootSignature = m_rootSignature.Get();
            psoDesc.VS = CD3DX12_SHADER_BYTECODE(vertexShader.Get());
            psoDesc.PS = CD3DX12_SHADER_BYTECODE(pixelShader.Get());
            psoDesc.RasterizerState = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
            psoDesc.BlendState = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
            psoDesc.DepthStencilState.DepthEnable = FALSE;
            psoDesc.DepthStencilState.StencilEnable = FALSE;
            psoDesc.SampleMask = UINT_MAX;
            psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
            psoDesc.NumRenderTargets = 1;
            psoDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
            psoDesc.SampleDesc.Count = 1;
            m_device->CreateGraphicsPipelineState(&psoDesc, IID_PPV_ARGS(&m_pipelineState));
        }

        // Create the command list.
        m_device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_commandAllocators[m_frameIndex].Get(), m_pipelineState.Get(), IID_PPV_ARGS(&m_CommandList));

        // Command lists are created in the recording state, but there is nothing
        // to record yet. The main loop expects it to be closed, so close it now.
        m_CommandList->Close();

        // Create the vertex buffer.
        {
            // Define the geometry for a triangle.
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

            const UINT vertexBufferSize = sizeof(triangle_arr_vert_c_d3d);

            // Note: using upload heaps to transfer static data like vert buffers is not 
            // recommended. Every time the GPU needs it, the upload heap will be marshalled 
            // over. Please read up on Default Heap usage. An upload heap is used here for 
            // code simplicity and because there are very few verts to actually transfer.
            D3D12_HEAP_PROPERTIES upload_heap = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
            D3D12_RESOURCE_DESC res_desc1 = CD3DX12_RESOURCE_DESC::Buffer(vertexBufferSize);
            m_device->CreateCommittedResource(
                &upload_heap,
                D3D12_HEAP_FLAG_NONE,
                &res_desc1,
                D3D12_RESOURCE_STATE_GENERIC_READ,
                nullptr,
                IID_PPV_ARGS(&m_vertexBuffer));

            // Copy the triangle data to the vertex buffer.
            UINT8* pVertexDataBegin;
            CD3DX12_RANGE readRange(0, 0);        // We do not intend to read from this resource on the CPU.
            m_vertexBuffer->Map(0, &readRange, reinterpret_cast<void**>(&pVertexDataBegin));
            memcpy(pVertexDataBegin, triangle_arr_vert_c_d3d, sizeof(triangle_arr_vert_c_d3d));
            m_vertexBuffer->Unmap(0, nullptr);

            // Initialize the vertex buffer view.
            m_vertexBufferView.BufferLocation = m_vertexBuffer->GetGPUVirtualAddress();
            m_vertexBufferView.StrideInBytes = sizeof(vertex_pc);
            m_vertexBufferView.SizeInBytes = vertexBufferSize;
        }

        // Create synchronization objects and wait until assets have been uploaded to the GPU.
        {
            m_device->CreateFence(m_fenceValues[m_frameIndex], D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence));
            m_fenceValues[m_frameIndex]++;

            // Create an event handle to use for frame synchronization.
            m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
            if (m_fenceEvent == nullptr)
            {
                HRESULT_FROM_WIN32(GetLastError());
            }

            // Wait for the command list to execute; we are reusing the same command 
            // list in our main loop but for now, we just want to wait for setup to 
            // complete before continuing.
            WaitForGpu();
        }
    }


    void OnDestroy()
    {
        // Ensure that the GPU is no longer referencing resources that are about to be
        // cleaned up by the destructor.
        WaitForGpu();

        CloseHandle(m_fenceEvent);
    }

    void PopulateCommandList()
    {
        // Command list allocators can only be reset when the associated 
        // command lists have finished execution on the GPU; apps should use 
        // fences to determine GPU execution progress.
        m_commandAllocators[m_frameIndex]->Reset();

        // However, when ExecuteCommandList() is called on a particular command 
        // list, that command list can then be reset at any time and must be before 
        // re-recording.
        m_CommandList->Reset(m_commandAllocators[m_frameIndex].Get(), m_pipelineState.Get());

        // Set necessary state.
        m_CommandList->SetGraphicsRootSignature(m_rootSignature.Get());
        m_CommandList->RSSetViewports(1, &m_viewport);
        m_CommandList->RSSetScissorRects(1, &m_scissorRect);

        // Indicate that the back buffer will be used as a render target.
        D3D12_RESOURCE_BARRIER res_usage_barrier1 = CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
        m_CommandList->ResourceBarrier(1, &res_usage_barrier1);

        CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(mRtvHeap->GetCPUDescriptorHandleForHeapStart(), m_frameIndex, mRtvDescriptorSize);
        m_CommandList->OMSetRenderTargets(1, &rtvHandle, FALSE, nullptr);

        // Record commands.
        const float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
        m_CommandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
        m_CommandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        m_CommandList->IASetVertexBuffers(0, 1, &m_vertexBufferView);
        m_CommandList->DrawInstanced(3, 1, 0, 0);

        // Indicate that the back buffer will now be used to present.
        D3D12_RESOURCE_BARRIER res_usage_barrier2 = CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
        m_CommandList->ResourceBarrier(1, &res_usage_barrier2);

        m_CommandList->Close();
    }

    // Wait for pending GPU work to complete.
    void WaitForGpu()
    {
        // Schedule a Signal command in the queue.
        m_CommandQueue->Signal(m_fence.Get(), m_fenceValues[m_frameIndex]);

        // Wait until the fence has been processed.
        m_fence->SetEventOnCompletion(m_fenceValues[m_frameIndex], m_fenceEvent);
        WaitForSingleObjectEx(m_fenceEvent, INFINITE, FALSE);

        // Increment the fence value for the current frame.
        m_fenceValues[m_frameIndex]++;
    }

    // Prepare to render the next frame.
    void MoveToNextFrame()
    {
        // Schedule a Signal command in the queue.
        const UINT64 currentFenceValue = m_fenceValues[m_frameIndex];
        m_CommandQueue->Signal(m_fence.Get(), currentFenceValue);

        // Update the frame index.
        m_frameIndex = m_SwapChain->GetCurrentBackBufferIndex();

        // If the next frame is not ready to be rendered yet, wait until it is ready.
        if (m_fence->GetCompletedValue() < m_fenceValues[m_frameIndex])
        {
            m_fence->SetEventOnCompletion(m_fenceValues[m_frameIndex], m_fenceEvent);
            WaitForSingleObjectEx(m_fenceEvent, INFINITE, FALSE);
        }

        // Set the fence value for the next frame.
        m_fenceValues[m_frameIndex] = currentFenceValue + 1;
    }

};