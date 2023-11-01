#pragma once

#include "../base_math.h"

#include "irr_shared.h"

namespace sdf 
{
template<class T>
inline const T& min3(const T& a, const T& b, const T& c) {
	return a < b ? tmin(a, c) : tmin(b, c);
}

//! returns maximum of three values. Own implementation to get rid of the STL (VS6 problems)
template<class T>
inline const T& max3(const T& a, const T& b, const T& c) {
	return a > b ? tmax(a, c) : tmax(b, c);
}

// Note: We use the same trick as boost and use two template arguments to
// avoid ambiguity when swapping objects of an Irrlicht type that has not
// it's own swap overload. Otherwise we get conflicts with some compilers
// in combination with stl.
//template <class T1, class T2>
//inline void swap_irr(T1& a, T2& b) {
//	T1 c(a);
//	a = b;
//	b = c;
//}

}

//----------------------------------------------------------------
namespace mf
{


//const float ROUNDING_ERROR_f32 = 0.000001f;
//const double ROUNDING_ERROR_f64 = 0.00000001;

template<class T>
inline const T k_epsilon_irr = scast<T>(0);
template<>
inline const float k_epsilon_irr<float> = scast<float>(0.000001);
template<>
inline const double k_epsilon_irr<double> = scast<double>(0.00000001);


//const double PI64 = 3.1415926535897932384626433832795028841971693993751;

const float PI = mf::k_pi<float>; //= 3.14159265359f;
const float RECIPROCAL_PI	= mf::k_inv_1_pi<float>; //= 1.0f/PI;
const float HALF_PI = mf::k_inv_pi_2<float>; //= PI/2.0f;
const float DEGTORAD = scast<float>(mathdef::GM_DEG_TO_RAD); //= PI / 180.0f;
const float RADTODEG = scast<float>(mathdef::GM_RAD_TO_DEG); //= 180.0f / PI;



template<class T>
inline T abs_irr(const T& a) 	{
	return a < (T)0 ? -a : a;
}

union FloatIntUnion32 {
	FloatIntUnion32(float f1 = 0.0f) : f(f1) {}
	// Portable sign-extraction
	bool sign() const { return (i >> 31) != 0; }

	int i;
	float f;
};

//! We compare the difference in ULP's (spacing between floating-point numbers, aka ULP=1 means there exists no float between).
//\result true when numbers have a ULP <= maxUlpDiff AND have the same sign.
inline bool equalsByUlp(float a, float b, int maxUlpDiff) {
	// Based on the ideas and code from Bruce Dawson on
	// http://www.altdevblogaday.com/2012/02/22/comparing-floating-point-numbers-2012-edition/
	// When floats are interpreted as integers the two nearest possible float numbers differ just
	// by one integer number. Also works the other way round, an integer of 1 interpreted as float
	// is for example the smallest possible float number.

	FloatIntUnion32 fa(a);
	FloatIntUnion32 fb(b);

	// Different signs, we could maybe get difference to 0, but so close to 0 using epsilons is better.
	if (fa.sign() != fb.sign()) {
		// Check for equality to make sure +0==-0
		if (fa.i == fb.i)
			return true;
		return false;
	}

	// Find the difference in ULPs.
	int ulpsDiff = abs_irr(fa.i- fb.i);
	if (ulpsDiff <= maxUlpDiff) {
		return true;
	}

	return false;
}


template<class T>
inline bool equals_irr(T a, T b, T tolerance = k_epsilon_irr<T>) {
	return (a + tolerance >= b) && (a - tolerance <= b);
}


template<class T>
inline bool is_zero(const T a, const T tolerance = k_epsilon_irr<T>) {
	return fabs(a) <= tolerance;
}

template<class T>
inline bool is_notzero(const T a, const T tolerance = k_epsilon_irr<T>) {
	return fabs(a) > tolerance;
}


inline s32 s32_min(s32 a, s32 b) {
	const s32 mask = (a - b) >> 31;
	return (a & mask) | (b & ~mask);
}

inline s32 s32_max(s32 a, s32 b) {
	const s32 mask = (a - b) >> 31;
	return (b & mask) | (a & ~mask);
}

inline s32 s32_clamp (s32 value, s32 low, s32 high) {
	return s32_min(s32_max(value,low), high);
}


inline float reciprocal(float x) {
	return (scast<float>(1) / x);
}

// fractional part of x
inline float fract(float x) {
	return x - floorf(x);
}

inline float round(float x) {
	return floorf( x + 0.5f );
}

//squareroot = sqrt
//reciprocal_squareroot = rsqrt

//typedef union { uint u; s32 s; float f; } inttofloat;
//
//#define F32_AS_S32(f)		(*((s32 *) &(f)))
//#define F32_AS_U32(f)		(*((uint *) &(f)))
//
////! Integer representation of a floating-point value.
//#ifdef IRRLICHT_FAST_MATH
//#define IR(x)                           ((uint&)(x))
//#else
//inline uint IR(float x) {inttofloat tmp; tmp.f=x; return tmp.u;}
//#endif
//
////! Absolute integer representation of a floating-point value
//#define AIR(x)				(IR(x)&0x7fffffff)
//
////! Floating-point representation of an integer value.
//#ifdef IRRLICHT_FAST_MATH
//#define FR(x)                           ((float&)(x))
//#else
//inline float FR(uint x) {inttofloat tmp; tmp.u=x; return tmp.f;}
//inline float FR(s32 x) {inttofloat tmp; tmp.s=x; return tmp.f;}
//#endif


}