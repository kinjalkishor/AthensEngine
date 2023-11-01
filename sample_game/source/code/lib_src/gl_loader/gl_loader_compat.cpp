#include "gl_loader_compat.h"

#include <stdio.h>
#if defined GL_LOADER_COMPAT_PRINT_ERRORS
#define print_msg(format, ...)		printf(format "\n", __VA_ARGS__)
#else
#define print_msg
#endif


// GL_VERSION_1_0
PFNGLACCUMPROC glfn_glAccum = nullptr;
PFNGLALPHAFUNCPROC glfn_glAlphaFunc = nullptr;
PFNGLARETEXTURESRESIDENTPROC glfn_glAreTexturesResident = nullptr;
PFNGLARRAYELEMENTPROC glfn_glArrayElement = nullptr;
PFNGLBEGINPROC glfn_glBegin = nullptr;
PFNGLBINDTEXTUREPROC glfn_glBindTexture = nullptr;
PFNGLBITMAPPROC glfn_glBitmap = nullptr;
PFNGLBLENDFUNCPROC glfn_glBlendFunc = nullptr;
PFNGLCALLLISTPROC glfn_glCallList = nullptr;
PFNGLCALLLISTSPROC glfn_glCallLists = nullptr;
PFNGLCLEARPROC glfn_glClear = nullptr;
PFNGLCLEARACCUMPROC glfn_glClearAccum = nullptr;
PFNGLCLEARCOLORPROC glfn_glClearColor = nullptr;
PFNGLCLEARDEPTHPROC glfn_glClearDepth = nullptr;
PFNGLCLEARINDEXPROC glfn_glClearIndex = nullptr;
PFNGLCLEARSTENCILPROC glfn_glClearStencil = nullptr;
PFNGLCLIPPLANEPROC glfn_glClipPlane = nullptr;
PFNGLCOLOR3BPROC glfn_glColor3b = nullptr;
PFNGLCOLOR3BVPROC glfn_glColor3bv = nullptr;
PFNGLCOLOR3DPROC glfn_glColor3d = nullptr;
PFNGLCOLOR3DVPROC glfn_glColor3dv = nullptr;
PFNGLCOLOR3FPROC glfn_glColor3f = nullptr;
PFNGLCOLOR3FVPROC glfn_glColor3fv = nullptr;
PFNGLCOLOR3IPROC glfn_glColor3i = nullptr;
PFNGLCOLOR3IVPROC glfn_glColor3iv = nullptr;
PFNGLCOLOR3SPROC glfn_glColor3s = nullptr;
PFNGLCOLOR3SVPROC glfn_glColor3sv = nullptr;
PFNGLCOLOR3UBPROC glfn_glColor3ub = nullptr;
PFNGLCOLOR3UBVPROC glfn_glColor3ubv = nullptr;
PFNGLCOLOR3UIPROC glfn_glColor3ui = nullptr;
PFNGLCOLOR3UIVPROC glfn_glColor3uiv = nullptr;
PFNGLCOLOR3USPROC glfn_glColor3us = nullptr;
PFNGLCOLOR3USVPROC glfn_glColor3usv = nullptr;
PFNGLCOLOR4BPROC glfn_glColor4b = nullptr;
PFNGLCOLOR4BVPROC glfn_glColor4bv = nullptr;
PFNGLCOLOR4DPROC glfn_glColor4d = nullptr;
PFNGLCOLOR4DVPROC glfn_glColor4dv = nullptr;
PFNGLCOLOR4FPROC glfn_glColor4f = nullptr;
PFNGLCOLOR4FVPROC glfn_glColor4fv = nullptr;
PFNGLCOLOR4IPROC glfn_glColor4i = nullptr;
PFNGLCOLOR4IVPROC glfn_glColor4iv = nullptr;
PFNGLCOLOR4SPROC glfn_glColor4s = nullptr;
PFNGLCOLOR4SVPROC glfn_glColor4sv = nullptr;
PFNGLCOLOR4UBPROC glfn_glColor4ub = nullptr;
PFNGLCOLOR4UBVPROC glfn_glColor4ubv = nullptr;
PFNGLCOLOR4UIPROC glfn_glColor4ui = nullptr;
PFNGLCOLOR4UIVPROC glfn_glColor4uiv = nullptr;
PFNGLCOLOR4USPROC glfn_glColor4us = nullptr;
PFNGLCOLOR4USVPROC glfn_glColor4usv = nullptr;
PFNGLCOLORMASKPROC glfn_glColorMask = nullptr;
PFNGLCOLORMATERIALPROC glfn_glColorMaterial = nullptr;
PFNGLCOLORPOINTERPROC glfn_glColorPointer = nullptr;
PFNGLCOPYPIXELSPROC glfn_glCopyPixels = nullptr;
PFNGLCOPYTEXIMAGE1DPROC glfn_glCopyTexImage1D = nullptr;
PFNGLCOPYTEXIMAGE2DPROC glfn_glCopyTexImage2D = nullptr;
PFNGLCOPYTEXSUBIMAGE1DPROC glfn_glCopyTexSubImage1D = nullptr;
PFNGLCOPYTEXSUBIMAGE2DPROC glfn_glCopyTexSubImage2D = nullptr;
PFNGLCULLFACEPROC glfn_glCullFace = nullptr;
PFNGLDELETELISTSPROC glfn_glDeleteLists = nullptr;
PFNGLDELETETEXTURESPROC glfn_glDeleteTextures = nullptr;
PFNGLDEPTHFUNCPROC glfn_glDepthFunc = nullptr;
PFNGLDEPTHMASKPROC glfn_glDepthMask = nullptr;
PFNGLDEPTHRANGEPROC glfn_glDepthRange = nullptr;
PFNGLDISABLEPROC glfn_glDisable = nullptr;
PFNGLDISABLECLIENTSTATEPROC glfn_glDisableClientState = nullptr;
PFNGLDRAWARRAYSPROC glfn_glDrawArrays = nullptr;
PFNGLDRAWBUFFERPROC glfn_glDrawBuffer = nullptr;
PFNGLDRAWELEMENTSPROC glfn_glDrawElements = nullptr;
PFNGLDRAWPIXELSPROC glfn_glDrawPixels = nullptr;
PFNGLEDGEFLAGPROC glfn_glEdgeFlag = nullptr;
PFNGLEDGEFLAGPOINTERPROC glfn_glEdgeFlagPointer = nullptr;
PFNGLEDGEFLAGVPROC glfn_glEdgeFlagv = nullptr;
PFNGLENABLEPROC glfn_glEnable = nullptr;
PFNGLENABLECLIENTSTATEPROC glfn_glEnableClientState = nullptr;
PFNGLENDPROC glfn_glEnd = nullptr;
PFNGLENDLISTPROC glfn_glEndList = nullptr;
PFNGLEVALCOORD1DPROC glfn_glEvalCoord1d = nullptr;
PFNGLEVALCOORD1DVPROC glfn_glEvalCoord1dv = nullptr;
PFNGLEVALCOORD1FPROC glfn_glEvalCoord1f = nullptr;
PFNGLEVALCOORD1FVPROC glfn_glEvalCoord1fv = nullptr;
PFNGLEVALCOORD2DPROC glfn_glEvalCoord2d = nullptr;
PFNGLEVALCOORD2DVPROC glfn_glEvalCoord2dv = nullptr;
PFNGLEVALCOORD2FPROC glfn_glEvalCoord2f = nullptr;
PFNGLEVALCOORD2FVPROC glfn_glEvalCoord2fv = nullptr;
PFNGLEVALMESH1PROC glfn_glEvalMesh1 = nullptr;
PFNGLEVALMESH2PROC glfn_glEvalMesh2 = nullptr;
PFNGLEVALPOINT1PROC glfn_glEvalPoint1 = nullptr;
PFNGLEVALPOINT2PROC glfn_glEvalPoint2 = nullptr;
PFNGLFEEDBACKBUFFERPROC glfn_glFeedbackBuffer = nullptr;
PFNGLFINISHPROC glfn_glFinish = nullptr;
PFNGLFLUSHPROC glfn_glFlush = nullptr;
PFNGLFOGFPROC glfn_glFogf = nullptr;
PFNGLFOGFVPROC glfn_glFogfv = nullptr;
PFNGLFOGIPROC glfn_glFogi = nullptr;
PFNGLFOGIVPROC glfn_glFogiv = nullptr;
PFNGLFRONTFACEPROC glfn_glFrontFace = nullptr;
PFNGLFRUSTUMPROC glfn_glFrustum = nullptr;
PFNGLGENLISTSPROC glfn_glGenLists = nullptr;
PFNGLGENTEXTURESPROC glfn_glGenTextures = nullptr;
PFNGLGETBOOLEANVPROC glfn_glGetBooleanv = nullptr;
PFNGLGETCLIPPLANEPROC glfn_glGetClipPlane = nullptr;
PFNGLGETDOUBLEVPROC glfn_glGetDoublev = nullptr;
PFNGLGETERRORPROC glfn_glGetError = nullptr;
PFNGLGETFLOATVPROC glfn_glGetFloatv = nullptr;
PFNGLGETINTEGERVPROC glfn_glGetIntegerv = nullptr;
PFNGLGETLIGHTFVPROC glfn_glGetLightfv = nullptr;
PFNGLGETLIGHTIVPROC glfn_glGetLightiv = nullptr;
PFNGLGETMAPDVPROC glfn_glGetMapdv = nullptr;
PFNGLGETMAPFVPROC glfn_glGetMapfv = nullptr;
PFNGLGETMAPIVPROC glfn_glGetMapiv = nullptr;
PFNGLGETMATERIALFVPROC glfn_glGetMaterialfv = nullptr;
PFNGLGETMATERIALIVPROC glfn_glGetMaterialiv = nullptr;
PFNGLGETPIXELMAPFVPROC glfn_glGetPixelMapfv = nullptr;
PFNGLGETPIXELMAPUIVPROC glfn_glGetPixelMapuiv = nullptr;
PFNGLGETPIXELMAPUSVPROC glfn_glGetPixelMapusv = nullptr;
PFNGLGETPOINTERVPROC glfn_glGetPointerv = nullptr;
PFNGLGETPOLYGONSTIPPLEPROC glfn_glGetPolygonStipple = nullptr;
PFNGLGETSTRINGPROC glfn_glGetString = nullptr;
PFNGLGETTEXENVFVPROC glfn_glGetTexEnvfv = nullptr;
PFNGLGETTEXENVIVPROC glfn_glGetTexEnviv = nullptr;
PFNGLGETTEXGENDVPROC glfn_glGetTexGendv = nullptr;
PFNGLGETTEXGENFVPROC glfn_glGetTexGenfv = nullptr;
PFNGLGETTEXGENIVPROC glfn_glGetTexGeniv = nullptr;
PFNGLGETTEXIMAGEPROC glfn_glGetTexImage = nullptr;
PFNGLGETTEXLEVELPARAMETERFVPROC glfn_glGetTexLevelParameterfv = nullptr;
PFNGLGETTEXLEVELPARAMETERIVPROC glfn_glGetTexLevelParameteriv = nullptr;
PFNGLGETTEXPARAMETERFVPROC glfn_glGetTexParameterfv = nullptr;
PFNGLGETTEXPARAMETERIVPROC glfn_glGetTexParameteriv = nullptr;
PFNGLHINTPROC glfn_glHint = nullptr;
PFNGLINDEXMASKPROC glfn_glIndexMask = nullptr;
PFNGLINDEXPOINTERPROC glfn_glIndexPointer = nullptr;
PFNGLINDEXDPROC glfn_glIndexd = nullptr;
PFNGLINDEXDVPROC glfn_glIndexdv = nullptr;
PFNGLINDEXFPROC glfn_glIndexf = nullptr;
PFNGLINDEXFVPROC glfn_glIndexfv = nullptr;
PFNGLINDEXIPROC glfn_glIndexi = nullptr;
PFNGLINDEXIVPROC glfn_glIndexiv = nullptr;
PFNGLINDEXSPROC glfn_glIndexs = nullptr;
PFNGLINDEXSVPROC glfn_glIndexsv = nullptr;
PFNGLINDEXUBPROC glfn_glIndexub = nullptr;
PFNGLINDEXUBVPROC glfn_glIndexubv = nullptr;
PFNGLINITNAMESPROC glfn_glInitNames = nullptr;
PFNGLINTERLEAVEDARRAYSPROC glfn_glInterleavedArrays = nullptr;
PFNGLISENABLEDPROC glfn_glIsEnabled = nullptr;
PFNGLISLISTPROC glfn_glIsList = nullptr;
PFNGLISTEXTUREPROC glfn_glIsTexture = nullptr;
PFNGLLIGHTMODELFPROC glfn_glLightModelf = nullptr;
PFNGLLIGHTMODELFVPROC glfn_glLightModelfv = nullptr;
PFNGLLIGHTMODELIPROC glfn_glLightModeli = nullptr;
PFNGLLIGHTMODELIVPROC glfn_glLightModeliv = nullptr;
PFNGLLIGHTFPROC glfn_glLightf = nullptr;
PFNGLLIGHTFVPROC glfn_glLightfv = nullptr;
PFNGLLIGHTIPROC glfn_glLighti = nullptr;
PFNGLLIGHTIVPROC glfn_glLightiv = nullptr;
PFNGLLINESTIPPLEPROC glfn_glLineStipple = nullptr;
PFNGLLINEWIDTHPROC glfn_glLineWidth = nullptr;
PFNGLLISTBASEPROC glfn_glListBase = nullptr;
PFNGLLOADIDENTITYPROC glfn_glLoadIdentity = nullptr;
PFNGLLOADMATRIXDPROC glfn_glLoadMatrixd = nullptr;
PFNGLLOADMATRIXFPROC glfn_glLoadMatrixf = nullptr;
PFNGLLOADNAMEPROC glfn_glLoadName = nullptr;
PFNGLLOGICOPPROC glfn_glLogicOp = nullptr;
PFNGLMAP1DPROC glfn_glMap1d = nullptr;
PFNGLMAP1FPROC glfn_glMap1f = nullptr;
PFNGLMAP2DPROC glfn_glMap2d = nullptr;
PFNGLMAP2FPROC glfn_glMap2f = nullptr;
PFNGLMAPGRID1DPROC glfn_glMapGrid1d = nullptr;
PFNGLMAPGRID1FPROC glfn_glMapGrid1f = nullptr;
PFNGLMAPGRID2DPROC glfn_glMapGrid2d = nullptr;
PFNGLMAPGRID2FPROC glfn_glMapGrid2f = nullptr;
PFNGLMATERIALFPROC glfn_glMaterialf = nullptr;
PFNGLMATERIALFVPROC glfn_glMaterialfv = nullptr;
PFNGLMATERIALIPROC glfn_glMateriali = nullptr;
PFNGLMATERIALIVPROC glfn_glMaterialiv = nullptr;
PFNGLMATRIXMODEPROC glfn_glMatrixMode = nullptr;
PFNGLMULTMATRIXDPROC glfn_glMultMatrixd = nullptr;
PFNGLMULTMATRIXFPROC glfn_glMultMatrixf = nullptr;
PFNGLNEWLISTPROC glfn_glNewList = nullptr;
PFNGLNORMAL3BPROC glfn_glNormal3b = nullptr;
PFNGLNORMAL3BVPROC glfn_glNormal3bv = nullptr;
PFNGLNORMAL3DPROC glfn_glNormal3d = nullptr;
PFNGLNORMAL3DVPROC glfn_glNormal3dv = nullptr;
PFNGLNORMAL3FPROC glfn_glNormal3f = nullptr;
PFNGLNORMAL3FVPROC glfn_glNormal3fv = nullptr;
PFNGLNORMAL3IPROC glfn_glNormal3i = nullptr;
PFNGLNORMAL3IVPROC glfn_glNormal3iv = nullptr;
PFNGLNORMAL3SPROC glfn_glNormal3s = nullptr;
PFNGLNORMAL3SVPROC glfn_glNormal3sv = nullptr;
PFNGLNORMALPOINTERPROC glfn_glNormalPointer = nullptr;
PFNGLORTHOPROC glfn_glOrtho = nullptr;
PFNGLPASSTHROUGHPROC glfn_glPassThrough = nullptr;
PFNGLPIXELMAPFVPROC glfn_glPixelMapfv = nullptr;
PFNGLPIXELMAPUIVPROC glfn_glPixelMapuiv = nullptr;
PFNGLPIXELMAPUSVPROC glfn_glPixelMapusv = nullptr;
PFNGLPIXELSTOREFPROC glfn_glPixelStoref = nullptr;
PFNGLPIXELSTOREIPROC glfn_glPixelStorei = nullptr;
PFNGLPIXELTRANSFERFPROC glfn_glPixelTransferf = nullptr;
PFNGLPIXELTRANSFERIPROC glfn_glPixelTransferi = nullptr;
PFNGLPIXELZOOMPROC glfn_glPixelZoom = nullptr;
PFNGLPOINTSIZEPROC glfn_glPointSize = nullptr;
PFNGLPOLYGONMODEPROC glfn_glPolygonMode = nullptr;
PFNGLPOLYGONOFFSETPROC glfn_glPolygonOffset = nullptr;
PFNGLPOLYGONSTIPPLEPROC glfn_glPolygonStipple = nullptr;
PFNGLPOPATTRIBPROC glfn_glPopAttrib = nullptr;
PFNGLPOPCLIENTATTRIBPROC glfn_glPopClientAttrib = nullptr;
PFNGLPOPMATRIXPROC glfn_glPopMatrix = nullptr;
PFNGLPOPNAMEPROC glfn_glPopName = nullptr;
PFNGLPRIORITIZETEXTURESPROC glfn_glPrioritizeTextures = nullptr;
PFNGLPUSHATTRIBPROC glfn_glPushAttrib = nullptr;
PFNGLPUSHCLIENTATTRIBPROC glfn_glPushClientAttrib = nullptr;
PFNGLPUSHMATRIXPROC glfn_glPushMatrix = nullptr;
PFNGLPUSHNAMEPROC glfn_glPushName = nullptr;
PFNGLRASTERPOS2DPROC glfn_glRasterPos2d = nullptr;
PFNGLRASTERPOS2DVPROC glfn_glRasterPos2dv = nullptr;
PFNGLRASTERPOS2FPROC glfn_glRasterPos2f = nullptr;
PFNGLRASTERPOS2FVPROC glfn_glRasterPos2fv = nullptr;
PFNGLRASTERPOS2IPROC glfn_glRasterPos2i = nullptr;
PFNGLRASTERPOS2IVPROC glfn_glRasterPos2iv = nullptr;
PFNGLRASTERPOS2SPROC glfn_glRasterPos2s = nullptr;
PFNGLRASTERPOS2SVPROC glfn_glRasterPos2sv = nullptr;
PFNGLRASTERPOS3DPROC glfn_glRasterPos3d = nullptr;
PFNGLRASTERPOS3DVPROC glfn_glRasterPos3dv = nullptr;
PFNGLRASTERPOS3FPROC glfn_glRasterPos3f = nullptr;
PFNGLRASTERPOS3FVPROC glfn_glRasterPos3fv = nullptr;
PFNGLRASTERPOS3IPROC glfn_glRasterPos3i = nullptr;
PFNGLRASTERPOS3IVPROC glfn_glRasterPos3iv = nullptr;
PFNGLRASTERPOS3SPROC glfn_glRasterPos3s = nullptr;
PFNGLRASTERPOS3SVPROC glfn_glRasterPos3sv = nullptr;
PFNGLRASTERPOS4DPROC glfn_glRasterPos4d = nullptr;
PFNGLRASTERPOS4DVPROC glfn_glRasterPos4dv = nullptr;
PFNGLRASTERPOS4FPROC glfn_glRasterPos4f = nullptr;
PFNGLRASTERPOS4FVPROC glfn_glRasterPos4fv = nullptr;
PFNGLRASTERPOS4IPROC glfn_glRasterPos4i = nullptr;
PFNGLRASTERPOS4IVPROC glfn_glRasterPos4iv = nullptr;
PFNGLRASTERPOS4SPROC glfn_glRasterPos4s = nullptr;
PFNGLRASTERPOS4SVPROC glfn_glRasterPos4sv = nullptr;
PFNGLREADBUFFERPROC glfn_glReadBuffer = nullptr;
PFNGLREADPIXELSPROC glfn_glReadPixels = nullptr;
PFNGLRECTDPROC glfn_glRectd = nullptr;
PFNGLRECTDVPROC glfn_glRectdv = nullptr;
PFNGLRECTFPROC glfn_glRectf = nullptr;
PFNGLRECTFVPROC glfn_glRectfv = nullptr;
PFNGLRECTIPROC glfn_glRecti = nullptr;
PFNGLRECTIVPROC glfn_glRectiv = nullptr;
PFNGLRECTSPROC glfn_glRects = nullptr;
PFNGLRECTSVPROC glfn_glRectsv = nullptr;
PFNGLRENDERMODEPROC glfn_glRenderMode = nullptr;
PFNGLROTATEDPROC glfn_glRotated = nullptr;
PFNGLROTATEFPROC glfn_glRotatef = nullptr;
PFNGLSCALEDPROC glfn_glScaled = nullptr;
PFNGLSCALEFPROC glfn_glScalef = nullptr;
PFNGLSCISSORPROC glfn_glScissor = nullptr;
PFNGLSELECTBUFFERPROC glfn_glSelectBuffer = nullptr;
PFNGLSHADEMODELPROC glfn_glShadeModel = nullptr;
PFNGLSTENCILFUNCPROC glfn_glStencilFunc = nullptr;
PFNGLSTENCILMASKPROC glfn_glStencilMask = nullptr;
PFNGLSTENCILOPPROC glfn_glStencilOp = nullptr;
PFNGLTEXCOORD1DPROC glfn_glTexCoord1d = nullptr;
PFNGLTEXCOORD1DVPROC glfn_glTexCoord1dv = nullptr;
PFNGLTEXCOORD1FPROC glfn_glTexCoord1f = nullptr;
PFNGLTEXCOORD1FVPROC glfn_glTexCoord1fv = nullptr;
PFNGLTEXCOORD1IPROC glfn_glTexCoord1i = nullptr;
PFNGLTEXCOORD1IVPROC glfn_glTexCoord1iv = nullptr;
PFNGLTEXCOORD1SPROC glfn_glTexCoord1s = nullptr;
PFNGLTEXCOORD1SVPROC glfn_glTexCoord1sv = nullptr;
PFNGLTEXCOORD2DPROC glfn_glTexCoord2d = nullptr;
PFNGLTEXCOORD2DVPROC glfn_glTexCoord2dv = nullptr;
PFNGLTEXCOORD2FPROC glfn_glTexCoord2f = nullptr;
PFNGLTEXCOORD2FVPROC glfn_glTexCoord2fv = nullptr;
PFNGLTEXCOORD2IPROC glfn_glTexCoord2i = nullptr;
PFNGLTEXCOORD2IVPROC glfn_glTexCoord2iv = nullptr;
PFNGLTEXCOORD2SPROC glfn_glTexCoord2s = nullptr;
PFNGLTEXCOORD2SVPROC glfn_glTexCoord2sv = nullptr;
PFNGLTEXCOORD3DPROC glfn_glTexCoord3d = nullptr;
PFNGLTEXCOORD3DVPROC glfn_glTexCoord3dv = nullptr;
PFNGLTEXCOORD3FPROC glfn_glTexCoord3f = nullptr;
PFNGLTEXCOORD3FVPROC glfn_glTexCoord3fv = nullptr;
PFNGLTEXCOORD3IPROC glfn_glTexCoord3i = nullptr;
PFNGLTEXCOORD3IVPROC glfn_glTexCoord3iv = nullptr;
PFNGLTEXCOORD3SPROC glfn_glTexCoord3s = nullptr;
PFNGLTEXCOORD3SVPROC glfn_glTexCoord3sv = nullptr;
PFNGLTEXCOORD4DPROC glfn_glTexCoord4d = nullptr;
PFNGLTEXCOORD4DVPROC glfn_glTexCoord4dv = nullptr;
PFNGLTEXCOORD4FPROC glfn_glTexCoord4f = nullptr;
PFNGLTEXCOORD4FVPROC glfn_glTexCoord4fv = nullptr;
PFNGLTEXCOORD4IPROC glfn_glTexCoord4i = nullptr;
PFNGLTEXCOORD4IVPROC glfn_glTexCoord4iv = nullptr;
PFNGLTEXCOORD4SPROC glfn_glTexCoord4s = nullptr;
PFNGLTEXCOORD4SVPROC glfn_glTexCoord4sv = nullptr;
PFNGLTEXCOORDPOINTERPROC glfn_glTexCoordPointer = nullptr;
PFNGLTEXENVFPROC glfn_glTexEnvf = nullptr;
PFNGLTEXENVFVPROC glfn_glTexEnvfv = nullptr;
PFNGLTEXENVIPROC glfn_glTexEnvi = nullptr;
PFNGLTEXENVIVPROC glfn_glTexEnviv = nullptr;
PFNGLTEXGENDPROC glfn_glTexGend = nullptr;
PFNGLTEXGENDVPROC glfn_glTexGendv = nullptr;
PFNGLTEXGENFPROC glfn_glTexGenf = nullptr;
PFNGLTEXGENFVPROC glfn_glTexGenfv = nullptr;
PFNGLTEXGENIPROC glfn_glTexGeni = nullptr;
PFNGLTEXGENIVPROC glfn_glTexGeniv = nullptr;
PFNGLTEXIMAGE1DPROC glfn_glTexImage1D = nullptr;
PFNGLTEXIMAGE2DPROC glfn_glTexImage2D = nullptr;
PFNGLTEXPARAMETERFPROC glfn_glTexParameterf = nullptr;
PFNGLTEXPARAMETERFVPROC glfn_glTexParameterfv = nullptr;
PFNGLTEXPARAMETERIPROC glfn_glTexParameteri = nullptr;
PFNGLTEXPARAMETERIVPROC glfn_glTexParameteriv = nullptr;
PFNGLTEXSUBIMAGE1DPROC glfn_glTexSubImage1D = nullptr;
PFNGLTEXSUBIMAGE2DPROC glfn_glTexSubImage2D = nullptr;
PFNGLTRANSLATEDPROC glfn_glTranslated = nullptr;
PFNGLTRANSLATEFPROC glfn_glTranslatef = nullptr;
PFNGLVERTEX2DPROC glfn_glVertex2d = nullptr;
PFNGLVERTEX2DVPROC glfn_glVertex2dv = nullptr;
PFNGLVERTEX2FPROC glfn_glVertex2f = nullptr;
PFNGLVERTEX2FVPROC glfn_glVertex2fv = nullptr;
PFNGLVERTEX2IPROC glfn_glVertex2i = nullptr;
PFNGLVERTEX2IVPROC glfn_glVertex2iv = nullptr;
PFNGLVERTEX2SPROC glfn_glVertex2s = nullptr;
PFNGLVERTEX2SVPROC glfn_glVertex2sv = nullptr;
PFNGLVERTEX3DPROC glfn_glVertex3d = nullptr;
PFNGLVERTEX3DVPROC glfn_glVertex3dv = nullptr;
PFNGLVERTEX3FPROC glfn_glVertex3f = nullptr;
PFNGLVERTEX3FVPROC glfn_glVertex3fv = nullptr;
PFNGLVERTEX3IPROC glfn_glVertex3i = nullptr;
PFNGLVERTEX3IVPROC glfn_glVertex3iv = nullptr;
PFNGLVERTEX3SPROC glfn_glVertex3s = nullptr;
PFNGLVERTEX3SVPROC glfn_glVertex3sv = nullptr;
PFNGLVERTEX4DPROC glfn_glVertex4d = nullptr;
PFNGLVERTEX4DVPROC glfn_glVertex4dv = nullptr;
PFNGLVERTEX4FPROC glfn_glVertex4f = nullptr;
PFNGLVERTEX4FVPROC glfn_glVertex4fv = nullptr;
PFNGLVERTEX4IPROC glfn_glVertex4i = nullptr;
PFNGLVERTEX4IVPROC glfn_glVertex4iv = nullptr;
PFNGLVERTEX4SPROC glfn_glVertex4s = nullptr;
PFNGLVERTEX4SVPROC glfn_glVertex4sv = nullptr;
PFNGLVERTEXPOINTERPROC glfn_glVertexPointer = nullptr;
PFNGLVIEWPORTPROC glfn_glViewport = nullptr;


