#pragma once

//============================================================================
#if 1


//============================================================
// <GENERAL>
//============================================================
<CHECK>
<TODO>
<ERROR>

// Project Properties -C/C++ -Preprocessor
// NDEBUG;_WINDOWS;%(PreprocessorDefinitions)


// Standard library headers, include as needed
#include <iostream>  // cin, cout (standard input/output)
#include <fstream>   // ifstream, ofstream (files)
#include <string>    // string (sequence of characters)
#include <vector>    // vector (an array with stack operations)
#include <map>       // map (associative array)
#include <algorithm> // min(), max(), swap(), sort(), copy(), fill()
#include <cstdlib>   // rand(), abs(), atoi(), exit()
#include <cctype>    // isalpha(), isdigit(), tolower()
#include <cmath>     // pow(), log(), exp(), sqrt(), sin(), cos(), atan()
#include <ctime>     // time()


#if 0
%s 	a string of characters
%d 	int, signed decimal (integer) number (base 10)
%u 	unsigned int, unsigned decimal (integer) number
%lld long long int or long long
%llu unsigned long long int or unsigned long long
%f 	floating-point number

%c 	character
%e 	exponential floating-point number
%o 	octal number (base 8)
%x 	number in hexadecimal (base 16)
//%i 	integer (base 10)
//%ld long int or long
//%lu unsigned long int or long unsigned int or unsigned long

%% 	print a percent sign
// \% 	print a percent sign (crash)


//#include <inttypes.h>
//uint64_t x;
//uint32_t y;
//PRId64, PRId32, PRIu64, PRIu32
// Because C++ interprets a character immediately following a string literal as a user-defined string literal, 
// C code such as printf("%"PRId64"\n",n); is invalid C++ and requires a space before PRId64. 
//printf("x: %" PRIu64 ", y: %" PRIu32 "\n", x, y);
//printf("%+" PRId64 "\n", INT64_MAX);    //+9223372036854775807


// 64-bit
//The %x (hex int format) printf modifier will not work as expected on a 64-bit Windows operating system. 
//It will only operate on the first 32 bits of the value that is passed to it.
%I32x to display a 32-bit integral type in hex format.
%I64x to display a 64-bit integral type in hex format.
%p (hex format for a pointer) will work as expected on a 64-bit Windows operating system.
#endif

// Escape Sequences That Represent Control Characters
\n Newline
\r Carriage return
\t Horizontal tab
\b Backspace 
//---
\\ Backslash
\' Single quote
\" Double quote


//=============================================================
// Tokenize a string in C
// The strtok function has an internal variable that stores the state of the strtok call. 
// This state is not unique to each thread - it is global. If any other code uses strtok 
// in another thread, you get problems.
const char* str = "POSITION:R32G32B32_FLOAT, COLOR:R32G32B32A32_FLOAT";
const char* sep = ", :";
char s[256];
//strcpy(s, "one two three");
strcpy(s, str);
char* token = strtok(s, sep);
while (token) {
	printf("token:%s\n", token);
	token = strtok(nullptr, sep);
}
//=============================================================
// extern templates
// .h
template <class T>
void g(int a) {
}
// .cpp
template <class T>
void g(int a) {
}
template void g<int>(int a);
template void g<long>(int a);
template void g<void*>(int a);

//=============================================================
// Define function pointer by using syntax
//typedef void (*FunctionPtr)();
//using FunctionPtr = void (*)();
//#include <type_traits>
//using FunctionPtr = std::add_pointer<void()>;

//=============================================================
//#include  <format>
//#include <source_location>
//template <> 
//struct std::formatter<std::source_location> : std::formatter<std::string>
//{
//	template<typename FC>  
//    auto format(const std::source_location& sl, FC& ctx)
//	{
//		auto s {std::format("file:{} line:{} column:{} function:{}", sl.file_name(), sl.line(), sl.column(), sl.function_name())};
//		return std::formatter::format(s, ctx);
//	}
//};

//template<>
//struct std::formatter<glm::dvec3> : std::formatter<std::string> {
//    auto format(glm::dvec3 t, std::format_context& ctx) {
//        auto s{ std::format("{} {} {}", t[0], t[1], t[2]) };
//        return std::formatter::format<std::string>(s, ctx);
//    }
//};


#include "fmt/format.h"

// FMT PRINT, PRINTLN FUNCTIONS
//----------------------------------
//template <class... _Types>
//_NODISCARD inline void print(const std::string_view _Fmt, const _Types&... _Args) {	
//	fmt::vprint(fmt::string_view(_Fmt), fmt::make_format_args(_Args...));
//}
//template <class... _Types>
//_NODISCARD inline void println(const std::string_view _Fmt, const _Types&... _Args) {	
//	fmt::vprint(fmt::string_view(_Fmt), fmt::make_format_args(_Args...));
//	fmt::print("\n");
//}
//template <class... _Types>
//_NODISCARD inline void wprint(const std::wstring_view _Fmt, const _Types&... _Args) {
//	fmt::vprint(fmt::wstring_view(_Fmt), fmt::make_wformat_args(_Args...));
//}
//template <class... _Types>
//_NODISCARD inline void wprintln(const std::wstring_view _Fmt, const _Types&... _Args) {
//	fmt::vprint(fmt::wstring_view(_Fmt), fmt::make_wformat_args(_Args...));
//	fmt::print("\n");
//}
// fmtlib version
//template <typename... T>
//_NODISCARD inline void print(fmt::format_string<T...> fmt, T&&... args) {
//  const auto& vargs = fmt::make_format_args(args...);
//  return fmt::detail::is_utf8() ? fmt::vprint(fmt, vargs)
//                           : fmt::detail::vprint_mojibake(stdout, fmt, vargs);
//}
//template <typename... T>
//_NODISCARD inline void wprint(fmt::wformat_string<T...> fmt, T&&... args) {
//  const auto& vargs = fmt::make_wformat_args(args...);
//  fmt::vprint(fmt::wstring_view(fmt), vargs);
//}
// logging functions
//template <typename... Args>
//_NODISCARD inline void log_warn(fmt::format_string<Args...>&& fmt_str, Args&&... args) {
//    fmt::print(stderr, "warning: {}\n", fmt::format(std::forward<fmt::format_string<Args...>>(fmt_str), std::forward<Args>(args)...));
//}
//template <typename... Args>
//_NODISCARD inline void log_info(fmt::format_string<Args...>&& fmt_str, Args&&... args) {
//    fmt::print("info: {}\n", fmt::format(std::forward<fmt::format_string<Args...>>(fmt_str), std::forward<Args>(args)...));
//}

// FMT CUSTOM TYPES
//----------------------------------
//template <>
//struct fmt::formatter<gm::vec3> {
//  char presentation = 'f';
//  constexpr auto parse(format_parse_context& ctx) {
//    auto it = ctx.begin(), end = ctx.end();
//    if (it != end && (*it == 'f')) { presentation = *it++; }
//    if (it != end && *it != '}') { throw format_error("invalid format"); }
//    return it;
//  }
//
//  template <typename FormatContext>
//  auto format(const gm::vec3& p, FormatContext& ctx) {
//    return format_to( ctx.out(), "{:.1f}, {:.1f}, {:.1f}", p[0], p[1], p[2]);
//  }
//};

#if 0
#include <fmt/format.h>

struct point {
  double x, y;
};

template <> struct fmt::formatter<point> {
  // Presentation format: 'f' - fixed, 'e' - exponential.
  char presentation = 'f';

  // Parses format specifications of the form ['f' | 'e'].
  constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
    // [ctx.begin(), ctx.end()) is a character range that contains a part of
    // the format string starting from the format specifications to be parsed,
    // e.g. in
    //
    //   fmt::format("{:f} - point of interest", point{1, 2});
    //
    // the range will contain "f} - point of interest". The formatter should
    // parse specifiers until '}' or the end of the range. In this example
    // the formatter should parse the 'f' specifier and return an iterator
    // pointing to '}'.

    // Please also note that this character range may be empty, in case of
    // the "{}" format string, so therefore you should check ctx.begin()
    // for equality with ctx.end().

    // Parse the presentation format and store it in the formatter:
    auto it = ctx.begin(), end = ctx.end();
    if (it != end && (*it == 'f' || *it == 'e')) presentation = *it++;

    // Check if reached the end of the range:
    if (it != end && *it != '}') throw format_error("invalid format");

    // Return an iterator past the end of the parsed range:
    return it;
  }

  // Formats the point p using the parsed format specification (presentation)
  // stored in this formatter.
  template <typename FormatContext>
  auto format(const point& p, FormatContext& ctx) const -> decltype(ctx.out()) {
    // ctx.out() is an output iterator to write to.
    return presentation == 'f'
              ? fmt::format_to(ctx.out(), "({:.1f}, {:.1f})", p.x, p.y)
              : fmt::format_to(ctx.out(), "({:.1e}, {:.1e})", p.x, p.y);
  }
};
#endif

fmt::print("Hello, world!\n");
fmt::print("I'd rather be {} than {}.\n", "right", "happy");
fmt::print("I'd rather be {1} than {0}.\n", "right", "happy");
gm::vec3 v1(1.1, 2.2, 3.3);
gm::vec3 v2(2.2, 3.3, 4.4);
fmt::print("{}\n{}\n", v1, v2);


