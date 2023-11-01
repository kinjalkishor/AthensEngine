#pragma once

#include "t2_ex_rs_d3d9b.h"
#include "t2_ex_rs_d3d9b_util.h"
#include "../base_gmath_ex.h"


class rd3d9b_tri_color0 : public rd3d9b  {
public:
	IDirect3DVertexBuffer9* Triangle = nullptr;

	struct vertex_pcd3d {
		float x, y, z;
		D3DCOLOR c;
	};
	const DWORD vertex_pcd3d_FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE;
	//const DWORD vertex_pnt_FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1;	

	void setup() {
		// Set Render Pipeline state.
		// Turn off lighting.
		m_device->SetRenderState(D3DRS_LIGHTING, false);
		//m_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
		//m_device->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_FLAT);
		////m_device->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD); //default		

		std::vector<vertex_pcd3d> tri_buf;
		tri_buf.resize(3);
		tri_buf[0] = vertex_pcd3d(-1.0, 0.0, 0.9,	D3DCOLOR_XRGB(255,   0,   0));
		tri_buf[1] = vertex_pcd3d( 0.0, 1.0, 0.9,	D3DCOLOR_XRGB(  0, 255,   0));
		tri_buf[2] = vertex_pcd3d( 1.0, 0.0, 0.9,	D3DCOLOR_XRGB(  0,   0, 255));

		// Create the vertex buffer.
		m_device->CreateVertexBuffer(3*sizeof(vertex_pcd3d), D3DUSAGE_WRITEONLY, 
			vertex_pcd3d_FVF, D3DPOOL_MANAGED, &Triangle, nullptr);

		// Fill the buffer with the triangle data.
		vertex_pcd3d* v;
		//Triangle->Lock(0, sizeof(vertices), (void**)&v, 0);	
		Triangle->Lock(0, 0, (void**)&v, 0);		
		//v[0] = vertex_pcd3d(-1.0, 0.0, 0.9,	D3DCOLOR_XRGB(255,   0,   0));
		//v[1] = vertex_pcd3d( 0.0, 1.0, 0.9,	D3DCOLOR_XRGB(  0, 255,   0));
		//v[2] = vertex_pcd3d( 1.0, 0.0, 0.9,	D3DCOLOR_XRGB(  0,   0, 255));
		//sdf::copy_a(&v[0], tri_buf.data(), 3);
		sdf::mem_copy(&v[0], tri_buf.data(), 3);		
		Triangle->Unlock();
	}

	void render(float dt) {
		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

		m_device->BeginScene();

		m_device->SetStreamSource(0, Triangle, 0, sizeof(vertex_pcd3d));
		m_device->SetFVF(vertex_pcd3d_FVF);

		// Draw one triangle.
		m_device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);

		m_device->EndScene();
	}

	void cleanup() {
		com_release(Triangle);
	}
};


class rd3d9b_font_mesh : public rd3d9b  {
public:
	gm::mat4 mat_world_tri = gm::mat4::k_identity();
	D3DMATERIAL9 mtrl0;
	d3dx9_mesh m_font_mesh;

	void create_font_d3dx_create_text(const char* text) {
		sdf::wstring_st<255> wtext;
		sdf::string_st_wcs_from_mbs(wtext, text, sdf::strfz_len(text));


		LOGFONTW lf = {};
		create_log_font(lf);

		// Get a handle to a device context.
		HDC hdc = CreateCompatibleDC(0);
		HFONT hFont;
		HFONT hFontOld;
		// Create the font and select it with the device context.
		hFont = CreateFontIndirectW(&lf);
		hFontOld = (HFONT)SelectObject(hdc, hFont); 
		// Create the text mesh based on the selected font in the HDC.
		D3DXCreateTextW(m_device, hdc, wtext.c_str(), 0.001f, 0.4f, &m_font_mesh.data, nullptr, 0);
		// Restore the old font and free the acquired HDC.
		SelectObject(hdc, hFontOld);
		DeleteObject(hFont);
		DeleteDC(hdc);
	}
	void draw_font_d3dx_create_text() {
		m_font_mesh.data->DrawSubset(0);
	}

	void setup() {	
		set_rs_culling(rs_cull_mode_e::cull_ccw);
		//set_rs_lighting(false);

		create_font_d3dx_create_text("Font Mesh");

		mtrl0 = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::yellow));

		// Directional light.
		gm::vec3 ddir(0.0f, -0.5f, 1.0f);
		gm::color4 dc = gm::cc::white;
		rs_light_directional dir_light(dc, ddir);

		D3DLIGHT9 light0 = D3DLIGHT9_from_rs_light_directional(dir_light);
		m_device->SetLight(0, &light0);		
		m_device->LightEnable(0, true);

		set_light_render_state();
		
		//--------------------------
		m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(mat_world_tri));

		// View Matrix
		// Position and aim the camera.
		gm::vec3 position(0.0f, 1.5f, -3.3f);
		gm::vec3 target(0.0f, 0.0f, 0.0f);
		gm::vec3 up(0.0f, 1.0f, 0.0f);
		mat_view = gm::mat4_look_at_lh(position, target, up);
		m_device->SetTransform(D3DTS_VIEW, pD3DMATRIX_from_mat4(mat_view));

		mat_proj = set_projection_matrix();
		m_device->SetTransform(D3DTS_PROJECTION, pD3DMATRIX_from_mat4(mat_proj));
	}
	void render(float dt) {
		// Update: Spin the 3D text.
		gm::mat4 yRot, T;
		static float y = 0.0f;
		yRot = gm::mat4_rotation_y(y);
		y += dt;
		if (y >= 6.28f) {
			y = 0.0f;
		}
		T = gm::mat4_translation(gm::vec3(-1.6f, 0.0f, 0.0f));
		T = T * yRot;
		m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(T));

		//--------------
		// Render
		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

		m_device->BeginScene();

		m_device->SetMaterial(&mtrl0);
		draw_font_d3dx_create_text();

		m_device->EndScene();
	}
};


class rd3d9b_multi_cube : public rd3d9b  {
public:	
	d3d9_input_layout m_input_layout;

	gm::mat4 model_mat_world[5];
	d3d9b_model model[5];
	d3d9_texture tex[5];
	D3DMATERIAL9 mtrl[5];		

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
		
	#if 1
		for_range (i, 0, 5) {
			create_texture(RS_MEDIA_PATH("nw_tex/checker_white.png"), tex[i].data);
		}
	#else
		create_texture(RS_MEDIA_PATH("nw_tex/colors/lt_turqoise.png"), tex[0].data);
		create_texture(RS_MEDIA_PATH("nw_tex/colors/gold.png"), tex[1].data);
		create_texture(RS_MEDIA_PATH("nw_tex/colors/lime.png"), tex[2].data);
		create_texture(RS_MEDIA_PATH("nw_tex/colors/orange.png"), tex[3].data);
		create_texture(RS_MEDIA_PATH("nw_tex/colors/rose.png"), tex[4].data);
	#endif

		set_sampler_state(rs_texture_filter_e::texf_anisotropic, 0);
		

		// model positions in world.
		model_mat_world[0] = gm::mat4_translation(gm::vec3(0.0f, 0.0f,  0.0f));
		model_mat_world[1] = gm::mat4_translation(gm::vec3(-5.0f, 0.0f,  5.0f));
		model_mat_world[2] = gm::mat4_translation(gm::vec3(5.0f, 0.0f,  5.0f));
		model_mat_world[3] = gm::mat4_translation(gm::vec3(-5.0f, 0.0f, 15.0f));
		model_mat_world[4] = gm::mat4_translation(gm::vec3(4.0f, 0.0f, 10.0f));