void glfnlib_init_GL_VERSION_1_0(PFN_loadfunc_gl load) {
	glfn_glAccum = (PFNGLACCUMPROC)load("glAccum");
	if (!glAccum) { print_msg("glAccum not loaded"); }
	glfn_glAlphaFunc = (PFNGLALPHAFUNCPROC)load("glAlphaFunc");
	if (!glAlphaFunc) { print_msg("glAlphaFunc not loaded"); }
	glfn_glAreTexturesResident = (PFNGLARETEXTURESRESIDENTPROC)load("glAreTexturesResident");
	if (!glAreTexturesResident) { print_msg("glAreTexturesResident not loaded"); }
	glfn_glArrayElement = (PFNGLARRAYELEMENTPROC)load("glArrayElement");
	if (!glArrayElement) { print_msg("glArrayElement not loaded"); }
	glfn_glBegin = (PFNGLBEGINPROC)load("glBegin");
	if (!glBegin) { print_msg("glBegin not loaded"); }
	glfn_glBindTexture = (PFNGLBINDTEXTUREPROC)load("glBindTexture");
	if (!glBindTexture) { print_msg("glBindTexture not loaded"); }
	glfn_glBitmap = (PFNGLBITMAPPROC)load("glBitmap");
	if (!glBitmap) { print_msg("glBitmap not loaded"); }
	glfn_glBlendFunc = (PFNGLBLENDFUNCPROC)load("glBlendFunc");
	if (!glBlendFunc) { print_msg("glBlendFunc not loaded"); }
	glfn_glCallList = (PFNGLCALLLISTPROC)load("glCallList");
	if (!glCallList) { print_msg("glCallList not loaded"); }
	glfn_glCallLists = (PFNGLCALLLISTSPROC)load("glCallLists");
	if (!glCallLists) { print_msg("glCallLists not loaded"); }
	glfn_glClear = (PFNGLCLEARPROC)load("glClear");
	if (!glClear) { print_msg("glClear not loaded"); }
	glfn_glClearAccum = (PFNGLCLEARACCUMPROC)load("glClearAccum");
	if (!glClearAccum) { print_msg("glClearAccum not loaded"); }
	glfn_glClearColor = (PFNGLCLEARCOLORPROC)load("glClearColor");
	if (!glClearColor) { print_msg("glClearColor not loaded"); }
	glfn_glClearDepth = (PFNGLCLEARDEPTHPROC)load("glClearDepth");
	if (!glClearDepth) { print_msg("glClearDepth not loaded"); }
	glfn_glClearIndex = (PFNGLCLEARINDEXPROC)load("glClearIndex");
	if (!glClearIndex) { print_msg("glClearIndex not loaded"); }
	glfn_glClearStencil = (PFNGLCLEARSTENCILPROC)load("glClearStencil");
	if (!glClearStencil) { print_msg("glClearStencil not loaded"); }
	glfn_glClipPlane = (PFNGLCLIPPLANEPROC)load("glClipPlane");
	if (!glClipPlane) { print_msg("glClipPlane not loaded"); }
	glfn_glColor3b = (PFNGLCOLOR3BPROC)load("glColor3b");
	if (!glColor3b) { print_msg("glColor3b not loaded"); }
	glfn_glColor3bv = (PFNGLCOLOR3BVPROC)load("glColor3bv");
	if (!glColor3bv) { print_msg("glColor3bv not loaded"); }
	glfn_glColor3d = (PFNGLCOLOR3DPROC)load("glColor3d");
	if (!glColor3d) { print_msg("glColor3d not loaded"); }
	glfn_glColor3dv = (PFNGLCOLOR3DVPROC)load("glColor3dv");
	if (!glColor3dv) { print_msg("glColor3dv not loaded"); }
	glfn_glColor3f = (PFNGLCOLOR3FPROC)load("glColor3f");
	if (!glColor3f) { print_msg("glColor3f not loaded"); }
	glfn_glColor3fv = (PFNGLCOLOR3FVPROC)load("glColor3fv");
	if (!glColor3fv) { print_msg("glColor3fv not loaded"); }
	glfn_glColor3i = (PFNGLCOLOR3IPROC)load("glColor3i");
	if (!glColor3i) { print_msg("glColor3i not loaded"); }
	glfn_glColor3iv = (PFNGLCOLOR3IVPROC)load("glColor3iv");
	if (!glColor3iv) { print_msg("glColor3iv not loaded"); }
	glfn_glColor3s = (PFNGLCOLOR3SPROC)load("glColor3s");
	if (!glColor3s) { print_msg("glColor3s not loaded"); }
	glfn_glColor3sv = (PFNGLCOLOR3SVPROC)load("glColor3sv");
	if (!glColor3sv) { print_msg("glColor3sv not loaded"); }
	glfn_glColor3ub = (PFNGLCOLOR3UBPROC)load("glColor3ub");
	if (!glColor3ub) { print_msg("glColor3ub not loaded"); }
	glfn_glColor3ubv = (PFNGLCOLOR3UBVPROC)load("glColor3ubv");
	if (!glColor3ubv) { print_msg("glColor3ubv not loaded"); }
	glfn_glColor3ui = (PFNGLCOLOR3UIPROC)load("glColor3ui");
	if (!glColor3ui) { print_msg("glColor3ui not loaded"); }
	glfn_glColor3uiv = (PFNGLCOLOR3UIVPROC)load("glColor3uiv");
	if (!glColor3uiv) { print_msg("glColor3uiv not loaded"); }
	glfn_glColor3us = (PFNGLCOLOR3USPROC)load("glColor3us");
	if (!glColor3us) { print_msg("glColor3us not loaded"); }
	glfn_glColor3usv = (PFNGLCOLOR3USVPROC)load("glColor3usv");
	if (!glColor3usv) { print_msg("glColor3usv not loaded"); }
	glfn_glColor4b = (PFNGLCOLOR4BPROC)load("glColor4b");
	if (!glColor4b) { print_msg("glColor4b not loaded"); }
	glfn_glColor4bv = (PFNGLCOLOR4BVPROC)load("glColor4bv");
	if (!glColor4bv) { print_msg("glColor4bv not loaded"); }
	glfn_glColor4d = (PFNGLCOLOR4DPROC)load("glColor4d");
	if (!glColor4d) { print_msg("glColor4d not loaded"); }
	glfn_glColor4dv = (PFNGLCOLOR4DVPROC)load("glColor4dv");
	if (!glColor4dv) { print_msg("glColor4dv not loaded"); }
	glfn_glColor4f = (PFNGLCOLOR4FPROC)load("glColor4f");
	if (!glColor4f) { print_msg("glColor4f not loaded"); }
	glfn_glColor4fv = (PFNGLCOLOR4FVPROC)load("glColor4fv");
	if (!glColor4fv) { print_msg("glColor4fv not loaded"); }
	glfn_glColor4i = (PFNGLCOLOR4IPROC)load("glColor4i");
	if (!glColor4i) { print_msg("glColor4i not loaded"); }
	glfn_glColor4iv = (PFNGLCOLOR4IVPROC)load("glColor4iv");
	if (!glColor4iv) { print_msg("glColor4iv not loaded"); }
	glfn_glColor4s = (PFNGLCOLOR4SPROC)load("glColor4s");
	if (!glColor4s) { print_msg("glColor4s not loaded"); }
	glfn_glColor4sv = (PFNGLCOLOR4SVPROC)load("glColor4sv");
	if (!glColor4sv) { print_msg("glColor4sv not loaded"); }
	glfn_glColor4ub = (PFNGLCOLOR4UBPROC)load("glColor4ub");
	if (!glColor4ub) { print_msg("glColor4ub not loaded"); }
	glfn_glColor4ubv = (PFNGLCOLOR4UBVPROC)load("glColor4ubv");
	if (!glColor4ubv) { print_msg("glColor4ubv not loaded"); }
	glfn_glColor4ui = (PFNGLCOLOR4UIPROC)load("glColor4ui");
	if (!glColor4ui) { print_msg("glColor4ui not loaded"); }
	glfn_glColor4uiv = (PFNGLCOLOR4UIVPROC)load("glColor4uiv");
	if (!glColor4uiv) { print_msg("glColor4uiv not loaded"); }
	glfn_glColor4us = (PFNGLCOLOR4USPROC)load("glColor4us");
	if (!glColor4us) { print_msg("glColor4us not loaded"); }
	glfn_glColor4usv = (PFNGLCOLOR4USVPROC)load("glColor4usv");
	if (!glColor4usv) { print_msg("glColor4usv not loaded"); }
	glfn_glColorMask = (PFNGLCOLORMASKPROC)load("glColorMask");
	if (!glColorMask) { print_msg("glColorMask not loaded"); }
	glfn_glColorMaterial = (PFNGLCOLORMATERIALPROC)load("glColorMaterial");
	if (!glColorMaterial) { print_msg("glColorMaterial not loaded"); }
	glfn_glColorPointer = (PFNGLCOLORPOINTERPROC)load("glColorPointer");
	if (!glColorPointer) { print_msg("glColorPointer not loaded"); }
	glfn_glCopyPixels = (PFNGLCOPYPIXELSPROC)load("glCopyPixels");
	if (!glCopyPixels) { print_msg("glCopyPixels not loaded"); }
	glfn_glCopyTexImage1D = (PFNGLCOPYTEXIMAGE1DPROC)load("glCopyTexImage1D");
	if (!glCopyTexImage1D) { print_msg("glCopyTexImage1D not loaded"); }
	glfn_glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC)load("glCopyTexImage2D");
	if (!glCopyTexImage2D) { print_msg("glCopyTexImage2D not loaded"); }
	glfn_glCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC)load("glCopyTexSubImage1D");
	if (!glCopyTexSubImage1D) { print_msg("glCopyTexSubImage1D not loaded"); }
	glfn_glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC)load("glCopyTexSubImage2D");
	if (!glCopyTexSubImage2D) { print_msg("glCopyTexSubImage2D not loaded"); }
	glfn_glCullFace = (PFNGLCULLFACEPROC)load("glCullFace");
	if (!glCullFace) { print_msg("glCullFace not loaded"); }
	glfn_glDeleteLists = (PFNGLDELETELISTSPROC)load("glDeleteLists");
	if (!glDeleteLists) { print_msg("glDeleteLists not loaded"); }
	glfn_glDeleteTextures = (PFNGLDELETETEXTURESPROC)load("glDeleteTextures");
	if (!glDeleteTextures) { print_msg("glDeleteTextures not loaded"); }
	glfn_glDepthFunc = (PFNGLDEPTHFUNCPROC)load("glDepthFunc");
	if (!glDepthFunc) { print_msg("glDepthFunc not loaded"); }
	glfn_glDepthMask = (PFNGLDEPTHMASKPROC)load("glDepthMask");
	if (!glDepthMask) { print_msg("glDepthMask not loaded"); }
	glfn_glDepthRange = (PFNGLDEPTHRANGEPROC)load("glDepthRange");
	if (!glDepthRange) { print_msg("glDepthRange not loaded"); }
	glfn_glDisable = (PFNGLDISABLEPROC)load("glDisable");
	if (!glDisable) { print_msg("glDisable not loaded"); }
	glfn_glDisableClientState = (PFNGLDISABLECLIENTSTATEPROC)load("glDisableClientState");
	if (!glDisableClientState) { print_msg("glDisableClientState not loaded"); }
	glfn_glDrawArrays = (PFNGLDRAWARRAYSPROC)load("glDrawArrays");
	if (!glDrawArrays) { print_msg("glDrawArrays not loaded"); }
	glfn_glDrawBuffer = (PFNGLDRAWBUFFERPROC)load("glDrawBuffer");
	if (!glDrawBuffer) { print_msg("glDrawBuffer not loaded"); }
	glfn_glDrawElements = (PFNGLDRAWELEMENTSPROC)load("glDrawElements");
	if (!glDrawElements) { print_msg("glDrawElements not loaded"); }
	glfn_glDrawPixels = (PFNGLDRAWPIXELSPROC)load("glDrawPixels");
	if (!glDrawPixels) { print_msg("glDrawPixels not loaded"); }
	glfn_glEdgeFlag = (PFNGLEDGEFLAGPROC)load("glEdgeFlag");
	if (!glEdgeFlag) { print_msg("glEdgeFlag not loaded"); }
	glfn_glEdgeFlagPointer = (PFNGLEDGEFLAGPOINTERPROC)load("glEdgeFlagPointer");
	if (!glEdgeFlagPointer) { print_msg("glEdgeFlagPointer not loaded"); }
	glfn_glEdgeFlagv = (PFNGLEDGEFLAGVPROC)load("glEdgeFlagv");
	if (!glEdgeFlagv) { print_msg("glEdgeFlagv not loaded"); }
	glfn_glEnable = (PFNGLENABLEPROC)load("glEnable");
	if (!glEnable) { print_msg("glEnable not loaded"); }
	glfn_glEnableClientState = (PFNGLENABLECLIENTSTATEPROC)load("glEnableClientState");
	if (!glEnableClientState) { print_msg("glEnableClientState not loaded"); }
	glfn_glEnd = (PFNGLENDPROC)load("glEnd");
	if (!glEnd) { print_msg("glEnd not loaded"); }
	glfn_glEndList = (PFNGLENDLISTPROC)load("glEndList");
	if (!glEndList) { print_msg("glEndList not loaded"); }
	glfn_glEvalCoord1d = (PFNGLEVALCOORD1DPROC)load("glEvalCoord1d");
	if (!glEvalCoord1d) { print_msg("glEvalCoord1d not loaded"); }
	glfn_glEvalCoord1dv = (PFNGLEVALCOORD1DVPROC)load("glEvalCoord1dv");
	if (!glEvalCoord1dv) { print_msg("glEvalCoord1dv not loaded"); }
	glfn_glEvalCoord1f = (PFNGLEVALCOORD1FPROC)load("glEvalCoord1f");
	if (!glEvalCoord1f) { print_msg("glEvalCoord1f not loaded"); }
	glfn_glEvalCoord1fv = (PFNGLEVALCOORD1FVPROC)load("glEvalCoord1fv");
	if (!glEvalCoord1fv) { print_msg("glEvalCoord1fv not loaded"); }
	glfn_glEvalCoord2d = (PFNGLEVALCOORD2DPROC)load("glEvalCoord2d");
	if (!glEvalCoord2d) { print_msg("glEvalCoord2d not loaded"); }
	glfn_glEvalCoord2dv = (PFNGLEVALCOORD2DVPROC)load("glEvalCoord2dv");
	if (!glEvalCoord2dv) { print_msg("glEvalCoord2dv not loaded"); }
	glfn_glEvalCoord2f = (PFNGLEVALCOORD2FPROC)load("glEvalCoord2f");
	if (!glEvalCoord2f) { print_msg("glEvalCoord2f not loaded"); }
	glfn_glEvalCoord2fv = (PFNGLEVALCOORD2FVPROC)load("glEvalCoord2fv");
	if (!glEvalCoord2fv) { print_msg("glEvalCoord2fv not loaded"); }
	glfn_glEvalMesh1 = (PFNGLEVALMESH1PROC)load("glEvalMesh1");
	if (!glEvalMesh1) { print_msg("glEvalMesh1 not loaded"); }
	glfn_glEvalMesh2 = (PFNGLEVALMESH2PROC)load("glEvalMesh2");
	if (!glEvalMesh2) { print_msg("glEvalMesh2 not loaded"); }
	glfn_glEvalPoint1 = (PFNGLEVALPOINT1PROC)load("glEvalPoint1");
	if (!glEvalPoint1) { print_msg("glEvalPoint1 not loaded"); }
	glfn_glEvalPoint2 = (PFNGLEVALPOINT2PROC)load("glEvalPoint2");
	if (!glEvalPoint2) { print_msg("glEvalPoint2 not loaded"); }
	glfn_glFeedbackBuffer = (PFNGLFEEDBACKBUFFERPROC)load("glFeedbackBuffer");
	if (!glFeedbackBuffer) { print_msg("glFeedbackBuffer not loaded"); }
	glfn_glFinish = (PFNGLFINISHPROC)load("glFinish");
	if (!glFinish) { print_msg("glFinish not loaded"); }
	glfn_glFlush = (PFNGLFLUSHPROC)load("glFlush");
	if (!glFlush) { print_msg("glFlush not loaded"); }
	glfn_glFogf = (PFNGLFOGFPROC)load("glFogf");
	if (!glFogf) { print_msg("glFogf not loaded"); }
	glfn_glFogfv = (PFNGLFOGFVPROC)load("glFogfv");
	if (!glFogfv) { print_msg("glFogfv not loaded"); }
	glfn_glFogi = (PFNGLFOGIPROC)load("glFogi");
	if (!glFogi) { print_msg("glFogi not loaded"); }
	glfn_glFogiv = (PFNGLFOGIVPROC)load("glFogiv");
	if (!glFogiv) { print_msg("glFogiv not loaded"); }
	glfn_glFrontFace = (PFNGLFRONTFACEPROC)load("glFrontFace");
	if (!glFrontFace) { print_msg("glFrontFace not loaded"); }
	glfn_glFrustum = (PFNGLFRUSTUMPROC)load("glFrustum");
	if (!glFrustum) { print_msg("glFrustum not loaded"); }
	glfn_glGenLists = (PFNGLGENLISTSPROC)load("glGenLists");
	if (!glGenLists) { print_msg("glGenLists not loaded"); }
	glfn_glGenTextures = (PFNGLGENTEXTURESPROC)load("glGenTextures");
	if (!glGenTextures) { print_msg("glGenTextures not loaded"); }
	glfn_glGetBooleanv = (PFNGLGETBOOLEANVPROC)load("glGetBooleanv");
	if (!glGetBooleanv) { print_msg("glGetBooleanv not loaded"); }
	glfn_glGetClipPlane = (PFNGLGETCLIPPLANEPROC)load("glGetClipPlane");
	if (!glGetClipPlane) { print_msg("glGetClipPlane not loaded"); }
	glfn_glGetDoublev = (PFNGLGETDOUBLEVPROC)load("glGetDoublev");
	if (!glGetDoublev) { print_msg("glGetDoublev not loaded"); }
	glfn_glGetError = (PFNGLGETERRORPROC)load("glGetError");
	if (!glGetError) { print_msg("glGetError not loaded"); }
	glfn_glGetFloatv = (PFNGLGETFLOATVPROC)load("glGetFloatv");
	if (!glGetFloatv) { print_msg("glGetFloatv not loaded"); }
	glfn_glGetIntegerv = (PFNGLGETINTEGERVPROC)load("glGetIntegerv");
	if (!glGetIntegerv) { print_msg("glGetIntegerv not loaded"); }
	glfn_glGetLightfv = (PFNGLGETLIGHTFVPROC)load("glGetLightfv");
	if (!glGetLightfv) { print_msg("glGetLightfv not loaded"); }
	glfn_glGetLightiv = (PFNGLGETLIGHTIVPROC)load("glGetLightiv");
	if (!glGetLightiv) { print_msg("glGetLightiv not loaded"); }
	glfn_glGetMapdv = (PFNGLGETMAPDVPROC)load("glGetMapdv");
	if (!glGetMapdv) { print_msg("glGetMapdv not loaded"); }
	glfn_glGetMapfv = (PFNGLGETMAPFVPROC)load("glGetMapfv");
	if (!glGetMapfv) { print_msg("glGetMapfv not loaded"); }
	glfn_glGetMapiv = (PFNGLGETMAPIVPROC)load("glGetMapiv");
	if (!glGetMapiv) { print_msg("glGetMapiv not loaded"); }
	glfn_glGetMaterialfv = (PFNGLGETMATERIALFVPROC)load("glGetMaterialfv");
	if (!glGetMaterialfv) { print_msg("glGetMaterialfv not loaded"); }
	glfn_glGetMaterialiv = (PFNGLGETMATERIALIVPROC)load("glGetMaterialiv");
	if (!glGetMaterialiv) { print_msg("glGetMaterialiv not loaded"); }
	glfn_glGetPixelMapfv = (PFNGLGETPIXELMAPFVPROC)load("glGetPixelMapfv");
	if (!glGetPixelMapfv) { print_msg("glGetPixelMapfv not loaded"); }
	glfn_glGetPixelMapuiv = (PFNGLGETPIXELMAPUIVPROC)load("glGetPixelMapuiv");
	if (!glGetPixelMapuiv) { print_msg("glGetPixelMapuiv not loaded"); }
	glfn_glGetPixelMapusv = (PFNGLGETPIXELMAPUSVPROC)load("glGetPixelMapusv");
	if (!glGetPixelMapusv) { print_msg("glGetPixelMapusv not loaded"); }
	glfn_glGetPointerv = (PFNGLGETPOINTERVPROC)load("glGetPointerv");
	if (!glGetPointerv) { print_msg("glGetPointerv not loaded"); }
	glfn_glGetPolygonStipple = (PFNGLGETPOLYGONSTIPPLEPROC)load("glGetPolygonStipple");
	if (!glGetPolygonStipple) { print_msg("glGetPolygonStipple not loaded"); }
	glfn_glGetString = (PFNGLGETSTRINGPROC)load("glGetString");
	if (!glGetString) { print_msg("glGetString not loaded"); }
	glfn_glGetTexEnvfv = (PFNGLGETTEXENVFVPROC)load("glGetTexEnvfv");
	if (!glGetTexEnvfv) { print_msg("glGetTexEnvfv not loaded"); }
	glfn_glGetTexEnviv = (PFNGLGETTEXENVIVPROC)load("glGetTexEnviv");
	if (!glGetTexEnviv) { print_msg("glGetTexEnviv not loaded"); }
	glfn_glGetTexGendv = (PFNGLGETTEXGENDVPROC)load("glGetTexGendv");
	if (!glGetTexGendv) { print_msg("glGetTexGendv not loaded"); }
	glfn_glGetTexGenfv = (PFNGLGETTEXGENFVPROC)load("glGetTexGenfv");
	if (!glGetTexGenfv) { print_msg("glGetTexGenfv not loaded"); }
	glfn_glGetTexGeniv = (PFNGLGETTEXGENIVPROC)load("glGetTexGeniv");
	if (!glGetTexGeniv) { print_msg("glGetTexGeniv not loaded"); }
	glfn_glGetTexImage = (PFNGLGETTEXIMAGEPROC)load("glGetTexImage");
	if (!glGetTexImage) { print_msg("glGetTexImage not loaded"); }
	glfn_glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC)load("glGetTexLevelParameterfv");
	if (!glGetTexLevelParameterfv) { print_msg("glGetTexLevelParameterfv not loaded"); }
	glfn_glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC)load("glGetTexLevelParameteriv");
	if (!glGetTexLevelParameteriv) { print_msg("glGetTexLevelParameteriv not loaded"); }
	glfn_glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC)load("glGetTexParameterfv");
	if (!glGetTexParameterfv) { print_msg("glGetTexParameterfv not loaded"); }
	glfn_glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC)load("glGetTexParameteriv");
	if (!glGetTexParameteriv) { print_msg("glGetTexParameteriv not loaded"); }
	glfn_glHint = (PFNGLHINTPROC)load("glHint");
	if (!glHint) { print_msg("glHint not loaded"); }
	glfn_glIndexMask = (PFNGLINDEXMASKPROC)load("glIndexMask");
	if (!glIndexMask) { print_msg("glIndexMask not loaded"); }
	glfn_glIndexPointer = (PFNGLINDEXPOINTERPROC)load("glIndexPointer");
	if (!glIndexPointer) { print_msg("glIndexPointer not loaded"); }
	glfn_glIndexd = (PFNGLINDEXDPROC)load("glIndexd");
	if (!glIndexd) { print_msg("glIndexd not loaded"); }
	glfn_glIndexdv = (PFNGLINDEXDVPROC)load("glIndexdv");
	if (!glIndexdv) { print_msg("glIndexdv not loaded"); }
	glfn_glIndexf = (PFNGLINDEXFPROC)load("glIndexf");
	if (!glIndexf) { print_msg("glIndexf not loaded"); }
	glfn_glIndexfv = (PFNGLINDEXFVPROC)load("glIndexfv");
	if (!glIndexfv) { print_msg("glIndexfv not loaded"); }
	glfn_glIndexi = (PFNGLINDEXIPROC)load("glIndexi");
	if (!glIndexi) { print_msg("glIndexi not loaded"); }
	glfn_glIndexiv = (PFNGLINDEXIVPROC)load("glIndexiv");
	if (!glIndexiv) { print_msg("glIndexiv not loaded"); }
	glfn_glIndexs = (PFNGLINDEXSPROC)load("glIndexs");
	if (!glIndexs) { print_msg("glIndexs not loaded"); }
	glfn_glIndexsv = (PFNGLINDEXSVPROC)load("glIndexsv");
	if (!glIndexsv) { print_msg("glIndexsv not loaded"); }
	glfn_glIndexub = (PFNGLINDEXUBPROC)load("glIndexub");
	if (!glIndexub) { print_msg("glIndexub not loaded"); }
	glfn_glIndexubv = (PFNGLINDEXUBVPROC)load("glIndexubv");
	if (!glIndexubv) { print_msg("glIndexubv not loaded"); }
	glfn_glInitNames = (PFNGLINITNAMESPROC)load("glInitNames");
	if (!glInitNames) { print_msg("glInitNames not loaded"); }
	glfn_glInterleavedArrays = (PFNGLINTERLEAVEDARRAYSPROC)load("glInterleavedArrays");
	if (!glInterleavedArrays) { print_msg("glInterleavedArrays not loaded"); }
	glfn_glIsEnabled = (PFNGLISENABLEDPROC)load("glIsEnabled");
	if (!glIsEnabled) { print_msg("glIsEnabled not loaded"); }
	glfn_glIsList = (PFNGLISLISTPROC)load("glIsList");
	if (!glIsList) { print_msg("glIsList not loaded"); }
	glfn_glIsTexture = (PFNGLISTEXTUREPROC)load("glIsTexture");
	if (!glIsTexture) { print_msg("glIsTexture not loaded"); }
	glfn_glLightModelf = (PFNGLLIGHTMODELFPROC)load("glLightModelf");
	if (!glLightModelf) { print_msg("glLightModelf not loaded"); }
	glfn_glLightModelfv = (PFNGLLIGHTMODELFVPROC)load("glLightModelfv");
	if (!glLightModelfv) { print_msg("glLightModelfv not loaded"); }
	glfn_glLightModeli = (PFNGLLIGHTMODELIPROC)load("glLightModeli");
	if (!glLightModeli) { print_msg("glLightModeli not loaded"); }
	glfn_glLightModeliv = (PFNGLLIGHTMODELIVPROC)load("glLightModeliv");
	if (!glLightModeliv) { print_msg("glLightModeliv not loaded"); }
	glfn_glLightf = (PFNGLLIGHTFPROC)load("glLightf");
	if (!glLightf) { print_msg("glLightf not loaded"); }
	glfn_glLightfv = (PFNGLLIGHTFVPROC)load("glLightfv");
	if (!glLightfv) { print_msg("glLightfv not loaded"); }
	glfn_glLighti = (PFNGLLIGHTIPROC)load("glLighti");
	if (!glLighti) { print_msg("glLighti not loaded"); }
	glfn_glLightiv = (PFNGLLIGHTIVPROC)load("glLightiv");
	if (!glLightiv) { print_msg("glLightiv not loaded"); }
	glfn_glLineStipple = (PFNGLLINESTIPPLEPROC)load("glLineStipple");
	if (!glLineStipple) { print_msg("glLineStipple not loaded"); }
	glfn_glLineWidth = (PFNGLLINEWIDTHPROC)load("glLineWidth");
	if (!glLineWidth) { print_msg("glLineWidth not loaded"); }
	glfn_glListBase = (PFNGLLISTBASEPROC)load("glListBase");
	if (!glListBase) { print_msg("glListBase not loaded"); }
	glfn_glLoadIdentity = (PFNGLLOADIDENTITYPROC)load("glLoadIdentity");
	if (!glLoadIdentity) { print_msg("glLoadIdentity not loaded"); }
	glfn_glLoadMatrixd = (PFNGLLOADMATRIXDPROC)load("glLoadMatrixd");
	if (!glLoadMatrixd) { print_msg("glLoadMatrixd not loaded"); }
	glfn_glLoadMatrixf = (PFNGLLOADMATRIXFPROC)load("glLoadMatrixf");
	if (!glLoadMatrixf) { print_msg("glLoadMatrixf not loaded"); }
	glfn_glLoadName = (PFNGLLOADNAMEPROC)load("glLoadName");
	if (!glLoadName) { print_msg("glLoadName not loaded"); }
	glfn_glLogicOp = (PFNGLLOGICOPPROC)load("glLogicOp");
	if (!glLogicOp) { print_msg("glLogicOp not loaded"); }
	glfn_glMap1d = (PFNGLMAP1DPROC)load("glMap1d");
	if (!glMap1d) { print_msg("glMap1d not loaded"); }
	glfn_glMap1f = (PFNGLMAP1FPROC)load("glMap1f");
	if (!glMap1f) { print_msg("glMap1f not loaded"); }
	glfn_glMap2d = (PFNGLMAP2DPROC)load("glMap2d");
	if (!glMap2d) { print_msg("glMap2d not loaded"); }
	glfn_glMap2f = (PFNGLMAP2FPROC)load("glMap2f");
	if (!glMap2f) { print_msg("glMap2f not loaded"); }
	glfn_glMapGrid1d = (PFNGLMAPGRID1DPROC)load("glMapGrid1d");
	if (!glMapGrid1d) { print_msg("glMapGrid1d not loaded"); }
	glfn_glMapGrid1f = (PFNGLMAPGRID1FPROC)load("glMapGrid1f");
	if (!glMapGrid1f) { print_msg("glMapGrid1f not loaded"); }
	glfn_glMapGrid2d = (PFNGLMAPGRID2DPROC)load("glMapGrid2d");
	if (!glMapGrid2d) { print_msg("glMapGrid2d not loaded"); }
	glfn_glMapGrid2f = (PFNGLMAPGRID2FPROC)load("glMapGrid2f");
	if (!glMapGrid2f) { print_msg("glMapGrid2f not loaded"); }
	glfn_glMaterialf = (PFNGLMATERIALFPROC)load("glMaterialf");
	if (!glMaterialf) { print_msg("glMaterialf not loaded"); }
	glfn_glMaterialfv = (PFNGLMATERIALFVPROC)load("glMaterialfv");
	if (!glMaterialfv) { print_msg("glMaterialfv not loaded"); }
	glfn_glMateriali = (PFNGLMATERIALIPROC)load("glMateriali");
	if (!glMateriali) { print_msg("glMateriali not loaded"); }
	glfn_glMaterialiv = (PFNGLMATERIALIVPROC)load("glMaterialiv");
	if (!glMaterialiv) { print_msg("glMaterialiv not loaded"); }
	glfn_glMatrixMode = (PFNGLMATRIXMODEPROC)load("glMatrixMode");
	if (!glMatrixMode) { print_msg("glMatrixMode not loaded"); }
	glfn_glMultMatrixd = (PFNGLMULTMATRIXDPROC)load("glMultMatrixd");
	if (!glMultMatrixd) { print_msg("glMultMatrixd not loaded"); }
	glfn_glMultMatrixf = (PFNGLMULTMATRIXFPROC)load("glMultMatrixf");
	if (!glMultMatrixf) { print_msg("glMultMatrixf not loaded"); }
	glfn_glNewList = (PFNGLNEWLISTPROC)load("glNewList");
	if (!glNewList) { print_msg("glNewList not loaded"); }
	glfn_glNormal3b = (PFNGLNORMAL3BPROC)load("glNormal3b");
	if (!glNormal3b) { print_msg("glNormal3b not loaded"); }
	glfn_glNormal3bv = (PFNGLNORMAL3BVPROC)load("glNormal3bv");
	if (!glNormal3bv) { print_msg("glNormal3bv not loaded"); }
	glfn_glNormal3d = (PFNGLNORMAL3DPROC)load("glNormal3d");
	if (!glNormal3d) { print_msg("glNormal3d not loaded"); }
	glfn_glNormal3dv = (PFNGLNORMAL3DVPROC)load("glNormal3dv");
	if (!glNormal3dv) { print_msg("glNormal3dv not loaded"); }
	glfn_glNormal3f = (PFNGLNORMAL3FPROC)load("glNormal3f");
	if (!glNormal3f) { print_msg("glNormal3f not loaded"); }
	glfn_glNormal3fv = (PFNGLNORMAL3FVPROC)load("glNormal3fv");
	if (!glNormal3fv) { print_msg("glNormal3fv not loaded"); }
	glfn_glNormal3i = (PFNGLNORMAL3IPROC)load("glNormal3i");
	if (!glNormal3i) { print_msg("glNormal3i not loaded"); }
	glfn_glNormal3iv = (PFNGLNORMAL3IVPROC)load("glNormal3iv");
	if (!glNormal3iv) { print_msg("glNormal3iv not loaded"); }
	glfn_glNormal3s = (PFNGLNORMAL3SPROC)load("glNormal3s");
	if (!glNormal3s) { print_msg("glNormal3s not loaded"); }
	glfn_glNormal3sv = (PFNGLNORMAL3SVPROC)load("glNormal3sv");
	if (!glNormal3sv) { print_msg("glNormal3sv not loaded"); }
	glfn_glNormalPointer = (PFNGLNORMALPOINTERPROC)load("glNormalPointer");
	if (!glNormalPointer) { print_msg("glNormalPointer not loaded"); }
	glfn_glOrtho = (PFNGLORTHOPROC)load("glOrtho");
	if (!glOrtho) { print_msg("glOrtho not loaded"); }
	glfn_glPassThrough = (PFNGLPASSTHROUGHPROC)load("glPassThrough");
	if (!glPassThrough) { print_msg("glPassThrough not loaded"); }
	glfn_glPixelMapfv = (PFNGLPIXELMAPFVPROC)load("glPixelMapfv");
	if (!glPixelMapfv) { print_msg("glPixelMapfv not loaded"); }
	glfn_glPixelMapuiv = (PFNGLPIXELMAPUIVPROC)load("glPixelMapuiv");
	if (!glPixelMapuiv) { print_msg("glPixelMapuiv not loaded"); }
	glfn_glPixelMapusv = (PFNGLPIXELMAPUSVPROC)load("glPixelMapusv");
	if (!glPixelMapusv) { print_msg("glPixelMapusv not loaded"); }
	glfn_glPixelStoref = (PFNGLPIXELSTOREFPROC)load("glPixelStoref");
	if (!glPixelStoref) { print_msg("glPixelStoref not loaded"); }
	glfn_glPixelStorei = (PFNGLPIXELSTOREIPROC)load("glPixelStorei");
	if (!glPixelStorei) { print_msg("glPixelStorei not loaded"); }
	glfn_glPixelTransferf = (PFNGLPIXELTRANSFERFPROC)load("glPixelTransferf");
	if (!glPixelTransferf) { print_msg("glPixelTransferf not loaded"); }
	glfn_glPixelTransferi = (PFNGLPIXELTRANSFERIPROC)load("glPixelTransferi");
	if (!glPixelTransferi) { print_msg("glPixelTransferi not loaded"); }
	glfn_glPixelZoom = (PFNGLPIXELZOOMPROC)load("glPixelZoom");
	if (!glPixelZoom) { print_msg("glPixelZoom not loaded"); }
	glfn_glPointSize = (PFNGLPOINTSIZEPROC)load("glPointSize");
	if (!glPointSize) { print_msg("glPointSize not loaded"); }
	glfn_glPolygonMode = (PFNGLPOLYGONMODEPROC)load("glPolygonMode");
	if (!glPolygonMode) { print_msg("glPolygonMode not loaded"); }
	glfn_glPolygonOffset = (PFNGLPOLYGONOFFSETPROC)load("glPolygonOffset");
	if (!glPolygonOffset) { print_msg("glPolygonOffset not loaded"); }
	glfn_glPolygonStipple = (PFNGLPOLYGONSTIPPLEPROC)load("glPolygonStipple");
	if (!glPolygonStipple) { print_msg("glPolygonStipple not loaded"); }
	glfn_glPopAttrib = (PFNGLPOPATTRIBPROC)load("glPopAttrib");
	if (!glPopAttrib) { print_msg("glPopAttrib not loaded"); }
	glfn_glPopClientAttrib = (PFNGLPOPCLIENTATTRIBPROC)load("glPopClientAttrib");
	if (!glPopClientAttrib) { print_msg("glPopClientAttrib not loaded"); }
	glfn_glPopMatrix = (PFNGLPOPMATRIXPROC)load("glPopMatrix");
	if (!glPopMatrix) { print_msg("glPopMatrix not loaded"); }
	glfn_glPopName = (PFNGLPOPNAMEPROC)load("glPopName");
	if (!glPopName) { print_msg("glPopName not loaded"); }
	glfn_glPrioritizeTextures = (PFNGLPRIORITIZETEXTURESPROC)load("glPrioritizeTextures");
	if (!glPrioritizeTextures) { print_msg("glPrioritizeTextures not loaded"); }
	glfn_glPushAttrib = (PFNGLPUSHATTRIBPROC)load("glPushAttrib");
	if (!glPushAttrib) { print_msg("glPushAttrib not loaded"); }
	glfn_glPushClientAttrib = (PFNGLPUSHCLIENTATTRIBPROC)load("glPushClientAttrib");
	if (!glPushClientAttrib) { print_msg("glPushClientAttrib not loaded"); }
	glfn_glPushMatrix = (PFNGLPUSHMATRIXPROC)load("glPushMatrix");
	if (!glPushMatrix) { print_msg("glPushMatrix not loaded"); }
	glfn_glPushName = (PFNGLPUSHNAMEPROC)load("glPushName");
	if (!glPushName) { print_msg("glPushName not loaded"); }
	glfn_glRasterPos2d = (PFNGLRASTERPOS2DPROC)load("glRasterPos2d");
	if (!glRasterPos2d) { print_msg("glRasterPos2d not loaded"); }
	glfn_glRasterPos2dv = (PFNGLRASTERPOS2DVPROC)load("glRasterPos2dv");
	if (!glRasterPos2dv) { print_msg("glRasterPos2dv not loaded"); }
	glfn_glRasterPos2f = (PFNGLRASTERPOS2FPROC)load("glRasterPos2f");
	if (!glRasterPos2f) { print_msg("glRasterPos2f not loaded"); }
	glfn_glRasterPos2fv = (PFNGLRASTERPOS2FVPROC)load("glRasterPos2fv");
	if (!glRasterPos2fv) { print_msg("glRasterPos2fv not loaded"); }
	glfn_glRasterPos2i = (PFNGLRASTERPOS2IPROC)load("glRasterPos2i");
	if (!glRasterPos2i) { print_msg("glRasterPos2i not loaded"); }
	glfn_glRasterPos2iv = (PFNGLRASTERPOS2IVPROC)load("glRasterPos2iv");
	if (!glRasterPos2iv) { print_msg("glRasterPos2iv not loaded"); }
	glfn_glRasterPos2s = (PFNGLRASTERPOS2SPROC)load("glRasterPos2s");
	if (!glRasterPos2s) { print_msg("glRasterPos2s not loaded"); }
	glfn_glRasterPos2sv = (PFNGLRASTERPOS2SVPROC)load("glRasterPos2sv");
	if (!glRasterPos2sv) { print_msg("glRasterPos2sv not loaded"); }
	glfn_glRasterPos3d = (PFNGLRASTERPOS3DPROC)load("glRasterPos3d");
	if (!glRasterPos3d) { print_msg("glRasterPos3d not loaded"); }
	glfn_glRasterPos3dv = (PFNGLRASTERPOS3DVPROC)load("glRasterPos3dv");
	if (!glRasterPos3dv) { print_msg("glRasterPos3dv not loaded"); }
	glfn_glRasterPos3f = (PFNGLRASTERPOS3FPROC)load("glRasterPos3f");
	if (!glRasterPos3f) { print_msg("glRasterPos3f not loaded"); }
	glfn_glRasterPos3fv = (PFNGLRASTERPOS3FVPROC)load("glRasterPos3fv");
	if (!glRasterPos3fv) { print_msg("glRasterPos3fv not loaded"); }
	glfn_glRasterPos3i = (PFNGLRASTERPOS3IPROC)load("glRasterPos3i");
	if (!glRasterPos3i) { print_msg("glRasterPos3i not loaded"); }
	glfn_glRasterPos3iv = (PFNGLRASTERPOS3IVPROC)load("glRasterPos3iv");
	if (!glRasterPos3iv) { print_msg("glRasterPos3iv not loaded"); }
	glfn_glRasterPos3s = (PFNGLRASTERPOS3SPROC)load("glRasterPos3s");
	if (!glRasterPos3s) { print_msg("glRasterPos3s not loaded"); }
	glfn_glRasterPos3sv = (PFNGLRASTERPOS3SVPROC)load("glRasterPos3sv");
	if (!glRasterPos3sv) { print_msg("glRasterPos3sv not loaded"); }
	glfn_glRasterPos4d = (PFNGLRASTERPOS4DPROC)load("glRasterPos4d");
	if (!glRasterPos4d) { print_msg("glRasterPos4d not loaded"); }
	glfn_glRasterPos4dv = (PFNGLRASTERPOS4DVPROC)load("glRasterPos4dv");
	if (!glRasterPos4dv) { print_msg("glRasterPos4dv not loaded"); }
	glfn_glRasterPos4f = (PFNGLRASTERPOS4FPROC)load("glRasterPos4f");
	if (!glRasterPos4f) { print_msg("glRasterPos4f not loaded"); }
	glfn_glRasterPos4fv = (PFNGLRASTERPOS4FVPROC)load("glRasterPos4fv");
	if (!glRasterPos4fv) { print_msg("glRasterPos4fv not loaded"); }
	glfn_glRasterPos4i = (PFNGLRASTERPOS4IPROC)load("glRasterPos4i");
	if (!glRasterPos4i) { print_msg("glRasterPos4i not loaded"); }
	glfn_glRasterPos4iv = (PFNGLRASTERPOS4IVPROC)load("glRasterPos4iv");
	if (!glRasterPos4iv) { print_msg("glRasterPos4iv not loaded"); }
	glfn_glRasterPos4s = (PFNGLRASTERPOS4SPROC)load("glRasterPos4s");
	if (!glRasterPos4s) { print_msg("glRasterPos4s not loaded"); }
	glfn_glRasterPos4sv = (PFNGLRASTERPOS4SVPROC)load("glRasterPos4sv");
	if (!glRasterPos4sv) { print_msg("glRasterPos4sv not loaded"); }
	glfn_glReadBuffer = (PFNGLREADBUFFERPROC)load("glReadBuffer");
	if (!glReadBuffer) { print_msg("glReadBuffer not loaded"); }
	glfn_glReadPixels = (PFNGLREADPIXELSPROC)load("glReadPixels");
	if (!glReadPixels) { print_msg("glReadPixels not loaded"); }
	glfn_glRectd = (PFNGLRECTDPROC)load("glRectd");
	if (!glRectd) { print_msg("glRectd not loaded"); }
	glfn_glRectdv = (PFNGLRECTDVPROC)load("glRectdv");
	if (!glRectdv) { print_msg("glRectdv not loaded"); }
	glfn_glRectf = (PFNGLRECTFPROC)load("glRectf");
	if (!glRectf) { print_msg("glRectf not loaded"); }
	glfn_glRectfv = (PFNGLRECTFVPROC)load("glRectfv");
	if (!glRectfv) { print_msg("glRectfv not loaded"); }
	glfn_glRecti = (PFNGLRECTIPROC)load("glRecti");
	if (!glRecti) { print_msg("glRecti not loaded"); }
	glfn_glRectiv = (PFNGLRECTIVPROC)load("glRectiv");
	if (!glRectiv) { print_msg("glRectiv not loaded"); }
	glfn_glRects = (PFNGLRECTSPROC)load("glRects");
	if (!glRects) { print_msg("glRects not loaded"); }
	glfn_glRectsv = (PFNGLRECTSVPROC)load("glRectsv");
	if (!glRectsv) { print_msg("glRectsv not loaded"); }
	glfn_glRenderMode = (PFNGLRENDERMODEPROC)load("glRenderMode");
	if (!glRenderMode) { print_msg("glRenderMode not loaded"); }
	glfn_glRotated = (PFNGLROTATEDPROC)load("glRotated");
	if (!glRotated) { print_msg("glRotated not loaded"); }
	glfn_glRotatef = (PFNGLROTATEFPROC)load("glRotatef");
	if (!glRotatef) { print_msg("glRotatef not loaded"); }
	glfn_glScaled = (PFNGLSCALEDPROC)load("glScaled");
	if (!glScaled) { print_msg("glScaled not loaded"); }
	glfn_glScalef = (PFNGLSCALEFPROC)load("glScalef");
	if (!glScalef) { print_msg("glScalef not loaded"); }
	glfn_glScissor = (PFNGLSCISSORPROC)load("glScissor");
	if (!glScissor) { print_msg("glScissor not loaded"); }
	glfn_glSelectBuffer = (PFNGLSELECTBUFFERPROC)load("glSelectBuffer");
	if (!glSelectBuffer) { print_msg("glSelectBuffer not loaded"); }
	glfn_glShadeModel = (PFNGLSHADEMODELPROC)load("glShadeModel");
	if (!glShadeModel) { print_msg("glShadeModel not loaded"); }
	glfn_glStencilFunc = (PFNGLSTENCILFUNCPROC)load("glStencilFunc");
	if (!glStencilFunc) { print_msg("glStencilFunc not loaded"); }
	glfn_glStencilMask = (PFNGLSTENCILMASKPROC)load("glStencilMask");
	if (!glStencilMask) { print_msg("glStencilMask not loaded"); }
	glfn_glStencilOp = (PFNGLSTENCILOPPROC)load("glStencilOp");
	if (!glStencilOp) { print_msg("glStencilOp not loaded"); }
	glfn_glTexCoord1d = (PFNGLTEXCOORD1DPROC)load("glTexCoord1d");
	if (!glTexCoord1d) { print_msg("glTexCoord1d not loaded"); }
	glfn_glTexCoord1dv = (PFNGLTEXCOORD1DVPROC)load("glTexCoord1dv");
	if (!glTexCoord1dv) { print_msg("glTexCoord1dv not loaded"); }
	glfn_glTexCoord1f = (PFNGLTEXCOORD1FPROC)load("glTexCoord1f");
	if (!glTexCoord1f) { print_msg("glTexCoord1f not loaded"); }
	glfn_glTexCoord1fv = (PFNGLTEXCOORD1FVPROC)load("glTexCoord1fv");
	if (!glTexCoord1fv) { print_msg("glTexCoord1fv not loaded"); }
	glfn_glTexCoord1i = (PFNGLTEXCOORD1IPROC)load("glTexCoord1i");
	if (!glTexCoord1i) { print_msg("glTexCoord1i not loaded"); }
	glfn_glTexCoord1iv = (PFNGLTEXCOORD1IVPROC)load("glTexCoord1iv");
	if (!glTexCoord1iv) { print_msg("glTexCoord1iv not loaded"); }
	glfn_glTexCoord1s = (PFNGLTEXCOORD1SPROC)load("glTexCoord1s");
	if (!glTexCoord1s) { print_msg("glTexCoord1s not loaded"); }
	glfn_glTexCoord1sv = (PFNGLTEXCOORD1SVPROC)load("glTexCoord1sv");
	if (!glTexCoord1sv) { print_msg("glTexCoord1sv not loaded"); }
	glfn_glTexCoord2d = (PFNGLTEXCOORD2DPROC)load("glTexCoord2d");
	if (!glTexCoord2d) { print_msg("glTexCoord2d not loaded"); }
	glfn_glTexCoord2dv = (PFNGLTEXCOORD2DVPROC)load("glTexCoord2dv");
	if (!glTexCoord2dv) { print_msg("glTexCoord2dv not loaded"); }
	glfn_glTexCoord2f = (PFNGLTEXCOORD2FPROC)load("glTexCoord2f");
	if (!glTexCoord2f) { print_msg("glTexCoord2f not loaded"); }
	glfn_glTexCoord2fv = (PFNGLTEXCOORD2FVPROC)load("glTexCoord2fv");
	if (!glTexCoord2fv) { print_msg("glTexCoord2fv not loaded"); }
	glfn_glTexCoord2i = (PFNGLTEXCOORD2IPROC)load("glTexCoord2i");
	if (!glTexCoord2i) { print_msg("glTexCoord2i not loaded"); }
	glfn_glTexCoord2iv = (PFNGLTEXCOORD2IVPROC)load("glTexCoord2iv");
	if (!glTexCoord2iv) { print_msg("glTexCoord2iv not loaded"); }
	glfn_glTexCoord2s = (PFNGLTEXCOORD2SPROC)load("glTexCoord2s");
	if (!glTexCoord2s) { print_msg("glTexCoord2s not loaded"); }
	glfn_glTexCoord2sv = (PFNGLTEXCOORD2SVPROC)load("glTexCoord2sv");
	if (!glTexCoord2sv) { print_msg("glTexCoord2sv not loaded"); }
	glfn_glTexCoord3d = (PFNGLTEXCOORD3DPROC)load("glTexCoord3d");
	if (!glTexCoord3d) { print_msg("glTexCoord3d not loaded"); }
	glfn_glTexCoord3dv = (PFNGLTEXCOORD3DVPROC)load("glTexCoord3dv");
	if (!glTexCoord3dv) { print_msg("glTexCoord3dv not loaded"); }
	glfn_glTexCoord3f = (PFNGLTEXCOORD3FPROC)load("glTexCoord3f");
	if (!glTexCoord3f) { print_msg("glTexCoord3f not loaded"); }
	glfn_glTexCoord3fv = (PFNGLTEXCOORD3FVPROC)load("glTexCoord3fv");
	if (!glTexCoord3fv) { print_msg("glTexCoord3fv not loaded"); }
	glfn_glTexCoord3i = (PFNGLTEXCOORD3IPROC)load("glTexCoord3i");
	if (!glTexCoord3i) { print_msg("glTexCoord3i not loaded"); }
	glfn_glTexCoord3iv = (PFNGLTEXCOORD3IVPROC)load("glTexCoord3iv");
	if (!glTexCoord3iv) { print_msg("glTexCoord3iv not loaded"); }
	glfn_glTexCoord3s = (PFNGLTEXCOORD3SPROC)load("glTexCoord3s");
	if (!glTexCoord3s) { print_msg("glTexCoord3s not loaded"); }
	glfn_glTexCoord3sv = (PFNGLTEXCOORD3SVPROC)load("glTexCoord3sv");
	if (!glTexCoord3sv) { print_msg("glTexCoord3sv not loaded"); }
	glfn_glTexCoord4d = (PFNGLTEXCOORD4DPROC)load("glTexCoord4d");
	if (!glTexCoord4d) { print_msg("glTexCoord4d not loaded"); }
	glfn_glTexCoord4dv = (PFNGLTEXCOORD4DVPROC)load("glTexCoord4dv");
	if (!glTexCoord4dv) { print_msg("glTexCoord4dv not loaded"); }
	glfn_glTexCoord4f = (PFNGLTEXCOORD4FPROC)load("glTexCoord4f");
	if (!glTexCoord4f) { print_msg("glTexCoord4f not loaded"); }
	glfn_glTexCoord4fv = (PFNGLTEXCOORD4FVPROC)load("glTexCoord4fv");
	if (!glTexCoord4fv) { print_msg("glTexCoord4fv not loaded"); }
	glfn_glTexCoord4i = (PFNGLTEXCOORD4IPROC)load("glTexCoord4i");
	if (!glTexCoord4i) { print_msg("glTexCoord4i not loaded"); }
	glfn_glTexCoord4iv = (PFNGLTEXCOORD4IVPROC)load("glTexCoord4iv");
	if (!glTexCoord4iv) { print_msg("glTexCoord4iv not loaded"); }
	glfn_glTexCoord4s = (PFNGLTEXCOORD4SPROC)load("glTexCoord4s");
	if (!glTexCoord4s) { print_msg("glTexCoord4s not loaded"); }
	glfn_glTexCoord4sv = (PFNGLTEXCOORD4SVPROC)load("glTexCoord4sv");
	if (!glTexCoord4sv) { print_msg("glTexCoord4sv not loaded"); }
	glfn_glTexCoordPointer = (PFNGLTEXCOORDPOINTERPROC)load("glTexCoordPointer");
	if (!glTexCoordPointer) { print_msg("glTexCoordPointer not loaded"); }
	glfn_glTexEnvf = (PFNGLTEXENVFPROC)load("glTexEnvf");
	if (!glTexEnvf) { print_msg("glTexEnvf not loaded"); }
	glfn_glTexEnvfv = (PFNGLTEXENVFVPROC)load("glTexEnvfv");
	if (!glTexEnvfv) { print_msg("glTexEnvfv not loaded"); }
	glfn_glTexEnvi = (PFNGLTEXENVIPROC)load("glTexEnvi");
	if (!glTexEnvi) { print_msg("glTexEnvi not loaded"); }
	glfn_glTexEnviv = (PFNGLTEXENVIVPROC)load("glTexEnviv");
	if (!glTexEnviv) { print_msg("glTexEnviv not loaded"); }
	glfn_glTexGend = (PFNGLTEXGENDPROC)load("glTexGend");
	if (!glTexGend) { print_msg("glTexGend not loaded"); }
	glfn_glTexGendv = (PFNGLTEXGENDVPROC)load("glTexGendv");
	if (!glTexGendv) { print_msg("glTexGendv not loaded"); }
	glfn_glTexGenf = (PFNGLTEXGENFPROC)load("glTexGenf");
	if (!glTexGenf) { print_msg("glTexGenf not loaded"); }
	glfn_glTexGenfv = (PFNGLTEXGENFVPROC)load("glTexGenfv");
	if (!glTexGenfv) { print_msg("glTexGenfv not loaded"); }
	glfn_glTexGeni = (PFNGLTEXGENIPROC)load("glTexGeni");
	if (!glTexGeni) { print_msg("glTexGeni not loaded"); }
	glfn_glTexGeniv = (PFNGLTEXGENIVPROC)load("glTexGeniv");
	if (!glTexGeniv) { print_msg("glTexGeniv not loaded"); }
	glfn_glTexImage1D = (PFNGLTEXIMAGE1DPROC)load("glTexImage1D");
	if (!glTexImage1D) { print_msg("glTexImage1D not loaded"); }
	glfn_glTexImage2D = (PFNGLTEXIMAGE2DPROC)load("glTexImage2D");
	if (!glTexImage2D) { print_msg("glTexImage2D not loaded"); }
	glfn_glTexParameterf = (PFNGLTEXPARAMETERFPROC)load("glTexParameterf");
	if (!glTexParameterf) { print_msg("glTexParameterf not loaded"); }
	glfn_glTexParameterfv = (PFNGLTEXPARAMETERFVPROC)load("glTexParameterfv");
	if (!glTexParameterfv) { print_msg("glTexParameterfv not loaded"); }
	glfn_glTexParameteri = (PFNGLTEXPARAMETERIPROC)load("glTexParameteri");
	if (!glTexParameteri) { print_msg("glTexParameteri not loaded"); }
	glfn_glTexParameteriv = (PFNGLTEXPARAMETERIVPROC)load("glTexParameteriv");
	if (!glTexParameteriv) { print_msg("glTexParameteriv not loaded"); }
	glfn_glTexSubImage1D = (PFNGLTEXSUBIMAGE1DPROC)load("glTexSubImage1D");
	if (!glTexSubImage1D) { print_msg("glTexSubImage1D not loaded"); }
	glfn_glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC)load("glTexSubImage2D");
	if (!glTexSubImage2D) { print_msg("glTexSubImage2D not loaded"); }
	glfn_glTranslated = (PFNGLTRANSLATEDPROC)load("glTranslated");
	if (!glTranslated) { print_msg("glTranslated not loaded"); }
	glfn_glTranslatef = (PFNGLTRANSLATEFPROC)load("glTranslatef");
	if (!glTranslatef) { print_msg("glTranslatef not loaded"); }
	glfn_glVertex2d = (PFNGLVERTEX2DPROC)load("glVertex2d");
	if (!glVertex2d) { print_msg("glVertex2d not loaded"); }
	glfn_glVertex2dv = (PFNGLVERTEX2DVPROC)load("glVertex2dv");
	if (!glVertex2dv) { print_msg("glVertex2dv not loaded"); }
	glfn_glVertex2f = (PFNGLVERTEX2FPROC)load("glVertex2f");
	if (!glVertex2f) { print_msg("glVertex2f not loaded"); }
	glfn_glVertex2fv = (PFNGLVERTEX2FVPROC)load("glVertex2fv");
	if (!glVertex2fv) { print_msg("glVertex2fv not loaded"); }
	glfn_glVertex2i = (PFNGLVERTEX2IPROC)load("glVertex2i");
	if (!glVertex2i) { print_msg("glVertex2i not loaded"); }
	glfn_glVertex2iv = (PFNGLVERTEX2IVPROC)load("glVertex2iv");
	if (!glVertex2iv) { print_msg("glVertex2iv not loaded"); }
	glfn_glVertex2s = (PFNGLVERTEX2SPROC)load("glVertex2s");
	if (!glVertex2s) { print_msg("glVertex2s not loaded"); }
	glfn_glVertex2sv = (PFNGLVERTEX2SVPROC)load("glVertex2sv");
	if (!glVertex2sv) { print_msg("glVertex2sv not loaded"); }
	glfn_glVertex3d = (PFNGLVERTEX3DPROC)load("glVertex3d");
	if (!glVertex3d) { print_msg("glVertex3d not loaded"); }
	glfn_glVertex3dv = (PFNGLVERTEX3DVPROC)load("glVertex3dv");
	if (!glVertex3dv) { print_msg("glVertex3dv not loaded"); }
	glfn_glVertex3f = (PFNGLVERTEX3FPROC)load("glVertex3f");
	if (!glVertex3f) { print_msg("glVertex3f not loaded"); }
	glfn_glVertex3fv = (PFNGLVERTEX3FVPROC)load("glVertex3fv");
	if (!glVertex3fv) { print_msg("glVertex3fv not loaded"); }
	glfn_glVertex3i = (PFNGLVERTEX3IPROC)load("glVertex3i");
	if (!glVertex3i) { print_msg("glVertex3i not loaded"); }
	glfn_glVertex3iv = (PFNGLVERTEX3IVPROC)load("glVertex3iv");
	if (!glVertex3iv) { print_msg("glVertex3iv not loaded"); }
	glfn_glVertex3s = (PFNGLVERTEX3SPROC)load("glVertex3s");
	if (!glVertex3s) { print_msg("glVertex3s not loaded"); }
	glfn_glVertex3sv = (PFNGLVERTEX3SVPROC)load("glVertex3sv");
	if (!glVertex3sv) { print_msg("glVertex3sv not loaded"); }
	glfn_glVertex4d = (PFNGLVERTEX4DPROC)load("glVertex4d");
	if (!glVertex4d) { print_msg("glVertex4d not loaded"); }
	glfn_glVertex4dv = (PFNGLVERTEX4DVPROC)load("glVertex4dv");
	if (!glVertex4dv) { print_msg("glVertex4dv not loaded"); }
	glfn_glVertex4f = (PFNGLVERTEX4FPROC)load("glVertex4f");
	if (!glVertex4f) { print_msg("glVertex4f not loaded"); }
	glfn_glVertex4fv = (PFNGLVERTEX4FVPROC)load("glVertex4fv");
	if (!glVertex4fv) { print_msg("glVertex4fv not loaded"); }
	glfn_glVertex4i = (PFNGLVERTEX4IPROC)load("glVertex4i");
	if (!glVertex4i) { print_msg("glVertex4i not loaded"); }
	glfn_glVertex4iv = (PFNGLVERTEX4IVPROC)load("glVertex4iv");
	if (!glVertex4iv) { print_msg("glVertex4iv not loaded"); }
	glfn_glVertex4s = (PFNGLVERTEX4SPROC)load("glVertex4s");
	if (!glVertex4s) { print_msg("glVertex4s not loaded"); }
	glfn_glVertex4sv = (PFNGLVERTEX4SVPROC)load("glVertex4sv");
	if (!glVertex4sv) { print_msg("glVertex4sv not loaded"); }
	glfn_glVertexPointer = (PFNGLVERTEXPOINTERPROC)load("glVertexPointer");
	if (!glVertexPointer) { print_msg("glVertexPointer not loaded"); }
	glfn_glViewport = (PFNGLVIEWPORTPROC)load("glViewport");
	if (!glViewport) { print_msg("glViewport not loaded"); }
}


