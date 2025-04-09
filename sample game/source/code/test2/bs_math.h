#pragma once

#include <cmath>


//----------------------------------------------------------------
// Math Constants
//----------------------------------------------------------------
namespace mathdef
{
// Math defines
//----------------------------------------------
// openbsd math.h
//inline constexpr float GM_MAXFLOAT = (static_cast<float>(3.40282346638528860e+38)); //FLT_MAX


inline constexpr double GM_E				= 2.7182818284590452354;  // e - 2.7182818284590452353602874713527;
inline constexpr double GM_LOG2E			= 1.4426950408889634074;  // log 2e - 1.4426950408889634073599246810019;
inline constexpr double GM_LOG10E			= 0.43429448190325182765; // log 10e - 0.43429448190325182765112891891661;
inline constexpr double GM_LN2				= 0.69314718055994530942; // log e2 - 0.69314718055994530941723212145818;
inline constexpr double GM_LN10				= 2.30258509299404568402; // log e10 - 2.3025850929940456840179914546844;
inline constexpr double GM_PI				= 3.14159265358979323846; // pi - 3.1415926535897932384626433832795;
inline constexpr double GM_PI_2				= 1.57079632679489661923; // pi/2 - 1.5707963267948966192313216916398;
inline constexpr double GM_PI_4				= 0.78539816339744830962; // pi/4 - 0.78539816339744830961566084581988;
inline constexpr double GM_1_PI				= 0.31830988618379067154; // 1/pi - 0.31830988618379067153776752674503;
inline constexpr double GM_2_PI				= 0.63661977236758134308; // 2/pi - 0.63661977236758134307553505349006;
inline constexpr double GM_2_SQRTPI			= 1.12837916709551257390; // 2/sqrt(pi) - 1.1283791670955125738961589031215;
inline constexpr double GM_SQRT2			= 1.41421356237309504880; // sqrt(2) - 1.4142135623730950488016887242097;
inline constexpr double GM_1_SQRT2			= 0.70710678118654752440; // 1/sqrt(2) - 0.70710678118654752440084436210485;
											  
// other constants
inline constexpr double GM_1_SQRTPI			= 0.56418958354775628695;		// 1/sqrt(pi) - 0.56418958354775628694807945156077;
inline constexpr double GM_2PI				= 6.28318530717958647692;		// 2*pi; //TAU - 6.283185307179586476925286766559;
inline constexpr double GM_1_2PI			= 0.15915494309189533577;		// 1/2*pi - 0.15915494309189533576888376337251;
inline constexpr double GM_SQRT3		    = 1.73205080756887729352;       // sqrt(3) - 1.7320508075688772935274463415059;
inline constexpr double GM_1_SQRT3			= 0.57735026918962576450;       // 1/sqrt(3) - 0.57735026918962576450914878050196;

//---
//const double GM_3PI_4		= 2.356194490192344928845;		// (3*pi)/4- 2.3561944901923449288469825374596;
									   
//inline constexpr double GM_DEG_TO_RAD		= 0.017453292519943295769;	    // pi/180 - 0.01745329251994329576923690768489;
//inline constexpr double GM_RAD_TO_DEG		= 57.295779513082320876846;     // 180/pi - 57.295779513082320876798154814105;

//inline constexpr double GM_SEC_TO_MS		= 1000.0;
//inline constexpr double GM_MS_TO_SEC		= 0.001;

//inline constexpr float GM_FLT_INFINITY		= 1e30f;
//inline constexpr float GM_FLT_EPSILON		= 1.192092896e-07f;
}


