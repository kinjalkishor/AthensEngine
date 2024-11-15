//////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Microsoft Corporation.  All Rights Reserved.
//
//  File:       d3dx9math.h
//  Content:    D3DX math types and functions
//
//////////////////////////////////////////////////////////////////////////////

#include "d3dx9.h"

#ifndef __D3DX9MATH_H__
#define __D3DX9MATH_H__

#include <math.h>
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning(disable:4201) // anonymous unions warning



//===========================================================================
//
// General purpose utilities
//
//===========================================================================
#define D3DX_PI    ((FLOAT)  3.141592654f)
#define D3DX_1BYPI ((FLOAT)  0.318309886f)

#define D3DXToRadian( degree ) ((degree) * (D3DX_PI / 180.0f))
#define D3DXToDegree( radian ) ((radian) * (180.0f / D3DX_PI))



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


typedef struct D3DXFLOAT16
{
#ifdef __cplusplus
public:
    D3DXFLOAT16() {};
    D3DXFLOAT16( FLOAT );
    D3DXFLOAT16( CONST D3DXFLOAT16& );

    // casting
    operator FLOAT ();

    // binary operators
    BOOL operator == ( CONST D3DXFLOAT16& ) const;
    BOOL operator != ( CONST D3DXFLOAT16& ) const;

protected:
#endif //__cplusplus
    WORD value;
} D3DXFLOAT16, *LPD3DXFLOAT16;



//===========================================================================
//
// Vectors
//
//===========================================================================


//--------------------------
// 2D Vector
//--------------------------
typedef struct D3DXVECTOR2
{
#ifdef __cplusplus
public:
    D3DXVECTOR2() {};
    D3DXVECTOR2( CONST FLOAT * );
    D3DXVECTOR2( CONST D3DXFLOAT16 * );
    D3DXVECTOR2( FLOAT x, FLOAT y );

    // casting
    operator FLOAT* ();
    operator CONST FLOAT* () const;

    // assignment operators
    D3DXVECTOR2& operator += ( CONST D3DXVECTOR2& );
    D3DXVECTOR2& operator -= ( CONST D3DXVECTOR2& );
    D3DXVECTOR2& operator *= ( FLOAT );
    D3DXVECTOR2& operator /= ( FLOAT );

    // unary operators
    D3DXVECTOR2 operator + () const;
    D3DXVECTOR2 operator - () const;

    // binary operators
    D3DXVECTOR2 operator + ( CONST D3DXVECTOR2& ) const;
    D3DXVECTOR2 operator - ( CONST D3DXVECTOR2& ) const;
    D3DXVECTOR2 operator * ( FLOAT ) const;
    D3DXVECTOR2 operator / ( FLOAT ) const;

    friend D3DXVECTOR2 operator * ( FLOAT, CONST D3DXVECTOR2& );

    BOOL operator == ( CONST D3DXVECTOR2& ) const;
    BOOL operator != ( CONST D3DXVECTOR2& ) const;


public:
#endif //__cplusplus
    FLOAT x, y;
} D3DXVECTOR2, *LPD3DXVECTOR2;



//--------------------------
// 2D Vector (16 bit)
//--------------------------

typedef struct D3DXVECTOR2_16F
{
#ifdef __cplusplus
public:
    D3DXVECTOR2_16F() {};
    D3DXVECTOR2_16F( CONST FLOAT * );
    D3DXVECTOR2_16F( CONST D3DXFLOAT16 * );
    D3DXVECTOR2_16F( CONST D3DXFLOAT16 &x, CONST D3DXFLOAT16 &y );

    // casting
    operator D3DXFLOAT16* ();
    operator CONST D3DXFLOAT16* () const;

    // binary operators
    BOOL operator == ( CONST D3DXVECTOR2_16F& ) const;
    BOOL operator != ( CONST D3DXVECTOR2_16F& ) const;

public:
#endif //__cplusplus
    D3DXFLOAT16 x, y;

} D3DXVECTOR2_16F, *LPD3DXVECTOR2_16F;



//--------------------------
// 3D Vector
//--------------------------
#ifdef __cplusplus
typedef struct D3DXVECTOR3 : public D3DVECTOR
{
public:
    D3DXVECTOR3() {};
    D3DXVECTOR3( CONST FLOAT * );
    D3DXVECTOR3( CONST D3DVECTOR& );
    D3DXVECTOR3( CONST D3DXFLOAT16 * );
    D3DXVECTOR3( FLOAT x, FLOAT y, FLOAT z );

    // casting
    operator FLOAT* ();
    operator CONST FLOAT* () const;

    // assignment operators
    D3DXVECTOR3& operator += ( CONST D3DXVECTOR3& );
    D3DXVECTOR3& operator -= ( CONST D3DXVECTOR3& );
    D3DXVECTOR3& operator *= ( FLOAT );
    D3DXVECTOR3& operator /= ( FLOAT );

    // unary operators
    D3DXVECTOR3 operator + () const;
    D3DXVECTOR3 operator - () const;

    // binary operators
    D3DXVECTOR3 operator + ( CONST D3DXVECTOR3& ) const;
    D3DXVECTOR3 operator - ( CONST D3DXVECTOR3& ) const;
    D3DXVECTOR3 operator * ( FLOAT ) const;
    D3DXVECTOR3 operator / ( FLOAT ) const;

    friend D3DXVECTOR3 operator * ( FLOAT, CONST struct D3DXVECTOR3& );

    BOOL operator == ( CONST D3DXVECTOR3& ) const;
    BOOL operator != ( CONST D3DXVECTOR3& ) const;

} D3DXVECTOR3, *LPD3DXVECTOR3;

#else //!__cplusplus
typedef struct _D3DVECTOR D3DXVECTOR3, *LPD3DXVECTOR3;
#endif //!__cplusplus



//--------------------------
// 3D Vector (16 bit)
//--------------------------
typedef struct D3DXVECTOR3_16F
{
#ifdef __cplusplus
public:
    D3DXVECTOR3_16F() {};
    D3DXVECTOR3_16F( CONST FLOAT * );
    D3DXVECTOR3_16F( CONST D3DVECTOR& );
    D3DXVECTOR3_16F( CONST D3DXFLOAT16 * );
    D3DXVECTOR3_16F( CONST D3DXFLOAT16 &x, CONST D3DXFLOAT16 &y, CONST D3DXFLOAT16 &z );

    // casting
    operator D3DXFLOAT16* ();
    operator CONST D3DXFLOAT16* () const;

    // binary operators
    BOOL operator == ( CONST D3DXVECTOR3_16F& ) const;
    BOOL operator != ( CONST D3DXVECTOR3_16F& ) const;

public:
#endif //__cplusplus
    D3DXFLOAT16 x, y, z;

} D3DXVECTOR3_16F, *LPD3DXVECTOR3_16F;



//--------------------------
// 4D Vector
//--------------------------
typedef struct D3DXVECTOR4
{
#ifdef __cplusplus
public:
    D3DXVECTOR4() {};
    D3DXVECTOR4( CONST FLOAT* );
    D3DXVECTOR4( CONST D3DXFLOAT16* );
    D3DXVECTOR4( CONST D3DVECTOR& xyz, FLOAT w );
    D3DXVECTOR4( FLOAT x, FLOAT y, FLOAT z, FLOAT w );

    // casting
    operator FLOAT* ();
    operator CONST FLOAT* () const;

    // assignment operators
    D3DXVECTOR4& operator += ( CONST D3DXVECTOR4& );
    D3DXVECTOR4& operator -= ( CONST D3DXVECTOR4& );
    D3DXVECTOR4& operator *= ( FLOAT );
    D3DXVECTOR4& operator /= ( FLOAT );

    // unary operators
    D3DXVECTOR4 operator + () const;
    D3DXVECTOR4 operator - () const;

    // binary operators
    D3DXVECTOR4 operator + ( CONST D3DXVECTOR4& ) const;
    D3DXVECTOR4 operator - ( CONST D3DXVECTOR4& ) const;
    D3DXVECTOR4 operator * ( FLOAT ) const;
    D3DXVECTOR4 operator / ( FLOAT ) const;

    friend D3DXVECTOR4 operator * ( FLOAT, CONST D3DXVECTOR4& );

    BOOL operator == ( CONST D3DXVECTOR4& ) const;
    BOOL operator != ( CONST D3DXVECTOR4& ) const;

public:
#endif //__cplusplus
    FLOAT x, y, z, w;
} D3DXVECTOR4, *LPD3DXVECTOR4;


//--------------------------
// 4D Vector (16 bit)
//--------------------------
typedef struct D3DXVECTOR4_16F
{
#ifdef __cplusplus
public:
    D3DXVECTOR4_16F() {};
    D3DXVECTOR4_16F( CONST FLOAT * );
    D3DXVECTOR4_16F( CONST D3DXFLOAT16* );
    D3DXVECTOR4_16F( CONST D3DXVECTOR3_16F& xyz, CONST D3DXFLOAT16& w );
    D3DXVECTOR4_16F( CONST D3DXFLOAT16& x, CONST D3DXFLOAT16& y, CONST D3DXFLOAT16& z, CONST D3DXFLOAT16& w );

    // casting
    operator D3DXFLOAT16* ();
    operator CONST D3DXFLOAT16* () const;

    // binary operators
    BOOL operator == ( CONST D3DXVECTOR4_16F& ) const;
    BOOL operator != ( CONST D3DXVECTOR4_16F& ) const;

public:
#endif //__cplusplus
    D3DXFLOAT16 x, y, z, w;

} D3DXVECTOR4_16F, *LPD3DXVECTOR4_16F;



//===========================================================================
//
// Matrices
//
//===========================================================================
#ifdef __cplusplus
typedef struct D3DXMATRIX : public D3DMATRIX
{
public:
    D3DXMATRIX() {};
    D3DXMATRIX( CONST FLOAT * );
    D3DXMATRIX( CONST D3DMATRIX& );
    D3DXMATRIX( CONST D3DXFLOAT16 * );
    D3DXMATRIX( FLOAT _11, FLOAT _12, FLOAT _13, FLOAT _14,
                FLOAT _21, FLOAT _22, FLOAT _23, FLOAT _24,
                FLOAT _31, FLOAT _32, FLOAT _33, FLOAT _34,
                FLOAT _41, FLOAT _42, FLOAT _43, FLOAT _44 );


    // access grants
    FLOAT& operator () ( UINT Row, UINT Col );
    FLOAT  operator () ( UINT Row, UINT Col ) const;

    // casting operators
    operator FLOAT* ();
    operator CONST FLOAT* () const;

    // assignment operators
    D3DXMATRIX& operator *= ( CONST D3DXMATRIX& );
    D3DXMATRIX& operator += ( CONST D3DXMATRIX& );
    D3DXMATRIX& operator -= ( CONST D3DXMATRIX& );
    D3DXMATRIX& operator *= ( FLOAT );
    D3DXMATRIX& operator /= ( FLOAT );

    // unary operators
    D3DXMATRIX operator + () const;
    D3DXMATRIX operator - () const;

    // binary operators
    D3DXMATRIX operator * ( CONST D3DXMATRIX& ) const;
    D3DXMATRIX operator + ( CONST D3DXMATRIX& ) const;
    D3DXMATRIX operator - ( CONST D3DXMATRIX& ) const;
    D3DXMATRIX operator * ( FLOAT ) const;
    D3DXMATRIX operator / ( FLOAT ) const;

    friend D3DXMATRIX operator * ( FLOAT, CONST D3DXMATRIX& );

    BOOL operator == ( CONST D3DXMATRIX& ) const;
    BOOL operator != ( CONST D3DXMATRIX& ) const;

} D3DXMATRIX, *LPD3DXMATRIX;

#else //!__cplusplus
typedef struct _D3DMATRIX D3DXMATRIX, *LPD3DXMATRIX;
#endif //!__cplusplus


//---------------------------------------------------------------------------
// Aligned Matrices
//
// This class helps keep matrices 16-byte aligned as preferred by P4 cpus.
// It aligns matrices on the stack and on the heap or in global scope.
// It does this using __declspec(align(16)) which works on VC7 and on VC 6
// with the processor pack. Unfortunately there is no way to detect the 
// latter so this is turned on only on VC7. On other compilers this is the
// the same as D3DXMATRIX.
//
// Using this class on a compiler that does not actually do the alignment
// can be dangerous since it will not expose bugs that ignore alignment.
// E.g if an object of this class in inside a struct or class, and some code
// memcopys data in it assuming tight packing. This could break on a compiler
// that eventually start aligning the matrix.
//---------------------------------------------------------------------------
#ifdef __cplusplus
typedef struct _D3DXMATRIXA16 : public D3DXMATRIX
{
    _D3DXMATRIXA16() {}
    _D3DXMATRIXA16( CONST FLOAT * );
    _D3DXMATRIXA16( CONST D3DMATRIX& );
    _D3DXMATRIXA16( CONST D3DXFLOAT16 * );
    _D3DXMATRIXA16( FLOAT _11, FLOAT _12, FLOAT _13, FLOAT _14,
                    FLOAT _21, FLOAT _22, FLOAT _23, FLOAT _24,
                    FLOAT _31, FLOAT _32, FLOAT _33, FLOAT _34,
                    FLOAT _41, FLOAT _42, FLOAT _43, FLOAT _44 );

    // new operators
    void* operator new   ( size_t );
    void* operator new[] ( size_t );

    // delete operators
    void operator delete   ( void* );   // These are NOT virtual; Do not 
    void operator delete[] ( void* );   // cast to D3DXMATRIX and delete.
    
    // assignment operators
    _D3DXMATRIXA16& operator = ( CONST D3DXMATRIX& );

} _D3DXMATRIXA16;

#else //!__cplusplus
typedef D3DXMATRIX  _D3DXMATRIXA16;
#endif //!__cplusplus



#if _MSC_VER >= 1300  // VC7
#define D3DX_ALIGN16 __declspec(align(16))
#else
#define D3DX_ALIGN16  // Earlier compiler may not understand this, do nothing.
#endif

typedef D3DX_ALIGN16 _D3DXMATRIXA16 D3DXMATRIXA16, *LPD3DXMATRIXA16;



//===========================================================================
//
//    Quaternions
//
//===========================================================================
typedef struct D3DXQUATERNION
{
#ifdef __cplusplus
public:
    D3DXQUATERNION() {}
    D3DXQUATERNION( CONST FLOAT * );
    D3DXQUATERNION( CONST D3DXFLOAT16 * );
    D3DXQUATERNION( FLOAT x, FLOAT y, FLOAT z, FLOAT w );

    // casting
    operator FLOAT* ();
    operator CONST FLOAT* () const;

    // assignment operators
    D3DXQUATERNION& operator += ( CONST D3DXQUATERNION& );
    D3DXQUATERNION& operator -= ( CONST D3DXQUATERNION& );
    D3DXQUATERNION& operator *= ( CONST D3DXQUATERNION& );
    D3DXQUATERNION& operator *= ( FLOAT );
    D3DXQUATERNION& operator /= ( FLOAT );

    // unary operators
    D3DXQUATERNION  operator + () const;
    D3DXQUATERNION  operator - () const;

    // binary operators
    D3DXQUATERNION operator + ( CONST D3DXQUATERNION& ) const;
    D3DXQUATERNION operator - ( CONST D3DXQUATERNION& ) const;
    D3DXQUATERNION operator * ( CONST D3DXQUATERNION& ) const;
    D3DXQUATERNION operator * ( FLOAT ) const;
    D3DXQUATERNION operator / ( FLOAT ) const;

    friend D3DXQUATERNION operator * (FLOAT, CONST D3DXQUATERNION& );

    BOOL operator == ( CONST D3DXQUATERNION& ) const;
    BOOL operator != ( CONST D3DXQUATERNION& ) const;

#endif //__cplusplus
    FLOAT x, y, z, w;
} D3DXQUATERNION, *LPD3DXQUATERNION;


//===========================================================================
//
// Planes
//
//===========================================================================
typedef struct D3DXPLANE
{
#ifdef __cplusplus
public:
    D3DXPLANE() {}
    D3DXPLANE( CONST FLOAT* );
    D3DXPLANE( CONST D3DXFLOAT16* );
    D3DXPLANE( FLOAT a, FLOAT b, FLOAT c, FLOAT d );

    // casting
    operator FLOAT* ();
    operator CONST FLOAT* () const;

    // assignment operators
    D3DXPLANE& operator *= ( FLOAT );
    D3DXPLANE& operator /= ( FLOAT );

    // unary operators
    D3DXPLANE operator + () const;
    D3DXPLANE operator - () const;

    // binary operators
    D3DXPLANE operator * ( FLOAT ) const;
    D3DXPLANE operator / ( FLOAT ) const;

    friend D3DXPLANE operator * ( FLOAT, CONST D3DXPLANE& );

    BOOL operator == ( CONST D3DXPLANE& ) const;
    BOOL operator != ( CONST D3DXPLANE& ) const;

#endif //__cplusplus
    FLOAT a, b, c, d;
} D3DXPLANE, *LPD3DXPLANE;


//===========================================================================
//
// Colors
//
//===========================================================================

typedef struct D3DXCOLOR
{
#ifdef __cplusplus
public:
    D3DXCOLOR() {}
    D3DXCOLOR( DWORD argb );
    D3DXCOLOR( CONST FLOAT * );
    D3DXCOLOR( CONST D3DXFLOAT16 * );
    D3DXCOLOR( CONST D3DCOLORVALUE& );
    D3DXCOLOR( FLOAT r, FLOAT g, FLOAT b, FLOAT a );

    // casting
    operator DWORD () const;

    operator FLOAT* ();
    operator CONST FLOAT* () const;

    operator D3DCOLORVALUE* ();
    operator CONST D3DCOLORVALUE* () const;

    operator D3DCOLORVALUE& ();
    operator CONST D3DCOLORVALUE& () const;

    // assignment operators
    D3DXCOLOR& operator += ( CONST D3DXCOLOR& );
    D3DXCOLOR& operator -= ( CONST D3DXCOLOR& );
    D3DXCOLOR& operator *= ( FLOAT );
    D3DXCOLOR& operator /= ( FLOAT );

    // unary operators
    D3DXCOLOR operator + () const;
    D3DXCOLOR operator - () const;

    // binary operators
    D3DXCOLOR operator + ( CONST D3DXCOLOR& ) const;
    D3DXCOLOR operator - ( CONST D3DXCOLOR& ) const;
    D3DXCOLOR operator * ( FLOAT ) const;
    D3DXCOLOR operator / ( FLOAT ) const;

    friend D3DXCOLOR operator * ( FLOAT, CONST D3DXCOLOR& );

    BOOL operator == ( CONST D3DXCOLOR& ) const;
    BOOL operator != ( CONST D3DXCOLOR& ) const;

#endif //__cplusplus
    FLOAT r, g, b, a;
} D3DXCOLOR, *LPD3DXCOLOR;



//===========================================================================
//
// D3DX math functions:
//
// NOTE:
//  * All these functions can take the same object as in and out parameters.
//
//  * Out parameters are typically also returned as return values, so that
//    the output of one function may be used as a parameter to another.
//
//===========================================================================

//--------------------------
// Float16
//--------------------------

// non-inline
#ifdef __cplusplus
extern "C" {
#endif

// Converts an array 32-bit floats to 16-bit floats
D3DXFLOAT16* WINAPI D3DXFloat32To16Array
    ( D3DXFLOAT16 *pOut, CONST FLOAT *pIn, UINT n );

// Converts an array 16-bit floats to 32-bit floats
FLOAT* WINAPI D3DXFloat16To32Array
    ( FLOAT *pOut, CONST D3DXFLOAT16 *pIn, UINT n );

#ifdef __cplusplus
}
#endif


//--------------------------
// 2D Vector
//--------------------------

// inline

FLOAT D3DXVec2Length
    ( CONST D3DXVECTOR2 *pV );

FLOAT D3DXVec2LengthSq
    ( CONST D3DXVECTOR2 *pV );

FLOAT D3DXVec2Dot
    ( CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 );

// Z component of ((x1,y1,0) cross (x2,y2,0))
FLOAT D3DXVec2CCW
    ( CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 );

D3DXVECTOR2* D3DXVec2Add
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 );

D3DXVECTOR2* D3DXVec2Subtract
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 );

// Minimize each component.  x = min(x1, x2), y = min(y1, y2)
D3DXVECTOR2* D3DXVec2Minimize
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 );

// Maximize each component.  x = max(x1, x2), y = max(y1, y2)
D3DXVECTOR2* D3DXVec2Maximize
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 );

D3DXVECTOR2* D3DXVec2Scale
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV, FLOAT s );

// Linear interpolation. V1 + s(V2-V1)
D3DXVECTOR2* D3DXVec2Lerp
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2,
      FLOAT s );

// non-inline
#ifdef __cplusplus
extern "C" {
#endif

D3DXVECTOR2* WINAPI D3DXVec2Normalize
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV );

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR2* WINAPI D3DXVec2Hermite
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pT1,
      CONST D3DXVECTOR2 *pV2, CONST D3DXVECTOR2 *pT2, FLOAT s );

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR2* WINAPI D3DXVec2CatmullRom
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV0, CONST D3DXVECTOR2 *pV1,
      CONST D3DXVECTOR2 *pV2, CONST D3DXVECTOR2 *pV3, FLOAT s );

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR2* WINAPI D3DXVec2BaryCentric
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2,
      CONST D3DXVECTOR2 *pV3, FLOAT f, FLOAT g);

// Transform (x, y, 0, 1) by matrix.
D3DXVECTOR4* WINAPI D3DXVec2Transform
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR2 *pV, CONST D3DXMATRIX *pM );

// Transform (x, y, 0, 1) by matrix, project result back into w=1.
D3DXVECTOR2* WINAPI D3DXVec2TransformCoord
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV, CONST D3DXMATRIX *pM );

// Transform (x, y, 0, 0) by matrix.
D3DXVECTOR2* WINAPI D3DXVec2TransformNormal
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV, CONST D3DXMATRIX *pM );
     
// Transform Array (x, y, 0, 1) by matrix.
D3DXVECTOR4* WINAPI D3DXVec2TransformArray
    ( D3DXVECTOR4 *pOut, UINT OutStride, CONST D3DXVECTOR2 *pV, UINT VStride, CONST D3DXMATRIX *pM, UINT n);

// Transform Array (x, y, 0, 1) by matrix, project result back into w=1.
D3DXVECTOR2* WINAPI D3DXVec2TransformCoordArray
    ( D3DXVECTOR2 *pOut, UINT OutStride, CONST D3DXVECTOR2 *pV, UINT VStride, CONST D3DXMATRIX *pM, UINT n );

// Transform Array (x, y, 0, 0) by matrix.
D3DXVECTOR2* WINAPI D3DXVec2TransformNormalArray
    ( D3DXVECTOR2 *pOut, UINT OutStride, CONST D3DXVECTOR2 *pV, UINT VStride, CONST D3DXMATRIX *pM, UINT n );
    
    

#ifdef __cplusplus
}
#endif


//--------------------------
// 3D Vector
//--------------------------

// inline

FLOAT D3DXVec3Length
    ( CONST D3DXVECTOR3 *pV );

FLOAT D3DXVec3LengthSq
    ( CONST D3DXVECTOR3 *pV );

FLOAT D3DXVec3Dot
    ( CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 );

D3DXVECTOR3* D3DXVec3Cross
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 );

D3DXVECTOR3* D3DXVec3Add
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 );

D3DXVECTOR3* D3DXVec3Subtract
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 );

// Minimize each component.  x = min(x1, x2), y = min(y1, y2), ...
D3DXVECTOR3* D3DXVec3Minimize
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 );

// Maximize each component.  x = max(x1, x2), y = max(y1, y2), ...
D3DXVECTOR3* D3DXVec3Maximize
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 );

D3DXVECTOR3* D3DXVec3Scale
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV, FLOAT s);

// Linear interpolation. V1 + s(V2-V1)
D3DXVECTOR3* D3DXVec3Lerp
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2,
      FLOAT s );

// non-inline
#ifdef __cplusplus
extern "C" {
#endif

D3DXVECTOR3* WINAPI D3DXVec3Normalize
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV );

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR3* WINAPI D3DXVec3Hermite
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pT1,
      CONST D3DXVECTOR3 *pV2, CONST D3DXVECTOR3 *pT2, FLOAT s );

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR3* WINAPI D3DXVec3CatmullRom
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV0, CONST D3DXVECTOR3 *pV1,
      CONST D3DXVECTOR3 *pV2, CONST D3DXVECTOR3 *pV3, FLOAT s );

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR3* WINAPI D3DXVec3BaryCentric
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2,
      CONST D3DXVECTOR3 *pV3, FLOAT f, FLOAT g);

// Transform (x, y, z, 1) by matrix.
D3DXVECTOR4* WINAPI D3DXVec3Transform
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR3 *pV, CONST D3DXMATRIX *pM );

// Transform (x, y, z, 1) by matrix, project result back into w=1.
D3DXVECTOR3* WINAPI D3DXVec3TransformCoord
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV, CONST D3DXMATRIX *pM );

// Transform (x, y, z, 0) by matrix.  If you transforming a normal by a 
// non-affine matrix, the matrix you pass to this function should be the 
// transpose of the inverse of the matrix you would use to transform a coord.
D3DXVECTOR3* WINAPI D3DXVec3TransformNormal
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV, CONST D3DXMATRIX *pM );
    
    
// Transform Array (x, y, z, 1) by matrix. 
D3DXVECTOR4* WINAPI D3DXVec3TransformArray
    ( D3DXVECTOR4 *pOut, UINT OutStride, CONST D3DXVECTOR3 *pV, UINT VStride, CONST D3DXMATRIX *pM, UINT n );

// Transform Array (x, y, z, 1) by matrix, project result back into w=1.
D3DXVECTOR3* WINAPI D3DXVec3TransformCoordArray
    ( D3DXVECTOR3 *pOut, UINT OutStride, CONST D3DXVECTOR3 *pV, UINT VStride, CONST D3DXMATRIX *pM, UINT n );

// Transform (x, y, z, 0) by matrix.  If you transforming a normal by a 
// non-affine matrix, the matrix you pass to this function should be the 
// transpose of the inverse of the matrix you would use to transform a coord.
D3DXVECTOR3* WINAPI D3DXVec3TransformNormalArray
    ( D3DXVECTOR3 *pOut, UINT OutStride, CONST D3DXVECTOR3 *pV, UINT VStride, CONST D3DXMATRIX *pM, UINT n );

// Project vector from object space into screen space
D3DXVECTOR3* WINAPI D3DXVec3Project
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV, CONST D3DVIEWPORT9 *pViewport,
      CONST D3DXMATRIX *pProjection, CONST D3DXMATRIX *pView, CONST D3DXMATRIX *pWorld);

// Project vector from screen space into object space
D3DXVECTOR3* WINAPI D3DXVec3Unproject
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV, CONST D3DVIEWPORT9 *pViewport,
      CONST D3DXMATRIX *pProjection, CONST D3DXMATRIX *pView, CONST D3DXMATRIX *pWorld);
      
// Project vector Array from object space into screen space
D3DXVECTOR3* WINAPI D3DXVec3ProjectArray
    ( D3DXVECTOR3 *pOut, UINT OutStride,CONST D3DXVECTOR3 *pV, UINT VStride,CONST D3DVIEWPORT9 *pViewport,
      CONST D3DXMATRIX *pProjection, CONST D3DXMATRIX *pView, CONST D3DXMATRIX *pWorld, UINT n);

// Project vector Array from screen space into object space
D3DXVECTOR3* WINAPI D3DXVec3UnprojectArray
    ( D3DXVECTOR3 *pOut, UINT OutStride, CONST D3DXVECTOR3 *pV, UINT VStride, CONST D3DVIEWPORT9 *pViewport,
      CONST D3DXMATRIX *pProjection, CONST D3DXMATRIX *pView, CONST D3DXMATRIX *pWorld, UINT n);


#ifdef __cplusplus
}
#endif



//--------------------------
// 4D Vector
//--------------------------

// inline

FLOAT D3DXVec4Length
    ( CONST D3DXVECTOR4 *pV );

FLOAT D3DXVec4LengthSq
    ( CONST D3DXVECTOR4 *pV );

FLOAT D3DXVec4Dot
    ( CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2 );

D3DXVECTOR4* D3DXVec4Add
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2);

D3DXVECTOR4* D3DXVec4Subtract
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2);

// Minimize each component.  x = min(x1, x2), y = min(y1, y2), ...
D3DXVECTOR4* D3DXVec4Minimize
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2);

// Maximize each component.  x = max(x1, x2), y = max(y1, y2), ...
D3DXVECTOR4* D3DXVec4Maximize
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2);

D3DXVECTOR4* D3DXVec4Scale
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV, FLOAT s);

// Linear interpolation. V1 + s(V2-V1)
D3DXVECTOR4* D3DXVec4Lerp
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2,
      FLOAT s );

// non-inline
#ifdef __cplusplus
extern "C" {
#endif

// Cross-product in 4 dimensions.
D3DXVECTOR4* WINAPI D3DXVec4Cross
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2,
      CONST D3DXVECTOR4 *pV3);

D3DXVECTOR4* WINAPI D3DXVec4Normalize
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV );

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR4* WINAPI D3DXVec4Hermite
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pT1,
      CONST D3DXVECTOR4 *pV2, CONST D3DXVECTOR4 *pT2, FLOAT s );

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR4* WINAPI D3DXVec4CatmullRom
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV0, CONST D3DXVECTOR4 *pV1,
      CONST D3DXVECTOR4 *pV2, CONST D3DXVECTOR4 *pV3, FLOAT s );

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR4* WINAPI D3DXVec4BaryCentric
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2,
      CONST D3DXVECTOR4 *pV3, FLOAT f, FLOAT g);

// Transform vector by matrix.
D3DXVECTOR4* WINAPI D3DXVec4Transform
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV, CONST D3DXMATRIX *pM );
    
// Transform vector array by matrix.
D3DXVECTOR4* WINAPI D3DXVec4TransformArray
    ( D3DXVECTOR4 *pOut, UINT OutStride, CONST D3DXVECTOR4 *pV, UINT VStride, CONST D3DXMATRIX *pM, UINT n );

#ifdef __cplusplus
}
#endif


//--------------------------
// 4D Matrix
//--------------------------

// inline

D3DXMATRIX* D3DXMatrixIdentity
    ( D3DXMATRIX *pOut );

BOOL D3DXMatrixIsIdentity
    ( CONST D3DXMATRIX *pM );


