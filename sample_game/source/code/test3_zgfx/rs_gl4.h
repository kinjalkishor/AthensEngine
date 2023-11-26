#pragma once

//------------------------------------
#include "win32_loader_gl_wgl.h"

//------------------------------------

#include "rs_gl_util.h"

#include "rs_irenderer.h"
#include "rs_hdr_gl.h"


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

		glGetShaderInfoLog(hshader, sdf::size(infoLog), nullptr, infoLog);
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

inline void load_vertex_shader_file(const char* shader_filename, uint& vs_shader) {
	gl4_compile_shader_from_file(shader_filename, "vs", vs_shader);
}
inline void load_pixel_shader_file(const char* shader_filename, uint& ps_shader) {
	gl4_compile_shader_from_file(shader_filename, "ps", ps_shader);
}

inline bool link_shaders_vs_ps(uint& shaderProgram, uint vs_shader, uint ps_shader) {
	return gl4_link_shaders(shaderProgram, vs_shader, ps_shader);
}

//--------------------------------

inline void create_vertex_buffer(UINT vb_size_bytes, const void* sys_mem_data, uint& vb, uint vstride) {
	//isz vb_size_bytes = vertices_vec.size() * sizeof(vertex_type);
	glGenBuffers(1, &vb);		
	glBindBuffer(GL_ARRAY_BUFFER, vb);
	glBufferData(GL_ARRAY_BUFFER, vb_size_bytes, sys_mem_data, GL_STATIC_DRAW);

	glBindVertexBuffer(0, vb, 0, vstride);		
}

inline void create_index_buffer(UINT ib_size_bytes, const void* sys_mem_data, uint& ib) {
	//isz ib_size_bytes = indices_vec.size() * sizeof(index_type_uint);
	glGenBuffers(1, &ib);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, ib_size_bytes, sys_mem_data, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
}

inline void create_constant_buffer(UINT cb_size_bytes, uint& buffer) {		
	// Create the uniform/constant buffer
	glGenBuffers(1, &buffer);  
	glBindBuffer(GL_UNIFORM_BUFFER, buffer);
	glBufferData(GL_UNIFORM_BUFFER, cb_size_bytes, nullptr, GL_STATIC_DRAW);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);  
	// Define the range of the buffer that links to a uniform binding point
	glBindBufferRange(GL_UNIFORM_BUFFER, 0, buffer, 0, cb_size_bytes);
}
inline void upload_constant_buffer(UINT cb_size_bytes, uint& constant_buffers, const void* src_data) {
	// Set the WVP matrix in the uniform block    
	glBindBuffer(GL_UNIFORM_BUFFER, constant_buffers);
	//offset in bytes (0, 0 + sizeof(gm::mat4), etc), size, data
	glBufferSubData(GL_UNIFORM_BUFFER, 0, cb_size_bytes, src_data);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);  
}

