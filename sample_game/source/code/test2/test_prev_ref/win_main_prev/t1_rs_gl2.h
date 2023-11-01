#pragma once

#include "t2_rs_irenderer.h"

#include "base_gmath.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <gl\gl.h>
#include <gl\glu.h>
//#include <gl\glaux.h>

//#pragma comment(lib, "OpenGL32.lib")
//#pragma comment(lib, "glu32.lib")

class rgl2 : public irenderer {
public:
	HDC m_hDC = nullptr;
	HGLRC m_hRC = nullptr;

	void deinit_r() {
		if (m_hRC) {
			if (!wglMakeCurrent(nullptr, nullptr)) {
				printfln("Release Of DC And RC Failed.");
			}
			if (!wglDeleteContext(m_hRC)) {
				printfln("Release Rendering Context Failed.");
			}
			m_hRC = nullptr;
		}

		HWND hwnd = WindowFromDC(m_hDC);
		if (m_hDC) {
			if (!ReleaseDC(hwnd, m_hDC)) {
				printfln("Release Device Context Failed.");
			}
			m_hDC = nullptr;
		}
	}

	bool init_r(HINSTANCE hinstance, HWND hwnd, int width, int height, bool fullscreen) {
		//set_viewport(0.0f, 0.0f, width, height);
		if (!hwnd) { eprintfln("Window Handle passed is null."); }
		//m_render_window = hwnd;
		sys_win_title_append(hwnd, " : OpenGL1.0");
		m_aspect_ratio = sdf::get_aspect_ratio(width, height);

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

		m_hDC = GetDC(hwnd);
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

		ReSizeGLScene(width, height);

	}

	void ReSizeGLScene(int width, int height) {
		if (height==0) {
			height=1;
		}

		// Reset The Current Viewport
		glViewport(0, 0, width, height);

		// Select The Projection Matrix
		glMatrixMode(GL_PROJECTION);
		// Reset The Projection Matrix
		glLoadIdentity();

		// Calculate The Aspect Ratio Of The Window
		gluPerspective(45.0f, (float)width/(float)height, 0.1f, 100.0f);

		//float aspect_ratio = sdf::get_aspect_ratio(width, height);
		//float yfov = mf::yfov_from_xfovdeg(m_xfov_deg, m_aspect_ratio);
		//perspective_gl(mf::rad_to_deg(yfov), aspect_ratio, 0.1f, 100.0f);


		// Select The Modelview Matrix
		glMatrixMode(GL_MODELVIEW);

		// Reset The Modelview Matrix
		glLoadIdentity();
	}

	void setup_r() {
		// Enable Smooth Shading
		glShadeModel(GL_SMOOTH);	

		// Enables Depth Testing
		glEnable(GL_DEPTH_TEST);	
		// The Type Of Depth Testing To Do
		glDepthFunc(GL_LEQUAL);								

		// Really Nice Perspective Calculations
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	
	}



	// Default setup, cleanup, render func.
	void setup() {}
	void cleanup() {}	

	void render(float dt) {		
	}

	void swap_buffers() {
		SwapBuffers(m_hDC);
	}

	//----------------------------
	void clear_all(bool clear_color, const gm::color4& color_val, bool clear_depth, float depth_val, bool clear_stencil, int stencil_val) {
		//glClearColor(0.2f, 0.2f, 0.2f, 0.0f); 
		//glClear(GL_COLOR_BUFFER_BIT);
		uint clear_flag = 0;
		if (clear_color) { clear_flag = clear_flag | GL_COLOR_BUFFER_BIT; glClearColor(color_val[0], color_val[1], color_val[2], color_val[3]);}
		if (clear_depth) { clear_flag = clear_flag | GL_DEPTH_BUFFER_BIT; glClearDepth(depth_val); }
		if (clear_stencil) { clear_flag = clear_flag | GL_STENCIL_BUFFER_BIT; glClearStencil(stencil_val); }    
		glClear(clear_flag);
	}

	void clear(const gm::color4& color_rgba) {
		clear_all(true, color_rgba, true, 1.0f, true, 0);
	}

	void enable_lighting(bool enable) {
		if (enable)		{ glEnable(GL_LIGHTING); }
		else			{ glDisable(GL_LIGHTING); }
	}

};


class rgl2_color_polygon : public rgl2 {
public:
	void setup() {
		setup_r();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();	   
	}

	void render(float dt) {
		clear(gm::color4(0.2, 0.2, 0.2, 1.0));

		// Reset The Current Modelview Matrix
		glLoadIdentity();

		#if 0
			glPushMatrix();
			glBegin(GL_TRIANGLES);
				glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
				glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
				glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);
			glEnd();
			glPopMatrix();    
		#endif

		#if 1
			// draw white polygon (rectangle) with corners at
			// (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0) 
			//glColor3f (1.0, 1.0, 1.0);
		    glColor3f (1.0, 0.0, 1.0);

			//GLfloat color_array[] = {1.0, 0.0, 0.0};
			//glColor3fv(color_array);

			glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
			glBegin(GL_POLYGON);
				glVertex3f (0.25, 0.25, 0.0);
				glVertex3f (0.75, 0.25, 0.0);
				glVertex3f (0.75, 0.75, 0.0);
				glVertex3f (0.25, 0.75, 0.0);
			glEnd();
			// don't wait!  
			// start processing buffered OpenGL routines 
			glFlush();
	   #endif
	}
};