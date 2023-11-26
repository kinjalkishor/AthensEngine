#pragma once

#pragma once

#include "t2_rs_irenderer.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <gl\gl.h>
#include <gl\glu.h>
//#include <gl\glaux.h>

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "glu32.lib")


// Nehe: Replacement for gluPerspective
// Replaces gluPerspective. Sets the frustum to perspective mode.
// fovY     - Field of vision in degrees in the y direction
// aspect   - Aspect ratio of the viewport
// zNear    - The near clipping distance
// zFar     - The far clipping distance 
inline void perspective_gl(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar) {
	//Very long (& in theory accurate!) version of Pi. Hopefully an optimizing compiler will replace references to this with the value!	
	const GLdouble pi = 3.1415926535897932384626433832795;

	//Half of the size of the x and y clipping planes.	
	GLdouble fW, fH;

	//Calculate the distance from 0 of the y clipping plane. Basically trig to calculate position of clipper at zNear.
	//Note: tan(double) uses radians but OpenGL works in degrees so we convert degrees to radians by dividing by 360 then multiplying by pi.

	//Formula below corrected by Carsten Jurenz:	
	//fH = tan((fovy/2) / 180.0f*pi ) * zNear;
	//Which can be reduced to:	
	fH = tan(fovy / 360.0f*pi) * zNear;

	//Calculate the distance from 0 of the x clipping plane based on the aspect ratio.	
	fW = fH * aspect;

	// Finally call glFrustum, this is all gluPerspective does anyway! This is why we 
	// calculate half the distance between the clipping planes - glFrustum takes an offset 
	// from zero for each clipping planes distance. (Saves 2 divides)	
	glFrustum(-fW, fW, -fH, fH, zNear, zFar);
}


class rgl2 : public irenderer {
public:
	HDC m_hDC = nullptr;
	HGLRC m_hRC = nullptr;

	bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { 
		set_init_params(hwnd, width, height, " : OpenGL1.0");

		GLuint PixelFormat;
		int color_bits = 32;
		int alpha_bits = 8;
		int depth_bits = 24;

		PIXELFORMATDESCRIPTOR pfd =	 {
			sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
			1,											// Version Number
			PFD_DRAW_TO_WINDOW | 						// Format Must Support Window
			PFD_SUPPORT_OPENGL | 						// Format Must Support OpenGL
			PFD_DOUBLEBUFFER,							// Must Support Double Buffering
			PFD_TYPE_RGBA,								// Request An RGBA Format
			color_bits,									// Select Our Color Depth
			0, 0, 0, 0, 0, 0,							// Color Bits Ignored
			alpha_bits,									// Alpha Buffer
			0,											// Shift Bit Ignored
			0,											// No Accumulation Buffer
			0, 0, 0, 0,									// Accumulation Bits Ignored
			depth_bits,									// 24 Bit Z-Buffer (Depth Buffer)
			0,											// No Stencil Buffer
			0,											// No Auxiliary Buffer
			PFD_MAIN_PLANE,								// Main Drawing Layer
			0,											// Reserved
			0, 0, 0										// Layer Masks Ignored
		};

		m_hDC = GetDC(m_render_window);
		if (!m_hDC) {
			// Cannot get device context of render window.
			eprintfln("Can't Create A GL Device Context.");
			return false;
		}

		// Did Windows Find A Matching Pixel Format?
		// Convert PIXELFORMATDESCRIPTOR into a pixel format number.
		PixelFormat = ChoosePixelFormat(m_hDC, &pfd);
		if (!PixelFormat) {
			// ChoosePixelFormat failed.
			eprintfln("Can't Find A Suitable PixelFormat.");
			return false;
		}

		// Set pixel format number into the DC with SetPixelFormat
		if(!SetPixelFormat(m_hDC,PixelFormat,&pfd)) {
			// SetPixelFormat failed.
			eprintfln("Can't Set The PixelFormat.");
			return false;
		}

		// Are We Able To Get A OpenGL 2.1 Rendering Context?
		m_hRC = wglCreateContext(m_hDC);
		if (!m_hRC) {
			// OpenGL2.1, wglCreateContext failed.
			eprintfln("Can't Create A GL Rendering Context.");
			return false;
		}

		// Make the OpenGL 2.1 context current and active.
		// If there is already a current context, then this function will cause the old context to be replaced with the new. 
		// OpenGL functions after this will refer to state in the new context, not the old one.
		// The current context is thread-specific; each thread can have a different context current, 
		// and it's dangerous to have the same context current in multiple threads. 
		if(!wglMakeCurrent(m_hDC, m_hRC)) {
			// OpenGL 2.1 Activate Rendering Context, wglMakeCurrent failed
			eprintfln("Can't Activate The GL Rendering Context.");
			return false;
		}

		resize_internal();

		setup_post_init();

		return true;
	}