// GL_VERSION_1_2
PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = nullptr;
PFNGLTEXIMAGE3DPROC glTexImage3D = nullptr;
PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D = nullptr;
PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = nullptr;
// GL_VERSION_1_3
PFNGLACTIVETEXTUREPROC glActiveTexture = nullptr;
PFNGLSAMPLECOVERAGEPROC glSampleCoverage = nullptr;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D = nullptr;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D = nullptr;
PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D = nullptr;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D = nullptr;
PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage = nullptr;
PFNGLCLIENTACTIVETEXTUREPROC glClientActiveTexture = nullptr;
PFNGLMULTITEXCOORD1DPROC glMultiTexCoord1d = nullptr;
PFNGLMULTITEXCOORD1DVPROC glMultiTexCoord1dv = nullptr;
PFNGLMULTITEXCOORD1FPROC glMultiTexCoord1f = nullptr;
PFNGLMULTITEXCOORD1FVPROC glMultiTexCoord1fv = nullptr;
PFNGLMULTITEXCOORD1IPROC glMultiTexCoord1i = nullptr;
PFNGLMULTITEXCOORD1IVPROC glMultiTexCoord1iv = nullptr;
PFNGLMULTITEXCOORD1SPROC glMultiTexCoord1s = nullptr;
PFNGLMULTITEXCOORD1SVPROC glMultiTexCoord1sv = nullptr;
PFNGLMULTITEXCOORD2DPROC glMultiTexCoord2d = nullptr;
PFNGLMULTITEXCOORD2DVPROC glMultiTexCoord2dv = nullptr;
PFNGLMULTITEXCOORD2FPROC glMultiTexCoord2f = nullptr;
PFNGLMULTITEXCOORD2FVPROC glMultiTexCoord2fv = nullptr;
PFNGLMULTITEXCOORD2IPROC glMultiTexCoord2i = nullptr;
PFNGLMULTITEXCOORD2IVPROC glMultiTexCoord2iv = nullptr;
PFNGLMULTITEXCOORD2SPROC glMultiTexCoord2s = nullptr;
PFNGLMULTITEXCOORD2SVPROC glMultiTexCoord2sv = nullptr;
PFNGLMULTITEXCOORD3DPROC glMultiTexCoord3d = nullptr;
PFNGLMULTITEXCOORD3DVPROC glMultiTexCoord3dv = nullptr;
PFNGLMULTITEXCOORD3FPROC glMultiTexCoord3f = nullptr;
PFNGLMULTITEXCOORD3FVPROC glMultiTexCoord3fv = nullptr;
PFNGLMULTITEXCOORD3IPROC glMultiTexCoord3i = nullptr;
PFNGLMULTITEXCOORD3IVPROC glMultiTexCoord3iv = nullptr;
PFNGLMULTITEXCOORD3SPROC glMultiTexCoord3s = nullptr;
PFNGLMULTITEXCOORD3SVPROC glMultiTexCoord3sv = nullptr;
PFNGLMULTITEXCOORD4DPROC glMultiTexCoord4d = nullptr;
PFNGLMULTITEXCOORD4DVPROC glMultiTexCoord4dv = nullptr;
PFNGLMULTITEXCOORD4FPROC glMultiTexCoord4f = nullptr;
PFNGLMULTITEXCOORD4FVPROC glMultiTexCoord4fv = nullptr;
PFNGLMULTITEXCOORD4IPROC glMultiTexCoord4i = nullptr;
PFNGLMULTITEXCOORD4IVPROC glMultiTexCoord4iv = nullptr;
PFNGLMULTITEXCOORD4SPROC glMultiTexCoord4s = nullptr;
PFNGLMULTITEXCOORD4SVPROC glMultiTexCoord4sv = nullptr;
PFNGLLOADTRANSPOSEMATRIXFPROC glLoadTransposeMatrixf = nullptr;
PFNGLLOADTRANSPOSEMATRIXDPROC glLoadTransposeMatrixd = nullptr;
PFNGLMULTTRANSPOSEMATRIXFPROC glMultTransposeMatrixf = nullptr;
PFNGLMULTTRANSPOSEMATRIXDPROC glMultTransposeMatrixd = nullptr;
// GL_VERSION_1_4
PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate = nullptr;
PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays = nullptr;
PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements = nullptr;
PFNGLPOINTPARAMETERFPROC glPointParameterf = nullptr;
PFNGLPOINTPARAMETERFVPROC glPointParameterfv = nullptr;
PFNGLPOINTPARAMETERIPROC glPointParameteri = nullptr;
PFNGLPOINTPARAMETERIVPROC glPointParameteriv = nullptr;
PFNGLFOGCOORDFPROC glFogCoordf = nullptr;
PFNGLFOGCOORDFVPROC glFogCoordfv = nullptr;
PFNGLFOGCOORDDPROC glFogCoordd = nullptr;
PFNGLFOGCOORDDVPROC glFogCoorddv = nullptr;
PFNGLFOGCOORDPOINTERPROC glFogCoordPointer = nullptr;
PFNGLSECONDARYCOLOR3BPROC glSecondaryColor3b = nullptr;
PFNGLSECONDARYCOLOR3BVPROC glSecondaryColor3bv = nullptr;
PFNGLSECONDARYCOLOR3DPROC glSecondaryColor3d = nullptr;
PFNGLSECONDARYCOLOR3DVPROC glSecondaryColor3dv = nullptr;
PFNGLSECONDARYCOLOR3FPROC glSecondaryColor3f = nullptr;
PFNGLSECONDARYCOLOR3FVPROC glSecondaryColor3fv = nullptr;
PFNGLSECONDARYCOLOR3IPROC glSecondaryColor3i = nullptr;
PFNGLSECONDARYCOLOR3IVPROC glSecondaryColor3iv = nullptr;
PFNGLSECONDARYCOLOR3SPROC glSecondaryColor3s = nullptr;
PFNGLSECONDARYCOLOR3SVPROC glSecondaryColor3sv = nullptr;
PFNGLSECONDARYCOLOR3UBPROC glSecondaryColor3ub = nullptr;
PFNGLSECONDARYCOLOR3UBVPROC glSecondaryColor3ubv = nullptr;
PFNGLSECONDARYCOLOR3UIPROC glSecondaryColor3ui = nullptr;
PFNGLSECONDARYCOLOR3UIVPROC glSecondaryColor3uiv = nullptr;
PFNGLSECONDARYCOLOR3USPROC glSecondaryColor3us = nullptr;
PFNGLSECONDARYCOLOR3USVPROC glSecondaryColor3usv = nullptr;
PFNGLSECONDARYCOLORPOINTERPROC glSecondaryColorPointer = nullptr;
PFNGLWINDOWPOS2DPROC glWindowPos2d = nullptr;
PFNGLWINDOWPOS2DVPROC glWindowPos2dv = nullptr;
PFNGLWINDOWPOS2FPROC glWindowPos2f = nullptr;
PFNGLWINDOWPOS2FVPROC glWindowPos2fv = nullptr;
PFNGLWINDOWPOS2IPROC glWindowPos2i = nullptr;
PFNGLWINDOWPOS2IVPROC glWindowPos2iv = nullptr;
PFNGLWINDOWPOS2SPROC glWindowPos2s = nullptr;
PFNGLWINDOWPOS2SVPROC glWindowPos2sv = nullptr;
PFNGLWINDOWPOS3DPROC glWindowPos3d = nullptr;
PFNGLWINDOWPOS3DVPROC glWindowPos3dv = nullptr;
PFNGLWINDOWPOS3FPROC glWindowPos3f = nullptr;
PFNGLWINDOWPOS3FVPROC glWindowPos3fv = nullptr;
PFNGLWINDOWPOS3IPROC glWindowPos3i = nullptr;
PFNGLWINDOWPOS3IVPROC glWindowPos3iv = nullptr;
PFNGLWINDOWPOS3SPROC glWindowPos3s = nullptr;
PFNGLWINDOWPOS3SVPROC glWindowPos3sv = nullptr;
PFNGLBLENDCOLORPROC glBlendColor = nullptr;
PFNGLBLENDEQUATIONPROC glBlendEquation = nullptr;
// GL_VERSION_1_5
PFNGLGENQUERIESPROC glGenQueries = nullptr;
PFNGLDELETEQUERIESPROC glDeleteQueries = nullptr;
PFNGLISQUERYPROC glIsQuery = nullptr;
PFNGLBEGINQUERYPROC glBeginQuery = nullptr;
PFNGLENDQUERYPROC glEndQuery = nullptr;
PFNGLGETQUERYIVPROC glGetQueryiv = nullptr;
PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv = nullptr;
PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv = nullptr;
PFNGLBINDBUFFERPROC glBindBuffer = nullptr;
PFNGLDELETEBUFFERSPROC glDeleteBuffers = nullptr;
PFNGLGENBUFFERSPROC glGenBuffers = nullptr;
PFNGLISBUFFERPROC glIsBuffer = nullptr;
PFNGLBUFFERDATAPROC glBufferData = nullptr;
PFNGLBUFFERSUBDATAPROC glBufferSubData = nullptr;
PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData = nullptr;
PFNGLMAPBUFFERPROC glMapBuffer = nullptr;
PFNGLUNMAPBUFFERPROC glUnmapBuffer = nullptr;
PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv = nullptr;
PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv = nullptr;
// GL_VERSION_2_0
PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate = nullptr;
PFNGLDRAWBUFFERSPROC glDrawBuffers = nullptr;
PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate = nullptr;
PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate = nullptr;
PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate = nullptr;
PFNGLATTACHSHADERPROC glAttachShader = nullptr;
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation = nullptr;
PFNGLCOMPILESHADERPROC glCompileShader = nullptr;
PFNGLCREATEPROGRAMPROC glCreateProgram = nullptr;
PFNGLCREATESHADERPROC glCreateShader = nullptr;
PFNGLDELETEPROGRAMPROC glDeleteProgram = nullptr;
PFNGLDELETESHADERPROC glDeleteShader = nullptr;
PFNGLDETACHSHADERPROC glDetachShader = nullptr;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = nullptr;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = nullptr;
PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib = nullptr;
PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform = nullptr;
PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders = nullptr;
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation = nullptr;
PFNGLGETPROGRAMIVPROC glGetProgramiv = nullptr;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = nullptr;
PFNGLGETSHADERIVPROC glGetShaderiv = nullptr;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = nullptr;
PFNGLGETSHADERSOURCEPROC glGetShaderSource = nullptr;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = nullptr;
PFNGLGETUNIFORMFVPROC glGetUniformfv = nullptr;
PFNGLGETUNIFORMIVPROC glGetUniformiv = nullptr;
PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv = nullptr;
PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv = nullptr;
PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv = nullptr;
PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv = nullptr;
PFNGLISPROGRAMPROC glIsProgram = nullptr;
PFNGLISSHADERPROC glIsShader = nullptr;
PFNGLLINKPROGRAMPROC glLinkProgram = nullptr;
PFNGLSHADERSOURCEPROC glShaderSource = nullptr;
PFNGLUSEPROGRAMPROC glUseProgram = nullptr;
PFNGLUNIFORM1FPROC glUniform1f = nullptr;
PFNGLUNIFORM2FPROC glUniform2f = nullptr;
PFNGLUNIFORM3FPROC glUniform3f = nullptr;
PFNGLUNIFORM4FPROC glUniform4f = nullptr;
PFNGLUNIFORM1IPROC glUniform1i = nullptr;
PFNGLUNIFORM2IPROC glUniform2i = nullptr;
PFNGLUNIFORM3IPROC glUniform3i = nullptr;
PFNGLUNIFORM4IPROC glUniform4i = nullptr;
PFNGLUNIFORM1FVPROC glUniform1fv = nullptr;
PFNGLUNIFORM2FVPROC glUniform2fv = nullptr;
PFNGLUNIFORM3FVPROC glUniform3fv = nullptr;
PFNGLUNIFORM4FVPROC glUniform4fv = nullptr;
PFNGLUNIFORM1IVPROC glUniform1iv = nullptr;
PFNGLUNIFORM2IVPROC glUniform2iv = nullptr;
PFNGLUNIFORM3IVPROC glUniform3iv = nullptr;
PFNGLUNIFORM4IVPROC glUniform4iv = nullptr;
PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv = nullptr;
PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv = nullptr;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv = nullptr;
PFNGLVALIDATEPROGRAMPROC glValidateProgram = nullptr;
PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d = nullptr;
PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv = nullptr;
PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f = nullptr;
PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv = nullptr;
PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s = nullptr;
PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv = nullptr;
PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d = nullptr;
PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv = nullptr;
PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f = nullptr;
PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv = nullptr;
PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s = nullptr;
PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv = nullptr;
PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d = nullptr;
PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv = nullptr;
PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f = nullptr;
PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv = nullptr;
PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s = nullptr;
PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv = nullptr;
PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv = nullptr;
PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv = nullptr;
PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv = nullptr;
PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub = nullptr;
PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv = nullptr;
PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv = nullptr;
PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv = nullptr;
PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv = nullptr;
PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d = nullptr;
PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv = nullptr;
PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f = nullptr;
PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv = nullptr;
PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv = nullptr;
PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s = nullptr;
PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv = nullptr;
PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv = nullptr;
PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv = nullptr;
PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv = nullptr;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = nullptr;
// GL_VERSION_2_1
PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv = nullptr;
PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv = nullptr;
PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv = nullptr;
PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv = nullptr;
PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv = nullptr;
PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv = nullptr;
// GL_VERSION_3_0
PFNGLCOLORMASKIPROC glColorMaski = nullptr;
PFNGLGETBOOLEANI_VPROC glGetBooleani_v = nullptr;
PFNGLGETINTEGERI_VPROC glGetIntegeri_v = nullptr;
PFNGLENABLEIPROC glEnablei = nullptr;
PFNGLDISABLEIPROC glDisablei = nullptr;
PFNGLISENABLEDIPROC glIsEnabledi = nullptr;
PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback = nullptr;
PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback = nullptr;
PFNGLBINDBUFFERRANGEPROC glBindBufferRange = nullptr;
PFNGLBINDBUFFERBASEPROC glBindBufferBase = nullptr;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings = nullptr;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying = nullptr;
PFNGLCLAMPCOLORPROC glClampColor = nullptr;
PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender = nullptr;
PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender = nullptr;
PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer = nullptr;
PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv = nullptr;
PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv = nullptr;
PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i = nullptr;
PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i = nullptr;
PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i = nullptr;
PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i = nullptr;
PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui = nullptr;
PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui = nullptr;
PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui = nullptr;
PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui = nullptr;
PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv = nullptr;
PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv = nullptr;
PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv = nullptr;
PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv = nullptr;
PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv = nullptr;
PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv = nullptr;
PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv = nullptr;
PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv = nullptr;
PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv = nullptr;
PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv = nullptr;
PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv = nullptr;
PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv = nullptr;
PFNGLGETUNIFORMUIVPROC glGetUniformuiv = nullptr;
PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation = nullptr;
PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation = nullptr;
PFNGLUNIFORM1UIPROC glUniform1ui = nullptr;
PFNGLUNIFORM2UIPROC glUniform2ui = nullptr;
PFNGLUNIFORM3UIPROC glUniform3ui = nullptr;
PFNGLUNIFORM4UIPROC glUniform4ui = nullptr;
PFNGLUNIFORM1UIVPROC glUniform1uiv = nullptr;
PFNGLUNIFORM2UIVPROC glUniform2uiv = nullptr;
PFNGLUNIFORM3UIVPROC glUniform3uiv = nullptr;
PFNGLUNIFORM4UIVPROC glUniform4uiv = nullptr;
PFNGLTEXPARAMETERIIVPROC glTexParameterIiv = nullptr;
PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv = nullptr;
PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv = nullptr;
PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv = nullptr;
PFNGLCLEARBUFFERIVPROC glClearBufferiv = nullptr;
PFNGLCLEARBUFFERUIVPROC glClearBufferuiv = nullptr;
PFNGLCLEARBUFFERFVPROC glClearBufferfv = nullptr;
PFNGLCLEARBUFFERFIPROC glClearBufferfi = nullptr;
PFNGLGETSTRINGIPROC glGetStringi = nullptr;
PFNGLISRENDERBUFFERPROC glIsRenderbuffer = nullptr;
PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer = nullptr;
PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers = nullptr;
PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers = nullptr;
PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage = nullptr;
PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv = nullptr;
PFNGLISFRAMEBUFFERPROC glIsFramebuffer = nullptr;
PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer = nullptr;
PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers = nullptr;
PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers = nullptr;
PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus = nullptr;
PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D = nullptr;
PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D = nullptr;
PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D = nullptr;
PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer = nullptr;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv = nullptr;
PFNGLGENERATEMIPMAPPROC glGenerateMipmap = nullptr;
PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer = nullptr;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample = nullptr;
PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer = nullptr;
PFNGLMAPBUFFERRANGEPROC glMapBufferRange = nullptr;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange = nullptr;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray = nullptr;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays = nullptr;
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = nullptr;
PFNGLISVERTEXARRAYPROC glIsVertexArray = nullptr;
// GL_VERSION_3_1
PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced = nullptr;
PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced = nullptr;
PFNGLTEXBUFFERPROC glTexBuffer = nullptr;
PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex = nullptr;
PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData = nullptr;
PFNGLGETUNIFORMINDICESPROC glGetUniformIndices = nullptr;
PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv = nullptr;
PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName = nullptr;
PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex = nullptr;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv = nullptr;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName = nullptr;
PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding = nullptr;
// GL_VERSION_3_2
PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex = nullptr;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex = nullptr;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex = nullptr;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex = nullptr;
PFNGLPROVOKINGVERTEXPROC glProvokingVertex = nullptr;
PFNGLFENCESYNCPROC glFenceSync = nullptr;
PFNGLISSYNCPROC glIsSync = nullptr;
PFNGLDELETESYNCPROC glDeleteSync = nullptr;
PFNGLCLIENTWAITSYNCPROC glClientWaitSync = nullptr;
PFNGLWAITSYNCPROC glWaitSync = nullptr;
PFNGLGETINTEGER64VPROC glGetInteger64v = nullptr;
PFNGLGETSYNCIVPROC glGetSynciv = nullptr;
PFNGLGETINTEGER64I_VPROC glGetInteger64i_v = nullptr;
PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v = nullptr;
PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture = nullptr;
PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample = nullptr;
PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample = nullptr;
PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv = nullptr;
PFNGLSAMPLEMASKIPROC glSampleMaski = nullptr;
// GL_VERSION_3_3
PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed = nullptr;
PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex = nullptr;
PFNGLGENSAMPLERSPROC glGenSamplers = nullptr;
PFNGLDELETESAMPLERSPROC glDeleteSamplers = nullptr;
PFNGLISSAMPLERPROC glIsSampler = nullptr;
PFNGLBINDSAMPLERPROC glBindSampler = nullptr;
PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri = nullptr;
PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv = nullptr;
PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf = nullptr;
PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv = nullptr;
PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv = nullptr;
PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv = nullptr;
PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv = nullptr;
PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv = nullptr;
PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv = nullptr;
PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv = nullptr;
PFNGLQUERYCOUNTERPROC glQueryCounter = nullptr;
PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v = nullptr;
PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v = nullptr;
PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor = nullptr;
PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui = nullptr;
PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv = nullptr;
PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui = nullptr;
PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv = nullptr;
PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui = nullptr;
PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv = nullptr;
PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui = nullptr;
PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv = nullptr;
PFNGLVERTEXP2UIPROC glVertexP2ui = nullptr;
PFNGLVERTEXP2UIVPROC glVertexP2uiv = nullptr;
PFNGLVERTEXP3UIPROC glVertexP3ui = nullptr;
PFNGLVERTEXP3UIVPROC glVertexP3uiv = nullptr;
PFNGLVERTEXP4UIPROC glVertexP4ui = nullptr;
PFNGLVERTEXP4UIVPROC glVertexP4uiv = nullptr;
PFNGLTEXCOORDP1UIPROC glTexCoordP1ui = nullptr;
PFNGLTEXCOORDP1UIVPROC glTexCoordP1uiv = nullptr;
PFNGLTEXCOORDP2UIPROC glTexCoordP2ui = nullptr;
PFNGLTEXCOORDP2UIVPROC glTexCoordP2uiv = nullptr;
PFNGLTEXCOORDP3UIPROC glTexCoordP3ui = nullptr;
PFNGLTEXCOORDP3UIVPROC glTexCoordP3uiv = nullptr;
PFNGLTEXCOORDP4UIPROC glTexCoordP4ui = nullptr;
PFNGLTEXCOORDP4UIVPROC glTexCoordP4uiv = nullptr;
PFNGLMULTITEXCOORDP1UIPROC glMultiTexCoordP1ui = nullptr;
PFNGLMULTITEXCOORDP1UIVPROC glMultiTexCoordP1uiv = nullptr;
PFNGLMULTITEXCOORDP2UIPROC glMultiTexCoordP2ui = nullptr;
PFNGLMULTITEXCOORDP2UIVPROC glMultiTexCoordP2uiv = nullptr;
PFNGLMULTITEXCOORDP3UIPROC glMultiTexCoordP3ui = nullptr;
PFNGLMULTITEXCOORDP3UIVPROC glMultiTexCoordP3uiv = nullptr;
PFNGLMULTITEXCOORDP4UIPROC glMultiTexCoordP4ui = nullptr;
PFNGLMULTITEXCOORDP4UIVPROC glMultiTexCoordP4uiv = nullptr;
PFNGLNORMALP3UIPROC glNormalP3ui = nullptr;
PFNGLNORMALP3UIVPROC glNormalP3uiv = nullptr;
PFNGLCOLORP3UIPROC glColorP3ui = nullptr;
PFNGLCOLORP3UIVPROC glColorP3uiv = nullptr;
PFNGLCOLORP4UIPROC glColorP4ui = nullptr;
PFNGLCOLORP4UIVPROC glColorP4uiv = nullptr;
PFNGLSECONDARYCOLORP3UIPROC glSecondaryColorP3ui = nullptr;
PFNGLSECONDARYCOLORP3UIVPROC glSecondaryColorP3uiv = nullptr;
// GL_VERSION_4_0
PFNGLMINSAMPLESHADINGPROC glMinSampleShading = nullptr;
PFNGLBLENDEQUATIONIPROC glBlendEquationi = nullptr;
PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei = nullptr;
PFNGLBLENDFUNCIPROC glBlendFunci = nullptr;
PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei = nullptr;
PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect = nullptr;
PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect = nullptr;
PFNGLUNIFORM1DPROC glUniform1d = nullptr;
PFNGLUNIFORM2DPROC glUniform2d = nullptr;
PFNGLUNIFORM3DPROC glUniform3d = nullptr;
PFNGLUNIFORM4DPROC glUniform4d = nullptr;
PFNGLUNIFORM1DVPROC glUniform1dv = nullptr;
PFNGLUNIFORM2DVPROC glUniform2dv = nullptr;
PFNGLUNIFORM3DVPROC glUniform3dv = nullptr;
PFNGLUNIFORM4DVPROC glUniform4dv = nullptr;
PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv = nullptr;
PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv = nullptr;
PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv = nullptr;
PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv = nullptr;
PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv = nullptr;
PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv = nullptr;
PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv = nullptr;
PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv = nullptr;
PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv = nullptr;
PFNGLGETUNIFORMDVPROC glGetUniformdv = nullptr;
PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation = nullptr;
PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex = nullptr;
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv = nullptr;
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName = nullptr;
PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName = nullptr;
PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv = nullptr;
PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv = nullptr;
PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv = nullptr;
PFNGLPATCHPARAMETERIPROC glPatchParameteri = nullptr;
PFNGLPATCHPARAMETERFVPROC glPatchParameterfv = nullptr;
PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback = nullptr;
PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks = nullptr;
PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks = nullptr;
PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback = nullptr;
PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback = nullptr;
PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback = nullptr;
PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback = nullptr;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream = nullptr;
PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed = nullptr;
PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed = nullptr;
PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv = nullptr;
// GL_VERSION_4_1
PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler = nullptr;
PFNGLSHADERBINARYPROC glShaderBinary = nullptr;
PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat = nullptr;
PFNGLDEPTHRANGEFPROC glDepthRangef = nullptr;
PFNGLCLEARDEPTHFPROC glClearDepthf = nullptr;
PFNGLGETPROGRAMBINARYPROC glGetProgramBinary = nullptr;
PFNGLPROGRAMBINARYPROC glProgramBinary = nullptr;
PFNGLPROGRAMPARAMETERIPROC glProgramParameteri = nullptr;
PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages = nullptr;
PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram = nullptr;
PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv = nullptr;
PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline = nullptr;
PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines = nullptr;
PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines = nullptr;
PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline = nullptr;
PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv = nullptr;
PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i = nullptr;
PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv = nullptr;
PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f = nullptr;
PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv = nullptr;
PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d = nullptr;
PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv = nullptr;
PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui = nullptr;
PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv = nullptr;
PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i = nullptr;
PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv = nullptr;
PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f = nullptr;
PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv = nullptr;
PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d = nullptr;
PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv = nullptr;
PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui = nullptr;
PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv = nullptr;
PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i = nullptr;
PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv = nullptr;
PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f = nullptr;
PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv = nullptr;
PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d = nullptr;
PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv = nullptr;
PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui = nullptr;
PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv = nullptr;
PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i = nullptr;
PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv = nullptr;
PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f = nullptr;
PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv = nullptr;
PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d = nullptr;
PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv = nullptr;
PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui = nullptr;
PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv = nullptr;
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv = nullptr;
PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline = nullptr;
PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog = nullptr;
PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d = nullptr;
PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d = nullptr;
PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d = nullptr;
PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d = nullptr;
PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv = nullptr;
PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv = nullptr;
PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv = nullptr;
PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv = nullptr;
PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer = nullptr;
PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv = nullptr;
PFNGLVIEWPORTARRAYVPROC glViewportArrayv = nullptr;
PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf = nullptr;
PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv = nullptr;
PFNGLSCISSORARRAYVPROC glScissorArrayv = nullptr;
PFNGLSCISSORINDEXEDPROC glScissorIndexed = nullptr;
PFNGLSCISSORINDEXEDVPROC glScissorIndexedv = nullptr;
PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv = nullptr;
PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed = nullptr;
PFNGLGETFLOATI_VPROC glGetFloati_v = nullptr;
PFNGLGETDOUBLEI_VPROC glGetDoublei_v = nullptr;
// GL_VERSION_4_2
PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance = nullptr;
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance = nullptr;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance = nullptr;
PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ = nullptr;
PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv = nullptr;
PFNGLBINDIMAGETEXTUREPROC glBindImageTexture = nullptr;
PFNGLMEMORYBARRIERPROC glMemoryBarrier = nullptr;
PFNGLTEXSTORAGE1DPROC glTexStorage1D = nullptr;
PFNGLTEXSTORAGE2DPROC glTexStorage2D = nullptr;
PFNGLTEXSTORAGE3DPROC glTexStorage3D = nullptr;
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced = nullptr;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced = nullptr;
// GL_VERSION_4_3
PFNGLCLEARBUFFERDATAPROC glClearBufferData = nullptr;
PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData = nullptr;
PFNGLDISPATCHCOMPUTEPROC glDispatchCompute = nullptr;
PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect = nullptr;
PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubData = nullptr;
PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri = nullptr;
PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv = nullptr;
PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64v = nullptr;
PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage = nullptr;
PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage = nullptr;
PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData = nullptr;
PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData = nullptr;
PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer = nullptr;
PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer = nullptr;
PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect = nullptr;
PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect = nullptr;
PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv = nullptr;
PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex = nullptr;
PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName = nullptr;
PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv = nullptr;
PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation = nullptr;
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex = nullptr;
PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding = nullptr;
PFNGLTEXBUFFERRANGEPROC glTexBufferRange = nullptr;
PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultisample = nullptr;
PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage3DMultisample = nullptr;
PFNGLTEXTUREVIEWPROC glTextureView = nullptr;
PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer = nullptr;
PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat = nullptr;
PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat = nullptr;
PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat = nullptr;
PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding = nullptr;
PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor = nullptr;
PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl = nullptr;
PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert = nullptr;
PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback = nullptr;
PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog = nullptr;
PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup = nullptr;
PFNGLPOPDEBUGGROUPPROC glPopDebugGroup = nullptr;
PFNGLOBJECTLABELPROC glObjectLabel = nullptr;
PFNGLGETOBJECTLABELPROC glGetObjectLabel = nullptr;
PFNGLOBJECTPTRLABELPROC glObjectPtrLabel = nullptr;
PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel = nullptr;
// GL_VERSION_4_4
PFNGLBUFFERSTORAGEPROC glBufferStorage = nullptr;
PFNGLCLEARTEXIMAGEPROC glClearTexImage = nullptr;
PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage = nullptr;
PFNGLBINDBUFFERSBASEPROC glBindBuffersBase = nullptr;
PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange = nullptr;
PFNGLBINDTEXTURESPROC glBindTextures = nullptr;
PFNGLBINDSAMPLERSPROC glBindSamplers = nullptr;
PFNGLBINDIMAGETEXTURESPROC glBindImageTextures = nullptr;
PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers = nullptr;
// GL_VERSION_4_5
PFNGLCLIPCONTROLPROC glClipControl = nullptr;
PFNGLCREATETRANSFORMFEEDBACKSPROC glCreateTransformFeedbacks = nullptr;
PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glTransformFeedbackBufferBase = nullptr;
PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glTransformFeedbackBufferRange = nullptr;
PFNGLGETTRANSFORMFEEDBACKIVPROC glGetTransformFeedbackiv = nullptr;
PFNGLGETTRANSFORMFEEDBACKI_VPROC glGetTransformFeedbacki_v = nullptr;
PFNGLGETTRANSFORMFEEDBACKI64_VPROC glGetTransformFeedbacki64_v = nullptr;
PFNGLCREATEBUFFERSPROC glCreateBuffers = nullptr;
PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage = nullptr;
PFNGLNAMEDBUFFERDATAPROC glNamedBufferData = nullptr;
PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData = nullptr;
PFNGLCOPYNAMEDBUFFERSUBDATAPROC glCopyNamedBufferSubData = nullptr;
PFNGLCLEARNAMEDBUFFERDATAPROC glClearNamedBufferData = nullptr;
PFNGLCLEARNAMEDBUFFERSUBDATAPROC glClearNamedBufferSubData = nullptr;
PFNGLMAPNAMEDBUFFERPROC glMapNamedBuffer = nullptr;
PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange = nullptr;
PFNGLUNMAPNAMEDBUFFERPROC glUnmapNamedBuffer = nullptr;
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRange = nullptr;
PFNGLGETNAMEDBUFFERPARAMETERIVPROC glGetNamedBufferParameteriv = nullptr;
PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glGetNamedBufferParameteri64v = nullptr;
PFNGLGETNAMEDBUFFERPOINTERVPROC glGetNamedBufferPointerv = nullptr;
PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData = nullptr;
PFNGLCREATEFRAMEBUFFERSPROC glCreateFramebuffers = nullptr;
PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer = nullptr;
PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glNamedFramebufferParameteri = nullptr;
PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture = nullptr;
PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glNamedFramebufferTextureLayer = nullptr;
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glNamedFramebufferDrawBuffer = nullptr;
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glNamedFramebufferDrawBuffers = nullptr;
PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glNamedFramebufferReadBuffer = nullptr;
PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glInvalidateNamedFramebufferData = nullptr;
PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glInvalidateNamedFramebufferSubData = nullptr;
PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glClearNamedFramebufferiv = nullptr;
PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glClearNamedFramebufferuiv = nullptr;
PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glClearNamedFramebufferfv = nullptr;
PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glClearNamedFramebufferfi = nullptr;
PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer = nullptr;
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus = nullptr;
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv = nullptr;
PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv = nullptr;
PFNGLCREATERENDERBUFFERSPROC glCreateRenderbuffers = nullptr;
PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage = nullptr;
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample = nullptr;
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv = nullptr;
PFNGLCREATETEXTURESPROC glCreateTextures = nullptr;
PFNGLTEXTUREBUFFERPROC glTextureBuffer = nullptr;
PFNGLTEXTUREBUFFERRANGEPROC glTextureBufferRange = nullptr;
PFNGLTEXTURESTORAGE1DPROC glTextureStorage1D = nullptr;
PFNGLTEXTURESTORAGE2DPROC glTextureStorage2D = nullptr;
PFNGLTEXTURESTORAGE3DPROC glTextureStorage3D = nullptr;
PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glTextureStorage2DMultisample = nullptr;
PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glTextureStorage3DMultisample = nullptr;
PFNGLTEXTURESUBIMAGE1DPROC glTextureSubImage1D = nullptr;
PFNGLTEXTURESUBIMAGE2DPROC glTextureSubImage2D = nullptr;
PFNGLTEXTURESUBIMAGE3DPROC glTextureSubImage3D = nullptr;
PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glCompressedTextureSubImage1D = nullptr;
PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glCompressedTextureSubImage2D = nullptr;
PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glCompressedTextureSubImage3D = nullptr;
PFNGLCOPYTEXTURESUBIMAGE1DPROC glCopyTextureSubImage1D = nullptr;
PFNGLCOPYTEXTURESUBIMAGE2DPROC glCopyTextureSubImage2D = nullptr;
PFNGLCOPYTEXTURESUBIMAGE3DPROC glCopyTextureSubImage3D = nullptr;
PFNGLTEXTUREPARAMETERFPROC glTextureParameterf = nullptr;
PFNGLTEXTUREPARAMETERFVPROC glTextureParameterfv = nullptr;
PFNGLTEXTUREPARAMETERIPROC glTextureParameteri = nullptr;
PFNGLTEXTUREPARAMETERIIVPROC glTextureParameterIiv = nullptr;
PFNGLTEXTUREPARAMETERIUIVPROC glTextureParameterIuiv = nullptr;
PFNGLTEXTUREPARAMETERIVPROC glTextureParameteriv = nullptr;
PFNGLGENERATETEXTUREMIPMAPPROC glGenerateTextureMipmap = nullptr;
PFNGLBINDTEXTUREUNITPROC glBindTextureUnit = nullptr;
PFNGLGETTEXTUREIMAGEPROC glGetTextureImage = nullptr;
PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glGetCompressedTextureImage = nullptr;
PFNGLGETTEXTURELEVELPARAMETERFVPROC glGetTextureLevelParameterfv = nullptr;
PFNGLGETTEXTURELEVELPARAMETERIVPROC glGetTextureLevelParameteriv = nullptr;
PFNGLGETTEXTUREPARAMETERFVPROC glGetTextureParameterfv = nullptr;
PFNGLGETTEXTUREPARAMETERIIVPROC glGetTextureParameterIiv = nullptr;
PFNGLGETTEXTUREPARAMETERIUIVPROC glGetTextureParameterIuiv = nullptr;
PFNGLGETTEXTUREPARAMETERIVPROC glGetTextureParameteriv = nullptr;
PFNGLCREATEVERTEXARRAYSPROC glCreateVertexArrays = nullptr;
PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttrib = nullptr;
PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttrib = nullptr;
PFNGLVERTEXARRAYELEMENTBUFFERPROC glVertexArrayElementBuffer = nullptr;
PFNGLVERTEXARRAYVERTEXBUFFERPROC glVertexArrayVertexBuffer = nullptr;
PFNGLVERTEXARRAYVERTEXBUFFERSPROC glVertexArrayVertexBuffers = nullptr;
PFNGLVERTEXARRAYATTRIBBINDINGPROC glVertexArrayAttribBinding = nullptr;
PFNGLVERTEXARRAYATTRIBFORMATPROC glVertexArrayAttribFormat = nullptr;
PFNGLVERTEXARRAYATTRIBIFORMATPROC glVertexArrayAttribIFormat = nullptr;
PFNGLVERTEXARRAYATTRIBLFORMATPROC glVertexArrayAttribLFormat = nullptr;
PFNGLVERTEXARRAYBINDINGDIVISORPROC glVertexArrayBindingDivisor = nullptr;
PFNGLGETVERTEXARRAYIVPROC glGetVertexArrayiv = nullptr;
PFNGLGETVERTEXARRAYINDEXEDIVPROC glGetVertexArrayIndexediv = nullptr;
PFNGLGETVERTEXARRAYINDEXED64IVPROC glGetVertexArrayIndexed64iv = nullptr;
PFNGLCREATESAMPLERSPROC glCreateSamplers = nullptr;
PFNGLCREATEPROGRAMPIPELINESPROC glCreateProgramPipelines = nullptr;
PFNGLCREATEQUERIESPROC glCreateQueries = nullptr;
PFNGLGETQUERYBUFFEROBJECTI64VPROC glGetQueryBufferObjecti64v = nullptr;
PFNGLGETQUERYBUFFEROBJECTIVPROC glGetQueryBufferObjectiv = nullptr;
PFNGLGETQUERYBUFFEROBJECTUI64VPROC glGetQueryBufferObjectui64v = nullptr;
PFNGLGETQUERYBUFFEROBJECTUIVPROC glGetQueryBufferObjectuiv = nullptr;
PFNGLMEMORYBARRIERBYREGIONPROC glMemoryBarrierByRegion = nullptr;
PFNGLGETTEXTURESUBIMAGEPROC glGetTextureSubImage = nullptr;
PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glGetCompressedTextureSubImage = nullptr;
PFNGLGETGRAPHICSRESETSTATUSPROC glGetGraphicsResetStatus = nullptr;
PFNGLGETNCOMPRESSEDTEXIMAGEPROC glGetnCompressedTexImage = nullptr;
PFNGLGETNTEXIMAGEPROC glGetnTexImage = nullptr;
PFNGLGETNUNIFORMDVPROC glGetnUniformdv = nullptr;
PFNGLGETNUNIFORMFVPROC glGetnUniformfv = nullptr;
PFNGLGETNUNIFORMIVPROC glGetnUniformiv = nullptr;
PFNGLGETNUNIFORMUIVPROC glGetnUniformuiv = nullptr;
PFNGLREADNPIXELSPROC glReadnPixels = nullptr;
PFNGLGETNMAPDVPROC glGetnMapdv = nullptr;
PFNGLGETNMAPFVPROC glGetnMapfv = nullptr;
PFNGLGETNMAPIVPROC glGetnMapiv = nullptr;
PFNGLGETNPIXELMAPFVPROC glGetnPixelMapfv = nullptr;
PFNGLGETNPIXELMAPUIVPROC glGetnPixelMapuiv = nullptr;
PFNGLGETNPIXELMAPUSVPROC glGetnPixelMapusv = nullptr;
PFNGLGETNPOLYGONSTIPPLEPROC glGetnPolygonStipple = nullptr;
PFNGLGETNCOLORTABLEPROC glGetnColorTable = nullptr;
PFNGLGETNCONVOLUTIONFILTERPROC glGetnConvolutionFilter = nullptr;
PFNGLGETNSEPARABLEFILTERPROC glGetnSeparableFilter = nullptr;
PFNGLGETNHISTOGRAMPROC glGetnHistogram = nullptr;
PFNGLGETNMINMAXPROC glGetnMinmax = nullptr;
PFNGLTEXTUREBARRIERPROC glTextureBarrier = nullptr;
// GL_VERSION_4_6
PFNGLSPECIALIZESHADERPROC glSpecializeShader = nullptr;
PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount = nullptr;
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount = nullptr;
PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp = nullptr;


