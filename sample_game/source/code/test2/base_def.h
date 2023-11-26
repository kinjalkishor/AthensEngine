#pragma once

#include "base_types.h"


#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include <ctype.h>
//#include <stdio.h>
//#include <stdarg.h>


//=========================
// Utility Functions
//=========================
//#define fm_arr_cap(x)			static_cast<ptrdiff_t>((sizeof(x) / sizeof(*(x))))
//#define fm_strz_cap(x)			(fm_arr_cap(x) - 1)

//"D:\some 256-character path string<NUL>". 1+2+256+1 or [drive][:\][path][null] = 260
inline constexpr int MAX_PATH_OS = 260;
inline constexpr int MAX_STR_PATH_OS = 259;    //260;
inline constexpr int MAX_STR_PATH_FILE = 255;  //256;


template<class T> inline void com_release(T*& t) { if(t) { t->Release(); t = nullptr; } }	

template<class T> inline void safe_delete(T*& t) { if(t) { delete t; t = nullptr; } }
template<class T> inline void safe_delete_arr(T*& t) { if(t) { delete[] t; t = nullptr; } }


namespace sdf 
{

// Gives capacity of a stack allocated array in the scope of its declaration,
// for char string arrays gives capacity with space for null char included.
//template <class T, size_t N> inline constexpr size_t size(const T (&arr)[N]) noexcept;
template <class T, size_t N>
inline constexpr size_t size(const T (&)[N]) noexcept { return N; }
template <class T, ptrdiff_t N>
inline constexpr ptrdiff_t arr_cap(const T (&)[N]) noexcept { return N; }


template<class T> inline void element_construct(T* ptr) { new (ptr) T(); }
template<class T> inline void element_copy_construct(T* ptr, const T& value) { new (ptr) T(value); }
template<class T> inline void element_destruct(T* ptr) { ptr->~T(); }


template<class T> inline T tmin(const T a, const T b) { return (a < b) ? a : b; }
template<class T> inline T tmax(const T a, const T b) { return (a > b) ? a : b; }

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


template <class T>
inline void swap(T& a, T& b) {
    T temp = ::std::move(a);
    a = ::std::move(b);
    b = ::std::move(temp);
}


template<class T> inline isz size_bytes(isz count) { return (count * sizeof(T)); }	


inline constexpr float k_aspect_16_9 = 1.77777777777777777778;
inline float get_aspect_ratio(float width, float height) { 
    // return 1:1 if height is zero.
    //1:1-1.0, 4:3-1.33, 16:9-1.77, 21:9-2.33
    return (height < 0.0001f) ? 1.0f : (width/height); 
}


//====================
// size, Memory
//====================
// size to memset in bytes: count*sizeof(=size in bytes of type)
template<class T>
void mem_zero(T* dest, size_t count) { memset(dest, 0, count*sizeof(T)); }
//memcpy(&dst[dstIdx], &src[srcIdx], numElementsToCopy * sizeof(Element));
template<class T>
inline void mem_copy(T* dest, const T* src, size_t count) { memcpy(dest, src, count*sizeof(T)); }

template<class T>
inline void vec_copy(T* dest, const T* src, isz count) { for (isz i=0; i<count; ++i) { dest[i] = src[i]; } }

template<class T>
inline T* ty_malloc(size_t count) { return static_cast<T*>(malloc(sizeof(T)*count)); }
inline void ty_free(void* ptr) { free(ptr); }


//==========================================
// char*, string, wstring, utf-8 conversion
//==========================================
// fixed size string functions (strf_), truncates src.
// string growable memory functions, increase memory with resize.
// Using stdlib functions as they are faster.

// For null terminated char arrays, returns size without null char.
template <class T, ptrdiff_t N>
inline constexpr ptrdiff_t strz_cap(const T (&)[N]) noexcept { return N-1; }

inline isz strfz_len(const char* src) { return strlen(src); }
inline isz strfz_len(const wchar_t* src) { return wcslen(src); }

//====================================
// utf-8 functions
// Functions take ptr & len so that both const char* & std::string can be passed.
// dest_num_chars is dest capacity to hold chars without null char.
// mb_ functions do not insert terminating null char.
//==========================================
// WideCharToMultiByte function exposes the encodings/code pages used for the conversion in the parameter list, while wcstombs does not.
// CP_ACP, means a codepage specific to the systems current locale - set in the control panel Localization tool "Language to use for 
// Non Unicode Programs". Use CP_UTF8 instead.
// Windows only
// dest_capacity is dest capacity to hold chars without null char.
inline int mb_wcs_from_mbs(wchar_t* dest, int dest_capacity, const char* src, int src_len) {	
	const int dest_size_with_null_char = dest_capacity+1;	
	int result = MultiByteToWideChar(CP_UTF8, 0, src, src_len, dest, dest_size_with_null_char);	
	return result;
}
inline int mb_mbs_from_wcs(char* dest, int dest_capacity, const wchar_t* src, int src_len) {
	const int dest_size_with_null_char = dest_capacity+1;	
	int result = WideCharToMultiByte(CP_UTF8, 0, src, src_len, dest, dest_size_with_null_char, nullptr, nullptr);	
	return result;
}

inline isz strf_assign_mbs(wchar_t* dest, isz dest_capacity, const char* src, isz src_len) {
    isz copy_len = src_len;
    if (copy_len > dest_capacity) { copy_len = dest_capacity; }

	//sdf::mb_wcs_from_mbs(dest, dest_capacity, src, copy_len);
	const int dest_size_with_null_char = dest_capacity+1;
	int result = MultiByteToWideChar(CP_UTF8, 0, src, src_len, dest, dest_size_with_null_char);

	dest[copy_len] = L'\0';
	return copy_len;
}
inline isz strf_assign_wcs(char* dest, isz dest_capacity, const wchar_t* src, isz src_len) {
    isz copy_len = src_len;
    if (copy_len > dest_capacity) { copy_len = dest_capacity; }

	//sdf::mb_mbs_from_wcs(dest, dest_capacity, src, copy_len);
	const int dest_size_with_null_char = dest_capacity+1;
	int result = WideCharToMultiByte(CP_UTF8, 0, src, src_len, dest, dest_size_with_null_char, nullptr, nullptr);	

	dest[copy_len] = '\0';
	return copy_len;
}

//----------------------------------------------------------
template<class T>
inline isz strf_assign(T* dest, isz dest_capacity, const T* src, isz src_len) {
    isz copy_len = src_len;
    if (copy_len > dest_capacity) { copy_len = dest_capacity; }
    //sdf::mem_copy(&dest[0], &src[0], copy_len);
    memcpy(&dest[0], &src[0], sizeof(T)*copy_len);
    dest[copy_len] = '\0';
    return copy_len;
}

template<class T>
inline isz strf_append(T* dest, isz dest_len, isz dest_capacity, const T* src, isz src_len) {
    isz total_len = dest_len + src_len;
    if (total_len > dest_capacity) { total_len = dest_capacity; }
    isz append_len = total_len - dest_len;
    //sdf::mem_copy(&dest[dest_len], &src[0], append_len);
    memcpy(&dest[dest_len], &src[0], sizeof(T)*append_len);
    dest[total_len] = L'\0';
    return total_len;
}

inline bool strfz_equals(const char* str1, const char* str2) { return !(strcmp(str1, str2)); }
inline bool strfz_equals(const wchar_t* str1, const wchar_t* str2) { return !(wcscmp(str1, str2)); }
inline bool strfz_ci_equals(const char* str1, const char* str2) { return !(stricmp(str1, str2)); }
inline bool strfz_ci_equals(const wchar_t* str1, const wchar_t* str2) { return !(wcsicmp(str1, str2)); }


template<class T> inline constexpr T k_null_char();
template <> inline constexpr char k_null_char<char>() { return '\0'; }
template <> inline constexpr wchar_t k_null_char<wchar_t>() { return L'\0'; }

template<class T>
inline bool strfz_is_empty(const T* s) {
    // Check if first char given by pointer to string is nullchar.
    return (*s == sdf::k_null_char<T>());
}


//----------------------------------------------------------
inline bool strfz_isalpha(const char *src) {
    while (isalpha(*src)) { ++src; }
    return (*src == '\0');
}
inline bool strfz_isalnum(const char* src) {
	while (isalnum(*src)) { ++src; }
    return (*src == '\0');
}
inline bool strfz_isdigit(const char* src) {
	while (isdigit(*src)) { ++src; }
    return (*src == '\0');
}
inline bool strfz_islower(const char* src) {
	while (islower(*src)) { ++src; }
    return (*src == '\0');
}
inline bool strfz_isupper(const char* src) {
	while (isupper(*src)) { ++src; }
    return (*src == '\0');
}



//=======================
// SPAN, STRING_VIEW
//=======================
template<class T>
class span {
private:
    T* m_data = nullptr;
    isz m_size = 0; 

public:
    span() {}
    span(T* data, isz size) : m_data(data), m_size(size) {}

