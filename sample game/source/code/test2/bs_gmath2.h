#pragma once

#pragma once

#include "bs_gmath.h"



//========================================================================================================================
//The Vec2Hermite function interpolates from (positionA, tangentA) to (positionB, tangentB) using Hermite spline interpolation.
//The spline interpolation is a generalization of the ease-in, ease-out spline. The ramp is a function of Q(s) with the following properties.
//Q(s) = As3 + Bs2 + Cs + D (and therefore, Q'(s) = 3As2 + 2Bs + C)
//a) Q(0) = v1, so Q'(0) = t1
//b) Q(1) = v2, so Q'(1) = t2
//v1 is the contents of pV1, v2 in the contents of pV2, t1 is the contents of pT1, and t2 is the contents of pT2.
//These properties are used to solve for A, B, C, D.
//Q(s) = (2s3 - 3s2 + 1)v1 + (-2s3 + 3s2)v2 + (s3 - 2s2 + s)t1 + (s3 - s2)t2
//Hermite splines are useful for controlling animation because the curve runs through all the control points. Also, because 
//the position and tangent are explicitly specified at the ends of each segment, it is easy to create a C2 continuous curve 
//as long as you make sure that your starting position and tangent match the ending values of the last segment.
// v - end points
// t - tangent directions at end points
// s (alpha) - distance along spline
// cubic interpolation
// Hermite interpolation between position V1, tangent T1 (when s == 0) and position V2, tangent T2 (when s == 1).
inline vec3 vec3_hermite(const vec3& v1, const vec3& t1, const vec3& v2, const vec3& t2, float s) {
    vec3 out = vec3::k_zero(); 
    float h1, h2, h3, h4;
    //set_hermite_coeffcients(h1, h2, h3, h4, s);
    float s3 = s*s*s;
	float s2 = s*s;

    //h1 = (2.0f * s*s*s) - (3.0f * s*s) + 1.0f;
    //h2 = (s*s*s) - (2.0f * s*s) + s;
    //h3 = (-2.0f * s*s*s) + (3.0f * s*s);
    //h4 = (s*s*s) - (s*s);

    h1 = (static_cast<float>(2.0) * s3) - (static_cast<float>(3.0) * s2) + static_cast<float>(1.0);
    h2 = (s3) - (static_cast<float>(2.0) * s2) + s;
    h3 = (-static_cast<float>(2.0) * s3) + (static_cast<float>(3.0) * s2);
    h4 = (s3) - (s2);    

    for (int i=0; i < vec3::size(); ++i) { out[i] = h1 * v1[i] + h2 * t1[i] + h3 * v2[i] + h4 * t2[i]; }

    return out;
}

//Given four points (p1, p2, p3, p4), find a function Q(s) such that:
//Q(s) is a cubic function.
//Q(s) interpolates between p2 and p3 as s ranges from 0 to 1.
//Q(s) is parallel to the line joining p1 to p3 when s is 0.
//Q(s) is parallel to the line joining p2 to p4 when s is 1.
//The Catmull-Rom spline can be derived from the Hermite spline by setting:
//Q(s) = [(-s3 + 2s2 - s)p1 + (3s3 - 5s2 + 2)p2 + (-3s3 + 4s2 + s)p3 + (s3 - s2)p4] / 2
// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
inline vec3 vec3_catmull_rom(const vec3& v0, const vec3& v1, const vec3& v2, const vec3& v3, float s) {
    vec3 out = vec3::k_zero(); 
    float s3 = s*s*s;
	float s2 = s*s;

    for (int i=0; i < vec3::size(); ++i) {
        out[i] = static_cast<float>(0.5) * (static_cast<float>(2.0) * v1[i] + (v2[i] - v0[i]) * s 
            + (static_cast<float>(2.0) * v0[i] - static_cast<float>(5.0) * v1[i] + static_cast<float>(4.0) * v2[i] - v3[i]) * s2 
            + (v3[i] -static_cast<float>(3.0) * v2[i] + static_cast<float>(3.0) * v1[i] - v0[i]) * s3);

        // From formula
        //out[i] = ( (-s3 + static_cast<float>(2.0)*s2 - s)*v0[i] + (static_cast<float>(3.0)*s3 - static_cast<float>(5.0)*s2 + static_cast<float>(2.0))*v1[i] 
        //    + (-static_cast<float>(3.0)*s3 + static_cast<float>(4.0)*s2 + s)*v2[i] + (s3 - s2)*v3[i] ) * static_cast<float>(0.5);
    }

    return out;
}

//The Vec2BaryCentric function provides a way to understand points in and around a triangle, independent of where the triangle is actually located. 
//This function returns the resulting point by using the following equation: V1 + f(V2-V1) + g(V3-V1).
//Any point in the plane V1V2V3 can be represented by the Barycentric coordinate (f,g).The parameter f controls how much V2 gets weighted 
//into the result, and the parameter g controls how much V3 gets weighted into the result. Lastly, 1-f-g controls how much V1 gets weighted into the result.
//Note the following relations.
//    If (f>=0 &, & g>=0 &, & 1-f-g>=0), the point is inside the triangle V1V2V3.
//    If (f==0 &, & g>=0 &, & 1-f-g>=0), the point is on the line V1V3.
//    If (f>=0 &, & g==0 &, & 1-f-g>=0), the point is on the line V1V2.
//    If (f>=0 &, & g>=0 &, & 1-f-g==0), the point is on the line V2V3.
//Barycentric coordinates define a point inside a triangle in terms of the triangle's vertices.
// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
inline vec3 vec3_bary_centric(const vec3& v1, const vec3& v2, const vec3& v3, float f, float g) {
    vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = (static_cast<float>(1.0)-f-g) * v1[i] + f * v2[i] + g * v3[i]; } return out;
}


