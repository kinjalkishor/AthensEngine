#pragma once

#include "base_def.h"
#include "base_print.h"
#include "base_math.h"
#include "base_gmath_util.h"


namespace gm
{



class vec2 {
public:
	union {
		struct { float x, y; };
		float e[2];
    };	

	vec2() = default;
	vec2(float x, float y) : x(x), y(y) {}

	constexpr static int size() { return 2; }	

	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }

    vec2& operator +=(const vec2& rhs) { for_range(i, 0, size()) { e[i] += rhs[i]; } return *this; }
    vec2& operator -=(const vec2& rhs) { for_range(i, 0, size()) { e[i] -= rhs[i]; } return *this; }
	vec2& operator *=(const vec2& rhs) { for_range(i, 0, size()) { e[i] *= rhs[i]; } return *this; }
	vec2& operator /=(const vec2& rhs) { for_range(i, 0, size()) { e[i] /= rhs[i]; } return *this; }
    vec2& operator +=(float s) { for_range(i, 0, size()) { e[i] += s; } return *this; }
    vec2& operator -=(float s) { for_range(i, 0, size()) { e[i] -= s; } return *this; }
	vec2& operator *=(float s) { for_range(i, 0, size()) { e[i] *= s; } return *this; }
	vec2& operator /=(float s) { for_range(i, 0, size()) { e[i] /= s; } return *this; }

	const static vec2 k_zero() { return {0, 0}; }
	const static vec2 k_identity() { return {1, 1}; }	
    const static vec2 k_origin() { return {0, 0}; }
    const static vec2 k_unit() { return {1, 1}; }
};

class vec3 {
public:
	union {
		struct { float x, y, z; };
		float e[3];
    };	

	vec3() = default;
	vec3(float x, float y, float z) : x(x), y(y), z(z) {}

	constexpr static int size() { return 3; }	

	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }

	vec3& operator +=(const vec3& rhs) { for_range(i, 0, size()) { e[i] += rhs[i]; } return *this; }
    vec3& operator -=(const vec3& rhs) { for_range(i, 0, size()) { e[i] -= rhs[i]; } return *this; }
	vec3& operator *=(const vec3& rhs) { for_range(i, 0, size()) { e[i] *= rhs[i]; } return *this; }
	vec3& operator /=(const vec3& rhs) { for_range(i, 0, size()) { e[i] /= rhs[i]; } return *this; }
    vec3& operator +=(float s) { for_range(i, 0, size()) { e[i] += s; } return *this; }
    vec3& operator -=(float s) { for_range(i, 0, size()) { e[i] -= s; } return *this; }
	vec3& operator *=(float s) { for_range(i, 0, size()) { e[i] *= s; } return *this; }
	vec3& operator /=(float s) { for_range(i, 0, size()) { e[i] /= s; } return *this; }


	const static vec3 k_zero() { return {0, 0, 0}; }
    const static vec3 k_identity() { return {1, 1, 1}; }
    const static vec3 k_origin() { return {0, 0, 0}; }
    const static vec3 k_unit() { return {1, 1, 1}; }			
};

class vec4 {
public:
	union {
		struct { float x, y, z, w; };
		float e[4];
    };	

	vec4() = default;
	vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	constexpr static int size() { return 4; }	

	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }

    vec4& operator +=(const vec4& rhs) { for_range(i, 0, size()) { e[i] += rhs[i]; } return *this; }
    vec4& operator -=(const vec4& rhs) { for_range(i, 0, size()) { e[i] -= rhs[i]; } return *this; }
	vec4& operator *=(const vec4& rhs) { for_range(i, 0, size()) { e[i] *= rhs[i]; } return *this; }
	vec4& operator /=(const vec4& rhs) { for_range(i, 0, size()) { e[i] /= rhs[i]; } return *this; }
    vec4& operator +=(float s) { for_range(i, 0, size()) { e[i] += s; } return *this; }
    vec4& operator -=(float s) { for_range(i, 0, size()) { e[i] -= s; } return *this; }
	vec4& operator *=(float s) { for_range(i, 0, size()) { e[i] *= s; } return *this; }
	vec4& operator /=(float s) { for_range(i, 0, size()) { e[i] /= s; } return *this; }

	const static vec4 k_zero() { return {0, 0, 0, 0}; }
	const static vec4 k_identity() { return {1, 1, 1, 1}; }	
    const static vec4 k_origin() { return {0, 0, 0, 0}; }
    const static vec4 k_unit() { return {1, 1, 1, 1}; }
};

class color4 {
public:
	union {
		struct { float r, g, b, a; };
		float e[4];
		vec4 v;
    };	

	color4() = default;
	color4(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
	//color4(float r, float g, float b) : r(r), g(g), b(b), a(1.0) {}
	color4(vec4 a) : v(a) {}

	constexpr static int size() { return 4; }	

	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }

	const static color4 k_zero() { return {0, 0, 0, 0}; }	
};


// (x, y, z) axis about which a rotation will occur, imaginary part
// (w) amount of rotation which will occur about this axis, real part
class quat {
public:
	union {
		struct { float x, y, z, w; };		
		float e[4];
		vec4 v;
		struct { vec3 axis; float rotation; };
    };	

	quat() = default;
	quat(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
	quat(vec3 axis, float rotation) : axis(axis), rotation(rotation) {}
	quat(vec4 a) : v(a) {}

	constexpr static int size() { return 4; }	

	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }

	const static quat k_zero() { return {0, 0, 0, 0}; }
	const static quat k_identity() { return {0, 0, 0, 1}; }	
};


class plane {
public:
	// (a, b, c) Normal vector of the plane
	// (d) distance of the plane normal (from origin)
	union {
		struct { float a, b, c, d; };
		float e[4];
		vec4 v;
        struct { vec3 normal; float dist; };
    };	

    plane() = default;
	plane(float a, float b, float c, float d) : a(a), b(b), c(c), d(d) {}
	plane(const vec3& normal, float dist) : normal(normal), dist(dist) {}
	plane(vec4 a) : v(a) {}

	constexpr static int size() { return 4; }	

	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }

	const static plane k_zero() { return {0, 0, 0, 0}; }
};



class mat3 {
public:
	union {
		struct {
            float	m11, m12, m13,
					m21, m22, m23,
					m31, m32, m33;
        };
		float e[9];
		float r[3][3];
	};

	mat3() = default;
	
	mat3(float m11, float m12, float m13,
		 float m21, float m22, float m23,
		 float m31, float m32, float m33) {
		e[0]  = m11; e[1]  = m12; e[2] = m13;
		e[3]  = m21; e[4]  = m22; e[5] = m23;
		e[6]  = m31; e[7]  = m32; e[8] = m33;
	}

	constexpr static int size() { return 9; }	
	constexpr int dim() const	{ return 3; }	
	
	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }

	//const float& operator ()(int row, int col) const	{ return r[row][col]; }
    //float& operator ()(int row, int col)				{ return r[row][col]; }

	const static mat3 k_zero() { 
		return mat3(
			0, 0, 0,
			0, 0, 0,
			0, 0, 0
		);	
	}

	const static mat3 k_identity() { 
		return mat3(
			1, 0, 0,	
			0, 1, 0,	
			0, 0, 1
		);
	}	
};


//--------------------
class viewport {
public:
    float x, y, w, h;
    float zn, zf;
};
//--------------------


class mat4 {
public:
	union {
		float e[16];
		float r[4][4];
	};

	mat4() = default;
	
	mat4(float m11, float m12, float m13, float m14,
		 float m21, float m22, float m23, float m24,
		 float m31, float m32, float m33, float m34,
		 float m41, float m42, float m43, float m44) {
		e[0]  = m11; e[1]  = m12; e[2]  = m13; e[3]  = m14;
		e[4]  = m21; e[5]  = m22; e[6]  = m23; e[7]  = m24;
		e[8]  = m31; e[9]  = m32; e[10] = m33; e[11] = m34;
		e[12] = m41; e[13] = m42; e[14] = m43; e[15] = m44;
	}

	constexpr static int size() { return 16; }	
	constexpr int dim() const	{ return 4; }	
	
	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }

	//const float& operator ()(int row, int col) const	{ return r[row][col]; }
    //float& operator ()(int row, int col)				{ return r[row][col]; }
	//const float& operator ()(int row, int col) const	{ return e[(row * 4) + col]; }
	//float& operator ()(int row, int col)				{ return e[(row * 4) + col]; }


	const static mat4 k_zero() { 
		return mat4(
			0, 0, 0, 0,		
			0, 0, 0, 0,		
			0, 0, 0, 0,		
			0, 0, 0, 0
		); 
	}

	const static mat4 k_identity() { 
		return mat4(
			1, 0, 0, 0,		
			0, 1, 0, 0,		
			0, 0, 1, 0,		
			0, 0, 0, 1
		); 
	}	
};




