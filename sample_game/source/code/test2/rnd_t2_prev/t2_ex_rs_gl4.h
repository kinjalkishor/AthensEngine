#pragma once

#include "t2_rs_gl4.h"

#if 0
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/string_cast.hpp"

class rgl4_tri_color_gl : public rgl4 {
public:		
	uint VAO = 0;

	uint triangle_m_vb = 0;
	uint triangle_m_ib = 0;
	int64 tri_num_vertices = 0;
	int64 tri_num_indices = 0;

	//gm::mat4 mat_world_tri = gm::mat4::k_identity();
	glm::mat4 mat_world_tri2;
	glm::mat4 mat_view2;
	glm::mat4 mat_proj2;
	struct cb_struct_mat4_ex2 {
		glm::mat4 wvp;
		glm::mat4 W;
		glm::mat4 V;
		glm::mat4 P;
		int mode;
		float pad[3];
	};

	uint shader_vs;
	uint shader_ps;
	uint shader_prog;

	uint cbuffer_wvp = 0;

	void setup() {
		// Visible Front face is CW. Cull back Face CCW.
		//set_rs_culling(rs_cull_mode_e::cull_ccw);
		//set_rs_culling(rs_cull_mode_e::cull_none);

		//set_rs_culling_gl(rs_cull_mode_e::cull_ccw);

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);		
		glEnable(GL_STENCIL_TEST);

		const char* vs_filename = RS_SHADER_PATH2("gl4_vertex_pc_gl.vert");
		const char* ps_filename = RS_SHADER_PATH2("gl4_vertex_pc.frag");
		gl4_compile_shader_from_file(vs_filename, "vs", shader_vs);
		gl4_compile_shader_from_file(ps_filename, "ps", shader_ps);
		gl4_link_shaders(shader_prog, shader_vs, shader_ps);		

		// Define data to load. Can be loaded from file also.
		//vertex_pc triangle_arr_vert_c_d3d[] = {
		//	{-1.0, 0.0, 0.9,	1.0, 0.0, 0.0, 1.0}, // bottom-left red
		//	{ 0.0, 1.0, 0.9,	0.0, 1.0, 0.0, 1.0}, // top green
		//	{ 1.0, 0.0, 0.9,	0.0, 0.0, 1.0, 1.0}, // bottom-right blue
		//};

		vertex_pc triangle_arr_vert_c_d3d[] = {
			{-1.0, 0.0, -0.9,	1.0, 0.0, 0.0, 1.0}, // bottom-left red
			{ 0.0, 1.0, -0.9,	0.0, 1.0, 0.0, 1.0}, // top green
			{ 1.0, 0.0, -0.9,	0.0, 0.0, 1.0, 1.0}, // bottom-right blue
		};

		uint triangle_arr_ind_d3d[] = {
			0, 1, 2,
		};
		tri_num_vertices = sdf::arr_cap(triangle_arr_vert_c_d3d);
		tri_num_indices = sdf::arr_cap(triangle_arr_ind_d3d);		

	#if 1
		// Load data to vector.
		sdr::vector<vertex_pc> vertices_vec;
		sdr::vector<uint> indices_vec;
		vertices_vec.resize(tri_num_vertices);
		sdf::mem_copy(vertices_vec.data(), triangle_arr_vert_c_d3d, tri_num_vertices);
		indices_vec.resize(tri_num_indices);
		sdf::mem_copy(indices_vec.data(), triangle_arr_ind_d3d, tri_num_indices);

		
		//---
		isz vb_size_bytes = vertices_vec.size() * sizeof(vertex_pc);	
		glGenBuffers(1, &triangle_m_vb);		
		glBindBuffer(GL_ARRAY_BUFFER, triangle_m_vb);
		glBufferData(GL_ARRAY_BUFFER, vb_size_bytes, vertices_vec.data(), GL_STATIC_DRAW);

