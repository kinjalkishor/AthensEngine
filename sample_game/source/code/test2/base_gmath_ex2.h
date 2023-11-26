#pragma once

#include "base_gmath.h"
#include "base_gmath_ex.h"

namespace gm
{

class viewport_gl {
public:
    float x, y, w, h;   
};

inline void fix_camera_axis(gm::vec3& position) {
	if (position.x == 0.0f && position.y == 0.0f) { position.x = 0.000001f; }
}


//=======================================================
// EXTRA FUNCTIONS
//=======================================================
inline mat4 mat4_inverse_transpose(const mat4& ma) {
	return mat4_transpose(mat4_inverse(ma));
}


inline mat4 mat4_shadow_vec3(vec3 const& light_dir, plane const& pa) {
    return mat4_shadow(vec4(light_dir.x, light_dir.y, light_dir.z, 0.0), pa);
}

//------------------
inline vec3 vec3_negate(const vec3& a) { return -a; }
inline vec3 vec3_inverse(const vec3& a) { return -a; }

inline vec3 vec3_fabs(const vec3& a) {
	vec3 out = vec3::k_zero();
	for_range (i, 0, a.size()) {
		out[i] = std::fabs(a[i]);
	}
	return out;
}

inline vec3 vec3_deg_to_rad(const vec3& a) {
    vec3 out = vec3::k_zero();
	for_range (i, 0, a.size()) {
		out[i] = mf::deg_to_rad(a[i]);
	}
	return out;
}


//----------------------------------------

//color4 color4_srgb_correction(color4 color) {
//    constexpr float GAMMAVAL = 2.2;
//
//    // unpack D3DCOLOR into something we can manipulate
//    color4 out = gm::color4::k_zero();
//    // gamma correct colors...
//    out.r = pow(color.r, GAMMAVAL);
//    out.g = pow(color.g, GAMMAVAL);
//    out.b = pow(color.b, GAMMAVAL);
//    out.a = color.a;
//
//    // repack the aforementioned data into the colorvalue for returning
//    return out;
//}

//----------------------------------------
inline mat4 mat4_shearing(float x, float y) {
	return mat4(
		scast<float>(1.0),	y,					scast<float>(0.0), scast<float>(0.0),
		x,					scast<float>(1.0),	scast<float>(0.0), scast<float>(0.0),
		scast<float>(0.0),	scast<float>(0.0),	scast<float>(1.0), scast<float>(0.0),
		scast<float>(0.0),	scast<float>(0.0),	scast<float>(0.0), scast<float>(1.0)
	);
}


//--------------------------------------------
//--------------------------------------------
// Disable when glm functions are implemented:

// Direct3D-like: The clip space depth goes from 0.0 at the near plane to +1.0 at the far plane. 
// This applies to Direct3D, Vulkan, Metal and consoles. 
// OpenGL-like: The clip space depth goes from –1.0 at the near plane to +1.0 at the far plane.
inline mat4 glm_perspectiveRH_NO(float fovy, float aspect, float zNear, float zFar) {
	//assert(abs(aspect - std::numeric_limits<float>::epsilon()) > static_cast<float>(0));

	float const tanHalfFovy = tan(fovy / static_cast<float>(2));

	mat4 Result(static_cast<float>(0));
	Result.r[0][0] = static_cast<float>(1) / (aspect * tanHalfFovy);
	Result.r[1][1] = static_cast<float>(1) / (tanHalfFovy);
	Result.r[2][2] = - (zFar + zNear) / (zFar - zNear);
	Result.r[2][3] = - static_cast<float>(1);
	Result.r[3][2] = - (static_cast<float>(2) * zFar * zNear) / (zFar - zNear);
	return Result;
}

inline mat4 glm_perspectiveRH_ZO(float fovy, float aspect, float zNear, float zFar) {
	//assert(abs(aspect - std::numeric_limits<float>::epsilon()) > static_cast<float>(0));

	float const tanHalfFovy = tan(fovy / static_cast<float>(2));

	mat4 Result(static_cast<float>(0));
	Result.r[0][0] = static_cast<float>(1) / (aspect * tanHalfFovy);
	Result.r[1][1] = static_cast<float>(1) / (tanHalfFovy);
	Result.r[2][2] = zFar / (zNear - zFar);
	Result.r[2][3] = - static_cast<float>(1);
	Result.r[3][2] = -(zFar * zNear) / (zFar - zNear);
	return Result;
}
//--------------------------------------------


}