#pragma once

//------------------------------------
#include "../win32_loader_gl_wgl.h"
#include <wglext.h>

//#include <gl/gl.h>
//#include <glext.h>
// Do not #include both <GL/glcorearb.h> and either of <GL/gl.h> or <GL/glext.h> in the same source file.
//#include <glcorearb.h>
// include glcorearb.h or gl/gl.h before wglext.h
//#include <wglext.h>
//---
// Use gl_loader_core.h, compat enabled only for testing gl2 in other file
// as only one cpp can be active at a time with same function pointer names.
//#include "gl_loader/gl_loader_core.h"
#include "gl_loader/gl_loader_compat.h"
//------------------------------------


#include "t2_rs_irenderer.h"


void gl_load_texture(const char* tex_file_name, bool gamma_correction);

// Add other types of shaders compiling & linking with if statement.
inline bool gl4_compile_shader_from_file(const char* shader_filename, const char* shader_type, uint& hshader) {
	if (!(is_file_exists(shader_filename))) {
		eprintfln("Cannot find shader file: %s", shader_filename);
	}

	//size_t shader_src_len = 0;
	//char* shader_src_strz = sdf::read_text_file_strz_c(shader_filename, shader_src_len);
	//int shader_src_len_gl = scast<int>(shader_src_len);
	//free(shader_src_strz); //AT END before return

	sdr::vector<char> shader_src_strz_vec;
	sdf::read_text_file_strz(shader_src_strz_vec, shader_filename);
	// Store to pass to OpenGL functions taking ** pointers.
	// Don't manually free shader_src_strz as it is just an non owning pointer to vector data.
	char* shader_src_strz = shader_src_strz_vec.data();
	int shader_src_len_gl = shader_src_strz_vec.size();


	if (sdf::strfz_equals(shader_type, "vs")) {
		hshader = glCreateShader(GL_VERTEX_SHADER);
	} else if (sdf::strfz_equals(shader_type, "ps")) {
		hshader = glCreateShader(GL_FRAGMENT_SHADER);
	} else {
		eprintfln("Wrong shader type: %s", shader_type);
	}


	//glShaderSource(hshader, 1, &shader_src_strz, nullptr);
	glShaderSource(hshader, 1, &shader_src_strz, &shader_src_len_gl);
	glCompileShader(hshader);

	// check for shader compile errors
	int success = 0;
	char infoLog[512] = {};
	glGetShaderiv(hshader, GL_COMPILE_STATUS, &success);
	if (!success) {
		//GLint maxLength = 0;
		//glGetShaderiv(hshader, GL_INFO_LOG_LENGTH, &maxLength);
		//// The maxLength includes the NULL character
		////std::vector<GLchar> infoLog(maxLength);
		//GLchar* infoLog2 = new GLchar[maxLength];
		//glGetShaderInfoLog(hshader, maxLength, &maxLength, &infoLog2[0]);
		////print error message.
		//delete[] infoLog2; 

		glGetShaderInfoLog(hshader, sdf::arr_cap(infoLog), nullptr, infoLog);
		eprintfln("Shader type %s compilation failed: \n%s", shader_type, infoLog);
	}

	
	return scast<bool>(success);
}

inline bool gl4_link_shaders(uint& shaderProgram, uint hvertex_shader, uint hpixel_shader) {
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, hvertex_shader);
	glAttachShader(shaderProgram, hpixel_shader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	int success = 0;
	char infoLog[512] = {};
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		//glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &maxLength);

		glGetProgramInfoLog(shaderProgram, sdf::arr_cap(infoLog), nullptr, infoLog);
		eprintfln("Shader program linking failed: \n%s", infoLog);
	}	

	if (success) {
		// Always detach shaders after a successful link.
		glDetachShader(shaderProgram, hvertex_shader);
		glDetachShader(shaderProgram, hpixel_shader);
	}

	return scast<bool>(success);
}

