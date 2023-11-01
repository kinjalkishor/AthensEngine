#pragma once

#include <stdio.h>

#define USE_STD_FORMAT 1

#if USE_STD_FORMAT
#include <format>
// C++ 23
//#include <print> 
// printf is not slower than cout for strings since from C++11, string c_str() and data() both return 
// null terminated char pointer, which requires string to be always null terminated in memory.

//template<class... Args>
//void println(std::FILE* stream, std::format_string<Args...> fmt, Args&&... args);
//std::print(stream, "{}\n", std::format(fmt, std::forward<Args>(args)...));
//std::println(stdout, fmt, std::forward<Args>(args)...);

template <class... _Types>
_NODISCARD inline void print(const std::string_view _Fmt, const _Types&... _Args) {
	//std::vprint(std::string_view(_Fmt), std::make_format_args(_Args...));
    //std::cout << std::vformat(_Fmt, std::make_format_args(_Args...));
	std::printf("%s", std::vformat(_Fmt, std::make_format_args(_Args...)).c_str());
}
template <class... _Types>
_NODISCARD inline void println(const std::string_view _Fmt, const _Types&... _Args) {
    //std::cout << std::vformat(_Fmt, std::make_format_args(_Args...)) << "\n";
	std::printf("%s\n", std::vformat(_Fmt, std::make_format_args(_Args...)).c_str());
}

template <class... _Types>
_NODISCARD inline void wprint(const std::wstring_view _Fmt, const _Types&... _Args) {
	std::wprintf(L"%s", std::vformat(_Fmt, std::make_format_args<std::wformat_context>(_Args...)).c_str());
}
template <class... _Types>
_NODISCARD inline void wprintln(const std::wstring_view _Fmt, const _Types&... _Args) {
	std::wprintf(L"%s\n", std::vformat(_Fmt, std::make_format_args<std::wformat_context>(_Args...)).c_str());
}

#endif