#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "base_print.h"

class exp1_irenderer {
public:
	float m_aspect_ratio = 1.0f;

	exp1_irenderer() {}
	virtual ~exp1_irenderer() {}

	virtual bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { return false; }
	virtual void deinit_r() {}

	virtual void setup() {}
	virtual void cleanup() {}
	virtual void render(float dt) {}
	virtual void swap_buffers() {}
};