inline void gl4_create_input_element_desc(sdf::span<rs_input_element_desc> iedesc, uint& vao) {
	glGenVertexArrays(1, &vao);	
	glBindVertexArray(vao);

	constexpr int size_float = 4;
	uint curr_aligned_byte_offset = 0;
	uint next_aligned_byte_offset = 0;
	uint num_elems = 0;
	for_range (i, 0, iedesc.size()) {
		switch(iedesc[i].format) {
			case rs_rdfmt_e::R32G32B32A32_FLOAT: num_elems = 4; next_aligned_byte_offset += num_elems*size_float; break;
			case rs_rdfmt_e::R32G32B32_FLOAT: num_elems = 3; next_aligned_byte_offset += num_elems*size_float; break;
			case rs_rdfmt_e::R32G32_FLOAT: num_elems = 2; next_aligned_byte_offset += num_elems*size_float; break;
			default: break;
		}

		glEnableVertexAttribArray(i);
		glVertexAttribFormat(i, num_elems, GL_FLOAT, GL_FALSE, curr_aligned_byte_offset);
		glVertexAttribBinding(i, 0);

		curr_aligned_byte_offset = next_aligned_byte_offset;
	}
}


class gl_vao {
public:	
	uint data = 0;
	~gl_vao() { glDeleteVertexArrays(1, &data); }
};

class gl_buffer {
public:	
	uint data = 0;
	~gl_buffer() { glDeleteBuffers(1, &data); }
};

class gl_shader {
public:
	uint data = 0;
	~gl_shader() { glDeleteShader(data); }
};

class gl_shader_program {
public:
	uint data = 0;
	~gl_shader_program() { glDeleteProgram(data); }
};

class gl_texture {
public:	
	uint data = 0;
	~gl_texture() { glDeleteTextures(1, &data); }
};

class gl_sampler_state {
public:	
	uint data;
	~gl_sampler_state() { glDeleteSamplers(1, &data); }
};

//---
class gl_model {
public:
	uint m_vb = 0;
	uint m_ib = 0;
	isz num_vertices = 0;
	isz num_indices = 0;

	//uint* m_input_layout = nullptr;
	uint m_tex = 0;	

	uint vstride = 0;

	~gl_model() {
		glDeleteBuffers(1, &m_vb);
		glDeleteBuffers(1, &m_ib);
	}
};

//----------------------
class rgl4 : public irenderer {
public:
	//-------------
	HDC m_hDC = nullptr;
	HGLRC m_hRC = nullptr;


	HWND gl_helper_hwnd = nullptr;
	HDC gl_helper_hdc = nullptr;
	HGLRC gl_helper_hrc = nullptr;

	bool use_opengl_compatibility_profile = false;

	int gl_ver_major = 4;
	int gl_ver_minor = 6;

	gl_texture m_default_tex;
	gl_sampler_state m_sampler_anisotropic;


	static LRESULT CALLBACK gl_helper_wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {    
		return DefWindowProcW(hWnd, uMsg, wParam, lParam);
	}