inline void create_texture(const char* tex_file_name, uint& tex, uint tex_stage) {
	// Check if DDS texture.
	char filename_ext[8];
	get_filename_ext(filename_ext, tex_file_name);
	bool tex_is_dds = !strcmpi(filename_ext, "dds");

	//if (tex_is_dds) {
	//} else {
		glGenTextures(1, &tex);
		glActiveTexture(GL_TEXTURE0 + tex_stage);
		glBindTexture(GL_TEXTURE_2D, tex);

		gl_load_texture(tex_file_name, false);				
	//}		
}
//--------------------------------
// OpenGL 3.3 sampler states allow to stick to Direct3D 11 logic and its D3D11_SAMPLER_DESC structure and 
// CreateSamplerState(D3D11 device) and PSSetSamplers(immediate context) functions.
inline void create_sampler_state(uint& sampler_state, rs_texture_filter_e filtering, int anisotropic_quality) {
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

inline void set_sampler_state(uint tex_unit, uint& sampler_state) {
	glBindSampler(tex_unit, sampler_state);
}

inline void unbind_vao() {
	glBindVertexArray(0); 
}

inline void set_texture(uint tex_stage, const uint& tex) {
	glActiveTexture(GL_TEXTURE0 + tex_stage);
	glBindTexture(GL_TEXTURE_2D, tex);
}
inline void set_texture_null(uint tex_stage) {
	glActiveTexture(GL_TEXTURE0 + tex_stage);
	glBindTexture(GL_TEXTURE_2D, 0);
}

//--------------------------
class wm_rgl4 : public wm_irenderer {
public:
	HDC m_hDC = nullptr;
	HGLRC m_hRC = nullptr;

	//-------------
	HWND gl_helper_hwnd = nullptr;
	HDC gl_helper_hdc = nullptr;
	HGLRC gl_helper_hrc = nullptr;

	bool use_opengl_compatibility_profile = false;

	int gl_ver_major = 4;
	int gl_ver_minor = 6;

	uint m_sampler_anisotropic;


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

	bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { 
		set_init_params(hwnd, width, height, " : OpenGL4.6");		

		//------------
		// Create helper window for creating temporary OpenGL context for loading OpenGL function pointers.
		gl_helper_window_init(hInstance);
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

		#if !USE_GLAD_LIB
			// Load OpenGL functions. Own glfn.
			glfnlib_load((PFN_loadfunc_gl)get_gl_func_address_name);
		#endif

		#if USE_GLAD_LIB
			// Glad2
			// With glad loader func.
			//if (!gladLoaderLoadGL()) { printfln("Failed to initialize GLAD"); }	
			// If glad loader func not generated.
			// Load OpenGL functions, gladLoadGL returns the loaded version, 0 on error.
			// glfwGetProcAddress is already correct type
			//int version = gladLoadGL(glfwGetProcAddress); 
			//int version = gladLoadGL((GLADloadfunc)glfwGetProcAddress); 

			int version = gladLoadGL((GLADloadfunc)get_gl_func_address_name);
			////int version = gladLoadGLUserPtr((GLADuserptrloadfunc)get_gl_func_address_userptr, wglfn.instance);
		#endif
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

		resize_internal();

		setup_post_init();

		return true;
	}

	void resize_internal() {	
		// make sure the viewport matches the new window dimensions; note that width and 
		// height will be significantly larger than specified on retina displays.
		glViewport(0, 0, m_client_width, m_client_height);

		// Set the viewport transform.

		// If changed again in resize.
		//set_rs_anitialiasing();

		mat_proj = get_proj_matrix();
	}

	void deinit_r() {
		glDeleteSamplers(1, &m_sampler_anisotropic);

		if (m_hRC) {
			if (!wglfn.fwglMakeCurrent(nullptr, nullptr)) {
				printfln("Release Of DC And RC Failed.");
			}
			if (!wglfn.fwglDeleteContext(m_hRC)) {
				printfln("Release Rendering Context Failed.");
			}
			m_hRC = nullptr;
		}

		//HWND hwnd = WindowFromDC(m_hDC);
		if (m_hDC) {
			if (!ReleaseDC(m_render_window, m_hDC)) {
				printfln("Release Device Context Failed.");
			}
			m_hDC = nullptr;
		}

		wglfn.deinit();
	}

	void setup() {}
	void cleanup() {}

	void render(float dt) {
		clear(gm::color4(0.0, 1.0, 0.0, 1.0));
	}

	void swap_buffers() {
		// Swap the back and front buffers.
		SwapBuffers(m_hDC);
	}
	//-----------------------
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
	void clear(const gm::color4& color_rgba) {
		clear_render_target(color_rgba);
		clear_depth_stencil(true, true, 1.0f, 0);
	}

	void setup_post_init() {
		// The polygon area computation defined by gl_FrontFacing to determine if a polygon is front- 
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
};

class wm_rgl4_tri0 : public wm_rgl4 {
public:
	uint VAO = 0;

	uint model_vb = 0;
	uint model_ib = 0;
	int64 model_num_vertices = 0;
	int64 model_num_indices = 0;

	gm::mat4 mat_world_model = gm::mat4::k_identity();

	uint vs_shader = 0;
	uint ps_shader = 0;
	uint shader_prog = 0;

	struct cb_per_object_s {
		gm::mat4 wvp;
	};
	uint buffer_per_object = 0;

	void setup() {
		// Visible Front face is CW. Cull back Face CCW.
		set_rs_culling(rs_cull_mode_e::cull_ccw);			

		//-------------------
		//load_shaders_file(RS_SHADER_PATH2("gl4_vertex_pc.vert"), RS_SHADER_PATH2("gl4_vertex_pc.frag"), vs_shader, ps_shader);
		load_vertex_shader_file(RS_SHADER_PATH("gl4_vertex_pc.vert"), vs_shader);
		load_pixel_shader_file(RS_SHADER_PATH("gl4_vertex_pc.frag"), ps_shader);
		link_shaders_vs_ps(shader_prog, vs_shader, ps_shader);	


		// Load data to vector.
		sdr::vector<vertex_pc> vertices_vec;
		sdr::vector<uint> indices_vec;

		//glClipControl(GL_LOWER_LEFT, GL_NEGATIVE_ONE_TO_ONE);		// OpenGL default
		//glClipControl(GL_UPPER_LEFT, GL_ZERO_TO_ONE);				// D3D default

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
		model_num_vertices = sdf::arr_cap(triangle_arr_vert_c_d3d);
		model_num_indices = sdf::arr_cap(triangle_arr_ind_d3d);	

		vertices_vec.resize(model_num_vertices);
		sdf::mem_copy(vertices_vec.data(), triangle_arr_vert_c_d3d, model_num_vertices);
		indices_vec.resize(model_num_indices);
		sdf::mem_copy(indices_vec.data(), triangle_arr_ind_d3d, model_num_indices);
		
		//---
		isz vb_size_bytes = vertices_vec.size() * sizeof(vertex_pc);	
		glGenBuffers(1, &model_vb);		
		glBindBuffer(GL_ARRAY_BUFFER, model_vb);
		glBufferData(GL_ARRAY_BUFFER, vb_size_bytes, vertices_vec.data(), GL_STATIC_DRAW);

		isz ib_size_bytes = indices_vec.size() * sizeof(uint);
		glGenBuffers(1, &model_ib);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model_ib);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, ib_size_bytes, indices_vec.data(), GL_STATIC_DRAW);

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);
		//---

		// Create VAO.
		glGenVertexArrays(1, &VAO);	
		glBindVertexArray(VAO);

		// Create vertex declaration.
		glEnableVertexAttribArray(0);
		glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
		glVertexAttribBinding(0, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribFormat(1, 4, GL_FLOAT, GL_FALSE, (3 * sizeof(float)));
		glVertexAttribBinding(1, 0);

		
		int stride = sizeof(vertex_pc);
		glBindVertexBuffer(0, model_vb, 0, stride);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model_ib);

		unbind_vao();
		
		//---
		glUseProgram(shader_prog);


		// Create Constant buffers
		glUniformBlockBinding(shader_prog, 0, 0);
		// Create the uniform/constant buffer
		glGenBuffers(1, &buffer_per_object);  
		glBindBuffer(GL_UNIFORM_BUFFER, buffer_per_object);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(cb_per_object_s), nullptr, GL_STATIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);  
		// Define the range of the buffer that links to a uniform binding point
		glBindBufferRange(GL_UNIFORM_BUFFER, 0, buffer_per_object, 0, sizeof(cb_per_object_s));
		//------------------------------------------------------------------------

		// Set WVP matrices.
		set_world_matrix_tri1(mat_world_model);
		set_view_matrix_tri1(mat_view);
		set_proj_matrix_tri1(mat_proj, m_client_width, m_client_height);
	}

	void cleanup() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &model_vb);
		glDeleteBuffers(1, &model_ib);	
		glDeleteBuffers(1, &buffer_per_object);
		glDeleteShader(vs_shader);
		glDeleteShader(ps_shader);
		glDeleteProgram(shader_prog);
	}

	void render(float dt) {
		//-----------
		// Enable if you want to render to multiple opengl windows
		//wglMakeCurrent(m_hDC, m_hRC);	
		//-----------

		clear(k_clear_color);		

        // draw our first triangle
        glUseProgram(shader_prog);

		gm::mat4 mat_wvp_temp = mat_world_model * mat_view * mat_proj;
		gm::mat4 mat_wvp_temp_t = gm::mat4_transpose(mat_wvp_temp);

		cb_per_object_s cb_per_object = {};
		cb_per_object.wvp = mat_wvp_temp_t;
		// Set the WVP matrix in the uniform block    
		glBindBuffer(GL_UNIFORM_BUFFER, buffer_per_object);
		//offset in bytes (0, 0 + sizeof(gm::mat4), etc), size, data
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(cb_per_object_s), &cb_per_object);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);  

        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //glDrawArrays(GL_TRIANGLES, 0, model_num_indices);
        glDrawElements(GL_TRIANGLES, model_num_indices, GL_UNSIGNED_INT, 0);
        // unbind_vao(); // no need to unbind it every time  
	}

	//----------------------------------
};