    isz size() const { return m_size; }

    const T* data() const { return m_data; }
    const T& operator [](isz i) const { return m_data[i]; }
};

template<class T>
inline span<T> make_span(T* data, isz size) { return span(data, size); }
template <class T, size_t N>
inline span<T> make_span(T (&data)[N]) { return span(data, N); }

//---
template <class T>
class basic_string_view { 
private:
    const T* m_data = nullptr;
    isz m_size = 0;

public:
    basic_string_view() {}
    basic_string_view(const T* data, isz size) : m_data(data), m_size(size) {}

    isz size() const { return m_size; }

    const T* data() const { return m_data; }
    const T& operator [](isz i) const { return m_data[i]; }
};

using string_view = basic_string_view<char>;
using wstring_view = basic_string_view<wchar_t>;

template<class T>
inline basic_string_view<T> make_sv(T* data, isz size) { return basic_string_view(data, size); }

inline basic_string_view<char> make_sv(const char* src) { return basic_string_view<char>(src, strlen(src)); }
inline basic_string_view<wchar_t> make_sv(const wchar_t* src) { return basic_string_view<wchar_t>(src, wcslen(src)); }


//template <class T, size_t N>
//inline basic_string_view<T> make_sv(const T (&data)[N]) { return basic_string_view(data, N); }
// constructor for arrays
//template <size_t _Size>
//span(T (&_Arr)[_Size]) noexcept : span(_Arr, _Size) {}
// For span having const type
//span<const int> ia;


//====================
// Optional
//====================
// no-value state indicator
struct tag_nullopt { 
    struct tag_f {};
    constexpr explicit tag_nullopt(tag_f) {}
};
inline constexpr tag_nullopt nullopt{tag_nullopt::tag_f{}};

template<class T>
class optional {
public:
    bool has_value = false;    
    T val;

