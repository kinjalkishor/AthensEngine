#pragma once

#include <stdio.h>


#define eprintf(format, ...)	printf("ERROR: %s: " format, __FUNCTION__, ##__VA_ARGS__)

inline void print_sep_line()	{ printf("\n--------------------------------\n"); }

inline void check_assert(const char *file, int line, const char* func, const char *expression, const char *msg) {
	printf("ASSERT FAILED: (%s), in %s: [%s: Line(%d)]", expression, func, file, line);
}
//#define fm_assert
#define fm_assert(expression, msg) \
do { if (!(expression)) { check_assert(__FILE__, __LINE__, __FUNCTION__, #expression, msg); } } while (0)

