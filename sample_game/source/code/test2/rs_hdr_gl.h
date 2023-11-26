#pragma once

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

//#include <wglext.h>
//----------