//================================================================================================


//========================================================================================================================
// Template functions for N size
//========================================================================================================================

template<class T> inline T vecnt_negate(const T& a) { T out = T::k_zero(); for_range (i, 0, out.size()) { out[i] = -a[i]; } return out; }
template<class T> inline T vecnt_add(const T& a, const T& b) { T out = T::k_zero(); for_range (i, 0, out.size()) { out[i] = a[i] + b[i]; } return out; }
template<class T> inline T vecnt_sub(const T& a, const T& b) { T out = T::k_zero(); for_range (i, 0, out.size()) { out[i] = a[i] - b[i]; } return out; }
template<class T> inline T vecnt_mul(const T& a, const T& b) { T out = T::k_zero(); for_range (i, 0, out.size()) { out[i] = a[i] * b[i]; } return out; }
template<class T> inline T vecnt_div(const T& a, const T& b) { T out = T::k_zero(); for_range (i, 0, out.size()) { out[i] = a[i] / b[i]; } return out; }
template<class T> inline T vecnt_add_s(const T& a, float s) { T out = T::k_zero(); for_range (i, 0, out.size()) { out[i] = a[i] + s; } return out; }
template<class T> inline T vecnt_sub_s(const T& a, float s) { T out = T::k_zero(); for_range (i, 0, out.size()) { out[i] = a[i] - s; } return out; }
template<class T> inline T vecnt_mul_s(const T& a, float s) { T out = T::k_zero(); for_range (i, 0, out.size()) { out[i] = a[i] * s; } return out; }
template<class T> inline T vecnt_div_s(const T& a, float s) { 
	const float inv_s = scast<float>(1.0)/s; 
	//return (a * inv_s); 
	T out = T::k_zero(); for_range (i, 0, out.size()) { out[i] = a[i] * inv_s; } return out;
}

//(a.x==b.x && a.y==b.y)
template<class T> inline bool vecnt_is_equal_ep(const T& a, const T& b, float epsilon) { 
	// If any elements is not equal return false. If this test fails for all elements than vectors are equal, return true.
	for_range (i, 0, a.size()) { if (!(mf::equals_ep(a[i], b[i], epsilon))) { return false; } }	return true; 
}
template<class T> inline bool vecnt_is_equal_ep2(const T& a, const T& b) { 
	for_range (i, 0, a.size()) { if (!(mf::equals2(a[i], b[i]))) { return false; } }	return true; 
}
template<class T> inline bool vecnt_is_not_equal_ep(const T& a, const T& b, float epsilon) { 
	return !(vecnt_is_equal_ep(a, b, epsilon)); 
}

template<class T> inline bool vecnt_is_equal(const T& a, const T& b) { 
	//for_range (i, 0, a.size()) { if (!(a[i] == b[i])) { return false; } }	return true; 
	return vecnt_is_equal_ep2(a, b);
}
template<class T> inline bool vecnt_is_not_equal(const T& a, const T& b) { 
	//return !(a == b); 
	return !(vecnt_is_equal(a, b));
}
//(a.x<b.x && a.y<b.y)

template<class T> inline bool vecnt_is_less(const T& a, const T& b) { 
	//(<)
	// If any elements is not less_than return false. If this test fails for all elements than 1st vector is less_than, return true.
	for_range (i, 0, a.size()) { if (!(a[i] < b[i])) { return false; } }	return true; 
}
template<class T> inline bool vecnt_is_greater(const T& a, const T& b) { 
	//(>)
	//return (b < a); 
	return vecnt_is_less(b, a);
}
template<class T> inline bool vecnt_is_less_equal(const T& a, const T&b) { 
	//(<=)
	//return !(b < a); 
	return !(vecnt_is_less(b, a));
}
template<class T> inline bool vecnt_is_greater_equal(const T& a, const T& b) { 
	//(>=)
	//return !(a < b); 
	return !(vecnt_is_less(a, b));
}

template<class T> inline float vecnt_dot(const T& a, const T& b) {
	//a.x*b.x + a.y*b.y + a.z*b.z
	float out = scast<float>(0.0); for_range (i, 0, a.size()) { out += a[i] * b[i]; } return out;
}

template<class T> inline float vecnt_length_sq(const T& a) {
	//(square(a.x) + square(a.y) + square(a.z));
	//a.x*a.x + a.y*a.y + a.z*a.z	
	//dot(a, a);
	float out = scast<float>(0.0); for_range (i, 0, a.size()) { out += mf::square(a[i]); } return out;
}
// vector length, magnitude
template<class T> inline float vecnt_length(const T& a) { return std::sqrt(vecnt_length_sq(a));  }

template<class T> inline float vecnt_distance_sq(const T& a, const T& b) {
	//(square(a.x - b.x) + square(a.y - b.y) + square(a.z - b.z));
	//(a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z)	
    float out = scast<float>(0.0); for_range (i, 0, a.size()) { out += mf::square(a[i] - b[i]); } return out;
}
template<class T> inline float vecnt_distance(const T& a, const T& b) { return std::sqrt(vecnt_distance_sq(a, b)); }

// Linear interpolation. V1 + s(V2-V1)
template<class T> inline T vecnt_lerp(const T& a, const T& b, float s) {
    T out = T::k_zero(); for_range (i, 0, out.size()) { out[i] = mf::lerp(a[i], b[i], s); } return out;
}

// Minimize each component.  x = min(x1, x2), y = min(y1, y2)
template<class T> inline T vecnt_min(const T& a, const T& b) {
    T out = T::k_zero(); for_range (i, 0, out.size()) { out[i] = sdf::tmin(a[i], b[i]); } return out;
}
// Maximize each component.  x = max(x1, x2), y = max(y1, y2)
template<class T> inline T vecnt_max(const T& a, const T& b) {
    T out = T::k_zero(); for_range (i, 0, out.size()) { out[i] = sdf::tmax(a[i], b[i]); } return out;
}

template<class T> inline T vecnt_clamp(const T& a, const T& low, const T& high) {
    T out = T::k_zero(); for_range (i, 0, out.size()) { out[i] = sdf::clamp(a[i], low[i], high[i]); } return out;
}

// Passing zero vector will make length or norm 0, and divide by zero exception will occur
// for a zero vector this will let the zero vector remain zero
// for zero length vector or if length is too small it is x/0 (infinity). Should throw exception or return NaN.
// check norm with epsilon, as for zero or too small vector length will approach infinity
template<class T> inline T vecnt_normalize(const T& a) {
    //a / length(a);
    T out = T::k_zero(); 
	float length = vecnt_length(a);

	if (length) {
		float inv_length = scast<float>(1.0)/length;
		//out = a * inv_length;	
		for_range (i, 0, out.size()) { out[i] = a[i] * inv_length; }
	} else {
		// out is already zero. If out is used error will propogate
		//out = T::k_zero();	
        printf("Cannot normalize zero length vector. Zero vector returned. Error will propogate.\n");			
	}
		
    return out;
	//return length;
}



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

    for_range (i, 0, out.size()) { out[i] = h1 * v1[i] + h2 * t1[i] + h3 * v2[i] + h4 * t2[i]; }

    return out;
}

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
template<class T> inline T vecnt_catmull_rom(const T& v0, const T& v1, const T& v2, const T& v3, float s) {
    T out = T::k_zero(); 
    float s3 = mf::cube(s);
	float s2 = mf::square(s); 

    for_range (i, 0, out.size()) {
        out[i] = scast<float>(0.5) * (scast<float>(2.0) * v1[i] + (v2[i] - v0[i]) * s + (scast<float>(2.0) * v0[i] - scast<float>(5.0) * v1[i] 
            + scast<float>(4.0) * v2[i] - v3[i]) * s2 + (v3[i] -scast<float>(3.0) * v2[i] + scast<float>(3.0) * v1[i] - v0[i]) * s3);
    }

    return out;
}

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
template<class T> inline T vecnt_bary_centric(const T& v1, const T& v2, const T& v3, float f, float g) {
    T out = T::k_zero(); for_range (i, 0, out.size()) { out[i] = (scast<float>(1.0)-f-g) * v1[i] + f * v2[i] + g * v3[i]; } return out;
}

template<class T> inline T vecnt_mul_angles(const T& a, const T& b, float s) { T out = T::k_zero(); for_range (i, 0, out.size()) { out[i] = a[i] + s*b[i]; } return out; }

