#pragma once

#if 0
    vec2& operator += (const vec2& rhs) { for (int i=0; i < size(); ++i) { e[i] += rhs[i]; } return *this; }
    vec2& operator -= (const vec2& rhs) { for (int i=0; i < size(); ++i) { e[i] -= rhs[i]; } return *this; }
	vec2& operator *= (const vec2& rhs) { for (int i=0; i < size(); ++i) { e[i] *= rhs[i]; } return *this; }
	vec2& operator /= (const vec2& rhs) { for (int i=0; i < size(); ++i) { e[i] /= rhs[i]; } return *this; }
    vec2& operator += (float s) { for (int i=0; i < size(); ++i) { e[i] += s; } return *this; }
    vec2& operator -= (float s) { for (int i=0; i < size(); ++i) { e[i] -= s; } return *this; }
	vec2& operator *= (float s) { for (int i=0; i < size(); ++i) { e[i] *= s; } return *this; }
	vec2& operator /= (float s) { for (int i=0; i < size(); ++i) { float inv_s = static_cast<float>(1.0)/s; e[i] *= inv_s; } return *this; }

    vec3& operator += (const vec3& rhs) { for (int i=0; i < size(); ++i) { e[i] += rhs[i]; } return *this; }
    vec3& operator -= (const vec3& rhs) { for (int i=0; i < size(); ++i) { e[i] -= rhs[i]; } return *this; }
	vec3& operator *= (const vec3& rhs) { for (int i=0; i < size(); ++i) { e[i] *= rhs[i]; } return *this; }
	vec3& operator /= (const vec3& rhs) { for (int i=0; i < size(); ++i) { e[i] /= rhs[i]; } return *this; }
    vec3& operator += (float s) { for (int i=0; i < size(); ++i) { e[i] += s; } return *this; }
    vec3& operator -= (float s) { for (int i=0; i < size(); ++i) { e[i] -= s; } return *this; }
	vec3& operator *= (float s) { for (int i=0; i < size(); ++i) { e[i] *= s; } return *this; }
	vec3& operator /= (float s) { for (int i=0; i < size(); ++i) { float inv_s = static_cast<float>(1.0)/s; e[i] *= inv_s; } return *this; }

    vec4& operator += (const vec4& rhs) { for (int i=0; i < size(); ++i) { e[i] += rhs[i]; } return *this; }
    vec4& operator -= (const vec4& rhs) { for (int i=0; i < size(); ++i) { e[i] -= rhs[i]; } return *this; }
	vec4& operator *= (const vec4& rhs) { for (int i=0; i < size(); ++i) { e[i] *= rhs[i]; } return *this; }
	vec4& operator /= (const vec4& rhs) { for (int i=0; i < size(); ++i) { e[i] /= rhs[i]; } return *this; }
    vec4& operator += (float s) { for (int i=0; i < size(); ++i) { e[i] += s; } return *this; }
    vec4& operator -= (float s) { for (int i=0; i < size(); ++i) { e[i] -= s; } return *this; }
	vec4& operator *= (float s) { for (int i=0; i < size(); ++i) { e[i] *= s; } return *this; }
	vec4& operator /= (float s) { for (int i=0; i < size(); ++i) { float inv_s = static_cast<float>(1.0)/s; e[i] *= inv_s; } return *this; }


    //vec2  
    //operator float* () { return (float*)&x; }    
    //operator const float* () const { return (const float*)&x; }
    //vec2& operator += (const vec2& v) { x += v.x; y += v.y; return *this; }
    //vec2 operator + (const vec2& v) const { return vec2(x + v.x, y + v.y); }
    //bool operator == (const vec2& v) const { return x == v.x && y == v.y; }
    //bool operator != (const vec2& v) const { return x != v.x || y != v.y; }

    //vec3

    //vec4
    //vec4(const vec3& xyz, float w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}
    //inline float vec4_dot(const vec4& a, const vec4& b) { return (a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w); }
    //inline float vec4_length_sq(const vec4& a) { return (a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w); }
    //inline float vec4_length(const vec4& a) { return std::sqrt(a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w); }
    //inline float vec4_distance_sq(const vec4& a, const vec4& b) { return ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z) + (a.w - b.w)*(a.w - b.w)); }
    //inline float vec4_distance(const vec4& a, const vec4& b) { return std::sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z) + (a.w - b.w)*(a.w - b.w)); }
    //---
    //inline float vec4_dot(const vec4& a, const vec4& b) { float sum = 0.0;  for (int i=0; i < vec4::size(); ++i) { sum += a[i] * b[i]; }    return sum; }
    //inline float vec4_length_sq(const vec4& a) { float sum = 0.0;  for (int i=0; i < vec4::size(); ++i) { sum += a[i] * a[i]; }    return sum; }
    //inline float vec4_length(const vec4& a) { float sum = 0.0;  for (int i=0; i < vec4::size(); ++i) { sum += a[i] * a[i]; }    return sqrt(sum); }
    //inline float vec4_distance_sq(const vec4& a, const vec4& b) { float sum = 0.0;  for (int i=0; i < vec4::size(); ++i) { sum += (a[i] - b[i])*(a[i] - b[i]); }    return sum; }
    ///inline float vec4_distance(const vec4& a, const vec4& b) { float sum = 0.0;  for (int i=0; i < vec4::size(); ++i) { sum += (a[i] - b[i])*(a[i] - b[i]); }    return sqrt(sum); }
    //---

    //color4
    //color4(DWORD argb);
    //operator DWORD () const;

	//mat3
	//const float& operator ()(int row, int col) const	{ return r[row][col]; }
    //float& operator ()(int row, int col)				{ return r[row][col]; }

	//mat4
    //const float& operator ()(int row, int col) const	{ return r[row][col]; }
    //float& operator ()(int row, int col)				{ return r[row][col]; }
	//const float& operator ()(int row, int col) const	{ return e[(row * 4) + col]; }
	//float& operator ()(int row, int col)				{ return e[(row * 4) + col]; }    
    
    //mat4& operator *= (const mat4& rhs) { *this = (*this) * rhs; }

	//---
    //template<class T> inline const T k_zero;
    //template<> inline const vec2 k_zero<vec2> = vec2(0);

    //const static vec2 k_zero() { return vec2(0); }


    //template<class T>
    //class quat2 {};
    //template<class T, class U> inline const T k_identity2;
    //template<class U> inline const quat2<U> k_identity2<quat2<U>, U> = quat2<U>(0, 0, 0, 1);
    //gm::quat2<float> b = gm::k_identity2<gm::quat2<float>, float>;