class wm_rgl4_tri_gl33 : public wm_rgl4 {
public:
	uint VAO = 0;

	uint model_vb = 0;
	uint model_ib = 0;
	int64 model_num_vertices = 0;
	int64 model_num_indices = 0;

	gm::mat4 mat_world_model = gm::mat4::k_identity();

	uint vs_shader = 0;
	uint ps_shader = 0;
	uint shader_prog = 0;

	uint hmat_wvp = 0;
	//struct cb_per_object_s {
	//	gm::mat4 wvp;
	//};
	//uint buffer_per_object = 0;


	void setup() {
		set_rs_culling_gl(rs_cull_mode_e::cull_ccw);			
		glClipControl(GL_LOWER_LEFT, GL_NEGATIVE_ONE_TO_ONE);		// OpenGL default

		// Load Shaders.
		load_vertex_shader_file(RS_SHADER_PATH("gl4_vertex_pc.vert"), vs_shader);
		load_pixel_shader_file(RS_SHADER_PATH("gl4_vertex_pc.frag"), ps_shader);
		link_shaders_vs_ps(shader_prog, vs_shader, ps_shader);	
		// Obtain handles
		hmat_wvp = glGetUniformLocation(shader_prog, "g_wvp");

		// Create VAO.
		glGenVertexArrays(1, &VAO);	
		glBindVertexArray(VAO);	


		// Load data to vector.
		sdr::vector<vertex_pc> vertices_vec;
		sdr::vector<uint> indices_vec;
		fill_triangle_vertex_pc(vertices_vec, indices_vec);

		model_num_vertices = vertices_vec.size();
		model_num_indices = indices_vec.size();		
		//-----------------
		glBindVertexArray(VAO);

		glGenBuffers(1, &model_vb);
		glBindBuffer(GL_ARRAY_BUFFER, model_vb);
		glBufferData(GL_ARRAY_BUFFER, vertices_vec.size() * sizeof(vertex_pc), vertices_vec.data(), GL_STATIC_DRAW);

		glGenBuffers(1, &model_ib);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model_ib);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_vec.size() * sizeof(uint), indices_vec.data(), GL_STATIC_DRAW);


		// Create vertex declaration.
		//glEnableVertexAttribArray(0);
		//glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
		//glVertexAttribBinding(0, 0);
		//glEnableVertexAttribArray(1);
		//glVertexAttribFormat(1, 4, GL_FLOAT, GL_FALSE, (3 * sizeof(float)));
		//glVertexAttribBinding(1, 0);

		// De-interleaved vertex data
		// Only difference is more buffers generated and offset is zero, (easy to compose various formats data though)
		//-http://www.opengl-tutorial.org/beginners-tutorials/tutorial-4-a-colored-cube/
		// 1st attribute buffer : vertices
		// This will identify our vertex buffer
	#if 0
		GLuint vertexbuffer;
		glGenBuffers(1, &vertexbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		GLuint colorbuffer;
		glGenBuffers(1, &colorbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	#endif

		// Interleaved vertex data
		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float))); //12
		glEnableVertexAttribArray(1);
		// texture coord attribute
		//num_bytes in vertex format is (9 * sizeof(float)) if using texture also.
		//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float))); //28
		//glEnableVertexAttribArray(2);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0); 
		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		unbind_vao();


		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);
		//---
		
		//---
		glUseProgram(shader_prog);

		//// Create Constant buffers
		//glUniformBlockBinding(shader_prog, 0, 0);
		//create_constant_buffer(sizeof(cb_per_object_s), buffer_per_object);


		// Set WVP matrices.
		set_world_matrix_tri1(mat_world_model);
		set_view_matrix_tri1(mat_view);
		set_proj_matrix_tri1(mat_proj, m_client_width, m_client_height);
	}

	void cleanup() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &model_vb);
		glDeleteBuffers(1, &model_ib);	
		//glDeleteBuffers(1, &buffer_per_object);
		glDeleteShader(vs_shader);
		glDeleteShader(ps_shader);
		glDeleteProgram(shader_prog);
	}

	void render(float dt) {
		//-----------
		// Enable if you want to render to multiple opengl windows
		//wglMakeCurrent(m_hDC, m_hRC);	
		//-----------

		clear(k_clear_color);

        glUseProgram(shader_prog);

		gm::mat4 mat_wvp_temp = mat_world_model * mat_view * mat_proj;
		gm::mat4 mat_wvp_temp_t = gm::mat4_transpose(mat_wvp_temp);

		// get matrix's uniform location and set matrix       
        glUniformMatrix4fv(hmat_wvp, 1, GL_FALSE, mat_wvp_temp_t.data());

		//cb_per_object_s cb_per_object = {};
		//cb_per_object.wvp = mat_wvp_temp_t;
		//upload_constant_buffer(sizeof(cb_per_object_s), buffer_per_object, &cb_per_object);

		// Draw one triangle.
        glBindVertexArray(VAO); 
        //glDrawArrays(GL_TRIANGLES, 0, model_num_indices);
        glDrawElements(GL_TRIANGLES, model_num_indices, GL_UNSIGNED_INT, 0);
        ////unbind_vao();; // no need to unbind it every time  
	}

};


