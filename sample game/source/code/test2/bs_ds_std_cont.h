#pragma once


#include <vector>
#include <string>


template<class T>
inline void vec_clear_memory(std::pmr::vector<T>& v) {
	std::pmr::vector<T>().swap(v);
}

template<class T>
inline intmax_t vec_size_bytes(const std::pmr::vector<T>& v) {
	return (sizeof(T) * v.size());
}

//-------------------------
// std::string Functions
//-------------------------


#if 0
inline void str_wcs_from_mbs(std::wstring& dest, const char* src, intmax_t src_len) {
    const intmax_t copy_len = src_len;
    if (copy_len > dest.size()) { dest.resize(copy_len); }
	sdf::mb_wcs_from_mbs(dest.data(), dest.size(), src, copy_len);
}
inline void str_mbs_from_wcs(std::string& dest, const wchar_t* src, intmax_t src_len) {
	const intmax_t copy_len = src_len;
    if (copy_len > dest.size()) { dest.resize(copy_len); }
	sdf::mb_mbs_from_wcs(dest.data(), dest.size(), src, copy_len);
}

inline void strz_wcs_from_mbs(std::wstring& dest, const char* src) {
    intmax_t src_len = sdf::strfz_len(src);
    str_wcs_from_mbs(dest, src, src_len);
}
inline void strz_mbs_from_wcs(std::string& dest, const wchar_t* src) {
    intmax_t src_len = sdf::strfz_len(src);
    str_mbs_from_wcs(dest, src, src_len);
}

inline void str_wcs_from_mbs(std::wstring& dest, const std::string& src) {
    str_wcs_from_mbs(dest, src.data(), src.size());
}
inline void str_mbs_from_wcs(std::string& dest, const std::wstring& src) {
	str_mbs_from_wcs(dest, src.data(), src.size());
}
#endif

//inline ostrz str(const std::wstring& e) { 
//	char buffer[1024];
//	sdf::strz_mbs_from_wcs(buffer, std::ssize(buffer), e.data(), e.size());
//	return ostrz_fmt("%s", buffer); 
//}