//================================================================================================

//---------------------------------------------------
// Constants
//---------------------------------------------------
inline const vec3 k_vec3_one() { return {1, 1, 1}; }
// default (0, 1, 0, 0)
//inline const plane k_plane_default() { return {0, 1, 0, 0}; }    


//---------------------------------------------------
// vec2
//---------------------------------------------------

inline vec2 operator - (const vec2& a) { return vecnt_negate(a); }

inline vec2 operator + (const vec2& a, const vec2& b) { return vecnt_add(a, b); }
inline vec2 operator - (const vec2& a, const vec2& b) { return vecnt_sub(a, b); }
inline vec2 operator * (const vec2& a, const vec2& b) { return vecnt_mul(a, b); }
inline vec2 operator / (const vec2& a, const vec2& b) { return vecnt_div(a, b); }

inline vec2 operator + (const vec2& a, float s) { return vecnt_add_s(a, s); }
inline vec2 operator - (const vec2& a, float s) { return vecnt_sub_s(a, s); }
inline vec2 operator * (const vec2& a, float s) { return vecnt_mul_s(a, s); }
inline vec2 operator / (const vec2& a, float s) { return vecnt_div_s(a, s); }

inline vec2 operator + (float s, const vec2& a) { return vecnt_add_s(a, s); }
inline vec2 operator - (float s, const vec2& a) { return vecnt_sub_s(a, s); }
inline vec2 operator * (float s, const vec2& a) { return vecnt_mul_s(a, s); }
inline vec2 operator / (float s, const vec2& a) { return vecnt_div_s(a, s); }

inline bool vec2_equals_ep(const vec2& a, const vec2& b, float epsilon) { return vecnt_is_equal_ep(a, b, epsilon); }
inline bool vec2_equals_ep2(const vec2& a, const vec2& b) { return vecnt_is_equal_ep2(a, b); }

inline bool operator == (const vec2& a, const vec2& b) { return vecnt_is_equal(a, b); }
inline bool operator != (const vec2& a, const vec2& b) { return vecnt_is_not_equal(a, b); }

inline bool operator > (const vec2& a, const vec2& b)	{ return vecnt_is_greater(a, b); }
inline bool operator < (const vec2& a, const vec2& b)	{ return vecnt_is_less(a, b); }
inline bool operator >= (const vec2& a, const vec2& b)	{ return vecnt_is_greater_equal(a, b); }
inline bool operator <= (const vec2& a, const vec2& b)	{ return vecnt_is_less_equal(a, b); }


inline float vec2_dot(const vec2& a, const vec2& b) { return vecnt_dot(a, b); }
inline float vec2_length_sq(const vec2& a) { return vecnt_length_sq(a); }	
inline float vec2_length(const vec2& a) { return vecnt_length(a); }
//,inline float vec2_distance_sq(const vec2& a, const vec2& b) { return vecnt_distance_sq(a, b); }
//,inline float vec2_distance(const vec2& a, const vec2& b) { return vecnt_distance(a, b); }

inline vec2 vec2_scale(const vec2& a, float s) { return (a * s); }
inline vec2 vec2_lerp(const vec2& a, const vec2& b, float s) { return vecnt_lerp(a, b, s); }
inline vec2 vec2_min(const vec2& a, const vec2& b) { return vecnt_min(a, b); }
inline vec2 vec2_max(const vec2& a, const vec2& b) { return vecnt_max(a, b); }
//,inline vec2 vec2_clamp(const vec2& a, const vec2& min, const vec2& max) { return vecnt_clamp(a, min, max); }

inline vec2 vec2_normalize(const vec2& a) { return vecnt_normalize(a); }

inline float vec2_ccw(const vec2& a, const vec2& b) { return (a.x*b.y - a.y*b.x); }


//---------------------------------------------------
// vec3
//---------------------------------------------------

inline vec3 operator - (const vec3& a) { return vecnt_negate(a); }

inline vec3 operator + (const vec3& a, const vec3& b) { return vecnt_add(a, b); }
inline vec3 operator - (const vec3& a, const vec3& b) { return vecnt_sub(a, b); }
inline vec3 operator * (const vec3& a, const vec3& b) { return vecnt_mul(a, b); }
inline vec3 operator / (const vec3& a, const vec3& b) { return vecnt_div(a, b); }

inline vec3 operator + (const vec3& a, float s) { return vecnt_add_s(a, s); }
inline vec3 operator - (const vec3& a, float s) { return vecnt_sub_s(a, s); }
inline vec3 operator * (const vec3& a, float s) { return vecnt_mul_s(a, s); }
inline vec3 operator / (const vec3& a, float s) { return vecnt_div_s(a, s); }

inline vec3 operator + (float s, const vec3& a) { return vecnt_add_s(a, s); }
inline vec3 operator - (float s, const vec3& a) { return vecnt_sub_s(a, s); }
inline vec3 operator * (float s, const vec3& a) { return vecnt_mul_s(a, s); }
inline vec3 operator / (float s, const vec3& a) { return vecnt_div_s(a, s); }

inline bool vec3_equals_ep(const vec3& a, const vec3& b, float epsilon) { return vecnt_is_equal_ep(a, b, epsilon); }
inline bool vec3_equals_ep2(const vec3& a, const vec3& b) { return vecnt_is_equal_ep2(a, b); }

inline bool operator == (const vec3& a, const vec3& b) { return vecnt_is_equal(a, b); }
inline bool operator != (const vec3& a, const vec3& b) { return vecnt_is_not_equal(a, b); }

inline bool operator > (const vec3& a, const vec3& b)	{ return vecnt_is_greater(a, b); }
inline bool operator < (const vec3& a, const vec3& b)	{ return vecnt_is_less(a, b); }
inline bool operator >= (const vec3& a, const vec3& b)	{ return vecnt_is_greater_equal(a, b); }
inline bool operator <= (const vec3& a, const vec3& b)	{ return vecnt_is_less_equal(a, b); }


inline float vec3_dot(const vec3& a, const vec3& b) { return vecnt_dot(a, b); }
inline float vec3_length_sq(const vec3& a) { return vecnt_length_sq(a); }	
inline float vec3_length(const vec3& a) { return vecnt_length(a); }
//,inline float vec3_distance_sq(const vec3& a, const vec3& b) { return vecnt_distance_sq(a, b); }
//,inline float vec3_distance(const vec3& a, const vec3& b) { return vecnt_distance(a, b); }

inline vec3 vec3_scale(const vec3& a, float s) { return (a * s); }
inline vec3 vec3_lerp(const vec3& a, const vec3& b, float s) { return vecnt_lerp(a, b, s); }
inline vec3 vec3_min(const vec3& a, const vec3& b) { return vecnt_min(a, b); }
inline vec3 vec3_max(const vec3& a, const vec3& b) { return vecnt_max(a, b); }
//,inline vec3 vec3_clamp(const vec3& a, const vec3& min, const vec3& max) { return vecnt_clamp(a, min, max); }

inline vec3 vec3_normalize(const vec3& a) { return vecnt_normalize(a); }

//,inline vec3 vec3_reflect(const vec3& a, const vec3& normal) { return (a - (scast<float>(2.0) * vecnt_dot(a, normal) * normal)); }

inline vec3 vec3_cross(const vec3& a, const vec3& b) {
	vec3 out = vec3::k_zero();
	out.x = a.y*b.z - a.z*b.y;
	out.y = a.z*b.x - a.x*b.z;
	out.z = a.x*b.y - a.y*b.x;
	return out;
}

//---------------------------------------------------
// vec4
//---------------------------------------------------

inline vec4 operator - (const vec4& a) { return vecnt_negate(a); }

inline vec4 operator + (const vec4& a, const vec4& b) { return vecnt_add(a, b); }
inline vec4 operator - (const vec4& a, const vec4& b) { return vecnt_sub(a, b); }
inline vec4 operator * (const vec4& a, const vec4& b) { return vecnt_mul(a, b); }
inline vec4 operator / (const vec4& a, const vec4& b) { return vecnt_div(a, b); }

inline vec4 operator + (const vec4& a, float s) { return vecnt_add_s(a, s); }
inline vec4 operator - (const vec4& a, float s) { return vecnt_sub_s(a, s); }
inline vec4 operator * (const vec4& a, float s) { return vecnt_mul_s(a, s); }
inline vec4 operator / (const vec4& a, float s) { return vecnt_div_s(a, s); }

