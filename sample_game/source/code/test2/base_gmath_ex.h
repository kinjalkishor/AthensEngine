#pragma once

#include "base_gmath.h"

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
    T out = T::k_zero(); 
    float h1, h2, h3, h4;
    //set_hermite_coeffcients(h1, h2, h3, h4, s);
    float s3 = mf::cube(s);
	float s2 = mf::square(s); 

    //h1 = (2.0f * s*s*s) - (3.0f * s*s) + 1.0f;
    //h2 = (s*s*s) - (2.0f * s*s) + s;
    //h3 = -(2.0f * s*s*s) + (3.0f * s*s);
    //h4 = (s*s*s) - (s*s);

    h1 = (scast<float>(2.0) * s3) - (scast<float>(3.0) * s2) + scast<float>(1.0);
    h2 = (s3) - (scast<float>(2.0) * s2) + s;
    h3 = (-scast<float>(2.0) * s3) + (scast<float>(3.0) * s2);
    h4 = (s3) - (s2);    

    for_range (i, 0, T::size()) { out[i] = h1 * v1[i] + h2 * t1[i] + h3 * v2[i] + h4 * t2[i]; }

    return out;
}

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
template<class T> inline T vecnt_catmull_rom(const T& v0, const T& v1, const T& v2, const T& v3, float s) {
    T out = T::k_zero(); 
    float s3 = mf::cube(s);
	float s2 = mf::square(s); 

    for_range (i, 0, T::size()) {
        out[i] = scast<float>(0.5) * (scast<float>(2.0) * v1[i] + (v2[i] - v0[i]) * s + (scast<float>(2.0) * v0[i] - scast<float>(5.0) * v1[i] 
            + scast<float>(4.0) * v2[i] - v3[i]) * s2 + (v3[i] -scast<float>(3.0) * v2[i] + scast<float>(3.0) * v1[i] - v0[i]) * s3);
    }

    return out;
}

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
template<class T> inline T vecnt_bary_centric(const T& v1, const T& v2, const T& v3, float f, float g) {
    T out = T::k_zero(); for_range (i, 0, T::size()) { out[i] = (scast<float>(1.0)-f-g) * v1[i] + f * v2[i] + g * v3[i]; } return out;
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
    vec4 out = vec4::k_zero();
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
        -scast<float>(2.0)*p.a*p.a + scast<float>(1.0), -scast<float>(2.0)*p.b*p.a,                     -scast<float>(2.0)*p.c*p.a,                     scast<float>(0.0),
        -scast<float>(2.0)*p.a*p.b,                     -scast<float>(2.0)*p.b*p.b + scast<float>(1.0), -scast<float>(2.0)*p.c*p.b,                     scast<float>(0.0),
        -scast<float>(2.0)*p.a*p.c,                     -scast<float>(2.0)*p.b*p.c,                     -scast<float>(2.0)*p.c*p.c + scast<float>(1.0), scast<float>(0.0),
        -scast<float>(2.0)*p.a*p.d,                     -scast<float>(2.0)*p.b*p.d,                     -scast<float>(2.0)*p.c*p.d,                     scast<float>(1.0)
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
        scast<float>(2.0) * zn/w, scast<float>(0.0),		    scast<float>(0.0),  scast<float>(0.0), 
        scast<float>(0.0),		  scast<float>(2.0) * zn/h,     scast<float>(0.0),  scast<float>(0.0), 
        scast<float>(0.0),		  scast<float>(0.0),		    zf/(zf-zn),		    scast<float>(1.0), 
        scast<float>(0.0),		  scast<float>(0.0),		    (zn*zf)/(zn-zf),    scast<float>(0.0)
	);    
}

//2*zn/w  0       0              0
//0       2*zn/h  0              0
//0       0       zf/(zn-zf)    -1
//0       0       zn*zf/(zn-zf)  0
//D3DXMatrixPerspectiveRH
inline mat4 mat4_perspective_rh(float w, float h, float zn, float zf) {
    return mat4(
        scast<float>(2.0) * zn/w, scast<float>(0.0),		scast<float>(0.0), scast<float>(0.0), 
        scast<float>(0.0),		  scast<float>(2.0) * zn/h, scast<float>(0.0), scast<float>(0.0), 
        scast<float>(0.0),		  scast<float>(0.0),		zf/(zn-zf),		   -scast<float>(1.0), 
        scast<float>(0.0),		  scast<float>(0.0),		(zn*zf)/(zn-zf),   scast<float>(0.0)
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
        scast<float>(2.0) * zn/(r-l),   scast<float>(0.0),										            scast<float>(0.0),	scast<float>(0.0), 
        scast<float>(0.0),			    -scast<float>(2.0) * zn/(b-t),							            scast<float>(0.0),	scast<float>(0.0), 
        -scast<float>(1.0) - scast<float>(2.0) * l/(r-l), scast<float>(1.0) + scast<float>(2.0) * t/(b-t),  -zf/(zn-zf),	    scast<float>(1.0), 
        scast<float>(0.0),			    scast<float>(0.0),											        (zn*zf)/(zn-zf),    scast<float>(0.0)
	);    
}

