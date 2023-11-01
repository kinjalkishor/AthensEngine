#pragma once

#include <stdarg.h>
#include <stdio.h>
#include <format>

//#include <iostream>
//#include <stdarg.h>

//=====================================
// Printing custom types with printf
//=====================================
struct ostrz {
	// Can use dynamic allocation for bigger sizes, truncates for now
	static const int N = 1024;
	char m_data[N] = {};

	int z_capacity_wnc() const { return N; }
	const char* c_str() { return m_data; }
    void print_data() { printf("%s\n", m_data); }
};
//inline std::ostream& operator<<(std::ostream& o, const ostrz& v) {
//	o << v.c_str();	
//	return o;
//}

//ostrz ostrz_fmt(const char* fmt, ...);

//-------------------------------
inline ostrz ostrz_fmt(const char* fmt, ...) {
	ostrz result;
    va_list argptr;
    va_start(argptr, fmt);
    int len = vsnprintf(result.m_data, result.z_capacity_wnc(), fmt, argptr);
    const int len_wnc = len + 1;
	if (len_wnc >= 1 && len_wnc <= result.z_capacity_wnc()) { 
        result.m_data[len_wnc-1] = '\0'; 
    } else if (len_wnc > result.z_capacity_wnc()) { 
       result.m_data[result.z_capacity_wnc()-1] = '\0'; 
    } else {
        // len < 0
        result.m_data[0] = '\0'; 
    }
    va_end(argptr);
    return result;
}


template <>
struct std::formatter<ostrz> : std::formatter<std::string> {
	auto format(ostrz v, format_context& ctx) {
		return formatter<string>::format(std::format("{}", v.c_str()), ctx);
	}
};

#if USE_FMT_FORMAT
template <>
struct fmt::formatter<ostrz> {
    constexpr auto parse (format_parse_context& ctx) { return ctx.begin(); }
    template <typename FormatContext>
    auto format(ostrz& v, FormatContext& ctx) const -> decltype(ctx.out()) {
        fmt::format_to(ctx.out(), "{}", v.c_str()); 
        return ctx.out();
    }
};
#endif


//printf("%s\n", ostrz_fmt("\n%06d\n%6d\n%6d\n%010.3f",1, 12, 123, 123.456).c_str());
//struct v3 {
//	float x, y, z;
//	ostrz str() { return ostrz_fmt("%f, %f, %f", x, y,z); }
//};
//v3 a{2, 4, 5};
//ostrz r = a.str();
//printf("%s\n", r.c_str());	
//printf("%s\n", a.str().c_str());	