//---------------------------------------------------
// ggformat lib
// ggprint("hello {}\n", 1.23);
//size_t ggformat( char * buf, size_t len, const char * fmt, ... );
//bool ggprint_to_file( FILE * file, const char * fmt, ... );
//bool ggprint( const char * fmt, ... );
// ggformat replaces snprintf, ggprint_to_file replaces fprintf, and ggprint replaces printf.
//#include <ggformat.h>
// GGFORMAT
void format(FormatBuffer* fb, const gm::vec3& v, const FormatOpts& opts) {
	//format(fb, "v3(");
	format(fb, v.x, opts);
	format(fb, ", ");
	format(fb, v.y, opts);
	format(fb, ", ");
	format(fb, v.z, opts);
	format(fb, ", ");
	//format(fb, ")");
}

//---------------------------------------------------
sdf::vector<float> numbers = {1, 2.2, 3};
fmt::print("[{}]\n", fmt::join(numbers, ", "));
fmt::print("{}\n", numbers); //<fmt/ranges.h>
std::cout << numbers << qwe;
for (const auto& x : numbers) { std::cout << x << ", "; } std::cout << qwe;
for (auto i = numbers.begin(); i != numbers.end(); ++i) { std::cout << *i << ", "; } std::cout << qwe;
// iterators with index() & value()
for (auto it = vec.begin(); it != vec.end(); ++it) { print("{} - {}\n", it.index(), *it); }
for (auto it = vec.begin(); it != vec.end(); ++it) { print("{} - {}\n", it.index(), it.value()); }
for (auto it = vec.begin()+2; it != vec.end()-1; ++it) { print("{} - {}\n", it.index(), it.value()); }
for (auto it = vec.begin(); auto& elem: vec) { print("{} - {}\n", it.index(), *it); ++it; }

//template <typename TStream, typename TRange> TStream& operator<<(TStream& os, const TRange& cont) {
//	os << "[ ";
//	for (const auto& x : cont) { os << x << ", "; }
//	os << "]";
//	return os;
//}
//template <typename TStream, typename T> 
//TStream& operator<<(TStream& os, const sdf::basic_string<T>& cont) {
//	os << cont.c_str();	
//	return os;
//}
//template <typename TStream, typename T> TStream& operator<<(TStream& os, const std::vector<T>& cont) {
//  //fmt::print(os, "[{}]", fmt::join(cont, ", "));
//	//fmt::print(os, "{}", cont); //<fmt/ranges.h>
//	os << "[ ";
//	for (const auto& x : cont) { os << x << ", "; }
//	//copy(cont.begin(), cont.end(), std::ostream_iterator<T>(os, ", "));
//	os << "]";
//	return os;
//}
// //Matches std::pair (for map et.al.), std::tuple and other heterogenous containers:
//template <typename T>
//concept is_tuple = requires { typename std::tuple_size<T>::type; };
//template <is_tuple T, std::size_t... Is>
//std::ostream& print_tuple(std::ostream& os, const T & tuple, std::index_sequence<Is...>) {
//    return os << ... << get<Is>(tuple);
//}
//template <is_tuple T>
//std::ostream& operator<<(std::ostream& os, const T & tuple) {
//    return print_tuple(os, tuple, std::make_index_sequence<std::tuple_size_v<T>>{});
//}

// println functions
//fmt::print("{}", fmt::vformat(_Fmt, fmt::make_format_args(_Args...)));
//fmt::print("{}\n", fmt::vformat(_Fmt, fmt::make_format_args(_Args...)));
//fmt::print(L"{}\n", fmt::vformat(_Fmt, fmt::make_wformat_args(_Args...)));

// Not needed: Use <fmt/ranges.h>
//template <typename Value>
//struct fmt::formatter<sdf::vector<Value>> 
//{
//    // Parses format specifications of the form ['f' | 'e'].
//    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
//        // Parse the presentation format and store it in the formatter:
//        auto it = ctx.begin(), end = ctx.end();
//        // Check if reached the end of the range:
//        if (it != end && *it != '}') throw format_error("invalid format");
//        // Return an iterator past the end of the parsed range:
//        return it;
//    }
//
//    template <typename FormatContext>
//    auto format(const sdf::vector<Value>& v, FormatContext& ctx) const -> decltype(ctx.out()) {
//        // ctx.out() is an output iterator to write to.
//        if (v.size()>0) {
//            //fmt::format_to(ctx.out(), "[");
//            //const isz one_less_size = v.size()-1;
//            //for (isz i = 0; i < one_less_size; ++i) { fmt::format_to(ctx.out(), "{}, ", v[i]); } 
//            //fmt::format_to(ctx.out(), "{}]", v[one_less_size]); 
//            fmt::format_to(ctx.out(), "[ ");
//            for (isz i = 0; i < v.size(); ++i) { fmt::format_to(ctx.out(), "{}, ", v[i]); } 
//            fmt::format_to(ctx.out(), "]"); 
//        } else {
//            fmt::format_to(ctx.out(), "[]"); 
//        }
//
//        return ctx.out();
//    }
//};

//template <typename T>
//struct fmt::formatter<sdf::basic_string<T>> {
//    //constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
//    //    auto it = ctx.begin(), end = ctx.end();
//    //    if (it != end && *it != '}') { throw format_error("invalid format"); }
//    //    return it;
//    //}
//	constexpr auto parse (format_parse_context& ctx) { return ctx.begin(); }
//    template <typename FormatContext>
//    auto format(const sdf::basic_string<T>& cont, FormatContext& ctx) const -> decltype(ctx.out()) {
//		fmt::format_to(ctx.out(), "{}", cont.c_str());
//        return ctx.out();
//    }
//};

// smaller and with fmt/ranges.h
//// for fmt/ranges.h error: constexpr function 'fmt::v9::detail::encode_types' cannot result in a constant expression
//namespace fmt { inline namespace v9 { namespace detail {
//	template <typename T>
//	struct is_std_string_like<sdf::basic_string<T>> : std::true_type {};
//}}}
//template <typename T>
//struct fmt::formatter<sdf::basic_string<T>> {
//	constexpr auto parse (format_parse_context& ctx) { return ctx.begin(); }
//    template <typename FormatContext>
//    auto format(const sdf::basic_string<T>& cont, FormatContext& ctx) const -> decltype(ctx.out()) {
//		fmt::format_to(ctx.out(), "{}", cont.c_str());
//        return ctx.out();
//    }
//};

//template <typename TSTREAM, typename T> TSTREAM& operator<<(TSTREAM& os, const sdf::vector<T>& vec) {
//    //fmt::print(os, "[{}]", fmt::join(vec, ", "));
//	os << "[ ";
//	for (const auto& x : vec) { os << x << ", "; }
//	//copy(vec.begin(), vec.end(), std::ostream_iterator<T>(os, ", "));
//	os << "]";
//	return os;
//}
//std::vector<int> numbers = {1, 2, 3};
//fmt::print("[{}]\n", fmt::join(numbers, ", "));
////std::ofstream fout("vector.txt");
////fout.precision(10);	
////std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(fout, "\n"));
//std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(std::cout, ", "));

//template <>
//struct fmt::formatter<sdf::basic_string<char>> 
//{
//    // Parses format specifications of the form ['f' | 'e'].
//    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
//        // Parse the presentation format and store it in the formatter:
//        auto it = ctx.begin(), end = ctx.end();
//        // Check if reached the end of the range:
//        if (it != end && *it != '}') throw format_error("invalid format");
//        // Return an iterator past the end of the parsed range:
//        return it;
//    }
//
//    template <typename FormatContext>
//    auto format(const sdf::basic_string<char>& cont, FormatContext& ctx) const -> decltype(ctx.out()) {
//        // ctx.out() is an output iterator to write to.
//        for (isz i = 0; i < cont.size(); ++i) { fmt::format_to(ctx.out(), "{}", cont[i]); } 
//        //fmt::format_to(ctx.out(), "{}", cont.c_str());
//        return ctx.out();
//    }
//};
//
//template <typename TStream, typename T> TStream& operator<<(TStream& os, const sdf::basic_string<T>& cont) {
//    for (isz i = 0; i < cont.size(); ++i) { os << cont[i]; } 
//    //os << cont.c_str();
//	return os;
//}

//template <typename Value>
//struct fmt::formatter<sdf::basic_string<Value>> 
//{
//    // Parses format specifications of the form ['f' | 'e'].
//    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
//        // Parse the presentation format and store it in the formatter:
//        auto it = ctx.begin(), end = ctx.end();
//        // Check if reached the end of the range:
//        if (it != end && *it != '}') throw format_error("invalid format");
//        // Return an iterator past the end of the parsed range:
//        return it;
//    }
//
//    template <typename FormatContext>
//    auto format(const sdf::basic_string<Value>& v, FormatContext& ctx) const -> decltype(ctx.out()) {
//        // ctx.out() is an output iterator to write to.
//        //if (v.size()>0) {            
//        //    for (isz i = 0; i < v.size(); ++i) { fmt::format_to(ctx.out(), "{}", v[i]); } 
//        //} else {            
//        //}
//        fmt::format_to(ctx.out(), "{}", v.c_str());
//        return ctx.out();
//    }
//};

// SCNLIB
#include <scn/scn.h>
#include <cstdio>
int main() {
    int i;
    // Read an integer from stdin
    // with an accompanying message
    scn::prompt("What's your favorite number? ", "{}", i);
    printf("Oh, cool, %d!", i);
}

//=============================================================
#define forloopi32(v, m)			for(int v = 0; v < int(m); ++v)
#define for_range(v, m)             for (std::decay_t<decltype(m)> v(0); v < m; ++v)

//=============================================================
// <MODULES>
// External lib to Modules
// sdl.ixx
module;
#include "SDL2/SDL.h"
export module sdl;
export using SDL_Init = ::SDL_Init;
//=============================================================

