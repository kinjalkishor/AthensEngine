#pragma once

#include <stdio.h>
#include <limits>

#include "bs_types.h"
#include "bs_math.h"
#include "bs_gmath_types.h"


namespace gm
{


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
    explicit quat(float f) : x(f), y(f), z(f), w(f) {}
	explicit quat(vec3 axis, float rotation) : axis(axis), rotation(rotation) {}
	explicit quat(vec4 a) : v(a) {}

	constexpr static int size() { return 4; }	

	float* data()							{ return &e[0]; }
	const float* data() const				{ return &e[0]; }
	float& operator [](int i)				{ return e[i]; }
	const float& operator [](int i) const	{ return e[i]; }    	

    const static quat k_zero() { return quat(0, 0, 0, 0); }
    const static quat k_identity() { return quat(0, 0, 0, 1); }
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
    explicit plane(float f) : a(f), b(f), c(f), d(f) {}
	explicit plane(const vec3& normal, float dist) : normal(normal), dist(dist) {}
	explicit plane(vec4 a) : v(a) {}

	constexpr static int size() { return 4; }	

	float* data()							{ return &e[0]; }
	const float* data() const				{ return &e[0]; }
	float& operator [](int i)				{ return e[i]; }
	const float& operator [](int i) const	{ return e[i]; }    	

    const static plane k_zero() { return plane(0, 0, 0, 0); }
    //const static plane k_default() { return plane(0, 1, 0, 0); } //irr
};



//--------------------
class viewport {
public:
    float x, y, w, h;
    float n, f;
};
//--------------------


//========================================================================

template<class T> inline T tmin(const T a, const T b) { return (a < b) ? a : b; }
template<class T> inline T tmax(const T a, const T b) { return (a > b) ? a : b; }

// returns x in [low, high].
template<class T>
inline T clamp(const T& x, const T& low, const T& high) {
    if (x < low) { return low; }
    if (x > high) { return high; }
    return x;       
}
//---------------------------------------------------


inline const vec3 k_vec3_one = vec3(1, 1, 1);
inline const vec3 k_vec3_origin = vec3(0, 0, 0);

//---------------------------------------------------
// vec2
//---------------------------------------------------
inline vec2 operator - (const vec2& a) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = -a[i]; } return out; }

inline vec2 operator + (const vec2& a, const vec2& b) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = a[i] + b[i]; } return out; }
inline vec2 operator - (const vec2& a, const vec2& b) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = a[i] - b[i]; } return out; }
inline vec2 operator * (const vec2& a, const vec2& b) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = a[i] * b[i]; } return out; }
inline vec2 operator / (const vec2& a, const vec2& b) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = a[i] / b[i]; } return out; }

inline vec2 operator + (const vec2& a, float s) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = a[i] + s; } return out; }
inline vec2 operator - (const vec2& a, float s) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = a[i] - s; } return out; }
inline vec2 operator * (const vec2& a, float s) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = a[i] * s; } return out; }
inline vec2 operator / (const vec2& a, float s) { float inv_s = static_cast<float>(1.0)/s; vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = a[i] * inv_s; } return out; }

inline vec2 operator + (float s, const vec2& a) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = a[i] + s; } return out; }
inline vec2 operator - (float s, const vec2& a) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = a[i] - s; } return out; }
inline vec2 operator * (float s, const vec2& a) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = a[i] * s; } return out; }
inline vec2 operator / (float s, const vec2& a) { float inv_s = static_cast<float>(1.0)/s; vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = a[i] * inv_s; } return out; }


inline bool operator == (const vec2& a, const vec2& b) { for (int i=0; i < vec2::size(); ++i) { if (!(a[i] == b[i])) { return false; } }	return true; }
inline bool operator != (const vec2& a, const vec2& b) { for (int i=0; i < vec2::size(); ++i) { if (!(a[i] == b[i])) { return true; } }	return false; }


inline bool vec2_equals_ep(const vec2& a, const vec2& b, float epsilon) { for (int i=0; i < vec2::size(); ++i) { if (!(mf::equals_ep(a[i], b[i], epsilon))) { return false; } }	return true; }
inline bool vec2_equals_ep2(const vec2& a, const vec2& b) { for (int i=0; i < vec2::size(); ++i) { if (!(mf::equals2(a[i], b[i]))) { return false; } }	return true; }

inline bool operator < (const vec2& a, const vec2& b)	{ for (int i=0; i < vec2::size(); ++i) { if (!(a[i] < b[i])) { return false; } }	return true; }
inline bool operator > (const vec2& a, const vec2& b)	{ for (int i=0; i < vec2::size(); ++i) { if (!(a[i] > b[i])) { return false; } }	return true; }
inline bool operator <= (const vec2& a, const vec2& b)	{ for (int i=0; i < vec2::size(); ++i) { if (!(a[i] <= b[i])) { return false; } }	return true; }
inline bool operator >= (const vec2& a, const vec2& b)	{ for (int i=0; i < vec2::size(); ++i) { if (!(a[i] >= b[i])) { return false; } }	return true; }


inline float vec2_dot(const vec2& a, const vec2& b) { return (a.x*b.x + a.y*b.y); }
inline float vec2_length_sq(const vec2& a) { return (a.x*a.x + a.y*a.y); }
inline float vec2_length(const vec2& a) { return std::sqrt(a.x*a.x + a.y*a.y); }
inline float vec2_distance_sq(const vec2& a, const vec2& b) { return ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)); }
inline float vec2_distance(const vec2& a, const vec2& b) { return std::sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)); }

inline vec2 vec2_scale(const vec2& a, float s) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = a[i] * s; } return out; }
inline vec2 vec2_lerp(const vec2& a, const vec2& b, float s) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = mf::lerp(a[i], b[i], s); } return out; }
inline vec2 vec2_min(const vec2& a, const vec2& b) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = tmin(a[i], b[i]); } return out; }
inline vec2 vec2_max(const vec2& a, const vec2& b) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = tmax(a[i], b[i]); } return out; }
inline vec2 vec2_clamp(const vec2& a, const vec2& min, const vec2& max) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = clamp(a[i], min[i], max[i]); } return out; }

inline vec2 vec2_normalize(const vec2& a) { 
    vec2 out = vec2::k_zero(); 
	float length = vec2_length(a);

	if (length) {
		float inv_length = static_cast<float>(1.0)/length;
		//out = a * inv_length;	
        for (int i=0; i < vec2::size(); ++i) {
			out[i] = a[i] * inv_length;
		}
	} else {
        out = vec2::k_zero();
        printf("Cannot normalize zero length vector. Zero vector returned. Error will propogate.\n");			
	}
		
    return out;
}

// Z component of ((x1,y1,0) cross (x2,y2,0))
// If the value of the z-component is positive, the vector V2 is counterclockwise from the vector V1. This information is useful for back-face culling.
inline float vec2_ccw(const vec2& a, const vec2& b) { return (a.x*b.y - a.y*b.x); }

inline vec2 vec2_ma(const vec2& a, const vec2& b, float s) { vec2 out = vec2::k_zero(); for (int i=0; i < vec2::size(); ++i) { out[i] = a[i] + s*b[i]; } return out; }


