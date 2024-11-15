#pragma once



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



FLOAT* WINAPI D3DXSHRotate
    ( FLOAT *pOut, UINT Order, CONST D3DXMATRIX *pMatrix, CONST FLOAT *pIn );
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
FLOAT* WINAPI D3DXSHAdd(FLOAT *out, UINT order, const FLOAT *a, const FLOAT *b)
{
    UINT i;

    TRACE("out %p, order %u, a %p, b %p\n", out, order, a, b);

    for (i = 0; i < order * order; i++)
        out[i] = a[i] + b[i];

    return out;
}


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
FLOAT* WINAPI D3DXSHScale(FLOAT *out, UINT order, const FLOAT *a, const FLOAT scale)
{
    UINT i;

    TRACE("out %p, order %u, a %p, scale %f\n", out, order, a, scale);

    for (i = 0; i < order * order; i++)
        out[i] = a[i] * scale;

    return out;
}
    
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



FLOAT* WINAPI D3DXSHMultiply3( FLOAT *pOut, CONST FLOAT *pF, CONST FLOAT *pG);
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




FLOAT* WINAPI D3DXSHMultiply4( FLOAT *pOut, CONST FLOAT *pF, CONST FLOAT *pG);
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





//-------------------------------------
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




HRESULT WINAPI D3DXSHEvalSphericalLight
    ( UINT Order, CONST D3DXVECTOR3 *pPos, FLOAT Radius,
      FLOAT RIntensity, FLOAT GIntensity, FLOAT BIntensity,
      FLOAT *pROut, FLOAT *pGOut, FLOAT *pBOut );
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