	bool gl_helper_window_init(HINSTANCE hinstance) {
		HINSTANCE helper_instance = hinstance;
		const wchar_t* helper_class_name = L"GL_HELPER_WINDOW";
		
		WNDCLASSEX wcex = {};
		wcex.cbSize = sizeof(wcex);
		wcex.style = CS_OWNDC; 
		wcex.lpfnWndProc = gl_helper_wnd_proc; //m_wnd_proc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = helper_instance;
		wcex.hIcon = LoadIconW(nullptr, IDI_APPLICATION);
		wcex.hCursor = LoadCursorW(nullptr, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wcex.lpszMenuName = nullptr;
		wcex.lpszClassName = helper_class_name;
		wcex.hIconSm = LoadIconW(nullptr, IDI_APPLICATION);
		RegisterClassExW(&wcex);

		//uint gl_helper_style = WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPSIBLINGS|WS_CLIPCHILDREN; 
		uint gl_helper_style = WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS|WS_CLIPCHILDREN; //invisible
		uint gl_helper_exstyle = 0;
		// create temporary window
		gl_helper_hwnd = CreateWindowExW(
							gl_helper_exstyle,
							helper_class_name, L"OpenGL helper window",
							gl_helper_style,
							0, 0, 160, 160,
							nullptr, nullptr, helper_instance, nullptr);

		if (!gl_helper_hwnd) {
			printfln("Cannot create OpenGL helper window");
			return false;
		}   

		gl_helper_hdc = GetDC(gl_helper_hwnd);	// Device Context
		return true;
	}

	void gl_helper_window_deinit() {
		DestroyWindow(gl_helper_hwnd);
	}
	//---


	void deinit_r() {
		if (m_hRC) {
			if (!wglfn.fwglMakeCurrent(nullptr, nullptr)) {
				printfln("Release Of DC And RC Failed.");
			}
			if (!wglfn.fwglDeleteContext(m_hRC)) {
				printfln("Release Rendering Context Failed.");
			}
			m_hRC = nullptr;
		}

		HWND hwnd = WindowFromDC(m_hDC);
		if (m_hDC) {
			if (!ReleaseDC(hwnd, m_hDC)) {
				printfln("Release Device Context Failed.");
			}
			m_hDC = nullptr;
		}

		wglfn.deinit();
	}


	bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) {
		//set_viewport(0.0f, 0.0f, width, height);
		if (!hwnd) { eprintfln("Window Handle passed is null."); }
		//m_render_window = hwnd;
		sys_win_title_append(hwnd, " : OpenGL4.6");
		m_aspect_ratio = sdf::get_aspect_ratio(width, height);

		//------------
		// Create helper window for creating temporary OpenGL context for loading OpenGL function pointers.
		gl_helper_window_init(hinstance);
		wglfn.init();
		
		//---
		PIXELFORMATDESCRIPTOR hleper_pfd = {};
		hleper_pfd.nSize = sizeof(hleper_pfd);
		hleper_pfd.nVersion = 1;
		hleper_pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		hleper_pfd.iPixelType = PFD_TYPE_RGBA;
		hleper_pfd.cColorBits = 32;
		hleper_pfd.cAlphaBits = 8;
		hleper_pfd.cDepthBits = 24;

		const int helper_pixel_format = ChoosePixelFormat(gl_helper_hdc, &hleper_pfd);
		if (helper_pixel_format == 0) {
			printfln("ChoosePixelFormat() failed.");
			return false;
		}

		if (!SetPixelFormat(gl_helper_hdc, helper_pixel_format, &hleper_pfd)) {
			printfln("SetPixelFormat() failed.");
			return false;
		}
		
		// Rendering Context
		gl_helper_hrc = wglfn.fwglCreateContext(gl_helper_hdc);	
		if (!gl_helper_hrc) {
			printfln("wglCreateContext() failed.");
			return false;
		}
		
		if (!wglfn.fwglMakeCurrent(gl_helper_hdc, gl_helper_hrc)) {
			printfln("wglMakeCurrent() failed.");
			return false;
		}		

		
		

		// Load wgl extension.
		wglext_init();

		// Load OpenGL functions
		glfnlib_load((PFN_loadfunc_gl)get_gl_func_address_name);
		//-------------------------		

		// Create OpenGL context in main window.
		m_hDC = GetDC(hwnd);

		const int pixelAttribs[] = {
			WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
			WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
			WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
			WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
			WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
			WGL_COLOR_BITS_ARB, 32,
			WGL_ALPHA_BITS_ARB, 8,
			WGL_DEPTH_BITS_ARB, 24,
			WGL_STENCIL_BITS_ARB, 8,
			WGL_SAMPLE_BUFFERS_ARB, GL_TRUE,
			WGL_SAMPLES_ARB, 4,
			0
		};

		int pixel_format_idx = 0; 
		UINT numFormats = 0;
		const bool status = wglChoosePixelFormatARB(m_hDC, pixelAttribs, nullptr, 1, &pixel_format_idx, &numFormats);
		if (status == false || numFormats == 0) {
			printfln("wglChoosePixelFormatARB() failed.");
			return 1;
		}

		PIXELFORMATDESCRIPTOR PFD = {};
		DescribePixelFormat(m_hDC, pixel_format_idx, sizeof(PFD), &PFD);
		SetPixelFormat(m_hDC, pixel_format_idx, &PFD);

		use_opengl_compatibility_profile = true;
		int profile_type_val = WGL_CONTEXT_CORE_PROFILE_BIT_ARB;
		if (use_opengl_compatibility_profile) {
			profile_type_val = WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB;
		}

		//const int gl_ver_major = 4, gl_ver_minor = 6;
		const int contextAttribs[] = {
			WGL_CONTEXT_MAJOR_VERSION_ARB, gl_ver_major,
			WGL_CONTEXT_MINOR_VERSION_ARB, gl_ver_minor,
			WGL_CONTEXT_PROFILE_MASK_ARB, profile_type_val,
			//WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
			//WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB, // or compatibility
			//WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB,
			0
		};

		
		m_hRC = wglCreateContextAttribsARB(m_hDC, 0, contextAttribs);
		if (!m_hRC) {
			printfln("wglCreateContextAttribsARB() failed for opengl version %d.%d", gl_ver_major, gl_ver_minor);
			return false;
		}
		
	
		// Delete temporary context and helper window.
		wglfn.fwglMakeCurrent(nullptr, nullptr);
		wglfn.fwglDeleteContext(gl_helper_hrc);		
		ReleaseDC(gl_helper_hwnd, gl_helper_hdc);
		gl_helper_window_deinit();


		if (!wglfn.fwglMakeCurrent(m_hDC, m_hRC)) {
			printfln("wglMakeCurrent() failed.");
			return false;
		}

		//---
		//printfln("glGetString: %s", rcast<const char*>(glGetString(GL_VERSION)));
		//IDirect3D9::GetAdapterIdentifier //DirectX3 through DirectX9
		//IDXGIAdapter::GetDesc //DirectX9 and above
		//glGetString(GL_VENDOR) and glGetString(GL_RENDERER) //OpenGL

		//resize(width, height);

		enable_depth_stencil();

		//init_fonts();

		init_default_texture();

		return true;
	}

