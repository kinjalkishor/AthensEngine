#pragma once

#include "base_types.h"

#include <limits.h>

//================================================================
// Extra Functions
//================================================================
namespace gm
{

//===============================
// Integer Packing Unpacking
//===============================

// Packs uint8 a, b, c, d [0-255] components in a uint.
// Maps unsigned 8 bits/channel to UColor.
// RGBA format
inline uint pack_u32(uint8 a, uint8 b, uint8 c, uint8 d) {
	return ((uint)(a) << 24) | ((uint)(b) << 16) | ((uint)(c) << 8) | ((uint)(d));
}

// Unpacks four uint8 components out of uint and assign to uint.
inline void unpack_u32(uint val, uint8& a, uint8& b, uint8& c, uint8& d) {
	a = (uint8)((val)>>24);
	b = (uint8)((val)>>16);
	c = (uint8)((val)>>8);
	d = (uint8)(val);
}

inline uint xbgr_from_u8(uint8 r, uint8 g, uint8 b) {
	return pack_u32(0x00, b, g, r);
}

//UCHAR_MAX; //0xff;
inline uint byte_order_swap_u32(uint x) {
	uint8 A = (x >> 24) & UCHAR_MAX;
	uint8 R = (x >> 16) & UCHAR_MAX;
	uint8 G = (x >>  8) & UCHAR_MAX;
	uint8 B = (x >>  0) & UCHAR_MAX;

	return ((A << 24) | (B << 16) | (G << 8) | (R << 0));
}

inline uint abgr_from_argb(uint x) {
	return byte_order_swap_u32(x);
}

inline uint argb_from_abgr(uint x) {
	return byte_order_swap_u32(x);
}



//-------------
// float to uint component of a packed uint.
inline uint ftouc(float x) {
	//return ((uint)((x)*255.f)&0xff);
	//return (scast<uint>(x*255.f) & UCHAR_MAX);	
	return (x >= 1.0f ? UCHAR_MAX : x <= 0.0f ? 0x00 : (uint) (x * 255.0f));
}

inline uint ftouc_r(float x) {
	//255.0f + 0.5f changes value
	return (x >= 1.0f ? UCHAR_MAX : x <= 0.0f ? 0x00 : (uint) (x * 255.0f + 0.5f)); 
}

// Multiply with this to get float value in [0-1.0] from a component of packed uint. (1.0 / 255.0)
// (0.003921568627);
inline constexpr float k_uc_inv = scast<float>(0.00392156862745098039);
//template <class T> inline constexpr T k_uc_inv = scast<T>(0.00392156862745098039);

// Packs float a, b, c, d [0-1.0] components in a uint.
// ARGB format
inline uint packf_u32(float a, float b, float c, float d) {
	//uint ua = ftouc(a);
	//uint ub = ftouc(b);
	//uint uc = ftouc(c);
	//uint ud = ftouc(d);
	//return ((ua << 24) | (ub << 16) | (uc << 8) | ud);

	return ((ftouc(a) << 24) | (ftouc(b) << 16) | (ftouc(c) << 8) | (ftouc(d)));
}

inline uint packf_u32_r(float a, float b, float c, float d) {
	return ((ftouc_r(a) << 24) | (ftouc_r(b) << 16) | (ftouc_r(c) << 8) | (ftouc_r(d)));
}


// Unpacks four uint8 components out of uint and assign to floats.
inline void unpackf_u32(uint x, float& a, float& b, float& c, float& d) {
	a = k_uc_inv * (float) (uint8) (x >> 24);
	b = k_uc_inv * (float) (uint8) (x >> 16);
	c = k_uc_inv * (float) (uint8) (x >>  8);
	d = k_uc_inv * (float) (uint8) (x >>  0);
}
//-------------

}