void glfnlib_init_GL_VERSION_1_2(PFN_loadfunc_gl load) {
	glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)load("glDrawRangeElements");
	if (!glDrawRangeElements) { print_msg("glDrawRangeElements not loaded"); }
	glTexImage3D = (PFNGLTEXIMAGE3DPROC)load("glTexImage3D");
	if (!glTexImage3D) { print_msg("glTexImage3D not loaded"); }
	glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)load("glTexSubImage3D");
	if (!glTexSubImage3D) { print_msg("glTexSubImage3D not loaded"); }
	glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)load("glCopyTexSubImage3D");
	if (!glCopyTexSubImage3D) { print_msg("glCopyTexSubImage3D not loaded"); }
}


void glfnlib_init_GL_VERSION_1_3(PFN_loadfunc_gl load) {
	glActiveTexture = (PFNGLACTIVETEXTUREPROC)load("glActiveTexture");
	if (!glActiveTexture) { print_msg("glActiveTexture not loaded"); }
	glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)load("glSampleCoverage");
	if (!glSampleCoverage) { print_msg("glSampleCoverage not loaded"); }
	glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)load("glCompressedTexImage3D");
	if (!glCompressedTexImage3D) { print_msg("glCompressedTexImage3D not loaded"); }
	glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)load("glCompressedTexImage2D");
	if (!glCompressedTexImage2D) { print_msg("glCompressedTexImage2D not loaded"); }
	glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)load("glCompressedTexImage1D");
	if (!glCompressedTexImage1D) { print_msg("glCompressedTexImage1D not loaded"); }
	glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)load("glCompressedTexSubImage3D");
	if (!glCompressedTexSubImage3D) { print_msg("glCompressedTexSubImage3D not loaded"); }
	glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)load("glCompressedTexSubImage2D");
	if (!glCompressedTexSubImage2D) { print_msg("glCompressedTexSubImage2D not loaded"); }
	glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)load("glCompressedTexSubImage1D");
	if (!glCompressedTexSubImage1D) { print_msg("glCompressedTexSubImage1D not loaded"); }
	glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)load("glGetCompressedTexImage");
	if (!glGetCompressedTexImage) { print_msg("glGetCompressedTexImage not loaded"); }
	glClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC)load("glClientActiveTexture");
	if (!glClientActiveTexture) { print_msg("glClientActiveTexture not loaded"); }
	glMultiTexCoord1d = (PFNGLMULTITEXCOORD1DPROC)load("glMultiTexCoord1d");
	if (!glMultiTexCoord1d) { print_msg("glMultiTexCoord1d not loaded"); }
	glMultiTexCoord1dv = (PFNGLMULTITEXCOORD1DVPROC)load("glMultiTexCoord1dv");
	if (!glMultiTexCoord1dv) { print_msg("glMultiTexCoord1dv not loaded"); }
	glMultiTexCoord1f = (PFNGLMULTITEXCOORD1FPROC)load("glMultiTexCoord1f");
	if (!glMultiTexCoord1f) { print_msg("glMultiTexCoord1f not loaded"); }
	glMultiTexCoord1fv = (PFNGLMULTITEXCOORD1FVPROC)load("glMultiTexCoord1fv");
	if (!glMultiTexCoord1fv) { print_msg("glMultiTexCoord1fv not loaded"); }
	glMultiTexCoord1i = (PFNGLMULTITEXCOORD1IPROC)load("glMultiTexCoord1i");
	if (!glMultiTexCoord1i) { print_msg("glMultiTexCoord1i not loaded"); }
	glMultiTexCoord1iv = (PFNGLMULTITEXCOORD1IVPROC)load("glMultiTexCoord1iv");
	if (!glMultiTexCoord1iv) { print_msg("glMultiTexCoord1iv not loaded"); }
	glMultiTexCoord1s = (PFNGLMULTITEXCOORD1SPROC)load("glMultiTexCoord1s");
	if (!glMultiTexCoord1s) { print_msg("glMultiTexCoord1s not loaded"); }
	glMultiTexCoord1sv = (PFNGLMULTITEXCOORD1SVPROC)load("glMultiTexCoord1sv");
	if (!glMultiTexCoord1sv) { print_msg("glMultiTexCoord1sv not loaded"); }
	glMultiTexCoord2d = (PFNGLMULTITEXCOORD2DPROC)load("glMultiTexCoord2d");
	if (!glMultiTexCoord2d) { print_msg("glMultiTexCoord2d not loaded"); }
	glMultiTexCoord2dv = (PFNGLMULTITEXCOORD2DVPROC)load("glMultiTexCoord2dv");
	if (!glMultiTexCoord2dv) { print_msg("glMultiTexCoord2dv not loaded"); }
	glMultiTexCoord2f = (PFNGLMULTITEXCOORD2FPROC)load("glMultiTexCoord2f");
	if (!glMultiTexCoord2f) { print_msg("glMultiTexCoord2f not loaded"); }
	glMultiTexCoord2fv = (PFNGLMULTITEXCOORD2FVPROC)load("glMultiTexCoord2fv");
	if (!glMultiTexCoord2fv) { print_msg("glMultiTexCoord2fv not loaded"); }
	glMultiTexCoord2i = (PFNGLMULTITEXCOORD2IPROC)load("glMultiTexCoord2i");
	if (!glMultiTexCoord2i) { print_msg("glMultiTexCoord2i not loaded"); }
	glMultiTexCoord2iv = (PFNGLMULTITEXCOORD2IVPROC)load("glMultiTexCoord2iv");
	if (!glMultiTexCoord2iv) { print_msg("glMultiTexCoord2iv not loaded"); }
	glMultiTexCoord2s = (PFNGLMULTITEXCOORD2SPROC)load("glMultiTexCoord2s");
	if (!glMultiTexCoord2s) { print_msg("glMultiTexCoord2s not loaded"); }
	glMultiTexCoord2sv = (PFNGLMULTITEXCOORD2SVPROC)load("glMultiTexCoord2sv");
	if (!glMultiTexCoord2sv) { print_msg("glMultiTexCoord2sv not loaded"); }
	glMultiTexCoord3d = (PFNGLMULTITEXCOORD3DPROC)load("glMultiTexCoord3d");
	if (!glMultiTexCoord3d) { print_msg("glMultiTexCoord3d not loaded"); }
	glMultiTexCoord3dv = (PFNGLMULTITEXCOORD3DVPROC)load("glMultiTexCoord3dv");
	if (!glMultiTexCoord3dv) { print_msg("glMultiTexCoord3dv not loaded"); }
	glMultiTexCoord3f = (PFNGLMULTITEXCOORD3FPROC)load("glMultiTexCoord3f");
	if (!glMultiTexCoord3f) { print_msg("glMultiTexCoord3f not loaded"); }
	glMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FVPROC)load("glMultiTexCoord3fv");
	if (!glMultiTexCoord3fv) { print_msg("glMultiTexCoord3fv not loaded"); }
	glMultiTexCoord3i = (PFNGLMULTITEXCOORD3IPROC)load("glMultiTexCoord3i");
	if (!glMultiTexCoord3i) { print_msg("glMultiTexCoord3i not loaded"); }
	glMultiTexCoord3iv = (PFNGLMULTITEXCOORD3IVPROC)load("glMultiTexCoord3iv");
	if (!glMultiTexCoord3iv) { print_msg("glMultiTexCoord3iv not loaded"); }
	glMultiTexCoord3s = (PFNGLMULTITEXCOORD3SPROC)load("glMultiTexCoord3s");
	if (!glMultiTexCoord3s) { print_msg("glMultiTexCoord3s not loaded"); }
	glMultiTexCoord3sv = (PFNGLMULTITEXCOORD3SVPROC)load("glMultiTexCoord3sv");
	if (!glMultiTexCoord3sv) { print_msg("glMultiTexCoord3sv not loaded"); }
	glMultiTexCoord4d = (PFNGLMULTITEXCOORD4DPROC)load("glMultiTexCoord4d");
	if (!glMultiTexCoord4d) { print_msg("glMultiTexCoord4d not loaded"); }
	glMultiTexCoord4dv = (PFNGLMULTITEXCOORD4DVPROC)load("glMultiTexCoord4dv");
	if (!glMultiTexCoord4dv) { print_msg("glMultiTexCoord4dv not loaded"); }
	glMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC)load("glMultiTexCoord4f");
	if (!glMultiTexCoord4f) { print_msg("glMultiTexCoord4f not loaded"); }
	glMultiTexCoord4fv = (PFNGLMULTITEXCOORD4FVPROC)load("glMultiTexCoord4fv");
	if (!glMultiTexCoord4fv) { print_msg("glMultiTexCoord4fv not loaded"); }
	glMultiTexCoord4i = (PFNGLMULTITEXCOORD4IPROC)load("glMultiTexCoord4i");
	if (!glMultiTexCoord4i) { print_msg("glMultiTexCoord4i not loaded"); }
	glMultiTexCoord4iv = (PFNGLMULTITEXCOORD4IVPROC)load("glMultiTexCoord4iv");
	if (!glMultiTexCoord4iv) { print_msg("glMultiTexCoord4iv not loaded"); }
	glMultiTexCoord4s = (PFNGLMULTITEXCOORD4SPROC)load("glMultiTexCoord4s");
	if (!glMultiTexCoord4s) { print_msg("glMultiTexCoord4s not loaded"); }
	glMultiTexCoord4sv = (PFNGLMULTITEXCOORD4SVPROC)load("glMultiTexCoord4sv");
	if (!glMultiTexCoord4sv) { print_msg("glMultiTexCoord4sv not loaded"); }
	glLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXFPROC)load("glLoadTransposeMatrixf");
	if (!glLoadTransposeMatrixf) { print_msg("glLoadTransposeMatrixf not loaded"); }
	glLoadTransposeMatrixd = (PFNGLLOADTRANSPOSEMATRIXDPROC)load("glLoadTransposeMatrixd");
	if (!glLoadTransposeMatrixd) { print_msg("glLoadTransposeMatrixd not loaded"); }
	glMultTransposeMatrixf = (PFNGLMULTTRANSPOSEMATRIXFPROC)load("glMultTransposeMatrixf");
	if (!glMultTransposeMatrixf) { print_msg("glMultTransposeMatrixf not loaded"); }
	glMultTransposeMatrixd = (PFNGLMULTTRANSPOSEMATRIXDPROC)load("glMultTransposeMatrixd");
	if (!glMultTransposeMatrixd) { print_msg("glMultTransposeMatrixd not loaded"); }
}