// non-inline
#ifdef __cplusplus
extern "C" {
#endif

FLOAT WINAPI D3DXMatrixDeterminant
    ( CONST D3DXMATRIX *pM );

HRESULT WINAPI D3DXMatrixDecompose
    ( D3DXVECTOR3 *pOutScale, D3DXQUATERNION *pOutRotation, 
	  D3DXVECTOR3 *pOutTranslation, CONST D3DXMATRIX *pM );

D3DXMATRIX* WINAPI D3DXMatrixTranspose
    ( D3DXMATRIX *pOut, CONST D3DXMATRIX *pM );

// Matrix multiplication.  The result represents the transformation M2
// followed by the transformation M1.  (Out = M1 * M2)
D3DXMATRIX* WINAPI D3DXMatrixMultiply
    ( D3DXMATRIX *pOut, CONST D3DXMATRIX *pM1, CONST D3DXMATRIX *pM2 );

// Matrix multiplication, followed by a transpose. (Out = T(M1 * M2))
D3DXMATRIX* WINAPI D3DXMatrixMultiplyTranspose
    ( D3DXMATRIX *pOut, CONST D3DXMATRIX *pM1, CONST D3DXMATRIX *pM2 );

// Calculate inverse of matrix.  Inversion my fail, in which case NULL will
// be returned.  The determinant of pM is also returned it pfDeterminant
// is non-NULL.
D3DXMATRIX* WINAPI D3DXMatrixInverse
    ( D3DXMATRIX *pOut, FLOAT *pDeterminant, CONST D3DXMATRIX *pM );

// Build a matrix which scales by (sx, sy, sz)
D3DXMATRIX* WINAPI D3DXMatrixScaling
    ( D3DXMATRIX *pOut, FLOAT sx, FLOAT sy, FLOAT sz );

// Build a matrix which translates by (x, y, z)
D3DXMATRIX* WINAPI D3DXMatrixTranslation
    ( D3DXMATRIX *pOut, FLOAT x, FLOAT y, FLOAT z );

// Build a matrix which rotates around the X axis
D3DXMATRIX* WINAPI D3DXMatrixRotationX
    ( D3DXMATRIX *pOut, FLOAT Angle );

// Build a matrix which rotates around the Y axis
D3DXMATRIX* WINAPI D3DXMatrixRotationY
    ( D3DXMATRIX *pOut, FLOAT Angle );

// Build a matrix which rotates around the Z axis
D3DXMATRIX* WINAPI D3DXMatrixRotationZ
    ( D3DXMATRIX *pOut, FLOAT Angle );

// Build a matrix which rotates around an arbitrary axis
D3DXMATRIX* WINAPI D3DXMatrixRotationAxis
    ( D3DXMATRIX *pOut, CONST D3DXVECTOR3 *pV, FLOAT Angle );

// Build a matrix from a quaternion
D3DXMATRIX* WINAPI D3DXMatrixRotationQuaternion
    ( D3DXMATRIX *pOut, CONST D3DXQUATERNION *pQ);

// Yaw around the Y axis, a pitch around the X axis,
// and a roll around the Z axis.
D3DXMATRIX* WINAPI D3DXMatrixRotationYawPitchRoll
    ( D3DXMATRIX *pOut, FLOAT Yaw, FLOAT Pitch, FLOAT Roll );

// Build transformation matrix.  NULL arguments are treated as identity.
// Mout = Msc-1 * Msr-1 * Ms * Msr * Msc * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WINAPI D3DXMatrixTransformation
    ( D3DXMATRIX *pOut, CONST D3DXVECTOR3 *pScalingCenter,
      CONST D3DXQUATERNION *pScalingRotation, CONST D3DXVECTOR3 *pScaling,
      CONST D3DXVECTOR3 *pRotationCenter, CONST D3DXQUATERNION *pRotation,
      CONST D3DXVECTOR3 *pTranslation);

// Build 2D transformation matrix in XY plane.  NULL arguments are treated as identity.
// Mout = Msc-1 * Msr-1 * Ms * Msr * Msc * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WINAPI D3DXMatrixTransformation2D
    ( D3DXMATRIX *pOut, CONST D3DXVECTOR2* pScalingCenter, 
      FLOAT ScalingRotation, CONST D3DXVECTOR2* pScaling, 
      CONST D3DXVECTOR2* pRotationCenter, FLOAT Rotation, 
      CONST D3DXVECTOR2* pTranslation);

// Build affine transformation matrix.  NULL arguments are treated as identity.
// Mout = Ms * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WINAPI D3DXMatrixAffineTransformation
    ( D3DXMATRIX *pOut, FLOAT Scaling, CONST D3DXVECTOR3 *pRotationCenter,
      CONST D3DXQUATERNION *pRotation, CONST D3DXVECTOR3 *pTranslation);

// Build 2D affine transformation matrix in XY plane.  NULL arguments are treated as identity.
// Mout = Ms * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* WINAPI D3DXMatrixAffineTransformation2D
    ( D3DXMATRIX *pOut, FLOAT Scaling, CONST D3DXVECTOR2* pRotationCenter, 
      FLOAT Rotation, CONST D3DXVECTOR2* pTranslation);

// Build a lookat matrix. (right-handed)
D3DXMATRIX* WINAPI D3DXMatrixLookAtRH
    ( D3DXMATRIX *pOut, CONST D3DXVECTOR3 *pEye, CONST D3DXVECTOR3 *pAt,
      CONST D3DXVECTOR3 *pUp );

// Build a lookat matrix. (left-handed)
D3DXMATRIX* WINAPI D3DXMatrixLookAtLH
    ( D3DXMATRIX *pOut, CONST D3DXVECTOR3 *pEye, CONST D3DXVECTOR3 *pAt,
      CONST D3DXVECTOR3 *pUp );

// Build a perspective projection matrix. (right-handed)
D3DXMATRIX* WINAPI D3DXMatrixPerspectiveRH
    ( D3DXMATRIX *pOut, FLOAT w, FLOAT h, FLOAT zn, FLOAT zf );

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* WINAPI D3DXMatrixPerspectiveLH
    ( D3DXMATRIX *pOut, FLOAT w, FLOAT h, FLOAT zn, FLOAT zf );

// Build a perspective projection matrix. (right-handed)
D3DXMATRIX* WINAPI D3DXMatrixPerspectiveFovRH
    ( D3DXMATRIX *pOut, FLOAT fovy, FLOAT Aspect, FLOAT zn, FLOAT zf );

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* WINAPI D3DXMatrixPerspectiveFovLH
    ( D3DXMATRIX *pOut, FLOAT fovy, FLOAT Aspect, FLOAT zn, FLOAT zf );

// Build a perspective projection matrix. (right-handed)
D3DXMATRIX* WINAPI D3DXMatrixPerspectiveOffCenterRH
    ( D3DXMATRIX *pOut, FLOAT l, FLOAT r, FLOAT b, FLOAT t, FLOAT zn,
      FLOAT zf );

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* WINAPI D3DXMatrixPerspectiveOffCenterLH
    ( D3DXMATRIX *pOut, FLOAT l, FLOAT r, FLOAT b, FLOAT t, FLOAT zn,
      FLOAT zf );

// Build an ortho projection matrix. (right-handed)
D3DXMATRIX* WINAPI D3DXMatrixOrthoRH
    ( D3DXMATRIX *pOut, FLOAT w, FLOAT h, FLOAT zn, FLOAT zf );

// Build an ortho projection matrix. (left-handed)
D3DXMATRIX* WINAPI D3DXMatrixOrthoLH
    ( D3DXMATRIX *pOut, FLOAT w, FLOAT h, FLOAT zn, FLOAT zf );

// Build an ortho projection matrix. (right-handed)
D3DXMATRIX* WINAPI D3DXMatrixOrthoOffCenterRH
    ( D3DXMATRIX *pOut, FLOAT l, FLOAT r, FLOAT b, FLOAT t, FLOAT zn,
      FLOAT zf );

// Build an ortho projection matrix. (left-handed)
D3DXMATRIX* WINAPI D3DXMatrixOrthoOffCenterLH
    ( D3DXMATRIX *pOut, FLOAT l, FLOAT r, FLOAT b, FLOAT t, FLOAT zn,
      FLOAT zf );

// Build a matrix which flattens geometry into a plane, as if casting
// a shadow from a light.
D3DXMATRIX* WINAPI D3DXMatrixShadow
    ( D3DXMATRIX *pOut, CONST D3DXVECTOR4 *pLight,
      CONST D3DXPLANE *pPlane );

// Build a matrix which reflects the coordinate system about a plane
D3DXMATRIX* WINAPI D3DXMatrixReflect
    ( D3DXMATRIX *pOut, CONST D3DXPLANE *pPlane );

#ifdef __cplusplus
}
#endif


//--------------------------
// Quaternion
//--------------------------

// inline

FLOAT D3DXQuaternionLength
    ( CONST D3DXQUATERNION *pQ );

// Length squared, or "norm"
FLOAT D3DXQuaternionLengthSq
    ( CONST D3DXQUATERNION *pQ );

FLOAT D3DXQuaternionDot
    ( CONST D3DXQUATERNION *pQ1, CONST D3DXQUATERNION *pQ2 );

// (0, 0, 0, 1)
D3DXQUATERNION* D3DXQuaternionIdentity
    ( D3DXQUATERNION *pOut );

BOOL D3DXQuaternionIsIdentity
    ( CONST D3DXQUATERNION *pQ );

// (-x, -y, -z, w)
D3DXQUATERNION* D3DXQuaternionConjugate
    ( D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ );


// non-inline
#ifdef __cplusplus
extern "C" {
#endif

// Compute a quaternin's axis and angle of rotation. Expects unit quaternions.
void WINAPI D3DXQuaternionToAxisAngle
    ( CONST D3DXQUATERNION *pQ, D3DXVECTOR3 *pAxis, FLOAT *pAngle );

// Build a quaternion from a rotation matrix.
D3DXQUATERNION* WINAPI D3DXQuaternionRotationMatrix
    ( D3DXQUATERNION *pOut, CONST D3DXMATRIX *pM);

// Rotation about arbitrary axis.
D3DXQUATERNION* WINAPI D3DXQuaternionRotationAxis
    ( D3DXQUATERNION *pOut, CONST D3DXVECTOR3 *pV, FLOAT Angle );

// Yaw around the Y axis, a pitch around the X axis,
// and a roll around the Z axis.
D3DXQUATERNION* WINAPI D3DXQuaternionRotationYawPitchRoll
    ( D3DXQUATERNION *pOut, FLOAT Yaw, FLOAT Pitch, FLOAT Roll );

// Quaternion multiplication.  The result represents the rotation Q2
// followed by the rotation Q1.  (Out = Q2 * Q1)
D3DXQUATERNION* WINAPI D3DXQuaternionMultiply
    ( D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ1,
      CONST D3DXQUATERNION *pQ2 );

D3DXQUATERNION* WINAPI D3DXQuaternionNormalize
    ( D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ );

// Conjugate and re-norm
D3DXQUATERNION* WINAPI D3DXQuaternionInverse
    ( D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ );

// Expects unit quaternions.
// if q = (cos(theta), sin(theta) * v); ln(q) = (0, theta * v)
D3DXQUATERNION* WINAPI D3DXQuaternionLn
    ( D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ );

// Expects pure quaternions. (w == 0)  w is ignored in calculation.
// if q = (0, theta * v); exp(q) = (cos(theta), sin(theta) * v)
D3DXQUATERNION* WINAPI D3DXQuaternionExp
    ( D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ );
      
// Spherical linear interpolation between Q1 (t == 0) and Q2 (t == 1).
// Expects unit quaternions.
D3DXQUATERNION* WINAPI D3DXQuaternionSlerp
    ( D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ1,
      CONST D3DXQUATERNION *pQ2, FLOAT t );

// Spherical quadrangle interpolation.
// Slerp(Slerp(Q1, C, t), Slerp(A, B, t), 2t(1-t))
D3DXQUATERNION* WINAPI D3DXQuaternionSquad
    ( D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ1,
      CONST D3DXQUATERNION *pA, CONST D3DXQUATERNION *pB,
      CONST D3DXQUATERNION *pC, FLOAT t );

// Setup control points for spherical quadrangle interpolation
// from Q1 to Q2.  The control points are chosen in such a way 
// to ensure the continuity of tangents with adjacent segments.
void WINAPI D3DXQuaternionSquadSetup
    ( D3DXQUATERNION *pAOut, D3DXQUATERNION *pBOut, D3DXQUATERNION *pCOut,
      CONST D3DXQUATERNION *pQ0, CONST D3DXQUATERNION *pQ1, 
      CONST D3DXQUATERNION *pQ2, CONST D3DXQUATERNION *pQ3 );

// Barycentric interpolation.
// Slerp(Slerp(Q1, Q2, f+g), Slerp(Q1, Q3, f+g), g/(f+g))
D3DXQUATERNION* WINAPI D3DXQuaternionBaryCentric
    ( D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ1,
      CONST D3DXQUATERNION *pQ2, CONST D3DXQUATERNION *pQ3,
      FLOAT f, FLOAT g );

#ifdef __cplusplus
}
#endif


//--------------------------
// Plane
//--------------------------

// inline

// ax + by + cz + dw
FLOAT D3DXPlaneDot
    ( CONST D3DXPLANE *pP, CONST D3DXVECTOR4 *pV);

// ax + by + cz + d
FLOAT D3DXPlaneDotCoord
    ( CONST D3DXPLANE *pP, CONST D3DXVECTOR3 *pV);

// ax + by + cz
FLOAT D3DXPlaneDotNormal
    ( CONST D3DXPLANE *pP, CONST D3DXVECTOR3 *pV);

D3DXPLANE* D3DXPlaneScale
    (D3DXPLANE *pOut, CONST D3DXPLANE *pP, FLOAT s);

// non-inline
#ifdef __cplusplus
extern "C" {
#endif

// Normalize plane (so that |a,b,c| == 1)
D3DXPLANE* WINAPI D3DXPlaneNormalize
    ( D3DXPLANE *pOut, CONST D3DXPLANE *pP);

// Find the intersection between a plane and a line.  If the line is
// parallel to the plane, NULL is returned.
D3DXVECTOR3* WINAPI D3DXPlaneIntersectLine
    ( D3DXVECTOR3 *pOut, CONST D3DXPLANE *pP, CONST D3DXVECTOR3 *pV1,
      CONST D3DXVECTOR3 *pV2);

// Construct a plane from a point and a normal
D3DXPLANE* WINAPI D3DXPlaneFromPointNormal
    ( D3DXPLANE *pOut, CONST D3DXVECTOR3 *pPoint, CONST D3DXVECTOR3 *pNormal);

// Construct a plane from 3 points
D3DXPLANE* WINAPI D3DXPlaneFromPoints
    ( D3DXPLANE *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2,
      CONST D3DXVECTOR3 *pV3);

// Transform a plane by a matrix.  The vector (a,b,c) must be normal.
// M should be the inverse transpose of the transformation desired.
D3DXPLANE* WINAPI D3DXPlaneTransform
    ( D3DXPLANE *pOut, CONST D3DXPLANE *pP, CONST D3DXMATRIX *pM );
    
// Transform an array of planes by a matrix.  The vectors (a,b,c) must be normal.
// M should be the inverse transpose of the transformation desired.
D3DXPLANE* WINAPI D3DXPlaneTransformArray
    ( D3DXPLANE *pOut, UINT OutStride, CONST D3DXPLANE *pP, UINT PStride, CONST D3DXMATRIX *pM, UINT n );

#ifdef __cplusplus
}
#endif


//--------------------------
// Color
//--------------------------

// inline

// (1-r, 1-g, 1-b, a)
D3DXCOLOR* D3DXColorNegative
    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC);

D3DXCOLOR* D3DXColorAdd
    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2);

D3DXCOLOR* D3DXColorSubtract
    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2);

D3DXCOLOR* D3DXColorScale
    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC, FLOAT s);

// (r1*r2, g1*g2, b1*b2, a1*a2)
D3DXCOLOR* D3DXColorModulate
    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2);

// Linear interpolation of r,g,b, and a. C1 + s(C2-C1)
D3DXCOLOR* D3DXColorLerp
    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2, FLOAT s);

// non-inline
#ifdef __cplusplus
extern "C" {
#endif

// Interpolate r,g,b between desaturated color and color.
// DesaturatedColor + s(Color - DesaturatedColor)
D3DXCOLOR* WINAPI D3DXColorAdjustSaturation
    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC, FLOAT s);

// Interpolate r,g,b between 50% grey and color.  Grey + s(Color - Grey)
D3DXCOLOR* WINAPI D3DXColorAdjustContrast
    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC, FLOAT c);

#ifdef __cplusplus
}
#endif




//--------------------------
// Misc
//--------------------------

#ifdef __cplusplus
extern "C" {
#endif

// Calculate Fresnel term given the cosine of theta (likely obtained by
// taking the dot of two normals), and the refraction index of the material.
FLOAT WINAPI D3DXFresnelTerm
    (FLOAT CosTheta, FLOAT RefractionIndex);     

#ifdef __cplusplus
}
#endif



//===========================================================================
//
//    Matrix Stack
//
//===========================================================================

typedef interface ID3DXMatrixStack ID3DXMatrixStack;
typedef interface ID3DXMatrixStack *LPD3DXMATRIXSTACK;

// {C7885BA7-F990-4fe7-922D-8515E477DD85}
DEFINE_GUID(IID_ID3DXMatrixStack, 
0xc7885ba7, 0xf990, 0x4fe7, 0x92, 0x2d, 0x85, 0x15, 0xe4, 0x77, 0xdd, 0x85);


#undef INTERFACE
#define INTERFACE ID3DXMatrixStack

DECLARE_INTERFACE_(ID3DXMatrixStack, IUnknown)
{
    //
    // IUnknown methods
    //
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;

    //
    // ID3DXMatrixStack methods
    //

    // Pops the top of the stack, returns the current top
    // *after* popping the top.
    STDMETHOD(Pop)(THIS) PURE;

    // Pushes the stack by one, duplicating the current matrix.
    STDMETHOD(Push)(THIS) PURE;

    // Loads identity in the current matrix.
    STDMETHOD(LoadIdentity)(THIS) PURE;

    // Loads the given matrix into the current matrix
    STDMETHOD(LoadMatrix)(THIS_ CONST D3DXMATRIX* pM ) PURE;

    // Right-Multiplies the given matrix to the current matrix.
    // (transformation is about the current world origin)
    STDMETHOD(MultMatrix)(THIS_ CONST D3DXMATRIX* pM ) PURE;

    // Left-Multiplies the given matrix to the current matrix
    // (transformation is about the local origin of the object)
    STDMETHOD(MultMatrixLocal)(THIS_ CONST D3DXMATRIX* pM ) PURE;

    // Right multiply the current matrix with the computed rotation
    // matrix, counterclockwise about the given axis with the given angle.
    // (rotation is about the current world origin)
    STDMETHOD(RotateAxis)
        (THIS_ CONST D3DXVECTOR3* pV, FLOAT Angle) PURE;

    // Left multiply the current matrix with the computed rotation
    // matrix, counterclockwise about the given axis with the given angle.
    // (rotation is about the local origin of the object)
    STDMETHOD(RotateAxisLocal)
        (THIS_ CONST D3DXVECTOR3* pV, FLOAT Angle) PURE;

    // Right multiply the current matrix with the computed rotation
    // matrix. All angles are counterclockwise. (rotation is about the
    // current world origin)

    // The rotation is composed of a yaw around the Y axis, a pitch around
    // the X axis, and a roll around the Z axis.
    STDMETHOD(RotateYawPitchRoll)
        (THIS_ FLOAT Yaw, FLOAT Pitch, FLOAT Roll) PURE;

    // Left multiply the current matrix with the computed rotation
    // matrix. All angles are counterclockwise. (rotation is about the
    // local origin of the object)

    // The rotation is composed of a yaw around the Y axis, a pitch around
    // the X axis, and a roll around the Z axis.
    STDMETHOD(RotateYawPitchRollLocal)
        (THIS_ FLOAT Yaw, FLOAT Pitch, FLOAT Roll) PURE;

    // Right multiply the current matrix with the computed scale
    // matrix. (transformation is about the current world origin)
    STDMETHOD(Scale)(THIS_ FLOAT x, FLOAT y, FLOAT z) PURE;

    // Left multiply the current matrix with the computed scale
    // matrix. (transformation is about the local origin of the object)
    STDMETHOD(ScaleLocal)(THIS_ FLOAT x, FLOAT y, FLOAT z) PURE;

    // Right multiply the current matrix with the computed translation
    // matrix. (transformation is about the current world origin)
    STDMETHOD(Translate)(THIS_ FLOAT x, FLOAT y, FLOAT z ) PURE;

    // Left multiply the current matrix with the computed translation
    // matrix. (transformation is about the local origin of the object)
    STDMETHOD(TranslateLocal)(THIS_ FLOAT x, FLOAT y, FLOAT z) PURE;

    // Obtain the current matrix at the top of the stack
    STDMETHOD_(D3DXMATRIX*, GetTop)(THIS) PURE;
};

#ifdef __cplusplus
extern "C" {
#endif

HRESULT WINAPI 
    D3DXCreateMatrixStack( 
        DWORD               Flags, 
        LPD3DXMATRIXSTACK*  ppStack);

#ifdef __cplusplus
}
#endif

//===========================================================================
//
//  Spherical Harmonic Runtime Routines
//
// NOTE:
//  * Most of these functions can take the same object as in and out parameters.
//    The exceptions are the rotation functions.  
//
//  * Out parameters are typically also returned as return values, so that
//    the output of one function may be used as a parameter to another.
//
//============================================================================


// non-inline
#ifdef __cplusplus
extern "C" {
#endif

//============================================================================
//
//  Basic Spherical Harmonic math routines
//
//============================================================================

#define D3DXSH_MINORDER 2
#define D3DXSH_MAXORDER 6

//============================================================================
//
//  D3DXSHEvalDirection:
//  --------------------
//  Evaluates the Spherical Harmonic basis functions
//
//  Parameters:
//   pOut
//      Output SH coefficients - basis function Ylm is stored at l*l + m+l
//      This is the pointer that is returned.
//   Order
//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
//   pDir
//      Direction to evaluate in - assumed to be normalized
//
//============================================================================

FLOAT* WINAPI D3DXSHEvalDirection
    (  FLOAT *pOut, UINT Order, CONST D3DXVECTOR3 *pDir );
    
//============================================================================
//
//  D3DXSHRotate:
//  --------------------
//  Rotates SH vector by a rotation matrix
//
//  Parameters:
//   pOut
//      Output SH coefficients - basis function Ylm is stored at l*l + m+l
//      This is the pointer that is returned (should not alias with pIn.)
//   Order
//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
//   pMatrix
//      Matrix used for rotation - rotation sub matrix should be orthogonal
//      and have a unit determinant.
//   pIn
//      Input SH coeffs (rotated), incorect results if this is also output.
//
//============================================================================

FLOAT* WINAPI D3DXSHRotate
    ( FLOAT *pOut, UINT Order, CONST D3DXMATRIX *pMatrix, CONST FLOAT *pIn );
    
//============================================================================
//
//  D3DXSHRotateZ:
//  --------------------
//  Rotates the SH vector in the Z axis by an angle
//
//  Parameters:
//   pOut
//      Output SH coefficients - basis function Ylm is stored at l*l + m+l
//      This is the pointer that is returned (should not alias with pIn.)
//   Order
//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
//   Angle
//      Angle in radians to rotate around the Z axis.
//   pIn
//      Input SH coeffs (rotated), incorect results if this is also output.
//
//============================================================================


FLOAT* WINAPI D3DXSHRotateZ
    ( FLOAT *pOut, UINT Order, FLOAT Angle, CONST FLOAT *pIn );
    
//============================================================================
//
//  D3DXSHAdd:
//  --------------------
//  Adds two SH vectors, pOut[i] = pA[i] + pB[i];
//
//  Parameters:
//   pOut
//      Output SH coefficients - basis function Ylm is stored at l*l + m+l
//      This is the pointer that is returned.
//   Order
//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
//   pA
//      Input SH coeffs.
//   pB
//      Input SH coeffs (second vector.)
//
//============================================================================

FLOAT* WINAPI D3DXSHAdd
    ( FLOAT *pOut, UINT Order, CONST FLOAT *pA, CONST FLOAT *pB );

//============================================================================
//
//  D3DXSHScale:
//  --------------------
//  Adds two SH vectors, pOut[i] = pA[i]*Scale;
//
//  Parameters:
//   pOut
//      Output SH coefficients - basis function Ylm is stored at l*l + m+l
//      This is the pointer that is returned.
//   Order
//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
//   pIn
//      Input SH coeffs.
//   Scale
//      Scale factor.
//
//============================================================================

FLOAT* WINAPI D3DXSHScale
    ( FLOAT *pOut, UINT Order, CONST FLOAT *pIn, CONST FLOAT Scale );
    
//============================================================================
//
//  D3DXSHDot:
//  --------------------
//  Computes the dot product of two SH vectors
//
//  Parameters:
//   Order
//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
//   pA
//      Input SH coeffs.
//   pB
//      Second set of input SH coeffs.
//
//============================================================================

FLOAT WINAPI D3DXSHDot
    ( UINT Order, CONST FLOAT *pA, CONST FLOAT *pB );

//============================================================================
//
//  D3DXSHMultiply[O]:
//  --------------------
//  Computes the product of two functions represented using SH (f and g), where:
//  pOut[i] = int(y_i(s) * f(s) * g(s)), where y_i(s) is the ith SH basis
//  function, f(s) and g(s) are SH functions (sum_i(y_i(s)*c_i)).  The order O
//  determines the lengths of the arrays, where there should always be O^2 
//  coefficients.  In general the product of two SH functions of order O generates
//  and SH function of order 2*O - 1, but we truncate the result.  This means
//  that the product commutes (f*g == g*f) but doesn't associate 
//  (f*(g*h) != (f*g)*h.
//
//  Parameters:
//   pOut
//      Output SH coefficients - basis function Ylm is stored at l*l + m+l
//      This is the pointer that is returned.
//   pF
//      Input SH coeffs for first function.
//   pG
//      Second set of input SH coeffs.
//
//============================================================================

FLOAT* WINAPI D3DXSHMultiply2( FLOAT *pOut, CONST FLOAT *pF, CONST FLOAT *pG);
FLOAT* WINAPI D3DXSHMultiply3( FLOAT *pOut, CONST FLOAT *pF, CONST FLOAT *pG);
FLOAT* WINAPI D3DXSHMultiply4( FLOAT *pOut, CONST FLOAT *pF, CONST FLOAT *pG);
FLOAT* WINAPI D3DXSHMultiply5( FLOAT *pOut, CONST FLOAT *pF, CONST FLOAT *pG);
FLOAT* WINAPI D3DXSHMultiply6( FLOAT *pOut, CONST FLOAT *pF, CONST FLOAT *pG);


//============================================================================
//
//  Basic Spherical Harmonic lighting routines
//
//============================================================================

//============================================================================
//
//  D3DXSHEvalDirectionalLight:
//  --------------------
//  Evaluates a directional light and returns spectral SH data.  The output 
//  vector is computed so that if the intensity of R/G/B is unit the resulting
//  exit radiance of a point directly under the light on a diffuse object with
//  an albedo of 1 would be 1.0.  This will compute 3 spectral samples, pROut
//  has to be specified, while pGout and pBout are optional.
//
//  Parameters:
//   Order
//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
//   pDir
//      Direction light is coming from (assumed to be normalized.)
//   RIntensity
//      Red intensity of light.
//   GIntensity
//      Green intensity of light.
//   BIntensity
//      Blue intensity of light.
//   pROut
//      Output SH vector for Red.
//   pGOut
//      Output SH vector for Green (optional.)
//   pBOut
//      Output SH vector for Blue (optional.)        
//
//============================================================================

HRESULT WINAPI D3DXSHEvalDirectionalLight
    ( UINT Order, CONST D3DXVECTOR3 *pDir, 
      FLOAT RIntensity, FLOAT GIntensity, FLOAT BIntensity,
      FLOAT *pROut, FLOAT *pGOut, FLOAT *pBOut );

//============================================================================
//
//  D3DXSHEvalSphericalLight:
//  --------------------
//  Evaluates a spherical light and returns spectral SH data.  There is no 
//  normalization of the intensity of the light like there is for directional
//  lights, care has to be taken when specifiying the intensities.  This will 
//  compute 3 spectral samples, pROut has to be specified, while pGout and 
//  pBout are optional.
//
//  Parameters:
//   Order
//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
//   pPos
//      Position of light - reciever is assumed to be at the origin.
//   Radius
//      Radius of the spherical light source.
//   RIntensity
//      Red intensity of light.
//   GIntensity
//      Green intensity of light.
//   BIntensity
//      Blue intensity of light.
//   pROut
//      Output SH vector for Red.
//   pGOut
//      Output SH vector for Green (optional.)
//   pBOut
//      Output SH vector for Blue (optional.)        
//
//============================================================================

HRESULT WINAPI D3DXSHEvalSphericalLight
    ( UINT Order, CONST D3DXVECTOR3 *pPos, FLOAT Radius,
      FLOAT RIntensity, FLOAT GIntensity, FLOAT BIntensity,
      FLOAT *pROut, FLOAT *pGOut, FLOAT *pBOut );

//============================================================================
//
//  D3DXSHEvalConeLight:
//  --------------------
//  Evaluates a light that is a cone of constant intensity and returns spectral
//  SH data.  The output vector is computed so that if the intensity of R/G/B is
//  unit the resulting exit radiance of a point directly under the light oriented
//  in the cone direction on a diffuse object with an albedo of 1 would be 1.0.
//  This will compute 3 spectral samples, pROut has to be specified, while pGout
//  and pBout are optional.
//
//  Parameters:
//   Order
//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
//   pDir
//      Direction light is coming from (assumed to be normalized.)
//   Radius
//      Radius of cone in radians.
//   RIntensity
//      Red intensity of light.
//   GIntensity
//      Green intensity of light.
//   BIntensity
//      Blue intensity of light.
//   pROut
//      Output SH vector for Red.
//   pGOut
//      Output SH vector for Green (optional.)
//   pBOut
//      Output SH vector for Blue (optional.)        
//
//============================================================================

HRESULT WINAPI D3DXSHEvalConeLight
    ( UINT Order, CONST D3DXVECTOR3 *pDir, FLOAT Radius,
      FLOAT RIntensity, FLOAT GIntensity, FLOAT BIntensity,
      FLOAT *pROut, FLOAT *pGOut, FLOAT *pBOut );
      
//============================================================================
//
//  D3DXSHEvalHemisphereLight:
//  --------------------
//  Evaluates a light that is a linear interpolant between two colors over the
//  sphere.  The interpolant is linear along the axis of the two points, not
//  over the surface of the sphere (ie: if the axis was (0,0,1) it is linear in
//  Z, not in the azimuthal angle.)  The resulting spherical lighting function
//  is normalized so that a point on a perfectly diffuse surface with no
//  shadowing and a normal pointed in the direction pDir would result in exit
//  radiance with a value of 1 if the top color was white and the bottom color
//  was black.  This is a very simple model where Top represents the intensity 
//  of the "sky" and Bottom represents the intensity of the "ground".
//
//  Parameters:
//   Order
//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
//   pDir
//      Axis of the hemisphere.
//   Top
//      Color of the upper hemisphere.
//   Bottom
//      Color of the lower hemisphere.
//   pROut
//      Output SH vector for Red.
//   pGOut
//      Output SH vector for Green
//   pBOut
//      Output SH vector for Blue        
//
//============================================================================

HRESULT WINAPI D3DXSHEvalHemisphereLight
    ( UINT Order, CONST D3DXVECTOR3 *pDir, D3DXCOLOR Top, D3DXCOLOR Bottom,
      FLOAT *pROut, FLOAT *pGOut, FLOAT *pBOut );

//============================================================================
//
//  Basic Spherical Harmonic projection routines
//
//============================================================================

//============================================================================
//
//  D3DXSHProjectCubeMap:
//  --------------------
//  Projects a function represented on a cube map into spherical harmonics.
//
//  Parameters:
//   Order
//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
//   pCubeMap
//      CubeMap that is going to be projected into spherical harmonics
//   pROut
//      Output SH vector for Red.
//   pGOut
//      Output SH vector for Green
//   pBOut
//      Output SH vector for Blue        
//
//============================================================================

HRESULT WINAPI D3DXSHProjectCubeMap
    ( UINT uOrder, LPDIRECT3DCUBETEXTURE9 pCubeMap,
      FLOAT *pROut, FLOAT *pGOut, FLOAT *pBOut );


#ifdef __cplusplus
}
#endif


#include "d3dx9math.inl"

#if _MSC_VER >= 1200
#pragma warning(pop)
#else
#pragma warning(default:4201)
#endif

#endif // __D3DX9MATH_H__



//////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) Microsoft Corporation.  All Rights Reserved.
//
//  File:       d3dx9math.inl
//  Content:    D3DX math inline functions
//
//////////////////////////////////////////////////////////////////////////////

#ifndef __D3DX9MATH_INL__
#define __D3DX9MATH_INL__

//===========================================================================
//
// Inline Class Methods
//
//===========================================================================

#ifdef __cplusplus

//--------------------------
// Float16
//--------------------------

D3DXINLINE
D3DXFLOAT16::D3DXFLOAT16( FLOAT f )
{
    D3DXFloat32To16Array(this, &f, 1);
}

D3DXINLINE
D3DXFLOAT16::D3DXFLOAT16( CONST D3DXFLOAT16& f )
{
    value = f.value;
}

// casting
D3DXINLINE
D3DXFLOAT16::operator FLOAT ()
{
    FLOAT f;
    D3DXFloat16To32Array(&f, this, 1);
    return f;
}

// binary operators
D3DXINLINE BOOL
D3DXFLOAT16::operator == ( CONST D3DXFLOAT16& f ) const
{
    return value == f.value;
}

D3DXINLINE BOOL
D3DXFLOAT16::operator != ( CONST D3DXFLOAT16& f ) const
{
    return value != f.value;
}


//--------------------------
// 2D Vector
//--------------------------

D3DXINLINE
D3DXVECTOR2::D3DXVECTOR2( CONST FLOAT *pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    x = pf[0];
    y = pf[1];
}

D3DXINLINE
D3DXVECTOR2::D3DXVECTOR2( CONST D3DXFLOAT16 *pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    D3DXFloat16To32Array(&x, pf, 2);    
}

D3DXINLINE
D3DXVECTOR2::D3DXVECTOR2( FLOAT fx, FLOAT fy )
{
    x = fx;
    y = fy;
}


// casting
D3DXINLINE
D3DXVECTOR2::operator FLOAT* ()
{
    return (FLOAT *) &x;
}

D3DXINLINE
D3DXVECTOR2::operator CONST FLOAT* () const
{
    return (CONST FLOAT *) &x;
}


// assignment operators
D3DXINLINE D3DXVECTOR2&
D3DXVECTOR2::operator += ( CONST D3DXVECTOR2& v )
{
    x += v.x;
    y += v.y;
    return *this;
}

D3DXINLINE D3DXVECTOR2&
D3DXVECTOR2::operator -= ( CONST D3DXVECTOR2& v )
{
    x -= v.x;
    y -= v.y;
    return *this;
}

D3DXINLINE D3DXVECTOR2&
D3DXVECTOR2::operator *= ( FLOAT f )
{
    x *= f;
    y *= f;
    return *this;
}

D3DXINLINE D3DXVECTOR2&
D3DXVECTOR2::operator /= ( FLOAT f )
{
    FLOAT fInv = 1.0f / f;
    x *= fInv;
    y *= fInv;
    return *this;
}


// unary operators
D3DXINLINE D3DXVECTOR2
D3DXVECTOR2::operator + () const
{
    return *this;
}

D3DXINLINE D3DXVECTOR2
D3DXVECTOR2::operator - () const
{
    return D3DXVECTOR2(-x, -y);
}


