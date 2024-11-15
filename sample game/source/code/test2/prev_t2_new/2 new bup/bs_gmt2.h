



// angle in radians
// Build a matrix which rotates around the X axis
// Creates an x-axis rotation matrix, centered on the origin.
inline mat4 mat4_rotation_x(float angle) {
    const float sin_a = sinf(angle);
    const float cos_a = cosf(angle);

    return mat4(
            static_cast<float>(1.0),    static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(0.0),
            static_cast<float>(0.0),    cos_a,				sin_a,				static_cast<float>(0.0),
            static_cast<float>(0.0),    -sin_a,				cos_a,				static_cast<float>(0.0),
            static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(1.0)
	);
}

// Build a matrix which rotates around the Y axis
inline mat4 mat4_rotation_y(float angle) {
    const float sin_a = sinf(angle);
    const float cos_a = cosf(angle);

    return mat4(
            cos_a,				static_cast<float>(0.0),    -sin_a,				static_cast<float>(0.0),
            static_cast<float>(0.0),	static_cast<float>(1.0),    static_cast<float>(0.0),    static_cast<float>(0.0),
            sin_a,				static_cast<float>(0.0),    cos_a,				static_cast<float>(0.0),
            static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(1.0)
	);
}

// Build a matrix which rotates around the Z axis
inline mat4 mat4_rotation_z(float angle) {
    const float sin_a = sinf(angle);
    const float cos_a = cosf(angle);
    
    return mat4(
            cos_a,				sin_a,				static_cast<float>(0.0),    static_cast<float>(0.0),
            -sin_a,				cos_a,				static_cast<float>(0.0),    static_cast<float>(0.0),
            static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(1.0),    static_cast<float>(0.0),
            static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(1.0)
	);
}


// Build a matrix which rotates around an arbitrary axis
//mat4 mat4_glm_rotation_xyz(float angle, const vec3& axis)
//D3DXMatrixRotationAxis
inline mat4 mat4_rotation_axis(const vec3& axis, float angle) {    
    vec3 nv = vec3_normalize(axis);
    const float sa = sinf(angle);
    const float ca = cosf(angle);
    const float cd = static_cast<float>(1.0) - ca;    

    return mat4(
            cd*nv.x*nv.x + ca,          cd*nv.y*nv.x + sa*nv.z,     cd*nv.z*nv.x - sa*nv.y,     static_cast<float>(0.0),
            cd*nv.x*nv.y - sa*nv.z,     cd*nv.y*nv.y + ca,          cd*nv.z*nv.y + sa*nv.x,     static_cast<float>(0.0),
            cd*nv.x*nv.z + sa*nv.y,     cd*nv.y*nv.z - sa*nv.x,     cd*nv.z*nv.z + ca,          static_cast<float>(0.0),
            static_cast<float>(0.0),            static_cast<float>(0.0),            static_cast<float>(0.0),            static_cast<float>(1.0)
        );
}


inline mat4 mat4_translation(const vec3& position) {
    return mat4(
            static_cast<float>(1.0),		static_cast<float>(0.0),		static_cast<float>(0.0),		static_cast<float>(0.0),
            static_cast<float>(0.0),		static_cast<float>(1.0),		static_cast<float>(0.0),		static_cast<float>(0.0),
            static_cast<float>(0.0),		static_cast<float>(0.0),		static_cast<float>(1.0),		static_cast<float>(0.0),
            position.x,				position.y,				position.z,				static_cast<float>(1.0)
	);
}

inline mat4 mat4_scaling(const vec3& scales) {
    return mat4(
            scales.x,			static_cast<float>(0.0),	static_cast<float>(0.0),	static_cast<float>(0.0),
            static_cast<float>(0.0),	scales.y,			static_cast<float>(0.0),	static_cast<float>(0.0),
            static_cast<float>(0.0),	static_cast<float>(0.0),	scales.z,			static_cast<float>(0.0),
            static_cast<float>(0.0),	static_cast<float>(0.0),	static_cast<float>(0.0),	static_cast<float>(1.0)
	);
}


//==================================================================


//-----------------------------------------
// LookAt Matrices
//-----------------

//zaxis = normal(At - Eye)
//xaxis = normal(cross(Up, zaxis))
//yaxis = cross(zaxis, xaxis)
//
// xaxis.x           yaxis.x           zaxis.x          0
// xaxis.y           yaxis.y           zaxis.y          0
// xaxis.z           yaxis.z           zaxis.z          0
//-dot(xaxis, eye)  -dot(yaxis, eye)  -dot(zaxis, eye)  1
// Build a lookat matrix. (left-handed)
//D3DXMatrixLookAtLH
inline mat4 mat4_look_at_lh(const vec3& eye, const vec3& at, const vec3& up) {
    vec3 right = k_zero<vec3>;
    vec3 upn = k_zero<vec3>;
    vec3 dir = k_zero<vec3>;

    dir = vec3_normalize(at - eye);
    right = vec3_cross(up, dir);
    upn = vec3_cross(dir, right);
    right = vec3_normalize(right);
    upn = vec3_normalize(upn);

    return mat4(
        right.x,			   upn.x,				dir.x,				 static_cast<float>(0.0),
        right.y,			   upn.y,				dir.y,				 static_cast<float>(0.0),
        right.z,			   upn.z,				dir.z,				 static_cast<float>(0.0),
        -vec3_dot(right, eye), -vec3_dot(upn, eye), -vec3_dot(dir, eye), static_cast<float>(1.0)
    );
}

//zaxis = normal(Eye - At)
//xaxis = normal(cross(Up, zaxis))
//yaxis = cross(zaxis, xaxis)
//
// xaxis.x            yaxis.x            zaxis.x           0
// xaxis.y            yaxis.y            zaxis.y           0
// xaxis.z            yaxis.z            zaxis.z           0
// -dot(xaxis, eye)   -dot(yaxis, eye)   -dot(zaxis, eye)  1
// Build a lookat matrix. (right-handed)
//D3DXMatrixLookAtRH
inline mat4 mat4_look_at_rh(const vec3& eye, const vec3& at, const vec3& up) {
    vec3 right = k_zero<vec3>; 
    vec3 upn = k_zero<vec3>;
    vec3 dir = k_zero<vec3>;

    dir = vec3_normalize(at - eye);
    right = vec3_cross(up, dir);
    upn = vec3_cross(dir, right);
    right = vec3_normalize(right);
    upn = vec3_normalize(upn);

    return mat4(
        -right.x,			  upn.x,			   -dir.x,		       static_cast<float>(0.0),
        -right.y,			  upn.y,			   -dir.y,             static_cast<float>(0.0),
        -right.z,			  upn.z,			   -dir.z,			   static_cast<float>(0.0),
        vec3_dot(right, eye), -vec3_dot(upn, eye), vec3_dot(dir, eye), static_cast<float>(1.0)
    );
}


//--------------------------------------------
// Perspective Matrices d3dx9
//--------------------------------------------

//width = tan(fov * 0.5f);
//height = width/aspect;
//
//yScale = cot(fovY/2)
//xScale = yScale / aspect ratio
//xScale     0          0               0
//0        yScale       0               0
//0          0       zf/(zf-zn)         1
//0          0       -zn*zf/(zf-zn)     0
//
// Build a perspective projection matrix. (left-handed)
//D3DXMatrixPerspectiveFovLH
inline mat4 mat4_perspective_fov_lh(float fovy, float aspect, float zn, float zf) {
	const float tan_half_fovy = tan(fovy * static_cast<float>(0.5));
	const float x_scale = static_cast<float>(1.0)/(aspect * tan_half_fovy);
	const float y_scale = static_cast<float>(1.0)/tan_half_fovy;

    return mat4(
        x_scale,		 static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0), 
        static_cast<float>(0.0), y_scale,		  static_cast<float>(0.0), static_cast<float>(0.0), 
        static_cast<float>(0.0), static_cast<float>(0.0), zf/(zf-zn),	   static_cast<float>(1.0), 
        static_cast<float>(0.0), static_cast<float>(0.0), (zf*zn)/(zn-zf), static_cast<float>(0.0) 
	);    
}

