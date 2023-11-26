#pragma once

//-----------------------------------------------------------------------------------------------------
// BASE_DEF
//-----------------------------------------------------------------------------------------------------

//=====================================================================
//#include <limits>
//#include <float.h>

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
//=====================================================================

#include <cstring>

//#if _MSC_VER
//// Inconsistent annotation for function: this instance has an error
//#pragma warning(disable : 28251)	
////libcmt.lib conflicts with use of other libs warning
//#pragma comment(linker, "/NODEFAULTLIB:libcmt.lib")
//#endif

// CHECK: using better than typedef

// Rust's bool has the same layout as C17's _Bool, that is, its size and alignment are implementation-defined. 
// Any bool can be cast into an integer, taking on the values 1 (true) or 0 (false).
// Rust char is 32-bit wide and represents an unicode scalar value. The alignment of char is implementation-defined.
// The isize and usize types are pointer-sized signed and unsigned integers. They have the same layout as the pointer types 
// for which the pointee is Sized, and are layout compatible with C's uintptr_t and intptr_t types.
// Rust's signed and unsigned fixed-width integer types {i,u}{8,16,32,64} have the same layout as 
// the C fixed-width integer types from the <stdint.h> header {u,}int{8,16,32,64}_t
// These fixed-width integer types are therefore safe to use directly in C FFI where the corresponding C fixed-width integer types are expected.
// The alignment of Rust's {i,u}128 is unspecified and allowed to change.
// The specification of native C integer types, char, short, int, long, ... as well as their unsigned variants, guarantees 
// a lower bound on their size, e.g., short is at least 16-bit wide and at least as wide as char.
// Their exact sizes are implementation-defined.
// Rust's f32 and f64 single (32-bit) and double (64-bit) precision floating-point types have IEEE-754 binary32 and binary64 
// floating-point layouts, respectively.
// When the platforms' "math.h" header defines the __STDC_IEC_559__ macro, Rust's floating-point types are safe to use directly 
// in C FFI where the appropriate C types are expected (f32 for float, f64 for double).
// If the C platform's "math.h" header does not define the __STDC_IEC_559__ macro, whether using f32 and f64 in C FFI is safe or 
// not for which C type is implementation-defined.

// On 64 bit windows platforms.
// int, long - 32 bit
// ULONG - 32 bit, use portable ULONG_PTR instead
// Pointers - 64 bit, pointer value truncated if assigned to a 32-bit variable.
// size_t, time_t, ptrdiff_t - 64 bit, check if int is processes as these and then truncated when passed back as int.
// %x in printf works on only first 32 bits, use %I32x (32 bit), %I64x (64 bit). %p (hex format for a pointer) will work as expected.
// A 32-bit unsigned negative number becomes a large 64-bit positive number, declare variable as a signed value or explicitly typecast it to LONG.

// Alignment (1 byte is 8 bits) - Byte – 8 bits, Word – 16 bits, Double Word – 32 bits, Quad Word – 64 bits, Octa Word – 128 bits.
// int32 can store 32 bit values or 32 flags.

//int32_t //long int // max_size 2 billion
//uint32_t // unsigned long int
//int64_t //long long int 
//uint64_t // unsigned long long int



// Data type size:
//char			1 byte
//short			2 bytes
//int			4 bytes	
//long			4 bytes (8 bytes on other 64 bit OS LP64, Windows64 is LLP64)
//long long		8 bytes		
//float			4 bytes
//double		8 bytes
//long double	16 bytes
// Pointers 8 bytes (64-bit)
//intptr_t		Signed integer of size equal to a pointer
//uintptr_t		Unsigned integer of size equal to a pointer
//size_t, time_t, and ptrdiff_t 64-bit
//intmax_t		Biggest size of integer on the platform (might be larger than int64_t)
//time_t		64-bit


// used in math functions
//using llint = signed long long int;
//using ullint = unsigned long long int;
//using half16 = uint16;		// 16-bit float


//typedef uint16			word;					// 16-bit unsigned, word.
//typedef uint32			dword;					// 32-bit unsigned, double word.
//typedef uint64			qword;					// 64-bit unsigned, quad word.
// Windows defines
//typedef int                 BOOL;
//typedef unsigned char       BYTE;
//typedef unsigned short	  WORD;
//typedef unsigned long       DWORD;
//typedef unsigned __int64	  DWORDLONG;
// windows DWORDLONG is ULONGLONG or uint64. DWORD is uint32
//typedef __int64 LONGLONG;	//LL
//typedef unsigned __int64 ULONGLONG; //ULL


#if defined(_WINDOWS)
	#if defined(_MSC_VER)
			using i8 = signed __int8;
			using uint8 = unsigned __int8;
			using i16 = signed __int16;
			using u16 = unsigned __int16;
			using i32 = signed __int32;				// long int					// max_size 2 billion
			using u32 = unsigned __int32;			// unsigned long int
			using i64 = signed __int64;				// long long int
			using u64 = unsigned __int64;			// unsigned long long int
	#else
			using i8 = signed char;
			using uint8 = unsigned char;
			using i16 = signed short int;
			using u16 = unsigned short int;
			using i32 = signed long int;		
			using u32 = unsigned long int;		
			using i64 = signed long long int;
			using u64 = unsigned long long int;
	#endif
#endif

//using isize = intmax_t;		//int64;	 //ssize_t //ptrdiff_t //isz
//using usize = uintmax_t;		//uint64;	 //size_t //size_t
//using iptr = intptr_t;
//using uptr = uintptr_t;

// For api that takes only unsigned int
using u32 = unsigned int;

using isz = intmax_t;
using usz = size_t;		//uintmax_t;


using f32 = float;
using f64 = double;

using c8 = char8_t;
using c16 = char16_t;
using c32 = char32_t;

using schar = signed char;
using wchar = wchar_t;

//using ushort = unsigned short int;
//using ulong = unsigned long int;		
//using ulonglong = unsigned long long int;

//============================
// User Defined Types
//============================
using byte = unsigned char;		

//---------------------------
//#include <cstdint>
// index types, maximum int size provided by system
// On 32 bit system 2^31 int32 type char array(1 byte unit) will take 16GB RAM
// On 64 bit system 2^63 int64 type char array(1 byte unit) will take 68719476736 GB of Ram
//size_t holds numbers as large as the address space

// ptrdiff_t, intptr_t, ssize_t
//typedef long long          intmax_t;
//typedef unsigned long long uintmax_t;
//#ifdef _WIN64
//    typedef unsigned __int64    size_t;
//    typedef __int64             ptrdiff_t;
//    typedef __int64             intptr_t;
//    typedef unsigned __int64    uintptr_t;
//#else
//    typedef unsigned int        size_t;
//    typedef int                 ptrdiff_t;
//    typedef int                 intptr_t;
//    typedef unsigned int        uintptr_t;
//#endif

//#ifdef _WIN64 || __LP64__ 
//    using isz = signed __int64;
//    using size_t = unsigned __int64;
//#else
//    using isz = signed int;
//    using size_t = unsigned int;
//#endif

//using uchar = unsigned char;

//#ifdef _WIN64
//using isz = signed long long int;
//constexpr isz ISZ_MAX = LLONG_MAX;
//constexpr isz ISZ_MIN = LLONG_MIN;
//#else _WIN32
//using isz = signed int;
//constexpr isz ISZ_MAX = INT_MAX;
//constexpr isz ISZ_MIN = INT_MIN;
//#endif

