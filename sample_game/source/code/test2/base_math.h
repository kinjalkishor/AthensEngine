#pragma once

#include <cmath>
//C++11 mt19937, mt19937_64
//#include <random>

#include "base_types.h"


//----------------------------------------------------------------
// Math Constants
//----------------------------------------------------------------
namespace mathdef
{
// Math defines
//----------------------------------------------
// openbsd math.h
inline constexpr double GM_E				= 2.7182818284590452354;  // e - 2.7182818284590452353602874713527;
inline constexpr double GM_LOG2E			= 1.4426950408889634074;  // log 2e - 1.4426950408889634073599246810019;
inline constexpr double GM_LOG10E			= 0.43429448190325182765; // log 10e - 0.43429448190325182765112891891661;
inline constexpr double GM_LN2				= 0.69314718055994530942; // log e2 - 0.69314718055994530941723212145818;
inline constexpr double GM_LN10				= 2.30258509299404568402; // log e10 - 2.3025850929940456840179914546844;
inline constexpr double GM_PI				= 3.14159265358979323846; // pi - 3.1415926535897932384626433832795;
inline constexpr double GM_INV_PI_2			= 1.57079632679489661923; // pi/2 - 1.5707963267948966192313216916398;
inline constexpr double GM_INV_PI_4			= 0.78539816339744830962; // pi/4 - 0.78539816339744830961566084581988;
inline constexpr double GM_INV_1_PI			= 0.31830988618379067154; // 1/pi - 0.31830988618379067153776752674503;
inline constexpr double GM_INV_2_PI			= 0.63661977236758134308; // 2/pi - 0.63661977236758134307553505349006;
inline constexpr double GM_INV_2_SQRTPI		= 1.12837916709551257390; // 2/sqrt(pi) - 1.1283791670955125738961589031215;
inline constexpr double GM_SQRT2			= 1.41421356237309504880; // sqrt(2) - 1.4142135623730950488016887242097;
inline constexpr double GM_INV_1_SQRT2		= 0.70710678118654752440; // 1/sqrt(2) - 0.70710678118654752440084436210485;
											  
// other constants
inline constexpr double GM_INV_1_SQRTPI		= 0.56418958354775628695;		// 1/sqrt(pi) - 0.56418958354775628694807945156077;
inline constexpr double GM_2PI				= 6.28318530717958647692;		// 2*pi; //TAU - 6.283185307179586476925286766559;
inline constexpr double GM_INV_1_2PI		= 0.15915494309189533577;		// 1/2*pi - 0.15915494309189533576888376337251;
inline constexpr double GM_SQRT3		    = 1.73205080756887729352;       // sqrt(3) - 1.7320508075688772935274463415059;
inline constexpr double GM_INV_1_SQRT3		= 0.57735026918962576450;       // 1/sqrt(3) - 0.57735026918962576450914878050196;

//---
//const double GM_INV_3PI_4		= 2.356194490192344928845;		// (3*pi)/4- 2.3561944901923449288469825374596;
									   
inline constexpr double GM_DEG_TO_RAD		= 0.017453292519943295769;	    // pi/180 - 0.01745329251994329576923690768489;
inline constexpr double GM_RAD_TO_DEG		= 57.295779513082320876846;     // 180/pi - 57.295779513082320876798154814105;

inline constexpr double GM_SEC_TO_MS		= 1000.0;
inline constexpr double GM_MS_TO_SEC		= 0.001;

inline constexpr float GM_FLT_INFINITY		= 1e30f;
inline constexpr float GM_FLT_EPSILON		= 1.192092896e-07f;
}