//yScale = cot(fovY/2)
//xScale = yScale / aspect ratio
//xScale     0          0              0
//0        yScale       0              0
//0        0        zf/(zn-zf)        -1
//0        0        zn*zf/(zn-zf)      0
//
// Build a perspective projection matrix. (right-handed)
//D3DXMatrixPerspectiveFovRH
inline mat4 mat4_perspective_fov_rh(float fovy, float aspect, float zn, float zf) {
	const float tan_half_fovy = tan(fovy * static_cast<float>(0.5));
	const float x_scale = static_cast<float>(1.0)/(aspect * tan_half_fovy);
	const float y_scale = static_cast<float>(1.0)/tan_half_fovy;

    return mat4(
        x_scale,		 static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0), 
        static_cast<float>(0.0), y_scale,		  static_cast<float>(0.0), static_cast<float>(0.0), 
        static_cast<float>(0.0), static_cast<float>(0.0), zf/(zn-zf),	   -static_cast<float>(1.0), 
        static_cast<float>(0.0), static_cast<float>(0.0), (zf*zn)/(zn-zf), static_cast<float>(0.0)
	);    
}





//==================================================================
inline vec3 vec2_to_vec3(const vec2& a, float z) { return vec3(a.x, a.y, z); }
inline vec3 vec4_to_vec3(const vec4& a) { return vec3(a.x, a.y, a.z); }
inline vec4 vec2_to_vec4(const vec2& a, float z, float w) { return vec4(a.x, a.y, z, w); }
inline vec4 vec3_to_vec4(const vec3& a, float w) { return vec4(a.x, a.y, a.z, w); }


//----------------
// vec transform
//----------------

// Transform (x, y, 0, 1) by matrix, project result back into w=1.
//D3DXVec2TransformCoord
inline vec2 vec2_transform_coord(const vec2& a, const mat4& ma) {	
    float norm = ma.r[0][3] * a.x + ma.r[1][3] * a.y + ma.r[3][3];
	float inv_norm = static_cast<float>(1.0)/norm;

	return vec2(
		(ma.r[0][0] * a.x + ma.r[1][0] * a.y + ma.r[3][0]) * inv_norm,
		(ma.r[0][1] * a.x + ma.r[1][1] * a.y + ma.r[3][1]) * inv_norm
	);
} 

// Transform (x, y, 0, 0) by matrix.
//D3DXVec2TransformNormal
inline vec2 vec2_transform_normal(const vec2& a, const mat4& ma) {
	return vec2(
		ma.r[0][0] * a.x + ma.r[1][0] * a.y,
		ma.r[0][1] * a.x + ma.r[1][1] * a.y
    );
}   

//--------------------------------------
// Transform (x, y, z, 1) by matrix, project result back into w=1.
//D3DXVec3TransformCoord
inline vec3 vec3_transform_coord(const vec3& a, const mat4& ma) {	
    float norm = ma.r[0][3] * a.x + ma.r[1][3] * a.y + ma.r[2][3] *a.z + ma.r[3][3];
	float inv_norm = static_cast<float>(1.0)/norm;

	return vec3(
		(ma.r[0][0] * a.x + ma.r[1][0] * a.y + ma.r[2][0] * a.z + ma.r[3][0]) * inv_norm,
		(ma.r[0][1] * a.x + ma.r[1][1] * a.y + ma.r[2][1] * a.z + ma.r[3][1]) * inv_norm,
		(ma.r[0][2] * a.x + ma.r[1][2] * a.y + ma.r[2][2] * a.z + ma.r[3][2]) * inv_norm
    );
}

// Transform (x, y, z, 0) by matrix.  If you transforming a normal by a non-affine matrix, the matrix you pass to this function should be the 
// transpose of the inverse of the matrix you would use to transform a coord.
//D3DXVec3TransformNormal
inline vec3 vec3_transform_normal(const vec3& a, const mat4& ma) {
	return vec3(
		ma.r[0][0] * a.x + ma.r[1][0] * a.y + ma.r[2][0] * a.z,
		ma.r[0][1] * a.x + ma.r[1][1] * a.y + ma.r[2][1] * a.z,
		ma.r[0][2] * a.x + ma.r[1][2] * a.y + ma.r[2][2] * a.z
    );
}

//--------------------------------------
// Transform (x, y, 0, 1) by matrix.
//D3DXVec2Transform
inline vec4 vec4_transform_pos2(const vec2& a, const mat4& ma) {
	return vec4(
		ma.r[0][0] * a.x + ma.r[1][0] * a.y  + ma.r[3][0],
		ma.r[0][1] * a.x + ma.r[1][1] * a.y  + ma.r[3][1],
		ma.r[0][2] * a.x + ma.r[1][2] * a.y  + ma.r[3][2],
		ma.r[0][3] * a.x + ma.r[1][3] * a.y  + ma.r[3][3]
    );
}

// Transform (x, y, z, 1) by matrix.
//D3DXVec3Transform
inline vec4 vec4_transform_pos3(const vec3& a, const mat4& ma) {
	return vec4(
		ma.r[0][0] * a.x + ma.r[1][0] * a.y + ma.r[2][0] * a.z + ma.r[3][0],
		ma.r[0][1] * a.x + ma.r[1][1] * a.y + ma.r[2][1] * a.z + ma.r[3][1],
		ma.r[0][2] * a.x + ma.r[1][2] * a.y + ma.r[2][2] * a.z + ma.r[3][2],
		ma.r[0][3] * a.x + ma.r[1][3] * a.y + ma.r[2][3] * a.z + ma.r[3][3]
    );
}

// Transform vector by matrix.
//D3DXVec4Transform
inline vec4 vec4_transform_pos4(const vec4& a, const mat4& ma) {
	return vec4(
		ma.r[0][0] * a.x + ma.r[1][0] * a.y + ma.r[2][0] * a.z + ma.r[3][0] * a.w,
		ma.r[0][1] * a.x + ma.r[1][1] * a.y + ma.r[2][1] * a.z + ma.r[3][1] * a.w,
		ma.r[0][2] * a.x + ma.r[1][2] * a.y + ma.r[2][2] * a.z + ma.r[3][2] * a.w,
		ma.r[0][3] * a.x + ma.r[1][3] * a.y + ma.r[2][3] * a.z + ma.r[3][3] * a.w
    );
}

//--------------------------------------------
//d3dx9
// xWin = x + 0.5 * (xNdc + 1.0) * w;
// yWin = y + 0.5 * (yNdc + 1.0) * h;
// Project vector from object space into screen space
//D3DXVec3Project
inline vec3 vec3_project(const vec3& a, const viewport& vp, const mat4& proj, const mat4& view, const mat4& world) {
    vec3 out = k_zero<vec3>;
    mat4 m = k_identity<mat4>;

    m = world * view * proj;

    out = vec3_transform_coord(a, m);

    out.x = vp.x + (static_cast<float>(1.0) + out.x) * vp.w*static_cast<float>(0.5);
    out.y = vp.y + (static_cast<float>(1.0) - out.y) * vp.h*static_cast<float>(0.5);
    out.z = vp.zn + out.z * (vp.zf - vp.zn);

    return out;
}
// Project vector from screen space into object space
//D3DXVec3Unproject
inline vec3 vec3_unproject(const vec3& a, const viewport& vp, const mat4& proj, const mat4& view, const mat4& world) {
    vec3 out = k_zero<vec3>;
    mat4 m = k_identity<mat4>;

    m = world * view * proj;
    m = mat4_inverse(m);    

    out = a;

    out.x = static_cast<float>(2.0)*(out.x - vp.x) / vp.w - static_cast<float>(1.0);
    out.y = static_cast<float>(1.0) - static_cast<float>(2.0)*(out.y - vp.y)/vp.h;
    out.z = (out.z - vp.zn)/(vp.zf - vp.zn);

    out = vec3_transform_coord(out, m);
    return out;
}
//--------------------------------------------



//=========================================================================================
// UNCHECKED

