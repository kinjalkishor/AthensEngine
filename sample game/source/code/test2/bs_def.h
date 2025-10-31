#pragma once


#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <optional>


// implement sys_msg_box_print function
// fm_msg_box_ok does not work with variable names as L## does not work with variable names. Make it in function.
#define fm_msg_box_ok(msg)      MessageBoxW(nullptr, L##msg, L"Error", MB_OK)
#define fm_msg_box_ok_w(msg)    MessageBoxW(nullptr, msg, L"Error", MB_OK)

template <class T> inline void com_release(T*& t) { if (t) { t->Release(); t = nullptr; } }


namespace sdf {

template <class T, size_t N>
inline constexpr size_t size(const T (&)[N]) noexcept { return N; }
template <class T, ptrdiff_t N>
inline constexpr ptrdiff_t arr_cap(const T (&)[N]) noexcept { return N; }
// For null terminated char arrays, returns size without null char.
template <class T, ptrdiff_t N>
inline constexpr ptrdiff_t strz_cap(const T (&)[N]) noexcept { return N - 1; }

template <class T>
inline T tmin(const T a, const T b) { return (a < b) ? a : b; }
template <class T>
inline T tmax(const T a, const T b) { return (a > b) ? a : b; }

// returns x in [low, high].
template <class T>
inline T clamp(const T& x, const T& low, const T& high) {
    if (x < low) {
        return low;
    }
    if (x > high) {
        return high;
    }
    return x;
}


//==========================================
// size, Memory
//==========================================
// size to memset in bytes: count*sizeof(=size in bytes of type)
// memcpy(&dst[dstIdx], &src[srcIdx], numElementsToCopy * sizeof(Element));

inline void mem_set(void* dest, int val, size_t count, size_t elem_size) { memset(dest, val, count * elem_size); }
inline void mem_zero(void* dest, size_t count, size_t elem_size) { memset(dest, 0, count * elem_size); }
inline void mem_copy(void* dest, const void* src, size_t count, size_t elem_size) { memcpy(dest, src, count * sizeof(elem_size)); }
inline void* mem_alloc(size_t count, size_t elem_size) { return malloc(count * elem_size); }
inline void* mem_calloc(size_t count, size_t elem_size) { return calloc(count, elem_size); }

inline void safe_free(void*& t) { if (t) { free(t); t = nullptr; } }

//---
template <class T>
inline void vec_copy(T* dest, const T* src, ptrdiff_t count) { for (ptrdiff_t i = 0; i < count; ++i) { dest[i] = src[i]; } }


//==========================================
// STRING
//==========================================
inline ptrdiff_t strz_len(const char* src) { return strlen(src); }
inline ptrdiff_t strz_len(const wchar_t* src) { return wcslen(src); }

inline bool strz_equals(const char* str1, const char* str2) { return !(strcmp(str1, str2)); }
inline bool strz_ci_equals(const char* str1, const char* str2) { return !(stricmp(str1, str2)); }

inline void strz_to_lower(char* src) {
    for (ptrdiff_t i = 0; src[i] != '\0'; ++i) {
        src[i] = tolower(src[i]);
    }
}
inline void strz_to_upper(char* src) {
    for (ptrdiff_t i = 0; src[i] != '\0'; ++i) {
        src[i] = tolower(src[i]);
    }
}

//==========================================
// len and capacity are excluding null char at end of char string.
inline ptrdiff_t str_assign(char* dest, ptrdiff_t dest_capacity, const char* src, ptrdiff_t src_len) {
    ptrdiff_t copy_len = (src_len > dest_capacity) ? dest_capacity : src_len;
    memcpy(&dest[0], &src[0], copy_len * sizeof(char));
    dest[copy_len] = '\0';
    return copy_len;
}

inline ptrdiff_t str_append(char* dest, ptrdiff_t dest_len, ptrdiff_t dest_capacity, const char* src, ptrdiff_t src_len) {
    ptrdiff_t total_len = dest_len + src_len;
    if (total_len > dest_capacity) {
        total_len = dest_capacity;
    }
    ptrdiff_t append_len = total_len - dest_len;
    memcpy(&dest[dest_len], &src[0], append_len * sizeof(char));
    dest[total_len] = '\0';
    return total_len;
}

inline ptrdiff_t str_assignz(char* dest, ptrdiff_t dest_capacity, const char* src) {
    str_assign(dest, dest_capacity, src, strlen(src));
}

inline ptrdiff_t str_appendz(char* dest, ptrdiff_t dest_len, ptrdiff_t dest_capacity, const char* src) {
    str_append(dest, dest_len, dest_capacity, src, strlen(src));
}

//==========================================
inline ptrdiff_t wstr_assign_ansi(wchar_t* dest, ptrdiff_t dest_capacity, const char* src, ptrdiff_t src_len) {
    ptrdiff_t copy_len = (src_len > dest_capacity) ? dest_capacity : src_len;
    const int dest_cap_with_null_char = dest_capacity + 1;
    int result = MultiByteToWideChar(CP_UTF8, 0, src, copy_len, dest, dest_cap_with_null_char);
    if (!result) {
        return 0;
    }
    dest[copy_len] = L'\0';
    return copy_len;
}

inline ptrdiff_t wstr_assign_ansiz(wchar_t* dest, ptrdiff_t dest_capacity, const char* src) {
    wstr_assign_ansi(dest, dest_capacity, src, strlen(src));
}

//---------
// src contains terminating null char
// WideCharToMultiByte returns count_with_null_char for buffer required to store mb string, when cchWideChar is 0.
inline wchar_t* wstrz_assign_mbstrz_a(const char* src) {
    wchar_t* dest = nullptr;
    int count_with_null_char = MultiByteToWideChar(CP_UTF8, 0, src, -1, nullptr, 0);
    if (!count_with_null_char) {
        printf("Failed to convert string from UTF-8\n");
        return nullptr;
    }

    dest = static_cast<wchar_t*>(malloc(count_with_null_char * sizeof(wchar_t)));
    int result = MultiByteToWideChar(CP_UTF8, 0, src, -1, dest, count_with_null_char);
    if (!result) {
        printf("Failed to convert string from UTF-8\n");
        free(dest);
        return nullptr;
    }
    return dest;
}

// dest for return pointer must be mbstr.
// WideCharToMultiByte returns bytes_with_null_char size of buffer required to store wchar string, when cbMultiByte is 0.
inline char* mbstrz_assign_wstrz_a(const wchar_t* src) {
    char* dest = nullptr;
    int bytes_with_null_char = WideCharToMultiByte(CP_UTF8, 0, src, -1, nullptr, 0, nullptr, nullptr);
    if (!bytes_with_null_char) {
        printf("Failed to convert string to UTF-8\n");
        return nullptr;
    }

    dest = static_cast<char*>(malloc(bytes_with_null_char * sizeof(char)));
    int result = WideCharToMultiByte(CP_UTF8, 0, src, -1, dest, bytes_with_null_char, nullptr, nullptr);
    if (!result) {
        printf("Failed to convert string to UTF-8\n");
        free(dest);
        return nullptr;
    }
    return dest;
}


//-------------------------------
}