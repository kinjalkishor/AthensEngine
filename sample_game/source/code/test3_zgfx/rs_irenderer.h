#pragma once

#include "base_shared.h"
#include "base_shared2.h"

#include <vector>


inline const gm::color4 k_clear_color = gm::color4(0.2, 0.2, 0.2, 1.0);

class wm_irenderer {
public:
	gm::mat4 mat_view = gm::mat4::k_identity();
	gm::mat4 mat_proj = gm::mat4::k_identity();

	HWND m_render_window = nullptr;
	int m_client_width = 320;
	int m_client_height = 240;
	float m_aspect_ratio = sdf::k_aspect_16_9;

	float m_near_plane = 0.9f;
	float m_far_plane = 1000.0f;
	float m_yfov = 100;

	UINT curr_msaa_sample_count = 1;
	UINT curr_msaa_sample_quality = 0;

	uint m_anisotropic_quality = 16;

	bool msaa_enabled = false;

	wm_irenderer() {}
	virtual ~wm_irenderer() {}	

	virtual bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { return false; }
	virtual void deinit_r() {}

	virtual void setup() {}
	virtual void cleanup() {}
	virtual void render(float dt) {}
	virtual void swap_buffers() {}

	virtual void resize_internal() {}

	void resize(int width, int height) {
		set_width_height(width, height);
		resize_internal();
	}

	//---------------	
	void set_init_params(HWND hwnd, int width, int height, const char* title_append) {
		//set_viewport(0.0f, 0.0f, width, height);
		if (!hwnd) { eprintfln("Window Handle passed is null."); }
		sys_win_title_append(hwnd, title_append);
		set_render_window(hwnd);
		set_width_height(width, height);
		set_yfov_in_radians(90);
	}
	void set_render_window(HWND hwnd) { m_render_window = hwnd; }
	HWND get_render_window(HWND hwnd) { return m_render_window; }
	void set_width_height(int width, int height) { 
		m_client_width = width; 
		m_client_height = height; 
		m_aspect_ratio = sdf::get_aspect_ratio(m_client_width, m_client_height);
	}
	void set_yfov_in_radians(float xfov_deg) {
		m_yfov = mf::yfov_from_xfov(mf::deg_to_rad(xfov_deg), m_aspect_ratio);
	}
	gm::mat4 get_proj_matrix() {
		return gm::mat4_perspective_fov_lh(m_yfov, m_aspect_ratio, m_near_plane, m_far_plane);
	}
};

//==============================================
struct vertex_pc {
	float x, y, z;
	float r, g, b, a;		
};

struct vertex_pct {
	float x, y, z;
	float r, g, b, a;		
	float u, v; 
};

//-------------------------
enum class rs_cull_mode_e {
	cull_none,
	cull_cw,
	cull_ccw,
};

enum class rs_texture_filter_e {
    //texf_none,
	texf_point, //nearest neighbour
    texf_bilinear,
	texf_trilinear,
	texf_anisotropic,
};
//==============================================

inline void set_world_matrix_tri1(gm::mat4& mat_world_model) {
	// World Matrix
	mat_world_model = gm::mat4_translation(gm::vec3(1.25f, 0.0f, 0.0f));
	//mat_world_model = gm::mat4_scaling(gm::vec3(2.0, 1.0, 1.0));
	// Rotating on x axis, since x axis is same while y or z can be up.
	//mat_world_model = gm::mat4_rotation_x(mf::deg_to_rad<float>(30));	
}
inline void set_view_matrix_tri1(gm::mat4& mat_view) {
	// View Matrix
	// Position and aim the camera.
	gm::vec3 position(0.0f, 0.0f, -2.0f);
	gm::vec3 target(0.0f, 0.0f, 0.0f);
	gm::vec3 up(0.0f, 1.0f, 0.0f);
	mat_view = gm::mat4_look_at_lh(position, target, up);	
}
inline void set_proj_matrix_tri1(gm::mat4& mat_proj, float width, float height) {
	// Projection Matrix
	mat_proj = gm::mat4_perspective_fov_lh(
					mf::deg_to_rad<float>(100), //yfov
					//1.777777,	//(16/9) //(float)800 / (float)600,
					sdf::get_aspect_ratio(width, height),
					0.9f,		//1.0f,
					1000.0f);
}

//----------------------------------
inline void fill_triangle_vertex_pc(sdr::vector<vertex_pc>& vertices_vec, sdr::vector<uint>& indices_vec) {
	// Define data to load.
	vertex_pc triangle_arr_vert_c_d3d[] = {
		{-1.0, 0.0, 0.9,	1.0, 0.0, 0.0, 1.0}, // bottom-left red
		{ 0.0, 1.0, 0.9,	0.0, 1.0, 0.0, 1.0}, // top green
		{ 1.0, 0.0, 0.9,	0.0, 0.0, 1.0, 1.0}, // bottom-right blue
	};
	uint triangle_arr_ind_d3d[] = {
		0, 1, 2,
	};

	isz tri_num_vertices = sdf::arr_cap(triangle_arr_vert_c_d3d);
	isz tri_num_indices = sdf::arr_cap(triangle_arr_ind_d3d);		

	// Load data to vector.
	vertices_vec.resize(tri_num_vertices);
	sdf::mem_copy(vertices_vec.data(), triangle_arr_vert_c_d3d, tri_num_vertices);
	indices_vec.resize(tri_num_indices);
	sdf::mem_copy(indices_vec.data(), triangle_arr_ind_d3d, tri_num_indices);
}

inline void fill_triangle_vertex_pct(sdr::vector<vertex_pct>& vertices_vec, sdr::vector<uint>& indices_vec) {
	// Define data to load.
	vertex_pct triangle_arr_vert_c_d3d[] = {
		//z[0, 1] for d3d9, z[0, 1) for d3d11 [-1, 1] for opengl. x, y is [-1, 1]

		// OpenGL texture coordinates, images flipped generally at load so that (0, 0) is at bottom
		// which is normally at top for images and D3D.
		//{-1.0, 0.0, 0.9,	1.0, 0.0, 0.0, 1.0,		0.0, 0.0}, // bottom-left red
		//{ 0.0, 1.0, 0.9,	0.0, 1.0, 0.0, 1.0,		0.5, 1.0}, // top green
		//{ 1.0, 0.0, 0.9,	0.0, 0.0, 1.0, 1.0,		1.0, 0.0}, // bottom-right blue	

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
	vertices_vec.resize(tri_num_vertices);
	sdf::mem_copy(vertices_vec.data(), triangle_arr_vert_c_d3d, tri_num_vertices);
	indices_vec.resize(tri_num_indices);
	sdf::mem_copy(indices_vec.data(), triangle_arr_ind_d3d, tri_num_indices);
}

//============================================