// binary operators
D3DXINLINE D3DXVECTOR2
D3DXVECTOR2::operator + ( CONST D3DXVECTOR2& v ) const
{
    return D3DXVECTOR2(x + v.x, y + v.y);
}

D3DXINLINE D3DXVECTOR2
D3DXVECTOR2::operator - ( CONST D3DXVECTOR2& v ) const
{
    return D3DXVECTOR2(x - v.x, y - v.y);
}

D3DXINLINE D3DXVECTOR2
D3DXVECTOR2::operator * ( FLOAT f ) const
{
    return D3DXVECTOR2(x * f, y * f);
}

D3DXINLINE D3DXVECTOR2
D3DXVECTOR2::operator / ( FLOAT f ) const
{
    FLOAT fInv = 1.0f / f;
    return D3DXVECTOR2(x * fInv, y * fInv);
}

D3DXINLINE D3DXVECTOR2
operator * ( FLOAT f, CONST D3DXVECTOR2& v )
{
    return D3DXVECTOR2(f * v.x, f * v.y);
}

D3DXINLINE BOOL
D3DXVECTOR2::operator == ( CONST D3DXVECTOR2& v ) const
{
    return x == v.x && y == v.y;
}

D3DXINLINE BOOL
D3DXVECTOR2::operator != ( CONST D3DXVECTOR2& v ) const
{
    return x != v.x || y != v.y;
}



//--------------------------
// 2D Vector (16 bit)
//--------------------------

D3DXINLINE
D3DXVECTOR2_16F::D3DXVECTOR2_16F( CONST FLOAT *pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    D3DXFloat32To16Array(&x, pf, 2);
}

D3DXINLINE
D3DXVECTOR2_16F::D3DXVECTOR2_16F( CONST D3DXFLOAT16 *pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    *((DWORD *) &x) = *((DWORD *) &pf[0]);
}

D3DXINLINE
D3DXVECTOR2_16F::D3DXVECTOR2_16F( CONST D3DXFLOAT16 &fx, CONST D3DXFLOAT16 &fy )
{
    x = fx;
    y = fy;
}


// casting
D3DXINLINE
D3DXVECTOR2_16F::operator D3DXFLOAT16* ()
{
    return (D3DXFLOAT16*) &x;
}

D3DXINLINE
D3DXVECTOR2_16F::operator CONST D3DXFLOAT16* () const
{
    return (CONST D3DXFLOAT16*) &x;
}


// binary operators
D3DXINLINE BOOL 
D3DXVECTOR2_16F::operator == ( CONST D3DXVECTOR2_16F &v ) const
{
    return *((DWORD *) &x) == *((DWORD *) &v.x);
}

D3DXINLINE BOOL 
D3DXVECTOR2_16F::operator != ( CONST D3DXVECTOR2_16F &v ) const
{
    return *((DWORD *) &x) != *((DWORD *) &v.x);
}


//--------------------------
// 3D Vector
//--------------------------
D3DXINLINE
D3DXVECTOR3::D3DXVECTOR3( CONST FLOAT *pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    x = pf[0];
    y = pf[1];
    z = pf[2];
}

D3DXINLINE
D3DXVECTOR3::D3DXVECTOR3( CONST D3DVECTOR& v )
{
    x = v.x;
    y = v.y;
    z = v.z;
}

D3DXINLINE
D3DXVECTOR3::D3DXVECTOR3( CONST D3DXFLOAT16 *pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    D3DXFloat16To32Array(&x, pf, 3);
}

D3DXINLINE
D3DXVECTOR3::D3DXVECTOR3( FLOAT fx, FLOAT fy, FLOAT fz )
{
    x = fx;
    y = fy;
    z = fz;
}


// casting
D3DXINLINE
D3DXVECTOR3::operator FLOAT* ()
{
    return (FLOAT *) &x;
}

D3DXINLINE
D3DXVECTOR3::operator CONST FLOAT* () const
{
    return (CONST FLOAT *) &x;
}


// assignment operators
D3DXINLINE D3DXVECTOR3&
D3DXVECTOR3::operator += ( CONST D3DXVECTOR3& v )
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

D3DXINLINE D3DXVECTOR3&
D3DXVECTOR3::operator -= ( CONST D3DXVECTOR3& v )
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

D3DXINLINE D3DXVECTOR3&
D3DXVECTOR3::operator *= ( FLOAT f )
{
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

D3DXINLINE D3DXVECTOR3&
D3DXVECTOR3::operator /= ( FLOAT f )
{
    FLOAT fInv = 1.0f / f;
    x *= fInv;
    y *= fInv;
    z *= fInv;
    return *this;
}


// unary operators
D3DXINLINE D3DXVECTOR3
D3DXVECTOR3::operator + () const
{
    return *this;
}

D3DXINLINE D3DXVECTOR3
D3DXVECTOR3::operator - () const
{
    return D3DXVECTOR3(-x, -y, -z);
}


// binary operators
D3DXINLINE D3DXVECTOR3
D3DXVECTOR3::operator + ( CONST D3DXVECTOR3& v ) const
{
    return D3DXVECTOR3(x + v.x, y + v.y, z + v.z);
}

D3DXINLINE D3DXVECTOR3
D3DXVECTOR3::operator - ( CONST D3DXVECTOR3& v ) const
{
    return D3DXVECTOR3(x - v.x, y - v.y, z - v.z);
}

D3DXINLINE D3DXVECTOR3
D3DXVECTOR3::operator * ( FLOAT f ) const
{
    return D3DXVECTOR3(x * f, y * f, z * f);
}

D3DXINLINE D3DXVECTOR3
D3DXVECTOR3::operator / ( FLOAT f ) const
{
    FLOAT fInv = 1.0f / f;
    return D3DXVECTOR3(x * fInv, y * fInv, z * fInv);
}


D3DXINLINE D3DXVECTOR3
operator * ( FLOAT f, CONST struct D3DXVECTOR3& v )
{
    return D3DXVECTOR3(f * v.x, f * v.y, f * v.z);
}


D3DXINLINE BOOL
D3DXVECTOR3::operator == ( CONST D3DXVECTOR3& v ) const
{
    return x == v.x && y == v.y && z == v.z;
}

D3DXINLINE BOOL
D3DXVECTOR3::operator != ( CONST D3DXVECTOR3& v ) const
{
    return x != v.x || y != v.y || z != v.z;
}



//--------------------------
// 3D Vector (16 bit)
//--------------------------

D3DXINLINE
D3DXVECTOR3_16F::D3DXVECTOR3_16F( CONST FLOAT *pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    D3DXFloat32To16Array(&x, pf, 3);
}

D3DXINLINE
D3DXVECTOR3_16F::D3DXVECTOR3_16F( CONST D3DVECTOR& v )
{
    D3DXFloat32To16Array(&x, &v.x, 1);
    D3DXFloat32To16Array(&y, &v.y, 1);
    D3DXFloat32To16Array(&z, &v.z, 1);
}

D3DXINLINE
D3DXVECTOR3_16F::D3DXVECTOR3_16F( CONST D3DXFLOAT16 *pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    *((DWORD *) &x) = *((DWORD *) &pf[0]);
    *((WORD  *) &z) = *((WORD  *) &pf[2]);
}

D3DXINLINE
D3DXVECTOR3_16F::D3DXVECTOR3_16F( CONST D3DXFLOAT16 &fx, CONST D3DXFLOAT16 &fy, CONST D3DXFLOAT16 &fz )
{
    x = fx;
    y = fy;
    z = fz;
}


// casting
D3DXINLINE
D3DXVECTOR3_16F::operator D3DXFLOAT16* ()
{
    return (D3DXFLOAT16*) &x;
}

D3DXINLINE
D3DXVECTOR3_16F::operator CONST D3DXFLOAT16* () const
{
    return (CONST D3DXFLOAT16*) &x;
}


// binary operators
D3DXINLINE BOOL 
D3DXVECTOR3_16F::operator == ( CONST D3DXVECTOR3_16F &v ) const
{
    return *((DWORD *) &x) == *((DWORD *) &v.x) &&
           *((WORD  *) &z) == *((WORD  *) &v.z);
}

D3DXINLINE BOOL 
D3DXVECTOR3_16F::operator != ( CONST D3DXVECTOR3_16F &v ) const
{
    return *((DWORD *) &x) != *((DWORD *) &v.x) ||
           *((WORD  *) &z) != *((WORD  *) &v.z);
}


//--------------------------
// 4D Vector
//--------------------------
D3DXINLINE
D3DXVECTOR4::D3DXVECTOR4( CONST FLOAT *pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    x = pf[0];
    y = pf[1];
    z = pf[2];
    w = pf[3];
}

D3DXINLINE
D3DXVECTOR4::D3DXVECTOR4( CONST D3DXFLOAT16 *pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    D3DXFloat16To32Array(&x, pf, 4);
}

D3DXINLINE
D3DXVECTOR4::D3DXVECTOR4( CONST D3DVECTOR& v, FLOAT f )
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = f;
}

D3DXINLINE
D3DXVECTOR4::D3DXVECTOR4( FLOAT fx, FLOAT fy, FLOAT fz, FLOAT fw )
{
    x = fx;
    y = fy;
    z = fz;
    w = fw;
}


// casting
D3DXINLINE
D3DXVECTOR4::operator FLOAT* ()
{
    return (FLOAT *) &x;
}

D3DXINLINE
D3DXVECTOR4::operator CONST FLOAT* () const
{
    return (CONST FLOAT *) &x;
}


// assignment operators
D3DXINLINE D3DXVECTOR4&
D3DXVECTOR4::operator += ( CONST D3DXVECTOR4& v )
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

D3DXINLINE D3DXVECTOR4&
D3DXVECTOR4::operator -= ( CONST D3DXVECTOR4& v )
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

D3DXINLINE D3DXVECTOR4&
D3DXVECTOR4::operator *= ( FLOAT f )
{
    x *= f;
    y *= f;
    z *= f;
    w *= f;
    return *this;
}

D3DXINLINE D3DXVECTOR4&
D3DXVECTOR4::operator /= ( FLOAT f )
{
    FLOAT fInv = 1.0f / f;
    x *= fInv;
    y *= fInv;
    z *= fInv;
    w *= fInv;
    return *this;
}


// unary operators
D3DXINLINE D3DXVECTOR4
D3DXVECTOR4::operator + () const
{
    return *this;
}

D3DXINLINE D3DXVECTOR4
D3DXVECTOR4::operator - () const
{
    return D3DXVECTOR4(-x, -y, -z, -w);
}


// binary operators
D3DXINLINE D3DXVECTOR4
D3DXVECTOR4::operator + ( CONST D3DXVECTOR4& v ) const
{
    return D3DXVECTOR4(x + v.x, y + v.y, z + v.z, w + v.w);
}

D3DXINLINE D3DXVECTOR4
D3DXVECTOR4::operator - ( CONST D3DXVECTOR4& v ) const
{
    return D3DXVECTOR4(x - v.x, y - v.y, z - v.z, w - v.w);
}

D3DXINLINE D3DXVECTOR4
D3DXVECTOR4::operator * ( FLOAT f ) const
{
    return D3DXVECTOR4(x * f, y * f, z * f, w * f);
}

D3DXINLINE D3DXVECTOR4
D3DXVECTOR4::operator / ( FLOAT f ) const
{
    FLOAT fInv = 1.0f / f;
    return D3DXVECTOR4(x * fInv, y * fInv, z * fInv, w * fInv);
}

D3DXINLINE D3DXVECTOR4
operator * ( FLOAT f, CONST D3DXVECTOR4& v )
{
    return D3DXVECTOR4(f * v.x, f * v.y, f * v.z, f * v.w);
}


D3DXINLINE BOOL
D3DXVECTOR4::operator == ( CONST D3DXVECTOR4& v ) const
{
    return x == v.x && y == v.y && z == v.z && w == v.w;
}

D3DXINLINE BOOL
D3DXVECTOR4::operator != ( CONST D3DXVECTOR4& v ) const
{
    return x != v.x || y != v.y || z != v.z || w != v.w;
}



//--------------------------
// 4D Vector (16 bit)
//--------------------------

D3DXINLINE
D3DXVECTOR4_16F::D3DXVECTOR4_16F( CONST FLOAT *pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    D3DXFloat32To16Array(&x, pf, 4);
}

D3DXINLINE
D3DXVECTOR4_16F::D3DXVECTOR4_16F( CONST D3DXFLOAT16 *pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    *((DWORD *) &x) = *((DWORD *) &pf[0]);
    *((DWORD *) &z) = *((DWORD *) &pf[2]);
}

D3DXINLINE
D3DXVECTOR4_16F::D3DXVECTOR4_16F( CONST D3DXVECTOR3_16F& v, CONST D3DXFLOAT16& f )
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = f;
}

D3DXINLINE
D3DXVECTOR4_16F::D3DXVECTOR4_16F( CONST D3DXFLOAT16 &fx, CONST D3DXFLOAT16 &fy, CONST D3DXFLOAT16 &fz, CONST D3DXFLOAT16 &fw )
{
    x = fx;
    y = fy;
    z = fz;
    w = fw;
}


// casting
D3DXINLINE
D3DXVECTOR4_16F::operator D3DXFLOAT16* ()
{
    return (D3DXFLOAT16*) &x;
}

D3DXINLINE
D3DXVECTOR4_16F::operator CONST D3DXFLOAT16* () const
{
    return (CONST D3DXFLOAT16*) &x;
}


// binary operators
D3DXINLINE BOOL 
D3DXVECTOR4_16F::operator == ( CONST D3DXVECTOR4_16F &v ) const
{
    return *((DWORD *) &x) == *((DWORD *) &v.x) &&
           *((DWORD *) &z) == *((DWORD *) &v.z);
}

D3DXINLINE BOOL 
D3DXVECTOR4_16F::operator != ( CONST D3DXVECTOR4_16F &v ) const
{
    return *((DWORD *) &x) != *((DWORD *) &v.x) ||
           *((DWORD *) &z) != *((DWORD *) &v.z);
}


//--------------------------
// Matrix
//--------------------------
D3DXINLINE
D3DXMATRIX::D3DXMATRIX( CONST FLOAT* pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    memcpy(&_11, pf, sizeof(D3DXMATRIX));
}

D3DXINLINE
D3DXMATRIX::D3DXMATRIX( CONST D3DMATRIX& mat )
{
    memcpy(&_11, &mat, sizeof(D3DXMATRIX));
}

D3DXINLINE
D3DXMATRIX::D3DXMATRIX( CONST D3DXFLOAT16* pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    D3DXFloat16To32Array(&_11, pf, 16);
}

D3DXINLINE
D3DXMATRIX::D3DXMATRIX( FLOAT f11, FLOAT f12, FLOAT f13, FLOAT f14,
                        FLOAT f21, FLOAT f22, FLOAT f23, FLOAT f24,
                        FLOAT f31, FLOAT f32, FLOAT f33, FLOAT f34,
                        FLOAT f41, FLOAT f42, FLOAT f43, FLOAT f44 )
{
    _11 = f11; _12 = f12; _13 = f13; _14 = f14;
    _21 = f21; _22 = f22; _23 = f23; _24 = f24;
    _31 = f31; _32 = f32; _33 = f33; _34 = f34;
    _41 = f41; _42 = f42; _43 = f43; _44 = f44;
}



// access grants
D3DXINLINE FLOAT&
D3DXMATRIX::operator () ( UINT iRow, UINT iCol )
{
    return m[iRow][iCol];
}

D3DXINLINE FLOAT
D3DXMATRIX::operator () ( UINT iRow, UINT iCol ) const
{
    return m[iRow][iCol];
}


// casting operators
D3DXINLINE
D3DXMATRIX::operator FLOAT* ()
{
    return (FLOAT *) &_11;
}

D3DXINLINE
D3DXMATRIX::operator CONST FLOAT* () const
{
    return (CONST FLOAT *) &_11;
}


// assignment operators
D3DXINLINE D3DXMATRIX&
D3DXMATRIX::operator *= ( CONST D3DXMATRIX& mat )
{
    D3DXMatrixMultiply(this, this, &mat);
    return *this;
}

D3DXINLINE D3DXMATRIX&
D3DXMATRIX::operator += ( CONST D3DXMATRIX& mat )
{
    _11 += mat._11; _12 += mat._12; _13 += mat._13; _14 += mat._14;
    _21 += mat._21; _22 += mat._22; _23 += mat._23; _24 += mat._24;
    _31 += mat._31; _32 += mat._32; _33 += mat._33; _34 += mat._34;
    _41 += mat._41; _42 += mat._42; _43 += mat._43; _44 += mat._44;
    return *this;
}

D3DXINLINE D3DXMATRIX&
D3DXMATRIX::operator -= ( CONST D3DXMATRIX& mat )
{
    _11 -= mat._11; _12 -= mat._12; _13 -= mat._13; _14 -= mat._14;
    _21 -= mat._21; _22 -= mat._22; _23 -= mat._23; _24 -= mat._24;
    _31 -= mat._31; _32 -= mat._32; _33 -= mat._33; _34 -= mat._34;
    _41 -= mat._41; _42 -= mat._42; _43 -= mat._43; _44 -= mat._44;
    return *this;
}

D3DXINLINE D3DXMATRIX&
D3DXMATRIX::operator *= ( FLOAT f )
{
    _11 *= f; _12 *= f; _13 *= f; _14 *= f;
    _21 *= f; _22 *= f; _23 *= f; _24 *= f;
    _31 *= f; _32 *= f; _33 *= f; _34 *= f;
    _41 *= f; _42 *= f; _43 *= f; _44 *= f;
    return *this;
}

D3DXINLINE D3DXMATRIX&
D3DXMATRIX::operator /= ( FLOAT f )
{
    FLOAT fInv = 1.0f / f;
    _11 *= fInv; _12 *= fInv; _13 *= fInv; _14 *= fInv;
    _21 *= fInv; _22 *= fInv; _23 *= fInv; _24 *= fInv;
    _31 *= fInv; _32 *= fInv; _33 *= fInv; _34 *= fInv;
    _41 *= fInv; _42 *= fInv; _43 *= fInv; _44 *= fInv;
    return *this;
}


// unary operators
D3DXINLINE D3DXMATRIX
D3DXMATRIX::operator + () const
{
    return *this;
}

D3DXINLINE D3DXMATRIX
D3DXMATRIX::operator - () const
{
    return D3DXMATRIX(-_11, -_12, -_13, -_14,
                      -_21, -_22, -_23, -_24,
                      -_31, -_32, -_33, -_34,
                      -_41, -_42, -_43, -_44);
}


// binary operators
D3DXINLINE D3DXMATRIX
D3DXMATRIX::operator * ( CONST D3DXMATRIX& mat ) const
{
    D3DXMATRIX matT;
    D3DXMatrixMultiply(&matT, this, &mat);
    return matT;
}

D3DXINLINE D3DXMATRIX
D3DXMATRIX::operator + ( CONST D3DXMATRIX& mat ) const
{
    return D3DXMATRIX(_11 + mat._11, _12 + mat._12, _13 + mat._13, _14 + mat._14,
                      _21 + mat._21, _22 + mat._22, _23 + mat._23, _24 + mat._24,
                      _31 + mat._31, _32 + mat._32, _33 + mat._33, _34 + mat._34,
                      _41 + mat._41, _42 + mat._42, _43 + mat._43, _44 + mat._44);
}

D3DXINLINE D3DXMATRIX
D3DXMATRIX::operator - ( CONST D3DXMATRIX& mat ) const
{
    return D3DXMATRIX(_11 - mat._11, _12 - mat._12, _13 - mat._13, _14 - mat._14,
                      _21 - mat._21, _22 - mat._22, _23 - mat._23, _24 - mat._24,
                      _31 - mat._31, _32 - mat._32, _33 - mat._33, _34 - mat._34,
                      _41 - mat._41, _42 - mat._42, _43 - mat._43, _44 - mat._44);
}

D3DXINLINE D3DXMATRIX
D3DXMATRIX::operator * ( FLOAT f ) const
{
    return D3DXMATRIX(_11 * f, _12 * f, _13 * f, _14 * f,
                      _21 * f, _22 * f, _23 * f, _24 * f,
                      _31 * f, _32 * f, _33 * f, _34 * f,
                      _41 * f, _42 * f, _43 * f, _44 * f);
}

D3DXINLINE D3DXMATRIX
D3DXMATRIX::operator / ( FLOAT f ) const
{
    FLOAT fInv = 1.0f / f;
    return D3DXMATRIX(_11 * fInv, _12 * fInv, _13 * fInv, _14 * fInv,
                      _21 * fInv, _22 * fInv, _23 * fInv, _24 * fInv,
                      _31 * fInv, _32 * fInv, _33 * fInv, _34 * fInv,
                      _41 * fInv, _42 * fInv, _43 * fInv, _44 * fInv);
}


D3DXINLINE D3DXMATRIX
operator * ( FLOAT f, CONST D3DXMATRIX& mat )
{
    return D3DXMATRIX(f * mat._11, f * mat._12, f * mat._13, f * mat._14,
                      f * mat._21, f * mat._22, f * mat._23, f * mat._24,
                      f * mat._31, f * mat._32, f * mat._33, f * mat._34,
                      f * mat._41, f * mat._42, f * mat._43, f * mat._44);
}


D3DXINLINE BOOL
D3DXMATRIX::operator == ( CONST D3DXMATRIX& mat ) const
{
    return 0 == memcmp(this, &mat, sizeof(D3DXMATRIX));
}

D3DXINLINE BOOL
D3DXMATRIX::operator != ( CONST D3DXMATRIX& mat ) const
{
    return 0 != memcmp(this, &mat, sizeof(D3DXMATRIX));
}



//--------------------------
// Aligned Matrices
//--------------------------

D3DXINLINE
_D3DXMATRIXA16::_D3DXMATRIXA16( CONST FLOAT* f ) : 
    D3DXMATRIX( f ) 
{
}

D3DXINLINE
_D3DXMATRIXA16::_D3DXMATRIXA16( CONST D3DMATRIX& m ) : 
    D3DXMATRIX( m ) 
{
}

D3DXINLINE
_D3DXMATRIXA16::_D3DXMATRIXA16( CONST D3DXFLOAT16* f ) : 
    D3DXMATRIX( f ) 
{
}

D3DXINLINE
_D3DXMATRIXA16::_D3DXMATRIXA16( FLOAT _11, FLOAT _12, FLOAT _13, FLOAT _14,
                                FLOAT _21, FLOAT _22, FLOAT _23, FLOAT _24,
                                FLOAT _31, FLOAT _32, FLOAT _33, FLOAT _34,
                                FLOAT _41, FLOAT _42, FLOAT _43, FLOAT _44 ) :
    D3DXMATRIX(_11, _12, _13, _14,
               _21, _22, _23, _24,
               _31, _32, _33, _34,
               _41, _42, _43, _44) 
{
}

#ifndef SIZE_MAX
#define SIZE_MAX ((SIZE_T)-1)
#endif

D3DXINLINE void* 
_D3DXMATRIXA16::operator new( size_t s )
{
    if (s > (SIZE_MAX-16))
	return NULL;
    LPBYTE p = ::new BYTE[s + 16];
    if (p)
    {
        BYTE offset = (BYTE)(16 - ((UINT_PTR)p & 15));
        p += offset;
        p[-1] = offset;
    }
    return p;
}

D3DXINLINE void* 
_D3DXMATRIXA16::operator new[]( size_t s )
{
    if (s > (SIZE_MAX-16))
	return NULL;
    LPBYTE p = ::new BYTE[s + 16];
    if (p)
    {
        BYTE offset = (BYTE)(16 - ((UINT_PTR)p & 15));
        p += offset;
        p[-1] = offset;
    }
    return p;
}

D3DXINLINE void 
_D3DXMATRIXA16::operator delete(void* p)
{
    if(p)
    {
        BYTE* pb = static_cast<BYTE*>(p);
        pb -= pb[-1];
        ::delete [] pb;
    }
}

D3DXINLINE void 
_D3DXMATRIXA16::operator delete[](void* p)
{
    if(p)
    {
        BYTE* pb = static_cast<BYTE*>(p);
        pb -= pb[-1];
        ::delete [] pb;
    }
}

D3DXINLINE _D3DXMATRIXA16& 
_D3DXMATRIXA16::operator=(CONST D3DXMATRIX& rhs)
{
    memcpy(&_11, &rhs, sizeof(D3DXMATRIX));
    return *this;
}


//--------------------------
// Quaternion
//--------------------------

D3DXINLINE
D3DXQUATERNION::D3DXQUATERNION( CONST FLOAT* pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    x = pf[0];
    y = pf[1];
    z = pf[2];
    w = pf[3];
}

D3DXINLINE
D3DXQUATERNION::D3DXQUATERNION( CONST D3DXFLOAT16* pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    D3DXFloat16To32Array(&x, pf, 4);
}

D3DXINLINE
D3DXQUATERNION::D3DXQUATERNION( FLOAT fx, FLOAT fy, FLOAT fz, FLOAT fw )
{
    x = fx;
    y = fy;
    z = fz;
    w = fw;
}


// casting
D3DXINLINE
D3DXQUATERNION::operator FLOAT* ()
{
    return (FLOAT *) &x;
}

D3DXINLINE
D3DXQUATERNION::operator CONST FLOAT* () const
{
    return (CONST FLOAT *) &x;
}


// assignment operators
D3DXINLINE D3DXQUATERNION&
D3DXQUATERNION::operator += ( CONST D3DXQUATERNION& q )
{
    x += q.x;
    y += q.y;
    z += q.z;
    w += q.w;
    return *this;
}

D3DXINLINE D3DXQUATERNION&
D3DXQUATERNION::operator -= ( CONST D3DXQUATERNION& q )
{
    x -= q.x;
    y -= q.y;
    z -= q.z;
    w -= q.w;
    return *this;
}

D3DXINLINE D3DXQUATERNION&
D3DXQUATERNION::operator *= ( CONST D3DXQUATERNION& q )
{
    D3DXQuaternionMultiply(this, this, &q);
    return *this;
}

D3DXINLINE D3DXQUATERNION&
D3DXQUATERNION::operator *= ( FLOAT f )
{
    x *= f;
    y *= f;
    z *= f;
    w *= f;
    return *this;
}

D3DXINLINE D3DXQUATERNION&
D3DXQUATERNION::operator /= ( FLOAT f )
{
    FLOAT fInv = 1.0f / f;
    x *= fInv;
    y *= fInv;
    z *= fInv;
    w *= fInv;
    return *this;
}


// unary operators
D3DXINLINE D3DXQUATERNION
D3DXQUATERNION::operator + () const
{
    return *this;
}

D3DXINLINE D3DXQUATERNION
D3DXQUATERNION::operator - () const
{
    return D3DXQUATERNION(-x, -y, -z, -w);
}


// binary operators
D3DXINLINE D3DXQUATERNION
D3DXQUATERNION::operator + ( CONST D3DXQUATERNION& q ) const
{
    return D3DXQUATERNION(x + q.x, y + q.y, z + q.z, w + q.w);
}

D3DXINLINE D3DXQUATERNION
D3DXQUATERNION::operator - ( CONST D3DXQUATERNION& q ) const
{
    return D3DXQUATERNION(x - q.x, y - q.y, z - q.z, w - q.w);
}

D3DXINLINE D3DXQUATERNION
D3DXQUATERNION::operator * ( CONST D3DXQUATERNION& q ) const
{
    D3DXQUATERNION qT;
    D3DXQuaternionMultiply(&qT, this, &q);
    return qT;
}

D3DXINLINE D3DXQUATERNION
D3DXQUATERNION::operator * ( FLOAT f ) const
{
    return D3DXQUATERNION(x * f, y * f, z * f, w * f);
}

D3DXINLINE D3DXQUATERNION
D3DXQUATERNION::operator / ( FLOAT f ) const
{
    FLOAT fInv = 1.0f / f;
    return D3DXQUATERNION(x * fInv, y * fInv, z * fInv, w * fInv);
}


D3DXINLINE D3DXQUATERNION
operator * (FLOAT f, CONST D3DXQUATERNION& q )
{
    return D3DXQUATERNION(f * q.x, f * q.y, f * q.z, f * q.w);
}


D3DXINLINE BOOL
D3DXQUATERNION::operator == ( CONST D3DXQUATERNION& q ) const
{
    return x == q.x && y == q.y && z == q.z && w == q.w;
}

D3DXINLINE BOOL
D3DXQUATERNION::operator != ( CONST D3DXQUATERNION& q ) const
{
    return x != q.x || y != q.y || z != q.z || w != q.w;
}



//--------------------------
// Plane
//--------------------------

D3DXINLINE
D3DXPLANE::D3DXPLANE( CONST FLOAT* pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    a = pf[0];
    b = pf[1];
    c = pf[2];
    d = pf[3];
}

D3DXINLINE
D3DXPLANE::D3DXPLANE( CONST D3DXFLOAT16* pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    D3DXFloat16To32Array(&a, pf, 4);
}

D3DXINLINE
D3DXPLANE::D3DXPLANE( FLOAT fa, FLOAT fb, FLOAT fc, FLOAT fd )
{
    a = fa;
    b = fb;
    c = fc;
    d = fd;
}


// casting
D3DXINLINE
D3DXPLANE::operator FLOAT* ()
{
    return (FLOAT *) &a;
}

D3DXINLINE
D3DXPLANE::operator CONST FLOAT* () const
{
    return (CONST FLOAT *) &a;
}


// assignment operators
D3DXINLINE D3DXPLANE&
D3DXPLANE::operator *= ( FLOAT f )
{
    a *= f;
    b *= f;
    c *= f;
    d *= f;
    return *this;
}

D3DXINLINE D3DXPLANE&
D3DXPLANE::operator /= ( FLOAT f )
{
    FLOAT fInv = 1.0f / f;
    a *= fInv;
    b *= fInv;
    c *= fInv;
    d *= fInv;
    return *this;
}


// unary operators
D3DXINLINE D3DXPLANE
D3DXPLANE::operator + () const
{
    return *this;
}

D3DXINLINE D3DXPLANE
D3DXPLANE::operator - () const
{
    return D3DXPLANE(-a, -b, -c, -d);
}


// binary operators
D3DXINLINE D3DXPLANE
D3DXPLANE::operator * ( FLOAT f ) const
{
    return D3DXPLANE(a * f, b * f, c * f, d * f);
}

D3DXINLINE D3DXPLANE
D3DXPLANE::operator / ( FLOAT f ) const
{
    FLOAT fInv = 1.0f / f;
    return D3DXPLANE(a * fInv, b * fInv, c * fInv, d * fInv);
}

D3DXINLINE D3DXPLANE
operator * (FLOAT f, CONST D3DXPLANE& p )
{
    return D3DXPLANE(f * p.a, f * p.b, f * p.c, f * p.d);
}

D3DXINLINE BOOL
D3DXPLANE::operator == ( CONST D3DXPLANE& p ) const
{
    return a == p.a && b == p.b && c == p.c && d == p.d;
}

D3DXINLINE BOOL
D3DXPLANE::operator != ( CONST D3DXPLANE& p ) const
{
    return a != p.a || b != p.b || c != p.c || d != p.d;
}




//--------------------------
// Color
//--------------------------

D3DXINLINE
D3DXCOLOR::D3DXCOLOR( DWORD dw )
{
    CONST FLOAT f = 1.0f / 255.0f;
    r = f * (FLOAT) (unsigned char) (dw >> 16);
    g = f * (FLOAT) (unsigned char) (dw >>  8);
    b = f * (FLOAT) (unsigned char) (dw >>  0);
    a = f * (FLOAT) (unsigned char) (dw >> 24);
}

D3DXINLINE
D3DXCOLOR::D3DXCOLOR( CONST FLOAT* pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    r = pf[0];
    g = pf[1];
    b = pf[2];
    a = pf[3];
}

D3DXINLINE
D3DXCOLOR::D3DXCOLOR( CONST D3DXFLOAT16* pf )
{
#ifdef D3DX_DEBUG
    if(!pf)
        return;
#endif

    D3DXFloat16To32Array(&r, pf, 4);
}

D3DXINLINE
D3DXCOLOR::D3DXCOLOR( CONST D3DCOLORVALUE& c )
{
    r = c.r;
    g = c.g;
    b = c.b;
    a = c.a;
}

D3DXINLINE
D3DXCOLOR::D3DXCOLOR( FLOAT fr, FLOAT fg, FLOAT fb, FLOAT fa )
{
    r = fr;
    g = fg;
    b = fb;
    a = fa;
}


// casting
D3DXINLINE
D3DXCOLOR::operator DWORD () const
{
    DWORD dwR = r >= 1.0f ? 0xff : r <= 0.0f ? 0x00 : (DWORD) (r * 255.0f + 0.5f);
    DWORD dwG = g >= 1.0f ? 0xff : g <= 0.0f ? 0x00 : (DWORD) (g * 255.0f + 0.5f);
    DWORD dwB = b >= 1.0f ? 0xff : b <= 0.0f ? 0x00 : (DWORD) (b * 255.0f + 0.5f);
    DWORD dwA = a >= 1.0f ? 0xff : a <= 0.0f ? 0x00 : (DWORD) (a * 255.0f + 0.5f);

    return (dwA << 24) | (dwR << 16) | (dwG << 8) | dwB;
}


D3DXINLINE
D3DXCOLOR::operator FLOAT * ()
{
    return (FLOAT *) &r;
}

