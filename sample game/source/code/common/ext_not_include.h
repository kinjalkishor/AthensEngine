//============================================================
// <GENERAL>
//============================================================

// Project Properties -C/C++ -Preprocessor
// NDEBUG;_WINDOWS;%(PreprocessorDefinitions)

//=============================================================
// Win Main cpp compile settings -
//#if _MSC_VER
//	#pragma comment( linker, "/subsystem:windows" )
//#endif
//----------------
// ProjectSettings preprocessor
//_CRT_SECURE_NO_WARNINGS
//_CRT_NONSTDC_NO_DEPRECATE
//NOMINMAX
//----------------
//clang win_basic.c -luser32 -lgdi32 -owin_basic_msvc.exe
//clang -target x86_64-pc-windows-gnu win_basic.c -luser32 -lgdi32 -owin_basic_mingw64.exe
//----------------
//kernel32.lib
//user32.lib
//gdi32.lib
//winspool.lib
//comdlg32.lib
//advapi32.lib
//shell32.lib
//ole32.lib
//oleaut32.lib
//uuid.lib
//odbc32.lib
//odbccp32.lib
//----------------

//=============================================================
// Standard library headers, include as needed -
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

//=============================================================
// printf Specifiers -
%s 	a string of characters
%d 	int, signed decimal (integer) number (base 10)
%u 	unsigned int, unsigned decimal (integer) number
%lld long long int or long long
%llu unsigned long long int or unsigned long long
%f 	floating-point number
%td ptrdiff_t // or cast to ull and use %lld


PRId64 int64_t 
PRIu64 uint64_t 
PRIx64 to print in hexadecimal
printf("%" PRId64 "\n", t);
printf("%" PRIu64 "\n", t);


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