#endif

#if 0

#include <math.h>

//===========================================================================
//
// 16 bit floating point numbers
//
//===========================================================================

#define D3DX_16F_DIG          3                // # of decimal digits of precision
#define D3DX_16F_EPSILON      4.8875809e-4f    // smallest such that 1.0 + epsilon != 1.0
#define D3DX_16F_MANT_DIG     11               // # of bits in mantissa
#define D3DX_16F_MAX          6.550400e+004    // max value
#define D3DX_16F_MAX_10_EXP   4                // max decimal exponent
#define D3DX_16F_MAX_EXP      15               // max binary exponent
#define D3DX_16F_MIN          6.1035156e-5f    // min positive value
#define D3DX_16F_MIN_10_EXP   (-4)             // min decimal exponent
#define D3DX_16F_MIN_EXP      (-14)            // min binary exponent
#define D3DX_16F_RADIX        2                // exponent radix
#define D3DX_16F_ROUNDS       1                // addition rounding: near


class D3DXFLOAT16 {
public:
    //typedef unsigned short      WORD;
    //WORD value;
    unsigned short value;


    D3DXFLOAT16() {};

    D3DXFLOAT16(float f) {
        D3DXFloat32To16Array(this, &f, 1);
    }

    D3DXFLOAT16(const D3DXFLOAT16& f) {
        value = f.value;
    }

    // casting
    operator float () {
        float f;
        D3DXFloat16To32Array(&f, this, 1);
        return f;
    }

    // binary operators
    bool operator == (const D3DXFLOAT16& f) const {
        return value == f.value;
    }

    bool operator != (const D3DXFLOAT16& f) const {
        return value != f.value;
    }    
};



