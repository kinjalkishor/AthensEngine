#if defined(_MSC_VER)		
	#pragma comment(lib, "user32.lib")
	#pragma comment(lib, "gdi32.lib")
#endif

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdio.h>

#include "bs_types.h"
#include "bs_lib.h"

#include "rs_hdr_sdk_d3d9.h"

#include <timeapi.h>
#pragma comment(lib, "winmm.lib")

#include "bs_gmath.h"


LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);


const int Width  = 640;
const int Height = 480;


struct Vertex
{
	Vertex(){}

	Vertex(float x, float y, float z)
	{
		_x = x;	 _y = y;  _z = z;
	}

	float _x, _y, _z;

	static const DWORD FVF;
};
const DWORD Vertex::FVF = D3DFVF_XYZ;


class rs_d3d9b {
public:
	IDirect3DDevice9* Device = 0; 
	IDirect3DVertexBuffer9* Triangle = 0;                                      


	bool InitD3D(HINSTANCE hInstance, int width, int height, bool windowed, D3DDEVTYPE deviceType, IDirect3DDevice9** device) {
		const wchar_t* APP_CLASS_NAME = L"Direct3D9App";

		//
		// Create the main application window.
		//

		WNDCLASS wc;

		wc.style         = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc   = (WNDPROC)MainWndProc; 
		wc.cbClsExtra    = 0;
		wc.cbWndExtra    = 0;
		wc.hInstance     = hInstance;
		wc.hIcon         = LoadIcon(0, IDI_APPLICATION);
		wc.hCursor       = LoadCursor(0, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wc.lpszMenuName  = 0;
		wc.lpszClassName = APP_CLASS_NAME; //L"Direct3D9App";

		if( !RegisterClass(&wc) ) 
		{
			::MessageBox(0, L"RegisterClass() - FAILED", 0, 0);
			return false;
		}
		
		HWND hwnd = 0;

		//-----------------
		//hwnd = ::CreateWindow(L"Direct3D9App", L"Direct3D9App", 
		//	WS_EX_TOPMOST,
		//	0, 0, width, height,
		//	0 /*parent hwnd*/, 0 /* menu */, hInstance, 0 /*extra*/); 

		//if( !hwnd )
		//{
		//	::MessageBox(0, L"CreateWindow() - FAILED", 0, 0);
		//	return false;
		//}

		//::ShowWindow(hwnd, SW_SHOW);
		//::UpdateWindow(hwnd);


		//-------------------
		int xpos = 10;
		int ypos = 50;
		uint dwStyle = 0;
		uint dwExStyle = 0;
		dwStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPSIBLINGS|WS_CLIPCHILDREN;
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

		int x, y, w, h;
		RECT window_rect = {0, 0, width, height};
		AdjustWindowRectEx(&window_rect, dwStyle, false, dwExStyle);
		x = xpos + window_rect.left;
		y = ypos + window_rect.top;
		w = window_rect.right - window_rect.left;
		h = window_rect.bottom - window_rect.top;	

		hwnd = CreateWindowExW(dwExStyle,					
							APP_CLASS_NAME,			        
							L"Direct3D9App",	 		
							dwStyle,
							x, y, w, h,
							nullptr, nullptr, hInstance, nullptr);									

		if (!hwnd) {							
			printf("Cannot Create Window.\n");
			return false;
		}  
		
		ShowWindow(hwnd, SW_SHOW);   	
		UpdateWindow(hwnd); 
		SetForegroundWindow(hwnd);						
		SetFocus(hwnd);	
		//-------------------

		//
		// Init D3D: 
		//

		HRESULT hr = 0;

		// Step 1: Create the IDirect3D9 object.

		IDirect3D9* d3d9 = 0;
		d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

		if( !d3d9 ) {
			::MessageBox(0, L"Direct3DCreate9() - FAILED", 0, 0);
			return false;
		}

		// Step 2: Check for hardware vp.

		D3DCAPS9 caps;
		d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, deviceType, &caps);

		int vp = 0;
		if( caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT )
			vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
		else
			vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

		// Step 3: Fill out the D3DPRESENT_PARAMETERS structure.
 
		D3DPRESENT_PARAMETERS d3dpp;
		d3dpp.BackBufferWidth            = width;
		d3dpp.BackBufferHeight           = height;
		d3dpp.BackBufferFormat           = D3DFMT_A8R8G8B8;
		d3dpp.BackBufferCount            = 1;
		d3dpp.MultiSampleType            = D3DMULTISAMPLE_NONE;
		d3dpp.MultiSampleQuality         = 0;
		d3dpp.SwapEffect                 = D3DSWAPEFFECT_DISCARD; 
		d3dpp.hDeviceWindow              = hwnd;
		d3dpp.Windowed                   = windowed;
		d3dpp.EnableAutoDepthStencil     = true; 
		d3dpp.AutoDepthStencilFormat     = D3DFMT_D24S8;
		d3dpp.Flags                      = 0;
		d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
		d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;

		// Step 4: Create the device.

		hr = d3d9->CreateDevice(
			D3DADAPTER_DEFAULT, // primary adapter
			deviceType,         // device type
			hwnd,               // window associated with device
			vp,                 // vertex processing
			&d3dpp,             // present parameters
			device);            // return created device

		if( FAILED(hr) )
		{
			// try again using a 16-bit depth buffer
			d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
		
			hr = d3d9->CreateDevice(
				D3DADAPTER_DEFAULT,
				deviceType,
				hwnd,
				vp,
				&d3dpp,
				device);

			if( FAILED(hr) )
			{
				d3d9->Release(); // done with d3d9 object
				::MessageBox(0, L"CreateDevice() - FAILED", 0, 0);
				return false;
			}
		}

		d3d9->Release(); // done with d3d9 object
	
		return true;
	}