//----------------
// vec transform
//----------------

// Transform the vector V (x, y, 0, 1) by matrix M, project result back into w=1.
//D3DXVec2TransformCoord
inline vec2 vec2_transform_coord(const vec2& a, const mat4& ma) {	
    float norm = ma.r[0][3] * a.x + ma.r[1][3] * a.y + ma.r[3][3];
	float inv_norm = static_cast<float>(1.0)/norm;

	return vec2(
		(ma.r[0][0] * a.x + ma.r[1][0] * a.y + ma.r[3][0]) * inv_norm,
		(ma.r[0][1] * a.x + ma.r[1][1] * a.y + ma.r[3][1]) * inv_norm
	);
} 

// Transform the vector V (x, y, 0, 0) by matrix M.
// If you want to transform a normal, the matrix you pass to this function should be 
// the transpose of the inverse of the matrix you would use to transform a point.
//D3DXVec2TransformNormal
inline vec2 vec2_transform_normal(const vec2& a, const mat4& ma) {
	return vec2(
		ma.r[0][0] * a.x + ma.r[1][0] * a.y,
		ma.r[0][1] * a.x + ma.r[1][1] * a.y
    );
}   


//--------------------------------------
//vec3_transform_coord

// Transform the vector V (x, y, z, 0) by matrix M. 
// If you want to transform a normal by a non-affine matrix, the matrix you pass to this function 
// should be the transpose of the inverse of the matrix you would use to transform a point(coord).
//D3DXVec3TransformNormal
inline vec3 vec3_transform_normal(const vec3& a, const mat4& ma) {
	return vec3(
		ma.r[0][0] * a.x + ma.r[1][0] * a.y + ma.r[2][0] * a.z,
		ma.r[0][1] * a.x + ma.r[1][1] * a.y + ma.r[2][1] * a.z,
		ma.r[0][2] * a.x + ma.r[1][2] * a.y + ma.r[2][2] * a.z
    );
}


//--------------------------------------
// Transform the vector V (x, y, 0, 1) by matrix M.
//D3DXVec2Transform
inline vec4 vec4_transform_pos2(const vec2& a, const mat4& ma) {
	return vec4(
		ma.r[0][0] * a.x + ma.r[1][0] * a.y  + ma.r[3][0],
		ma.r[0][1] * a.x + ma.r[1][1] * a.y  + ma.r[3][1],
		ma.r[0][2] * a.x + ma.r[1][2] * a.y  + ma.r[3][2],
		ma.r[0][3] * a.x + ma.r[1][3] * a.y  + ma.r[3][3]
    );
}

// Transform the vector V (x, y, z, 1) by matrix M.
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


//--------------------------------------------------
// Cross-product in 4 dimensions.
inline vec4 vec4_cross(const vec4& a, const vec4& b, const vec4& c) {
    vec4 out = vec4::k_zero();
    out.x = a.y * (b.z * c.w - c.z * b.w) - a.z * (b.y * c.w - c.y * b.w) + a.w * (b.y * c.z - b.z *c.y);
    out.y = -(a.x * (b.z * c.w - c.z * b.w) - a.z * (b.x * c.w - c.x * b.w) + a.w * (b.x * c.z - c.x * b.z));
    out.z = a.x * (b.y * c.w - c.y * b.w) - a.y * (b.x *c.w - c.x * b.w) + a.w * (b.x * c.y - c.x * b.y);
    out.w = -(a.x * (b.y * c.z - c.y * b.z) - a.y * (b.x * c.z - c.x *b.z) + a.z * (b.x * c.y - c.x * b.y));
    return out;
}


//==========================================================================================

// Convert Direct3D projection to OpenGL 
// Convert Direct3D projection matrix to an OpenGL one by applying a Z scale of 2 and a translation of -1. 
// This will make [0,+1] to [-1,+1].
//glMatrixMode(GL_PROJECTION); 
//glLoadMatrixf(&d3d_projection_matrix); 
//glScalef(1, 1, 2); 
//glTranslatef(0, 0, -1);


// Matrix multiplication, followed by a transpose. (result = T(M1 * M2))
inline mat4 mat4_mul_transpose(const mat4& ma, const mat4& mb) {
	return mat4_transpose(ma * mb);
}

//----------------------

// The MatrixShadow function flattens geometry into a plane, as if casting a shadow from a light.
// If the light's w-component is 0, the ray from the origin to the light represents a directional light. If it is 1, the light is a point light.
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
// Formula from d3dx9 docs is different from D3DXMatrixShadow (-ve of D3DXMatrixShadow). Return -ve of formula result.
//D3DXMatrixShadow
inline mat4 mat4_shadow(const vec4& light, const plane& pa) {
    const vec4& l = light;
    const plane pn = plane_normalize(pa);  
    const float dot = plane_dot(pn, l);

    const plane p = -pn;

    return mat4(
        p.a*l.x + dot, p.a*l.y,       p.a*l.z,       p.a*l.w,
        p.b*l.x,       p.b*l.y + dot, p.b*l.z,       p.b*l.w,
        p.c*l.x,       p.c*l.y,       p.c*l.z + dot, p.c*l.w,
        p.d*l.x,       p.d*l.y,       p.d*l.z,       p.d*l.w + dot
    );
}


