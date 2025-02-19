#pragma once

#include <stdio.h>

#include <format>

template <class... _Types>
inline void print(const std::string_view _Fmt, const _Types&... _Args) {	    
	printf("%s", std::vformat(_Fmt, std::make_format_args(_Args...)).c_str());
}
template <class... _Types>
inline void println(const std::string_view _Fmt, const _Types&... _Args) {    
	printf("%s\n", std::vformat(_Fmt, std::make_format_args(_Args...)).c_str());
}

template <class... _Types>
inline void wprint(const std::wstring_view _Fmt, const _Types&... _Args) {
	wprintf(L"%s", std::vformat(_Fmt, std::make_format_args<std::wformat_context>(_Args...)).c_str());
}
template <class... _Types>
inline void wprintln(const std::wstring_view _Fmt, const _Types&... _Args) {
	wprintf(L"%s\n", std::vformat(_Fmt, std::make_format_args<std::wformat_context>(_Args...)).c_str());
}


