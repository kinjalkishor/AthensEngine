#pragma once

#include <stdio.h>


#define printfln(format, ...)		printf(format "\n", ##__VA_ARGS__)
#define wprintfln(format, ...)		wprintf(format L"\n", ##__VA_ARGS__)

#define eprintfln(format, ...)		printf("ERROR: %s: \n" format, __FUNCTION__, ##__VA_ARGS__)


inline void q_print_sep_line()	{ printf("\n--------------------------------\n"); }

//#define fm_assert

inline void check_assert(const char *file, int line, const char* func, const char *expression, const char *msg) {
	printf("ASSERT FAILED: (%s), in %s: [%s: Line(%d)]\n", expression, func, file, line);
}
#define fm_assert_m(expression, msg) \
do { if (!(expression)) { check_assert(__FILE__, __LINE__, __FUNCTION__, #expression, msg); } } while (0)
#define fm_assert(expression)	fm_assert_m(expression, "")