D3DXINLINE
D3DXCOLOR::operator CONST FLOAT * () const
{
    return (CONST FLOAT *) &r;
}


D3DXINLINE
D3DXCOLOR::operator D3DCOLORVALUE * ()
{
    return (D3DCOLORVALUE *) &r;
}

D3DXINLINE
D3DXCOLOR::operator CONST D3DCOLORVALUE * () const
{
    return (CONST D3DCOLORVALUE *) &r;
}


D3DXINLINE
D3DXCOLOR::operator D3DCOLORVALUE& ()
{
    return *((D3DCOLORVALUE *) &r);
}

D3DXINLINE
D3DXCOLOR::operator CONST D3DCOLORVALUE& () const
{
    return *((CONST D3DCOLORVALUE *) &r);
}


// assignment operators
D3DXINLINE D3DXCOLOR&
D3DXCOLOR::operator += ( CONST D3DXCOLOR& c )
{
    r += c.r;
    g += c.g;
    b += c.b;
    a += c.a;
    return *this;
}

D3DXINLINE D3DXCOLOR&
D3DXCOLOR::operator -= ( CONST D3DXCOLOR& c )
{
    r -= c.r;
    g -= c.g;
    b -= c.b;
    a -= c.a;
    return *this;
}

D3DXINLINE D3DXCOLOR&
D3DXCOLOR::operator *= ( FLOAT f )
{
    r *= f;
    g *= f;
    b *= f;
    a *= f;
    return *this;
}

D3DXINLINE D3DXCOLOR&
D3DXCOLOR::operator /= ( FLOAT f )
{
    FLOAT fInv = 1.0f / f;
    r *= fInv;
    g *= fInv;
    b *= fInv;
    a *= fInv;
    return *this;
}


// unary operators
D3DXINLINE D3DXCOLOR
D3DXCOLOR::operator + () const
{
    return *this;
}

D3DXINLINE D3DXCOLOR
D3DXCOLOR::operator - () const
{
    return D3DXCOLOR(-r, -g, -b, -a);
}


// binary operators
D3DXINLINE D3DXCOLOR
D3DXCOLOR::operator + ( CONST D3DXCOLOR& c ) const
{
    return D3DXCOLOR(r + c.r, g + c.g, b + c.b, a + c.a);
}

D3DXINLINE D3DXCOLOR
D3DXCOLOR::operator - ( CONST D3DXCOLOR& c ) const
{
    return D3DXCOLOR(r - c.r, g - c.g, b - c.b, a - c.a);
}

D3DXINLINE D3DXCOLOR
D3DXCOLOR::operator * ( FLOAT f ) const
{
    return D3DXCOLOR(r * f, g * f, b * f, a * f);
}

D3DXINLINE D3DXCOLOR
D3DXCOLOR::operator / ( FLOAT f ) const
{
    FLOAT fInv = 1.0f / f;
    return D3DXCOLOR(r * fInv, g * fInv, b * fInv, a * fInv);
}


D3DXINLINE D3DXCOLOR
operator * (FLOAT f, CONST D3DXCOLOR& c )
{
    return D3DXCOLOR(f * c.r, f * c.g, f * c.b, f * c.a);
}


D3DXINLINE BOOL
D3DXCOLOR::operator == ( CONST D3DXCOLOR& c ) const
{
    return r == c.r && g == c.g && b == c.b && a == c.a;
}

D3DXINLINE BOOL
D3DXCOLOR::operator != ( CONST D3DXCOLOR& c ) const
{
    return r != c.r || g != c.g || b != c.b || a != c.a;
}


#endif //__cplusplus



//===========================================================================
//
// Inline functions
//
//===========================================================================


//--------------------------
// 2D Vector
//--------------------------

D3DXINLINE FLOAT D3DXVec2Length
    ( CONST D3DXVECTOR2 *pV )
{
#ifdef D3DX_DEBUG
    if(!pV)
        return 0.0f;
#endif

#ifdef __cplusplus
    return sqrtf(pV->x * pV->x + pV->y * pV->y);
#else
    return (FLOAT) sqrt(pV->x * pV->x + pV->y * pV->y);
#endif
}

D3DXINLINE FLOAT D3DXVec2LengthSq
    ( CONST D3DXVECTOR2 *pV )
{
#ifdef D3DX_DEBUG
    if(!pV)
        return 0.0f;
#endif

    return pV->x * pV->x + pV->y * pV->y;
}

D3DXINLINE FLOAT D3DXVec2Dot
    ( CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 )
{
#ifdef D3DX_DEBUG
    if(!pV1 || !pV2)
        return 0.0f;
#endif

    return pV1->x * pV2->x + pV1->y * pV2->y;
}

D3DXINLINE FLOAT D3DXVec2CCW
    ( CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 )
{
#ifdef D3DX_DEBUG
    if(!pV1 || !pV2)
        return 0.0f;
#endif

    return pV1->x * pV2->y - pV1->y * pV2->x;
}

D3DXINLINE D3DXVECTOR2* D3DXVec2Add
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 )
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    pOut->x = pV1->x + pV2->x;
    pOut->y = pV1->y + pV2->y;
    return pOut;
}

D3DXINLINE D3DXVECTOR2* D3DXVec2Subtract
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 )
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    pOut->x = pV1->x - pV2->x;
    pOut->y = pV1->y - pV2->y;
    return pOut;
}

D3DXINLINE D3DXVECTOR2* D3DXVec2Minimize
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 )
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    pOut->x = pV1->x < pV2->x ? pV1->x : pV2->x;
    pOut->y = pV1->y < pV2->y ? pV1->y : pV2->y;
    return pOut;
}

D3DXINLINE D3DXVECTOR2* D3DXVec2Maximize
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 )
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    pOut->x = pV1->x > pV2->x ? pV1->x : pV2->x;
    pOut->y = pV1->y > pV2->y ? pV1->y : pV2->y;
    return pOut;
}

D3DXINLINE D3DXVECTOR2* D3DXVec2Scale
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV, FLOAT s )
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV)
        return NULL;
#endif

    pOut->x = pV->x * s;
    pOut->y = pV->y * s;
    return pOut;
}

D3DXINLINE D3DXVECTOR2* D3DXVec2Lerp
    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2,
      FLOAT s )
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    pOut->x = pV1->x + s * (pV2->x - pV1->x);
    pOut->y = pV1->y + s * (pV2->y - pV1->y);
    return pOut;
}


//--------------------------
// 3D Vector
//--------------------------

D3DXINLINE FLOAT D3DXVec3Length
    ( CONST D3DXVECTOR3 *pV )
{
#ifdef D3DX_DEBUG
    if(!pV)
        return 0.0f;
#endif

#ifdef __cplusplus
    return sqrtf(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z);
#else
    return (FLOAT) sqrt(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z);
#endif
}

D3DXINLINE FLOAT D3DXVec3LengthSq
    ( CONST D3DXVECTOR3 *pV )
{
#ifdef D3DX_DEBUG
    if(!pV)
        return 0.0f;
#endif

    return pV->x * pV->x + pV->y * pV->y + pV->z * pV->z;
}

D3DXINLINE FLOAT D3DXVec3Dot
    ( CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
{
#ifdef D3DX_DEBUG
    if(!pV1 || !pV2)
        return 0.0f;
#endif

    return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z;
}

D3DXINLINE D3DXVECTOR3* D3DXVec3Cross
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
{
    D3DXVECTOR3 v;

#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    v.x = pV1->y * pV2->z - pV1->z * pV2->y;
    v.y = pV1->z * pV2->x - pV1->x * pV2->z;
    v.z = pV1->x * pV2->y - pV1->y * pV2->x;

    *pOut = v;
    return pOut;
}

D3DXINLINE D3DXVECTOR3* D3DXVec3Add
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    pOut->x = pV1->x + pV2->x;
    pOut->y = pV1->y + pV2->y;
    pOut->z = pV1->z + pV2->z;
    return pOut;
}

D3DXINLINE D3DXVECTOR3* D3DXVec3Subtract
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    pOut->x = pV1->x - pV2->x;
    pOut->y = pV1->y - pV2->y;
    pOut->z = pV1->z - pV2->z;
    return pOut;
}

D3DXINLINE D3DXVECTOR3* D3DXVec3Minimize
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    pOut->x = pV1->x < pV2->x ? pV1->x : pV2->x;
    pOut->y = pV1->y < pV2->y ? pV1->y : pV2->y;
    pOut->z = pV1->z < pV2->z ? pV1->z : pV2->z;
    return pOut;
}

D3DXINLINE D3DXVECTOR3* D3DXVec3Maximize
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    pOut->x = pV1->x > pV2->x ? pV1->x : pV2->x;
    pOut->y = pV1->y > pV2->y ? pV1->y : pV2->y;
    pOut->z = pV1->z > pV2->z ? pV1->z : pV2->z;
    return pOut;
}

D3DXINLINE D3DXVECTOR3* D3DXVec3Scale
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV, FLOAT s)
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV)
        return NULL;
#endif

    pOut->x = pV->x * s;
    pOut->y = pV->y * s;
    pOut->z = pV->z * s;
    return pOut;
}

D3DXINLINE D3DXVECTOR3* D3DXVec3Lerp
    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2,
      FLOAT s )
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    pOut->x = pV1->x + s * (pV2->x - pV1->x);
    pOut->y = pV1->y + s * (pV2->y - pV1->y);
    pOut->z = pV1->z + s * (pV2->z - pV1->z);
    return pOut;
}


//--------------------------
// 4D Vector
//--------------------------

D3DXINLINE FLOAT D3DXVec4Length
    ( CONST D3DXVECTOR4 *pV )
{
#ifdef D3DX_DEBUG
    if(!pV)
        return 0.0f;
#endif

#ifdef __cplusplus
    return sqrtf(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z + pV->w * pV->w);
#else
    return (FLOAT) sqrt(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z + pV->w * pV->w);
#endif
}

D3DXINLINE FLOAT D3DXVec4LengthSq
    ( CONST D3DXVECTOR4 *pV )
{
#ifdef D3DX_DEBUG
    if(!pV)
        return 0.0f;
#endif

    return pV->x * pV->x + pV->y * pV->y + pV->z * pV->z + pV->w * pV->w;
}

D3DXINLINE FLOAT D3DXVec4Dot
    ( CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2 )
{
#ifdef D3DX_DEBUG
    if(!pV1 || !pV2)
        return 0.0f;
#endif

    return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z + pV1->w * pV2->w;
}

D3DXINLINE D3DXVECTOR4* D3DXVec4Add
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2)
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    pOut->x = pV1->x + pV2->x;
    pOut->y = pV1->y + pV2->y;
    pOut->z = pV1->z + pV2->z;
    pOut->w = pV1->w + pV2->w;
    return pOut;
}

D3DXINLINE D3DXVECTOR4* D3DXVec4Subtract
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2)
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    pOut->x = pV1->x - pV2->x;
    pOut->y = pV1->y - pV2->y;
    pOut->z = pV1->z - pV2->z;
    pOut->w = pV1->w - pV2->w;
    return pOut;
}

D3DXINLINE D3DXVECTOR4* D3DXVec4Minimize
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2)
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    pOut->x = pV1->x < pV2->x ? pV1->x : pV2->x;
    pOut->y = pV1->y < pV2->y ? pV1->y : pV2->y;
    pOut->z = pV1->z < pV2->z ? pV1->z : pV2->z;
    pOut->w = pV1->w < pV2->w ? pV1->w : pV2->w;
    return pOut;
}

D3DXINLINE D3DXVECTOR4* D3DXVec4Maximize
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2)
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    pOut->x = pV1->x > pV2->x ? pV1->x : pV2->x;
    pOut->y = pV1->y > pV2->y ? pV1->y : pV2->y;
    pOut->z = pV1->z > pV2->z ? pV1->z : pV2->z;
    pOut->w = pV1->w > pV2->w ? pV1->w : pV2->w;
    return pOut;
}

D3DXINLINE D3DXVECTOR4* D3DXVec4Scale
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV, FLOAT s)
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV)
        return NULL;
#endif

    pOut->x = pV->x * s;
    pOut->y = pV->y * s;
    pOut->z = pV->z * s;
    pOut->w = pV->w * s;
    return pOut;
}

D3DXINLINE D3DXVECTOR4* D3DXVec4Lerp
    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2,
      FLOAT s )
{
#ifdef D3DX_DEBUG
    if(!pOut || !pV1 || !pV2)
        return NULL;
#endif

    pOut->x = pV1->x + s * (pV2->x - pV1->x);
    pOut->y = pV1->y + s * (pV2->y - pV1->y);
    pOut->z = pV1->z + s * (pV2->z - pV1->z);
    pOut->w = pV1->w + s * (pV2->w - pV1->w);
    return pOut;
}


//--------------------------
// 4D Matrix
//--------------------------

D3DXINLINE D3DXMATRIX* D3DXMatrixIdentity
    ( D3DXMATRIX *pOut )
{
#ifdef D3DX_DEBUG
    if(!pOut)
        return NULL;
#endif

    pOut->m[0][1] = pOut->m[0][2] = pOut->m[0][3] =
    pOut->m[1][0] = pOut->m[1][2] = pOut->m[1][3] =
    pOut->m[2][0] = pOut->m[2][1] = pOut->m[2][3] =
    pOut->m[3][0] = pOut->m[3][1] = pOut->m[3][2] = 0.0f;

    pOut->m[0][0] = pOut->m[1][1] = pOut->m[2][2] = pOut->m[3][3] = 1.0f;
    return pOut;
}


D3DXINLINE BOOL D3DXMatrixIsIdentity
    ( CONST D3DXMATRIX *pM )
{
#ifdef D3DX_DEBUG
    if(!pM)
        return FALSE;
#endif

    return pM->m[0][0] == 1.0f && pM->m[0][1] == 0.0f && pM->m[0][2] == 0.0f && pM->m[0][3] == 0.0f &&
           pM->m[1][0] == 0.0f && pM->m[1][1] == 1.0f && pM->m[1][2] == 0.0f && pM->m[1][3] == 0.0f &&
           pM->m[2][0] == 0.0f && pM->m[2][1] == 0.0f && pM->m[2][2] == 1.0f && pM->m[2][3] == 0.0f &&
           pM->m[3][0] == 0.0f && pM->m[3][1] == 0.0f && pM->m[3][2] == 0.0f && pM->m[3][3] == 1.0f;
}


//--------------------------
// Quaternion
//--------------------------

D3DXINLINE FLOAT D3DXQuaternionLength
    ( CONST D3DXQUATERNION *pQ )
{
#ifdef D3DX_DEBUG
    if(!pQ)
        return 0.0f;
#endif

#ifdef __cplusplus
    return sqrtf(pQ->x * pQ->x + pQ->y * pQ->y + pQ->z * pQ->z + pQ->w * pQ->w);
#else
    return (FLOAT) sqrt(pQ->x * pQ->x + pQ->y * pQ->y + pQ->z * pQ->z + pQ->w * pQ->w);
#endif
}

D3DXINLINE FLOAT D3DXQuaternionLengthSq
    ( CONST D3DXQUATERNION *pQ )
{
#ifdef D3DX_DEBUG
    if(!pQ)
        return 0.0f;
#endif

    return pQ->x * pQ->x + pQ->y * pQ->y + pQ->z * pQ->z + pQ->w * pQ->w;
}

D3DXINLINE FLOAT D3DXQuaternionDot
    ( CONST D3DXQUATERNION *pQ1, CONST D3DXQUATERNION *pQ2 )
{
#ifdef D3DX_DEBUG
    if(!pQ1 || !pQ2)
        return 0.0f;
#endif

    return pQ1->x * pQ2->x + pQ1->y * pQ2->y + pQ1->z * pQ2->z + pQ1->w * pQ2->w;
}


D3DXINLINE D3DXQUATERNION* D3DXQuaternionIdentity
    ( D3DXQUATERNION *pOut )
{
#ifdef D3DX_DEBUG
    if(!pOut)
        return NULL;
#endif

    pOut->x = pOut->y = pOut->z = 0.0f;
    pOut->w = 1.0f;
    return pOut;
}

D3DXINLINE BOOL D3DXQuaternionIsIdentity
    ( CONST D3DXQUATERNION *pQ )
{
#ifdef D3DX_DEBUG
    if(!pQ)
        return FALSE;
#endif

    return pQ->x == 0.0f && pQ->y == 0.0f && pQ->z == 0.0f && pQ->w == 1.0f;
}


D3DXINLINE D3DXQUATERNION* D3DXQuaternionConjugate
    ( D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ )
{
#ifdef D3DX_DEBUG
    if(!pOut || !pQ)
        return NULL;
#endif

    pOut->x = -pQ->x;
    pOut->y = -pQ->y;
    pOut->z = -pQ->z;
    pOut->w =  pQ->w;
    return pOut;
}


//--------------------------
// Plane
//--------------------------

D3DXINLINE FLOAT D3DXPlaneDot
    ( CONST D3DXPLANE *pP, CONST D3DXVECTOR4 *pV)
{
#ifdef D3DX_DEBUG
    if(!pP || !pV)
        return 0.0f;
#endif

    return pP->a * pV->x + pP->b * pV->y + pP->c * pV->z + pP->d * pV->w;
}

D3DXINLINE FLOAT D3DXPlaneDotCoord
    ( CONST D3DXPLANE *pP, CONST D3DXVECTOR3 *pV)
{
#ifdef D3DX_DEBUG
    if(!pP || !pV)
        return 0.0f;
#endif

    return pP->a * pV->x + pP->b * pV->y + pP->c * pV->z + pP->d;
}

D3DXINLINE FLOAT D3DXPlaneDotNormal
    ( CONST D3DXPLANE *pP, CONST D3DXVECTOR3 *pV)
{
#ifdef D3DX_DEBUG
    if(!pP || !pV)
        return 0.0f;
#endif

    return pP->a * pV->x + pP->b * pV->y + pP->c * pV->z;
}

D3DXINLINE D3DXPLANE* D3DXPlaneScale
    (D3DXPLANE *pOut, CONST D3DXPLANE *pP, FLOAT s)
{
#ifdef D3DX_DEBUG
    if(!pOut || !pP)
        return NULL;
#endif

    pOut->a = pP->a * s;
    pOut->b = pP->b * s;
    pOut->c = pP->c * s;
    pOut->d = pP->d * s;
    return pOut;
}


//--------------------------
// Color
//--------------------------

D3DXINLINE D3DXCOLOR* D3DXColorNegative
    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC)
{
#ifdef D3DX_DEBUG
    if(!pOut || !pC)
        return NULL;
#endif

    pOut->r = 1.0f - pC->r;
    pOut->g = 1.0f - pC->g;
    pOut->b = 1.0f - pC->b;
    pOut->a = pC->a;
    return pOut;
}

D3DXINLINE D3DXCOLOR* D3DXColorAdd
    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2)
{
#ifdef D3DX_DEBUG
    if(!pOut || !pC1 || !pC2)
        return NULL;
#endif

    pOut->r = pC1->r + pC2->r;
    pOut->g = pC1->g + pC2->g;
    pOut->b = pC1->b + pC2->b;
    pOut->a = pC1->a + pC2->a;
    return pOut;
}

D3DXINLINE D3DXCOLOR* D3DXColorSubtract
    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2)
{
#ifdef D3DX_DEBUG
    if(!pOut || !pC1 || !pC2)
        return NULL;
#endif

    pOut->r = pC1->r - pC2->r;
    pOut->g = pC1->g - pC2->g;
    pOut->b = pC1->b - pC2->b;
    pOut->a = pC1->a - pC2->a;
    return pOut;
}

D3DXINLINE D3DXCOLOR* D3DXColorScale
    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC, FLOAT s)
{
#ifdef D3DX_DEBUG
    if(!pOut || !pC)
        return NULL;
#endif

    pOut->r = pC->r * s;
    pOut->g = pC->g * s;
    pOut->b = pC->b * s;
    pOut->a = pC->a * s;
    return pOut;
}

D3DXINLINE D3DXCOLOR* D3DXColorModulate
    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2)
{
#ifdef D3DX_DEBUG
    if(!pOut || !pC1 || !pC2)
        return NULL;
#endif

    pOut->r = pC1->r * pC2->r;
    pOut->g = pC1->g * pC2->g;
    pOut->b = pC1->b * pC2->b;
    pOut->a = pC1->a * pC2->a;
    return pOut;
}

D3DXINLINE D3DXCOLOR* D3DXColorLerp
    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2, FLOAT s)
{
#ifdef D3DX_DEBUG
    if(!pOut || !pC1 || !pC2)
        return NULL;
#endif

    pOut->r = pC1->r + s * (pC2->r - pC1->r);
    pOut->g = pC1->g + s * (pC2->g - pC1->g);
    pOut->b = pC1->b + s * (pC2->b - pC1->b);
    pOut->a = pC1->a + s * (pC2->a - pC1->a);
    return pOut;
}


#endif // __D3DX9MATH_INL__



/*
 * Mathematical operations specific to D3DX9.
 *
 * Copyright (C) 2008 David Adam
 * Copyright (C) 2008 Luis Busquets
 * Copyright (C) 2008 Jérôme Gardou
 * Copyright (C) 2008 Philip Nilsson
 * Copyright (C) 2008 Henri Verbeet
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include "config.h"
#include "wine/port.h"

#include "d3dx9_private.h"

WINE_DEFAULT_DEBUG_CHANNEL(d3dx);

struct ID3DXMatrixStackImpl
{
  ID3DXMatrixStack ID3DXMatrixStack_iface;
  LONG ref;

  unsigned int current;
  unsigned int stack_size;
  D3DXMATRIX *stack;
};

static const unsigned int INITIAL_STACK_SIZE = 32;

/*_________________D3DXColor____________________*/

D3DXCOLOR* WINAPI D3DXColorAdjustContrast(D3DXCOLOR *pout, const D3DXCOLOR *pc, FLOAT s)
{
    TRACE("pout %p, pc %p, s %f\n", pout, pc, s);

    pout->r = 0.5f + s * (pc->r - 0.5f);
    pout->g = 0.5f + s * (pc->g - 0.5f);
    pout->b = 0.5f + s * (pc->b - 0.5f);
    pout->a = pc->a;
    return pout;
}

D3DXCOLOR* WINAPI D3DXColorAdjustSaturation(D3DXCOLOR *pout, const D3DXCOLOR *pc, FLOAT s)
{
    FLOAT grey;

    TRACE("pout %p, pc %p, s %f\n", pout, pc, s);

    grey = pc->r * 0.2125f + pc->g * 0.7154f + pc->b * 0.0721f;
    pout->r = grey + s * (pc->r - grey);
    pout->g = grey + s * (pc->g - grey);
    pout->b = grey + s * (pc->b - grey);
    pout->a = pc->a;
    return pout;
}

/*_________________Misc__________________________*/

FLOAT WINAPI D3DXFresnelTerm(FLOAT costheta, FLOAT refractionindex)
{
    FLOAT a, d, g, result;

    TRACE("costheta %f, refractionindex %f\n", costheta, refractionindex);

    g = sqrtf(refractionindex * refractionindex + costheta * costheta - 1.0f);
    a = g + costheta;
    d = g - costheta;
    result = (costheta * a - 1.0f) * (costheta * a - 1.0f) / ((costheta * d + 1.0f) * (costheta * d + 1.0f)) + 1.0f;
    result *= 0.5f * d * d / (a * a);

    return result;
}

/*_________________D3DXMatrix____________________*/

D3DXMATRIX * WINAPI D3DXMatrixAffineTransformation(D3DXMATRIX *out, FLOAT scaling, const D3DXVECTOR3 *rotationcenter,
        const D3DXQUATERNION *rotation, const D3DXVECTOR3 *translation)
{
    TRACE("out %p, scaling %f, rotationcenter %p, rotation %p, translation %p\n",
            out, scaling, rotationcenter, rotation, translation);

    D3DXMatrixIdentity(out);

    if (rotation)
    {
        FLOAT temp00, temp01, temp02, temp10, temp11, temp12, temp20, temp21, temp22;

        temp00 = 1.0f - 2.0f * (rotation->y * rotation->y + rotation->z * rotation->z);
        temp01 = 2.0f * (rotation->x * rotation->y + rotation->z * rotation->w);
        temp02 = 2.0f * (rotation->x * rotation->z - rotation->y * rotation->w);
        temp10 = 2.0f * (rotation->x * rotation->y - rotation->z * rotation->w);
        temp11 = 1.0f - 2.0f * (rotation->x * rotation->x + rotation->z * rotation->z);
        temp12 = 2.0f * (rotation->y * rotation->z + rotation->x * rotation->w);
        temp20 = 2.0f * (rotation->x * rotation->z + rotation->y * rotation->w);
        temp21 = 2.0f * (rotation->y * rotation->z - rotation->x * rotation->w);
        temp22 = 1.0f - 2.0f * (rotation->x * rotation->x + rotation->y * rotation->y);

        out->u.m[0][0] = scaling * temp00;
        out->u.m[0][1] = scaling * temp01;
        out->u.m[0][2] = scaling * temp02;
        out->u.m[1][0] = scaling * temp10;
        out->u.m[1][1] = scaling * temp11;
        out->u.m[1][2] = scaling * temp12;
        out->u.m[2][0] = scaling * temp20;
        out->u.m[2][1] = scaling * temp21;
        out->u.m[2][2] = scaling * temp22;

        if (rotationcenter)
        {
            out->u.m[3][0] = rotationcenter->x * (1.0f - temp00) - rotationcenter->y * temp10
                    - rotationcenter->z * temp20;
            out->u.m[3][1] = rotationcenter->y * (1.0f - temp11) - rotationcenter->x * temp01
                    - rotationcenter->z * temp21;
            out->u.m[3][2] = rotationcenter->z * (1.0f - temp22) - rotationcenter->x * temp02
                    - rotationcenter->y * temp12;
        }
    }
    else
    {
        out->u.m[0][0] = scaling;
        out->u.m[1][1] = scaling;
        out->u.m[2][2] = scaling;
    }

    if (translation)
    {
        out->u.m[3][0] += translation->x;
        out->u.m[3][1] += translation->y;
        out->u.m[3][2] += translation->z;
    }

    return out;
}

D3DXMATRIX * WINAPI D3DXMatrixAffineTransformation2D(D3DXMATRIX *out, FLOAT scaling,
        const D3DXVECTOR2 *rotationcenter, FLOAT rotation, const D3DXVECTOR2 *translation)
{
    FLOAT tmp1, tmp2, s;

    TRACE("out %p, scaling %f, rotationcenter %p, rotation %f, translation %p\n",
            out, scaling, rotationcenter, rotation, translation);

    s = sinf(rotation / 2.0f);
    tmp1 = 1.0f - 2.0f * s * s;
    tmp2 = 2.0f * s * cosf(rotation / 2.0f);

    D3DXMatrixIdentity(out);
    out->u.m[0][0] = scaling * tmp1;
    out->u.m[0][1] = scaling * tmp2;
    out->u.m[1][0] = -scaling * tmp2;
    out->u.m[1][1] = scaling * tmp1;

    if (rotationcenter)
    {
        FLOAT x, y;

        x = rotationcenter->x;
        y = rotationcenter->y;

        out->u.m[3][0] = y * tmp2 - x * tmp1 + x;
        out->u.m[3][1] = -x * tmp2 - y * tmp1 + y;
    }

    if (translation)
    {
        out->u.m[3][0] += translation->x;
        out->u.m[3][1] += translation->y;
    }

    return out;
}

HRESULT WINAPI D3DXMatrixDecompose(D3DXVECTOR3 *poutscale, D3DXQUATERNION *poutrotation, D3DXVECTOR3 *pouttranslation, const D3DXMATRIX *pm)
{
    D3DXMATRIX normalized;
    D3DXVECTOR3 vec;

    TRACE("poutscale %p, poutrotation %p, pouttranslation %p, pm %p\n", poutscale, poutrotation, pouttranslation, pm);

    /*Compute the scaling part.*/
    vec.x=pm->u.m[0][0];
    vec.y=pm->u.m[0][1];
    vec.z=pm->u.m[0][2];
    poutscale->x=D3DXVec3Length(&vec);

    vec.x=pm->u.m[1][0];
    vec.y=pm->u.m[1][1];
    vec.z=pm->u.m[1][2];
    poutscale->y=D3DXVec3Length(&vec);

    vec.x=pm->u.m[2][0];
    vec.y=pm->u.m[2][1];
    vec.z=pm->u.m[2][2];
    poutscale->z=D3DXVec3Length(&vec);

    /*Compute the translation part.*/
    pouttranslation->x=pm->u.m[3][0];
    pouttranslation->y=pm->u.m[3][1];
    pouttranslation->z=pm->u.m[3][2];

    /*Let's calculate the rotation now*/
    if ( (poutscale->x == 0.0f) || (poutscale->y == 0.0f) || (poutscale->z == 0.0f) ) return D3DERR_INVALIDCALL;

    normalized.u.m[0][0]=pm->u.m[0][0]/poutscale->x;
    normalized.u.m[0][1]=pm->u.m[0][1]/poutscale->x;
    normalized.u.m[0][2]=pm->u.m[0][2]/poutscale->x;
    normalized.u.m[1][0]=pm->u.m[1][0]/poutscale->y;
    normalized.u.m[1][1]=pm->u.m[1][1]/poutscale->y;
    normalized.u.m[1][2]=pm->u.m[1][2]/poutscale->y;
    normalized.u.m[2][0]=pm->u.m[2][0]/poutscale->z;
    normalized.u.m[2][1]=pm->u.m[2][1]/poutscale->z;
    normalized.u.m[2][2]=pm->u.m[2][2]/poutscale->z;

    D3DXQuaternionRotationMatrix(poutrotation,&normalized);
    return S_OK;
}

FLOAT WINAPI D3DXMatrixDeterminant(const D3DXMATRIX *pm)
{
    FLOAT t[3], v[4];

    TRACE("pm %p\n", pm);

    t[0] = pm->u.m[2][2] * pm->u.m[3][3] - pm->u.m[2][3] * pm->u.m[3][2];
    t[1] = pm->u.m[1][2] * pm->u.m[3][3] - pm->u.m[1][3] * pm->u.m[3][2];
    t[2] = pm->u.m[1][2] * pm->u.m[2][3] - pm->u.m[1][3] * pm->u.m[2][2];
    v[0] = pm->u.m[1][1] * t[0] - pm->u.m[2][1] * t[1] + pm->u.m[3][1] * t[2];
    v[1] = -pm->u.m[1][0] * t[0] + pm->u.m[2][0] * t[1] - pm->u.m[3][0] * t[2];

    t[0] = pm->u.m[1][0] * pm->u.m[2][1] - pm->u.m[2][0] * pm->u.m[1][1];
    t[1] = pm->u.m[1][0] * pm->u.m[3][1] - pm->u.m[3][0] * pm->u.m[1][1];
    t[2] = pm->u.m[2][0] * pm->u.m[3][1] - pm->u.m[3][0] * pm->u.m[2][1];
    v[2] = pm->u.m[3][3] * t[0] - pm->u.m[2][3] * t[1] + pm->u.m[1][3] * t[2];
    v[3] = -pm->u.m[3][2] * t[0] + pm->u.m[2][2] * t[1] - pm->u.m[1][2] * t[2];

    return pm->u.m[0][0] * v[0] + pm->u.m[0][1] * v[1] +
        pm->u.m[0][2] * v[2] + pm->u.m[0][3] * v[3];
}

