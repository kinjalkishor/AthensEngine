#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "../base_def.h"
#include "../base_win_util.h"
#include "../base_gmath.h"

#include "../rs_shared.h"

#include <vector>

inline const gm::color4 k_clear_color = gm::color4(0.2, 0.2, 0.2, 1.0);

class irenderer {
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

	irenderer() {}
	virtual ~irenderer() {}	

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


//============================================