//--------------------------------------





//-------------------------------------------------------------------



// END UNCHECKED
}



#pragma once

#include "bs_gmath.h"

namespace gm
{

//========================================================================================================================
// Template functions for N size
//========================================================================================================================
// v - end points
// t - tangent directions at end points
// s (alpha) - distance along spline
// cubic interpolation
// Hermite interpolation between position V1, tangent T1 (when s == 0) and position V2, tangent T2 (when s == 1).
template<class T> inline T vecnt_hermite(const T& v1, const T& t1, const T& v2, const T& t2, float s) {
    T out = k_zero<T>; 
    float h1, h2, h3, h4;
    //set_hermite_coeffcients(h1, h2, h3, h4, s);
    float s3 = mf::cube(s);
	float s2 = mf::square(s); 

    //h1 = (2.0f * s*s*s) - (3.0f * s*s) + 1.0f;
    //h2 = (s*s*s) - (2.0f * s*s) + s;
    //h3 = -(2.0f * s*s*s) + (3.0f * s*s);
    //h4 = (s*s*s) - (s*s);

    h1 = (static_cast<float>(2.0) * s3) - (static_cast<float>(3.0) * s2) + static_cast<float>(1.0);
    h2 = (s3) - (static_cast<float>(2.0) * s2) + s;
    h3 = (-static_cast<float>(2.0) * s3) + (static_cast<float>(3.0) * s2);
    h4 = (s3) - (s2);    

    for (int i=0; i < T::size(); ++i) { out[i] = h1 * v1[i] + h2 * t1[i] + h3 * v2[i] + h4 * t2[i]; }

    return out;
}

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
template<class T> inline T vecnt_catmull_rom(const T& v0, const T& v1, const T& v2, const T& v3, float s) {
    T out = k_zero<T>; 
    float s3 = mf::cube(s);
	float s2 = mf::square(s); 

    for (int i=0; i < T::size(); ++i) {
        out[i] = static_cast<float>(0.5) * (static_cast<float>(2.0) * v1[i] + (v2[i] - v0[i]) * s + (static_cast<float>(2.0) * v0[i] - static_cast<float>(5.0) * v1[i] 
            + static_cast<float>(4.0) * v2[i] - v3[i]) * s2 + (v3[i] -static_cast<float>(3.0) * v2[i] + static_cast<float>(3.0) * v1[i] - v0[i]) * s3);
    }

    return out;
}

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
template<class T> inline T vecnt_bary_centric(const T& v1, const T& v2, const T& v3, float f, float g) {
    T out = k_zero<T>; for (int i=0; i < T::size(); ++i) { out[i] = (static_cast<float>(1.0)-f-g) * v1[i] + f * v2[i] + g * v3[i]; } return out;
}

//------------------------------------------------------------------
inline vec2 vec2_hermite(const vec2& v1, const vec2& t1, const vec2& v2, const vec2& t2, float s) {
    return vecnt_hermite(v1, t1, v2, t2, s);
}
inline vec2 vec2_catmull_rom(const vec2& v0, const vec2& v1, const vec2& v2, const vec2& v3, float s) {
    return vecnt_catmull_rom(v0, v1, v2, v3, s);
}
inline vec2 vec2_bary_centric(const vec2& v1, const vec2& v2, const vec2& v3, float f, float g) {
    return vecnt_bary_centric(v1, v2, v3, f, g);
}

//----------------------
inline vec3 vec3_hermite(const vec3& v1, const vec3& t1, const vec3& v2, const vec3& t2, float s) {
    return vecnt_hermite(v1, t1, v2, t2, s);
}
inline vec3 vec3_catmull_rom(const vec3& v0, const vec3& v1, const vec3& v2, const vec3& v3, float s) {
    return vecnt_catmull_rom(v0, v1, v2, v3, s);
}
inline vec3 vec3_bary_centric(const vec3& v1, const vec3& v2, const vec3& v3, float f, float g) {
    return vecnt_bary_centric(v1, v2, v3, f, g);
}


//----------------------
// Cross-product in 4 dimensions.
inline vec4 vec4_cross(const vec4& a, const vec4& b, const vec4& c) {
    vec4 out = k_zero<vec4>;
    out.x = a.y * (b.z * c.w - c.z * b.w) - a.z * (b.y * c.w - c.y * b.w) + a.w * (b.y * c.z - b.z *c.y);
    out.y = -(a.x * (b.z * c.w - c.z * b.w) - a.z * (b.x * c.w - c.x * b.w) + a.w * (b.x * c.z - c.x * b.z));
    out.z = a.x * (b.y * c.w - c.y * b.w) - a.y * (b.x *c.w - c.x * b.w) + a.w * (b.x * c.y - c.x * b.y);
    out.w = -(a.x * (b.y * c.z - c.y * b.z) - a.y * (b.x * c.z - c.x *b.z) + a.z * (b.x * c.y - c.x * b.y));
    return out;
}


inline vec4 vec4_hermite(const vec4& v1, const vec4& t1, const vec4& v2, const vec4& t2, float s) {
   return vecnt_hermite(v1, t1, v2, t2, s);
}
inline vec4 vec4_catmull_rom(const vec4& v0, const vec4& v1, const vec4& v2, const vec4& v3, float s) {
    return vecnt_catmull_rom(v0, v1, v2, v3, s);
}
inline vec4 vec4_bary_centric(const vec4& v1, const vec4& v2, const vec4& v3, float f, float g) {
    return vecnt_bary_centric(v1, v2, v3, f, g);
}


//----------------------
// Convert Direct3D projection to OpenGL 
// Convert Direct3D projection matrix to an OpenGL one by applying a Z scale of 2 and a translation of -1. 
// This will make [0,+1] to [-1,+1].
//glMatrixMode(GL_PROJECTION); 
//glLoadMatrixf(&d3d_projection_matrix); 
//glScalef(1, 1, 2); 
//glTranslatef(0, 0, -1);

inline mat4 mat4_mul_transpose(const mat4& ma, const mat4& mb) {
	return mat4_transpose(ma * mb);
}

//P = normalize(Plane);
//L = Light;
//d = -dot(P, L)
//
//P.a * L.x + d  P.a * L.y      P.a * L.z      P.a * L.w  
//P.b * L.x      P.b * L.y + d  P.b * L.z      P.b * L.w  
//P.c * L.x      P.c * L.y      P.c * L.z + d  P.c * L.w  
//P.d * L.x      P.d * L.y      P.d * L.z      P.d * L.w + d
// Build a matrix which flattens geometry into a plane, as if casting a shadow from a light.
// If the light's w-component is 0, the ray from the origin to the light represents a directional 
// light and if it is 1, the light is a point light.
//D3DXMatrixShadow
inline mat4 mat4_shadow(const vec4& light, const plane& pa) {
    const vec4& l = light;
    const plane p = plane_normalize(pa);  

    //d3dx9
    const float dot = plane_dot_vec4(p, l);

    return mat4(
        -p.a*l.x + dot, -p.a*l.y,       -p.a*l.z,       -p.a*l.w,
        -p.b*l.x,       -p.b*l.y + dot, -p.b*l.z,       -p.b*l.w,
        -p.c*l.x,       -p.c*l.y,       -p.c*l.z + dot, -p.c*l.w,
        -p.d*l.x,       -p.d*l.y,       -p.d*l.z,       -p.d*l.w + dot
    );

    // Using d3dx9 docs formula & negate the result.
    // Formula from d3dx9 docs is different from D3DXMatrixShadow (-ve of D3DXMatrixShadow).
    //const float dot = -plane_dot_vec4(p, l);
    //return mat4(
    //    -(p.a*l.x + dot),   -p.a*l.y,          -p.a*l.z,          -p.a*l.w,  
    //     -p.b*l.x,         -(p.b*l.y + dot),   -p.b*l.z,          -p.b*l.w,  
    //     -p.c*l.x,          -p.c*l.y,         -(p.c*l.z + dot),   -p.c*l.w,  
    //     -p.d*l.x,          -p.d*l.y,          -p.d*l.z,         -(p.d*l.w + dot)
    //);
}


//-2 * P.a * P.a + 1  -2 * P.b * P.a      -2 * P.c * P.a        0
//-2 * P.a * P.b      -2 * P.b * P.b + 1  -2 * P.c * P.b        0
//-2 * P.a * P.c      -2 * P.b * P.c      -2 * P.c * P.c + 1    0
//-2 * P.a * P.d      -2 * P.b * P.d      -2 * P.c * P.d        1
// Build a matrix which reflects the coordinate system about a plane
//D3DXMatrixReflect
inline mat4 mat4_reflect(const plane& pa) {
    plane p = plane_normalize(pa);     

    return mat4(
        -static_cast<float>(2.0)*p.a*p.a + static_cast<float>(1.0), -static_cast<float>(2.0)*p.b*p.a,               -static_cast<float>(2.0)*p.c*p.a,                           static_cast<float>(0.0),
        -static_cast<float>(2.0)*p.a*p.b,                     -static_cast<float>(2.0)*p.b*p.b + static_cast<float>(1.0), -static_cast<float>(2.0)*p.c*p.b,                     static_cast<float>(0.0),
        -static_cast<float>(2.0)*p.a*p.c,                     -static_cast<float>(2.0)*p.b*p.c,                     -static_cast<float>(2.0)*p.c*p.c + static_cast<float>(1.0), static_cast<float>(0.0),
        -static_cast<float>(2.0)*p.a*p.d,                     -static_cast<float>(2.0)*p.b*p.d,                     -static_cast<float>(2.0)*p.c*p.d,                           static_cast<float>(1.0)
    );
}


//--------------------------------------------
// Perspective Matrices d3dx9
//--------------------------------------------
//-----------
//2*zn/w  0       0              0
//0       2*zn/h  0              0
//0       0       zf/(zf-zn)     1
//0       0       zn*zf/(zn-zf)  0
//D3DXMatrixPerspectiveLH
inline mat4 mat4_perspective_lh(float w, float h, float zn, float zf) {
    return mat4(
        static_cast<float>(2.0) * zn/w,   static_cast<float>(0.0),		    static_cast<float>(0.0),  static_cast<float>(0.0), 
        static_cast<float>(0.0),		  static_cast<float>(2.0) * zn/h,   static_cast<float>(0.0),  static_cast<float>(0.0), 
        static_cast<float>(0.0),		  static_cast<float>(0.0),		    zf/(zf-zn),		          static_cast<float>(1.0), 
        static_cast<float>(0.0),		  static_cast<float>(0.0),		    (zn*zf)/(zn-zf),          static_cast<float>(0.0)
	);    
}

//2*zn/w  0       0              0
//0       2*zn/h  0              0
//0       0       zf/(zn-zf)    -1
//0       0       zn*zf/(zn-zf)  0
//D3DXMatrixPerspectiveRH
inline mat4 mat4_perspective_rh(float w, float h, float zn, float zf) {
    return mat4(
        static_cast<float>(2.0) * zn/w,   static_cast<float>(0.0),		  static_cast<float>(0.0),    static_cast<float>(0.0), 
        static_cast<float>(0.0),		  static_cast<float>(2.0) * zn/h, static_cast<float>(0.0),    static_cast<float>(0.0), 
        static_cast<float>(0.0),		  static_cast<float>(0.0),		  zf/(zn-zf),		          -static_cast<float>(1.0), 
        static_cast<float>(0.0),		  static_cast<float>(0.0),		  (zn*zf)/(zn-zf),            static_cast<float>(0.0)
	);    
}


//-----------
//2*zn/(r-l)   0            0              0
//0            2*zn/(t-b)   0              0
//(l+r)/(l-r)  (t+b)/(b-t)  zf/(zf-zn)     1
//0            0            zn*zf/(zn-zf)  0
//D3DXMatrixPerspectiveOffCenterLH
inline mat4 mat4_perspective_offcenter_lh(float l, float r, float b, float t, float zn, float zf) {
    return mat4(
        static_cast<float>(2.0) * zn/(r-l),     static_cast<float>(0.0),										            static_cast<float>(0.0),	static_cast<float>(0.0), 
        static_cast<float>(0.0),			    -static_cast<float>(2.0) * zn/(b-t),							            static_cast<float>(0.0),	static_cast<float>(0.0), 
        -static_cast<float>(1.0) - static_cast<float>(2.0) * l/(r-l), static_cast<float>(1.0) + static_cast<float>(2.0) * t/(b-t),  -zf/(zn-zf),	    static_cast<float>(1.0), 
        static_cast<float>(0.0),			    static_cast<float>(0.0),											        (zn*zf)/(zn-zf),            static_cast<float>(0.0)
	);    
}

//2*zn/(r-l)   0            0                0
//0            2*zn/(t-b)   0                0
//(l+r)/(r-l)  (t+b)/(t-b)  zf/(zn-zf)      -1
//0            0            zn*zf/(zn-zf)    0
//D3DXMatrixPerspectiveOffCenterRH
inline mat4 mat4_perspective_offcenter_rh(float l, float r, float b, float t, float zn, float zf) {
    return mat4(
        static_cast<float>(2.0) * zn/(r-l),   static_cast<float>(0.0),										          static_cast<float>(0.0),  static_cast<float>(0.0), 
        static_cast<float>(0.0),			  -static_cast<float>(2.0) * zn/(b-t),								      static_cast<float>(0.0),  static_cast<float>(0.0), 
        static_cast<float>(1.0) + static_cast<float>(2.0) * l/(r-l), -static_cast<float>(1.0) -static_cast<float>(2.0) * t/(b-t), zf/(zn-zf),   -static_cast<float>(1.0), 
        static_cast<float>(0.0),			  static_cast<float>(0.0),											      (zn*zf)/(zn-zf),          static_cast<float>(0.0)
	);    
}


//-----------
//2/(r-l)      0            0           0
//0            2/(t-b)      0           0
//0            0            1/(zf-zn)   0
//(l+r)/(l-r)  (t+b)/(b-t)  zn/(zn-zf)  1
//D3DXMatrixOrthoOffCenterLH
inline mat4 mat4_ortho_offcenter_lh(float l, float r, float b, float t, float zn, float zf) {
    return mat4(
        static_cast<float>(2.0)/(r-l),					     static_cast<float>(0.0),				static_cast<float>(0.0),		            static_cast<float>(0.0), 
        static_cast<float>(0.0),							 static_cast<float>(2.0)/(t-b),		    static_cast<float>(0.0),		            static_cast<float>(0.0), 
        static_cast<float>(0.0),							 static_cast<float>(0.0),				static_cast<float>(1.0)/(zf -zn),           static_cast<float>(0.0), 
        -static_cast<float>(1.0) - static_cast<float>(2.0) * l/(r-l), static_cast<float>(1.0) + static_cast<float>(2.0) * t/(b-t), zn/(zn-zf),  static_cast<float>(1.0)
	);    
}

//2/(r-l)      0            0           0
//0            2/(t-b)      0           0
//0            0            1/(zn-zf)   0
//(l+r)/(l-r)  (t+b)/(b-t)  zn/(zn-zf)  1
//D3DXMatrixOrthoOffCenterRH
inline mat4 mat4_ortho_offcenter_rh(float l, float r, float b, float t, float zn, float zf) {
    return mat4(
        static_cast<float>(2.0)/(r-l),				         static_cast<float>(0.0),					static_cast<float>(0.0),		        static_cast<float>(0.0), 
        static_cast<float>(0.0),							 static_cast<float>(2.0)/(t-b),			    static_cast<float>(0.0),		        static_cast<float>(0.0), 
        static_cast<float>(0.0),							 static_cast<float>(0.0),					static_cast<float>(1.0)/(zn-zf),        static_cast<float>(0.0), 
        -static_cast<float>(1.0) - static_cast<float>(2.0) * l/(r-l), static_cast<float>(1.0) + static_cast<float>(2.0) * t/(b-t), zn/(zn-zf),	static_cast<float>(1.0)
	);    
}

//-----------
// The D3DXMatrixOrthoLH function is a special case of the D3DXMatrixOrthoOffCenterLH function. 
// To create the same projection using D3DXMatrixOrthoOffCenterLH, use the following values: 
// l = -w/2, r = w/2, b = -h/2, and t = h/2.
//
//2/w  0    0           0
//0    2/h  0           0
//0    0    1/(zf-zn)   0
//0    0   -zn/(zf-zn)  1
//D3DXMatrixOrthoLH
inline mat4 mat4_ortho_lh(float w, float h, float zn, float zf) {
    return mat4(
        static_cast<float>(2.0)/w, static_cast<float>(0.0),   static_cast<float>(0.0),		    static_cast<float>(0.0), 
        static_cast<float>(0.0),   static_cast<float>(2.0)/h, static_cast<float>(0.0),		    static_cast<float>(0.0), 
        static_cast<float>(0.0),   static_cast<float>(0.0),   static_cast<float>(1.0)/(zf-zn),  static_cast<float>(0.0), 
        static_cast<float>(0.0),   static_cast<float>(0.0),   zn/(zn-zf),			            static_cast<float>(1.0)
    );
}

// The D3DXMatrixOrthoRH function is a special case of the D3DXMatrixOrthoOffCenterRH function. 
// To create the same projection using D3DXMatrixOrthoOffCenterRH, use the following values: 
// l = -w/2, r = w/2, b = -h/2, and t = h/2.
//
//2/w  0    0           0
//0    2/h  0           0
//0    0    1/(zn-zf)   0
//0    0    zn/(zn-zf)  1
//D3DXMatrixOrthoRH
inline mat4 mat4_ortho_rh(float w, float h, float zn, float zf) {
    return mat4(
        static_cast<float>(2.0)/w, static_cast<float>(0.0),   static_cast<float>(0.0),		    static_cast<float>(0.0), 
        static_cast<float>(0.0),   static_cast<float>(2.0)/h, static_cast<float>(0.0),		    static_cast<float>(0.0), 
        static_cast<float>(0.0),   static_cast<float>(0.0),   static_cast<float>(1.0)/(zn-zf),  static_cast<float>(0.0), 
        static_cast<float>(0.0),   static_cast<float>(0.0),   zn/(zn-zf),			            static_cast<float>(1.0)
	);    
}


//-----------------------------------------------
//-----------------------------------------------
// Find the intersection between a plane and a line.  If the line is parallel to the plane, NULL is returned.
//D3DXPlaneIntersectLine
inline vec3 plane_intersect_line(const plane& p, const vec3& pt1, const vec3& pt2) {
    vec3 out = k_zero<vec3>;
    vec3 direction = k_zero<vec3>;
    vec3 normal = k_zero<vec3>;
    float dot = 0.0, temp = 0.0;

    normal = p.normal;
    direction = pt2 - pt1;
    dot = vec3_dot(normal, direction);

    // line is parallel to the plane
    if (!dot) {
        printf("Line is parallel to the plane. Line does not intersect the plane.\n");
    } else {
        //hr.set_ok();
    }

    temp = (p.d + vec3_dot(normal, pt1)) / dot;
    
    for (int i=0; i < vec3::size(); ++i) {
        out[i] = pt1[i] - temp * direction[i];
    }

    return out;
}

// Construct a plane from a point and a normal
//vec3_point_normal_to_plane
//D3DXPlaneFromPointNormal
inline plane plane_from_point_normal(const vec3& point, const vec3& normal) {
    return plane(normal, -vec3_dot(point, normal));
}

// Construct a plane from 3 points
//plane_from_vertices
//D3DXPlaneFromPoints
inline plane plane_from_points(const vec3& pt1, const vec3& pt2, const vec3& pt3) {
    vec3 edge1 = pt2 - pt1;
    vec3 edge2 = pt3 - pt1;
    vec3 normal = vec3_normalize(vec3_cross(edge1, edge2));
    return plane_from_point_normal(pt1, normal);
}


// Transform a plane by a matrix. The vector (a,b,c) must be normal.
// M should be the inverse transpose of the transformation desired.
//D3DXPlaneTransform
inline plane plane_transform_mat4_inverse_transposed(const plane& p, const mat4& ma) {
    return plane(
        ma.r[0][0]*p.a + ma.r[1][0]*p.b + ma.r[2][0]*p.c + ma.r[3][0]*p.d,
        ma.r[0][1]*p.a + ma.r[1][1]*p.b + ma.r[2][1]*p.c + ma.r[3][1]*p.d,
        ma.r[0][2]*p.a + ma.r[1][2]*p.b + ma.r[2][2]*p.c + ma.r[3][2]*p.d,
        ma.r[0][3]*p.a + ma.r[1][3]*p.b + ma.r[2][3]*p.c + ma.r[3][3]*p.d
    );
}    

//----------------------


// (-x, -y, -z, w)
inline quat quat_conjugate(const quat& a) { return quat(-a.x, -a.y, -a.z, a.w); }

//// same as quat_conjugate
//, inline quat quat_negate(const quat& a) { 
//	//return quat(-a.axis, a.rotation); 
//	return quat_conjugate(a);
//}

// Conjugate and re-norm
inline quat quat_inverse(const quat& a) {
    //return quat_conjugate(a * (static_cast<float>(1.0) / quat_length_sq(a)));

    quat out = k_zero<quat>;

    float norm = quat_length_sq(a);
    float inv_norm = static_cast<float>(1.0)/norm;

    out.x = -a.x * inv_norm;
    out.y = -a.y * inv_norm;
    out.z = -a.z * inv_norm;
    out.w = a.w * inv_norm;

    return out;
}

//, inline quat operator/(const quat& a, const quat& b) { return a * quat_inverse(b); }


inline bool quat_is_identity(const quat& a) { return (a == k_identity<quat>); }

//, inline quat quat_concatenate(const quat& a, const quat& b) { return b * a; }


//----------------------------------------
// Build a matrix from a quaternion
//D3DXMatrixRotationQuaternion
inline mat4 mat4_rotation_quat(const quat& qa) {
    float xx = qa.x*qa.x;
    float yy = qa.y*qa.y;
    float zz = qa.z*qa.z;
    float xy = qa.x*qa.y;
    float zw = qa.z*qa.w;
    float xz = qa.x*qa.z;
    float yw = qa.y*qa.w;
    float yz = qa.y*qa.z;
    float wx = qa.w*qa.x;

    return mat4(
        static_cast<float>(1.0) - static_cast<float>(2.0)*(yy + zz),  static_cast<float>(2.0)*(xy + zw),                      static_cast<float>(2.0)*(xz - yw),      static_cast<float>(0.0),
        static_cast<float>(2.0)*(xy - zw),                      static_cast<float>(1.0) - static_cast<float>(2.0)*(xx + zz),  static_cast<float>(2.0)*(yz + wx),      static_cast<float>(0.0),
        static_cast<float>(2.0)*(xz + yw),                      static_cast<float>(2.0)*(yz - wx),                      static_cast<float>(1.0) - static_cast<float>(2.0)*(xx + yy),  static_cast<float>(0.0),
        static_cast<float>(0.0),                                static_cast<float>(0.0),                                static_cast<float>(0.0),                static_cast<float>(1.0)
    );
}
// Yaw around the Y axis, Pitch around the X axis, Roll around the Z axis.
//D3DXMatrixRotationYawPitchRoll
inline mat4 mat4_rotation_yaw_pitch_roll(float yaw, float pitch, float roll) {
    const float sy = sin(yaw);
    const float cy = cos(yaw);
    const float sp = sin(pitch);
    const float cp = cos(pitch);
    const float sr = sin(roll);
    const float cr = cos(roll);    

    mat4 out(
        sr*sp*sy + cr*cy,         sr*cp,                    sr*sp*cy - cr*sy,         static_cast<float>(0.0),
        cr*sp*sy - sr*cy,         cr*cp,                    cr*sp*cy + sr*sy,         static_cast<float>(0.0),
        cp*sy,                    -sp,                      cp*cy,                    static_cast<float>(0.0),
        static_cast<float>(0.0),  static_cast<float>(0.0),  static_cast<float>(0.0),  static_cast<float>(1.0)
    );

    return out;
}

// Compute a quaternian's axis and angle of rotation. Expects unit quaternions.
//D3DXQuaternionToAxisAngle
inline void quat_to_axis_angle(const quat& unit_quat, vec3& axis, float& angle) {
    axis = unit_quat.axis;
    angle = static_cast<float>(2.0) * acos(unit_quat.rotation);
}


//D3DXQuaternionRotationMatrix
// winnumerics
// Build a quaternion from a rotation matrix.
// same as quat_from_rotation_mat4
//inline quat make_quaternion_from_rotation_matrix(const mat4& ma)
inline quat quat_rotation_mat4(const mat4& ma) {
    if (ma.r[0][0] + ma.r[1][1] + ma.r[2][2] > static_cast<float>(0.0)) {
        float s = sqrtf(static_cast<float>(1.0) + ma.r[0][0] + ma.r[1][1] + ma.r[2][2]);
        float inv_s = static_cast<float>(0.5) / s;

        return quat((ma.r[1][2] - ma.r[2][1]) * inv_s,
                    (ma.r[2][0] - ma.r[0][2]) * inv_s,
                    (ma.r[0][1] - ma.r[1][0]) * inv_s,
                    s * static_cast<float>(0.5));

    } else if (ma.r[0][0] >= ma.r[1][1] && ma.r[0][0] >= ma.r[2][2]) {
        float s = sqrtf(static_cast<float>(1.0) + ma.r[0][0] - ma.r[1][1] - ma.r[2][2]);
        float inv_s = static_cast<float>(0.5) / s;

        return quat(static_cast<float>(0.5) * s,
                    (ma.r[0][1] + ma.r[1][0]) * inv_s,
                    (ma.r[0][2] + ma.r[2][0]) * inv_s,
                    (ma.r[1][2] - ma.r[2][1]) * inv_s);

    } else if (ma.r[1][1] > ma.r[2][2]) {
        float s = sqrtf(static_cast<float>(1.0) + ma.r[1][1] - ma.r[0][0] - ma.r[2][2]);
        float inv_s = static_cast<float>(0.5) / s;

        return quat((ma.r[1][0] + ma.r[0][1]) * inv_s,
                    static_cast<float>(0.5) * s,
                    (ma.r[2][1] + ma.r[1][2]) * inv_s,
                    (ma.r[2][0] - ma.r[0][2]) * inv_s);

    } else {
        float s = sqrtf(static_cast<float>(1.0) + ma.r[2][2] - ma.r[0][0] - ma.r[1][1]);
        float inv_s = static_cast<float>(0.5) / s;

        return quat((ma.r[2][0] + ma.r[0][2]) * inv_s,
                    (ma.r[2][1] + ma.r[1][2]) * inv_s,
                    static_cast<float>(0.5) * s,
                    (ma.r[0][1] - ma.r[1][0]) * inv_s);
    }
}


//D3DXQuaternionSlerp
//winnumerics
// Spherical linear interpolation between Q1 (t == 0) and Q2 (t == 1). s (time)
// Expects unit quaternions.
// Interpolates between two quaternions, using spherical linear interpolation.
//inline quaternion slerp(quaternion const& quaternion1, quaternion const& quaternion2, float amount)
inline quat quat_slerp(const quat& unit_quat_a, const quat& unit_quat_b, float s) {    
    const quat& a = unit_quat_a;
    const quat& b = unit_quat_b;
    const float& t = s;

    const float epsilon = static_cast<float>(1e-6);
    
    float cos_omega = quat_dot(a, b);
    bool flip = false;
        
    // Make sure we use the short rotation
    if (cos_omega < static_cast<float>(0.0)) {
        flip = true;
        cos_omega = -cos_omega;
    }

    float s1 = 0.0, s2 = 0.0;
        
    if (cos_omega > (static_cast<float>(1.0) - epsilon)) {
        // Too close, do straight linear interpolation.
        s1 = static_cast<float>(1.0) - t;
        s2 = flip ? -t : t;
    } else {
        // spherical interpolation
        float omega = acos(cos_omega);
        float inv_sin_omega = static_cast<float>(1.0) / sin(omega);

        s1 = sin((static_cast<float>(1.0) - t) * omega) * inv_sin_omega;
        s2 = flip ? -sin(t * omega) * inv_sin_omega
                  :  sin(t * omega) * inv_sin_omega;
    }

    quat out = k_zero<quat>;
    for (int i=0; i < quat::size(); ++i) {
        out[i] = s1 * a[i] + s2 * b[i];
    }
    return out;
}


//----------
// Rotation about arbitrary axis.
//D3DXQuaternionRotationAxis
inline quat quat_from_rotation_axis(const vec3& a, float angle) {    
    quat out = k_zero<quat>;
    vec3 temp = vec3_normalize(a);
    float half_angle = angle * static_cast<float>(0.5);
    const float sha = sin(half_angle);
    const float cha = cos(half_angle);
    out.axis = sha * temp;
    out.rotation = cha;
    return out;
}


// Yaw around the Y axis, Pitch around the X axis, Roll around the Z axis.
//D3DXQuaternionRotationYawPitchRoll
inline quat quat_rotation_yaw_pitch_roll(float yaw, float pitch, float roll) {
    quat out = k_zero<quat>;

    // Roll first, about axis the object is facing, then pitch upward, then yaw to face into the new heading
    float half_yaw = yaw * static_cast<float>(0.5);
    float sy = sin(half_yaw); 
    float cy = cos(half_yaw);
    float half_pitch = pitch * static_cast<float>(0.5);
    float sp = sin(half_pitch); 
    float cp = cos(half_pitch);
    float half_roll = roll * static_cast<float>(0.5);
    float sr = sin(half_roll); 
    float cr = cos(half_roll);

    out.x = sy*cp*sr + cy*sp*cr;
    out.y = sy*cp*cr - cy*sp*sr;
    out.z = cy*cp*sr - sy*sp*cr;
    out.w = cy*cp*cr + sy*sp*sr;

    return out;
}



//----------------------------------------------------------
// A unit quaternion, is defined by:
// Q == (cos(theta), sin(theta) * a) where |a| = 1
// The natural logarithm of Q is, ln(Q) = (0, theta * a)

// Expects unit quaternions.
// if q = (cos(theta), sin(theta) * a); ln(q) = (0, theta * a)
//D3DXQuaternionLn
inline quat quat_ln(const quat& a) {
    quat out = k_zero<quat>;
    float tf = 0.0;

    if ((a.w >= static_cast<float>(1.0)) || (a.w == -static_cast<float>(1.0))) {
        tf = static_cast<float>(1.0);
    } else {
        tf = acos(a.w) / sqrt(static_cast<float>(1.0) - (a.w*a.w));
    }

    out.axis = tf * a.axis;
    out.rotation = static_cast<float>(0.0);

    return out;
}

// Expects pure quaternions. (w == 0)  w is ignored in calculation.
// if q = (0, theta * a); exp(q) = (cos(theta), sin(theta) * a)
//D3DXQuaternionExp
inline quat quat_exp(const quat& a) {
    quat out = k_identity<quat>;

    // only first 3 members used
    float norm = sqrt(a.x*a.x + a.y*a.y + a.z*a.z);    

    if (norm) {
        float inv_norm = static_cast<float>(1.0)/norm;
        float snorm = sin(norm);
        float cnorm = cos(norm);

        out.x = snorm * a.x * inv_norm;
        out.y = snorm * a.y * inv_norm;
        out.z = snorm * a.z * inv_norm;
        out.w = cnorm;
    }
    // else: return out set as quat_identity.

    return out;
}



// Spherical quadrangle interpolation.
// Slerp(Slerp(Q1, C, s), Slerp(A, B, s), 2s(1-s))
//D3DXQuaternionSquad
inline quat quat_squad(const quat& pq1, const quat& pqa, const quat& pqb, const quat& pqc, float s) {
    quat out = k_zero<quat>;
    quat temp1 = quat_slerp(pq1, pqc, s);
    quat temp2 = quat_slerp(pqa, pqb, s);
    out = quat_slerp(temp1, temp2, static_cast<float>(2.0)*s * (static_cast<float>(1.0) - s));
    return out;
}

// Setup control points for spherical quadrangle interpolation from Q1 to Q2.  
// The control points are chosen in such a way to ensure the continuity of tangents with adjacent segments.
//D3DXQuaternionSquadSetup
inline void quat_squad_setup(quat& aout, quat& bout, quat& cout, const quat& pq0, const quat& pq1, const quat& pq2, const quat& pq3) {
    quat q = k_zero<quat>;
    quat temp1 = k_zero<quat>;
    quat temp2 = k_zero<quat>;
    quat temp3 = k_zero<quat>;
    quat tzero = k_zero<quat>;


    if (quat_dot(pq0, pq1) < static_cast<float>(0.0)) {
        temp2 = quat_mul_angles(tzero, pq0, -static_cast<float>(1.0));
    } else {
        temp2 = pq0;
    }

    if (quat_dot(pq1, pq2) < static_cast<float>(0.0)) {
        cout = quat_mul_angles(tzero, pq2, -static_cast<float>(1.0));
    } else {
        cout = pq2;
    }

    if (quat_dot(cout, pq3) < static_cast<float>(0.0)) {
        temp3 = quat_mul_angles(tzero, pq3, -static_cast<float>(1.0));
    } else {
        temp3 = pq3;
    }

    temp1 = quat_inverse(pq1);
    temp2 = quat_ln(temp1 * temp2);
    q = quat_ln(temp1 * cout);
    temp1 = quat_mul_angles(temp2, q, static_cast<float>(1.0));
    temp1 = temp1 * (-static_cast<float>(0.25));
    aout = pq1 * quat_exp(temp1);

    temp1 = quat_inverse(cout);
    temp2 = quat_ln(temp1 * pq1);
    q = quat_ln(temp1 * temp3);
    temp1 = quat_mul_angles(temp2, q, static_cast<float>(1.0));
    temp1 = temp1 * (-static_cast<float>(0.25));
    bout = cout * quat_exp(temp1);           
}


// Barycentric interpolation.
// Slerp(Slerp(Q1, Q2, f+g), Slerp(Q1, Q3, f+g), g/(f+g))
//D3DXQuaternionBaryCentric
inline quat quat_bary_centric(const quat& pq1, const quat& pq2, const quat& pq3, float f, float g) {
    quat out = k_zero<quat>;
    quat temp1 = quat_slerp(pq1, pq2, f + g);
    quat temp2 = quat_slerp(pq1, pq3, f + g);
    out = quat_slerp(temp1, temp2, g/(f + g));
    return out;
}

//----------------------------------------------------------
//----------------------------------------------------------
// Original d3dx9math functions takes pointers. NULL arguments are treated as identity transformations.
// Builds a transformation matrix. 
// Mout = Msc-1 * Msr-1 * Ms * Msr * Msc * Mrc-1 * Mr * Mrc * Mt
//D3DXMatrixTransformation
// NOT EQUAL to d3dx9.dll version. Totally different result.
// Check from other mathlib
inline mat4 mat4_transformation_ptr(const vec3 *pscalingcenter, const quat *pscalingrotation, 
    const vec3 *pscaling, const vec3 *protationcenter, const quat *protation, const vec3 *ptranslation) {
    mat4 out = k_identity<mat4>;

    mat4 m1 = k_identity<mat4>;
    mat4 m2 = k_identity<mat4>;
    mat4 m3 = k_identity<mat4>; 
    mat4 m4 = k_identity<mat4>; 
    mat4 m5 = k_identity<mat4>; 
    mat4 m6 = k_identity<mat4>; 
    mat4 m7 = k_identity<mat4>;

    quat qrc = k_identity<quat>;
    vec3 vsc = k_zero<vec3>;
    vec3 vtr = k_zero<vec3>;

    if (pscalingcenter) {
        vsc = *pscalingcenter;
    } else {
        vsc = k_zero<vec3>;
    }

    if (protationcenter) {
        qrc = quat(*protationcenter, static_cast<float>(1.0));
    } else {
        qrc = k_identity<quat>;       
    }

    if (ptranslation) {
        vtr = *ptranslation;
    } else {
        vtr = k_zero<vec3>;        
    }

    m1 = mat4_translation(-vsc);

    if (pscalingrotation) {
        m4 = mat4_rotation_quat(*pscalingrotation);
        m2 = mat4_inverse(m4);        
    } else {        
        m4 = k_identity<mat4>;
        m2 = k_identity<mat4>;
    }

    if (pscaling) { 
        m3 = mat4_scaling(*pscaling);        
    } else {
        m3 = k_identity<mat4>;
    }

    if (protation) { 
        m6 = mat4_rotation_quat(*protation);        
    } else {
        m6 = k_identity<mat4>;
    }

    m5 = mat4_translation(vec3(vsc.x - qrc.x,  vsc.y - qrc.y,  vsc.z - qrc.z));
    m7 = mat4_translation(vec3(qrc.x + vtr.x, qrc.y + vtr.y, qrc.z + vtr.z));

    m1 = m1 * m2;
    m1 = m1 * m3;
    m1 = m1 * m4;
    m1 = m1 * m5;
    m1 = m1 * m6;
    out = m1 * m7;

    return out;
}

// Build 2D transformation matrix in XY plane.
// Mout = Msc-1 * Msr-1 * Ms * Msr * Msc * Mrc-1 * Mr * Mrc * Mt
//D3DXMatrixTransformation2D
inline mat4 mat4_transformation_2d_ptr(const vec2 *pscalingcenter, float scalingrotation, 
    const vec2 *pscaling, const vec2 *protationcenter, float rotation, const vec2 *ptranslation) {
    mat4 out = k_identity<mat4>;

    quat qrot = k_zero<quat>; 
    quat qsrot = k_zero<quat>;

    vec3 vs = k_one<vec3>;

    vec3 vrc = k_zero<vec3>;    
    vec3 vsc = k_zero<vec3>;
    vec3 vt = k_zero<vec3>;

    if (pscalingcenter) {
        vsc = vec2_to_vec3(*pscalingcenter, static_cast<float>(0.0));
    } else {
        vsc = k_zero<vec3>;
    }

    if (pscaling) {
        vs = vec2_to_vec3(*pscaling, static_cast<float>(1.0));
    } else {
        vs = k_one<vec3>;
    }

    if (protationcenter) {
        vrc = vec2_to_vec3(*protationcenter, static_cast<float>(0.0));
    } else {
        vrc = k_zero<vec3>;
    }

    if (ptranslation) {
        vt = vec2_to_vec3(*ptranslation, static_cast<float>(0.0));
    } else {
        vt = k_zero<vec3>;
    }

    
    const float hrot = rotation * static_cast<float>(0.5);
    const float hsrot = scalingrotation * static_cast<float>(0.5);

    qrot.x = static_cast<float>(0.0);
    qrot.y = static_cast<float>(0.0);
    qrot.z = sin(hrot);
    qrot.w = cos(hrot);

    
    qsrot.x = static_cast<float>(0.0);
    qsrot.y = static_cast<float>(0.0);
    qsrot.z = sin(hsrot);
    qsrot.w = cos(hsrot);

    out = mat4_transformation_ptr(&vsc, &qsrot, &vs, &vrc, &qrot, &vt);

    return out;
}

// Build affine transformation matrix.
// Mout = Ms * Mrc-1 * Mr * Mrc * Mt
//D3DXMatrixAffineTransformation
inline mat4 mat4_affine_transformation_ptr(float scaling, const vec3 *rotationcenter, const quat *rotation, const vec3 *translation) {

    mat4 out = k_identity<mat4>;

    if (rotation) {
        float temp00 = 0.0f, temp01 = 0.0f, temp02 = 0.0f, temp10 = 0.0f, temp11 = 0.0f, temp12 = 0.0f, temp20 = 0.0f, temp21 = 0.0f, temp22 = 0.0f;

        temp00 = static_cast<float>(1.0) - static_cast<float>(2.0) * (rotation->y * rotation->y + rotation->z * rotation->z);
        temp01 = static_cast<float>(2.0) * (rotation->x * rotation->y + rotation->z * rotation->w);
        temp02 = static_cast<float>(2.0) * (rotation->x * rotation->z - rotation->y * rotation->w);
        temp10 = static_cast<float>(2.0) * (rotation->x * rotation->y - rotation->z * rotation->w);
        temp11 = static_cast<float>(1.0) - static_cast<float>(2.0) * (rotation->x * rotation->x + rotation->z * rotation->z);
        temp12 = static_cast<float>(2.0) * (rotation->y * rotation->z + rotation->x * rotation->w);
        temp20 = static_cast<float>(2.0) * (rotation->x * rotation->z + rotation->y * rotation->w);
        temp21 = static_cast<float>(2.0) * (rotation->y * rotation->z - rotation->x * rotation->w);
        temp22 = static_cast<float>(1.0) - static_cast<float>(2.0) * (rotation->x * rotation->x + rotation->y * rotation->y);

        out.r[0][0] = scaling * temp00;
        out.r[0][1] = scaling * temp01;
        out.r[0][2] = scaling * temp02;
        out.r[1][0] = scaling * temp10;
        out.r[1][1] = scaling * temp11;
        out.r[1][2] = scaling * temp12;
        out.r[2][0] = scaling * temp20;
        out.r[2][1] = scaling * temp21;
        out.r[2][2] = scaling * temp22;

        if (rotationcenter) {
            out.r[3][0] = rotationcenter->x * (static_cast<float>(1.0) - temp00) - rotationcenter->y * temp10 - rotationcenter->z * temp20;
            out.r[3][1] = rotationcenter->y * (static_cast<float>(1.0) - temp11) - rotationcenter->x * temp01 - rotationcenter->z * temp21;
            out.r[3][2] = rotationcenter->z * (static_cast<float>(1.0) - temp22) - rotationcenter->x * temp02 - rotationcenter->y * temp12;
        }
    } else {
        out.r[0][0] = scaling;
        out.r[1][1] = scaling;
        out.r[2][2] = scaling;
    }

    if (translation) {
        out.r[3][0] += translation->x;
        out.r[3][1] += translation->y;
        out.r[3][2] += translation->z;
    }

    return out;
}

// Build 2D affine transformation matrix in XY plane.
// Mout = Ms * Mrc-1 * Mr * Mrc * Mt
//D3DXMatrixAffineTransformation2D
inline mat4 mat4_affine_transformation_2d_ptr(float scaling, const vec2 *rotationcenter, float rotation, const vec2 *translation) {
    mat4 out = k_identity<mat4>;

    float half_rotation = rotation * static_cast<float>(0.5);
    const float s = sin(half_rotation);
    const float tmp1 = static_cast<float>(1.0) - static_cast<float>(2.0)*s*s;
    const float tmp2 = static_cast<float>(2.0) * s * cos(half_rotation);
    
    out.r[0][0] = scaling * tmp1;
    out.r[0][1] = scaling * tmp2;
    out.r[1][0] = -scaling * tmp2;
    out.r[1][1] = scaling * tmp1;

    if (rotationcenter) {
        const float x = rotationcenter->x;
        const float y = rotationcenter->y;

        out.r[3][0] =  y * tmp2 - x * tmp1 + x;
        out.r[3][1] = -x * tmp2 - y * tmp1 + y;
    }

    if (translation) {
        out.r[3][0] += translation->x;
        out.r[3][1] += translation->y;
    }

    return out;
}



//===================================================================================
//g_math_ex_2.h


class viewport_gl {
public:
    float x, y, w, h;   
};

inline void fix_camera_axis(gm::vec3& position) {
	if (position.x == 0.0f && position.y == 0.0f) { position.x = 0.000001f; }
}


//=======================================================
// EXTRA FUNCTIONS
//=======================================================
inline mat4 mat4_inverse_transpose(const mat4& ma) {
	return mat4_transpose(mat4_inverse(ma));
}


inline mat4 mat4_shadow_vec3(vec3 const& light_dir, plane const& pa) {
    return mat4_shadow(vec4(light_dir.x, light_dir.y, light_dir.z, 0.0), pa);
}

//------------------
inline vec3 vec3_negate(const vec3& a) { return -a; }
inline vec3 vec3_inverse(const vec3& a) { return -a; }

inline vec3 vec3_fabs(const vec3& a) {
	vec3 out = k_zero<vec3>;
	for (int i=0; i < vec3::size(); ++i) {
		out[i] = fabs(a[i]);
	}
	return out;
}

inline vec3 vec3_deg_to_rad(const vec3& a) {
    vec3 out = k_zero<vec3>;
	for (int i=0; i < vec3::size(); ++i) {
		out[i] = mf::deg_to_rad(a[i]);
	}
	return out;
}


//----------------------------------------

//color4 color4_srgb_correction(color4 color) {
//    constexpr float GAMMAVAL = 2.2;
//
//    // unpack D3DCOLOR into something we can manipulate
//    color4 out = gm::color4::k_zero();
//    // gamma correct colors...
//    out.r = pow(color.r, GAMMAVAL);
//    out.g = pow(color.g, GAMMAVAL);
//    out.b = pow(color.b, GAMMAVAL);
//    out.a = color.a;
//
//    // repack the aforementioned data into the colorvalue for returning
//    return out;
//}

//----------------------------------------
inline mat4 mat4_shearing(float x, float y) {
	return mat4(
		static_cast<float>(1.0),	y,					        static_cast<float>(0.0), static_cast<float>(0.0),
		x,					        static_cast<float>(1.0),	static_cast<float>(0.0), static_cast<float>(0.0),
		static_cast<float>(0.0),	static_cast<float>(0.0),	static_cast<float>(1.0), static_cast<float>(0.0),
		static_cast<float>(0.0),	static_cast<float>(0.0),	static_cast<float>(0.0), static_cast<float>(1.0)
	);
}


//--------------------------------------------
//--------------------------------------------
// Disable when glm functions are implemented:

// Direct3D-like: The clip space depth goes from 0.0 at the near plane to +1.0 at the far plane. 
// This applies to Direct3D, Vulkan, Metal and consoles. 
// OpenGL-like: The clip space depth goes from –1.0 at the near plane to +1.0 at the far plane.
inline mat4 glm_perspectiveRH_NO(float fovy, float aspect, float zNear, float zFar) {
	//assert(abs(aspect - std::numeric_limits<float>::epsilon()) > static_cast<float>(0));

	float const tanHalfFovy = tan(fovy / static_cast<float>(2));

	mat4 Result(static_cast<float>(0));
	Result.r[0][0] = static_cast<float>(1) / (aspect * tanHalfFovy);
	Result.r[1][1] = static_cast<float>(1) / (tanHalfFovy);
	Result.r[2][2] = - (zFar + zNear) / (zFar - zNear);
	Result.r[2][3] = - static_cast<float>(1);
	Result.r[3][2] = - (static_cast<float>(2) * zFar * zNear) / (zFar - zNear);
	return Result;
}

inline mat4 glm_perspectiveRH_ZO(float fovy, float aspect, float zNear, float zFar) {
	//assert(abs(aspect - std::numeric_limits<float>::epsilon()) > static_cast<float>(0));

	float const tanHalfFovy = tan(fovy / static_cast<float>(2));

	mat4 Result(static_cast<float>(0));
	Result.r[0][0] = static_cast<float>(1) / (aspect * tanHalfFovy);
	Result.r[1][1] = static_cast<float>(1) / (tanHalfFovy);
	Result.r[2][2] = zFar / (zNear - zFar);
	Result.r[2][3] = - static_cast<float>(1);
	Result.r[3][2] = -(zFar * zNear) / (zFar - zNear);
	return Result;
}
//--------------------------------------------




}













