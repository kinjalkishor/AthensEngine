#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "base_types.h"
#include "base_print.h"

#include "t2_rs_shared.h"
#include "t2_rs_vertex_formats.h"

#include "rs_camera_la.h"

class irenderer {
public:
	//int m_width = 640;
	//int m_height = 480;	

	float m_aspect_ratio = 1.0f;

	gm::mat4 mat_view = gm::mat4::k_identity();
	gm::mat4 mat_proj = gm::mat4::k_identity();


	bool msaa_enabled = false;
	int msaa_sample_count = 4;
	UINT msaa_num_quality_levels = 0;

	UINT curr_msaa_sample_count = 1;
	UINT curr_msaa_sample_quality = 0;

	//uint m_anisotropic_quality = 16;

	float m_xfov_deg = 90.0f;
	float m_near_plane = 1.0f;
	float m_far_plane = 1000.0f;

	camera_la m_camera;



	irenderer() {}
	virtual ~irenderer() {}	

	virtual bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) { eprintfln(""); return false; }
	virtual void deinit_r() { eprintfln(""); }

	virtual void setup() { eprintfln(""); }
	virtual void cleanup() { eprintfln(""); }
	virtual void render(float dt) { eprintfln(""); }
	virtual void swap_buffers() { eprintfln(""); }

	//virtual void switch_to_fullscreen(bool fullscreen) {}
	//------------------------------------
	void set_fov(float x_fov_deg) { m_xfov_deg = x_fov_deg; } 
	gm::mat4 set_projection_matrix() {
		float yfov = mf::yfov_from_xfov_deg(m_xfov_deg, m_aspect_ratio);
		return gm::mat4_perspective_fov_lh(yfov, m_aspect_ratio, m_near_plane, m_far_plane);		
	}
	gm::mat4 set_view_matrix(gm::vec3 eye, gm::vec3 at, gm::vec3 up) {
		return gm::mat4_look_at_lh(eye, at, up);
	}


	//------------------------------------
	void update_camera(float dt) {
		float move_sensitivity = 4.0;
		float rotation_sensitivity = 1.0;

		// set walk, rotation speed variable, action keys
		if (get_async_key_state('W')) {
			m_camera.walk(move_sensitivity * dt);
		}
		if (get_async_key_state('S')) {
			m_camera.walk(-move_sensitivity * dt);
		}
		if (get_async_key_state('A')) {
			m_camera.strafe(-move_sensitivity * dt);
		}
		if (get_async_key_state('D')) {
			m_camera.strafe(move_sensitivity * dt);
		}
		if (get_async_key_state('C')) {
			m_camera.fly(-move_sensitivity * dt);
		}
		if (get_async_key_state(VK_SPACE)) {
			m_camera.fly(move_sensitivity * dt);
		}
		if (get_async_key_state('R')) {
			m_camera.pitch(rotation_sensitivity * dt);
		}
		if (get_async_key_state('F')) {
			m_camera.pitch(-rotation_sensitivity * dt);
		}
		if (get_async_key_state('Q')) {
			m_camera.yaw(-rotation_sensitivity * dt);
		}			
		if (get_async_key_state('E')) {
			m_camera.yaw(rotation_sensitivity * dt);
		}
		if (get_async_key_state('T')) {
			m_camera.roll(rotation_sensitivity * dt);
		}
		if (get_async_key_state('G')) {
			m_camera.roll(-rotation_sensitivity * dt);
		}		
	}

};

//------------------------
template<class T>
class rs_com_raii {
public:
	T* data = nullptr;    
	~rs_com_raii() { com_release(data); }
};

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


//------------------------
// constant buffers for matrices only
struct cb_struct_mat4_s {
	gm::mat4 wvp;
};

enum class rs_rdfmt_e {
    R32G32B32_FLOAT,
    R32G32B32A32_FLOAT,   
	R32G32_FLOAT,
};
struct rs_input_element_desc {
	const char* semantic_name;
	rs_rdfmt_e format;
};

// Vertex Format inputs for shaders
//BINORMAL[n] 	Binormal 							float4
//BLENDINDICES[n] Blend indices 						uint
//BLENDWEIGHT[n] 	Blend weights 						float
//COLOR[n] 		Diffuse and specular color 			float4
//NORMAL[n] 		Normal vector 						float4
//POSITION[n] 	Vertex position in object space. 	float4
//POSITIONT 		Transformed vertex position. 		float4
//PSIZE[n] 		Point size 							float
//TANGENT[n] 		Tangent 							float4
//TEXCOORD[n] 	Texture coordinates 				float4

//----------------------------------
inline void create_log_font(LOGFONTW &lf) 	{
	// Initialize a LOGFONT structure that describes the font we want to create.
	//LOGFONTW lf = {};
	lf.lfHeight         = 25;    // in logical units
	lf.lfWidth          = 12;    // in logical units
	lf.lfEscapement     = 0;        
	lf.lfOrientation    = 0;     
	lf.lfWeight         = 500;   // boldness, range 0(light) - 1000(bold) //FW_BOLD;
	lf.lfItalic         = false;   
	lf.lfUnderline      = false;    
	lf.lfStrikeOut      = false;    
	lf.lfCharSet        = DEFAULT_CHARSET;
	lf.lfOutPrecision   = 0;	//OUT_DEFAULT_PRECIS;          
	lf.lfClipPrecision  = 0;          
	lf.lfQuality        = 0;	//DEFAULT_QUALITY;     
	lf.lfPitchAndFamily = 0;    //DEFAULT_PITCH | FF_DONTCARE;       
	const wchar_t* font_name = L"Times New Roman";
	wcsncpy(lf.lfFaceName, font_name, LF_FACESIZE-1); // font style
}