
#include "win32_loader_gl_wgl.h"

#include "base_shared.h"

wglfn_lib wglfn;

typedef void (*PFN_apiproc)(void);
typedef PFN_apiproc (*PFN_loadfunc_gl)(const char *name);

#define CHECK_FUNC_PTR_ERROR(name)	\
if (!name) { printfln(#name " not loaded."); } 


bool wglfn_lib::init() {
	//if (!hinstance_dll) { printfln("wglfn_lib hinstance_dll is NULL."); }
	//ptr = rcast<PFNWGLCHOOSEPIXELFORMATARBPROC>()

	if (hinstance_dll) {
		printfln("wglfn_lib is already initialised");
		return true;
	}

	// Load opengl32.dll
	hinstance_dll = LoadLibraryW(L"opengl32.dll");
	if (!hinstance_dll) {
		printfln("Failed to load opengl32.dll");
		return false;
	}

	// Set wgl function pointers.
	fwglCopyContext = (PFN_wglCopyContext)GetProcAddress(hinstance_dll, "wglCopyContext");
	CHECK_FUNC_PTR_ERROR(fwglCopyContext)
	fwglCreateContext = (PFN_wglCreateContext)GetProcAddress(hinstance_dll, "wglCreateContext");
	CHECK_FUNC_PTR_ERROR(fwglCreateContext)
	fwglCreateLayerContext	= (PFN_wglCreateLayerContext)GetProcAddress(hinstance_dll, "wglCreateLayerContext");
	CHECK_FUNC_PTR_ERROR(fwglCreateLayerContext)
	fwglDeleteContext = (PFN_wglDeleteContext)GetProcAddress(hinstance_dll, "wglDeleteContext");
	CHECK_FUNC_PTR_ERROR(fwglDeleteContext)
	fwglGetCurrentContext = (PFN_wglGetCurrentContext)GetProcAddress(hinstance_dll, "wglGetCurrentContext");
	CHECK_FUNC_PTR_ERROR(fwglGetCurrentContext)
	fwglGetCurrentDC = (PFN_wglGetCurrentDC)GetProcAddress(hinstance_dll, "wglGetCurrentDC");
	CHECK_FUNC_PTR_ERROR(fwglGetCurrentDC)
	fwglGetProcAddress = (PFN_wglGetProcAddress)GetProcAddress(hinstance_dll, "wglGetProcAddress");
	CHECK_FUNC_PTR_ERROR(fwglGetProcAddress)
	fwglMakeCurrent = (PFN_wglMakeCurrent)GetProcAddress(hinstance_dll, "wglMakeCurrent");
	CHECK_FUNC_PTR_ERROR(fwglMakeCurrent)
	fwglShareLists = (PFN_wglShareLists)GetProcAddress(hinstance_dll, "wglShareLists");
	CHECK_FUNC_PTR_ERROR(fwglShareLists)
	fwglUseFontBitmapsA = (PFN_wglUseFontBitmapsA)GetProcAddress(hinstance_dll, "wglUseFontBitmapsA");
	CHECK_FUNC_PTR_ERROR(fwglUseFontBitmapsA)
	fwglUseFontBitmapsW = (PFN_wglUseFontBitmapsW)GetProcAddress(hinstance_dll, "wglUseFontBitmapsW");
	CHECK_FUNC_PTR_ERROR(fwglUseFontBitmapsW)

	return true;
}

void wglfn_lib::deinit() {
	if (hinstance_dll) {
		FreeLibrary(hinstance_dll);
	}
}

//-----------------------
void* get_gl_func_address_name(const char* name) {
	//void* p = (void*)wglGetProcAddress(name);
	void* p = (void*)wglfn.fwglGetProcAddress(name);
	// wglGetProcAddress returns NULL on failure but some implementations will return other values. 
	// 1, 2, and 3 are used, as well as -1. 
	if (p == 0 || (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) || (p == (void*)-1)) {
		//HMODULE module = LoadLibraryA("opengl32.dll");
		//p = (void*)GetProcAddress(module, name);
		//p = (void*)GetProcAddress(rcast<HMODULE>(module), name);
		p = (void*)GetProcAddress(wglfn.hinstance_dll, name);
	}
	return p;
}



//------------------------------------
// wgl extension function pointer.

#define LOAD_WGLEXT_FUNCTION(name, funcptr_name)                        \
name = (funcptr_name)get_gl_func_address_name(#name);					\
if (!name) { printfln(#name " not loaded."); } 


PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;
PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB = nullptr;
PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribivARB = nullptr;
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
PFNWGLGETEXTENSIONSSTRINGEXTPROC wglGetExtensionsStringEXT = nullptr;
PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = nullptr;


void wglext_init() {
	LOAD_WGLEXT_FUNCTION(wglCreateContextAttribsARB, PFNWGLCREATECONTEXTATTRIBSARBPROC)
	LOAD_WGLEXT_FUNCTION(wglGetExtensionsStringARB, PFNWGLGETEXTENSIONSSTRINGARBPROC)
	LOAD_WGLEXT_FUNCTION(wglGetPixelFormatAttribivARB, PFNWGLGETPIXELFORMATATTRIBIVARBPROC)
	LOAD_WGLEXT_FUNCTION(wglChoosePixelFormatARB, PFNWGLCHOOSEPIXELFORMATARBPROC)
	LOAD_WGLEXT_FUNCTION(wglGetExtensionsStringEXT, PFNWGLGETEXTENSIONSSTRINGEXTPROC)
	LOAD_WGLEXT_FUNCTION(wglSwapIntervalEXT, PFNWGLSWAPINTERVALEXTPROC)
}


