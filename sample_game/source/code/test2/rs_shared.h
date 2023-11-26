#pragma once

#define RS_MODEL_PATH(model_name)			"E:/nex/AthensEngine/nw_mdtxt/" model_name
#define RS_SHADER_PATH(shader_name)			"../../../source/code/test2/a_rs_shaders/" shader_name

#define RS_MEDIA_PATH(sub_path)				"E:/nex/aw_media/" sub_path
#define TUT_MEDIA_PATH(sub_path)			"E:/nex/aw_media/tut/d3d_fl/" sub_path

#include "base_def.h"
#include "base_gmath.h"
#include "rs_vertex_formats.h"

#include "base_ds_std_cont.h"
#include <vector>

//------------------------
enum class rs_cull_mode_e {
	cull_none,
	cull_cw,
	cull_ccw,
};
enum class rs_fill_mode_e {
	fill_wireframe,
	fill_solid,
};

enum class rs_texture_filter_e {
    //texf_none,
	texf_point, //nearest neighbour
    texf_bilinear,
	texf_trilinear,
	texf_anisotropic,
};

//------------------------

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


//==============================================
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