//---------------------------------------------------
// vec3
//---------------------------------------------------
inline vec3 operator - (const vec3& a) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = -a[i]; } return out; }

inline vec3 operator + (const vec3& a, const vec3& b) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = a[i] + b[i]; } return out; }
inline vec3 operator - (const vec3& a, const vec3& b) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = a[i] - b[i]; } return out; }
inline vec3 operator * (const vec3& a, const vec3& b) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = a[i] * b[i]; } return out; }
inline vec3 operator / (const vec3& a, const vec3& b) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = a[i] / b[i]; } return out; }

inline vec3 operator + (const vec3& a, float s) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = a[i] + s; } return out; }
inline vec3 operator - (const vec3& a, float s) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = a[i] - s; } return out; }
inline vec3 operator * (const vec3& a, float s) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = a[i] * s; } return out; }
inline vec3 operator / (const vec3& a, float s) { float inv_s = static_cast<float>(1.0)/s; vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = a[i] * inv_s; } return out; }

inline vec3 operator + (float s, const vec3& a) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = a[i] + s; } return out; }
inline vec3 operator - (float s, const vec3& a) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = a[i] - s; } return out; }
inline vec3 operator * (float s, const vec3& a) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = a[i] * s; } return out; }
inline vec3 operator / (float s, const vec3& a) { float inv_s = static_cast<float>(1.0)/s; vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = a[i] * inv_s; } return out; }


inline bool operator == (const vec3& a, const vec3& b) { for (int i=0; i < vec3::size(); ++i) { if (!(a[i] == b[i])) { return false; } }	return true; }
inline bool operator != (const vec3& a, const vec3& b) { for (int i=0; i < vec3::size(); ++i) { if (!(a[i] == b[i])) { return true; } }	return false; }


inline bool vec3_equals_ep(const vec3& a, const vec3& b, float epsilon) { for (int i=0; i < vec3::size(); ++i) { if (!(mf::equals_ep(a[i], b[i], epsilon))) { return false; } }	return true; }
inline bool vec3_equals_ep2(const vec3& a, const vec3& b) { for (int i=0; i < vec3::size(); ++i) { if (!(mf::equals2(a[i], b[i]))) { return false; } }	return true; }

inline bool operator < (const vec3& a, const vec3& b)	{ for (int i=0; i < vec3::size(); ++i) { if (!(a[i] < b[i])) { return false; } }	return true; }
inline bool operator > (const vec3& a, const vec3& b)	{ for (int i=0; i < vec3::size(); ++i) { if (!(a[i] > b[i])) { return false; } }	return true; }
inline bool operator <= (const vec3& a, const vec3& b)	{ for (int i=0; i < vec3::size(); ++i) { if (!(a[i] <= b[i])) { return false; } }	return true; }
inline bool operator >= (const vec3& a, const vec3& b)	{ for (int i=0; i < vec3::size(); ++i) { if (!(a[i] >= b[i])) { return false; } }	return true; }


inline float vec3_dot(const vec3& a, const vec3& b) { return (a.x*b.x + a.y*b.y + a.z*b.z); }
inline float vec3_length_sq(const vec3& a) { return (a.x*a.x + a.y*a.y + a.z*a.z); }
inline float vec3_length(const vec3& a) { return std::sqrt(a.x*a.x + a.y*a.y + a.z*a.z); }
inline float vec3_distance_sq(const vec3& a, const vec3& b) { return ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z)); }
inline float vec3_distance(const vec3& a, const vec3& b) { return std::sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z)); }

inline vec3 vec3_scale(const vec3& a, float s) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = a[i] * s; } return out; }
inline vec3 vec3_lerp(const vec3& a, const vec3& b, float s) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = mf::lerp(a[i], b[i], s); } return out; }
inline vec3 vec3_min(const vec3& a, const vec3& b) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = tmin(a[i], b[i]); } return out; }
inline vec3 vec3_max(const vec3& a, const vec3& b) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = tmax(a[i], b[i]); } return out; }
inline vec3 vec3_clamp(const vec3& a, const vec3& min, const vec3& max) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = clamp(a[i], min[i], max[i]); } return out; }


inline vec3 vec3_normalize(const vec3& a) { 
    vec3 out = vec3::k_zero(); 
	float length = vec3_length(a);

	if (length) {
		float inv_length = static_cast<float>(1.0)/length;
		//out = a * inv_length;	
        for (int i=0; i < vec3::size(); ++i) {
			out[i] = a[i] * inv_length;
		}
	} else {
        out = vec3::k_zero();
        printf("Cannot normalize zero length vector. Zero vector returned. Error will propogate.\n");			
	}
		
    return out;
}


inline vec3 vec3_cross(const vec3& a, const vec3& b) {
	vec3 out = vec3::k_zero();
	out.x = a.y*b.z - a.z*b.y;
	out.y = a.z*b.x - a.x*b.z;
	out.z = a.x*b.y - a.y*b.x;
	return out;
}

inline vec3 vec3_ma(const vec3& a, const vec3& b, float s) { vec3 out = vec3::k_zero(); for (int i=0; i < vec3::size(); ++i) { out[i] = a[i] + s*b[i]; } return out; }

//---------------------------------------------------
// vec4
//---------------------------------------------------
inline vec4 operator - (const vec4& a) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = -a[i]; } return out; }

inline vec4 operator + (const vec4& a, const vec4& b) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = a[i] + b[i]; } return out; }
inline vec4 operator - (const vec4& a, const vec4& b) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = a[i] - b[i]; } return out; }
inline vec4 operator * (const vec4& a, const vec4& b) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = a[i] * b[i]; } return out; }
inline vec4 operator / (const vec4& a, const vec4& b) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = a[i] / b[i]; } return out; }

inline vec4 operator + (const vec4& a, float s) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = a[i] + s; } return out; }
inline vec4 operator - (const vec4& a, float s) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = a[i] - s; } return out; }
inline vec4 operator * (const vec4& a, float s) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = a[i] * s; } return out; }
inline vec4 operator / (const vec4& a, float s) { float inv_s = static_cast<float>(1.0)/s; vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = a[i] * inv_s; } return out; }

inline vec4 operator + (float s, const vec4& a) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = a[i] + s; } return out; }
inline vec4 operator - (float s, const vec4& a) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = a[i] - s; } return out; }
inline vec4 operator * (float s, const vec4& a) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = a[i] * s; } return out; }
inline vec4 operator / (float s, const vec4& a) { float inv_s = static_cast<float>(1.0)/s; vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = a[i] * inv_s; } return out; }


inline bool operator == (const vec4& a, const vec4& b) { for (int i=0; i < vec4::size(); ++i) { if (!(a[i] == b[i])) { return false; } }	return true; }
inline bool operator != (const vec4& a, const vec4& b) { for (int i=0; i < vec4::size(); ++i) { if (!(a[i] == b[i])) { return true; } }	return false; }


inline bool vec4_equals_ep(const vec4& a, const vec4& b, float epsilon) { for (int i=0; i < vec4::size(); ++i) { if (!(mf::equals_ep(a[i], b[i], epsilon))) { return false; } }	return true; }
inline bool vec4_equals_ep2(const vec4& a, const vec4& b) { for (int i=0; i < vec4::size(); ++i) { if (!(mf::equals2(a[i], b[i]))) { return false; } }	return true; }

