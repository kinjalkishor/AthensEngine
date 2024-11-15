#pragma once

//================================================================================================

#if 0

//========================================================================================================================
// Template functions for N size
//========================================================================================================================
template<class T> inline T vecnt_negate(const T& a) { T out = T::k_zero(); for (int i=0; i < T::size(); ++i) { out[i] = -a[i]; } return out; }
template<class T> inline T vecnt_add(const T& a, const T& b) { T out = T::k_zero(); for (int i=0; i < T::size(); ++i) { out[i] = a[i] + b[i]; } return out; }
template<class T> inline T vecnt_sub(const T& a, const T& b) { T out = T::k_zero(); for (int i=0; i < T::size(); ++i) { out[i] = a[i] - b[i]; } return out; }
template<class T> inline T vecnt_mul(const T& a, const T& b) { T out = T::k_zero(); for (int i=0; i < T::size(); ++i) { out[i] = a[i] * b[i]; } return out; }
template<class T> inline T vecnt_div(const T& a, const T& b) { T out = T::k_zero(); for (int i=0; i < T::size(); ++i) { out[i] = a[i] / b[i]; } return out; }
template<class T> inline T vecnt_add_s(const T& a, float s) { T out = T::k_zero(); for (int i=0; i < T::size(); ++i) { out[i] = a[i] + s; } return out; }
template<class T> inline T vecnt_sub_s(const T& a, float s) { T out = T::k_zero(); for (int i=0; i < T::size(); ++i) { out[i] = a[i] - s; } return out; }
template<class T> inline T vecnt_mul_s(const T& a, float s) { T out = T::k_zero(); for (int i=0; i < T::size(); ++i) { out[i] = a[i] * s; } return out; }
template<class T> inline T vecnt_div_s(const T& a, float s) { 
	const float inv_s = scast<float>(1.0)/s; 
	//return (a * inv_s); 
	T out = T::k_zero(); for (int i=0; i < T::size(); ++i) { out[i] = a[i] * inv_s; } return out;
}

//(a.x==b.x && a.y==b.y)
template<class T> inline bool vecnt_is_equal_ep(const T& a, const T& b, float epsilon) { 
	// If any elements is not equal return false. If this test fails for all elements than vectors are equal, return true.
	for (int i=0; i < T::size(); ++i) { if (!(mf::equals_ep(a[i], b[i], epsilon))) { return false; } }	return true; 
}
template<class T> inline bool vecnt_is_equal_ep2(const T& a, const T& b) { 
	for (int i=0; i < T::size(); ++i) { if (!(mf::equals2(a[i], b[i]))) { return false; } }	return true; 
}
//(a.x!=b.x || a.y!=b.y)
template<class T> inline bool vecnt_is_not_equal_ep(const T& a, const T& b, float epsilon) { 
	return !(vecnt_is_equal_ep(a, b, epsilon)); 
}

template<class T> inline bool vecnt_is_equal(const T& a, const T& b) { 
	for (int i=0; i < T::size(); ++i) { if (!(a[i] == b[i])) { return false; } }	return true; 
	//return vecnt_is_equal_ep2(a, b);
}
template<class T> inline bool vecnt_is_not_equal(const T& a, const T& b) { 
	//return !(a == b); 
	//return !(vecnt_is_equal(a, b));
	for (int i=0; i < T::size(); ++i) { if (!(a[i] == b[i])) { return true; } }	return false;
}

//(a.x<b.x && a.y<b.y)
template<class T> inline bool vecnt_is_less(const T& a, const T& b) { 
	//(<)
	// If any elements is not less_than return false. If this test fails for all elements than 1st vector is less_than, return true.
	for (int i=0; i < T::size(); ++i) { if (!(a[i] < b[i])) { return false; } }	return true; 
}