		isz ib_size_bytes = indices_vec.size() * sizeof(uint);
		glGenBuffers(1, &triangle_m_ib);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangle_m_ib);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, ib_size_bytes, indices_vec.data(), GL_STATIC_DRAW);

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);
		//---

		glGenVertexArrays(1, &VAO);	
		glBindVertexArray(VAO);
		glEnableVertexAttribArray(0);
		glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
		glVertexAttribBinding(0, 0);
		glEnableVertexAttribArray(1);
		glVertexAttribFormat(1, 4, GL_FLOAT, GL_FALSE, (3 * sizeof(float)));
		glVertexAttribBinding(1, 0);
		
		int stride = sizeof(vertex_pc);
		glBindVertexBuffer(0, triangle_m_vb, 0, stride);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangle_m_ib);

		glBindVertexArray(0); 
		
		//---
		glUseProgram(shader_prog);


		// Create Constant buffers
		glUniformBlockBinding(shader_prog, 0, 0);
		// Create the uniform/constant buffer
		glGenBuffers(1, &cbuffer_wvp);  
		glBindBuffer(GL_UNIFORM_BUFFER, cbuffer_wvp);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(cb_struct_mat4_ex2), nullptr, GL_STATIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);  
		// Define the range of the buffer that links to a uniform binding point
		glBindBufferRange(GL_UNIFORM_BUFFER, 0, cbuffer_wvp, 0, sizeof(cb_struct_mat4_ex2));
		//------------------------------------------------------------------------
	#endif

	#if 0
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

	#endif

		mat_world_tri2 = glm::mat4(1.0f);
		mat_world_tri2 = glm::translate(glm::mat4(1.0), glm::vec3(1.25f, 0.0f, 0.0f));
		// View Matrix
		// d3d eye: -2.0 to 0.9 (+z), gl eye: 2.0 to -0.9 (-z)
		glm::vec3 position(0.0f, 0.0f, 2.0f);
		glm::vec3 target(0.0f, 0.0f, 0.0f);
		glm::vec3 up(0.0f, 1.0f, 0.0f);
		mat_view2 = glm::lookAtRH(position, target, up);

		// Projection Matrix
		mat_proj2 = glm::perspectiveRH_NO(
								mf::deg_to_rad<float>(100), //yfov
								1.777777f,	//(16/9) //(float)800 / (float)600,
								0.9f,		//1.0f,
								1000.0f);		
	}


	int mode = 1;

	void render(float dt) {

		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

        // draw our first triangle
        glUseProgram(shader_prog);

		//glm::mat4 mat_wvp_temp = mat_world_tri2 * mat_view2 * mat_proj2;
		// reverse multiply in glm mat4 operator*, so this is same as above in calculation.
		glm::mat4 mat_wvp_temp = mat_proj2 * mat_view2 * mat_world_tri2;
		glm::mat4 mat_wvp_temp_t;
		mat_wvp_temp_t = glm::transpose(mat_wvp_temp);

		cb_struct_mat4_ex2 cbs_mat4_wvp = {};
		cbs_mat4_wvp.W = glm::transpose(mat_world_tri2);
		cbs_mat4_wvp.V = glm::transpose(mat_view2);
		cbs_mat4_wvp.P = glm::transpose(mat_proj2);
		cbs_mat4_wvp.wvp = mat_wvp_temp_t;
		cbs_mat4_wvp.mode = mode;

		// Set the WVP matrix in the uniform block    
		glBindBuffer(GL_UNIFORM_BUFFER, cbuffer_wvp);
		//offset in bytes (0, 0 + sizeof(gm::mat4), etc), size, data
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(cb_struct_mat4_ex2), &cbs_mat4_wvp);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);  


        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //glDrawArrays(GL_TRIANGLES, 0, tri_num_indices);
        glDrawElements(GL_TRIANGLES, tri_num_indices, GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0); // no need to unbind it every time  
	}

	void cleanup() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &triangle_m_vb);
		glDeleteBuffers(1, &triangle_m_ib);	
		glDeleteBuffers(1, &cbuffer_wvp);
	}

};
#endif