//2*zn/(r-l)   0            0                0
//0            2*zn/(t-b)   0                0
//(l+r)/(r-l)  (t+b)/(t-b)  zf/(zn-zf)      -1
//0            0            zn*zf/(zn-zf)    0
//D3DXMatrixPerspectiveOffCenterRH
inline mat4 mat4_perspective_offcenter_rh(float l, float r, float b, float t, float zn, float zf) {
    return mat4(
        scast<float>(2.0) * zn/(r-l), scast<float>(0.0),										          scast<float>(0.0),  scast<float>(0.0), 
        scast<float>(0.0),			  -scast<float>(2.0) * zn/(b-t),								      scast<float>(0.0),  scast<float>(0.0), 
        scast<float>(1.0) + scast<float>(2.0) * l/(r-l), -scast<float>(1.0) -scast<float>(2.0) * t/(b-t), zf/(zn-zf),         -scast<float>(1.0), 
        scast<float>(0.0),			  scast<float>(0.0),											      (zn*zf)/(zn-zf),    scast<float>(0.0)
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
        scast<float>(2.0)/(r-l),					 scast<float>(0.0),				scast<float>(0.0),		    scast<float>(0.0), 
        scast<float>(0.0),							 scast<float>(2.0)/(t-b),		scast<float>(0.0),		    scast<float>(0.0), 
        scast<float>(0.0),							 scast<float>(0.0),				scast<float>(1.0)/(zf -zn), scast<float>(0.0), 
        -scast<float>(1.0) - scast<float>(2.0) * l/(r-l), scast<float>(1.0) + scast<float>(2.0) * t/(b-t), zn/(zn-zf), scast<float>(1.0)
	);    
}

//2/(r-l)      0            0           0
//0            2/(t-b)      0           0
//0            0            1/(zn-zf)   0
//(l+r)/(l-r)  (t+b)/(b-t)  zn/(zn-zf)  1
//D3DXMatrixOrthoOffCenterRH
inline mat4 mat4_ortho_offcenter_rh(float l, float r, float b, float t, float zn, float zf) {
    return mat4(
        scast<float>(2.0)/(r-l),				     scast<float>(0.0),					scast<float>(0.0),		        scast<float>(0.0), 
        scast<float>(0.0),							 scast<float>(2.0)/(t-b),			scast<float>(0.0),		        scast<float>(0.0), 
        scast<float>(0.0),							 scast<float>(0.0),					scast<float>(1.0)/(zn-zf),      scast<float>(0.0), 
        -scast<float>(1.0) - scast<float>(2.0) * l/(r-l), scast<float>(1.0) + scast<float>(2.0) * t/(b-t), zn/(zn-zf),	scast<float>(1.0)
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
        scast<float>(2.0)/w, scast<float>(0.0),   scast<float>(0.0),		    scast<float>(0.0), 
        scast<float>(0.0),   scast<float>(2.0)/h, scast<float>(0.0),		    scast<float>(0.0), 
        scast<float>(0.0),   scast<float>(0.0),   scast<float>(1.0)/(zf-zn),    scast<float>(0.0), 
        scast<float>(0.0),   scast<float>(0.0),   zn/(zn-zf),			        scast<float>(1.0)
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
        scast<float>(2.0)/w, scast<float>(0.0),   scast<float>(0.0),		    scast<float>(0.0), 
        scast<float>(0.0),   scast<float>(2.0)/h, scast<float>(0.0),		    scast<float>(0.0), 
        scast<float>(0.0),   scast<float>(0.0),   scast<float>(1.0)/(zn-zf),    scast<float>(0.0), 
        scast<float>(0.0),   scast<float>(0.0),   zn/(zn-zf),			        scast<float>(1.0)
	);    
}