	void setup_post_init() {
		// Enable Smooth Shading
		glShadeModel(GL_SMOOTH);	

		// Enables Depth Testing
		glEnable(GL_DEPTH_TEST);	
		// The Type Of Depth Testing To Do
		glDepthFunc(GL_LEQUAL);								

		// Really Nice Perspective Calculations
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	
	}

	void resize_internal() {
		//if (height==0) { height=1; }

		// Reset The Current Viewport
		glViewport(0, 0, m_client_width, m_client_height);

		// Select The Projection Matrix
		glMatrixMode(GL_PROJECTION);
		// Reset The Projection Matrix
		glLoadIdentity();

		// Calculate The Aspect Ratio Of The Window
		//gluPerspective(mf::rad_to_deg(m_yfov), m_aspect_ratio, m_near_plane, m_far_plane);

		//float yfov = mf::yfov_from_xfovdeg(m_xfov_deg, m_aspect_ratio);
		perspective_gl(mf::rad_to_deg(m_yfov), m_aspect_ratio, m_near_plane, m_far_plane);


		// Select The Modelview Matrix
		glMatrixMode(GL_MODELVIEW);

		// Reset The Modelview Matrix
		glLoadIdentity();
	}

	void deinit_r() {
		if (m_hRC) {
			if (!wglMakeCurrent(nullptr, nullptr)) {
				eprintfln("Release Of DC And RC Failed.");
			}
			if (!wglDeleteContext(m_hRC)) {
				eprintfln("Release Rendering Context Failed.");
			}
			m_hRC = nullptr;
		}

		//HWND hwnd = WindowFromDC(m_hDC);
		if (m_hDC) {
			if (!ReleaseDC(m_render_window, m_hDC)) {
				eprintfln("Release Device Context Failed.");
			}
			m_hDC = nullptr;
		}
	}	

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
		//glClearColor(0.2f, 0.2f, 0.2f, 0.0f); 
		//glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(color_rgba[0], color_rgba[1], color_rgba[2], color_rgba[3]);
		glClear(GL_COLOR_BUFFER_BIT);		
	}
	void clear_depth_stencil(bool clear_depth, bool clear_stencil, float depth, uint stencil) {
		uint clear_flag = 0;
		if (clear_depth) { clear_flag = clear_flag | GL_DEPTH_BUFFER_BIT; glClearDepth(depth); }
		if (clear_stencil) { clear_flag = clear_flag | GL_STENCIL_BUFFER_BIT; glClearStencil(stencil); }    
		glClear(clear_flag);
	}
	void clear(const gm::color4& color_rgba) {
		clear_render_target(color_rgba);
		clear_depth_stencil(true, true, 1.0f, 0);
	}

	void set_rs_culling_gl(rs_cull_mode_e cullmode_back_face) {
		switch (cullmode_back_face) {
			case rs_cull_mode_e::cull_none: glDisable(GL_CULL_FACE); break;
			// Without glClipControl, normal default opengl.
			case rs_cull_mode_e::cull_cw: glEnable(GL_CULL_FACE); glFrontFace(GL_CCW); break;
			case rs_cull_mode_e::cull_ccw: glEnable(GL_CULL_FACE); glFrontFace(GL_CW); break;
			default: glEnable(GL_CULL_FACE); glFrontFace(GL_CW); break;
		}
	}
};


class rgl2_tri : public rgl2 {
public:

	void setup() {
		set_rs_culling_gl(rs_cull_mode_e::cull_ccw);
		glDisable(GL_LIGHTING);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();	   
	}

	void render(float dt) {
		clear(k_clear_color);

		// Reset The Current Modelview Matrix
		glLoadIdentity();

		// Load data to vector.
		sdr::vector<vertex_pct> v;
		sdr::vector<uint> indices_vec;
		fill_triangle_vertex_pct(v, indices_vec);

		// Draw colored triangle.
		glPushMatrix();
		glBegin(GL_TRIANGLES);
			//glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
			//glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
			//glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);

			glColor4f(v[0].r, v[0].g, v[0].b, v[0].a);   glVertex3f(v[0].x, v[0].y, v[0].z);
			glColor4f(v[1].r, v[1].g, v[1].b, v[1].a);   glVertex3f(v[1].x, v[1].y, v[1].z);
			glColor4f(v[2].r, v[2].g, v[2].b, v[2].a);   glVertex3f(v[2].x, v[2].y, v[2].z);
		glEnd();
		glPopMatrix();    

	}
};