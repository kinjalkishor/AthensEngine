#pragma once

#include "tut_renderer.h"

#include "t2_rs_d3d9_hdr.h"

namespace tdg 
{

}



class rtdg_d3d9b : public tdg_irenderer {
public:
	IDirect3DDevice9* Device = nullptr;


	bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) { 
		//set_viewport(0.0f, 0.0f, width, height);
		if (!hwnd) { eprintfln("Window Handle passed is null."); }
		//m_render_window = hwnd;
		sys_win_title_append(hwnd, " : rtdg_d3d9b");
		m_aspect_ratio = sdf::get_aspect_ratio(width, height);
		//------------
		
		HRESULT hr = 0;

		// Step 1: Create the IDirect3D9 object.

		IDirect3D9* d3d9 = 0;
		d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

		if( !d3d9 )
		{
			printfln("Direct3DCreate9() - FAILED");
			return false;
		}

		// Step 2: Check for hardware vp.
		D3DDEVTYPE deviceType = D3DDEVTYPE_HAL;

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
		d3dpp.Windowed                   = !fullscreen;
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
			&Device);            // return created device

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
				&Device);

			if( FAILED(hr) )
			{
				d3d9->Release(); // done with d3d9 object
				printfln("CreateDevice() - FAILED");
				return false;
			}
		}

		d3d9->Release(); // done with d3d9 object
	
		return true;
	}

	void deinit_r() {
		com_release(Device);
	}

	void setup() {}

	void cleanup() {}

	void render(float dt) {
			// Instruct the device to set each pixel on the back buffer black -
			// D3DCLEAR_TARGET: 0x00000000 (black) - and to set each pixel on
			// the depth buffer to a value of 1.0 - D3DCLEAR_ZBUFFER: 1.0f.
			Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x0000FF00, 1.0f, 0);
	}

	void swap_buffers() {
		// Swap the back and front buffers.
		Device->Present(0, 0, 0, 0);
	}	
};

class rtdg_d3d9b_tri_white : public rtdg_d3d9b {
public:
	void setup() {}
	void cleanup() {}
	void render(float dt) {}
};