inline bool operator < (const vec4& a, const vec4& b)	{ for (int i=0; i < vec4::size(); ++i) { if (!(a[i] < b[i])) { return false; } }	return true; }
inline bool operator > (const vec4& a, const vec4& b)	{ for (int i=0; i < vec4::size(); ++i) { if (!(a[i] > b[i])) { return false; } }	return true; }
inline bool operator <= (const vec4& a, const vec4& b)	{ for (int i=0; i < vec4::size(); ++i) { if (!(a[i] <= b[i])) { return false; } }	return true; }
inline bool operator >= (const vec4& a, const vec4& b)	{ for (int i=0; i < vec4::size(); ++i) { if (!(a[i] >= b[i])) { return false; } }	return true; }

inline float vec4_dot(const vec4& a, const vec4& b) { return (a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w); }
inline float vec4_length_sq(const vec4& a) { return (a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w); }
inline float vec4_length(const vec4& a) { return std::sqrt(a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w); }
inline float vec4_distance_sq(const vec4& a, const vec4& b) { return ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z) + (a.w - b.w)*(a.w - b.w)); }
inline float vec4_distance(const vec4& a, const vec4& b) { return std::sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z) + (a.w - b.w)*(a.w - b.w)); }

inline vec4 vec4_scale(const vec4& a, float s) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = a[i] * s; } return out; }
inline vec4 vec4_lerp(const vec4& a, const vec4& b, float s) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = mf::lerp(a[i], b[i], s); } return out; }
inline vec4 vec4_min(const vec4& a, const vec4& b) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = tmin(a[i], b[i]); } return out; }
inline vec4 vec4_max(const vec4& a, const vec4& b) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = tmax(a[i], b[i]); } return out; }
inline vec4 vec4_clamp(const vec4& a, const vec4& min, const vec4& max) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = clamp(a[i], min[i], max[i]); } return out; }


inline vec4 vec4_normalize(const vec4& a) { 
    vec4 out = vec4::k_zero(); 
	float length = vec4_length(a);

	if (length) {
		float inv_length = static_cast<float>(1.0)/length;
		//out = a * inv_length;	
        for (int i=0; i < vec4::size(); ++i) {
			out[i] = a[i] * inv_length;
		}
	} else {
        out = vec4::k_zero();
        printf("Cannot normalize zero length vector. Zero vector returned. Error will propogate.\n");			
	}
		
    return out;
}

inline vec4 vec4_ma(const vec4& a, const vec4& b, float s) { vec4 out = vec4::k_zero(); for (int i=0; i < vec4::size(); ++i) { out[i] = a[i] + s*b[i]; } return out; }

//---------------------------------------------------
// mat4
//---------------------------------------------------
inline mat4 operator - (const mat4& a) { mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = -a[i]; } return out; }

inline mat4 operator + (const mat4& a, const mat4& b) { mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = a[i] + b[i]; } return out; }
inline mat4 operator - (const mat4& a, const mat4& b) { mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = a[i] - b[i]; } return out; }

//inline mat4 operator * (const mat4& a, const mat4& b) { mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = a[i] * b[i]; } return out; }
//inline mat4 operator / (const mat4& a, const mat4& b) { mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = a[i] / b[i]; } return out; }

// Multiplying in forward order like d3d
// for row order matrix storage
// The result represents the transformation B followed by the transformation A. (result = A * B)
// T(R(S(v))) = v*S*R*T = v*SRT
inline mat4 operator * (const mat4& ma, const mat4& mb) {
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

// Result represents the transformation M1 followed by the transformation M2 (Out = M1 * M2).
inline mat4 mat4_mul(const mat4& ma, const mat4& mb) { return (ma * mb); }

// Only difference between D3D_Math row matrix math & gl/glm matrix (column notation in docs)
// which otherwise is stored as row major d3d like) is reverse multiply of mat4*mat4, vec4*mat4.
// Written in reverse order as b*a or T*v, but internally does a*b or v*T resulting in same values.
// (RM1 x RM2)->T  sent to shader in D3D is same as 
// (CM2[:(RM2)->T] x CM1[:(RM1)->T ]) for open gl, since CM1 is already RM1->T
// Transpose of matrix before uploading to shader is done due to shaders having column major matrices unless compile time option for shader compiler is set.
inline mat4 mat4_mul_glm(const mat4& ma, const mat4& mb) { return (mb * ma); }


// Component wise multiplication and division. Hadamard product
inline mat4 mat4_mul_cw(const mat4& a, const mat4& b) { mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = a[i] * b[i]; } return out; }
inline mat4 mat4_div_cw(const mat4& a, const mat4& b) { mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = a[i] / b[i]; } return out; }

inline mat4 operator + (const mat4& a, float s) { mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = a[i] + s; } return out; }
inline mat4 operator - (const mat4& a, float s) { mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = a[i] - s; } return out; }
inline mat4 operator * (const mat4& a, float s) { mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = a[i] * s; } return out; }
inline mat4 operator / (const mat4& a, float s) { float inv_s = static_cast<float>(1.0)/s; mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = a[i] * inv_s; } return out; }

inline mat4 operator + (float s, const mat4& a) { mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = a[i] + s; } return out; }
inline mat4 operator - (float s, const mat4& a) { mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = a[i] - s; } return out; }
inline mat4 operator * (float s, const mat4& a) { mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = a[i] * s; } return out; }
inline mat4 operator / (float s, const mat4& a) { float inv_s = static_cast<float>(1.0)/s; mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = a[i] * inv_s; } return out; }


inline bool operator == (const mat4& a, const mat4& b) { for (int i=0; i < mat4::size(); ++i) { if (!(a[i] == b[i])) { return false; } }	return true; }
inline bool operator != (const mat4& a, const mat4& b) { for (int i=0; i < mat4::size(); ++i) { if (!(a[i] == b[i])) { return true; } }	return false; }

inline bool mat4_equals_ep(const mat4& a, const mat4& b, float epsilon) { for (int i=0; i < mat4::size(); ++i) { if (!(mf::equals_ep(a[i], b[i], epsilon))) { return false; } }	return true; }
inline bool mat4_equals_ep2(const mat4& a, const mat4& b) { for (int i=0; i < mat4::size(); ++i) { if (!(mf::equals2(a[i], b[i]))) { return false; } }	return true; }

inline bool operator < (const mat4& a, const mat4& b)	{ for (int i=0; i < mat4::size(); ++i) { if (!(a[i] < b[i])) { return false; } }	return true; }
inline bool operator > (const mat4& a, const mat4& b)	{ for (int i=0; i < mat4::size(); ++i) { if (!(a[i] > b[i])) { return false; } }	return true; }
inline bool operator <= (const mat4& a, const mat4& b)	{ for (int i=0; i < mat4::size(); ++i) { if (!(a[i] <= b[i])) { return false; } }	return true; }
inline bool operator >= (const mat4& a, const mat4& b)	{ for (int i=0; i < mat4::size(); ++i) { if (!(a[i] >= b[i])) { return false; } }	return true; }

