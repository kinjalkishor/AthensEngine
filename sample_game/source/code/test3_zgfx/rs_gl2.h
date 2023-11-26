#pragma once

#include "rs_irenderer.h"

class wm_rgl2 : public wm_irenderer {
public:
	HDC m_hDC = nullptr;
	HGLRC m_hRC = nullptr;

	bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { 
		set_init_params(hwnd, width, height, " : OpenGL2.1");

		return true;
	}

	void deinit_r() {}

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
		////float clear_color[4] = {0.0f, 1.0f, 1.0f, 1.0f};
		////m_device->ClearRenderTargetView(m_render_target_view, clear_color);
		//m_device->ClearRenderTargetView(m_render_target_view, color_rgba.data());
	}
	void clear_depth_stencil(bool clear_depth, bool clear_stencil, float depth, uint stencil) {
		//uint clear_flag = 0;
		//if (clear_depth) { clear_flag |= D3D10_CLEAR_DEPTH; }
		//if (clear_stencil) { clear_flag |= D3D10_CLEAR_STENCIL; }    
		////m_device->ClearDepthStencilView(m_depth_stencil_view, D3D10_CLEAR_DEPTH|D3D10_CLEAR_STENCIL, 1.0f, 0);
		//m_device->ClearDepthStencilView(m_depth_stencil_view, clear_flag, depth, stencil);
	}
	void clear(const gm::color4& color_rgba) {
		clear_render_target(color_rgba);
		clear_depth_stencil(true, true, 1.0f, 0);
	}
};


class wm_rgl2_tri : public wm_rgl2 {
public:
};