//-----------------------
//__LP32__, __LP64__ (_LP64) //Linux
//__i386__, __x86_64__ //arch
//
//#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
//   //define something for Windows (32-bit and 64-bit, this part is common)
//   #ifdef _WIN64
//      //define something for Windows (64-bit only)
//   #else
//      //define something for Windows (32-bit only)
//   #endif
//#elif __APPLE__
//    #include <TargetConditionals.h>
//    #if TARGET_IPHONE_SIMULATOR
//         // iOS, tvOS, or watchOS Simulator
//    #elif TARGET_OS_MACCATALYST
//         // Mac's Catalyst (ports iOS API into Mac, like UIKit).
//    #elif TARGET_OS_IPHONE
//        // iOS, tvOS, or watchOS device
//    #elif TARGET_OS_MAC
//        // Other kinds of Apple platforms
//    #else
//    #   error "Unknown Apple platform"
//    #endif
//#elif __ANDROID__
//    // Below __linux__ check should be enough to handle Android,
//    // but something may be unique to Android.
//#elif __linux__
//    // linux
//#elif __unix__ // all unices not caught above
//    // Unix
//#elif defined(_POSIX_VERSION)
//    // POSIX
//#else
//#   error "Unknown compiler"
//#endif



//----------------------------------------------------------
//#define forloopi32(v, m)			for(int v = 0; v < int(m); ++v)
//#define forloopu32(v, m)			for(uint v = 0; v < uint(m); ++v)
//#define forloopi64(v, m)			for(int64 v = 0; v < int64(m); ++v)
//#define forloopu64(v, m)			for(uint64 v = 0; v < uint64(m); ++v)
//#define forloopisz(v, m)			for(isz v = 0; v < isz(m); ++v)
//#define forloopusz(v, m)			for(size_t v = 0; v < size_t(m); ++v)
//#define forloopi_rev(v, m)		for(int v = int(m); --v >= 0;)
//#define forloop_t(type, x, v, m)	for (type v = x; v < type(m); ++v)
//#define forloopi_step(v, m, step)	for(int v = 0; v < m; i += step)



//=========================
// CONSOLE color printing
//=========================
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// You can loop k higher to see more color choices
for (int k = 1; k < 255; k++) {
	SetConsoleTextAttribute(hConsole, k);
	printf("%3d  %s\n", k, "I want to be nice today!");
}
int k = scast<uint16>(12);
SetConsoleTextAttribute(hConsole, k);
printf("%3d  %s\n", k, "I want to be nice today!");



//=========================
// Utility Functions
//=========================

// vsnprintf: returns -1 only on error and returns count of needed size if it does not fit into buffer.
// _vsnprintf, _vsnwprintf: returns -1 even if buffer is small. 
#ifdef _WIN32
	#define fm_vsnprintf	vsnprintf
	#define fm_vsnwprintf	_vsnwprintf
#else
	#define fm_vsnprintf	vsnprintf
	#define fm_vsnwprintf	vswprintf 
#endif

//SecureZeroMemory
#define fm_zero_memory(dest, length)		memset((dest), 0, (length))


// Safe Memory freeing.
//#undef SAFE_DELETE
#define q_safe_delete(p)			{ if(p) { delete (p);		(p) = nullptr; } }
#define q_safe_free(p)				{ if(p) { free(p);		(p) = nullptr; } }

// Memory allocated by new[] should always be free by delete[] or only one elment will be deleted by delete.
//#undef SAFE_DELETE_ARR
#define q_safe_delete_arr(p)		{ if(p) { delete[] (p);		(p) = nullptr; } }

//#define q_finfo(msg)		(__FUNCTION__": "  #msg)
//#define q_finfo(...)		(__FUNCTION__": ",  __VA_ARGS__)

// BITSET
#define BIT(num)	(1ULL << (num))


// C++03
//template<class T>
//inline void swap(T& a, T& b) {
//    T temp = a;
//    a = b;
//    b = temp;
//}



//-----------------------
// BITSET
//-----------------------
inline void bit_set(size_t& x, size_t n) { (x |= (1ULL<<n)); }
inline void bit_clear(size_t& x, size_t n) { (x &= ~(1ULL<<n)); }
inline void bit_flip(size_t& x, size_t n) { (x ^= (1ULL<<n)); }
inline bool bit_check(size_t x, size_t n) { return scast<bool>(x & (1ULL<<n)); }   
inline void bitmask_set(size_t& x, size_t mask) { (x |= mask); }
inline void bitmask_clear(size_t& x, size_t mask) { (x &= (~mask)); }
inline void bitmask_flip(size_t& x, size_t mask) { (x ^= mask); }
inline bool bitmask_check_all(size_t x, size_t mask) { return scast<bool>(!(~x & mask)); }
inline bool bitmask_check_any(size_t x, size_t mask) { return scast<bool>(x & mask); }


// Safe Set nullptr
//#define q_safe_null(p)			{ if(p) { (p) = nullptr; } }




// ARRAYSIZE in C only
// Return the number of elements in a statically sized array.
// This is also popularly known as: NUMBER_OF, ARRSIZE, _countof, NELEM, etc.
//#define ARRAYSIZE(A) (sizeof(A)/sizeof((A)[0]))

// ARRAYSIZE in C++ with macro only
// When sizeof(a) is not a multiple of sizeof(* (a)), the % is not zero, which the ! inverts, 
// and then the static_cast evaluates to zero, causing a compile-time division by zero. So to 
// the extent possible in a macro, this division catches the problem at compile-time.
//#define ARRAYSIZE(a) \
//  ((sizeof(a) / sizeof(*(a))) / \
//  static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

// ARRAYSIZE in C++
// We never call _ArraySizeHelper, we just take the size of dereferencing its return type.
// We do not even implement _ArraySizeHelper, we just declare it.
// Attempts to pass pointers instead of arrays to this macro result in compile time errors.
// For before C++17 only, use std::size (C++17) and std::ssize (C++20)
template <typename T, size_t N>
char (*_ArraySizeHelper( __unaligned T (&)[N] ))[N];
#define fm_array_size(A) (sizeof(*_ArraySizeHelper(A)))
#define fm_array_ssize(A)   static_cast<int64_t>(fm_array_size(A))



//#define q_memory_equals(Destination, Source, Length)	(!memcmp((Destination), (Source), (Length)))
//#define q_memory_move(Destination, Source, Length)		memmove((Destination), (Source), (Length))
//#define q_memory_copy(Destination, Source, Length)		memcpy((Destination), (Source), (Length))
//#define q_memory_fill(Destination, Length, Fill)		memset((Destination), (Fill), (Length))
//#define q_memory_zero(Destination, Length)				memset((Destination), 0, (Length))


#define q_copy_array(dest, src)		std::copy(std::begin(src), std::end(src), dest)

template<class T>
void com_move_ptr_data(T*& out_ptr, T*& in_ptr) {
    *out_ptr = *in_ptr;
    in_ptr = nullptr;
}

inline constexpr size_t k_KB =	1024; 
inline constexpr size_t k_MB =	1048576; 
inline constexpr size_t k_GB =	1073741824; 
inline constexpr size_t k_TB =	1099511627776; 
inline size_t bytes_from_kb(size_t x) { return (x * k_KB); }
inline size_t bytes_from_mb(size_t x) { return (x * k_MB); }
inline size_t bytes_from_gb(size_t x) { return (x * k_GB); }
inline size_t bytes_from_tb(size_t x) { return (x * k_TB); }


//---------------------------------
// STRING
//---------------------------------

template<class T> inline isz strfz_len(const T* src);
template<> inline isz strfz_len(const char* src) { return strlen(src); }
template<> inline isz strfz_len(const wchar_t* src) { return wcslen(src); }