//----------------------------------------------------------------
// Math Functions
//----------------------------------------------------------------
namespace mf
{

template<class T>
inline constexpr T k_e	= scast<T>(mathdef::GM_E);
template<class T>
inline constexpr T k_log2e = scast<T>(mathdef::GM_LOG2E);
template<class T>
inline constexpr T k_log10e = scast<T>(mathdef::GM_LOG10E);
template<class T>
inline constexpr T k_ln2 = scast<T>(mathdef::GM_LN2);
template<class T>
inline constexpr T k_ln10 = scast<T>(mathdef::GM_LN10);
template<class T>
inline constexpr T k_pi = scast<T>(mathdef::GM_PI);
template<class T>
inline constexpr T k_inv_pi_2 = scast<T>(mathdef::GM_INV_PI_2);
template<class T>
inline constexpr T k_inv_pi_4 = scast<T>(mathdef::GM_INV_PI_4);
template<class T>
inline constexpr T k_inv_1_pi = scast<T>(mathdef::GM_INV_1_PI);
template<class T>
inline constexpr T k_inv_2_pi = scast<T>(mathdef::GM_INV_2_PI);
template<class T>
inline constexpr T k_inv_2_sqrtpi = scast<T>(mathdef::GM_INV_2_SQRTPI);
template<class T>
inline constexpr T k_sqrt2 = scast<T>(mathdef::GM_SQRT2);
template<class T>
inline constexpr T k_inv_1_sqrt2 = scast<T>(mathdef::GM_INV_1_SQRT2);
template<class T>
inline constexpr T k_inv_1_sqrtpi = scast<T>(mathdef::GM_INV_1_SQRTPI);
template<class T>
inline constexpr T k_2pi = scast<T>(mathdef::GM_2PI);
template<class T>
inline constexpr T k_inv_1_2pi = scast<T>(mathdef::GM_INV_1_2PI);
template<class T>
inline constexpr T k_sqrt3 = scast<T>(mathdef::GM_SQRT3);
template<class T>
inline constexpr T k_inv_1_sqrt3 = scast<T>(mathdef::GM_INV_1_SQRT3);

template<class T>
inline constexpr T k_epsilon = std::numeric_limits<T>::epsilon();
template<class T>
inline constexpr T k_infinity = std::numeric_limits<T>::infinity();
template<class T>
inline constexpr T k_round_error = std::numeric_limits<T>::round_error();
template<class T>
inline constexpr T k_real_min = std::numeric_limits<T>::min();
template<class T>
inline constexpr T k_real_max = std::numeric_limits<T>::max();

//template<class T>
//inline constexpr T k_zero = scast<T>(0);
//template<class T>
//inline constexpr T k_one = scast<T>(1);

template<class T>
inline constexpr T k_epsilon6 = scast<T>(0.0000005);

//----------------------------
template<class T>
inline T deg_to_rad(T a) {	
	//return (a * (k_pi / scast<T>(180)));
    return (a * scast<T>(mathdef::GM_DEG_TO_RAD));
}

template<class T>
inline T rad_to_deg(T a) {	
	//return (a * (scast<T>(180) / k_pi));
	return (a * scast<T>(mathdef::GM_RAD_TO_DEG));
}

template<class T>
inline T square(const T a) {
	return (a*a);
}

template<class T>
inline T cube(const T a) {
	return (a*a*a);
}

template<class T>
inline T rsqrt(const T a) {
	return (scast<T>(1)/std::sqrt(a));
}

// lerp, mix: a + s*(b-a)
template<class T>
inline T lerp(T a, T b, T s) {
	// Precision loss when a and b significantly differ in magnitude for (b-a)
	//return (a + s*(b-a));
	//return (a + (b-a)*s);
	// handles unsigned values wraparound
	//return (a*(scast<T>(1)-s) + s*b);
	return (a*(scast<T>(1)-s) + b*s);
}


//---
// returns if a equals b, taking possible rounding errors into account
template<class T>
inline bool equals_ep(T a, T b, const T epsilon) { 
	if ((std::fabs(a - b) > epsilon)) { return false; }	
	else { return true; } 
	//return approximately_equal(a, b, epsilon);
}

template<class T>
inline bool equals(T a, T b) { 
	return equals_ep(a, b, mf::k_epsilon<T>);
}

template<class T>
inline bool equals2(T a, T b) { 
	return equals_ep(a, b, mf::k_epsilon6<T>);
}

template<class T>
inline bool equals_zero(T a) { 
	return equals_ep(a, scast<T>(0), mf::k_epsilon<T>);
}

//---------------------------
// Convert horizontal field of view to vertical field of view.
// xfov, yfov are in radians. Convert in degrees if required
//mf::rad_to_deg(mf::yfov_from_xfov(mf::deg_to_rad(rs_xfov->data.floatval), sdf::get_aspect_ratio(16, 9)))
inline float yfov_from_xfov(float xfov, float aspect) {
    return (scast<float>(2) * atan(tan(xfov * float(0.5)) / aspect));
}

// Convert vertical field of view to horizontal field of view. 
// xfov_beta = 2 * inverse_of_tan(aspect_r * tan(yfov_alpha/2))
inline float xfov_from_yfov(float yfov, float aspect) {
    return (scast<float>(2) * atan(tan(yfov * float(0.5)) * aspect));
}

inline float yfov_from_xfov_deg(float xfov_deg, float aspect) {
	return mf::yfov_from_xfov(mf::deg_to_rad(xfov_deg), aspect);
}

inline float xfov_from_yfov_deg(float yfov_deg, float aspect) {
	return mf::xfov_from_yfov(mf::deg_to_rad(yfov_deg), aspect);
}

}


