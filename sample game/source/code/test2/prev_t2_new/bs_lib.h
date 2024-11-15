#pragma once

#include "bs_types.h"


namespace sdf
{

// Copy the string, or as much of it as fits, into the dest buffer. 
// returns the number of characters copied (not including the trailing NUL) or -E2BIG if the destination buffer wasn't big enough.
// Preferred to strlcpy since the API doesn't require reading memory from the src string beyond the specified “count” bytes, and since the return value is easier to error-check than strlcpy's.
// Preferred to strncpy since it always returns a valid string, and doesn't unnecessarily force the tail of the destination buffer to be zeroed. If the zeroing is desired, it's likely cleaner 
// to use strscpy with an overflow test, then just memset the tail of the dest buffer.
//ssize_t strscpy(char * dest, const char * src, size_t count);



}