		mtrl[0] = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::red));
		mtrl[1] = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::blue));
		mtrl[2] = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::green));
		mtrl[3] = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::yellow));
		mtrl[4] = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::white));

		// Load data to vector.
		rs_model<vertex_ptn> rmodel0;	
		fill_cube_vertex_ptn(rmodel0.vertices_vec, rmodel0.indices_vec);		

		for_range (i, 0, 5) {			
			create_model_rsmodel(model[i], rmodel0, m_input_layout.data, tex[i].data, &mtrl[i]);
		}
		
		rmodel0.clear_memory();



		// Directional light.
		gm::vec3 ddir(1.0f, -1.0f, 0.0f);
		gm::color4 dc = gm::cc::white;
		rs_light_directional dir_light(dc, ddir);

		D3DLIGHT9 light0 = D3DLIGHT9_from_rs_light_directional(dir_light);
		m_device->SetLight(0, &light0);		
		m_device->LightEnable(0, true);

		set_light_render_state();
		
		//----------------------------------------

		m_camera.set_position(gm::vec3(0.0f, 3.0f, -8.0f));
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
		
		for_range (i, 0, 5) {
			m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(model_mat_world[i]));
			draw_model(model[i]);
		}

		m_device->EndScene();
	}

	void cleanup() {		
	}
};


class rd3d9b_multi_d3dx9mesh : public rd3d9b  {
public:	
	d3d9_input_layout m_input_layout;

	d3d9_texture tex[5];
	D3DMATERIAL9 mtrl[5];	

	d3dx9_mesh mesh[5];
	gm::mat4 mesh_mat_world[5];

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
		

		mesh_mat_world[0] = gm::mat4_translation(gm::vec3(0.0f, 0.0f,  0.0f));
		mesh_mat_world[1] = gm::mat4_translation(gm::vec3(-5.0f, 0.0f,  5.0f));
		mesh_mat_world[2] = gm::mat4_translation(gm::vec3(5.0f, 0.0f,  5.0f));
		mesh_mat_world[3] = gm::mat4_translation(gm::vec3(-5.0f, 0.0f, 15.0f));
		mesh_mat_world[4] = gm::mat4_translation(gm::vec3(4.0f, 0.0f, 10.0f));

		mtrl[0] = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::red));
		mtrl[1] = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::blue));
		mtrl[2] = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::green));
		mtrl[3] = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::yellow));
		mtrl[4] = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::white));


		// ID3DX MESH
		D3DXCreateTeapot(m_device, &mesh[0].data, 0);
		D3DXCreateBox(m_device, 2.0f, 2.0f, 2.0f, &mesh[1].data, 0);
		// cylinder is built aligned on z-axis
		D3DXCreateCylinder(m_device, 1.0f, 1.0f, 3.0f, 20, 20, &mesh[2].data, 0);
		D3DXCreateTorus(m_device, 1.0f, 3.0f, 20, 20, &mesh[3].data, 0);
		D3DXCreateSphere(m_device, 1.0f, 20, 20, &mesh[4].data, 0);


		// Directional light.
		gm::vec3 ddir(1.0f, -1.0f, 0.0f);
		gm::color4 dc = gm::cc::white;
		rs_light_directional dir_light(dc, ddir);

		D3DLIGHT9 light0 = D3DLIGHT9_from_rs_light_directional(dir_light);
		m_device->SetLight(0, &light0);		
		m_device->LightEnable(0, true);

		set_light_render_state();
		
		//----------------------------------------

		m_camera.set_position(gm::vec3(0.0f, 3.0f, -8.0f));
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
		
		for_range (i, 0, 5) {
			m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(mesh_mat_world[i]));
			m_device->SetMaterial(&mtrl[i]);			
			if (mesh[i].data) {
				mesh[i].data->DrawSubset(0);
			}
		}

		m_device->EndScene();
	}

	void cleanup() {		
	}
};


class rd3d9b_zbuffer : public rd3d9b  {
public:	
	d3d9_input_layout m_input_layout;

	gm::mat4 model_mat_world[2];
	d3d9b_model model[2];
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

		model_mat_world[0] = gm::mat4_translation(gm::vec3(0.0, 0.0, -1.0f));	// near
		model_mat_world[1] = gm::mat4_translation(gm::vec3(0.0, -0.2, 2.0f));	// far  

		// Load data to vector.
		rs_model<vertex_pct> rmodel0;	
		fill_triangle_vertex_pct(rmodel0.vertices_vec, rmodel0.indices_vec);	

		for_range(i, 0, 2) {
			create_model_basic(model[i], rmodel0.vertices_vec.data(), rmodel0.vertices_vec.size(), rmodel0.vstride(), 
				rmodel0.indices_vec.data(), rmodel0.indices_vec.size(), rmodel0.istride(), m_input_layout.data, tex0.data);
		}


		rmodel0.clear_memory();		

		//----------------------------------------

		// World Matrix
		//model0.mat_world = gm::mat4_translation(gm::vec3(1.25f, 0.0f, 0.0f));
		//model0.mat_world = gm::mat4_scaling(gm::vec3(2.0, 1.0, 1.0));
		// Rotating on x axis, since x axis is same while y or z can be up.
		//model0.mat_world = gm::mat4_rotation_x(mf::deg_to_rad<float>(30));
		//m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(model0_mat_world));

		m_camera.set_position(gm::vec3(0.0f, 0.0f, -3.0f));
		mat_proj = set_projection_matrix();
		m_device->SetTransform(D3DTS_PROJECTION, pD3DMATRIX_from_mat4(mat_proj));
		
	}


	void render(float dt) {
		// Set the z-buffer.
		// crate textured triangle is drawn second and should rendered behind
		// as its' depth buffer z value is 2.0 > -2.0 of checker textured triangle
		// But when depth buffer is disabled 2nd crate triangle overwrites 1st drawn triangle.
		if (get_async_key_state('U')) { m_device->SetRenderState(D3DRS_ZENABLE, false); }
		if (get_async_key_state('I')) { m_device->SetRenderState(D3DRS_ZENABLE, true); }	

		//-----------------
		update_camera(dt);
		mat_view = m_camera.get_view_matrix();
		m_device->SetTransform(D3DTS_VIEW, pD3DMATRIX_from_mat4(mat_view));

		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

		m_device->BeginScene();	
		
		for_range(i, 0, 2) {
			m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(model_mat_world[i]));
			draw_model(model[i]);
		}

		m_device->EndScene();
	}

	void cleanup() {		
	}
};


class rd3d9b_blending_tex_alpha : public rd3d9b  {
public:
	d3d9_input_layout m_input_layout;

	d3d9b_model model_backdrop_quad; 
	d3d9_texture tex_backdrop_quad;
	D3DMATERIAL9 mtrl_backdrop_quad;
	gm::mat4 mat_world_backdrop_quad = gm::mat4::k_identity();

	d3d9b_model model_cube; 
	d3d9_texture tex_cube;
	D3DMATERIAL9 mtrl_cube;
	gm::mat4 mat_world_cube = gm::mat4::k_identity();

	//#define D3D9B_PROG_BLENDING_TEAPOT 1
#if D3D9B_PROG_BLENDING_TEAPOT
	d3dx9_mesh mesh_teapot;
	gm::mat4 mat_world_teapot = gm::mat4::k_identity();
#endif

	rs_material mtrl_alpha;