// The MatrixReflect function normalizes the plane equation before it creates the reflected matrix.
// P = normalize(Plane);
//
//-2 * P.a * P.a + 1  -2 * P.b * P.a      -2 * P.c * P.a        0
//-2 * P.a * P.b      -2 * P.b * P.b + 1  -2 * P.c * P.b        0
//-2 * P.a * P.c      -2 * P.b * P.c      -2 * P.c * P.c + 1    0
//-2 * P.a * P.d      -2 * P.b * P.d      -2 * P.c * P.d        1
// Build a matrix which reflects the coordinate system about a plane
//D3DXMatrixReflect
inline mat4 mat4_reflect(const plane& pa) {
    plane p = plane_normalize(pa);     

    return mat4(
        -static_cast<float>(2.0)*p.a*p.a + static_cast<float>(1.0), -static_cast<float>(2.0)*p.b*p.a,   -static_cast<float>(2.0)*p.c*p.a,           static_cast<float>(0.0),
        -static_cast<float>(2.0)*p.a*p.b,   -static_cast<float>(2.0)*p.b*p.b + static_cast<float>(1.0), -static_cast<float>(2.0)*p.c*p.b,           static_cast<float>(0.0),
        -static_cast<float>(2.0)*p.a*p.c,   -static_cast<float>(2.0)*p.b*p.c,           -static_cast<float>(2.0)*p.c*p.c + static_cast<float>(1.0), static_cast<float>(0.0),
        -static_cast<float>(2.0)*p.a*p.d,   -static_cast<float>(2.0)*p.b*p.d,                           -static_cast<float>(2.0)*p.c*p.d,           static_cast<float>(1.0)
    );
}


//--------------------------------------------
// Perspective Matrices d3dx9
//--------------------------------------------
//-----------
// All the parameters of the D3DXMatrixPerspectiveLH (and other Perspective Matrices) function are distances in camera space. 
// The parameters describe the dimensions of the view volume.
//2*n/w   0       0          0
//0       2*n/h   0          0
//0       0       f/(f-n)    1
//0       0       n*f/(n-f)  0
//D3DXMatrixPerspectiveLH
inline mat4 mat4_perspective_lh(float w, float h, float n, float f) {
    return mat4(
        static_cast<float>(2.0)*n/w,      static_cast<float>(0.0),		    static_cast<float>(0.0),  static_cast<float>(0.0), 
        static_cast<float>(0.0),		  static_cast<float>(2.0)*n/h,      static_cast<float>(0.0),  static_cast<float>(0.0), 
        static_cast<float>(0.0),		  static_cast<float>(0.0),		    f/(f-n),		          static_cast<float>(1.0), 
        static_cast<float>(0.0),		  static_cast<float>(0.0),		    (n*f)/(n-f),              static_cast<float>(0.0)
	);    
}


//2*n/w   0       0           0
//0       2*n/h   0           0
//0       0       f/(n-f)    -1
//0       0       n*f/(n-f)   0
//D3DXMatrixPerspectiveRH
inline mat4 mat4_perspective_rh(float w, float h, float n, float f) {
    return mat4(
        static_cast<float>(2.0)*n/w,      static_cast<float>(0.0),		  static_cast<float>(0.0),  static_cast<float>(0.0), 
        static_cast<float>(0.0),		  static_cast<float>(2.0)*n/h,    static_cast<float>(0.0),  static_cast<float>(0.0), 
        static_cast<float>(0.0),		  static_cast<float>(0.0),		  f/(n-f),		            -static_cast<float>(1.0), 
        static_cast<float>(0.0),		  static_cast<float>(0.0),		  (n*f)/(n-f),              static_cast<float>(0.0)
	);    
}


//-----------
//2*n/(r-l)    0            0           0
//0            2*n/(t-b)    0           0
//(l+r)/(l-r)  (t+b)/(b-t)  f/(f-n)     1
//0            0            n*f/(n-f)   0
//D3DXMatrixPerspectiveOffCenterLH
//inline mat4 mat4_perspective_offcenter_lh(float l, float r, float b, float t, float n, float f) {
//    return mat4(
//        static_cast<float>(2.0)*n/(r-l), static_cast<float>(0.0),										            static_cast<float>(0.0),	static_cast<float>(0.0), 
//        static_cast<float>(0.0),		   -static_cast<float>(2.0)*n/(b-t),							            static_cast<float>(0.0),	static_cast<float>(0.0), 
//        -static_cast<float>(1.0) - static_cast<float>(2.0) * l/(r-l), static_cast<float>(1.0) + static_cast<float>(2.0) * t/(b-t), -f/(n-f),	static_cast<float>(1.0), 
//        static_cast<float>(0.0),		   static_cast<float>(0.0),											        (n*f)/(n-f),                static_cast<float>(0.0)
//	);    
//}
inline mat4 mat4_perspective_offcenter_lh(float l, float r, float b, float t, float n, float f) {
    return mat4(
        static_cast<float>(2.0)*n/(r-l),    static_cast<float>(0.0),            static_cast<float>(0.0),    static_cast<float>(0.0),
        static_cast<float>(0.0),            static_cast<float>(2.0)*n/(t-b),    static_cast<float>(0.0),    static_cast<float>(0.0),
        (l+r)/(l-r),                        (t+b)/(b-t),                        f/(f-n),                    static_cast<float>(1.0),
        static_cast<float>(0.0),            static_cast<float>(0.0),            (n*f)/(n-f),                static_cast<float>(0.0)
	);    
}


