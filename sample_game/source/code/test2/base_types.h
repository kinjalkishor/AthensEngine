#pragma once

#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <type_traits>

//============================
// Basic Types
//============================

//using i8 = signed char;
//using i16 = signed short int;
//using i32 = signed int;
//using i64 = signed long long int;
//using u8 = unsigned char;
//using u16 = unsigned short int;
//using u32 = unsigned int;
//using u64 = unsigned long long int;
//using f32 = float;
//using f64 = double;


using int16 = signed short int;
using int64 = signed long long int;
using uint8 = unsigned char;
using uint16 = unsigned short int;
using uint = unsigned int;
using uint64 = unsigned long long int;

using ldouble = long double;

using isz = ptrdiff_t;
constexpr isz ISZ_MAX = PTRDIFF_MAX;
constexpr isz ISZ_MIN = PTRDIFF_MIN;

//using usz = size_t;

//using llong = signed long long int;
//using ushort = unsigned short int;
//using ullong = unsigned long long int;

using byte = unsigned char;	


//======================================
// MISC
//======================================
#define for_range(v, start, end)	for (std::decay_t<decltype(end)> v(start); v < end; ++v)
#define for_range_c(v, cont)		for_range(v, 0, cont.size())
//#define for_range_e(v, end)			for (std::decay_t<decltype(end)> v(0); v < end; ++v)

#define scast						static_cast
#define dcast						dynamic_cast
#define rcast						reinterpret_cast
#define ccast						const_cast



//======================================
// NAMESPACE TYPEDEF
//======================================
namespace std::pmr {}
namespace sdr = std::pmr;


//======================================
// C++ defines
//======================================
// For std::cout easy endline
//#define qwe		"\n"