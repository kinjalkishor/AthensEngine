//=====================================================================
//====================================================================
// DEF

//template<class T>
//int tvsnprintf(T* const buffer, size_t const buffer_count, T const* const format, va_list arg_list);
//template<>
//int tvsnprintf(char* const buffer, size_t const buffer_count, char const* const format, va_list arg_list) {
//    return vsnprintf(buffer, buffer_count, format, arg_list);
//}
//template<>
//int tvsnprintf(wchar_t* const buffer, size_t const buffer_count, wchar_t const* const format, va_list arg_list) {
//    return _vsnwprintf(buffer, buffer_count, format, arg_list);
//}

//template<class T>
//inline isz size_bytes(isz num) {
//	return (num*sizeof(T));
//}


//-----------------------
// STRUCTS
//struct wrect {
//	int x, y, w, h;
//};


namespace sdf
{



template<class T>
struct vspan {
    T* m_data = nullptr;
    isz m_size = 0;      
    isz m_capacity = 0;

    vspan() : m_data(nullptr), m_size(0), m_capacity(0) {}
    vspan(T* data, isz size, isz capacity) : m_data(data), m_size(size), m_capacity(capacity) {}

    isz size() const { return m_size; }
    isz capacity() const { return m_capacity; }
    const T* data() const { return m_data; }
	T* data() { return m_data; }
    const T& operator[] (isz i) const { return m_data[i]; }
	T& operator[] (isz i) { return m_data[i]; }
};

using string_vspan = vspan<const char>;
using wstring_vspan = vspan<const wchar_t>;
//-----------------------

//====================
// HASH Functions
//====================
// SEE fnv-5.0.3_2012-05-20.rar
// Original source
// http://www.isthe.com/chongo/tech/comp/fnv/
/*
// Unknown source

uint fnv1a_hash(const char* text);
inline uint get_hash(const char* text) { return fnv1a_hash(text); }

// Fowler/Noll/Vo (FNV) hash function, variant 1a 
// default values recommended by isthe.com/chongo/tech/comp/fnv/
constexpr uint Prime = 0x01000193; //   16777619
constexpr uint Seed  = 0x811C9DC5; // 2166136261
// hash a C-style string
uint fnv1a_hash(const char* text) {
    uint hash = Seed;
    //assert(text);
    const unsigned char* ptr = (const unsigned char*)text;
    while (*ptr) {
        hash = (*ptr++ ^ hash) * Prime;
        // same as hash = fnv1a(*ptr++, hash); but much faster in debug mode
    }
    return hash;
}
*/

//---------------------------------
/*
// C style null terminated safe string functions.
template<class T>
inline isz strz_assign(T* dest, isz dest_capacity, const T* src, isz src_len) {
    isz rdest_len = 0;
    sdf::strf_assign(dest, rdest_len, dest_capacity, src, src_len);
    return rdest_len;
}

template<class T>
inline isz strz_assign_n(T* dest, isz dest_capacity, const T* src, isz src_len, isz n) {
    isz rdest_len = 0;
    sdf::strf_assign_n(dest, rdest_len, dest_capacity, src, src_len, n);
    return rdest_len;
}

template<class T>
inline isz strz_append(T* dest, isz dest_len, isz dest_capacity, const T* src, isz src_len) {
    isz rdest_len = dest_len;
    sdf::strf_append(dest, rdest_len, dest_capacity, src, src_len);
    return rdest_len;
}


// dest_num_chars is dest capacity to hold chars without null char.
inline isz strz_wcs_from_mbs(wchar_t* dest, isz dest_num_chars, const char* src, isz src_len) {
	isz rdest_len = 0;
	sdf::strf_wcs_from_mbs(dest, rdest_len, dest_num_chars, src, src_len);
	return rdest_len;
}
inline isz strz_mbs_from_wcs(char* dest, isz dest_num_chars, const wchar_t* src, isz src_len) {
	isz rdest_len = 0;
	sdf::strf_mbs_from_wcs(dest, rdest_len, dest_num_chars, src, src_len);
	return rdest_len;
}
*/



//=====================================================================
//====================================================================
// MATH

#if 0

namespace mf
{


//------------------------------------------------------------------------------------------------------------

//---------------------------
// Float Comparison
// Donald Knuth
inline bool approximately_equal(float a, float b, float epsilon) {
    return fabs(a - b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
inline bool essentially_equal(float a, float b, float epsilon) {
    return fabs(a - b) <= ( (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
inline bool definitely_greater_than(float a, float b, float epsilon) {
    return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
inline bool definitely_less_than(float a, float b, float epsilon) {
    return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}


//------------------------------------------------------------------------------------------------------------

// unsigned and signed normalized or unorm and snorm
// unit_range to symmetric_unit_range, zo_to_no, d3d to gl
// [0.0, 1.0] to [-1.0 to 1.0]
inline float range_un_to_sn(float x)
{
	//n = 2.0 * (z - 0.5))
	//n = 2*z - 1
	return ((scast<float>(2)*x) - scast<float>(1));
}

// symmetric_unit_range to unit_range, no_to_zo
// [-1.0 to 1.0] to [0.0, 1.0], gl to d3d
inline float range_sn_to_un(float x)
{
	//z = (n+1)/2 = (n+1)*0.5
	return ((x + scast<float>(1)) * scast<float>(0.5));
}


inline float clamp01(const float& x)
{
    return std::clamp(x, scast<float>(0), scast<float>(1));
}


inline float clamp1(const float& x)
{
    return std::clamp(x, scast<float>(-1), scast<float>(1));
}




//-------------------
//template<class T>
//static inline T abs(const T x)
//{
//	return (x < scast<T>(0)) ? -x : x;
//}

template<class T>
static inline int sign(const T x)
{
	//return 0 for 0 (correct)
	//return ( (x > scast<T>(0)) ? 1 : ((x < scast<T>(0)) ? -1 : 0) ); 

	if (x > scast<T>(0)) { return 1; }
	else if (x < scast<T>(0)) { return -1; }
	else { return 0; }
}

// Non-zero sign
template<class T>
static inline int sign_nz(const T x)
{
	// return 1 for 0
    //return ( (x >= scast<T>(0)) ? 1 : -1 );

	if (x >= scast<T>(0)) { return 1; }
	else { return -1; }
}

template<class T>
inline T clamp_type(const T& x)
{
	return std::clamp(x, std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
}

}


//----------------------------------------------------------------
// Random Numbers
//----------------------------------------------------------------
class mrand
{
private:
	static inline constexpr uint k_rand_max = std::numeric_limits<uint>::max();	
	static inline std::mt19937 rng;

public:

	//Random Numbers
	static inline void rand_seed(uint seed)
	{
		//rng.seed(std::chrono::steady_clock::now().time_since_epoch().count());
		rng.seed(seed);
	}

	static inline uint rand_u32()
	{
		return rng();
	}


	// frand, unit_random
	// returns a float between 0 and 1.0
	static inline float rand_unit()	
	{
		return (scast<float>(rand_u32())/scast<float>(k_rand_max));		
	}

	// crand, symmetric_random
	// returns a float between -1 and 1.0
	static inline float rand_sunit()	
	{
		return mf::range_un_to_sn(rand_unit());		
	}

	// float in [min, max] range
	static inline float rand_range(float min, float max)
	{
		return min + rand_unit()*(max-min);
	}
};

#endif


//=====================================================================
//====================================================================
// IO FMT

#else
#define USE_FMT_FORMAT 1

#include <fmt/core.h>
//#include <fmt/format.h>
//#include <fmt/xchar.h>
//#include <fmt/ranges.h>

template <typename... _Types>
_NODISCARD inline void print(fmt::format_string<_Types...>&& fmt_str, _Types&&... _Args) {
	fmt::print("{}", fmt::format(std::forward<fmt::format_string<_Types...>>(fmt_str), std::forward<_Types>(_Args)...));
}
template <typename... _Types>
_NODISCARD inline void println(fmt::format_string<_Types...>&& fmt_str, _Types&&... _Args) {
	fmt::print("{}\n", fmt::format(std::forward<fmt::format_string<_Types...>>(fmt_str), std::forward<_Types>(_Args)...));
}

//template <typename... _Types>
//_NODISCARD inline void wprint(fmt::wformat_string<_Types...>&& fmt_str, _Types&&... _Args) {
//	fmt::print(L"{}", fmt::format(std::forward<fmt::wformat_string<_Types...>>(fmt_str), std::forward<_Types>(_Args)...));
//}
//template <typename... _Types>
//_NODISCARD inline void wprintln(fmt::wformat_string<_Types...>&& fmt_str, _Types&&... _Args) {
//	fmt::print(L"{}\n", fmt::format(std::forward<fmt::wformat_string<_Types...>>(fmt_str), std::forward<_Types>(_Args)...));
//}

struct fmt_base {
	constexpr auto parse(fmt::format_parse_context& ctx) -> decltype(ctx.begin()) {
        auto it = ctx.begin(), end = ctx.end();
        if (it != end && *it != '}') { 
			//throw fmt::format_error("invalid format"); 
		}
        return it;
    }
	//constexpr auto parse (format_parse_context& ctx) { return ctx.begin(); }
};

#endif


//---
//#define dprintln(format, ...)		do { println("DEBUG: {}: " format, __FUNCTION__, __VA_ARGS__); } while (0)
//#define eprintln(format, ...)		do { println("ERROR: {}: " format, __FUNCTION__, __VA_ARGS__); } while (0)

#define eprintln(format, ...)		 println("ERROR: {}: " format, __FUNCTION__, ##__VA_ARGS__)


//// for containers
//template<typename T>
//void print_sc(const T& v)  { println("S: {}, C: {}", v.size(), v.capacity()); }
////#define print_sc(v)  { println("S: {}, C: {}", v.size(), v.capacity()); }
//template<typename T>
//void print_dt(const T& v)  { println("{}", v); }



//------------------------------------------


//#include <source_location>
//inline void logerr(const char* message, const std::source_location location = std::source_location::current()) {
//	//std::printf("ERROR: %s (%d, %d): %s: %s\n", location.file_name(), location.line(), location.column(), 
//	location.function_name(), message);
//	std::printf("ERROR: %s (%d): %s: %s\n", location.file_name(), location.line(), location.function_name(), message);
//}

//#define fm_debug(format, ...) do { printf("%s: (%d), %s: " format, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); } while (0)
//#define fm_error(format, ...) do { printf("ERROR: %s: (%d), %s: " format, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); } while (0)


// Old _MSC_VER behavior.
// MSVC (at least prior to the /Zc:preprocessor switch) will eat a trailing comma if VA_ARGS is empty.
// syntax error ')'
//#define eprintfln(format, ...)		printfln("ERROR: %s: " format, __FUNCTION__, __VA_ARGS__)
//#define dprintfln(format, ...)		printfln("DEBUG: %s: " format, __FUNCTION__, __VA_ARGS__)
////#define LOG_HELPER_INDIRECT(fmt, ...) LOG_HELPER("mylog: " fmt, ##__VA_ARGS__)
////#define MYLOG(...)                    LOG_HELPER_INDIRECT(__VA_ARGS__, 1)
// All compilers.
////#define eprintfln(format, ...)		printfln("ERROR: %s: " format, __FUNCTION__, ##__VA_ARGS__)



//=========================================
// Printing STD containers with iostream
//=========================================
//template <typename TStream, typename TRange> TStream& operator<<(TStream& os, const TRange& cont) {
//	os << "[";
//	bool first = true;
//	for (const auto& x : cont) { 
//		if (first) {
//		  first = false;
//		} else {
//		  os << ", ";
//		}
//		os << x;
//	}
//	os << "]";
//	return os;
//}


//=====================================================================
//=====================================================================
// PRINT

void printfln(const char* fmt, ...);
void wprintfln(const wchar_t* fmt, ...);

//---
inline constexpr int printf_buf_size = 1024;

void printfln(const char* fmt, ...) {
    char result[printf_buf_size] = {};
    int result_z_capacity = printf_buf_size;
    va_list argptr;
    va_start(argptr, fmt);
    // vsnprintf returns len without null terminator
    int len = vsnprintf(result, result_z_capacity, fmt, argptr);
    len = len + 1; //for '\n'
    const int len_wnc = len + 1;
	if (len_wnc >= 2 && len_wnc <= result_z_capacity) { 
        result[len_wnc-2] = '\n'; 
        result[len_wnc-1] = '\0'; 
    } else if (len_wnc > result_z_capacity) { 
        result[result_z_capacity-2] = '\n'; 
        result[result_z_capacity-1] = '\0'; 
    } else {
        // len < 0
        result[0] = '\n';
        result[1] = '\0';
    }
    va_end(argptr);
    printf(result);
}

void wprintfln(const wchar_t* fmt, ...) {
    wchar_t result[printf_buf_size] = {};
    int result_z_capacity = printf_buf_size;
    va_list argptr;
    va_start(argptr, fmt);
    // vsnprintf returns len without null terminator
    int len = _vsnwprintf(result, result_z_capacity, fmt, argptr);
    len = len + 1; //for '\n'
    const int len_wnc = len + 1;
	if (len_wnc >= 2 && len_wnc <= result_z_capacity) { 
        result[len_wnc-2] = '\n'; 
        result[len_wnc-1] = '\0'; 
    } else if (len_wnc > result_z_capacity) { 
        result[result_z_capacity-2] = '\n'; 
        result[result_z_capacity-1] = '\0'; 
    } else {
        // len < 0
        result[0] = '\n';
        result[1] = '\0';
    }
    va_end(argptr);
    wprintf(result);
}

//==================================================================
//==================================================================
// DS ST

template<class T, isz N>
class vector_st {
private:


    //bool is_reserve_needed(isz required_size) { return (required_size > capacity()); }

public:   


    //isz size_bytes() const { return (sizeof(T) * size()); }

    
    sdf::optional<isz> find_index(const T& element) {
    //isz find_index(const T& element) {
        for (isz i=0; i<size; ++i) {
            if (data[i] == element) { return i; }
        }
        //eprintfln("Element not found");
        return sdf::nullopt;
        //return -1;
    }

    void assign_data(const T* arr, isz arr_size) {
        isz copy_size = arr_size;
        if (copy_size > capacity()) {
            copy_size = capacity();
        }
        resize(copy_size);
        for_range(i, 0, copy_size) {
            m_data[i] = arr[i];
        }
    }
};


template<class T, isz N>
class basic_string_st {
private:


    bool is_reserve_needed(isz required_size) { return (required_size > capacity()); }

public:	

    isz capacity_wnc() const { return capacity() + 1; }
    
    //basic_string_st& operator=(const T* src) { this->assign(src); return *this; }   
    

    //basic_string_st& append_data(const T* src, isz src_len) { 
    //    sdf::strf_append(m_data, m_size, capacity(), src, src_len); 
    //    return *this; 
    //}
    //basic_string_st& append(const T* src) { return append_data(src, sdf::strz_len(src)); }
	
    //bool operator==(const T* src) { return !strcmp(m_data, src); }


    //isz size_bytes() const { return (sizeof(T) * size()); }
    
    void clear_memory() { 
        // CHANGED from resizable vector
        // Used only for resetting memory.    
        // Not needed in destructor as stack allocated arrays will destruct elements when they go out of scope.
        m_size = 0;
	} 

    void resize(isz count) {
        if (count > size()) {
            // Expand
            if (count > capacity()) {
                // count >= size and capacity
                // Memory reallocation needed
                //resize_exact(count); 
                // CHANGED from resizable vector                
                if (count == size()) { return; }
                // Fixed vector cannot allocate more memory than capacity.
                // Treat count as equal to capacity now since count is more than capacity.
                m_size = capacity();
            } else {
                // count > size but less than capacity
                m_size = count;
            }
        } else {
            // Shrink
            m_size = count;
        }
    }
};




