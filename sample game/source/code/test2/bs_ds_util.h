#pragma once

#include <stdlib.h>
#include <string.h>

namespace dsf
{

class sys_allocator {
public:
    void* allocate(size_t size_bytes) { return malloc(size_bytes); }
    void deallocate(void* ptr) { free(ptr); }	
};



//=========================================================
template<class T> inline void element_construct(T* ptr) { new (ptr) T(); }
template<class T> inline void element_copy_construct(T* ptr, const T& value) { new (ptr) T(value); }
template<class T> inline void element_destruct(T* ptr) { ptr->~T(); }


// Use std::swap or member swap for movable types.
template <class T>
inline void swap(T& a, T& b) {
    T temp(a);
    a = b;
    b = temp;
}

//=========================================================

inline size_t next_power2_floor(size_t x) {
    int power = 1;
	while (x >>= 1) { power <<= 1; }
    return power;
}
inline size_t next_power2_ceil(size_t x) {
	if (x <= 1) { return 1; }
    int power = 2;
    x--;
	while (x >>= 1) { power <<= 1; }
    return power;
}
// std::has_single_bit in <bit> header
inline bool is_power2(size_t x) {
    return (x != 0 && (x & (x - 1)) == 0);
}


template<class T> inline constexpr T k_null_char();
template <> inline constexpr char k_null_char<char>() { return '\0'; }
template <> inline constexpr wchar_t k_null_char<wchar_t>() { return L'\0'; }

template<class T> inline constexpr T k_default_char();
template <> inline constexpr char k_default_char<char>() { return '-'; }
template <> inline constexpr wchar_t k_default_char<wchar_t>() { return L'-'; }

inline ptrdiff_t strz_len(const char* src) { return strlen(src); }
inline ptrdiff_t strz_len(const wchar_t* src) { return wcslen(src); }

template<class T>
inline bool str_equals(const T* str1, ptrdiff_t str1_len, const T* str2, ptrdiff_t str2_len) { 
    if (str1_len != str2_len) { return false; }
    for (ptrdiff_t i = 0; i < str1_len; ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
        return true;
    }
}
//-----------------------------------------------------------
inline ptrdiff_t vector_calculate_growth(ptrdiff_t new_size, ptrdiff_t curr_capacity, ptrdiff_t max_size) {
    // given old_capacity and new_size, calculate geometric growth
    const ptrdiff_t old_capacity = curr_capacity;
    const auto max = max_size;

    if (old_capacity > max - old_capacity / 2) {
        return max; // geometric growth would overflow
    }

    const ptrdiff_t geometric = old_capacity + old_capacity / 2;

    if (geometric < new_size) {
        return new_size; // geometric growth would be insufficient
    }

    return geometric; // geometric growth is sufficient
}

}