//2*n/(r-l)    0            0            0
//0            2*n/(t-b)    0            0
//(l+r)/(r-l)  (t+b)/(t-b)  f/(n-f)      -1
//0            0            n*f/(n-f)    0
//D3DXMatrixPerspectiveOffCenterRH
//inline mat4 mat4_perspective_offcenter_rh(float l, float r, float b, float t, float n, float f) {
//    return mat4(
//        static_cast<float>(2.0)*n/(r-l), static_cast<float>(0.0),										          static_cast<float>(0.0),  static_cast<float>(0.0), 
//        static_cast<float>(0.0),		   -static_cast<float>(2.0)*n/(b-t),								      static_cast<float>(0.0),  static_cast<float>(0.0), 
//        static_cast<float>(1.0) + static_cast<float>(2.0) * l/(r-l), -static_cast<float>(1.0) -static_cast<float>(2.0) * t/(b-t), f/(n-f),  -static_cast<float>(1.0), 
//        static_cast<float>(0.0),		   static_cast<float>(0.0),											      (n*f)/(n-f),              static_cast<float>(0.0)
//	);    
//}
inline mat4 mat4_perspective_offcenter_rh(float l, float r, float b, float t, float n, float f) {
    return mat4(
        static_cast<float>(2.0)*n/(r-l),    static_cast<float>(0.0),            static_cast<float>(0.0),    static_cast<float>(0.0),
        static_cast<float>(0.0),            static_cast<float>(2.0)*n/(t-b),    static_cast<float>(0.0),    static_cast<float>(0.0),
        (l+r)/(r-l),                        (t+b)/(t-b),                        f/(n-f),                    -static_cast<float>(1.0),
        static_cast<float>(0.0),            static_cast<float>(0.0),            n*f/(n-f),                  static_cast<float>(0.0)
	);    
}

//-----------
//2/(r-l)      0            0        0
//0            2/(t-b)      0        0
//0            0            1/(f-n)  0
//(l+r)/(l-r)  (t+b)/(b-t)  n/(n-f)  1
//D3DXMatrixOrthoOffCenterLH
//inline mat4 mat4_ortho_offcenter_lh(float l, float r, float b, float t, float n, float f) {
//    return mat4(
//        static_cast<float>(2.0)/(r-l),					static_cast<float>(0.0),			static_cast<float>(0.0),		    static_cast<float>(0.0), 
//        static_cast<float>(0.0),						static_cast<float>(2.0)/(t-b),		static_cast<float>(0.0),		    static_cast<float>(0.0), 
//        static_cast<float>(0.0),						static_cast<float>(0.0),			static_cast<float>(1.0)/(f-n),      static_cast<float>(0.0), 
//        -static_cast<float>(1.0) - static_cast<float>(2.0) * l/(r-l), static_cast<float>(1.0) + static_cast<float>(2.0) * t/(b-t), n/(n-f), static_cast<float>(1.0)
//	);    
//}
inline mat4 mat4_ortho_offcenter_lh(float l, float r, float b, float t, float n, float f) {
    return mat4(
        static_cast<float>(2.0)/(r-l),      static_cast<float>(0.0),            static_cast<float>(0.0),        static_cast<float>(0.0),
        static_cast<float>(0.0),            static_cast<float>(2.0)/(t-b),      static_cast<float>(0.0),        static_cast<float>(0.0),
        static_cast<float>(0.0),            static_cast<float>(0.0),            static_cast<float>(1.0)/(f-n),  static_cast<float>(0.0),
        (l+r)/(l-r),                        (t+b)/(b-t),                        n/(n-f),                        static_cast<float>(1.0)
	);    
}


//2/(r-l)      0            0        0
//0            2/(t-b)      0        0
//0            0            1/(n-f)  0
//(l+r)/(l-r)  (t+b)/(b-t)  n/(n-f)  1
//D3DXMatrixOrthoOffCenterRH
//inline mat4 mat4_ortho_offcenter_rh(float l, float r, float b, float t, float n, float f) {
//    return mat4(
//        static_cast<float>(2.0)/(r-l),				    static_cast<float>(0.0),				static_cast<float>(0.0),		    static_cast<float>(0.0), 
//        static_cast<float>(0.0),						static_cast<float>(2.0)/(t-b),			static_cast<float>(0.0),		    static_cast<float>(0.0), 
//        static_cast<float>(0.0),						static_cast<float>(0.0),				static_cast<float>(1.0)/(n-f),      static_cast<float>(0.0), 
//        -static_cast<float>(1.0) - static_cast<float>(2.0) * l/(r-l), static_cast<float>(1.0) + static_cast<float>(2.0) * t/(b-t), n/(n-f),	static_cast<float>(1.0)
//	);    
//}
inline mat4 mat4_ortho_offcenter_rh(float l, float r, float b, float t, float n, float f) {
    return mat4(
        static_cast<float>(2.0)/(r-l),      static_cast<float>(0.0),            static_cast<float>(0.0),        static_cast<float>(0.0),
        static_cast<float>(0.0),            static_cast<float>(2.0)/(t-b),      static_cast<float>(0.0),        static_cast<float>(0.0),
        static_cast<float>(0.0),            static_cast<float>(0.0),            static_cast<float>(1.0)/(n-f),  static_cast<float>(0.0),
        (l+r)/(l-r),                        (t+b)/(b-t),                        n/(n-f),                        static_cast<float>(1.0)
	);    
}

