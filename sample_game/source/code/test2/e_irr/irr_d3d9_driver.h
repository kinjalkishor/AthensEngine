#pragma once

#include "../base_types.h"

#include "../t2_rs_d3d9_hdr.h"

#include "irr_driver.h"

class irr_rd3d9_driver : public irr_idriver {
public:
	bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) { return false; }
	void deinit_r() {}

	void setup() {}
	void cleanup() {}
	void render(float dt) {}
	void swap_buffers() {}
};