//----------------------------------------------------------------
// Math Functions
//----------------------------------------------------------------
namespace mf
{


//---


template<class T>
inline constexpr T k_e	= static_cast<T>(mathdef::GM_E);
template<class T>
inline constexpr T k_log2e = static_cast<T>(mathdef::GM_LOG2E);
template<class T>
inline constexpr T k_log10e = static_cast<T>(mathdef::GM_LOG10E);
template<class T>
inline constexpr T k_ln2 = static_cast<T>(mathdef::GM_LN2);
template<class T>
inline constexpr T k_ln10 = static_cast<T>(mathdef::GM_LN10);
template<class T>
inline constexpr T k_pi = static_cast<T>(mathdef::GM_PI);
template<class T>
inline constexpr T k_pi_2 = static_cast<T>(mathdef::GM_PI_2);
template<class T>
inline constexpr T k_pi_4 = static_cast<T>(mathdef::GM_PI_4);
template<class T>
inline constexpr T k_1_pi = static_cast<T>(mathdef::GM_1_PI);
template<class T>
inline constexpr T k_2_pi = static_cast<T>(mathdef::GM_2_PI);
template<class T>
inline constexpr T k_2_sqrtpi = static_cast<T>(mathdef::GM_2_SQRTPI);
template<class T>
inline constexpr T k_sqrt2 = static_cast<T>(mathdef::GM_SQRT2);
template<class T>
inline constexpr T k_1_sqrt2 = static_cast<T>(mathdef::GM_1_SQRT2);
template<class T>
inline constexpr T k_1_sqrtpi = static_cast<T>(mathdef::GM_1_SQRTPI);
template<class T>
inline constexpr T k_2pi = static_cast<T>(mathdef::GM_2PI);
template<class T>
inline constexpr T k_1_2pi = static_cast<T>(mathdef::GM_1_2PI);
template<class T>
inline constexpr T k_sqrt3 = static_cast<T>(mathdef::GM_SQRT3);
template<class T>
inline constexpr T k_1_sqrt3 = static_cast<T>(mathdef::GM_1_SQRT3);

template<class T>
inline constexpr T k_epsilon = std::numeric_limits<T>::epsilon();
template<class T>
inline constexpr T k_infinity = std::numeric_limits<T>::infinity();
//template<class T>
//inline constexpr T k_round_error = std::numeric_limits<T>::round_error();
//template<class T>
//inline constexpr T k_real_min = std::numeric_limits<T>::min();
//template<class T>
//inline constexpr T k_real_max = std::numeric_limits<T>::max();

//template<class T>
//inline constexpr T k_zero = static_cast<T>(0);
//template<class T>
//inline constexpr T k_one = static_cast<T>(1);

template<class T>
inline constexpr T k_eps7 = static_cast<T>(0.0000005);

template<class T>
inline constexpr T k_small_eps = static_cast<T>(0.0005);
template<class T>
inline constexpr T k_eps = static_cast<T>(0.005);
template<class T>
inline constexpr T k_big_eps = static_cast<T>(0.05);


//==============================================
//template<class T> 
//inline T fabs(T x) { return std::fabs(x); }





//==============================================
inline float deg_to_rad(float degree) { return (degree * (k_pi<float> / static_cast<float>(180.0))); }
inline float rad_to_deg(float radian) { return (radian * (static_cast<float>(180.0) / k_pi<float>)); }


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
	return equals_ep(a, b, mf::k_eps7<T>);
}


// lerp, mix: a + s*(b-a)
template<class T>
inline T lerp(T a, T b, T s) {
	// Precision loss when a and b significantly differ in magnitude for (b-a)
	//return (a + s*(b - a)); //d3dx9
	//return (a + (b - a)*s);
	// handles unsigned values wraparound
	//return (a*(static_cast<T>(1.0)-s) + s*b);
	return (a*(static_cast<T>(1.0)-s) + b*s);
}



//===============================================================================================
//#define Square(x)                     (x*x)
//#define Saturate(x)                   clamp(x, 0.0, 1.0)
//#define Min3(x, y, z)                 min(x, min(y, z))
//#define Max3(x, y, z)                 max(x, max(y, z))
//#define RemapTo01(x)                  (x * 0.5 + 0.5)
//#define SmoothAbs(x, k, offset)       (sqrt(x * x + k * k) - offset)
}