class rgl4_tri_color_ex : public rgl4 {
public:		

	uint VAO = 0;

	uint triangle_m_vb = 0;
	uint triangle_m_ib = 0;
	int64 tri_num_vertices = 0;
	int64 tri_num_indices = 0;

	gm::mat4 mat_world_tri = gm::mat4::k_identity();

	uint shader_vs;
	uint shader_ps;
	uint shader_prog;

	uint cbuffer_wvp = 0;

	void setup() {			
		// Visible Front face is CW. Cull back Face CCW.
		set_rs_culling(rs_cull_mode_e::cull_ccw);


		// the polygon area computation defined by gl_FrontFacing to determine if a polygon is front- 
		// or back-facing has its sign negated when origin is GL_UPPER_LEFT
		//glClipControl(GL_LOWER_LEFT, GL_NEGATIVE_ONE_TO_ONE);		// OpenGL default
		glClipControl(GL_UPPER_LEFT, GL_ZERO_TO_ONE);				// D3D default
		//gl_Position.z = gl_Position.z * 2.0 - gl_Position.w; //glClipControl or this in vertex shader
		
		//glShadeModel(GL_SMOOTH); // FF Pipeline

		// Enables Depth Testing and type Of Depth Testing To Do
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);		
		glEnable(GL_STENCIL_TEST);
		//glEnable(GL_BLEND);

		// Really Nice Perspective Calculations
		//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// FF Pipeline

		//glEnable(GL_MULTISAMPLE); //CHECK

	#if 0
		// OpenGL clips the z-coordinate to the [-1, 1] range and then transforms it to the
		// [near, far] range specified with glDepthRangef. Direct3D uses the [0, 1] range instead.
		//glDepthRangef(0.0f, 1.0f);	

		//glViewport(d3d_viewport_x, window_height - (d3d_viewport_y + d3d_viewport_height), d3d_viewport_width, d3d_viewport_height);		

		//glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);				// Set old gl Line Antialiasing
	#endif

		//-------------------
		//load_shaders_file(RS_SHADER_PATH2("gl4_vertex_pc.vert"), RS_SHADER_PATH2("gl4_vertex_pc.frag"), shader_vs, shader_ps);
		const char* vs_filename = RS_SHADER_PATH2("gl4_vertex_pc_ex.vert");
		const char* ps_filename = RS_SHADER_PATH2("gl4_vertex_pc.frag");
		gl4_compile_shader_from_file(vs_filename, "vs", shader_vs);
		gl4_compile_shader_from_file(ps_filename, "ps", shader_ps);
		gl4_link_shaders(shader_prog, shader_vs, shader_ps);		

		// Define data to load. Can be loaded from file also.
		vertex_pc triangle_arr_vert_c_d3d[] = {
			{-1.0, 0.0, 0.9,	1.0, 0.0, 0.0, 1.0}, // bottom-left red
			{ 0.0, 1.0, 0.9,	0.0, 1.0, 0.0, 1.0}, // top green
			{ 1.0, 0.0, 0.9,	0.0, 0.0, 1.0, 1.0}, // bottom-right blue
		};

		//vertex_pc triangle_arr_vert_c_d3d[] = {
		//	{-1.0, 0.0, -0.9,	1.0, 0.0, 0.0, 1.0}, // bottom-left red
		//	{ 0.0, 1.0, -0.9,	0.0, 1.0, 0.0, 1.0}, // top green
		//	{ 1.0, 0.0, -0.9,	0.0, 0.0, 1.0, 1.0}, // bottom-right blue
		//};

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

		
		//---
		isz vb_size_bytes = vertices_vec.size() * sizeof(vertex_pc);	
		glGenBuffers(1, &triangle_m_vb);		
		glBindBuffer(GL_ARRAY_BUFFER, triangle_m_vb);
		glBufferData(GL_ARRAY_BUFFER, vb_size_bytes, vertices_vec.data(), GL_STATIC_DRAW);

