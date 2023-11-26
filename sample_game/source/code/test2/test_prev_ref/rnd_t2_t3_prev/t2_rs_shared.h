#pragma once

#define RS_MODEL_PATH(model_name)			"E:/nex/AthensEngine/nw_mdtxt/" model_name
#define RS_SHADER_PATH(shader_name)			"../../../source/code/test2/a_rs_shaders/" shader_name

#define RS_MEDIA_PATH(sub_path)				"E:/nex/aw_media/" sub_path
#define TUT_MEDIA_PATH(sub_path)			"E:/nex/aw_media/tut/d3d_fl/" sub_path

#if 0
class rs_gl2 {
public:
	rs_gl2() {}
	virtual ~rs_gl2() {}	

	virtual bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) { return false; }
	virtual void deinit_r() {}

	virtual void setup() {}
	virtual void cleanup() {}
	virtual void render(float dt) {}
	virtual void swap_buffers() {}
};

//---------------------
class q2_irenderer {
public:
	q2_irenderer() {}
	virtual ~q2_irenderer() {}

	virtual bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) { return false; }
	virtual void deinit_r() {}

	virtual void setup() {}
	virtual void cleanup() {}
	virtual void render(float dt) {}
	virtual void swap_buffers() {}
};

class rq2_gl2 : public q2_irenderer {
public:

	bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) { return false; }
	void deinit_r() {}

	void setup() {}
	void cleanup() {}
	void render(float dt) {}
	void swap_buffers() {}	
};
#endif