#define GL4_TRI_SEP_MAT_GLCOORD 1

class wm_rgl4_tri_sep_mat : public wm_rgl4 {
public:
	uint VAO = 0;

	uint model_vb = 0;
	uint model_ib = 0;
	int64 model_num_vertices = 0;
	int64 model_num_indices = 0;

	gm::mat4 mat_world_model = gm::mat4::k_identity();

	uint vs_shader = 0;
	uint ps_shader = 0;
	uint shader_prog = 0;

	struct cb_per_object_ex2_s {
		gm::mat4 wvp;
		gm::mat4 W;
		gm::mat4 V;
		gm::mat4 P;
		int mode;
		float pad[3];
	};
	uint buffer_per_object = 0;

	void setup() {
		//set_rs_culling(rs_cull_mode_e::cull_ccw);		
		set_rs_culling(rs_cull_mode_e::cull_none);			

		// Load Shaders.
		load_vertex_shader_file(RS_SHADER_PATH("gl4_vertex_pc_sep_wvp_gl_coord.vert"), vs_shader);
		load_pixel_shader_file(RS_SHADER_PATH("gl4_vertex_pc.frag"), ps_shader);
		link_shaders_vs_ps(shader_prog, vs_shader, ps_shader);	

		// Create VAO.
		glGenVertexArrays(1, &VAO);	
		glBindVertexArray(VAO);

		// Create vertex declaration.
		glEnableVertexAttribArray(0);
		glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
		glVertexAttribBinding(0, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribFormat(1, 4, GL_FLOAT, GL_FALSE, (3 * sizeof(float)));
		glVertexAttribBinding(1, 0);


		// Load data to vector.
	#if !GL4_TRI_SEP_MAT_GLCOORD
		glClipControl(GL_UPPER_LEFT, GL_ZERO_TO_ONE);				// D3D default

		vertex_pc triangle_arr_vert_c_d3d[] = {
			{-1.0, 0.0, 0.9,	1.0, 0.0, 0.0, 1.0}, // bottom-left red
			{ 0.0, 1.0, 0.9,	0.0, 1.0, 0.0, 1.0}, // top green
			{ 1.0, 0.0, 0.9,	0.0, 0.0, 1.0, 1.0}, // bottom-right blue
		};
	#else
		glClipControl(GL_LOWER_LEFT, GL_NEGATIVE_ONE_TO_ONE);		// OpenGL default
		
		vertex_pc triangle_arr_vert_c_d3d[] = {
			{-1.0, 0.0, -0.9,	1.0, 0.0, 0.0, 1.0}, // bottom-left red
			{ 0.0, 1.0, -0.9,	0.0, 1.0, 0.0, 1.0}, // top green
			{ 1.0, 0.0, -0.9,	0.0, 0.0, 1.0, 1.0}, // bottom-right blue
		};
	#endif

		uint triangle_arr_ind_d3d[] = {
			0, 1, 2,
		};
		model_num_vertices = sdf::arr_cap(triangle_arr_vert_c_d3d);
		model_num_indices = sdf::arr_cap(triangle_arr_ind_d3d);	

		create_vertex_buffer(model_num_vertices * sizeof(vertex_pc), triangle_arr_vert_c_d3d, model_vb, sizeof(vertex_pc));	
		create_index_buffer(model_num_indices * sizeof(uint), triangle_arr_ind_d3d, model_ib);

		//---

		// Unbind VAO.
		unbind_vao();
		
		//---
		glUseProgram(shader_prog);

		// Create Constant buffers
		glUniformBlockBinding(shader_prog, 0, 0);
		create_constant_buffer(sizeof(cb_per_object_ex2_s), buffer_per_object);

	#if !GL4_TRI_SEP_MAT_GLCOORD
		// World Matrix
		mat_world_model = gm::mat4_translation(gm::vec3(1.25f, 0.0f, 0.0f));
		//mat_world_model = gm::mat4_scaling(gm::vec3(2.0, 1.0, 1.0));
		// Rotating on x axis, since x axis is same while y or z can be up.
		//mat_world_model = gm::mat4_rotation_x(mf::deg_to_rad<float>(30));	

		// View Matrix
		// Position and aim the camera.
		gm::vec3 position(0.0f, 0.0f, -2.0f);
		gm::vec3 target(0.0f, 0.0f, 0.0f);
		gm::vec3 up(0.0f, 1.0f, 0.0f);
		mat_view = gm::mat4_look_at_lh(position, target, up);	

		// Projection Matrix
		mat_proj = gm::mat4_perspective_fov_lh(
						mf::deg_to_rad<float>(100), //yfov
						//1.777777,	//(16/9) //(float)800 / (float)600,
						sdf::get_aspect_ratio(m_client_width, m_client_height),
						0.9f,		//1.0f,
						1000.0f);

		// Set WVP matrices.
		//set_world_matrix_tri1(mat_world_model);
		//set_view_matrix_tri1(mat_view);
		//set_proj_matrix_tri1(mat_proj, m_client_width, m_client_height);
	#else
		// World Matrix
		mat_world_model = gm::mat4_translation(gm::vec3(1.25f, 0.0f, 0.0f));
		//mat_world_model = gm::mat4_scaling(gm::vec3(2.0, 1.0, 1.0));
		// Rotating on x axis, since x axis is same while y or z can be up.
		//mat_world_model = gm::mat4_rotation_x(mf::deg_to_rad<float>(30));	

		// View Matrix
		// Position and aim the camera.
		// d3d eye: -2.0 to 0.9 (+z), gl eye: 2.0 to -0.9 (-z)
		gm::vec3 position(0.0f, 0.0f, 2.0f);					//z is +ve
		gm::vec3 target(0.0f, 0.0f, 0.0f);
		gm::vec3 up(0.0f, 1.0f, 0.0f);
		mat_view = gm::mat4_look_at_rh(position, target, up);	//glm::lookAtRH

		// Projection Matrix
		//glm::perspectiveRH_NO  //use no version this is zo
		mat_proj = 
				//gm::mat4_perspective_fov_rh(					//mat4_perspective_fov_rh
				gm::glm_perspectiveRH_NO(
						mf::deg_to_rad<float>(100), //yfov
						//1.777777,	//(16/9) //(float)800 / (float)600,
						sdf::get_aspect_ratio(m_client_width, m_client_height),
						0.9f,		//1.0f,
						1000.0f);
	#endif
	}

	void cleanup() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &model_vb);
		glDeleteBuffers(1, &model_ib);	
		glDeleteBuffers(1, &buffer_per_object);
		glDeleteShader(vs_shader);
		glDeleteShader(ps_shader);
		glDeleteProgram(shader_prog);
	}

	void render(float dt) {
		//-----------
		// Enable if you want to render to multiple opengl windows
		//wglMakeCurrent(m_hDC, m_hRC);	
		//-----------

		clear(k_clear_color);

		// Set shaders.
        glUseProgram(shader_prog);

	#if !GL4_TRI_SEP_MAT_GLCOORD
		gm::mat4 mat_wvp_temp = mat_world_model * mat_view * mat_proj;
		gm::mat4 mat_wvp_temp_t = gm::mat4_transpose(mat_wvp_temp);
	#else
		gm::mat4 mat_wvp_temp;
		// same as glm matrix multiplication. glms reverse multiplies (a,b) internally to (b*a).
		mat_wvp_temp = mat4_mul_gl(mat_proj, mat4_mul_gl(mat_view, mat_world_model));
		//or
		//mat_wvp_temp = mat_world_model * mat_view * mat_proj;
		gm::mat4 mat_wvp_temp_t = mat_wvp_temp;
	#endif

		// Upload mat_wvp_temp_t to shader by constant buffer "buffer_per_object" of type struct cb_per_object_s.
		cb_per_object_ex2_s cb_per_object = {};
	#if !GL4_TRI_SEP_MAT_GLCOORD
		//cb_per_object.mode = 1;
		cb_per_object.mode = 2; //seperate matrices in shader
		cb_per_object.W = gm::mat4_transpose(mat_world_model);
		cb_per_object.V = gm::mat4_transpose(mat_view);
		cb_per_object.P = gm::mat4_transpose(mat_proj);	
	#else
		cb_per_object.mode = 3;
		//cb_per_object.mode = 4; //seperate matrices in shader
		cb_per_object.W = mat_world_model;
		cb_per_object.V = mat_view;
		cb_per_object.P = mat_proj;	
	#endif
		cb_per_object.wvp = mat_wvp_temp_t;
		upload_constant_buffer(sizeof(cb_per_object_ex2_s), buffer_per_object, &cb_per_object);

		// Draw one triangle.
        glBindVertexArray(VAO); 
        //glDrawArrays(GL_TRIANGLES, 0, model_num_indices);
        glDrawElements(GL_TRIANGLES, model_num_indices, GL_UNSIGNED_INT, 0);
        ////unbind_vao(); // no need to unbind it every time  
	}
};


