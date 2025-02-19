#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <vector>
#include <string>
#include <optional>

template<class T>
inline void vec_clear_memory(std::pmr::vector<T>& v) {
	sdr::vector<T>().swap(v);
}


//-------------------------
inline ptrdiff_t wstring_assign_mbs(std::pmr::wstring& dest, const char* src, ptrdiff_t src_len) {
    ptrdiff_t copy_len = src_len;
	if (copy_len > dest.size()) { dest.resize(copy_len); }
	int result = MultiByteToWideChar(CP_UTF8, 0, src, copy_len, dest.data(), dest.size());
    if (!result) { return 0; }
	return copy_len;
}

inline ptrdiff_t wstring_assign_mbsz(std::pmr::wstring& dest, const char* src) {
    int count_with_null_char = MultiByteToWideChar(CP_UTF8, 0, src, -1, nullptr, 0);
    if (!count_with_null_char) { return 0; }
    ptrdiff_t copy_len = count_with_null_char-1;
	wstring_assign_mbs(dest, src, copy_len);
}

inline ptrdiff_t wstring_assign_string(std::pmr::wstring& dest, const std::pmr::string& src) {
    return wstring_assign_mbs(dest, src.data(), src.size());
}





