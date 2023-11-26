#pragma once

#include "../rs_hdr_sdk_d3d9.h"
#include "../rs_d3d9_util.h"

#include "t2_rs_irenderer.h"

class rd3d9b : public irenderer {
public:
	IDirect3DDevice9* m_device = nullptr; 	

	ID3DXFont* m_font = nullptr;

	bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { 
		set_init_params(hwnd, width, height, " : Direct3D9b");
		HRESULT hr = S_OK;

		// Create the IDirect3D9 object.
		IDirect3D9* d3d9 = nullptr;
		d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

		if (!d3d9) {
			eprintfln("Direct3DCreate9() - FAILED");
			return false;
		}

		// Verify hardware support for specified formats in windowed and full screen modes.	
		D3DDEVTYPE deviceType = D3DDEVTYPE_HAL;
		D3DDISPLAYMODE mode = {};
		d3d9->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &mode);
		d3d9->CheckDeviceType(D3DADAPTER_DEFAULT, deviceType, mode.Format, mode.Format, true);
		d3d9->CheckDeviceType(D3DADAPTER_DEFAULT, deviceType, D3DFMT_X8R8G8B8, D3DFMT_X8R8G8B8, false);

		// Check for hardware vertex processing.
		D3DCAPS9 caps = {};
		d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, deviceType, &caps);

		DWORD devBehaviorFlags = 0;
		if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) {
			//devBehaviorFlags |= D3DCREATE_HARDWARE_VERTEXPROCESSING;
			devBehaviorFlags = D3DCREATE_HARDWARE_VERTEXPROCESSING;
		} else {
			//devBehaviorFlags |= D3DCREATE_SOFTWARE_VERTEXPROCESSING;
			devBehaviorFlags = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
		}

		// Check pure device and if pure device and HW T&L supported.
		if (caps.DevCaps & D3DDEVCAPS_PUREDEVICE &&
			devBehaviorFlags & D3DCREATE_HARDWARE_VERTEXPROCESSING) {
				devBehaviorFlags |= D3DCREATE_PUREDEVICE;
		}


		// Fill out the D3DPRESENT_PARAMETERS structure. 
		D3DPRESENT_PARAMETERS m_d3dpp = {};
		m_d3dpp.BackBufferWidth            = m_client_width;
		m_d3dpp.BackBufferHeight           = m_client_height;
		m_d3dpp.BackBufferFormat           = D3DFMT_A8R8G8B8; //D3DFMT_UNKNOWN
		m_d3dpp.BackBufferCount            = 1;
		m_d3dpp.MultiSampleType            = D3DMULTISAMPLE_NONE;
		m_d3dpp.MultiSampleQuality         = 0;
		m_d3dpp.SwapEffect                 = D3DSWAPEFFECT_DISCARD; 
		m_d3dpp.hDeviceWindow              = m_render_window;
		m_d3dpp.Windowed                   = !fullscreen;
		m_d3dpp.EnableAutoDepthStencil     = true; 
		m_d3dpp.AutoDepthStencilFormat     = D3DFMT_D24S8;
		m_d3dpp.Flags                      = 0;
		m_d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
		m_d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;

		// Create the device.
		hr = d3d9->CreateDevice(
			D3DADAPTER_DEFAULT, // primary adapter
			deviceType,         // device type
			m_render_window,    // window associated with device
			devBehaviorFlags,   // vertex processing
			&m_d3dpp,             // present parameters
			&m_device);         // return created device

		if (FAILED(hr)) {
			d3d9->Release(); 
			eprintfln("CreateDevice() - FAILED");
			return false;
		}

		// done with d3d9 object
		d3d9->Release(); 

		return true; 
	}

	void deinit_r() {
		com_release(m_device);
		com_release(m_font);
	}

	void setup() {}
	void cleanup() {}

	void render(float dt) {
		clear(gm::color4(0.0, 1.0, 0.0, 1.0));
	}

	void swap_buffers() {
		// Swap the back and front buffers.
		m_device->Present(nullptr, nullptr, nullptr, nullptr);
	}
	//-----------------------
	void clear_render_target(const gm::color4& color_rgba) {
		// Instruct the device to set each pixel on the back buffer black -
		// D3DCLEAR_TARGET: 0x00000000 (black), 0x00FF0000 (red) - and to set each pixel on
		// the depth buffer to a value of 1.0 - D3DCLEAR_ZBUFFER: 1.0f.
		//m_device->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL, 0x00FF0000, 1.0f, 0);
		//m_device->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL, D3DCOLOR_COLORVALUE(0.0, 1.0, 0.0, 1.0), 1.0f, 0);
		m_device->Clear(0, nullptr, D3DCLEAR_TARGET, gm::argb_from_color4(color_rgba), 1.0f, 0);
	}
	void clear_depth_stencil(bool clear_depth, bool clear_stencil, float depth, uint stencil) {
		uint clear_flag = 0;
		if (clear_depth) { clear_flag |= D3DCLEAR_ZBUFFER; }
		if (clear_stencil) { clear_flag |= D3DCLEAR_STENCIL; }    
		m_device->Clear(0, nullptr, clear_flag, 0x00FFFFFF, depth, stencil);
	}
	void clear(const gm::color4& color_rgba) {
		clear_render_target(color_rgba);
		clear_depth_stencil(true, true, 1.0f, 0);
	}	

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
};