inline mat4 mat4_lerp(const mat4& a, const mat4& b, float s) { mat4 out = mat4::k_zero(); for (int i=0; i < mat4::size(); ++i) { out[i] = mf::lerp(a[i], b[i], s); } return out; }


inline vec4 operator * (const vec4& va, const mat4& ma) { 
	return vec4(
		va[0]*ma.r[0][0] + va[1]*ma.r[1][0] + va[2]*ma.r[2][0] + va[3]*ma.r[3][0],
        va[0]*ma.r[0][1] + va[1]*ma.r[1][1] + va[2]*ma.r[2][1] + va[3]*ma.r[3][1],
        va[0]*ma.r[0][2] + va[1]*ma.r[1][2] + va[2]*ma.r[2][2] + va[3]*ma.r[3][2],
        va[0]*ma.r[0][3] + va[1]*ma.r[1][3] + va[2]*ma.r[2][3] + va[3]*ma.r[3][3]
	);
}
inline vec4 operator * (const mat4& ma, const vec4& va) { 
	return vec4(
		 ma.r[0][0]*va[0] + ma.r[0][1]*va[1] + ma.r[0][2]*va[2] + ma.r[0][3]*va[3],
		 ma.r[1][0]*va[0] + ma.r[1][1]*va[1] + ma.r[1][2]*va[2] + ma.r[1][3]*va[3],
		 ma.r[2][0]*va[0] + ma.r[2][1]*va[1] + ma.r[2][2]*va[2] + ma.r[2][3]*va[3],
		 ma.r[3][0]*va[0] + ma.r[3][1]*va[1] + ma.r[3][2]*va[2] + ma.r[3][3]*va[3]
	);
}

inline vec4 vec4_mul_mat4(const vec4& va, const mat4& ma) { return (va * ma); }
inline vec4 mat4_mul_vec4(const mat4& ma, const vec4& va) { return (ma * va); }

inline vec4 vec4_mul_mat4_glm(const vec4& va, const mat4& ma) { return (ma * va); }
inline vec4 mat4_mul_vec4_glm(const mat4& ma, const vec4& va) { return (va * ma); }


//---------------------------------------------------
// color4
//---------------------------------------------------
inline color4 operator - (const color4& a) { color4 out = color4::k_zero(); for (int i=0; i < color4::size(); ++i) { out[i] = -a[i]; } return out; }

inline color4 operator + (const color4& a, const color4& b) { color4 out = color4::k_zero(); for (int i=0; i < color4::size(); ++i) { out[i] = a[i] + b[i]; } return out; }
inline color4 operator - (const color4& a, const color4& b) { color4 out = color4::k_zero(); for (int i=0; i < color4::size(); ++i) { out[i] = a[i] - b[i]; } return out; }
inline color4 operator * (const color4& a, const color4& b) { color4 out = color4::k_zero(); for (int i=0; i < color4::size(); ++i) { out[i] = a[i] * b[i]; } return out; }
//inline color4 operator / (const color4& a, const color4& b) { color4 out = color4::k_zero(); for (int i=0; i < color4::size(); ++i) { out[i] = a[i] / b[i]; } return out; }

inline color4 operator + (const color4& a, float s) { color4 out = color4::k_zero(); for (int i=0; i < color4::size(); ++i) { out[i] = a[i] + s; } return out; }
inline color4 operator - (const color4& a, float s) { color4 out = color4::k_zero(); for (int i=0; i < color4::size(); ++i) { out[i] = a[i] - s; } return out; }
inline color4 operator * (const color4& a, float s) { color4 out = color4::k_zero(); for (int i=0; i < color4::size(); ++i) { out[i] = a[i] * s; } return out; }
inline color4 operator / (const color4& a, float s) { float inv_s = static_cast<float>(1.0)/s; color4 out = color4::k_zero(); for (int i=0; i < color4::size(); ++i) { out[i] = a[i] * inv_s; } return out; }

inline color4 operator + (float s, const color4& a) { color4 out = color4::k_zero(); for (int i=0; i < color4::size(); ++i) { out[i] = a[i] + s; } return out; }
inline color4 operator - (float s, const color4& a) { color4 out = color4::k_zero(); for (int i=0; i < color4::size(); ++i) { out[i] = a[i] - s; } return out; }
inline color4 operator * (float s, const color4& a) { color4 out = color4::k_zero(); for (int i=0; i < color4::size(); ++i) { out[i] = a[i] * s; } return out; }
inline color4 operator / (float s, const color4& a) { float inv_s = static_cast<float>(1.0)/s; color4 out = color4::k_zero(); for (int i=0; i < color4::size(); ++i) { out[i] = a[i] * inv_s; } return out; }


inline bool operator == (const color4& a, const color4& b) { for (int i=0; i < color4::size(); ++i) { if (!(a[i] == b[i])) { return false; } }	return true; }
inline bool operator != (const color4& a, const color4& b) { for (int i=0; i < color4::size(); ++i) { if (!(a[i] == b[i])) { return true; } }	return false; }


inline bool color4_equals_ep(const color4& a, const color4& b, float epsilon) { for (int i=0; i < color4::size(); ++i) { if (!(mf::equals_ep(a[i], b[i], epsilon))) { return false; } }	return true; }
inline bool color4_equals_ep2(const color4& a, const color4& b) { for (int i=0; i < color4::size(); ++i) { if (!(mf::equals2(a[i], b[i]))) { return false; } }	return true; }


//inline bool operator < (const color4& a, const color4& b)	{ for (int i=0; i < color4::size(); ++i) { if (!(a[i] < b[i])) { return false; } }	return true; }
//inline bool operator > (const color4& a, const color4& b)	{ for (int i=0; i < color4::size(); ++i) { if (!(a[i] > b[i])) { return false; } }	return true; }
//inline bool operator <= (const color4& a, const color4& b)	{ for (int i=0; i < color4::size(); ++i) { if (!(a[i] <= b[i])) { return false; } }	return true; }
//inline bool operator >= (const color4& a, const color4& b)	{ for (int i=0; i < color4::size(); ++i) { if (!(a[i] >= b[i])) { return false; } }	return true; }


inline color4 color4_scale(const color4& a, float s) { color4 out = color4::k_zero(); for (int i=0; i < color4::size(); ++i) { out[i] = a[i] * s; } return out; }
inline color4 color4_lerp(const color4& a, const color4& b, float s) { color4 out = color4::k_zero(); for (int i=0; i < color4::size(); ++i) { out[i] = mf::lerp(a[i], b[i], s); } return out; }


inline const color4 ck_white = color4(1.0, 1.0, 1.0, 1.0);
inline const color4 ck_black = color4(0, 0, 0, 1.0);
inline const color4 ck_red = color4(1.0, 0, 0, 1.0);
inline const color4 ck_green = color4(0, 1.0,   0, 1.0);
inline const color4 ck_blue = color4(0, 0, 1.0, 1.0);
inline const color4 ck_yellow = color4(1.0, 1.0, 0, 1.0);
inline const color4 ck_cyan = color4(0, 1.0, 1.0, 1.0);
inline const color4 ck_magenta = color4(1.0, 0, 1.0, 1.0);

inline const color4 ck_lt_grey = color4(0.2, 0.2, 0.2, 1.0);