	void setup() {
		set_rs_culling(rs_cull_mode_e::cull_ccw);
		set_rs_lighting(false);

		rs_input_element_desc vfmt_pc[3] = {
			{"POSITION",	rs_rdfmt_e::R32G32B32_FLOAT},
			{"TEXCOORD",	rs_rdfmt_e::R32G32_FLOAT},
			{"NORMAL",		rs_rdfmt_e::R32G32B32_FLOAT},	
		};

		sdr::vector<D3DVERTEXELEMENT9> input_elements;
		d3d9_create_input_element_desc(sdf::span(vfmt_pc, sdf::arr_cap(vfmt_pc)), input_elements);
		m_device->CreateVertexDeclaration(input_elements.data(), &m_input_layout.data);	


		create_texture(RS_MEDIA_PATH("tut/d3d_fl/tex/lobbyxpos.jpg"), tex_backdrop_quad.data);
		create_texture(RS_MEDIA_PATH("tut/d3d_fl/tex/cratewalpha.dds"), tex_cube.data);

		set_sampler_state(rs_texture_filter_e::texf_anisotropic, 0);

		mtrl_backdrop_quad = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::white));

		// Load data to vector.
		rs_model<vertex_ptn> rmodel_backdrop_quad;	
		// Backdrop Quad.
		fill_quad_vertex_ptn(rmodel_backdrop_quad.vertices_vec, rmodel_backdrop_quad.indices_vec);

		create_model_rsmodel(model_backdrop_quad, rmodel_backdrop_quad, m_input_layout.data, tex_backdrop_quad.data, &mtrl_backdrop_quad);

		rmodel_backdrop_quad.clear_memory();

		mat_world_backdrop_quad = gm::mat4_scaling(gm::vec3(5.0, 5.0, 1.0)) * gm::mat4_translation(gm::vec3(0.0, 0.0, 5.0));
		

		//#define D3D9B_PROG_ALPHA_TEX 1
	#if defined D3D9B_PROG_ALPHA_TEX
		// Cube.
		rs_model<vertex_ptn> rmodel_cube;
		fill_cube_vertex_ptn(rmodel_cube.vertices_vec, rmodel_cube.indices_vec);
		create_model_rsmodel(model_cube, rmodel_cube, m_input_layout.data, tex_cube.data, nullptr);
	#else
		set_rs_lighting(true);

		// Material with alpha.
		mtrl_alpha = rs_material_from_color4(gm::cc::red);
		mtrl_alpha.diffuse.a = 0.5f; // set alpha to 50% opacity	
		mtrl_cube = D3DMATERIAL9_from_rs_material(mtrl_alpha);

	#if D3D9B_PROG_BLENDING_TEAPOT
		// Teapot.
		D3DXCreateTeapot(m_device, &mesh_teapot.data, 0);
		mat_world_teapot = gm::mat4_scaling(gm::vec3(1.5f, 1.5f, 1.5f));
	#endif

		// Cube.
		rs_model<vertex_ptn> rmodel_cube;	
		fill_cube_vertex_ptn(rmodel_cube.vertices_vec, rmodel_cube.indices_vec);
		create_model_rsmodel(model_cube, rmodel_cube, m_input_layout.data, tex_cube.data, &mtrl_cube);
		
		rmodel_cube.clear_memory();

		// Directional light.
		gm::vec3 ddir(0.707f, 0.0f, 0.707f);
		gm::color4 dc = gm::cc::white;
		rs_light_directional dir_light(dc*0.6f, dc, dc*0.2f, ddir);

		D3DLIGHT9 light0 = D3DLIGHT9_from_rs_light_directional(dir_light);
		m_device->SetLight(0, &light0);		
		m_device->LightEnable(0, true);

		set_light_render_state();
	#endif		

		//---
		// set alpha blending stuff
	#if defined D3D9B_PROG_ALPHA_TEX
		// use alpha channel in texture for alpha
		m_device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	#else
		// use alpha in material's diffuse component for alpha
		m_device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_DIFFUSE);
	#endif
		m_device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
		// set blending factors so that alpha component determines transparency
		m_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		m_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

		//----------
		m_camera.set_position(gm::vec3(0.0f, 0.0f, -4.0f));
		mat_proj = set_projection_matrix();
		m_device->SetTransform(D3DTS_PROJECTION, pD3DMATRIX_from_mat4(mat_proj));	
	}


	void render(float dt) {  
	#if !defined D3D9B_PROG_ALPHA_TEX		
		// increase/decrease alpha via keyboard input
		if (get_async_key_state('N')) { mtrl_alpha.diffuse.a += 0.4f*dt; }
		if (get_async_key_state('M')) { mtrl_alpha.diffuse.a -= 0.4f*dt; }
		// force alpha to [0, 1] interval
		if (mtrl_alpha.diffuse.a > 1.0f) { mtrl_alpha.diffuse.a = 1.0f; }
		if (mtrl_alpha.diffuse.a < 0.0f) { mtrl_alpha.diffuse.a = 0.0f; }
	#endif
		
		//----------------------
		update_camera(dt);
		mat_view = m_camera.get_view_matrix();
		m_device->SetTransform(D3DTS_VIEW, pD3DMATRIX_from_mat4(mat_view));

		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

		m_device->BeginScene();	

		// Draw back drop quad
		m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(mat_world_backdrop_quad));
		draw_model(model_backdrop_quad);
		// Draw cube or teapot.
		m_device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);		
	#if defined D3D9B_PROG_ALPHA_TEX
		m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(mat_world_cube));
		// cube is drawn in front of backdrop, but can be seen through due to texture alpha.
		draw_model(model_cube);
	#else

		#if D3D9B_PROG_BLENDING_TEAPOT
			m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(mat_world_teapot));
			mtrl_cube = D3DMATERIAL9_from_rs_material(mtrl_alpha);
			m_device->SetMaterial(&mtrl_cube);		
			mesh_teapot.data->DrawSubset(0);
		#else
			m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(mat_world_cube));
			// Set material again at runtime to see fading effect.
			mtrl_cube = D3DMATERIAL9_from_rs_material(mtrl_alpha);
			model_cube.m_mtrl = &mtrl_cube;
			draw_model(model_cube);
		#endif
	#endif
		m_device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);

		m_device->EndScene();
	}
};


class rd3d9b_stencil : public rd3d9b  {
public:
	d3d9_input_layout m_input_layout;	

	d3d9b_model model_cube;
	d3d9_texture tex_cube;
	gm::mat4 mat_world_cube = gm::mat4::k_identity();


	D3DMATERIAL9 mtrl_floor;
	D3DMATERIAL9 mtrl_wall;
	D3DMATERIAL9 mtrl_mirror;

	d3d9_texture tex_floor;
	d3d9_texture tex_wall;
	d3d9_texture tex_mirror;	
	
	// wall_mirror_floor
	d3d9b_model model_wmf;

	d3dx9_mesh mesh_teapot;

	D3DMATERIAL9 mtrl_teapot;
	gm::vec3 teapot_position = gm::vec3::k_zero();