//-----------
// The D3DXMatrixOrthoLH function is a special case of the D3DXMatrixOrthoOffCenterLH function. 
// To create the same projection using D3DXMatrixOrthoOffCenterLH, use the following values: 
// l = -w/2, r = w/2, b = -h/2, and t = h/2.
//
//2/w  0    0        0
//0    2/h  0        0
//0    0    1/(f-n)  0
//0    0   -n/(f-n)  1
//D3DXMatrixOrthoLH
inline mat4 mat4_ortho_lh(float w, float h, float n, float f) {
    return mat4(
        static_cast<float>(2.0)/w, static_cast<float>(0.0),   static_cast<float>(0.0),		  static_cast<float>(0.0), 
        static_cast<float>(0.0),   static_cast<float>(2.0)/h, static_cast<float>(0.0),		  static_cast<float>(0.0), 
        static_cast<float>(0.0),   static_cast<float>(0.0),   static_cast<float>(1.0)/(f-n),  static_cast<float>(0.0), 
        static_cast<float>(0.0),   static_cast<float>(0.0),   n/(n-f),			              static_cast<float>(1.0)
    );
}


// The D3DXMatrixOrthoRH function is a special case of the D3DXMatrixOrthoOffCenterRH function. 
// To create the same projection using D3DXMatrixOrthoOffCenterRH, use the following values: 
// l = -w/2, r = w/2, b = -h/2, and t = h/2.
//
//2/w  0    0        0
//0    2/h  0        0
//0    0    1/(n-f)  0
//0    0    n/(n-f)  1
//D3DXMatrixOrthoRH
inline mat4 mat4_ortho_rh(float w, float h, float n, float f) {
    return mat4(
        static_cast<float>(2.0)/w, static_cast<float>(0.0),   static_cast<float>(0.0),		  static_cast<float>(0.0), 
        static_cast<float>(0.0),   static_cast<float>(2.0)/h, static_cast<float>(0.0),		  static_cast<float>(0.0), 
        static_cast<float>(0.0),   static_cast<float>(0.0),   static_cast<float>(1.0)/(n-f),  static_cast<float>(0.0), 
        static_cast<float>(0.0),   static_cast<float>(0.0),   n/(n-f),			              static_cast<float>(1.0)
	);    
}

//-----------------------------------------------
//-----------------------------------------------
// Find the intersection between a plane and a line. If the line is parallel to the plane, NULL is returned.
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

    for (int i=0; i<vec3::size(); ++i) {
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
    vec3 normal = vec3_cross(edge1, edge2);
    vec3 normalized = vec3_normalize(normal);

    //return plane_from_point_normal(pt1, normalized);
    float d = -vec3_dot(pt1, normalized);
    return plane(normalized, d);
}


// Transform a plane by a matrix. The vector (a,b,c) must be normal.
// M should be the inverse transpose of the matrix of transformation desired.
//D3DXPlaneTransform
//inline plane plane_transform_mat4_inverse_transposed(const plane& p, const mat4& ma) {
//    return plane(vec4_transform_pos4(p.v, ma));
//}    

inline plane plane_transform_mat4(const plane& p, const mat4& ma) {
    mat4 inverse_matrix = mat4_inverse(ma);
    return plane(vec4_transform_pos4(p.v, mat4_transpose(inverse_matrix)));
}

//----------------------
// (-x, -y, -z, w)
inline quat quat_conjugate(const quat& a) { 
    //return quat(-a.x, -a.y, -a.z, a.w); 
    return quat(-a.axis, a.rotation);
}


// Conjugate and re-norm
inline quat quat_inverse(const quat& a) {
    //float inv_norm = static_cast<float>(1.0)/quat_length_sq(a);
    //return (quat_conjugate(a) * inv_norm);    

    quat out = quat::k_zero();

    float norm = quat_length_sq(a);
    float inv_norm = static_cast<float>(1.0)/norm;

    out.axis = -a.axis * inv_norm;
    out.rotation = a.rotation * inv_norm;

    return out;    
}


inline bool quat_is_identity(const quat& a) { return (a == quat::k_identity()); }



//----------------------------------------
// Build a matrix from a quaternion
//mat4_from_quaternion
//D3DXMatrixRotationQuaternion
inline mat4 mat4_rotation_quat(const quat& a) {
    float xx = a.x*a.x;
    float yy = a.y*a.y;
    float zz = a.z*a.z;
    float xy = a.x*a.y;
    float zw = a.z*a.w;
    float xz = a.x*a.z;
    float yw = a.y*a.w;
    float yz = a.y*a.z;
    float wx = a.w*a.x;

    return mat4(
        static_cast<float>(1.0) - static_cast<float>(2.0)*(yy + zz),  static_cast<float>(2.0)*(xy + zw),                      static_cast<float>(2.0)*(xz - yw),      static_cast<float>(0.0),
        static_cast<float>(2.0)*(xy - zw),                      static_cast<float>(1.0) - static_cast<float>(2.0)*(xx + zz),  static_cast<float>(2.0)*(yz + wx),      static_cast<float>(0.0),
        static_cast<float>(2.0)*(xz + yw),                      static_cast<float>(2.0)*(yz - wx),      static_cast<float>(1.0) - static_cast<float>(2.0)*(xx + yy),  static_cast<float>(0.0),
        static_cast<float>(0.0),                                static_cast<float>(0.0),                                       static_cast<float>(0.0),               static_cast<float>(1.0)
    );
}


// The order of transformations is roll first, then pitch, then yaw. Relative to the object's local coordinate axis, 
// this is equivalent to rotation around the z-axis, followed by rotation around the x-axis, followed by rotation around the y-axis.
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
        sr*sp*sy + cr*cy,           sr*cp,                      sr*sp*cy - cr*sy,           static_cast<float>(0.0),
        cr*sp*sy - sr*cy,           cr*cp,                      cr*sp*cy + sr*sy,           static_cast<float>(0.0),
        cp*sy,                      -sp,                        cp*cy,                      static_cast<float>(0.0),
        static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(1.0)
    );

    return out;
}