template<class T>
inline isz strfz_assign(T* dest, isz dest_capacity, const T* src) {
    isz src_len = sdf::strfz_len(src);
    return strf_assign(dest, dest_capacity, src, src_len);
}
template<class T>
inline isz strfz_assign_n(T* dest, isz dest_capacity, const T* src, isz n) {
    isz src_len = sdf::strfz_len(src); //not needed for strf_assign_n.
    if (n > src_len) { n = src_len; }
    return strf_assign(dest, dest_capacity, src, n);
}
template<class T>
inline isz strfz_append(T* dest, isz dest_capacity, const T* src) {
    isz src_len = sdf::strfz_len(src);
    isz dest_len = sdf::strfz_len(dest);
    return strf_append(dest, dest_len, dest_capacity, src, src_len);    
}
template<class T>
inline isz strfz_append_n(T* dest, isz dest_capacity, const T* src, isz n) {
    isz src_len = sdf::strfz_len(src); 
    if (n > src_len) { n = src_len; }
    isz dest_len = sdf::strfz_len(dest);
    return strf_append(dest, dest_len, dest_capacity, src, n);    
}


#if 0

int mb_wcs_from_mbs(wchar_t* dest, int dest_num_chars, const char* src, int src_len);
int mb_mbs_from_wcs(char* dest, int dest_num_chars, const wchar_t* src, int src_len);

inline isz strf_assign_mbs(wchar_t* dest, isz dest_capacity, const char* src, isz src_len) {
    isz copy_len = src_len;
    if (copy_len > dest_capacity) { copy_len = dest_capacity; }
	sdf::mb_wcs_from_mbs(dest, dest_capacity, src, copy_len);
	dest[copy_len] = k_null_char<wchar_t>();
	return copy_len;
}
inline isz strf_assign_wcs(char* dest, isz dest_capacity, const wchar_t* src, isz src_len) {
    isz copy_len = src_len;
    if (copy_len > dest_capacity) { copy_len = dest_capacity; }
	sdf::mb_mbs_from_wcs(dest, dest_capacity, src, copy_len);
	dest[copy_len] = k_null_char<char>();
	return copy_len;
}

inline isz strfz_wcs_from_mbs(wchar_t* dest, isz dest_capacity, const char* src) {
    isz src_len = sdf::strfz_len(src); 
    return strf_assign_mbs(dest, dest_capacity, src, src_len);
}
inline isz strfz_mbs_from_wcs(char* dest, isz dest_capacity, const wchar_t* src) {
    isz src_len = sdf::strfz_len(src); 
    return strf_assign_wcs(dest, dest_capacity, src, src_len);
}
#endif


// C++ multi byte functions depend on locale
//mbstowcs(dest, src, copy_len);
//wcstombs(dest, src, copy_len);


#if 0
// Returns a wide string version of the specified UTF-8 string
wchar_t* _glfwCreateWideStringFromUTF8Win32(const char* source) {
    wchar_t* target;
    int count;

    count = MultiByteToWideChar(CP_UTF8, 0, source, -1, NULL, 0);
    if (!count) {
        printf("Win32: Failed to convert string from UTF-8");
        return NULL;
    }

    target = static_cast<wchar_t*>(calloc(count, sizeof(wchar_t)));

    if (!MultiByteToWideChar(CP_UTF8, 0, source, -1, target, count)) {
        printf("Win32: Failed to convert string from UTF-8");
        free(target);
        return NULL;
    }

    return target;
}
// Returns a UTF-8 string version of the specified wide string
char* _glfwCreateUTF8FromWideStringWin32(const wchar_t* source) {
    char* target;
    int size;

    size = WideCharToMultiByte(CP_UTF8, 0, source, -1, NULL, 0, NULL, NULL);
    if (!size) {
        printf("Win32: Failed to convert string to UTF-8");
        return NULL;
    }

    target = static_cast<char*>(calloc(size, 1));

    if (!WideCharToMultiByte(CP_UTF8, 0, source, -1, target, size, NULL, NULL)) {
        printf("Win32: Failed to convert string to UTF-8");
        free(target);
        return NULL;
    }

    return target;
}
#endif

//------------------------
// OPTIONAL
//------------------------
template<class T>
class optional_2 {
public:
	// If do not want to run constructor of T in error case.
    struct empty_byte_s {};
    union {
        empty_byte_s empty_byte;
        T val;
    };
	// Error case	
    optional(const tag_nullopt) : has_value(false) {}
};


//------------------------
// ALLOCATORS
//------------------------
// Default allocation functions
//inline void* sys_allocate(size_t size_bytes) { return malloc(size_bytes); }
//inline void sys_deallocate(void* ptr) { free(ptr); }


//------------------------------
// DATA STRUCTURE ALGORITHMS
//------------------------------
//==============================================================================
#if 1
#include <limits>

// MSVC size claculation
isz vec_calculate_growth(isz requested_size, isz old_capacity) {
    // given old_capacity and requested_size, calculate geometric growth
    //const isz old_capacity = capacity();
    const auto max_limit = std::numeric_limits<isz>::max();

    if (old_capacity > max_limit - old_capacity / 2) {
        return max_limit; // geometric growth would overflow
    }

    const isz _Geometric = old_capacity + old_capacity / 2;

    if (_Geometric < requested_size) {
        return requested_size; // geometric growth would be insufficient
    }

    return _Geometric; // geometric growth is sufficient
}


// roundup mask for allocated buffers, [0, 15]:
template<class value_type>
static constexpr isz SDF_ALLOC_MASK = sizeof(value_type) <= 1 ? 15
                                       : sizeof(value_type) <= 2 ? 7
                                       : sizeof(value_type) <= 4 ? 3
                                       : sizeof(value_type) <= 8 ? 1
                                                                 : 0;

template<class value_type>
isz str_calculate_growth(isz requested_size, isz old_capacity) {
	const auto max_limit = std::numeric_limits<isz>::max();
	const isz masked_size = requested_size | SDF_ALLOC_MASK;
	// the mask overflows, settle for max_size()
	if (masked_size > max_limit) { 
		return max_limit;
	}

	// similarly, geometric overflows
	if (old_capacity > max_limit - old_capacity / 2) { 
		return max_limit;
	}

	return (sdf::tmax)(masked_size, old_capacity + old_capacity / 2);
}
#endif

isz next_capacity(isz requested_size) {    
	//return sdf::vec_calculate_growth(requested_size, capacity());
	//return sdf::str_calculate_growth<T>(requested_size, capacity());
	//return requested_size;
}



//-----------------------------------------------------------------------------------------------------
// BASE_DEF2
//-----------------------------------------------------------------------------------------------------

#include <cstring>
#include <cstdlib>

constexpr int MAX_PATH_OS_WNC = 260;   //MAX_PATH;
constexpr char NULLCHAR = '\0';
//inline const char* endln = "\n";

#include <format>
#include <vector>
#include <string>
#include <algorithm>


template<class T_base, class T_derived>
void com_ptr_as_derived(const T_base& base_class, T_derived& derived_class) {
	base_class->QueryInterface(__uuidof(T_derived), reinterpret_cast<void**>(&derived_class));	
}


template<class T, class U>
inline void copyarr_std(T dest, U src) { std::copy(std::begin(src), std::end(src), dest); }




//-----------------------------------
//inline std::pmr::wstring string_to_wstring(const std::pmr::string& s) {
//    std::pmr::wstring temp(s.length(), L' ');
//    std::copy(s.begin(), s.end(), temp.begin());
//    return temp; 
//}
//inline std::pmr::string wstring_to_string(const std::pmr::wstring& s) {
//    std::pmr::string temp(s.length(), ' ');
//    std::copy(s.begin(), s.end(), temp.begin());
//    return temp; 
//}

