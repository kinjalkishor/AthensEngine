#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdint.h>

namespace sdf
{

template <class T, intmax_t N> inline constexpr intmax_t strz_cap(const T (&)[N]) noexcept { return N-1; }

inline intmax_t strz_len(const char* src) { return strlen(src); }
inline intmax_t strz_len(const wchar_t* src) { return wcslen(src); }

inline intmax_t strf_assign_mbs(wchar_t* dest, intmax_t dest_capacity, const char* src, intmax_t src_len) {
    intmax_t copy_len = src_len;
    if (copy_len > dest_capacity) { copy_len = dest_capacity; }
	const int dest_size_with_null_char = dest_capacity+1;
	int result = MultiByteToWideChar(CP_UTF8, 0, src, src_len, dest, dest_size_with_null_char);
	dest[copy_len] = L'\0';
	return copy_len;
}
inline intmax_t strf_assign_wcs(char* dest, intmax_t dest_capacity, const wchar_t* src, intmax_t src_len) {
    intmax_t copy_len = src_len;
    if (copy_len > dest_capacity) { copy_len = dest_capacity; }
	const int dest_size_with_null_char = dest_capacity+1;
	int result = WideCharToMultiByte(CP_UTF8, 0, src, src_len, dest, dest_size_with_null_char, nullptr, nullptr);	
	dest[copy_len] = '\0';
	return copy_len;
}

}