// <algorithm>
min(x,y)                             // Smaller of x or y
max(x,y)                             // Larger of x or y
swap(x,y);                           // Exchange the values of x and y
sort(v.begin(), v.end());            // Sort a vector or string (but not a map)
copy(v.begin(), v.end(), d.begin()); // Copy v to d, d.size() >= v.size()
fill(v.begin(), v.end(), x);         // Set all elements of v to x


//------------------
// In for loops cache the vector size
vector<T,Alloc>::size() { return _M_end - _M_begin; }
for (size_t i = 0, i_end = container.size(); i < i_end; ++i){
// do something performance critical
}

//------------------
// ARRAYSIZE, _countof, std::size, std::ssize
int a[] = { -5, 10, 15 };
std::cout << std::size(a) << '\n'; 
// since C++20 the signed size (ssize) can avail
auto i = std::ssize(v);
for (--i; i != -1; --i) {
    std::cout << v[i] << (i ? ' ' : '\n');
}

//------------------
//template<class T>
//void arr_push_back(const T& element, T* arr_data, int& arr_size, int arr_capacity)
//{
//    if (arr_size < arr_capacity) {
//        arr_data[arr_size++] = element; 
//    }
//}
//vector_st<int, 40> as;
//arr_push_back<int>(11, as.data(), as.m_size, as.capacity());
//arr_push_back<int>(12, as.data(), as.m_size, as.capacity());

//------------------
// std::span
int a[5]{1,2,3,4,5};
//int a[5];
std::span span1{a};
//std::span span1{a, std::ssize(a)}; //extent is wrong
println("span1: {}", span1);
println("span1 extent: {}", span1.extent);
//------------------
// Same name getter and setter
class myclass
{
    type var_;
public:
    type var() const;
    void var(const type& value);
};

//=============================================================
WNDCLASSEX wcex = {}; //C++
WNDCLASSEX wcex = {0}; //C 
WNDCLASSEX wcex; memset(&wcex, 0, sizeof(WNDCLASSEX)); //C

// 4:3      aspect ratio resolutions: 640×480, 800×600, 960×720, 1024×768, 1280×960, 1400×1050, 1440×1080 , 1600×1200, 1856×1392, 1920×1440, and 2048×1536.
// 16:9     aspect ratio resolutions: 1024×576, 1152×648, 1280×720, 1366×768, 1600×900, 1920×1080, 2560×1440 and 3840×2160.
// 16:10    aspect ratio resolutions: 1280×800, 1440×900, 1680×1050, 1920×1200 and 2560×1600.

//The printf function is equivalent to fprintf with the argument stdout interposed before the arguments to printf.
//printf("hello");
//fprintf(stdout, "hello");

//q_print_array_ostream(o, v.e, vec3::size(), float_precision);
#define q_print_array_ostream(ostream_obj, array_name, array_size, precision) \
{ \
	std::ostringstream os; \
	os << std::setprecision(precision) << std::fixed; \
	forloopi(i, array_size) { os << array_name[i] << qcs; } \
	ostream_obj << os.str(); \
}

//----------------------
// Sleep functions
Sleep(1);			
// Sleep in ms
// nanosleep on linux	
std::this_thread::sleep_for(std::chrono::milliseconds(1));	
std::this_thread::sleep_for(1ms);

//-----------------------------
// Placement new and delete
auto obj1 = new std::string("1");
// can be thought of as equivalent to
auto obj2 = (std::string*)malloc(sizeof(std::string));
new(obj2) std::string("2");
//---
delete obj1;
// can be thought of as equivalent to
obj2->~string();
free(obj2);

// try catch exceptions
try {
    //myvector.at(20) = 100;
    gout << b.at(8).e << sdf;
} catch (const std::out_of_range& oor) {
    std::cerr << "Out of Range error: " << oor.what() << '\n';
}
b.at(8).e = 100;
gout << b.at(8).e << sdf;


//-----------------------------
// Iterate a list, for loop
for (node = list->head; node != NULL; node = node->next) {
}
//-----------------------------
// Enum Flags
enum flags
{
    a = 1,
    b = 2,
    c = 4,
    d = 8,
};

int some_flags = a | b;
some_flags &= ~b; // clear b
some_flags |= d; // set d

//---
//Set a bit by writing set |= a
//Clear/reset a bit by writing set &= ~a
//Toggle a bit by writing set ^= a
//Check for a bit by writing (set & a) != 0

// for C++11 enum class define operators
flags operator~(const flags& f) {
    return flags(~static_cast<int>(f));
}
flags operator|(const flags& a, const flags& b) {
    return flags(static_cast<int>(a) | static_cast<flags>(b));
}

/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))           //(((uintmax_t)1)<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))        // '!!' to make sure this returns 0 or 1

/* x=target variable, y=mask */
#define BITMASK_SET(x,y) ((x) |= (y))
#define BITMASK_CLEAR(x,y) ((x) &= (~(y)))
#define BITMASK_FLIP(x,y) ((x) ^= (y))
//BITMASK_CHECK_ALL(x,y) can be implemented as !~((~(y))|(x)) , 
//but after applying De Morgan's law and re-arranging we get !(~(x) & (y))
#define BITMASK_CHECK_ALL(x,y) (!(~(x) & (y)))
#define BITMASK_CHECK_ANY(x,y) ((x) & (y))


//============================================================
// <STRING>
//============================================================

// Dynamic or static char string allocation according to size
char buf[256];
char* data = (n < 256) ? buf: malloc(n+1);
if (data != buf)
{
     free(data);
}

//=======================================================================================
// Short-string optimization
constexpr size_t buffer_size = 16; // Slightly larger than the size of a pointer
class Immutable_string {
public:
    Immutable_string(const char* str) :
        size(strlen(str))
    {
        if (size < buffer_size)
            strcpy_s(string_buffer, buffer_size, str);
        else {
            string_ptr = new char[size + 1];
            strcpy_s(string_ptr, size + 1, str);
        }
    }

    ~Immutable_string()
    {
        if (size >= buffer_size)
            delete[] string_ptr;
    }

    const char* get_str() const
    {
        return (size < buffer_size) ? string_buffer : string_ptr;
    }

private:
    // If the string is short enough, we store the string itself
    // instead of a pointer to the string.
    union {
        char* string_ptr;
        char string_buffer[buffer_size];
    };

    const size_t size;
};
//====================================
// And for my function above that receives a string argument? We can use C++17’s std::string_view[7] as our input parameter. 
// That makes it easier to accept both std::string and string literals as arguments, without unnecessary overhead.
void safer_still_func(std::string_view input) 
{ 
  std::string buf = input; 
  // ... 
} 


char as[32];
strcpy(as, "HI");
gout << as << QEL << sdf;

//----------------
std::string data = "Abc";
std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return std::tolower(c); });
//----------------
char str [80];
int i = 2;
std::printf ("Enter your name: ");
std::scanf("%s", str);  
std::printf ("Enter your age: ");
std::scanf ("%d", &i);
//printf("%s\n %i\n", str, i);
//std::printf ("Mr. %s , %d years old.\n",str,i);
gprintf ("Mr. %s , %d years old.\n",str,i);

//-------------------------------------------------
#include "color_console/color.h"
std::cout << "When in doubt, wear " << hue::red << "red"  << hue::reset << "." << endln;
std::cout << "When in doubt, wear " << dye::red("red") << "." << endln;
std::cout << "When" << endln;
//-------------------------------------------------
// Helper code to unpack variadic arguments
namespace internal
{
    template<class T>
    void unpack(std::vector<std::string> &vbuf, T t)
    {
        std::stringstream buf;
        buf << t;
        vbuf.push_back(buf.str());
    }
    template<class T, class ...Args>
    void unpack(std::vector<std::string> &vbuf, T t, Args &&... args)
    {
        std::stringstream buf;
        buf << t;
        vbuf.push_back(buf.str());
        unpack(vbuf, std::forward<Args>(args)...);
    }
}

//=================================================================
size_t split(std::string s, std::vector<std::string>& tokens,
             std::string delim ="\t\n ")
{
   tokens.clear();
   size_t pos = s.find_first_not_of(delim);
   while (pos != std::string::npos)
   {
      size_t next = s.find_first_of(delim, pos);
      if (pos == std::string::npos)
         tokens.emplace_back(s.substr(pos));
      else
      {
         tokens.emplace_back(s.substr(pos, next-pos));
         pos = s.find_first_not_of(delim, next);
      }
   }
   return tokens.size();
}



//============================================================
// <STREAM>
//============================================================
// std::endl vs "\n"
'\n' - to end the line
"some string\n" - the end the line after some string
std::endl - to end the line and flush the stream
//They do different things. "\n" Outputs a newline (in the appropriate platform-specific representation, so it generates a "\r\n" on Windows), 
//but std::endl does the same and flushes the stream. Usually, you don't need to flush the stream immediately and it'll just cost you performance, 
//so for the most part there's no reason to use std::endl.


// use "\n" instead of std::endl as we do not want to flush the stream on every output
namespace cds {
  char const nl = '\n';
}
namespace cds {
  std::ostream& nl(std::ostream& os) {
    return os << '\n';
  }
}
std::cout << "Tick" << cds::nl << std::flush;

//------------------------------------
#if 0
#include <stdarg.h>
#include <stdio.h>

void dbg_printf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}
#define TRACE(x) do { if (DEBUG) dbg_printf x; } while (0)
// And then, in the code, write:
TRACE(("message %d\n", var));

#endif

void example()
{
	gprintf("%s\n", __func__);
} // prints "example"
example();




//============================================================
// <VEC3>
//============================================================


// anonymous struct not allowed in modules
template<class T>
class tvec3
{
public:
    T x, y, z;
	constexpr int size() const { return 3; }

