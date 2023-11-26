#pragma once

#include "base_gmath.h"

#include "t3_rs_irenderer.h"

#include "t2_rs_d3d9_hdr.h"

#include "base_win_util.h"

class rd3d9b : public irenderer {
public:
	IDirect3DDevice9* m_device = 0; 	

	bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) {
		sys_win_title_append(hwnd, " : Direct3D9b");
		m_aspect_ratio = sdf::get_aspect_ratio(width, height);
		//m_width = width;
		//m_height = height;

		D3DDEVTYPE deviceType = D3DDEVTYPE_HAL;

		// Init D3D: 
		HRESULT hr = 0;

		// Step 1: Create the IDirect3D9 object.
		IDirect3D9* d3d9 = 0;
		d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

		if( !d3d9 ) {
			printfln("Direct3DCreate9() - FAILED");
			return false;
		}

		// Step 2: Check for hardware vp.
		D3DCAPS9 caps;
		d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, deviceType, &caps);

		int vp = 0;
		//if( caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT ) {
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;

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
			&m_device);            // return created device

		if( FAILED(hr) ) {
			d3d9->Release(); // done with d3d9 object
			printfln("CreateDevice() - FAILED");
			return false;

		}

		d3d9->Release(); // done with d3d9 object

		return true;
	}

	void deinit_r() {
		m_device->Release();
	}

	void setup() {}
	void cleanup() {}

	void render(float dt) {}

	void swap_buffers() {
		m_device->Present(0, 0, 0, 0);
	}
};



class rd3d9b_tri : public rd3d9b {
public:
	IDirect3DVertexDeclaration9* m_input_layout = nullptr;	
	IDirect3DVertexBuffer9* triangle_m_vb = nullptr;
	IDirect3DIndexBuffer9* triangle_m_ib = nullptr;

	void setup() {
		m_device->SetRenderState(D3DRS_LIGHTING, false);

		D3DVERTEXELEMENT9 vertex_elements_pc[] =  {
			{0, 0,  D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0},
			{0, 12, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_COLOR, 0},
			D3DDECL_END()
		};	
		m_device->CreateVertexDeclaration(vertex_elements_pc, &m_input_layout);	

		// Create the vertex buffer.
		m_device->CreateVertexBuffer(
			3 * sizeof(vertex_pc), // size in bytes
			D3DUSAGE_WRITEONLY, // flags
			0,        // vertex format
			D3DPOOL_MANAGED,    // managed memory pool
			&triangle_m_vb,          // return create vertex buffer
			nullptr);                 // not used - set to 0


		// Fill the buffers with the triangle data.
		vertex_pc* vertices;
		triangle_m_vb->Lock(0, 0, (void**)&vertices, 0);
		vertices[0] = vertex_pc(-1.0f, 0.0f, 2.0f, 1.0, 0.0, 0.0, 1.0);
		vertices[1] = vertex_pc( 0.0f, 1.0f, 2.0f, 0.0, 1.0, 0.0, 1.0);
		vertices[2] = vertex_pc( 1.0f, 0.0f, 2.0f, 0.0, 0.0, 1.0, 1.0);
		triangle_m_vb->Unlock();


		m_device->CreateIndexBuffer(3 * sizeof(uint), D3DUSAGE_WRITEONLY, D3DFMT_INDEX32, D3DPOOL_MANAGED, &triangle_m_ib, nullptr);  
		uint* indices = nullptr;
		triangle_m_ib->Lock(0, 0, (void**)&indices, 0);
		indices[0] = 0;
		indices[1] = 1;
		indices[2] = 2;
		triangle_m_ib->Unlock();  		

		// Set the projection matrix.
		D3DXMATRIX proj;
		D3DXMatrixPerspectiveFovLH(
				&proj,                        // result
				D3DX_PI * 0.5f,               // 90 - degrees
				m_aspect_ratio,					// aspect ratio
				1.0f,                         // near plane
				1000.0f);                     // far plane
		m_device->SetTransform(D3DTS_PROJECTION, &proj);

		// Set wireframe mode render state.
		//m_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	}

	void cleanup() {
		com_release(triangle_m_vb);
		com_release(triangle_m_ib);
	}

	void render(float dt) { 
		m_device->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL, 
			gm::argb_from_color4(gm::color4(0.2, 0.2, 0.2, 1.0)), 1.0f, 0);
		m_device->BeginScene();

		m_device->SetStreamSource(0, triangle_m_vb, 0, sizeof(vertex_pc));
		m_device->SetVertexDeclaration(m_input_layout);	

		m_device->SetIndices(triangle_m_ib);

		// Draw one triangle.
		//m_device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
		m_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 3, 0, 3/3);

		m_device->EndScene();		
	}

};