// Compute a quaternian's axis and angle of rotation. Expects unit quaternions.
//D3DXQuaternionToAxisAngle
inline void quat_to_axis_angle(const quat& unit_quat, vec3& axis, float& angle) {
    axis = unit_quat.axis;
    angle = static_cast<float>(2.0) * std::acos(unit_quat.rotation);
}


//D3DXQuaternionRotationMatrix
//wnm
// Build a quaternion from a rotation matrix.
// same as quat_from_rotation_mat4
//inline quat make_quaternion_from_rotation_matrix(const mat4& ma)
inline quat quat_rotation_mat4(const mat4& ma) {
    if (ma.r[0][0] + ma.r[1][1] + ma.r[2][2] > static_cast<float>(0.0)) {
        float s = std::sqrt(static_cast<float>(1.0) + ma.r[0][0] + ma.r[1][1] + ma.r[2][2]);
        float inv_s = static_cast<float>(0.5) / s;

        return quat((ma.r[1][2] - ma.r[2][1]) * inv_s,
                    (ma.r[2][0] - ma.r[0][2]) * inv_s,
                    (ma.r[0][1] - ma.r[1][0]) * inv_s,
                    s * static_cast<float>(0.5));

    } else if (ma.r[0][0] >= ma.r[1][1] && ma.r[0][0] >= ma.r[2][2]) {
        float s = std::sqrt(static_cast<float>(1.0) + ma.r[0][0] - ma.r[1][1] - ma.r[2][2]);
        float inv_s = static_cast<float>(0.5) / s;

        return quat(static_cast<float>(0.5) * s,
                    (ma.r[0][1] + ma.r[1][0]) * inv_s,
                    (ma.r[0][2] + ma.r[2][0]) * inv_s,
                    (ma.r[1][2] - ma.r[2][1]) * inv_s);

    } else if (ma.r[1][1] > ma.r[2][2]) {
        float s = std::sqrt(static_cast<float>(1.0) + ma.r[1][1] - ma.r[0][0] - ma.r[2][2]);
        float inv_s = static_cast<float>(0.5) / s;

        return quat((ma.r[1][0] + ma.r[0][1]) * inv_s,
                    static_cast<float>(0.5) * s,
                    (ma.r[2][1] + ma.r[1][2]) * inv_s,
                    (ma.r[2][0] - ma.r[0][2]) * inv_s);

    } else {
        float s = std::sqrt(static_cast<float>(1.0) + ma.r[2][2] - ma.r[0][0] - ma.r[1][1]);
        float inv_s = static_cast<float>(0.5) / s;

        return quat((ma.r[2][0] + ma.r[0][2]) * inv_s,
                    (ma.r[2][1] + ma.r[1][2]) * inv_s,
                    static_cast<float>(0.5) * s,
                    (ma.r[0][1] - ma.r[1][0]) * inv_s);
    }
}


//D3DXQuaternionSlerp
//wnm
// Spherical linear interpolation between Q1 (t == 0) and Q2 (t == 1). s (time)
// Expects unit quaternions.
// Interpolates between two quaternions, using spherical linear interpolation.
//inline quaternion slerp(quaternion const& quaternion1, quaternion const& quaternion2, float amount)
inline quat quat_slerp(const quat& unit_quat_a, const quat& unit_quat_b, float t) {    
    const float epsilon = static_cast<float>(1e-6);
    
    float cos_omega = quat_dot(unit_quat_a, unit_quat_b);
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
        float omega = std::acos(cos_omega);
        float inv_sin_omega = static_cast<float>(1.0) / std::sin(omega);

        s1 = std::sin((static_cast<float>(1.0) - t) * omega) * inv_sin_omega;
        s2 = flip ? -std::sin(t * omega) * inv_sin_omega
                  :  std::sin(t * omega) * inv_sin_omega;
    }

    quat out = quat::k_zero();
    for (int i=0; i < quat::size(); ++i) {
        out[i] = s1 * unit_quat_a[i] + s2 * unit_quat_b[i];
    }
    return out;
}




//----------
// Rotation about arbitrary axis.
//D3DXQuaternionRotationAxis
inline quat quat_from_rotation_axis(const vec3& a, float angle) {        
    vec3 temp = vec3_normalize(a);
    float half_angle = angle * static_cast<float>(0.5);
    const float sin_half_angle = std::sin(half_angle);
    const float cos_half_angle = std::cos(half_angle);

    quat out = quat::k_zero();
    out.axis = sin_half_angle * temp;
    out.rotation = cos_half_angle;
    return out;
}


// Yaw around the Y axis, Pitch around the X axis, Roll around the Z axis.
//D3DXQuaternionRotationYawPitchRoll
inline quat quat_rotation_yaw_pitch_roll(float yaw, float pitch, float roll) {
    quat out = quat::k_zero();

    // Roll first, about axis the object is facing, then pitch upward, then yaw to face into the new heading
    float half_yaw = yaw * static_cast<float>(0.5);
    float sy = std::sin(half_yaw); 
    float cy = std::cos(half_yaw);
    float half_pitch = pitch * static_cast<float>(0.5);
    float sp = std::sin(half_pitch); 
    float cp = std::cos(half_pitch);
    float half_roll = roll * static_cast<float>(0.5);
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

    if ((a.w >= static_cast<float>(1.0)) || (a.w == -static_cast<float>(1.0))) {
        tf = static_cast<float>(1.0);
    } else {
        tf = std::acos(a.w) / std::sqrt(static_cast<float>(1.0) - (a.w*a.w));
    }

    out.axis = tf * a.axis;
    out.rotation = static_cast<float>(0.0);

    return out;
}