	tvec3() = default;
	//tvec3() : x(scast<T>(0)), y(scast<T>(0)), z(scast<T>(0)) {}
	explicit tvec3(T f) : x(f), y(f), z(f) {}	
	tvec3(T x, T y, T z) : x(x), y(y), z(z) {}	
		
	const T* data() const				{ return &x[0]; }
	T* data()							{ return &x[0]; }
    const T& operator[] (int i) const	{ return (&x)[i]; }
    T& operator [] (int i)				{ return (&x)[i]; }
};


// anonymous struct not allowed in modules
class vec3 {
public:
	float e[3];

	constexpr int size() const { return 3; }

	vec3() = default;
	//vec3() : e { {0.0f}, {0.0f}, {0.0f} } {} {}
	explicit vec3(float f) : e { {f}, {f}, {f} } {}
	vec3(float x, float y, float z) : e { {x}, {y}, {z} } {}

	const float& x() const { return e[0]; }
	float& x() { return e[0]; }
	const float& y() const { return e[1]; }
	float& y() { return e[1]; }
	const float& z() const { return e[2]; }	
	float& z() { return e[2]; }
};

vec3 vec3_add2(const vec3& a, const vec3& b)
{
    //return vec3{a.x+b.x, a.y+b.y, a.z+b.z};
    return vec3{a.x()+b.x(), a.y()+b.y(), a.z()+b.z()};
}



// named union with constructor
class cvec3
{
public:
	union ue
    {
		ue(float x, float y, float z) : e { {x}, {y}, {z} } {}
		~ue() {}
		struct { float x, y, z; };
		float e[3];
    } u;

	constexpr int size() const { return 3; }	

	cvec3() = default;
	//cvec3() : u(scast<float>(0), scast<float>(0), scast<float>(0)) {}
	explicit cvec3(float f) : u(f, f, f) {}		
	cvec3(float x, float y, float z) : u(x, y, z) {}
	
	const float* data() const				{ return &u.e[0]; }
	float* data()							{ return &u.e[0]; }
	const float& operator[] (int i) const	{ return u.e[i]; }
    float& operator [] (int i)				{ return u.e[i]; }
};

//---
class cvec3
{
public:

	union
    {
		struct { float x, y, z; };
		float e[3];
    };	

	constexpr int size() const { return 3; }	

	cvec3() = default;
	//cvec3() : e { {scast<float>(0)}, {scast<float>(0)}, {scast<float>(0)} } {}
	explicit cvec3(float f) : e { {f}, {f}, {f} } {}	
	cvec3(float x, float y, float z) : e { {x}, {y}, {z} } {}	
	
	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator[] (int i) const	{ return e[i]; }
    float& operator [] (int i)				{ return e[i]; }
};

cvec3 cvec3_add2(const cvec3& a, const cvec3& b)
{
    return cvec3{a.x+b.x, a.y+b.y, a.z+b.z};
    //return cvec3{a.x()+b.x(), a.y()+b.y(), a.z()+b.z()};
	//return cvec3{a.u.x+b.u.x, a.u.y+b.u.y, a.u.z+b.u.z};
}

//a(0, 0) * tb[0] + a(0, 1) * tb[1] + a(0, 2) * tb[2] + a(0, 3) * tb[3];

// Reset fixed format in cout
//----------------------------------------
//vec3(const base& v) : x(v.x), y(v.y), z(v.z) {}	//makes class non-pod

template <>
struct std::formatter<gm::vec3> : std::formatter<std::string> {
  auto format(gm::vec3 a, std::format_context& ctx) {
    return std::formatter<std::string>::format(
      std::format("{:.6f}, {:.6f}, {:.6f}", a[0], a[1], a[2]), ctx);
  }
}

inline friend std::ostream& operator << ( std::ostream& o, const base& v ) 
{
	std::streamsize ss = std::cout.precision();
	std::cout << std::setprecision(3) << std::fixed;
	o << v.x << qcs << v.y << qcs << v.z;	
	std::cout << std::defaultfloat;
	std::cout.precision(ss);
	return o;
}

inline friend std::ostream& operator << ( std::ostream& o, const base& v ) 
{
	std::ostringstream os;
	os << std::setprecision(float_precision) << std::fixed;
	//forloopi(i, size()) { os << v.e[i] << qcs; }
	forloopi(i, size()) { os << (*this)[i] << qcs; }	
	o << os.str();
	return o;
}


inline void vec3_copy(vec3& dest, const vec3& src)
{
	//memcpy(&dest, &src, sizeof(float) * vec3::size());
	//std::copy(src.e, src.e + vec3::size(), dest.e);
	std::copy(std::begin(src.e), std::end(src.e), std::begin(dest.e));
}

//vec3_compare
//(x != v.x || y != v.y || z != v.z);	//equals
//(x == v.x && y == v.y && z == v.z);	//not_equals

//static_assert(sizeof (vec3) == sizeof (float) * 3, "vec3 float struct size = 3 float array size")
// x, y, z struct to array index return
operator float * ()				{ return (float*) &e[0]; }
operator const float * () const	{ return (const float*) &e[0]; }

float& operator [] (int i)		{ return e[i]; }
float operator [] (int i) const	{ return e[i]; }
float operator[] (int i) const	{ return (&x)[i]; }
float& operator[] (int i)			{ return (&x)[i]; }
//(&this->x)[i];
//*(&x+i);
const T& operator[] (int i) const	{ return (&x)[i]; }
T& operator [] (int i)				{ return (&x)[i]; }

const T* data() const				{ return scast<const T*>(&e[0]); }
T* data()							{ return scast<T*>(&e[0]); }
const T* data() const				{ return &e[0]; }
T* data()							{ return &e[0]; }
float* data()				{ return (float*) &e[0]; }
const float* data() const	{ return (const float*) &e[0]; }
const float *data( void ) const { return &x; }
const float *data( void ) { return &x; }

//=====================================================
void vec2_add( int* out, const int a, const int b )
{
	*out = a + b;
}

int a=5, b=3, c=0;
vec2_add(&c, a, b);
gout << c << QEL << sdf;

void vec2_add( int& out, const int a, const int b )
{
	out = a + b;
}
vec2_add(c, a, b);


//--------------------------------
gm::vec3 a, b;
a = {1.0f, 2.0f, 3.0f};
b = {2.0f, 3.0f, 4.0f};
//gout << a << QEL << b << QEL << sdf;
//a = b;

gm::vec3 *pa, *pb;
// without malloc program will crash
pa = (gm::vec3*)malloc(sizeof(gm::vec3));
pb = (gm::vec3*)malloc(sizeof(gm::vec3));	
*pa = a; *pb = b;
gout << *pa << QEL << sdf;
memcpy(pa, pb, sizeof(gm::vec3));
gout << *pa << QEL << sdf;


//-----------------------------------
//============================================================
// <MAT4>
//============================================================
class mat4
{
public:
	union
    {
		// input matrix values in row major form like
		// { m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33 }
		//struct 
		//{ 
		//	float m00, m01, m02, m03,
		//		 m10, m11, m12, m13,
		//		 m20, m21, m22, m23,
		//		 m30, m31, m32, m33;
		//};

		float e[16];

		float r[4][4];
	};

	constexpr int size() const	{ return 16; }	
	constexpr int dim() const	{ return 4; }	

	mat4() = default;

	//mat4()  :
	//	m00(scast<float>(0)),	m01(scast<float>(0)),	m02(scast<float>(0)),	m03(scast<float>(0)),
	//	m10(scast<float>(0)),	m11(scast<float>(0)),	m12(scast<float>(0)),	m13(scast<float>(0)),
	//	m20(scast<float>(0)),	m21(scast<float>(0)),	m22(scast<float>(0)),	m23(scast<float>(0)),
	//	m30(scast<float>(0)),	m31(scast<float>(0)),	m32(scast<float>(0)),	m33(scast<float>(0)) {}

	// can make identity by: mat4 a(1.0f);
	explicit mat4(float f) : e { {f}, {f}, {f}, {f},
								 {f}, {f}, {f}, {f},
								 {f}, {f}, {f}, {f},
								 {f}, {f}, {f}, {f}, } {}
		//m00(f),					m01(scast<float>(0)),	m02(scast<float>(0)),	m03(scast<float>(0)),
		//m10(scast<float>(0)),	m11(f),					m12(scast<float>(0)),	m13(scast<float>(0)),
		//m20(scast<float>(0)),	m21(scast<float>(0)),	m22(f),					m23(scast<float>(0)),
		//m30(scast<float>(0)),	m31(scast<float>(0)),	m32(scast<float>(0)),	m33(f) {}

	mat4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33) 
		:   
		e { {m00}, {m01}, {m02}, {m03},
			{m10}, {m11}, {m12}, {m13},
			{m20}, {m21}, {m22}, {m23},
			{m30}, {m31}, {m32}, {m33}, } {}
		
		//m00(m00), m01(m01), m02(m02), m03(m03), m10(m10), m11(m11), m12(m12), m13(m13), m20(m20), m21(m21), m22(m22), m23(m23), m30(m30), m31(m31), m32(m32), m33(m33) {}	
};


// Convert Direct3D projection to OpenGL 
glMatrixMode(GL_PROJECTION); 
glLoadMatrixf(&d3d_projection_matrix); 
glScalef(1, 1, 2); 
glTranslatef(0, 0, -1);

//=================================================================
// Display/print a GLM mat or vec 
#include <glm/gtx/string_cast.hpp>
glm::mat4 mat;
std::cout << glm::to_string(mat) << std::endl;