    optional() {}
    ~optional() {}

    // Success case
    optional(const T& value) : has_value(true), val(value) {}
    // Error case	
    optional(const tag_nullopt) : has_value(false), val(T{}) {}

    optional(const optional& other) {
        if (other.has_value) { val = other.val; }
        has_value = other.has_value;
    }
    optional& operator =(const optional& other) {
        if (other.has_value) { val = other.val; }
        has_value = other.has_value;
    }

    optional(optional&& other) noexcept {
        if (other.has_value) { val = ::std::move(other.val); }
        has_value = other.has_value;
    }
    optional& operator =(optional&& other) noexcept {
        if (other.has_value) { val = ::std::move(other.val); }
        has_value = other.has_value;
    }

    explicit operator bool() const { return has_value; }

    const T value() const { return val; }
    T value() { return val; }

    const T value_or(const T& default_val) const { return (has_value ? val : default_val); }
    T value_or(const T& default_val) { return (has_value ? val : default_val); }
};


//=======================
// RELATIONAL
//=======================
// a!=b :	!(a == b)
// a>b  :	 (b < a)
// a<=b :	!(b < a)
// a>=b :	!(a < b)
template<class T> inline bool ty_is_not_equal(const T& a, const T& b) { return !(a == b); }
template<class T> inline bool ty_is_greater(const T& a, const T& b) { return (b < a); }
template<class T> inline bool ty_is_less_equal(const T& a, const T&b) { return !(b < a); }
template<class T> inline bool ty_is_greater_equal(const T& a, const T& b) { return !(a < b); }

//=======================
// DS FUNCTIONS
//=======================
// Linear search
//indexof
template<class T>
inline sdf::optional<isz> vec_find_index(const T* data, isz size, const T& element) {
    for (isz i=0; i<size; ++i) {
        if (data[i] == element) { return i; }
    }
    //eprintfln("Element not found");
    return sdf::nullopt;
}

}