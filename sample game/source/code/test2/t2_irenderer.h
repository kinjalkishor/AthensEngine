#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

class irenderer {
public:
	irenderer() {}
	virtual ~irenderer() {}	

	virtual bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { return false; }
	virtual void deinit_r() {}

	virtual void setup() {}
	virtual void cleanup() {}
	virtual void render(float dt) {}
	virtual void swap_buffers() {}
};