// Access/dereference glm::mat4 contents 
#include <glm/gtc/type_ptr.hpp>
glm::mat4 m = glm::mat4(1.0f);
auto p = glm::value_ptr(m);
std::cout << sizeof(p) << std::endl;
glUniformMatrix4fv(shader_uniform_m, 1, GL_FALSE, p);

//=================================================================
//A trivial type is a type whose storage is contiguous (trivially copyable) and which only supports static default initialization 
//(trivially default constructible), either cv-qualified or not. It includes scalar types, trivial classes and arrays of any such types.
//A trivial class is a class (defined with class, struct or union) that is both trivially default constructible and trivially copyable, which implies that:
//uses the implicitly defined default, copy and move constructors, copy and move assignments, and destructor. 
//has no virtual members.
//has no non-static data members with brace- or equal- initializers.
//its base class and non-static data members (if any) are themselves also trivial types.
// is_trivially_default_constructible: static default initialization (dynamic allocation compiler specific, use memset_zero or calloc on memory block)
// is_trivially_copyable: can do memcpy
// is_trivial: is_trivially_default_constructible & is_trivially_copyable (like POD)
// is_standard_layout: equal to C struct in memory layout
// is_pod: is_trivial & is_standard_layout //deprecated in C++ 20
#include <type_traits>
gout << "gm::vec3 is is_trivially_default_constructible: " << std::is_trivially_default_constructible<gm::vec3>::value << sdf;
gout << "gm::vec3 is is_trivially_copyable: " << std::is_trivially_copyable<gm::vec3>::value << sdf;
gout << "gm::vec3 is is_trivial: " << std::is_trivial<gm::vec3>::value << sdf;
gout << "gm::vec3 is is_standard_layout: " << std::is_standard_layout<gm::vec3>::value << sdf;
gout << "gm::vec3 is is_pod: " << std::is_pod<gm::vec3>::value << sdf;
//vec3f fa(1.0, 2.0, 3.0);
//vec3f fb(1.0, 2.0, 4.0);
//gout << "fa != fb: " <<  (fa != fb) << QEL << sdf;

//gm::vec2 a, b, c;
//a = {1.0, 2.0}; b = {5.0, 6.0};
//gm::vec2_add(c, a, b);
//gout << "vec2_add: " << c << QEL << sdf;
//gout << gm::k_vec2_zero<float> << QEL << sdf;

glm::vec3 gv3a(2.0f, 3.0f, 4.0f);
glm::vec3 gv3b(3.0f, 4.0f, 5.0f);
glm::vec3 gv3c(6.0f, 7.0f, 8.0f);
glm::vec4 gv4a(1, 2, 3, 4);
glm::mat4 gma(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16); 	
glm::mat4 gmb(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17); 
//glm::mat4 ga(1.0f);
//gout << "glm: m4*m4 \n" << gma * gmb << QEL << QEL << sdf;
//gout << "glm: transpose \n" << glm::transpose(gma) << QEL << sdf;
//gout << "glm: m4*v4 \n" << gma * gv4a << QEL << QEL << sdf;
//gout << "glm: v4*m4 \n" << gv4a * gma << QEL << QEL << sdf;
//gout << "glm: translate \n" << glm::translate(gma, gv3a) << QEL << QEL << sdf;
//gout << "glm: scale \n" << glm::scale(gma, gv3a) << QEL << QEL << sdf;
//gout << "glm: rotate \n" << glm::rotate( gma, glm::radians(45.0f), gv3a ) << QEL << QEL << sdf;
//gout << "glm: lookAtLH \n" << glm::lookAtLH(gv3a, gv3b, gv3c) << QEL << QEL << sdf;
//gout << "glm: lookAtRH \n" << glm::lookAtRH(gv3a, gv3b, gv3c) << QEL << QEL << sdf;
//gout << "glm: perspectiveRH_ZO \n" << glm::perspectiveRH_ZO(0.79f, 1.77f, 3.0f, 4.0f) << QEL << QEL << sdf;
//gout << "glm: perspectiveRH_NO \n" << glm::perspectiveRH_NO(0.79f, 1.77f, 3.0f, 4.0f) << QEL << QEL << sdf;
//gout << "glm: perspectiveLH_ZO \n" << glm::perspectiveLH_ZO(0.79f, 1.77f, 3.0f, 4.0f) << QEL << QEL << sdf;
//gout << "glm: perspectiveLH_NO \n" << glm::perspectiveLH_NO(0.79f, 1.77f, 3.0f, 4.0f) << QEL << QEL << sdf;



//gm::vec3 v3a = {2.0f, 3.0f, 4.0f};
//gm::vec3 v3b = {3.0f, 4.0f, 5.0f};
//gm::vec3 v3c = {6.0f, 7.0f, 8.0f};
//gm::vec4 v4a = {1, 2, 3, 4};
//gm::mat4 ma = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}; 	
//gm::mat4 mb = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
//gm::mat4 ma = {
//	1, 5, 9, 13, 
//	2, 6, 10, 14, 
//	3, 7, 11, 15, 
//	4, 8, 12, 16}; 	
//gm::mat4 mb = {
//	2, 6, 10, 14, 
//	3, 7, 11, 15, 
//	4, 8, 12, 16, 
//	5, 9, 13, 17};
//gm::mat4 mc;
//gm::mat4_mul(mc, ma, mb);
//gout << "gm: m4*m4 \n" << mc << QEL << QEL << sdf;
//gm::mat4_transpose(ma, ma);
//gout << "gm: transpose \n" << ma << QEL << sdf;
//gm::vec4 v4c;
//gm::mat4_mul_vec4(v4c, ma, v4a);
//gout << "gm: m4*v4 \n" << v4c << QEL << QEL << sdf;
//gm::vec4_mul_mat4(v4c, v4a, ma);
//gout << "gm: v4*m4 \n" << v4c << QEL << QEL << sdf;
//gm::mat4 md;	
//gm::mat4_translate(md, ma, v3a);
//gout << "gm: translate \n" << md << QEL << QEL << sdf;
//gm::mat4_scale(md, ma, v3a);
//gout << "gm: scale \n" << md << QEL << QEL << sdf;
//gm::mat4_rotate(md, ma, mf::deg_to_rad(45.0f), v3a );
//gout << "gm: rotate \n" << md << QEL << QEL << sdf;
//gm::mat4_look_at_lh(md, v3a, v3b, v3c);
//gout << "gm: mat4_look_at_lh \n" << md << QEL << QEL << sdf;
//gm::mat4_look_at_rh(md, v3a, v3b, v3c);
//gout << "gm: mat4_look_at_rh \n" << md << QEL << QEL << sdf;
//gm::perspective_rh_zo(md, 0.79f, 1.77f, 3.0f, 4.0f);
//gout << "gm: perspective_rh_zo \n" << md << QEL << QEL << sdf;
//gm::perspective_rh_no(md, 0.79f, 1.77f, 3.0f, 4.0f);
//gout << "gm: perspective_rh_no \n" << md << QEL << QEL << sdf;
//gm::perspective_lh_zo(md, 0.79f, 1.77f, 3.0f, 4.0f);
//gout << "gm: perspective_lh_zo \n" << md << QEL << QEL << sdf;
//gm::perspective_lh_no(md, 0.79f, 1.77f, 3.0f, 4.0f);
//gout << "gm: perspective_lh_no \n" << md << QEL << QEL << sdf;
gprintf("----------------------------------------------\n");
//=================================================================






//===========================================================
// <SCRIPTING>
//===========================================================
//-------------------------------------------
	// gamemonkey script
	gmMachine machine;
	//machine.ExecuteString("print(\"Hello world\");");
	//machine.ExecuteString("print(`Hello world`);");	// using backquote character
	//const int MAX_SCRIPT_SIZE = 4096;
	//char gms1[MAX_SCRIPT_SIZE];
	//std::strcpy(gms1, R"(print(`Hello world`);)");
	machine.ExecuteString(gms1);
	//getchar(); // Keypress before exit
//=================================================================
// raw strings
// In C++, to escape characters like “\n” we use an extra “\”. From C++ 11, we can use raw strings in which escape characters 
// (like \n \t or \” ) are not processed. The syntax of raw string is that the literal starts with R”( and ends in )”.
// A Normal string 
string string1 = "Geeks.\nFor.\nGeeks.\n" ;  
// output
Geeks.
For.
Geeks.
// A Raw string 
string string2 = R"(Geeks.\nFor.\nGeeks.\n)";  
// output
Geeks.\nFor.\nGeeks.\n

//------------------------------
// Load the entire script file into a string buffer
void LoadScriptFile(const char *fileName, string &script)
{
  // Open the file in binary mode
  FILE *f = fopen("test.as", "rb");
  
  // Determine the size of the file
  fseek(f, 0, SEEK_END);
  int len = ftell(f);
  fseek(f, 0, SEEK_SET);
  
  // Load the entire file in one call
  script.resize(len);
  fread(&script[0], len, 1, f);
  
  fclose(f);
} 





//============================================================
// <MISC>
//============================================================
unsigned int for loops:
The motivation for using an unsigned type as index or size in the standard is based on constraints only relevant to 16 bit machines. The natural type for any integral type in C++ is int, and that's what should probably be used; as you've noticed, trying to use unsigned types as numerical values in C++ is fraught with problems. If you're worried about the sizes being so big that they don't fit into an int, ptrdiff_t would be appropriate; this is, after all, the type of the results of subtraction of pointers or iterators. (The fact that v.size() has a different type than v.end() - v.begin() is really a design flaw in the standard library.)


