#pragma once


#include "base_print.h"
#include "base_io.h"
#include <iostream>


// test data type with constructors and destructors
//#define TRACK
class iw
{
public:
    int e = 0;
    iw() { 
#ifdef TRACK
        printf("iw consructor called\n"); 
#endif
    }
    ~iw() { 
        e = 0;
#ifdef TRACK
        printf("iw destructor called\n"); 
#endif
    }  
    iw(int i) : e(i) { 
#ifdef TRACK
        printf("iw consructor_i called\n"); 
#endif
    }
    iw(const iw& v) : e(v.e) { 
#ifdef TRACK
        printf("iw consructor_cpy called\n"); 
#endif
    }
    operator int() { return e; }
    //iw& operator = (int i) { e = i; }

    //iw operator=(iw other) { this->e ==other.e; return *this; }

    bool operator==(iw other) { return (this->e == other.e); }

    //ostrz str() { return ostrz_fmt("%d", e); }
};

inline std::ostream& operator << (std::ostream& o, const iw& v) {
	o << v.e;	
	return o;
}

template <>
struct fmt::formatter<iw> {
    constexpr auto parse (format_parse_context& ctx) { return ctx.begin(); }
    template <typename FormatContext>
    auto format(const iw& v, FormatContext& ctx) const -> decltype(ctx.out()) {
        fmt::format_to(ctx.out(), "{}", v.e); 
        return ctx.out();
    }
};

#if USE_STD_FORMAT
template<>
struct std::formatter<iw> : std::formatter<std::string> {
    auto format(const iw& value, std::format_context& ctx) {
        auto s{ std::format("{}", value) };
		return std::formatter<std::string>::format(s, ctx);
    }
};
#endif