unsigned short float_32_to_16(const float in) {
    int exp = 0, origexp;
    float tmp = std::fabs(in);
    int sign = (copysignf(1, in) < 0);
    unsigned int mantissa;
    unsigned short ret;

    /* Deal with special numbers */
    if (isinf(in)) return (sign ? 0xffff : 0x7fff);
    if (isnan(in)) return (sign ? 0xffff : 0x7fff);
    if (in == 0.0f) return (sign ? 0x8000 : 0x0000);

    if (tmp < (float)(1u << 10)) {
        do {
            tmp *= 2.0f;
            exp--;
        } while (tmp < (float)(1u << 10));
    } else if (tmp >= (float)(1u << 11)) {
        do {
            tmp /= 2.0f;
            exp++;
        } while (tmp >= (float)(1u << 11));
    }

    exp += 10;  /* Normalize the mantissa */
    exp += 15;  /* Exponent is encoded with excess 15 */

    origexp = exp;

    mantissa = (unsigned int) tmp;
    if ((tmp - mantissa == 0.5f && mantissa % 2 == 1) || /* round half to even */
        (tmp - mantissa > 0.5f)) {
        mantissa++; /* round to nearest, away from zero */
    }

    if (mantissa == 2048) {
        mantissa = 1024;
        exp++;
    }

    if (exp > 31) {
        /* too big */
        ret = 0x7fff; /* INF */
    } else if (exp <= 0) {
        unsigned int rounding = 0;

        /* Denormalized half float */

        /* return 0x0000 (=0.0) for numbers too small to represent in half floats */
        if (exp < -11)
            return (sign ? 0x8000 : 0x0000);

        exp = origexp;

        /* the 13 extra bits from single precision are used for rounding */
        mantissa = (unsigned int)(tmp * (1u << 13));
        mantissa >>= 1 - exp; /* denormalize */

        mantissa -= ~(mantissa >> 13) & 1; /* round half to even */
        /* remove 13 least significant bits to get half float precision */
        mantissa >>= 12;
        rounding = mantissa & 1;
        mantissa >>= 1;

        ret = mantissa + rounding;
    } else {
        ret = (exp << 10) | (mantissa & 0x3ff);
    }

    ret |= ((sign ? 1 : 0) << 15); /* Add the sign */
    return ret;
}

D3DXFLOAT16* D3DXFloat32To16Array(D3DXFLOAT16* pout, const float* pin, unsigned int n) {
    for (unsigned int i = 0; i < n; ++i) {
        pout[i].value = float_32_to_16(pin[i]);
    }
    return pout;
}

/* Native d3dx9's D3DXFloat16to32Array lacks support for NaN and Inf. Specifically, e = 16 is treated as a
 * regular number - e.g., 0x7fff is converted to 131008.0 and 0xffff to -131008.0. */
float float_16_to_32(const unsigned short in) {
    const unsigned short s = (in & 0x8000);
    const unsigned short e = (in & 0x7C00) >> 10;
    const unsigned short m = in & 0x3FF;
    const float sgn = (s ? -1.0f : 1.0f);

    if (e == 0) {
        if (m == 0) return sgn * 0.0f; /* +0.0 or -0.0 */
        else return sgn * powf(2, -14.0f) * (m / 1024.0f);
    } else {
        return sgn * powf(2, e - 15.0f) * (1.0f + (m / 1024.0f));
    }
}

float* D3DXFloat16To32Array(float* pout, const D3DXFLOAT16* pin, unsigned int n) {
    for (unsigned int i = 0; i < n; ++i) {
        pout[i] = float_16_to_32(pin[i].value);
    }
    return pout;
}



//-------------
// MISC
// Calculate Fresnel term given the cosine of theta (likely obtained by
// taking the dot of two normals), and the refraction index of the material.
float fresnel_term(float cos_theta, float refraction_index) {
    float a, d, g, result;

    g = std::sqrt(refraction_index * refraction_index + cos_theta * cos_theta - 1.0f);
    a = g + cos_theta;
    d = g - cos_theta;
    result = (cos_theta * a - 1.0f) * (cos_theta * a - 1.0f) / ((cos_theta * d + 1.0f) * (cos_theta * d + 1.0f)) + 1.0f;
    result *= 0.5f * d * d / (a * a);

    return result;
}


#endif

//==============================================
//inline const vec3 k_vec3_one() { return vec3(1.0); }
// default (0, 1, 0, 0)
//inline const plane k_plane_default() { return plane(0, 1, 0, 0); }
//---
//vec2(const float* arr) { x = arr[0]; y = arr[1]; }
//operator float* () { return &e[0]; }
//operator const float* () const { return &e[0]; }