unsigned semantic in C and C++ doesn't really mean "not negative" but it's more like "bitmask" or "modulo integer".
To understand why unsigned is not a good type for a "non-negative" number please consider
. Adding a possibly negative integer to a non-negative integer you get a non-negative integer
. The difference of two non-negative integers is always a non-negative integer
. Multiplying a non-negative integer by a negative integer you get a non-negative result
Obviously none of the above phrases make any sense... but it's how C and C++ unsigned semantic indeed works.
Actually using an unsigned type for the size of containers is a design mistake of C++ and unfortunately we're now doomed to use this wrong choice forever (for backward compatibility). You may like the name "unsigned" because it's similar to "non-negative" but the name is irrelevant and what counts is the semantic... and unsigned is very far from "non-negative".
For this reason when coding most loops on vectors my personally preferred form is:
for (int i=0,n=v.size(); i<n; i++) 
{
    //...
}
This running away from unsigned as soon as possible and using plain integers has the advantage of avoiding the traps that are a consequence of unsigned size_t design mistake. For example consider:
// draw lines connecting the dots
for (size_t i=0; i<pts.size()-1; i++) {
    drawLine(pts[i], pts[i+1]);
}
the code above will have problems if the pts vector is empty because pts.size()-1 is a huge nonsense number in that case. Dealing with expressions where a < b-1 is not the same as a+1 < b even for commonly used values.
Historically the justification for having size_t unsigned is for being able to use the extra bit for the values, e.g. being able to have 65535 elements in arrays instead of just 32767 on 16-bit platforms. In my opinion even at that time the extra cost of this wrong semantic choice was not worth the gain (and if 32767 elements are not enough now then 65535 won't be enough for long anyway).
Unsigned values are great and very useful, but NOT for representing container size or for indexes; for size and index regular signed integers work much better because the semantic is what you would expect.
Unsigned values are the ideal type when you need the modulo arithmetic property or when you want to work at the bit level.

//---
// Speaking of for-loops with size_t in reverse, there is a coding guideline in the style of 
for (size_t revind = 0u; revind < n; ++revind) 
{ 
	size_t ind = n - 1u - revind; 
	func(ind); 
}
//---

for (size_t i = v.size(); i-- > 0; )
{
    std::cout << v[i] << std::endl;
}

size_t i = v.size();
while (i > 0)
{
    --i;
    std::cout << v[i] << std::endl;
}


//=======================================================================================
// single .h, .cpp implementation
int sum(int a, int b)
#if CPP_IMPL
{
    return a+b;
}
#else 
;
#endif

//=======================================================================================
// OpenBSD math defines
/*
 * XOPEN/SVID
 */
#if __BSD_VISIBLE || __XPG_VISIBLE
#define	M_E			((double)2.7182818284590452354)  /* e */
#define	M_LOG2E		((double)1.4426950408889634074)  /* log 2e */
#define	M_LOG10E	((double)0.43429448190325182765) /* log 10e */
#define	M_LN2		((double)0.69314718055994530942) /* log e2 */
#define	M_LN10		((double)2.30258509299404568402) /* log e10 */
#define	M_PI		((double)3.14159265358979323846) /* pi */
#define	M_PI_2		((double)1.57079632679489661923) /* pi/2 */
#define	M_PI_4		((double)0.78539816339744830962) /* pi/4 */
#define	M_1_PI		((double)0.31830988618379067154) /* 1/pi */
#define	M_2_PI		((double)0.63661977236758134308) /* 2/pi */
#define	M_2_SQRTPI	((double)1.12837916709551257390) /* 2/sqrt(pi) */
#define	M_SQRT2		((double)1.41421356237309504880) /* sqrt(2) */
#define	M_SQRT1_2	((double)0.70710678118654752440) /* 1/sqrt(2) */
#endif /* __BSD_VISIBLE || __XPG_VISIBLE */
#if __POSIX_VISIBLE >= 201403
#define	M_El		2.718281828459045235360287471352662498L /* e */
#define	M_LOG2El	1.442695040888963407359924681001892137L /* log 2e */
#define	M_LOG10El	0.434294481903251827651128918916605082L /* log 10e */
#define	M_LN2l		0.693147180559945309417232121458176568L /* log e2 */
#define	M_LN10l		2.302585092994045684017991454684364208L /* log e10 */
#define	M_PIl		3.141592653589793238462643383279502884L /* pi */
#define	M_PI_2l		1.570796326794896619231321691639751442L /* pi/2 */
#define	M_PI_4l		0.785398163397448309615660845819875721L /* pi/4 */
#define	M_1_PIl		0.318309886183790671537767526745028724L /* 1/pi */
#define	M_2_PIl		0.636619772367581343075535053490057448L /* 2/pi */
#define	M_2_SQRTPIl	1.128379167095512573896158903121545172L /* 2/sqrt(pi) */
#define	M_SQRT2l	1.414213562373095048801688724209698079L /* sqrt(2) */
#define	M_SQRT1_2l	0.707106781186547524400844362104849039L /* 1/sqrt(2) */
#endif /* __POSIX_VISIBLE >= 201403 */
//-------------------------------------------------
//=======================================================================================
// QPC, QueryPerformanceFrequency clock
	LARGE_INTEGER cnts_per_sec;
	QueryPerformanceFrequency(&cnts_per_sec); 
	LARGE_INTEGER prev_time_qpc;
	QueryPerformanceCounter(&prev_time_qpc);
		LARGE_INTEGER curr_time_qpc;
		QueryPerformanceCounter(&curr_time_qpc);
		LARGE_INTEGER delta_micro_sec;
		delta_micro_sec.QuadPart = curr_time_qpc.QuadPart - prev_time_qpc.QuadPart;
		// We now have the elapsed number of ticks, along with the number of ticks-per-second. We use these values
		// to convert to the number of elapsed microseconds.
		// To guard against loss-of-precision, we convert to microseconds *before* dividing by ticks-per-second.
		delta_micro_sec.QuadPart *= 1000000;
		delta_micro_sec.QuadPart /= cnts_per_sec.QuadPart;
		float delta_time_qpc = scast<float>(delta_micro_sec.QuadPart);
		// Activity to be timed
		prev_time_qpc = curr_time_qpc;
//=======================================================================================

// UINT OVERFLOW

// uint, int overflow in loop
    uint8 ubyte_max = 255;
    gout << sdf;
    unsigned __int8 ai = 255;
    gout << unsigned(ai) << sdf;
    //gprintf("%u\n", ai);
    ai++;   //255+1 = 0 (wraps around)
    gout << unsigned(ai) << sdf;

    ai = 0;
    gout << unsigned(ai) << sdf;
    ai--;   //0-1 = 255 (wraps around)
    gout << unsigned(ai) << sdf;

#if 0
    for(uint8 i = 0;;++i) 
    //for( uint8 i = ubyte_max; i-- > 0; )    //less 1
    //for(uint8 i = ubyte_max; i-- > 0;) //less 1
    //for (uint8 i = ubyte_max - 1; i != -1; --i) //inf
    //for (uint8 i = 0; i <= uint8(255); ++i)   //inf
    {
        gout << unsigned(i) << qcs;

        if (i == ubyte_max) break;
    }
    gout << sdf;
#endif

    gout << "\n--------------------------------" << sdf;  
    __int8 ii = 127;
    gout << int(ii) << sdf;
    ii++;   //127+1 = -128 (wraps around)
    gout << int(ii) << sdf;

    ii = -128;
    gout << int(ii) << sdf;
    ii--;   //128-1 = 127 (wraps around)
    gout << int(ii) << sdf;

    int8 byte_max = 127;
    
    for(uint8 i = 0;;++i) 
    //for (int8 i = 0; i <= int8(byte_max) && (i)!=byte_max; ++i)   //inf
    //for (int8 i = 0; i <= int8(byte_max); ++i)   //inf
    {
        gout << int(i) << qcs;

        if (i == byte_max) break;
    }
    gout << sdf;

    gout << sdf;




//=======================================================
// unions
union test 
{ 
	std::string v;
	int x; 
	char y; 
	char str[32];

	~test() {}
};

test t = {"Hello, world"};
  
t.x = 68; // t.y also gets value 2 
gout << "After modifying x: x = " << t.x << ", y = " << t.y << QEL << sdf;
  
t.y = 'f'; // t.x is also updated to 10 
gout << "After modifying y: x = " << t.x << ", y = " << t.y << QEL << sdf;

//strcpy(t.str, "hello");
//strncpy(t.str, "hello", sizeof(t.str));
//sdf::str_copy(t.str, "hello", sizeof(t.str));
sdf::strcpy_safe(t.str, "hello");
gout << t.x << QCS << t.y << QCS << t.str << QEL << sdf;


union S
{
	// need to be 1st member and union needs to be initialized with a string
	std::string str;
	std::vector<int> vec;
	~S() {} // needs to know which member is active, only possible in union-like class 
};

S s = {"Hello, world"};
// at this point, reading from s.vec is undefined behavior
gout << "s.str = " << s.str << '\n' << sdf;
s.str.~basic_string();
new (&s.vec) std::vector<int>;
// now, s.vec is the active member of the union
s.vec.push_back(10);
gout << s.vec.size() << '\n' << sdf;
s.vec.~vector();

//-------------------------
enum 
{
	VAL_INT,
	VAL_FLOAT,
	VAL_BOOL,
	VAL_STR
};

struct CvarData2
{
	int type;
	uint flags;
	std::string name;
	std::string description;

	union u
	{
	public:
		char strval[32];
		int ival; 
		float fval;
		bool bval;
	};
};



//==============================
// function pointers
int add( int a, int b ) { return a + b; }
int (*pfn_add)(int, int);
pfn_add = &add;
pfn_add(5, 6);


//=======================================================
// run time class pointer switching using interface
//Renderer
char rs_api[16];
strcpy(rs_api, "gl2");
//strcpy(rs_api, "d3d9");
//strcpy(rs_api, "gl4");
//std::unique_ptr<IRenderer> renderer;
//renderer = std::make_unique<RendererGL2>();
// Default Renderer
//IRenderer* renderer = nullptr; // q_safe_delete(IRenderer);
std::unique_ptr<IRenderer> renderer = std::make_unique<RendererGL2>();

if (sdf::str_equals_ci(rs_api, "gl2"))
{
    //renderer = new RendererGL2();
    ////renderer = std::unique_ptr<RendererGL2>(new RendererGL2);
    renderer = std::make_unique<RendererGL2>();
}
else if (sdf::str_equals_ci(rs_api, "d3d9"))
{
    //renderer = new RendererD3D9();
    renderer = std::make_unique<RendererD3D9>();
    // D3D9 does its own swap buffers
    //fp_swap_buffers = app_swap_buffers_null;
    nw_app.fp_swap_buffers = app_swap_buffers_null;
}
else if (sdf::str_equals_ci(rs_api, "gl4"))
{
    renderer = std::make_unique<RendererGL4>();
}



//=======================================================================================
// Tagged Union -
// S has one non-static data member (tag), three enumerator members (CHAR, INT, DOUBLE), 
// and three variant members (c, i, d)
struct S
{
    enum{CHAR, INT, DOUBLE} tag;
    union
    {
        char c;
        int i;
        double d;
    };
};
 
void print_s(const S& s)
{
    switch(s.tag)
    {
        case S::CHAR: std::cout << s.c << '\n'; break;
        case S::INT: std::cout << s.i << '\n'; break;
        case S::DOUBLE: std::cout << s.d << '\n'; break;
    }
}
 
int main()
{
    S s = {S::CHAR, 'a'};
    print_s(s);
    s.tag = S::INT;
    s.i = 123;
    print_s(s);
}
//=======================================================================================
// template constants -
template <typename FloatType>
struct default_epsilon
{};

template <>
struct default_epsilon<float>
{
  static const float value = 1.0e-05f;
};

template <>
struct default_epsilon<double>
{
  static const double value = 1.0e-10;
};

template <>
struct default_epsilon<long double>
{
  static const long double value = 1.0e-12l;
};

// Then, I use it like that :
template <typename FloatType>
bool approx(FloatType x1, FloatType x2)
{
  return abs(x2 - x1) < default_epsilon<FloatType>::value;
}
// or that
bool approx(FloatType x1, FloatType x2, FloatType epsilon = default_epsilon<FloatType>::value)
{
  return abs(x2 - x1) < epsilon;
}
//---
#include <cmath>

template <typename FloatType>
struct default_epsilon
{};

template <>
struct default_epsilon<float>
{
    static const float value;
};
template <>
struct default_epsilon<double>
{
    static const double value;
};
template <>
struct default_epsilon<long double>
{
    static const long double value;
};

template <typename FloatType>
bool approx(FloatType x1, FloatType x2)
{
    return std::abs(x2 - x1) < default_epsilon<FloatType>::value;
}
//And somewhere in your .cpp file:

const float default_epsilon<float>::value = 1.0e-05f;
const double default_epsilon<double>::value = 1.0e-10;
const long double default_epsilon<long double>::value = 1.0e-12l;
//---
class MyEpsilon
{
public:
    operator float() {return 1.0e-05f;};
    operator double() { return 1.0e-10; };
    operator long double() { return 1.0e-12l; };
};

template<class T>
class MyTest {
public:
    T DoSome() {
        MyEpsilon e;
        return T(e);
    }
};

//=======================================================================================
// using vs typedef
typedef void (&MyFunc)(int, int);
using MyFunc = void(&)(int,int);
typedef int (*T)(int, int);
using MyFunc = int (*)(int, int); 
// template alias form is not possible with typedef. Exposing C API would require typedef in public headers.
//Using auto will make defining a pointer to this function much simpler:
auto pfun = find_maximum;
//You could also use auto* to highlight the fact that pfun is a pointer:
auto* pfun = find_maximum;
pfun = find_minimum;


//=======================================================
// bare name of an array is a const pointer to the first element. 
// A function name used without parenthesis is a pointer to a function.
// function prototype 
//int func(int, int);
// func definition goes here
int sum( int a, int b ) { return (a + b); }
int diff( int a, int b ) { return (a - b); }

//int (*pfnt_mathop)( int, int ) = &sum; 
//int (*pfnt_mathop)( int, int );

typedef int (*pfnt_mathop)(int, int);
pfnt_mathop pfn_sum = &sum;
//pfnt_mathop pfn_diff = &diff;

int main()
{
	int result1, result2, result3;
    // calling function named sum
    result1 = sum(10,20);       
    //gprintf("result1 = %d\n",result1);

	//pfnt_mathop = &sum;
	//pfnt_mathop = sum;	// also works but better write clearly

	// calling func() through explicit dereference 
    //result2 = (*pfnt_mathop)(10,20); 
	result2 = (*pfn_sum)(10,20); 
	//gprintf("result2 = %d\n",result2);
 
    // calling func() through implicit dereference        
    //result3 = pfnt_mathop(10,20);          
	result3 = pfn_sum(10,20);  
    //gprintf("result3 = %d\n",result3);

    return 0;
}


//=================================================================
enum class Error 
{ 
    k_success, 
    k_fileDoesNotExist, 
    k_badPermissions 
};
struct Result 
{ 
    Error m_error;
    Optional<std::string> m_contents;
};
Result readFile();

//-------------------------------
//Copy constructor is called when a new object is created from an existing object, as a copy of the existing object. 
//And assignment operator is called when an already initialized object is assigned a new value from another existing object.
//Example-
t2 = t1;  // calls assignment operator, same as "t2.operator=(t1);"
Test t3 = t1;  // calls copy constructor, same as "Test t3(t1);"




//============================================================
// <STL>
//============================================================

// Reset all elements to zero
template<class T>
static void setValue(T arr[], size_t length, const T& val)
{
    std::fill(arr, arr + length, val);
}

template<class T, size_t N>
static void setValue(T (&arr)[N], const T& val)
{
    std::fill(arr, arr + N, val);
}

// You can call it like this:

//fixed arrays
int a[10];
setValue(a, 0);



//----------------------------------------
// Iterating Forwards in std collections
//----------------------------------------

// This is almost identical. Just change the iterators / swap decrement by increment. You should prefer iterators. 
// Some people tell you to use std::size_t as the index variable type. However, that is not portable. 
// Always use the size_type typedef of the container (While you could get away with only a conversion in the forward iterating case, 
// it could actually go wrong all the way in the backward iterating case when using std::size_t, 
// in case std::size_t is wider than what is the typedef of size_type):

// Using std::vector
//-----------------------
// Using iterators

for(std::vector<T>::iterator it = v.begin(); it != v.end(); ++it) 
{
    // std::cout << *it;
}

// Important is, always use the prefix increment form for iterators whose definitions you don't know. That will ensure your code runs as generic as possible.
// Using Range C++11

for(auto const& value: a) 
{
     // std::cout << value;
}

// Using indices

for(std::vector<int>::size_type i = 0; i != v.size(); i++)
{
    // std::cout << v[i];
}

// Using arrays
//-----------------------
// Using iterators

for(element_type* it = a; it != (a + (sizeof a / sizeof *a)); it++)
{
    // std::cout << *it;
}

// Using Range C++11

for(auto const& value: a) 
{
     // std::cout << value;
}

// Using indices

for(std::size_t i = 0; i != (sizeof a / sizeof *a); i++)
{
    // std::cout << a[i]; 
}

// Read in the backward iterating answer what problem the sizeof approach can yield to, though.

// Counted Iterators
std::vector<int> b(20);
for_range (i, 0, b.size()) { b[i] = i+1; }
//for_range (i, 0, b.size()) { print("{}, ", b[i]); } print("\n");
//for (std::vector<int>::iterator it = b.begin() ; it != b.end(); ++it) {
//    print("{}, ", *it);
//}
for (auto it = std::counted_iterator{std::cbegin(b), (int)b.size()}; it != std::default_sentinel; ++it) {
    print("{}, ", *it);
}
print("\n");
//----------------------------------
// removing a element in std::vector by swap and pop
std::swap(objects[index], objects.back());
objects.pop_back();


//----------------------------------
// The std::vector can always grow dynamically, but there are two ways you can allocate an initial size:

// This allocates initial size and fills the elements with zeroes:
std::vector<int> v(10);
v.size(); //returns 10

// This allocates an initial size but does not populate the array with zeroes:
std::vector<int> v;
v.reserve(10);
v.size(); //returns 0

//-------------------
// Fixed Size vector
int n = 100;
// equal to resize(105)
std::vector<int> v(n);
gout << v.size() << QEL << sdf;

v.at(25) = 30;
v[50] = 25;

gout << v.at(24) << QCS << v[25] << QCS << v.at(50) << QEL << sdf;
	
// unhandled exception crashes the program
//gout << v.at(105) << QEL << sdf;

try 
{
	gout << v.at(105) << QEL << sdf;      // vector::at throws an out-of-range
}
catch (const std::out_of_range& oor) 
{
	gout << "Out of Range error: " << oor.what() << '\n' << sdf;
}


std::vector<int> vec1;
vec1.reserve(30);  // Allocate space for 30 items, but vec1 is still empty.

std::vector<int> vec2;
vec2.resize(30);  // Allocate space for 30 items, and vec2 now contains 30 items.

// equal to resize(50)
std::string a("HI", 50);
a.reserve(50);
a.resize(50);

//---------------------------------------
// If you want n elements identical, try this:

std::vector<T> v(n, t);  // creates n copies of the value t.
v.reserve(desired_capacity);

// If you don't want to specify an initial value, you can omit that:

std::vector<T> v(n);     // creates n copies of T, default constructed.
v.reserve(desired_capacity);

// If you have a certain number of elements you want to specify individually, try an initializer list.

std::vector({t1, t2, ..., tn});  // initializer list
v.reserve(desired_capacity);

// The list of possibilities goes on; for more, see the vector::vector reference.
// Using "in-place" construction means you can populate a vector with types that are not copy-constructible.
// Another option, to fill a vector with non-copyable types, is to use emplace_back repeatedly:
std::vector<T> v;
v.reserve(n); 
for (int i = 0; i < n; ++i)
{
   v.emplace_back(x, y, z);  // Construct T(x, y, z) in-place
}

//-------------------------
/*
push_back()

Each push_back() copy-constructs an element in the vector from the argument to the push_back() call. If the vector size() == capacity(), 
a reallocation will be performed. This will usually (but may not always) double the capacity, and may result in copying all of the existing elements into new storage.
push_back() with pre-allocation

Using reserve() allocates enough memory for the elements before we start. It's always worth doing this if you know (or have a reasonable guess for) the number of elements.
The push_back() call will still use the copy constructor of the element type, but there shouldn't be any allocations, because the space is already provided.

indexing and element assignment

Here, we create a vector of the correct number of default-constructed elements, and then use the copy-assignment operator to replace them with the elements we want. 
This has only one allocation, but can be slow if copy-assignment does anything complicated.

emplace_back()

emplace_back() constructs the element in-place with the arguments to the emplace_back() call. This can often be faster than the equivalent push_back() (but not always). 
It still allocates in the same pattern as push_back(), reserving some capacity, filling it, then reallocating when more is needed.

emplace_back() with pre-allocation

This should be your go-to strategy for C++11 or later codebases. You gain the emplace_back() efficiency (where possible) and avoid repeated allocations. 
Of the mechanisms listed, this would be expected to be the fastest in most cases.

vector of strings 
push_back requires extra reallocations each time capacity is exceeded. So option 2 can be improved by reserving enough space to avoid reallocations. 
It is also more efficient to directly push the string than to push an empty one and later on reassign. And there is a constructor for std::string which 
is very convenient for your needs : from sequence (5) string (const char* s, size_t n);

Regarding option 1: Preallocating the whole vector requires each element to be constructed once for initialization and yet another time for assignment. 
Better to reserve without constructing elements and directly push_back the ones you really want. 

void myfnc_1(void *a_src, uint32_t a_segment)
{
    std::vector<std::string> values;
    size_t nSize = GetSize( );
    values.reserve(nSize);
    char* v = static_cast<char*> ( a_src );

    for (size_t i = 0; i < nSize; ++i)
    {
        values.push_back( std::string( v, a_segment) );
        v += a_segment;
    }
}

*/

//-----------------------
std::vector<int> a;
// allocate space without calling constructors
a.reserve(60);
// allocate space with calling constructors
a.resize(60);
a[55] = 55;
// resize
//gout << a[55] << QEL << sdf;
//for (auto val: a)
//{
//	gout << val << QCS << sdf;
//}

// can use loop only till capacity for reserve as size is 0 till now, which can be increased
// by resize or push_back only
for (int i = 0; i < a.capacity(); i++)
{
	gout << a[i] << QCS << sdf;
}

gout << QEL << sdf;

gout << a.size() << QCS << a.capacity() << QEL << sdf;


// fill all elements with 0
std::fill(v.begin(), v.end(), 0);

//memcpy vector to arrray
// memcpy C array to pointer
//memcpy(vertices, cube_vert, sizeof(cube_vert));   
// copy C array
//std::copy(std::begin(src), std::end(src), std::begin(dest));
// std::copy(source.begin(), source.end(), destination);
//std::vector<ValueType> vec(a, a + n);


//std::copy(vecarr.begin(), vecarr.end(), vertices);
//std::copy(std::begin(vecarr), std::end(vecarr), vertices);
//std::ranges::copy(vecarr, vertices);
//sdf::copyarr(vertices, vecarr);

//d3d9b_copy_array_vertex(vertices, triangle1);
//std::copy(std::begin(cube_vert), std::end(cube_vert), std::begin(vertices)); // not working
//memcpy(vertices, triangle1.data(), sizeof(triangle1.data()));   // not working
//memcpy(vertices, &triangle1[0], sizeof(&triangle1[0]));   // not working
//std::copy(triangle1.begin(), triangle1.end(), vertices);  // not working

//---------------------
vector<int> dataVec;

int dataArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
unsigned dataArraySize = sizeof(dataArray) / sizeof(int);

// Method 1: Copy the array to the vector using back_inserter.
{
    copy(&dataArray[0], &dataArray[dataArraySize], back_inserter(dataVec));
}

// Method 2: Same as 1 but pre-extend the vector by the size of the array using reserve
{
    dataVec.reserve(dataVec.size() + dataArraySize);
    copy(&dataArray[0], &dataArray[dataArraySize], back_inserter(dataVec));
}

// Method 3: Memcpy
{
    dataVec.resize(dataVec.size() + dataArraySize);
    memcpy(&dataVec[dataVec.size() - dataArraySize], &dataArray[0], dataArraySize * sizeof(int));
}

// Method 4: vector::insert
{
    dataVec.insert(dataVec.end(), &dataArray[0], &dataArray[dataArraySize]);
}

// Method 5: vector + vector
{
    vector<int> dataVec2(&dataArray[0], &dataArray[dataArraySize]);
    dataVec.insert(dataVec.end(), dataVec2.begin(), dataVec2.end());
}

//-------------
std::vector<int> data; // evil global 
void CopyData(int *newData, size_t count)
{
   data.assign(newData, newData + count);
}

int foo(int* data, int size)
{
   static std::vector<int> my_data; //normally a class variable
   std::copy(data, data + size, std::back_inserter(my_data));
   return 0;
}

vector<int> x(size);
memcpy(&x[0], source, size*sizeof(int));


//----------
int dataArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//source
unsigned dataArraySize = sizeof(dataArray) / sizeof(int);
std::vector<int> myvector (dataArraySize );//target
std::copy ( myints, myints+dataArraySize , myvector.begin() );
//myvector now has 1,2,3,...10 :-)


//---------------
//you can use vectors in place of arrays, right? Even when a function expects c-style arrays you can use vectors:
vector<char> v(50); // Ensure there's enough space
strcpy(&v[0], "prefer vectors to c arrays");
//=======================================================================================
int* cvar_get_int_ref( const std::string& name, const std::string& default_value )
{
	auto kv = g_cvar_list.find(name);
	if ( kv != g_cvar_list.end() )
	{
		return &kv->second.u.ival;
	}

	cvar_insert(name, default_value, CvarType::intval );
	return cvar_get_int_ref(name, default_value);
}

// linking cvars to pointers
int* rs_width = cvar_get_int_ref("rs_width", "640");
gout << "rs_width_pointer: " << *rs_width << QEL << sdf;
*rs_width = 750;
cvar_print_details("rs_width");
cvar_set("rs_width", "760");
gout << "rs_width_pointer: " << *rs_width << QEL << sdf;
// if cvar rs_width is now deleted *rs_width will now point to wrong memory location
// better update cvar by cvar functions only
//=======================================================================================

template <class T> bool IsInVector(T what, std::vector<T> * vec)
{
    if(std::find(vec->begin(),vec->end(),what)!=vec->end())
        return true;
    return false;
}


#include <algorithm>
{
if ( std::find(vector.begin(), vector.end(), item) != vector.end() )
   do_this();
else
   do_that();
}


//=================================================================
std::vector<double> v{ 1.0, 2.2, 4.0, 5.5, 7.2 };
double r = 4.0;
std::for_each(v.begin(), v.end(), [&](double & v) { v += r; });
std::for_each(v.begin(), v.end(), [](double v) { std::cout << v << " "; });

//=================================================================
// FUNCTIONS
//=================================================================
// Get environment variable
printf("PATH : %s\n", getenv("PATH"));
printf("HOME : %s\n", getenv("HOME"));
printf("ROOT : %s\n", getenv("ROOT"));



//=================================================================
// ENUM STYLES
//=================================================================
// UE4
enum EHlslccBackend {
	HB_Glsl,
	HB_Metal,
	HB_Invalid,
};
enum class EFontImportFlags {
	None = 0x0,						// No flags
	EnableAntialiasing = 0x1,		// Whether the font should be antialiased or not.  Usually you should leave this enabled.
	EnableBold = 0x2,				// Whether the font should be generated in bold or not
	EnableItalic = 0x4,				// Whether the font should be generated in italics or not
	EnableUnderline = 0x8,			// Whether the font should be generated with an underline or not
	AlphaOnly = 0x10,				// Forces PF_G8 and only maintains Alpha value and discards color
	CreatePrintableOnly = 0x20,		// Skips generation of glyphs for any characters that are not considered 'printable'
	IncludeASCIIRange = 0x40,		// When specifying a range of characters and this is enabled, forces ASCII characters (0 thru 255) to be included as well
	EnableDropShadow = 0x80,		// Enables a very simple, 1-pixel, black colored drop shadow for the generated font
	EnableLegacyMode = 0x100,		// Enables legacy font import mode.  This results in lower quality antialiasing and larger glyph bounds, but may be useful when debugging problems
	UseDistanceFieldAlpha = 0x200	// Alpha channel of the font textures will store a distance field instead of a color mask
};

enum class EMediaStates {
	Closed,
	Error,
	Paused,
	Playing,
	Stopped
};