inline vec4 operator + (float s, const vec4& a) { return vecnt_add_s(a, s); }
inline vec4 operator - (float s, const vec4& a) { return vecnt_sub_s(a, s); }
inline vec4 operator * (float s, const vec4& a) { return vecnt_mul_s(a, s); }
inline vec4 operator / (float s, const vec4& a) { return vecnt_div_s(a, s); }

inline bool vec4_equals_ep(const vec4& a, const vec4& b, float epsilon) { return vecnt_is_equal_ep(a, b, epsilon); }
inline bool vec4_equals_ep2(const vec4& a, const vec4& b) { return vecnt_is_equal_ep2(a, b); }

inline bool operator == (const vec4& a, const vec4& b) { return vecnt_is_equal(a, b); }
inline bool operator != (const vec4& a, const vec4& b) { return vecnt_is_not_equal(a, b); }

inline bool operator > (const vec4& a, const vec4& b)	{ return vecnt_is_greater(a, b); }
inline bool operator < (const vec4& a, const vec4& b)	{ return vecnt_is_less(a, b); }
inline bool operator >= (const vec4& a, const vec4& b)	{ return vecnt_is_greater_equal(a, b); }
inline bool operator <= (const vec4& a, const vec4& b)	{ return vecnt_is_less_equal(a, b); }


inline float vec4_dot(const vec4& a, const vec4& b) { return vecnt_dot(a, b); }
inline float vec4_length_sq(const vec4& a) { return vecnt_length_sq(a); }	
inline float vec4_length(const vec4& a) { return vecnt_length(a); }
//,inline float vec4_distance_sq(const vec4& a, const vec4& b) { return vecnt_distance_sq(a, b); }
//,inline float vec4_distance(const vec4& a, const vec4& b) { return vecnt_distance(a, b); }

inline vec4 vec4_scale(const vec4& a, float s) { return (a * s); }
inline vec4 vec4_lerp(const vec4& a, const vec4& b, float s) { return vecnt_lerp(a, b, s); }
inline vec4 vec4_min(const vec4& a, const vec4& b) { return vecnt_min(a, b); }
inline vec4 vec4_max(const vec4& a, const vec4& b) { return vecnt_max(a, b); }
//,inline vec4 vec4_clamp(const vec4& a, const vec4& min, const vec4& max) { return vecnt_clamp(a, min, max); }

inline vec4 vec4_normalize(const vec4& a) { return vecnt_normalize(a); }


//---------------------------------------------------
// color4
//---------------------------------------------------

inline color4 operator - (const color4& a) { return (-a.v); }

inline color4 operator + (const color4& a, const color4& b) { return (a.v + b.v); }
inline color4 operator - (const color4& a, const color4& b) { return (a.v - b.v); }
inline color4 operator * (const color4& a, const color4& b) { return (a.v * b.v); }
//inline color4 operator / (const color4& a, const color4& b) { return (a.v / b.v); }

inline color4 operator + (const color4& a, float s) { return (a.v + s); }
inline color4 operator - (const color4& a, float s) { return (a.v - s); }
inline color4 operator * (const color4& a, float s) { return (a.v * s); }
inline color4 operator / (const color4& a, float s) { return (a.v / s); }

inline color4 operator + (float s, const color4& a) { return (a.v + s); }
inline color4 operator - (float s, const color4& a) { return (a.v - s); }
inline color4 operator * (float s, const color4& a) { return (a.v * s); }
inline color4 operator / (float s, const color4& a) { return (a.v / s); }

inline bool color4_equals_ep(const color4& a, const color4& b, float epsilon) { return vec4_equals_ep(a.v, b.v, epsilon); }
inline bool color4_equals_ep2(const color4& a, const color4& b) { return vec4_equals_ep2(a.v, b.v); }

inline bool operator == (const color4& a, const color4& b) { return (a.v == b.v); }
inline bool operator != (const color4& a, const color4& b) { return (a.v != b.v); }

inline bool operator > (const color4& a, const color4& b)	{ return (a.v > b.v); }
inline bool operator < (const color4& a, const color4& b)	{ return (a.v < b.v); }
inline bool operator >= (const color4& a, const color4& b)	{ return (a.v >= b.v); }
inline bool operator <= (const color4& a, const color4& b)	{ return (a.v <= b.v); }


inline color4 color4_scale(const color4& a, float s) { return (a * s); }
inline color4 color4_lerp(const color4& a, const color4& b, float s) { return vecnt_lerp(a, b, s); }



//---
inline color4 color4_from_argb(uint uc) {
	color4 out = color4::k_zero();
	//const float f = scast<float>(1.0)/scast<float>(255.0);
	//out.r = f * (float) (uint8) (uc >> 16);
	//out.g = f * (float) (uint8) (uc >>  8);
	//out.b = f * (float) (uint8) (uc >>  0);
	//out.a = f * (float) (uint8) (uc >> 24);

	unpackf_u32(uc, out.a, out.r, out.g, out.b);
	return out;
}

inline color4 color4_from_abgr(uint uc) {
	color4 out = color4::k_zero();
	unpackf_u32(uc, out.a, out.b, out.g, out.r);
	return out;
}

inline color4 color4_from_rgba(uint uc) {
	color4 out = color4::k_zero();
	unpackf_u32(uc, out.r, out.g, out.b, out.a);
	return out;
}


// d3dx9
inline uint argb_from_color4(const color4& a) {
	return packf_u32(a.a, a.r, a.g ,a.b);
}

// Only in d3dx9math D3DXCOLOR DWORD operator: D3DXCOLOR::operator DWORD () const {}
inline uint argb_from_color4_d3dx9(const color4& a) {
	////(uint) (x * 255.0f + 0.5f)) (d3dx9) instead of (uint) (x * 255.0f)) (packf_u32)
	//uint ur = a.r >= 1.0f ? 0xff : a.r <= 0.0f ? 0x00 : (uint) (a.r * 255.0f + 0.5f);
	//uint ug = a.g >= 1.0f ? 0xff : a.g <= 0.0f ? 0x00 : (uint) (a.g * 255.0f + 0.5f);
	//uint ub = a.b >= 1.0f ? 0xff : a.b <= 0.0f ? 0x00 : (uint) (a.b * 255.0f + 0.5f);
	//uint ua = a.a >= 1.0f ? 0xff : a.a <= 0.0f ? 0x00 : (uint) (a.a * 255.0f + 0.5f);
	//return (ua << 24) | (ur << 16) | (ug << 8) | ub;

	return packf_u32_r(a.a, a.r, a.g ,a.b);
}

// gl2
inline uint abgr_from_color4(const color4& a) {
	return packf_u32(a.a, a.b, a.g, a.r);
}

inline uint rgba_from_color4(const color4& a) {
	return packf_u32(a.r, a.g, a.b ,a.a);
}


// Same as RGB macro of Windows. Packs color in format of Win32 Api.
inline uint xbgr_from_color4(const color4& a) {
	return packf_u32(scast<float>(0.0), a.b, a.g, a.r);
}
//---

//,inline color4 color4_from_f3(float r, float g, float b) { return color4{r, g, b, scast<float>(1.0)}; }


// (1-r, 1-g, 1-b, a)
inline color4 color4_negative(const color4& a) {
	return color4{
		scast<float>(1.0) - a.r, 
		scast<float>(1.0) - a.g, 
		scast<float>(1.0) - a.b, 
		a.a
	};
}

// (r1*r2, g1*g2, b1*b2, a1*a2)
inline color4 color4_modulate(const color4& a, const color4& b) {
    return (a * b);
}

// CHECK: Use glm values
// Approximate values for each component's contribution to luminance.
// Based upon the NTSC standard described in ITU-R Recommendation BT.709.
// r = g = b = 0.2125*r + 0.7154*g + 0.0721*b
// Interpolate r,g,b between desaturated color and color.
// DesaturatedColor + s(Color - DesaturatedColor)
inline color4 color4_adjust_saturation(const color4& a, float s) {
    color4 out = color4::k_zero();
    const float grey = a.r * scast<float>(0.2125) + a.g * scast<float>(0.7154) + a.b * scast<float>(0.0721);

    out.r = grey + s * (a.r - grey);
    out.g = grey + s * (a.g - grey);
    out.b = grey + s * (a.b - grey);
    out.a = a.a;

    return out;
}

// Interpolate r,g,b between 50% grey and color.  Grey + s(Color - Grey)
inline color4 color4_adjust_contrast(const color4& a, float s) {
    color4 out = color4::k_zero();
    const float factor = scast<float>(0.5);
    
    out.r = factor + s * (a.r - factor);
    out.g = factor + s * (a.g - factor);
    out.b = factor + s * (a.b - factor);
    out.a = a.a;

    return out;
}