//===============================
// Integer Packing Unpacking
//===============================

// Packs uint8 a, b, c, d [0-255] components in a uint.
// Maps unsigned 8 bits/channel to UColor.
// RGBA format
inline uint pack_u32(uint8 a, uint8 b, uint8 c, uint8 d) {
	//return ((uint)(a) << 24) | ((uint)(b) << 16) | ((uint)(c) << 8) | ((uint)(d));
    return (static_cast<uint>(a) << 24) | (static_cast<uint>(b) << 16) | (static_cast<uint>(c) << 8) | (static_cast<uint>(d));
}

// Unpacks four uint8 components out of uint and assign to uint.
inline void unpack_u32(uint val, uint8& a, uint8& b, uint8& c, uint8& d) {
	//a = (uint8)((val)>>24);
	//b = (uint8)((val)>>16);
	//c = (uint8)((val)>>8);
	//d = (uint8)(val);
    
    a = static_cast<uint8>((val)>>24);
	b = static_cast<uint8>((val)>>16);
	c = static_cast<uint8>((val)>>8);
	d = static_cast<uint8>(val);
}

inline uint u8_to_xbgr(uint8 r, uint8 g, uint8 b) {
	return pack_u32(0x00, b, g, r);
}

//UCHAR_MAX; //0xff;
inline uint byte_order_swap_u32(uint x) {
	uint8 A = (x >> 24) & UCHAR_MAX;
	uint8 R = (x >> 16) & UCHAR_MAX;
	uint8 G = (x >>  8) & UCHAR_MAX;
	uint8 B = (x >>  0) & UCHAR_MAX;

	return ((A << 24) | (B << 16) | (G << 8) | (R << 0));
}

inline uint argb_to_abgr(uint x) {
	return byte_order_swap_u32(x);
}

inline uint abgr_to_argb(uint x) {
	return byte_order_swap_u32(x);
}


//-------------
// float to uint component of a packed uint.
inline uint ftouc(float x) {
	//return ((uint)((x)*255.f)&0xff);
	//return (static_cast<uint>(x*255.f) & UCHAR_MAX);	
	return static_cast<uint>(x >= 1.0f ? UCHAR_MAX : x <= 0.0f ? 0x00 : static_cast<uint>(x * 255.0f));
}

inline uint ftouc_d3dx9(float x) {
	//255.0f + 0.5f changes value
    //return (uint) (x >= 1.0f ? 0xff : x <= 0.0f ? 0x00 : (uint) (x * 255.0f + 0.5f));
	return static_cast<uint>(x >= 1.0f ? UCHAR_MAX : x <= 0.0f ? 0x00 : static_cast<uint>(x * 255.0f + 0.5f)); 
}


// Packs float a, b, c, d [0-1.0] components in a uint.
// ARGB format
inline uint packf_u32(float a, float b, float c, float d) {
	//uint ua = ftouc(a);
	//uint ub = ftouc(b);
	//uint uc = ftouc(c);
	//uint ud = ftouc(d);
	//return ((ua << 24) | (ub << 16) | (uc << 8) | ud);

	return ((ftouc(a) << 24) | (ftouc(b) << 16) | (ftouc(c) << 8) | (ftouc(d)));
}

inline uint packf_u32_d3dx(float a, float b, float c, float d) {
	return ((ftouc_d3dx9(a) << 24) | (ftouc_d3dx9(b) << 16) | (ftouc_d3dx9(c) << 8) | (ftouc_d3dx9(d)));
}


// Unpacks four uint8 components out of uint and assign to floats.
inline void unpackf_u32(uint x, float& a, float& b, float& c, float& d) {
    // Multiply with this to get float value in [0-1.0] from a component of packed uint. (1.0 / 255.0)
    // (0.003921568627);
    //inline constexpr float k_uc_inv = static_cast<float>(0.00392156862745098039);
    //template <class T> inline constexpr T k_uc_inv = static_cast<T>(0.00392156862745098039);
    //const float k_uc_inv = static_cast<float>(1.0)/static_cast<float>(255.0);
    const float k_uc_inv = static_cast<float>(0.00392156862745098039);

	//a = k_uc_inv * (float) (uint8) (x >> 24);
	//b = k_uc_inv * (float) (uint8) (x >> 16);
	//c = k_uc_inv * (float) (uint8) (x >>  8);
	//d = k_uc_inv * (float) (uint8) (x >>  0);
    a = k_uc_inv * static_cast<float>( static_cast<uint8>(x >> 24) );
	b = k_uc_inv * static_cast<float>( static_cast<uint8>(x >> 16) );
	c = k_uc_inv * static_cast<float>( static_cast<uint8>(x >>  8) );
	d = k_uc_inv * static_cast<float>( static_cast<uint8>(x >>  0) );
}
//-------------

//---
inline color4 argb_to_color4(uint uc) {
	color4 out = color4::k_zero();
	//const float f = static_cast<float>(1.0)/static_cast<float>(255.0);
	//out.r = f * (float) (uint8) (uc >> 16);
	//out.g = f * (float) (uint8) (uc >>  8);
	//out.b = f * (float) (uint8) (uc >>  0);
	//out.a = f * (float) (uint8) (uc >> 24);

	unpackf_u32(uc, out.a, out.r, out.g, out.b);
	return out;
}

inline color4 abgr_to_color4(uint uc) {
	color4 out = color4::k_zero();
	unpackf_u32(uc, out.a, out.b, out.g, out.r);
	return out;
}

inline color4 rgba_to_color4(uint uc) {
	color4 out = color4::k_zero();
	unpackf_u32(uc, out.r, out.g, out.b, out.a);
	return out;
}


// d3dx9
inline uint color4_to_argb(const color4& a) {
	return packf_u32(a.a, a.r, a.g ,a.b);
}

// Only in d3dx9math D3DXCOLOR DWORD operator: D3DXCOLOR::operator DWORD() const {}
inline uint color4_to_argb_d3dx(const color4& a) {
	////(uint) (x * 255.0f + 0.5f)) (d3dx9) instead of (uint) (x * 255.0f)) (packf_u32)
	//uint ur = a.r >= 1.0f ? 0xff : a.r <= 0.0f ? 0x00 : (uint) (a.r * 255.0f + 0.5f);
	//uint ug = a.g >= 1.0f ? 0xff : a.g <= 0.0f ? 0x00 : (uint) (a.g * 255.0f + 0.5f);
	//uint ub = a.b >= 1.0f ? 0xff : a.b <= 0.0f ? 0x00 : (uint) (a.b * 255.0f + 0.5f);
	//uint ua = a.a >= 1.0f ? 0xff : a.a <= 0.0f ? 0x00 : (uint) (a.a * 255.0f + 0.5f);
	//return (ua << 24) | (ur << 16) | (ug << 8) | ub;

	return packf_u32_d3dx(a.a, a.r, a.g ,a.b);
}

// gl2
inline uint color4_to_abgr(const color4& a) {
	return packf_u32(a.a, a.b, a.g, a.r);
}

inline uint color4_to_rgba(const color4& a) {
	return packf_u32(a.r, a.g, a.b ,a.a);
}


