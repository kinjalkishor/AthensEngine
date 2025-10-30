#pragma once

#include "t2_irenderer.h"

class rgl4 : public irenderer {
public:
    bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { return true; }
    void deinit_r() { }

    void setup() { }
    void cleanup() { }
    void render(float dt) { }
    void swap_buffers() { }
};