#define GL4_TEXTURES 1

class wm_rgl4_tri : public wm_rgl4 {
public:
	uint VAO = 0;

	uint model_vb = 0;
	uint model_ib = 0;
	int64 model_num_vertices = 0;
	int64 model_num_indices = 0;

	gm::mat4 mat_world_model = gm::mat4::k_identity();

	uint vs_shader = 0;
	uint ps_shader = 0;
	uint shader_prog = 0;

	struct cb_per_object_s {
		gm::mat4 wvp;
	};
	uint buffer_per_object = 0;

	uint tex = 0;

	void setup() {
		set_rs_culling(rs_cull_mode_e::cull_ccw);			

	#if !GL4_TEXTURES
		// Load Shaders.
		load_vertex_shader_file(RS_SHADER_PATH("gl4_vertex_pc.vert"), vs_shader);
		load_pixel_shader_file(RS_SHADER_PATH("gl4_vertex_pc.frag"), ps_shader);
		link_shaders_vs_ps(shader_prog, vs_shader, ps_shader);	

		// Create VAO.
		glGenVertexArrays(1, &VAO);	
		glBindVertexArray(VAO);

		// Create vertex declaration.
		glEnableVertexAttribArray(0);
		glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
		glVertexAttribBinding(0, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribFormat(1, 4, GL_FLOAT, GL_FALSE, (3 * sizeof(float)));
		glVertexAttribBinding(1, 0);


		// Load data to vector.
		sdr::vector<vertex_pc> vertices_vec;
		sdr::vector<uint> indices_vec;
		fill_triangle_vertex_pc(vertices_vec, indices_vec);

		model_num_vertices = vertices_vec.size();
		model_num_indices = indices_vec.size();		
		
		// Create the vertex buffer. 
		create_vertex_buffer(vec_size_bytes(vertices_vec), vertices_vec.data(), model_vb, sizeof(vertex_pc));
	#else
		// Load Shaders.
		load_vertex_shader_file(RS_SHADER_PATH("gl4_vertex_pct.vert"), vs_shader);
		load_pixel_shader_file(RS_SHADER_PATH("gl4_vertex_pct.frag"), ps_shader);
		link_shaders_vs_ps(shader_prog, vs_shader, ps_shader);	

		// Create VAO.
		glGenVertexArrays(1, &VAO);	
		glBindVertexArray(VAO);

		// Create vertex declaration.
		glEnableVertexAttribArray(0);
		glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
		glVertexAttribBinding(0, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribFormat(1, 4, GL_FLOAT, GL_FALSE, (3 * sizeof(float)));
		glVertexAttribBinding(1, 0);

		glEnableVertexAttribArray(2);
		glVertexAttribFormat(2, 2, GL_FLOAT, GL_FALSE, ((3+4) * sizeof(float)));
		glVertexAttribBinding(2, 0);


		// Load data to vector.
		sdr::vector<vertex_pct> vertices_vec;
		sdr::vector<uint> indices_vec;
		fill_triangle_vertex_pct(vertices_vec, indices_vec);

		model_num_vertices = vertices_vec.size();
		model_num_indices = indices_vec.size();		
		
		// Create the vertex buffer. 
		create_vertex_buffer(vec_size_bytes(vertices_vec), vertices_vec.data(), model_vb, sizeof(vertex_pct));

		// Create the texture and set filters.
		create_texture(RS_MEDIA_PATH("crate1.jpg"), tex, 0);
		create_sampler_state(m_sampler_anisotropic, rs_texture_filter_e::texf_anisotropic, m_anisotropic_quality);
	#endif

		// Create the index buffer. 
		create_index_buffer(vec_size_bytes(indices_vec), indices_vec.data(), model_ib);		

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);
		//---

		// Unbind VAO.
		unbind_vao();
		
		//---
		glUseProgram(shader_prog);

		// Create Constant buffers
		glUniformBlockBinding(shader_prog, 0, 0);
		create_constant_buffer(sizeof(cb_per_object_s), buffer_per_object);


		// Set WVP matrices.
		set_world_matrix_tri1(mat_world_model);
		set_view_matrix_tri1(mat_view);
		set_proj_matrix_tri1(mat_proj, m_client_width, m_client_height);

		//create_font(m_device, m_font);
	}

	void cleanup() {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &model_vb);
		glDeleteBuffers(1, &model_ib);	
		glDeleteBuffers(1, &buffer_per_object);
		glDeleteShader(vs_shader);
		glDeleteShader(ps_shader);
		glDeleteProgram(shader_prog);
		glDeleteTextures(1, &tex);
	}