//-----------------------------------------------
//-----------------------------------------------
// Find the intersection between a plane and a line.  If the line is parallel to the plane, NULL is returned.
//D3DXPlaneIntersectLine
inline vec3 plane_intersect_line(const plane& p, const vec3& pt1, const vec3& pt2) {
    vec3 out = vec3::k_zero();
    vec3 direction = vec3::k_zero();
    vec3 normal = vec3::k_zero();
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

    for_range (i, 0, vec3::size()) {
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
// Length squared, or "norm"
inline float quat_length_sq(const quat& a) { return vec4_length_sq(a.v); }	
inline float quat_length(const quat& a) { return vec4_length(a.v); }

// (-x, -y, -z, w)
inline quat quat_conjugate(const quat& a) { return quat(-a.x, -a.y, -a.z, a.w); }

//// same as quat_conjugate
//, inline quat quat_negate(const quat& a) { 
//	//return quat(-a.axis, a.rotation); 
//	return quat_conjugate(a);
//}

// Conjugate and re-norm
inline quat quat_inverse(const quat& a) {
    //return quat_conjugate(a * (scast<float>(1.0) / quat_length_sq(a)));

    quat out = quat::k_zero();

    float norm = quat_length_sq(a);
    float inv_norm = scast<float>(1.0)/norm;

    out.x = -a.x * inv_norm;
    out.y = -a.y * inv_norm;
    out.z = -a.z * inv_norm;
    out.w = a.w * inv_norm;

    return out;
}

//, inline quat operator/(const quat& a, const quat& b) { return a * quat_inverse(b); }

inline float quat_dot(const quat& a, const quat& b) { return vec4_dot(a.v, b.v); }
inline bool quat_is_identity(const quat& a) { return (a == quat::k_identity()); }
inline quat quat_normalize(const quat& a) {	return quat(vec4_normalize(a.v)); }
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
        scast<float>(1.0) - scast<float>(2.0)*(yy + zz),  scast<float>(2.0)*(xy + zw),                      scast<float>(2.0)*(xz - yw),      scast<float>(0.0),
        scast<float>(2.0)*(xy - zw),                      scast<float>(1.0) - scast<float>(2.0)*(xx + zz),  scast<float>(2.0)*(yz + wx),      scast<float>(0.0),
        scast<float>(2.0)*(xz + yw),                      scast<float>(2.0)*(yz - wx),                      scast<float>(1.0) - scast<float>(2.0)*(xx + yy),  scast<float>(0.0),
        scast<float>(0.0),                                scast<float>(0.0),                                scast<float>(0.0),                scast<float>(1.0)
    );
}
// Yaw around the Y axis, Pitch around the X axis, Roll around the Z axis.
//D3DXMatrixRotationYawPitchRoll
inline mat4 mat4_rotation_yaw_pitch_roll(float yaw, float pitch, float roll) {
    const float sy = std::sin(yaw);
    const float cy = std::cos(yaw);
    const float sp = std::sin(pitch);
    const float cp = std::cos(pitch);
    const float sr = std::sin(roll);
    const float cr = std::cos(roll);    

    mat4 out(
        sr*sp*sy + cr*cy,   sr*cp,              sr*sp*cy - cr*sy,   scast<float>(0.0),
        cr*sp*sy - sr*cy,   cr*cp,              cr*sp*cy + sr*sy,   scast<float>(0.0),
        cp*sy,              -sp,                cp*cy,              scast<float>(0.0),
        scast<float>(0.0),  scast<float>(0.0),  scast<float>(0.0),  scast<float>(1.0)
    );

    return out;
}

// Compute a quaternian's axis and angle of rotation. Expects unit quaternions.
//D3DXQuaternionToAxisAngle
inline void quat_to_axis_angle(const quat& unit_quat, vec3& axis, float& angle) {
    axis = unit_quat.axis;
    angle = scast<float>(2.0) * std::acos(unit_quat.rotation);
}