D3DXMATRIX* WINAPI D3DXMatrixInverse(D3DXMATRIX *pout, FLOAT *pdeterminant, const D3DXMATRIX *pm)
{
    FLOAT det, t[3], v[16];
    UINT i, j;

    TRACE("pout %p, pdeterminant %p, pm %p\n", pout, pdeterminant, pm);

    t[0] = pm->u.m[2][2] * pm->u.m[3][3] - pm->u.m[2][3] * pm->u.m[3][2];
    t[1] = pm->u.m[1][2] * pm->u.m[3][3] - pm->u.m[1][3] * pm->u.m[3][2];
    t[2] = pm->u.m[1][2] * pm->u.m[2][3] - pm->u.m[1][3] * pm->u.m[2][2];
    v[0] = pm->u.m[1][1] * t[0] - pm->u.m[2][1] * t[1] + pm->u.m[3][1] * t[2];
    v[4] = -pm->u.m[1][0] * t[0] + pm->u.m[2][0] * t[1] - pm->u.m[3][0] * t[2];

    t[0] = pm->u.m[1][0] * pm->u.m[2][1] - pm->u.m[2][0] * pm->u.m[1][1];
    t[1] = pm->u.m[1][0] * pm->u.m[3][1] - pm->u.m[3][0] * pm->u.m[1][1];
    t[2] = pm->u.m[2][0] * pm->u.m[3][1] - pm->u.m[3][0] * pm->u.m[2][1];
    v[8] = pm->u.m[3][3] * t[0] - pm->u.m[2][3] * t[1] + pm->u.m[1][3] * t[2];
    v[12] = -pm->u.m[3][2] * t[0] + pm->u.m[2][2] * t[1] - pm->u.m[1][2] * t[2];

    det = pm->u.m[0][0] * v[0] + pm->u.m[0][1] * v[4] +
        pm->u.m[0][2] * v[8] + pm->u.m[0][3] * v[12];
    if (det == 0.0f)
        return NULL;
    if (pdeterminant)
        *pdeterminant = det;

    t[0] = pm->u.m[2][2] * pm->u.m[3][3] - pm->u.m[2][3] * pm->u.m[3][2];
    t[1] = pm->u.m[0][2] * pm->u.m[3][3] - pm->u.m[0][3] * pm->u.m[3][2];
    t[2] = pm->u.m[0][2] * pm->u.m[2][3] - pm->u.m[0][3] * pm->u.m[2][2];
    v[1] = -pm->u.m[0][1] * t[0] + pm->u.m[2][1] * t[1] - pm->u.m[3][1] * t[2];
    v[5] = pm->u.m[0][0] * t[0] - pm->u.m[2][0] * t[1] + pm->u.m[3][0] * t[2];

    t[0] = pm->u.m[0][0] * pm->u.m[2][1] - pm->u.m[2][0] * pm->u.m[0][1];
    t[1] = pm->u.m[3][0] * pm->u.m[0][1] - pm->u.m[0][0] * pm->u.m[3][1];
    t[2] = pm->u.m[2][0] * pm->u.m[3][1] - pm->u.m[3][0] * pm->u.m[2][1];
    v[9] = -pm->u.m[3][3] * t[0] - pm->u.m[2][3] * t[1]- pm->u.m[0][3] * t[2];
    v[13] = pm->u.m[3][2] * t[0] + pm->u.m[2][2] * t[1] + pm->u.m[0][2] * t[2];

    t[0] = pm->u.m[1][2] * pm->u.m[3][3] - pm->u.m[1][3] * pm->u.m[3][2];
    t[1] = pm->u.m[0][2] * pm->u.m[3][3] - pm->u.m[0][3] * pm->u.m[3][2];
    t[2] = pm->u.m[0][2] * pm->u.m[1][3] - pm->u.m[0][3] * pm->u.m[1][2];
    v[2] = pm->u.m[0][1] * t[0] - pm->u.m[1][1] * t[1] + pm->u.m[3][1] * t[2];
    v[6] = -pm->u.m[0][0] * t[0] + pm->u.m[1][0] * t[1] - pm->u.m[3][0] * t[2];

    t[0] = pm->u.m[0][0] * pm->u.m[1][1] - pm->u.m[1][0] * pm->u.m[0][1];
    t[1] = pm->u.m[3][0] * pm->u.m[0][1] - pm->u.m[0][0] * pm->u.m[3][1];
    t[2] = pm->u.m[1][0] * pm->u.m[3][1] - pm->u.m[3][0] * pm->u.m[1][1];
    v[10] = pm->u.m[3][3] * t[0] + pm->u.m[1][3] * t[1] + pm->u.m[0][3] * t[2];
    v[14] = -pm->u.m[3][2] * t[0] - pm->u.m[1][2] * t[1] - pm->u.m[0][2] * t[2];

    t[0] = pm->u.m[1][2] * pm->u.m[2][3] - pm->u.m[1][3] * pm->u.m[2][2];
    t[1] = pm->u.m[0][2] * pm->u.m[2][3] - pm->u.m[0][3] * pm->u.m[2][2];
    t[2] = pm->u.m[0][2] * pm->u.m[1][3] - pm->u.m[0][3] * pm->u.m[1][2];
    v[3] = -pm->u.m[0][1] * t[0] + pm->u.m[1][1] * t[1] - pm->u.m[2][1] * t[2];
    v[7] = pm->u.m[0][0] * t[0] - pm->u.m[1][0] * t[1] + pm->u.m[2][0] * t[2];

    v[11] = -pm->u.m[0][0] * (pm->u.m[1][1] * pm->u.m[2][3] - pm->u.m[1][3] * pm->u.m[2][1]) +
        pm->u.m[1][0] * (pm->u.m[0][1] * pm->u.m[2][3] - pm->u.m[0][3] * pm->u.m[2][1]) -
        pm->u.m[2][0] * (pm->u.m[0][1] * pm->u.m[1][3] - pm->u.m[0][3] * pm->u.m[1][1]);

    v[15] = pm->u.m[0][0] * (pm->u.m[1][1] * pm->u.m[2][2] - pm->u.m[1][2] * pm->u.m[2][1]) -
        pm->u.m[1][0] * (pm->u.m[0][1] * pm->u.m[2][2] - pm->u.m[0][2] * pm->u.m[2][1]) +
        pm->u.m[2][0] * (pm->u.m[0][1] * pm->u.m[1][2] - pm->u.m[0][2] * pm->u.m[1][1]);

    det = 1.0f / det;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            pout->u.m[i][j] = v[4 * i + j] * det;

    return pout;
}

D3DXMATRIX * WINAPI D3DXMatrixLookAtLH(D3DXMATRIX *out, const D3DXVECTOR3 *eye, const D3DXVECTOR3 *at,
        const D3DXVECTOR3 *up)
{
    D3DXVECTOR3 right, upn, vec;

    TRACE("out %p, eye %p, at %p, up %p\n", out, eye, at, up);

    D3DXVec3Subtract(&vec, at, eye);
    D3DXVec3Normalize(&vec, &vec);
    D3DXVec3Cross(&right, up, &vec);
    D3DXVec3Cross(&upn, &vec, &right);
    D3DXVec3Normalize(&right, &right);
    D3DXVec3Normalize(&upn, &upn);
    out->u.m[0][0] = right.x;
    out->u.m[1][0] = right.y;
    out->u.m[2][0] = right.z;
    out->u.m[3][0] = -D3DXVec3Dot(&right, eye);
    out->u.m[0][1] = upn.x;
    out->u.m[1][1] = upn.y;
    out->u.m[2][1] = upn.z;
    out->u.m[3][1] = -D3DXVec3Dot(&upn, eye);
    out->u.m[0][2] = vec.x;
    out->u.m[1][2] = vec.y;
    out->u.m[2][2] = vec.z;
    out->u.m[3][2] = -D3DXVec3Dot(&vec, eye);
    out->u.m[0][3] = 0.0f;
    out->u.m[1][3] = 0.0f;
    out->u.m[2][3] = 0.0f;
    out->u.m[3][3] = 1.0f;

    return out;
}

D3DXMATRIX * WINAPI D3DXMatrixLookAtRH(D3DXMATRIX *out, const D3DXVECTOR3 *eye, const D3DXVECTOR3 *at,
        const D3DXVECTOR3 *up)
{
    D3DXVECTOR3 right, upn, vec;

    TRACE("out %p, eye %p, at %p, up %p\n", out, eye, at, up);

    D3DXVec3Subtract(&vec, at, eye);
    D3DXVec3Normalize(&vec, &vec);
    D3DXVec3Cross(&right, up, &vec);
    D3DXVec3Cross(&upn, &vec, &right);
    D3DXVec3Normalize(&right, &right);
    D3DXVec3Normalize(&upn, &upn);
    out->u.m[0][0] = -right.x;
    out->u.m[1][0] = -right.y;
    out->u.m[2][0] = -right.z;
    out->u.m[3][0] = D3DXVec3Dot(&right, eye);
    out->u.m[0][1] = upn.x;
    out->u.m[1][1] = upn.y;
    out->u.m[2][1] = upn.z;
    out->u.m[3][1] = -D3DXVec3Dot(&upn, eye);
    out->u.m[0][2] = -vec.x;
    out->u.m[1][2] = -vec.y;
    out->u.m[2][2] = -vec.z;
    out->u.m[3][2] = D3DXVec3Dot(&vec, eye);
    out->u.m[0][3] = 0.0f;
    out->u.m[1][3] = 0.0f;
    out->u.m[2][3] = 0.0f;
    out->u.m[3][3] = 1.0f;

    return out;
}

