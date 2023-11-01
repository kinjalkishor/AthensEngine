#pragma once

#include "base_def.h"
#include "base_gmath.h"
#include <vector>
#include "base_std_cont.h"
#include "t2_rs_vertex_formats.h"

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


inline void fill_cube_vertex_ptn(sdr::vector<vertex_ptn>& vertices_vec, sdr::vector<uint>& indices_vec) {
	// Define data to load.
	// 6 duplicate vertices can be removed from vertex array, but coordinates are 
	// more clear this way. Separate vertex color can be also added to each vertex.

	vertex_ptn cube_arr_vert_nt_d3d[] = {
		//front face
		{-1, -1, -1,	0, 1,	0, 0, -1}, //0 F
		{-1, 1, -1,		0, 0,	0, 0, -1}, //1
		{ 1, 1, -1,		1, 0,	0, 0, -1}, //2
		{ 1, 1, -1,		1, 0,	0, 0, -1}, //2
		{ 1, -1, -1,	1, 1, 	0, 0, -1}, //3
		{-1, -1, -1,	0, 1,	0, 0, -1}, //0
		//left face
		{-1, -1, 1,		0, 1,	-1, 0, 0}, //4 L
		{-1, 1, 1,		0, 0, 	-1, 0, 0}, //5
		{-1, 1, -1,		1, 0,	-1, 0, 0}, //1
		{-1, 1, -1,		1, 0,	-1, 0, 0}, //1
		{-1, -1, -1,	1, 1,	-1, 0, 0}, //0
		{-1, -1, 1,		0, 1,	-1, 0, 0}, //4
		//back face
		{ 1, -1, 1,		0, 1,	0, 0, 1}, //7 B
		{ 1, 1, 1,		0, 0,	0, 0, 1}, //6
		{-1, 1, 1,		1, 0,	0, 0, 1}, //5
		{-1, 1, 1,		1, 0,	0, 0, 1}, //5
		{-1, -1, 1,		1, 1,	0, 0, 1}, //4
		{ 1, -1, 1,		0, 1,	0, 0, 1}, //7
		//right face
		{ 1, -1, -1,	0, 1, 	1, 0, 0}, //3 R
		{ 1, 1, -1,		0, 0,	1, 0, 0}, //2
		{ 1, 1, 1,		1, 0,	1, 0, 0}, //6
		{ 1, 1, 1,		1, 0,	1, 0, 0}, //6
		{ 1, -1, 1,		1, 1,	1, 0, 0}, //7
		{ 1, -1, -1,	0, 1,	1, 0, 0}, //3
		//up face
		{-1, 1, -1,		0, 1,	0, 1, 0}, //1 U
		{-1, 1, 1,		0, 0,	0, 1, 0}, //5
		{ 1, 1, 1,		1, 0, 	0, 1, 0}, //6
		{ 1, 1, 1, 		1, 0,	0, 1, 0}, //6
		{ 1, 1, -1,		1, 1,	0, 1, 0}, //2
		{-1, 1, -1,		0, 1,	0, 1, 0}, //1
		//down face
		{-1, -1, 1,		0, 1,	0, -1, 0}, //4 D
		{-1, -1, -1,	0, 0,	0, -1, 0}, //0
		{ 1, -1, -1,	1, 0,	0, -1, 0}, //3
		{ 1, -1, -1,	1, 0,	0, -1, 0}, //3
		{ 1, -1, 1,		1, 1, 	0, -1, 0}, //7
		{-1, -1, 1,		0, 1,	0, -1, 0}, //4		
	};	

	uint cube_arr_indices_d3d[] = {
		//front face
		0, 1, 2,
		3, 4, 5,
		//left face
		6, 7, 8,
		9, 10, 11,
		//back face
		12, 13, 14,
		15, 16, 17,
		//right face
		18, 19, 20,
		21, 22, 23,
		//up face
		24, 25, 26,
		27, 28, 29,
		//down face
		30, 31, 32,
		33, 34, 35,
	};

	isz tri_num_vertices = sdf::arr_cap(cube_arr_vert_nt_d3d);
	isz tri_num_indices = sdf::arr_cap(cube_arr_indices_d3d);		

	// Load data to vector.
	vertices_vec.resize(tri_num_vertices);
	sdf::mem_copy(vertices_vec.data(), cube_arr_vert_nt_d3d, tri_num_vertices);
	indices_vec.resize(tri_num_indices);
	sdf::mem_copy(indices_vec.data(), cube_arr_indices_d3d, tri_num_indices);
}

inline void fill_cube_vertex_pc(sdr::vector<vertex_pc>& vertices_vec, sdr::vector<uint>& indices_vec) {
	sdr::vector<vertex_ptn> v_ptn;
	fill_cube_vertex_ptn(v_ptn, indices_vec);

	gm::color4 vcolor = {1.0, 1.0, 1.0, 1.0}; //white
	vertices_vec.resize(v_ptn.size());
	for_range (i, 0, v_ptn.size()) {
		vertices_vec[i].x = v_ptn[i].x;
		vertices_vec[i].y = v_ptn[i].y;
		vertices_vec[i].z = v_ptn[i].z;

		vertices_vec[i].r = vcolor.r;
		vertices_vec[i].g = vcolor.g;
		vertices_vec[i].b = vcolor.b;
		vertices_vec[i].a = vcolor.a;
	}
}

//-------------------
inline void fill_quad_vertex_ptn(sdr::vector<vertex_ptn>& vertices_vec, sdr::vector<uint>& indices_vec) {
	vertex_ptn quad_arr_vert_nt_d3d[] = {
		//front face
		{-1, -1, -1,	0, 1,	0, 0, -1}, //0 F
		{-1, 1, -1,		0, 0,	0, 0, -1}, //1
		{ 1, 1, -1,		1, 0,	0, 0, -1}, //2
		{ 1, 1, -1,		1, 0,	0, 0, -1}, //2
		{ 1, -1, -1,	1, 1, 	0, 0, -1}, //3
		{-1, -1, -1,	0, 1,	0, 0, -1}, //0		
	};	

	uint quad_arr_indices_d3d[] = {
		//front face
		0, 1, 2,
		3, 4, 5,		
	};

	isz tri_num_vertices = sdf::arr_cap(quad_arr_vert_nt_d3d);
	isz tri_num_indices = sdf::arr_cap(quad_arr_indices_d3d);		

	// Load data to vector.
	vertices_vec.resize(tri_num_vertices);
	sdf::mem_copy(vertices_vec.data(), quad_arr_vert_nt_d3d, tri_num_vertices);
	indices_vec.resize(tri_num_indices);
	sdf::mem_copy(indices_vec.data(), quad_arr_indices_d3d, tri_num_indices);
}