//---------------------------------------------------
// quat
//---------------------------------------------------

inline quat operator - (const quat& a) { return (-a.v); }

inline quat operator + (const quat& a, const quat& b) { return (a.v + b.v); }
inline quat operator - (const quat& a, const quat& b) { return (a.v - b.v); }
//inline quat operator * (const quat& a, const quat& b) { return (a.v * b.v); }
//inline quat operator / (const quat& a, const quat& b) { return (a.v / b.v); }

inline quat operator + (const quat& a, float s) { return (a.v + s); }
inline quat operator - (const quat& a, float s) { return (a.v - s); }
inline quat operator * (const quat& a, float s) { return (a.v * s); }
inline quat operator / (const quat& a, float s) { return (a.v / s); }

inline quat operator + (float s, const quat& a) { return (a.v + s); }
inline quat operator - (float s, const quat& a) { return (a.v - s); }
inline quat operator * (float s, const quat& a) { return (a.v * s); }
inline quat operator / (float s, const quat& a) { return (a.v / s); }

inline bool quat_equals_ep(const quat& a, const quat& b, float epsilon) { return vec4_equals_ep(a.v, b.v, epsilon); }
inline bool quat_equals_ep2(const quat& a, const quat& b) { return vec4_equals_ep2(a.v, b.v); }

inline bool operator == (const quat& a, const quat& b) { return (a.v == b.v); }
inline bool operator != (const quat& a, const quat& b) { return (a.v != b.v); }

inline bool operator > (const quat& a, const quat& b)	{ return (a.v > b.v); }
inline bool operator < (const quat& a, const quat& b)	{ return (a.v < b.v); }
inline bool operator >= (const quat& a, const quat& b)	{ return (a.v >= b.v); }
inline bool operator <= (const quat& a, const quat& b)	{ return (a.v <= b.v); }

// Quaternion multiplication. The result represents the rotation b followed by the rotation a. (out = b * a)
inline quat operator * (const quat& a, const quat& b) { 
	quat out = quat::k_zero();		
	out.x = (b.w * a.x) + (b.x * a.w) + (b.y * a.z) - (b.z * a.y);
	out.y = (b.w * a.y) - (b.x * a.z) + (b.y * a.w) + (b.z * a.x);
	out.z = (b.w * a.z) + (b.x * a.y) - (b.y * a.x) + (b.z * a.w);
	out.w = (b.w * a.w) - (b.x * a.x) - (b.y * a.y) - (b.z * a.z);	
	return out; 
}


//---------------------------------------------------
// plane
//---------------------------------------------------

inline plane operator - (const plane& a) { return (-a.v); }

inline plane operator + (const plane& a, float s) { return (a.v + s); }
inline plane operator - (const plane& a, float s) { return (a.v - s); }
inline plane operator * (const plane& a, float s) { return (a.v * s); }
inline plane operator / (const plane& a, float s) { return (a.v / s); }

inline plane operator + (float s, const plane& a) { return (a.v + s); }
inline plane operator - (float s, const plane& a) { return (a.v - s); }
inline plane operator * (float s, const plane& a) { return (a.v * s); }
inline plane operator / (float s, const plane& a) { return (a.v / s); }

inline bool plane_equals_ep(const plane& a, const plane& b, float epsilon) { return vec4_equals_ep(a.v, b.v, epsilon); }
inline bool plane_equals_ep2(const plane& a, const plane& b) { return vec4_equals_ep2(a.v, b.v); }

inline bool operator == (const plane& a, const plane& b) { return (a.v == b.v); }
inline bool operator != (const plane& a, const plane& b) { return (a.v != b.v); }

inline bool operator > (const plane& a, const plane& b)		{ return (a.v > b.v); }
inline bool operator < (const plane& a, const plane& b)		{ return (a.v < b.v); }
inline bool operator >= (const plane& a, const plane& b)	{ return (a.v >= b.v); }
inline bool operator <= (const plane& a, const plane& b)	{ return (a.v <= b.v); }


//D3DXPlaneDot
inline float plane_dot_vec4(const plane& p, const vec4& a) {
	// ax + by + cz + dw
    return (p.a*a.x + p.b*a.y + p.c*a.z + p.d*a.w);
}
//D3DXPlaneDotCoord
inline float plane_dot_coord(const plane& p, const vec3& a) {
	// ax + by + cz + d
    return (p.a*a.x + p.b*a.y + p.c*a.z + p.d);
}
//D3DXPlaneDotNormal
inline float plane_dot_normal(const plane& p, const vec3& a) {
	// ax + by + cz
    return (p.a*a.x + p.b*a.y + p.c*a.z);
}

inline plane plane_scale(const plane& a, float s) { return (a * s); }

// Normalize plane (so that |a, b, c| == 1)
inline plane plane_normalize(const plane& a) {
    plane out = plane::k_zero();    
    // only first 3 members used
    //norm = std::sqrt(a.a*a.a + a.b*a.b + a.c*a.c);
    float norm = vec3_length(a.normal);
    if (norm) {
        float inv_norm = scast<float>(1.0)/norm;
        for_range (i, 0, out.size()) {
			out[i] = a[i] * inv_norm;
		}
    } else {
        //out = plane::k_zero();	
        printf("Cannot normalize zero length vector. Zero vector returned. Error will propogate.\n");
    }
    return out;
}


//---------------------------------------------------
// mat3
//---------------------------------------------------

inline mat3 mat3_transpose(const mat3& ma) {
	return mat3(
		ma.r[0][0], ma.r[1][0], ma.r[2][0],
		ma.r[0][1], ma.r[1][1], ma.r[2][1],
		ma.r[0][2], ma.r[1][2], ma.r[2][2]
	);
}

//---------------------------------------------------
// mat4
//---------------------------------------------------

inline mat4 operator - (const mat4& a) { return vecnt_negate(a); }

inline mat4 operator + (const mat4& a, const mat4& b) { return vecnt_add(a, b); }
inline mat4 operator - (const mat4& a, const mat4& b) { return vecnt_sub(a, b); }

inline mat4 operator + (const mat4& a, float s) { return vecnt_add_s(a, s); }
inline mat4 operator - (const mat4& a, float s) { return vecnt_sub_s(a, s); }
inline mat4 operator * (const mat4& a, float s) { return vecnt_mul_s(a, s); }
inline mat4 operator / (const mat4& a, float s) { return vecnt_div_s(a, s); }

inline mat4 operator + (float s, const mat4& a) { return vecnt_add_s(a, s); }
inline mat4 operator - (float s, const mat4& a) { return vecnt_sub_s(a, s); }
inline mat4 operator * (float s, const mat4& a) { return vecnt_mul_s(a, s); }
inline mat4 operator / (float s, const mat4& a) { return vecnt_div_s(a, s); }

inline bool mat4_equals_ep(const mat4& a, const mat4& b, float epsilon) { return vecnt_is_equal_ep(a, b, epsilon); }
inline bool mat4_equals_ep2(const mat4& a, const mat4& b) { return vecnt_is_equal_ep2(a, b); }

inline bool operator == (const mat4& a, const mat4& b) { return vecnt_is_equal(a, b); }
inline bool operator != (const mat4& a, const mat4& b) { return vecnt_is_not_equal(a, b); }

inline bool operator > (const mat4& a, const mat4& b)	{ return vecnt_is_greater(a, b); }
inline bool operator < (const mat4& a, const mat4& b)	{ return vecnt_is_less(a, b); }
inline bool operator >= (const mat4& a, const mat4& b)	{ return vecnt_is_greater_equal(a, b); }
inline bool operator <= (const mat4& a, const mat4& b)	{ return vecnt_is_less_equal(a, b); }


