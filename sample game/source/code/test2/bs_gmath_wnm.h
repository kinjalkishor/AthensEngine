#pragma once

#include "bs_gmath.h"
#include "bs_gmath2.h"

namespace gm
{

inline vec2 vec2_transform_pos2(const vec2& a, const mat4& ma) {
    return vec2(ma.r[0][0] * a.x + ma.r[1][0] * a.y  + ma.r[3][0],
				ma.r[0][1] * a.x + ma.r[1][1] * a.y  + ma.r[3][1]);
}

inline vec3 vec3_transform_pos3(const vec3& a, const mat4& ma) {
    return vec3(ma.r[0][0] * a.x + ma.r[1][0] * a.y + ma.r[2][0] * a.z + ma.r[3][0],
				ma.r[0][1] * a.x + ma.r[1][1] * a.y + ma.r[2][1] * a.z + ma.r[3][1],
				ma.r[0][2] * a.x + ma.r[1][2] * a.y + ma.r[2][2] * a.z + ma.r[3][2]);
}


inline vec3 vec3_translation_mat4(const mat4& value) {
    return vec3(value.r[3][0], value.r[3][1], value.r[3][2]);
}


inline plane plane_transform_quat(const plane& value, const quat& rotation) {
    vec4 planeAsVector(value.normal, value.d);
    return plane(transform(planeAsVector, rotation)); //vec4_transform_v4_quat
}

inline quat quat_from_axis_angle(const vec3& axis, float angle) {
    float halfAngle = angle * 0.5f;
    float s = sinf(halfAngle);
    float c = cosf(halfAngle);

    return quat(axis * s, c);
}


inline vec2 vec2_transform_v2_quat(const vec2& a, const quat& rotation) {
    float x2 = rotation.x + rotation.x;
    float y2 = rotation.y + rotation.y;
    float z2 = rotation.z + rotation.z;

    float wz2 = rotation.w * z2;
    float xx2 = rotation.x * x2;
    float xy2 = rotation.x * y2;
    float yy2 = rotation.y * y2;
    float zz2 = rotation.z * z2;

    return vec2(a.x * (1.0f - yy2 - zz2) + a.y * (xy2 - wz2),
				a.x * (xy2 + wz2) + a.y * (1.0f - xx2 - zz2));
}

inline vec3 vec3_transform_v3_quat(const vec3& a, const quat& rotation) {
    float x2 = rotation.x + rotation.x;
    float y2 = rotation.y + rotation.y;
    float z2 = rotation.z + rotation.z;

    float wx2 = rotation.w * x2;
    float wy2 = rotation.w * y2;
    float wz2 = rotation.w * z2;
    float xx2 = rotation.x * x2;
    float xy2 = rotation.x * y2;
    float xz2 = rotation.x * z2;
    float yy2 = rotation.y * y2;
    float yz2 = rotation.y * z2;
    float zz2 = rotation.z * z2;

    return vec3(a.x * (1.0f - yy2 - zz2) + a.y * (xy2 - wz2) + a.z * (xz2 + wy2),
				a.x * (xy2 + wz2) + a.y * (1.0f - xx2 - zz2) + a.z * (yz2 - wx2),
				a.x * (xz2 - wy2) + a.y * (yz2 + wx2) + a.z * (1.0f - xx2 - yy2));
}


inline vec4 vec4_transform_v2_quat(const vec2& a, const quat& rotation) {
    float x2 = rotation.x + rotation.x;
    float y2 = rotation.y + rotation.y;
    float z2 = rotation.z + rotation.z;

    float wx2 = rotation.w * x2;
    float wy2 = rotation.w * y2;
    float wz2 = rotation.w * z2;
    float xx2 = rotation.x * x2;
    float xy2 = rotation.x * y2;
    float xz2 = rotation.x * z2;
    float yy2 = rotation.y * y2;
    float yz2 = rotation.y * z2;
    float zz2 = rotation.z * z2;

    return vec4(a.x * (1.0f - yy2 - zz2) + a.y * (       xy2 - wz2),
				a.x * (       xy2 + wz2) + a.y * (1.0f - xx2 - zz2),
				a.x * (       xz2 - wy2) + a.y * (       yz2 + wx2),
				1.0f);
}

inline vec4 vec4_transform_v3_quat(const vec3& a, const quat& rotation) {
    float x2 = rotation.x + rotation.x;
    float y2 = rotation.y + rotation.y;
    float z2 = rotation.z + rotation.z;

    float wx2 = rotation.w * x2;
    float wy2 = rotation.w * y2;
    float wz2 = rotation.w * z2;
    float xx2 = rotation.x * x2;
    float xy2 = rotation.x * y2;
    float xz2 = rotation.x * z2;
    float yy2 = rotation.y * y2;
    float yz2 = rotation.y * z2;
    float zz2 = rotation.z * z2;

    return vec4(a.x * (1.0f - yy2 - zz2) + a.y * (       xy2 - wz2) + a.z * (       xz2 + wy2),
				a.x * (       xy2 + wz2) + a.y * (1.0f - xx2 - zz2) + a.z * (       yz2 - wx2),
				a.x * (       xz2 - wy2) + a.y * (       yz2 + wx2) + a.z * (1.0f - xx2 - yy2),
				1.0f);
}

inline vec4 vec4_transform_v4_quat(const vec4& a, const quat& rotation) {
    float x2 = rotation.x + rotation.x;
    float y2 = rotation.y + rotation.y;
    float z2 = rotation.z + rotation.z;

    float wx2 = rotation.w * x2;
    float wy2 = rotation.w * y2;
    float wz2 = rotation.w * z2;
    float xx2 = rotation.x * x2;
    float xy2 = rotation.x * y2;
    float xz2 = rotation.x * z2;
    float yy2 = rotation.y * y2;
    float yz2 = rotation.y * z2;
    float zz2 = rotation.z * z2;

    return vec4(a.x * (1.0f - yy2 - zz2) + a.y * (       xy2 - wz2) + a.z * (       xz2 + wy2),
				a.x * (       xy2 + wz2) + a.y * (1.0f - xx2 - zz2) + a.z * (       yz2 - wx2),
				a.x * (       xz2 - wy2) + a.y * (       yz2 + wx2) + a.z * (1.0f - xx2 - yy2),
				a.w);
}


inline quat lerp(const quat& a, const quat& b, float s) {
    float t2 = s;
    float t1 = 1.0f - s;

    if (quat_dot(a, b) < 0.0f) {
        t2 = -t2;
    }


    return quat_normalize(quat(t1 * a.x + t2 * b.x,
						       t1 * a.y + t2 * b.y,
						       t1 * a.z + t2 * b.z,
						       t1 * a.w + t2 * b.w));
}

inline quat quat_concatenate(const quat& a, const quat& b) { return (b * a); }


inline mat4 mat4_transform_quat(const mat4& ma, const quat& rotation) {
    // Compute rotation matrix.
    float x2 = rotation.x + rotation.x;
    float y2 = rotation.y + rotation.y;
    float z2 = rotation.z + rotation.z;

    float wx2 = rotation.w * x2;
    float wy2 = rotation.w * y2;
    float wz2 = rotation.w * z2;
    float xx2 = rotation.x * x2;
    float xy2 = rotation.x * y2;
    float xz2 = rotation.x * z2;
    float yy2 = rotation.y * y2;
    float yz2 = rotation.y * z2;
    float zz2 = rotation.z * z2;

    float q11 = 1 - yy2 - zz2;
    float q21 = xy2 - wz2;
    float q31 = xz2 + wy2;

    float q12 = xy2 + wz2;
    float q22 = 1 - xx2 - zz2;
    float q32 = yz2 - wx2;

    float q13 = xz2 - wy2;
    float q23 = yz2 + wx2;
    float q33 = 1 - xx2 - yy2;

    return mat4(
        // First row
        ma.r[0][0] * q11 + ma.r[0][1] * q21 + ma.r[0][2] * q31,
        ma.r[0][0] * q12 + ma.r[0][1] * q22 + ma.r[0][2] * q32,
        ma.r[0][0] * q13 + ma.r[0][1] * q23 + ma.r[0][2] * q33,
        ma.r[0][3],

        // Second row
        ma.r[1][0] * q11 + ma.r[1][1] * q21 + ma.r[1][2] * q31,
        ma.r[1][0] * q12 + ma.r[1][1] * q22 + ma.r[1][2] * q32,
        ma.r[1][0] * q13 + ma.r[1][1] * q23 + ma.r[1][2] * q33,
        ma.r[1][3],

        // Third row
        ma.r[2][0] * q11 + ma.r[2][1] * q21 + ma.r[2][2] * q31,
        ma.r[2][0] * q12 + ma.r[2][1] * q22 + ma.r[2][2] * q32,
        ma.r[2][0] * q13 + ma.r[2][1] * q23 + ma.r[2][2] * q33,
        ma.r[2][3],

        // Fourth row
        ma.r[3][0] * q11 + ma.r[3][1] * q21 + ma.r[3][2] * q31,
        ma.r[3][0] * q12 + ma.r[3][1] * q22 + ma.r[3][2] * q32,
        ma.r[3][0] * q13 + ma.r[3][1] * q23 + ma.r[3][2] * q33,
        ma.r[3][3]
    );
}



inline mat4 mat4_rotation_x_pt(float angle, const vec3& center_point) {
    float c = cosf(angle);
    float s = sinf(angle);

    float y = center_point.y * (1 - c) + center_point.z * s;
    float z = center_point.z * (1 - c) - center_point.y * s;

    return mat4(1,  0, 0, 0,
				0,  c, s, 0,
				0, -s, c, 0,
				0,  y, z, 1);
}

inline mat4 mat4_rotation_y_pt(float angle, const vec3& center_point) {
    float c = cosf(angle);
    float s = sinf(angle);

    float x = center_point.x * (1 - c) - center_point.z * s;
    float z = center_point.z * (1 - c) + center_point.x * s;

    return mat4(c, 0, -s, 0,
				0, 1,  0, 0,
				s, 0,  c, 0,
				x, 0,  z, 1);
}

inline mat4 mat4_rotation_z_pt(float angle, const vec3& center_point) {
    float c = cosf(angle);
    float s = sinf(angle);

    float x = center_point.x * (1 - c) + center_point.y * s;
    float y = center_point.y * (1 - c) - center_point.x * s;

    return mat4( c, s, 0, 0,
				-s, c, 0, 0,
				 0, 0, 1, 0,
				 x, y, 0, 1);
}


inline mat4 mat4_scale_pt(const vec3& scales, const vec3& center_point) {
    vec3 t = vec3(center_point.x * (1 - scales.x),
				  center_point.y * (1 - scales.y),
				  center_point.z * (1 - scales.z));

    return mat4(scales.x, 0,        0,        0,
				0,        scales.y, 0,        0,
				0,        0,        scales.z, 0,
				t.x,      t.y,      t.z,      1);
}


inline mat4 mat4_world(const vec3& position, const vec3& forward, const vec3& up) {
    vec3 zaxis = vec3_normalize(-forward);
    vec3 xaxis = vec3_normalize(cross(up, zaxis));
    vec3 yaxis = vec3_cross(zaxis, xaxis);

    return mat4(xaxis.x,    xaxis.y,    xaxis.z,    0,
				yaxis.x,    yaxis.y,    yaxis.z,    0,
				zaxis.x,    zaxis.y,    zaxis.z,    0,
				position.x, position.y, position.z, 1);
}



inline mat4 mat4_from_axis_angle(const vec3& axis, float angle) {
    // a: angle
    // x, y, z: unit vector for axis.
    //
    // Rotation matrix M can be computed by below equation.
    //
    //  M = uu + (cos a)(I-uu) + (sin a)S
    //
    // Where:
    //
    //  u = ( x, y, z )
    //
    //      [  0 -z  y ]
    //  S = [  z  0 -x ]
    //      [ -y  x  0 ]
    //
    //      [ 1 0 0 ]
    //  I = [ 0 1 0 ]
    //      [ 0 0 1 ]

    float x = axis.x, y = axis.y, z = axis.z;
    float sa = sinf(angle), ca = cosf(angle);
    float xx = x * x, yy = y * y, zz = z * z;
    float xy = x * y, xz = x * z, yz = y * z;

    return mat4(xx + ca * (1 - xx),     xy - ca * xy + sa * z,  xz - ca * xz - sa * y,  0,
				xy - ca * xy - sa * z,  yy + ca * (1 - yy),     yz - ca * yz + sa * x,  0,
				xz - ca * xz + sa * y,  yz - ca * yz - sa * x,  zz + ca * (1 - zz),     0,
				0,                      0,                      0,                      1);
}


inline mat4 mat4_shadow_v3(const vec3& light, const plane& pa) {
    const vec3& l = light;
    const plane pn = plane_normalize(pa);
    const float dot = plane_dot_normal(pn, l);	

    const plane p = -pn;

    return mat4(
        p.a*l.x + dot, p.a*l.y,       p.a*l.z,       0,
		p.b*l.x,       p.b*l.y + dot, p.b*l.z,       0,
		p.c*l.x,       p.c*l.y,       p.c*l.z + dot, 0,
		p.d*l.x,       p.d*l.y,       p.d*l.z,       dot
    );
}






inline mat4 mat4_billboard(const vec3& object_position, const vec3& camera_position, const vec3& camera_up_vector, const vec3& camera_forward_vector) {
    const float epsilon = 1e-4f;

    vec3 zaxis = object_position - camera_position;

    float norm = length_squared(zaxis);

    if (norm < epsilon) {
        zaxis = -camera_forward_vector;
    } else {
        zaxis = zaxis / sqrtf(norm);
    }

    vec3 xaxis = normalize(cross(camera_up_vector, zaxis));
    vec3 yaxis = cross(zaxis, xaxis);

    return mat4(xaxis.x,          xaxis.y,          xaxis.z,          0,
                yaxis.x,          yaxis.y,          yaxis.z,          0,
                zaxis.x,          zaxis.y,          zaxis.z,          0,
                object_position.x, object_position.y, object_position.z, 1);
}

inline mat4 mat4_constrained_billboard(const vec3& object_position, const vec3& camera_position, const vec3& rotate_axis, const vec3& camera_forward_vector, const vec3& object_forward_vector) {
    const float epsilon = 1e-4f;
    const float minAngle = 1.0f - (0.1f * (DX_XM_PI / 180.0f)); // 0.1 degrees

    // Treat the case when object and camera positions are too close.
    vec3 faceDir = object_position - camera_position;

    float norm = length_squared(faceDir);

    if (norm < epsilon) {
        faceDir = -camera_forward_vector;
    } else {
        faceDir = faceDir / sqrtf(norm);
    }

    vec3 yaxis = rotate_axis;
    vec3 xaxis;
    vec3 zaxis;

    // Treat the case when angle between faceDir and rotate_axis is too close to 0.
    if (fabs(dot(rotate_axis, faceDir)) > minAngle) {
        zaxis = object_forward_vector;

        if (fabs(dot(rotate_axis, zaxis)) > minAngle) {
            zaxis = (fabs(rotate_axis.z) > minAngle) ? vec3(1, 0, 0) : vec3(0, 0, -1);
        }

        xaxis = normalize(cross(rotate_axis, zaxis));
        zaxis = normalize(cross(xaxis, rotate_axis));
    } else {
        xaxis = normalize(cross(rotate_axis, faceDir));
        zaxis = normalize(cross(xaxis, yaxis));
    }

    return mat4(xaxis.x,          xaxis.y,          xaxis.z,          0,
                yaxis.x,          yaxis.y,          yaxis.z,          0,
                zaxis.x,          zaxis.y,          zaxis.z,          0,
                object_position.x, object_position.y, object_position.z, 1);
}


//-----------------------------------------------------------
// CHECK: mat4_rotation_yaw_pitch_roll
inline mat4 mat4_from_yaw_pitch_roll_wnm(float yaw, float pitch, float roll) {
    //quat q = make_quaternion_from_yaw_pitch_roll(yaw, pitch, roll);
    //return mat4_from_quaternion(q);
    quat q = quat_rotation_yaw_pitch_roll(yaw, pitch, roll);
    return mat4_rotation_quat(q);
}
}