	void fill_wall_mirror_floor_rs_model(sdr::vector<vertex_ptn>& vertices_vec, sdr::vector<uint>& indices_vec) {
		// Create and specify geometry.  For this sample we draw a floor
		// and a wall with a mirror on it.  We put the floor, wall, and
		// mirror geometry in one vertex buffer.
		//
		//   |----|----|----|
		//   |Wall|Mirr|Wall|
		//   |    | or |    |
		//   /--------------/
		//  /   Floor      /
		// /--------------/
		//

		vertex_ptn scene_arr_vert_nt_d3d[] = {
			// floor
			{-7.5f, 0.0f, -10.0f,	0.0f, 1.0f,		0.0f, 1.0f, 0.0f},
			{-7.5f, 0.0f,   0.0f,	0.0f, 0.0f,		0.0f, 1.0f, 0.0f},
			{ 7.5f, 0.0f,   0.0f,	1.0f, 0.0f,		0.0f, 1.0f, 0.0f},
	
			{-7.5f, 0.0f, -10.0f,	0.0f, 1.0f,		0.0f, 1.0f, 0.0f},
			{ 7.5f, 0.0f,   0.0f,	1.0f, 0.0f,		0.0f, 1.0f, 0.0f},
			{ 7.5f, 0.0f, -10.0f,	1.0f, 1.0f,		0.0f, 1.0f, 0.0f},

			// wall
			{-7.5f, 0.0f, 0.0f,		0.0f, 1.0f,		0.0f, 0.0f, -1.0f},
			{-7.5f, 5.0f, 0.0f,		0.0f, 0.0f,		0.0f, 0.0f, -1.0f},
			{-2.5f, 5.0f, 0.0f,		1.0f, 0.0f,		0.0f, 0.0f, -1.0f},
	
			{-7.5f, 0.0f, 0.0f,		0.0f, 1.0f,		0.0f, 0.0f, -1.0f},
			{-2.5f, 5.0f, 0.0f,		1.0f, 0.0f,		0.0f, 0.0f, -1.0f},
			{-2.5f, 0.0f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f, -1.0f},

			// Note: We leave gap in middle of walls for mirror

			{ 2.5f, 0.0f, 0.0f,		0.0f, 1.0f,		0.0f, 0.0f, -1.0f},
			{ 2.5f, 5.0f, 0.0f,		0.0f, 0.0f,		0.0f, 0.0f, -1.0f},
			{ 7.5f, 5.0f, 0.0f,		1.0f, 0.0f,		0.0f, 0.0f, -1.0f},
	
			{ 2.5f, 0.0f, 0.0f,		0.0f, 1.0f,		0.0f, 0.0f, -1.0f},
			{ 7.5f, 5.0f, 0.0f,		1.0f, 0.0f,		0.0f, 0.0f, -1.0f},
			{ 7.5f, 0.0f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f, -1.0f},

			// mirror
			{-2.5f, 0.0f, 0.0f,		0.0f, 1.0f,		0.0f, 0.0f, -1.0f},
			{-2.5f, 5.0f, 0.0f,		0.0f, 0.0f,		0.0f, 0.0f, -1.0f},
			{ 2.5f, 5.0f, 0.0f,		1.0f, 0.0f,		0.0f, 0.0f, -1.0f},
	
			{-2.5f, 0.0f, 0.0f,		0.0f, 1.0f,		0.0f, 0.0f, -1.0f},
			{ 2.5f, 5.0f, 0.0f,		1.0f, 0.0f,		0.0f, 0.0f, -1.0f},
			{ 2.5f, 0.0f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f, -1.0f},
		};
		uint scene_arr_ind_d3d[] = {
			0, 1, 2,
			3, 4, 5,
			6, 7, 8,
			9, 10, 11,
			12, 13, 14,
			15, 16, 17,
			18, 19, 20,
			21, 22, 23,
		};

		isz tri_num_vertices = sdf::arr_cap(scene_arr_vert_nt_d3d);
		isz tri_num_indices = sdf::arr_cap(scene_arr_ind_d3d);		

		// Load data to vector.
		vertices_vec.resize(tri_num_vertices);
		sdf::mem_copy(vertices_vec.data(), scene_arr_vert_nt_d3d, tri_num_vertices);
		indices_vec.resize(tri_num_indices);
		sdf::mem_copy(indices_vec.data(), scene_arr_ind_d3d, tri_num_indices);
	}