D3DXMATRIX* WINAPI D3DXMatrixMultiply(D3DXMATRIX *pout, const D3DXMATRIX *pm1, const D3DXMATRIX *pm2)
{
    D3DXMATRIX out;
    int i,j;

    TRACE("pout %p, pm1 %p, pm2 %p\n", pout, pm1, pm2);

    for (i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            out.u.m[i][j] = pm1->u.m[i][0] * pm2->u.m[0][j] + pm1->u.m[i][1] * pm2->u.m[1][j] + pm1->u.m[i][2] * pm2->u.m[2][j] + pm1->u.m[i][3] * pm2->u.m[3][j];
        }
    }

    *pout = out;
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixMultiplyTranspose(D3DXMATRIX *pout, const D3DXMATRIX *pm1, const D3DXMATRIX *pm2)
{
    D3DXMATRIX temp;
    int i, j;

    TRACE("pout %p, pm1 %p, pm2 %p\n", pout, pm1, pm2);

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            temp.u.m[j][i] = pm1->u.m[i][0] * pm2->u.m[0][j] + pm1->u.m[i][1] * pm2->u.m[1][j] + pm1->u.m[i][2] * pm2->u.m[2][j] + pm1->u.m[i][3] * pm2->u.m[3][j];

    *pout = temp;
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixOrthoLH(D3DXMATRIX *pout, FLOAT w, FLOAT h, FLOAT zn, FLOAT zf)
{
    TRACE("pout %p, w %f, h %f, zn %f, zf %f\n", pout, w, h, zn, zf);

    D3DXMatrixIdentity(pout);
    pout->u.m[0][0] = 2.0f / w;
    pout->u.m[1][1] = 2.0f / h;
    pout->u.m[2][2] = 1.0f / (zf - zn);
    pout->u.m[3][2] = zn / (zn - zf);
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixOrthoOffCenterLH(D3DXMATRIX *pout, FLOAT l, FLOAT r, FLOAT b, FLOAT t, FLOAT zn, FLOAT zf)
{
    TRACE("pout %p, l %f, r %f, b %f, t %f, zn %f, zf %f\n", pout, l, r, b, t, zn, zf);

    D3DXMatrixIdentity(pout);
    pout->u.m[0][0] = 2.0f / (r - l);
    pout->u.m[1][1] = 2.0f / (t - b);
    pout->u.m[2][2] = 1.0f / (zf -zn);
    pout->u.m[3][0] = -1.0f -2.0f *l / (r - l);
    pout->u.m[3][1] = 1.0f + 2.0f * t / (b - t);
    pout->u.m[3][2] = zn / (zn -zf);
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixOrthoOffCenterRH(D3DXMATRIX *pout, FLOAT l, FLOAT r, FLOAT b, FLOAT t, FLOAT zn, FLOAT zf)
{
    TRACE("pout %p, l %f, r %f, b %f, t %f, zn %f, zf %f\n", pout, l, r, b, t, zn, zf);

    D3DXMatrixIdentity(pout);
    pout->u.m[0][0] = 2.0f / (r - l);
    pout->u.m[1][1] = 2.0f / (t - b);
    pout->u.m[2][2] = 1.0f / (zn -zf);
    pout->u.m[3][0] = -1.0f -2.0f *l / (r - l);
    pout->u.m[3][1] = 1.0f + 2.0f * t / (b - t);
    pout->u.m[3][2] = zn / (zn -zf);
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixOrthoRH(D3DXMATRIX *pout, FLOAT w, FLOAT h, FLOAT zn, FLOAT zf)
{
    TRACE("pout %p, w %f, h %f, zn %f, zf %f\n", pout, w, h, zn, zf);

    D3DXMatrixIdentity(pout);
    pout->u.m[0][0] = 2.0f / w;
    pout->u.m[1][1] = 2.0f / h;
    pout->u.m[2][2] = 1.0f / (zn - zf);
    pout->u.m[3][2] = zn / (zn - zf);
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixPerspectiveFovLH(D3DXMATRIX *pout, FLOAT fovy, FLOAT aspect, FLOAT zn, FLOAT zf)
{
    TRACE("pout %p, fovy %f, aspect %f, zn %f, zf %f\n", pout, fovy, aspect, zn, zf);

    D3DXMatrixIdentity(pout);
    pout->u.m[0][0] = 1.0f / (aspect * tanf(fovy/2.0f));
    pout->u.m[1][1] = 1.0f / tanf(fovy/2.0f);
    pout->u.m[2][2] = zf / (zf - zn);
    pout->u.m[2][3] = 1.0f;
    pout->u.m[3][2] = (zf * zn) / (zn - zf);
    pout->u.m[3][3] = 0.0f;
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixPerspectiveFovRH(D3DXMATRIX *pout, FLOAT fovy, FLOAT aspect, FLOAT zn, FLOAT zf)
{
    TRACE("pout %p, fovy %f, aspect %f, zn %f, zf %f\n", pout, fovy, aspect, zn, zf);

    D3DXMatrixIdentity(pout);
    pout->u.m[0][0] = 1.0f / (aspect * tanf(fovy/2.0f));
    pout->u.m[1][1] = 1.0f / tanf(fovy/2.0f);
    pout->u.m[2][2] = zf / (zn - zf);
    pout->u.m[2][3] = -1.0f;
    pout->u.m[3][2] = (zf * zn) / (zn - zf);
    pout->u.m[3][3] = 0.0f;
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixPerspectiveLH(D3DXMATRIX *pout, FLOAT w, FLOAT h, FLOAT zn, FLOAT zf)
{
    TRACE("pout %p, w %f, h %f, zn %f, zf %f\n", pout, w, h, zn, zf);

    D3DXMatrixIdentity(pout);
    pout->u.m[0][0] = 2.0f * zn / w;
    pout->u.m[1][1] = 2.0f * zn / h;
    pout->u.m[2][2] = zf / (zf - zn);
    pout->u.m[3][2] = (zn * zf) / (zn - zf);
    pout->u.m[2][3] = 1.0f;
    pout->u.m[3][3] = 0.0f;
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixPerspectiveOffCenterLH(D3DXMATRIX *pout, FLOAT l, FLOAT r, FLOAT b, FLOAT t, FLOAT zn, FLOAT zf)
{
    TRACE("pout %p, l %f, r %f, b %f, t %f, zn %f, zf %f\n", pout, l, r, b, t, zn, zf);

    D3DXMatrixIdentity(pout);
    pout->u.m[0][0] = 2.0f * zn / (r - l);
    pout->u.m[1][1] = -2.0f * zn / (b - t);
    pout->u.m[2][0] = -1.0f - 2.0f * l / (r - l);
    pout->u.m[2][1] = 1.0f + 2.0f * t / (b - t);
    pout->u.m[2][2] = - zf / (zn - zf);
    pout->u.m[3][2] = (zn * zf) / (zn -zf);
    pout->u.m[2][3] = 1.0f;
    pout->u.m[3][3] = 0.0f;
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixPerspectiveOffCenterRH(D3DXMATRIX *pout, FLOAT l, FLOAT r, FLOAT b, FLOAT t, FLOAT zn, FLOAT zf)
{
    TRACE("pout %p, l %f, r %f, b %f, t %f, zn %f, zf %f\n", pout, l, r, b, t, zn, zf);

    D3DXMatrixIdentity(pout);
    pout->u.m[0][0] = 2.0f * zn / (r - l);
    pout->u.m[1][1] = -2.0f * zn / (b - t);
    pout->u.m[2][0] = 1.0f + 2.0f * l / (r - l);
    pout->u.m[2][1] = -1.0f -2.0f * t / (b - t);
    pout->u.m[2][2] = zf / (zn - zf);
    pout->u.m[3][2] = (zn * zf) / (zn -zf);
    pout->u.m[2][3] = -1.0f;
    pout->u.m[3][3] = 0.0f;
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixPerspectiveRH(D3DXMATRIX *pout, FLOAT w, FLOAT h, FLOAT zn, FLOAT zf)
{
    TRACE("pout %p, w %f, h %f, zn %f, zf %f\n", pout, w, h, zn, zf);

    D3DXMatrixIdentity(pout);
    pout->u.m[0][0] = 2.0f * zn / w;
    pout->u.m[1][1] = 2.0f * zn / h;
    pout->u.m[2][2] = zf / (zn - zf);
    pout->u.m[3][2] = (zn * zf) / (zn - zf);
    pout->u.m[2][3] = -1.0f;
    pout->u.m[3][3] = 0.0f;
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixReflect(D3DXMATRIX *pout, const D3DXPLANE *pplane)
{
    D3DXPLANE Nplane;

    TRACE("pout %p, pplane %p\n", pout, pplane);

    D3DXPlaneNormalize(&Nplane, pplane);
    D3DXMatrixIdentity(pout);
    pout->u.m[0][0] = 1.0f - 2.0f * Nplane.a * Nplane.a;
    pout->u.m[0][1] = -2.0f * Nplane.a * Nplane.b;
    pout->u.m[0][2] = -2.0f * Nplane.a * Nplane.c;
    pout->u.m[1][0] = -2.0f * Nplane.a * Nplane.b;
    pout->u.m[1][1] = 1.0f - 2.0f * Nplane.b * Nplane.b;
    pout->u.m[1][2] = -2.0f * Nplane.b * Nplane.c;
    pout->u.m[2][0] = -2.0f * Nplane.c * Nplane.a;
    pout->u.m[2][1] = -2.0f * Nplane.c * Nplane.b;
    pout->u.m[2][2] = 1.0f - 2.0f * Nplane.c * Nplane.c;
    pout->u.m[3][0] = -2.0f * Nplane.d * Nplane.a;
    pout->u.m[3][1] = -2.0f * Nplane.d * Nplane.b;
    pout->u.m[3][2] = -2.0f * Nplane.d * Nplane.c;
    return pout;
}

D3DXMATRIX * WINAPI D3DXMatrixRotationAxis(D3DXMATRIX *out, const D3DXVECTOR3 *v, FLOAT angle)
{
    D3DXVECTOR3 nv;
    FLOAT sangle, cangle, cdiff;

    TRACE("out %p, v %p, angle %f\n", out, v, angle);

    D3DXVec3Normalize(&nv, v);
    sangle = sinf(angle);
    cangle = cosf(angle);
    cdiff = 1.0f - cangle;

    out->u.m[0][0] = cdiff * nv.x * nv.x + cangle;
    out->u.m[1][0] = cdiff * nv.x * nv.y - sangle * nv.z;
    out->u.m[2][0] = cdiff * nv.x * nv.z + sangle * nv.y;
    out->u.m[3][0] = 0.0f;
    out->u.m[0][1] = cdiff * nv.y * nv.x + sangle * nv.z;
    out->u.m[1][1] = cdiff * nv.y * nv.y + cangle;
    out->u.m[2][1] = cdiff * nv.y * nv.z - sangle * nv.x;
    out->u.m[3][1] = 0.0f;
    out->u.m[0][2] = cdiff * nv.z * nv.x - sangle * nv.y;
    out->u.m[1][2] = cdiff * nv.z * nv.y + sangle * nv.x;
    out->u.m[2][2] = cdiff * nv.z * nv.z + cangle;
    out->u.m[3][2] = 0.0f;
    out->u.m[0][3] = 0.0f;
    out->u.m[1][3] = 0.0f;
    out->u.m[2][3] = 0.0f;
    out->u.m[3][3] = 1.0f;

    return out;
}

D3DXMATRIX* WINAPI D3DXMatrixRotationQuaternion(D3DXMATRIX *pout, const D3DXQUATERNION *pq)
{
    TRACE("pout %p, pq %p\n", pout, pq);

    D3DXMatrixIdentity(pout);
    pout->u.m[0][0] = 1.0f - 2.0f * (pq->y * pq->y + pq->z * pq->z);
    pout->u.m[0][1] = 2.0f * (pq->x *pq->y + pq->z * pq->w);
    pout->u.m[0][2] = 2.0f * (pq->x * pq->z - pq->y * pq->w);
    pout->u.m[1][0] = 2.0f * (pq->x * pq->y - pq->z * pq->w);
    pout->u.m[1][1] = 1.0f - 2.0f * (pq->x * pq->x + pq->z * pq->z);
    pout->u.m[1][2] = 2.0f * (pq->y *pq->z + pq->x *pq->w);
    pout->u.m[2][0] = 2.0f * (pq->x * pq->z + pq->y * pq->w);
    pout->u.m[2][1] = 2.0f * (pq->y *pq->z - pq->x *pq->w);
    pout->u.m[2][2] = 1.0f - 2.0f * (pq->x * pq->x + pq->y * pq->y);
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixRotationX(D3DXMATRIX *pout, FLOAT angle)
{
    TRACE("pout %p, angle %f\n", pout, angle);

    D3DXMatrixIdentity(pout);
    pout->u.m[1][1] = cosf(angle);
    pout->u.m[2][2] = cosf(angle);
    pout->u.m[1][2] = sinf(angle);
    pout->u.m[2][1] = -sinf(angle);
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixRotationY(D3DXMATRIX *pout, FLOAT angle)
{
    TRACE("pout %p, angle %f\n", pout, angle);

    D3DXMatrixIdentity(pout);
    pout->u.m[0][0] = cosf(angle);
    pout->u.m[2][2] = cosf(angle);
    pout->u.m[0][2] = -sinf(angle);
    pout->u.m[2][0] = sinf(angle);
    return pout;
}

D3DXMATRIX * WINAPI D3DXMatrixRotationYawPitchRoll(D3DXMATRIX *out, FLOAT yaw, FLOAT pitch, FLOAT roll)
{
    FLOAT sroll, croll, spitch, cpitch, syaw, cyaw;

    TRACE("out %p, yaw %f, pitch %f, roll %f\n", out, yaw, pitch, roll);

    sroll = sinf(roll);
    croll = cosf(roll);
    spitch = sinf(pitch);
    cpitch = cosf(pitch);
    syaw = sinf(yaw);
    cyaw = cosf(yaw);

    out->u.m[0][0] = sroll * spitch * syaw + croll * cyaw;
    out->u.m[0][1] = sroll * cpitch;
    out->u.m[0][2] = sroll * spitch * cyaw - croll * syaw;
    out->u.m[0][3] = 0.0f;
    out->u.m[1][0] = croll * spitch * syaw - sroll * cyaw;
    out->u.m[1][1] = croll * cpitch;
    out->u.m[1][2] = croll * spitch * cyaw + sroll * syaw;
    out->u.m[1][3] = 0.0f;
    out->u.m[2][0] = cpitch * syaw;
    out->u.m[2][1] = -spitch;
    out->u.m[2][2] = cpitch * cyaw;
    out->u.m[2][3] = 0.0f;
    out->u.m[3][0] = 0.0f;
    out->u.m[3][1] = 0.0f;
    out->u.m[3][2] = 0.0f;
    out->u.m[3][3] = 1.0f;

    return out;
}

D3DXMATRIX* WINAPI D3DXMatrixRotationZ(D3DXMATRIX *pout, FLOAT angle)
{
    TRACE("pout %p, angle %f\n", pout, angle);

    D3DXMatrixIdentity(pout);
    pout->u.m[0][0] = cosf(angle);
    pout->u.m[1][1] = cosf(angle);
    pout->u.m[0][1] = sinf(angle);
    pout->u.m[1][0] = -sinf(angle);
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixScaling(D3DXMATRIX *pout, FLOAT sx, FLOAT sy, FLOAT sz)
{
    TRACE("pout %p, sx %f, sy %f, sz %f\n", pout, sx, sy, sz);

    D3DXMatrixIdentity(pout);
    pout->u.m[0][0] = sx;
    pout->u.m[1][1] = sy;
    pout->u.m[2][2] = sz;
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixShadow(D3DXMATRIX *pout, const D3DXVECTOR4 *plight, const D3DXPLANE *pplane)
{
    D3DXPLANE Nplane;
    FLOAT dot;

    TRACE("pout %p, plight %p, pplane %p\n", pout, plight, pplane);

    D3DXPlaneNormalize(&Nplane, pplane);
    dot = D3DXPlaneDot(&Nplane, plight);
    pout->u.m[0][0] = dot - Nplane.a * plight->x;
    pout->u.m[0][1] = -Nplane.a * plight->y;
    pout->u.m[0][2] = -Nplane.a * plight->z;
    pout->u.m[0][3] = -Nplane.a * plight->w;
    pout->u.m[1][0] = -Nplane.b * plight->x;
    pout->u.m[1][1] = dot - Nplane.b * plight->y;
    pout->u.m[1][2] = -Nplane.b * plight->z;
    pout->u.m[1][3] = -Nplane.b * plight->w;
    pout->u.m[2][0] = -Nplane.c * plight->x;
    pout->u.m[2][1] = -Nplane.c * plight->y;
    pout->u.m[2][2] = dot - Nplane.c * plight->z;
    pout->u.m[2][3] = -Nplane.c * plight->w;
    pout->u.m[3][0] = -Nplane.d * plight->x;
    pout->u.m[3][1] = -Nplane.d * plight->y;
    pout->u.m[3][2] = -Nplane.d * plight->z;
    pout->u.m[3][3] = dot - Nplane.d * plight->w;
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixTransformation(D3DXMATRIX *pout, const D3DXVECTOR3 *pscalingcenter, const D3DXQUATERNION *pscalingrotation, const D3DXVECTOR3 *pscaling, const D3DXVECTOR3 *protationcenter, const D3DXQUATERNION *protation, const D3DXVECTOR3 *ptranslation)
{
    D3DXMATRIX m1, m2, m3, m4, m5, m6, m7;
    D3DXQUATERNION prc;
    D3DXVECTOR3 psc, pt;

    TRACE("pout %p, pscalingcenter %p, pscalingrotation %p, pscaling %p, protationcentr %p, protation %p, ptranslation %p\n",
        pout, pscalingcenter, pscalingrotation, pscaling, protationcenter, protation, ptranslation);

    if ( !pscalingcenter )
    {
        psc.x = 0.0f;
        psc.y = 0.0f;
        psc.z = 0.0f;
    }
    else
    {
        psc.x = pscalingcenter->x;
        psc.y = pscalingcenter->y;
        psc.z = pscalingcenter->z;
    }

    if ( !protationcenter )
    {
        prc.x = 0.0f;
        prc.y = 0.0f;
        prc.z = 0.0f;
    }
    else
    {
        prc.x = protationcenter->x;
        prc.y = protationcenter->y;
        prc.z = protationcenter->z;
    }

    if ( !ptranslation )
    {
        pt.x = 0.0f;
        pt.y = 0.0f;
        pt.z = 0.0f;
    }
    else
    {
        pt.x = ptranslation->x;
        pt.y = ptranslation->y;
        pt.z = ptranslation->z;
    }

    D3DXMatrixTranslation(&m1, -psc.x, -psc.y, -psc.z);

    if ( !pscalingrotation )
    {
        D3DXMatrixIdentity(&m2);
        D3DXMatrixIdentity(&m4);
    }
    else
    {
        D3DXMatrixRotationQuaternion(&m4, pscalingrotation);
        D3DXMatrixInverse(&m2, NULL, &m4);
    }

    if ( !pscaling ) D3DXMatrixIdentity(&m3);
    else D3DXMatrixScaling(&m3, pscaling->x, pscaling->y, pscaling->z);

    if ( !protation ) D3DXMatrixIdentity(&m6);
    else D3DXMatrixRotationQuaternion(&m6, protation);

    D3DXMatrixTranslation(&m5, psc.x - prc.x,  psc.y - prc.y,  psc.z - prc.z);
    D3DXMatrixTranslation(&m7, prc.x + pt.x, prc.y + pt.y, prc.z + pt.z);
    D3DXMatrixMultiply(&m1, &m1, &m2);
    D3DXMatrixMultiply(&m1, &m1, &m3);
    D3DXMatrixMultiply(&m1, &m1, &m4);
    D3DXMatrixMultiply(&m1, &m1, &m5);
    D3DXMatrixMultiply(&m1, &m1, &m6);
    D3DXMatrixMultiply(pout, &m1, &m7);
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixTransformation2D(D3DXMATRIX *pout, const D3DXVECTOR2 *pscalingcenter, FLOAT scalingrotation, const D3DXVECTOR2 *pscaling, const D3DXVECTOR2 *protationcenter, FLOAT rotation, const D3DXVECTOR2 *ptranslation)
{
    D3DXQUATERNION rot, sca_rot;
    D3DXVECTOR3 rot_center, sca, sca_center, trans;

    TRACE("pout %p, pscalingcenter %p, scalingrotation %f, pscaling %p, protztioncenter %p, rotation %f, ptranslation %p\n",
        pout, pscalingcenter, scalingrotation, pscaling, protationcenter, rotation, ptranslation);

    if ( pscalingcenter )
    {
        sca_center.x=pscalingcenter->x;
        sca_center.y=pscalingcenter->y;
        sca_center.z=0.0f;
    }
    else
    {
        sca_center.x=0.0f;
        sca_center.y=0.0f;
        sca_center.z=0.0f;
    }

    if ( pscaling )
    {
        sca.x=pscaling->x;
        sca.y=pscaling->y;
        sca.z=1.0f;
    }
    else
    {
        sca.x=1.0f;
        sca.y=1.0f;
        sca.z=1.0f;
    }

    if ( protationcenter )
    {
        rot_center.x=protationcenter->x;
        rot_center.y=protationcenter->y;
        rot_center.z=0.0f;
    }
    else
    {
        rot_center.x=0.0f;
        rot_center.y=0.0f;
        rot_center.z=0.0f;
    }

    if ( ptranslation )
    {
        trans.x=ptranslation->x;
        trans.y=ptranslation->y;
        trans.z=0.0f;
    }
    else
    {
        trans.x=0.0f;
        trans.y=0.0f;
        trans.z=0.0f;
    }

    rot.w=cosf(rotation/2.0f);
    rot.x=0.0f;
    rot.y=0.0f;
    rot.z=sinf(rotation/2.0f);

    sca_rot.w=cosf(scalingrotation/2.0f);
    sca_rot.x=0.0f;
    sca_rot.y=0.0f;
    sca_rot.z=sinf(scalingrotation/2.0f);

    D3DXMatrixTransformation(pout, &sca_center, &sca_rot, &sca, &rot_center, &rot, &trans);

    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixTranslation(D3DXMATRIX *pout, FLOAT x, FLOAT y, FLOAT z)
{
    TRACE("pout %p, x %f, y %f, z %f\n", pout, x, y, z);

    D3DXMatrixIdentity(pout);
    pout->u.m[3][0] = x;
    pout->u.m[3][1] = y;
    pout->u.m[3][2] = z;
    return pout;
}

D3DXMATRIX* WINAPI D3DXMatrixTranspose(D3DXMATRIX *pout, const D3DXMATRIX *pm)
{
    const D3DXMATRIX m = *pm;
    int i,j;

    TRACE("pout %p, pm %p\n", pout, pm);

    for (i=0; i<4; i++)
        for (j=0; j<4; j++) pout->u.m[i][j] = m.u.m[j][i];

    return pout;
}

/*_________________D3DXMatrixStack____________________*/


static inline struct ID3DXMatrixStackImpl *impl_from_ID3DXMatrixStack(ID3DXMatrixStack *iface)
{
  return CONTAINING_RECORD(iface, struct ID3DXMatrixStackImpl, ID3DXMatrixStack_iface);
}

static HRESULT WINAPI ID3DXMatrixStackImpl_QueryInterface(ID3DXMatrixStack *iface, REFIID riid, void **out)
{
    TRACE("iface %p, riid %s, out %p.\n", iface, debugstr_guid(riid), out);

    if (IsEqualGUID(riid, &IID_ID3DXMatrixStack)
            || IsEqualGUID(riid, &IID_IUnknown))
    {
        ID3DXMatrixStack_AddRef(iface);
        *out = iface;
        return S_OK;
    }

    WARN("%s not implemented, returning E_NOINTERFACE.\n", debugstr_guid(riid));

    *out = NULL;
    return E_NOINTERFACE;
}

static ULONG WINAPI ID3DXMatrixStackImpl_AddRef(ID3DXMatrixStack *iface)
{
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);
    ULONG ref = InterlockedIncrement(&This->ref);
    TRACE("(%p) : AddRef from %d\n", This, ref - 1);
    return ref;
}

static ULONG WINAPI ID3DXMatrixStackImpl_Release(ID3DXMatrixStack *iface)
{
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);
    ULONG ref = InterlockedDecrement(&This->ref);
    if (!ref)
    {
        HeapFree(GetProcessHeap(), 0, This->stack);
        HeapFree(GetProcessHeap(), 0, This);
    }
    TRACE("(%p) : ReleaseRef to %d\n", This, ref);
    return ref;
}

static D3DXMATRIX* WINAPI ID3DXMatrixStackImpl_GetTop(ID3DXMatrixStack *iface)
{
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);

    TRACE("iface %p\n", iface);

    return &This->stack[This->current];
}

static HRESULT WINAPI ID3DXMatrixStackImpl_LoadIdentity(ID3DXMatrixStack *iface)
{
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);

    TRACE("iface %p\n", iface);

    D3DXMatrixIdentity(&This->stack[This->current]);

    return D3D_OK;
}

static HRESULT WINAPI ID3DXMatrixStackImpl_LoadMatrix(ID3DXMatrixStack *iface, const D3DXMATRIX *pm)
{
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);

    TRACE("iface %p, pm %p\n", iface, pm);

    This->stack[This->current] = *pm;

    return D3D_OK;
}

static HRESULT WINAPI ID3DXMatrixStackImpl_MultMatrix(ID3DXMatrixStack *iface, const D3DXMATRIX *pm)
{
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);

    TRACE("iface %p, pm %p\n", iface, pm);

    D3DXMatrixMultiply(&This->stack[This->current], &This->stack[This->current], pm);

    return D3D_OK;
}

static HRESULT WINAPI ID3DXMatrixStackImpl_MultMatrixLocal(ID3DXMatrixStack *iface, const D3DXMATRIX *pm)
{
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);

    TRACE("iface %p, pm %p\n", iface, pm);

    D3DXMatrixMultiply(&This->stack[This->current], pm, &This->stack[This->current]);

    return D3D_OK;
}

static HRESULT WINAPI ID3DXMatrixStackImpl_Pop(ID3DXMatrixStack *iface)
{
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);

    TRACE("iface %p\n", iface);

    /* Popping the last element on the stack returns D3D_OK, but does nothing. */
    if (!This->current) return D3D_OK;

    if (This->current <= This->stack_size / 4 && This->stack_size >= INITIAL_STACK_SIZE * 2)
    {
        unsigned int new_size;
        D3DXMATRIX *new_stack;

        new_size = This->stack_size / 2;
        new_stack = HeapReAlloc(GetProcessHeap(), 0, This->stack, new_size * sizeof(*new_stack));
        if (new_stack)
        {
            This->stack_size = new_size;
            This->stack = new_stack;
        }
    }

    --This->current;

    return D3D_OK;
}

static HRESULT WINAPI ID3DXMatrixStackImpl_Push(ID3DXMatrixStack *iface)
{
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);

    TRACE("iface %p\n", iface);

    if (This->current == This->stack_size - 1)
    {
        unsigned int new_size;
        D3DXMATRIX *new_stack;

        if (This->stack_size > UINT_MAX / 2) return E_OUTOFMEMORY;

        new_size = This->stack_size * 2;
        new_stack = HeapReAlloc(GetProcessHeap(), 0, This->stack, new_size * sizeof(*new_stack));
        if (!new_stack) return E_OUTOFMEMORY;

        This->stack_size = new_size;
        This->stack = new_stack;
    }

    ++This->current;
    This->stack[This->current] = This->stack[This->current - 1];

    return D3D_OK;
}

static HRESULT WINAPI ID3DXMatrixStackImpl_RotateAxis(ID3DXMatrixStack *iface, const D3DXVECTOR3 *pv, FLOAT angle)
{
    D3DXMATRIX temp;
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);

    TRACE("iface %p, pv %p, angle %f\n", iface, pv, angle);

    D3DXMatrixRotationAxis(&temp, pv, angle);
    D3DXMatrixMultiply(&This->stack[This->current], &This->stack[This->current], &temp);

    return D3D_OK;
}

static HRESULT WINAPI ID3DXMatrixStackImpl_RotateAxisLocal(ID3DXMatrixStack *iface, const D3DXVECTOR3 *pv, FLOAT angle)
{
    D3DXMATRIX temp;
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);

    TRACE("iface %p, pv %p, angle %f\n", iface, pv, angle);

    D3DXMatrixRotationAxis(&temp, pv, angle);
    D3DXMatrixMultiply(&This->stack[This->current], &temp, &This->stack[This->current]);

    return D3D_OK;
}

static HRESULT WINAPI ID3DXMatrixStackImpl_RotateYawPitchRoll(ID3DXMatrixStack *iface, FLOAT x, FLOAT y, FLOAT z)
{
    D3DXMATRIX temp;
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);

    TRACE("iface %p, x %f, y %f, z %f\n", iface, x, y, z);

    D3DXMatrixRotationYawPitchRoll(&temp, x, y, z);
    D3DXMatrixMultiply(&This->stack[This->current], &This->stack[This->current], &temp);

    return D3D_OK;
}

static HRESULT WINAPI ID3DXMatrixStackImpl_RotateYawPitchRollLocal(ID3DXMatrixStack *iface, FLOAT x, FLOAT y, FLOAT z)
{
    D3DXMATRIX temp;
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);

    TRACE("iface %p, x %f, y %f, z %f\n", iface, x, y, z);

    D3DXMatrixRotationYawPitchRoll(&temp, x, y, z);
    D3DXMatrixMultiply(&This->stack[This->current], &temp, &This->stack[This->current]);

    return D3D_OK;
}

static HRESULT WINAPI ID3DXMatrixStackImpl_Scale(ID3DXMatrixStack *iface, FLOAT x, FLOAT y, FLOAT z)
{
    D3DXMATRIX temp;
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);

    TRACE("iface %p,x %f, y %f, z %f\n", iface, x, y, z);

    D3DXMatrixScaling(&temp, x, y, z);
    D3DXMatrixMultiply(&This->stack[This->current], &This->stack[This->current], &temp);

    return D3D_OK;
}

static HRESULT WINAPI ID3DXMatrixStackImpl_ScaleLocal(ID3DXMatrixStack *iface, FLOAT x, FLOAT y, FLOAT z)
{
    D3DXMATRIX temp;
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);

    TRACE("iface %p, x %f, y %f, z %f\n", iface, x, y, z);

    D3DXMatrixScaling(&temp, x, y, z);
    D3DXMatrixMultiply(&This->stack[This->current], &temp, &This->stack[This->current]);

    return D3D_OK;
}

static HRESULT WINAPI ID3DXMatrixStackImpl_Translate(ID3DXMatrixStack *iface, FLOAT x, FLOAT y, FLOAT z)
{
    D3DXMATRIX temp;
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);

    TRACE("iface %p, x %f, y %f, z %f\n", iface, x, y, z);

    D3DXMatrixTranslation(&temp, x, y, z);
    D3DXMatrixMultiply(&This->stack[This->current], &This->stack[This->current], &temp);

    return D3D_OK;
}

static HRESULT WINAPI ID3DXMatrixStackImpl_TranslateLocal(ID3DXMatrixStack *iface, FLOAT x, FLOAT y, FLOAT z)
{
    D3DXMATRIX temp;
    struct ID3DXMatrixStackImpl *This = impl_from_ID3DXMatrixStack(iface);

    TRACE("iface %p, x %f, y %f, z %f\n", iface, x, y, z);

    D3DXMatrixTranslation(&temp, x, y, z);
    D3DXMatrixMultiply(&This->stack[This->current], &temp,&This->stack[This->current]);

    return D3D_OK;
}

static const ID3DXMatrixStackVtbl ID3DXMatrixStack_Vtbl =
{
    ID3DXMatrixStackImpl_QueryInterface,
    ID3DXMatrixStackImpl_AddRef,
    ID3DXMatrixStackImpl_Release,
    ID3DXMatrixStackImpl_Pop,
    ID3DXMatrixStackImpl_Push,
    ID3DXMatrixStackImpl_LoadIdentity,
    ID3DXMatrixStackImpl_LoadMatrix,
    ID3DXMatrixStackImpl_MultMatrix,
    ID3DXMatrixStackImpl_MultMatrixLocal,
    ID3DXMatrixStackImpl_RotateAxis,
    ID3DXMatrixStackImpl_RotateAxisLocal,
    ID3DXMatrixStackImpl_RotateYawPitchRoll,
    ID3DXMatrixStackImpl_RotateYawPitchRollLocal,
    ID3DXMatrixStackImpl_Scale,
    ID3DXMatrixStackImpl_ScaleLocal,
    ID3DXMatrixStackImpl_Translate,
    ID3DXMatrixStackImpl_TranslateLocal,
    ID3DXMatrixStackImpl_GetTop
};

HRESULT WINAPI D3DXCreateMatrixStack(DWORD flags, ID3DXMatrixStack **stack)
{
    struct ID3DXMatrixStackImpl *object;

    TRACE("flags %#x, stack %p.\n", flags, stack);

    if (!(object = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(*object))))
    {
        *stack = NULL;
        return E_OUTOFMEMORY;
    }
    object->ID3DXMatrixStack_iface.lpVtbl = &ID3DXMatrixStack_Vtbl;
    object->ref = 1;

    if (!(object->stack = HeapAlloc(GetProcessHeap(), 0, INITIAL_STACK_SIZE * sizeof(*object->stack))))
    {
        HeapFree(GetProcessHeap(), 0, object);
        *stack = NULL;
        return E_OUTOFMEMORY;
    }

    object->current = 0;
    object->stack_size = INITIAL_STACK_SIZE;
    D3DXMatrixIdentity(&object->stack[0]);

    TRACE("Created matrix stack %p.\n", object);

    *stack = &object->ID3DXMatrixStack_iface;
    return D3D_OK;
}

/*_________________D3DXPLANE________________*/

D3DXPLANE* WINAPI D3DXPlaneFromPointNormal(D3DXPLANE *pout, const D3DXVECTOR3 *pvpoint, const D3DXVECTOR3 *pvnormal)
{
    TRACE("pout %p, pvpoint %p, pvnormal %p\n", pout, pvpoint, pvnormal);

    pout->a = pvnormal->x;
    pout->b = pvnormal->y;
    pout->c = pvnormal->z;
    pout->d = -D3DXVec3Dot(pvpoint, pvnormal);
    return pout;
}

D3DXPLANE* WINAPI D3DXPlaneFromPoints(D3DXPLANE *pout, const D3DXVECTOR3 *pv1, const D3DXVECTOR3 *pv2, const D3DXVECTOR3 *pv3)
{
    D3DXVECTOR3 edge1, edge2, normal, Nnormal;

    TRACE("pout %p, pv1 %p, pv2 %p, pv3 %p\n", pout, pv1, pv2, pv3);

    edge1.x = 0.0f; edge1.y = 0.0f; edge1.z = 0.0f;
    edge2.x = 0.0f; edge2.y = 0.0f; edge2.z = 0.0f;
    D3DXVec3Subtract(&edge1, pv2, pv1);
    D3DXVec3Subtract(&edge2, pv3, pv1);
    D3DXVec3Cross(&normal, &edge1, &edge2);
    D3DXVec3Normalize(&Nnormal, &normal);
    D3DXPlaneFromPointNormal(pout, pv1, &Nnormal);
    return pout;
}

D3DXVECTOR3* WINAPI D3DXPlaneIntersectLine(D3DXVECTOR3 *pout, const D3DXPLANE *pp, const D3DXVECTOR3 *pv1, const D3DXVECTOR3 *pv2)
{
    D3DXVECTOR3 direction, normal;
    FLOAT dot, temp;

    TRACE("pout %p, pp %p, pv1 %p, pv2 %p\n", pout, pp, pv1, pv2);

    normal.x = pp->a;
    normal.y = pp->b;
    normal.z = pp->c;
    direction.x = pv2->x - pv1->x;
    direction.y = pv2->y - pv1->y;
    direction.z = pv2->z - pv1->z;
    dot = D3DXVec3Dot(&normal, &direction);
    if ( !dot ) return NULL;
    temp = ( pp->d + D3DXVec3Dot(&normal, pv1) ) / dot;
    pout->x = pv1->x - temp * direction.x;
    pout->y = pv1->y - temp * direction.y;
    pout->z = pv1->z - temp * direction.z;
    return pout;
}

D3DXPLANE * WINAPI D3DXPlaneNormalize(D3DXPLANE *out, const D3DXPLANE *p)
{
    FLOAT norm;

    TRACE("out %p, p %p\n", out, p);

    norm = sqrtf(p->a * p->a + p->b * p->b + p->c * p->c);
    if (norm)
    {
        out->a = p->a / norm;
        out->b = p->b / norm;
        out->c = p->c / norm;
        out->d = p->d / norm;
    }
    else
    {
        out->a = 0.0f;
        out->b = 0.0f;
        out->c = 0.0f;
        out->d = 0.0f;
    }

    return out;
}

D3DXPLANE* WINAPI D3DXPlaneTransform(D3DXPLANE *pout, const D3DXPLANE *pplane, const D3DXMATRIX *pm)
{
    const D3DXPLANE plane = *pplane;

    TRACE("pout %p, pplane %p, pm %p\n", pout, pplane, pm);

    pout->a = pm->u.m[0][0] * plane.a + pm->u.m[1][0] * plane.b + pm->u.m[2][0] * plane.c + pm->u.m[3][0] * plane.d;
    pout->b = pm->u.m[0][1] * plane.a + pm->u.m[1][1] * plane.b + pm->u.m[2][1] * plane.c + pm->u.m[3][1] * plane.d;
    pout->c = pm->u.m[0][2] * plane.a + pm->u.m[1][2] * plane.b + pm->u.m[2][2] * plane.c + pm->u.m[3][2] * plane.d;
    pout->d = pm->u.m[0][3] * plane.a + pm->u.m[1][3] * plane.b + pm->u.m[2][3] * plane.c + pm->u.m[3][3] * plane.d;
    return pout;
}

D3DXPLANE* WINAPI D3DXPlaneTransformArray(D3DXPLANE* out, UINT outstride, const D3DXPLANE* in, UINT instride, const D3DXMATRIX* matrix, UINT elements)
{
    UINT i;

    TRACE("out %p, outstride %u, in %p, instride %u, matrix %p, elements %u\n", out, outstride, in, instride, matrix, elements);

    for (i = 0; i < elements; ++i) {
        D3DXPlaneTransform(
            (D3DXPLANE*)((char*)out + outstride * i),
            (const D3DXPLANE*)((const char*)in + instride * i),
            matrix);
    }
    return out;
}

/*_________________D3DXQUATERNION________________*/

D3DXQUATERNION* WINAPI D3DXQuaternionBaryCentric(D3DXQUATERNION *pout, const D3DXQUATERNION *pq1, const D3DXQUATERNION *pq2, const D3DXQUATERNION *pq3, FLOAT f, FLOAT g)
{
    D3DXQUATERNION temp1, temp2;

     TRACE("pout %p, pq1 %p, pq2 %p, pq3 %p, f %f, g %f\n", pout, pq1, pq2, pq3, f, g);

    D3DXQuaternionSlerp(pout, D3DXQuaternionSlerp(&temp1, pq1, pq2, f + g), D3DXQuaternionSlerp(&temp2, pq1, pq3, f+g), g / (f + g));
    return pout;
}

D3DXQUATERNION * WINAPI D3DXQuaternionExp(D3DXQUATERNION *out, const D3DXQUATERNION *q)
{
    FLOAT norm;

    TRACE("out %p, q %p\n", out, q);

    norm = sqrtf(q->x * q->x + q->y * q->y + q->z * q->z);
    if (norm)
    {
        out->x = sinf(norm) * q->x / norm;
        out->y = sinf(norm) * q->y / norm;
        out->z = sinf(norm) * q->z / norm;
        out->w = cosf(norm);
    }
    else
    {
        out->x = 0.0f;
        out->y = 0.0f;
        out->z = 0.0f;
        out->w = 1.0f;
    }

    return out;
}

D3DXQUATERNION* WINAPI D3DXQuaternionInverse(D3DXQUATERNION *pout, const D3DXQUATERNION *pq)
{
    FLOAT norm;

    TRACE("pout %p, pq %p\n", pout, pq);

    norm = D3DXQuaternionLengthSq(pq);

    pout->x = -pq->x / norm;
    pout->y = -pq->y / norm;
    pout->z = -pq->z / norm;
    pout->w = pq->w / norm;
    return pout;
}

D3DXQUATERNION * WINAPI D3DXQuaternionLn(D3DXQUATERNION *out, const D3DXQUATERNION *q)
{
    FLOAT t;

    TRACE("out %p, q %p\n", out, q);

    if ((q->w >= 1.0f) || (q->w == -1.0f))
        t = 1.0f;
    else
        t = acosf(q->w) / sqrtf(1.0f - q->w * q->w);

    out->x = t * q->x;
    out->y = t * q->y;
    out->z = t * q->z;
    out->w = 0.0f;

    return out;
}

D3DXQUATERNION* WINAPI D3DXQuaternionMultiply(D3DXQUATERNION *pout, const D3DXQUATERNION *pq1, const D3DXQUATERNION *pq2)
{
    D3DXQUATERNION out;

    TRACE("pout %p, pq1 %p, pq2 %p\n", pout, pq1, pq2);

    out.x = pq2->w * pq1->x + pq2->x * pq1->w + pq2->y * pq1->z - pq2->z * pq1->y;
    out.y = pq2->w * pq1->y - pq2->x * pq1->z + pq2->y * pq1->w + pq2->z * pq1->x;
    out.z = pq2->w * pq1->z + pq2->x * pq1->y - pq2->y * pq1->x + pq2->z * pq1->w;
    out.w = pq2->w * pq1->w - pq2->x * pq1->x - pq2->y * pq1->y - pq2->z * pq1->z;
    *pout = out;
    return pout;
}

D3DXQUATERNION * WINAPI D3DXQuaternionNormalize(D3DXQUATERNION *out, const D3DXQUATERNION *q)
{
    FLOAT norm;

    TRACE("out %p, q %p\n", out, q);

    norm = D3DXQuaternionLength(q);

    out->x = q->x / norm;
    out->y = q->y / norm;
    out->z = q->z / norm;
    out->w = q->w / norm;

    return out;
}

D3DXQUATERNION * WINAPI D3DXQuaternionRotationAxis(D3DXQUATERNION *out, const D3DXVECTOR3 *v, FLOAT angle)
{
    D3DXVECTOR3 temp;

    TRACE("out %p, v %p, angle %f\n", out, v, angle);

    D3DXVec3Normalize(&temp, v);

    out->x = sinf(angle / 2.0f) * temp.x;
    out->y = sinf(angle / 2.0f) * temp.y;
    out->z = sinf(angle / 2.0f) * temp.z;
    out->w = cosf(angle / 2.0f);

    return out;
}

D3DXQUATERNION * WINAPI D3DXQuaternionRotationMatrix(D3DXQUATERNION *out, const D3DXMATRIX *m)
{
    FLOAT s, trace;

    TRACE("out %p, m %p\n", out, m);

    trace = m->u.m[0][0] + m->u.m[1][1] + m->u.m[2][2] + 1.0f;
    if (trace > 1.0f)
    {
        s = 2.0f * sqrtf(trace);
        out->x = (m->u.m[1][2] - m->u.m[2][1]) / s;
        out->y = (m->u.m[2][0] - m->u.m[0][2]) / s;
        out->z = (m->u.m[0][1] - m->u.m[1][0]) / s;
        out->w = 0.25f * s;
    }
    else
    {
        int i, maxi = 0;

        for (i = 1; i < 3; i++)
        {
            if (m->u.m[i][i] > m->u.m[maxi][maxi])
                maxi = i;
        }

        switch (maxi)
        {
            case 0:
                s = 2.0f * sqrtf(1.0f + m->u.m[0][0] - m->u.m[1][1] - m->u.m[2][2]);
                out->x = 0.25f * s;
                out->y = (m->u.m[0][1] + m->u.m[1][0]) / s;
                out->z = (m->u.m[0][2] + m->u.m[2][0]) / s;
                out->w = (m->u.m[1][2] - m->u.m[2][1]) / s;
                break;

            case 1:
                s = 2.0f * sqrtf(1.0f + m->u.m[1][1] - m->u.m[0][0] - m->u.m[2][2]);
                out->x = (m->u.m[0][1] + m->u.m[1][0]) / s;
                out->y = 0.25f * s;
                out->z = (m->u.m[1][2] + m->u.m[2][1]) / s;
                out->w = (m->u.m[2][0] - m->u.m[0][2]) / s;
                break;

            case 2:
                s = 2.0f * sqrtf(1.0f + m->u.m[2][2] - m->u.m[0][0] - m->u.m[1][1]);
                out->x = (m->u.m[0][2] + m->u.m[2][0]) / s;
                out->y = (m->u.m[1][2] + m->u.m[2][1]) / s;
                out->z = 0.25f * s;
                out->w = (m->u.m[0][1] - m->u.m[1][0]) / s;
                break;
        }
    }

    return out;
}

D3DXQUATERNION * WINAPI D3DXQuaternionRotationYawPitchRoll(D3DXQUATERNION *out, FLOAT yaw, FLOAT pitch, FLOAT roll)
{
    FLOAT syaw, cyaw, spitch, cpitch, sroll, croll;

    TRACE("out %p, yaw %f, pitch %f, roll %f\n", out, yaw, pitch, roll);

    syaw = sinf(yaw / 2.0f);
    cyaw = cosf(yaw / 2.0f);
    spitch = sinf(pitch / 2.0f);
    cpitch = cosf(pitch / 2.0f);
    sroll = sinf(roll / 2.0f);
    croll = cosf(roll / 2.0f);

    out->x = syaw * cpitch * sroll + cyaw * spitch * croll;
    out->y = syaw * cpitch * croll - cyaw * spitch * sroll;
    out->z = cyaw * cpitch * sroll - syaw * spitch * croll;
    out->w = cyaw * cpitch * croll + syaw * spitch * sroll;

    return out;
}

D3DXQUATERNION * WINAPI D3DXQuaternionSlerp(D3DXQUATERNION *out, const D3DXQUATERNION *q1,
        const D3DXQUATERNION *q2, FLOAT t)
{
    FLOAT dot, temp;

    TRACE("out %p, q1 %p, q2 %p, t %f\n", out, q1, q2, t);

    temp = 1.0f - t;
    dot = D3DXQuaternionDot(q1, q2);
    if (dot < 0.0f)
    {
        t = -t;
        dot = -dot;
    }

    if (1.0f - dot > 0.001f)
    {
        FLOAT theta = acosf(dot);

        temp = sinf(theta * temp) / sinf(theta);
        t = sinf(theta * t) / sinf(theta);
    }

    out->x = temp * q1->x + t * q2->x;
    out->y = temp * q1->y + t * q2->y;
    out->z = temp * q1->z + t * q2->z;
    out->w = temp * q1->w + t * q2->w;

    return out;
}

D3DXQUATERNION* WINAPI D3DXQuaternionSquad(D3DXQUATERNION *pout, const D3DXQUATERNION *pq1, const D3DXQUATERNION *pq2, const D3DXQUATERNION *pq3, const D3DXQUATERNION *pq4, FLOAT t)
{
    D3DXQUATERNION temp1, temp2;

    TRACE("pout %p, pq1 %p, pq2 %p, pq3 %p, pq4 %p, t %f\n", pout, pq1, pq2, pq3, pq4, t);

    D3DXQuaternionSlerp(pout, D3DXQuaternionSlerp(&temp1, pq1, pq4, t), D3DXQuaternionSlerp(&temp2, pq2, pq3, t), 2.0f * t * (1.0f - t));
    return pout;
}

static D3DXQUATERNION add_diff(const D3DXQUATERNION *q1, const D3DXQUATERNION *q2, const FLOAT add)
{
    D3DXQUATERNION temp;

    temp.x = q1->x + add * q2->x;
    temp.y = q1->y + add * q2->y;
    temp.z = q1->z + add * q2->z;
    temp.w = q1->w + add * q2->w;

    return temp;
}

void WINAPI D3DXQuaternionSquadSetup(D3DXQUATERNION *paout, D3DXQUATERNION *pbout, D3DXQUATERNION *pcout, const D3DXQUATERNION *pq0, const D3DXQUATERNION *pq1, const D3DXQUATERNION *pq2, const D3DXQUATERNION *pq3)
{
    D3DXQUATERNION q, temp1, temp2, temp3, zero;
    D3DXQUATERNION aout, cout;

    TRACE("paout %p, pbout %p, pcout %p, pq0 %p, pq1 %p, pq2 %p, pq3 %p\n", paout, pbout, pcout, pq0, pq1, pq2, pq3);

    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    zero.w = 0.0f;

    if (D3DXQuaternionDot(pq0, pq1) < 0.0f)
        temp2 = add_diff(&zero, pq0, -1.0f);
    else
        temp2 = *pq0;

    if (D3DXQuaternionDot(pq1, pq2) < 0.0f)
        cout = add_diff(&zero, pq2, -1.0f);
    else
        cout = *pq2;

    if (D3DXQuaternionDot(&cout, pq3) < 0.0f)
        temp3 = add_diff(&zero, pq3, -1.0f);
    else
        temp3 = *pq3;

    D3DXQuaternionInverse(&temp1, pq1);
    D3DXQuaternionMultiply(&temp2, &temp1, &temp2);
    D3DXQuaternionLn(&temp2, &temp2);
    D3DXQuaternionMultiply(&q, &temp1, &cout);
    D3DXQuaternionLn(&q, &q);
    temp1 = add_diff(&temp2, &q, 1.0f);
    temp1.x *= -0.25f;
    temp1.y *= -0.25f;
    temp1.z *= -0.25f;
    temp1.w *= -0.25f;
    D3DXQuaternionExp(&temp1, &temp1);
    D3DXQuaternionMultiply(&aout, pq1, &temp1);

    D3DXQuaternionInverse(&temp1, &cout);
    D3DXQuaternionMultiply(&temp2, &temp1, pq1);
    D3DXQuaternionLn(&temp2, &temp2);
    D3DXQuaternionMultiply(&q, &temp1, &temp3);
    D3DXQuaternionLn(&q, &q);
    temp1 = add_diff(&temp2, &q, 1.0f);
    temp1.x *= -0.25f;
    temp1.y *= -0.25f;
    temp1.z *= -0.25f;
    temp1.w *= -0.25f;
    D3DXQuaternionExp(&temp1, &temp1);
    D3DXQuaternionMultiply(pbout, &cout, &temp1);
    *paout = aout;
    *pcout = cout;
}

void WINAPI D3DXQuaternionToAxisAngle(const D3DXQUATERNION *pq, D3DXVECTOR3 *paxis, FLOAT *pangle)
{
    TRACE("pq %p, paxis %p, pangle %p\n", pq, paxis, pangle);

    if (paxis)
    {
        paxis->x = pq->x;
        paxis->y = pq->y;
        paxis->z = pq->z;
    }
    if (pangle)
        *pangle = 2.0f * acosf(pq->w);
}

/*_________________D3DXVec2_____________________*/

D3DXVECTOR2* WINAPI D3DXVec2BaryCentric(D3DXVECTOR2 *pout, const D3DXVECTOR2 *pv1, const D3DXVECTOR2 *pv2, const D3DXVECTOR2 *pv3, FLOAT f, FLOAT g)
{
    TRACE("pout %p, pv1 %p, pv2 %p, pv3 %p, f %f, g %f\n", pout, pv1, pv2, pv3, f, g);

    pout->x = (1.0f-f-g) * (pv1->x) + f * (pv2->x) + g * (pv3->x);
    pout->y = (1.0f-f-g) * (pv1->y) + f * (pv2->y) + g * (pv3->y);
    return pout;
}

D3DXVECTOR2* WINAPI D3DXVec2CatmullRom(D3DXVECTOR2 *pout, const D3DXVECTOR2 *pv0, const D3DXVECTOR2 *pv1, const D3DXVECTOR2 *pv2, const D3DXVECTOR2 *pv3, FLOAT s)
{
    TRACE("pout %p, pv0 %p, pv1 %p, pv2 %p, pv3 %p, s %f\n", pout, pv0, pv1, pv2, pv3, s);

    pout->x = 0.5f * (2.0f * pv1->x + (pv2->x - pv0->x) *s + (2.0f *pv0->x - 5.0f * pv1->x + 4.0f * pv2->x - pv3->x) * s * s + (pv3->x -3.0f * pv2->x + 3.0f * pv1->x - pv0->x) * s * s * s);
    pout->y = 0.5f * (2.0f * pv1->y + (pv2->y - pv0->y) *s + (2.0f *pv0->y - 5.0f * pv1->y + 4.0f * pv2->y - pv3->y) * s * s + (pv3->y -3.0f * pv2->y + 3.0f * pv1->y - pv0->y) * s * s * s);
    return pout;
}

D3DXVECTOR2* WINAPI D3DXVec2Hermite(D3DXVECTOR2 *pout, const D3DXVECTOR2 *pv1, const D3DXVECTOR2 *pt1, const D3DXVECTOR2 *pv2, const D3DXVECTOR2 *pt2, FLOAT s)
{
    FLOAT h1, h2, h3, h4;

    TRACE("pout %p, pv1 %p, pt1 %p, pv2 %p, pt2 %p, s %f\n", pout, pv1, pt1, pv2, pt2, s);

    h1 = 2.0f * s * s * s - 3.0f * s * s + 1.0f;
    h2 = s * s * s - 2.0f * s * s + s;
    h3 = -2.0f * s * s * s + 3.0f * s * s;
    h4 = s * s * s - s * s;

    pout->x = h1 * (pv1->x) + h2 * (pt1->x) + h3 * (pv2->x) + h4 * (pt2->x);
    pout->y = h1 * (pv1->y) + h2 * (pt1->y) + h3 * (pv2->y) + h4 * (pt2->y);
    return pout;
}

D3DXVECTOR2* WINAPI D3DXVec2Normalize(D3DXVECTOR2 *pout, const D3DXVECTOR2 *pv)
{
    FLOAT norm;

    TRACE("pout %p, pv %p\n", pout, pv);

    norm = D3DXVec2Length(pv);
    if ( !norm )
    {
        pout->x = 0.0f;
        pout->y = 0.0f;
    }
    else
    {
        pout->x = pv->x / norm;
        pout->y = pv->y / norm;
    }

    return pout;
}

D3DXVECTOR4* WINAPI D3DXVec2Transform(D3DXVECTOR4 *pout, const D3DXVECTOR2 *pv, const D3DXMATRIX *pm)
{
    D3DXVECTOR4 out;

    TRACE("pout %p, pv %p, pm %p\n", pout, pv, pm);

    out.x = pm->u.m[0][0] * pv->x + pm->u.m[1][0] * pv->y  + pm->u.m[3][0];
    out.y = pm->u.m[0][1] * pv->x + pm->u.m[1][1] * pv->y  + pm->u.m[3][1];
    out.z = pm->u.m[0][2] * pv->x + pm->u.m[1][2] * pv->y  + pm->u.m[3][2];
    out.w = pm->u.m[0][3] * pv->x + pm->u.m[1][3] * pv->y  + pm->u.m[3][3];
    *pout = out;
    return pout;
}

D3DXVECTOR4* WINAPI D3DXVec2TransformArray(D3DXVECTOR4* out, UINT outstride, const D3DXVECTOR2* in, UINT instride, const D3DXMATRIX* matrix, UINT elements)
{
    UINT i;

    TRACE("out %p, outstride %u, in %p, instride %u, matrix %p, elements %u\n", out, outstride, in, instride, matrix, elements);

    for (i = 0; i < elements; ++i) {
        D3DXVec2Transform(
            (D3DXVECTOR4*)((char*)out + outstride * i),
            (const D3DXVECTOR2*)((const char*)in + instride * i),
            matrix);
    }
    return out;
}

D3DXVECTOR2* WINAPI D3DXVec2TransformCoord(D3DXVECTOR2 *pout, const D3DXVECTOR2 *pv, const D3DXMATRIX *pm)
{
    D3DXVECTOR2 v;
    FLOAT norm;

    TRACE("pout %p, pv %p, pm %p\n", pout, pv, pm);

    v = *pv;
    norm = pm->u.m[0][3] * pv->x + pm->u.m[1][3] * pv->y + pm->u.m[3][3];

    pout->x = (pm->u.m[0][0] * v.x + pm->u.m[1][0] * v.y + pm->u.m[3][0]) / norm;
    pout->y = (pm->u.m[0][1] * v.x + pm->u.m[1][1] * v.y + pm->u.m[3][1]) / norm;

    return pout;
}

D3DXVECTOR2* WINAPI D3DXVec2TransformCoordArray(D3DXVECTOR2* out, UINT outstride, const D3DXVECTOR2* in, UINT instride, const D3DXMATRIX* matrix, UINT elements)
{
    UINT i;

    TRACE("out %p, outstride %u, in %p, instride %u, matrix %p, elements %u\n", out, outstride, in, instride, matrix, elements);

    for (i = 0; i < elements; ++i) {
        D3DXVec2TransformCoord(
            (D3DXVECTOR2*)((char*)out + outstride * i),
            (const D3DXVECTOR2*)((const char*)in + instride * i),
            matrix);
    }
    return out;
}

D3DXVECTOR2* WINAPI D3DXVec2TransformNormal(D3DXVECTOR2 *pout, const D3DXVECTOR2 *pv, const D3DXMATRIX *pm)
{
    const D3DXVECTOR2 v = *pv;

    TRACE("pout %p, pv %p, pm %p\n", pout, pv, pm);

    pout->x = pm->u.m[0][0] * v.x + pm->u.m[1][0] * v.y;
    pout->y = pm->u.m[0][1] * v.x + pm->u.m[1][1] * v.y;
    return pout;
}

D3DXVECTOR2* WINAPI D3DXVec2TransformNormalArray(D3DXVECTOR2* out, UINT outstride, const D3DXVECTOR2 *in, UINT instride, const D3DXMATRIX *matrix, UINT elements)
{
    UINT i;

    TRACE("out %p, outstride %u, in %p, instride %u, matrix %p, elements %u\n", out, outstride, in, instride, matrix, elements);

    for (i = 0; i < elements; ++i) {
        D3DXVec2TransformNormal(
            (D3DXVECTOR2*)((char*)out + outstride * i),
            (const D3DXVECTOR2*)((const char*)in + instride * i),
            matrix);
    }
    return out;
}

/*_________________D3DXVec3_____________________*/

D3DXVECTOR3* WINAPI D3DXVec3BaryCentric(D3DXVECTOR3 *pout, const D3DXVECTOR3 *pv1, const D3DXVECTOR3 *pv2, const D3DXVECTOR3 *pv3, FLOAT f, FLOAT g)
{
    TRACE("pout %p, pv1 %p, pv2 %p, pv3 %p, f %f, g %f\n", pout, pv1, pv2, pv3, f, g);

    pout->x = (1.0f-f-g) * (pv1->x) + f * (pv2->x) + g * (pv3->x);
    pout->y = (1.0f-f-g) * (pv1->y) + f * (pv2->y) + g * (pv3->y);
    pout->z = (1.0f-f-g) * (pv1->z) + f * (pv2->z) + g * (pv3->z);
    return pout;
}

D3DXVECTOR3* WINAPI D3DXVec3CatmullRom( D3DXVECTOR3 *pout, const D3DXVECTOR3 *pv0, const D3DXVECTOR3 *pv1, const D3DXVECTOR3 *pv2, const D3DXVECTOR3 *pv3, FLOAT s)
{
    TRACE("pout %p, pv0 %p, pv1 %p, pv2 %p, pv3 %p, s %f\n", pout, pv0, pv1, pv2, pv3, s);

    pout->x = 0.5f * (2.0f * pv1->x + (pv2->x - pv0->x) *s + (2.0f *pv0->x - 5.0f * pv1->x + 4.0f * pv2->x - pv3->x) * s * s + (pv3->x -3.0f * pv2->x + 3.0f * pv1->x - pv0->x) * s * s * s);
    pout->y = 0.5f * (2.0f * pv1->y + (pv2->y - pv0->y) *s + (2.0f *pv0->y - 5.0f * pv1->y + 4.0f * pv2->y - pv3->y) * s * s + (pv3->y -3.0f * pv2->y + 3.0f * pv1->y - pv0->y) * s * s * s);
    pout->z = 0.5f * (2.0f * pv1->z + (pv2->z - pv0->z) *s + (2.0f *pv0->z - 5.0f * pv1->z + 4.0f * pv2->z - pv3->z) * s * s + (pv3->z -3.0f * pv2->z + 3.0f * pv1->z - pv0->z) * s * s * s);
    return pout;
}

D3DXVECTOR3* WINAPI D3DXVec3Hermite(D3DXVECTOR3 *pout, const D3DXVECTOR3 *pv1, const D3DXVECTOR3 *pt1, const D3DXVECTOR3 *pv2, const D3DXVECTOR3 *pt2, FLOAT s)
{
    FLOAT h1, h2, h3, h4;

    TRACE("pout %p, pv1 %p, pt1 %p, pv2 %p, pt2 %p, s %f\n", pout, pv1, pt1, pv2, pt2, s);

    h1 = 2.0f * s * s * s - 3.0f * s * s + 1.0f;
    h2 = s * s * s - 2.0f * s * s + s;
    h3 = -2.0f * s * s * s + 3.0f * s * s;
    h4 = s * s * s - s * s;

    pout->x = h1 * (pv1->x) + h2 * (pt1->x) + h3 * (pv2->x) + h4 * (pt2->x);
    pout->y = h1 * (pv1->y) + h2 * (pt1->y) + h3 * (pv2->y) + h4 * (pt2->y);
    pout->z = h1 * (pv1->z) + h2 * (pt1->z) + h3 * (pv2->z) + h4 * (pt2->z);
    return pout;
}

D3DXVECTOR3* WINAPI D3DXVec3Normalize(D3DXVECTOR3 *pout, const D3DXVECTOR3 *pv)
{
    FLOAT norm;

    TRACE("pout %p, pv %p\n", pout, pv);

    norm = D3DXVec3Length(pv);
    if ( !norm )
    {
        pout->x = 0.0f;
        pout->y = 0.0f;
        pout->z = 0.0f;
    }
    else
    {
        pout->x = pv->x / norm;
        pout->y = pv->y / norm;
        pout->z = pv->z / norm;
    }

    return pout;
}

D3DXVECTOR3* WINAPI D3DXVec3Project(D3DXVECTOR3 *pout, const D3DXVECTOR3 *pv, const D3DVIEWPORT9 *pviewport, const D3DXMATRIX *pprojection, const D3DXMATRIX *pview, const D3DXMATRIX *pworld)
{
    D3DXMATRIX m;

    TRACE("pout %p, pv %p, pviewport %p, pprojection %p, pview %p, pworld %p\n", pout, pv, pviewport, pprojection, pview, pworld);

    D3DXMatrixIdentity(&m);
    if (pworld) D3DXMatrixMultiply(&m, &m, pworld);
    if (pview) D3DXMatrixMultiply(&m, &m, pview);
    if (pprojection) D3DXMatrixMultiply(&m, &m, pprojection);

    D3DXVec3TransformCoord(pout, pv, &m);

    if (pviewport)
    {
        pout->x = pviewport->X +  ( 1.0f + pout->x ) * pviewport->Width / 2.0f;
        pout->y = pviewport->Y +  ( 1.0f - pout->y ) * pviewport->Height / 2.0f;
        pout->z = pviewport->MinZ + pout->z * ( pviewport->MaxZ - pviewport->MinZ );
    }
    return pout;
}

D3DXVECTOR3* WINAPI D3DXVec3ProjectArray(D3DXVECTOR3* out, UINT outstride, const D3DXVECTOR3* in, UINT instride, const D3DVIEWPORT9* viewport, const D3DXMATRIX* projection, const D3DXMATRIX* view, const D3DXMATRIX* world, UINT elements)
{
    UINT i;

    TRACE("out %p, outstride %u, in %p, instride %u, viewport %p, projection %p, view %p, world %p, elements %u\n",
        out, outstride, in, instride, viewport, projection, view, world, elements);

    for (i = 0; i < elements; ++i) {
        D3DXVec3Project(
            (D3DXVECTOR3*)((char*)out + outstride * i),
            (const D3DXVECTOR3*)((const char*)in + instride * i),
            viewport, projection, view, world);
    }
    return out;
}

D3DXVECTOR4* WINAPI D3DXVec3Transform(D3DXVECTOR4 *pout, const D3DXVECTOR3 *pv, const D3DXMATRIX *pm)
{
    D3DXVECTOR4 out;

    TRACE("pout %p, pv %p, pm %p\n", pout, pv, pm);

    out.x = pm->u.m[0][0] * pv->x + pm->u.m[1][0] * pv->y + pm->u.m[2][0] * pv->z + pm->u.m[3][0];
    out.y = pm->u.m[0][1] * pv->x + pm->u.m[1][1] * pv->y + pm->u.m[2][1] * pv->z + pm->u.m[3][1];
    out.z = pm->u.m[0][2] * pv->x + pm->u.m[1][2] * pv->y + pm->u.m[2][2] * pv->z + pm->u.m[3][2];
    out.w = pm->u.m[0][3] * pv->x + pm->u.m[1][3] * pv->y + pm->u.m[2][3] * pv->z + pm->u.m[3][3];
    *pout = out;
    return pout;
}

D3DXVECTOR4* WINAPI D3DXVec3TransformArray(D3DXVECTOR4* out, UINT outstride, const D3DXVECTOR3* in, UINT instride, const D3DXMATRIX* matrix, UINT elements)
{
    UINT i;

    TRACE("out %p, outstride %u, in %p, instride %u, matrix %p, elements %u\n", out, outstride, in, instride, matrix, elements);

    for (i = 0; i < elements; ++i) {
        D3DXVec3Transform(
            (D3DXVECTOR4*)((char*)out + outstride * i),
            (const D3DXVECTOR3*)((const char*)in + instride * i),
            matrix);
    }
    return out;
}

D3DXVECTOR3* WINAPI D3DXVec3TransformCoord(D3DXVECTOR3 *pout, const D3DXVECTOR3 *pv, const D3DXMATRIX *pm)
{
    D3DXVECTOR3 out;
    FLOAT norm;

    TRACE("pout %p, pv %p, pm %p\n", pout, pv, pm);

    norm = pm->u.m[0][3] * pv->x + pm->u.m[1][3] * pv->y + pm->u.m[2][3] *pv->z + pm->u.m[3][3];

    out.x = (pm->u.m[0][0] * pv->x + pm->u.m[1][0] * pv->y + pm->u.m[2][0] * pv->z + pm->u.m[3][0]) / norm;
    out.y = (pm->u.m[0][1] * pv->x + pm->u.m[1][1] * pv->y + pm->u.m[2][1] * pv->z + pm->u.m[3][1]) / norm;
    out.z = (pm->u.m[0][2] * pv->x + pm->u.m[1][2] * pv->y + pm->u.m[2][2] * pv->z + pm->u.m[3][2]) / norm;

    *pout = out;

    return pout;
}

D3DXVECTOR3* WINAPI D3DXVec3TransformCoordArray(D3DXVECTOR3* out, UINT outstride, const D3DXVECTOR3* in, UINT instride, const D3DXMATRIX* matrix, UINT elements)
{
    UINT i;

    TRACE("out %p, outstride %u, in %p, instride %u, matrix %p, elements %u\n", out, outstride, in, instride, matrix, elements);

    for (i = 0; i < elements; ++i) {
        D3DXVec3TransformCoord(
            (D3DXVECTOR3*)((char*)out + outstride * i),
            (const D3DXVECTOR3*)((const char*)in + instride * i),
            matrix);
    }
    return out;
}

D3DXVECTOR3* WINAPI D3DXVec3TransformNormal(D3DXVECTOR3 *pout, const D3DXVECTOR3 *pv, const D3DXMATRIX *pm)
{
    const D3DXVECTOR3 v = *pv;

    TRACE("pout %p, pv %p, pm %p\n", pout, pv, pm);

    pout->x = pm->u.m[0][0] * v.x + pm->u.m[1][0] * v.y + pm->u.m[2][0] * v.z;
    pout->y = pm->u.m[0][1] * v.x + pm->u.m[1][1] * v.y + pm->u.m[2][1] * v.z;
    pout->z = pm->u.m[0][2] * v.x + pm->u.m[1][2] * v.y + pm->u.m[2][2] * v.z;
    return pout;

}

D3DXVECTOR3* WINAPI D3DXVec3TransformNormalArray(D3DXVECTOR3* out, UINT outstride, const D3DXVECTOR3* in, UINT instride, const D3DXMATRIX* matrix, UINT elements)
{
    UINT i;

    TRACE("out %p, outstride %u, in %p, instride %u, matrix %p, elements %u\n", out, outstride, in, instride, matrix, elements);

    for (i = 0; i < elements; ++i) {
        D3DXVec3TransformNormal(
            (D3DXVECTOR3*)((char*)out + outstride * i),
            (const D3DXVECTOR3*)((const char*)in + instride * i),
            matrix);
    }
    return out;
}

D3DXVECTOR3* WINAPI D3DXVec3Unproject(D3DXVECTOR3 *pout, const D3DXVECTOR3 *pv, const D3DVIEWPORT9 *pviewport, const D3DXMATRIX *pprojection, const D3DXMATRIX *pview, const D3DXMATRIX *pworld)
{
    D3DXMATRIX m;

    TRACE("pout %p, pv %p, pviewport %p, pprojection %p, pview %p, pworlds %p\n", pout, pv, pviewport, pprojection, pview, pworld);

    D3DXMatrixIdentity(&m);
    if (pworld) D3DXMatrixMultiply(&m, &m, pworld);
    if (pview) D3DXMatrixMultiply(&m, &m, pview);
    if (pprojection) D3DXMatrixMultiply(&m, &m, pprojection);
    D3DXMatrixInverse(&m, NULL, &m);

    *pout = *pv;
    if (pviewport)
    {
        pout->x = 2.0f * ( pout->x - pviewport->X ) / pviewport->Width - 1.0f;
        pout->y = 1.0f - 2.0f * ( pout->y - pviewport->Y ) / pviewport->Height;
        pout->z = ( pout->z - pviewport->MinZ) / ( pviewport->MaxZ - pviewport->MinZ );
    }
    D3DXVec3TransformCoord(pout, pout, &m);
    return pout;
}

D3DXVECTOR3* WINAPI D3DXVec3UnprojectArray(D3DXVECTOR3* out, UINT outstride, const D3DXVECTOR3* in, UINT instride, const D3DVIEWPORT9* viewport, const D3DXMATRIX* projection, const D3DXMATRIX* view, const D3DXMATRIX* world, UINT elements)
{
    UINT i;

    TRACE("out %p, outstride %u, in %p, instride %u, viewport %p, projection %p, view %p, world %p, elements %u\n",
        out, outstride, in, instride, viewport, projection, view, world, elements);

    for (i = 0; i < elements; ++i) {
        D3DXVec3Unproject(
            (D3DXVECTOR3*)((char*)out + outstride * i),
            (const D3DXVECTOR3*)((const char*)in + instride * i),
            viewport, projection, view, world);
    }
    return out;
}

/*_________________D3DXVec4_____________________*/

D3DXVECTOR4* WINAPI D3DXVec4BaryCentric(D3DXVECTOR4 *pout, const D3DXVECTOR4 *pv1, const D3DXVECTOR4 *pv2, const D3DXVECTOR4 *pv3, FLOAT f, FLOAT g)
{
    TRACE("pout %p, pv1 %p, pv2 %p, pv3 %p, f %f, g %f\n", pout, pv1, pv2, pv3, f, g);

    pout->x = (1.0f-f-g) * (pv1->x) + f * (pv2->x) + g * (pv3->x);
    pout->y = (1.0f-f-g) * (pv1->y) + f * (pv2->y) + g * (pv3->y);
    pout->z = (1.0f-f-g) * (pv1->z) + f * (pv2->z) + g * (pv3->z);
    pout->w = (1.0f-f-g) * (pv1->w) + f * (pv2->w) + g * (pv3->w);
    return pout;
}

D3DXVECTOR4* WINAPI D3DXVec4CatmullRom(D3DXVECTOR4 *pout, const D3DXVECTOR4 *pv0, const D3DXVECTOR4 *pv1, const D3DXVECTOR4 *pv2, const D3DXVECTOR4 *pv3, FLOAT s)
{
    TRACE("pout %p, pv0 %p, pv1 %p, pv2 %p, pv3 %p, s %f\n", pout, pv0, pv1, pv2, pv3, s);

    pout->x = 0.5f * (2.0f * pv1->x + (pv2->x - pv0->x) *s + (2.0f *pv0->x - 5.0f * pv1->x + 4.0f * pv2->x - pv3->x) * s * s + (pv3->x -3.0f * pv2->x + 3.0f * pv1->x - pv0->x) * s * s * s);
    pout->y = 0.5f * (2.0f * pv1->y + (pv2->y - pv0->y) *s + (2.0f *pv0->y - 5.0f * pv1->y + 4.0f * pv2->y - pv3->y) * s * s + (pv3->y -3.0f * pv2->y + 3.0f * pv1->y - pv0->y) * s * s * s);
    pout->z = 0.5f * (2.0f * pv1->z + (pv2->z - pv0->z) *s + (2.0f *pv0->z - 5.0f * pv1->z + 4.0f * pv2->z - pv3->z) * s * s + (pv3->z -3.0f * pv2->z + 3.0f * pv1->z - pv0->z) * s * s * s);
    pout->w = 0.5f * (2.0f * pv1->w + (pv2->w - pv0->w) *s + (2.0f *pv0->w - 5.0f * pv1->w + 4.0f * pv2->w - pv3->w) * s * s + (pv3->w -3.0f * pv2->w + 3.0f * pv1->w - pv0->w) * s * s * s);
    return pout;
}

D3DXVECTOR4* WINAPI D3DXVec4Cross(D3DXVECTOR4 *pout, const D3DXVECTOR4 *pv1, const D3DXVECTOR4 *pv2, const D3DXVECTOR4 *pv3)
{
    D3DXVECTOR4 out;

    TRACE("pout %p, pv1 %p, pv2 %p, pv3 %p\n", pout, pv1, pv2, pv3);

    out.x = pv1->y * (pv2->z * pv3->w - pv3->z * pv2->w) - pv1->z * (pv2->y * pv3->w - pv3->y * pv2->w) + pv1->w * (pv2->y * pv3->z - pv2->z *pv3->y);
    out.y = -(pv1->x * (pv2->z * pv3->w - pv3->z * pv2->w) - pv1->z * (pv2->x * pv3->w - pv3->x * pv2->w) + pv1->w * (pv2->x * pv3->z - pv3->x * pv2->z));
    out.z = pv1->x * (pv2->y * pv3->w - pv3->y * pv2->w) - pv1->y * (pv2->x *pv3->w - pv3->x * pv2->w) + pv1->w * (pv2->x * pv3->y - pv3->x * pv2->y);
    out.w = -(pv1->x * (pv2->y * pv3->z - pv3->y * pv2->z) - pv1->y * (pv2->x * pv3->z - pv3->x *pv2->z) + pv1->z * (pv2->x * pv3->y - pv3->x * pv2->y));
    *pout = out;
    return pout;
}

D3DXVECTOR4* WINAPI D3DXVec4Hermite(D3DXVECTOR4 *pout, const D3DXVECTOR4 *pv1, const D3DXVECTOR4 *pt1, const D3DXVECTOR4 *pv2, const D3DXVECTOR4 *pt2, FLOAT s)
{
    FLOAT h1, h2, h3, h4;

    TRACE("pout %p, pv1 %p, pt1 %p, pv2 %p, pt2 %p, s %f\n", pout, pv1, pt1, pv2, pt2, s);

    h1 = 2.0f * s * s * s - 3.0f * s * s + 1.0f;
    h2 = s * s * s - 2.0f * s * s + s;
    h3 = -2.0f * s * s * s + 3.0f * s * s;
    h4 = s * s * s - s * s;

    pout->x = h1 * (pv1->x) + h2 * (pt1->x) + h3 * (pv2->x) + h4 * (pt2->x);
    pout->y = h1 * (pv1->y) + h2 * (pt1->y) + h3 * (pv2->y) + h4 * (pt2->y);
    pout->z = h1 * (pv1->z) + h2 * (pt1->z) + h3 * (pv2->z) + h4 * (pt2->z);
    pout->w = h1 * (pv1->w) + h2 * (pt1->w) + h3 * (pv2->w) + h4 * (pt2->w);
    return pout;
}

D3DXVECTOR4* WINAPI D3DXVec4Normalize(D3DXVECTOR4 *pout, const D3DXVECTOR4 *pv)
{
    FLOAT norm;

    TRACE("pout %p, pv %p\n", pout, pv);

    norm = D3DXVec4Length(pv);

    pout->x = pv->x / norm;
    pout->y = pv->y / norm;
    pout->z = pv->z / norm;
    pout->w = pv->w / norm;

    return pout;
}

D3DXVECTOR4* WINAPI D3DXVec4Transform(D3DXVECTOR4 *pout, const D3DXVECTOR4 *pv, const D3DXMATRIX *pm)
{
    D3DXVECTOR4 out;

    TRACE("pout %p, pv %p, pm %p\n", pout, pv, pm);

    out.x = pm->u.m[0][0] * pv->x + pm->u.m[1][0] * pv->y + pm->u.m[2][0] * pv->z + pm->u.m[3][0] * pv->w;
    out.y = pm->u.m[0][1] * pv->x + pm->u.m[1][1] * pv->y + pm->u.m[2][1] * pv->z + pm->u.m[3][1] * pv->w;
    out.z = pm->u.m[0][2] * pv->x + pm->u.m[1][2] * pv->y + pm->u.m[2][2] * pv->z + pm->u.m[3][2] * pv->w;
    out.w = pm->u.m[0][3] * pv->x + pm->u.m[1][3] * pv->y + pm->u.m[2][3] * pv->z + pm->u.m[3][3] * pv->w;
    *pout = out;
    return pout;
}

D3DXVECTOR4* WINAPI D3DXVec4TransformArray(D3DXVECTOR4* out, UINT outstride, const D3DXVECTOR4* in, UINT instride, const D3DXMATRIX* matrix, UINT elements)
{
    UINT i;

    TRACE("out %p, outstride %u, in %p, instride %u, matrix %p, elements %u\n", out, outstride, in, instride, matrix, elements);

    for (i = 0; i < elements; ++i) {
        D3DXVec4Transform(
            (D3DXVECTOR4*)((char*)out + outstride * i),
            (const D3DXVECTOR4*)((const char*)in + instride * i),
            matrix);
    }
    return out;
}

unsigned short float_32_to_16(const float in)
{
    int exp = 0, origexp;
    float tmp = fabsf(in);
    int sign = (copysignf(1, in) < 0);
    unsigned int mantissa;
    unsigned short ret;

    /* Deal with special numbers */
    if (isinf(in)) return (sign ? 0xffff : 0x7fff);
    if (isnan(in)) return (sign ? 0xffff : 0x7fff);
    if (in == 0.0f) return (sign ? 0x8000 : 0x0000);

    if (tmp < (float)(1u << 10))
    {
        do
        {
            tmp *= 2.0f;
            exp--;
        } while (tmp < (float)(1u << 10));
    }
    else if (tmp >= (float)(1u << 11))
    {
        do
        {
            tmp /= 2.0f;
            exp++;
        } while (tmp >= (float)(1u << 11));
    }

    exp += 10;  /* Normalize the mantissa */
    exp += 15;  /* Exponent is encoded with excess 15 */

    origexp = exp;

    mantissa = (unsigned int) tmp;
    if ((tmp - mantissa == 0.5f && mantissa % 2 == 1) || /* round half to even */
        (tmp - mantissa > 0.5f))
    {
        mantissa++; /* round to nearest, away from zero */
    }
    if (mantissa == 2048)
    {
        mantissa = 1024;
        exp++;
    }

    if (exp > 31)
    {
        /* too big */
        ret = 0x7fff; /* INF */
    }
    else if (exp <= 0)
    {
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
    }
    else
    {
        ret = (exp << 10) | (mantissa & 0x3ff);
    }

    ret |= ((sign ? 1 : 0) << 15); /* Add the sign */
    return ret;
}

D3DXFLOAT16 *WINAPI D3DXFloat32To16Array(D3DXFLOAT16 *pout, const FLOAT *pin, UINT n)
{
    unsigned int i;

    TRACE("pout %p, pin %p, n %u\n", pout, pin, n);

    for (i = 0; i < n; ++i)
    {
        pout[i].value = float_32_to_16(pin[i]);
    }

    return pout;
}

/* Native d3dx9's D3DXFloat16to32Array lacks support for NaN and Inf. Specifically, e = 16 is treated as a
 * regular number - e.g., 0x7fff is converted to 131008.0 and 0xffff to -131008.0. */
float float_16_to_32(const unsigned short in)
{
    const unsigned short s = (in & 0x8000);
    const unsigned short e = (in & 0x7C00) >> 10;
    const unsigned short m = in & 0x3FF;
    const float sgn = (s ? -1.0f : 1.0f);

    if (e == 0)
    {
        if (m == 0) return sgn * 0.0f; /* +0.0 or -0.0 */
        else return sgn * powf(2, -14.0f) * (m / 1024.0f);
    }
    else
    {
        return sgn * powf(2, e - 15.0f) * (1.0f + (m / 1024.0f));
    }
}

FLOAT *WINAPI D3DXFloat16To32Array(FLOAT *pout, const D3DXFLOAT16 *pin, UINT n)
{
    unsigned int i;

    TRACE("pout %p, pin %p, n %u\n", pout, pin, n);

    for (i = 0; i < n; ++i)
    {
        pout[i] = float_16_to_32(pin[i].value);
    }

    return pout;
}

/*_________________D3DXSH________________*/

FLOAT* WINAPI D3DXSHAdd(FLOAT *out, UINT order, const FLOAT *a, const FLOAT *b)
{
    UINT i;

    TRACE("out %p, order %u, a %p, b %p\n", out, order, a, b);

    for (i = 0; i < order * order; i++)
        out[i] = a[i] + b[i];

    return out;
}

FLOAT WINAPI D3DXSHDot(UINT order, const FLOAT *a, const FLOAT *b)
{
    FLOAT s;
    UINT i;

    TRACE("order %u, a %p, b %p\n", order, a, b);

    s = a[0] * b[0];
    for (i = 1; i < order * order; i++)
        s += a[i] * b[i];

    return s;
}

static void weightedcapintegrale(FLOAT *out, UINT order, FLOAT angle)
{
    FLOAT coeff[3];

    coeff[0] = cosf(angle);

    out[0] = 2.0f * D3DX_PI * (1.0f - coeff[0]);
    out[1] = D3DX_PI * sinf(angle) * sinf(angle);
    if (order <= 2)
        return;

    out[2] = coeff[0] * out[1];
    if (order == 3)
        return;

    coeff[1] = coeff[0] * coeff[0];
    coeff[2] = coeff[1] * coeff[1];

    out[3] = D3DX_PI * (-1.25f * coeff[2] + 1.5f * coeff[1] - 0.25f);
    if (order == 4)
        return;

    out[4] = -0.25f * D3DX_PI * coeff[0] * (7.0f * coeff[2] - 10.0f * coeff[1] + 3.0f);
    if (order == 5)
        return;

    out[5] = D3DX_PI * (-2.625f * coeff[2] * coeff[1] + 4.375f * coeff[2] - 1.875f * coeff[1] + 0.125f);
}

HRESULT WINAPI D3DXSHEvalConeLight(UINT order, const D3DXVECTOR3 *dir, FLOAT radius,
    FLOAT Rintensity, FLOAT Gintensity, FLOAT Bintensity, FLOAT *rout, FLOAT *gout, FLOAT *bout)
{
    FLOAT cap[6], clamped_angle, norm, scale, temp;
    UINT i, index, j;

    TRACE("order %u, dir %p, radius %f, red %f, green %f, blue %f, rout %p, gout %p, bout %p\n",
        order, dir, radius, Rintensity, Gintensity, Bintensity, rout, gout, bout);

    if (radius <= 0.0f)
        return D3DXSHEvalDirectionalLight(order, dir, Rintensity, Gintensity, Bintensity, rout, gout, bout);

    clamped_angle = (radius > D3DX_PI / 2.0f) ? (D3DX_PI / 2.0f) : radius;
    norm = sinf(clamped_angle) * sinf(clamped_angle);

    if (order > D3DXSH_MAXORDER)
    {
        WARN("Order clamped at D3DXSH_MAXORDER\n");
        order = D3DXSH_MAXORDER;
    }

    weightedcapintegrale(cap, order, radius);
    D3DXSHEvalDirection(rout, order, dir);

    for (i = 0; i < order; i++)
    {
        scale = cap[i] / norm;

        for (j = 0; j < 2 * i + 1; j++)
        {
            index = i * i + j;
            temp = rout[index] * scale;

            rout[index] = temp * Rintensity;
            if (gout)
                gout[index] = temp * Gintensity;
            if (bout)
                bout[index] = temp * Bintensity;
        }
    }

    return D3D_OK;
}

FLOAT* WINAPI D3DXSHEvalDirection(FLOAT *out, UINT order, const D3DXVECTOR3 *dir)
{
    const FLOAT dirxx = dir->x * dir->x;
    const FLOAT dirxy = dir->x * dir->y;
    const FLOAT dirxz = dir->x * dir->z;
    const FLOAT diryy = dir->y * dir->y;
    const FLOAT diryz = dir->y * dir->z;
    const FLOAT dirzz = dir->z * dir->z;
    const FLOAT dirxxxx = dirxx * dirxx;
    const FLOAT diryyyy = diryy * diryy;
    const FLOAT dirzzzz = dirzz * dirzz;
    const FLOAT dirxyxy = dirxy * dirxy;

    TRACE("out %p, order %u, dir %p\n", out, order, dir);

    if ((order < D3DXSH_MINORDER) || (order > D3DXSH_MAXORDER))
        return out;

    out[0] = 0.5f / sqrtf(D3DX_PI);
    out[1] = -0.5f / sqrtf(D3DX_PI / 3.0f) * dir->y;
    out[2] = 0.5f / sqrtf(D3DX_PI / 3.0f) * dir->z;
    out[3] = -0.5f / sqrtf(D3DX_PI / 3.0f) * dir->x;
    if (order == 2)
        return out;

    out[4] = 0.5f / sqrtf(D3DX_PI / 15.0f) * dirxy;
    out[5] = -0.5f / sqrtf(D3DX_PI / 15.0f) * diryz;
    out[6] = 0.25f / sqrtf(D3DX_PI / 5.0f) * (3.0f * dirzz - 1.0f);
    out[7] = -0.5f / sqrtf(D3DX_PI / 15.0f) * dirxz;
    out[8] = 0.25f / sqrtf(D3DX_PI / 15.0f) * (dirxx - diryy);
    if (order == 3)
        return out;

    out[9] = -sqrtf(70.0f / D3DX_PI) / 8.0f * dir->y * (3.0f * dirxx - diryy);
    out[10] = sqrtf(105.0f / D3DX_PI) / 2.0f * dirxy * dir->z;
    out[11] = -sqrtf(42.0f / D3DX_PI) / 8.0f * dir->y * (-1.0f + 5.0f * dirzz);
    out[12] = sqrtf(7.0f / D3DX_PI) / 4.0f * dir->z * (5.0f * dirzz - 3.0f);
    out[13] = sqrtf(42.0f / D3DX_PI) / 8.0f * dir->x * (1.0f - 5.0f * dirzz);
    out[14] = sqrtf(105.0f / D3DX_PI) / 4.0f * dir->z * (dirxx - diryy);
    out[15] = -sqrtf(70.0f / D3DX_PI) / 8.0f * dir->x * (dirxx - 3.0f * diryy);
    if (order == 4)
        return out;

    out[16] = 0.75f * sqrtf(35.0f / D3DX_PI) * dirxy * (dirxx - diryy);
    out[17] = 3.0f * dir->z * out[9];
    out[18] = 0.75f * sqrtf(5.0f / D3DX_PI) * dirxy * (7.0f * dirzz - 1.0f);
    out[19] = 0.375f * sqrtf(10.0f / D3DX_PI) * diryz * (3.0f - 7.0f * dirzz);
    out[20] = 3.0f / (16.0f * sqrtf(D3DX_PI)) * (35.0f * dirzzzz - 30.f * dirzz + 3.0f);
    out[21] = 0.375f * sqrtf(10.0f / D3DX_PI) * dirxz * (3.0f - 7.0f * dirzz);
    out[22] = 0.375f * sqrtf(5.0f / D3DX_PI) * (dirxx - diryy) * (7.0f * dirzz - 1.0f);
    out[23] = 3.0f * dir->z * out[15];
    out[24] = 3.0f / 16.0f * sqrtf(35.0f / D3DX_PI) * (dirxxxx - 6.0f * dirxyxy + diryyyy);
    if (order == 5)
        return out;

    out[25] = -3.0f/ 32.0f * sqrtf(154.0f / D3DX_PI) * dir->y * (5.0f * dirxxxx - 10.0f * dirxyxy + diryyyy);
    out[26] = 0.75f * sqrtf(385.0f / D3DX_PI) * dirxy * dir->z * (dirxx - diryy);
    out[27] = sqrtf(770.0f / D3DX_PI) / 32.0f * dir->y * (3.0f * dirxx - diryy) * (1.0f - 9.0f * dirzz);
    out[28] = sqrtf(1155.0f / D3DX_PI) / 4.0f * dirxy * dir->z * (3.0f * dirzz - 1.0f);
    out[29] = sqrtf(165.0f / D3DX_PI) / 16.0f * dir->y * (14.0f * dirzz - 21.0f * dirzzzz - 1.0f);
    out[30] = sqrtf(11.0f / D3DX_PI) / 16.0f * dir->z * (63.0f * dirzzzz - 70.0f * dirzz + 15.0f);
    out[31] = sqrtf(165.0f / D3DX_PI) / 16.0f * dir->x * (14.0f * dirzz - 21.0f * dirzzzz - 1.0f);
    out[32] = sqrtf(1155.0f / D3DX_PI) / 8.0f * dir->z * (dirxx - diryy) * (3.0f * dirzz - 1.0f);
    out[33] = sqrtf(770.0f / D3DX_PI) / 32.0f * dir->x * (dirxx - 3.0f * diryy) * (1.0f - 9.0f * dirzz);
    out[34] = 3.0f / 16.0f * sqrtf(385.0f / D3DX_PI) * dir->z * (dirxxxx - 6.0f * dirxyxy + diryyyy);
    out[35] = -3.0f/ 32.0f * sqrtf(154.0f / D3DX_PI) * dir->x * (dirxxxx - 10.0f * dirxyxy + 5.0f * diryyyy);

    return out;
}

HRESULT WINAPI D3DXSHEvalDirectionalLight(UINT order, const D3DXVECTOR3 *dir, FLOAT Rintensity, FLOAT Gintensity, FLOAT Bintensity, FLOAT *Rout, FLOAT *Gout, FLOAT *Bout)
{
    FLOAT s, temp;
    UINT j;

    TRACE("Order %u, Vector %p, Red %f, Green %f, Blue %f, Rout %p, Gout %p, Bout %p\n", order, dir, Rintensity, Gintensity, Bintensity, Rout, Gout, Bout);

    s = 0.75f;
    if ( order > 2 )
        s += 5.0f / 16.0f;
    if ( order > 4 )
        s -= 3.0f / 32.0f;
    s /= D3DX_PI;

    D3DXSHEvalDirection(Rout, order, dir);
    for (j = 0; j < order * order; j++)
    {
        temp = Rout[j] / s;

        Rout[j] = Rintensity * temp;
        if ( Gout )
            Gout[j] = Gintensity * temp;
        if ( Bout )
            Bout[j] = Bintensity * temp;
    }

    return D3D_OK;
}

HRESULT WINAPI D3DXSHEvalHemisphereLight(UINT order, const D3DXVECTOR3 *dir, D3DXCOLOR top, D3DXCOLOR bottom,
    FLOAT *rout, FLOAT *gout, FLOAT *bout)
{
    FLOAT a[2], temp[4];
    UINT i, j;

    TRACE("order %u, dir %p, rout %p, gout %p, bout %p\n", order, dir, rout, gout, bout);

    D3DXSHEvalDirection(temp, 2, dir);

    a[0] = (top.r + bottom.r) * 3.0f * D3DX_PI;
    a[1] = (top.r - bottom.r) * D3DX_PI;
    for (i = 0; i < order; i++)
        for (j = 0; j < 2 * i + 1; j++)
            if (i < 2)
                rout[i * i + j] = temp[i * i + j] * a[i];
            else
                rout[i * i + j] = 0.0f;

    if (gout)
    {
        a[0] = (top.g + bottom.g) * 3.0f * D3DX_PI;
        a[1] = (top.g - bottom.g) * D3DX_PI;
        for (i = 0; i < order; i++)
            for (j = 0; j < 2 * i + 1; j++)
                if (i < 2)
                    gout[i * i + j] = temp[i * i + j] * a[i];
                else
                    gout[i * i + j] = 0.0f;
    }

    if (bout)
    {
        a[0] = (top.b + bottom.b) * 3.0f * D3DX_PI;
        a[1] = (top.b - bottom.b) * D3DX_PI;
        for (i = 0; i < order; i++)
            for (j = 0; j < 2 * i + 1; j++)
                if (i < 2)
                    bout[i * i + j] = temp[i * i + j] * a[i];
                else
                    bout[i * i + j] = 0.0f;
    }

    return D3D_OK;
}

HRESULT WINAPI D3DXSHEvalSphericalLight(UINT order, const D3DXVECTOR3 *dir, FLOAT radius,
    FLOAT Rintensity, FLOAT Gintensity, FLOAT Bintensity, FLOAT *rout, FLOAT *gout, FLOAT *bout)
{
    D3DXVECTOR3 normal;
    FLOAT cap[6], clamped_angle, dist, temp;
    UINT i, index, j;

    TRACE("order %u, dir %p, radius %f, red %f, green %f, blue %f, rout %p, gout %p, bout %p\n",
        order, dir, radius, Rintensity, Gintensity, Bintensity, rout, gout, bout);

    if (order > D3DXSH_MAXORDER)
    {
        WARN("Order clamped at D3DXSH_MAXORDER\n");
        order = D3DXSH_MAXORDER;
    }

    if (radius < 0.0f)
        radius = -radius;

    dist = D3DXVec3Length(dir);
    clamped_angle = (dist <= radius) ? D3DX_PI / 2.0f : asinf(radius / dist);

    weightedcapintegrale(cap, order, clamped_angle);
    D3DXVec3Normalize(&normal, dir);
    D3DXSHEvalDirection(rout, order, &normal);

    for (i = 0; i < order; i++)
        for (j = 0; j < 2 * i + 1; j++)
        {
            index = i * i + j;
            temp = rout[index] * cap[i];

            rout[index] = temp * Rintensity;
            if (gout)
                gout[index] = temp * Gintensity;
            if (bout)
                bout[index] = temp * Bintensity;
        }

    return D3D_OK;
}

FLOAT * WINAPI D3DXSHMultiply2(FLOAT *out, const FLOAT *a, const FLOAT *b)
{
    FLOAT ta, tb;

    TRACE("out %p, a %p, b %p\n", out, a, b);

    ta = 0.28209479f * a[0];
    tb = 0.28209479f * b[0];

    out[0] = 0.28209479f * D3DXSHDot(2, a, b);
    out[1] = ta * b[1] + tb * a[1];
    out[2] = ta * b[2] + tb * a[2];
    out[3] = ta * b[3] + tb * a[3];

    return out;
}

FLOAT * WINAPI D3DXSHMultiply3(FLOAT *out, const FLOAT *a, const FLOAT *b)
{
    FLOAT t, ta, tb;

    TRACE("out %p, a %p, b %p\n", out, a, b);

    out[0] = 0.28209479f * a[0] * b[0];

    ta = 0.28209479f * a[0] - 0.12615662f * a[6] - 0.21850968f * a[8];
    tb = 0.28209479f * b[0] - 0.12615662f * b[6] - 0.21850968f * b[8];
    out[1] = ta * b[1] + tb * a[1];
    t = a[1] * b[1];
    out[0] += 0.28209479f * t;
    out[6] = -0.12615662f * t;
    out[8] = -0.21850968f * t;

    ta = 0.21850968f * a[5];
    tb = 0.21850968f * b[5];
    out[1] += ta * b[2] + tb * a[2];
    out[2] = ta * b[1] + tb * a[1];
    t = a[1] * b[2] +a[2] * b[1];
    out[5] = 0.21850968f * t;

    ta = 0.21850968f * a[4];
    tb = 0.21850968f * b[4];
    out[1] += ta * b[3] + tb * a[3];
    out[3]  = ta * b[1] + tb * a[1];
    t = a[1] * b[3] + a[3] * b[1];
    out[4] = 0.21850968f * t;

    ta = 0.28209480f * a[0] + 0.25231326f * a[6];
    tb = 0.28209480f * b[0] + 0.25231326f * b[6];
    out[2] += ta * b[2] + tb * a[2];
    t = a[2] * b[2];
    out[0] += 0.28209480f * t;
    out[6] += 0.25231326f * t;

    ta = 0.21850969f * a[7];
    tb = 0.21850969f * b[7];
    out[2] += ta * b[3] + tb * a[3];
    out[3] += ta * b[2] + tb * a[2];
    t = a[2] * b[3] + a[3] * b[2];
    out[7] = 0.21850969f * t;

    ta = 0.28209479f * a[0] - 0.12615663f * a[6] + 0.21850969f * a[8];
    tb = 0.28209479f * b[0] - 0.12615663f * b[6] + 0.21850969f * b[8];
    out[3] += ta * b[3] + tb * a[3];
    t = a[3] * b[3];
    out[0] += 0.28209479f * t;
    out[6] -= 0.12615663f * t;
    out[8] += 0.21850969f * t;

    ta = 0.28209479f * a[0] - 0.18022375f * a[6];
    tb = 0.28209479f * b[0] - 0.18022375f * b[6];
    out[4] += ta * b[4] + tb * a[4];
    t = a[4] * b[4];
    out[0] += 0.28209479f * t;
    out[6] -= 0.18022375f * t;

    ta = 0.15607835f * a[7];
    tb = 0.15607835f * b[7];
    out[4] += ta * b[5] + tb * a[5];
    out[5] += ta * b[4] + tb * a[4];
    t = a[4] * b[5] + a[5] * b[4];
    out[7] += 0.15607834f * t;

    ta = 0.28209479f * a[0] + 0.09011186f * a[6] - 0.15607835f * a[8];
    tb = 0.28209479f * b[0] + 0.09011186f * b[6] - 0.15607835f * b[8];
    out[5] += ta * b[5] + tb * a[5];
    t = a[5] * b[5];
    out[0] += 0.28209479f * t;
    out[6] += 0.09011186f * t;
    out[8] -= 0.15607835f * t;

    ta = 0.28209480f * a[0];
    tb = 0.28209480f * b[0];
    out[6] += ta * b[6] + tb * a[6];
    t = a[6] * b[6];
    out[0] += 0.28209480f * t;
    out[6] += 0.18022376f * t;

    ta = 0.28209479f * a[0] + 0.09011186f * a[6] + 0.15607835f * a[8];
    tb = 0.28209479f * b[0] + 0.09011186f * b[6] + 0.15607835f * b[8];
    out[7] += ta * b[7] + tb * a[7];
    t = a[7] * b[7];
    out[0] += 0.28209479f * t;
    out[6] += 0.09011186f * t;
    out[8] += 0.15607835f * t;

    ta = 0.28209479f * a[0] - 0.18022375f * a[6];
    tb = 0.28209479f * b[0] - 0.18022375f * b[6];
    out[8] += ta * b[8] + tb * a[8];
    t = a[8] * b[8];
    out[0] += 0.28209479f * t;
    out[6] -= 0.18022375f * t;

    return out;
}

FLOAT * WINAPI D3DXSHMultiply4(FLOAT *out, const FLOAT *a, const FLOAT *b)
{
    FLOAT ta, tb, t;

    TRACE("out %p, a %p, b %p\n", out, a, b);

    out[0] = 0.28209479f * a[0] * b[0];

    ta = 0.28209479f * a[0] - 0.12615663f * a[6] - 0.21850969f * a[8];
    tb = 0.28209479f * b[0] - 0.12615663f * b[6] - 0.21850969f * b[8];
    out[1] = ta * b[1] + tb * a[1];
    t = a[1] * b[1];
    out[0] += 0.28209479f * t;
    out[6] = -0.12615663f * t;
    out[8] = -0.21850969f * t;

    ta = 0.21850969f * a[3] - 0.05839917f * a[13] - 0.22617901f * a[15];
    tb = 0.21850969f * b[3] - 0.05839917f * b[13] - 0.22617901f * b[15];
    out[1] += ta * b[4] + tb * a[4];
    out[4] = ta * b[1] + tb * a[1];
    t = a[1] * b[4] + a[4] * b[1];
    out[3] = 0.21850969f * t;
    out[13] = -0.05839917f * t;
    out[15] = -0.22617901f * t;

    ta = 0.21850969f * a[2] - 0.14304817f * a[12] - 0.18467439f * a[14];
    tb = 0.21850969f * b[2] - 0.14304817f * b[12] - 0.18467439f * b[14];
    out[1] += ta * b[5] + tb * a[5];
    out[5] = ta * b[1] + tb * a[1];
    t = a[1] * b[5] + a[5] * b[1];
    out[2] = 0.21850969f * t;
    out[12] = -0.14304817f * t;
    out[14] = -0.18467439f * t;

    ta = 0.20230066f * a[11];
    tb = 0.20230066f * b[11];
    out[1] += ta * b[6] + tb * a[6];
    out[6] += ta * b[1] + tb * a[1];
    t = a[1] * b[6] + a[6] * b[1];
    out[11] = 0.20230066f * t;

    ta = 0.22617901f * a[9] + 0.05839917f * a[11];
    tb = 0.22617901f * b[9] + 0.05839917f * b[11];
    out[1] += ta * b[8] + tb * a[8];
    out[8] += ta * b[1] + tb * a[1];
    t = a[1] * b[8] + a[8] * b[1];
    out[9] = 0.22617901f * t;
    out[11] += 0.05839917f * t;

    ta = 0.28209480f * a[0] + 0.25231326f * a[6];
    tb = 0.28209480f * b[0] + 0.25231326f * b[6];
    out[2] += ta * b[2] + tb * a[2];
    t = a[2] * b[2];
    out[0] += 0.28209480f * t;
    out[6] += 0.25231326f * t;

    ta = 0.24776671f * a[12];
    tb = 0.24776671f * b[12];
    out[2] += ta * b[6] + tb * a[6];
    out[6] += ta * b[2] + tb * a[2];
    t = a[2] * b[6] + a[6] * b[2];
    out[12] += 0.24776671f * t;

    ta = 0.28209480f * a[0] - 0.12615663f * a[6] + 0.21850969f * a[8];
    tb = 0.28209480f * b[0] - 0.12615663f * b[6] + 0.21850969f * b[8];
    out[3] += ta * b[3] + tb * a[3];
    t = a[3] * b[3];
    out[0] += 0.28209480f * t;
    out[6] -= 0.12615663f * t;
    out[8] += 0.21850969f * t;

    ta = 0.20230066f * a[13];
    tb = 0.20230066f * b[13];
    out[3] += ta * b[6] + tb * a[6];
    out[6] += ta * b[3] + tb * a[3];
    t = a[3] * b[6] + a[6] * b[3];
    out[13] += 0.20230066f * t;

    ta = 0.21850969f * a[2] - 0.14304817f * a[12] + 0.18467439f * a[14];
    tb = 0.21850969f * b[2] - 0.14304817f * b[12] + 0.18467439f * b[14];
    out[3] += ta * b[7] + tb * a[7];
    out[7] = ta * b[3] + tb * a[3];
    t = a[3] * b[7] + a[7] * b[3];
    out[2] += 0.21850969f * t;
    out[12] -= 0.14304817f * t;
    out[14] += 0.18467439f * t;

    ta = -0.05839917f * a[13] + 0.22617901f * a[15];
    tb = -0.05839917f * b[13] + 0.22617901f * b[15];
    out[3] += ta * b[8] + tb * a[8];
    out[8] += ta * b[3] + tb * a[3];
    t = a[3] * b[8] + a[8] * b[3];
    out[13] -= 0.05839917f * t;
    out[15] += 0.22617901f * t;

    ta = 0.28209479f * a[0] - 0.18022375f * a[6];
    tb = 0.28209479f * b[0] - 0.18022375f * b[6];
    out[4] += ta * b[4] + tb * a[4];
    t = a[4] * b[4];
    out[0] += 0.28209479f * t;
    out[6] -= 0.18022375f * t;

    ta = 0.15607835f * a[7];
    tb = 0.15607835f * b[7];
    out[4] += ta * b[5] + tb * a[5];
    out[5] += ta * b[4] + tb * a[4];
    t = a[4] * b[5] + a[5] * b[4];
    out[7] += 0.15607835f * t;

    ta = 0.22617901f * a[3] - 0.09403160f * a[13];
    tb = 0.22617901f * b[3] - 0.09403160f * b[13];
    out[4] += ta * b[9] + tb * a[9];
    out[9] += ta * b[4] + tb * a[4];
    t = a[4] * b[9] + a[9] * b[4];
    out[3] += 0.22617901f * t;
    out[13] -= 0.09403160f * t;

    ta = 0.18467439f * a[2] - 0.18806319f * a[12];
    tb = 0.18467439f * b[2] - 0.18806319f * b[12];
    out[4] += ta * b[10] + tb * a [10];
    out[10] = ta * b[4] + tb * a[4];
    t = a[4] * b[10] + a[10] * b[4];
    out[2] += 0.18467439f * t;
    out[12] -= 0.18806319f * t;

    ta = -0.05839917f * a[3] + 0.14567312f * a[13] + 0.09403160f * a[15];
    tb = -0.05839917f * b[3] + 0.14567312f * b[13] + 0.09403160f * b[15];
    out[4] += ta * b[11] + tb * a[11];
    out[11] += ta * b[4] + tb * a[4];
    t = a[4] * b[11] + a[11] * b[4];
    out[3] -= 0.05839917f * t;
    out[13] += 0.14567312f * t;
    out[15] += 0.09403160f * t;

    ta = 0.28209479f * a[0] + 0.09011186f * a[6] - 0.15607835f * a[8];
    tb = 0.28209479f * b[0] + 0.09011186f * b[6] - 0.15607835f * b[8];
    out[5] += ta * b[5] + tb * a[5];
    t = a[5] * b[5];
    out[0] += 0.28209479f * t;
    out[6] += 0.09011186f * t;
    out[8] -= 0.15607835f * t;

    ta = 0.14867701f * a[14];
    tb = 0.14867701f * b[14];
    out[5] += ta * b[9] + tb * a[9];
    out[9] += ta * b[5] + tb * a[5];
    t = a[5] * b[9] + a[9] * b[5];
    out[14] += 0.14867701f * t;

    ta = 0.18467439f * a[3] + 0.11516472f * a[13] - 0.14867701f * a[15];
    tb = 0.18467439f * b[3] + 0.11516472f * b[13] - 0.14867701f * b[15];
    out[5] += ta * b[10] + tb * a[10];
    out[10] += ta * b[5] + tb * a[5];
    t = a[5] * b[10] + a[10] * b[5];
    out[3] += 0.18467439f * t;
    out[13] += 0.11516472f * t;
    out[15] -= 0.14867701f * t;

    ta = 0.23359668f * a[2] + 0.05947080f * a[12] - 0.11516472f * a[14];
    tb = 0.23359668f * b[2] + 0.05947080f * b[12] - 0.11516472f * b[14];
    out[5] += ta * b[11] + tb * a[11];
    out[11] += ta * b[5] + tb * a[5];
    t = a[5] * b[11] + a[11] * b[5];
    out[2] += 0.23359668f * t;
    out[12] += 0.05947080f * t;
    out[14] -= 0.11516472f * t;

    ta = 0.28209479f * a[0];
    tb = 0.28209479f * b[0];
    out[6] += ta * b[6] + tb * a[6];
    t = a[6] * b[6];
    out[0] += 0.28209479f * t;
    out[6] += 0.18022376f * t;

    ta = 0.09011186f * a[6] + 0.28209479f * a[0] + 0.15607835f * a[8];
    tb = 0.09011186f * b[6] + 0.28209479f * b[0] + 0.15607835f * b[8];
    out[7] += ta * b[7] + tb * a[7];
    t = a[7] * b[7];
    out[6] += 0.09011186f * t;
    out[0] += 0.28209479f * t;
    out[8] += 0.15607835f * t;

    ta = 0.14867701f * a[9] + 0.18467439f * a[1] + 0.11516472f * a[11];
    tb = 0.14867701f * b[9] + 0.18467439f * b[1] + 0.11516472f * b[11];
    out[7] += ta * b[10] + tb * a[10];
    out[10] += ta * b[7] + tb * a[7];
    t = a[7] * b[10] + a[10] * b[7];
    out[9] += 0.14867701f * t;
    out[1] += 0.18467439f * t;
    out[11] += 0.11516472f * t;

    ta = 0.05947080f * a[12] + 0.23359668f * a[2] + 0.11516472f * a[14];
    tb = 0.05947080f * b[12] + 0.23359668f * b[2] + 0.11516472f * b[14];
    out[7] += ta * b[13] + tb * a[13];
    out[13] += ta * b[7]+ tb * a[7];
    t = a[7] * b[13] + a[13] * b[7];
    out[12] += 0.05947080f * t;
    out[2] += 0.23359668f * t;
    out[14] += 0.11516472f * t;

    ta = 0.14867701f * a[15];
    tb = 0.14867701f * b[15];
    out[7] += ta * b[14] + tb * a[14];
    out[14] += ta * b[7] + tb * a[7];
    t = a[7] * b[14] + a[14] * b[7];
    out[15] += 0.14867701f * t;

    ta = 0.28209479f * a[0] - 0.18022375f * a[6];
    tb = 0.28209479f * b[0] - 0.18022375f * b[6];
    out[8] += ta * b[8] + tb * a[8];
    t = a[8] * b[8];
    out[0] += 0.28209479f * t;
    out[6] -= 0.18022375f * t;

    ta = -0.09403160f * a[11];
    tb = -0.09403160f * b[11];
    out[8] += ta * b[9] + tb * a[9];
    out[9] += ta * b[8] + tb * a[8];
    t = a[8] * b[9] + a[9] * b[8];
    out[11] -= 0.09403160f * t;

    ta = -0.09403160f * a[15];
    tb = -0.09403160f * b[15];
    out[8] += ta * b[13] + tb * a[13];
    out[13] += ta * b[8] + tb * a[8];
    t = a[8] * b[13] + a[13] * b[8];
    out[15] -= 0.09403160f * t;

    ta = 0.18467439f * a[2] - 0.18806319f * a[12];
    tb = 0.18467439f * b[2] - 0.18806319f * b[12];
    out[8] += ta * b[14] + tb * a[14];
    out[14] += ta * b[8] + tb * a[8];
    t = a[8] * b[14] + a[14] * b[8];
    out[2] += 0.18467439f * t;
    out[12] -= 0.18806319f * t;

    ta = -0.21026104f * a[6] + 0.28209479f * a[0];
    tb = -0.21026104f * b[6] + 0.28209479f * b[0];
    out[9] += ta * b[9] + tb * a[9];
    t = a[9] * b[9];
    out[6] -= 0.21026104f * t;
    out[0] += 0.28209479f * t;

    ta = 0.28209479f * a[0];
    tb = 0.28209479f * b[0];
    out[10] += ta * b[10] + tb * a[10];
    t = a[10] * b[10];
    out[0] += 0.28209479f * t;

    ta = 0.28209479f * a[0] + 0.12615663f * a[6] - 0.14567312f * a[8];
    tb = 0.28209479f * b[0] + 0.12615663f * b[6] - 0.14567312f * b[8];
    out[11] += ta * b[11] + tb * a[11];
    t = a[11] * b[11];
    out[0] += 0.28209479f * t;
    out[6] += 0.12615663f * t;
    out[8] -= 0.14567312f * t;

    ta = 0.28209479f * a[0] + 0.16820885f * a[6];
    tb = 0.28209479f * b[0] + 0.16820885f * b[6];
    out[12] += ta * b[12] + tb * a[12];
    t = a[12] * b[12];
    out[0] += 0.28209479f * t;
    out[6] += 0.16820885f * t;

    ta =0.28209479f * a[0] + 0.14567312f * a[8] + 0.12615663f * a[6];
    tb =0.28209479f * b[0] + 0.14567312f * b[8] + 0.12615663f * b[6];
    out[13] += ta * b[13] + tb * a[13];
    t = a[13] * b[13];
    out[0] += 0.28209479f * t;
    out[8] += 0.14567312f * t;
    out[6] += 0.12615663f * t;

    ta = 0.28209479f * a[0];
    tb = 0.28209479f * b[0];
    out[14] += ta * b[14] + tb * a[14];
    t = a[14] * b[14];
    out[0] += 0.28209479f * t;

    ta = 0.28209479f * a[0] - 0.21026104f * a[6];
    tb = 0.28209479f * b[0] - 0.21026104f * b[6];
    out[15] += ta * b[15] + tb * a[15];
    t = a[15] * b[15];
    out[0] += 0.28209479f * t;
    out[6] -= 0.21026104f * t;

    return out;
}

static void rotate_X(FLOAT *out, UINT order, FLOAT a, FLOAT *in)
{
    out[0] = in[0];

    out[1] = a * in[2];
    out[2] = -a * in[1];
    out[3] = in[3];

    out[4] = a * in[7];
    out[5] = -in[5];
    out[6] = -0.5f * in[6] - 0.8660253882f * in[8];
    out[7] = -a * in[4];
    out[8] = -0.8660253882f * in[6] + 0.5f * in[8];
    out[9] = -a * 0.7905694842f * in[12] + a * 0.6123724580f * in[14];

    out[10] = -in[10];
    out[11] = -a * 0.6123724580f * in[12] - a * 0.7905694842f * in[14];
    out[12] = a * 0.7905694842f * in[9] + a * 0.6123724580f * in[11];
    out[13] = -0.25f * in[13] - 0.9682458639f * in[15];
    out[14] = -a * 0.6123724580f * in[9] + a * 0.7905694842f * in[11];
    out[15] = -0.9682458639f * in[13] + 0.25f * in[15];
    if (order == 4)
        return;

    out[16] = -a * 0.9354143739f * in[21] + a * 0.3535533845f * in[23];
    out[17] = -0.75f * in[17] + 0.6614378095f * in[19];
    out[18] = -a * 0.3535533845f * in[21] - a * 0.9354143739f * in[23];
    out[19] = 0.6614378095f * in[17] + 0.75f * in[19];
    out[20] = 0.375f * in[20] + 0.5590170026f * in[22] + 0.7395099998f * in[24];
    out[21] = a * 0.9354143739f * in[16] + a * 0.3535533845f * in[18];
    out[22] = 0.5590170026f * in[20] + 0.5f * in[22] - 0.6614378691f * in[24];
    out[23] = -a * 0.3535533845f * in[16] + a * 0.9354143739f * in[18];
    out[24] = 0.7395099998f * in[20] - 0.6614378691f * in[22] + 0.125f * in[24];
    if (order == 5)
        return;

    out[25] = a * 0.7015607357f * in[30] - a * 0.6846531630f * in[32] + a * 0.1976423711f * in[34];
    out[26] = -0.5f * in[26] + 0.8660253882f * in[28];
    out[27] = a * 0.5229125023f * in[30] + a * 0.3061861992f * in[32] - a * 0.7954951525f * in[34];
    out[28] = 0.8660253882f * in[26] + 0.5f * in[28];
    out[29] = a * 0.4841229022f * in[30] + a * 0.6614378691f * in[32] + a * 0.5728219748f * in[34];
    out[30] = -a * 0.7015607357f * in[25] - a * 0.5229125023f * in[27] - a * 0.4841229022f * in[29];
    out[31] = 0.125f * in[31] + 0.4050463140f * in[33] + 0.9057110548f * in[35];
    out[32] = a * 0.6846531630f * in[25] - a * 0.3061861992f * in[27] - a * 0.6614378691f * in[29];
    out[33] = 0.4050463140f * in[31] + 0.8125f * in[33] - 0.4192627370f * in[35];
    out[34] = -a * 0.1976423711f * in[25] + a * 0.7954951525f * in[27] - a * 0.5728219748f * in[29];
    out[35] = 0.9057110548f * in[31] - 0.4192627370f * in[33] + 0.0624999329f * in[35];
}

FLOAT* WINAPI D3DXSHRotate(FLOAT *out, UINT order, const D3DXMATRIX *matrix, const FLOAT *in)
{
    FLOAT alpha, beta, gamma, sinb, temp[36], temp1[36];

    TRACE("out %p, order %u, matrix %p, in %p\n", out, order, matrix, in);

    out[0] = in[0];

    if ((order > D3DXSH_MAXORDER) || (order < D3DXSH_MINORDER))
        return out;

    if (order <= 3)
    {
        out[1] = matrix->u.m[1][1] * in[1] - matrix->u.m[2][1] * in[2] + matrix->u.m[0][1] * in[3];
        out[2] = -matrix->u.m[1][2] * in[1] + matrix->u.m[2][2] * in[2] - matrix->u.m[0][2] * in[3];
        out[3] = matrix->u.m[1][0] * in[1] - matrix->u.m[2][0] * in[2] + matrix->u.m[0][0] * in[3];

        if (order == 3)
        {
            FLOAT coeff[]={
                matrix->u.m[1][0] * matrix->u.m[0][0], matrix->u.m[1][1] * matrix->u.m[0][1],
                matrix->u.m[1][1] * matrix->u.m[2][1], matrix->u.m[1][0] * matrix->u.m[2][0],
                matrix->u.m[2][0] * matrix->u.m[2][0], matrix->u.m[2][1] * matrix->u.m[2][1],
                matrix->u.m[0][0] * matrix->u.m[2][0], matrix->u.m[0][1] * matrix->u.m[2][1],
                matrix->u.m[0][1] * matrix->u.m[0][1], matrix->u.m[1][0] * matrix->u.m[1][0],
                matrix->u.m[1][1] * matrix->u.m[1][1], matrix->u.m[0][0] * matrix->u.m[0][0], };

            out[4] = (matrix->u.m[1][1] * matrix->u.m[0][0] + matrix->u.m[0][1] * matrix->u.m[1][0]) * in[4];
            out[4] -= (matrix->u.m[1][0] * matrix->u.m[2][1] + matrix->u.m[1][1] * matrix->u.m[2][0]) * in[5];
            out[4] += 1.7320508076f * matrix->u.m[2][0] * matrix->u.m[2][1] * in[6];
            out[4] -= (matrix->u.m[0][1] * matrix->u.m[2][0] + matrix->u.m[0][0] * matrix->u.m[2][1]) * in[7];
            out[4] += (matrix->u.m[0][0] * matrix->u.m[0][1] - matrix->u.m[1][0] * matrix->u.m[1][1]) * in[8];

            out[5] = (matrix->u.m[1][1] * matrix->u.m[2][2] + matrix->u.m[1][2] * matrix->u.m[2][1]) * in[5];
            out[5] -= (matrix->u.m[1][1] * matrix->u.m[0][2] + matrix->u.m[1][2] * matrix->u.m[0][1]) * in[4];
            out[5] -= 1.7320508076f * matrix->u.m[2][2] * matrix->u.m[2][1] * in[6];
            out[5] += (matrix->u.m[0][2] * matrix->u.m[2][1] + matrix->u.m[0][1] * matrix->u.m[2][2]) * in[7];
            out[5] -= (matrix->u.m[0][1] * matrix->u.m[0][2] - matrix->u.m[1][1] * matrix->u.m[1][2]) * in[8];

            out[6] = (matrix->u.m[2][2] * matrix->u.m[2][2] - 0.5f * (coeff[4] + coeff[5])) * in[6];
            out[6] -= (0.5773502692f * (coeff[0] + coeff[1]) - 1.1547005384f * matrix->u.m[1][2] * matrix->u.m[0][2]) * in[4];
            out[6] += (0.5773502692f * (coeff[2] + coeff[3]) - 1.1547005384f * matrix->u.m[1][2] * matrix->u.m[2][2]) * in[5];
            out[6] += (0.5773502692f * (coeff[6] + coeff[7]) - 1.1547005384f * matrix->u.m[0][2] * matrix->u.m[2][2]) * in[7];
            out[6] += (0.2886751347f * (coeff[9] - coeff[8] + coeff[10] - coeff[11]) - 0.5773502692f *
                  (matrix->u.m[1][2] * matrix->u.m[1][2] - matrix->u.m[0][2] * matrix->u.m[0][2])) * in[8];

            out[7] = (matrix->u.m[0][0] * matrix->u.m[2][2] + matrix->u.m[0][2] * matrix->u.m[2][0]) * in[7];
            out[7] -= (matrix->u.m[1][0] * matrix->u.m[0][2] + matrix->u.m[1][2] * matrix->u.m[0][0]) * in[4];
            out[7] += (matrix->u.m[1][0] * matrix->u.m[2][2] + matrix->u.m[1][2] * matrix->u.m[2][0]) * in[5];
            out[7] -= 1.7320508076f * matrix->u.m[2][2] * matrix->u.m[2][0] * in[6];
            out[7] -= (matrix->u.m[0][0] * matrix->u.m[0][2] - matrix->u.m[1][0] * matrix->u.m[1][2]) * in[8];

            out[8] = 0.5f * (coeff[11] - coeff[8] - coeff[9] + coeff[10]) * in[8];
            out[8] += (coeff[0] - coeff[1]) * in[4];
            out[8] += (coeff[2] - coeff[3]) * in[5];
            out[8] += 0.86602540f * (coeff[4] - coeff[5]) * in[6];
            out[8] += (coeff[7] - coeff[6]) * in[7];
        }

        return out;
    }

    if (fabsf(matrix->u.m[2][2]) != 1.0f)
    {
        sinb = sqrtf(1.0f - matrix->u.m[2][2] * matrix->u.m[2][2]);
        alpha = atan2f(matrix->u.m[2][1] / sinb, matrix->u.m[2][0] / sinb);
        beta = atan2f(sinb, matrix->u.m[2][2]);
        gamma = atan2f(matrix->u.m[1][2] / sinb, -matrix->u.m[0][2] / sinb);
    }
    else
    {
        alpha = atan2f(matrix->u.m[0][1], matrix->u.m[0][0]);
        beta = 0.0f;
        gamma = 0.0f;
    }

    D3DXSHRotateZ(temp, order, gamma, in);
    rotate_X(temp1, order, 1.0f, temp);
    D3DXSHRotateZ(temp, order, beta, temp1);
    rotate_X(temp1, order, -1.0f, temp);
    D3DXSHRotateZ(out, order, alpha, temp1);

    return out;
}

FLOAT * WINAPI D3DXSHRotateZ(FLOAT *out, UINT order, FLOAT angle, const FLOAT *in)
{
    UINT i, sum = 0;
    FLOAT c[5], s[5];

    TRACE("out %p, order %u, angle %f, in %p\n", out, order, angle, in);

    order = min(max(order, D3DXSH_MINORDER), D3DXSH_MAXORDER);

    out[0] = in[0];

    for (i = 1; i < order; i++)
    {
        UINT j;

        c[i - 1] = cosf(i * angle);
        s[i - 1] = sinf(i * angle);
        sum += i * 2;

        out[sum - i] = c[i - 1] * in[sum - i];
        out[sum - i] += s[i - 1] * in[sum + i];
        for (j = i - 1; j > 0; j--)
        {
            out[sum - j] = 0.0f;
            out[sum - j] = c[j - 1] * in[sum - j];
            out[sum - j] += s[j - 1] * in[sum + j];
        }

        if (in == out)
            out[sum] = 0.0f;
        else
            out[sum] = in[sum];

        for (j = 1; j < i; j++)
        {
            out[sum + j] = 0.0f;
            out[sum + j] = -s[j - 1] * in[sum - j];
            out[sum + j] += c[j - 1] * in[sum + j];
        }
        out[sum + i] = -s[i - 1] * in[sum - i];
        out[sum + i] += c[i - 1] * in[sum + i];
    }

    return out;
}

FLOAT* WINAPI D3DXSHScale(FLOAT *out, UINT order, const FLOAT *a, const FLOAT scale)
{
    UINT i;

    TRACE("out %p, order %u, a %p, scale %f\n", out, order, a, scale);

    for (i = 0; i < order * order; i++)
        out[i] = a[i] * scale;

    return out;
}