		isz ib_size_bytes = indices_vec.size() * sizeof(uint);
		glGenBuffers(1, &triangle_m_ib);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangle_m_ib);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, ib_size_bytes, indices_vec.data(), GL_STATIC_DRAW);

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);
		//---

		glGenVertexArrays(1, &VAO);	
		glBindVertexArray(VAO);
		glEnableVertexAttribArray(0);
		glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
		glVertexAttribBinding(0, 0);
		glEnableVertexAttribArray(1);
		glVertexAttribFormat(1, 4, GL_FLOAT, GL_FALSE, (3 * sizeof(float)));
		glVertexAttribBinding(1, 0);
		
		int stride = sizeof(vertex_pc);
		glBindVertexBuffer(0, triangle_m_vb, 0, stride);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangle_m_ib);

		glBindVertexArray(0); 
		
		//---
		glUseProgram(shader_prog);


		// Create Constant buffers
		glUniformBlockBinding(shader_prog, 0, 0);
		// Create the uniform/constant buffer
		glGenBuffers(1, &cbuffer_wvp);  
		glBindBuffer(GL_UNIFORM_BUFFER, cbuffer_wvp);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(cb_struct_mat4_ex_s), nullptr, GL_STATIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);  
		// Define the range of the buffer that links to a uniform binding point
		glBindBufferRange(GL_UNIFORM_BUFFER, 0, cbuffer_wvp, 0, sizeof(cb_struct_mat4_ex_s));
		//------------------------------------------------------------------------

		set_rs_culling(rs_cull_mode_e::cull_none);
		////glClipControl(GL_UPPER_LEFT, GL_ZERO_TO_ONE);				// D3D default
		glClipControl(GL_LOWER_LEFT, GL_NEGATIVE_ONE_TO_ONE);

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

	int mode = 2;

	void render(float dt) {
		//-----------
		// Enable if you want to render to multiple opengl windows
		//wglMakeCurrent(m_hDC, m_hRC);	
		//-----------
		//update_camera(dt);
		//set_view_matrix(m_camera.get_view_matrix());

        clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

        // draw our first triangle
        glUseProgram(shader_prog);

		gm::mat4 mat_wvp_temp = mat_world_tri * mat_view * mat_proj;

		gm::mat4 mat_wvp_temp_t;

		if (mode == 3) {
			mat_wvp_temp_t = mat_wvp_temp;
		} else if (mode == 4) {
			mat_wvp_temp_t = gm::mat4_transpose(mat_wvp_temp);
		}

		cb_struct_mat4_ex_s cbs_mat4_wvp = {};
		cbs_mat4_wvp.wvp = mat_wvp_temp_t;

		if (mode == 1) {
			cbs_mat4_wvp.W = mat_world_tri;
			cbs_mat4_wvp.V = mat_view;
			cbs_mat4_wvp.P = mat_proj;
		} else if (mode == 2) {
			cbs_mat4_wvp.W = gm::mat4_transpose(mat_world_tri);
			cbs_mat4_wvp.V = gm::mat4_transpose(mat_view);
			cbs_mat4_wvp.P = gm::mat4_transpose(mat_proj);
		}

		cbs_mat4_wvp.mode = mode;

		// Set the WVP matrix in the uniform block    
		glBindBuffer(GL_UNIFORM_BUFFER, cbuffer_wvp);
		//offset in bytes (0, 0 + sizeof(gm::mat4), etc), size, data
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(cb_struct_mat4_ex_s), &cbs_mat4_wvp);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);  


        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //glDrawArrays(GL_TRIANGLES, 0, tri_num_indices);
        glDrawElements(GL_TRIANGLES, tri_num_indices, GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0); // no need to unbind it every time  
	}

	void cleanup() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &triangle_m_vb);
		glDeleteBuffers(1, &triangle_m_ib);	
		glDeleteBuffers(1, &cbuffer_wvp);
	}
};