	void setup() {
		set_rs_lighting(true);

		rs_input_element_desc vfmt_pc[3] = {
			{"POSITION",	rs_rdfmt_e::R32G32B32_FLOAT},
			{"TEXCOORD",	rs_rdfmt_e::R32G32_FLOAT},
			{"NORMAL",		rs_rdfmt_e::R32G32B32_FLOAT},	
		};

		sdr::vector<D3DVERTEXELEMENT9> input_elements;
		d3d9_create_input_element_desc(sdf::span(vfmt_pc, sdf::arr_cap(vfmt_pc)), input_elements);
		m_device->CreateVertexDeclaration(input_elements.data(), &m_input_layout.data);		
		
		// Load Textures, set filters.
		create_texture(RS_MEDIA_PATH("nw_tex/colors/white.png"), tex_cube.data);
		create_texture(RS_MEDIA_PATH("tut/d3d_fl/tex/checker1.jpg"), tex_floor.data);	//floor
		create_texture(RS_MEDIA_PATH("tut/d3d_fl/tex/brick1.jpg"), tex_wall.data);		//wall
		create_texture(RS_MEDIA_PATH("tut/d3d_fl/tex/ice1.bmp"), tex_mirror.data);		//mirror

		set_sampler_state(rs_texture_filter_e::texf_anisotropic, 0);		

		mtrl_teapot = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::yellow));	// teapot
		mtrl_floor = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::white));	// floor

		rs_material rmtrl_wall = rs_material_from_color4(gm::cc::white);
		// Make walls have low specular reflectance: 20%.
		rmtrl_wall.specular = gm::cc::white * 0.2f;
		mtrl_wall = D3DMATERIAL9_from_rs_material(rmtrl_wall);	// wall	

		mtrl_mirror = D3DMATERIAL9_from_rs_material(rs_material_from_color4(gm::cc::white));	// mirror
		teapot_position = gm::vec3(0.0f, 3.0f, -7.5f);
		
		//#define D3D9B_STENCIL_D3DXMESH 1
	#if D3D9B_STENCIL_D3DXMESH
		// Create the teapot.
		D3DXCreateTeapot(m_device, &mesh_teapot.data, 0);
	 #else
		rs_model<vertex_ptn> bmodel_cube;
		fill_cube_vertex_ptn(bmodel_cube.vertices_vec, bmodel_cube.indices_vec);
		create_model_rsmodel(model_cube, bmodel_cube, m_input_layout.data, tex_cube.data, &mtrl_teapot);
		//create_d3d9_model(model_cube, model_cube, m_vertex_ptn_decl.data, tex_cube.data);
		bmodel_cube.clear_memory();
		mat_world_cube = gm::mat4_translation(teapot_position);
	#endif


		rs_model<vertex_ptn> rmodel_wmf;	
		fill_wall_mirror_floor_rs_model(rmodel_wmf.vertices_vec, rmodel_wmf.indices_vec);	
		create_model_rsmodel(model_wmf, rmodel_wmf, m_input_layout.data, nullptr, nullptr);
			//create_d3d9_model(model0, model_wmf, m_vertex_ptn_decl.data, nullptr);
		//mat_world_arr[1] = gm::mat4_translation(gm::vec3(0.0, -3.0, 15.0));	
		rmodel_wmf.clear_memory();


		// Lights.
		set_rs_lighting(true);
		// Directional light.
		gm::vec3 ddir(0.707f, -0.707f, 0.707f);
		gm::color4 dc = gm::cc::white;
		rs_light_directional dir_light(dc, ddir);

		D3DLIGHT9 light0 = D3DLIGHT9_from_rs_light_directional(dir_light);
		m_device->SetLight(0, &light0);		
		m_device->LightEnable(0, true);

		set_light_render_state();

		//m_camera.set_position(gm::vec3(0.0f, 4.0f, -8.0f));
		m_camera.set_position(gm::vec3(-5.0f, 3.0f, -16.0f));
		mat_proj = set_projection_matrix();
		m_device->SetTransform(D3DTS_PROJECTION, pD3DMATRIX_from_mat4(mat_proj));	
	}

	void render_stencil_helper_scene() {
		// draw teapot
		mat_world_cube = gm::mat4_translation(teapot_position);
		m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(mat_world_cube));

	#if D3D9B_STENCIL_D3DXMESH
		m_device->SetMaterial(&mtrl_teapot);
		set_texture_null(0);	
		mesh_teapot.data->DrawSubset(0);		
	#else
		model_cube.m_mtrl = &mtrl_teapot;
		draw_model(model_cube);
	#endif


		gm::mat4 w1 = gm::mat4::k_identity();
		m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(w1));

		m_device->SetVertexDeclaration(m_input_layout.data);		
		m_device->SetStreamSource(0, model_wmf.m_vb, 0, sizeof(vertex_ptn));
		m_device->SetIndices(model_wmf.m_ib);

		// draw the floor
		m_device->SetMaterial(&mtrl_floor);
		set_texture(tex_floor.data, 0);	
		m_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, model_wmf.num_vertices, 0, 2);		
		// draw the walls
		m_device->SetMaterial(&mtrl_wall);
		set_texture(tex_wall.data, 0);	
		m_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, model_wmf.num_vertices, 6, 4);
		// draw the mirror
		m_device->SetMaterial(&mtrl_mirror);
		set_texture(tex_mirror.data, 0);	
		m_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, model_wmf.num_vertices, 18, 2);
	}	

	void render_stencil_helper_mirror() {
		// Draw Mirror quad to stencil buffer ONLY. In this way only the stencil bits that correspond to the mirror will be on.
		// Therefore, the reflected teapot can only be rendered where the stencil bits are turned on, and thus on the mirror only.
		m_device->SetRenderState(D3DRS_STENCILENABLE,    true);
		m_device->SetRenderState(D3DRS_STENCILFUNC,      D3DCMP_ALWAYS);
		m_device->SetRenderState(D3DRS_STENCILREF,       0x1);
		m_device->SetRenderState(D3DRS_STENCILMASK,      0xffffffff);
		m_device->SetRenderState(D3DRS_STENCILWRITEMASK, 0xffffffff);
		m_device->SetRenderState(D3DRS_STENCILZFAIL,     D3DSTENCILOP_KEEP);
		m_device->SetRenderState(D3DRS_STENCILFAIL,      D3DSTENCILOP_KEEP);
		m_device->SetRenderState(D3DRS_STENCILPASS,      D3DSTENCILOP_REPLACE);
		// Disable writes to the depth and back buffers
		m_device->SetRenderState(D3DRS_ZWRITEENABLE, false);
		m_device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
		m_device->SetRenderState(D3DRS_SRCBLEND,  D3DBLEND_ZERO);
		m_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

		// Draw the mirror to the stencil buffer
		m_device->SetVertexDeclaration(m_input_layout.data);		
		m_device->SetStreamSource(0, model_wmf.m_vb, 0, sizeof(vertex_ptn));
		m_device->SetIndices(model_wmf.m_ib);
		m_device->SetMaterial(&mtrl_mirror);
		set_texture(tex_mirror.data, 0);	
		gm::mat4 w1 = gm::mat4::k_identity();
		m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(w1));
		m_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, model_wmf.num_vertices, 18, 2);

		// Re-enable depth writes
		m_device->SetRenderState( D3DRS_ZWRITEENABLE, true );
		// Only draw reflected teapot to the pixels where the mirror was drawn to.
		m_device->SetRenderState(D3DRS_STENCILFUNC,  D3DCMP_EQUAL);
		m_device->SetRenderState(D3DRS_STENCILPASS,  D3DSTENCILOP_KEEP);

		// Position reflection
		gm::plane mirror_plane(0.0f, 0.0f, 1.0f, 0.0f); // xy plane
		gm::mat4 mat_reflection = gm::mat4_reflect(mirror_plane);
		gm::mat4 mat_translation = gm::mat4_translation(teapot_position);
		mat_world_cube = mat_translation * mat_reflection;

		// Clear depth buffer and blend the reflected teapot with the mirror
		m_device->Clear(0, 0, D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
		m_device->SetRenderState(D3DRS_SRCBLEND,  D3DBLEND_DESTCOLOR);
		m_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ZERO);

		// Finally, draw the reflected teapot
		// Reverse cull mode
		set_rs_culling(rs_cull_mode_e::cull_cw);

		m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(mat_world_cube));
	#if D3D9B_STENCIL_D3DXMESH
		m_device->SetMaterial(&mtrl_teapot);
		set_texture_null(0);
		mesh_teapot.data->DrawSubset(0);
	#else
		model_cube.m_mtrl = &mtrl_teapot;
		draw_model(model_cube);
	#endif
	
		// Restore render states.
		m_device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		m_device->SetRenderState(D3DRS_STENCILENABLE, false);
		set_rs_culling(rs_cull_mode_e::cull_ccw);
	}

	void render_stencil_helper_shadow() {
		m_device->SetRenderState(D3DRS_STENCILENABLE,    true);
		m_device->SetRenderState(D3DRS_STENCILFUNC,      D3DCMP_EQUAL);
		m_device->SetRenderState(D3DRS_STENCILREF,       0x0);
		m_device->SetRenderState(D3DRS_STENCILMASK,      0xffffffff);
		m_device->SetRenderState(D3DRS_STENCILWRITEMASK, 0xffffffff);
		m_device->SetRenderState(D3DRS_STENCILZFAIL,     D3DSTENCILOP_KEEP);
		m_device->SetRenderState(D3DRS_STENCILFAIL,      D3DSTENCILOP_KEEP);
		m_device->SetRenderState(D3DRS_STENCILPASS,      D3DSTENCILOP_INCR); // increment to 1

		// Position shadow
		gm::vec4 lightDirection(0.707f, -0.707f, 0.707f, 0.0f);
		gm::plane groundPlane(0.0f, -1.0f, 0.0f, 0.0f);
		gm::mat4 S = gm::mat4_shadow(lightDirection, groundPlane); 
		gm::mat4 T = gm::mat4_translation(teapot_position);
		mat_world_cube = T * S;
		m_device->SetTransform(D3DTS_WORLD, pD3DMATRIX_from_mat4(mat_world_cube));

		// alpha blend the shadow
		m_device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
		m_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		m_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

		rs_material rshadow_mtrl(gm::cc::black, gm::cc::black, gm::cc::black, gm::cc::black, 0.0f);
		rshadow_mtrl.diffuse.a = 0.5f; // 50% transparency.
		D3DMATERIAL9 shadow_mtrl = D3DMATERIAL9_from_rs_material(rshadow_mtrl);

		// Disable depth buffer so that z-fighting doesn't occur when we
		// render the shadow on top of the floor.
		m_device->SetRenderState(D3DRS_ZENABLE, false);

	#if D3D9B_STENCIL_D3DXMESH
		m_device->SetMaterial(&shadow_mtrl);
		set_texture_null(0);
		mesh_teapot.data->DrawSubset(0);
	#else
		// Black alpha material with no texture for shadow.
		model_cube.m_mtrl = &shadow_mtrl;
		model_cube.m_tex = nullptr;		
		draw_model(model_cube);
		// Restore original texture and material
		model_cube.m_mtrl = &mtrl_teapot;
		model_cube.m_tex = tex_cube.data;		
	#endif

		// Enable the depth buffer again.
		m_device->SetRenderState(D3DRS_ZENABLE, true);
		m_device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		m_device->SetRenderState(D3DRS_STENCILENABLE,    false);
	}

	void render(float dt) {
		if (get_async_key_state(VK_LEFT))	{ teapot_position.x -= 3.0f * dt; }
		if (get_async_key_state(VK_RIGHT))	{ teapot_position.x += 3.0f * dt; }
		if (get_async_key_state(VK_UP))		{ teapot_position.z += 3.0f * dt; }
		if (get_async_key_state(VK_DOWN))	{ teapot_position.z -= 3.0f * dt; }
		if (get_async_key_state('I'))		{ teapot_position.y += 3.0f * dt; }
		if (get_async_key_state('K'))		{ teapot_position.y -= 3.0f * dt; }

		//-------------
		update_camera(dt);
		mat_view = m_camera.get_view_matrix();
		m_device->SetTransform(D3DTS_VIEW, pD3DMATRIX_from_mat4(mat_view));

		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);
		m_device->BeginScene();

		render_stencil_helper_scene();

		// Draw shadow before mirror because the depth buffer hasn't been cleared depth buffer so 
		// that the shadow is blended correctly. That is, if an object obscures the shadow, 
		// we don't want to write the shadow pixel. Alternatively, we could redraw the scene 
		// to rewrite the depth buffer. (RenderMirror clears the depth buffer).
		render_stencil_helper_shadow();

		render_stencil_helper_mirror();	

		m_device->EndScene();
	}	
};




//================================================
#if 1

// TO_CONVERT:
// TO_ARRANGE:
//------------------------------------------------

