#pragma once

#include "base_types.h"

#include <stdlib.h>
#include <string.h>
//#include <stdio.h>
//#include <stdarg.h>


//=========================
// Utility Functions
//=========================

//#define fm_arr_cap(x)			static_cast<ptrdiff_t>((sizeof(x) / sizeof(*(x))))
//#define fm_strz_cap(x)			(fm_arr_cap(x) - 1)

//"D:\some 256-character path string<NUL>". 1+2+256+1 or [drive][:\][path][null] = 260
constexpr int MAX_STR_PATH_OS = 259;    //260;
constexpr int MAX_STR_PATH_FILE = 255;  //256;

template<class T> inline void com_release(T*& t) { if(t) { t->Release(); t = nullptr; } }	

template<class T> inline void safe_delete(T*& t) { if(t) { delete t; t = nullptr; } }
template<class T> inline void safe_delete_arr(T*& t) { if(t) { delete[] t; t = nullptr; } }


namespace sdf
{

template<class T>
struct span {
    T* m_data = nullptr;
    isz m_size = 0;        

    span() : m_data(nullptr), m_size(0) {}
    span(T* data, isz size) : m_data(data), m_size(size) {}

    isz size() const { return m_size; }
    const T* data() const { return m_data; }
	//T* data() { return m_data; }
    const T& operator[] (isz i) const { return m_data[i]; }
	//T& operator[] (isz i) { return m_data[i]; }
};

template<class T>
inline span<T> make_span(T* data, isz size) {
    return span(data, size);
}


// constructor for arrays
//template <size_t _Size>
//span(T (&_Arr)[_Size]) noexcept : span(_Arr, _Size) {}
// For span having const type
//span<const int> ia;
//using string_view = span<const char>;
//using wstring_view = span<const wchar_t>;

template<class T>
struct cspan {
    const T* m_data = nullptr;
    isz m_size = 0;        

    cspan() : m_data(nullptr), m_size(0) {}
    cspan(const T* data, isz size) : m_data(data), m_size(size) {}

    isz size() const { return m_size; }
    const T* data() const { return m_data; }
	//T* data() { return m_data; }
    const T& operator[] (isz i) const { return m_data[i]; }
	//T& operator[] (isz i) { return m_data[i]; }