// Multiplying in forward order like d3d
// for row order matrix storage
// The result represents the transformation B followed by the transformation A. (result = A * B)
// T(R(S(v))) = v*S*R*T = v*SRT
inline mat4 mat4_mul(const mat4& ma, const mat4& mb) {	
	return mat4(
		ma.r[0][0]*mb.r[0][0] + ma.r[0][1]*mb.r[1][0] + ma.r[0][2]*mb.r[2][0] + ma.r[0][3]*mb.r[3][0],
        ma.r[0][0]*mb.r[0][1] + ma.r[0][1]*mb.r[1][1] + ma.r[0][2]*mb.r[2][1] + ma.r[0][3]*mb.r[3][1],
        ma.r[0][0]*mb.r[0][2] + ma.r[0][1]*mb.r[1][2] + ma.r[0][2]*mb.r[2][2] + ma.r[0][3]*mb.r[3][2],
        ma.r[0][0]*mb.r[0][3] + ma.r[0][1]*mb.r[1][3] + ma.r[0][2]*mb.r[2][3] + ma.r[0][3]*mb.r[3][3],

        ma.r[1][0]*mb.r[0][0] + ma.r[1][1]*mb.r[1][0] + ma.r[1][2]*mb.r[2][0] + ma.r[1][3]*mb.r[3][0],
        ma.r[1][0]*mb.r[0][1] + ma.r[1][1]*mb.r[1][1] + ma.r[1][2]*mb.r[2][1] + ma.r[1][3]*mb.r[3][1],
        ma.r[1][0]*mb.r[0][2] + ma.r[1][1]*mb.r[1][2] + ma.r[1][2]*mb.r[2][2] + ma.r[1][3]*mb.r[3][2],
        ma.r[1][0]*mb.r[0][3] + ma.r[1][1]*mb.r[1][3] + ma.r[1][2]*mb.r[2][3] + ma.r[1][3]*mb.r[3][3],

        ma.r[2][0]*mb.r[0][0] + ma.r[2][1]*mb.r[1][0] + ma.r[2][2]*mb.r[2][0] + ma.r[2][3]*mb.r[3][0],
        ma.r[2][0]*mb.r[0][1] + ma.r[2][1]*mb.r[1][1] + ma.r[2][2]*mb.r[2][1] + ma.r[2][3]*mb.r[3][1],
        ma.r[2][0]*mb.r[0][2] + ma.r[2][1]*mb.r[1][2] + ma.r[2][2]*mb.r[2][2] + ma.r[2][3]*mb.r[3][2],
        ma.r[2][0]*mb.r[0][3] + ma.r[2][1]*mb.r[1][3] + ma.r[2][2]*mb.r[2][3] + ma.r[2][3]*mb.r[3][3],

        ma.r[3][0]*mb.r[0][0] + ma.r[3][1]*mb.r[1][0] + ma.r[3][2]*mb.r[2][0] + ma.r[3][3]*mb.r[3][0],
        ma.r[3][0]*mb.r[0][1] + ma.r[3][1]*mb.r[1][1] + ma.r[3][2]*mb.r[2][1] + ma.r[3][3]*mb.r[3][1],
        ma.r[3][0]*mb.r[0][2] + ma.r[3][1]*mb.r[1][2] + ma.r[3][2]*mb.r[2][2] + ma.r[3][3]*mb.r[3][2],
        ma.r[3][0]*mb.r[0][3] + ma.r[3][1]*mb.r[1][3] + ma.r[3][2]*mb.r[2][3] + ma.r[3][3]*mb.r[3][3]
	);
}

inline mat4 operator * (const mat4& ma, const mat4& mb) { return mat4_mul(ma, mb); }

// Only difference between D3D_Math row matrix math & gl/glm matrix (column notation in docs 
// but otherwise stored as row major d3d like) is reverse multiply of mat4*mat4, vec4*mat4.
// written in reverse order as b*a or T*v, but internally does a*b or v*T resulting in same values.
inline mat4 mat4_mul_gl(const mat4& ma, const mat4& mb) {	
	return mat4_mul(mb, ma);
}

inline vec4 vec4_mul_mat4(const vec4& va, const mat4& ma) {
	return vec4(
		va[0]*ma.r[0][0] + va[1]*ma.r[1][0] + va[2]*ma.r[2][0] + va[3]*ma.r[3][0],
        va[0]*ma.r[0][1] + va[1]*ma.r[1][1] + va[2]*ma.r[2][1] + va[3]*ma.r[3][1],
        va[0]*ma.r[0][2] + va[1]*ma.r[1][2] + va[2]*ma.r[2][2] + va[3]*ma.r[3][2],
        va[0]*ma.r[0][3] + va[1]*ma.r[1][3] + va[2]*ma.r[2][3] + va[3]*ma.r[3][3]
	);
}

inline vec4 mat4_mul_vec4(const mat4& ma, const vec4& va) {
	return vec4(
		 ma.r[0][0]*va[0] + ma.r[0][1]*va[1] + ma.r[0][2]*va[2] + ma.r[0][3]*va[3],
		 ma.r[1][0]*va[0] + ma.r[1][1]*va[1] + ma.r[1][2]*va[2] + ma.r[1][3]*va[3],
		 ma.r[2][0]*va[0] + ma.r[2][1]*va[1] + ma.r[2][2]*va[2] + ma.r[2][3]*va[3],
		 ma.r[3][0]*va[0] + ma.r[3][1]*va[1] + ma.r[3][2]*va[2] + ma.r[3][3]*va[3]
	);
}

inline vec4 operator * (const vec4& va, const mat4& ma) { return vec4_mul_mat4(va, ma); }
inline vec4 operator * (const mat4& ma, const vec4& va) { return mat4_mul_vec4(ma, va); }

inline vec4 vec4_mul_mat4_gl(const vec4& va, const mat4& ma) {
	return mat4_mul_vec4(ma, va);
}
inline vec4 mat4_mul_vec4_gl(const mat4& ma, const vec4& va) {
	return vec4_mul_mat4(va, ma);
}


inline bool mat4_is_identity(const mat4& ma) {
	return (ma == mat4::k_identity());
}

inline mat4 mat4_transpose(const mat4& ma) {
	return mat4(
		ma.r[0][0], ma.r[1][0], ma.r[2][0], ma.r[3][0],
		ma.r[0][1], ma.r[1][1], ma.r[2][1], ma.r[3][1],
		ma.r[0][2], ma.r[1][2], ma.r[2][2], ma.r[3][2],
		ma.r[0][3], ma.r[1][3], ma.r[2][3], ma.r[3][3]
	);
}


//-----------------------
inline float mat4_determinant(const mat4& ma) {

	//-----------------------------------------------------------------------
	// | a b c d |     | f g h |     | e g h |     | e f h |     | e f g |
    // | e f g h | = a | j k l | - b | i k l | + c | i j l | - d | i j k |
    // | i j k l |     | n o p |     | m o p |     | m n p |     | m n o |
    // | m n o p |
    //
    //   | f g h |
    // a | j k l | = a ( f ( kp - lo ) - g ( jp - ln ) + h ( jo - kn ) )
    //   | n o p |
    //
    //   | e g h |     
    // b | i k l | = b ( e ( kp - lo ) - g ( ip - lm ) + h ( io - km ) )
    //   | m o p |     
    //
    //   | e f h |
    // c | i j l | = c ( e ( jp - ln ) - f ( ip - lm ) + h ( in - jm ) )
    //   | m n p |
    //
    //   | e f g |
    // d | i j k | = d ( e ( jo - kn ) - f ( io - km ) + g ( in - jm ) )
    //   | m n o |
	//-----------------------------------------------------------------------

	float a = ma.r[0][0], b = ma.r[0][1], c = ma.r[0][2], d = ma.r[0][3];
    float e = ma.r[1][0], f = ma.r[1][1], g = ma.r[1][2], h = ma.r[1][3];
    float i = ma.r[2][0], j = ma.r[2][1], k = ma.r[2][2], l = ma.r[2][3];
    float m = ma.r[3][0], n = ma.r[3][1], o = ma.r[3][2], p = ma.r[3][3];

    float kp_lo = k * p - l * o;
    float jp_ln = j * p - l * n;
    float jo_kn = j * o - k * n;
    float ip_lm = i * p - l * m;
    float io_km = i * o - k * m;
    float in_jm = i * n - j * m;

    //return    a * (f * kp_lo - g * jp_ln + h * jo_kn) 
    //        - b * (e * kp_lo - g * ip_lm + h * io_km) 
    //        + c * (e * jp_ln - f * ip_lm + h * in_jm) 
    //        - d * (e * jo_kn - f * io_km + g * in_jm);


	float c11 = +(f * kp_lo - g * jp_ln + h * jo_kn);
    float c12 = -(e * kp_lo - g * ip_lm + h * io_km);
    float c13 = +(e * jp_ln - f * ip_lm + h * in_jm);
    float c14 = -(e * jo_kn - f * io_km + g * in_jm);

    float det = a * c11 + b * c12 + c * c13 + d * c14;

    return det;
}