template<class T> inline bool vecnt_is_greater(const T& a, const T& b) { 
	//(>)
	//return (b < a); 
	//return vecnt_is_less(b, a);
    for (int i=0; i < T::size(); ++i) { if (!(a[i] > b[i])) { return false; } }	return true; 
}
template<class T> inline bool vecnt_is_less_equal(const T& a, const T&b) { 
	//(<=)
	//return !(b < a); 
	//return !(vecnt_is_less(b, a));
    for (int i=0; i < T::size(); ++i) { if (!(a[i] <= b[i])) { return false; } }	return true; 
}
template<class T> inline bool vecnt_is_greater_equal(const T& a, const T& b) { 
	//(>=)
	//return !(a < b); 
	//return !(vecnt_is_less(a, b));
    for (int i=0; i < T::size(); ++i) { if (!(a[i] >= b[i])) { return false; } }	return true; 
}


template<class T> inline float vecnt_dot(const T& a, const T& b) {
	//a.x*b.x + a.y*b.y + a.z*b.z
	float out = scast<float>(0.0); for (int i=0; i < T::size(); ++i) { out += a[i] * b[i]; } return out;
}

template<class T> inline float vecnt_length_sq(const T& a) {
	//(square(a.x) + square(a.y) + square(a.z));
	//a.x*a.x + a.y*a.y + a.z*a.z	
	//dot(a, a);
	float out = scast<float>(0.0); for (int i=0; i < T::size(); ++i) { out += mf::square(a[i]); } return out;
}
// vector length, magnitude
template<class T> inline float vecnt_length(const T& a) { return sqrt(vecnt_length_sq(a));  }

// Passing zero vector will make length or norm 0, and divide by zero exception will occur
// for a zero vector this will let the zero vector remain zero
// for zero length vector or if length is too small it is x/0 (infinity). Should throw exception or return NaN.
// check norm with epsilon, as for zero or too small vector length will approach infinity
// Since zero vector cannot be normalized, return value for zero vector can be checked for error. Better use std::optional.
template<class T> inline T vecnt_normalize(const T& a) {
    //a / length(a);
    T out = T::k_zero(); 
	float length = vecnt_length(a);

	if (length) {
		float inv_length = scast<float>(1.0)/length;
		//out = a * inv_length;	
		for (int i=0; i < T::size(); ++i) { out[i] = a[i] * inv_length; }
	} else {
		// out is already zero. If out is used error will propogate
		out = T::k_zero();
        printf("Cannot normalize zero length vector. Zero vector returned. Error will propogate.\n");			
	}
		
    return out;
	//return length;
}


template<class T> inline T vecnt_ma(const T& a, const T& b, float s) { 
    T out = T::k_zero(); for (int i=0; i < T::size(); ++i) { out[i] = a[i] + s*b[i]; } return out; 
}

template<class T> inline float vecnt_distance_sq(const T& a, const T& b) {
	//(square(a.x - b.x) + square(a.y - b.y) + square(a.z - b.z));
	//(a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z);	
	//length_sq(a - b); //length_sq(a.x - b.x, a.y - b.y, a.z - b.z)
    float out = scast<float>(0.0); for (int i=0; i < T::size(); ++i) { out += mf::square(a[i] - b[i]); } return out;
}
template<class T> inline float vecnt_distance(const T& a, const T& b) { return std::sqrt(vecnt_distance_sq(a, b)); }

// Linear interpolation. V1 + s(V2-V1)
template<class T> inline T vecnt_lerp(const T& a, const T& b, float s) {
    T out = T::k_zero(); for (int i=0; i < T::size(); ++i) { out[i] = mf::lerp(a[i], b[i], s); } return out;
}

// Minimize each component.  x = min(x1, x2), y = min(y1, y2)
template<class T> inline T vecnt_min(const T& a, const T& b) {
    T out = T::k_zero(); for (int i=0; i < T::size(); ++i) { out[i] = sdf::tmin(a[i], b[i]); } return out;
}
// Maximize each component.  x = max(x1, x2), y = max(y1, y2)
template<class T> inline T vecnt_max(const T& a, const T& b) {
    T out = T::k_zero(); for (int i=0; i < T::size(); ++i) { out[i] = sdf::tmax(a[i], b[i]); } return out;
}

