#pragma once

#include <vector>
#include <string>

#include "base_def.h"



//sdf::span(vertices_vec.data(), vertices_vec.size())
//make_span(vertices_vec)
template<class T>
inline sdf::span<T> make_span(sdr::vector<T>& v) {
	return sdf::span<T>(v.data(), v.size());
}

template<class T>
inline void vec_clear_memory(sdr::vector<T>& v) {
	sdr::vector<T>().swap(v);
}

template<class T>
inline isz vec_size_bytes(const sdr::vector<T>& v) {
	return (sizeof(T) * v.size());
}

//-------------------------
// std::string Functions
//-------------------------

template<class T>
inline sdf::basic_string_view<T> make_sv(sdr::basic_string<T>& v) {
	return sdf::basic_string_view<T>(v.data(), v.size());
}

inline void str_wcs_from_mbs(std::wstring& dest, const char* src, isz src_len) {
    const isz copy_len = src_len;
    if (copy_len > dest.size()) { dest.resize(copy_len); }
	sdf::mb_wcs_from_mbs(dest.data(), dest.size(), src, copy_len);
}
inline void str_mbs_from_wcs(std::string& dest, const wchar_t* src, isz src_len) {
	const isz copy_len = src_len;
    if (copy_len > dest.size()) { dest.resize(copy_len); }
	sdf::mb_mbs_from_wcs(dest.data(), dest.size(), src, copy_len);
}

inline void strz_wcs_from_mbs(std::wstring& dest, const char* src) {
    isz src_len = sdf::strfz_len(src);
    str_wcs_from_mbs(dest, src, src_len);
}
inline void strz_mbs_from_wcs(std::string& dest, const wchar_t* src) {
    isz src_len = sdf::strfz_len(src);
    str_mbs_from_wcs(dest, src, src_len);
}

inline void str_wcs_from_mbs(std::wstring& dest, const std::string& src) {
    str_wcs_from_mbs(dest, src.data(), src.size());
}
inline void str_mbs_from_wcs(std::string& dest, const std::wstring& src) {
	str_mbs_from_wcs(dest, src.data(), src.size());
}

//inline ostrz str(const std::wstring& e) { 
//	char buffer[1024];
//	sdf::strz_mbs_from_wcs(buffer, std::ssize(buffer), e.data(), e.size());
//	return ostrz_fmt("%s", buffer); 
//}