//D3DXQuaternionRotationMatrix
// winnumerics
// Build a quaternion from a rotation matrix.
// same as quat_from_rotation_mat4
//inline quat make_quaternion_from_rotation_matrix(const mat4& ma)
inline quat quat_rotation_mat4(const mat4& ma) {
    if (ma.r[0][0] + ma.r[1][1] + ma.r[2][2] > scast<float>(0.0)) {
        float s = sqrtf(scast<float>(1.0) + ma.r[0][0] + ma.r[1][1] + ma.r[2][2]);
        float inv_s = scast<float>(0.5) / s;

        return quat((ma.r[1][2] - ma.r[2][1]) * inv_s,
                    (ma.r[2][0] - ma.r[0][2]) * inv_s,
                    (ma.r[0][1] - ma.r[1][0]) * inv_s,
                    s * scast<float>(0.5));

    } else if (ma.r[0][0] >= ma.r[1][1] && ma.r[0][0] >= ma.r[2][2]) {
        float s = sqrtf(scast<float>(1.0) + ma.r[0][0] - ma.r[1][1] - ma.r[2][2]);
        float inv_s = scast<float>(0.5) / s;

        return quat(scast<float>(0.5) * s,
                    (ma.r[0][1] + ma.r[1][0]) * inv_s,
                    (ma.r[0][2] + ma.r[2][0]) * inv_s,
                    (ma.r[1][2] - ma.r[2][1]) * inv_s);

    } else if (ma.r[1][1] > ma.r[2][2]) {
        float s = sqrtf(scast<float>(1.0) + ma.r[1][1] - ma.r[0][0] - ma.r[2][2]);
        float inv_s = scast<float>(0.5) / s;

        return quat((ma.r[1][0] + ma.r[0][1]) * inv_s,
                    scast<float>(0.5) * s,
                    (ma.r[2][1] + ma.r[1][2]) * inv_s,
                    (ma.r[2][0] - ma.r[0][2]) * inv_s);

    } else {
        float s = sqrtf(scast<float>(1.0) + ma.r[2][2] - ma.r[0][0] - ma.r[1][1]);
        float inv_s = scast<float>(0.5) / s;

        return quat((ma.r[2][0] + ma.r[0][2]) * inv_s,
                    (ma.r[2][1] + ma.r[1][2]) * inv_s,
                    scast<float>(0.5) * s,
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

    const float epsilon = scast<float>(1e-6);
    
    float cos_omega = quat_dot(a, b);
    bool flip = false;
        
    // Make sure we use the short rotation
    if (cos_omega < scast<float>(0.0)) {
        flip = true;
        cos_omega = -cos_omega;
    }

    float s1 = 0.0, s2 = 0.0;
        
    if (cos_omega > (scast<float>(1.0) - epsilon)) {
        // Too close, do straight linear interpolation.
        s1 = scast<float>(1.0) - t;
        s2 = flip ? -t : t;
    } else {
        // spherical interpolation
        float omega = std::acos(cos_omega);
        float inv_sin_omega = scast<float>(1.0) / std::sin(omega);

        s1 = std::sin((scast<float>(1.0) - t) * omega) * inv_sin_omega;
        s2 = flip ? -std::sin(t * omega) * inv_sin_omega
                  :  std::sin(t * omega) * inv_sin_omega;
    }

    quat out = quat::k_zero();
    for_range (i, 0, quat::size()) {
        out[i] = s1 * a[i] + s2 * b[i];
    }
    return out;
}

//----------
// Rotation about arbitrary axis.
//D3DXQuaternionRotationAxis
inline quat quat_from_rotation_axis(const vec3& a, float angle) {    
    quat out = quat::k_zero();
    vec3 temp = vec3_normalize(a);
    float half_angle = angle * scast<float>(0.5);
    const float sha = std::sin(half_angle);
    const float cha = std::cos(half_angle);
    out.axis = sha * temp;
    out.rotation = cha;
    return out;
}


// Yaw around the Y axis, Pitch around the X axis, Roll around the Z axis.
//D3DXQuaternionRotationYawPitchRoll
inline quat quat_rotation_yaw_pitch_roll(float yaw, float pitch, float roll) {
    quat out = quat::k_zero();

    // Roll first, about axis the object is facing, then pitch upward, then yaw to face into the new heading
    float half_yaw = yaw * scast<float>(0.5);
    float sy = std::sin(half_yaw); 
    float cy = std::cos(half_yaw);
    float half_pitch = pitch * scast<float>(0.5);
    float sp = std::sin(half_pitch); 
    float cp = std::cos(half_pitch);
    float half_roll = roll * scast<float>(0.5);
    float sr = std::sin(half_roll); 
    float cr = std::cos(half_roll);

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
    quat out = quat::k_zero();
    float tf = 0.0;

    if ((a.w >= scast<float>(1.0)) || (a.w == -scast<float>(1.0))) {
        tf = scast<float>(1.0);
    } else {
        tf = std::acos(a.w) / std::sqrt(scast<float>(1.0) - mf::square(a.w));
    }

    out.axis = tf * a.axis;
    out.rotation = scast<float>(0.0);

    return out;
}

// Expects pure quaternions. (w == 0)  w is ignored in calculation.
// if q = (0, theta * a); exp(q) = (cos(theta), sin(theta) * a)
//D3DXQuaternionExp
inline quat quat_exp(const quat& a) {
    quat out = quat::k_identity();

    // only first 3 members used
    float norm = std::sqrt(mf::square(a.x) + mf::square(a.y) + mf::square(a.z));    

    if (norm) {
        float inv_norm = scast<float>(1.0)/norm;
        float snorm = std::sin(norm);
        float cnorm = std::cos(norm);

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
    quat out = quat::k_zero();
    quat temp1 = quat_slerp(pq1, pqc, s);
    quat temp2 = quat_slerp(pqa, pqb, s);
    out = quat_slerp(temp1, temp2, scast<float>(2.0)*s * (scast<float>(1.0) - s));
    return out;
}

// Setup control points for spherical quadrangle interpolation from Q1 to Q2.  
// The control points are chosen in such a way to ensure the continuity of tangents with adjacent segments.
//D3DXQuaternionSquadSetup
inline void quat_squad_setup(quat& aout, quat& bout, quat& cout, const quat& pq0, const quat& pq1, const quat& pq2, const quat& pq3) {
    quat q = quat::k_zero();
    quat temp1 = quat::k_zero();
    quat temp2 = quat::k_zero();
    quat temp3 = quat::k_zero();
    quat tzero = quat::k_zero();


    if (quat_dot(pq0, pq1) < scast<float>(0.0)) {
        temp2 = quat_mul_angles(tzero, pq0, -scast<float>(1.0));
    } else {
        temp2 = pq0;
    }

    if (quat_dot(pq1, pq2) < scast<float>(0.0)) {
        cout = quat_mul_angles(tzero, pq2, -scast<float>(1.0));
    } else {
        cout = pq2;
    }

    if (quat_dot(cout, pq3) < scast<float>(0.0)) {
        temp3 = quat_mul_angles(tzero, pq3, -scast<float>(1.0));
    } else {
        temp3 = pq3;
    }

    temp1 = quat_inverse(pq1);
    temp2 = quat_ln(temp1 * temp2);
    q = quat_ln(temp1 * cout);
    temp1 = quat_mul_angles(temp2, q, scast<float>(1.0));
    temp1 = temp1 * (-scast<float>(0.25));
    aout = pq1 * quat_exp(temp1);

    temp1 = quat_inverse(cout);
    temp2 = quat_ln(temp1 * pq1);
    q = quat_ln(temp1 * temp3);
    temp1 = quat_mul_angles(temp2, q, scast<float>(1.0));
    temp1 = temp1 * (-scast<float>(0.25));
    bout = cout * quat_exp(temp1);           
}


// Barycentric interpolation.
// Slerp(Slerp(Q1, Q2, f+g), Slerp(Q1, Q3, f+g), g/(f+g))
//D3DXQuaternionBaryCentric
inline quat quat_bary_centric(const quat& pq1, const quat& pq2, const quat& pq3, float f, float g) {
    quat out = quat::k_zero();
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
    mat4 out = mat4::k_identity();

    mat4 m1 = mat4::k_identity();
    mat4 m2 = mat4::k_identity();
    mat4 m3 = mat4::k_identity(); 
    mat4 m4 = mat4::k_identity(); 
    mat4 m5 = mat4::k_identity(); 
    mat4 m6 = mat4::k_identity(); 
    mat4 m7 = mat4::k_identity();

    quat qrc = quat::k_identity();
    vec3 vsc = vec3::k_zero();
    vec3 vtr = vec3::k_zero();

    if (pscalingcenter) {
        vsc = *pscalingcenter;
    } else {
        vsc = vec3::k_zero();
    }

    if (protationcenter) {
        qrc = quat(*protationcenter, scast<float>(1.0));
    } else {
        qrc = quat::k_identity();       
    }

    if (ptranslation) {
        vtr = *ptranslation;
    } else {
        vtr = vec3::k_zero();        
    }

    m1 = mat4_translation(-vsc);

    if (pscalingrotation) {
        m4 = mat4_rotation_quat(*pscalingrotation);
        m2 = mat4_inverse(m4);        
    } else {        
        m4 = mat4::k_identity();
        m2 = mat4::k_identity();
    }

    if (pscaling) { 
        m3 = mat4_scaling(*pscaling);        
    } else {
        m3 = mat4::k_identity();
    }

    if (protation) { 
        m6 = mat4_rotation_quat(*protation);        
    } else {
        m6 = mat4::k_identity();
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
    mat4 out = mat4::k_identity();

    quat qrot = quat::k_zero(); 
    quat qsrot = quat::k_zero();

    vec3 vs = k_vec3_one();

    vec3 vrc = vec3::k_zero();    
    vec3 vsc = vec3::k_zero();
    vec3 vt = vec3::k_zero();

    if (pscalingcenter) {
        vsc = vec3_from_vec2(*pscalingcenter, scast<float>(0.0));
    } else {
        vsc = vec3::k_zero();
    }

    if (pscaling) {
        vs = vec3_from_vec2(*pscaling, scast<float>(1.0));
    } else {
        vs = k_vec3_one();
    }

    if (protationcenter) {
        vrc = vec3_from_vec2(*protationcenter, scast<float>(0.0));
    } else {
        vrc = vec3::k_zero();
    }

    if (ptranslation) {
        vt = vec3_from_vec2(*ptranslation, scast<float>(0.0));
    } else {
        vt = vec3::k_zero();
    }

    
    const float hrot = rotation * scast<float>(0.5);
    const float hsrot = scalingrotation * scast<float>(0.5);

    qrot.x = scast<float>(0.0);
    qrot.y = scast<float>(0.0);
    qrot.z = std::sin(hrot);
    qrot.w = std::cos(hrot);

    
    qsrot.x = scast<float>(0.0);
    qsrot.y = scast<float>(0.0);
    qsrot.z = std::sin(hsrot);
    qsrot.w = std::cos(hsrot);

    out = mat4_transformation_ptr(&vsc, &qsrot, &vs, &vrc, &qrot, &vt);

    return out;
}

// Build affine transformation matrix.
// Mout = Ms * Mrc-1 * Mr * Mrc * Mt
//D3DXMatrixAffineTransformation
inline mat4 mat4_affine_transformation_ptr(float scaling, const vec3 *rotationcenter, const quat *rotation, const vec3 *translation) {

    mat4 out = mat4::k_identity();

    if (rotation) {
        float temp00 = 0.0f, temp01 = 0.0f, temp02 = 0.0f, temp10 = 0.0f, temp11 = 0.0f, temp12 = 0.0f, temp20 = 0.0f, temp21 = 0.0f, temp22 = 0.0f;

        temp00 = scast<float>(1.0) - scast<float>(2.0) * (rotation->y * rotation->y + rotation->z * rotation->z);
        temp01 = scast<float>(2.0) * (rotation->x * rotation->y + rotation->z * rotation->w);
        temp02 = scast<float>(2.0) * (rotation->x * rotation->z - rotation->y * rotation->w);
        temp10 = scast<float>(2.0) * (rotation->x * rotation->y - rotation->z * rotation->w);
        temp11 = scast<float>(1.0) - scast<float>(2.0) * (rotation->x * rotation->x + rotation->z * rotation->z);
        temp12 = scast<float>(2.0) * (rotation->y * rotation->z + rotation->x * rotation->w);
        temp20 = scast<float>(2.0) * (rotation->x * rotation->z + rotation->y * rotation->w);
        temp21 = scast<float>(2.0) * (rotation->y * rotation->z - rotation->x * rotation->w);
        temp22 = scast<float>(1.0) - scast<float>(2.0) * (rotation->x * rotation->x + rotation->y * rotation->y);

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
            out.r[3][0] = rotationcenter->x * (scast<float>(1.0) - temp00) - rotationcenter->y * temp10 - rotationcenter->z * temp20;
            out.r[3][1] = rotationcenter->y * (scast<float>(1.0) - temp11) - rotationcenter->x * temp01 - rotationcenter->z * temp21;
            out.r[3][2] = rotationcenter->z * (scast<float>(1.0) - temp22) - rotationcenter->x * temp02 - rotationcenter->y * temp12;
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
    mat4 out = mat4::k_identity();

    float half_rotation = rotation * scast<float>(0.5);
    const float s = std::sin(half_rotation);
    const float tmp1 = scast<float>(1.0) - scast<float>(2.0)*s*s;
    const float tmp2 = scast<float>(2.0) * s * std::cos(half_rotation);
    
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
//UNCHECKED







}