void glfnlib_init_GL_VERSION_1_4(PFN_loadfunc_gl load) {
	glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)load("glBlendFuncSeparate");
	if (!glBlendFuncSeparate) { print_msg("glBlendFuncSeparate not loaded"); }
	glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)load("glMultiDrawArrays");
	if (!glMultiDrawArrays) { print_msg("glMultiDrawArrays not loaded"); }
	glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)load("glMultiDrawElements");
	if (!glMultiDrawElements) { print_msg("glMultiDrawElements not loaded"); }
	glPointParameterf = (PFNGLPOINTPARAMETERFPROC)load("glPointParameterf");
	if (!glPointParameterf) { print_msg("glPointParameterf not loaded"); }
	glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)load("glPointParameterfv");
	if (!glPointParameterfv) { print_msg("glPointParameterfv not loaded"); }
	glPointParameteri = (PFNGLPOINTPARAMETERIPROC)load("glPointParameteri");
	if (!glPointParameteri) { print_msg("glPointParameteri not loaded"); }
	glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC)load("glPointParameteriv");
	if (!glPointParameteriv) { print_msg("glPointParameteriv not loaded"); }
	glFogCoordf = (PFNGLFOGCOORDFPROC)load("glFogCoordf");
	if (!glFogCoordf) { print_msg("glFogCoordf not loaded"); }
	glFogCoordfv = (PFNGLFOGCOORDFVPROC)load("glFogCoordfv");
	if (!glFogCoordfv) { print_msg("glFogCoordfv not loaded"); }
	glFogCoordd = (PFNGLFOGCOORDDPROC)load("glFogCoordd");
	if (!glFogCoordd) { print_msg("glFogCoordd not loaded"); }
	glFogCoorddv = (PFNGLFOGCOORDDVPROC)load("glFogCoorddv");
	if (!glFogCoorddv) { print_msg("glFogCoorddv not loaded"); }
	glFogCoordPointer = (PFNGLFOGCOORDPOINTERPROC)load("glFogCoordPointer");
	if (!glFogCoordPointer) { print_msg("glFogCoordPointer not loaded"); }
	glSecondaryColor3b = (PFNGLSECONDARYCOLOR3BPROC)load("glSecondaryColor3b");
	if (!glSecondaryColor3b) { print_msg("glSecondaryColor3b not loaded"); }
	glSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BVPROC)load("glSecondaryColor3bv");
	if (!glSecondaryColor3bv) { print_msg("glSecondaryColor3bv not loaded"); }
	glSecondaryColor3d = (PFNGLSECONDARYCOLOR3DPROC)load("glSecondaryColor3d");
	if (!glSecondaryColor3d) { print_msg("glSecondaryColor3d not loaded"); }
	glSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DVPROC)load("glSecondaryColor3dv");
	if (!glSecondaryColor3dv) { print_msg("glSecondaryColor3dv not loaded"); }
	glSecondaryColor3f = (PFNGLSECONDARYCOLOR3FPROC)load("glSecondaryColor3f");
	if (!glSecondaryColor3f) { print_msg("glSecondaryColor3f not loaded"); }
	glSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC)load("glSecondaryColor3fv");
	if (!glSecondaryColor3fv) { print_msg("glSecondaryColor3fv not loaded"); }
	glSecondaryColor3i = (PFNGLSECONDARYCOLOR3IPROC)load("glSecondaryColor3i");
	if (!glSecondaryColor3i) { print_msg("glSecondaryColor3i not loaded"); }
	glSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IVPROC)load("glSecondaryColor3iv");
	if (!glSecondaryColor3iv) { print_msg("glSecondaryColor3iv not loaded"); }
	glSecondaryColor3s = (PFNGLSECONDARYCOLOR3SPROC)load("glSecondaryColor3s");
	if (!glSecondaryColor3s) { print_msg("glSecondaryColor3s not loaded"); }
	glSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SVPROC)load("glSecondaryColor3sv");
	if (!glSecondaryColor3sv) { print_msg("glSecondaryColor3sv not loaded"); }
	glSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UBPROC)load("glSecondaryColor3ub");
	if (!glSecondaryColor3ub) { print_msg("glSecondaryColor3ub not loaded"); }
	glSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBVPROC)load("glSecondaryColor3ubv");
	if (!glSecondaryColor3ubv) { print_msg("glSecondaryColor3ubv not loaded"); }
	glSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UIPROC)load("glSecondaryColor3ui");
	if (!glSecondaryColor3ui) { print_msg("glSecondaryColor3ui not loaded"); }
	glSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIVPROC)load("glSecondaryColor3uiv");
	if (!glSecondaryColor3uiv) { print_msg("glSecondaryColor3uiv not loaded"); }
	glSecondaryColor3us = (PFNGLSECONDARYCOLOR3USPROC)load("glSecondaryColor3us");
	if (!glSecondaryColor3us) { print_msg("glSecondaryColor3us not loaded"); }
	glSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USVPROC)load("glSecondaryColor3usv");
	if (!glSecondaryColor3usv) { print_msg("glSecondaryColor3usv not loaded"); }
	glSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTERPROC)load("glSecondaryColorPointer");
	if (!glSecondaryColorPointer) { print_msg("glSecondaryColorPointer not loaded"); }
	glWindowPos2d = (PFNGLWINDOWPOS2DPROC)load("glWindowPos2d");
	if (!glWindowPos2d) { print_msg("glWindowPos2d not loaded"); }
	glWindowPos2dv = (PFNGLWINDOWPOS2DVPROC)load("glWindowPos2dv");
	if (!glWindowPos2dv) { print_msg("glWindowPos2dv not loaded"); }
	glWindowPos2f = (PFNGLWINDOWPOS2FPROC)load("glWindowPos2f");
	if (!glWindowPos2f) { print_msg("glWindowPos2f not loaded"); }
	glWindowPos2fv = (PFNGLWINDOWPOS2FVPROC)load("glWindowPos2fv");
	if (!glWindowPos2fv) { print_msg("glWindowPos2fv not loaded"); }
	glWindowPos2i = (PFNGLWINDOWPOS2IPROC)load("glWindowPos2i");
	if (!glWindowPos2i) { print_msg("glWindowPos2i not loaded"); }
	glWindowPos2iv = (PFNGLWINDOWPOS2IVPROC)load("glWindowPos2iv");
	if (!glWindowPos2iv) { print_msg("glWindowPos2iv not loaded"); }
	glWindowPos2s = (PFNGLWINDOWPOS2SPROC)load("glWindowPos2s");
	if (!glWindowPos2s) { print_msg("glWindowPos2s not loaded"); }
	glWindowPos2sv = (PFNGLWINDOWPOS2SVPROC)load("glWindowPos2sv");
	if (!glWindowPos2sv) { print_msg("glWindowPos2sv not loaded"); }
	glWindowPos3d = (PFNGLWINDOWPOS3DPROC)load("glWindowPos3d");
	if (!glWindowPos3d) { print_msg("glWindowPos3d not loaded"); }
	glWindowPos3dv = (PFNGLWINDOWPOS3DVPROC)load("glWindowPos3dv");
	if (!glWindowPos3dv) { print_msg("glWindowPos3dv not loaded"); }
	glWindowPos3f = (PFNGLWINDOWPOS3FPROC)load("glWindowPos3f");
	if (!glWindowPos3f) { print_msg("glWindowPos3f not loaded"); }
	glWindowPos3fv = (PFNGLWINDOWPOS3FVPROC)load("glWindowPos3fv");
	if (!glWindowPos3fv) { print_msg("glWindowPos3fv not loaded"); }
	glWindowPos3i = (PFNGLWINDOWPOS3IPROC)load("glWindowPos3i");
	if (!glWindowPos3i) { print_msg("glWindowPos3i not loaded"); }
	glWindowPos3iv = (PFNGLWINDOWPOS3IVPROC)load("glWindowPos3iv");
	if (!glWindowPos3iv) { print_msg("glWindowPos3iv not loaded"); }
	glWindowPos3s = (PFNGLWINDOWPOS3SPROC)load("glWindowPos3s");
	if (!glWindowPos3s) { print_msg("glWindowPos3s not loaded"); }
	glWindowPos3sv = (PFNGLWINDOWPOS3SVPROC)load("glWindowPos3sv");
	if (!glWindowPos3sv) { print_msg("glWindowPos3sv not loaded"); }
	glBlendColor = (PFNGLBLENDCOLORPROC)load("glBlendColor");
	if (!glBlendColor) { print_msg("glBlendColor not loaded"); }
	glBlendEquation = (PFNGLBLENDEQUATIONPROC)load("glBlendEquation");
	if (!glBlendEquation) { print_msg("glBlendEquation not loaded"); }
}


void glfnlib_init_GL_VERSION_1_5(PFN_loadfunc_gl load) {
	glGenQueries = (PFNGLGENQUERIESPROC)load("glGenQueries");
	if (!glGenQueries) { print_msg("glGenQueries not loaded"); }
	glDeleteQueries = (PFNGLDELETEQUERIESPROC)load("glDeleteQueries");
	if (!glDeleteQueries) { print_msg("glDeleteQueries not loaded"); }
	glIsQuery = (PFNGLISQUERYPROC)load("glIsQuery");
	if (!glIsQuery) { print_msg("glIsQuery not loaded"); }
	glBeginQuery = (PFNGLBEGINQUERYPROC)load("glBeginQuery");
	if (!glBeginQuery) { print_msg("glBeginQuery not loaded"); }
	glEndQuery = (PFNGLENDQUERYPROC)load("glEndQuery");
	if (!glEndQuery) { print_msg("glEndQuery not loaded"); }
	glGetQueryiv = (PFNGLGETQUERYIVPROC)load("glGetQueryiv");
	if (!glGetQueryiv) { print_msg("glGetQueryiv not loaded"); }
	glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)load("glGetQueryObjectiv");
	if (!glGetQueryObjectiv) { print_msg("glGetQueryObjectiv not loaded"); }
	glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)load("glGetQueryObjectuiv");
	if (!glGetQueryObjectuiv) { print_msg("glGetQueryObjectuiv not loaded"); }
	glBindBuffer = (PFNGLBINDBUFFERPROC)load("glBindBuffer");
	if (!glBindBuffer) { print_msg("glBindBuffer not loaded"); }
	glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)load("glDeleteBuffers");
	if (!glDeleteBuffers) { print_msg("glDeleteBuffers not loaded"); }
	glGenBuffers = (PFNGLGENBUFFERSPROC)load("glGenBuffers");
	if (!glGenBuffers) { print_msg("glGenBuffers not loaded"); }
	glIsBuffer = (PFNGLISBUFFERPROC)load("glIsBuffer");
	if (!glIsBuffer) { print_msg("glIsBuffer not loaded"); }
	glBufferData = (PFNGLBUFFERDATAPROC)load("glBufferData");
	if (!glBufferData) { print_msg("glBufferData not loaded"); }
	glBufferSubData = (PFNGLBUFFERSUBDATAPROC)load("glBufferSubData");
	if (!glBufferSubData) { print_msg("glBufferSubData not loaded"); }
	glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)load("glGetBufferSubData");
	if (!glGetBufferSubData) { print_msg("glGetBufferSubData not loaded"); }
	glMapBuffer = (PFNGLMAPBUFFERPROC)load("glMapBuffer");
	if (!glMapBuffer) { print_msg("glMapBuffer not loaded"); }
	glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)load("glUnmapBuffer");
	if (!glUnmapBuffer) { print_msg("glUnmapBuffer not loaded"); }
	glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)load("glGetBufferParameteriv");
	if (!glGetBufferParameteriv) { print_msg("glGetBufferParameteriv not loaded"); }
	glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)load("glGetBufferPointerv");
	if (!glGetBufferPointerv) { print_msg("glGetBufferPointerv not loaded"); }
}


void glfnlib_init_GL_VERSION_2_0(PFN_loadfunc_gl load) {
	glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)load("glBlendEquationSeparate");
	if (!glBlendEquationSeparate) { print_msg("glBlendEquationSeparate not loaded"); }
	glDrawBuffers = (PFNGLDRAWBUFFERSPROC)load("glDrawBuffers");
	if (!glDrawBuffers) { print_msg("glDrawBuffers not loaded"); }
	glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)load("glStencilOpSeparate");
	if (!glStencilOpSeparate) { print_msg("glStencilOpSeparate not loaded"); }
	glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)load("glStencilFuncSeparate");
	if (!glStencilFuncSeparate) { print_msg("glStencilFuncSeparate not loaded"); }
	glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)load("glStencilMaskSeparate");
	if (!glStencilMaskSeparate) { print_msg("glStencilMaskSeparate not loaded"); }
	glAttachShader = (PFNGLATTACHSHADERPROC)load("glAttachShader");
	if (!glAttachShader) { print_msg("glAttachShader not loaded"); }
	glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)load("glBindAttribLocation");
	if (!glBindAttribLocation) { print_msg("glBindAttribLocation not loaded"); }
	glCompileShader = (PFNGLCOMPILESHADERPROC)load("glCompileShader");
	if (!glCompileShader) { print_msg("glCompileShader not loaded"); }
	glCreateProgram = (PFNGLCREATEPROGRAMPROC)load("glCreateProgram");
	if (!glCreateProgram) { print_msg("glCreateProgram not loaded"); }
	glCreateShader = (PFNGLCREATESHADERPROC)load("glCreateShader");
	if (!glCreateShader) { print_msg("glCreateShader not loaded"); }
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC)load("glDeleteProgram");
	if (!glDeleteProgram) { print_msg("glDeleteProgram not loaded"); }
	glDeleteShader = (PFNGLDELETESHADERPROC)load("glDeleteShader");
	if (!glDeleteShader) { print_msg("glDeleteShader not loaded"); }
	glDetachShader = (PFNGLDETACHSHADERPROC)load("glDetachShader");
	if (!glDetachShader) { print_msg("glDetachShader not loaded"); }
	glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)load("glDisableVertexAttribArray");
	if (!glDisableVertexAttribArray) { print_msg("glDisableVertexAttribArray not loaded"); }
	glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)load("glEnableVertexAttribArray");
	if (!glEnableVertexAttribArray) { print_msg("glEnableVertexAttribArray not loaded"); }
	glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)load("glGetActiveAttrib");
	if (!glGetActiveAttrib) { print_msg("glGetActiveAttrib not loaded"); }
	glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)load("glGetActiveUniform");
	if (!glGetActiveUniform) { print_msg("glGetActiveUniform not loaded"); }
	glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)load("glGetAttachedShaders");
	if (!glGetAttachedShaders) { print_msg("glGetAttachedShaders not loaded"); }
	glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)load("glGetAttribLocation");
	if (!glGetAttribLocation) { print_msg("glGetAttribLocation not loaded"); }
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)load("glGetProgramiv");
	if (!glGetProgramiv) { print_msg("glGetProgramiv not loaded"); }
	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)load("glGetProgramInfoLog");
	if (!glGetProgramInfoLog) { print_msg("glGetProgramInfoLog not loaded"); }
	glGetShaderiv = (PFNGLGETSHADERIVPROC)load("glGetShaderiv");
	if (!glGetShaderiv) { print_msg("glGetShaderiv not loaded"); }
	glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)load("glGetShaderInfoLog");
	if (!glGetShaderInfoLog) { print_msg("glGetShaderInfoLog not loaded"); }
	glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)load("glGetShaderSource");
	if (!glGetShaderSource) { print_msg("glGetShaderSource not loaded"); }
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)load("glGetUniformLocation");
	if (!glGetUniformLocation) { print_msg("glGetUniformLocation not loaded"); }
	glGetUniformfv = (PFNGLGETUNIFORMFVPROC)load("glGetUniformfv");
	if (!glGetUniformfv) { print_msg("glGetUniformfv not loaded"); }
	glGetUniformiv = (PFNGLGETUNIFORMIVPROC)load("glGetUniformiv");
	if (!glGetUniformiv) { print_msg("glGetUniformiv not loaded"); }
	glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)load("glGetVertexAttribdv");
	if (!glGetVertexAttribdv) { print_msg("glGetVertexAttribdv not loaded"); }
	glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)load("glGetVertexAttribfv");
	if (!glGetVertexAttribfv) { print_msg("glGetVertexAttribfv not loaded"); }
	glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)load("glGetVertexAttribiv");
	if (!glGetVertexAttribiv) { print_msg("glGetVertexAttribiv not loaded"); }
	glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)load("glGetVertexAttribPointerv");
	if (!glGetVertexAttribPointerv) { print_msg("glGetVertexAttribPointerv not loaded"); }
	glIsProgram = (PFNGLISPROGRAMPROC)load("glIsProgram");
	if (!glIsProgram) { print_msg("glIsProgram not loaded"); }
	glIsShader = (PFNGLISSHADERPROC)load("glIsShader");
	if (!glIsShader) { print_msg("glIsShader not loaded"); }
	glLinkProgram = (PFNGLLINKPROGRAMPROC)load("glLinkProgram");
	if (!glLinkProgram) { print_msg("glLinkProgram not loaded"); }
	glShaderSource = (PFNGLSHADERSOURCEPROC)load("glShaderSource");
	if (!glShaderSource) { print_msg("glShaderSource not loaded"); }
	glUseProgram = (PFNGLUSEPROGRAMPROC)load("glUseProgram");
	if (!glUseProgram) { print_msg("glUseProgram not loaded"); }
	glUniform1f = (PFNGLUNIFORM1FPROC)load("glUniform1f");
	if (!glUniform1f) { print_msg("glUniform1f not loaded"); }
	glUniform2f = (PFNGLUNIFORM2FPROC)load("glUniform2f");
	if (!glUniform2f) { print_msg("glUniform2f not loaded"); }
	glUniform3f = (PFNGLUNIFORM3FPROC)load("glUniform3f");
	if (!glUniform3f) { print_msg("glUniform3f not loaded"); }
	glUniform4f = (PFNGLUNIFORM4FPROC)load("glUniform4f");
	if (!glUniform4f) { print_msg("glUniform4f not loaded"); }
	glUniform1i = (PFNGLUNIFORM1IPROC)load("glUniform1i");
	if (!glUniform1i) { print_msg("glUniform1i not loaded"); }
	glUniform2i = (PFNGLUNIFORM2IPROC)load("glUniform2i");
	if (!glUniform2i) { print_msg("glUniform2i not loaded"); }
	glUniform3i = (PFNGLUNIFORM3IPROC)load("glUniform3i");
	if (!glUniform3i) { print_msg("glUniform3i not loaded"); }
	glUniform4i = (PFNGLUNIFORM4IPROC)load("glUniform4i");
	if (!glUniform4i) { print_msg("glUniform4i not loaded"); }
	glUniform1fv = (PFNGLUNIFORM1FVPROC)load("glUniform1fv");
	if (!glUniform1fv) { print_msg("glUniform1fv not loaded"); }
	glUniform2fv = (PFNGLUNIFORM2FVPROC)load("glUniform2fv");
	if (!glUniform2fv) { print_msg("glUniform2fv not loaded"); }
	glUniform3fv = (PFNGLUNIFORM3FVPROC)load("glUniform3fv");
	if (!glUniform3fv) { print_msg("glUniform3fv not loaded"); }
	glUniform4fv = (PFNGLUNIFORM4FVPROC)load("glUniform4fv");
	if (!glUniform4fv) { print_msg("glUniform4fv not loaded"); }
	glUniform1iv = (PFNGLUNIFORM1IVPROC)load("glUniform1iv");
	if (!glUniform1iv) { print_msg("glUniform1iv not loaded"); }
	glUniform2iv = (PFNGLUNIFORM2IVPROC)load("glUniform2iv");
	if (!glUniform2iv) { print_msg("glUniform2iv not loaded"); }
	glUniform3iv = (PFNGLUNIFORM3IVPROC)load("glUniform3iv");
	if (!glUniform3iv) { print_msg("glUniform3iv not loaded"); }
	glUniform4iv = (PFNGLUNIFORM4IVPROC)load("glUniform4iv");
	if (!glUniform4iv) { print_msg("glUniform4iv not loaded"); }
	glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)load("glUniformMatrix2fv");
	if (!glUniformMatrix2fv) { print_msg("glUniformMatrix2fv not loaded"); }
	glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)load("glUniformMatrix3fv");
	if (!glUniformMatrix3fv) { print_msg("glUniformMatrix3fv not loaded"); }
	glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)load("glUniformMatrix4fv");
	if (!glUniformMatrix4fv) { print_msg("glUniformMatrix4fv not loaded"); }
	glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)load("glValidateProgram");
	if (!glValidateProgram) { print_msg("glValidateProgram not loaded"); }
	glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)load("glVertexAttrib1d");
	if (!glVertexAttrib1d) { print_msg("glVertexAttrib1d not loaded"); }
	glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)load("glVertexAttrib1dv");
	if (!glVertexAttrib1dv) { print_msg("glVertexAttrib1dv not loaded"); }
	glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)load("glVertexAttrib1f");
	if (!glVertexAttrib1f) { print_msg("glVertexAttrib1f not loaded"); }
	glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)load("glVertexAttrib1fv");
	if (!glVertexAttrib1fv) { print_msg("glVertexAttrib1fv not loaded"); }
	glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)load("glVertexAttrib1s");
	if (!glVertexAttrib1s) { print_msg("glVertexAttrib1s not loaded"); }
	glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)load("glVertexAttrib1sv");
	if (!glVertexAttrib1sv) { print_msg("glVertexAttrib1sv not loaded"); }
	glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)load("glVertexAttrib2d");
	if (!glVertexAttrib2d) { print_msg("glVertexAttrib2d not loaded"); }
	glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)load("glVertexAttrib2dv");
	if (!glVertexAttrib2dv) { print_msg("glVertexAttrib2dv not loaded"); }
	glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)load("glVertexAttrib2f");
	if (!glVertexAttrib2f) { print_msg("glVertexAttrib2f not loaded"); }
	glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)load("glVertexAttrib2fv");
	if (!glVertexAttrib2fv) { print_msg("glVertexAttrib2fv not loaded"); }
	glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)load("glVertexAttrib2s");
	if (!glVertexAttrib2s) { print_msg("glVertexAttrib2s not loaded"); }
	glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)load("glVertexAttrib2sv");
	if (!glVertexAttrib2sv) { print_msg("glVertexAttrib2sv not loaded"); }
	glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)load("glVertexAttrib3d");
	if (!glVertexAttrib3d) { print_msg("glVertexAttrib3d not loaded"); }
	glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)load("glVertexAttrib3dv");
	if (!glVertexAttrib3dv) { print_msg("glVertexAttrib3dv not loaded"); }
	glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)load("glVertexAttrib3f");
	if (!glVertexAttrib3f) { print_msg("glVertexAttrib3f not loaded"); }
	glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)load("glVertexAttrib3fv");
	if (!glVertexAttrib3fv) { print_msg("glVertexAttrib3fv not loaded"); }
	glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)load("glVertexAttrib3s");
	if (!glVertexAttrib3s) { print_msg("glVertexAttrib3s not loaded"); }
	glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)load("glVertexAttrib3sv");
	if (!glVertexAttrib3sv) { print_msg("glVertexAttrib3sv not loaded"); }
	glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)load("glVertexAttrib4Nbv");
	if (!glVertexAttrib4Nbv) { print_msg("glVertexAttrib4Nbv not loaded"); }
	glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)load("glVertexAttrib4Niv");
	if (!glVertexAttrib4Niv) { print_msg("glVertexAttrib4Niv not loaded"); }
	glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)load("glVertexAttrib4Nsv");
	if (!glVertexAttrib4Nsv) { print_msg("glVertexAttrib4Nsv not loaded"); }
	glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)load("glVertexAttrib4Nub");
	if (!glVertexAttrib4Nub) { print_msg("glVertexAttrib4Nub not loaded"); }
	glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)load("glVertexAttrib4Nubv");
	if (!glVertexAttrib4Nubv) { print_msg("glVertexAttrib4Nubv not loaded"); }
	glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)load("glVertexAttrib4Nuiv");
	if (!glVertexAttrib4Nuiv) { print_msg("glVertexAttrib4Nuiv not loaded"); }
	glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)load("glVertexAttrib4Nusv");
	if (!glVertexAttrib4Nusv) { print_msg("glVertexAttrib4Nusv not loaded"); }
	glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)load("glVertexAttrib4bv");
	if (!glVertexAttrib4bv) { print_msg("glVertexAttrib4bv not loaded"); }
	glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)load("glVertexAttrib4d");
	if (!glVertexAttrib4d) { print_msg("glVertexAttrib4d not loaded"); }
	glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)load("glVertexAttrib4dv");
	if (!glVertexAttrib4dv) { print_msg("glVertexAttrib4dv not loaded"); }
	glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)load("glVertexAttrib4f");
	if (!glVertexAttrib4f) { print_msg("glVertexAttrib4f not loaded"); }
	glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)load("glVertexAttrib4fv");
	if (!glVertexAttrib4fv) { print_msg("glVertexAttrib4fv not loaded"); }
	glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)load("glVertexAttrib4iv");
	if (!glVertexAttrib4iv) { print_msg("glVertexAttrib4iv not loaded"); }
	glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)load("glVertexAttrib4s");
	if (!glVertexAttrib4s) { print_msg("glVertexAttrib4s not loaded"); }
	glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)load("glVertexAttrib4sv");
	if (!glVertexAttrib4sv) { print_msg("glVertexAttrib4sv not loaded"); }
	glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)load("glVertexAttrib4ubv");
	if (!glVertexAttrib4ubv) { print_msg("glVertexAttrib4ubv not loaded"); }
	glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)load("glVertexAttrib4uiv");
	if (!glVertexAttrib4uiv) { print_msg("glVertexAttrib4uiv not loaded"); }
	glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)load("glVertexAttrib4usv");
	if (!glVertexAttrib4usv) { print_msg("glVertexAttrib4usv not loaded"); }
	glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)load("glVertexAttribPointer");
	if (!glVertexAttribPointer) { print_msg("glVertexAttribPointer not loaded"); }
}