// QuaternionExp function converts a pure quaternion to a unit quaternion.
// Expects pure quaternions. (w == 0)  w is ignored in calculation.
// if q = (0, theta * a); exp(q) = (cos(theta), sin(theta) * a)
// The QuaternionSquadSetup function can also be used to set up the control points of a quaternion.
//D3DXQuaternionExp
inline quat quat_exp(const quat& a) {
    quat out = quat::k_identity();

    float norm = vec3_length(a.axis);

    if (norm) {
        float inv_norm = static_cast<float>(1.0)/norm;
        float snorm = std::sin(norm);
        float cnorm = std::cos(norm);

        out.axis = snorm * a.axis * inv_norm;
        out.rotation = cnorm;
    } else {
        out = quat::k_identity();
    }    

    return out;
}


// Spherical quadrangle interpolation.
// Slerp(Slerp(Q1, C, s), Slerp(A, B, s), 2s(1-s))
//D3DXQuaternionSquad
inline quat quat_squad(const quat& pq1, const quat& pqa, const quat& pqb, const quat& pqc, float s) {
    quat out = quat::k_zero();
    quat temp1 = quat_slerp(pq1, pqc, s);
    quat temp2 = quat_slerp(pqa, pqb, s);
    out = quat_slerp(temp1, temp2, static_cast<float>(2.0) * s * (static_cast<float>(1.0) - s));
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


    if (quat_dot(pq0, pq1) < static_cast<float>(0.0)) {
        temp2 = quat_ma(tzero, pq0, -static_cast<float>(1.0));
    } else {
        temp2 = pq0;
    }

    if (quat_dot(pq1, pq2) < static_cast<float>(0.0)) {
        cout = quat_ma(tzero, pq2, -static_cast<float>(1.0));
    } else {
        cout = pq2;
    }

    if (quat_dot(cout, pq3) < static_cast<float>(0.0)) {
        temp3 = quat_ma(tzero, pq3, -static_cast<float>(1.0));
    } else {
        temp3 = pq3;
    }

    temp1 = quat_inverse(pq1);
    temp2 = quat_ln(temp1 * temp2);
    q = quat_ln(temp1 * cout);
    temp1 = quat_ma(temp2, q, static_cast<float>(1.0));
    temp1 = temp1 * (-static_cast<float>(0.25));
    aout = pq1 * quat_exp(temp1);

    temp1 = quat_inverse(cout);
    temp2 = quat_ln(temp1 * pq1);
    q = quat_ln(temp1 * temp3);
    temp1 = quat_ma(temp2, q, static_cast<float>(1.0));
    temp1 = temp1 * (-static_cast<float>(0.25));
    bout = cout * quat_exp(temp1);           
}