	void resize(int width, int height) {	
		// make sure the viewport matches the new window dimensions; note that width and 
		// height will be significantly larger than specified on retina displays.
		glViewport(0, 0, width, height);

		// Set the viewport transform.

		// If changed again in resize.
		//set_rs_anitialiasing();

		m_aspect_ratio = sdf::get_aspect_ratio(width, height);
		mat_proj = set_projection_matrix();
	}

	// Default setup, cleanup, render func.
	void setup() {}
	void cleanup() {}	

	void render(float dt) {
		clear_render_target(gm::color4(0.0, 1.0, 0.0, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);
	}

	void swap_buffers() {	
		SwapBuffers(m_hDC);
	}

	//-----------------------------------------------------------
	void clear_render_target(const gm::color4& color_rgba) {
		//float clear_color[4] = {0.0f, 1.0f, 1.0f, 1.0f};
		//glClearBufferfv(GL_COLOR, 0, clear_color);
		glClearBufferfv(GL_COLOR, 0, color_rgba.data());
	}
	void clear_depth_stencil(bool clear_depth, bool clear_stencil, float depth, uint stencil) {
		GLint stencil_val = stencil;
		if (clear_depth) { glClearBufferfv(GL_DEPTH, 0, &depth); }
		if (clear_stencil) { glClearBufferiv(GL_STENCIL, 0, &stencil_val); }
	}

	void enable_depth_stencil() {
		// Enables Depth Testing and type Of Depth Testing To Do
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);		
		glEnable(GL_STENCIL_TEST);
	}

	void enable_clip_control(bool d3d_like) {
		if (d3d_like) { 
			// D3D default
			glClipControl(GL_UPPER_LEFT, GL_ZERO_TO_ONE);				
		} else {
			// OpenGL default
			glClipControl(GL_LOWER_LEFT, GL_NEGATIVE_ONE_TO_ONE);		
		}		
	}
	//-----------------------------------------------------------
	void set_rs_culling_gl(rs_cull_mode_e cullmode_back_face) {
		switch (cullmode_back_face) {
			case rs_cull_mode_e::cull_none: glDisable(GL_CULL_FACE); break;
			// Without glClipControl, normal default opengl.
			case rs_cull_mode_e::cull_cw: glEnable(GL_CULL_FACE); glFrontFace(GL_CCW); break;
			case rs_cull_mode_e::cull_ccw: glEnable(GL_CULL_FACE); glFrontFace(GL_CW); break;
			default: glEnable(GL_CULL_FACE); glFrontFace(GL_CW); break;
		}
	}