	void render(float dt) {
		//-----------
		// Enable if you want to render to multiple opengl windows
		//wglMakeCurrent(m_hDC, m_hRC);	
		//-----------

		clear(k_clear_color);

		// Set shaders.
        glUseProgram(shader_prog);

		#if GL4_TEXTURES
			glActiveTexture(GL_TEXTURE0 + 0);
			glBindTexture(GL_TEXTURE_2D, tex);

			glBindSampler(0, m_sampler_anisotropic);
		#endif


		gm::mat4 mat_wvp_temp = mat_world_model * mat_view * mat_proj;
		gm::mat4 mat_wvp_temp_t = gm::mat4_transpose(mat_wvp_temp);

		// Upload mat_wvp_temp_t to shader by constant buffer "buffer_per_object" of type struct cb_per_object_s.
		cb_per_object_s cb_per_object = {};
		cb_per_object.wvp = mat_wvp_temp_t;
		upload_constant_buffer(sizeof(cb_per_object_s), buffer_per_object, &cb_per_object);

		// Draw one triangle.
        glBindVertexArray(VAO); 
        //glDrawArrays(GL_TRIANGLES, 0, model_num_indices);
        glDrawElements(GL_TRIANGLES, model_num_indices, GL_UNSIGNED_INT, 0);
        ////unbind_vao(); // no need to unbind it every time  

		//draw_font(m_device, m_font, "Hello World");
		//reset_default_states();
	}

};