void glfnlib_init_GL_VERSION_2_1(PFN_loadfunc_gl load) {
	glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)load("glUniformMatrix2x3fv");
	if (!glUniformMatrix2x3fv) { print_msg("glUniformMatrix2x3fv not loaded"); }
	glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)load("glUniformMatrix3x2fv");
	if (!glUniformMatrix3x2fv) { print_msg("glUniformMatrix3x2fv not loaded"); }
	glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)load("glUniformMatrix2x4fv");
	if (!glUniformMatrix2x4fv) { print_msg("glUniformMatrix2x4fv not loaded"); }
	glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)load("glUniformMatrix4x2fv");
	if (!glUniformMatrix4x2fv) { print_msg("glUniformMatrix4x2fv not loaded"); }
	glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)load("glUniformMatrix3x4fv");
	if (!glUniformMatrix3x4fv) { print_msg("glUniformMatrix3x4fv not loaded"); }
	glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)load("glUniformMatrix4x3fv");
	if (!glUniformMatrix4x3fv) { print_msg("glUniformMatrix4x3fv not loaded"); }
}


void glfnlib_init_GL_VERSION_3_0(PFN_loadfunc_gl load) {
	glColorMaski = (PFNGLCOLORMASKIPROC)load("glColorMaski");
	if (!glColorMaski) { print_msg("glColorMaski not loaded"); }
	glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)load("glGetBooleani_v");
	if (!glGetBooleani_v) { print_msg("glGetBooleani_v not loaded"); }
	glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)load("glGetIntegeri_v");
	if (!glGetIntegeri_v) { print_msg("glGetIntegeri_v not loaded"); }
	glEnablei = (PFNGLENABLEIPROC)load("glEnablei");
	if (!glEnablei) { print_msg("glEnablei not loaded"); }
	glDisablei = (PFNGLDISABLEIPROC)load("glDisablei");
	if (!glDisablei) { print_msg("glDisablei not loaded"); }
	glIsEnabledi = (PFNGLISENABLEDIPROC)load("glIsEnabledi");
	if (!glIsEnabledi) { print_msg("glIsEnabledi not loaded"); }
	glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)load("glBeginTransformFeedback");
	if (!glBeginTransformFeedback) { print_msg("glBeginTransformFeedback not loaded"); }
	glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)load("glEndTransformFeedback");
	if (!glEndTransformFeedback) { print_msg("glEndTransformFeedback not loaded"); }
	glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)load("glBindBufferRange");
	if (!glBindBufferRange) { print_msg("glBindBufferRange not loaded"); }
	glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)load("glBindBufferBase");
	if (!glBindBufferBase) { print_msg("glBindBufferBase not loaded"); }
	glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)load("glTransformFeedbackVaryings");
	if (!glTransformFeedbackVaryings) { print_msg("glTransformFeedbackVaryings not loaded"); }
	glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)load("glGetTransformFeedbackVarying");
	if (!glGetTransformFeedbackVarying) { print_msg("glGetTransformFeedbackVarying not loaded"); }
	glClampColor = (PFNGLCLAMPCOLORPROC)load("glClampColor");
	if (!glClampColor) { print_msg("glClampColor not loaded"); }
	glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)load("glBeginConditionalRender");
	if (!glBeginConditionalRender) { print_msg("glBeginConditionalRender not loaded"); }
	glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)load("glEndConditionalRender");
	if (!glEndConditionalRender) { print_msg("glEndConditionalRender not loaded"); }
	glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)load("glVertexAttribIPointer");
	if (!glVertexAttribIPointer) { print_msg("glVertexAttribIPointer not loaded"); }
	glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)load("glGetVertexAttribIiv");
	if (!glGetVertexAttribIiv) { print_msg("glGetVertexAttribIiv not loaded"); }
	glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)load("glGetVertexAttribIuiv");
	if (!glGetVertexAttribIuiv) { print_msg("glGetVertexAttribIuiv not loaded"); }
	glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)load("glVertexAttribI1i");
	if (!glVertexAttribI1i) { print_msg("glVertexAttribI1i not loaded"); }
	glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)load("glVertexAttribI2i");
	if (!glVertexAttribI2i) { print_msg("glVertexAttribI2i not loaded"); }
	glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)load("glVertexAttribI3i");
	if (!glVertexAttribI3i) { print_msg("glVertexAttribI3i not loaded"); }
	glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)load("glVertexAttribI4i");
	if (!glVertexAttribI4i) { print_msg("glVertexAttribI4i not loaded"); }
	glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)load("glVertexAttribI1ui");
	if (!glVertexAttribI1ui) { print_msg("glVertexAttribI1ui not loaded"); }
	glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)load("glVertexAttribI2ui");
	if (!glVertexAttribI2ui) { print_msg("glVertexAttribI2ui not loaded"); }
	glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)load("glVertexAttribI3ui");
	if (!glVertexAttribI3ui) { print_msg("glVertexAttribI3ui not loaded"); }
	glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)load("glVertexAttribI4ui");
	if (!glVertexAttribI4ui) { print_msg("glVertexAttribI4ui not loaded"); }
	glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)load("glVertexAttribI1iv");
	if (!glVertexAttribI1iv) { print_msg("glVertexAttribI1iv not loaded"); }
	glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)load("glVertexAttribI2iv");
	if (!glVertexAttribI2iv) { print_msg("glVertexAttribI2iv not loaded"); }
	glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)load("glVertexAttribI3iv");
	if (!glVertexAttribI3iv) { print_msg("glVertexAttribI3iv not loaded"); }
	glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)load("glVertexAttribI4iv");
	if (!glVertexAttribI4iv) { print_msg("glVertexAttribI4iv not loaded"); }
	glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)load("glVertexAttribI1uiv");
	if (!glVertexAttribI1uiv) { print_msg("glVertexAttribI1uiv not loaded"); }
	glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)load("glVertexAttribI2uiv");
	if (!glVertexAttribI2uiv) { print_msg("glVertexAttribI2uiv not loaded"); }
	glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)load("glVertexAttribI3uiv");
	if (!glVertexAttribI3uiv) { print_msg("glVertexAttribI3uiv not loaded"); }
	glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)load("glVertexAttribI4uiv");
	if (!glVertexAttribI4uiv) { print_msg("glVertexAttribI4uiv not loaded"); }
	glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)load("glVertexAttribI4bv");
	if (!glVertexAttribI4bv) { print_msg("glVertexAttribI4bv not loaded"); }
	glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)load("glVertexAttribI4sv");
	if (!glVertexAttribI4sv) { print_msg("glVertexAttribI4sv not loaded"); }
	glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)load("glVertexAttribI4ubv");
	if (!glVertexAttribI4ubv) { print_msg("glVertexAttribI4ubv not loaded"); }
	glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)load("glVertexAttribI4usv");
	if (!glVertexAttribI4usv) { print_msg("glVertexAttribI4usv not loaded"); }
	glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)load("glGetUniformuiv");
	if (!glGetUniformuiv) { print_msg("glGetUniformuiv not loaded"); }
	glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)load("glBindFragDataLocation");
	if (!glBindFragDataLocation) { print_msg("glBindFragDataLocation not loaded"); }
	glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)load("glGetFragDataLocation");
	if (!glGetFragDataLocation) { print_msg("glGetFragDataLocation not loaded"); }
	glUniform1ui = (PFNGLUNIFORM1UIPROC)load("glUniform1ui");
	if (!glUniform1ui) { print_msg("glUniform1ui not loaded"); }
	glUniform2ui = (PFNGLUNIFORM2UIPROC)load("glUniform2ui");
	if (!glUniform2ui) { print_msg("glUniform2ui not loaded"); }
	glUniform3ui = (PFNGLUNIFORM3UIPROC)load("glUniform3ui");
	if (!glUniform3ui) { print_msg("glUniform3ui not loaded"); }
	glUniform4ui = (PFNGLUNIFORM4UIPROC)load("glUniform4ui");
	if (!glUniform4ui) { print_msg("glUniform4ui not loaded"); }
	glUniform1uiv = (PFNGLUNIFORM1UIVPROC)load("glUniform1uiv");
	if (!glUniform1uiv) { print_msg("glUniform1uiv not loaded"); }
	glUniform2uiv = (PFNGLUNIFORM2UIVPROC)load("glUniform2uiv");
	if (!glUniform2uiv) { print_msg("glUniform2uiv not loaded"); }
	glUniform3uiv = (PFNGLUNIFORM3UIVPROC)load("glUniform3uiv");
	if (!glUniform3uiv) { print_msg("glUniform3uiv not loaded"); }
	glUniform4uiv = (PFNGLUNIFORM4UIVPROC)load("glUniform4uiv");
	if (!glUniform4uiv) { print_msg("glUniform4uiv not loaded"); }
	glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)load("glTexParameterIiv");
	if (!glTexParameterIiv) { print_msg("glTexParameterIiv not loaded"); }
	glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)load("glTexParameterIuiv");
	if (!glTexParameterIuiv) { print_msg("glTexParameterIuiv not loaded"); }
	glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)load("glGetTexParameterIiv");
	if (!glGetTexParameterIiv) { print_msg("glGetTexParameterIiv not loaded"); }
	glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)load("glGetTexParameterIuiv");
	if (!glGetTexParameterIuiv) { print_msg("glGetTexParameterIuiv not loaded"); }
	glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)load("glClearBufferiv");
	if (!glClearBufferiv) { print_msg("glClearBufferiv not loaded"); }
	glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)load("glClearBufferuiv");
	if (!glClearBufferuiv) { print_msg("glClearBufferuiv not loaded"); }
	glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)load("glClearBufferfv");
	if (!glClearBufferfv) { print_msg("glClearBufferfv not loaded"); }
	glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)load("glClearBufferfi");
	if (!glClearBufferfi) { print_msg("glClearBufferfi not loaded"); }
	glGetStringi = (PFNGLGETSTRINGIPROC)load("glGetStringi");
	if (!glGetStringi) { print_msg("glGetStringi not loaded"); }
	glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)load("glIsRenderbuffer");
	if (!glIsRenderbuffer) { print_msg("glIsRenderbuffer not loaded"); }
	glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)load("glBindRenderbuffer");
	if (!glBindRenderbuffer) { print_msg("glBindRenderbuffer not loaded"); }
	glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)load("glDeleteRenderbuffers");
	if (!glDeleteRenderbuffers) { print_msg("glDeleteRenderbuffers not loaded"); }
	glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)load("glGenRenderbuffers");
	if (!glGenRenderbuffers) { print_msg("glGenRenderbuffers not loaded"); }
	glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)load("glRenderbufferStorage");
	if (!glRenderbufferStorage) { print_msg("glRenderbufferStorage not loaded"); }
	glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)load("glGetRenderbufferParameteriv");
	if (!glGetRenderbufferParameteriv) { print_msg("glGetRenderbufferParameteriv not loaded"); }
	glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)load("glIsFramebuffer");
	if (!glIsFramebuffer) { print_msg("glIsFramebuffer not loaded"); }
	glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)load("glBindFramebuffer");
	if (!glBindFramebuffer) { print_msg("glBindFramebuffer not loaded"); }
	glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)load("glDeleteFramebuffers");
	if (!glDeleteFramebuffers) { print_msg("glDeleteFramebuffers not loaded"); }
	glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)load("glGenFramebuffers");
	if (!glGenFramebuffers) { print_msg("glGenFramebuffers not loaded"); }
	glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)load("glCheckFramebufferStatus");
	if (!glCheckFramebufferStatus) { print_msg("glCheckFramebufferStatus not loaded"); }
	glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)load("glFramebufferTexture1D");
	if (!glFramebufferTexture1D) { print_msg("glFramebufferTexture1D not loaded"); }
	glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)load("glFramebufferTexture2D");
	if (!glFramebufferTexture2D) { print_msg("glFramebufferTexture2D not loaded"); }
	glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)load("glFramebufferTexture3D");
	if (!glFramebufferTexture3D) { print_msg("glFramebufferTexture3D not loaded"); }
	glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)load("glFramebufferRenderbuffer");
	if (!glFramebufferRenderbuffer) { print_msg("glFramebufferRenderbuffer not loaded"); }
	glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)load("glGetFramebufferAttachmentParameteriv");
	if (!glGetFramebufferAttachmentParameteriv) { print_msg("glGetFramebufferAttachmentParameteriv not loaded"); }
	glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)load("glGenerateMipmap");
	if (!glGenerateMipmap) { print_msg("glGenerateMipmap not loaded"); }
	glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)load("glBlitFramebuffer");
	if (!glBlitFramebuffer) { print_msg("glBlitFramebuffer not loaded"); }
	glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)load("glRenderbufferStorageMultisample");
	if (!glRenderbufferStorageMultisample) { print_msg("glRenderbufferStorageMultisample not loaded"); }
	glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)load("glFramebufferTextureLayer");
	if (!glFramebufferTextureLayer) { print_msg("glFramebufferTextureLayer not loaded"); }
	glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)load("glMapBufferRange");
	if (!glMapBufferRange) { print_msg("glMapBufferRange not loaded"); }
	glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)load("glFlushMappedBufferRange");
	if (!glFlushMappedBufferRange) { print_msg("glFlushMappedBufferRange not loaded"); }
	glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)load("glBindVertexArray");
	if (!glBindVertexArray) { print_msg("glBindVertexArray not loaded"); }
	glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)load("glDeleteVertexArrays");
	if (!glDeleteVertexArrays) { print_msg("glDeleteVertexArrays not loaded"); }
	glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)load("glGenVertexArrays");
	if (!glGenVertexArrays) { print_msg("glGenVertexArrays not loaded"); }
	glIsVertexArray = (PFNGLISVERTEXARRAYPROC)load("glIsVertexArray");
	if (!glIsVertexArray) { print_msg("glIsVertexArray not loaded"); }
}


void glfnlib_init_GL_VERSION_3_1(PFN_loadfunc_gl load) {
	glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)load("glDrawArraysInstanced");
	if (!glDrawArraysInstanced) { print_msg("glDrawArraysInstanced not loaded"); }
	glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)load("glDrawElementsInstanced");
	if (!glDrawElementsInstanced) { print_msg("glDrawElementsInstanced not loaded"); }
	glTexBuffer = (PFNGLTEXBUFFERPROC)load("glTexBuffer");
	if (!glTexBuffer) { print_msg("glTexBuffer not loaded"); }
	glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)load("glPrimitiveRestartIndex");
	if (!glPrimitiveRestartIndex) { print_msg("glPrimitiveRestartIndex not loaded"); }
	glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)load("glCopyBufferSubData");
	if (!glCopyBufferSubData) { print_msg("glCopyBufferSubData not loaded"); }
	glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)load("glGetUniformIndices");
	if (!glGetUniformIndices) { print_msg("glGetUniformIndices not loaded"); }
	glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)load("glGetActiveUniformsiv");
	if (!glGetActiveUniformsiv) { print_msg("glGetActiveUniformsiv not loaded"); }
	glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)load("glGetActiveUniformName");
	if (!glGetActiveUniformName) { print_msg("glGetActiveUniformName not loaded"); }
	glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)load("glGetUniformBlockIndex");
	if (!glGetUniformBlockIndex) { print_msg("glGetUniformBlockIndex not loaded"); }
	glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)load("glGetActiveUniformBlockiv");
	if (!glGetActiveUniformBlockiv) { print_msg("glGetActiveUniformBlockiv not loaded"); }
	glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)load("glGetActiveUniformBlockName");
	if (!glGetActiveUniformBlockName) { print_msg("glGetActiveUniformBlockName not loaded"); }
	glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)load("glUniformBlockBinding");
	if (!glUniformBlockBinding) { print_msg("glUniformBlockBinding not loaded"); }
}


void glfnlib_init_GL_VERSION_3_2(PFN_loadfunc_gl load) {
	glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)load("glDrawElementsBaseVertex");
	if (!glDrawElementsBaseVertex) { print_msg("glDrawElementsBaseVertex not loaded"); }
	glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)load("glDrawRangeElementsBaseVertex");
	if (!glDrawRangeElementsBaseVertex) { print_msg("glDrawRangeElementsBaseVertex not loaded"); }
	glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)load("glDrawElementsInstancedBaseVertex");
	if (!glDrawElementsInstancedBaseVertex) { print_msg("glDrawElementsInstancedBaseVertex not loaded"); }
	glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)load("glMultiDrawElementsBaseVertex");
	if (!glMultiDrawElementsBaseVertex) { print_msg("glMultiDrawElementsBaseVertex not loaded"); }
	glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)load("glProvokingVertex");
	if (!glProvokingVertex) { print_msg("glProvokingVertex not loaded"); }
	glFenceSync = (PFNGLFENCESYNCPROC)load("glFenceSync");
	if (!glFenceSync) { print_msg("glFenceSync not loaded"); }
	glIsSync = (PFNGLISSYNCPROC)load("glIsSync");
	if (!glIsSync) { print_msg("glIsSync not loaded"); }
	glDeleteSync = (PFNGLDELETESYNCPROC)load("glDeleteSync");
	if (!glDeleteSync) { print_msg("glDeleteSync not loaded"); }
	glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)load("glClientWaitSync");
	if (!glClientWaitSync) { print_msg("glClientWaitSync not loaded"); }
	glWaitSync = (PFNGLWAITSYNCPROC)load("glWaitSync");
	if (!glWaitSync) { print_msg("glWaitSync not loaded"); }
	glGetInteger64v = (PFNGLGETINTEGER64VPROC)load("glGetInteger64v");
	if (!glGetInteger64v) { print_msg("glGetInteger64v not loaded"); }
	glGetSynciv = (PFNGLGETSYNCIVPROC)load("glGetSynciv");
	if (!glGetSynciv) { print_msg("glGetSynciv not loaded"); }
	glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)load("glGetInteger64i_v");
	if (!glGetInteger64i_v) { print_msg("glGetInteger64i_v not loaded"); }
	glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)load("glGetBufferParameteri64v");
	if (!glGetBufferParameteri64v) { print_msg("glGetBufferParameteri64v not loaded"); }
	glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)load("glFramebufferTexture");
	if (!glFramebufferTexture) { print_msg("glFramebufferTexture not loaded"); }
	glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)load("glTexImage2DMultisample");
	if (!glTexImage2DMultisample) { print_msg("glTexImage2DMultisample not loaded"); }
	glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)load("glTexImage3DMultisample");
	if (!glTexImage3DMultisample) { print_msg("glTexImage3DMultisample not loaded"); }
	glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)load("glGetMultisamplefv");
	if (!glGetMultisamplefv) { print_msg("glGetMultisamplefv not loaded"); }
	glSampleMaski = (PFNGLSAMPLEMASKIPROC)load("glSampleMaski");
	if (!glSampleMaski) { print_msg("glSampleMaski not loaded"); }
}


void glfnlib_init_GL_VERSION_3_3(PFN_loadfunc_gl load) {
	glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)load("glBindFragDataLocationIndexed");
	if (!glBindFragDataLocationIndexed) { print_msg("glBindFragDataLocationIndexed not loaded"); }
	glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC)load("glGetFragDataIndex");
	if (!glGetFragDataIndex) { print_msg("glGetFragDataIndex not loaded"); }
	glGenSamplers = (PFNGLGENSAMPLERSPROC)load("glGenSamplers");
	if (!glGenSamplers) { print_msg("glGenSamplers not loaded"); }
	glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)load("glDeleteSamplers");
	if (!glDeleteSamplers) { print_msg("glDeleteSamplers not loaded"); }
	glIsSampler = (PFNGLISSAMPLERPROC)load("glIsSampler");
	if (!glIsSampler) { print_msg("glIsSampler not loaded"); }
	glBindSampler = (PFNGLBINDSAMPLERPROC)load("glBindSampler");
	if (!glBindSampler) { print_msg("glBindSampler not loaded"); }
	glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)load("glSamplerParameteri");
	if (!glSamplerParameteri) { print_msg("glSamplerParameteri not loaded"); }
	glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)load("glSamplerParameteriv");
	if (!glSamplerParameteriv) { print_msg("glSamplerParameteriv not loaded"); }
	glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)load("glSamplerParameterf");
	if (!glSamplerParameterf) { print_msg("glSamplerParameterf not loaded"); }
	glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)load("glSamplerParameterfv");
	if (!glSamplerParameterfv) { print_msg("glSamplerParameterfv not loaded"); }
	glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)load("glSamplerParameterIiv");
	if (!glSamplerParameterIiv) { print_msg("glSamplerParameterIiv not loaded"); }
	glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)load("glSamplerParameterIuiv");
	if (!glSamplerParameterIuiv) { print_msg("glSamplerParameterIuiv not loaded"); }
	glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)load("glGetSamplerParameteriv");
	if (!glGetSamplerParameteriv) { print_msg("glGetSamplerParameteriv not loaded"); }
	glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)load("glGetSamplerParameterIiv");
	if (!glGetSamplerParameterIiv) { print_msg("glGetSamplerParameterIiv not loaded"); }
	glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)load("glGetSamplerParameterfv");
	if (!glGetSamplerParameterfv) { print_msg("glGetSamplerParameterfv not loaded"); }
	glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)load("glGetSamplerParameterIuiv");
	if (!glGetSamplerParameterIuiv) { print_msg("glGetSamplerParameterIuiv not loaded"); }
	glQueryCounter = (PFNGLQUERYCOUNTERPROC)load("glQueryCounter");
	if (!glQueryCounter) { print_msg("glQueryCounter not loaded"); }
	glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC)load("glGetQueryObjecti64v");
	if (!glGetQueryObjecti64v) { print_msg("glGetQueryObjecti64v not loaded"); }
	glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)load("glGetQueryObjectui64v");
	if (!glGetQueryObjectui64v) { print_msg("glGetQueryObjectui64v not loaded"); }
	glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)load("glVertexAttribDivisor");
	if (!glVertexAttribDivisor) { print_msg("glVertexAttribDivisor not loaded"); }
	glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC)load("glVertexAttribP1ui");
	if (!glVertexAttribP1ui) { print_msg("glVertexAttribP1ui not loaded"); }
	glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC)load("glVertexAttribP1uiv");
	if (!glVertexAttribP1uiv) { print_msg("glVertexAttribP1uiv not loaded"); }
	glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC)load("glVertexAttribP2ui");
	if (!glVertexAttribP2ui) { print_msg("glVertexAttribP2ui not loaded"); }
	glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC)load("glVertexAttribP2uiv");
	if (!glVertexAttribP2uiv) { print_msg("glVertexAttribP2uiv not loaded"); }
	glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC)load("glVertexAttribP3ui");
	if (!glVertexAttribP3ui) { print_msg("glVertexAttribP3ui not loaded"); }
	glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC)load("glVertexAttribP3uiv");
	if (!glVertexAttribP3uiv) { print_msg("glVertexAttribP3uiv not loaded"); }
	glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC)load("glVertexAttribP4ui");
	if (!glVertexAttribP4ui) { print_msg("glVertexAttribP4ui not loaded"); }
	glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC)load("glVertexAttribP4uiv");
	if (!glVertexAttribP4uiv) { print_msg("glVertexAttribP4uiv not loaded"); }
	glVertexP2ui = (PFNGLVERTEXP2UIPROC)load("glVertexP2ui");
	if (!glVertexP2ui) { print_msg("glVertexP2ui not loaded"); }
	glVertexP2uiv = (PFNGLVERTEXP2UIVPROC)load("glVertexP2uiv");
	if (!glVertexP2uiv) { print_msg("glVertexP2uiv not loaded"); }
	glVertexP3ui = (PFNGLVERTEXP3UIPROC)load("glVertexP3ui");
	if (!glVertexP3ui) { print_msg("glVertexP3ui not loaded"); }
	glVertexP3uiv = (PFNGLVERTEXP3UIVPROC)load("glVertexP3uiv");
	if (!glVertexP3uiv) { print_msg("glVertexP3uiv not loaded"); }
	glVertexP4ui = (PFNGLVERTEXP4UIPROC)load("glVertexP4ui");
	if (!glVertexP4ui) { print_msg("glVertexP4ui not loaded"); }
	glVertexP4uiv = (PFNGLVERTEXP4UIVPROC)load("glVertexP4uiv");
	if (!glVertexP4uiv) { print_msg("glVertexP4uiv not loaded"); }
	glTexCoordP1ui = (PFNGLTEXCOORDP1UIPROC)load("glTexCoordP1ui");
	if (!glTexCoordP1ui) { print_msg("glTexCoordP1ui not loaded"); }
	glTexCoordP1uiv = (PFNGLTEXCOORDP1UIVPROC)load("glTexCoordP1uiv");
	if (!glTexCoordP1uiv) { print_msg("glTexCoordP1uiv not loaded"); }
	glTexCoordP2ui = (PFNGLTEXCOORDP2UIPROC)load("glTexCoordP2ui");
	if (!glTexCoordP2ui) { print_msg("glTexCoordP2ui not loaded"); }
	glTexCoordP2uiv = (PFNGLTEXCOORDP2UIVPROC)load("glTexCoordP2uiv");
	if (!glTexCoordP2uiv) { print_msg("glTexCoordP2uiv not loaded"); }
	glTexCoordP3ui = (PFNGLTEXCOORDP3UIPROC)load("glTexCoordP3ui");
	if (!glTexCoordP3ui) { print_msg("glTexCoordP3ui not loaded"); }
	glTexCoordP3uiv = (PFNGLTEXCOORDP3UIVPROC)load("glTexCoordP3uiv");
	if (!glTexCoordP3uiv) { print_msg("glTexCoordP3uiv not loaded"); }
	glTexCoordP4ui = (PFNGLTEXCOORDP4UIPROC)load("glTexCoordP4ui");
	if (!glTexCoordP4ui) { print_msg("glTexCoordP4ui not loaded"); }
	glTexCoordP4uiv = (PFNGLTEXCOORDP4UIVPROC)load("glTexCoordP4uiv");
	if (!glTexCoordP4uiv) { print_msg("glTexCoordP4uiv not loaded"); }
	glMultiTexCoordP1ui = (PFNGLMULTITEXCOORDP1UIPROC)load("glMultiTexCoordP1ui");
	if (!glMultiTexCoordP1ui) { print_msg("glMultiTexCoordP1ui not loaded"); }
	glMultiTexCoordP1uiv = (PFNGLMULTITEXCOORDP1UIVPROC)load("glMultiTexCoordP1uiv");
	if (!glMultiTexCoordP1uiv) { print_msg("glMultiTexCoordP1uiv not loaded"); }
	glMultiTexCoordP2ui = (PFNGLMULTITEXCOORDP2UIPROC)load("glMultiTexCoordP2ui");
	if (!glMultiTexCoordP2ui) { print_msg("glMultiTexCoordP2ui not loaded"); }
	glMultiTexCoordP2uiv = (PFNGLMULTITEXCOORDP2UIVPROC)load("glMultiTexCoordP2uiv");
	if (!glMultiTexCoordP2uiv) { print_msg("glMultiTexCoordP2uiv not loaded"); }
	glMultiTexCoordP3ui = (PFNGLMULTITEXCOORDP3UIPROC)load("glMultiTexCoordP3ui");
	if (!glMultiTexCoordP3ui) { print_msg("glMultiTexCoordP3ui not loaded"); }
	glMultiTexCoordP3uiv = (PFNGLMULTITEXCOORDP3UIVPROC)load("glMultiTexCoordP3uiv");
	if (!glMultiTexCoordP3uiv) { print_msg("glMultiTexCoordP3uiv not loaded"); }
	glMultiTexCoordP4ui = (PFNGLMULTITEXCOORDP4UIPROC)load("glMultiTexCoordP4ui");
	if (!glMultiTexCoordP4ui) { print_msg("glMultiTexCoordP4ui not loaded"); }
	glMultiTexCoordP4uiv = (PFNGLMULTITEXCOORDP4UIVPROC)load("glMultiTexCoordP4uiv");
	if (!glMultiTexCoordP4uiv) { print_msg("glMultiTexCoordP4uiv not loaded"); }
	glNormalP3ui = (PFNGLNORMALP3UIPROC)load("glNormalP3ui");
	if (!glNormalP3ui) { print_msg("glNormalP3ui not loaded"); }
	glNormalP3uiv = (PFNGLNORMALP3UIVPROC)load("glNormalP3uiv");
	if (!glNormalP3uiv) { print_msg("glNormalP3uiv not loaded"); }
	glColorP3ui = (PFNGLCOLORP3UIPROC)load("glColorP3ui");
	if (!glColorP3ui) { print_msg("glColorP3ui not loaded"); }
	glColorP3uiv = (PFNGLCOLORP3UIVPROC)load("glColorP3uiv");
	if (!glColorP3uiv) { print_msg("glColorP3uiv not loaded"); }
	glColorP4ui = (PFNGLCOLORP4UIPROC)load("glColorP4ui");
	if (!glColorP4ui) { print_msg("glColorP4ui not loaded"); }
	glColorP4uiv = (PFNGLCOLORP4UIVPROC)load("glColorP4uiv");
	if (!glColorP4uiv) { print_msg("glColorP4uiv not loaded"); }
	glSecondaryColorP3ui = (PFNGLSECONDARYCOLORP3UIPROC)load("glSecondaryColorP3ui");
	if (!glSecondaryColorP3ui) { print_msg("glSecondaryColorP3ui not loaded"); }
	glSecondaryColorP3uiv = (PFNGLSECONDARYCOLORP3UIVPROC)load("glSecondaryColorP3uiv");
	if (!glSecondaryColorP3uiv) { print_msg("glSecondaryColorP3uiv not loaded"); }
}