	void set_rs_culling(rs_cull_mode_e cullmode_back_face) {
		// Default cull mode is D3DCULL_CCW for D3D9, culling refering to back face culling.
		// A front face is one in which vertices are defined in clockwise order. Back faces having CCW are culled.
		// In OpenGL CCW is frontface by default. Use glFrontFace(GL_CW) to specify CCW as backface like D3D9. 
		//---
		// For glClipControl(GL_UPPER_LEFT, GL_ZERO_TO_ONE) like D3D
		// The polygon area computation defined by gl_FrontFace to determine if a polygon is 
		// front- or back-facing has its sign negated when origin is GL_UPPER_LEFT. 
		switch (cullmode_back_face) {
			case rs_cull_mode_e::cull_none: glDisable(GL_CULL_FACE); break;
			// Use these if using glClipControl.
			case rs_cull_mode_e::cull_cw: glEnable(GL_CULL_FACE); glFrontFace(GL_CW); break;
			case rs_cull_mode_e::cull_ccw: glEnable(GL_CULL_FACE); glFrontFace(GL_CCW); break;
			default: glEnable(GL_CULL_FACE); glFrontFace(GL_CCW); break;
		}
	}


	void set_rs_fillmode(rs_fill_mode_e fill_mode) {
		switch (fill_mode) {
			case rs_fill_mode_e::fill_solid: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); break;
			case rs_fill_mode_e::fill_wireframe: glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); break;
			//case rs_fill_mode_e::fill_point: glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); break;
			default: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); break;
		}
	} 


	//----------------------------------
	void load_vertex_shader_file(const char* shader_filename, uint& vs_shader) {
		gl4_compile_shader_from_file(shader_filename, "vs", vs_shader);
	}
	void load_pixel_shader_file(const char* shader_filename, uint& ps_shader) {
		gl4_compile_shader_from_file(shader_filename, "ps", ps_shader);
	}

	inline bool link_shaders_vs_ps(uint& shaderProgram, uint vs_shader, uint ps_shader) {
		return gl4_link_shaders(shaderProgram, vs_shader, ps_shader);
	}

	//----------------------------------
	void unbind_vao() {
		glBindVertexArray(0); 
	}

	void set_texture(uint tex_stage, const uint& tex) {
		glActiveTexture(GL_TEXTURE0 + tex_stage);
		glBindTexture(GL_TEXTURE_2D, tex);
	}

	void set_texture_null(uint tex_stage) {
		glActiveTexture(GL_TEXTURE0 + tex_stage);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void create_texture(const char* tex_file_name, uint& tex, uint tex_stage) {
		// Check if DDS texture.
		char filename_ext[8];
		get_filename_ext(filename_ext, tex_file_name);
		bool tex_is_dds = !strcmpi(filename_ext, "dds");

		//if (tex_is_dds) {
		//} else {
			glGenTextures(1, &tex);
			set_texture(tex_stage, tex);
			gl_load_texture(tex_file_name, false);				
		//}		
	}

	void init_default_texture() {
		create_texture(m_default_texture_file, m_default_tex.data, 0);
	}

	// OpenGL 3.3 sampler states allow to stick to Direct3D 11 logic and its D3D11_SAMPLER_DESC structure and 
	// CreateSamplerState(D3D11 device) and PSSetSamplers(immediate context) functions.
	void create_sampler_state(uint& sampler_state, rs_texture_filter_e filtering, int anisotropic_quality) {
		glGenSamplers(1, &sampler_state);
		glSamplerParameteri(sampler_state, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glSamplerParameteri(sampler_state, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glSamplerParameteri(sampler_state, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glSamplerParameteri(sampler_state, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		// Any value greater than 1.0f counts as a use of anisotropic filtering. 
		glSamplerParameterf(sampler_state, GL_TEXTURE_MAX_ANISOTROPY, 1.0f);

		switch (filtering) {
			case rs_texture_filter_e::texf_anisotropic: glSamplerParameterf(sampler_state, GL_TEXTURE_MAX_ANISOTROPY, scast<float>(anisotropic_quality)); break;			
		}		
	}

	void set_sampler_state(uint tex_unit, uint& sampler_state) {
		glBindSampler(tex_unit, sampler_state);
	}
	//--------------------------------

	void create_vertex_buffer(UINT vb_size_bytes, const void* sys_mem_data, uint& vb, uint vstride) {
		//isz vb_size_bytes = vertices_vec.size() * sizeof(vertex_pc);	
		glGenBuffers(1, &vb);		
		glBindBuffer(GL_ARRAY_BUFFER, vb);
		glBufferData(GL_ARRAY_BUFFER, vb_size_bytes, sys_mem_data, GL_STATIC_DRAW);

		glBindVertexBuffer(0, vb, 0, vstride);		
	}

	void create_index_buffer(UINT ib_size_bytes, const void* sys_mem_data, uint& ib) {
		//isz ib_size_bytes = indices_vec.size() * sizeof(uint);
		glGenBuffers(1, &ib);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, ib_size_bytes, sys_mem_data, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
	}

	void create_constant_buffer(UINT cb_size_bytes, uint& buffer) {		
		// Create the uniform/constant buffer
		glGenBuffers(1, &buffer);  
		glBindBuffer(GL_UNIFORM_BUFFER, buffer);
		glBufferData(GL_UNIFORM_BUFFER, cb_size_bytes, nullptr, GL_STATIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);  
		// Define the range of the buffer that links to a uniform binding point
		glBindBufferRange(GL_UNIFORM_BUFFER, 0, buffer, 0, cb_size_bytes);
	}
	void upload_constant_buffer(UINT cb_size_bytes, uint& constant_buffers, const void* src_data) {
		// Set the WVP matrix in the uniform block    
		glBindBuffer(GL_UNIFORM_BUFFER, constant_buffers);
		//offset in bytes (0, 0 + sizeof(gm::mat4), etc), size, data
		glBufferSubData(GL_UNIFORM_BUFFER, 0, cb_size_bytes, src_data);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);  
	}

	//--------------------------------------
	void create_model(gl_model& model, const void* vertices_data, isz vertices_size, uint vertices_stride, 
		const void* indices_data, isz indices_size, uint indices_stride, uint tex) {
		model.num_vertices = vertices_size;
		model.num_indices = indices_size;
		model.vstride = vertices_stride;
		
		create_vertex_buffer(vertices_size*vertices_stride, vertices_data, model.m_vb, model.vstride);
		create_index_buffer(indices_size*indices_stride, indices_data, model.m_ib);		
		if (tex != 0) {
			model.m_tex = tex;
		} else {
			model.m_tex = m_default_tex.data;
		}
	}

	void create_model_basic(gl_model& model, const void* vertices_data, isz vertices_size, uint vertices_stride, 
		const void* indices_data, isz indices_size, uint indices_stride, uint tex) {
		create_model(model, vertices_data, vertices_size, vertices_stride, indices_data, indices_size, indices_stride, tex);
	}

	template<class T>
	void create_model_rsmodel(gl_model& model, rs_model<T> rmodel, uint tex) {
		create_model(model, rmodel.vertices_vec.data(), rmodel.vertices_vec.size(), rmodel.vstride(), 
				rmodel.indices_vec.data(), rmodel.indices_vec.size(), rmodel.istride(), tex);	
	}

	void draw_model(const gl_model& model) {
		set_texture(0, model.m_tex);		
		glDrawElements(GL_TRIANGLES, model.num_indices, GL_UNSIGNED_INT, 0);		
	}
};


class rgl4_tri_color : public rgl4 {
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
		// NOTE: Enable "gl_Position.y = -gl_Position.y;" in "gl4_vertex_pc.vert" if using this.
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
		const char* vs_filename = RS_SHADER_PATH2("gl4_vertex_pc.vert");
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
		glBufferData(GL_UNIFORM_BUFFER, sizeof(cb_struct_mat4_s), nullptr, GL_STATIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);  
		// Define the range of the buffer that links to a uniform binding point
		glBindBufferRange(GL_UNIFORM_BUFFER, 0, cbuffer_wvp, 0, sizeof(cb_struct_mat4_s));
		//------------------------------------------------------------------------

		//set_rs_culling(rs_cull_mode_e::cull_none);
		////glClipControl(GL_UPPER_LEFT, GL_ZERO_TO_ONE);				// D3D default
		//glClipControl(GL_LOWER_LEFT, GL_NEGATIVE_ONE_TO_ONE);
		// NOTE: Disable "gl_Position.y = -gl_Position.y;" in "gl4_vertex_pc.vert" if using this.

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

		gm::mat4 mat_wvp_temp_t = gm::mat4_transpose(mat_wvp_temp);

		cb_struct_mat4_s cbs_mat4_wvp = {};
		cbs_mat4_wvp.wvp = mat_wvp_temp_t;
		// Set the WVP matrix in the uniform block    
		glBindBuffer(GL_UNIFORM_BUFFER, cbuffer_wvp);
		//offset in bytes (0, 0 + sizeof(gm::mat4), etc), size, data
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(cb_struct_mat4_s), &cbs_mat4_wvp);
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


class rgl4_tri_color_tex : public rgl4 {
public:		

	gl_vao VAO;

	gl_model model0;
	gl_texture tex0;

	gm::mat4 model0_mat_world = gm::mat4::k_identity();

	gl_shader shader_vs;
	gl_shader shader_ps;
	gl_shader_program shader_prog;

	gl_buffer buffer_per_object;

	struct cb_per_object_s {
		gm::mat4 wvp;
	};
	

	void setup() {		
		enable_clip_control(true);
		set_rs_culling(rs_cull_mode_e::cull_ccw);

		//-------------------
		const char* vs_filename = RS_SHADER_PATH2("gl4_vertex_pct.vert");
		const char* ps_filename = RS_SHADER_PATH2("gl4_vertex_pct.frag");
		load_vertex_shader_file(vs_filename, shader_vs.data);
		load_pixel_shader_file(ps_filename, shader_ps.data);
		link_shaders_vs_ps(shader_prog.data, shader_vs.data, shader_ps.data);			


		rs_input_element_desc vfmt_pc[3] = {
			{"POSITION",	rs_rdfmt_e::R32G32B32_FLOAT},
			{"COLOR",		rs_rdfmt_e::R32G32B32A32_FLOAT},
			{"TEXCOORD",	rs_rdfmt_e::R32G32_FLOAT},			
		};

		gl4_create_input_element_desc(sdf::span(vfmt_pc, sdf::arr_cap(vfmt_pc)), VAO.data); 

		create_texture(RS_MEDIA_PATH("tut/glitter/dog.jpg"), tex0.data, 0);
		//create_texture(RS_MEDIA_PATH("nw_tex/checker_white.png"), tex0.data, 0);

		create_sampler_state(m_sampler_anisotropic.data, rs_texture_filter_e::texf_anisotropic, m_anisotropic_quality);

	
		// Load data to vector.
		sdr::vector<vertex_pct> vertices_vec;
		sdr::vector<uint> indices_vec;
		fill_triangle_vertex_pct(vertices_vec, indices_vec);
		
		create_model_basic(model0, vertices_vec.data(), vertices_vec.size(), sizeof(decltype(vertices_vec)::value_type),
			indices_vec.data(), indices_vec.size(), sizeof(decltype(indices_vec)::value_type), tex0.data);

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);		


		unbind_vao();
		
		//---
		glUseProgram(shader_prog.data);

		// Create Constant buffers
		glUniformBlockBinding(shader_prog.data, 0, 0);
		create_constant_buffer(sizeof(cb_per_object_s), buffer_per_object.data);

		//----------------------------------------
		// World Matrix
		//model0.mat_world = gm::mat4_translation(gm::vec3(1.25f, 0.0f, 0.0f));
		//model0.mat_world = gm::mat4_scaling(gm::vec3(2.0, 1.0, 1.0));
		// Rotating on x axis, since x axis is same while y or z can be up.
		//model0.mat_world = gm::mat4_rotation_x(mf::deg_to_rad<float>(30));

		m_camera.set_position(gm::vec3(0.0f, 0.0f, -3.0f));
		mat_proj = set_projection_matrix();
	}

	void render(float dt) {
		//-----------
		// Enable if you want to render to multiple opengl windows
		//wglMakeCurrent(m_hDC, m_hRC);	
		//-----------
		update_camera(dt);
		mat_view = m_camera.get_view_matrix();

		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

		gm::mat4 mat_wvp_temp = model0_mat_world * mat_view * mat_proj;
		gm::mat4 mat_wvp_temp_t = gm::mat4_transpose(mat_wvp_temp);


        glUseProgram(shader_prog.data);

		// Upload mat_wvp_temp_t to shader by constant buffer cb_per_frame by putting it in struct cb_per_frame_s.
		cb_per_object_s cb_per_object = {};
		cb_per_object.wvp = mat_wvp_temp_t;
		upload_constant_buffer(sizeof(cb_per_object_s), buffer_per_object.data, &cb_per_object);
 

		set_sampler_state(0, m_sampler_anisotropic.data);

        glBindVertexArray(VAO.data); 
        draw_model(model0);

		unbind_vao();
	}

	void cleanup() {
	}
};


class rgl4_cube : public rgl4 {
public:		

	gl_vao VAO;

	gl_model model0;
	gl_texture tex0;

	gm::mat4 model0_mat_world = gm::mat4::k_identity();

	gl_shader shader_vs;
	gl_shader shader_ps;
	gl_shader_program shader_prog;

	gl_buffer buffer_per_object;

	struct cb_per_object_s {
		gm::mat4 wvp;
	};
	

	void setup() {		
		enable_clip_control(true);
		set_rs_culling(rs_cull_mode_e::cull_ccw);

		//-------------------
		const char* vs_filename = RS_SHADER_PATH2("gl4_vertex_ptn.vert");
		const char* ps_filename = RS_SHADER_PATH2("gl4_vertex_ptn.frag");
		load_vertex_shader_file(vs_filename, shader_vs.data);
		load_pixel_shader_file(ps_filename, shader_ps.data);
		link_shaders_vs_ps(shader_prog.data, shader_vs.data, shader_ps.data);	
			
		rs_input_element_desc vfmt_pc[3] = {
			{"POSITION",	rs_rdfmt_e::R32G32B32_FLOAT},
			{"TEXCOORD",	rs_rdfmt_e::R32G32_FLOAT},
			{"NORMAL",		rs_rdfmt_e::R32G32B32_FLOAT},	
		};

		gl4_create_input_element_desc(sdf::span(vfmt_pc, sdf::arr_cap(vfmt_pc)), VAO.data); 

		//create_texture(RS_MEDIA_PATH("tut/glitter/dog.jpg"), tex0.data, 0);
		create_texture(RS_MEDIA_PATH("nw_tex/checker_white.png"), tex0.data, 0);

		create_sampler_state(m_sampler_anisotropic.data, rs_texture_filter_e::texf_anisotropic, m_anisotropic_quality);	
	
		// Load data to vector.
		rs_model<vertex_ptn> rmodel0;	
		fill_cube_vertex_ptn(rmodel0.vertices_vec, rmodel0.indices_vec);

		create_model_rsmodel(model0, rmodel0, tex0.data);

		rmodel0.clear_memory();	


		unbind_vao();
		
		//---
		glUseProgram(shader_prog.data);

		// Create Constant buffers
		glUniformBlockBinding(shader_prog.data, 0, 0);
		create_constant_buffer(sizeof(cb_per_object_s), buffer_per_object.data);

		//----------------------------------------
		// World Matrix
		//model0.mat_world = gm::mat4_translation(gm::vec3(1.25f, 0.0f, 0.0f));
		//model0.mat_world = gm::mat4_scaling(gm::vec3(2.0, 1.0, 1.0));
		// Rotating on x axis, since x axis is same while y or z can be up.
		//model0.mat_world = gm::mat4_rotation_x(mf::deg_to_rad<float>(30));

		m_camera.set_position(gm::vec3(0.0f, 3.0f, -8.0f));
		mat_proj = set_projection_matrix();
	}

	void render(float dt) {
		//-----------
		// Enable if you want to render to multiple opengl windows
		//wglMakeCurrent(m_hDC, m_hRC);	
		//-----------
		update_camera(dt);
		mat_view = m_camera.get_view_matrix();

		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);

		gm::mat4 mat_wvp_temp = model0_mat_world * mat_view * mat_proj;
		gm::mat4 mat_wvp_temp_t = gm::mat4_transpose(mat_wvp_temp);


        glUseProgram(shader_prog.data);

		// Upload mat_wvp_temp_t to shader by constant buffer cb_per_frame by putting it in struct cb_per_frame_s.
		cb_per_object_s cb_per_object = {};
		cb_per_object.wvp = mat_wvp_temp_t;
		upload_constant_buffer(sizeof(cb_per_object_s), buffer_per_object.data, &cb_per_object);
 

		set_sampler_state(0, m_sampler_anisotropic.data);

        glBindVertexArray(VAO.data); 
        draw_model(model0);

		unbind_vao();
	}

	void cleanup() {
	}
};