template<class T> inline T vecnt_clamp(const T& a, const T& low, const T& high) {
    T out = T::k_zero(); for (int i=0; i < T::size(); ++i) { out[i] = sdf::clamp(a[i], low[i], high[i]); } return out;
}

#endif
//================================================================================================


#if 0

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

inline vec2 operator + (float s, const vec2& a) { return a + s; }
inline vec2 operator - (float s, const vec2& a) { return a - s; }
inline vec2 operator * (float s, const vec2& a) { return a * s; }
inline vec2 operator / (float s, const vec2& a) { return a / s; }

inline bool vec2_equals_ep(const vec2& a, const vec2& b, float epsilon) { return vecnt_is_equal_ep(a, b, epsilon); }
inline bool vec2_equals_ep2(const vec2& a, const vec2& b) { return vecnt_is_equal_ep2(a, b); }

inline bool operator == (const vec2& a, const vec2& b) { return vecnt_is_equal(a, b); }
inline bool operator != (const vec2& a, const vec2& b) { return vecnt_is_not_equal(a, b); }

inline bool operator < (const vec2& a, const vec2& b)	{ return vecnt_is_less(a, b); }
inline bool operator > (const vec2& a, const vec2& b)	{ return vecnt_is_greater(a, b); }
inline bool operator <= (const vec2& a, const vec2& b)	{ return vecnt_is_less_equal(a, b); }
inline bool operator >= (const vec2& a, const vec2& b)	{ return vecnt_is_greater_equal(a, b); }


inline float vec2_dot(const vec2& a, const vec2& b) { return vecnt_dot(a, b); }
inline float vec2_length_sq(const vec2& a) { return vecnt_length_sq(a); }	
inline float vec2_length(const vec2& a) { return vecnt_length(a); }
inline float vec2_distance_sq(const vec2& a, const vec2& b) { return vecnt_distance_sq(a, b); }
inline float vec2_distance(const vec2& a, const vec2& b) { return vecnt_distance(a, b); }

inline vec2 vec2_scale(const vec2& a, float s) { return (a * s); }
inline vec2 vec2_lerp(const vec2& a, const vec2& b, float s) { return vecnt_lerp(a, b, s); }
inline vec2 vec2_min(const vec2& a, const vec2& b) { return vecnt_min(a, b); }
inline vec2 vec2_max(const vec2& a, const vec2& b) { return vecnt_max(a, b); }
inline vec2 vec2_clamp(const vec2& a, const vec2& min, const vec2& max) { return vecnt_clamp(a, min, max); }

inline vec2 vec2_normalize(const vec2& a) { return vecnt_normalize(a); }

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

inline vec3 operator + (float s, const vec3& a) { return a + s; }
inline vec3 operator - (float s, const vec3& a) { return a - s; }
inline vec3 operator * (float s, const vec3& a) { return a * s; }
inline vec3 operator / (float s, const vec3& a) { return a / s; }

inline bool vec3_equals_ep(const vec3& a, const vec3& b, float epsilon) { return vecnt_is_equal_ep(a, b, epsilon); }
inline bool vec3_equals_ep2(const vec3& a, const vec3& b) { return vecnt_is_equal_ep2(a, b); }

inline bool operator == (const vec3& a, const vec3& b) { return vecnt_is_equal(a, b); }
inline bool operator != (const vec3& a, const vec3& b) { return vecnt_is_not_equal(a, b); }

inline bool operator < (const vec3& a, const vec3& b)	{ return vecnt_is_less(a, b); }
inline bool operator > (const vec3& a, const vec3& b)	{ return vecnt_is_greater(a, b); }
inline bool operator <= (const vec3& a, const vec3& b)	{ return vecnt_is_less_equal(a, b); }
inline bool operator >= (const vec3& a, const vec3& b)	{ return vecnt_is_greater_equal(a, b); }