// Barycentric interpolation.
// Slerp(Slerp(Q1, Q2, f+g), Slerp(Q1, Q3, f+g), g/(f+g))
// Barycentric coordinates define a point inside a triangle in terms of the triangle's vertices. 
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
// TODO: Find correct implementation
// Original d3dx9math functions takes pointers. NULL arguments are treated as identity transformations if taking pointers.
// Builds a transformation matrix. 
// Mout = Msc^-1 * Msr^-1 * Ms * Msr * Msc * Mrc^-1 * Mr * Mrc * Mt
//D3DXMatrixTransformation
// NOT EQUAL to d3dx9.dll version. Totally different result.
// Check from other mathlib
inline mat4 mat4_transformation_ptr(const vec3* scalingcenter, const quat* scalingrotation, 
    const vec3* scaling, const vec3* rotationcenter, const quat* rotation, const vec3* translation) {
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

    if (scalingcenter) {
        vsc = *scalingcenter;
    } else {
        vsc = vec3::k_zero();
    }

    if (rotationcenter) {
        qrc = quat(*rotationcenter, static_cast<float>(1.0));
    } else {
        qrc = quat::k_identity();       
    }

    if (translation) {
        vtr = *translation;
    } else {
        vtr = vec3::k_zero();        
    }

    m1 = mat4_translation(-vsc);

    if (scalingrotation) {
        m4 = mat4_rotation_quat(*scalingrotation);
        m2 = mat4_inverse(m4);        
    } else {        
        m4 = mat4::k_identity();
        m2 = mat4::k_identity();
    }

    if (scaling) { 
        m3 = mat4_scaling(*scaling);        
    } else {
        m3 = mat4::k_identity();
    }

    if (rotation) { 
        m6 = mat4_rotation_quat(*rotation);        
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


// Build 2D transformation matrix in XY plane. NULL arguments are treated as identity if taking pointers.
// Mout = Msc^-1 * Msr^-1 * Ms * Msr * Msc * Mrc^-1 * Mr * Mrc * Mt
//D3DXMatrixTransformation2D
inline mat4 mat4_transformation_2d_ptr(const vec2* scalingcenter, float scalingrotation, 
    const vec2* scaling, const vec2* rotationcenter, float rotation, const vec2* translation) {
    mat4 out = mat4::k_identity();

    quat qrot = quat::k_zero(); 
    quat qsrot = quat::k_zero();

    vec3 vs = k_vec3_one;

    vec3 vrc = vec3::k_zero();    
    vec3 vsc = vec3::k_zero();
    vec3 vt = vec3::k_zero();

    if (scalingcenter) {
        vsc = vec2_to_vec3(*scalingcenter, static_cast<float>(0.0));
    } else {
        vsc = vec3::k_zero();
    }

    if (scaling) {
        vs = vec2_to_vec3(*scaling, static_cast<float>(1.0));
    } else {
        vs = k_vec3_one;
    }

    if (rotationcenter) {
        vrc = vec2_to_vec3(*rotationcenter, static_cast<float>(0.0));
    } else {
        vrc = vec3::k_zero();
    }

    if (translation) {
        vt = vec2_to_vec3(*translation, static_cast<float>(0.0));
    } else {
        vt = vec3::k_zero();
    }

    
    const float half_rot = rotation * static_cast<float>(0.5);
    const float half_srot = scalingrotation * static_cast<float>(0.5);

    qrot.x = static_cast<float>(0.0);
    qrot.y = static_cast<float>(0.0);
    qrot.z = std::sin(half_rot);
    qrot.w = std::cos(half_rot);

    
    qsrot.x = static_cast<float>(0.0);
    qsrot.y = static_cast<float>(0.0);
    qsrot.z = std::sin(half_srot);
    qsrot.w = std::cos(half_srot);

    out = mat4_transformation_ptr(&vsc, &qsrot, &vs, &vrc, &qrot, &vt);

    return out;
}


// Build affine transformation matrix. NULL arguments are treated as identity if taking pointers.
// Mout = Ms * Mrc^-1 * Mr * Mrc * Mt
//D3DXMatrixAffineTransformation
inline mat4 mat4_affine_transformation_ptr(float scaling, const vec3* rotationcenter, const quat* rotation, const vec3* translation) {

    mat4 out = mat4::k_identity();

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


// Build 2D affine transformation matrix in XY plane. NULL arguments are treated as identity if taking pointers.
// Mout = Ms * Mrc^-1 * Mr * Mrc * Mt
//D3DXMatrixAffineTransformation2D
inline mat4 mat4_affine_transformation_2d_ptr(float scaling, const vec2* rotationcenter, float rotation, const vec2* translation) {
    mat4 out = mat4::k_identity();

    float half_rotation = rotation * static_cast<float>(0.5);
    const float s = std::sin(half_rotation);
    const float tmp1 = static_cast<float>(1.0) - static_cast<float>(2.0)*s*s;
    const float tmp2 = static_cast<float>(2.0) * s * std::cos(half_rotation);
    
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


// D3DXMatrixDecompose
bool D3DXMatrixDecompose(vec3& outscale, quat& outrotation, vec3& outtranslation, const mat4& ma) {
    mat4 normalized;
    vec3 vec;

    //Compute the scaling part.
    vec.x = ma.r[0][0];
    vec.y = ma.r[0][1];
    vec.z = ma.r[0][2];
    outscale.x = vec3_length(vec);

    vec.x = ma.r[1][0];
    vec.y = ma.r[1][1];
    vec.z = ma.r[1][2];
    outscale.y = vec3_length(vec);

    vec.x = ma.r[2][0];
    vec.y = ma.r[2][1];
    vec.z = ma.r[2][2];
    outscale.z = vec3_length(vec);

    //Compute the translation part.
    outtranslation.x = ma.r[3][0];
    outtranslation.y = ma.r[3][1];
    outtranslation.z = ma.r[3][2];

    //Let's calculate the rotation now.
    if ((outscale.x == 0.0f) || (outscale.y == 0.0f) || (outscale.z == 0.0f)) {
        return false; //D3DERR_INVALIDCALL;
    }

    normalized.r[0][0] = ma.r[0][0]/outscale.x;
    normalized.r[0][1] = ma.r[0][1]/outscale.x;
    normalized.r[0][2] = ma.r[0][2]/outscale.x;
    normalized.r[1][0] = ma.r[1][0]/outscale.y;
    normalized.r[1][1] = ma.r[1][1]/outscale.y;
    normalized.r[1][2] = ma.r[1][2]/outscale.y;
    normalized.r[2][0] = ma.r[2][0]/outscale.z;
    normalized.r[2][1] = ma.r[2][1]/outscale.z;
    normalized.r[2][2] = ma.r[2][2]/outscale.z;

    outrotation = quat_rotation_mat4(normalized);
    //outrotation = quat_rotation_mat4_d3dx(normalized);

    return true; //S_OK;
}


//===================================================================================
//UNCHECKED


//=======================================
// EXTRA
//--------------
//// same as quat_conjugate
//, inline quat quat_negate(const quat& a) { 
//	//return quat(-a.axis, a.rotation); 
//	return quat_conjugate(a);
//}



//WNM
//--------------
inline const vec2 k_vec2_one = vec2(1, 1);
inline const vec2 k_vec2_unit_x = vec2(1, 0);
inline const vec2 k_vec2_unit_y = vec2(0, 1);

inline const vec3 k_vec3_unit_x = vec3(1, 0, 0);
inline const vec3 k_vec3_unit_y = vec3(0, 1, 0);
inline const vec3 k_vec3_unit_z = vec3(0, 0, 1);

inline const vec4 k_vec4_one = vec4(1, 1, 1, 1);
inline const vec4 k_vec4_unit_x = vec4(1, 0, 0, 0);
inline const vec4 k_vec4_unit_y = vec4(0, 1, 0, 0);
inline const vec4 k_vec4_unit_z = vec4(0, 0, 1, 0);
inline const vec4 k_vec4_unit_w = vec4(0, 0, 0, 1);

//---
inline vec2 vec2_reflect(const vec2& a, const vec2& normal) {
    return (a - static_cast<float>(2.0) * vec2_dot(a, normal) * normal);
}

inline vec3 vec3_reflect(const vec3& a, const vec3& normal) {
    return (a - static_cast<float>(2.0) * vec3_dot(a, normal) * normal);
}


