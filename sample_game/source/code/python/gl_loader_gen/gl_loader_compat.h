#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <gl/gl.h>
#include <glext.h>


typedef void (*PFN_apiproc)(void);
typedef PFN_apiproc (*PFN_loadfunc_gl)(const char *name);

//#define GL_LOADER_COMPAT_PRINT_ERRORS

// GL_VERSION_1_0
typedef void (APIENTRYP PFNGLACCUMPROC) (GLenum op, GLfloat value);
typedef void (APIENTRYP PFNGLALPHAFUNCPROC) (GLenum func, GLclampf ref);
typedef GLboolean (APIENTRYP PFNGLARETEXTURESRESIDENTPROC) (GLsizei n, const GLuint *textures, GLboolean *residences);
typedef void (APIENTRYP PFNGLARRAYELEMENTPROC) (GLint i);
typedef void (APIENTRYP PFNGLBEGINPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC) (GLenum target, GLuint texture);
typedef void (APIENTRYP PFNGLBITMAPPROC) (GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
typedef void (APIENTRYP PFNGLBLENDFUNCPROC) (GLenum sfactor, GLenum dfactor);
typedef void (APIENTRYP PFNGLCALLLISTPROC) (GLuint list);
typedef void (APIENTRYP PFNGLCALLLISTSPROC) (GLsizei n, GLenum type, const GLvoid *lists);
typedef void (APIENTRYP PFNGLCLEARPROC) (GLbitfield mask);
typedef void (APIENTRYP PFNGLCLEARACCUMPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLCLEARCOLORPROC) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
typedef void (APIENTRYP PFNGLCLEARDEPTHPROC) (GLclampd depth);
typedef void (APIENTRYP PFNGLCLEARINDEXPROC) (GLfloat c);
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC) (GLint s);
typedef void (APIENTRYP PFNGLCLIPPLANEPROC) (GLenum plane, const GLdouble *equation);
typedef void (APIENTRYP PFNGLCOLOR3BPROC) (GLbyte red, GLbyte green, GLbyte blue);
typedef void (APIENTRYP PFNGLCOLOR3BVPROC) (const GLbyte *v);
typedef void (APIENTRYP PFNGLCOLOR3DPROC) (GLdouble red, GLdouble green, GLdouble blue);
typedef void (APIENTRYP PFNGLCOLOR3DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLCOLOR3FPROC) (GLfloat red, GLfloat green, GLfloat blue);
typedef void (APIENTRYP PFNGLCOLOR3FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLCOLOR3IPROC) (GLint red, GLint green, GLint blue);
typedef void (APIENTRYP PFNGLCOLOR3IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLCOLOR3SPROC) (GLshort red, GLshort green, GLshort blue);
typedef void (APIENTRYP PFNGLCOLOR3SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLCOLOR3UBPROC) (GLubyte red, GLubyte green, GLubyte blue);
typedef void (APIENTRYP PFNGLCOLOR3UBVPROC) (const GLubyte *v);
typedef void (APIENTRYP PFNGLCOLOR3UIPROC) (GLuint red, GLuint green, GLuint blue);
typedef void (APIENTRYP PFNGLCOLOR3UIVPROC) (const GLuint *v);
typedef void (APIENTRYP PFNGLCOLOR3USPROC) (GLushort red, GLushort green, GLushort blue);
typedef void (APIENTRYP PFNGLCOLOR3USVPROC) (const GLushort *v);
typedef void (APIENTRYP PFNGLCOLOR4BPROC) (GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
typedef void (APIENTRYP PFNGLCOLOR4BVPROC) (const GLbyte *v);
typedef void (APIENTRYP PFNGLCOLOR4DPROC) (GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
typedef void (APIENTRYP PFNGLCOLOR4DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLCOLOR4FPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLCOLOR4FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLCOLOR4IPROC) (GLint red, GLint green, GLint blue, GLint alpha);
typedef void (APIENTRYP PFNGLCOLOR4IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLCOLOR4SPROC) (GLshort red, GLshort green, GLshort blue, GLshort alpha);
typedef void (APIENTRYP PFNGLCOLOR4SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLCOLOR4UBPROC) (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
typedef void (APIENTRYP PFNGLCOLOR4UBVPROC) (const GLubyte *v);
typedef void (APIENTRYP PFNGLCOLOR4UIPROC) (GLuint red, GLuint green, GLuint blue, GLuint alpha);
typedef void (APIENTRYP PFNGLCOLOR4UIVPROC) (const GLuint *v);
typedef void (APIENTRYP PFNGLCOLOR4USPROC) (GLushort red, GLushort green, GLushort blue, GLushort alpha);
typedef void (APIENTRYP PFNGLCOLOR4USVPROC) (const GLushort *v);
typedef void (APIENTRYP PFNGLCOLORMASKPROC) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (APIENTRYP PFNGLCOLORMATERIALPROC) (GLenum face, GLenum mode);
typedef void (APIENTRYP PFNGLCOLORPOINTERPROC) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (APIENTRYP PFNGLCOPYPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCULLFACEPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLDELETELISTSPROC) (GLuint list, GLsizei range);
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC) (GLsizei n, const GLuint *textures);
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC) (GLenum func);
typedef void (APIENTRYP PFNGLDEPTHMASKPROC) (GLboolean flag);
typedef void (APIENTRYP PFNGLDEPTHRANGEPROC) (GLclampd zNear, GLclampd zFar);
typedef void (APIENTRYP PFNGLDISABLEPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEPROC) (GLenum array);
typedef void (APIENTRYP PFNGLDRAWARRAYSPROC) (GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLDRAWBUFFERPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
typedef void (APIENTRYP PFNGLDRAWPIXELSPROC) (GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (APIENTRYP PFNGLEDGEFLAGPROC) (GLboolean flag);
typedef void (APIENTRYP PFNGLEDGEFLAGPOINTERPROC) (GLsizei stride, const GLvoid *pointer);
typedef void (APIENTRYP PFNGLEDGEFLAGVPROC) (const GLboolean *flag);
typedef void (APIENTRYP PFNGLENABLEPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEPROC) (GLenum array);
typedef void (APIENTRYP PFNGLENDPROC) (void);
typedef void (APIENTRYP PFNGLENDLISTPROC) (void);
typedef void (APIENTRYP PFNGLEVALCOORD1DPROC) (GLdouble u);
typedef void (APIENTRYP PFNGLEVALCOORD1DVPROC) (const GLdouble *u);
typedef void (APIENTRYP PFNGLEVALCOORD1FPROC) (GLfloat u);
typedef void (APIENTRYP PFNGLEVALCOORD1FVPROC) (const GLfloat *u);
typedef void (APIENTRYP PFNGLEVALCOORD2DPROC) (GLdouble u, GLdouble v);
typedef void (APIENTRYP PFNGLEVALCOORD2DVPROC) (const GLdouble *u);
typedef void (APIENTRYP PFNGLEVALCOORD2FPROC) (GLfloat u, GLfloat v);
typedef void (APIENTRYP PFNGLEVALCOORD2FVPROC) (const GLfloat *u);
typedef void (APIENTRYP PFNGLEVALMESH1PROC) (GLenum mode, GLint i1, GLint i2);
typedef void (APIENTRYP PFNGLEVALMESH2PROC) (GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
typedef void (APIENTRYP PFNGLEVALPOINT1PROC) (GLint i);
typedef void (APIENTRYP PFNGLEVALPOINT2PROC) (GLint i, GLint j);
typedef void (APIENTRYP PFNGLFEEDBACKBUFFERPROC) (GLsizei size, GLenum type, GLfloat *buffer);
typedef void (APIENTRYP PFNGLFINISHPROC) (void);
typedef void (APIENTRYP PFNGLFLUSHPROC) (void);
typedef void (APIENTRYP PFNGLFOGFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLFOGFVPROC) (GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLFOGIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLFOGIVPROC) (GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLFRONTFACEPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLFRUSTUMPROC) (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef GLuint (APIENTRYP PFNGLGENLISTSPROC) (GLsizei range);
typedef void (APIENTRYP PFNGLGENTEXTURESPROC) (GLsizei n, GLuint *textures);
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC) (GLenum pname, GLboolean *params);
typedef void (APIENTRYP PFNGLGETCLIPPLANEPROC) (GLenum plane, GLdouble *equation);
typedef void (APIENTRYP PFNGLGETDOUBLEVPROC) (GLenum pname, GLdouble *params);
typedef GLenum (APIENTRYP PFNGLGETERRORPROC) (void);
typedef void (APIENTRYP PFNGLGETFLOATVPROC) (GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETINTEGERVPROC) (GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETLIGHTFVPROC) (GLenum light, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETLIGHTIVPROC) (GLenum light, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETMAPDVPROC) (GLenum target, GLenum query, GLdouble *v);
typedef void (APIENTRYP PFNGLGETMAPFVPROC) (GLenum target, GLenum query, GLfloat *v);
typedef void (APIENTRYP PFNGLGETMAPIVPROC) (GLenum target, GLenum query, GLint *v);
typedef void (APIENTRYP PFNGLGETMATERIALFVPROC) (GLenum face, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETMATERIALIVPROC) (GLenum face, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETPIXELMAPFVPROC) (GLenum map, GLfloat *values);
typedef void (APIENTRYP PFNGLGETPIXELMAPUIVPROC) (GLenum map, GLuint *values);
typedef void (APIENTRYP PFNGLGETPIXELMAPUSVPROC) (GLenum map, GLushort *values);
typedef void (APIENTRYP PFNGLGETPOINTERVPROC) (GLenum pname, GLvoid* *params);
typedef void (APIENTRYP PFNGLGETPOLYGONSTIPPLEPROC) (GLubyte *mask);
typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGPROC) (GLenum name);
typedef void (APIENTRYP PFNGLGETTEXENVFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXENVIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXGENDVPROC) (GLenum coord, GLenum pname, GLdouble *params);
typedef void (APIENTRYP PFNGLGETTEXGENFVPROC) (GLenum coord, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXGENIVPROC) (GLenum coord, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC) (GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC) (GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC) (GLenum target, GLint level, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC) (GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLHINTPROC) (GLenum target, GLenum mode);
typedef void (APIENTRYP PFNGLINDEXMASKPROC) (GLuint mask);
typedef void (APIENTRYP PFNGLINDEXPOINTERPROC) (GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (APIENTRYP PFNGLINDEXDPROC) (GLdouble c);
typedef void (APIENTRYP PFNGLINDEXDVPROC) (const GLdouble *c);
typedef void (APIENTRYP PFNGLINDEXFPROC) (GLfloat c);
typedef void (APIENTRYP PFNGLINDEXFVPROC) (const GLfloat *c);
typedef void (APIENTRYP PFNGLINDEXIPROC) (GLint c);
typedef void (APIENTRYP PFNGLINDEXIVPROC) (const GLint *c);
typedef void (APIENTRYP PFNGLINDEXSPROC) (GLshort c);
typedef void (APIENTRYP PFNGLINDEXSVPROC) (const GLshort *c);
typedef void (APIENTRYP PFNGLINDEXUBPROC) (GLubyte c);
typedef void (APIENTRYP PFNGLINDEXUBVPROC) (const GLubyte *c);
typedef void (APIENTRYP PFNGLINITNAMESPROC) (void);
typedef void (APIENTRYP PFNGLINTERLEAVEDARRAYSPROC) (GLenum format, GLsizei stride, const GLvoid *pointer);
typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC) (GLenum cap);
typedef GLboolean (APIENTRYP PFNGLISLISTPROC) (GLuint list);
typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC) (GLuint texture);
typedef void (APIENTRYP PFNGLLIGHTMODELFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLLIGHTMODELFVPROC) (GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLLIGHTMODELIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLLIGHTMODELIVPROC) (GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLLIGHTFPROC) (GLenum light, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLLIGHTFVPROC) (GLenum light, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLLIGHTIPROC) (GLenum light, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLLIGHTIVPROC) (GLenum light, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLLINESTIPPLEPROC) (GLint factor, GLushort pattern);
typedef void (APIENTRYP PFNGLLINEWIDTHPROC) (GLfloat width);
typedef void (APIENTRYP PFNGLLISTBASEPROC) (GLuint base);
typedef void (APIENTRYP PFNGLLOADIDENTITYPROC) (void);
typedef void (APIENTRYP PFNGLLOADMATRIXDPROC) (const GLdouble *m);
typedef void (APIENTRYP PFNGLLOADMATRIXFPROC) (const GLfloat *m);
typedef void (APIENTRYP PFNGLLOADNAMEPROC) (GLuint name);
typedef void (APIENTRYP PFNGLLOGICOPPROC) (GLenum opcode);
typedef void (APIENTRYP PFNGLMAP1DPROC) (GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
typedef void (APIENTRYP PFNGLMAP1FPROC) (GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
typedef void (APIENTRYP PFNGLMAP2DPROC) (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
typedef void (APIENTRYP PFNGLMAP2FPROC) (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
typedef void (APIENTRYP PFNGLMAPGRID1DPROC) (GLint un, GLdouble u1, GLdouble u2);
typedef void (APIENTRYP PFNGLMAPGRID1FPROC) (GLint un, GLfloat u1, GLfloat u2);
typedef void (APIENTRYP PFNGLMAPGRID2DPROC) (GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
typedef void (APIENTRYP PFNGLMAPGRID2FPROC) (GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLMATERIALFPROC) (GLenum face, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLMATERIALFVPROC) (GLenum face, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLMATERIALIPROC) (GLenum face, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLMATERIALIVPROC) (GLenum face, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLMATRIXMODEPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLMULTMATRIXDPROC) (const GLdouble *m);
typedef void (APIENTRYP PFNGLMULTMATRIXFPROC) (const GLfloat *m);
typedef void (APIENTRYP PFNGLNEWLISTPROC) (GLuint list, GLenum mode);
typedef void (APIENTRYP PFNGLNORMAL3BPROC) (GLbyte nx, GLbyte ny, GLbyte nz);
typedef void (APIENTRYP PFNGLNORMAL3BVPROC) (const GLbyte *v);
typedef void (APIENTRYP PFNGLNORMAL3DPROC) (GLdouble nx, GLdouble ny, GLdouble nz);
typedef void (APIENTRYP PFNGLNORMAL3DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLNORMAL3FPROC) (GLfloat nx, GLfloat ny, GLfloat nz);
typedef void (APIENTRYP PFNGLNORMAL3FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLNORMAL3IPROC) (GLint nx, GLint ny, GLint nz);
typedef void (APIENTRYP PFNGLNORMAL3IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLNORMAL3SPROC) (GLshort nx, GLshort ny, GLshort nz);
typedef void (APIENTRYP PFNGLNORMAL3SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLNORMALPOINTERPROC) (GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (APIENTRYP PFNGLORTHOPROC) (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (APIENTRYP PFNGLPASSTHROUGHPROC) (GLfloat token);
typedef void (APIENTRYP PFNGLPIXELMAPFVPROC) (GLenum map, GLsizei mapsize, const GLfloat *values);
typedef void (APIENTRYP PFNGLPIXELMAPUIVPROC) (GLenum map, GLsizei mapsize, const GLuint *values);
typedef void (APIENTRYP PFNGLPIXELMAPUSVPROC) (GLenum map, GLsizei mapsize, const GLushort *values);
typedef void (APIENTRYP PFNGLPIXELSTOREFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPIXELTRANSFERFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPIXELTRANSFERIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPIXELZOOMPROC) (GLfloat xfactor, GLfloat yfactor);
typedef void (APIENTRYP PFNGLPOINTSIZEPROC) (GLfloat size);
typedef void (APIENTRYP PFNGLPOLYGONMODEPROC) (GLenum face, GLenum mode);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC) (GLfloat factor, GLfloat units);
typedef void (APIENTRYP PFNGLPOLYGONSTIPPLEPROC) (const GLubyte *mask);
typedef void (APIENTRYP PFNGLPOPATTRIBPROC) (void);
typedef void (APIENTRYP PFNGLPOPCLIENTATTRIBPROC) (void);
typedef void (APIENTRYP PFNGLPOPMATRIXPROC) (void);
typedef void (APIENTRYP PFNGLPOPNAMEPROC) (void);
typedef void (APIENTRYP PFNGLPRIORITIZETEXTURESPROC) (GLsizei n, const GLuint *textures, const GLclampf *priorities);
typedef void (APIENTRYP PFNGLPUSHATTRIBPROC) (GLbitfield mask);
typedef void (APIENTRYP PFNGLPUSHCLIENTATTRIBPROC) (GLbitfield mask);
typedef void (APIENTRYP PFNGLPUSHMATRIXPROC) (void);
typedef void (APIENTRYP PFNGLPUSHNAMEPROC) (GLuint name);
typedef void (APIENTRYP PFNGLRASTERPOS2DPROC) (GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLRASTERPOS2DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLRASTERPOS2FPROC) (GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLRASTERPOS2FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLRASTERPOS2IPROC) (GLint x, GLint y);
typedef void (APIENTRYP PFNGLRASTERPOS2IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLRASTERPOS2SPROC) (GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLRASTERPOS2SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLRASTERPOS3DPROC) (GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLRASTERPOS3DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLRASTERPOS3FPROC) (GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLRASTERPOS3FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLRASTERPOS3IPROC) (GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLRASTERPOS3IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLRASTERPOS3SPROC) (GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLRASTERPOS3SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLRASTERPOS4DPROC) (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLRASTERPOS4DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLRASTERPOS4FPROC) (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLRASTERPOS4FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLRASTERPOS4IPROC) (GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLRASTERPOS4IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLRASTERPOS4SPROC) (GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLRASTERPOS4SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLREADBUFFERPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLREADPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
typedef void (APIENTRYP PFNGLRECTDPROC) (GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
typedef void (APIENTRYP PFNGLRECTDVPROC) (const GLdouble *v1, const GLdouble *v2);
typedef void (APIENTRYP PFNGLRECTFPROC) (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
typedef void (APIENTRYP PFNGLRECTFVPROC) (const GLfloat *v1, const GLfloat *v2);
typedef void (APIENTRYP PFNGLRECTIPROC) (GLint x1, GLint y1, GLint x2, GLint y2);
typedef void (APIENTRYP PFNGLRECTIVPROC) (const GLint *v1, const GLint *v2);
typedef void (APIENTRYP PFNGLRECTSPROC) (GLshort x1, GLshort y1, GLshort x2, GLshort y2);
typedef void (APIENTRYP PFNGLRECTSVPROC) (const GLshort *v1, const GLshort *v2);
typedef GLint (APIENTRYP PFNGLRENDERMODEPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLROTATEDPROC) (GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLROTATEFPROC) (GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLSCALEDPROC) (GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLSCALEFPROC) (GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLSCISSORPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLSELECTBUFFERPROC) (GLsizei size, GLuint *buffer);
typedef void (APIENTRYP PFNGLSHADEMODELPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC) (GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILMASKPROC) (GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILOPPROC) (GLenum fail, GLenum zfail, GLenum zpass);
typedef void (APIENTRYP PFNGLTEXCOORD1DPROC) (GLdouble s);
typedef void (APIENTRYP PFNGLTEXCOORD1DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLTEXCOORD1FPROC) (GLfloat s);
typedef void (APIENTRYP PFNGLTEXCOORD1FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLTEXCOORD1IPROC) (GLint s);
typedef void (APIENTRYP PFNGLTEXCOORD1IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLTEXCOORD1SPROC) (GLshort s);
typedef void (APIENTRYP PFNGLTEXCOORD1SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLTEXCOORD2DPROC) (GLdouble s, GLdouble t);
typedef void (APIENTRYP PFNGLTEXCOORD2DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLTEXCOORD2FPROC) (GLfloat s, GLfloat t);
typedef void (APIENTRYP PFNGLTEXCOORD2FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLTEXCOORD2IPROC) (GLint s, GLint t);
typedef void (APIENTRYP PFNGLTEXCOORD2IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLTEXCOORD2SPROC) (GLshort s, GLshort t);
typedef void (APIENTRYP PFNGLTEXCOORD2SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLTEXCOORD3DPROC) (GLdouble s, GLdouble t, GLdouble r);
typedef void (APIENTRYP PFNGLTEXCOORD3DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLTEXCOORD3FPROC) (GLfloat s, GLfloat t, GLfloat r);
typedef void (APIENTRYP PFNGLTEXCOORD3FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLTEXCOORD3IPROC) (GLint s, GLint t, GLint r);
typedef void (APIENTRYP PFNGLTEXCOORD3IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLTEXCOORD3SPROC) (GLshort s, GLshort t, GLshort r);
typedef void (APIENTRYP PFNGLTEXCOORD3SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLTEXCOORD4DPROC) (GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (APIENTRYP PFNGLTEXCOORD4DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLTEXCOORD4FPROC) (GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (APIENTRYP PFNGLTEXCOORD4FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLTEXCOORD4IPROC) (GLint s, GLint t, GLint r, GLint q);
typedef void (APIENTRYP PFNGLTEXCOORD4IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLTEXCOORD4SPROC) (GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (APIENTRYP PFNGLTEXCOORD4SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLTEXCOORDPOINTERPROC) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (APIENTRYP PFNGLTEXENVFPROC) (GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXENVFVPROC) (GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLTEXENVIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXENVIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXGENDPROC) (GLenum coord, GLenum pname, GLdouble param);
typedef void (APIENTRYP PFNGLTEXGENDVPROC) (GLenum coord, GLenum pname, const GLdouble *params);
typedef void (APIENTRYP PFNGLTEXGENFPROC) (GLenum coord, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXGENFVPROC) (GLenum coord, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLTEXGENIPROC) (GLenum coord, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXGENIVPROC) (GLenum coord, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXIMAGE1DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC) (GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (APIENTRYP PFNGLTRANSLATEDPROC) (GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLTRANSLATEFPROC) (GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEX2DPROC) (GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEX2DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEX2FPROC) (GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEX2FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEX2IPROC) (GLint x, GLint y);
typedef void (APIENTRYP PFNGLVERTEX2IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLVERTEX2SPROC) (GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLVERTEX2SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEX3DPROC) (GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEX3DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEX3FPROC) (GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEX3FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEX3IPROC) (GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLVERTEX3IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLVERTEX3SPROC) (GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEX3SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEX4DPROC) (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEX4DVPROC) (const GLdouble *v);
typedef void (APIENTRYP PFNGLVERTEX4FPROC) (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLVERTEX4FVPROC) (const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEX4IPROC) (GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLVERTEX4IVPROC) (const GLint *v);
typedef void (APIENTRYP PFNGLVERTEX4SPROC) (GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLVERTEX4SVPROC) (const GLshort *v);
typedef void (APIENTRYP PFNGLVERTEXPOINTERPROC) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (APIENTRYP PFNGLVIEWPORTPROC) (GLint x, GLint y, GLsizei width, GLsizei height);


extern PFNGLACCUMPROC glfn_glAccum;
// WINGDIAPI void APIENTRY glAccum (GLenum op, GLfloat value);
#define glAccum glfn_glAccum
extern PFNGLALPHAFUNCPROC glfn_glAlphaFunc;
// WINGDIAPI void APIENTRY glAlphaFunc (GLenum func, GLclampf ref);
#define glAlphaFunc glfn_glAlphaFunc
extern PFNGLARETEXTURESRESIDENTPROC glfn_glAreTexturesResident;
// WINGDIAPI GLboolean APIENTRY glAreTexturesResident (GLsizei n, const GLuint *textures, GLboolean *residences);
#define glAreTexturesResident glfn_glAreTexturesResident
extern PFNGLARRAYELEMENTPROC glfn_glArrayElement;
// WINGDIAPI void APIENTRY glArrayElement (GLint i);
#define glArrayElement glfn_glArrayElement
extern PFNGLBEGINPROC glfn_glBegin;
// WINGDIAPI void APIENTRY glBegin (GLenum mode);
#define glBegin glfn_glBegin
extern PFNGLBINDTEXTUREPROC glfn_glBindTexture;
// WINGDIAPI void APIENTRY glBindTexture (GLenum target, GLuint texture);
#define glBindTexture glfn_glBindTexture
extern PFNGLBITMAPPROC glfn_glBitmap;
// WINGDIAPI void APIENTRY glBitmap (GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
#define glBitmap glfn_glBitmap
extern PFNGLBLENDFUNCPROC glfn_glBlendFunc;
// WINGDIAPI void APIENTRY glBlendFunc (GLenum sfactor, GLenum dfactor);
#define glBlendFunc glfn_glBlendFunc
extern PFNGLCALLLISTPROC glfn_glCallList;
// WINGDIAPI void APIENTRY glCallList (GLuint list);
#define glCallList glfn_glCallList
extern PFNGLCALLLISTSPROC glfn_glCallLists;
// WINGDIAPI void APIENTRY glCallLists (GLsizei n, GLenum type, const GLvoid *lists);
#define glCallLists glfn_glCallLists
extern PFNGLCLEARPROC glfn_glClear;
// WINGDIAPI void APIENTRY glClear (GLbitfield mask);
#define glClear glfn_glClear
extern PFNGLCLEARACCUMPROC glfn_glClearAccum;
// WINGDIAPI void APIENTRY glClearAccum (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glClearAccum glfn_glClearAccum
extern PFNGLCLEARCOLORPROC glfn_glClearColor;
// WINGDIAPI void APIENTRY glClearColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
#define glClearColor glfn_glClearColor
extern PFNGLCLEARDEPTHPROC glfn_glClearDepth;
// WINGDIAPI void APIENTRY glClearDepth (GLclampd depth);
#define glClearDepth glfn_glClearDepth
extern PFNGLCLEARINDEXPROC glfn_glClearIndex;
// WINGDIAPI void APIENTRY glClearIndex (GLfloat c);
#define glClearIndex glfn_glClearIndex
extern PFNGLCLEARSTENCILPROC glfn_glClearStencil;
// WINGDIAPI void APIENTRY glClearStencil (GLint s);
#define glClearStencil glfn_glClearStencil
extern PFNGLCLIPPLANEPROC glfn_glClipPlane;
// WINGDIAPI void APIENTRY glClipPlane (GLenum plane, const GLdouble *equation);
#define glClipPlane glfn_glClipPlane
extern PFNGLCOLOR3BPROC glfn_glColor3b;
// WINGDIAPI void APIENTRY glColor3b (GLbyte red, GLbyte green, GLbyte blue);
#define glColor3b glfn_glColor3b
extern PFNGLCOLOR3BVPROC glfn_glColor3bv;
// WINGDIAPI void APIENTRY glColor3bv (const GLbyte *v);
#define glColor3bv glfn_glColor3bv
extern PFNGLCOLOR3DPROC glfn_glColor3d;
// WINGDIAPI void APIENTRY glColor3d (GLdouble red, GLdouble green, GLdouble blue);
#define glColor3d glfn_glColor3d
extern PFNGLCOLOR3DVPROC glfn_glColor3dv;
// WINGDIAPI void APIENTRY glColor3dv (const GLdouble *v);
#define glColor3dv glfn_glColor3dv
extern PFNGLCOLOR3FPROC glfn_glColor3f;
// WINGDIAPI void APIENTRY glColor3f (GLfloat red, GLfloat green, GLfloat blue);
#define glColor3f glfn_glColor3f
extern PFNGLCOLOR3FVPROC glfn_glColor3fv;
// WINGDIAPI void APIENTRY glColor3fv (const GLfloat *v);
#define glColor3fv glfn_glColor3fv
extern PFNGLCOLOR3IPROC glfn_glColor3i;
// WINGDIAPI void APIENTRY glColor3i (GLint red, GLint green, GLint blue);
#define glColor3i glfn_glColor3i
extern PFNGLCOLOR3IVPROC glfn_glColor3iv;
// WINGDIAPI void APIENTRY glColor3iv (const GLint *v);
#define glColor3iv glfn_glColor3iv
extern PFNGLCOLOR3SPROC glfn_glColor3s;
// WINGDIAPI void APIENTRY glColor3s (GLshort red, GLshort green, GLshort blue);
#define glColor3s glfn_glColor3s
extern PFNGLCOLOR3SVPROC glfn_glColor3sv;
// WINGDIAPI void APIENTRY glColor3sv (const GLshort *v);
#define glColor3sv glfn_glColor3sv
extern PFNGLCOLOR3UBPROC glfn_glColor3ub;
// WINGDIAPI void APIENTRY glColor3ub (GLubyte red, GLubyte green, GLubyte blue);
#define glColor3ub glfn_glColor3ub
extern PFNGLCOLOR3UBVPROC glfn_glColor3ubv;
// WINGDIAPI void APIENTRY glColor3ubv (const GLubyte *v);
#define glColor3ubv glfn_glColor3ubv
extern PFNGLCOLOR3UIPROC glfn_glColor3ui;
// WINGDIAPI void APIENTRY glColor3ui (GLuint red, GLuint green, GLuint blue);
#define glColor3ui glfn_glColor3ui
extern PFNGLCOLOR3UIVPROC glfn_glColor3uiv;
// WINGDIAPI void APIENTRY glColor3uiv (const GLuint *v);
#define glColor3uiv glfn_glColor3uiv
extern PFNGLCOLOR3USPROC glfn_glColor3us;
// WINGDIAPI void APIENTRY glColor3us (GLushort red, GLushort green, GLushort blue);
#define glColor3us glfn_glColor3us
extern PFNGLCOLOR3USVPROC glfn_glColor3usv;
// WINGDIAPI void APIENTRY glColor3usv (const GLushort *v);
#define glColor3usv glfn_glColor3usv
extern PFNGLCOLOR4BPROC glfn_glColor4b;
// WINGDIAPI void APIENTRY glColor4b (GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
#define glColor4b glfn_glColor4b
extern PFNGLCOLOR4BVPROC glfn_glColor4bv;
// WINGDIAPI void APIENTRY glColor4bv (const GLbyte *v);
#define glColor4bv glfn_glColor4bv
extern PFNGLCOLOR4DPROC glfn_glColor4d;
// WINGDIAPI void APIENTRY glColor4d (GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
#define glColor4d glfn_glColor4d
extern PFNGLCOLOR4DVPROC glfn_glColor4dv;
// WINGDIAPI void APIENTRY glColor4dv (const GLdouble *v);
#define glColor4dv glfn_glColor4dv
extern PFNGLCOLOR4FPROC glfn_glColor4f;
// WINGDIAPI void APIENTRY glColor4f (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glColor4f glfn_glColor4f
extern PFNGLCOLOR4FVPROC glfn_glColor4fv;
// WINGDIAPI void APIENTRY glColor4fv (const GLfloat *v);
#define glColor4fv glfn_glColor4fv
extern PFNGLCOLOR4IPROC glfn_glColor4i;
// WINGDIAPI void APIENTRY glColor4i (GLint red, GLint green, GLint blue, GLint alpha);
#define glColor4i glfn_glColor4i
extern PFNGLCOLOR4IVPROC glfn_glColor4iv;
// WINGDIAPI void APIENTRY glColor4iv (const GLint *v);
#define glColor4iv glfn_glColor4iv
extern PFNGLCOLOR4SPROC glfn_glColor4s;
// WINGDIAPI void APIENTRY glColor4s (GLshort red, GLshort green, GLshort blue, GLshort alpha);
#define glColor4s glfn_glColor4s
extern PFNGLCOLOR4SVPROC glfn_glColor4sv;
// WINGDIAPI void APIENTRY glColor4sv (const GLshort *v);
#define glColor4sv glfn_glColor4sv
extern PFNGLCOLOR4UBPROC glfn_glColor4ub;
// WINGDIAPI void APIENTRY glColor4ub (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
#define glColor4ub glfn_glColor4ub
extern PFNGLCOLOR4UBVPROC glfn_glColor4ubv;
// WINGDIAPI void APIENTRY glColor4ubv (const GLubyte *v);
#define glColor4ubv glfn_glColor4ubv
extern PFNGLCOLOR4UIPROC glfn_glColor4ui;
// WINGDIAPI void APIENTRY glColor4ui (GLuint red, GLuint green, GLuint blue, GLuint alpha);
#define glColor4ui glfn_glColor4ui
extern PFNGLCOLOR4UIVPROC glfn_glColor4uiv;
// WINGDIAPI void APIENTRY glColor4uiv (const GLuint *v);
#define glColor4uiv glfn_glColor4uiv
extern PFNGLCOLOR4USPROC glfn_glColor4us;
// WINGDIAPI void APIENTRY glColor4us (GLushort red, GLushort green, GLushort blue, GLushort alpha);
#define glColor4us glfn_glColor4us
extern PFNGLCOLOR4USVPROC glfn_glColor4usv;
// WINGDIAPI void APIENTRY glColor4usv (const GLushort *v);
#define glColor4usv glfn_glColor4usv
extern PFNGLCOLORMASKPROC glfn_glColorMask;
// WINGDIAPI void APIENTRY glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
#define glColorMask glfn_glColorMask
extern PFNGLCOLORMATERIALPROC glfn_glColorMaterial;
// WINGDIAPI void APIENTRY glColorMaterial (GLenum face, GLenum mode);
#define glColorMaterial glfn_glColorMaterial
extern PFNGLCOLORPOINTERPROC glfn_glColorPointer;
// WINGDIAPI void APIENTRY glColorPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
#define glColorPointer glfn_glColorPointer
extern PFNGLCOPYPIXELSPROC glfn_glCopyPixels;
// WINGDIAPI void APIENTRY glCopyPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
#define glCopyPixels glfn_glCopyPixels
extern PFNGLCOPYTEXIMAGE1DPROC glfn_glCopyTexImage1D;
// WINGDIAPI void APIENTRY glCopyTexImage1D (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border);
#define glCopyTexImage1D glfn_glCopyTexImage1D
extern PFNGLCOPYTEXIMAGE2DPROC glfn_glCopyTexImage2D;
// WINGDIAPI void APIENTRY glCopyTexImage2D (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
#define glCopyTexImage2D glfn_glCopyTexImage2D
extern PFNGLCOPYTEXSUBIMAGE1DPROC glfn_glCopyTexSubImage1D;
// WINGDIAPI void APIENTRY glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
#define glCopyTexSubImage1D glfn_glCopyTexSubImage1D
extern PFNGLCOPYTEXSUBIMAGE2DPROC glfn_glCopyTexSubImage2D;
// WINGDIAPI void APIENTRY glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#define glCopyTexSubImage2D glfn_glCopyTexSubImage2D
extern PFNGLCULLFACEPROC glfn_glCullFace;
// WINGDIAPI void APIENTRY glCullFace (GLenum mode);
#define glCullFace glfn_glCullFace
extern PFNGLDELETELISTSPROC glfn_glDeleteLists;
// WINGDIAPI void APIENTRY glDeleteLists (GLuint list, GLsizei range);
#define glDeleteLists glfn_glDeleteLists
extern PFNGLDELETETEXTURESPROC glfn_glDeleteTextures;
// WINGDIAPI void APIENTRY glDeleteTextures (GLsizei n, const GLuint *textures);
#define glDeleteTextures glfn_glDeleteTextures
extern PFNGLDEPTHFUNCPROC glfn_glDepthFunc;
// WINGDIAPI void APIENTRY glDepthFunc (GLenum func);
#define glDepthFunc glfn_glDepthFunc
extern PFNGLDEPTHMASKPROC glfn_glDepthMask;
// WINGDIAPI void APIENTRY glDepthMask (GLboolean flag);
#define glDepthMask glfn_glDepthMask
extern PFNGLDEPTHRANGEPROC glfn_glDepthRange;
// WINGDIAPI void APIENTRY glDepthRange (GLclampd zNear, GLclampd zFar);
#define glDepthRange glfn_glDepthRange
extern PFNGLDISABLEPROC glfn_glDisable;
// WINGDIAPI void APIENTRY glDisable (GLenum cap);
#define glDisable glfn_glDisable
extern PFNGLDISABLECLIENTSTATEPROC glfn_glDisableClientState;
// WINGDIAPI void APIENTRY glDisableClientState (GLenum array);
#define glDisableClientState glfn_glDisableClientState
extern PFNGLDRAWARRAYSPROC glfn_glDrawArrays;
// WINGDIAPI void APIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count);
#define glDrawArrays glfn_glDrawArrays
extern PFNGLDRAWBUFFERPROC glfn_glDrawBuffer;
// WINGDIAPI void APIENTRY glDrawBuffer (GLenum mode);
#define glDrawBuffer glfn_glDrawBuffer
extern PFNGLDRAWELEMENTSPROC glfn_glDrawElements;
// WINGDIAPI void APIENTRY glDrawElements (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
#define glDrawElements glfn_glDrawElements
extern PFNGLDRAWPIXELSPROC glfn_glDrawPixels;
// WINGDIAPI void APIENTRY glDrawPixels (GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
#define glDrawPixels glfn_glDrawPixels
extern PFNGLEDGEFLAGPROC glfn_glEdgeFlag;
// WINGDIAPI void APIENTRY glEdgeFlag (GLboolean flag);
#define glEdgeFlag glfn_glEdgeFlag
extern PFNGLEDGEFLAGPOINTERPROC glfn_glEdgeFlagPointer;
// WINGDIAPI void APIENTRY glEdgeFlagPointer (GLsizei stride, const GLvoid *pointer);
#define glEdgeFlagPointer glfn_glEdgeFlagPointer
extern PFNGLEDGEFLAGVPROC glfn_glEdgeFlagv;
// WINGDIAPI void APIENTRY glEdgeFlagv (const GLboolean *flag);
#define glEdgeFlagv glfn_glEdgeFlagv
extern PFNGLENABLEPROC glfn_glEnable;
// WINGDIAPI void APIENTRY glEnable (GLenum cap);
#define glEnable glfn_glEnable
extern PFNGLENABLECLIENTSTATEPROC glfn_glEnableClientState;
// WINGDIAPI void APIENTRY glEnableClientState (GLenum array);
#define glEnableClientState glfn_glEnableClientState
extern PFNGLENDPROC glfn_glEnd;
// WINGDIAPI void APIENTRY glEnd (void);
#define glEnd glfn_glEnd
extern PFNGLENDLISTPROC glfn_glEndList;
// WINGDIAPI void APIENTRY glEndList (void);
#define glEndList glfn_glEndList
extern PFNGLEVALCOORD1DPROC glfn_glEvalCoord1d;
// WINGDIAPI void APIENTRY glEvalCoord1d (GLdouble u);
#define glEvalCoord1d glfn_glEvalCoord1d
extern PFNGLEVALCOORD1DVPROC glfn_glEvalCoord1dv;
// WINGDIAPI void APIENTRY glEvalCoord1dv (const GLdouble *u);
#define glEvalCoord1dv glfn_glEvalCoord1dv
extern PFNGLEVALCOORD1FPROC glfn_glEvalCoord1f;
// WINGDIAPI void APIENTRY glEvalCoord1f (GLfloat u);
#define glEvalCoord1f glfn_glEvalCoord1f
extern PFNGLEVALCOORD1FVPROC glfn_glEvalCoord1fv;
// WINGDIAPI void APIENTRY glEvalCoord1fv (const GLfloat *u);
#define glEvalCoord1fv glfn_glEvalCoord1fv
extern PFNGLEVALCOORD2DPROC glfn_glEvalCoord2d;
// WINGDIAPI void APIENTRY glEvalCoord2d (GLdouble u, GLdouble v);
#define glEvalCoord2d glfn_glEvalCoord2d
extern PFNGLEVALCOORD2DVPROC glfn_glEvalCoord2dv;
// WINGDIAPI void APIENTRY glEvalCoord2dv (const GLdouble *u);
#define glEvalCoord2dv glfn_glEvalCoord2dv
extern PFNGLEVALCOORD2FPROC glfn_glEvalCoord2f;
// WINGDIAPI void APIENTRY glEvalCoord2f (GLfloat u, GLfloat v);
#define glEvalCoord2f glfn_glEvalCoord2f
extern PFNGLEVALCOORD2FVPROC glfn_glEvalCoord2fv;
// WINGDIAPI void APIENTRY glEvalCoord2fv (const GLfloat *u);
#define glEvalCoord2fv glfn_glEvalCoord2fv
extern PFNGLEVALMESH1PROC glfn_glEvalMesh1;
// WINGDIAPI void APIENTRY glEvalMesh1 (GLenum mode, GLint i1, GLint i2);
#define glEvalMesh1 glfn_glEvalMesh1
extern PFNGLEVALMESH2PROC glfn_glEvalMesh2;
// WINGDIAPI void APIENTRY glEvalMesh2 (GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
#define glEvalMesh2 glfn_glEvalMesh2
extern PFNGLEVALPOINT1PROC glfn_glEvalPoint1;
// WINGDIAPI void APIENTRY glEvalPoint1 (GLint i);
#define glEvalPoint1 glfn_glEvalPoint1
extern PFNGLEVALPOINT2PROC glfn_glEvalPoint2;
// WINGDIAPI void APIENTRY glEvalPoint2 (GLint i, GLint j);
#define glEvalPoint2 glfn_glEvalPoint2
extern PFNGLFEEDBACKBUFFERPROC glfn_glFeedbackBuffer;
// WINGDIAPI void APIENTRY glFeedbackBuffer (GLsizei size, GLenum type, GLfloat *buffer);
#define glFeedbackBuffer glfn_glFeedbackBuffer
extern PFNGLFINISHPROC glfn_glFinish;
// WINGDIAPI void APIENTRY glFinish (void);
#define glFinish glfn_glFinish
extern PFNGLFLUSHPROC glfn_glFlush;
// WINGDIAPI void APIENTRY glFlush (void);
#define glFlush glfn_glFlush
extern PFNGLFOGFPROC glfn_glFogf;
// WINGDIAPI void APIENTRY glFogf (GLenum pname, GLfloat param);
#define glFogf glfn_glFogf
extern PFNGLFOGFVPROC glfn_glFogfv;
// WINGDIAPI void APIENTRY glFogfv (GLenum pname, const GLfloat *params);
#define glFogfv glfn_glFogfv
extern PFNGLFOGIPROC glfn_glFogi;
// WINGDIAPI void APIENTRY glFogi (GLenum pname, GLint param);
#define glFogi glfn_glFogi
extern PFNGLFOGIVPROC glfn_glFogiv;
// WINGDIAPI void APIENTRY glFogiv (GLenum pname, const GLint *params);
#define glFogiv glfn_glFogiv
extern PFNGLFRONTFACEPROC glfn_glFrontFace;
// WINGDIAPI void APIENTRY glFrontFace (GLenum mode);
#define glFrontFace glfn_glFrontFace
extern PFNGLFRUSTUMPROC glfn_glFrustum;
// WINGDIAPI void APIENTRY glFrustum (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glFrustum glfn_glFrustum
extern PFNGLGENLISTSPROC glfn_glGenLists;
// WINGDIAPI GLuint APIENTRY glGenLists (GLsizei range);
#define glGenLists glfn_glGenLists
extern PFNGLGENTEXTURESPROC glfn_glGenTextures;
// WINGDIAPI void APIENTRY glGenTextures (GLsizei n, GLuint *textures);
#define glGenTextures glfn_glGenTextures
extern PFNGLGETBOOLEANVPROC glfn_glGetBooleanv;
// WINGDIAPI void APIENTRY glGetBooleanv (GLenum pname, GLboolean *params);
#define glGetBooleanv glfn_glGetBooleanv
extern PFNGLGETCLIPPLANEPROC glfn_glGetClipPlane;
// WINGDIAPI void APIENTRY glGetClipPlane (GLenum plane, GLdouble *equation);
#define glGetClipPlane glfn_glGetClipPlane
extern PFNGLGETDOUBLEVPROC glfn_glGetDoublev;
// WINGDIAPI void APIENTRY glGetDoublev (GLenum pname, GLdouble *params);
#define glGetDoublev glfn_glGetDoublev
extern PFNGLGETERRORPROC glfn_glGetError;
// WINGDIAPI GLenum APIENTRY glGetError (void);
#define glGetError glfn_glGetError
extern PFNGLGETFLOATVPROC glfn_glGetFloatv;
// WINGDIAPI void APIENTRY glGetFloatv (GLenum pname, GLfloat *params);
#define glGetFloatv glfn_glGetFloatv
extern PFNGLGETINTEGERVPROC glfn_glGetIntegerv;
// WINGDIAPI void APIENTRY glGetIntegerv (GLenum pname, GLint *params);
#define glGetIntegerv glfn_glGetIntegerv
extern PFNGLGETLIGHTFVPROC glfn_glGetLightfv;
// WINGDIAPI void APIENTRY glGetLightfv (GLenum light, GLenum pname, GLfloat *params);
#define glGetLightfv glfn_glGetLightfv
extern PFNGLGETLIGHTIVPROC glfn_glGetLightiv;
// WINGDIAPI void APIENTRY glGetLightiv (GLenum light, GLenum pname, GLint *params);
#define glGetLightiv glfn_glGetLightiv
extern PFNGLGETMAPDVPROC glfn_glGetMapdv;
// WINGDIAPI void APIENTRY glGetMapdv (GLenum target, GLenum query, GLdouble *v);
#define glGetMapdv glfn_glGetMapdv
extern PFNGLGETMAPFVPROC glfn_glGetMapfv;
// WINGDIAPI void APIENTRY glGetMapfv (GLenum target, GLenum query, GLfloat *v);
#define glGetMapfv glfn_glGetMapfv
extern PFNGLGETMAPIVPROC glfn_glGetMapiv;
// WINGDIAPI void APIENTRY glGetMapiv (GLenum target, GLenum query, GLint *v);
#define glGetMapiv glfn_glGetMapiv
extern PFNGLGETMATERIALFVPROC glfn_glGetMaterialfv;
// WINGDIAPI void APIENTRY glGetMaterialfv (GLenum face, GLenum pname, GLfloat *params);
#define glGetMaterialfv glfn_glGetMaterialfv
extern PFNGLGETMATERIALIVPROC glfn_glGetMaterialiv;
// WINGDIAPI void APIENTRY glGetMaterialiv (GLenum face, GLenum pname, GLint *params);
#define glGetMaterialiv glfn_glGetMaterialiv
extern PFNGLGETPIXELMAPFVPROC glfn_glGetPixelMapfv;
// WINGDIAPI void APIENTRY glGetPixelMapfv (GLenum map, GLfloat *values);
#define glGetPixelMapfv glfn_glGetPixelMapfv
extern PFNGLGETPIXELMAPUIVPROC glfn_glGetPixelMapuiv;
// WINGDIAPI void APIENTRY glGetPixelMapuiv (GLenum map, GLuint *values);
#define glGetPixelMapuiv glfn_glGetPixelMapuiv
extern PFNGLGETPIXELMAPUSVPROC glfn_glGetPixelMapusv;
// WINGDIAPI void APIENTRY glGetPixelMapusv (GLenum map, GLushort *values);
#define glGetPixelMapusv glfn_glGetPixelMapusv
extern PFNGLGETPOINTERVPROC glfn_glGetPointerv;
// WINGDIAPI void APIENTRY glGetPointerv (GLenum pname, GLvoid* *params);
#define glGetPointerv glfn_glGetPointerv
extern PFNGLGETPOLYGONSTIPPLEPROC glfn_glGetPolygonStipple;
// WINGDIAPI void APIENTRY glGetPolygonStipple (GLubyte *mask);
#define glGetPolygonStipple glfn_glGetPolygonStipple
extern PFNGLGETSTRINGPROC glfn_glGetString;
// WINGDIAPI const GLubyte * APIENTRY glGetString (GLenum name);
#define glGetString glfn_glGetString
extern PFNGLGETTEXENVFVPROC glfn_glGetTexEnvfv;
// WINGDIAPI void APIENTRY glGetTexEnvfv (GLenum target, GLenum pname, GLfloat *params);
#define glGetTexEnvfv glfn_glGetTexEnvfv
extern PFNGLGETTEXENVIVPROC glfn_glGetTexEnviv;
// WINGDIAPI void APIENTRY glGetTexEnviv (GLenum target, GLenum pname, GLint *params);
#define glGetTexEnviv glfn_glGetTexEnviv
extern PFNGLGETTEXGENDVPROC glfn_glGetTexGendv;
// WINGDIAPI void APIENTRY glGetTexGendv (GLenum coord, GLenum pname, GLdouble *params);
#define glGetTexGendv glfn_glGetTexGendv
extern PFNGLGETTEXGENFVPROC glfn_glGetTexGenfv;
// WINGDIAPI void APIENTRY glGetTexGenfv (GLenum coord, GLenum pname, GLfloat *params);
#define glGetTexGenfv glfn_glGetTexGenfv
extern PFNGLGETTEXGENIVPROC glfn_glGetTexGeniv;
// WINGDIAPI void APIENTRY glGetTexGeniv (GLenum coord, GLenum pname, GLint *params);
#define glGetTexGeniv glfn_glGetTexGeniv
extern PFNGLGETTEXIMAGEPROC glfn_glGetTexImage;
// WINGDIAPI void APIENTRY glGetTexImage (GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
#define glGetTexImage glfn_glGetTexImage
extern PFNGLGETTEXLEVELPARAMETERFVPROC glfn_glGetTexLevelParameterfv;
// WINGDIAPI void APIENTRY glGetTexLevelParameterfv (GLenum target, GLint level, GLenum pname, GLfloat *params);
#define glGetTexLevelParameterfv glfn_glGetTexLevelParameterfv
extern PFNGLGETTEXLEVELPARAMETERIVPROC glfn_glGetTexLevelParameteriv;
// WINGDIAPI void APIENTRY glGetTexLevelParameteriv (GLenum target, GLint level, GLenum pname, GLint *params);
#define glGetTexLevelParameteriv glfn_glGetTexLevelParameteriv
extern PFNGLGETTEXPARAMETERFVPROC glfn_glGetTexParameterfv;
// WINGDIAPI void APIENTRY glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params);
#define glGetTexParameterfv glfn_glGetTexParameterfv
extern PFNGLGETTEXPARAMETERIVPROC glfn_glGetTexParameteriv;
// WINGDIAPI void APIENTRY glGetTexParameteriv (GLenum target, GLenum pname, GLint *params);
#define glGetTexParameteriv glfn_glGetTexParameteriv
extern PFNGLHINTPROC glfn_glHint;
// WINGDIAPI void APIENTRY glHint (GLenum target, GLenum mode);
#define glHint glfn_glHint
extern PFNGLINDEXMASKPROC glfn_glIndexMask;
// WINGDIAPI void APIENTRY glIndexMask (GLuint mask);
#define glIndexMask glfn_glIndexMask
extern PFNGLINDEXPOINTERPROC glfn_glIndexPointer;
// WINGDIAPI void APIENTRY glIndexPointer (GLenum type, GLsizei stride, const GLvoid *pointer);
#define glIndexPointer glfn_glIndexPointer
extern PFNGLINDEXDPROC glfn_glIndexd;
// WINGDIAPI void APIENTRY glIndexd (GLdouble c);
#define glIndexd glfn_glIndexd
extern PFNGLINDEXDVPROC glfn_glIndexdv;
// WINGDIAPI void APIENTRY glIndexdv (const GLdouble *c);
#define glIndexdv glfn_glIndexdv
extern PFNGLINDEXFPROC glfn_glIndexf;
// WINGDIAPI void APIENTRY glIndexf (GLfloat c);
#define glIndexf glfn_glIndexf
extern PFNGLINDEXFVPROC glfn_glIndexfv;
// WINGDIAPI void APIENTRY glIndexfv (const GLfloat *c);
#define glIndexfv glfn_glIndexfv
extern PFNGLINDEXIPROC glfn_glIndexi;
// WINGDIAPI void APIENTRY glIndexi (GLint c);
#define glIndexi glfn_glIndexi
extern PFNGLINDEXIVPROC glfn_glIndexiv;
// WINGDIAPI void APIENTRY glIndexiv (const GLint *c);
#define glIndexiv glfn_glIndexiv
extern PFNGLINDEXSPROC glfn_glIndexs;
// WINGDIAPI void APIENTRY glIndexs (GLshort c);
#define glIndexs glfn_glIndexs
extern PFNGLINDEXSVPROC glfn_glIndexsv;
// WINGDIAPI void APIENTRY glIndexsv (const GLshort *c);
#define glIndexsv glfn_glIndexsv
extern PFNGLINDEXUBPROC glfn_glIndexub;
// WINGDIAPI void APIENTRY glIndexub (GLubyte c);
#define glIndexub glfn_glIndexub
extern PFNGLINDEXUBVPROC glfn_glIndexubv;
// WINGDIAPI void APIENTRY glIndexubv (const GLubyte *c);
#define glIndexubv glfn_glIndexubv
extern PFNGLINITNAMESPROC glfn_glInitNames;
// WINGDIAPI void APIENTRY glInitNames (void);
#define glInitNames glfn_glInitNames
extern PFNGLINTERLEAVEDARRAYSPROC glfn_glInterleavedArrays;
// WINGDIAPI void APIENTRY glInterleavedArrays (GLenum format, GLsizei stride, const GLvoid *pointer);
#define glInterleavedArrays glfn_glInterleavedArrays
extern PFNGLISENABLEDPROC glfn_glIsEnabled;
// WINGDIAPI GLboolean APIENTRY glIsEnabled (GLenum cap);
#define glIsEnabled glfn_glIsEnabled
extern PFNGLISLISTPROC glfn_glIsList;
// WINGDIAPI GLboolean APIENTRY glIsList (GLuint list);
#define glIsList glfn_glIsList
extern PFNGLISTEXTUREPROC glfn_glIsTexture;
// WINGDIAPI GLboolean APIENTRY glIsTexture (GLuint texture);
#define glIsTexture glfn_glIsTexture
extern PFNGLLIGHTMODELFPROC glfn_glLightModelf;
// WINGDIAPI void APIENTRY glLightModelf (GLenum pname, GLfloat param);
#define glLightModelf glfn_glLightModelf
extern PFNGLLIGHTMODELFVPROC glfn_glLightModelfv;
// WINGDIAPI void APIENTRY glLightModelfv (GLenum pname, const GLfloat *params);
#define glLightModelfv glfn_glLightModelfv
extern PFNGLLIGHTMODELIPROC glfn_glLightModeli;
// WINGDIAPI void APIENTRY glLightModeli (GLenum pname, GLint param);
#define glLightModeli glfn_glLightModeli
extern PFNGLLIGHTMODELIVPROC glfn_glLightModeliv;
// WINGDIAPI void APIENTRY glLightModeliv (GLenum pname, const GLint *params);
#define glLightModeliv glfn_glLightModeliv
extern PFNGLLIGHTFPROC glfn_glLightf;
// WINGDIAPI void APIENTRY glLightf (GLenum light, GLenum pname, GLfloat param);
#define glLightf glfn_glLightf
extern PFNGLLIGHTFVPROC glfn_glLightfv;
// WINGDIAPI void APIENTRY glLightfv (GLenum light, GLenum pname, const GLfloat *params);
#define glLightfv glfn_glLightfv
extern PFNGLLIGHTIPROC glfn_glLighti;
// WINGDIAPI void APIENTRY glLighti (GLenum light, GLenum pname, GLint param);
#define glLighti glfn_glLighti
extern PFNGLLIGHTIVPROC glfn_glLightiv;
// WINGDIAPI void APIENTRY glLightiv (GLenum light, GLenum pname, const GLint *params);
#define glLightiv glfn_glLightiv
extern PFNGLLINESTIPPLEPROC glfn_glLineStipple;
// WINGDIAPI void APIENTRY glLineStipple (GLint factor, GLushort pattern);
#define glLineStipple glfn_glLineStipple
extern PFNGLLINEWIDTHPROC glfn_glLineWidth;
// WINGDIAPI void APIENTRY glLineWidth (GLfloat width);
#define glLineWidth glfn_glLineWidth
extern PFNGLLISTBASEPROC glfn_glListBase;
// WINGDIAPI void APIENTRY glListBase (GLuint base);
#define glListBase glfn_glListBase
extern PFNGLLOADIDENTITYPROC glfn_glLoadIdentity;
// WINGDIAPI void APIENTRY glLoadIdentity (void);
#define glLoadIdentity glfn_glLoadIdentity
extern PFNGLLOADMATRIXDPROC glfn_glLoadMatrixd;
// WINGDIAPI void APIENTRY glLoadMatrixd (const GLdouble *m);
#define glLoadMatrixd glfn_glLoadMatrixd
extern PFNGLLOADMATRIXFPROC glfn_glLoadMatrixf;
// WINGDIAPI void APIENTRY glLoadMatrixf (const GLfloat *m);
#define glLoadMatrixf glfn_glLoadMatrixf
extern PFNGLLOADNAMEPROC glfn_glLoadName;
// WINGDIAPI void APIENTRY glLoadName (GLuint name);
#define glLoadName glfn_glLoadName
extern PFNGLLOGICOPPROC glfn_glLogicOp;
// WINGDIAPI void APIENTRY glLogicOp (GLenum opcode);
#define glLogicOp glfn_glLogicOp
extern PFNGLMAP1DPROC glfn_glMap1d;
// WINGDIAPI void APIENTRY glMap1d (GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
#define glMap1d glfn_glMap1d
extern PFNGLMAP1FPROC glfn_glMap1f;
// WINGDIAPI void APIENTRY glMap1f (GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
#define glMap1f glfn_glMap1f
extern PFNGLMAP2DPROC glfn_glMap2d;
// WINGDIAPI void APIENTRY glMap2d (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
#define glMap2d glfn_glMap2d
extern PFNGLMAP2FPROC glfn_glMap2f;
// WINGDIAPI void APIENTRY glMap2f (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
#define glMap2f glfn_glMap2f
extern PFNGLMAPGRID1DPROC glfn_glMapGrid1d;
// WINGDIAPI void APIENTRY glMapGrid1d (GLint un, GLdouble u1, GLdouble u2);
#define glMapGrid1d glfn_glMapGrid1d
extern PFNGLMAPGRID1FPROC glfn_glMapGrid1f;
// WINGDIAPI void APIENTRY glMapGrid1f (GLint un, GLfloat u1, GLfloat u2);
#define glMapGrid1f glfn_glMapGrid1f
extern PFNGLMAPGRID2DPROC glfn_glMapGrid2d;
// WINGDIAPI void APIENTRY glMapGrid2d (GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
#define glMapGrid2d glfn_glMapGrid2d
extern PFNGLMAPGRID2FPROC glfn_glMapGrid2f;
// WINGDIAPI void APIENTRY glMapGrid2f (GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
#define glMapGrid2f glfn_glMapGrid2f
extern PFNGLMATERIALFPROC glfn_glMaterialf;
// WINGDIAPI void APIENTRY glMaterialf (GLenum face, GLenum pname, GLfloat param);
#define glMaterialf glfn_glMaterialf
extern PFNGLMATERIALFVPROC glfn_glMaterialfv;
// WINGDIAPI void APIENTRY glMaterialfv (GLenum face, GLenum pname, const GLfloat *params);
#define glMaterialfv glfn_glMaterialfv
extern PFNGLMATERIALIPROC glfn_glMateriali;
// WINGDIAPI void APIENTRY glMateriali (GLenum face, GLenum pname, GLint param);
#define glMateriali glfn_glMateriali
extern PFNGLMATERIALIVPROC glfn_glMaterialiv;
// WINGDIAPI void APIENTRY glMaterialiv (GLenum face, GLenum pname, const GLint *params);
#define glMaterialiv glfn_glMaterialiv
extern PFNGLMATRIXMODEPROC glfn_glMatrixMode;
// WINGDIAPI void APIENTRY glMatrixMode (GLenum mode);
#define glMatrixMode glfn_glMatrixMode
extern PFNGLMULTMATRIXDPROC glfn_glMultMatrixd;
// WINGDIAPI void APIENTRY glMultMatrixd (const GLdouble *m);
#define glMultMatrixd glfn_glMultMatrixd
extern PFNGLMULTMATRIXFPROC glfn_glMultMatrixf;
// WINGDIAPI void APIENTRY glMultMatrixf (const GLfloat *m);
#define glMultMatrixf glfn_glMultMatrixf
extern PFNGLNEWLISTPROC glfn_glNewList;
// WINGDIAPI void APIENTRY glNewList (GLuint list, GLenum mode);
#define glNewList glfn_glNewList
extern PFNGLNORMAL3BPROC glfn_glNormal3b;
// WINGDIAPI void APIENTRY glNormal3b (GLbyte nx, GLbyte ny, GLbyte nz);
#define glNormal3b glfn_glNormal3b
extern PFNGLNORMAL3BVPROC glfn_glNormal3bv;
// WINGDIAPI void APIENTRY glNormal3bv (const GLbyte *v);
#define glNormal3bv glfn_glNormal3bv
extern PFNGLNORMAL3DPROC glfn_glNormal3d;
// WINGDIAPI void APIENTRY glNormal3d (GLdouble nx, GLdouble ny, GLdouble nz);
#define glNormal3d glfn_glNormal3d
extern PFNGLNORMAL3DVPROC glfn_glNormal3dv;
// WINGDIAPI void APIENTRY glNormal3dv (const GLdouble *v);
#define glNormal3dv glfn_glNormal3dv
extern PFNGLNORMAL3FPROC glfn_glNormal3f;
// WINGDIAPI void APIENTRY glNormal3f (GLfloat nx, GLfloat ny, GLfloat nz);
#define glNormal3f glfn_glNormal3f
extern PFNGLNORMAL3FVPROC glfn_glNormal3fv;
// WINGDIAPI void APIENTRY glNormal3fv (const GLfloat *v);
#define glNormal3fv glfn_glNormal3fv
extern PFNGLNORMAL3IPROC glfn_glNormal3i;
// WINGDIAPI void APIENTRY glNormal3i (GLint nx, GLint ny, GLint nz);
#define glNormal3i glfn_glNormal3i
extern PFNGLNORMAL3IVPROC glfn_glNormal3iv;
// WINGDIAPI void APIENTRY glNormal3iv (const GLint *v);
#define glNormal3iv glfn_glNormal3iv
extern PFNGLNORMAL3SPROC glfn_glNormal3s;
// WINGDIAPI void APIENTRY glNormal3s (GLshort nx, GLshort ny, GLshort nz);
#define glNormal3s glfn_glNormal3s
extern PFNGLNORMAL3SVPROC glfn_glNormal3sv;
// WINGDIAPI void APIENTRY glNormal3sv (const GLshort *v);
#define glNormal3sv glfn_glNormal3sv
extern PFNGLNORMALPOINTERPROC glfn_glNormalPointer;
// WINGDIAPI void APIENTRY glNormalPointer (GLenum type, GLsizei stride, const GLvoid *pointer);
#define glNormalPointer glfn_glNormalPointer
extern PFNGLORTHOPROC glfn_glOrtho;
// WINGDIAPI void APIENTRY glOrtho (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#define glOrtho glfn_glOrtho
extern PFNGLPASSTHROUGHPROC glfn_glPassThrough;
// WINGDIAPI void APIENTRY glPassThrough (GLfloat token);
#define glPassThrough glfn_glPassThrough
extern PFNGLPIXELMAPFVPROC glfn_glPixelMapfv;
// WINGDIAPI void APIENTRY glPixelMapfv (GLenum map, GLsizei mapsize, const GLfloat *values);
#define glPixelMapfv glfn_glPixelMapfv
extern PFNGLPIXELMAPUIVPROC glfn_glPixelMapuiv;
// WINGDIAPI void APIENTRY glPixelMapuiv (GLenum map, GLsizei mapsize, const GLuint *values);
#define glPixelMapuiv glfn_glPixelMapuiv
extern PFNGLPIXELMAPUSVPROC glfn_glPixelMapusv;
// WINGDIAPI void APIENTRY glPixelMapusv (GLenum map, GLsizei mapsize, const GLushort *values);
#define glPixelMapusv glfn_glPixelMapusv
extern PFNGLPIXELSTOREFPROC glfn_glPixelStoref;
// WINGDIAPI void APIENTRY glPixelStoref (GLenum pname, GLfloat param);
#define glPixelStoref glfn_glPixelStoref
extern PFNGLPIXELSTOREIPROC glfn_glPixelStorei;
// WINGDIAPI void APIENTRY glPixelStorei (GLenum pname, GLint param);
#define glPixelStorei glfn_glPixelStorei
extern PFNGLPIXELTRANSFERFPROC glfn_glPixelTransferf;
// WINGDIAPI void APIENTRY glPixelTransferf (GLenum pname, GLfloat param);
#define glPixelTransferf glfn_glPixelTransferf
extern PFNGLPIXELTRANSFERIPROC glfn_glPixelTransferi;
// WINGDIAPI void APIENTRY glPixelTransferi (GLenum pname, GLint param);
#define glPixelTransferi glfn_glPixelTransferi
extern PFNGLPIXELZOOMPROC glfn_glPixelZoom;
// WINGDIAPI void APIENTRY glPixelZoom (GLfloat xfactor, GLfloat yfactor);
#define glPixelZoom glfn_glPixelZoom
extern PFNGLPOINTSIZEPROC glfn_glPointSize;
// WINGDIAPI void APIENTRY glPointSize (GLfloat size);
#define glPointSize glfn_glPointSize
extern PFNGLPOLYGONMODEPROC glfn_glPolygonMode;
// WINGDIAPI void APIENTRY glPolygonMode (GLenum face, GLenum mode);
#define glPolygonMode glfn_glPolygonMode
extern PFNGLPOLYGONOFFSETPROC glfn_glPolygonOffset;
// WINGDIAPI void APIENTRY glPolygonOffset (GLfloat factor, GLfloat units);
#define glPolygonOffset glfn_glPolygonOffset
extern PFNGLPOLYGONSTIPPLEPROC glfn_glPolygonStipple;
// WINGDIAPI void APIENTRY glPolygonStipple (const GLubyte *mask);
#define glPolygonStipple glfn_glPolygonStipple
extern PFNGLPOPATTRIBPROC glfn_glPopAttrib;
// WINGDIAPI void APIENTRY glPopAttrib (void);
#define glPopAttrib glfn_glPopAttrib
extern PFNGLPOPCLIENTATTRIBPROC glfn_glPopClientAttrib;
// WINGDIAPI void APIENTRY glPopClientAttrib (void);
#define glPopClientAttrib glfn_glPopClientAttrib
extern PFNGLPOPMATRIXPROC glfn_glPopMatrix;
// WINGDIAPI void APIENTRY glPopMatrix (void);
#define glPopMatrix glfn_glPopMatrix
extern PFNGLPOPNAMEPROC glfn_glPopName;
// WINGDIAPI void APIENTRY glPopName (void);
#define glPopName glfn_glPopName
extern PFNGLPRIORITIZETEXTURESPROC glfn_glPrioritizeTextures;
// WINGDIAPI void APIENTRY glPrioritizeTextures (GLsizei n, const GLuint *textures, const GLclampf *priorities);
#define glPrioritizeTextures glfn_glPrioritizeTextures
extern PFNGLPUSHATTRIBPROC glfn_glPushAttrib;
// WINGDIAPI void APIENTRY glPushAttrib (GLbitfield mask);
#define glPushAttrib glfn_glPushAttrib
extern PFNGLPUSHCLIENTATTRIBPROC glfn_glPushClientAttrib;
// WINGDIAPI void APIENTRY glPushClientAttrib (GLbitfield mask);
#define glPushClientAttrib glfn_glPushClientAttrib
extern PFNGLPUSHMATRIXPROC glfn_glPushMatrix;
// WINGDIAPI void APIENTRY glPushMatrix (void);
#define glPushMatrix glfn_glPushMatrix
extern PFNGLPUSHNAMEPROC glfn_glPushName;
// WINGDIAPI void APIENTRY glPushName (GLuint name);
#define glPushName glfn_glPushName
extern PFNGLRASTERPOS2DPROC glfn_glRasterPos2d;
// WINGDIAPI void APIENTRY glRasterPos2d (GLdouble x, GLdouble y);
#define glRasterPos2d glfn_glRasterPos2d
extern PFNGLRASTERPOS2DVPROC glfn_glRasterPos2dv;
// WINGDIAPI void APIENTRY glRasterPos2dv (const GLdouble *v);
#define glRasterPos2dv glfn_glRasterPos2dv
extern PFNGLRASTERPOS2FPROC glfn_glRasterPos2f;
// WINGDIAPI void APIENTRY glRasterPos2f (GLfloat x, GLfloat y);
#define glRasterPos2f glfn_glRasterPos2f
extern PFNGLRASTERPOS2FVPROC glfn_glRasterPos2fv;
// WINGDIAPI void APIENTRY glRasterPos2fv (const GLfloat *v);
#define glRasterPos2fv glfn_glRasterPos2fv
extern PFNGLRASTERPOS2IPROC glfn_glRasterPos2i;
// WINGDIAPI void APIENTRY glRasterPos2i (GLint x, GLint y);
#define glRasterPos2i glfn_glRasterPos2i
extern PFNGLRASTERPOS2IVPROC glfn_glRasterPos2iv;
// WINGDIAPI void APIENTRY glRasterPos2iv (const GLint *v);
#define glRasterPos2iv glfn_glRasterPos2iv
extern PFNGLRASTERPOS2SPROC glfn_glRasterPos2s;
// WINGDIAPI void APIENTRY glRasterPos2s (GLshort x, GLshort y);
#define glRasterPos2s glfn_glRasterPos2s
extern PFNGLRASTERPOS2SVPROC glfn_glRasterPos2sv;
// WINGDIAPI void APIENTRY glRasterPos2sv (const GLshort *v);
#define glRasterPos2sv glfn_glRasterPos2sv
extern PFNGLRASTERPOS3DPROC glfn_glRasterPos3d;
// WINGDIAPI void APIENTRY glRasterPos3d (GLdouble x, GLdouble y, GLdouble z);
#define glRasterPos3d glfn_glRasterPos3d
extern PFNGLRASTERPOS3DVPROC glfn_glRasterPos3dv;
// WINGDIAPI void APIENTRY glRasterPos3dv (const GLdouble *v);
#define glRasterPos3dv glfn_glRasterPos3dv
extern PFNGLRASTERPOS3FPROC glfn_glRasterPos3f;
// WINGDIAPI void APIENTRY glRasterPos3f (GLfloat x, GLfloat y, GLfloat z);
#define glRasterPos3f glfn_glRasterPos3f
extern PFNGLRASTERPOS3FVPROC glfn_glRasterPos3fv;
// WINGDIAPI void APIENTRY glRasterPos3fv (const GLfloat *v);
#define glRasterPos3fv glfn_glRasterPos3fv
extern PFNGLRASTERPOS3IPROC glfn_glRasterPos3i;
// WINGDIAPI void APIENTRY glRasterPos3i (GLint x, GLint y, GLint z);
#define glRasterPos3i glfn_glRasterPos3i
extern PFNGLRASTERPOS3IVPROC glfn_glRasterPos3iv;
// WINGDIAPI void APIENTRY glRasterPos3iv (const GLint *v);
#define glRasterPos3iv glfn_glRasterPos3iv
extern PFNGLRASTERPOS3SPROC glfn_glRasterPos3s;
// WINGDIAPI void APIENTRY glRasterPos3s (GLshort x, GLshort y, GLshort z);
#define glRasterPos3s glfn_glRasterPos3s
extern PFNGLRASTERPOS3SVPROC glfn_glRasterPos3sv;
// WINGDIAPI void APIENTRY glRasterPos3sv (const GLshort *v);
#define glRasterPos3sv glfn_glRasterPos3sv
extern PFNGLRASTERPOS4DPROC glfn_glRasterPos4d;
// WINGDIAPI void APIENTRY glRasterPos4d (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glRasterPos4d glfn_glRasterPos4d
extern PFNGLRASTERPOS4DVPROC glfn_glRasterPos4dv;
// WINGDIAPI void APIENTRY glRasterPos4dv (const GLdouble *v);
#define glRasterPos4dv glfn_glRasterPos4dv
extern PFNGLRASTERPOS4FPROC glfn_glRasterPos4f;
// WINGDIAPI void APIENTRY glRasterPos4f (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glRasterPos4f glfn_glRasterPos4f
extern PFNGLRASTERPOS4FVPROC glfn_glRasterPos4fv;
// WINGDIAPI void APIENTRY glRasterPos4fv (const GLfloat *v);
#define glRasterPos4fv glfn_glRasterPos4fv
extern PFNGLRASTERPOS4IPROC glfn_glRasterPos4i;
// WINGDIAPI void APIENTRY glRasterPos4i (GLint x, GLint y, GLint z, GLint w);
#define glRasterPos4i glfn_glRasterPos4i
extern PFNGLRASTERPOS4IVPROC glfn_glRasterPos4iv;
// WINGDIAPI void APIENTRY glRasterPos4iv (const GLint *v);
#define glRasterPos4iv glfn_glRasterPos4iv
extern PFNGLRASTERPOS4SPROC glfn_glRasterPos4s;
// WINGDIAPI void APIENTRY glRasterPos4s (GLshort x, GLshort y, GLshort z, GLshort w);
#define glRasterPos4s glfn_glRasterPos4s
extern PFNGLRASTERPOS4SVPROC glfn_glRasterPos4sv;
// WINGDIAPI void APIENTRY glRasterPos4sv (const GLshort *v);
#define glRasterPos4sv glfn_glRasterPos4sv
extern PFNGLREADBUFFERPROC glfn_glReadBuffer;
// WINGDIAPI void APIENTRY glReadBuffer (GLenum mode);
#define glReadBuffer glfn_glReadBuffer
extern PFNGLREADPIXELSPROC glfn_glReadPixels;
// WINGDIAPI void APIENTRY glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
#define glReadPixels glfn_glReadPixels
extern PFNGLRECTDPROC glfn_glRectd;
// WINGDIAPI void APIENTRY glRectd (GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
#define glRectd glfn_glRectd
extern PFNGLRECTDVPROC glfn_glRectdv;
// WINGDIAPI void APIENTRY glRectdv (const GLdouble *v1, const GLdouble *v2);
#define glRectdv glfn_glRectdv
extern PFNGLRECTFPROC glfn_glRectf;
// WINGDIAPI void APIENTRY glRectf (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
#define glRectf glfn_glRectf
extern PFNGLRECTFVPROC glfn_glRectfv;
// WINGDIAPI void APIENTRY glRectfv (const GLfloat *v1, const GLfloat *v2);
#define glRectfv glfn_glRectfv
extern PFNGLRECTIPROC glfn_glRecti;
// WINGDIAPI void APIENTRY glRecti (GLint x1, GLint y1, GLint x2, GLint y2);
#define glRecti glfn_glRecti
extern PFNGLRECTIVPROC glfn_glRectiv;
// WINGDIAPI void APIENTRY glRectiv (const GLint *v1, const GLint *v2);
#define glRectiv glfn_glRectiv
extern PFNGLRECTSPROC glfn_glRects;
// WINGDIAPI void APIENTRY glRects (GLshort x1, GLshort y1, GLshort x2, GLshort y2);
#define glRects glfn_glRects
extern PFNGLRECTSVPROC glfn_glRectsv;
// WINGDIAPI void APIENTRY glRectsv (const GLshort *v1, const GLshort *v2);
#define glRectsv glfn_glRectsv
extern PFNGLRENDERMODEPROC glfn_glRenderMode;
// WINGDIAPI GLint APIENTRY glRenderMode (GLenum mode);
#define glRenderMode glfn_glRenderMode
extern PFNGLROTATEDPROC glfn_glRotated;
// WINGDIAPI void APIENTRY glRotated (GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
#define glRotated glfn_glRotated
extern PFNGLROTATEFPROC glfn_glRotatef;
// WINGDIAPI void APIENTRY glRotatef (GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
#define glRotatef glfn_glRotatef
extern PFNGLSCALEDPROC glfn_glScaled;
// WINGDIAPI void APIENTRY glScaled (GLdouble x, GLdouble y, GLdouble z);
#define glScaled glfn_glScaled
extern PFNGLSCALEFPROC glfn_glScalef;
// WINGDIAPI void APIENTRY glScalef (GLfloat x, GLfloat y, GLfloat z);
#define glScalef glfn_glScalef
extern PFNGLSCISSORPROC glfn_glScissor;
// WINGDIAPI void APIENTRY glScissor (GLint x, GLint y, GLsizei width, GLsizei height);
#define glScissor glfn_glScissor
extern PFNGLSELECTBUFFERPROC glfn_glSelectBuffer;
// WINGDIAPI void APIENTRY glSelectBuffer (GLsizei size, GLuint *buffer);
#define glSelectBuffer glfn_glSelectBuffer
extern PFNGLSHADEMODELPROC glfn_glShadeModel;
// WINGDIAPI void APIENTRY glShadeModel (GLenum mode);
#define glShadeModel glfn_glShadeModel
extern PFNGLSTENCILFUNCPROC glfn_glStencilFunc;
// WINGDIAPI void APIENTRY glStencilFunc (GLenum func, GLint ref, GLuint mask);
#define glStencilFunc glfn_glStencilFunc
extern PFNGLSTENCILMASKPROC glfn_glStencilMask;
// WINGDIAPI void APIENTRY glStencilMask (GLuint mask);
#define glStencilMask glfn_glStencilMask
extern PFNGLSTENCILOPPROC glfn_glStencilOp;
// WINGDIAPI void APIENTRY glStencilOp (GLenum fail, GLenum zfail, GLenum zpass);
#define glStencilOp glfn_glStencilOp
extern PFNGLTEXCOORD1DPROC glfn_glTexCoord1d;
// WINGDIAPI void APIENTRY glTexCoord1d (GLdouble s);
#define glTexCoord1d glfn_glTexCoord1d
extern PFNGLTEXCOORD1DVPROC glfn_glTexCoord1dv;
// WINGDIAPI void APIENTRY glTexCoord1dv (const GLdouble *v);
#define glTexCoord1dv glfn_glTexCoord1dv
extern PFNGLTEXCOORD1FPROC glfn_glTexCoord1f;
// WINGDIAPI void APIENTRY glTexCoord1f (GLfloat s);
#define glTexCoord1f glfn_glTexCoord1f
extern PFNGLTEXCOORD1FVPROC glfn_glTexCoord1fv;
// WINGDIAPI void APIENTRY glTexCoord1fv (const GLfloat *v);
#define glTexCoord1fv glfn_glTexCoord1fv
extern PFNGLTEXCOORD1IPROC glfn_glTexCoord1i;
// WINGDIAPI void APIENTRY glTexCoord1i (GLint s);
#define glTexCoord1i glfn_glTexCoord1i
extern PFNGLTEXCOORD1IVPROC glfn_glTexCoord1iv;
// WINGDIAPI void APIENTRY glTexCoord1iv (const GLint *v);
#define glTexCoord1iv glfn_glTexCoord1iv
extern PFNGLTEXCOORD1SPROC glfn_glTexCoord1s;
// WINGDIAPI void APIENTRY glTexCoord1s (GLshort s);
#define glTexCoord1s glfn_glTexCoord1s
extern PFNGLTEXCOORD1SVPROC glfn_glTexCoord1sv;
// WINGDIAPI void APIENTRY glTexCoord1sv (const GLshort *v);
#define glTexCoord1sv glfn_glTexCoord1sv
extern PFNGLTEXCOORD2DPROC glfn_glTexCoord2d;
// WINGDIAPI void APIENTRY glTexCoord2d (GLdouble s, GLdouble t);
#define glTexCoord2d glfn_glTexCoord2d
extern PFNGLTEXCOORD2DVPROC glfn_glTexCoord2dv;
// WINGDIAPI void APIENTRY glTexCoord2dv (const GLdouble *v);
#define glTexCoord2dv glfn_glTexCoord2dv
extern PFNGLTEXCOORD2FPROC glfn_glTexCoord2f;
// WINGDIAPI void APIENTRY glTexCoord2f (GLfloat s, GLfloat t);
#define glTexCoord2f glfn_glTexCoord2f
extern PFNGLTEXCOORD2FVPROC glfn_glTexCoord2fv;
// WINGDIAPI void APIENTRY glTexCoord2fv (const GLfloat *v);
#define glTexCoord2fv glfn_glTexCoord2fv
extern PFNGLTEXCOORD2IPROC glfn_glTexCoord2i;
// WINGDIAPI void APIENTRY glTexCoord2i (GLint s, GLint t);
#define glTexCoord2i glfn_glTexCoord2i
extern PFNGLTEXCOORD2IVPROC glfn_glTexCoord2iv;
// WINGDIAPI void APIENTRY glTexCoord2iv (const GLint *v);
#define glTexCoord2iv glfn_glTexCoord2iv
extern PFNGLTEXCOORD2SPROC glfn_glTexCoord2s;
// WINGDIAPI void APIENTRY glTexCoord2s (GLshort s, GLshort t);
#define glTexCoord2s glfn_glTexCoord2s
extern PFNGLTEXCOORD2SVPROC glfn_glTexCoord2sv;
// WINGDIAPI void APIENTRY glTexCoord2sv (const GLshort *v);
#define glTexCoord2sv glfn_glTexCoord2sv
extern PFNGLTEXCOORD3DPROC glfn_glTexCoord3d;
// WINGDIAPI void APIENTRY glTexCoord3d (GLdouble s, GLdouble t, GLdouble r);
#define glTexCoord3d glfn_glTexCoord3d
extern PFNGLTEXCOORD3DVPROC glfn_glTexCoord3dv;
// WINGDIAPI void APIENTRY glTexCoord3dv (const GLdouble *v);
#define glTexCoord3dv glfn_glTexCoord3dv
extern PFNGLTEXCOORD3FPROC glfn_glTexCoord3f;
// WINGDIAPI void APIENTRY glTexCoord3f (GLfloat s, GLfloat t, GLfloat r);
#define glTexCoord3f glfn_glTexCoord3f
extern PFNGLTEXCOORD3FVPROC glfn_glTexCoord3fv;
// WINGDIAPI void APIENTRY glTexCoord3fv (const GLfloat *v);
#define glTexCoord3fv glfn_glTexCoord3fv
extern PFNGLTEXCOORD3IPROC glfn_glTexCoord3i;
// WINGDIAPI void APIENTRY glTexCoord3i (GLint s, GLint t, GLint r);
#define glTexCoord3i glfn_glTexCoord3i
extern PFNGLTEXCOORD3IVPROC glfn_glTexCoord3iv;
// WINGDIAPI void APIENTRY glTexCoord3iv (const GLint *v);
#define glTexCoord3iv glfn_glTexCoord3iv
extern PFNGLTEXCOORD3SPROC glfn_glTexCoord3s;
// WINGDIAPI void APIENTRY glTexCoord3s (GLshort s, GLshort t, GLshort r);
#define glTexCoord3s glfn_glTexCoord3s
extern PFNGLTEXCOORD3SVPROC glfn_glTexCoord3sv;
// WINGDIAPI void APIENTRY glTexCoord3sv (const GLshort *v);
#define glTexCoord3sv glfn_glTexCoord3sv
extern PFNGLTEXCOORD4DPROC glfn_glTexCoord4d;
// WINGDIAPI void APIENTRY glTexCoord4d (GLdouble s, GLdouble t, GLdouble r, GLdouble q);
#define glTexCoord4d glfn_glTexCoord4d
extern PFNGLTEXCOORD4DVPROC glfn_glTexCoord4dv;
// WINGDIAPI void APIENTRY glTexCoord4dv (const GLdouble *v);
#define glTexCoord4dv glfn_glTexCoord4dv
extern PFNGLTEXCOORD4FPROC glfn_glTexCoord4f;
// WINGDIAPI void APIENTRY glTexCoord4f (GLfloat s, GLfloat t, GLfloat r, GLfloat q);
#define glTexCoord4f glfn_glTexCoord4f
extern PFNGLTEXCOORD4FVPROC glfn_glTexCoord4fv;
// WINGDIAPI void APIENTRY glTexCoord4fv (const GLfloat *v);
#define glTexCoord4fv glfn_glTexCoord4fv
extern PFNGLTEXCOORD4IPROC glfn_glTexCoord4i;
// WINGDIAPI void APIENTRY glTexCoord4i (GLint s, GLint t, GLint r, GLint q);
#define glTexCoord4i glfn_glTexCoord4i
extern PFNGLTEXCOORD4IVPROC glfn_glTexCoord4iv;
// WINGDIAPI void APIENTRY glTexCoord4iv (const GLint *v);
#define glTexCoord4iv glfn_glTexCoord4iv
extern PFNGLTEXCOORD4SPROC glfn_glTexCoord4s;
// WINGDIAPI void APIENTRY glTexCoord4s (GLshort s, GLshort t, GLshort r, GLshort q);
#define glTexCoord4s glfn_glTexCoord4s
extern PFNGLTEXCOORD4SVPROC glfn_glTexCoord4sv;
// WINGDIAPI void APIENTRY glTexCoord4sv (const GLshort *v);
#define glTexCoord4sv glfn_glTexCoord4sv
extern PFNGLTEXCOORDPOINTERPROC glfn_glTexCoordPointer;
// WINGDIAPI void APIENTRY glTexCoordPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
#define glTexCoordPointer glfn_glTexCoordPointer
extern PFNGLTEXENVFPROC glfn_glTexEnvf;
// WINGDIAPI void APIENTRY glTexEnvf (GLenum target, GLenum pname, GLfloat param);
#define glTexEnvf glfn_glTexEnvf
extern PFNGLTEXENVFVPROC glfn_glTexEnvfv;
// WINGDIAPI void APIENTRY glTexEnvfv (GLenum target, GLenum pname, const GLfloat *params);
#define glTexEnvfv glfn_glTexEnvfv
extern PFNGLTEXENVIPROC glfn_glTexEnvi;
// WINGDIAPI void APIENTRY glTexEnvi (GLenum target, GLenum pname, GLint param);
#define glTexEnvi glfn_glTexEnvi
extern PFNGLTEXENVIVPROC glfn_glTexEnviv;
// WINGDIAPI void APIENTRY glTexEnviv (GLenum target, GLenum pname, const GLint *params);
#define glTexEnviv glfn_glTexEnviv
extern PFNGLTEXGENDPROC glfn_glTexGend;
// WINGDIAPI void APIENTRY glTexGend (GLenum coord, GLenum pname, GLdouble param);
#define glTexGend glfn_glTexGend
extern PFNGLTEXGENDVPROC glfn_glTexGendv;
// WINGDIAPI void APIENTRY glTexGendv (GLenum coord, GLenum pname, const GLdouble *params);
#define glTexGendv glfn_glTexGendv
extern PFNGLTEXGENFPROC glfn_glTexGenf;
// WINGDIAPI void APIENTRY glTexGenf (GLenum coord, GLenum pname, GLfloat param);
#define glTexGenf glfn_glTexGenf
extern PFNGLTEXGENFVPROC glfn_glTexGenfv;
// WINGDIAPI void APIENTRY glTexGenfv (GLenum coord, GLenum pname, const GLfloat *params);
#define glTexGenfv glfn_glTexGenfv
extern PFNGLTEXGENIPROC glfn_glTexGeni;
// WINGDIAPI void APIENTRY glTexGeni (GLenum coord, GLenum pname, GLint param);
#define glTexGeni glfn_glTexGeni
extern PFNGLTEXGENIVPROC glfn_glTexGeniv;
// WINGDIAPI void APIENTRY glTexGeniv (GLenum coord, GLenum pname, const GLint *params);
#define glTexGeniv glfn_glTexGeniv
extern PFNGLTEXIMAGE1DPROC glfn_glTexImage1D;
// WINGDIAPI void APIENTRY glTexImage1D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexImage1D glfn_glTexImage1D
extern PFNGLTEXIMAGE2DPROC glfn_glTexImage2D;
// WINGDIAPI void APIENTRY glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexImage2D glfn_glTexImage2D
extern PFNGLTEXPARAMETERFPROC glfn_glTexParameterf;
// WINGDIAPI void APIENTRY glTexParameterf (GLenum target, GLenum pname, GLfloat param);
#define glTexParameterf glfn_glTexParameterf
extern PFNGLTEXPARAMETERFVPROC glfn_glTexParameterfv;
// WINGDIAPI void APIENTRY glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params);
#define glTexParameterfv glfn_glTexParameterfv
extern PFNGLTEXPARAMETERIPROC glfn_glTexParameteri;
// WINGDIAPI void APIENTRY glTexParameteri (GLenum target, GLenum pname, GLint param);
#define glTexParameteri glfn_glTexParameteri
extern PFNGLTEXPARAMETERIVPROC glfn_glTexParameteriv;
// WINGDIAPI void APIENTRY glTexParameteriv (GLenum target, GLenum pname, const GLint *params);
#define glTexParameteriv glfn_glTexParameteriv
extern PFNGLTEXSUBIMAGE1DPROC glfn_glTexSubImage1D;
// WINGDIAPI void APIENTRY glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexSubImage1D glfn_glTexSubImage1D
extern PFNGLTEXSUBIMAGE2DPROC glfn_glTexSubImage2D;
// WINGDIAPI void APIENTRY glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
#define glTexSubImage2D glfn_glTexSubImage2D
extern PFNGLTRANSLATEDPROC glfn_glTranslated;
// WINGDIAPI void APIENTRY glTranslated (GLdouble x, GLdouble y, GLdouble z);
#define glTranslated glfn_glTranslated
extern PFNGLTRANSLATEFPROC glfn_glTranslatef;
// WINGDIAPI void APIENTRY glTranslatef (GLfloat x, GLfloat y, GLfloat z);
#define glTranslatef glfn_glTranslatef
extern PFNGLVERTEX2DPROC glfn_glVertex2d;
// WINGDIAPI void APIENTRY glVertex2d (GLdouble x, GLdouble y);
#define glVertex2d glfn_glVertex2d
extern PFNGLVERTEX2DVPROC glfn_glVertex2dv;
// WINGDIAPI void APIENTRY glVertex2dv (const GLdouble *v);
#define glVertex2dv glfn_glVertex2dv
extern PFNGLVERTEX2FPROC glfn_glVertex2f;
// WINGDIAPI void APIENTRY glVertex2f (GLfloat x, GLfloat y);
#define glVertex2f glfn_glVertex2f
extern PFNGLVERTEX2FVPROC glfn_glVertex2fv;
// WINGDIAPI void APIENTRY glVertex2fv (const GLfloat *v);
#define glVertex2fv glfn_glVertex2fv
extern PFNGLVERTEX2IPROC glfn_glVertex2i;
// WINGDIAPI void APIENTRY glVertex2i (GLint x, GLint y);
#define glVertex2i glfn_glVertex2i
extern PFNGLVERTEX2IVPROC glfn_glVertex2iv;
// WINGDIAPI void APIENTRY glVertex2iv (const GLint *v);
#define glVertex2iv glfn_glVertex2iv
extern PFNGLVERTEX2SPROC glfn_glVertex2s;
// WINGDIAPI void APIENTRY glVertex2s (GLshort x, GLshort y);
#define glVertex2s glfn_glVertex2s
extern PFNGLVERTEX2SVPROC glfn_glVertex2sv;
// WINGDIAPI void APIENTRY glVertex2sv (const GLshort *v);
#define glVertex2sv glfn_glVertex2sv
extern PFNGLVERTEX3DPROC glfn_glVertex3d;
// WINGDIAPI void APIENTRY glVertex3d (GLdouble x, GLdouble y, GLdouble z);
#define glVertex3d glfn_glVertex3d
extern PFNGLVERTEX3DVPROC glfn_glVertex3dv;
// WINGDIAPI void APIENTRY glVertex3dv (const GLdouble *v);
#define glVertex3dv glfn_glVertex3dv
extern PFNGLVERTEX3FPROC glfn_glVertex3f;
// WINGDIAPI void APIENTRY glVertex3f (GLfloat x, GLfloat y, GLfloat z);
#define glVertex3f glfn_glVertex3f
extern PFNGLVERTEX3FVPROC glfn_glVertex3fv;
// WINGDIAPI void APIENTRY glVertex3fv (const GLfloat *v);
#define glVertex3fv glfn_glVertex3fv
extern PFNGLVERTEX3IPROC glfn_glVertex3i;
// WINGDIAPI void APIENTRY glVertex3i (GLint x, GLint y, GLint z);
#define glVertex3i glfn_glVertex3i
extern PFNGLVERTEX3IVPROC glfn_glVertex3iv;
// WINGDIAPI void APIENTRY glVertex3iv (const GLint *v);
#define glVertex3iv glfn_glVertex3iv
extern PFNGLVERTEX3SPROC glfn_glVertex3s;
// WINGDIAPI void APIENTRY glVertex3s (GLshort x, GLshort y, GLshort z);
#define glVertex3s glfn_glVertex3s
extern PFNGLVERTEX3SVPROC glfn_glVertex3sv;
// WINGDIAPI void APIENTRY glVertex3sv (const GLshort *v);
#define glVertex3sv glfn_glVertex3sv
extern PFNGLVERTEX4DPROC glfn_glVertex4d;
// WINGDIAPI void APIENTRY glVertex4d (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#define glVertex4d glfn_glVertex4d
extern PFNGLVERTEX4DVPROC glfn_glVertex4dv;
// WINGDIAPI void APIENTRY glVertex4dv (const GLdouble *v);
#define glVertex4dv glfn_glVertex4dv
extern PFNGLVERTEX4FPROC glfn_glVertex4f;
// WINGDIAPI void APIENTRY glVertex4f (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#define glVertex4f glfn_glVertex4f
extern PFNGLVERTEX4FVPROC glfn_glVertex4fv;
// WINGDIAPI void APIENTRY glVertex4fv (const GLfloat *v);
#define glVertex4fv glfn_glVertex4fv
extern PFNGLVERTEX4IPROC glfn_glVertex4i;
// WINGDIAPI void APIENTRY glVertex4i (GLint x, GLint y, GLint z, GLint w);
#define glVertex4i glfn_glVertex4i
extern PFNGLVERTEX4IVPROC glfn_glVertex4iv;
// WINGDIAPI void APIENTRY glVertex4iv (const GLint *v);
#define glVertex4iv glfn_glVertex4iv
extern PFNGLVERTEX4SPROC glfn_glVertex4s;
// WINGDIAPI void APIENTRY glVertex4s (GLshort x, GLshort y, GLshort z, GLshort w);
#define glVertex4s glfn_glVertex4s
extern PFNGLVERTEX4SVPROC glfn_glVertex4sv;
// WINGDIAPI void APIENTRY glVertex4sv (const GLshort *v);
#define glVertex4sv glfn_glVertex4sv
extern PFNGLVERTEXPOINTERPROC glfn_glVertexPointer;
// WINGDIAPI void APIENTRY glVertexPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
#define glVertexPointer glfn_glVertexPointer
extern PFNGLVIEWPORTPROC glfn_glViewport;
// WINGDIAPI void APIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height);
#define glViewport glfn_glViewport


// GL_VERSION_1_2
// GLAPI void APIENTRY glDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
extern PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;
// GLAPI void APIENTRY glTexImage3D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
extern PFNGLTEXIMAGE3DPROC glTexImage3D;
// GLAPI void APIENTRY glTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
extern PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D;
// GLAPI void APIENTRY glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D;


// GL_VERSION_1_3
// GLAPI void APIENTRY glActiveTexture (GLenum texture);
extern PFNGLACTIVETEXTUREPROC glActiveTexture;
// GLAPI void APIENTRY glSampleCoverage (GLfloat value, GLboolean invert);
extern PFNGLSAMPLECOVERAGEPROC glSampleCoverage;
// GLAPI void APIENTRY glCompressedTexImage3D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
extern PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D;
// GLAPI void APIENTRY glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
extern PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
// GLAPI void APIENTRY glCompressedTexImage1D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
extern PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D;
// GLAPI void APIENTRY glCompressedTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D;
// GLAPI void APIENTRY glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D;
// GLAPI void APIENTRY glCompressedTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
extern PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D;
// GLAPI void APIENTRY glGetCompressedTexImage (GLenum target, GLint level, void *img);
extern PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage;
// GLAPI void APIENTRY glClientActiveTexture (GLenum texture);
extern PFNGLCLIENTACTIVETEXTUREPROC glClientActiveTexture;
// GLAPI void APIENTRY glMultiTexCoord1d (GLenum target, GLdouble s);
extern PFNGLMULTITEXCOORD1DPROC glMultiTexCoord1d;
// GLAPI void APIENTRY glMultiTexCoord1dv (GLenum target, const GLdouble *v);
extern PFNGLMULTITEXCOORD1DVPROC glMultiTexCoord1dv;
// GLAPI void APIENTRY glMultiTexCoord1f (GLenum target, GLfloat s);
extern PFNGLMULTITEXCOORD1FPROC glMultiTexCoord1f;
// GLAPI void APIENTRY glMultiTexCoord1fv (GLenum target, const GLfloat *v);
extern PFNGLMULTITEXCOORD1FVPROC glMultiTexCoord1fv;
// GLAPI void APIENTRY glMultiTexCoord1i (GLenum target, GLint s);
extern PFNGLMULTITEXCOORD1IPROC glMultiTexCoord1i;
// GLAPI void APIENTRY glMultiTexCoord1iv (GLenum target, const GLint *v);
extern PFNGLMULTITEXCOORD1IVPROC glMultiTexCoord1iv;
// GLAPI void APIENTRY glMultiTexCoord1s (GLenum target, GLshort s);
extern PFNGLMULTITEXCOORD1SPROC glMultiTexCoord1s;
// GLAPI void APIENTRY glMultiTexCoord1sv (GLenum target, const GLshort *v);
extern PFNGLMULTITEXCOORD1SVPROC glMultiTexCoord1sv;
// GLAPI void APIENTRY glMultiTexCoord2d (GLenum target, GLdouble s, GLdouble t);
extern PFNGLMULTITEXCOORD2DPROC glMultiTexCoord2d;
// GLAPI void APIENTRY glMultiTexCoord2dv (GLenum target, const GLdouble *v);
extern PFNGLMULTITEXCOORD2DVPROC glMultiTexCoord2dv;
// GLAPI void APIENTRY glMultiTexCoord2f (GLenum target, GLfloat s, GLfloat t);
extern PFNGLMULTITEXCOORD2FPROC glMultiTexCoord2f;
// GLAPI void APIENTRY glMultiTexCoord2fv (GLenum target, const GLfloat *v);
extern PFNGLMULTITEXCOORD2FVPROC glMultiTexCoord2fv;
// GLAPI void APIENTRY glMultiTexCoord2i (GLenum target, GLint s, GLint t);
extern PFNGLMULTITEXCOORD2IPROC glMultiTexCoord2i;
// GLAPI void APIENTRY glMultiTexCoord2iv (GLenum target, const GLint *v);
extern PFNGLMULTITEXCOORD2IVPROC glMultiTexCoord2iv;
// GLAPI void APIENTRY glMultiTexCoord2s (GLenum target, GLshort s, GLshort t);
extern PFNGLMULTITEXCOORD2SPROC glMultiTexCoord2s;
// GLAPI void APIENTRY glMultiTexCoord2sv (GLenum target, const GLshort *v);
extern PFNGLMULTITEXCOORD2SVPROC glMultiTexCoord2sv;
// GLAPI void APIENTRY glMultiTexCoord3d (GLenum target, GLdouble s, GLdouble t, GLdouble r);
extern PFNGLMULTITEXCOORD3DPROC glMultiTexCoord3d;
// GLAPI void APIENTRY glMultiTexCoord3dv (GLenum target, const GLdouble *v);
extern PFNGLMULTITEXCOORD3DVPROC glMultiTexCoord3dv;
// GLAPI void APIENTRY glMultiTexCoord3f (GLenum target, GLfloat s, GLfloat t, GLfloat r);
extern PFNGLMULTITEXCOORD3FPROC glMultiTexCoord3f;
// GLAPI void APIENTRY glMultiTexCoord3fv (GLenum target, const GLfloat *v);
extern PFNGLMULTITEXCOORD3FVPROC glMultiTexCoord3fv;
// GLAPI void APIENTRY glMultiTexCoord3i (GLenum target, GLint s, GLint t, GLint r);
extern PFNGLMULTITEXCOORD3IPROC glMultiTexCoord3i;
// GLAPI void APIENTRY glMultiTexCoord3iv (GLenum target, const GLint *v);
extern PFNGLMULTITEXCOORD3IVPROC glMultiTexCoord3iv;
// GLAPI void APIENTRY glMultiTexCoord3s (GLenum target, GLshort s, GLshort t, GLshort r);
extern PFNGLMULTITEXCOORD3SPROC glMultiTexCoord3s;
// GLAPI void APIENTRY glMultiTexCoord3sv (GLenum target, const GLshort *v);
extern PFNGLMULTITEXCOORD3SVPROC glMultiTexCoord3sv;
// GLAPI void APIENTRY glMultiTexCoord4d (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
extern PFNGLMULTITEXCOORD4DPROC glMultiTexCoord4d;
// GLAPI void APIENTRY glMultiTexCoord4dv (GLenum target, const GLdouble *v);
extern PFNGLMULTITEXCOORD4DVPROC glMultiTexCoord4dv;
// GLAPI void APIENTRY glMultiTexCoord4f (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
extern PFNGLMULTITEXCOORD4FPROC glMultiTexCoord4f;
// GLAPI void APIENTRY glMultiTexCoord4fv (GLenum target, const GLfloat *v);
extern PFNGLMULTITEXCOORD4FVPROC glMultiTexCoord4fv;
// GLAPI void APIENTRY glMultiTexCoord4i (GLenum target, GLint s, GLint t, GLint r, GLint q);
extern PFNGLMULTITEXCOORD4IPROC glMultiTexCoord4i;
// GLAPI void APIENTRY glMultiTexCoord4iv (GLenum target, const GLint *v);
extern PFNGLMULTITEXCOORD4IVPROC glMultiTexCoord4iv;
// GLAPI void APIENTRY glMultiTexCoord4s (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
extern PFNGLMULTITEXCOORD4SPROC glMultiTexCoord4s;
// GLAPI void APIENTRY glMultiTexCoord4sv (GLenum target, const GLshort *v);
extern PFNGLMULTITEXCOORD4SVPROC glMultiTexCoord4sv;
// GLAPI void APIENTRY glLoadTransposeMatrixf (const GLfloat *m);
extern PFNGLLOADTRANSPOSEMATRIXFPROC glLoadTransposeMatrixf;
// GLAPI void APIENTRY glLoadTransposeMatrixd (const GLdouble *m);
extern PFNGLLOADTRANSPOSEMATRIXDPROC glLoadTransposeMatrixd;
// GLAPI void APIENTRY glMultTransposeMatrixf (const GLfloat *m);
extern PFNGLMULTTRANSPOSEMATRIXFPROC glMultTransposeMatrixf;
// GLAPI void APIENTRY glMultTransposeMatrixd (const GLdouble *m);
extern PFNGLMULTTRANSPOSEMATRIXDPROC glMultTransposeMatrixd;


// GL_VERSION_1_4
// GLAPI void APIENTRY glBlendFuncSeparate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
extern PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;
// GLAPI void APIENTRY glMultiDrawArrays (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
extern PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays;
// GLAPI void APIENTRY glMultiDrawElements (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
extern PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements;
// GLAPI void APIENTRY glPointParameterf (GLenum pname, GLfloat param);
extern PFNGLPOINTPARAMETERFPROC glPointParameterf;
// GLAPI void APIENTRY glPointParameterfv (GLenum pname, const GLfloat *params);
extern PFNGLPOINTPARAMETERFVPROC glPointParameterfv;
// GLAPI void APIENTRY glPointParameteri (GLenum pname, GLint param);
extern PFNGLPOINTPARAMETERIPROC glPointParameteri;
// GLAPI void APIENTRY glPointParameteriv (GLenum pname, const GLint *params);
extern PFNGLPOINTPARAMETERIVPROC glPointParameteriv;
// GLAPI void APIENTRY glFogCoordf (GLfloat coord);
extern PFNGLFOGCOORDFPROC glFogCoordf;
// GLAPI void APIENTRY glFogCoordfv (const GLfloat *coord);
extern PFNGLFOGCOORDFVPROC glFogCoordfv;
// GLAPI void APIENTRY glFogCoordd (GLdouble coord);
extern PFNGLFOGCOORDDPROC glFogCoordd;
// GLAPI void APIENTRY glFogCoorddv (const GLdouble *coord);
extern PFNGLFOGCOORDDVPROC glFogCoorddv;
// GLAPI void APIENTRY glFogCoordPointer (GLenum type, GLsizei stride, const void *pointer);
extern PFNGLFOGCOORDPOINTERPROC glFogCoordPointer;
// GLAPI void APIENTRY glSecondaryColor3b (GLbyte red, GLbyte green, GLbyte blue);
extern PFNGLSECONDARYCOLOR3BPROC glSecondaryColor3b;
// GLAPI void APIENTRY glSecondaryColor3bv (const GLbyte *v);
extern PFNGLSECONDARYCOLOR3BVPROC glSecondaryColor3bv;
// GLAPI void APIENTRY glSecondaryColor3d (GLdouble red, GLdouble green, GLdouble blue);
extern PFNGLSECONDARYCOLOR3DPROC glSecondaryColor3d;
// GLAPI void APIENTRY glSecondaryColor3dv (const GLdouble *v);
extern PFNGLSECONDARYCOLOR3DVPROC glSecondaryColor3dv;
// GLAPI void APIENTRY glSecondaryColor3f (GLfloat red, GLfloat green, GLfloat blue);
extern PFNGLSECONDARYCOLOR3FPROC glSecondaryColor3f;
// GLAPI void APIENTRY glSecondaryColor3fv (const GLfloat *v);
extern PFNGLSECONDARYCOLOR3FVPROC glSecondaryColor3fv;
// GLAPI void APIENTRY glSecondaryColor3i (GLint red, GLint green, GLint blue);
extern PFNGLSECONDARYCOLOR3IPROC glSecondaryColor3i;
// GLAPI void APIENTRY glSecondaryColor3iv (const GLint *v);
extern PFNGLSECONDARYCOLOR3IVPROC glSecondaryColor3iv;
// GLAPI void APIENTRY glSecondaryColor3s (GLshort red, GLshort green, GLshort blue);
extern PFNGLSECONDARYCOLOR3SPROC glSecondaryColor3s;
// GLAPI void APIENTRY glSecondaryColor3sv (const GLshort *v);
extern PFNGLSECONDARYCOLOR3SVPROC glSecondaryColor3sv;
// GLAPI void APIENTRY glSecondaryColor3ub (GLubyte red, GLubyte green, GLubyte blue);
extern PFNGLSECONDARYCOLOR3UBPROC glSecondaryColor3ub;
// GLAPI void APIENTRY glSecondaryColor3ubv (const GLubyte *v);
extern PFNGLSECONDARYCOLOR3UBVPROC glSecondaryColor3ubv;
// GLAPI void APIENTRY glSecondaryColor3ui (GLuint red, GLuint green, GLuint blue);
extern PFNGLSECONDARYCOLOR3UIPROC glSecondaryColor3ui;
// GLAPI void APIENTRY glSecondaryColor3uiv (const GLuint *v);
extern PFNGLSECONDARYCOLOR3UIVPROC glSecondaryColor3uiv;
// GLAPI void APIENTRY glSecondaryColor3us (GLushort red, GLushort green, GLushort blue);
extern PFNGLSECONDARYCOLOR3USPROC glSecondaryColor3us;
// GLAPI void APIENTRY glSecondaryColor3usv (const GLushort *v);
extern PFNGLSECONDARYCOLOR3USVPROC glSecondaryColor3usv;
// GLAPI void APIENTRY glSecondaryColorPointer (GLint size, GLenum type, GLsizei stride, const void *pointer);
extern PFNGLSECONDARYCOLORPOINTERPROC glSecondaryColorPointer;
// GLAPI void APIENTRY glWindowPos2d (GLdouble x, GLdouble y);
extern PFNGLWINDOWPOS2DPROC glWindowPos2d;
// GLAPI void APIENTRY glWindowPos2dv (const GLdouble *v);
extern PFNGLWINDOWPOS2DVPROC glWindowPos2dv;
// GLAPI void APIENTRY glWindowPos2f (GLfloat x, GLfloat y);
extern PFNGLWINDOWPOS2FPROC glWindowPos2f;
// GLAPI void APIENTRY glWindowPos2fv (const GLfloat *v);
extern PFNGLWINDOWPOS2FVPROC glWindowPos2fv;
// GLAPI void APIENTRY glWindowPos2i (GLint x, GLint y);
extern PFNGLWINDOWPOS2IPROC glWindowPos2i;
// GLAPI void APIENTRY glWindowPos2iv (const GLint *v);
extern PFNGLWINDOWPOS2IVPROC glWindowPos2iv;
// GLAPI void APIENTRY glWindowPos2s (GLshort x, GLshort y);
extern PFNGLWINDOWPOS2SPROC glWindowPos2s;
// GLAPI void APIENTRY glWindowPos2sv (const GLshort *v);
extern PFNGLWINDOWPOS2SVPROC glWindowPos2sv;
// GLAPI void APIENTRY glWindowPos3d (GLdouble x, GLdouble y, GLdouble z);
extern PFNGLWINDOWPOS3DPROC glWindowPos3d;
// GLAPI void APIENTRY glWindowPos3dv (const GLdouble *v);
extern PFNGLWINDOWPOS3DVPROC glWindowPos3dv;
// GLAPI void APIENTRY glWindowPos3f (GLfloat x, GLfloat y, GLfloat z);
extern PFNGLWINDOWPOS3FPROC glWindowPos3f;
// GLAPI void APIENTRY glWindowPos3fv (const GLfloat *v);
extern PFNGLWINDOWPOS3FVPROC glWindowPos3fv;
// GLAPI void APIENTRY glWindowPos3i (GLint x, GLint y, GLint z);
extern PFNGLWINDOWPOS3IPROC glWindowPos3i;
// GLAPI void APIENTRY glWindowPos3iv (const GLint *v);
extern PFNGLWINDOWPOS3IVPROC glWindowPos3iv;
// GLAPI void APIENTRY glWindowPos3s (GLshort x, GLshort y, GLshort z);
extern PFNGLWINDOWPOS3SPROC glWindowPos3s;
// GLAPI void APIENTRY glWindowPos3sv (const GLshort *v);
extern PFNGLWINDOWPOS3SVPROC glWindowPos3sv;
// GLAPI void APIENTRY glBlendColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern PFNGLBLENDCOLORPROC glBlendColor;
// GLAPI void APIENTRY glBlendEquation (GLenum mode);
extern PFNGLBLENDEQUATIONPROC glBlendEquation;


// GL_VERSION_1_5
// GLAPI void APIENTRY glGenQueries (GLsizei n, GLuint *ids);
extern PFNGLGENQUERIESPROC glGenQueries;
// GLAPI void APIENTRY glDeleteQueries (GLsizei n, const GLuint *ids);
extern PFNGLDELETEQUERIESPROC glDeleteQueries;
// GLAPI GLboolean APIENTRY glIsQuery (GLuint id);
extern PFNGLISQUERYPROC glIsQuery;
// GLAPI void APIENTRY glBeginQuery (GLenum target, GLuint id);
extern PFNGLBEGINQUERYPROC glBeginQuery;
// GLAPI void APIENTRY glEndQuery (GLenum target);
extern PFNGLENDQUERYPROC glEndQuery;
// GLAPI void APIENTRY glGetQueryiv (GLenum target, GLenum pname, GLint *params);
extern PFNGLGETQUERYIVPROC glGetQueryiv;
// GLAPI void APIENTRY glGetQueryObjectiv (GLuint id, GLenum pname, GLint *params);
extern PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv;
// GLAPI void APIENTRY glGetQueryObjectuiv (GLuint id, GLenum pname, GLuint *params);
extern PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv;
// GLAPI void APIENTRY glBindBuffer (GLenum target, GLuint buffer);
extern PFNGLBINDBUFFERPROC glBindBuffer;
// GLAPI void APIENTRY glDeleteBuffers (GLsizei n, const GLuint *buffers);
extern PFNGLDELETEBUFFERSPROC glDeleteBuffers;
// GLAPI void APIENTRY glGenBuffers (GLsizei n, GLuint *buffers);
extern PFNGLGENBUFFERSPROC glGenBuffers;
// GLAPI GLboolean APIENTRY glIsBuffer (GLuint buffer);
extern PFNGLISBUFFERPROC glIsBuffer;
// GLAPI void APIENTRY glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
extern PFNGLBUFFERDATAPROC glBufferData;
// GLAPI void APIENTRY glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
extern PFNGLBUFFERSUBDATAPROC glBufferSubData;
// GLAPI void APIENTRY glGetBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
extern PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData;
// GLAPI void *APIENTRY glMapBuffer (GLenum target, GLenum access);
extern PFNGLMAPBUFFERPROC glMapBuffer;
// GLAPI GLboolean APIENTRY glUnmapBuffer (GLenum target);
extern PFNGLUNMAPBUFFERPROC glUnmapBuffer;
// GLAPI void APIENTRY glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params);
extern PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv;
// GLAPI void APIENTRY glGetBufferPointerv (GLenum target, GLenum pname, void **params);
extern PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv;


// GL_VERSION_2_0
// GLAPI void APIENTRY glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha);
extern PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate;
// GLAPI void APIENTRY glDrawBuffers (GLsizei n, const GLenum *bufs);
extern PFNGLDRAWBUFFERSPROC glDrawBuffers;
// GLAPI void APIENTRY glStencilOpSeparate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
extern PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate;
// GLAPI void APIENTRY glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask);
extern PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate;
// GLAPI void APIENTRY glStencilMaskSeparate (GLenum face, GLuint mask);
extern PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate;
// GLAPI void APIENTRY glAttachShader (GLuint program, GLuint shader);
extern PFNGLATTACHSHADERPROC glAttachShader;
// GLAPI void APIENTRY glBindAttribLocation (GLuint program, GLuint index, const GLchar *name);
extern PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
// GLAPI void APIENTRY glCompileShader (GLuint shader);
extern PFNGLCOMPILESHADERPROC glCompileShader;
// GLAPI GLuint APIENTRY glCreateProgram (void);
extern PFNGLCREATEPROGRAMPROC glCreateProgram;
// GLAPI GLuint APIENTRY glCreateShader (GLenum type);
extern PFNGLCREATESHADERPROC glCreateShader;
// GLAPI void APIENTRY glDeleteProgram (GLuint program);
extern PFNGLDELETEPROGRAMPROC glDeleteProgram;
// GLAPI void APIENTRY glDeleteShader (GLuint shader);
extern PFNGLDELETESHADERPROC glDeleteShader;
// GLAPI void APIENTRY glDetachShader (GLuint program, GLuint shader);
extern PFNGLDETACHSHADERPROC glDetachShader;
// GLAPI void APIENTRY glDisableVertexAttribArray (GLuint index);
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
// GLAPI void APIENTRY glEnableVertexAttribArray (GLuint index);
extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
// GLAPI void APIENTRY glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
extern PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib;
// GLAPI void APIENTRY glGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
extern PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform;
// GLAPI void APIENTRY glGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
extern PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders;
// GLAPI GLint APIENTRY glGetAttribLocation (GLuint program, const GLchar *name);
extern PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
// GLAPI void APIENTRY glGetProgramiv (GLuint program, GLenum pname, GLint *params);
extern PFNGLGETPROGRAMIVPROC glGetProgramiv;
// GLAPI void APIENTRY glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
extern PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
// GLAPI void APIENTRY glGetShaderiv (GLuint shader, GLenum pname, GLint *params);
extern PFNGLGETSHADERIVPROC glGetShaderiv;
// GLAPI void APIENTRY glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
extern PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
// GLAPI void APIENTRY glGetShaderSource (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
extern PFNGLGETSHADERSOURCEPROC glGetShaderSource;
// GLAPI GLint APIENTRY glGetUniformLocation (GLuint program, const GLchar *name);
extern PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
// GLAPI void APIENTRY glGetUniformfv (GLuint program, GLint location, GLfloat *params);
extern PFNGLGETUNIFORMFVPROC glGetUniformfv;
// GLAPI void APIENTRY glGetUniformiv (GLuint program, GLint location, GLint *params);
extern PFNGLGETUNIFORMIVPROC glGetUniformiv;
// GLAPI void APIENTRY glGetVertexAttribdv (GLuint index, GLenum pname, GLdouble *params);
extern PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv;
// GLAPI void APIENTRY glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params);
extern PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv;
// GLAPI void APIENTRY glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params);
extern PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv;
// GLAPI void APIENTRY glGetVertexAttribPointerv (GLuint index, GLenum pname, void **pointer);
extern PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv;
// GLAPI GLboolean APIENTRY glIsProgram (GLuint program);
extern PFNGLISPROGRAMPROC glIsProgram;
// GLAPI GLboolean APIENTRY glIsShader (GLuint shader);
extern PFNGLISSHADERPROC glIsShader;
// GLAPI void APIENTRY glLinkProgram (GLuint program);
extern PFNGLLINKPROGRAMPROC glLinkProgram;
// GLAPI void APIENTRY glShaderSource (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
extern PFNGLSHADERSOURCEPROC glShaderSource;
// GLAPI void APIENTRY glUseProgram (GLuint program);
extern PFNGLUSEPROGRAMPROC glUseProgram;
// GLAPI void APIENTRY glUniform1f (GLint location, GLfloat v0);
extern PFNGLUNIFORM1FPROC glUniform1f;
// GLAPI void APIENTRY glUniform2f (GLint location, GLfloat v0, GLfloat v1);
extern PFNGLUNIFORM2FPROC glUniform2f;
// GLAPI void APIENTRY glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
extern PFNGLUNIFORM3FPROC glUniform3f;
// GLAPI void APIENTRY glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
extern PFNGLUNIFORM4FPROC glUniform4f;
// GLAPI void APIENTRY glUniform1i (GLint location, GLint v0);
extern PFNGLUNIFORM1IPROC glUniform1i;
// GLAPI void APIENTRY glUniform2i (GLint location, GLint v0, GLint v1);
extern PFNGLUNIFORM2IPROC glUniform2i;
// GLAPI void APIENTRY glUniform3i (GLint location, GLint v0, GLint v1, GLint v2);
extern PFNGLUNIFORM3IPROC glUniform3i;
// GLAPI void APIENTRY glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
extern PFNGLUNIFORM4IPROC glUniform4i;
// GLAPI void APIENTRY glUniform1fv (GLint location, GLsizei count, const GLfloat *value);
extern PFNGLUNIFORM1FVPROC glUniform1fv;
// GLAPI void APIENTRY glUniform2fv (GLint location, GLsizei count, const GLfloat *value);
extern PFNGLUNIFORM2FVPROC glUniform2fv;
// GLAPI void APIENTRY glUniform3fv (GLint location, GLsizei count, const GLfloat *value);
extern PFNGLUNIFORM3FVPROC glUniform3fv;
// GLAPI void APIENTRY glUniform4fv (GLint location, GLsizei count, const GLfloat *value);
extern PFNGLUNIFORM4FVPROC glUniform4fv;
// GLAPI void APIENTRY glUniform1iv (GLint location, GLsizei count, const GLint *value);
extern PFNGLUNIFORM1IVPROC glUniform1iv;
// GLAPI void APIENTRY glUniform2iv (GLint location, GLsizei count, const GLint *value);
extern PFNGLUNIFORM2IVPROC glUniform2iv;
// GLAPI void APIENTRY glUniform3iv (GLint location, GLsizei count, const GLint *value);
extern PFNGLUNIFORM3IVPROC glUniform3iv;
// GLAPI void APIENTRY glUniform4iv (GLint location, GLsizei count, const GLint *value);
extern PFNGLUNIFORM4IVPROC glUniform4iv;
// GLAPI void APIENTRY glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv;
// GLAPI void APIENTRY glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
// GLAPI void APIENTRY glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
// GLAPI void APIENTRY glValidateProgram (GLuint program);
extern PFNGLVALIDATEPROGRAMPROC glValidateProgram;
// GLAPI void APIENTRY glVertexAttrib1d (GLuint index, GLdouble x);
extern PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d;
// GLAPI void APIENTRY glVertexAttrib1dv (GLuint index, const GLdouble *v);
extern PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv;
// GLAPI void APIENTRY glVertexAttrib1f (GLuint index, GLfloat x);
extern PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f;
// GLAPI void APIENTRY glVertexAttrib1fv (GLuint index, const GLfloat *v);
extern PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv;
// GLAPI void APIENTRY glVertexAttrib1s (GLuint index, GLshort x);
extern PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s;
// GLAPI void APIENTRY glVertexAttrib1sv (GLuint index, const GLshort *v);
extern PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv;
// GLAPI void APIENTRY glVertexAttrib2d (GLuint index, GLdouble x, GLdouble y);
extern PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d;
// GLAPI void APIENTRY glVertexAttrib2dv (GLuint index, const GLdouble *v);
extern PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv;
// GLAPI void APIENTRY glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y);
extern PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f;
// GLAPI void APIENTRY glVertexAttrib2fv (GLuint index, const GLfloat *v);
extern PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv;
// GLAPI void APIENTRY glVertexAttrib2s (GLuint index, GLshort x, GLshort y);
extern PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s;
// GLAPI void APIENTRY glVertexAttrib2sv (GLuint index, const GLshort *v);
extern PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv;
// GLAPI void APIENTRY glVertexAttrib3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
extern PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d;
// GLAPI void APIENTRY glVertexAttrib3dv (GLuint index, const GLdouble *v);
extern PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv;
// GLAPI void APIENTRY glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z);
extern PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f;
// GLAPI void APIENTRY glVertexAttrib3fv (GLuint index, const GLfloat *v);
extern PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv;
// GLAPI void APIENTRY glVertexAttrib3s (GLuint index, GLshort x, GLshort y, GLshort z);
extern PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s;
// GLAPI void APIENTRY glVertexAttrib3sv (GLuint index, const GLshort *v);
extern PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv;
// GLAPI void APIENTRY glVertexAttrib4Nbv (GLuint index, const GLbyte *v);
extern PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv;
// GLAPI void APIENTRY glVertexAttrib4Niv (GLuint index, const GLint *v);
extern PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv;
// GLAPI void APIENTRY glVertexAttrib4Nsv (GLuint index, const GLshort *v);
extern PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv;
// GLAPI void APIENTRY glVertexAttrib4Nub (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
extern PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub;
// GLAPI void APIENTRY glVertexAttrib4Nubv (GLuint index, const GLubyte *v);
extern PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv;
// GLAPI void APIENTRY glVertexAttrib4Nuiv (GLuint index, const GLuint *v);
extern PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv;
// GLAPI void APIENTRY glVertexAttrib4Nusv (GLuint index, const GLushort *v);
extern PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv;
// GLAPI void APIENTRY glVertexAttrib4bv (GLuint index, const GLbyte *v);
extern PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv;
// GLAPI void APIENTRY glVertexAttrib4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d;
// GLAPI void APIENTRY glVertexAttrib4dv (GLuint index, const GLdouble *v);
extern PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv;
// GLAPI void APIENTRY glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f;
// GLAPI void APIENTRY glVertexAttrib4fv (GLuint index, const GLfloat *v);
extern PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv;
// GLAPI void APIENTRY glVertexAttrib4iv (GLuint index, const GLint *v);
extern PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv;
// GLAPI void APIENTRY glVertexAttrib4s (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
extern PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s;
// GLAPI void APIENTRY glVertexAttrib4sv (GLuint index, const GLshort *v);
extern PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv;
// GLAPI void APIENTRY glVertexAttrib4ubv (GLuint index, const GLubyte *v);
extern PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv;
// GLAPI void APIENTRY glVertexAttrib4uiv (GLuint index, const GLuint *v);
extern PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv;
// GLAPI void APIENTRY glVertexAttrib4usv (GLuint index, const GLushort *v);
extern PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv;
// GLAPI void APIENTRY glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;


// GL_VERSION_2_1
// GLAPI void APIENTRY glUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
// GLAPI void APIENTRY glUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
// GLAPI void APIENTRY glUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
// GLAPI void APIENTRY glUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
// GLAPI void APIENTRY glUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
// GLAPI void APIENTRY glUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;


// GL_VERSION_3_0
// GLAPI void APIENTRY glColorMaski (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
extern PFNGLCOLORMASKIPROC glColorMaski;
// GLAPI void APIENTRY glGetBooleani_v (GLenum target, GLuint index, GLboolean *data);
extern PFNGLGETBOOLEANI_VPROC glGetBooleani_v;
// GLAPI void APIENTRY glGetIntegeri_v (GLenum target, GLuint index, GLint *data);
extern PFNGLGETINTEGERI_VPROC glGetIntegeri_v;
// GLAPI void APIENTRY glEnablei (GLenum target, GLuint index);
extern PFNGLENABLEIPROC glEnablei;
// GLAPI void APIENTRY glDisablei (GLenum target, GLuint index);
extern PFNGLDISABLEIPROC glDisablei;
// GLAPI GLboolean APIENTRY glIsEnabledi (GLenum target, GLuint index);
extern PFNGLISENABLEDIPROC glIsEnabledi;
// GLAPI void APIENTRY glBeginTransformFeedback (GLenum primitiveMode);
extern PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback;
// GLAPI void APIENTRY glEndTransformFeedback (void);
extern PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback;
// GLAPI void APIENTRY glBindBufferRange (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern PFNGLBINDBUFFERRANGEPROC glBindBufferRange;
// GLAPI void APIENTRY glBindBufferBase (GLenum target, GLuint index, GLuint buffer);
extern PFNGLBINDBUFFERBASEPROC glBindBufferBase;
// GLAPI void APIENTRY glTransformFeedbackVaryings (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
extern PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings;
// GLAPI void APIENTRY glGetTransformFeedbackVarying (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
extern PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying;
// GLAPI void APIENTRY glClampColor (GLenum target, GLenum clamp);
extern PFNGLCLAMPCOLORPROC glClampColor;
// GLAPI void APIENTRY glBeginConditionalRender (GLuint id, GLenum mode);
extern PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender;
// GLAPI void APIENTRY glEndConditionalRender (void);
extern PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender;
// GLAPI void APIENTRY glVertexAttribIPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
extern PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;
// GLAPI void APIENTRY glGetVertexAttribIiv (GLuint index, GLenum pname, GLint *params);
extern PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv;
// GLAPI void APIENTRY glGetVertexAttribIuiv (GLuint index, GLenum pname, GLuint *params);
extern PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv;
// GLAPI void APIENTRY glVertexAttribI1i (GLuint index, GLint x);
extern PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i;
// GLAPI void APIENTRY glVertexAttribI2i (GLuint index, GLint x, GLint y);
extern PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i;
// GLAPI void APIENTRY glVertexAttribI3i (GLuint index, GLint x, GLint y, GLint z);
extern PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i;
// GLAPI void APIENTRY glVertexAttribI4i (GLuint index, GLint x, GLint y, GLint z, GLint w);
extern PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i;
// GLAPI void APIENTRY glVertexAttribI1ui (GLuint index, GLuint x);
extern PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui;
// GLAPI void APIENTRY glVertexAttribI2ui (GLuint index, GLuint x, GLuint y);
extern PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui;
// GLAPI void APIENTRY glVertexAttribI3ui (GLuint index, GLuint x, GLuint y, GLuint z);
extern PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui;
// GLAPI void APIENTRY glVertexAttribI4ui (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
extern PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui;
// GLAPI void APIENTRY glVertexAttribI1iv (GLuint index, const GLint *v);
extern PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv;
// GLAPI void APIENTRY glVertexAttribI2iv (GLuint index, const GLint *v);
extern PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv;
// GLAPI void APIENTRY glVertexAttribI3iv (GLuint index, const GLint *v);
extern PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv;
// GLAPI void APIENTRY glVertexAttribI4iv (GLuint index, const GLint *v);
extern PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv;
// GLAPI void APIENTRY glVertexAttribI1uiv (GLuint index, const GLuint *v);
extern PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv;
// GLAPI void APIENTRY glVertexAttribI2uiv (GLuint index, const GLuint *v);
extern PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv;
// GLAPI void APIENTRY glVertexAttribI3uiv (GLuint index, const GLuint *v);
extern PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv;
// GLAPI void APIENTRY glVertexAttribI4uiv (GLuint index, const GLuint *v);
extern PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv;
// GLAPI void APIENTRY glVertexAttribI4bv (GLuint index, const GLbyte *v);
extern PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv;
// GLAPI void APIENTRY glVertexAttribI4sv (GLuint index, const GLshort *v);
extern PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv;
// GLAPI void APIENTRY glVertexAttribI4ubv (GLuint index, const GLubyte *v);
extern PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv;
// GLAPI void APIENTRY glVertexAttribI4usv (GLuint index, const GLushort *v);
extern PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv;
// GLAPI void APIENTRY glGetUniformuiv (GLuint program, GLint location, GLuint *params);
extern PFNGLGETUNIFORMUIVPROC glGetUniformuiv;
// GLAPI void APIENTRY glBindFragDataLocation (GLuint program, GLuint color, const GLchar *name);
extern PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;
// GLAPI GLint APIENTRY glGetFragDataLocation (GLuint program, const GLchar *name);
extern PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation;
// GLAPI void APIENTRY glUniform1ui (GLint location, GLuint v0);
extern PFNGLUNIFORM1UIPROC glUniform1ui;
// GLAPI void APIENTRY glUniform2ui (GLint location, GLuint v0, GLuint v1);
extern PFNGLUNIFORM2UIPROC glUniform2ui;
// GLAPI void APIENTRY glUniform3ui (GLint location, GLuint v0, GLuint v1, GLuint v2);
extern PFNGLUNIFORM3UIPROC glUniform3ui;
// GLAPI void APIENTRY glUniform4ui (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
extern PFNGLUNIFORM4UIPROC glUniform4ui;
// GLAPI void APIENTRY glUniform1uiv (GLint location, GLsizei count, const GLuint *value);
extern PFNGLUNIFORM1UIVPROC glUniform1uiv;
// GLAPI void APIENTRY glUniform2uiv (GLint location, GLsizei count, const GLuint *value);
extern PFNGLUNIFORM2UIVPROC glUniform2uiv;
// GLAPI void APIENTRY glUniform3uiv (GLint location, GLsizei count, const GLuint *value);
extern PFNGLUNIFORM3UIVPROC glUniform3uiv;
// GLAPI void APIENTRY glUniform4uiv (GLint location, GLsizei count, const GLuint *value);
extern PFNGLUNIFORM4UIVPROC glUniform4uiv;
// GLAPI void APIENTRY glTexParameterIiv (GLenum target, GLenum pname, const GLint *params);
extern PFNGLTEXPARAMETERIIVPROC glTexParameterIiv;
// GLAPI void APIENTRY glTexParameterIuiv (GLenum target, GLenum pname, const GLuint *params);
extern PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv;
// GLAPI void APIENTRY glGetTexParameterIiv (GLenum target, GLenum pname, GLint *params);
extern PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv;
// GLAPI void APIENTRY glGetTexParameterIuiv (GLenum target, GLenum pname, GLuint *params);
extern PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv;
// GLAPI void APIENTRY glClearBufferiv (GLenum buffer, GLint drawbuffer, const GLint *value);
extern PFNGLCLEARBUFFERIVPROC glClearBufferiv;
// GLAPI void APIENTRY glClearBufferuiv (GLenum buffer, GLint drawbuffer, const GLuint *value);
extern PFNGLCLEARBUFFERUIVPROC glClearBufferuiv;
// GLAPI void APIENTRY glClearBufferfv (GLenum buffer, GLint drawbuffer, const GLfloat *value);
extern PFNGLCLEARBUFFERFVPROC glClearBufferfv;
// GLAPI void APIENTRY glClearBufferfi (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
extern PFNGLCLEARBUFFERFIPROC glClearBufferfi;
// GLAPI const GLubyte *APIENTRY glGetStringi (GLenum name, GLuint index);
extern PFNGLGETSTRINGIPROC glGetStringi;
// GLAPI GLboolean APIENTRY glIsRenderbuffer (GLuint renderbuffer);
extern PFNGLISRENDERBUFFERPROC glIsRenderbuffer;
// GLAPI void APIENTRY glBindRenderbuffer (GLenum target, GLuint renderbuffer);
extern PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
// GLAPI void APIENTRY glDeleteRenderbuffers (GLsizei n, const GLuint *renderbuffers);
extern PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
// GLAPI void APIENTRY glGenRenderbuffers (GLsizei n, GLuint *renderbuffers);
extern PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
// GLAPI void APIENTRY glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
extern PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
// GLAPI void APIENTRY glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint *params);
extern PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;
// GLAPI GLboolean APIENTRY glIsFramebuffer (GLuint framebuffer);
extern PFNGLISFRAMEBUFFERPROC glIsFramebuffer;
// GLAPI void APIENTRY glBindFramebuffer (GLenum target, GLuint framebuffer);
extern PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
// GLAPI void APIENTRY glDeleteFramebuffers (GLsizei n, const GLuint *framebuffers);
extern PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
// GLAPI void APIENTRY glGenFramebuffers (GLsizei n, GLuint *framebuffers);
extern PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
// GLAPI GLenum APIENTRY glCheckFramebufferStatus (GLenum target);
extern PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
// GLAPI void APIENTRY glFramebufferTexture1D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D;
// GLAPI void APIENTRY glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
// GLAPI void APIENTRY glFramebufferTexture3D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
extern PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D;
// GLAPI void APIENTRY glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
extern PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
// GLAPI void APIENTRY glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint *params);
extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;
// GLAPI void APIENTRY glGenerateMipmap (GLenum target);
extern PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
// GLAPI void APIENTRY glBlitFramebuffer (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
extern PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer;
// GLAPI void APIENTRY glRenderbufferStorageMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample;
// GLAPI void APIENTRY glFramebufferTextureLayer (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
extern PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer;
// GLAPI void *APIENTRY glMapBufferRange (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
extern PFNGLMAPBUFFERRANGEPROC glMapBufferRange;
// GLAPI void APIENTRY glFlushMappedBufferRange (GLenum target, GLintptr offset, GLsizeiptr length);
extern PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange;
// GLAPI void APIENTRY glBindVertexArray (GLuint array);
extern PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
// GLAPI void APIENTRY glDeleteVertexArrays (GLsizei n, const GLuint *arrays);
extern PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
// GLAPI void APIENTRY glGenVertexArrays (GLsizei n, GLuint *arrays);
extern PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
// GLAPI GLboolean APIENTRY glIsVertexArray (GLuint array);
extern PFNGLISVERTEXARRAYPROC glIsVertexArray;


// GL_VERSION_3_1
// GLAPI void APIENTRY glDrawArraysInstanced (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
extern PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
// GLAPI void APIENTRY glDrawElementsInstanced (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
extern PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
// GLAPI void APIENTRY glTexBuffer (GLenum target, GLenum internalformat, GLuint buffer);
extern PFNGLTEXBUFFERPROC glTexBuffer;
// GLAPI void APIENTRY glPrimitiveRestartIndex (GLuint index);
extern PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
// GLAPI void APIENTRY glCopyBufferSubData (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
extern PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData;
// GLAPI void APIENTRY glGetUniformIndices (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
extern PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
// GLAPI void APIENTRY glGetActiveUniformsiv (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
extern PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
// GLAPI void APIENTRY glGetActiveUniformName (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
extern PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName;
// GLAPI GLuint APIENTRY glGetUniformBlockIndex (GLuint program, const GLchar *uniformBlockName);
extern PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
// GLAPI void APIENTRY glGetActiveUniformBlockiv (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
extern PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
// GLAPI void APIENTRY glGetActiveUniformBlockName (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
extern PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName;
// GLAPI void APIENTRY glUniformBlockBinding (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
extern PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding;


// GL_VERSION_3_2
// GLAPI void APIENTRY glDrawElementsBaseVertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
extern PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex;
// GLAPI void APIENTRY glDrawRangeElementsBaseVertex (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
extern PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex;
// GLAPI void APIENTRY glDrawElementsInstancedBaseVertex (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex;
// GLAPI void APIENTRY glMultiDrawElementsBaseVertex (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
extern PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex;
// GLAPI void APIENTRY glProvokingVertex (GLenum mode);
extern PFNGLPROVOKINGVERTEXPROC glProvokingVertex;
// GLAPI GLsync APIENTRY glFenceSync (GLenum condition, GLbitfield flags);
extern PFNGLFENCESYNCPROC glFenceSync;
// GLAPI GLboolean APIENTRY glIsSync (GLsync sync);
extern PFNGLISSYNCPROC glIsSync;
// GLAPI void APIENTRY glDeleteSync (GLsync sync);
extern PFNGLDELETESYNCPROC glDeleteSync;
// GLAPI GLenum APIENTRY glClientWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout);
extern PFNGLCLIENTWAITSYNCPROC glClientWaitSync;
// GLAPI void APIENTRY glWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout);
extern PFNGLWAITSYNCPROC glWaitSync;
// GLAPI void APIENTRY glGetInteger64v (GLenum pname, GLint64 *data);
extern PFNGLGETINTEGER64VPROC glGetInteger64v;
// GLAPI void APIENTRY glGetSynciv (GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values);
extern PFNGLGETSYNCIVPROC glGetSynciv;
// GLAPI void APIENTRY glGetInteger64i_v (GLenum target, GLuint index, GLint64 *data);
extern PFNGLGETINTEGER64I_VPROC glGetInteger64i_v;
// GLAPI void APIENTRY glGetBufferParameteri64v (GLenum target, GLenum pname, GLint64 *params);
extern PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v;
// GLAPI void APIENTRY glFramebufferTexture (GLenum target, GLenum attachment, GLuint texture, GLint level);
extern PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture;
// GLAPI void APIENTRY glTexImage2DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
extern PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample;
// GLAPI void APIENTRY glTexImage3DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
extern PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample;
// GLAPI void APIENTRY glGetMultisamplefv (GLenum pname, GLuint index, GLfloat *val);
extern PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv;
// GLAPI void APIENTRY glSampleMaski (GLuint maskNumber, GLbitfield mask);
extern PFNGLSAMPLEMASKIPROC glSampleMaski;


// GL_VERSION_3_3
// GLAPI void APIENTRY glBindFragDataLocationIndexed (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
extern PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed;
// GLAPI GLint APIENTRY glGetFragDataIndex (GLuint program, const GLchar *name);
extern PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex;
// GLAPI void APIENTRY glGenSamplers (GLsizei count, GLuint *samplers);
extern PFNGLGENSAMPLERSPROC glGenSamplers;
// GLAPI void APIENTRY glDeleteSamplers (GLsizei count, const GLuint *samplers);
extern PFNGLDELETESAMPLERSPROC glDeleteSamplers;
// GLAPI GLboolean APIENTRY glIsSampler (GLuint sampler);
extern PFNGLISSAMPLERPROC glIsSampler;
// GLAPI void APIENTRY glBindSampler (GLuint unit, GLuint sampler);
extern PFNGLBINDSAMPLERPROC glBindSampler;
// GLAPI void APIENTRY glSamplerParameteri (GLuint sampler, GLenum pname, GLint param);
extern PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri;
// GLAPI void APIENTRY glSamplerParameteriv (GLuint sampler, GLenum pname, const GLint *param);
extern PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv;
// GLAPI void APIENTRY glSamplerParameterf (GLuint sampler, GLenum pname, GLfloat param);
extern PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf;
// GLAPI void APIENTRY glSamplerParameterfv (GLuint sampler, GLenum pname, const GLfloat *param);
extern PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv;
// GLAPI void APIENTRY glSamplerParameterIiv (GLuint sampler, GLenum pname, const GLint *param);
extern PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv;
// GLAPI void APIENTRY glSamplerParameterIuiv (GLuint sampler, GLenum pname, const GLuint *param);
extern PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv;
// GLAPI void APIENTRY glGetSamplerParameteriv (GLuint sampler, GLenum pname, GLint *params);
extern PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv;
// GLAPI void APIENTRY glGetSamplerParameterIiv (GLuint sampler, GLenum pname, GLint *params);
extern PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv;
// GLAPI void APIENTRY glGetSamplerParameterfv (GLuint sampler, GLenum pname, GLfloat *params);
extern PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv;
// GLAPI void APIENTRY glGetSamplerParameterIuiv (GLuint sampler, GLenum pname, GLuint *params);
extern PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv;
// GLAPI void APIENTRY glQueryCounter (GLuint id, GLenum target);
extern PFNGLQUERYCOUNTERPROC glQueryCounter;
// GLAPI void APIENTRY glGetQueryObjecti64v (GLuint id, GLenum pname, GLint64 *params);
extern PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v;
// GLAPI void APIENTRY glGetQueryObjectui64v (GLuint id, GLenum pname, GLuint64 *params);
extern PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v;
// GLAPI void APIENTRY glVertexAttribDivisor (GLuint index, GLuint divisor);
extern PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;
// GLAPI void APIENTRY glVertexAttribP1ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui;
// GLAPI void APIENTRY glVertexAttribP1uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
extern PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv;
// GLAPI void APIENTRY glVertexAttribP2ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui;
// GLAPI void APIENTRY glVertexAttribP2uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
extern PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv;
// GLAPI void APIENTRY glVertexAttribP3ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui;
// GLAPI void APIENTRY glVertexAttribP3uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
extern PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv;
// GLAPI void APIENTRY glVertexAttribP4ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
extern PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui;
// GLAPI void APIENTRY glVertexAttribP4uiv (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
extern PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv;
// GLAPI void APIENTRY glVertexP2ui (GLenum type, GLuint value);
extern PFNGLVERTEXP2UIPROC glVertexP2ui;
// GLAPI void APIENTRY glVertexP2uiv (GLenum type, const GLuint *value);
extern PFNGLVERTEXP2UIVPROC glVertexP2uiv;
// GLAPI void APIENTRY glVertexP3ui (GLenum type, GLuint value);
extern PFNGLVERTEXP3UIPROC glVertexP3ui;
// GLAPI void APIENTRY glVertexP3uiv (GLenum type, const GLuint *value);
extern PFNGLVERTEXP3UIVPROC glVertexP3uiv;
// GLAPI void APIENTRY glVertexP4ui (GLenum type, GLuint value);
extern PFNGLVERTEXP4UIPROC glVertexP4ui;
// GLAPI void APIENTRY glVertexP4uiv (GLenum type, const GLuint *value);
extern PFNGLVERTEXP4UIVPROC glVertexP4uiv;
// GLAPI void APIENTRY glTexCoordP1ui (GLenum type, GLuint coords);
extern PFNGLTEXCOORDP1UIPROC glTexCoordP1ui;
// GLAPI void APIENTRY glTexCoordP1uiv (GLenum type, const GLuint *coords);
extern PFNGLTEXCOORDP1UIVPROC glTexCoordP1uiv;
// GLAPI void APIENTRY glTexCoordP2ui (GLenum type, GLuint coords);
extern PFNGLTEXCOORDP2UIPROC glTexCoordP2ui;
// GLAPI void APIENTRY glTexCoordP2uiv (GLenum type, const GLuint *coords);
extern PFNGLTEXCOORDP2UIVPROC glTexCoordP2uiv;
// GLAPI void APIENTRY glTexCoordP3ui (GLenum type, GLuint coords);
extern PFNGLTEXCOORDP3UIPROC glTexCoordP3ui;
// GLAPI void APIENTRY glTexCoordP3uiv (GLenum type, const GLuint *coords);
extern PFNGLTEXCOORDP3UIVPROC glTexCoordP3uiv;
// GLAPI void APIENTRY glTexCoordP4ui (GLenum type, GLuint coords);
extern PFNGLTEXCOORDP4UIPROC glTexCoordP4ui;
// GLAPI void APIENTRY glTexCoordP4uiv (GLenum type, const GLuint *coords);
extern PFNGLTEXCOORDP4UIVPROC glTexCoordP4uiv;
// GLAPI void APIENTRY glMultiTexCoordP1ui (GLenum texture, GLenum type, GLuint coords);
extern PFNGLMULTITEXCOORDP1UIPROC glMultiTexCoordP1ui;
// GLAPI void APIENTRY glMultiTexCoordP1uiv (GLenum texture, GLenum type, const GLuint *coords);
extern PFNGLMULTITEXCOORDP1UIVPROC glMultiTexCoordP1uiv;
// GLAPI void APIENTRY glMultiTexCoordP2ui (GLenum texture, GLenum type, GLuint coords);
extern PFNGLMULTITEXCOORDP2UIPROC glMultiTexCoordP2ui;
// GLAPI void APIENTRY glMultiTexCoordP2uiv (GLenum texture, GLenum type, const GLuint *coords);
extern PFNGLMULTITEXCOORDP2UIVPROC glMultiTexCoordP2uiv;
// GLAPI void APIENTRY glMultiTexCoordP3ui (GLenum texture, GLenum type, GLuint coords);
extern PFNGLMULTITEXCOORDP3UIPROC glMultiTexCoordP3ui;
// GLAPI void APIENTRY glMultiTexCoordP3uiv (GLenum texture, GLenum type, const GLuint *coords);
extern PFNGLMULTITEXCOORDP3UIVPROC glMultiTexCoordP3uiv;
// GLAPI void APIENTRY glMultiTexCoordP4ui (GLenum texture, GLenum type, GLuint coords);
extern PFNGLMULTITEXCOORDP4UIPROC glMultiTexCoordP4ui;
// GLAPI void APIENTRY glMultiTexCoordP4uiv (GLenum texture, GLenum type, const GLuint *coords);
extern PFNGLMULTITEXCOORDP4UIVPROC glMultiTexCoordP4uiv;
// GLAPI void APIENTRY glNormalP3ui (GLenum type, GLuint coords);
extern PFNGLNORMALP3UIPROC glNormalP3ui;
// GLAPI void APIENTRY glNormalP3uiv (GLenum type, const GLuint *coords);
extern PFNGLNORMALP3UIVPROC glNormalP3uiv;
// GLAPI void APIENTRY glColorP3ui (GLenum type, GLuint color);
extern PFNGLCOLORP3UIPROC glColorP3ui;
// GLAPI void APIENTRY glColorP3uiv (GLenum type, const GLuint *color);
extern PFNGLCOLORP3UIVPROC glColorP3uiv;
// GLAPI void APIENTRY glColorP4ui (GLenum type, GLuint color);
extern PFNGLCOLORP4UIPROC glColorP4ui;
// GLAPI void APIENTRY glColorP4uiv (GLenum type, const GLuint *color);
extern PFNGLCOLORP4UIVPROC glColorP4uiv;
// GLAPI void APIENTRY glSecondaryColorP3ui (GLenum type, GLuint color);
extern PFNGLSECONDARYCOLORP3UIPROC glSecondaryColorP3ui;
// GLAPI void APIENTRY glSecondaryColorP3uiv (GLenum type, const GLuint *color);
extern PFNGLSECONDARYCOLORP3UIVPROC glSecondaryColorP3uiv;


// GL_VERSION_4_0
// GLAPI void APIENTRY glMinSampleShading (GLfloat value);
extern PFNGLMINSAMPLESHADINGPROC glMinSampleShading;
// GLAPI void APIENTRY glBlendEquationi (GLuint buf, GLenum mode);
extern PFNGLBLENDEQUATIONIPROC glBlendEquationi;
// GLAPI void APIENTRY glBlendEquationSeparatei (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
extern PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei;
// GLAPI void APIENTRY glBlendFunci (GLuint buf, GLenum src, GLenum dst);
extern PFNGLBLENDFUNCIPROC glBlendFunci;
// GLAPI void APIENTRY glBlendFuncSeparatei (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
extern PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei;
// GLAPI void APIENTRY glDrawArraysIndirect (GLenum mode, const void *indirect);
extern PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect;
// GLAPI void APIENTRY glDrawElementsIndirect (GLenum mode, GLenum type, const void *indirect);
extern PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect;
// GLAPI void APIENTRY glUniform1d (GLint location, GLdouble x);
extern PFNGLUNIFORM1DPROC glUniform1d;
// GLAPI void APIENTRY glUniform2d (GLint location, GLdouble x, GLdouble y);
extern PFNGLUNIFORM2DPROC glUniform2d;
// GLAPI void APIENTRY glUniform3d (GLint location, GLdouble x, GLdouble y, GLdouble z);
extern PFNGLUNIFORM3DPROC glUniform3d;
// GLAPI void APIENTRY glUniform4d (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern PFNGLUNIFORM4DPROC glUniform4d;
// GLAPI void APIENTRY glUniform1dv (GLint location, GLsizei count, const GLdouble *value);
extern PFNGLUNIFORM1DVPROC glUniform1dv;
// GLAPI void APIENTRY glUniform2dv (GLint location, GLsizei count, const GLdouble *value);
extern PFNGLUNIFORM2DVPROC glUniform2dv;
// GLAPI void APIENTRY glUniform3dv (GLint location, GLsizei count, const GLdouble *value);
extern PFNGLUNIFORM3DVPROC glUniform3dv;
// GLAPI void APIENTRY glUniform4dv (GLint location, GLsizei count, const GLdouble *value);
extern PFNGLUNIFORM4DVPROC glUniform4dv;
// GLAPI void APIENTRY glUniformMatrix2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv;
// GLAPI void APIENTRY glUniformMatrix3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv;
// GLAPI void APIENTRY glUniformMatrix4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv;
// GLAPI void APIENTRY glUniformMatrix2x3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv;
// GLAPI void APIENTRY glUniformMatrix2x4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv;
// GLAPI void APIENTRY glUniformMatrix3x2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv;
// GLAPI void APIENTRY glUniformMatrix3x4dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv;
// GLAPI void APIENTRY glUniformMatrix4x2dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv;
// GLAPI void APIENTRY glUniformMatrix4x3dv (GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv;
// GLAPI void APIENTRY glGetUniformdv (GLuint program, GLint location, GLdouble *params);
extern PFNGLGETUNIFORMDVPROC glGetUniformdv;
// GLAPI GLint APIENTRY glGetSubroutineUniformLocation (GLuint program, GLenum shadertype, const GLchar *name);
extern PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation;
// GLAPI GLuint APIENTRY glGetSubroutineIndex (GLuint program, GLenum shadertype, const GLchar *name);
extern PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex;
// GLAPI void APIENTRY glGetActiveSubroutineUniformiv (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
extern PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv;
// GLAPI void APIENTRY glGetActiveSubroutineUniformName (GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
extern PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName;
// GLAPI void APIENTRY glGetActiveSubroutineName (GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
extern PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName;
// GLAPI void APIENTRY glUniformSubroutinesuiv (GLenum shadertype, GLsizei count, const GLuint *indices);
extern PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv;
// GLAPI void APIENTRY glGetUniformSubroutineuiv (GLenum shadertype, GLint location, GLuint *params);
extern PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv;
// GLAPI void APIENTRY glGetProgramStageiv (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
extern PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv;
// GLAPI void APIENTRY glPatchParameteri (GLenum pname, GLint value);
extern PFNGLPATCHPARAMETERIPROC glPatchParameteri;
// GLAPI void APIENTRY glPatchParameterfv (GLenum pname, const GLfloat *values);
extern PFNGLPATCHPARAMETERFVPROC glPatchParameterfv;
// GLAPI void APIENTRY glBindTransformFeedback (GLenum target, GLuint id);
extern PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback;
// GLAPI void APIENTRY glDeleteTransformFeedbacks (GLsizei n, const GLuint *ids);
extern PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks;
// GLAPI void APIENTRY glGenTransformFeedbacks (GLsizei n, GLuint *ids);
extern PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks;
// GLAPI GLboolean APIENTRY glIsTransformFeedback (GLuint id);
extern PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback;
// GLAPI void APIENTRY glPauseTransformFeedback (void);
extern PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback;
// GLAPI void APIENTRY glResumeTransformFeedback (void);
extern PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback;
// GLAPI void APIENTRY glDrawTransformFeedback (GLenum mode, GLuint id);
extern PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback;
// GLAPI void APIENTRY glDrawTransformFeedbackStream (GLenum mode, GLuint id, GLuint stream);
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream;
// GLAPI void APIENTRY glBeginQueryIndexed (GLenum target, GLuint index, GLuint id);
extern PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed;
// GLAPI void APIENTRY glEndQueryIndexed (GLenum target, GLuint index);
extern PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed;
// GLAPI void APIENTRY glGetQueryIndexediv (GLenum target, GLuint index, GLenum pname, GLint *params);
extern PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv;


// GL_VERSION_4_1
// GLAPI void APIENTRY glReleaseShaderCompiler (void);
extern PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler;
// GLAPI void APIENTRY glShaderBinary (GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length);
extern PFNGLSHADERBINARYPROC glShaderBinary;
// GLAPI void APIENTRY glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
extern PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat;
// GLAPI void APIENTRY glDepthRangef (GLfloat n, GLfloat f);
extern PFNGLDEPTHRANGEFPROC glDepthRangef;
// GLAPI void APIENTRY glClearDepthf (GLfloat d);
extern PFNGLCLEARDEPTHFPROC glClearDepthf;
// GLAPI void APIENTRY glGetProgramBinary (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
extern PFNGLGETPROGRAMBINARYPROC glGetProgramBinary;
// GLAPI void APIENTRY glProgramBinary (GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
extern PFNGLPROGRAMBINARYPROC glProgramBinary;
// GLAPI void APIENTRY glProgramParameteri (GLuint program, GLenum pname, GLint value);
extern PFNGLPROGRAMPARAMETERIPROC glProgramParameteri;
// GLAPI void APIENTRY glUseProgramStages (GLuint pipeline, GLbitfield stages, GLuint program);
extern PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages;
// GLAPI void APIENTRY glActiveShaderProgram (GLuint pipeline, GLuint program);
extern PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram;
// GLAPI GLuint APIENTRY glCreateShaderProgramv (GLenum type, GLsizei count, const GLchar *const*strings);
extern PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv;
// GLAPI void APIENTRY glBindProgramPipeline (GLuint pipeline);
extern PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline;
// GLAPI void APIENTRY glDeleteProgramPipelines (GLsizei n, const GLuint *pipelines);
extern PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines;
// GLAPI void APIENTRY glGenProgramPipelines (GLsizei n, GLuint *pipelines);
extern PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines;
// GLAPI GLboolean APIENTRY glIsProgramPipeline (GLuint pipeline);
extern PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline;
// GLAPI void APIENTRY glGetProgramPipelineiv (GLuint pipeline, GLenum pname, GLint *params);
extern PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv;
// GLAPI void APIENTRY glProgramUniform1i (GLuint program, GLint location, GLint v0);
extern PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i;
// GLAPI void APIENTRY glProgramUniform1iv (GLuint program, GLint location, GLsizei count, const GLint *value);
extern PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv;
// GLAPI void APIENTRY glProgramUniform1f (GLuint program, GLint location, GLfloat v0);
extern PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f;
// GLAPI void APIENTRY glProgramUniform1fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
extern PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv;
// GLAPI void APIENTRY glProgramUniform1d (GLuint program, GLint location, GLdouble v0);
extern PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d;
// GLAPI void APIENTRY glProgramUniform1dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
extern PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv;
// GLAPI void APIENTRY glProgramUniform1ui (GLuint program, GLint location, GLuint v0);
extern PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui;
// GLAPI void APIENTRY glProgramUniform1uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
extern PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv;
// GLAPI void APIENTRY glProgramUniform2i (GLuint program, GLint location, GLint v0, GLint v1);
extern PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i;
// GLAPI void APIENTRY glProgramUniform2iv (GLuint program, GLint location, GLsizei count, const GLint *value);
extern PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv;
// GLAPI void APIENTRY glProgramUniform2f (GLuint program, GLint location, GLfloat v0, GLfloat v1);
extern PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f;
// GLAPI void APIENTRY glProgramUniform2fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
extern PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv;
// GLAPI void APIENTRY glProgramUniform2d (GLuint program, GLint location, GLdouble v0, GLdouble v1);
extern PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d;
// GLAPI void APIENTRY glProgramUniform2dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
extern PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv;
// GLAPI void APIENTRY glProgramUniform2ui (GLuint program, GLint location, GLuint v0, GLuint v1);
extern PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui;
// GLAPI void APIENTRY glProgramUniform2uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
extern PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv;
// GLAPI void APIENTRY glProgramUniform3i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
extern PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i;
// GLAPI void APIENTRY glProgramUniform3iv (GLuint program, GLint location, GLsizei count, const GLint *value);
extern PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv;
// GLAPI void APIENTRY glProgramUniform3f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
extern PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f;
// GLAPI void APIENTRY glProgramUniform3fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
extern PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv;
// GLAPI void APIENTRY glProgramUniform3d (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
extern PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d;
// GLAPI void APIENTRY glProgramUniform3dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
extern PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv;
// GLAPI void APIENTRY glProgramUniform3ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
extern PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui;
// GLAPI void APIENTRY glProgramUniform3uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
extern PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv;
// GLAPI void APIENTRY glProgramUniform4i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
extern PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i;
// GLAPI void APIENTRY glProgramUniform4iv (GLuint program, GLint location, GLsizei count, const GLint *value);
extern PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv;
// GLAPI void APIENTRY glProgramUniform4f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
extern PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f;
// GLAPI void APIENTRY glProgramUniform4fv (GLuint program, GLint location, GLsizei count, const GLfloat *value);
extern PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv;
// GLAPI void APIENTRY glProgramUniform4d (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
extern PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d;
// GLAPI void APIENTRY glProgramUniform4dv (GLuint program, GLint location, GLsizei count, const GLdouble *value);
extern PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv;
// GLAPI void APIENTRY glProgramUniform4ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
extern PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui;
// GLAPI void APIENTRY glProgramUniform4uiv (GLuint program, GLint location, GLsizei count, const GLuint *value);
extern PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv;
// GLAPI void APIENTRY glProgramUniformMatrix2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv;
// GLAPI void APIENTRY glProgramUniformMatrix3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv;
// GLAPI void APIENTRY glProgramUniformMatrix4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv;
// GLAPI void APIENTRY glProgramUniformMatrix2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv;
// GLAPI void APIENTRY glProgramUniformMatrix3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv;
// GLAPI void APIENTRY glProgramUniformMatrix4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv;
// GLAPI void APIENTRY glProgramUniformMatrix2x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv;
// GLAPI void APIENTRY glProgramUniformMatrix3x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv;
// GLAPI void APIENTRY glProgramUniformMatrix2x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv;
// GLAPI void APIENTRY glProgramUniformMatrix4x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv;
// GLAPI void APIENTRY glProgramUniformMatrix3x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv;
// GLAPI void APIENTRY glProgramUniformMatrix4x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
extern PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv;
// GLAPI void APIENTRY glProgramUniformMatrix2x3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv;
// GLAPI void APIENTRY glProgramUniformMatrix3x2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv;
// GLAPI void APIENTRY glProgramUniformMatrix2x4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv;
// GLAPI void APIENTRY glProgramUniformMatrix4x2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv;
// GLAPI void APIENTRY glProgramUniformMatrix3x4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv;
// GLAPI void APIENTRY glProgramUniformMatrix4x3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
extern PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv;
// GLAPI void APIENTRY glValidateProgramPipeline (GLuint pipeline);
extern PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline;
// GLAPI void APIENTRY glGetProgramPipelineInfoLog (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
extern PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog;
// GLAPI void APIENTRY glVertexAttribL1d (GLuint index, GLdouble x);
extern PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d;
// GLAPI void APIENTRY glVertexAttribL2d (GLuint index, GLdouble x, GLdouble y);
extern PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d;
// GLAPI void APIENTRY glVertexAttribL3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
extern PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d;
// GLAPI void APIENTRY glVertexAttribL4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
extern PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d;
// GLAPI void APIENTRY glVertexAttribL1dv (GLuint index, const GLdouble *v);
extern PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv;
// GLAPI void APIENTRY glVertexAttribL2dv (GLuint index, const GLdouble *v);
extern PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv;
// GLAPI void APIENTRY glVertexAttribL3dv (GLuint index, const GLdouble *v);
extern PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv;
// GLAPI void APIENTRY glVertexAttribL4dv (GLuint index, const GLdouble *v);
extern PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv;
// GLAPI void APIENTRY glVertexAttribLPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
extern PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer;
// GLAPI void APIENTRY glGetVertexAttribLdv (GLuint index, GLenum pname, GLdouble *params);
extern PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv;
// GLAPI void APIENTRY glViewportArrayv (GLuint first, GLsizei count, const GLfloat *v);
extern PFNGLVIEWPORTARRAYVPROC glViewportArrayv;
// GLAPI void APIENTRY glViewportIndexedf (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
extern PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf;
// GLAPI void APIENTRY glViewportIndexedfv (GLuint index, const GLfloat *v);
extern PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv;
// GLAPI void APIENTRY glScissorArrayv (GLuint first, GLsizei count, const GLint *v);
extern PFNGLSCISSORARRAYVPROC glScissorArrayv;
// GLAPI void APIENTRY glScissorIndexed (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
extern PFNGLSCISSORINDEXEDPROC glScissorIndexed;
// GLAPI void APIENTRY glScissorIndexedv (GLuint index, const GLint *v);
extern PFNGLSCISSORINDEXEDVPROC glScissorIndexedv;
// GLAPI void APIENTRY glDepthRangeArrayv (GLuint first, GLsizei count, const GLdouble *v);
extern PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv;
// GLAPI void APIENTRY glDepthRangeIndexed (GLuint index, GLdouble n, GLdouble f);
extern PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed;
// GLAPI void APIENTRY glGetFloati_v (GLenum target, GLuint index, GLfloat *data);
extern PFNGLGETFLOATI_VPROC glGetFloati_v;
// GLAPI void APIENTRY glGetDoublei_v (GLenum target, GLuint index, GLdouble *data);
extern PFNGLGETDOUBLEI_VPROC glGetDoublei_v;


// GL_VERSION_4_2
// GLAPI void APIENTRY glDrawArraysInstancedBaseInstance (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
extern PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance;
// GLAPI void APIENTRY glDrawElementsInstancedBaseInstance (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
extern PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance;
// GLAPI void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance;
// GLAPI void APIENTRY glGetInternalformativ (GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint *params);
extern PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ;
// GLAPI void APIENTRY glGetActiveAtomicCounterBufferiv (GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
extern PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv;
// GLAPI void APIENTRY glBindImageTexture (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
extern PFNGLBINDIMAGETEXTUREPROC glBindImageTexture;
// GLAPI void APIENTRY glMemoryBarrier (GLbitfield barriers);
extern PFNGLMEMORYBARRIERPROC glMemoryBarrier;
// GLAPI void APIENTRY glTexStorage1D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
extern PFNGLTEXSTORAGE1DPROC glTexStorage1D;
// GLAPI void APIENTRY glTexStorage2D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
extern PFNGLTEXSTORAGE2DPROC glTexStorage2D;
// GLAPI void APIENTRY glTexStorage3D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
extern PFNGLTEXSTORAGE3DPROC glTexStorage3D;
// GLAPI void APIENTRY glDrawTransformFeedbackInstanced (GLenum mode, GLuint id, GLsizei instancecount);
extern PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced;
// GLAPI void APIENTRY glDrawTransformFeedbackStreamInstanced (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced;


// GL_VERSION_4_3
// GLAPI void APIENTRY glClearBufferData (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
extern PFNGLCLEARBUFFERDATAPROC glClearBufferData;
// GLAPI void APIENTRY glClearBufferSubData (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
extern PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData;
// GLAPI void APIENTRY glDispatchCompute (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
extern PFNGLDISPATCHCOMPUTEPROC glDispatchCompute;
// GLAPI void APIENTRY glDispatchComputeIndirect (GLintptr indirect);
extern PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect;
// GLAPI void APIENTRY glCopyImageSubData (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
extern PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubData;
// GLAPI void APIENTRY glFramebufferParameteri (GLenum target, GLenum pname, GLint param);
extern PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri;
// GLAPI void APIENTRY glGetFramebufferParameteriv (GLenum target, GLenum pname, GLint *params);
extern PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv;
// GLAPI void APIENTRY glGetInternalformati64v (GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 *params);
extern PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64v;
// GLAPI void APIENTRY glInvalidateTexSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
extern PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage;
// GLAPI void APIENTRY glInvalidateTexImage (GLuint texture, GLint level);
extern PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage;
// GLAPI void APIENTRY glInvalidateBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr length);
extern PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData;
// GLAPI void APIENTRY glInvalidateBufferData (GLuint buffer);
extern PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData;
// GLAPI void APIENTRY glInvalidateFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments);
extern PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer;
// GLAPI void APIENTRY glInvalidateSubFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
extern PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer;
// GLAPI void APIENTRY glMultiDrawArraysIndirect (GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
extern PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect;
// GLAPI void APIENTRY glMultiDrawElementsIndirect (GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
extern PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect;
// GLAPI void APIENTRY glGetProgramInterfaceiv (GLuint program, GLenum programInterface, GLenum pname, GLint *params);
extern PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv;
// GLAPI GLuint APIENTRY glGetProgramResourceIndex (GLuint program, GLenum programInterface, const GLchar *name);
extern PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex;
// GLAPI void APIENTRY glGetProgramResourceName (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
extern PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName;
// GLAPI void APIENTRY glGetProgramResourceiv (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLint *params);
extern PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv;
// GLAPI GLint APIENTRY glGetProgramResourceLocation (GLuint program, GLenum programInterface, const GLchar *name);
extern PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation;
// GLAPI GLint APIENTRY glGetProgramResourceLocationIndex (GLuint program, GLenum programInterface, const GLchar *name);
extern PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex;
// GLAPI void APIENTRY glShaderStorageBlockBinding (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
extern PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding;
// GLAPI void APIENTRY glTexBufferRange (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern PFNGLTEXBUFFERRANGEPROC glTexBufferRange;
// GLAPI void APIENTRY glTexStorage2DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
extern PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultisample;
// GLAPI void APIENTRY glTexStorage3DMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
extern PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage3DMultisample;
// GLAPI void APIENTRY glTextureView (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
extern PFNGLTEXTUREVIEWPROC glTextureView;
// GLAPI void APIENTRY glBindVertexBuffer (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
extern PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer;
// GLAPI void APIENTRY glVertexAttribFormat (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
extern PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat;
// GLAPI void APIENTRY glVertexAttribIFormat (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
extern PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat;
// GLAPI void APIENTRY glVertexAttribLFormat (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
extern PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat;
// GLAPI void APIENTRY glVertexAttribBinding (GLuint attribindex, GLuint bindingindex);
extern PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding;
// GLAPI void APIENTRY glVertexBindingDivisor (GLuint bindingindex, GLuint divisor);
extern PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor;
// GLAPI void APIENTRY glDebugMessageControl (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
extern PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl;
// GLAPI void APIENTRY glDebugMessageInsert (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
extern PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert;
// GLAPI void APIENTRY glDebugMessageCallback (GLDEBUGPROC callback, const void *userParam);
extern PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback;
// GLAPI GLuint APIENTRY glGetDebugMessageLog (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
extern PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog;
// GLAPI void APIENTRY glPushDebugGroup (GLenum source, GLuint id, GLsizei length, const GLchar *message);
extern PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup;
// GLAPI void APIENTRY glPopDebugGroup (void);
extern PFNGLPOPDEBUGGROUPPROC glPopDebugGroup;
// GLAPI void APIENTRY glObjectLabel (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
extern PFNGLOBJECTLABELPROC glObjectLabel;
// GLAPI void APIENTRY glGetObjectLabel (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
extern PFNGLGETOBJECTLABELPROC glGetObjectLabel;
// GLAPI void APIENTRY glObjectPtrLabel (const void *ptr, GLsizei length, const GLchar *label);
extern PFNGLOBJECTPTRLABELPROC glObjectPtrLabel;
// GLAPI void APIENTRY glGetObjectPtrLabel (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);
extern PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel;


// GL_VERSION_4_4
// GLAPI void APIENTRY glBufferStorage (GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
extern PFNGLBUFFERSTORAGEPROC glBufferStorage;
// GLAPI void APIENTRY glClearTexImage (GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
extern PFNGLCLEARTEXIMAGEPROC glClearTexImage;
// GLAPI void APIENTRY glClearTexSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
extern PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage;
// GLAPI void APIENTRY glBindBuffersBase (GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
extern PFNGLBINDBUFFERSBASEPROC glBindBuffersBase;
// GLAPI void APIENTRY glBindBuffersRange (GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
extern PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange;
// GLAPI void APIENTRY glBindTextures (GLuint first, GLsizei count, const GLuint *textures);
extern PFNGLBINDTEXTURESPROC glBindTextures;
// GLAPI void APIENTRY glBindSamplers (GLuint first, GLsizei count, const GLuint *samplers);
extern PFNGLBINDSAMPLERSPROC glBindSamplers;
// GLAPI void APIENTRY glBindImageTextures (GLuint first, GLsizei count, const GLuint *textures);
extern PFNGLBINDIMAGETEXTURESPROC glBindImageTextures;
// GLAPI void APIENTRY glBindVertexBuffers (GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
extern PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers;


// GL_VERSION_4_5
// GLAPI void APIENTRY glClipControl (GLenum origin, GLenum depth);
extern PFNGLCLIPCONTROLPROC glClipControl;
// GLAPI void APIENTRY glCreateTransformFeedbacks (GLsizei n, GLuint *ids);
extern PFNGLCREATETRANSFORMFEEDBACKSPROC glCreateTransformFeedbacks;
// GLAPI void APIENTRY glTransformFeedbackBufferBase (GLuint xfb, GLuint index, GLuint buffer);
extern PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glTransformFeedbackBufferBase;
// GLAPI void APIENTRY glTransformFeedbackBufferRange (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glTransformFeedbackBufferRange;
// GLAPI void APIENTRY glGetTransformFeedbackiv (GLuint xfb, GLenum pname, GLint *param);
extern PFNGLGETTRANSFORMFEEDBACKIVPROC glGetTransformFeedbackiv;
// GLAPI void APIENTRY glGetTransformFeedbacki_v (GLuint xfb, GLenum pname, GLuint index, GLint *param);
extern PFNGLGETTRANSFORMFEEDBACKI_VPROC glGetTransformFeedbacki_v;
// GLAPI void APIENTRY glGetTransformFeedbacki64_v (GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
extern PFNGLGETTRANSFORMFEEDBACKI64_VPROC glGetTransformFeedbacki64_v;
// GLAPI void APIENTRY glCreateBuffers (GLsizei n, GLuint *buffers);
extern PFNGLCREATEBUFFERSPROC glCreateBuffers;
// GLAPI void APIENTRY glNamedBufferStorage (GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
extern PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage;
// GLAPI void APIENTRY glNamedBufferData (GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
extern PFNGLNAMEDBUFFERDATAPROC glNamedBufferData;
// GLAPI void APIENTRY glNamedBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
extern PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData;
// GLAPI void APIENTRY glCopyNamedBufferSubData (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
extern PFNGLCOPYNAMEDBUFFERSUBDATAPROC glCopyNamedBufferSubData;
// GLAPI void APIENTRY glClearNamedBufferData (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
extern PFNGLCLEARNAMEDBUFFERDATAPROC glClearNamedBufferData;
// GLAPI void APIENTRY glClearNamedBufferSubData (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
extern PFNGLCLEARNAMEDBUFFERSUBDATAPROC glClearNamedBufferSubData;
// GLAPI void *APIENTRY glMapNamedBuffer (GLuint buffer, GLenum access);
extern PFNGLMAPNAMEDBUFFERPROC glMapNamedBuffer;
// GLAPI void *APIENTRY glMapNamedBufferRange (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
extern PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange;
// GLAPI GLboolean APIENTRY glUnmapNamedBuffer (GLuint buffer);
extern PFNGLUNMAPNAMEDBUFFERPROC glUnmapNamedBuffer;
// GLAPI void APIENTRY glFlushMappedNamedBufferRange (GLuint buffer, GLintptr offset, GLsizeiptr length);
extern PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRange;
// GLAPI void APIENTRY glGetNamedBufferParameteriv (GLuint buffer, GLenum pname, GLint *params);
extern PFNGLGETNAMEDBUFFERPARAMETERIVPROC glGetNamedBufferParameteriv;
// GLAPI void APIENTRY glGetNamedBufferParameteri64v (GLuint buffer, GLenum pname, GLint64 *params);
extern PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glGetNamedBufferParameteri64v;
// GLAPI void APIENTRY glGetNamedBufferPointerv (GLuint buffer, GLenum pname, void **params);
extern PFNGLGETNAMEDBUFFERPOINTERVPROC glGetNamedBufferPointerv;
// GLAPI void APIENTRY glGetNamedBufferSubData (GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
extern PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData;
// GLAPI void APIENTRY glCreateFramebuffers (GLsizei n, GLuint *framebuffers);
extern PFNGLCREATEFRAMEBUFFERSPROC glCreateFramebuffers;
// GLAPI void APIENTRY glNamedFramebufferRenderbuffer (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
extern PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer;
// GLAPI void APIENTRY glNamedFramebufferParameteri (GLuint framebuffer, GLenum pname, GLint param);
extern PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glNamedFramebufferParameteri;
// GLAPI void APIENTRY glNamedFramebufferTexture (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
extern PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture;
// GLAPI void APIENTRY glNamedFramebufferTextureLayer (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
extern PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glNamedFramebufferTextureLayer;
// GLAPI void APIENTRY glNamedFramebufferDrawBuffer (GLuint framebuffer, GLenum buf);
extern PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glNamedFramebufferDrawBuffer;
// GLAPI void APIENTRY glNamedFramebufferDrawBuffers (GLuint framebuffer, GLsizei n, const GLenum *bufs);
extern PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glNamedFramebufferDrawBuffers;
// GLAPI void APIENTRY glNamedFramebufferReadBuffer (GLuint framebuffer, GLenum src);
extern PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glNamedFramebufferReadBuffer;
// GLAPI void APIENTRY glInvalidateNamedFramebufferData (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
extern PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glInvalidateNamedFramebufferData;
// GLAPI void APIENTRY glInvalidateNamedFramebufferSubData (GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
extern PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glInvalidateNamedFramebufferSubData;
// GLAPI void APIENTRY glClearNamedFramebufferiv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
extern PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glClearNamedFramebufferiv;
// GLAPI void APIENTRY glClearNamedFramebufferuiv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
extern PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glClearNamedFramebufferuiv;
// GLAPI void APIENTRY glClearNamedFramebufferfv (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
extern PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glClearNamedFramebufferfv;
// GLAPI void APIENTRY glClearNamedFramebufferfi (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
extern PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glClearNamedFramebufferfi;
// GLAPI void APIENTRY glBlitNamedFramebuffer (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
extern PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer;
// GLAPI GLenum APIENTRY glCheckNamedFramebufferStatus (GLuint framebuffer, GLenum target);
extern PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus;
// GLAPI void APIENTRY glGetNamedFramebufferParameteriv (GLuint framebuffer, GLenum pname, GLint *param);
extern PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv;
// GLAPI void APIENTRY glGetNamedFramebufferAttachmentParameteriv (GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
extern PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv;
// GLAPI void APIENTRY glCreateRenderbuffers (GLsizei n, GLuint *renderbuffers);
extern PFNGLCREATERENDERBUFFERSPROC glCreateRenderbuffers;
// GLAPI void APIENTRY glNamedRenderbufferStorage (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
extern PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage;
// GLAPI void APIENTRY glNamedRenderbufferStorageMultisample (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
extern PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample;
// GLAPI void APIENTRY glGetNamedRenderbufferParameteriv (GLuint renderbuffer, GLenum pname, GLint *params);
extern PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv;
// GLAPI void APIENTRY glCreateTextures (GLenum target, GLsizei n, GLuint *textures);
extern PFNGLCREATETEXTURESPROC glCreateTextures;
// GLAPI void APIENTRY glTextureBuffer (GLuint texture, GLenum internalformat, GLuint buffer);
extern PFNGLTEXTUREBUFFERPROC glTextureBuffer;
// GLAPI void APIENTRY glTextureBufferRange (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
extern PFNGLTEXTUREBUFFERRANGEPROC glTextureBufferRange;
// GLAPI void APIENTRY glTextureStorage1D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
extern PFNGLTEXTURESTORAGE1DPROC glTextureStorage1D;
// GLAPI void APIENTRY glTextureStorage2D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
extern PFNGLTEXTURESTORAGE2DPROC glTextureStorage2D;
// GLAPI void APIENTRY glTextureStorage3D (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
extern PFNGLTEXTURESTORAGE3DPROC glTextureStorage3D;
// GLAPI void APIENTRY glTextureStorage2DMultisample (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
extern PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glTextureStorage2DMultisample;
// GLAPI void APIENTRY glTextureStorage3DMultisample (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
extern PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glTextureStorage3DMultisample;
// GLAPI void APIENTRY glTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
extern PFNGLTEXTURESUBIMAGE1DPROC glTextureSubImage1D;
// GLAPI void APIENTRY glTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
extern PFNGLTEXTURESUBIMAGE2DPROC glTextureSubImage2D;
// GLAPI void APIENTRY glTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
extern PFNGLTEXTURESUBIMAGE3DPROC glTextureSubImage3D;
// GLAPI void APIENTRY glCompressedTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glCompressedTextureSubImage1D;
// GLAPI void APIENTRY glCompressedTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glCompressedTextureSubImage2D;
// GLAPI void APIENTRY glCompressedTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glCompressedTextureSubImage3D;
// GLAPI void APIENTRY glCopyTextureSubImage1D (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
extern PFNGLCOPYTEXTURESUBIMAGE1DPROC glCopyTextureSubImage1D;
// GLAPI void APIENTRY glCopyTextureSubImage2D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern PFNGLCOPYTEXTURESUBIMAGE2DPROC glCopyTextureSubImage2D;
// GLAPI void APIENTRY glCopyTextureSubImage3D (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern PFNGLCOPYTEXTURESUBIMAGE3DPROC glCopyTextureSubImage3D;
// GLAPI void APIENTRY glTextureParameterf (GLuint texture, GLenum pname, GLfloat param);
extern PFNGLTEXTUREPARAMETERFPROC glTextureParameterf;
// GLAPI void APIENTRY glTextureParameterfv (GLuint texture, GLenum pname, const GLfloat *param);
extern PFNGLTEXTUREPARAMETERFVPROC glTextureParameterfv;
// GLAPI void APIENTRY glTextureParameteri (GLuint texture, GLenum pname, GLint param);
extern PFNGLTEXTUREPARAMETERIPROC glTextureParameteri;
// GLAPI void APIENTRY glTextureParameterIiv (GLuint texture, GLenum pname, const GLint *params);
extern PFNGLTEXTUREPARAMETERIIVPROC glTextureParameterIiv;
// GLAPI void APIENTRY glTextureParameterIuiv (GLuint texture, GLenum pname, const GLuint *params);
extern PFNGLTEXTUREPARAMETERIUIVPROC glTextureParameterIuiv;
// GLAPI void APIENTRY glTextureParameteriv (GLuint texture, GLenum pname, const GLint *param);
extern PFNGLTEXTUREPARAMETERIVPROC glTextureParameteriv;
// GLAPI void APIENTRY glGenerateTextureMipmap (GLuint texture);
extern PFNGLGENERATETEXTUREMIPMAPPROC glGenerateTextureMipmap;
// GLAPI void APIENTRY glBindTextureUnit (GLuint unit, GLuint texture);
extern PFNGLBINDTEXTUREUNITPROC glBindTextureUnit;
// GLAPI void APIENTRY glGetTextureImage (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
extern PFNGLGETTEXTUREIMAGEPROC glGetTextureImage;
// GLAPI void APIENTRY glGetCompressedTextureImage (GLuint texture, GLint level, GLsizei bufSize, void *pixels);
extern PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glGetCompressedTextureImage;
// GLAPI void APIENTRY glGetTextureLevelParameterfv (GLuint texture, GLint level, GLenum pname, GLfloat *params);
extern PFNGLGETTEXTURELEVELPARAMETERFVPROC glGetTextureLevelParameterfv;
// GLAPI void APIENTRY glGetTextureLevelParameteriv (GLuint texture, GLint level, GLenum pname, GLint *params);
extern PFNGLGETTEXTURELEVELPARAMETERIVPROC glGetTextureLevelParameteriv;
// GLAPI void APIENTRY glGetTextureParameterfv (GLuint texture, GLenum pname, GLfloat *params);
extern PFNGLGETTEXTUREPARAMETERFVPROC glGetTextureParameterfv;
// GLAPI void APIENTRY glGetTextureParameterIiv (GLuint texture, GLenum pname, GLint *params);
extern PFNGLGETTEXTUREPARAMETERIIVPROC glGetTextureParameterIiv;
// GLAPI void APIENTRY glGetTextureParameterIuiv (GLuint texture, GLenum pname, GLuint *params);
extern PFNGLGETTEXTUREPARAMETERIUIVPROC glGetTextureParameterIuiv;
// GLAPI void APIENTRY glGetTextureParameteriv (GLuint texture, GLenum pname, GLint *params);
extern PFNGLGETTEXTUREPARAMETERIVPROC glGetTextureParameteriv;
// GLAPI void APIENTRY glCreateVertexArrays (GLsizei n, GLuint *arrays);
extern PFNGLCREATEVERTEXARRAYSPROC glCreateVertexArrays;
// GLAPI void APIENTRY glDisableVertexArrayAttrib (GLuint vaobj, GLuint index);
extern PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttrib;
// GLAPI void APIENTRY glEnableVertexArrayAttrib (GLuint vaobj, GLuint index);
extern PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttrib;
// GLAPI void APIENTRY glVertexArrayElementBuffer (GLuint vaobj, GLuint buffer);
extern PFNGLVERTEXARRAYELEMENTBUFFERPROC glVertexArrayElementBuffer;
// GLAPI void APIENTRY glVertexArrayVertexBuffer (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
extern PFNGLVERTEXARRAYVERTEXBUFFERPROC glVertexArrayVertexBuffer;
// GLAPI void APIENTRY glVertexArrayVertexBuffers (GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
extern PFNGLVERTEXARRAYVERTEXBUFFERSPROC glVertexArrayVertexBuffers;
// GLAPI void APIENTRY glVertexArrayAttribBinding (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
extern PFNGLVERTEXARRAYATTRIBBINDINGPROC glVertexArrayAttribBinding;
// GLAPI void APIENTRY glVertexArrayAttribFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
extern PFNGLVERTEXARRAYATTRIBFORMATPROC glVertexArrayAttribFormat;
// GLAPI void APIENTRY glVertexArrayAttribIFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
extern PFNGLVERTEXARRAYATTRIBIFORMATPROC glVertexArrayAttribIFormat;
// GLAPI void APIENTRY glVertexArrayAttribLFormat (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
extern PFNGLVERTEXARRAYATTRIBLFORMATPROC glVertexArrayAttribLFormat;
// GLAPI void APIENTRY glVertexArrayBindingDivisor (GLuint vaobj, GLuint bindingindex, GLuint divisor);
extern PFNGLVERTEXARRAYBINDINGDIVISORPROC glVertexArrayBindingDivisor;
// GLAPI void APIENTRY glGetVertexArrayiv (GLuint vaobj, GLenum pname, GLint *param);
extern PFNGLGETVERTEXARRAYIVPROC glGetVertexArrayiv;
// GLAPI void APIENTRY glGetVertexArrayIndexediv (GLuint vaobj, GLuint index, GLenum pname, GLint *param);
extern PFNGLGETVERTEXARRAYINDEXEDIVPROC glGetVertexArrayIndexediv;
// GLAPI void APIENTRY glGetVertexArrayIndexed64iv (GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
extern PFNGLGETVERTEXARRAYINDEXED64IVPROC glGetVertexArrayIndexed64iv;
// GLAPI void APIENTRY glCreateSamplers (GLsizei n, GLuint *samplers);
extern PFNGLCREATESAMPLERSPROC glCreateSamplers;
// GLAPI void APIENTRY glCreateProgramPipelines (GLsizei n, GLuint *pipelines);
extern PFNGLCREATEPROGRAMPIPELINESPROC glCreateProgramPipelines;
// GLAPI void APIENTRY glCreateQueries (GLenum target, GLsizei n, GLuint *ids);
extern PFNGLCREATEQUERIESPROC glCreateQueries;
// GLAPI void APIENTRY glGetQueryBufferObjecti64v (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
extern PFNGLGETQUERYBUFFEROBJECTI64VPROC glGetQueryBufferObjecti64v;
// GLAPI void APIENTRY glGetQueryBufferObjectiv (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
extern PFNGLGETQUERYBUFFEROBJECTIVPROC glGetQueryBufferObjectiv;
// GLAPI void APIENTRY glGetQueryBufferObjectui64v (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
extern PFNGLGETQUERYBUFFEROBJECTUI64VPROC glGetQueryBufferObjectui64v;
// GLAPI void APIENTRY glGetQueryBufferObjectuiv (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
extern PFNGLGETQUERYBUFFEROBJECTUIVPROC glGetQueryBufferObjectuiv;
// GLAPI void APIENTRY glMemoryBarrierByRegion (GLbitfield barriers);
extern PFNGLMEMORYBARRIERBYREGIONPROC glMemoryBarrierByRegion;
// GLAPI void APIENTRY glGetTextureSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
extern PFNGLGETTEXTURESUBIMAGEPROC glGetTextureSubImage;
// GLAPI void APIENTRY glGetCompressedTextureSubImage (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
extern PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glGetCompressedTextureSubImage;
// GLAPI GLenum APIENTRY glGetGraphicsResetStatus (void);
extern PFNGLGETGRAPHICSRESETSTATUSPROC glGetGraphicsResetStatus;
// GLAPI void APIENTRY glGetnCompressedTexImage (GLenum target, GLint lod, GLsizei bufSize, void *pixels);
extern PFNGLGETNCOMPRESSEDTEXIMAGEPROC glGetnCompressedTexImage;
// GLAPI void APIENTRY glGetnTexImage (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
extern PFNGLGETNTEXIMAGEPROC glGetnTexImage;
// GLAPI void APIENTRY glGetnUniformdv (GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
extern PFNGLGETNUNIFORMDVPROC glGetnUniformdv;
// GLAPI void APIENTRY glGetnUniformfv (GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
extern PFNGLGETNUNIFORMFVPROC glGetnUniformfv;
// GLAPI void APIENTRY glGetnUniformiv (GLuint program, GLint location, GLsizei bufSize, GLint *params);
extern PFNGLGETNUNIFORMIVPROC glGetnUniformiv;
// GLAPI void APIENTRY glGetnUniformuiv (GLuint program, GLint location, GLsizei bufSize, GLuint *params);
extern PFNGLGETNUNIFORMUIVPROC glGetnUniformuiv;
// GLAPI void APIENTRY glReadnPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
extern PFNGLREADNPIXELSPROC glReadnPixels;
// GLAPI void APIENTRY glGetnMapdv (GLenum target, GLenum query, GLsizei bufSize, GLdouble *v);
extern PFNGLGETNMAPDVPROC glGetnMapdv;
// GLAPI void APIENTRY glGetnMapfv (GLenum target, GLenum query, GLsizei bufSize, GLfloat *v);
extern PFNGLGETNMAPFVPROC glGetnMapfv;
// GLAPI void APIENTRY glGetnMapiv (GLenum target, GLenum query, GLsizei bufSize, GLint *v);
extern PFNGLGETNMAPIVPROC glGetnMapiv;
// GLAPI void APIENTRY glGetnPixelMapfv (GLenum map, GLsizei bufSize, GLfloat *values);
extern PFNGLGETNPIXELMAPFVPROC glGetnPixelMapfv;
// GLAPI void APIENTRY glGetnPixelMapuiv (GLenum map, GLsizei bufSize, GLuint *values);
extern PFNGLGETNPIXELMAPUIVPROC glGetnPixelMapuiv;
// GLAPI void APIENTRY glGetnPixelMapusv (GLenum map, GLsizei bufSize, GLushort *values);
extern PFNGLGETNPIXELMAPUSVPROC glGetnPixelMapusv;
// GLAPI void APIENTRY glGetnPolygonStipple (GLsizei bufSize, GLubyte *pattern);
extern PFNGLGETNPOLYGONSTIPPLEPROC glGetnPolygonStipple;
// GLAPI void APIENTRY glGetnColorTable (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table);
extern PFNGLGETNCOLORTABLEPROC glGetnColorTable;
// GLAPI void APIENTRY glGetnConvolutionFilter (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image);
extern PFNGLGETNCONVOLUTIONFILTERPROC glGetnConvolutionFilter;
// GLAPI void APIENTRY glGetnSeparableFilter (GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span);
extern PFNGLGETNSEPARABLEFILTERPROC glGetnSeparableFilter;
// GLAPI void APIENTRY glGetnHistogram (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
extern PFNGLGETNHISTOGRAMPROC glGetnHistogram;
// GLAPI void APIENTRY glGetnMinmax (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
extern PFNGLGETNMINMAXPROC glGetnMinmax;
// GLAPI void APIENTRY glTextureBarrier (void);
extern PFNGLTEXTUREBARRIERPROC glTextureBarrier;


// GL_VERSION_4_6
// GLAPI void APIENTRY glSpecializeShader (GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
extern PFNGLSPECIALIZESHADERPROC glSpecializeShader;
// GLAPI void APIENTRY glMultiDrawArraysIndirectCount (GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
extern PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount;
// GLAPI void APIENTRY glMultiDrawElementsIndirectCount (GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
extern PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount;
// GLAPI void APIENTRY glPolygonOffsetClamp (GLfloat factor, GLfloat units, GLfloat clamp);
extern PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp;


// Loader Function
void glfnlib_load(PFN_loadfunc_gl load);