class rd3d9b_xfile : public rd3d9b  {
public:
	ID3DXMesh*                      Mesh = 0;	
	std::vector<D3DMATERIAL9>       Mtrls;
	std::vector<IDirect3DTexture9*> Textures;
	// Progressive mesh
	ID3DXPMesh*                     PMesh = 0; 
	// Bounding Box
	ID3DXMesh* SphereMesh = 0;
	ID3DXMesh* BoxMesh    = 0;
	bool RenderBoundingSphere = true;

	void setup() {
		HRESULT hr = 0;

		// Load the XFile data.
		ID3DXBuffer* adjBuffer  = 0;
		ID3DXBuffer* mtrlBuffer = 0;
		DWORD        numMtrls   = 0;

		hr = D3DXLoadMeshFromXW(  
			RS_MEDIA_PATHW("tut/d3d_fl/xfile/bigship1.x"),
			//RS_MEDIA_PATHW("tut/d3d_fl/xfile/car.x"),
			D3DXMESH_MANAGED,
			m_device,
			&adjBuffer,
			&mtrlBuffer,
			0,
			&numMtrls,
			&Mesh);

		if (FAILED(hr))
		{
			printfln("D3DXLoadMeshFromX() - FAILED");
			//return false;
		}

		//
		// Extract the materials, and load textures.
		//

		if (mtrlBuffer != 0 && numMtrls != 0)
		{
			D3DXMATERIAL* mtrls = (D3DXMATERIAL*)mtrlBuffer->GetBufferPointer();

			for(int i = 0; i < numMtrls; i++)
			{
				// the MatD3D property doesn't have an ambient value set
				// when its loaded, so set it now:
				mtrls[i].MatD3D.Ambient = mtrls[i].MatD3D.Diffuse;

				// save the ith material
				Mtrls.push_back( mtrls[i].MatD3D );

				// check if the ith material has an associative texture
				if (mtrls[i].pTextureFilename != 0)
				{

					sdf::wstring_st<255> wTextureFilename;
					sdf::string_st_wcs_from_mbs(wTextureFilename, mtrls[i].pTextureFilename, sdf::strfz_len(mtrls[i].pTextureFilename));
					sdf::wstring_st<255> wTextureFilenamePath;
					wTextureFilenamePath.assign(L"E:/nex/aw_media/tut/d3d_fl/tex/");
					wTextureFilenamePath.append(wTextureFilename.c_str());
					// yes, load the texture for the ith subset
					IDirect3DTexture9* tex = 0;
					D3DXCreateTextureFromFileW(
						m_device,
						//mtrls[i].pTextureFilename,
						wTextureFilenamePath.c_str(),
						&tex);

					// save the loaded texture
					Textures.push_back( tex );
				}
				else
				{
					// no texture for the ith subset
					Textures.push_back( 0 );
				}
			}
		}
		com_release(mtrlBuffer); // done w/ buffer

	//#define D3D9B_PROGRESSIVE_MESH
	#define D3D9B_BUOUNDING_VOLUME

		//
		// Optimize the mesh.
		//
	#if !defined D3D9B_PROGRESSIVE_MESH
		hr = Mesh->OptimizeInplace(		
			D3DXMESHOPT_ATTRSORT |
			D3DXMESHOPT_COMPACT  |
			D3DXMESHOPT_VERTEXCACHE,
			(DWORD*)adjBuffer->GetBufferPointer(),
			0, 0, 0);

		if (FAILED(hr))
		{
			printfln("OptimizeInplace() - FAILED");
			//return false;
		}

		com_release(adjBuffer); // done w/ buffer

		#if defined D3D9B_BUOUNDING_VOLUME
			//
			// Compute Bounding Sphere and Bounding Box.
			//
    
			d3d::BoundingSphere boundingSphere;
			d3d::BoundingBox    boundingBox;

			ComputeBoundingSphere(Mesh, &boundingSphere);
			ComputeBoundingBox(Mesh, &boundingBox);

			D3DXCreateSphere(
				m_device,
				boundingSphere._radius,
				20,
				20,
				&SphereMesh,
				0);

			D3DXCreateBox(
				m_device,
				boundingBox._max.x - boundingBox._min.x,
				boundingBox._max.y - boundingBox._min.y,
				boundingBox._max.z - boundingBox._min.z,
				&BoxMesh,
				0);
		#endif

	#else
			hr = Mesh->OptimizeInplace(		
			D3DXMESHOPT_ATTRSORT |
			D3DXMESHOPT_COMPACT  |
			D3DXMESHOPT_VERTEXCACHE,
			(DWORD*)adjBuffer->GetBufferPointer(),
			(DWORD*)adjBuffer->GetBufferPointer(), // new adjacency info
			0, 0);

		if (FAILED(hr))
		{
			printfln("OptimizeInplace() - FAILED");
			com_release(adjBuffer); // free
			//return false;
		}

		//
		// Generate the progressive mesh. 
		//

		hr = D3DXGeneratePMesh(
			Mesh,
			(DWORD*)adjBuffer->GetBufferPointer(), // adjacency
			0,                  // default vertex attribute weights
			0,                  // default vertex weights
			1,                  // simplify as low as possible
			D3DXMESHSIMP_FACE,  // simplify by face count
			&PMesh);

		com_release(Mesh);  // done w/ source mesh
		com_release(adjBuffer); // done w/ buffer

		if (FAILED(hr))
		{
			printfln("D3DXGeneratePMesh() - FAILED");
			//return false;
		}

		// set to original detail
		DWORD maxFaces = PMesh->GetMaxFaces();
		PMesh->SetNumFaces(maxFaces);
	#endif


		//
		// Set texture filters.
		//

		m_device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
		m_device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
		m_device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);

		// 
		// Set Lights.
		//

		D3DXVECTOR3 dir(1.0f, -1.0f, 1.0f);
		D3DXCOLOR col(1.0f, 1.0f, 1.0f, 1.0f);
		D3DLIGHT9 light = d3d::InitDirectionalLight(&dir, &col);

		m_device->SetLight(0, &light);
		m_device->LightEnable(0, true);
		m_device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
		m_device->SetRenderState(D3DRS_SPECULARENABLE, true);

		//
		// Set camera.
		//
		D3DXVECTOR3 pos(4.0f, 4.0f, -13.0f);
		D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
		D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
		D3DXMATRIX V;
		D3DXMatrixLookAtLH(
			&V,
			&pos,
			&target,
			&up);
		m_device->SetTransform(D3DTS_VIEW, &V);

		//
		// Set projection matrix.
		//
		D3DXMATRIX proj;
		D3DXMatrixPerspectiveFovLH(
				&proj,
				D3DX_PI * 0.5f, // 90 - degree
				(float)640 / (float)480,
				1.0f,
				1000.0f);
		m_device->SetTransform(D3DTS_PROJECTION, &proj);

