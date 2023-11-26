#pragma once

#include "t3_rs_irenderer.h"


class rd3d9b : public irenderer {
public:
	bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) { return true; }
	void deinit_r() {}

	void setup() {}
	void cleanup() {}
	void render(float dt) {}
	void swap_buffers() {}
};