// Calculate inverse of matrix. Inversion may fail, in which case NULL will be returned.
// The determinant of M is also returned if determinant is not zero (matrix is invertible).
//mat4 mat4_inverse(float& determinant, const mat4& ma)
//bool mat4_inverse(mat4& out, const mat4& ma);
inline mat4 mat4_inverse(const mat4& ma) {

	//--------------------------------------------------------------------------------- 
    // inv(M) = (1/det(M)) * A
	// A is adjugate (adjoint) of M, where: A = transpose(C)
	// C is Cofactor matrix of M, where:
	// Cij   = (-1)^i+j * det(M_ij)
	//
	//     | a b c d |
    // M = | e f g h |
    //     | i j k l |
    //     | m n o p |
    //
    // First row values for C are also used for calculating det.
    // det = a * c11 + b * c12 + c * c13 + d * c14;
    // First Row
    //					| f g h |
    // C11   = (-1)^2	| j k l | = + ( f ( kp - lo ) - g ( jp - ln ) + h ( jo - kn ) )
    //					| n o p |
    //
    //					| e g h |
    // C12   = (-1)^3	| i k l | = - ( e ( kp - lo ) - g ( ip - lm ) + h ( io - km ) )
    //					| m o p |
    //
    //					| e f h |
    // C13   = (-1)^4	| i j l | = + ( e ( jp - ln ) - f ( ip - lm ) + h ( in - jm ) )
    //					| m n p |
    //
    //					| e f g |
    // C14   = (-1)^5	| i j k | = - ( e ( jo - kn ) - f ( io - km ) + g ( in - jm ) )
    //					| m n o |
    //
    // Second Row
    //					| b c d |
    // C21   = (-1)^3	| j k l | = - ( b ( kp - lo ) - c ( jp - ln ) + d ( jo - kn ) )
    //					| n o p |
    //
    //					| a c d |
    // C22   = (-1)^4	| i k l | = + ( a ( kp - lo ) - c ( ip - lm ) + d ( io - km ) )
    //					| m o p |
    //
    //					| a b d |
    // C23   = (-1)^5	| i j l | = - ( a ( jp - ln ) - b ( ip - lm ) + d ( in - jm ) )
    //					| m n p |
    //
    //					| a b c |
    // C24   = (-1)^6	| i j k | = + ( a ( jo - kn ) - b ( io - km ) + c ( in - jm ) )
    //					| m n o |
    //
    // Third Row
    //					| b c d |
    // C31   = (-1)^4	| f g h | = + ( b ( gp - ho ) - c ( fp - hn ) + d ( fo - gn ) )
    //					| n o p |
    //
    //					| a c d |
    // C32   = (-1)^5	| e g h | = - ( a ( gp - ho ) - c ( ep - hm ) + d ( eo - gm ) )
    //					| m o p |
    //
    //					| a b d |
    // C33   = (-1)^6	| e f h | = + ( a ( fp - hn ) - b ( ep - hm ) + d ( en - fm ) )
    //					| m n p |
    //
    //					| a b c |
    // C34   = (-1)^7	| e f g | = - ( a ( fo - gn ) - b ( eo - gm ) + c ( en - fm ) )
    //					| m n o |
    //
    // Fourth Row
    //					| b c d |
    // C41   = (-1)^5	| f g h | = - ( b ( gl - hk ) - c ( fl - hj ) + d ( fk - gj ) )
    //					| j k l |
    //
    //					| a c d |
    // C42   = (-1)^6	| e g h | = + ( a ( gl - hk ) - c ( el - hi ) + d ( ek - gi ) )
    //					| i k l |
    //
    //					| a b d |
    // C43   = (-1)^7	| e f h | = - ( a ( fl - hj ) - b ( el - hi ) + d ( ej - fi ) )
    //					| i j l |
    //
    //					| a b c |
    // C44   = (-1)^8	| e f g | = + ( a ( fk - gj ) - b ( ek - gi ) + c ( ej - fi ) )
    //					| i j k |
    //
    //---------------------------------------------------------------------------------

	float a = ma.r[0][0], b = ma.r[0][1], c = ma.r[0][2], d = ma.r[0][3];
    float e = ma.r[1][0], f = ma.r[1][1], g = ma.r[1][2], h = ma.r[1][3];
    float i = ma.r[2][0], j = ma.r[2][1], k = ma.r[2][2], l = ma.r[2][3];
    float m = ma.r[3][0], n = ma.r[3][1], o = ma.r[3][2], p = ma.r[3][3];

    float kp_lo = k * p - l * o;
    float jp_ln = j * p - l * n;
    float jo_kn = j * o - k * n;
    float ip_lm = i * p - l * m;
    float io_km = i * o - k * m;
    float in_jm = i * n - j * m;

    float c11 = +(f * kp_lo - g * jp_ln + h * jo_kn);
    float c12 = -(e * kp_lo - g * ip_lm + h * io_km);
    float c13 = +(e * jp_ln - f * ip_lm + h * in_jm);
    float c14 = -(e * jo_kn - f * io_km + g * in_jm);

    float det = a * c11 + b * c12 + c * c13 + d * c14;

    mat4 out = mat4::k_zero();

    // NaN safe
    if (!(std::fabs(det) >= FLT_EPSILON)) {
        const float nan = std::numeric_limits<float>::quiet_NaN();
        // out is zero matrix
        //out = mat4(nan, nan, nan, nan,
        //            nan, nan, nan, nan,
        //            nan, nan, nan, nan,
        //            nan, nan, nan, nan);
        //return false;

        printf("Cannot invert matrix. Zero Matrix returned. Error will propogate.\n");
        return out;
    }

    float inv_det = scast<float>(1.0) / det;

    // row |c11, c12, c13, c14| of C transposed to col (0, 4, 8, 12) of A  
    // and divided by det for final matrix values.

    // First Row |c11, c12, c13, c14|, transposed & divided by det
    out.r[0][0] = c11 * inv_det;
    out.r[1][0] = c12 * inv_det;
    out.r[2][0] = c13 * inv_det;
    out.r[3][0] = c14 * inv_det;

    // Second Row |c21, c22, c23, c24|, transposed & divided by det
    out.r[0][1] = -(b * kp_lo - c * jp_ln + d * jo_kn) * inv_det;
    out.r[1][1] = +(a * kp_lo - c * ip_lm + d * io_km) * inv_det;
    out.r[2][1] = -(a * jp_ln - b * ip_lm + d * in_jm) * inv_det;
    out.r[3][1] = +(a * jo_kn - b * io_km + c * in_jm) * inv_det;

    // Third Row |c31, c32, c33, c34|, transposed & divided by det
    float gp_ho = g * p - h * o;
    float fp_hn = f * p - h * n;
    float fo_gn = f * o - g * n;
    float ep_hm = e * p - h * m;
    float eo_gm = e * o - g * m;
    float en_fm = e * n - f * m;
    
    out.r[0][2] = +(b * gp_ho - c * fp_hn + d * fo_gn) * inv_det;
    out.r[1][2] = -(a * gp_ho - c * ep_hm + d * eo_gm) * inv_det;
    out.r[2][2] = +(a * fp_hn - b * ep_hm + d * en_fm) * inv_det;
    out.r[3][2] = -(a * fo_gn - b * eo_gm + c * en_fm) * inv_det;

    // Fourth Row |c41, c42, c43, c44|, transposed & divided by det
    float gl_hk = g * l - h * k;
    float fl_hj = f * l - h * j;
    float fk_gj = f * k - g * j;
    float el_hi = e * l - h * i;
    float ek_gi = e * k - g * i;
    float ej_fi = e * j - f * i;
    
    out.r[0][3] = -(b * gl_hk - c * fl_hj + d * fk_gj) * inv_det;
    out.r[1][3] = +(a * gl_hk - c * el_hi + d * ek_gi) * inv_det;
    out.r[2][3] = -(a * fl_hj - b * el_hi + d * ej_fi) * inv_det;
    out.r[3][3] = +(a * fk_gj - b * ek_gi + c * ej_fi) * inv_det;

    //return true;
    return out;
}
//-----------------------

// angle in radians
// Build a matrix which rotates around the X axis
// Creates an x-axis rotation matrix, centered on the origin.
inline mat4 mat4_rotation_x(float angle) {
    const float sin_a = std::sinf(angle);
    const float cos_a = std::cosf(angle);

    return mat4(
            scast<float>(1.0),    scast<float>(0.0),    scast<float>(0.0),    scast<float>(0.0),
            scast<float>(0.0),    cos_a,				sin_a,				scast<float>(0.0),
            scast<float>(0.0),    -sin_a,				cos_a,				scast<float>(0.0),
            scast<float>(0.0),    scast<float>(0.0),    scast<float>(0.0),    scast<float>(1.0)
	);
}

