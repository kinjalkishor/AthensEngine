#pragma once

#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <type_traits>

//============================
// Basic Types
//============================

//#include <limits>
//#include <float.h>

//using i8 = signed char;
//using i16 = signed short int;
//using i32 = signed int;
//using i64 = signed long long int;
//using u8 = unsigned char;
//using u16 = unsigned short int;
//using u32 = unsigned int;
//using u64 = unsigned long long int;


using int16 = signed short int;
using int64 = signed long long int;
using uint8 = unsigned char;
using uint16 = unsigned short int;
using uint = unsigned int;
using uint64 = unsigned long long int;


//using f32 = float;
//using f64 = double;
using ldouble = long double;

using isz = ptrdiff_t;
constexpr isz ISZ_MAX = PTRDIFF_MAX;
constexpr isz ISZ_MIN = PTRDIFF_MIN;

//using usz = size_t;

//using llong = signed long long int;
//using ushort = unsigned short int;
//using uint = unsigned int;
//using ullong = unsigned long long int;

using byte = unsigned char;	


//using wchar = wchar_t;
//using char8 = char8_t;
//using char16 = char16_t;
//using char32 = char32_t;


// Windows Types
//typedef unsigned long       DWORD;
//typedef int                 BOOL;
//typedef unsigned char       BYTE;
//typedef unsigned short      WORD;
//typedef float               FLOAT;
//typedef int                 INT;
//typedef unsigned int        UINT;
//typedef short				SHORT;
//typedef long				LONG;
//typedef char				CHAR;
//typedef unsigned short		USHORT;
//typedef unsigned long		ULONG;
//typedef unsigned char		UCHAR;
//typedef __int64				LONGLONG;
////typedef signed __int64 LONGLONG;
//typedef unsigned __int64	ULONGLONG;
//typedef wchar_t				WCHAR;    // wc,   16-bit UNICODE character
//typedef void*				HANDLE;
//typedef signed char         INT8;
//typedef signed short        INT16;
//typedef signed int          INT32;
//typedef signed __int64      INT64;
//typedef unsigned char       UINT8;
//typedef unsigned short      UINT16;
//typedef unsigned int        UINT32;
//typedef unsigned __int64    UINT64;
//typedef signed int			LONG32;
//typedef unsigned int		ULONG32;
//typedef unsigned int		DWORD32;
//typedef __int64				LONG64;
//// typedef signed __int64 LONG64;
//typedef unsigned __int64	ULONG64;
//typedef unsigned __int64	DWORD64;
//typedef unsigned __int64	QWORD;
//typedef BYTE				BOOLEAN;
//// A BSTR is a pointer to a null-terminated character string in which the string length is stored with the string.
//typedef WCHAR*				BSTR;
//typedef double				DOUBLE;
//typedef ULONGLONG			DWORDLONG;
//typedef LONG				HRESULT;
////typedef unsigned __int3264 ULONG_PTR;
//typedef ULONG_PTR			SIZE_T;
//typedef void				VOID;




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