void glfnlib_init_GL_VERSION_4_0(PFN_loadfunc_gl load) {
	glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC)load("glMinSampleShading");
	if (!glMinSampleShading) { print_msg("glMinSampleShading not loaded"); }
	glBlendEquationi = (PFNGLBLENDEQUATIONIPROC)load("glBlendEquationi");
	if (!glBlendEquationi) { print_msg("glBlendEquationi not loaded"); }
	glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC)load("glBlendEquationSeparatei");
	if (!glBlendEquationSeparatei) { print_msg("glBlendEquationSeparatei not loaded"); }
	glBlendFunci = (PFNGLBLENDFUNCIPROC)load("glBlendFunci");
	if (!glBlendFunci) { print_msg("glBlendFunci not loaded"); }
	glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC)load("glBlendFuncSeparatei");
	if (!glBlendFuncSeparatei) { print_msg("glBlendFuncSeparatei not loaded"); }
	glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)load("glDrawArraysIndirect");
	if (!glDrawArraysIndirect) { print_msg("glDrawArraysIndirect not loaded"); }
	glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)load("glDrawElementsIndirect");
	if (!glDrawElementsIndirect) { print_msg("glDrawElementsIndirect not loaded"); }
	glUniform1d = (PFNGLUNIFORM1DPROC)load("glUniform1d");
	if (!glUniform1d) { print_msg("glUniform1d not loaded"); }
	glUniform2d = (PFNGLUNIFORM2DPROC)load("glUniform2d");
	if (!glUniform2d) { print_msg("glUniform2d not loaded"); }
	glUniform3d = (PFNGLUNIFORM3DPROC)load("glUniform3d");
	if (!glUniform3d) { print_msg("glUniform3d not loaded"); }
	glUniform4d = (PFNGLUNIFORM4DPROC)load("glUniform4d");
	if (!glUniform4d) { print_msg("glUniform4d not loaded"); }
	glUniform1dv = (PFNGLUNIFORM1DVPROC)load("glUniform1dv");
	if (!glUniform1dv) { print_msg("glUniform1dv not loaded"); }
	glUniform2dv = (PFNGLUNIFORM2DVPROC)load("glUniform2dv");
	if (!glUniform2dv) { print_msg("glUniform2dv not loaded"); }
	glUniform3dv = (PFNGLUNIFORM3DVPROC)load("glUniform3dv");
	if (!glUniform3dv) { print_msg("glUniform3dv not loaded"); }
	glUniform4dv = (PFNGLUNIFORM4DVPROC)load("glUniform4dv");
	if (!glUniform4dv) { print_msg("glUniform4dv not loaded"); }
	glUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC)load("glUniformMatrix2dv");
	if (!glUniformMatrix2dv) { print_msg("glUniformMatrix2dv not loaded"); }
	glUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC)load("glUniformMatrix3dv");
	if (!glUniformMatrix3dv) { print_msg("glUniformMatrix3dv not loaded"); }
	glUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC)load("glUniformMatrix4dv");
	if (!glUniformMatrix4dv) { print_msg("glUniformMatrix4dv not loaded"); }
	glUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC)load("glUniformMatrix2x3dv");
	if (!glUniformMatrix2x3dv) { print_msg("glUniformMatrix2x3dv not loaded"); }
	glUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC)load("glUniformMatrix2x4dv");
	if (!glUniformMatrix2x4dv) { print_msg("glUniformMatrix2x4dv not loaded"); }
	glUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC)load("glUniformMatrix3x2dv");
	if (!glUniformMatrix3x2dv) { print_msg("glUniformMatrix3x2dv not loaded"); }
	glUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC)load("glUniformMatrix3x4dv");
	if (!glUniformMatrix3x4dv) { print_msg("glUniformMatrix3x4dv not loaded"); }
	glUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC)load("glUniformMatrix4x2dv");
	if (!glUniformMatrix4x2dv) { print_msg("glUniformMatrix4x2dv not loaded"); }
	glUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC)load("glUniformMatrix4x3dv");
	if (!glUniformMatrix4x3dv) { print_msg("glUniformMatrix4x3dv not loaded"); }
	glGetUniformdv = (PFNGLGETUNIFORMDVPROC)load("glGetUniformdv");
	if (!glGetUniformdv) { print_msg("glGetUniformdv not loaded"); }
	glGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)load("glGetSubroutineUniformLocation");
	if (!glGetSubroutineUniformLocation) { print_msg("glGetSubroutineUniformLocation not loaded"); }
	glGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC)load("glGetSubroutineIndex");
	if (!glGetSubroutineIndex) { print_msg("glGetSubroutineIndex not loaded"); }
	glGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)load("glGetActiveSubroutineUniformiv");
	if (!glGetActiveSubroutineUniformiv) { print_msg("glGetActiveSubroutineUniformiv not loaded"); }
	glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)load("glGetActiveSubroutineUniformName");
	if (!glGetActiveSubroutineUniformName) { print_msg("glGetActiveSubroutineUniformName not loaded"); }
	glGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC)load("glGetActiveSubroutineName");
	if (!glGetActiveSubroutineName) { print_msg("glGetActiveSubroutineName not loaded"); }
	glUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC)load("glUniformSubroutinesuiv");
	if (!glUniformSubroutinesuiv) { print_msg("glUniformSubroutinesuiv not loaded"); }
	glGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)load("glGetUniformSubroutineuiv");
	if (!glGetUniformSubroutineuiv) { print_msg("glGetUniformSubroutineuiv not loaded"); }
	glGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC)load("glGetProgramStageiv");
	if (!glGetProgramStageiv) { print_msg("glGetProgramStageiv not loaded"); }
	glPatchParameteri = (PFNGLPATCHPARAMETERIPROC)load("glPatchParameteri");
	if (!glPatchParameteri) { print_msg("glPatchParameteri not loaded"); }
	glPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC)load("glPatchParameterfv");
	if (!glPatchParameterfv) { print_msg("glPatchParameterfv not loaded"); }
	glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)load("glBindTransformFeedback");
	if (!glBindTransformFeedback) { print_msg("glBindTransformFeedback not loaded"); }
	glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)load("glDeleteTransformFeedbacks");
	if (!glDeleteTransformFeedbacks) { print_msg("glDeleteTransformFeedbacks not loaded"); }
	glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)load("glGenTransformFeedbacks");
	if (!glGenTransformFeedbacks) { print_msg("glGenTransformFeedbacks not loaded"); }
	glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)load("glIsTransformFeedback");
	if (!glIsTransformFeedback) { print_msg("glIsTransformFeedback not loaded"); }
	glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)load("glPauseTransformFeedback");
	if (!glPauseTransformFeedback) { print_msg("glPauseTransformFeedback not loaded"); }
	glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)load("glResumeTransformFeedback");
	if (!glResumeTransformFeedback) { print_msg("glResumeTransformFeedback not loaded"); }
	glDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC)load("glDrawTransformFeedback");
	if (!glDrawTransformFeedback) { print_msg("glDrawTransformFeedback not loaded"); }
	glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)load("glDrawTransformFeedbackStream");
	if (!glDrawTransformFeedbackStream) { print_msg("glDrawTransformFeedbackStream not loaded"); }
	glBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC)load("glBeginQueryIndexed");
	if (!glBeginQueryIndexed) { print_msg("glBeginQueryIndexed not loaded"); }
	glEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC)load("glEndQueryIndexed");
	if (!glEndQueryIndexed) { print_msg("glEndQueryIndexed not loaded"); }
	glGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC)load("glGetQueryIndexediv");
	if (!glGetQueryIndexediv) { print_msg("glGetQueryIndexediv not loaded"); }
}


void glfnlib_init_GL_VERSION_4_1(PFN_loadfunc_gl load) {
	glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)load("glReleaseShaderCompiler");
	if (!glReleaseShaderCompiler) { print_msg("glReleaseShaderCompiler not loaded"); }
	glShaderBinary = (PFNGLSHADERBINARYPROC)load("glShaderBinary");
	if (!glShaderBinary) { print_msg("glShaderBinary not loaded"); }
	glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)load("glGetShaderPrecisionFormat");
	if (!glGetShaderPrecisionFormat) { print_msg("glGetShaderPrecisionFormat not loaded"); }
	glDepthRangef = (PFNGLDEPTHRANGEFPROC)load("glDepthRangef");
	if (!glDepthRangef) { print_msg("glDepthRangef not loaded"); }
	glClearDepthf = (PFNGLCLEARDEPTHFPROC)load("glClearDepthf");
	if (!glClearDepthf) { print_msg("glClearDepthf not loaded"); }
	glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)load("glGetProgramBinary");
	if (!glGetProgramBinary) { print_msg("glGetProgramBinary not loaded"); }
	glProgramBinary = (PFNGLPROGRAMBINARYPROC)load("glProgramBinary");
	if (!glProgramBinary) { print_msg("glProgramBinary not loaded"); }
	glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)load("glProgramParameteri");
	if (!glProgramParameteri) { print_msg("glProgramParameteri not loaded"); }
	glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)load("glUseProgramStages");
	if (!glUseProgramStages) { print_msg("glUseProgramStages not loaded"); }
	glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)load("glActiveShaderProgram");
	if (!glActiveShaderProgram) { print_msg("glActiveShaderProgram not loaded"); }
	glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)load("glCreateShaderProgramv");
	if (!glCreateShaderProgramv) { print_msg("glCreateShaderProgramv not loaded"); }
	glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)load("glBindProgramPipeline");
	if (!glBindProgramPipeline) { print_msg("glBindProgramPipeline not loaded"); }
	glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)load("glDeleteProgramPipelines");
	if (!glDeleteProgramPipelines) { print_msg("glDeleteProgramPipelines not loaded"); }
	glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)load("glGenProgramPipelines");
	if (!glGenProgramPipelines) { print_msg("glGenProgramPipelines not loaded"); }
	glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)load("glIsProgramPipeline");
	if (!glIsProgramPipeline) { print_msg("glIsProgramPipeline not loaded"); }
	glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)load("glGetProgramPipelineiv");
	if (!glGetProgramPipelineiv) { print_msg("glGetProgramPipelineiv not loaded"); }
	glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)load("glProgramUniform1i");
	if (!glProgramUniform1i) { print_msg("glProgramUniform1i not loaded"); }
	glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)load("glProgramUniform1iv");
	if (!glProgramUniform1iv) { print_msg("glProgramUniform1iv not loaded"); }
	glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)load("glProgramUniform1f");
	if (!glProgramUniform1f) { print_msg("glProgramUniform1f not loaded"); }
	glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)load("glProgramUniform1fv");
	if (!glProgramUniform1fv) { print_msg("glProgramUniform1fv not loaded"); }
	glProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC)load("glProgramUniform1d");
	if (!glProgramUniform1d) { print_msg("glProgramUniform1d not loaded"); }
	glProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC)load("glProgramUniform1dv");
	if (!glProgramUniform1dv) { print_msg("glProgramUniform1dv not loaded"); }
	glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)load("glProgramUniform1ui");
	if (!glProgramUniform1ui) { print_msg("glProgramUniform1ui not loaded"); }
	glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)load("glProgramUniform1uiv");
	if (!glProgramUniform1uiv) { print_msg("glProgramUniform1uiv not loaded"); }
	glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)load("glProgramUniform2i");
	if (!glProgramUniform2i) { print_msg("glProgramUniform2i not loaded"); }
	glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)load("glProgramUniform2iv");
	if (!glProgramUniform2iv) { print_msg("glProgramUniform2iv not loaded"); }
	glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)load("glProgramUniform2f");
	if (!glProgramUniform2f) { print_msg("glProgramUniform2f not loaded"); }
	glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)load("glProgramUniform2fv");
	if (!glProgramUniform2fv) { print_msg("glProgramUniform2fv not loaded"); }
	glProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC)load("glProgramUniform2d");
	if (!glProgramUniform2d) { print_msg("glProgramUniform2d not loaded"); }
	glProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC)load("glProgramUniform2dv");
	if (!glProgramUniform2dv) { print_msg("glProgramUniform2dv not loaded"); }
	glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)load("glProgramUniform2ui");
	if (!glProgramUniform2ui) { print_msg("glProgramUniform2ui not loaded"); }
	glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)load("glProgramUniform2uiv");
	if (!glProgramUniform2uiv) { print_msg("glProgramUniform2uiv not loaded"); }
	glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)load("glProgramUniform3i");
	if (!glProgramUniform3i) { print_msg("glProgramUniform3i not loaded"); }
	glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)load("glProgramUniform3iv");
	if (!glProgramUniform3iv) { print_msg("glProgramUniform3iv not loaded"); }
	glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)load("glProgramUniform3f");
	if (!glProgramUniform3f) { print_msg("glProgramUniform3f not loaded"); }
	glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)load("glProgramUniform3fv");
	if (!glProgramUniform3fv) { print_msg("glProgramUniform3fv not loaded"); }
	glProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC)load("glProgramUniform3d");
	if (!glProgramUniform3d) { print_msg("glProgramUniform3d not loaded"); }
	glProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC)load("glProgramUniform3dv");
	if (!glProgramUniform3dv) { print_msg("glProgramUniform3dv not loaded"); }
	glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)load("glProgramUniform3ui");
	if (!glProgramUniform3ui) { print_msg("glProgramUniform3ui not loaded"); }
	glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)load("glProgramUniform3uiv");
	if (!glProgramUniform3uiv) { print_msg("glProgramUniform3uiv not loaded"); }
	glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)load("glProgramUniform4i");
	if (!glProgramUniform4i) { print_msg("glProgramUniform4i not loaded"); }
	glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)load("glProgramUniform4iv");
	if (!glProgramUniform4iv) { print_msg("glProgramUniform4iv not loaded"); }
	glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)load("glProgramUniform4f");
	if (!glProgramUniform4f) { print_msg("glProgramUniform4f not loaded"); }
	glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)load("glProgramUniform4fv");
	if (!glProgramUniform4fv) { print_msg("glProgramUniform4fv not loaded"); }
	glProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC)load("glProgramUniform4d");
	if (!glProgramUniform4d) { print_msg("glProgramUniform4d not loaded"); }
	glProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC)load("glProgramUniform4dv");
	if (!glProgramUniform4dv) { print_msg("glProgramUniform4dv not loaded"); }
	glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)load("glProgramUniform4ui");
	if (!glProgramUniform4ui) { print_msg("glProgramUniform4ui not loaded"); }
	glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)load("glProgramUniform4uiv");
	if (!glProgramUniform4uiv) { print_msg("glProgramUniform4uiv not loaded"); }
	glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)load("glProgramUniformMatrix2fv");
	if (!glProgramUniformMatrix2fv) { print_msg("glProgramUniformMatrix2fv not loaded"); }
	glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)load("glProgramUniformMatrix3fv");
	if (!glProgramUniformMatrix3fv) { print_msg("glProgramUniformMatrix3fv not loaded"); }
	glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)load("glProgramUniformMatrix4fv");
	if (!glProgramUniformMatrix4fv) { print_msg("glProgramUniformMatrix4fv not loaded"); }
	glProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)load("glProgramUniformMatrix2dv");
	if (!glProgramUniformMatrix2dv) { print_msg("glProgramUniformMatrix2dv not loaded"); }
	glProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)load("glProgramUniformMatrix3dv");
	if (!glProgramUniformMatrix3dv) { print_msg("glProgramUniformMatrix3dv not loaded"); }
	glProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)load("glProgramUniformMatrix4dv");
	if (!glProgramUniformMatrix4dv) { print_msg("glProgramUniformMatrix4dv not loaded"); }
	glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)load("glProgramUniformMatrix2x3fv");
	if (!glProgramUniformMatrix2x3fv) { print_msg("glProgramUniformMatrix2x3fv not loaded"); }
	glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)load("glProgramUniformMatrix3x2fv");
	if (!glProgramUniformMatrix3x2fv) { print_msg("glProgramUniformMatrix3x2fv not loaded"); }
	glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)load("glProgramUniformMatrix2x4fv");
	if (!glProgramUniformMatrix2x4fv) { print_msg("glProgramUniformMatrix2x4fv not loaded"); }
	glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)load("glProgramUniformMatrix4x2fv");
	if (!glProgramUniformMatrix4x2fv) { print_msg("glProgramUniformMatrix4x2fv not loaded"); }
	glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)load("glProgramUniformMatrix3x4fv");
	if (!glProgramUniformMatrix3x4fv) { print_msg("glProgramUniformMatrix3x4fv not loaded"); }
	glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)load("glProgramUniformMatrix4x3fv");
	if (!glProgramUniformMatrix4x3fv) { print_msg("glProgramUniformMatrix4x3fv not loaded"); }
	glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)load("glProgramUniformMatrix2x3dv");
	if (!glProgramUniformMatrix2x3dv) { print_msg("glProgramUniformMatrix2x3dv not loaded"); }
	glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)load("glProgramUniformMatrix3x2dv");
	if (!glProgramUniformMatrix3x2dv) { print_msg("glProgramUniformMatrix3x2dv not loaded"); }
	glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)load("glProgramUniformMatrix2x4dv");
	if (!glProgramUniformMatrix2x4dv) { print_msg("glProgramUniformMatrix2x4dv not loaded"); }
	glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)load("glProgramUniformMatrix4x2dv");
	if (!glProgramUniformMatrix4x2dv) { print_msg("glProgramUniformMatrix4x2dv not loaded"); }
	glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)load("glProgramUniformMatrix3x4dv");
	if (!glProgramUniformMatrix3x4dv) { print_msg("glProgramUniformMatrix3x4dv not loaded"); }
	glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)load("glProgramUniformMatrix4x3dv");
	if (!glProgramUniformMatrix4x3dv) { print_msg("glProgramUniformMatrix4x3dv not loaded"); }
	glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)load("glValidateProgramPipeline");
	if (!glValidateProgramPipeline) { print_msg("glValidateProgramPipeline not loaded"); }
	glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)load("glGetProgramPipelineInfoLog");
	if (!glGetProgramPipelineInfoLog) { print_msg("glGetProgramPipelineInfoLog not loaded"); }
	glVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC)load("glVertexAttribL1d");
	if (!glVertexAttribL1d) { print_msg("glVertexAttribL1d not loaded"); }
	glVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC)load("glVertexAttribL2d");
	if (!glVertexAttribL2d) { print_msg("glVertexAttribL2d not loaded"); }
	glVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC)load("glVertexAttribL3d");
	if (!glVertexAttribL3d) { print_msg("glVertexAttribL3d not loaded"); }
	glVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC)load("glVertexAttribL4d");
	if (!glVertexAttribL4d) { print_msg("glVertexAttribL4d not loaded"); }
	glVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC)load("glVertexAttribL1dv");
	if (!glVertexAttribL1dv) { print_msg("glVertexAttribL1dv not loaded"); }
	glVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC)load("glVertexAttribL2dv");
	if (!glVertexAttribL2dv) { print_msg("glVertexAttribL2dv not loaded"); }
	glVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC)load("glVertexAttribL3dv");
	if (!glVertexAttribL3dv) { print_msg("glVertexAttribL3dv not loaded"); }
	glVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC)load("glVertexAttribL4dv");
	if (!glVertexAttribL4dv) { print_msg("glVertexAttribL4dv not loaded"); }
	glVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC)load("glVertexAttribLPointer");
	if (!glVertexAttribLPointer) { print_msg("glVertexAttribLPointer not loaded"); }
	glGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC)load("glGetVertexAttribLdv");
	if (!glGetVertexAttribLdv) { print_msg("glGetVertexAttribLdv not loaded"); }
	glViewportArrayv = (PFNGLVIEWPORTARRAYVPROC)load("glViewportArrayv");
	if (!glViewportArrayv) { print_msg("glViewportArrayv not loaded"); }
	glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)load("glViewportIndexedf");
	if (!glViewportIndexedf) { print_msg("glViewportIndexedf not loaded"); }
	glViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC)load("glViewportIndexedfv");
	if (!glViewportIndexedfv) { print_msg("glViewportIndexedfv not loaded"); }
	glScissorArrayv = (PFNGLSCISSORARRAYVPROC)load("glScissorArrayv");
	if (!glScissorArrayv) { print_msg("glScissorArrayv not loaded"); }
	glScissorIndexed = (PFNGLSCISSORINDEXEDPROC)load("glScissorIndexed");
	if (!glScissorIndexed) { print_msg("glScissorIndexed not loaded"); }
	glScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC)load("glScissorIndexedv");
	if (!glScissorIndexedv) { print_msg("glScissorIndexedv not loaded"); }
	glDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC)load("glDepthRangeArrayv");
	if (!glDepthRangeArrayv) { print_msg("glDepthRangeArrayv not loaded"); }
	glDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC)load("glDepthRangeIndexed");
	if (!glDepthRangeIndexed) { print_msg("glDepthRangeIndexed not loaded"); }
	glGetFloati_v = (PFNGLGETFLOATI_VPROC)load("glGetFloati_v");
	if (!glGetFloati_v) { print_msg("glGetFloati_v not loaded"); }
	glGetDoublei_v = (PFNGLGETDOUBLEI_VPROC)load("glGetDoublei_v");
	if (!glGetDoublei_v) { print_msg("glGetDoublei_v not loaded"); }
}


void glfnlib_init_GL_VERSION_4_2(PFN_loadfunc_gl load) {
	glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)load("glDrawArraysInstancedBaseInstance");
	if (!glDrawArraysInstancedBaseInstance) { print_msg("glDrawArraysInstancedBaseInstance not loaded"); }
	glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)load("glDrawElementsInstancedBaseInstance");
	if (!glDrawElementsInstancedBaseInstance) { print_msg("glDrawElementsInstancedBaseInstance not loaded"); }
	glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)load("glDrawElementsInstancedBaseVertexBaseInstance");
	if (!glDrawElementsInstancedBaseVertexBaseInstance) { print_msg("glDrawElementsInstancedBaseVertexBaseInstance not loaded"); }
	glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)load("glGetInternalformativ");
	if (!glGetInternalformativ) { print_msg("glGetInternalformativ not loaded"); }
	glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)load("glGetActiveAtomicCounterBufferiv");
	if (!glGetActiveAtomicCounterBufferiv) { print_msg("glGetActiveAtomicCounterBufferiv not loaded"); }
	glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)load("glBindImageTexture");
	if (!glBindImageTexture) { print_msg("glBindImageTexture not loaded"); }
	glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)load("glMemoryBarrier");
	if (!glMemoryBarrier) { print_msg("glMemoryBarrier not loaded"); }
	glTexStorage1D = (PFNGLTEXSTORAGE1DPROC)load("glTexStorage1D");
	if (!glTexStorage1D) { print_msg("glTexStorage1D not loaded"); }
	glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)load("glTexStorage2D");
	if (!glTexStorage2D) { print_msg("glTexStorage2D not loaded"); }
	glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)load("glTexStorage3D");
	if (!glTexStorage3D) { print_msg("glTexStorage3D not loaded"); }
	glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)load("glDrawTransformFeedbackInstanced");
	if (!glDrawTransformFeedbackInstanced) { print_msg("glDrawTransformFeedbackInstanced not loaded"); }
	glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)load("glDrawTransformFeedbackStreamInstanced");
	if (!glDrawTransformFeedbackStreamInstanced) { print_msg("glDrawTransformFeedbackStreamInstanced not loaded"); }
}


void glfnlib_init_GL_VERSION_4_3(PFN_loadfunc_gl load) {
	glClearBufferData = (PFNGLCLEARBUFFERDATAPROC)load("glClearBufferData");
	if (!glClearBufferData) { print_msg("glClearBufferData not loaded"); }
	glClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC)load("glClearBufferSubData");
	if (!glClearBufferSubData) { print_msg("glClearBufferSubData not loaded"); }
	glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)load("glDispatchCompute");
	if (!glDispatchCompute) { print_msg("glDispatchCompute not loaded"); }
	glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)load("glDispatchComputeIndirect");
	if (!glDispatchComputeIndirect) { print_msg("glDispatchComputeIndirect not loaded"); }
	glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)load("glCopyImageSubData");
	if (!glCopyImageSubData) { print_msg("glCopyImageSubData not loaded"); }
	glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)load("glFramebufferParameteri");
	if (!glFramebufferParameteri) { print_msg("glFramebufferParameteri not loaded"); }
	glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)load("glGetFramebufferParameteriv");
	if (!glGetFramebufferParameteriv) { print_msg("glGetFramebufferParameteriv not loaded"); }
	glGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC)load("glGetInternalformati64v");
	if (!glGetInternalformati64v) { print_msg("glGetInternalformati64v not loaded"); }
	glInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC)load("glInvalidateTexSubImage");
	if (!glInvalidateTexSubImage) { print_msg("glInvalidateTexSubImage not loaded"); }
	glInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC)load("glInvalidateTexImage");
	if (!glInvalidateTexImage) { print_msg("glInvalidateTexImage not loaded"); }
	glInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC)load("glInvalidateBufferSubData");
	if (!glInvalidateBufferSubData) { print_msg("glInvalidateBufferSubData not loaded"); }
	glInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC)load("glInvalidateBufferData");
	if (!glInvalidateBufferData) { print_msg("glInvalidateBufferData not loaded"); }
	glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)load("glInvalidateFramebuffer");
	if (!glInvalidateFramebuffer) { print_msg("glInvalidateFramebuffer not loaded"); }
	glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)load("glInvalidateSubFramebuffer");
	if (!glInvalidateSubFramebuffer) { print_msg("glInvalidateSubFramebuffer not loaded"); }
	glMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)load("glMultiDrawArraysIndirect");
	if (!glMultiDrawArraysIndirect) { print_msg("glMultiDrawArraysIndirect not loaded"); }
	glMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)load("glMultiDrawElementsIndirect");
	if (!glMultiDrawElementsIndirect) { print_msg("glMultiDrawElementsIndirect not loaded"); }
	glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)load("glGetProgramInterfaceiv");
	if (!glGetProgramInterfaceiv) { print_msg("glGetProgramInterfaceiv not loaded"); }
	glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)load("glGetProgramResourceIndex");
	if (!glGetProgramResourceIndex) { print_msg("glGetProgramResourceIndex not loaded"); }
	glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)load("glGetProgramResourceName");
	if (!glGetProgramResourceName) { print_msg("glGetProgramResourceName not loaded"); }
	glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)load("glGetProgramResourceiv");
	if (!glGetProgramResourceiv) { print_msg("glGetProgramResourceiv not loaded"); }
	glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)load("glGetProgramResourceLocation");
	if (!glGetProgramResourceLocation) { print_msg("glGetProgramResourceLocation not loaded"); }
	glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)load("glGetProgramResourceLocationIndex");
	if (!glGetProgramResourceLocationIndex) { print_msg("glGetProgramResourceLocationIndex not loaded"); }
	glShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)load("glShaderStorageBlockBinding");
	if (!glShaderStorageBlockBinding) { print_msg("glShaderStorageBlockBinding not loaded"); }
	glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)load("glTexBufferRange");
	if (!glTexBufferRange) { print_msg("glTexBufferRange not loaded"); }
	glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)load("glTexStorage2DMultisample");
	if (!glTexStorage2DMultisample) { print_msg("glTexStorage2DMultisample not loaded"); }
	glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)load("glTexStorage3DMultisample");
	if (!glTexStorage3DMultisample) { print_msg("glTexStorage3DMultisample not loaded"); }
	glTextureView = (PFNGLTEXTUREVIEWPROC)load("glTextureView");
	if (!glTextureView) { print_msg("glTextureView not loaded"); }
	glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)load("glBindVertexBuffer");
	if (!glBindVertexBuffer) { print_msg("glBindVertexBuffer not loaded"); }
	glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)load("glVertexAttribFormat");
	if (!glVertexAttribFormat) { print_msg("glVertexAttribFormat not loaded"); }
	glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)load("glVertexAttribIFormat");
	if (!glVertexAttribIFormat) { print_msg("glVertexAttribIFormat not loaded"); }
	glVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC)load("glVertexAttribLFormat");
	if (!glVertexAttribLFormat) { print_msg("glVertexAttribLFormat not loaded"); }
	glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)load("glVertexAttribBinding");
	if (!glVertexAttribBinding) { print_msg("glVertexAttribBinding not loaded"); }
	glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)load("glVertexBindingDivisor");
	if (!glVertexBindingDivisor) { print_msg("glVertexBindingDivisor not loaded"); }
	glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)load("glDebugMessageControl");
	if (!glDebugMessageControl) { print_msg("glDebugMessageControl not loaded"); }
	glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)load("glDebugMessageInsert");
	if (!glDebugMessageInsert) { print_msg("glDebugMessageInsert not loaded"); }
	glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)load("glDebugMessageCallback");
	if (!glDebugMessageCallback) { print_msg("glDebugMessageCallback not loaded"); }
	glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)load("glGetDebugMessageLog");
	if (!glGetDebugMessageLog) { print_msg("glGetDebugMessageLog not loaded"); }
	glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)load("glPushDebugGroup");
	if (!glPushDebugGroup) { print_msg("glPushDebugGroup not loaded"); }
	glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)load("glPopDebugGroup");
	if (!glPopDebugGroup) { print_msg("glPopDebugGroup not loaded"); }
	glObjectLabel = (PFNGLOBJECTLABELPROC)load("glObjectLabel");
	if (!glObjectLabel) { print_msg("glObjectLabel not loaded"); }
	glGetObjectLabel = (PFNGLGETOBJECTLABELPROC)load("glGetObjectLabel");
	if (!glGetObjectLabel) { print_msg("glGetObjectLabel not loaded"); }
	glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)load("glObjectPtrLabel");
	if (!glObjectPtrLabel) { print_msg("glObjectPtrLabel not loaded"); }
	glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)load("glGetObjectPtrLabel");
	if (!glGetObjectPtrLabel) { print_msg("glGetObjectPtrLabel not loaded"); }
}


