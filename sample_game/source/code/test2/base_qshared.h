#pragma once

#include "base_types.h"
#include "base_gmath.h"

#include <vector>


//------------------
#define SIZE_MAX_X64 0xffffffffffffffffui64
#define SIZE_MAX_X32 0xffffffffui32
// x64 platform check
#if SIZE_MAX == SIZE_MAX_X64
// 64-bit platform
#elif SIZE_MAX == SIZE_MAX_X32
// 32-bit platform
#else
#error Unknown platform - does not look either like 32-bit or 64-bit
#endif

//------------------
// OWN
#define Z_Malloc malloc
#define S_Malloc malloc
#define Z_Free free
#define Com_DPrintf printf
//#define Com_Printf printf

extern char* k_empty_strz[1];

//------------------
// OWN:
// CHECK:
char *CopyString( const char *in );
//------------------

using vec2_t = gm::vec2;
using vec3_t = gm::vec3;
using vec4_t = gm::vec4;

namespace gm 
{

class mat3x4 {
public:
	union {
		struct {
            float	m11, m12, m13, m14,
					m21, m22, m23, m24,
					m31, m32, m33, m34;
        };
		float e[12];
		float r[3][4];
	};

	mat3x4() = default;
	
	constexpr static int size() { return 12; }	
	
	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [] (int i) const	{ return e[i]; }
    float& operator [] (int i)				{ return e[i]; }
};

}
//---------------------------------