inline void wstring_from_string(std::pmr::wstring& dest, const std::pmr::string& src) {
	dest.resize(src.size());
    std::copy(src.begin(), src.end(), dest.begin());
}
inline void string_from_wstring(std::pmr::string& dest, const std::pmr::wstring& src) {
    dest.resize(src.size());
    std::copy(src.begin(), src.end(), dest.begin());
}




// string s = File.ReadAllText(filename);
// TextFileRead loads in a standard text file from a given filename and then returns it as a string.
inline bool string_from_file(std::string& out_string, const char *file_name) {
#if 0

	// Using getline
	// A string for holding the current line
	std::string line = std::string(); 

	// Open an input stream with the selected file
	std::ifstream filesrc_stream( file_name, std::ios::in ); 
	if (filesrc_stream.is_open()) {
		// If the file opened successfully
		while (!filesrc_stream.eof()) { 
			// While we are not at the end of the file
			std::getline(filesrc_stream, line); // Get the current line
		  	out_string.append(line); // Append the line to our file string
			out_string.append("\n"); // Append a new line character
		}
		filesrc_stream.close(); // Close the file
	} else {
		//gout << "Cannot open input file: " <<  file_name << QEL << sdf;
		return false;
	}


#else

	// Read the text from the file.
	// Open file.
	//std::ifstream filesrc_stream;
	//filesrc_stream.open(file_name);

	// Open file using constructor
	std::ifstream filesrc_stream(file_name, std::ios::in);

	//if (!filesrc_stream) { return false; }
	// Most vexing parse problem if () is removed surrounding 2nd parameter
	// TimeKeeper time_keeper(Timer()); is variable declaration or function declaration
	// programmer expect variable declaration but compiler interprets as function declaration
	//std::string out_string = std::string(std::istreambuf_iterator<char>(filesrc_stream), (std::istreambuf_iterator<char>()));
	// Uniform initialization syntax of C++11 solves Most vexing parse problem
	//std::string out_string{std::istreambuf_iterator<char>{filesrc_stream}, {}};
	//filesrc_stream.close();


	if (filesrc_stream.is_open()) {
#if 1
		// second fastest
		std::stringstream sstr;
		// Read file's buffer contents into streams.
		// Read file_name file stream in string stream. 
		sstr << filesrc_stream.rdbuf();		
		filesrc_stream.close();
		// Convert stream into string
		// Save string stream in std::string out_string
		out_string = sstr.str();
#else

		// fastest 
		filesrc_stream.seekg(0, std::ios::end);
		out_string.resize(filesrc_stream.tellg());
		filesrc_stream.seekg(0, std::ios::beg);
		filesrc_stream.read(&out_string[0], out_string.length());

		// slowest
		//filesrc_stream.seekg(0, std::ios::end);
		//out_string.reserve(filesrc_stream.tellg());
		//filesrc_stream.seekg(0, std::ios::beg);
		//out_string.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

		//slow
		//filesrc_stream.seekg( 0, std::ios_base::end );
		//const std::streampos pos = filesrc_stream.tellg();
		//filesrc_stream.seekg(0, std::ios_base::beg);
		//if( pos!=std::streampos(-1) ) { out_string.reserve(static_cast<std::string::size_type>(pos)); }
		//out_string.assign(std::istream_iterator<char>(file), std::istream_iterator<char>());	
#endif
	} else {
		//gout << "Cannot open input file: " <<  file_name << QEL << sdf;
		return false;
	}

#endif

	return true;
}





#if 0

//======================================
template<class Type>
inline Type align_f(const Type ptr, int alignment) {
	return (Type)(((DWORD)ptr + alignment - 1) & ~(alignment-1));
}



//======================================
// Sripting
//======================================
// chaiscript
//#include "../../dep/ChaiScript/include/chaiscript/chaiscript.hpp"
//std::string chai_helloworld(const std::string& t_name) {
//	std::string temp = "Hello Chai function " + t_name + "!\n";
//	gprintf("%s", temp.c_str());
//	//gout << "Hello Chai function " + t_name + "!" << QEL << sdf;
//	return "Hello Chai function " + t_name + "!";
//}
// main
//chaiscript::ChaiScript chai;
//chai.add(chaiscript::fun(&chai_helloworld), "chai_helloworld");
//chai.eval(R"(puts(chai_helloworld("Bob"));)");

//=======================================================
// for using WinMain with main, sfml way
//extern int main(int argc, char* argv[]);
//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {
//    return main(__argc, __argv);
//}
#endif


//===============================================================================
//===============================================================================
// strncpy: Copies at most count characters of the byte string pointed to by src (including the terminating null character) to character array pointed to by dest.
// If count is reached before the entire string src was copied, the resulting character array is not null-terminated.
// If, after copying the terminating null character from src, count is not reached, additional null characters are 
// written to dest until the total of count characters have been written.
inline char* strncpy_safe(char* dest, const char* src, size_t count) {
	std::strncpy(dest, src, count);
	// Always null terminate
	dest[count - 1] = '\0';
	return dest;
}




//MATH
namespace gm
{


class vidinfo {
public:
	int width = 0;
    int height = 0;			
    bool fullscreen = false;
};

}