    const T* c_str() const { return m_data; }
};

using string_view = cspan<char>;
using wstring_view = cspan<wchar_t>;


template<class T>
inline cspan<T> make_sv(const T* data, isz size) {
    return cspan(data, size);
}

inline cspan<char> make_sv(const char* src) {
    return cspan<char>(src, strlen(src));
}
inline cspan<wchar_t> make_sv(const wchar_t* src) {
    return cspan<wchar_t>(src, wcslen(src));
}


//-----------------------
template<class T>
inline T tmin(const T a, const T b) {
	return (a < b) ? a : b;
}
template<class T>
inline T tmax(const T a, const T b) {
	return (a > b) ? a : b;
}

template<class T>
inline void swap(T &a, T &b) {
    const T temp = a;
    a = b;
    b = temp;
}

//returns x in [low, high]
template<class T>
inline T clamp(const T& x, const T& low, const T& high) {
    //return tmin(tmax(x, low), high); //irr
	//return tmax(tmin(x, high), low); //dx
    //return tmin(high, tmax(x, low));

    if (x < low) { return low; }
    if (x > high) { return high; }
    return x;       
}

inline constexpr float k_aspect_16_9 = 1.77777777777777777778;
inline float get_aspect_ratio(int width, int height) { 
	const float w = scast<float>(width);
	const float h = scast<float>(height);
    // return 1:1 if height is zero.
    //1:1-1.0, 4:3-1.33, 16:9-1.77, 21:9-2.33
    return (h < 0.0001f) ? 1.0f : (w/h); 
}


//====================
// DS Functions
//====================
template<class T>
inline void element_construct(T* ptr) { new (ptr) T(); }
template<class T>
inline void element_copy_construct(T* ptr, const T& value) { new (ptr) T(value); }
template<class T>
inline void element_destruct(T* ptr) { ptr->~T(); }


//====================
// size, Memory
//====================

// Gives capacity of a stack allocated array in the scope of its declaration,
// for char string arrays gives capacity with space for null char included.
//template <class T, size_t N> inline constexpr size_t size(const T (&arr)[N]) noexcept;
template <class T, size_t N>
inline constexpr size_t size(const T (&)[N]) noexcept {
    return N;
}
template <class T, ptrdiff_t N>
inline constexpr ptrdiff_t arr_cap(const T (&)[N]) noexcept {
    return N;
}
// For null terminated char arrays, returns size without null char.
template <class T, ptrdiff_t N>
inline constexpr ptrdiff_t strz_cap(const T (&)[N]) noexcept {
    return N-1;
}

template <class T>
inline isz size_bytes(isz count) { return (count * sizeof(T)); }	


template<class T>
void mem_zero(T* dest, size_t num) {
	// size to memset in bytes: num*sizeof(=size in bytes of type)
	memset(dest, 0, num*sizeof(T));
}
//memcpy(&dst[dstIdx], &src[srcIdx], numElementsToCopy * sizeof(Element));
template<class T>
inline void mem_copy(T* dest, const T* src, size_t num) { 
    memcpy(dest, src, num*sizeof(T)); 
}

template<class T>
inline void vec_copy(T* dest, const T* src, isz num) {
    for (isz i=0; i<num; ++i) { dest[i] = src[i]; }
}

// Default allocation functions
//inline void* sys_allocate(size_t size_bytes) { return malloc(size_bytes); }
//inline void sys_deallocate(void* ptr) { free(ptr); }

template<class T>
inline T* ty_malloc(size_t cnt) { 
	//println("alloced:{}", cnt);
	return static_cast<T*>(malloc(sizeof(T)*cnt));
}
inline void ty_free(void* ptr) { free(ptr); }

//==========================================
// char*, string, wstring, utf-8 conversion
//==========================================
// fixed size string functions, truncating src and string growable memory functions with resize.
// Using stdlib functions as they are faster.

template<class T>
inline constexpr T k_null_char();
template <>
inline constexpr char k_null_char<char>() { return '\0'; }
template <>
inline constexpr wchar_t k_null_char<wchar_t>() { return L'\0'; }

inline isz get_truncated_len(isz src_len, isz max) {
    isz copy_len = src_len;
    if (copy_len > max) {  
        copy_len = max;
    }   
    return copy_len;
}

inline void calculate_append_len_fixed(isz& total_len, isz& append_len, isz dest_len, isz dest_capacity, isz src_len) {    
    const isz final_src_len = dest_len + src_len;   
    total_len = sdf::get_truncated_len(final_src_len, dest_capacity);
    // 0+10, 10-22 (0-22:23) (=22-10+1=23-10)
    // append_len = truncated_total_len - dest_len
    append_len = total_len - dest_len;
}

template<class T>
inline bool strf_is_empty(const T* s) {
    // Check if first char given by pointer to string is nullchar.
    return (*s == sdf::k_null_char<T>());
}


//---------------------
// fixed size string with known size functions
// If src_len > dest_capacity, src is truncated.
// dest_capacity, src_len is without null char.
template<class T>
inline void strf_assign(T* dest, isz& dest_len, isz dest_capacity, cspan<T> src) {
    isz copy_len = sdf::get_truncated_len(src.size(), dest_capacity);
	sdf::mem_copy(&dest[0], &src[0], copy_len);
	dest[copy_len] = sdf::k_null_char<T>();
	dest_len = copy_len;
}
template<class T>
inline void strf_assign_n(T* dest, isz& dest_len, isz dest_capacity, cspan<T> src, isz n) {
    isz copy_len = n;
    if (copy_len > src.size()) { copy_len = src.size(); }
    if (copy_len > dest_capacity) { copy_len = dest_capacity; }
	sdf::mem_copy(&dest[0], &src[0], copy_len);
	dest[copy_len] = sdf::k_null_char<T>();
	dest_len = copy_len;
}
template<class T>
inline void strf_append(T* dest, isz& dest_len, isz dest_capacity, cspan<T> src) {
    isz old_size = dest_len;
    isz total_len = 0;
    isz append_len = 0;
    sdf::calculate_append_len_fixed(total_len, append_len, old_size, dest_capacity, src.size());
    sdf::mem_copy(&dest[old_size], &src[0], append_len);
    dest[total_len] = sdf::k_null_char<T>();
    dest_len = total_len;  	    
}

//--------------------------
template<class T>
inline isz strz_len(const T* src);
template<>
inline isz strz_len(const char* src) {
	return strlen(src);
}
template<>
inline isz strz_len(const wchar_t* src) {
	return wcslen(src);
}

inline bool strz_equals(const char* str1, const char* str2) {
    return !(strcmp(str1, str2));
}
inline bool strz_ci_equals(const char* str1, const char* str2) { 
    return !(stricmp(str1, str2)); 
}

//====================================
// utf-8 functions
// Functions take ptr & len so that both const char* & std::string can be passed.
// dest_num_chars is dest capacity to hold chars without null char.
// mb_ functions do not insert terminating null char.
int mb_wcs_from_mbs(wchar_t* dest, int dest_num_chars, const char* src, int src_len);
int mb_mbs_from_wcs(char* dest, int dest_num_chars, const wchar_t* src, int src_len);

inline void strf_wcs_from_mbs(wchar_t* dest, isz& dest_len, isz dest_num_chars, sdf::string_view src) {
    isz copy_len = sdf::get_truncated_len(src.size(), dest_num_chars);
	sdf::mb_wcs_from_mbs(dest, dest_num_chars, src.data(), copy_len);
	dest[copy_len] = k_null_char<wchar_t>();
	dest_len = copy_len;
}
inline void strf_mbs_from_wcs(char* dest, isz& dest_len, isz dest_num_chars, sdf::wstring_view src) {
    isz copy_len = sdf::get_truncated_len(src.size(), dest_num_chars);
	sdf::mb_mbs_from_wcs(dest, dest_num_chars, src.data(), copy_len);
	dest[copy_len] = k_null_char<char>();
	dest_len = copy_len;
}


}