	void deinit() {
		Device->Release();
	}

	bool Setup() {
		//
		// Create the vertex buffer.
		//

		Device->CreateVertexBuffer(
			3 * sizeof(Vertex), // size in bytes
			D3DUSAGE_WRITEONLY, // flags
			Vertex::FVF,        // vertex format
			D3DPOOL_MANAGED,    // managed memory pool
			&Triangle,          // return create vertex buffer
			0);                 // not used - set to 0

		//
		// Fill the buffers with the triangle data.
		//

		Vertex* vertices;
		Triangle->Lock(0, 0, (void**)&vertices, 0);

		vertices[0] = Vertex(-1.0f, 0.0f, 2.0f);
		vertices[1] = Vertex( 0.0f, 1.0f, 2.0f);
		vertices[2] = Vertex( 1.0f, 0.0f, 2.0f);

		Triangle->Unlock();

		//
		// Set the projection matrix.
		//

		D3DXMATRIX proj;
		D3DXMatrixPerspectiveFovLH(
				&proj,                        // result
				D3DX_PI * 0.5f,               // 90 - degrees
				(float)Width / (float)Height, // aspect ratio
				1.0f,                         // near plane
				1000.0f);                     // far plane
		Device->SetTransform(D3DTS_PROJECTION, &proj);


		// Set wireframe mode render state.
		//Device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

		return true;
	}

	void Cleanup() {
		com_release(Triangle);
	}

	void Display(float timeDelta) {
		Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);
		Device->BeginScene();

		Device->SetStreamSource(0, Triangle, 0, sizeof(Vertex));
		Device->SetFVF(Vertex::FVF);

		// Draw one triangle.
		Device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);

		Device->EndScene();
		Device->Present(0, 0, 0, 0);
	}

};




LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch( msg ) {
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
		
	case WM_KEYDOWN:
		if( wParam == VK_ESCAPE )
			::DestroyWindow(hwnd);
		break;
	}
	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}


int WINAPI WinMain(HINSTANCE hinstance,
				   HINSTANCE prevInstance, 
				   PSTR cmdLine,
				   int showCmd)
{
	rs_d3d9b* rs = new rs_d3d9b;

	if(!rs->InitD3D(hinstance, Width, Height, true, D3DDEVTYPE_HAL, &rs->Device))
	{
		::MessageBox(0, L"InitD3D() - FAILED", 0, 0);
		return 0;
	}
		
	if(!rs->Setup())
	{
		::MessageBox(0, L"Setup() - FAILED", 0, 0);
		return 0;
	}
	

	MSG msg;
	::ZeroMemory(&msg, sizeof(MSG));

	static float lastTime = (float)timeGetTime(); 

	while(msg.message != WM_QUIT)
	{
		if(::PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
		else
        {	
			float currTime  = (float)timeGetTime();
			float timeDelta = (currTime - lastTime)*0.001f;

			rs->Display(timeDelta);

			lastTime = currTime;
        }
    }

	rs->Cleanup();

	rs->deinit();

	delete rs;

	return msg.wParam;
}