void glfnlib_init_GL_VERSION_4_4(PFN_loadfunc_gl load) {
	glBufferStorage = (PFNGLBUFFERSTORAGEPROC)load("glBufferStorage");
	if (!glBufferStorage) { print_msg("glBufferStorage not loaded"); }
	glClearTexImage = (PFNGLCLEARTEXIMAGEPROC)load("glClearTexImage");
	if (!glClearTexImage) { print_msg("glClearTexImage not loaded"); }
	glClearTexSubImage = (PFNGLCLEARTEXSUBIMAGEPROC)load("glClearTexSubImage");
	if (!glClearTexSubImage) { print_msg("glClearTexSubImage not loaded"); }
	glBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC)load("glBindBuffersBase");
	if (!glBindBuffersBase) { print_msg("glBindBuffersBase not loaded"); }
	glBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC)load("glBindBuffersRange");
	if (!glBindBuffersRange) { print_msg("glBindBuffersRange not loaded"); }
	glBindTextures = (PFNGLBINDTEXTURESPROC)load("glBindTextures");
	if (!glBindTextures) { print_msg("glBindTextures not loaded"); }
	glBindSamplers = (PFNGLBINDSAMPLERSPROC)load("glBindSamplers");
	if (!glBindSamplers) { print_msg("glBindSamplers not loaded"); }
	glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC)load("glBindImageTextures");
	if (!glBindImageTextures) { print_msg("glBindImageTextures not loaded"); }
	glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC)load("glBindVertexBuffers");
	if (!glBindVertexBuffers) { print_msg("glBindVertexBuffers not loaded"); }
}


void glfnlib_init_GL_VERSION_4_5(PFN_loadfunc_gl load) {
	glClipControl = (PFNGLCLIPCONTROLPROC)load("glClipControl");
	if (!glClipControl) { print_msg("glClipControl not loaded"); }
	glCreateTransformFeedbacks = (PFNGLCREATETRANSFORMFEEDBACKSPROC)load("glCreateTransformFeedbacks");
	if (!glCreateTransformFeedbacks) { print_msg("glCreateTransformFeedbacks not loaded"); }
	glTransformFeedbackBufferBase = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)load("glTransformFeedbackBufferBase");
	if (!glTransformFeedbackBufferBase) { print_msg("glTransformFeedbackBufferBase not loaded"); }
	glTransformFeedbackBufferRange = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)load("glTransformFeedbackBufferRange");
	if (!glTransformFeedbackBufferRange) { print_msg("glTransformFeedbackBufferRange not loaded"); }
	glGetTransformFeedbackiv = (PFNGLGETTRANSFORMFEEDBACKIVPROC)load("glGetTransformFeedbackiv");
	if (!glGetTransformFeedbackiv) { print_msg("glGetTransformFeedbackiv not loaded"); }
	glGetTransformFeedbacki_v = (PFNGLGETTRANSFORMFEEDBACKI_VPROC)load("glGetTransformFeedbacki_v");
	if (!glGetTransformFeedbacki_v) { print_msg("glGetTransformFeedbacki_v not loaded"); }
	glGetTransformFeedbacki64_v = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC)load("glGetTransformFeedbacki64_v");
	if (!glGetTransformFeedbacki64_v) { print_msg("glGetTransformFeedbacki64_v not loaded"); }
	glCreateBuffers = (PFNGLCREATEBUFFERSPROC)load("glCreateBuffers");
	if (!glCreateBuffers) { print_msg("glCreateBuffers not loaded"); }
	glNamedBufferStorage = (PFNGLNAMEDBUFFERSTORAGEPROC)load("glNamedBufferStorage");
	if (!glNamedBufferStorage) { print_msg("glNamedBufferStorage not loaded"); }
	glNamedBufferData = (PFNGLNAMEDBUFFERDATAPROC)load("glNamedBufferData");
	if (!glNamedBufferData) { print_msg("glNamedBufferData not loaded"); }
	glNamedBufferSubData = (PFNGLNAMEDBUFFERSUBDATAPROC)load("glNamedBufferSubData");
	if (!glNamedBufferSubData) { print_msg("glNamedBufferSubData not loaded"); }
	glCopyNamedBufferSubData = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC)load("glCopyNamedBufferSubData");
	if (!glCopyNamedBufferSubData) { print_msg("glCopyNamedBufferSubData not loaded"); }
	glClearNamedBufferData = (PFNGLCLEARNAMEDBUFFERDATAPROC)load("glClearNamedBufferData");
	if (!glClearNamedBufferData) { print_msg("glClearNamedBufferData not loaded"); }
	glClearNamedBufferSubData = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC)load("glClearNamedBufferSubData");
	if (!glClearNamedBufferSubData) { print_msg("glClearNamedBufferSubData not loaded"); }
	glMapNamedBuffer = (PFNGLMAPNAMEDBUFFERPROC)load("glMapNamedBuffer");
	if (!glMapNamedBuffer) { print_msg("glMapNamedBuffer not loaded"); }
	glMapNamedBufferRange = (PFNGLMAPNAMEDBUFFERRANGEPROC)load("glMapNamedBufferRange");
	if (!glMapNamedBufferRange) { print_msg("glMapNamedBufferRange not loaded"); }
	glUnmapNamedBuffer = (PFNGLUNMAPNAMEDBUFFERPROC)load("glUnmapNamedBuffer");
	if (!glUnmapNamedBuffer) { print_msg("glUnmapNamedBuffer not loaded"); }
	glFlushMappedNamedBufferRange = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)load("glFlushMappedNamedBufferRange");
	if (!glFlushMappedNamedBufferRange) { print_msg("glFlushMappedNamedBufferRange not loaded"); }
	glGetNamedBufferParameteriv = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC)load("glGetNamedBufferParameteriv");
	if (!glGetNamedBufferParameteriv) { print_msg("glGetNamedBufferParameteriv not loaded"); }
	glGetNamedBufferParameteri64v = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)load("glGetNamedBufferParameteri64v");
	if (!glGetNamedBufferParameteri64v) { print_msg("glGetNamedBufferParameteri64v not loaded"); }
	glGetNamedBufferPointerv = (PFNGLGETNAMEDBUFFERPOINTERVPROC)load("glGetNamedBufferPointerv");
	if (!glGetNamedBufferPointerv) { print_msg("glGetNamedBufferPointerv not loaded"); }
	glGetNamedBufferSubData = (PFNGLGETNAMEDBUFFERSUBDATAPROC)load("glGetNamedBufferSubData");
	if (!glGetNamedBufferSubData) { print_msg("glGetNamedBufferSubData not loaded"); }
	glCreateFramebuffers = (PFNGLCREATEFRAMEBUFFERSPROC)load("glCreateFramebuffers");
	if (!glCreateFramebuffers) { print_msg("glCreateFramebuffers not loaded"); }
	glNamedFramebufferRenderbuffer = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)load("glNamedFramebufferRenderbuffer");
	if (!glNamedFramebufferRenderbuffer) { print_msg("glNamedFramebufferRenderbuffer not loaded"); }
	glNamedFramebufferParameteri = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)load("glNamedFramebufferParameteri");
	if (!glNamedFramebufferParameteri) { print_msg("glNamedFramebufferParameteri not loaded"); }
	glNamedFramebufferTexture = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)load("glNamedFramebufferTexture");
	if (!glNamedFramebufferTexture) { print_msg("glNamedFramebufferTexture not loaded"); }
	glNamedFramebufferTextureLayer = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)load("glNamedFramebufferTextureLayer");
	if (!glNamedFramebufferTextureLayer) { print_msg("glNamedFramebufferTextureLayer not loaded"); }
	glNamedFramebufferDrawBuffer = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)load("glNamedFramebufferDrawBuffer");
	if (!glNamedFramebufferDrawBuffer) { print_msg("glNamedFramebufferDrawBuffer not loaded"); }
	glNamedFramebufferDrawBuffers = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)load("glNamedFramebufferDrawBuffers");
	if (!glNamedFramebufferDrawBuffers) { print_msg("glNamedFramebufferDrawBuffers not loaded"); }
	glNamedFramebufferReadBuffer = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)load("glNamedFramebufferReadBuffer");
	if (!glNamedFramebufferReadBuffer) { print_msg("glNamedFramebufferReadBuffer not loaded"); }
	glInvalidateNamedFramebufferData = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)load("glInvalidateNamedFramebufferData");
	if (!glInvalidateNamedFramebufferData) { print_msg("glInvalidateNamedFramebufferData not loaded"); }
	glInvalidateNamedFramebufferSubData = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)load("glInvalidateNamedFramebufferSubData");
	if (!glInvalidateNamedFramebufferSubData) { print_msg("glInvalidateNamedFramebufferSubData not loaded"); }
	glClearNamedFramebufferiv = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)load("glClearNamedFramebufferiv");
	if (!glClearNamedFramebufferiv) { print_msg("glClearNamedFramebufferiv not loaded"); }
	glClearNamedFramebufferuiv = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)load("glClearNamedFramebufferuiv");
	if (!glClearNamedFramebufferuiv) { print_msg("glClearNamedFramebufferuiv not loaded"); }
	glClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)load("glClearNamedFramebufferfv");
	if (!glClearNamedFramebufferfv) { print_msg("glClearNamedFramebufferfv not loaded"); }
	glClearNamedFramebufferfi = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)load("glClearNamedFramebufferfi");
	if (!glClearNamedFramebufferfi) { print_msg("glClearNamedFramebufferfi not loaded"); }
	glBlitNamedFramebuffer = (PFNGLBLITNAMEDFRAMEBUFFERPROC)load("glBlitNamedFramebuffer");
	if (!glBlitNamedFramebuffer) { print_msg("glBlitNamedFramebuffer not loaded"); }
	glCheckNamedFramebufferStatus = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)load("glCheckNamedFramebufferStatus");
	if (!glCheckNamedFramebufferStatus) { print_msg("glCheckNamedFramebufferStatus not loaded"); }
	glGetNamedFramebufferParameteriv = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)load("glGetNamedFramebufferParameteriv");
	if (!glGetNamedFramebufferParameteriv) { print_msg("glGetNamedFramebufferParameteriv not loaded"); }
	glGetNamedFramebufferAttachmentParameteriv = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)load("glGetNamedFramebufferAttachmentParameteriv");
	if (!glGetNamedFramebufferAttachmentParameteriv) { print_msg("glGetNamedFramebufferAttachmentParameteriv not loaded"); }
	glCreateRenderbuffers = (PFNGLCREATERENDERBUFFERSPROC)load("glCreateRenderbuffers");
	if (!glCreateRenderbuffers) { print_msg("glCreateRenderbuffers not loaded"); }
	glNamedRenderbufferStorage = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC)load("glNamedRenderbufferStorage");
	if (!glNamedRenderbufferStorage) { print_msg("glNamedRenderbufferStorage not loaded"); }
	glNamedRenderbufferStorageMultisample = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)load("glNamedRenderbufferStorageMultisample");
	if (!glNamedRenderbufferStorageMultisample) { print_msg("glNamedRenderbufferStorageMultisample not loaded"); }
	glGetNamedRenderbufferParameteriv = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)load("glGetNamedRenderbufferParameteriv");
	if (!glGetNamedRenderbufferParameteriv) { print_msg("glGetNamedRenderbufferParameteriv not loaded"); }
	glCreateTextures = (PFNGLCREATETEXTURESPROC)load("glCreateTextures");
	if (!glCreateTextures) { print_msg("glCreateTextures not loaded"); }
	glTextureBuffer = (PFNGLTEXTUREBUFFERPROC)load("glTextureBuffer");
	if (!glTextureBuffer) { print_msg("glTextureBuffer not loaded"); }
	glTextureBufferRange = (PFNGLTEXTUREBUFFERRANGEPROC)load("glTextureBufferRange");
	if (!glTextureBufferRange) { print_msg("glTextureBufferRange not loaded"); }
	glTextureStorage1D = (PFNGLTEXTURESTORAGE1DPROC)load("glTextureStorage1D");
	if (!glTextureStorage1D) { print_msg("glTextureStorage1D not loaded"); }
	glTextureStorage2D = (PFNGLTEXTURESTORAGE2DPROC)load("glTextureStorage2D");
	if (!glTextureStorage2D) { print_msg("glTextureStorage2D not loaded"); }
	glTextureStorage3D = (PFNGLTEXTURESTORAGE3DPROC)load("glTextureStorage3D");
	if (!glTextureStorage3D) { print_msg("glTextureStorage3D not loaded"); }
	glTextureStorage2DMultisample = (PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)load("glTextureStorage2DMultisample");
	if (!glTextureStorage2DMultisample) { print_msg("glTextureStorage2DMultisample not loaded"); }
	glTextureStorage3DMultisample = (PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)load("glTextureStorage3DMultisample");
	if (!glTextureStorage3DMultisample) { print_msg("glTextureStorage3DMultisample not loaded"); }
	glTextureSubImage1D = (PFNGLTEXTURESUBIMAGE1DPROC)load("glTextureSubImage1D");
	if (!glTextureSubImage1D) { print_msg("glTextureSubImage1D not loaded"); }
	glTextureSubImage2D = (PFNGLTEXTURESUBIMAGE2DPROC)load("glTextureSubImage2D");
	if (!glTextureSubImage2D) { print_msg("glTextureSubImage2D not loaded"); }
	glTextureSubImage3D = (PFNGLTEXTURESUBIMAGE3DPROC)load("glTextureSubImage3D");
	if (!glTextureSubImage3D) { print_msg("glTextureSubImage3D not loaded"); }
	glCompressedTextureSubImage1D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)load("glCompressedTextureSubImage1D");
	if (!glCompressedTextureSubImage1D) { print_msg("glCompressedTextureSubImage1D not loaded"); }
	glCompressedTextureSubImage2D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)load("glCompressedTextureSubImage2D");
	if (!glCompressedTextureSubImage2D) { print_msg("glCompressedTextureSubImage2D not loaded"); }
	glCompressedTextureSubImage3D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)load("glCompressedTextureSubImage3D");
	if (!glCompressedTextureSubImage3D) { print_msg("glCompressedTextureSubImage3D not loaded"); }
	glCopyTextureSubImage1D = (PFNGLCOPYTEXTURESUBIMAGE1DPROC)load("glCopyTextureSubImage1D");
	if (!glCopyTextureSubImage1D) { print_msg("glCopyTextureSubImage1D not loaded"); }
	glCopyTextureSubImage2D = (PFNGLCOPYTEXTURESUBIMAGE2DPROC)load("glCopyTextureSubImage2D");
	if (!glCopyTextureSubImage2D) { print_msg("glCopyTextureSubImage2D not loaded"); }
	glCopyTextureSubImage3D = (PFNGLCOPYTEXTURESUBIMAGE3DPROC)load("glCopyTextureSubImage3D");
	if (!glCopyTextureSubImage3D) { print_msg("glCopyTextureSubImage3D not loaded"); }
	glTextureParameterf = (PFNGLTEXTUREPARAMETERFPROC)load("glTextureParameterf");
	if (!glTextureParameterf) { print_msg("glTextureParameterf not loaded"); }
	glTextureParameterfv = (PFNGLTEXTUREPARAMETERFVPROC)load("glTextureParameterfv");
	if (!glTextureParameterfv) { print_msg("glTextureParameterfv not loaded"); }
	glTextureParameteri = (PFNGLTEXTUREPARAMETERIPROC)load("glTextureParameteri");
	if (!glTextureParameteri) { print_msg("glTextureParameteri not loaded"); }
	glTextureParameterIiv = (PFNGLTEXTUREPARAMETERIIVPROC)load("glTextureParameterIiv");
	if (!glTextureParameterIiv) { print_msg("glTextureParameterIiv not loaded"); }
	glTextureParameterIuiv = (PFNGLTEXTUREPARAMETERIUIVPROC)load("glTextureParameterIuiv");
	if (!glTextureParameterIuiv) { print_msg("glTextureParameterIuiv not loaded"); }
	glTextureParameteriv = (PFNGLTEXTUREPARAMETERIVPROC)load("glTextureParameteriv");
	if (!glTextureParameteriv) { print_msg("glTextureParameteriv not loaded"); }
	glGenerateTextureMipmap = (PFNGLGENERATETEXTUREMIPMAPPROC)load("glGenerateTextureMipmap");
	if (!glGenerateTextureMipmap) { print_msg("glGenerateTextureMipmap not loaded"); }
	glBindTextureUnit = (PFNGLBINDTEXTUREUNITPROC)load("glBindTextureUnit");
	if (!glBindTextureUnit) { print_msg("glBindTextureUnit not loaded"); }
	glGetTextureImage = (PFNGLGETTEXTUREIMAGEPROC)load("glGetTextureImage");
	if (!glGetTextureImage) { print_msg("glGetTextureImage not loaded"); }
	glGetCompressedTextureImage = (PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)load("glGetCompressedTextureImage");
	if (!glGetCompressedTextureImage) { print_msg("glGetCompressedTextureImage not loaded"); }
	glGetTextureLevelParameterfv = (PFNGLGETTEXTURELEVELPARAMETERFVPROC)load("glGetTextureLevelParameterfv");
	if (!glGetTextureLevelParameterfv) { print_msg("glGetTextureLevelParameterfv not loaded"); }
	glGetTextureLevelParameteriv = (PFNGLGETTEXTURELEVELPARAMETERIVPROC)load("glGetTextureLevelParameteriv");
	if (!glGetTextureLevelParameteriv) { print_msg("glGetTextureLevelParameteriv not loaded"); }
	glGetTextureParameterfv = (PFNGLGETTEXTUREPARAMETERFVPROC)load("glGetTextureParameterfv");
	if (!glGetTextureParameterfv) { print_msg("glGetTextureParameterfv not loaded"); }
	glGetTextureParameterIiv = (PFNGLGETTEXTUREPARAMETERIIVPROC)load("glGetTextureParameterIiv");
	if (!glGetTextureParameterIiv) { print_msg("glGetTextureParameterIiv not loaded"); }
	glGetTextureParameterIuiv = (PFNGLGETTEXTUREPARAMETERIUIVPROC)load("glGetTextureParameterIuiv");
	if (!glGetTextureParameterIuiv) { print_msg("glGetTextureParameterIuiv not loaded"); }
	glGetTextureParameteriv = (PFNGLGETTEXTUREPARAMETERIVPROC)load("glGetTextureParameteriv");
	if (!glGetTextureParameteriv) { print_msg("glGetTextureParameteriv not loaded"); }
	glCreateVertexArrays = (PFNGLCREATEVERTEXARRAYSPROC)load("glCreateVertexArrays");
	if (!glCreateVertexArrays) { print_msg("glCreateVertexArrays not loaded"); }
	glDisableVertexArrayAttrib = (PFNGLDISABLEVERTEXARRAYATTRIBPROC)load("glDisableVertexArrayAttrib");
	if (!glDisableVertexArrayAttrib) { print_msg("glDisableVertexArrayAttrib not loaded"); }
	glEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIBPROC)load("glEnableVertexArrayAttrib");
	if (!glEnableVertexArrayAttrib) { print_msg("glEnableVertexArrayAttrib not loaded"); }
	glVertexArrayElementBuffer = (PFNGLVERTEXARRAYELEMENTBUFFERPROC)load("glVertexArrayElementBuffer");
	if (!glVertexArrayElementBuffer) { print_msg("glVertexArrayElementBuffer not loaded"); }
	glVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)load("glVertexArrayVertexBuffer");
	if (!glVertexArrayVertexBuffer) { print_msg("glVertexArrayVertexBuffer not loaded"); }
	glVertexArrayVertexBuffers = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC)load("glVertexArrayVertexBuffers");
	if (!glVertexArrayVertexBuffers) { print_msg("glVertexArrayVertexBuffers not loaded"); }
	glVertexArrayAttribBinding = (PFNGLVERTEXARRAYATTRIBBINDINGPROC)load("glVertexArrayAttribBinding");
	if (!glVertexArrayAttribBinding) { print_msg("glVertexArrayAttribBinding not loaded"); }
	glVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMATPROC)load("glVertexArrayAttribFormat");
	if (!glVertexArrayAttribFormat) { print_msg("glVertexArrayAttribFormat not loaded"); }
	glVertexArrayAttribIFormat = (PFNGLVERTEXARRAYATTRIBIFORMATPROC)load("glVertexArrayAttribIFormat");
	if (!glVertexArrayAttribIFormat) { print_msg("glVertexArrayAttribIFormat not loaded"); }
	glVertexArrayAttribLFormat = (PFNGLVERTEXARRAYATTRIBLFORMATPROC)load("glVertexArrayAttribLFormat");
	if (!glVertexArrayAttribLFormat) { print_msg("glVertexArrayAttribLFormat not loaded"); }
	glVertexArrayBindingDivisor = (PFNGLVERTEXARRAYBINDINGDIVISORPROC)load("glVertexArrayBindingDivisor");
	if (!glVertexArrayBindingDivisor) { print_msg("glVertexArrayBindingDivisor not loaded"); }
	glGetVertexArrayiv = (PFNGLGETVERTEXARRAYIVPROC)load("glGetVertexArrayiv");
	if (!glGetVertexArrayiv) { print_msg("glGetVertexArrayiv not loaded"); }
	glGetVertexArrayIndexediv = (PFNGLGETVERTEXARRAYINDEXEDIVPROC)load("glGetVertexArrayIndexediv");
	if (!glGetVertexArrayIndexediv) { print_msg("glGetVertexArrayIndexediv not loaded"); }
	glGetVertexArrayIndexed64iv = (PFNGLGETVERTEXARRAYINDEXED64IVPROC)load("glGetVertexArrayIndexed64iv");
	if (!glGetVertexArrayIndexed64iv) { print_msg("glGetVertexArrayIndexed64iv not loaded"); }
	glCreateSamplers = (PFNGLCREATESAMPLERSPROC)load("glCreateSamplers");
	if (!glCreateSamplers) { print_msg("glCreateSamplers not loaded"); }
	glCreateProgramPipelines = (PFNGLCREATEPROGRAMPIPELINESPROC)load("glCreateProgramPipelines");
	if (!glCreateProgramPipelines) { print_msg("glCreateProgramPipelines not loaded"); }
	glCreateQueries = (PFNGLCREATEQUERIESPROC)load("glCreateQueries");
	if (!glCreateQueries) { print_msg("glCreateQueries not loaded"); }
	glGetQueryBufferObjecti64v = (PFNGLGETQUERYBUFFEROBJECTI64VPROC)load("glGetQueryBufferObjecti64v");
	if (!glGetQueryBufferObjecti64v) { print_msg("glGetQueryBufferObjecti64v not loaded"); }
	glGetQueryBufferObjectiv = (PFNGLGETQUERYBUFFEROBJECTIVPROC)load("glGetQueryBufferObjectiv");
	if (!glGetQueryBufferObjectiv) { print_msg("glGetQueryBufferObjectiv not loaded"); }
	glGetQueryBufferObjectui64v = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC)load("glGetQueryBufferObjectui64v");
	if (!glGetQueryBufferObjectui64v) { print_msg("glGetQueryBufferObjectui64v not loaded"); }
	glGetQueryBufferObjectuiv = (PFNGLGETQUERYBUFFEROBJECTUIVPROC)load("glGetQueryBufferObjectuiv");
	if (!glGetQueryBufferObjectuiv) { print_msg("glGetQueryBufferObjectuiv not loaded"); }
	glMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGIONPROC)load("glMemoryBarrierByRegion");
	if (!glMemoryBarrierByRegion) { print_msg("glMemoryBarrierByRegion not loaded"); }
	glGetTextureSubImage = (PFNGLGETTEXTURESUBIMAGEPROC)load("glGetTextureSubImage");
	if (!glGetTextureSubImage) { print_msg("glGetTextureSubImage not loaded"); }
	glGetCompressedTextureSubImage = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)load("glGetCompressedTextureSubImage");
	if (!glGetCompressedTextureSubImage) { print_msg("glGetCompressedTextureSubImage not loaded"); }
	glGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUSPROC)load("glGetGraphicsResetStatus");
	if (!glGetGraphicsResetStatus) { print_msg("glGetGraphicsResetStatus not loaded"); }
	glGetnCompressedTexImage = (PFNGLGETNCOMPRESSEDTEXIMAGEPROC)load("glGetnCompressedTexImage");
	if (!glGetnCompressedTexImage) { print_msg("glGetnCompressedTexImage not loaded"); }
	glGetnTexImage = (PFNGLGETNTEXIMAGEPROC)load("glGetnTexImage");
	if (!glGetnTexImage) { print_msg("glGetnTexImage not loaded"); }
	glGetnUniformdv = (PFNGLGETNUNIFORMDVPROC)load("glGetnUniformdv");
	if (!glGetnUniformdv) { print_msg("glGetnUniformdv not loaded"); }
	glGetnUniformfv = (PFNGLGETNUNIFORMFVPROC)load("glGetnUniformfv");
	if (!glGetnUniformfv) { print_msg("glGetnUniformfv not loaded"); }
	glGetnUniformiv = (PFNGLGETNUNIFORMIVPROC)load("glGetnUniformiv");
	if (!glGetnUniformiv) { print_msg("glGetnUniformiv not loaded"); }
	glGetnUniformuiv = (PFNGLGETNUNIFORMUIVPROC)load("glGetnUniformuiv");
	if (!glGetnUniformuiv) { print_msg("glGetnUniformuiv not loaded"); }
	glReadnPixels = (PFNGLREADNPIXELSPROC)load("glReadnPixels");
	if (!glReadnPixels) { print_msg("glReadnPixels not loaded"); }
	glGetnMapdv = (PFNGLGETNMAPDVPROC)load("glGetnMapdv");
	if (!glGetnMapdv) { print_msg("glGetnMapdv not loaded"); }
	glGetnMapfv = (PFNGLGETNMAPFVPROC)load("glGetnMapfv");
	if (!glGetnMapfv) { print_msg("glGetnMapfv not loaded"); }
	glGetnMapiv = (PFNGLGETNMAPIVPROC)load("glGetnMapiv");
	if (!glGetnMapiv) { print_msg("glGetnMapiv not loaded"); }
	glGetnPixelMapfv = (PFNGLGETNPIXELMAPFVPROC)load("glGetnPixelMapfv");
	if (!glGetnPixelMapfv) { print_msg("glGetnPixelMapfv not loaded"); }
	glGetnPixelMapuiv = (PFNGLGETNPIXELMAPUIVPROC)load("glGetnPixelMapuiv");
	if (!glGetnPixelMapuiv) { print_msg("glGetnPixelMapuiv not loaded"); }
	glGetnPixelMapusv = (PFNGLGETNPIXELMAPUSVPROC)load("glGetnPixelMapusv");
	if (!glGetnPixelMapusv) { print_msg("glGetnPixelMapusv not loaded"); }
	glGetnPolygonStipple = (PFNGLGETNPOLYGONSTIPPLEPROC)load("glGetnPolygonStipple");
	if (!glGetnPolygonStipple) { print_msg("glGetnPolygonStipple not loaded"); }
	glGetnColorTable = (PFNGLGETNCOLORTABLEPROC)load("glGetnColorTable");
	if (!glGetnColorTable) { print_msg("glGetnColorTable not loaded"); }
	glGetnConvolutionFilter = (PFNGLGETNCONVOLUTIONFILTERPROC)load("glGetnConvolutionFilter");
	if (!glGetnConvolutionFilter) { print_msg("glGetnConvolutionFilter not loaded"); }
	glGetnSeparableFilter = (PFNGLGETNSEPARABLEFILTERPROC)load("glGetnSeparableFilter");
	if (!glGetnSeparableFilter) { print_msg("glGetnSeparableFilter not loaded"); }
	glGetnHistogram = (PFNGLGETNHISTOGRAMPROC)load("glGetnHistogram");
	if (!glGetnHistogram) { print_msg("glGetnHistogram not loaded"); }
	glGetnMinmax = (PFNGLGETNMINMAXPROC)load("glGetnMinmax");
	if (!glGetnMinmax) { print_msg("glGetnMinmax not loaded"); }
	glTextureBarrier = (PFNGLTEXTUREBARRIERPROC)load("glTextureBarrier");
	if (!glTextureBarrier) { print_msg("glTextureBarrier not loaded"); }
}


void glfnlib_init_GL_VERSION_4_6(PFN_loadfunc_gl load) {
	glSpecializeShader = (PFNGLSPECIALIZESHADERPROC)load("glSpecializeShader");
	if (!glSpecializeShader) { print_msg("glSpecializeShader not loaded"); }
	glMultiDrawArraysIndirectCount = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)load("glMultiDrawArraysIndirectCount");
	if (!glMultiDrawArraysIndirectCount) { print_msg("glMultiDrawArraysIndirectCount not loaded"); }
	glMultiDrawElementsIndirectCount = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)load("glMultiDrawElementsIndirectCount");
	if (!glMultiDrawElementsIndirectCount) { print_msg("glMultiDrawElementsIndirectCount not loaded"); }
	glPolygonOffsetClamp = (PFNGLPOLYGONOFFSETCLAMPPROC)load("glPolygonOffsetClamp");
	if (!glPolygonOffsetClamp) { print_msg("glPolygonOffsetClamp not loaded"); }
}


void glfnlib_load(PFN_loadfunc_gl load) {
	glfnlib_init_GL_VERSION_1_0(load);
	glfnlib_init_GL_VERSION_1_2(load);
	glfnlib_init_GL_VERSION_1_3(load);
	glfnlib_init_GL_VERSION_1_4(load);
	glfnlib_init_GL_VERSION_1_5(load);
	glfnlib_init_GL_VERSION_2_0(load);
	glfnlib_init_GL_VERSION_2_1(load);
	glfnlib_init_GL_VERSION_3_0(load);
	glfnlib_init_GL_VERSION_3_1(load);
	glfnlib_init_GL_VERSION_3_2(load);
	glfnlib_init_GL_VERSION_3_3(load);
	glfnlib_init_GL_VERSION_4_0(load);
	glfnlib_init_GL_VERSION_4_1(load);
	glfnlib_init_GL_VERSION_4_2(load);
	glfnlib_init_GL_VERSION_4_3(load);
	glfnlib_init_GL_VERSION_4_4(load);
	glfnlib_init_GL_VERSION_4_5(load);
	glfnlib_init_GL_VERSION_4_6(load);
}