#define D3D9B_TEXTURES 1

class rd3d9b_tri : public rd3d9b {
public:
	IDirect3DVertexDeclaration9* m_input_layout = nullptr;

	IDirect3DVertexBuffer9* model_vb = nullptr;
	IDirect3DIndexBuffer9* model_ib = nullptr;		
	int64 model_num_vertices = 0;
	int64 model_num_indices = 0;

	gm::mat4 mat_world_model = gm::mat4::k_identity();

	IDirect3DTexture9* tex = nullptr;


	void setup() {
		set_rs_culling(rs_cull_mode_e::cull_ccw);

		// Turn off lighting.
		m_device->SetRenderState(D3DRS_LIGHTING, false);

	#if !D3D9B_TEXTURES
		// Create vertex declaration for expressing the data layout. Conceptually, the vertex declaration is a way of 
		// programming the vertex direct memory access (DMA) and the tessellator engine of the graphics pipe.
		D3DVERTEXELEMENT9 vertex_elements_pc[] =  {
			{0, 0,  D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0},
			{0, 12, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_COLOR, 0},
			D3DDECL_END()
		};	
		m_device->CreateVertexDeclaration(vertex_elements_pc, &m_input_layout);	

		// Load data to vector.
		sdr::vector<vertex_pc> vertices_vec;
		sdr::vector<uint> indices_vec;
		fill_triangle_vertex_pc(vertices_vec, indices_vec);

		model_num_vertices = vertices_vec.size();
		model_num_indices = indices_vec.size();

		// Create the vertex buffer. 
		create_vertex_buffer(m_device, vec_size_bytes(vertices_vec), vertices_vec.data(), model_vb);
	#else
		// Create vertex declaration for expressing the data layout. Conceptually, the vertex declaration is a way of 
		// programming the vertex direct memory access (DMA) and the tessellator engine of the graphics pipe.
		D3DVERTEXELEMENT9 vertex_elements_pct[] =  {
			{0, 0,  D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0},
			{0, 12, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_COLOR, 0},
			{0, 28, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0},
			D3DDECL_END()
		};	
		m_device->CreateVertexDeclaration(vertex_elements_pct, &m_input_layout);	

		// Load data to vector.
		sdr::vector<vertex_pct> vertices_vec;
		sdr::vector<uint> indices_vec;
		fill_triangle_vertex_pct(vertices_vec, indices_vec);

		model_num_vertices = vertices_vec.size();
		model_num_indices = indices_vec.size();

		// Create the vertex buffer. 
		create_vertex_buffer(m_device, vec_size_bytes(vertices_vec), vertices_vec.data(), model_vb);

		// Create the texture and set filters.
		create_texture(m_device, RS_MEDIA_PATH("tut/d3d_fl/tex/crate1.jpg"), tex);		

		m_device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
		m_device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
		m_device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);
	#endif


		// Create the index buffer. 
		create_index_buffer(m_device, vec_size_bytes(indices_vec), indices_vec.data(), model_ib);

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);

		// Set WVP matrices.
		set_world_matrix_tri1(mat_world_model);
		set_view_matrix_tri1(mat_view);
		set_proj_matrix_tri1(mat_proj, m_client_width, m_client_height);

		m_device->SetTransform(D3DTS_VIEW, pD3DMATRIX_from_mat4(mat_view));
		m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(mat_world_model));
		m_device->SetTransform(D3DTS_PROJECTION, pD3DMATRIX_from_mat4(mat_proj));

		create_font(m_device, m_font);
	}


	void cleanup() {
		com_release(m_input_layout);
		com_release(model_vb);
		com_release(model_ib);
		com_release(tex);
	}

	void render(float dt) {
		clear(k_clear_color);
		m_device->BeginScene();

		m_device->SetVertexDeclaration(m_input_layout);	

	#if !D3D9B_TEXTURES
		// Set vertex buffer
		m_device->SetStreamSource(0, model_vb, 0, sizeof(vertex_pc));
	#else
		m_device->SetStreamSource(0, model_vb, 0, sizeof(vertex_pct));
		m_device->SetTexture(0, tex);
	#endif

		// Set index buffer
		m_device->SetIndices(model_ib);

		// Draw one triangle.
		int num_triangles = model_num_indices/3;
		//m_device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, num_triangles); //vertex buffer only
		m_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, model_num_vertices, 0, num_triangles);

		draw_font(m_device, m_font, "Hello World");

		m_device->EndScene();		
	}
};