namespace sdf
{


template<class T>
inline void flip_sign(T& x) {
	x = -x;
}

template<class T> inline 
T min3(const T a, const T b, const T c) {
	return minf(minf(a, b), c);
}
template<class T> inline 
T max3(const T a, const T b, const T c) {
	return maxf(maxf(a, b), c);
}

//-----------------------------------------------------------------------------------------------------
// Color Functions
//-----------------------------------------------------------------------------------------------------
#if 0
// maps unsigned 8 bits/channel to D3DCOLOR
#define D3DCOLOR_ARGB(a,r,g,b)  ((D3DCOLOR)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))
#define GLCOLOR_ABGR(a,b,g,r)	((uint)((((a)&0xff)<<24)|(((b)&0xff)<<16)|(((g)&0xff)<<8)|((r)&0xff)))
#define D3DCOLOR_RGBA(r,g,b,a)	D3DCOLOR_ARGB(a,r,g,b)
#define GLCOLOR_RGBA(r,g,b,a)	GLCOLOR_ABGR(a,b,g,r)
#define D3DCOLOR_XRGB(r,g,b)	D3DCOLOR_ARGB(0xff,r,g,b)
#define GLCOLOR_XBGR(r,g,b)		GLCOLOR_ABGR(0xff,b,g,r)

#define D3DCOLOR_XYUV(y,u,v)	D3DCOLOR_ARGB(0xff,y,u,v)
#define D3DCOLOR_AYUV(a,y,u,v)	D3DCOLOR_ARGB(a,y,u,v)

// maps floating point channels (0.f to 1.f range) to D3DCOLOR
#define D3DCOLOR_COLORVALUE(r,g,b,a)  D3DCOLOR_RGBA((DWORD)((r)*255.f), (DWORD)((g)*255.f), (DWORD)((b)*255.f), (DWORD)((a)*255.f))

//---
#define MAKEWORD(a, b)      ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))
#define MAKELONG(a, b)      ((LONG)(((WORD)(((DWORD_PTR)(a)) & 0xffff)) | ((DWORD)((WORD)(((DWORD_PTR)(b)) & 0xffff))) << 16))
#define LOWORD(l)           ((WORD)(((DWORD_PTR)(l)) & 0xffff))
#define HIWORD(l)           ((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))
#define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#define HIBYTE(w)           ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))

#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#define GetRValue(rgb)      (LOBYTE(rgb))
#define GetGValue(rgb)      (LOBYTE(((WORD)(rgb)) >> 8))
#define GetBValue(rgb)      (LOBYTE((rgb)>>16))


// float to uint component of a packed uint.
//#define Q_FTOUC( val )		( (uint) ((val)*255.f) & 0xff )

//----------------------------------------
//====================
// COLOR MACROS
//====================

//! Packs uint32 a, b, c, d [0-255] components in a uint32.
// Maps unsigned 8 bits/channel to UColor.
// ARGB format
#define Q_PACK_UINT( a, b, c, d ) \
    ( ((uint32)(a) << 24) | ((uint32)(b) << 16) | ((uint32)(c) << 8) | ((uint32)(d)) )

//! Unpacks four uint8 components out of uint32 and assign to uint32.
#define Q_UNPACK_UINT( val, a, b, c, d ) \
	( (a) = (uint32)((val)>>24), (b) = (uint32)((val)>>16), (c) = (uint32)((val)>>8), (d) = (uint32)(val) )

// float to uint32 component of a packed uint32.
#define Q_FTOUC( val )		( (uint32)((val)*255.f)&0xff )
// Multiply with this to get float value in [0-1.0] from a component of packed uint32.
#define Q_UCINV				(0.003921f)		//(1.0f / 255.0f)

//! Packs float a, b, c, d [0-1.0] components in a uint32.
// ARGB format
#define Q_PACKF_UINT( a, b, c, d ) \
    ( ((uint32)(Q_FTOUC(a)) << 24) | ((uint32)(Q_FTOUC(b)) << 16) | ((uint32)(Q_FTOUC(c)) << 8) | ((uint32)(Q_FTOUC(d))) )

//! Unpacks four uint8 components out of uint32 and assign to floats.
#define Q_UNPACKF_UINT( val, a, b, c, d ) \
	( (a) = ( ( (uint8)((val)>>24) ) * Q_UCINV ), (b) = ( ( (uint8)((val)>>16) ) * Q_UCINV ), (c) = ( ( (uint8)((val)>>8) ) * Q_UCINV ), (d) = ( ( (uint8)(val) ) * Q_UCINV ) )



// Supply arguments in order of name to Q_PACKF_UINT
#define Q_ARGB(r, g, b, a)			Q_PACKF_UINT(a, r, g, b)
//#define Q_XRGB(r, g, b)			Q_PACKF_UINT(1.0f, r, g, b)

#define Q_RGBA(r, g, b, a)			Q_PACKF_UINT(r, g, b, a)

// Same as RGB macro of Windows. Packs color in format of Win32 Api.
#define Q_ABGR(r, g, b, a)			Q_PACKF_UINT(0.0f, b, g, r)
//
//#define Q_XYUV(y, u, v)			Q_ARGB(0xff, y, u, v)
//#define Q_AYUV(a, y ,u, v)		Q_ARGB(a, y, u, v)

#endif

//-----------------------------------------------------------------------------------------------------
// IOSTREAM
//-----------------------------------------------------------------------------------------------------

//va_list argptr;
//char text[1024];
//va_start (argptr, error);
//vsprintf (text, error, argptr);
//va_end (argptr);

#define	fm_vsnprintf_buffer(buffer_name, buffer_size, message)			\
	va_list arg_ptr;													\
	char buffer_name[buffer_size];										\
	va_start(arg_ptr, message);											\
	vsnprintf(buffer_name, sizeof(buffer_name), message, arg_ptr);		\
	va_end(arg_ptr);

// Prints formatted msg in a wchar_t array named buffer_name.
#define	fm_vsnwprintf_buffer(buffer_name, buffer_size, message)			\
	va_list arg_ptr;													\
	wchar_t buffer_name[buffer_size];									\
	va_start(arg_ptr, message);											\
	vsnwprintf(buffer_name, sizeof(buffer_name), message, arg_ptr);		\
	va_end(arg_ptr);



#include <iostream>
#define gout	std::cout
inline std::ostream& sdf(std::ostream& os)  { return os << '\n'; }

#if 0
// <iostream> is required for std::cout
//#include <iostream>
//#include <iomanip>
//#include <sstream>

//#define gprintf		std::printf
//#define gout		std::cout	
//#define gerr		std::cerr	


//#define sdflush		std::flush
//#define sdf		std::endl
//#define sdf		"\n"

// newline
//inline std::ostream& sdf(std::ostream& os)  { return os << '\n'; }
//#define qcs			", "
//#define qtb 		"\t"

// streams seem slow because by default the iostreams are synchronizing with C FILE output so that intermixed
// cout and printfs are output correctly. Disabling this causes c++'s streams to outperform stdio.
//std::cout.sync_with_stdio(false);    

//inline void writef(const std::string_view fmt_str) { std::cout << fmt_str; }

//---------------------------------------------------

//#define MY_PRINT(format, ...)	std::printf(format "\n", __VA_ARGS__)	//MSVC
//#define MY_PRINT(format, ...)	std::printf(format "\n", ##__VA_ARGS__)	//GNU GCC

// Error Logging with source code location
// __FUNCTION__ gives function name with class, __func__ gives only function name.
// #x prints quoted string, x prints without quotes 


//=====================================================================================


//base_debug.cpp
//=========================
// ERROR Print
//=========================


// CONSOLE
//base_console.cpp
#if 0
void StdConsole::print_string_color(const char* message, uint con_color) {
	SetConsoleTextAttribute(hConsole, con_color);

	std::printf(message);

	// set default white foreground and black background
	//SetConsoleTextAttribute(hConsole, 15);
	SetConsoleTextAttribute(hConsole, StdConsole_local::color_default);
}

void StdConsole::print_string(const char* message) {
	//std::printf(message);
	print_string_color(message, StdConsole_local::color_yellow);
}

void StdConsole::print_debug_string(const char* message) {		
	print_string_color(message, StdConsole_local::color_green);
}

void StdConsole::print_error_string(const char* message) {
	print_string_color(message, StdConsole_local::color_magenta);
}

void set_console_colors(WORD attribs) {
	//HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFOEX cbi;
	cbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	GetConsoleScreenBufferInfoEx(hConsole, &cbi);
	cbi.wAttributes = attribs;
	SetConsoleScreenBufferInfoEx(hConsole, &cbi);
}
#endif


extern Logger glog;

//================================
class OutBuffer : public std::stringbuf {
public:
    virtual int sync() 	{
		//gcon.print_string(this->str());
		//gconstd.print_string(this->str());
		glog.print_string(this->str());


		// Erase the buffer
		// Clearing old contents of ostringstream st
		//this->str("");
		// this is more efficient, because you avoid invoking the std::string constructor that takes const char*
		this->str(std::string());		

		// reset error flags
		//st->clear();		

		//std::stringstream().swap(st); // swap m with a default constructed stringstream (when st is not a pointer).
		
		return 1;
    }
};

class OutBufferDebug : public std::stringbuf {
public:
    virtual int sync() 	{
		if (logger_print_debug) {
			glog.print_debug_string(this->str());
			this->str(std::string());	
		}
		return 1;
    }
};

class OutBufferError : public std::stringbuf {
public:
    virtual int sync() {
		if (logger_print_error) {
			glog.print_error_string(this->str());
			this->str(std::string());			
		}
		return 1;
    }
};

extern OutBuffer out_buf;
extern std::ostream custom_out;

extern OutBufferDebug out_buf_debug;
extern std::ostream custom_out_debug;

extern OutBufferError out_buf_error;
extern std::ostream custom_out_error;

//cpp
//OutBuffer out_buf;
//std::ostream custom_out(&out_buf);
//
//OutBufferDebug out_buf_debug;
//std::ostream custom_out_debug(&out_buf_debug);
//
//OutBufferError out_buf_error;
//std::ostream custom_out_error(&out_buf_error);

//------------------------------------------------



// BITSET
#if 0
// In C and C++ the double negation operator (!!) can be (and often is) used to convert a value to a boolean.
// If int x = 42, !!x evaluates to 1. If x = 0, !!x evaluates to 0.
//int x = 42;
//!!x or (x == 0 ? 0 : 1) or (x != 0) 
// All gives 0 or 1, even if operator! is overloaded for bool (or use explicit operator bool)

// Setting the nth bit to either 1 or 0. 
// Bit n will be set if bv is 1, and cleared if bv is 0. If bv has some other value, you get garbage. bv = !!bv will booleanize it to 0 or 1.
// To make this independent of 2's complement negation behaviour (where -1 has all bits set, 
// unlike on a 1's complement or sign/magnitude C++ implementation), use unsigned negation.
//x ^= (-(unsigned long long)bv ^ x) & (1ULL << (n));

// Return '1' if the bit value at position n within x is '1' and '0' if it's 0 by ANDing x with a bit mask where the bit in n's position is '1' and '0' 
// elsewhere and comparing it to all 0's.  Returns '1' in least significant bit position if the value of the bit is '1', '0' if it was '0'.
#define BIT_READ(x,n) ((0ULL == ((x) & (1ULL<<(n)))) ? 0ULL : 1ULL)

// -https://stackoverflow.com/questions/47981/how-do-i-set-clear-and-toggle-a-single-bit
// x=target variable, n=bit number to act upon 0-n
// Set bit n (0-indexed) of x to '1' by generating a a mask with a '1' in the proper bit location and ORing x with the mask.
#define BIT_SET(x, n) ((x) |= (1ULL<<(n)))
// Set bit n (0-indexed) of x to '0' by generating a mask with a '0' in the n position and 1's elsewhere then ANDing the mask with x.
#define BIT_CLEAR(x, n) ((x) &= ~(1ULL<<(n)))
// Toggle bit n (0-index) of x to the inverse: '0' becomes '1', '1' becomes '0' by XORing x with a bitmask where the bit in 
// position n is '1' and all others are '0'.
#define BIT_FLIP(x, n) ((x) ^= (1ULL<<(n)))
// '!!' to make sure this returns 0 or 1
#define BIT_CHECK(x, n) (!!((x) & (1ULL<<(n))))   
#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
// BITMASK_CHECK_ALL(x, mask) can be implemented as !~((~(mask))|(x))
// It's a bit easier to see why that works after applying De Morgan's law and re-arranging to get !(~(x) & (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))
#endif

//-----------------------------------------------------------------------------------------------------
#if UINTPTR_MAX == 0xffFFffFF
// 32-bit platform
#elif UINTPTR_MAX == 0xffFFffFFffFFffFF
// 64-bit platform
#else
#error Unknown platform - does not look either like 32-bit or 64-bit
#endif

//-----------------------------------------------------------------------------------------------------
// WINDOWS FUNCTIONS
//-----------------------------------------------------------------------------------------------------
inline void sys_win_title_append(HWND hwnd, const char* text) {
	isz text_len = sdf::strfz_len(text);

	wchar_t wnd_text[256] = {};
	//nMaxCount: maximum number of characters to copy to the buffer, including the null character.
	int wnd_text_len = GetWindowTextW(hwnd, wnd_text, sdf::arr_cap(wnd_text));
	//wprintfln(L"%s: %d", prev_wnd_text, wnd_text_len);

	//wchar_t wtitle[256] = {};
	//isz wtitle_len = sdf::strf_assign(wtitle, sdf::strz_cap(wtitle), wnd_text, wnd_text_len);
	//wchar_t wtext_to_add[256] = {};
	//isz wtext_to_add_len = 0;
	//wtext_to_add_len = sdf::strf_assign_mbs(wtext_to_add, sdf::strz_cap(wtext_to_add), text, text_len);
	//wtitle_len = sdf::strf_append(wtitle, wtitle_len, sdf::strz_cap(wtitle), wtext_to_add, wtext_to_add_len);
	//SetWindowTextW(hwnd, wtitle);

	sdf::wstring_st<255> wtitle;
	wtitle.assign_data(wnd_text, wnd_text_len);
	sdf::wstring_st<255> wtext_to_add;
	sdf::string_st_wcs_from_mbs(wtext_to_add, text, sdf::strfz_len(text));
	////wprintfln(L"%s: %d", wtext_to_add.c_str(), wtext_to_add.size());
	wtitle.append_data(wtext_to_add.data(), wtext_to_add.size());
	////wprintfln(L"%s: %d", wtitle.c_str(), wtitle.size());
	SetWindowTextW(hwnd, wtitle.c_str());
}

//-------------
// WINAPP
void z_switch_fullscreen(HWND hwnd) {
	WINDOWPLACEMENT g_wpPrev = { sizeof(g_wpPrev) };		
	//void OnLButtonUp(HWND hwnd, int x, int y, UINT keyFlags)
	DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);
	if (dwStyle & WS_OVERLAPPEDWINDOW) {
		MONITORINFO mi = { sizeof(mi) };
		if (GetWindowPlacement(hwnd, &g_wpPrev) && GetMonitorInfo(MonitorFromWindow(hwnd, MONITOR_DEFAULTTOPRIMARY), &mi)) {
			SetWindowLong(hwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
			SetWindowPos(hwnd, HWND_TOP,
						mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top,
						(SWP_NOOWNERZORDER | SWP_FRAMECHANGED));
		}
	} else {
		SetWindowLong(hwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(hwnd, &g_wpPrev);
		SetWindowPos(hwnd, NULL, 0, 0, 0, 0, (SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_FRAMECHANGED));
	}
}

//-----------------------------------------------------------------------------

class RaiiClipboard {
public:
  RaiiClipboard()
  {
    if (! OpenClipboard(nullptr))
      throw std::runtime_error("Can't open clipboard.");
      // ... or define some custom exception class for clipboard errors.
  }

  ~RaiiClipboard() {
    CloseClipboard();
  }

  // Ban copy   
private:
  RaiiClipboard(const RaiiClipboard&);
  RaiiClipboard& operator=(const RaiiClipboard&);
};

class RaiiTextGlobalLock
{
public:
  explicit RaiiTextGlobalLock(HANDLE hData) {
    m_psz = static_cast<const char*>(GlobalLock(m_hData));
    if (! m_psz)
      throw std::runtime_error("Can't acquire lock on clipboard text.");  
  }

  ~RaiiTextGlobalLock() {
    GlobalUnlock(m_hData);
  }

  const char* Get() const { 
    return m_psz;
  }

private:
  HANDLE m_hData;
  const char* m_psz;

  // Ban copy
  RaiiTextGlobalLock(const RaiiTextGlobalLock&);
  RaiiTextGlobalLock& operator=(const RaiiTextGlobalLock&);
};

std::string GetClipboardText() {
  RaiiClipboard clipboard;

  HANDLE hData = GetClipboardData(CF_TEXT);
  if (hData == nullptr)
    throw std::runtime_error("Can't get clipboard text.");

  RaiiTextGlobalLock textGlobalLock(hData);
  std::string text( textGlobalLock.Get() );

  return text;
}


//------------------------------------------------------------------


char ** CommandLineToArgv(std::string const & line, int & argc) {
    typedef std::vector<char *> CharPtrVector;
    char const * WHITESPACE_STR = " \n\r\t";
    char const SPACE = ' ';
    char const TAB = '\t';
    char const DQUOTE = '\"';
    char const SQUOTE = '\'';
    char const TERM = '\0';


    //--------------------------------------------------------------------------
    // Copy the command line string to a character array.
    // strdup() uses malloc() to get memory for the new string.
#if defined( WIN32 )
    char * pLine = _strdup( line.c_str() );
#else
    char * pLine = strdup( line.c_str() );
#endif


    //--------------------------------------------------------------------------
    // Crawl the character array and tokenize in place.
    CharPtrVector tokens;
    char * pCursor = pLine;
    while (*pCursor) {
        // Whitespace.
        if (*pCursor == SPACE || *pCursor == TAB) {
            ++pCursor;
        } else if (*pCursor == DQUOTE) {
			// Double quoted token.
            // Begin of token is one char past the begin quote.
            // Replace the quote with whitespace.
            tokens.push_back(pCursor + 1);
            *pCursor = SPACE;

            char * pEnd = strchr(pCursor + 1, DQUOTE);
            if (pEnd) {
                // End of token is one char before the end quote.
                // Replace the quote with terminator, and advance cursor.
                *pEnd = TERM;
                pCursor = pEnd + 1;
            } else {
                // End of token is end of line.
                break;
            }
        } else if (*pCursor == SQUOTE) {
			// Single quoted token.
            // Begin of token is one char past the begin quote.
            // Replace the quote with whitespace.
            tokens.push_back( pCursor + 1 );
            *pCursor = SPACE;

            char * pEnd = strchr(pCursor + 1, SQUOTE);
            if ( pEnd ) {
                // End of token is one char before the end quote.
                // Replace the quote with terminator, and advance cursor.
                *pEnd = TERM;
                pCursor = pEnd + 1;
            } else {
                // End of token is end of line.
                break;
            }   
        } else {
			// Unquoted token.
            // Begin of token is at cursor.
            tokens.push_back(pCursor);

            char * pEnd = strpbrk(pCursor + 1, WHITESPACE_STR);
            if ( pEnd ) {
                // End of token is one char before the next whitespace.
                // Replace whitespace with terminator, and advance cursor.
                *pEnd = TERM;
                pCursor = pEnd + 1;
            } else {
                // End of token is end of line.
                break;
            }
        }
    }


    //--------------------------------------------------------------------------
    // Fill the argv array.
    argc = tokens.size();
    char ** argv = static_cast<char **>( malloc( argc * sizeof( char * ) ) );
    int a = 0;
    for (CharPtrVector::const_iterator it = tokens.begin(); it != tokens.end(); ++it) {
        argv[ a++ ] = (*it);
    }


    return argv;
}
//----------------------------------------------------------------------------------------------------------
// includes .. of relative path also
std::string get_exe_file_name_with_path() {
  wchar_t buffer[MAX_PATH];
  GetModuleFileName( NULL, buffer, MAX_PATH );
  return std::string(flib::mb_tostr(buffer));
}

std::string get_exe_path() {
  std::string f = GetExeFileNameWithPath();
  return f.substr(0, f.find_last_of( "\\/" ));
}



//=======================
// Dynamic dll loading
//=======================

#if defined(Q_WIN_API)
	#include <Windows.h>
	#define Q_LoadLibrary( dllName )			(void*)LoadLibrary( QS(#dllName) )
	#define Q_UnloadLibrary( dllName )			FreeLibrary( (HMODULE)dllName )
	#define Q_LoadFunction( dllName ,func )		(void*)GetProcAddress( (HMODULE)dllName ,func )
	//#define Q_LibraryError()					QS("unknown")
#elif defined(Q_LINUX_API)
	// check for unicode
	#include <dlfcn.h>
	#define Q_LoadLibrary( dllName )			dlopen( dllName, RTLD_NOW )
	#define Q_UnloadLibrary( dllName )			dlclose( dllName )
	#define Q_LoadFunction( dllName, func )		dlsym( dllName,func )
	//#define Q_LibraryError()					dlerror()
#endif


#if defined(Q_WIN_API)

	#include <Windows.h>

	#define Q_CREATE_DLLCLASS( expdefine, classptr )	\
	extern "C" expdefine int QDECL Create_##classptr(classptr **p##classptr);	\
	extern "C" typedef int (*PFNT_Create_##classptr) (classptr **p##classptr);	\
																				\
	extern "C" expdefine int QDECL Release_##classptr(classptr **p##classptr);	\
	extern "C" typedef int (*PFNT_Release_##classptr) (classptr **p##classptr);



	// Returns pfn_funcname which can be used. Take care to define PFNT_funcname somwhere in code.
	#define Q_LOAD_FUNCTION(dllname, funcname) \
		PFNT_##funcname  pfn_##funcname = 0; \
		pfn_##funcname = (PFNT_##funcname)GetProcAddress(dllname, #funcname);
		//if ( !pfn_Create_IRenderer )	{
		//	//MessageBox(0, QS("Cannot Create PFN_Create_IRenderer"), QS("DLL Message"), MB_OK | MB_ICONINFORMATION);
		//	return Q_FAIL;
		//}

	#define Q_CHECK(var) \
		if((var)) { MessageBox(0, (QS(#var)QS(" does not exist")), QS("Q_CHECK var Message"), MB_OK | MB_ICONINFORMATION); return false; }

	// Error message, set target globally here. Will automatically convert errormsg to Unicode.
	#define Q_ERROR(errormsg) \
		MessageBox(0, QS(errormsg), QS("Q_ERROR Message"), MB_OK | MB_ICONINFORMATION);


	//INLINE HMODULE sys_LoadLibrary(TCHAR *libname) {
		// LoadLibrary returns HMODULE which is passed to DLL implemented class hInstance.
		//return LoadLibrary(libname);
	//}

	//INLINE void sys_FreeLibrary(HMODULE hDLL) {
		//if(hDLL)
			//FreeLibrary(hDLL);
	//}

#elif defined(Q_LINUX_API)

#endif

//-----------------------------------------------------------------------------------------------------
// RENDERER
//-----------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------
// D3D11RENDERER
//-----------------------------------------------------------------------------------------------------
#if 0
//---
//#pragma comment(lib,"E:/nex/AthensEngine/AscentWars/source/dep/tut/d3dxlib/lib/Effects11.lib")
//#pragma comment(lib,"E:/nex/AthensEngine/AscentWars/source/dep/tut/d3dxlib/lib/DirectXMesh.lib")
//#pragma comment(lib,"E:/nex/AthensEngine/AscentWars/source/dep/tut/d3dxlib/lib/DirectXTex.lib")
//#pragma comment(lib,"E:/nex/AthensEngine/AscentWars/source/dep/tut/d3dxlib/lib/DirectXTK.lib")
////#pragma comment(lib,"E:/nex/AthensEngine/AscentWars/source/dep/tut/d3dxlib/lib/UVAtlas.lib")

//#include "E:/nex/AthensEngine/AscentWars/source/dep/tut/d3dxlib/FX11/inc/d3dx11effect.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/tut/d3dxlib/DirectXTex/DDSTextureLoader/DDSTextureLoader.h"
//// DirectXMath.h name collision errors
////#include "E:/nex/AthensEngine/AscentWars/source/dep/tut/d3dxlib/DirectXTex/DirectXTex/DirectXTex.h"
//// Windows Imaging Component functionality. CreateWICTextureFromFile
//#include "E:/nex/AthensEngine/AscentWars/source/dep/tut/d3dxlib/DirectXTK/Inc/WICTextureLoader.h"

//#include "tut/d3dxlib/DirectXMath/Inc/DirectXMath.h"
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXPackedVector.h"
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXColors.h"
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXCollision.h"
//---

// DirectXTK
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/CommonStates.h"
////#include "E:/nex/AthensEngine/AscentWars/source/dep/tut/d3dxlib/DirectXTK/inc/DDSTextureLoader.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/DirectXHelpers.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/Effects.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/GamePad.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/GeometricPrimitive.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/GraphicsMemory.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/Keyboard.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/Model.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/Mouse.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/PostProcess.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/PrimitiveBatch.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/ScreenGrab.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/SpriteBatch.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/SpriteFont.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/VertexTypes.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/WICTextureLoader.h"
//#include "E:/nex/AthensEngine/AscentWars/source/dep/d3dxlib/DirectXTK/inc/Audio.h"
#endif
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <source_location>
inline void check_hr(HRESULT hr, const std::source_location location = std::source_location::current()) {
    if (FAILED(hr)) { std::printf("ERROR: %s (%d): %s\n", location.file_name(), location.line(), location.function_name()); }
}


//-----------------------------------------------------------------------------------------------------
// VULKAN HEADERS
//-----------------------------------------------------------------------------------------------------
#pragma comment(lib, "VulkanSDK/Lib/vulkan-1.lib")
// multi static dll gnerated, project is multi dynamic dll
//#pragma comment(lib, "VulkanSDK/Lib/shaderc_combined.lib")
//#pragma comment(lib, "VulkanSDK/Lib/VkLayer_utils.lib")
#pragma comment(lib, "E:/nex/AthensEngine/AscentWars/source/dep/lib/imgui.lib")
//#pragma comment(lib, "E:/nex/AthensEngine/AscentWars/source/dep/tut/tut_lib/assimp-vc140-mt.lib")
#pragma comment(lib, "E:/nex/AthensEngine/AscentWars/source/dep/tut/tut_lib/libktx.gl.lib")


//-----------------------------------------------------------------------------------------------------
// PROJECT CONFIG
//-----------------------------------------------------------------------------------------------------
// Project properties
// Select “C/ C++ All options” sub group. Multi-processor or /MP as shown in the figure below:
// linker switch /incremental

//#if _MSC_VER
// Specify in preprocessor settings

// msvc compiler warnings for sscanf_s non standard msvc extensions
//#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_NONSTDC_NO_DEPRECATE

//#ifdef max
//	#undef max
//#endif
//#ifdef min
//	#undef min
//#endif
// Suppress the min and max definitions in Windef.h
//#define _NOMINMAX
//#endif


//Properties Pages -Configuration Properties -C/C++ -Advanced property page.
//Disable Specific Warnings -4244;5201;
//#ifdef _MSC_VER
// 4244: conversion from 'double' to 'float', possible loss of data
// 5105: macro expansion producing 'defined' has undefined behavior
//-------------
// 5201: a module declaration can appear only at the start of a translation unit unless a global module fragment is used
//#pragma warning(disable : 4244)		
//#pragma warning(disable : 4244 5105 5201)

//#endif

// Disabled Warnings
// Linker warnings (cannot disable) -
// 4099: PDB '' was not found with 'glew32s.lib(glew.obj)' or at ''; linking object as if no debug info
// Compiler Warnings -
// 4244: conversion from 'double' to 'float', possible loss of data
// 5201: a module declaration can appear only at the start of a translation unit unless a global module fragment is used
//------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------
// DS
//-----------------------------------------------------------------------------------------------------
template<class T>
class unordered_vslotmap
{
	ska::bytell_hash_map<sdr::string, size_t> key_index;
	sdr::vector<std::pair<sdr::string, T>> data_vec;
	void push_back(sdr::string& key, const T& elem) {
		data_vec.push_back(std::pair(key, elem));
		key_index.insert({key, data_vec.size()-1});
	}
	void erase(sdr::string& key) {
		size_t pos = key_index.find(key)->second;	
		key_index.erase({key});
		// swap with last element of vec
		data_vec[pos] = data_vec.back();
		data_vec.pop_back();
		// update key_index
		key_index.find(data_vec[pos].first)->second = pos;	
	}
};



#if 0
//---
struct Foo {
    int n;
}; 
bool operator==(const Foo& lhs, const Foo& rhs) {
    return lhs.n == rhs.n;
} 
bool operator<(const Foo& lhs, const Foo& rhs) {
    return lhs.n < rhs.n;
}
int main() {
    Foo f1 = {1};
    Foo f2 = {2};
    using namespace std::rel_ops;
 
    std::cout << std::boolalpha;
    std::cout << "not equal?     : " << (f1 != f2) << '\n';
    std::cout << "greater?       : " << (f1 > f2) << '\n';
    std::cout << "less equal?    : " << (f1 <= f2) << '\n';
    std::cout << "greater equal? : " << (f1 >= f2) << '\n';
}
#endif



//--------------------------------------
// POWER OF 2
//--------------------------------------
//2147483647
//4294967296
//9223372036854775808
//18446744073709551615 //2^64-1 //(9223372036854775808+1)
//gout << flib::upper_power_of_two(9223372036854775808+1) << sdf;
//gout << flib::upper_power_of_two(18446744073709551615) << sdf;
//flib::size_t upper_power_of_two(size_t v);

double next_power_of_two(double value) {
    int exp;
    if(frexp(value, &exp) == 0.5) {
        // Omit this case to round precise powers of two up to the *next* power
        return value;
    }
    return ldexp(1.0, exp);
}


uint32_t upper_power_of_two_u32(uint32_t v) {
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}


usize ceil_powxi(usize x, int growth_factor) {
	if (x==0) { return 0; }

    // Handle overflow
    if (x > std::numeric_limits<usize>::max()/growth_factor) {
        return std::numeric_limits<usize>::max()-1;
    }

    usize power = 1;
    while (power <= x) {
        power *= growth_factor;
    }
    return power;
}


usize ceil_powxf(usize x, double growth_factor) {
	if (x==0.0) { return 0; }

    // Handle overflow
    if (x > std::numeric_limits<usize>::max()/growth_factor) {
        return std::numeric_limits<usize>::max()-1;
    }

    double power = 1.0f;
    while (power <= x) {
        power *= growth_factor;
    }
    return std::ceil(power);
}

usize floor_powxi(usize x, int growth_factor)		{ return ceil_powxi(x, growth_factor)/2; }
usize floor_powxf(usize x, double growth_factor)	{ return ceil_powxf(x, growth_factor)/2; }

// C++20 <bit> ispow2(), ceil2(), floor2(), log2p1()
//namespace std {
//  template <class T>
//    constexpr bool ispow2(T x) noexcept;
//  template <class T>
//    constexpr T ceil2(T x) noexcept;
//  template <class T>
//    constexpr T floor2(T x) noexcept;
//  template <class T>
//    constexpr T log2p1(T x) noexcept;
//}



//=======================================================

// Error message in a windows message Box for basic checking, mainly error output class.
#define Q_WIN_ERR_MB( message )		MessageBox(nullptr, message, QS(Q_ENGINE_ERROR_NAME), MB_OK|MB_ICONERROR)		//error message
#define Q_WIN_MSG_MB( message )		MessageBox(nullptr, message, QS(Q_ENGINE_NAME), MB_OK)								//message, MB_OK = 0
#define Q_WIN_YES_NO_MB( message, id_yes_no )		(MessageBox(nullptr, message, QS(Q_ENGINE_NAME), MB_YESNO|MB_ICONEXCLAMATION)==id_yes_no)

//#define		MAX_PRINTMSG_PRINTF		32768			//16384;			// buffer size for various printf functions

//#define SWAP_POINTERS(x, y)  { void* t; t = x; x = y; y = t; }



//============================================================================