inline float vec3_dot(const vec3& a, const vec3& b) { return vecnt_dot(a, b); }
inline float vec3_length_sq(const vec3& a) { return vecnt_length_sq(a); }	
inline float vec3_length(const vec3& a) { return vecnt_length(a); }
inline float vec3_distance_sq(const vec3& a, const vec3& b) { return vecnt_distance_sq(a, b); }
inline float vec3_distance(const vec3& a, const vec3& b) { return vecnt_distance(a, b); }

inline vec3 vec3_scale(const vec3& a, float s) { return (a * s); }
inline vec3 vec3_lerp(const vec3& a, const vec3& b, float s) { return vecnt_lerp(a, b, s); }
inline vec3 vec3_min(const vec3& a, const vec3& b) { return vecnt_min(a, b); }
inline vec3 vec3_max(const vec3& a, const vec3& b) { return vecnt_max(a, b); }
inline vec3 vec3_clamp(const vec3& a, const vec3& min, const vec3& max) { return vecnt_clamp(a, min, max); }

inline vec3 vec3_normalize(const vec3& a) { return vecnt_normalize(a); }

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

inline vec4 operator + (float s, const vec4& a) { return a + s; }
inline vec4 operator - (float s, const vec4& a) { return a - s; }
inline vec4 operator * (float s, const vec4& a) { return a * s; }
inline vec4 operator / (float s, const vec4& a) { return a / s; }

inline bool vec4_equals_ep(const vec4& a, const vec4& b, float epsilon) { return vecnt_is_equal_ep(a, b, epsilon); }
inline bool vec4_equals_ep2(const vec4& a, const vec4& b) { return vecnt_is_equal_ep2(a, b); }

inline bool operator == (const vec4& a, const vec4& b) { return vecnt_is_equal(a, b); }
inline bool operator != (const vec4& a, const vec4& b) { return vecnt_is_not_equal(a, b); }

inline bool operator < (const vec4& a, const vec4& b)	{ return vecnt_is_less(a, b); }
inline bool operator > (const vec4& a, const vec4& b)	{ return vecnt_is_greater(a, b); }
inline bool operator <= (const vec4& a, const vec4& b)	{ return vecnt_is_less_equal(a, b); }
inline bool operator >= (const vec4& a, const vec4& b)	{ return vecnt_is_greater_equal(a, b); }


inline float vec4_dot(const vec4& a, const vec4& b) { return vecnt_dot(a, b); }
inline float vec4_length_sq(const vec4& a) { return vecnt_length_sq(a); }	
inline float vec4_length(const vec4& a) { return vecnt_length(a); }
inline float vec4_distance_sq(const vec4& a, const vec4& b) { return vecnt_distance_sq(a, b); }
inline float vec4_distance(const vec4& a, const vec4& b) { return vecnt_distance(a, b); }

inline vec4 vec4_scale(const vec4& a, float s) { return (a * s); }
inline vec4 vec4_lerp(const vec4& a, const vec4& b, float s) { return vecnt_lerp(a, b, s); }
inline vec4 vec4_min(const vec4& a, const vec4& b) { return vecnt_min(a, b); }
inline vec4 vec4_max(const vec4& a, const vec4& b) { return vecnt_max(a, b); }
inline vec4 vec4_clamp(const vec4& a, const vec4& min, const vec4& max) { return vecnt_clamp(a, min, max); }

inline vec4 vec4_normalize(const vec4& a) { return vecnt_normalize(a); }

//---------------------------------------------------
// color4
//---------------------------------------------------

inline color4 operator - (const color4& a) { return vecnt_negate(a); }

inline color4 operator + (const color4& a, const color4& b) { return vecnt_add(a, b); }
inline color4 operator - (const color4& a, const color4& b) { return vecnt_sub(a, b); }
inline color4 operator * (const color4& a, const color4& b) { return vecnt_mul(a, b); }
//inline color4 operator / (const color4& a, const color4& b) { return vecnt_div(a, b); }

inline color4 operator + (const color4& a, float s) { return vecnt_add_s(a, s); }
inline color4 operator - (const color4& a, float s) { return vecnt_sub_s(a, s); }
inline color4 operator * (const color4& a, float s) { return vecnt_mul_s(a, s); }
inline color4 operator / (const color4& a, float s) { return vecnt_div_s(a, s); }