// Build a matrix which rotates around the Y axis
inline mat4 mat4_rotation_y(float angle) {
    const float sin_a = std::sinf(angle);
    const float cos_a = std::cosf(angle);

    return mat4(
            cos_a,				scast<float>(0.0),    -sin_a,				scast<float>(0.0),
            scast<float>(0.0),	scast<float>(1.0),    scast<float>(0.0),    scast<float>(0.0),
            sin_a,				scast<float>(0.0),    cos_a,				scast<float>(0.0),
            scast<float>(0.0),    scast<float>(0.0),    scast<float>(0.0),    scast<float>(1.0)
	);
}

// Build a matrix which rotates around the Z axis
inline mat4 mat4_rotation_z(float angle) {
    const float sin_a = std::sinf(angle);
    const float cos_a = std::cosf(angle);
    
    return mat4(
            cos_a,				sin_a,				scast<float>(0.0),    scast<float>(0.0),
            -sin_a,				cos_a,				scast<float>(0.0),    scast<float>(0.0),
            scast<float>(0.0),    scast<float>(0.0),    scast<float>(1.0),    scast<float>(0.0),
            scast<float>(0.0),    scast<float>(0.0),    scast<float>(0.0),    scast<float>(1.0)
	);
}


// Build a matrix which rotates around an arbitrary axis
//mat4 mat4_glm_rotation_xyz(float angle, const vec3& axis)
//D3DXMatrixRotationAxis
inline mat4 mat4_rotation_axis(const vec3& axis, float angle) {    
    vec3 nv = vec3_normalize(axis);
    const float sa = std::sinf(angle);
    const float ca = std::cosf(angle);
    const float cd = scast<float>(1.0) - ca;    

    return mat4(
            cd*nv.x*nv.x + ca,          cd*nv.y*nv.x + sa*nv.z,     cd*nv.z*nv.x - sa*nv.y,     scast<float>(0.0),
            cd*nv.x*nv.y - sa*nv.z,     cd*nv.y*nv.y + ca,          cd*nv.z*nv.y + sa*nv.x,     scast<float>(0.0),
            cd*nv.x*nv.z + sa*nv.y,     cd*nv.y*nv.z - sa*nv.x,     cd*nv.z*nv.z + ca,          scast<float>(0.0),
            scast<float>(0.0),            scast<float>(0.0),            scast<float>(0.0),            scast<float>(1.0)
        );
}


inline mat4 mat4_translation(const vec3& position) {
    return mat4(
            scast<float>(1.0),		scast<float>(0.0),		scast<float>(0.0),		scast<float>(0.0),
            scast<float>(0.0),		scast<float>(1.0),		scast<float>(0.0),		scast<float>(0.0),
            scast<float>(0.0),		scast<float>(0.0),		scast<float>(1.0),		scast<float>(0.0),
            position.x,				position.y,				position.z,				scast<float>(1.0)
	);
}

inline mat4 mat4_scaling(const vec3& scales) {
    return mat4(
            scales.x,			scast<float>(0.0),	scast<float>(0.0),	scast<float>(0.0),
            scast<float>(0.0),	scales.y,			scast<float>(0.0),	scast<float>(0.0),
            scast<float>(0.0),	scast<float>(0.0),	scales.z,			scast<float>(0.0),
            scast<float>(0.0),	scast<float>(0.0),	scast<float>(0.0),	scast<float>(1.0)
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
    vec3 right = vec3::k_zero();
    vec3 upn = vec3::k_zero();
    vec3 dir = vec3::k_zero();

    dir = vec3_normalize(at - eye);
    right = vec3_cross(up, dir);
    upn = vec3_cross(dir, right);
    right = vec3_normalize(right);
    upn = vec3_normalize(upn);

    return mat4(
        right.x,			   upn.x,				dir.x,				 scast<float>(0.0),
        right.y,			   upn.y,				dir.y,				 scast<float>(0.0),
        right.z,			   upn.z,				dir.z,				 scast<float>(0.0),
        -vec3_dot(right, eye), -vec3_dot(upn, eye), -vec3_dot(dir, eye), scast<float>(1.0)
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
    vec3 right = vec3::k_zero(); 
    vec3 upn = vec3::k_zero();
    vec3 dir = vec3::k_zero();

    dir = vec3_normalize(at - eye);
    right = vec3_cross(up, dir);
    upn = vec3_cross(dir, right);
    right = vec3_normalize(right);
    upn = vec3_normalize(upn);

    return mat4(
        -right.x,			  upn.x,			   -dir.x,		       scast<float>(0.0),
        -right.y,			  upn.y,			   -dir.y,             scast<float>(0.0),
        -right.z,			  upn.z,			   -dir.z,			   scast<float>(0.0),
        vec3_dot(right, eye), -vec3_dot(upn, eye), vec3_dot(dir, eye), scast<float>(1.0)
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
	const float tan_half_fovy = std::tan(fovy * scast<float>(0.5));
	const float x_scale = scast<float>(1.0)/(aspect * tan_half_fovy);
	const float y_scale = scast<float>(1.0)/tan_half_fovy;

    return mat4(
        x_scale,		 scast<float>(0.0), scast<float>(0.0), scast<float>(0.0), 
        scast<float>(0.0), y_scale,		  scast<float>(0.0), scast<float>(0.0), 
        scast<float>(0.0), scast<float>(0.0), zf/(zf-zn),	   scast<float>(1.0), 
        scast<float>(0.0), scast<float>(0.0), (zf*zn)/(zn-zf), scast<float>(0.0) 
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
	const float tan_half_fovy = std::tan(fovy * scast<float>(0.5));
	const float x_scale = scast<float>(1.0)/(aspect * tan_half_fovy);
	const float y_scale = scast<float>(1.0)/tan_half_fovy;

    return mat4(
        x_scale,		 scast<float>(0.0), scast<float>(0.0), scast<float>(0.0), 
        scast<float>(0.0), y_scale,		  scast<float>(0.0), scast<float>(0.0), 
        scast<float>(0.0), scast<float>(0.0), zf/(zn-zf),	   -scast<float>(1.0), 
        scast<float>(0.0), scast<float>(0.0), (zf*zn)/(zn-zf), scast<float>(0.0)
	);    
}





//==================================================================
inline vec3 vec3_from_vec2(const vec2& a, float z) { return vec3(a.x, a.y, z); }
inline vec3 vec3_from_vec4(const vec4& a) { return vec3(a.x, a.y, a.z); }
inline vec4 vec4_from_vec2(const vec2& a, float z, float w) { return vec4(a.x, a.y, z, w); }
inline vec4 vec4_from_vec3(const vec3& a, float w) { return vec4(a.x, a.y, a.z, w); }
inline vec3 vec3_from_quat(const quat& a) { return vec3(a.x, a.y, a.z); }
inline vec3 vec3_from_plane(const plane& p) { return vec3(p.a, p.b, p.c); }
inline vec4 vec4_from_plane(const plane& p) { return vec4(p.a, p.b, p.c, p.d); }
inline plane plane_from_vec4(const vec4& a) { return plane(a.x, a.y, a.z, a.w); }


//----------------
// vec transform
//----------------

// Transform (x, y, 0, 1) by matrix, project result back into w=1.
//D3DXVec2TransformCoord
inline vec2 vec2_transform_coord(const vec2& a, const mat4& ma) {	
    float norm = ma.r[0][3] * a.x + ma.r[1][3] * a.y + ma.r[3][3];
	float inv_norm = scast<float>(1.0)/norm;

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
	float inv_norm = scast<float>(1.0)/norm;

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
    vec3 out = vec3::k_zero();
    mat4 m = mat4::k_identity();

    m = world * view * proj;

    out = vec3_transform_coord(a, m);

    out.x = vp.x + (scast<float>(1.0) + out.x) * vp.w*scast<float>(0.5);
    out.y = vp.y + (scast<float>(1.0) - out.y) * vp.h*scast<float>(0.5);
    out.z = vp.zn + out.z * (vp.zf - vp.zn);

    return out;
}
// Project vector from screen space into object space
//D3DXVec3Unproject
inline vec3 vec3_unproject(const vec3& a, const viewport& vp, const mat4& proj, const mat4& view, const mat4& world) {
    vec3 out = vec3::k_zero();
    mat4 m = mat4::k_identity();

    m = world * view * proj;
    m = mat4_inverse(m);    

    out = a;

    out.x = scast<float>(2.0)*(out.x - vp.x) / vp.w - scast<float>(1.0);
    out.y = scast<float>(1.0) - scast<float>(2.0)*(out.y - vp.y)/vp.h;
    out.z = (out.z - vp.zn)/(vp.zf - vp.zn);

    out = vec3_transform_coord(out, m);
    return out;
}
//--------------------------------------------


// UNCHECKED

//--------------------------------------





//-------------------------------------------------------------------



// END UNCHECKED
}




