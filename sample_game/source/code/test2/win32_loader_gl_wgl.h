#pragma once

// core
//#include <glcorearb.h>

// compat
//#define WIN32_LEAN_AND_MEAN
//#include <Windows.h>
//#include <gl/gl.h>
//#include <glext.h>


// These typedefs are needed from OpenGL headers.
// Declaring here avoids the need to include OpenGL headers
typedef unsigned int GLenum;
typedef float GLfloat;
typedef int GLint;
typedef int GLsizei;
typedef unsigned int GLbitfield;
typedef unsigned int GLuint;
typedef unsigned char GLboolean;
typedef unsigned short int GLushort;

//----------
//#include <gl/gl.h>
//#include <glext.h>
// Do not #include both <GL/glcorearb.h> and either of <GL/gl.h> or <GL/glext.h> in the same source file.
//#include <glcorearb.h>
// include glcorearb.h or gl/gl.h before wglext.h
//#include <wglext.h>
//---
#define USE_GLAD_LIB 1

#if !USE_GLAD_LIB
	// Use gl_loader_core.h, compat enabled only for testing gl2 in other file
	// as only one cpp can be active at a time with same function pointer names.
	//#include "gl_loader/gl_loader_core.h"
	#include "gl_loader/gl_loader_compat.h"
#endif

#if USE_GLAD_LIB
	#include "glad/glad_compat/include/glad/gl.h"
#endif

#include <wglext.h>
//----------

typedef BOOL  (WINAPI * PFN_wglCopyContext)(HGLRC, HGLRC, UINT);
typedef HGLRC (WINAPI * PFN_wglCreateContext)(HDC);
typedef HGLRC (WINAPI * PFN_wglCreateLayerContext)(HDC, int);
typedef BOOL  (WINAPI * PFN_wglDeleteContext)(HGLRC);
typedef HGLRC (WINAPI * PFN_wglGetCurrentContext)(VOID);
typedef HDC   (WINAPI * PFN_wglGetCurrentDC)(VOID);
typedef PROC  (WINAPI * PFN_wglGetProcAddress)(LPCSTR name);
typedef BOOL  (WINAPI * PFN_wglMakeCurrent)(HDC, HGLRC);
typedef BOOL  (WINAPI * PFN_wglShareLists)(HGLRC, HGLRC);
typedef BOOL  (WINAPI * PFN_wglUseFontBitmapsA)(HDC, DWORD, DWORD, DWORD);
typedef BOOL  (WINAPI * PFN_wglUseFontBitmapsW)(HDC, DWORD, DWORD, DWORD);


class wglfn_lib {
public:
    HINSTANCE hinstance_dll = nullptr;

	PFN_wglCopyContext fwglCopyContext = nullptr;
	PFN_wglCreateContext fwglCreateContext = nullptr;
	PFN_wglCreateLayerContext fwglCreateLayerContext = nullptr;
	PFN_wglDeleteContext fwglDeleteContext = nullptr;
	PFN_wglGetCurrentContext fwglGetCurrentContext = nullptr;
	PFN_wglGetCurrentDC fwglGetCurrentDC = nullptr;
	PFN_wglGetProcAddress fwglGetProcAddress = nullptr;
	PFN_wglMakeCurrent fwglMakeCurrent = nullptr;
	PFN_wglShareLists fwglShareLists = nullptr;
	PFN_wglUseFontBitmapsA fwglUseFontBitmapsA = nullptr;
	PFN_wglUseFontBitmapsW fwglUseFontBitmapsW = nullptr;


	bool init();
	void deinit();	
};

extern wglfn_lib wglfn;

//typedef void (*GLADapiproc)(void);
//typedef GLADapiproc (*GLADloadfunc)(const char *name);
//typedef void* (GLAD_API_PTR *GLADglprocaddrfunc)(const char*);
//struct _glad_gl_userptr {
//    void *handle;
//    GLADglprocaddrfunc gl_get_proc_address_ptr;
//};
//typedef GLADapiproc (*GLADuserptrloadfunc)(void *userptr, const char *name);

void* get_gl_func_address_name(const char* name);


//------------------------------------
// wgl extension function pointer.
// HGLRC WINAPI wglCreateContextAttribsARB (HDC hDC, HGLRC hShareContext, const int *attribList);
extern PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;
// const char *WINAPI wglGetExtensionsStringARB (HDC hdc);
extern PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB;
// BOOL WINAPI wglGetPixelFormatAttribivARB (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
extern PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribivARB;
// BOOL WINAPI wglChoosePixelFormatARB (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
extern PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;
// const char *WINAPI wglGetExtensionsStringEXT (void);
extern PFNWGLGETEXTENSIONSSTRINGEXTPROC wglGetExtensionsStringEXT;
// BOOL WINAPI wglSwapIntervalEXT (int interval);
extern PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;

void wglext_init();