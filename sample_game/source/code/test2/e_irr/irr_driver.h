#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

class irr_idriver {
public:
	irr_idriver() {}
	virtual ~irr_idriver() {}	

	virtual bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) { return false; }
	virtual void deinit_r() {}

	virtual void setup() {}
	virtual void cleanup() {}
	virtual void render(float dt) {}
	virtual void swap_buffers() {}
};
