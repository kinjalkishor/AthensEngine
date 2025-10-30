#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <optional>
#include <string>
#include <vector>

template <class T>
inline void vec_clear_memory(std::pmr::vector<T>& v) {
    std::pmr:: ::vector<T>().swap(v);
}

template <class T>
inline void vec_assign_data(std::pmr::vector<T>& v, const T* src, ptrdiff_t src_len) {
    v.clear();
    v.resize(src_len);
    for (ptrdiff_t i = 0; i < src_len; ++i) {
        v[i] = src[i];
    }
}

//======================================================================
template <class T>
inline void string_assign_data(std::pmr::basic_string<T>& v, const T* src, ptrdiff_t src_len) {
    v.clear();
    v.resize(src_len);
    memcpy(v.data(), src, src_len);
}

inline ptrdiff_t wstring_assign_ansi(std::pmr::wstring& dest, const char* src, ptrdiff_t src_len) {
    ptrdiff_t copy_len = src_len;
    if (copy_len > dest.size()) {
        dest.resize(copy_len);
    }
    int result = MultiByteToWideChar(CP_UTF8, 0, src, copy_len, dest.data(), dest.size());
    if (!result) {
        return 0;
    }
    return copy_len;
}

inline ptrdiff_t wstring_assign_string(std::pmr::wstring& dest, const std::pmr::string& src) {
    return wstring_assign_ansi(dest, src.data(), src.size());
}

//-----------------
inline ptrdiff_t wstring_assign_mbsz(std::pmr::wstring& dest, const char* src) {
    int count_with_null_char = MultiByteToWideChar(CP_UTF8, 0, src, -1, nullptr, 0);
    if (!count_with_null_char) {
        return 0;
    }
    ptrdiff_t copy_len = count_with_null_char - 1;
    return wstring_assign_ansi(dest, src, copy_len);
}

//----------------------------------------------------------------------
// For tutorials only. May do extra malloc if string not move.
inline std::pmr::wstring strz_to_wstring(const char* src) {
    std::pmr::wstring dest;
    wstring_assign_mbsz(dest, src);
    return dest;
}