// Same as RGB macro of Windows. Packs color in format of Win32 Api.
inline uint color4_to_xbgr(const color4& a) {
	return packf_u32(static_cast<float>(0.0), a.b, a.g, a.r);
}
//-----------


// (1-r, 1-g, 1-b, a)
inline color4 color4_negative(const color4& a) {
	return color4{
		static_cast<float>(1.0) - a.r, 
		static_cast<float>(1.0) - a.g, 
		static_cast<float>(1.0) - a.b, 
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
    const float grey = a.r * static_cast<float>(0.2125) + a.g * static_cast<float>(0.7154) + a.b * static_cast<float>(0.0721);

    out.r = grey + s * (a.r - grey);
    out.g = grey + s * (a.g - grey);
    out.b = grey + s * (a.b - grey);
    out.a = a.a;

    return out;
}

// Interpolate r,g,b between 50% grey and color.  Grey + s(Color - Grey)
inline color4 color4_adjust_contrast(const color4& a, float s) {
    color4 out = color4::k_zero();
    // factor is 50% grey
    const float factor = static_cast<float>(0.5); 
    
    out.r = factor + s * (a.r - factor);
    out.g = factor + s * (a.g - factor);
    out.b = factor + s * (a.b - factor);
    out.a = a.a;

    return out;
}


//---------------------------------------------------
// quat
//---------------------------------------------------
inline quat operator - (const quat& a) { return quat(-a.v); }

inline quat operator + (const quat& a, const quat& b) { return quat(a.v + b.v); }
inline quat operator - (const quat& a, const quat& b) { return quat(a.v - b.v); }
//inline quat operator * (const quat& a, const quat& b) { return quat(a.v * b.v); }
//inline quat operator / (const quat& a, const quat& b) { return quat(a.v / b.v); }

// Quaternion multiplication. The result represents the rotation b followed by the rotation a. (out = b * a)
// quat_mul
inline quat operator * (const quat& a, const quat& b) { 
	quat out = quat::k_zero();		
	out.x = (b.w * a.x) + (b.x * a.w) + (b.y * a.z) - (b.z * a.y);
	out.y = (b.w * a.y) - (b.x * a.z) + (b.y * a.w) + (b.z * a.x);
	out.z = (b.w * a.z) + (b.x * a.y) - (b.y * a.x) + (b.z * a.w);
	out.w = (b.w * a.w) - (b.x * a.x) - (b.y * a.y) - (b.z * a.z);	
	return out; 
}

inline quat operator + (const quat& a, float s) { return quat(a.v + s); }
inline quat operator - (const quat& a, float s) { return quat(a.v - s); }
inline quat operator * (const quat& a, float s) { return quat(a.v * s); }
inline quat operator / (const quat& a, float s) { return quat(a.v / s); }

inline quat operator + (float s, const quat& a) { return quat(a.v + s); }
inline quat operator - (float s, const quat& a) { return quat(a.v - s); }
inline quat operator * (float s, const quat& a) { return quat(a.v * s); }
inline quat operator / (float s, const quat& a) { return quat(a.v / s); }


inline bool operator == (const quat& a, const quat& b) { return (a.v == b.v); }
inline bool operator != (const quat& a, const quat& b) { return (a.v != b.v); }

inline bool quat_equals_ep(const quat& a, const quat& b, float epsilon) { return vec4_equals_ep(a.v, b.v, epsilon); }
inline bool quat_equals_ep2(const quat& a, const quat& b) { return vec4_equals_ep2(a.v, b.v); }

inline bool operator < (const quat& a, const quat& b)	{ return (a.v < b.v); }
inline bool operator > (const quat& a, const quat& b)	{ return (a.v > b.v); }
inline bool operator <= (const quat& a, const quat& b)	{ return (a.v <= b.v); }
inline bool operator >= (const quat& a, const quat& b)	{ return (a.v >= b.v); }

inline float quat_dot(const quat& a, const quat& b) { return vec4_dot(a.v, b.v); }

// Length squared, or "norm"
inline float quat_length_sq(const quat& a) { return vec4_length_sq(a.v); }
inline float quat_length(const quat& a) { return vec4_length(a.v); }

inline quat quat_normalize(const quat& a) { 
    quat out = quat::k_zero(); 
	float length = quat_length(a);

	if (length) {
		float inv_length = static_cast<float>(1.0)/length;
		//out = a * inv_length;	
        for (int i=0; i < quat::size(); ++i) {
			out[i] = a[i] * inv_length;
		}
	} else {
        out = quat::k_zero();
        printf("Cannot normalize zero length vector. Zero vector returned. Error will propogate.\n");			
	}
		
    return out;
}

inline quat quat_ma(const quat& a, const quat& b, float s) { quat out = quat::k_zero(); for (int i=0; i < quat::size(); ++i) { out[i] = a[i] + s*b[i]; } return out; }


//---------------------------------------------------
// plane
//---------------------------------------------------
inline plane operator - (const plane& a) { return plane(-a.v); }

inline plane operator + (const plane& a, float s) { return plane(a.v + s); }
inline plane operator - (const plane& a, float s) { return plane(a.v - s); }
inline plane operator * (const plane& a, float s) { return plane(a.v * s); }
inline plane operator / (const plane& a, float s) { return plane(a.v / s); }

inline plane operator + (float s, const plane& a) { return plane(a.v + s); }
inline plane operator - (float s, const plane& a) { return plane(a.v - s); }
inline plane operator * (float s, const plane& a) { return plane(a.v * s); }
inline plane operator / (float s, const plane& a) { return plane(a.v / s); }

inline bool operator == (const plane& a, const plane& b) { return (a.v == b.v); }
inline bool operator != (const plane& a, const plane& b) { return (a.v != b.v); }

inline bool plane_equals_ep(const plane& a, const plane& b, float epsilon) { return vec4_equals_ep(a.v, b.v, epsilon); }
inline bool plane_equals_ep2(const plane& a, const plane& b) { return vec4_equals_ep2(a.v, b.v); }


//D3DXPlaneDot
// The PlaneDot function is useful for determining the plane's relationship with a homogeneous coordinate.
// This function could be used to determine if a particular coordinate is on a particular plane, or on which side of a particular plane a particular coordinate lies.
// ax + by + cz + dw
inline float plane_dot(const plane& p, const vec4& a) {	
    return (p.a*a.x + p.b*a.y + p.c*a.z + p.d*a.w);
}

//D3DXPlaneDotCoord
// The PlaneDotCoord function is useful for determining the plane's relationship with a coordinate in 3D space.
// ax + by + cz + d (= a*x + b*y + c*z + d*1)
inline float plane_dot_coord(const plane& p, const vec3& a) {	
    return (p.a*a.x + p.b*a.y + p.c*a.z + p.d);
}

//D3DXPlaneDotNormal
// The PlaneDotNormal function is useful for calculating the angle between the normal of the plane, and another normal.
// ax + by + cz (= a*x + b*y + c*z + d*0)
inline float plane_dot_normal(const plane& p, const vec3& a) {	
    return (p.a*a.x + p.b*a.y + p.c*a.z);
}


inline plane plane_scale(const plane& a, float s) { return (a * s); }

// Normalize plane (so that |a, b, c| == 1)
// vec3_length of (a, b, c), differs from vec2/3/4 normalize.
inline plane plane_normalize(const plane& a) {
    plane out = plane::k_zero();    
    // only first 3 members used
    //norm = sqrt(a.a*a.a + a.b*a.b + a.c*a.c);
    float norm = vec3_length(a.normal);

    if (norm) {
        float inv_norm = static_cast<float>(1.0)/norm;
        //out = a * inv_norm;	
        for (int i=0; i < plane::size(); ++i) {
			out[i] = a[i] * inv_norm;
		}
    } else {
        out = plane::k_zero();
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


//===================================================================================

//---------------------------------------------------
// mat4
//---------------------------------------------------

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
	// C_ij   = (-1)^i+j * det(M_ij)
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
        //const float nan = std::numeric_limits<float>::quiet_NaN();
        // out is zero matrix
        //out = mat4(nan, nan, nan, nan,
        //            nan, nan, nan, nan,
        //            nan, nan, nan, nan,
        //            nan, nan, nan, nan);
        //return false;

        printf("Cannot invert matrix. Zero Matrix returned. Error will propogate.\n");
        return mat4::k_zero();
    }

    float inv_det = static_cast<float>(1.0) / det;

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





//=====================================================================================================================
//=====================================================================================================================

// angle in radians
// Build a matrix which rotates around the X axis
// Creates an x-axis rotation matrix, centered on the origin.
inline mat4 mat4_rotation_x(float angle) {
    const float sin_a = std::sin(angle);
    const float cos_a = std::cos(angle);

    return mat4(
            static_cast<float>(1.0),    static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(0.0),
            static_cast<float>(0.0),    cos_a,				        sin_a,				        static_cast<float>(0.0),
            static_cast<float>(0.0),    -sin_a,				        cos_a,				        static_cast<float>(0.0),
            static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(1.0)
	);
}

// Build a matrix which rotates around the Y axis
inline mat4 mat4_rotation_y(float angle) {
    const float sin_a = std::sin(angle);
    const float cos_a = std::cos(angle);

    return mat4(
            cos_a,				        static_cast<float>(0.0),    -sin_a,				        static_cast<float>(0.0),
            static_cast<float>(0.0),    static_cast<float>(1.0),    static_cast<float>(0.0),    static_cast<float>(0.0),
            sin_a,				        static_cast<float>(0.0),    cos_a,				        static_cast<float>(0.0),
            static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(1.0)
	);
}

// Build a matrix which rotates around the Z axis
inline mat4 mat4_rotation_z(float angle) {
    const float sin_a = std::sin(angle);
    const float cos_a = std::cos(angle);
    
    return mat4(
            cos_a,				        sin_a,				        static_cast<float>(0.0),    static_cast<float>(0.0),
            -sin_a,				        cos_a,				        static_cast<float>(0.0),    static_cast<float>(0.0),
            static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(1.0),    static_cast<float>(0.0),
            static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(1.0)
	);
}


// Build a matrix which rotates around an arbitrary axis
//mat4 mat4_glm_rotation_xyz(float angle, const vec3& axis)
//D3DXMatrixRotationAxis
inline mat4 mat4_rotation_axis(const vec3& axis, float angle) {    
    vec3 nv = vec3_normalize(axis);
    const float sa = std::sin(angle);
    const float ca = std::cos(angle);
    const float cd = static_cast<float>(1.0) - ca;    

    return mat4(
            cd*nv.x*nv.x + ca,          cd*nv.y*nv.x + sa*nv.z,     cd*nv.z*nv.x - sa*nv.y,     static_cast<float>(0.0),
            cd*nv.x*nv.y - sa*nv.z,     cd*nv.y*nv.y + ca,          cd*nv.z*nv.y + sa*nv.x,     static_cast<float>(0.0),
            cd*nv.x*nv.z + sa*nv.y,     cd*nv.y*nv.z - sa*nv.x,     cd*nv.z*nv.z + ca,          static_cast<float>(0.0),
            static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(0.0),    static_cast<float>(1.0)
        );
}

inline mat4 mat4_translation(const vec3& position) {
    return mat4(
            static_cast<float>(1.0),	static_cast<float>(0.0),		static_cast<float>(0.0),		static_cast<float>(0.0),
            static_cast<float>(0.0),	static_cast<float>(1.0),		static_cast<float>(0.0),		static_cast<float>(0.0),
            static_cast<float>(0.0),	static_cast<float>(0.0),		static_cast<float>(1.0),		static_cast<float>(0.0),
            position.x,				    position.y,				        position.z,				        static_cast<float>(1.0)
	);
}

inline mat4 mat4_scaling(const vec3& scales) {
    return mat4(
            scales.x,			        static_cast<float>(0.0),	static_cast<float>(0.0),	static_cast<float>(0.0),
            static_cast<float>(0.0),	scales.y,			        static_cast<float>(0.0),	static_cast<float>(0.0),
            static_cast<float>(0.0),	static_cast<float>(0.0),	scales.z,			        static_cast<float>(0.0),
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

//inline mat4 mat4_look_at_lh(const vec3& eye, const vec3& at, const vec3& up) {
//    vec3 right = vec3::k_zero();
//    vec3 upn = vec3::k_zero();
//    vec3 dir = vec3::k_zero();
//
//    dir = vec3_normalize(at - eye);
//    right = vec3_cross(up, dir);
//    upn = vec3_cross(dir, right);
//    right = vec3_normalize(right);
//    upn = vec3_normalize(upn);
//
//    return mat4(
//        right.x,			   upn.x,				dir.x,				 static_cast<float>(0.0),
//        right.y,			   upn.y,				dir.y,				 static_cast<float>(0.0),
//        right.z,			   upn.z,				dir.z,				 static_cast<float>(0.0),
//        -vec3_dot(right, eye), -vec3_dot(upn, eye), -vec3_dot(dir, eye), static_cast<float>(1.0)
//    );
//}

//wnm
inline mat4 mat4_look_at_lh(const vec3& eye, const vec3& at, const vec3& up) {
    vec3 zaxis = vec3_normalize(at - eye);
    vec3 xaxis = vec3_normalize(vec3_cross(up, zaxis));
    vec3 yaxis = vec3_cross(zaxis, xaxis);

    return mat4(xaxis.x,               yaxis.x,               zaxis.x,               static_cast<float>(0.0),
				xaxis.y,               yaxis.y,               zaxis.y,               static_cast<float>(0.0),
				xaxis.z,               yaxis.z,               zaxis.z,               static_cast<float>(0.0),
				-vec3_dot(xaxis, eye), -vec3_dot(yaxis, eye), -vec3_dot(zaxis, eye), static_cast<float>(1.0)
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

//inline mat4 mat4_look_at_rh(const vec3& eye, const vec3& at, const vec3& up) {
//    vec3 right = vec3::k_zero(); 
//    vec3 upn = vec3::k_zero();
//    vec3 dir = vec3::k_zero();
//
//    dir = vec3_normalize(at - eye);
//    right = vec3_cross(up, dir);
//    upn = vec3_cross(dir, right);
//    right = vec3_normalize(right);
//    upn = vec3_normalize(upn);
//
//    return mat4(
//        -right.x,			  upn.x,			   -dir.x,		       static_cast<float>(0.0),
//        -right.y,			  upn.y,			   -dir.y,             static_cast<float>(0.0),
//        -right.z,			  upn.z,			   -dir.z,			   static_cast<float>(0.0),
//        vec3_dot(right, eye), -vec3_dot(upn, eye), vec3_dot(dir, eye), static_cast<float>(1.0)
//    );
//}

//wnm
inline mat4 mat4_look_at_rh(const vec3& eye, const vec3& at, const vec3& up) {
    vec3 zaxis = vec3_normalize(eye - at);
    vec3 xaxis = vec3_normalize(vec3_cross(up, zaxis));
    vec3 yaxis = vec3_cross(zaxis, xaxis);

    return mat4(xaxis.x,               yaxis.x,               zaxis.x,               static_cast<float>(0.0),
				xaxis.y,               yaxis.y,               zaxis.y,               static_cast<float>(0.0),
				xaxis.z,               yaxis.z,               zaxis.z,               static_cast<float>(0.0),
				-vec3_dot(xaxis, eye), -vec3_dot(yaxis, eye), -vec3_dot(zaxis, eye), static_cast<float>(1.0)
    );
}

//--------------------------------------------
// Perspective Matrices d3dx9
//--------------------------------------------

//width = tan(fov * 0.5f);
//height = width/aspect;
//yScale = cot(fovY/2)
//xScale = yScale / aspect ratio
//
////const float x_scale = static_cast<float>(1.0)/(aspect * tan_half_fovy);
////const float y_scale = static_cast<float>(1.0)/tan_half_fovy;
//
//xScale   0          0             0
//0        yScale     0             0
//0        0          f/(f-n)       1
//0        0          -n*f/(f-n)    0
//
// Build a perspective projection matrix. (left-handed)
//D3DXMatrixPerspectiveFovLH
inline mat4 mat4_perspective_fov_lh(float fovy, float aspect, float n, float f) {
	const float tan_half_fovy = std::tan(fovy * static_cast<float>(0.5));
    const float y_scale = static_cast<float>(1.0)/tan_half_fovy;
    const float x_scale = y_scale/aspect;

    return mat4(
        x_scale,		         static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0), 
        static_cast<float>(0.0), y_scale,		          static_cast<float>(0.0), static_cast<float>(0.0), 
        static_cast<float>(0.0), static_cast<float>(0.0), f/(f-n),	               static_cast<float>(1.0), 
        static_cast<float>(0.0), static_cast<float>(0.0), (n*f)/(n-f),             static_cast<float>(0.0) 
	);    
}


//yScale = cot(fovY/2)
//xScale = yScale / aspect ratio
//
//xScale   0        0              0
//0        yScale   0              0
//0        0        f/(n-f)       -1
//0        0        n*f/(n-f)      0
//
// Build a perspective projection matrix. (right-handed)
//D3DXMatrixPerspectiveFovRH
inline mat4 mat4_perspective_fov_rh(float fovy, float aspect, float n, float f) {
	const float tan_half_fovy = std::tan(fovy * static_cast<float>(0.5));
    const float y_scale = static_cast<float>(1.0)/tan_half_fovy;
    const float x_scale = y_scale/aspect;

    return mat4(
        x_scale,		         static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0), 
        static_cast<float>(0.0), y_scale,		          static_cast<float>(0.0), static_cast<float>(0.0), 
        static_cast<float>(0.0), static_cast<float>(0.0), f/(n-f),	               -static_cast<float>(1.0), 
        static_cast<float>(0.0), static_cast<float>(0.0), (n*f)/(n-f),             static_cast<float>(0.0)
	);    
}




//==================================================================
inline vec3 vec2_to_vec3(const vec2& a, float z) { return vec3(a.x, a.y, z); }
//inline vec3 vec4_to_vec3(const vec4& a) { return vec3(a.x, a.y, a.z); }
//inline vec4 vec2_to_vec4(const vec2& a, float z, float w) { return vec4(a.x, a.y, z, w); }
//inline vec4 vec3_to_vec4(const vec3& a, float w) { return vec4(a.x, a.y, a.z, w); }
//inline vec3 quat_to_vec3(const quat& a) { return vec3(a.x, a.y, a.z); }
//inline vec3 plane_to_vec3(const plane& p) { return vec3(p.a, p.b, p.c); }
//inline vec4 plane_to_vec4(const plane& p) { return vec4(p.a, p.b, p.c, p.d); }
//inline plane vec4_to_plane(const vec4& a) { return plane(a.x, a.y, a.z, a.w); }



// Transform the vector V (x, y, z, 1) by matrix M, project result back into w=1.
//D3DXVec3TransformCoord
inline vec3 vec3_transform_coord(const vec3& a, const mat4& ma) {	
    float norm = ma.r[0][3] * a.x + ma.r[1][3] * a.y + ma.r[2][3] * a.z + ma.r[3][3];
	float inv_norm = static_cast<float>(1.0)/norm;

	return vec3(
		(ma.r[0][0] * a.x + ma.r[1][0] * a.y + ma.r[2][0] * a.z + ma.r[3][0]) * inv_norm,
		(ma.r[0][1] * a.x + ma.r[1][1] * a.y + ma.r[2][1] * a.z + ma.r[3][1]) * inv_norm,
		(ma.r[0][2] * a.x + ma.r[1][2] * a.y + ma.r[2][2] * a.z + ma.r[3][2]) * inv_norm
    );
}


//---
//--------------------------------------------
//d3dx9
// xWin = x + 0.5 * (xNdc + 1.0) * w;
// yWin = y + 0.5 * (yNdc + 1.0) * h;
// Projects a 3D vector (x, y, z, 0) from object space into screen space.
//D3DXVec3Project
inline vec3 vec3_project(const vec3& a, const viewport& vp, const mat4& proj, const mat4& view, const mat4& world) {
    vec3 out = vec3::k_zero();
    mat4 m = mat4::k_identity();

    m = world * view * proj;

    out = vec3_transform_coord(a, m);

    out.x = vp.x + (static_cast<float>(1.0) + out.x) * vp.w*static_cast<float>(0.5);
    out.y = vp.y + (static_cast<float>(1.0) - out.y) * vp.h*static_cast<float>(0.5);
    out.z = vp.n + out.z * (vp.f - vp.n);

    return out;
}

// Projects a vector from screen space into object space.
//D3DXVec3Unproject
inline vec3 vec3_unproject(const vec3& a, const viewport& vp, const mat4& proj, const mat4& view, const mat4& world) {
    vec3 out = vec3::k_zero();
    mat4 m = mat4::k_identity();

    m = world * view * proj;
    m = mat4_inverse(m);    

    out = a;

    out.x = static_cast<float>(2.0)*(out.x - vp.x) / vp.w - static_cast<float>(1.0);
    out.y = static_cast<float>(1.0) - static_cast<float>(2.0)*(out.y - vp.y)/vp.h;
    out.z = (out.z - vp.n)/(vp.f - vp.n);

    out = vec3_transform_coord(out, m);
    return out;
}

//--------------------------------------------


// UNCHECKED

//--------------------------------------





//-------------------------------------------------------------------



// END UNCHECKED



}