inline color4 operator + (float s, const color4& a) { return a + s; }
inline color4 operator - (float s, const color4& a) { return a - s; }
inline color4 operator * (float s, const color4& a) { return a * s; }
inline color4 operator / (float s, const color4& a) { return a / s; }

inline bool color4_equals_ep(const color4& a, const color4& b, float epsilon) { return vecnt_is_equal_ep(a, b, epsilon); }
inline bool color4_equals_ep2(const color4& a, const color4& b) { return vecnt_is_equal_ep2(a, b); }

inline bool operator == (const color4& a, const color4& b) { return vecnt_is_equal(a, b); }
inline bool operator != (const color4& a, const color4& b) { return vecnt_is_not_equal(a, b); }

//inline bool operator < (const color4& a, const color4& b)	{ return vecnt_is_less(a, b); }
//inline bool operator > (const color4& a, const color4& b)	{ return vecnt_is_greater(a, b); }
//inline bool operator <= (const color4& a, const color4& b)	{ return vecnt_is_less_equal(a, b); }
//inline bool operator >= (const color4& a, const color4& b)	{ return vecnt_is_greater_equal(a, b); }

inline color4 color4_scale(const color4& a, float s) { return (a * s); }
inline color4 color4_lerp(const color4& a, const color4& b, float s) { return vecnt_lerp(a, b, s); }


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

inline mat4 operator + (float s, const mat4& a) { return a + s; }
inline mat4 operator - (float s, const mat4& a) { return a - s; }
inline mat4 operator * (float s, const mat4& a) { return a * s; }
inline mat4 operator / (float s, const mat4& a) { return a / s; }

inline bool mat4_equals_ep(const mat4& a, const mat4& b, float epsilon) { return vecnt_is_equal_ep(a, b, epsilon); }
inline bool mat4_equals_ep2(const mat4& a, const mat4& b) { return vecnt_is_equal_ep2(a, b); }

inline bool operator == (const mat4& a, const mat4& b) { return vecnt_is_equal(a, b); }
inline bool operator != (const mat4& a, const mat4& b) { return vecnt_is_not_equal(a, b); }

inline bool operator < (const mat4& a, const mat4& b)	{ return vecnt_is_less(a, b); }
inline bool operator > (const mat4& a, const mat4& b)	{ return vecnt_is_greater(a, b); }
inline bool operator <= (const mat4& a, const mat4& b)	{ return vecnt_is_less_equal(a, b); }
inline bool operator >= (const mat4& a, const mat4& b)	{ return vecnt_is_greater_equal(a, b); }


// Component wise multiplication and division. Hadamard product
inline mat4 mat4_mul_cw(const mat4& ma, const mat4& mb) { return vecnt_mul(ma, mb); }
inline mat4 mat4_div_cw(const mat4& ma, const mat4& mb) { return vecnt_div(ma, mb); }

inline mat4 operator * (const mat4& ma, const mat4& mb) { return mat4_mul(ma, mb); }

// Only difference between D3D_Math row matrix math & gl/glm matrix (column notation in docs 
// but otherwise stored as row major d3d like) is reverse multiply of mat4*mat4, vec4*mat4.
// written in reverse order as b*a or T*v, but internally does a*b or v*T resulting in same values.
inline mat4 mat4_mul_gl(const mat4& ma, const mat4& mb) {	
	return mat4_mul(mb, ma);
}

inline vec4 operator * (const vec4& va, const mat4& ma) { return vec4_mul_mat4(va, ma); }
inline vec4 operator * (const mat4& ma, const vec4& va) { return mat4_mul_vec4(ma, va); }

inline vec4 vec4_mul_mat4_gl(const vec4& va, const mat4& ma) {
	return mat4_mul_vec4(ma, va);
}
inline vec4 mat4_mul_vec4_gl(const mat4& ma, const vec4& va) {
	return vec4_mul_mat4(va, ma);
}

#endif