		m_camera.set_position(gm::vec3(4.0f, 4.0f, -20.0f));
		mat_proj = set_projection_matrix();
		m_device->SetTransform(D3DTS_PROJECTION, pD3DMATRIX_from_mat4(mat_proj));	
	}

	void render(float dt) {
		if (m_device)
		{
		#if defined D3D9B_PROGRESSIVE_MESH
			//
			// Update: Mesh resolution.
			//

			// Get the current number of faces the pmesh has.
			int numFaces = PMesh->GetNumFaces();

			// Add a face, note the SetNumFaces() will  automatically
			// clamp the specified value if it goes out of bounds.
			if (::GetAsyncKeyState('N') & 0x8000f)
			{
				// Sometimes we must add more than one face to invert
				// an edge collapse transformation
				PMesh->SetNumFaces( numFaces + 1 );
				if (PMesh->GetNumFaces() == numFaces)
					PMesh->SetNumFaces( numFaces + 2 );
			}

			// Remove a face, note the SetNumFaces() will  automatically
			// clamp the specified value if it goes out of bounds.
			if (::GetAsyncKeyState('M') & 0x8000f)
				PMesh->SetNumFaces( numFaces - 1 );
		#endif

			update_camera(dt);
			mat_view = m_camera.get_view_matrix();
			m_device->SetTransform(D3DTS_VIEW, pD3DMATRIX_from_mat4(mat_view));

			////
			//// Update: Rotate the mesh.
			////

			//static float y = 0.0f;
			//D3DXMATRIX yRot;
			//D3DXMatrixRotationY(&yRot, y);
			////y += dt;

			//if (y >= 6.28f)
			//	y = 0.0f;
			//D3DXMATRIX World = yRot;
			//m_device->SetTransform(D3DTS_WORLD, &World);

			// one key press detection, compare with old array or use windows message
			//if (wParam == VK_SPACE)
			if (::GetAsyncKeyState('K') & 0x8000f)
				RenderBoundingSphere = !RenderBoundingSphere;


			// Render
			m_device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);
			m_device->BeginScene();

			for(int i = 0; i < Mtrls.size(); i++)
			{
				m_device->SetMaterial( &Mtrls[i] );
				m_device->SetTexture(0, Textures[i]);

			#if !defined D3D9B_PROGRESSIVE_MESH				
				Mesh->DrawSubset(i);

				#if defined D3D9B_BUOUNDING_VOLUME
					//
					// Draw bounding volume in blue and at 10% opacity
					D3DMATERIAL9 blue = d3d::BLUE_MTRL;
					blue.Diffuse.a = 0.10f; // 10% opacity

					m_device->SetMaterial(&blue);
					m_device->SetTexture(0, 0); // disable texture

					m_device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
					m_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
					m_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

					if (RenderBoundingSphere) {
						SphereMesh->DrawSubset(0);
					} else {
						BoxMesh->DrawSubset(0);
					}

					m_device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
				#endif
			#else
				// draw pmesh
				PMesh->DrawSubset(i);

				// draw wireframe outline
				m_device->SetMaterial(&d3d::YELLOW_MTRL);
				m_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
				PMesh->DrawSubset(i);
				m_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
			#endif
			}	

			m_device->EndScene();
			m_device->Present(0, 0, 0, 0);
		}		
	}
};


class rd3d9b_picking : public rd3d9b  {
public:
	ID3DXMesh* Teapot = 0;
	ID3DXMesh* Sphere = 0;
	D3DXMATRIX World;
	d3d::BoundingSphere BSphere;

	void setup() {
		// Create the teapot.
		D3DXCreateTeapot(m_device, &Teapot, 0);


		// Compute the bounding sphere.
		BYTE* v = 0;
		Teapot->LockVertexBuffer(0, (void**)&v);

		D3DXComputeBoundingSphere(
			(D3DXVECTOR3*)v,
			Teapot->GetNumVertices(),
			D3DXGetFVFVertexSize(Teapot->GetFVF()),
			&BSphere._center,
			&BSphere._radius);

		Teapot->UnlockVertexBuffer();


		// Build a sphere mesh that describes the teapot's bounding sphere.
		D3DXCreateSphere(m_device, BSphere._radius, 20, 20, &Sphere, 0);


		// Set light.
		D3DXVECTOR3 dir(0.707f, -0.0f, 0.707f);
		D3DXCOLOR col(1.0f, 1.0f, 1.0f, 1.0f);
		D3DLIGHT9 light = d3d::InitDirectionalLight(&dir, &col);

		m_device->SetLight(0, &light);
		m_device->LightEnable(0, true);
		m_device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
		m_device->SetRenderState(D3DRS_SPECULARENABLE, false);	


		// Set view matrix.
		D3DXVECTOR3 pos(0.0f, 0.0f, -10.0f);
		D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
		D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);

		D3DXMATRIX V;
		D3DXMatrixLookAtLH(&V, &pos, &target, &up);
		m_device->SetTransform(D3DTS_VIEW, &V);


		// Set projection matrix.
		D3DXMATRIX proj;
		D3DXMatrixPerspectiveFovLH(
				&proj,
				D3DX_PI * 0.25f, // 45 - degree
				(float)640 / (float)480,
				1.0f,
				1000.0f);
		m_device->SetTransform(D3DTS_PROJECTION, &proj);
	}

	void render(float dt) {

		// Update: Update Teapot.
		static float r     = 0.0f;
		static float v     = 1.0f;
		static float angle = 0.0f;

		D3DXMatrixTranslation(&World, cosf(angle) * r, sinf(angle) * r, 10.0f);

		// transfrom the bounding sphere to match the teapots position in the
		// world.
		BSphere._center = D3DXVECTOR3(cosf(angle)*r, sinf(angle)*r, 10.0f);

		r += v * dt;

		if (r >= 8.0f) {
			v = -v; // reverse direction
		}

		if (r <= 0.0f) {
			v = -v; // reverse direction
		}

		angle += 1.0f * D3DX_PI * dt;
		if (angle >= D3DX_PI * 2.0f) {
			angle = 0.0f;
		}

		// One press mouse & keyboard input
	#if 0
		case WM_LBUTTONDOWN:
			// compute the ray in view space given the clicked screen point
			d3d::Ray ray = CalcPickingRay(LOWORD(lParam), HIWORD(lParam));

			// transform the ray to world space
			D3DXMATRIX view;
			m_device->GetTransform(D3DTS_VIEW, &view);

			D3DXMATRIX viewInverse;
			D3DXMatrixInverse(&viewInverse,	0, &view);

			TransformRay(&ray, &viewInverse);

			// test for a hit
			if (RaySphereIntTest(&ray, &BSphere)) {
				printfln("Hit!", L"HIT");
			}
			break;
	#endif

		//
		// Render
		//

		m_device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);
		m_device->BeginScene();

		// Render the teapot.
		m_device->SetTransform(D3DTS_WORLD, &World);
		m_device->SetMaterial(&d3d::YELLOW_MTRL);
		Teapot->DrawSubset(0);

		// Render the bounding sphere with alpha blending so we can see 
		// through it.
		m_device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
		m_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		m_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

		D3DMATERIAL9 blue = d3d::BLUE_MTRL;
		blue.Diffuse.a = 0.25f; // 25% opacity
		m_device->SetMaterial(&blue);
		Sphere->DrawSubset(0);

		m_device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);

		m_device->EndScene();
	}
};

class rd3d9b_terrain : public rd3d9b  {
public:
	Terrain* TheTerrain = 0;

	void setup() {
	#define D3D9B_TERRAIN1

		// Create the terrain.
		D3DXVECTOR3 lightDirection(0.0f, 1.0f, 0.0f);
		//TheTerrain = new Terrain(m_device, RS_MEDIA_PATH("tut/d3d_fl/hm/coastMountain64.raw"), 64, 64, 10, 0.5f);
		TheTerrain = new Terrain(m_device, RS_MEDIA_PATH("tut/d3d_fl/hm/castlehm257.raw"), 257, 257, 1, 0.2f);
	#if defined D3D9B_TERRAIN1
		TheTerrain->genTexture(&lightDirection, 1);
	#else
		// Ignores terrain color. Shows only light shading.
		TheTerrain->genTexture(&lightDirection, 2);
	#endif

		//
		// Create the font.
		//

		//FPS = new FPSCounter(m_device);

		//
		// Set texture filters.
		//

		m_device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
		m_device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
		m_device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

		//
		// Set projection matrix.
		//

		D3DXMATRIX proj;
		D3DXMatrixPerspectiveFovLH(
				&proj,
				D3DX_PI * 0.25f, // 45 - degree
				(float)640 / (float)480,
				1.0f,
				1000.0f);
		m_device->SetTransform(D3DTS_PROJECTION, &proj);


		m_camera.set_position(gm::vec3(0.0f, 4.0f, -8.0f));
		mat_proj = set_projection_matrix();
		m_device->SetTransform(D3DTS_PROJECTION, pD3DMATRIX_from_mat4(mat_proj));
		//d3d::Delete<Terrain*>(TheTerrain);
		//d3d::Delete<FPSCounter*>(FPS);

	}

	void render(float dt) {
		update_camera(dt);
		mat_view = m_camera.get_view_matrix();
		m_device->SetTransform(D3DTS_VIEW, pD3DMATRIX_from_mat4(mat_view));

		//if (::GetAsyncKeyState(VK_UP) & 0x8000f)
		//	TheCamera.walk(100.0f * timeDelta);

		//if (::GetAsyncKeyState(VK_DOWN) & 0x8000f)
		//	TheCamera.walk(-100.0f * timeDelta);

		//if (::GetAsyncKeyState(VK_LEFT) & 0x8000f)
		//	TheCamera.yaw(-1.0f * timeDelta);
		//
		//if (::GetAsyncKeyState(VK_RIGHT) & 0x8000f)
		//	TheCamera.yaw(1.0f * timeDelta);

		//if (::GetAsyncKeyState('N') & 0x8000f)
		//	TheCamera.strafe(-100.0f * timeDelta);

		//if (::GetAsyncKeyState('M') & 0x8000f)
		//	TheCamera.strafe(100.0f * timeDelta);

		//if (::GetAsyncKeyState('W') & 0x8000f)
		//	TheCamera.pitch(1.0f * timeDelta);

		//if (::GetAsyncKeyState('S') & 0x8000f)
		//	TheCamera.pitch(-1.0f * timeDelta);

		//D3DXVECTOR3 pos;
		//TheCamera.getPosition(&pos);
		gm::vec3 pos;
		pos = m_camera.get_position();
		float height = TheTerrain->getHeight( pos.x, pos.z );
		pos.y = height + 5.0f; // add height because we're standing up
		m_camera.set_position(pos);

		/*D3DXMATRIX V;
		TheCamera.getViewMatrix(&V);
		m_device->SetTransform(D3DTS_VIEW, &V);*/
		gm::mat4 V = m_camera.get_view_matrix();
		m_device->SetTransform(D3DTS_VIEW, pD3DMATRIX_from_mat4(V));

		//
		// Draw the scene:
		//

		m_device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xff000000, 1.0f, 0);
		m_device->BeginScene();

		D3DXMATRIX I;
		D3DXMatrixIdentity(&I);

		if (TheTerrain) {
			TheTerrain->draw(&I, false);
		}

		//if (FPS) {
		//	FPS->render(0xffffffff, dt);
		//}

		m_device->EndScene();
	}
};

class rd3d9b_particle : public rd3d9b  {
public:
	psys::PSystem* Sno = 0;
	psys::PSystem* Exp = 0;
	psys::PSystem* Gun = 0;

	void setup() {
		// seed random number generator
		srand((unsigned int)time(0));

	#define D3D9B_SNOW
	//#define D3D9B_FIREWORKS
	//#define D3D9B_LASER

	#if defined D3D9B_SNOW
		//
		// Create Snow System.
		//
		d3d::BoundingBox boundingBox;
		boundingBox._min = D3DXVECTOR3(-10.0f, -10.0f, -10.0f);
		boundingBox._max = D3DXVECTOR3( 10.0f,  10.0f,  10.0f);
		Sno = new psys::Snow(&boundingBox, 5000);
		Sno->init(m_device, RS_MEDIA_PATH("tut/d3d_fl/tex/snowflake1.dds"));
	#endif

	#if defined D3D9B_FIREWORKS
		//
		// Create the Firework system.
		//
		D3DXVECTOR3 origin(0.0f, 10.0f, 50.0f);
		Exp = new psys::Firework(&origin, 6000);
		Exp->init(m_device, RS_MEDIA_PATH("tut/d3d_fl/tex/flare1.bmp"));
	#endif

	#if defined D3D9B_LASER
		//
		// Create Laser.
		//
		Gun = new psys::ParticleGun(&m_camera);
		Gun->init(m_device, RS_MEDIA_PATH("tut/d3d_fl/tex/flare1_alpha.dds"));
	#endif

		//
		// Create basic scene.
		//
		d3d::DrawBasicScene(m_device, 1.0f);

		//
		// Set projection matrix.
		//
		D3DXMATRIX proj;
		D3DXMatrixPerspectiveFovLH(
				&proj,
				D3DX_PI / 4.0f, // 45 - degree
				(float)640 / (float)480,
				1.0f,
				5000.0f);
		m_device->SetTransform(D3DTS_PROJECTION, &proj);

		m_camera.set_position(gm::vec3(0.0f, 4.0f, -8.0f));
		mat_proj = set_projection_matrix();
		m_device->SetTransform(D3DTS_PROJECTION, pD3DMATRIX_from_mat4(mat_proj));
		
		//d3d::Delete<psys::PSystem*>( Sno );
		//d3d::Delete<psys::PSystem*>( Exp );
		//d3d::Delete<psys::PSystem*>( Gun );
	}

	void render(float dt) {
		update_camera(dt);
		mat_view = m_camera.get_view_matrix();
		m_device->SetTransform(D3DTS_VIEW, pD3DMATRIX_from_mat4(mat_view));

		//
		// Update the scene:
		//
		//if (::GetAsyncKeyState(VK_UP) & 0x8000f)
		//	TheCamera.walk(4.0f * timeDelta);
		//if (::GetAsyncKeyState(VK_DOWN) & 0x8000f)
		//	TheCamera.walk(-4.0f * timeDelta);
		//if (::GetAsyncKeyState(VK_LEFT) & 0x8000f)
		//	TheCamera.yaw(-1.0f * timeDelta);		
		//if (::GetAsyncKeyState(VK_RIGHT) & 0x8000f)
		//	TheCamera.yaw(1.0f * timeDelta);
		//if (::GetAsyncKeyState('N') & 0x8000f)
		//	TheCamera.strafe(-4.0f * timeDelta);
		//if (::GetAsyncKeyState('M') & 0x8000f)
		//	TheCamera.strafe(4.0f * timeDelta);
		//if (::GetAsyncKeyState('W') & 0x8000f)
		//	TheCamera.pitch(1.0f * timeDelta);
		//if (::GetAsyncKeyState('S') & 0x8000f)
		//	TheCamera.pitch(-1.0f * timeDelta);

		//D3DXMATRIX V;
		//TheCamera.getViewMatrix(&V);
		//m_device->SetTransform(D3DTS_VIEW, &V);

	#if defined D3D9B_SNOW
		Sno->update(dt);
	#endif

	#if defined D3D9B_FIREWORKS
		Exp->update(dt);
		if (Exp->isDead()) {
			Exp->reset();
		}
	#endif

	#if defined D3D9B_LASER
		Gun->update(dt);
		// Once key press update
		// Note: we use the message system over GetAsyncKeyState because
		// GetAsyncKeyState was adding particles to fast.  The message
		// system is slower and doesnt add them as fast.  This isn't
		// the best solution, but works for illustration purposes.
		//if (wParam == VK_SPACE ) // Already used for up in camera.
		if (get_async_key_state('K')) {
			Gun->addParticle();
		}
		//break;
	#endif



		// Draw the scene:
		m_device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0x00000000, 1.0f, 0);
		m_device->BeginScene();

		D3DXMATRIX I;
		D3DXMatrixIdentity(&I);
		m_device->SetTransform(D3DTS_WORLD, &I);

		d3d::DrawBasicScene(m_device, 1.0f);

		// order important, render snow last.
		m_device->SetTransform(D3DTS_WORLD, &I);

	#if defined D3D9B_SNOW
		Sno->render();
	#endif
	#if defined D3D9B_FIREWORKS
		Exp->render();
	#endif
	#if defined D3D9B_LASER
		Gun->render();
	#endif

		m_device->EndScene();		
	}
};

//------------------------------------------------
#endif
