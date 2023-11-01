#include "chk_math.h"

#if defined(_MSC_VER)	
	//libcmt.lib conflicts with use of other libs warning
	#pragma comment(linker, "/NODEFAULTLIB:libcmt.lib")
#endif


#define WIN32_LEAN_AND_MEAN
// DXSDK_Jun10
#include <d3d9.h>
#pragma comment(lib,"DXSDK_Jun10/Lib/x64/d3d9.lib")
#include "DXSDK_Jun10/Include/d3dx9.h"
#pragma comment(lib,"DXSDK_Jun10/Lib/x64/d3dx9.lib")
//----------------

// GLM
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/string_cast.hpp"
//----------------

#include "base_types.h"
#include "base_print.h"
#include "base_io.h"
#include "base_ostrz.h"
#include "base_gmath.h"
#include "base_gmath_ex.h"

//==========================================================================
#if 1
//-------------------------
// Printing to ostrz
//-------------------------

inline ostrz str(const gm::vec2& e) { return ostrz_fmt("%f, %f,", e[0], e[1]); }
inline ostrz str(const gm::vec3& e) { return ostrz_fmt("%f, %f, %f,", e[0], e[1], e[2]); }
inline ostrz str(const gm::vec4& e) { return ostrz_fmt("%f, %f, %f, %f,", e[0], e[1], e[2], e[3]); }
inline ostrz str(const gm::color4& e) { return ostrz_fmt("%f, %f, %f, %f,", e[0], e[1], e[2], e[3]); }
inline ostrz str(const gm::quat& e) { return ostrz_fmt("%f, %f, %f, %f,", e[0], e[1], e[2], e[3]); }
inline ostrz str(const gm::plane& e) { return ostrz_fmt("%f, %f, %f, %f,", e[0], e[1], e[2], e[3]); }
inline ostrz str(const gm::mat3& e) {
	return ostrz_fmt("\n%f, %f, %f,\n%f, %f, %f,\n%f, %f, %f,\n",
		e[0], e[1], e[2],
		e[3], e[4], e[5],
		e[6], e[7], e[8]
	);
}	
inline ostrz str(const gm::mat4& e) {
	return ostrz_fmt("\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n", 
		e[0],  e[1],  e[2],  e[3], 
		e[4],  e[5],  e[6],  e[7], 
		e[8],  e[9],  e[10], e[11], 
		e[12], e[13], e[14], e[15]
	);
}

//inline ostrz str(const gm::cmat4& e) {
//	return ostrz_fmt("\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n", 
//		e[0],  e[1],  e[2],  e[3], 
//		e[4],  e[5],  e[6],  e[7], 
//		e[8],  e[9],  e[10], e[11], 
//		e[12], e[13], e[14], e[15]
//	);
//}


//#include <type_traits>
//printf("is_pod - is_trivial: %d, is_standard_layout: %d\n", 
//	std::is_trivial<gm::vec3>::value, std::is_standard_layout<gm::vec3>::value);
// USE_FMT_FORMAT
//template <>
//struct fmt::formatter<gm::vec3> : fmt_base {
//    template <typename FormatContext>
//    auto format(const gm::vec3& p, FormatContext& ctx) const -> decltype(ctx.out()) {
//		fmt::format_to( ctx.out(), "{:.6f}, {:.6f}, {:.6f}", p[0], p[1], p[2]);
//        return ctx.out();
//    }
//};
#endif
//==========================================================================


inline void print_sep_m() { printfln("----------------"); }

#if 1
//d3dx9math print
inline ostrz str(const D3DXVECTOR2& e) { return ostrz_fmt("%f, %f,", e[0], e[1]); }
inline ostrz str(const D3DXVECTOR3& e) { return ostrz_fmt("%f, %f, %f,", e[0], e[1], e[2]); }
inline ostrz str(const D3DXVECTOR4& e) { return ostrz_fmt("%f, %f, %f, %f,", e[0], e[1], e[2], e[3]); }
inline ostrz str(const D3DXCOLOR& e) { return ostrz_fmt("%f, %f, %f, %f,", e.r, e.g, e.b, e.a); }
inline ostrz str(const D3DXQUATERNION& e) { return ostrz_fmt("%f, %f, %f, %f,", e[0], e[1], e[2], e[3]); }
inline ostrz str(const D3DXPLANE& e) { return ostrz_fmt("%f, %f, %f, %f,", e[0], e[1], e[2], e[3]); }
inline ostrz str(const D3DXMATRIX& e) {
	return ostrz_fmt("\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n", 
		e[0],  e[1],  e[2],  e[3], 
		e[4],  e[5],  e[6],  e[7], 
		e[8],  e[9],  e[10], e[11], 
		e[12], e[13], e[14], e[15]
	);
}


inline ostrz str(const glm::vec4& e) { 
	//printfln("%s", glm::to_string(e).c_str());
	return ostrz_fmt("%f, %f, %f, %f,", e[0], e[1], e[2], e[3]); 
}
inline ostrz str(const glm::mat4& e) {
	//printfln("%s", glm::to_string(e).c_str());

	return ostrz_fmt("\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n%f, %f, %f, %f,\n", 
		e[0][0],  e[0][1],  e[0][2],  e[0][3], 
		e[1][0],  e[1][1],  e[1][2],  e[1][3],
		e[2][0],  e[2][1],  e[2][2],  e[2][3],
		e[3][0],  e[3][1],  e[3][2],  e[3][3]
	);
}


//------------------
template<class T, class U>
inline bool chk_equals(T a, U b) {
	for_range (i, 0, a.size()) { 
		if (!(mf::equals2(a[i], b[i]))) {
		//if (!(a[i] == b[i])) { 
			return false; 
		} 
	}	
	return true; 
}


inline bool chk_equals_d9c4(gm::color4 a, D3DXCOLOR b) {
	return (a.r == b.r && a.g == b.g && a.b == b.b && a.a == b.a);
}

//inline bool chk_equals_glm_m4(gm::cmat4 a, glm::mat4 b) {
inline bool chk_equals_glm_m4(gm::mat4 a, glm::mat4 b) {
#if 1
	return (
			a[0]  == b[0][0] && a[1]  == b[0][1] && a[2]  == b[0][2] && a[3]  == b[0][3] && 
			a[4]  == b[1][0] && a[5]  == b[1][1] && a[6]  == b[1][2] && a[7]  == b[1][3] && 
			a[8]  == b[2][0] && a[9]  == b[2][1] && a[10] == b[2][2] && a[11] == b[2][3] && 
			a[12] == b[3][0] && a[13] == b[3][1] && a[14] == b[3][2] && a[15] == b[3][3]
		);
#else
	return (
			mf::equals2(a[0]  , b[0][0]) && mf::equals2(a[1]  , b[0][1]) && mf::equals2(a[2]  , b[0][2]) && mf::equals2(a[3]  , b[0][3]) && 
			mf::equals2(a[4]  , b[1][0]) && mf::equals2(a[5]  , b[1][1]) && mf::equals2(a[6]  , b[1][2]) && mf::equals2(a[7]  , b[1][3]) && 
			mf::equals2(a[8]  , b[2][0]) && mf::equals2(a[9]  , b[2][1]) && mf::equals2(a[10] , b[2][2]) && mf::equals2(a[11] , b[2][3]) && 
			mf::equals2(a[12] , b[3][0]) && mf::equals2(a[13] , b[3][1]) && mf::equals2(a[14] , b[3][2]) && mf::equals2(a[15] , b[3][3])
		);
#endif
}

//------------------
template<class T, class U>
inline void copy_vs(T& out, const U& in) {
	for_range (i, 0, in.size()) {
		out[i] = in[i];
	}
}

inline void copy_vs_glm_m4(glm::mat4& out, const gm::mat4& in) {
	out[0][0] = in[0];   out[0][1] = in[1];   out[0][2] = in[2];   out[0][3] = in[3]; 
	out[1][0] = in[4];   out[1][1] = in[5];   out[1][2] = in[6];   out[1][3] = in[7];
	out[2][0] = in[8];   out[2][1] = in[9];   out[2][2] = in[10];  out[2][3] = in[11];
	out[3][0] = in[12];  out[3][1] = in[13];  out[3][2] = in[14];  out[3][3] = in[15];
}

//inline void copy_vs_glm_m4(glm::mat4& out, const gm::cmat4& in) {
//	out[0][0] = in[0];   out[0][1] = in[1];   out[0][2] = in[2];   out[0][3] = in[3]; 
//	out[1][0] = in[4];   out[1][1] = in[5];   out[1][2] = in[6];   out[1][3] = in[7];
//	out[2][0] = in[8];   out[2][1] = in[9];   out[2][2] = in[10];  out[2][3] = in[11];
//	out[3][0] = in[12];  out[3][1] = in[13];  out[3][2] = in[14];  out[3][3] = in[15];
//}

inline void copy_vs_d9c4(D3DXCOLOR& out, const gm::color4& in) {
	out.r = in.r; out.g = in.g; out.b = in.b; out.a = in.a;
}
#endif

#if 1

template<class T>
inline void set_zero_vs(T& out) {
	int count = sizeof(T)/sizeof(float);
	for_range (i, 0, count) {
		out[i] = 0;
	}
	//printfln("count: %d", count);
}

inline void set_zero_vs_d9c4(D3DXCOLOR& out) {
	out = {0.0, 0.0, 0.0, 0.0};
}

inline void check_cond_print(bool cond) {
	if (cond) {
		printfln("equal");
	} else {
		printfln("[* NOTEQUAL *]");
	}
}


template<class T, class U>
inline void check(const char* other_name, const char* fname, T a, U b) {
	println("gm_::{}: {}", fname, str(a));
	println("{}::{}: {}", other_name, fname, str(b));
	check_cond_print(chk_equals(a, b));
	print_sep_m();
}
template<class T, class U>
inline void check_d9(const char* fname, T a, U b) {
	check("d9_", fname, a, b);
}
template<class T, class U>
inline void check_glm(const char* fname, T a, U b) {
	check("glm", fname, a, b);
}

inline void check_d9c4(const char* fname, gm::color4 a, D3DXCOLOR b) {
	println("gm_::{}: {}", fname, str(a));
	println("d9_::{}: {}", fname, str(b));
	check_cond_print(chk_equals_d9c4(a, b));
	print_sep_m();
}

//inline void chk_glm_m4(const char* fname, gm::cmat4 a, glm::mat4 b) {
inline void chk_glm_m4(const char* fname, gm::mat4 a, glm::mat4 b) {
	println("gm_::{}: {}", fname, str(a));
	println("glm::{}: {}", fname, str(b));
	check_cond_print(chk_equals_glm_m4(a, b));
	print_sep_m();
}

inline void check_bool(const char* nm1, const char* nm2, const char* fname, bool b1, bool b2, bool b3, bool b4) {
	println("{}::{}: {}, {}", nm1, fname, b1, b2);
	println("{}::{}: {}, {}", nm2, fname, b3, b4);
	check_cond_print((b1 == b3) && (b2 == b4));
	print_sep_m();
}
inline void check_bool_d9(const char* fname, bool b1, bool b2, bool b3, bool b4) {
	check_bool("gm_", "d9_", fname, b1, b2, b3, b4);
}

template<class T>
inline void check_rv(const char* nm1, const char* nm2, const char* fname, T f1, T f2) {
	println("{}::{}: {}", nm1, fname, f1);
	println("{}::{}: {}", nm2, fname, f2);
	check_cond_print(f1 == f2);
	print_sep_m();
}
template<class T>
inline void check_rv_d9(const char* fname, T f1, T f2) {
	check_rv("gm_", "d9_", fname, f1, f2);
}
#endif
//-------------



void check_math_func() {
	printfln("");
	printfln("----------------");
	printfln("check_d3dx9_math");
	printfln("----------------");

	float gsa = 2.5;
	float gsb = 3.2;
	float gsc = 4.7;
	float gsca = 0.3;

	float g_angle = 0.872665; //50 deg

	float fovy = 50.0;
	float aspect = 16.0/9.0;
	float zn = 4.0;
	float zf = 98.0;

	float w = 320.0f; float h = 240.0f;
	float l = 10.0f; float t = 50.0f; float b = 270.0f; float r = 350.0f;

	uint argb_color_a = 16121850; //rgb(245,255,250)

	gm::vec2 gv2a(1, 2);
	gm::vec2 gv2b(3, 5);	
	gm::vec2 gv2c(4, 8);	
	gm::vec2 gv2d(5, 7);	
	
	gm::vec3 gv3a(1, 2, 3);
	gm::vec3 gv3b(3, 5, 7);	
	gm::vec3 gv3c(4, 8, 2);	
	gm::vec3 gv3d(5, 7, 8);

	gm::vec4 gv4a(1, 2, 3, 4);
	gm::vec4 gv4b(3, 5, 7, 9);	
	gm::vec4 gv4c(4, 8, 2, 3);	
	gm::vec4 gv4d(5, 7, 8, 6);

	gm::color4 gc4a(0.1, 0.2, 0.3, 1.0);
	gm::color4 gc4b(0.3, 0.5, 0.7, 1.0);	

	gm::quat gq4a(1, 2, 3, 4);
	gm::quat gq4b(3, 5, 7, 9);	
	gm::quat gq4c(5, 9, 3, 2);
	gm::quat gq4d(7, 5, 6, 7);	

	gm::plane gp4a(1, 2, 3, 4);
	gm::plane gp4b(3, 5, 7, 9);	


	gm::mat4 gm4a(4, 3, 5, 6, 2, 4, 6, 8, 9, 7, 8, 7, 3, 6, 5, 9);
	gm::mat4 gm4b(2, 5, 7, 6, 3, 9, 4, 2, 5, 9, 3, 8, 4, 2, 3, 6);
	gm::mat4 gm4c(9, 6, 2, 4, 2, 3, 8, 4, 7, 3, 6, 9, 5, 4, 2, 5);
	
	gm::mat3 gm3a(4, 3, 5, 6, 2, 4, 6, 8, 9);

	D3DXVECTOR2 d9v2a; 
	copy_vs(d9v2a, gv2a);
	D3DXVECTOR2 d9v2b;
	copy_vs(d9v2b, gv2b);
	D3DXVECTOR2 d9v2c;
	copy_vs(d9v2c, gv2c);
	D3DXVECTOR2 d9v2d;
	copy_vs(d9v2d, gv2d);

	D3DXVECTOR3 d9v3a; 
	copy_vs(d9v3a, gv3a);
	D3DXVECTOR3 d9v3b;
	copy_vs(d9v3b, gv3b);
	D3DXVECTOR3 d9v3c;
	copy_vs(d9v3c, gv3c);
	D3DXVECTOR3 d9v3d;
	copy_vs(d9v3d, gv3d);

	D3DXVECTOR4 d9v4a; 
	copy_vs(d9v4a, gv4a);
	D3DXVECTOR4 d9v4b;
	copy_vs(d9v4b, gv4b);
	D3DXVECTOR4 d9v4c;
	copy_vs(d9v4c, gv4c);
	D3DXVECTOR4 d9v4d;
	copy_vs(d9v4d, gv4d);

	D3DXCOLOR d9c4a; 
	copy_vs_d9c4(d9c4a, gc4a);
	D3DXCOLOR d9c4b;
	copy_vs_d9c4(d9c4b, gc4b);

	D3DXVECTOR2 d9v2_o1(0, 0);
	D3DXVECTOR3 d9v3_o1(0, 0, 0);
	D3DXVECTOR4 d9v4_o1(0, 0, 0, 0);

	D3DXCOLOR d9c4_o1(0, 0, 0, 0);
	D3DXQUATERNION d9q4_o1(0, 0, 0, 0);
	D3DXPLANE d9p4_o1(0, 0, 0, 0);
	D3DXMATRIX d9m4_o1(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	D3DXQUATERNION d9q4a;
	copy_vs(d9q4a, gq4a);
	D3DXQUATERNION d9q4b;
	copy_vs(d9q4b, gq4b);
	D3DXQUATERNION d9q4c;
	copy_vs(d9q4c, gq4c);
	D3DXQUATERNION d9q4d;
	copy_vs(d9q4d, gq4d);

	D3DXPLANE d9p4a;
	copy_vs(d9p4a, gp4a);
	D3DXPLANE d9p4b;
	copy_vs(d9p4b, gp4b);

	D3DXMATRIX d9m4a;
	copy_vs(d9m4a, gm4a);
	D3DXMATRIX d9m4b;
	copy_vs(d9m4b, gm4b);
	D3DXMATRIX d9m4c;
	copy_vs(d9m4c, gm4c);
	float d9_det = 0.0f;

	gm::viewport gvwpt(10, 50, 320, 240, 1.1, 98.9);
	D3DVIEWPORT9 d9vwpt(gvwpt.x, gvwpt.y, gvwpt.w, gvwpt.h, gvwpt.zn, gvwpt.zf);

	// D3DXQuaternionToAxisAngle
	gm::quat gq4_uqa(4, 2, 3, 0.76);
	gm::quat gq4_uqb(8, 5, 2, 0.34);
	D3DXQUATERNION d9q4_uqa;
	copy_vs(d9q4_uqa, gq4_uqa);
	D3DXQUATERNION d9q4_uqb;
	copy_vs(d9q4_uqb, gq4_uqb);
	float gf_qaa, d9_qaa;
	gm::vec3 gv3_qaa;
	D3DXVECTOR3 d9v3_qaa;

	//VEC2
#if 0
	//--------------------------
	// 2D Vector
	//--------------------------

	
	check_d9("vec2 -u", -gv2a, -d9v2a);
	check_d9("vec2 +", gv2a + gv2b, d9v2a + d9v2b);
	check_d9("vec2 -", gv2a - gv2b, d9v2a - d9v2b);

	println("gm::vec2 *: {}", str(gv2a * gv2b));
	print_sep_m();
	println("gm::vec2 /: {}", str(gv2a / gv2b));
	print_sep_m();

	println("gm::vec2 +s: {}", str(gv2a + gsa));
	print_sep_m();
	println("gm::vec2 -s: {}", str(gv2a - gsa));
	print_sep_m();

	check_d9("vec2 *s",gv2a * gsa, d9v2a * gsa);
	check_d9("vec2 /s",gv2a / gsa, d9v2a / gsa);

	check_bool_d9("vec2 ==", gv2a == gv2b, gv2a == gv2a, d9v2a == d9v2b, d9v2a == d9v2a);
	check_bool_d9("vec2 !=", gv2a != gv2b, gv2a != gv2a, d9v2a != d9v2b, d9v2a != d9v2a);


	check_rv_d9("D3DXVec2Length", gm::vec2_length(gv2a), D3DXVec2Length(&d9v2a));
	check_rv_d9("D3DXVec2LengthSq", gm::vec2_length_sq(gv2a), D3DXVec2LengthSq(&d9v2a));
	check_rv_d9("D3DXVec2Dot", gm::vec2_dot(gv2a, gv2b), D3DXVec2Dot(&d9v2a, &d9v2b));
	check_rv_d9("D3DXVec2CCW", gm::vec2_ccw(gv2a, gv2b), D3DXVec2CCW(&d9v2a, &d9v2b));
	set_zero_vs(d9v2_o1);
	check_d9("D3DXVec2Minimize", gm::vec2_min(gv2a, gv2b), (*D3DXVec2Minimize(&d9v2_o1, &d9v2a, &d9v2b)));
	set_zero_vs(d9v2_o1);
	check_d9("D3DXVec2Maximize", gm::vec2_max(gv2a, gv2b), (*D3DXVec2Maximize(&d9v2_o1, &d9v2a, &d9v2b)));
	set_zero_vs(d9v2_o1);
	check_d9("D3DXVec2Scale", gm::vec2_scale(gv2a, gsa), (*D3DXVec2Scale(&d9v2_o1, &d9v2a, gsa)));
	set_zero_vs(d9v2_o1);
	check_d9("D3DXVec2Lerp", gm::vec2_lerp(gv2a, gv2b, gsa), (*D3DXVec2Lerp(&d9v2_o1, &d9v2a, &d9v2b, gsa)));

	set_zero_vs(d9v2_o1);
	check_d9("D3DXVec2Normalize", gm::vec2_normalize(gv2a) ,(*D3DXVec2Normalize(&d9v2_o1, &d9v2a)));
	set_zero_vs(d9v2_o1);
	check_d9("D3DXVec2Hermite", gm::vec2_hermite(gv2a, gv2c, gv2b, gv2d, gsa), (*D3DXVec2Hermite(&d9v2_o1, &d9v2a, &d9v2c,  &d9v2b, &d9v2d, gsa)));
	set_zero_vs(d9v2_o1);
	check_d9("D3DXVec2CatmullRom", gm::vec2_catmull_rom(gv2a, gv2b, gv2c, gv2d, gsa), (*D3DXVec2CatmullRom(&d9v2_o1, &d9v2a, &d9v2b, &d9v2c, &d9v2d, gsa)));
	set_zero_vs(d9v2_o1);
	check_d9("D3DXVec2BaryCentric", gm::vec2_bary_centric(gv2a, gv2b, gv2c, gsa, gsb), (*D3DXVec2BaryCentric(&d9v2_o1, &d9v2a, &d9v2b, &d9v2c, gsa, gsb)));

	set_zero_vs(d9v4_o1);
	check_d9("D3DXVec2Transform", gm::vec4_transform_pos2(gv2a, gm4a), (*D3DXVec2Transform(&d9v4_o1, &d9v2a, &d9m4a)));
	set_zero_vs(d9v2_o1);
	check_d9("D3DXVec2TransformCoord", gm::vec2_transform_coord(gv2a, gm4a), (*D3DXVec2TransformCoord(&d9v2_o1, &d9v2a, &d9m4a)));
	set_zero_vs(d9v2_o1);
	check_d9("D3DXVec2TransformNormal", gm::vec2_transform_normal(gv2a, gm4a), (*D3DXVec2TransformNormal(&d9v2_o1, &d9v2a, &d9m4a)));
#endif
	

	//VEC3
#if 0
	//--------------------------
	// 3D Vector
	//--------------------------

	check_d9("vec3 -u", -gv3a, -d9v3a);
	check_d9("vec3 +", gv3a + gv3b, d9v3a + d9v3b);
	check_d9("vec3 -", gv3a - gv3b, d9v3a - d9v3b);

	println("gm::vec3 *: {}", str(gv3a * gv3b));
	print_sep_m();
	println("gm::vec3 /: {}", str(gv3a / gv3b));
	print_sep_m();

	println("gm::vec3 +s: {}", str(gv3a + gsa));
	print_sep_m();
	println("gm::vec3 -s: {}", str(gv3a - gsa));
	print_sep_m();

	check_d9("vec3 *s",gv3a * gsa, d9v3a * gsa);
	check_d9("vec3 /s",gv3a / gsa, d9v3a / gsa);

	check_bool_d9("vec3 ==", gv3a == gv3b, gv3a == gv3a, d9v3a == d9v3b, d9v3a == d9v3a);
	check_bool_d9("vec3 !=", gv3a != gv3b, gv3a != gv3a, d9v3a != d9v3b, d9v3a != d9v3a);


	check_rv_d9("D3DXVec3Length", gm::vec3_length(gv3a), D3DXVec3Length(&d9v3a));
	check_rv_d9("D3DXVec3LengthSq", gm::vec3_length_sq(gv3a), D3DXVec3LengthSq(&d9v3a));
	check_rv_d9("D3DXVec3Dot", gm::vec3_dot(gv3a, gv3b), D3DXVec3Dot(&d9v3a, &d9v3b));
	set_zero_vs(d9v3_o1);
	check_d9("D3DXVec3Cross", gm::vec3_cross(gv3a, gv3b), (*D3DXVec3Cross(&d9v3_o1, &d9v3a, &d9v3b)));
	set_zero_vs(d9v3_o1);
	check_d9("D3DXVec3Minimize", gm::vec3_min(gv3a, gv3b), (*D3DXVec3Minimize(&d9v3_o1, &d9v3a, &d9v3b)));
	set_zero_vs(d9v3_o1);
	check_d9("D3DXVec3Maximize", gm::vec3_max(gv3a, gv3b), (*D3DXVec3Maximize(&d9v3_o1, &d9v3a, &d9v3b)));
	set_zero_vs(d9v3_o1);
	check_d9("D3DXVec3Scale", gm::vec3_scale(gv3a, gsa), (*D3DXVec3Scale(&d9v3_o1, &d9v3a, gsa)));
	set_zero_vs(d9v3_o1);
	check_d9("D3DXVec3Lerp", gm::vec3_lerp(gv3a, gv3b, gsa), (*D3DXVec3Lerp(&d9v3_o1, &d9v3a, &d9v3b, gsa)));

	set_zero_vs(d9v3_o1);
	check_d9("D3DXVec3Normalize", gm::vec3_normalize(gv3a) ,(*D3DXVec3Normalize(&d9v3_o1, &d9v3a)));
	set_zero_vs(d9v3_o1);
	check_d9("D3DXVec3Hermite", gm::vec3_hermite(gv3a, gv3c, gv3b, gv3d, gsa), (*D3DXVec3Hermite(&d9v3_o1, &d9v3a, &d9v3c,  &d9v3b, &d9v3d, gsa)));
	set_zero_vs(d9v3_o1);
	check_d9("D3DXVec3CatmullRom", gm::vec3_catmull_rom(gv3a, gv3b, gv3c, gv3d, gsa), (*D3DXVec3CatmullRom(&d9v3_o1, &d9v3a, &d9v3b, &d9v3c, &d9v3d, gsa)));
	set_zero_vs(d9v3_o1);
	check_d9("D3DXVec3BaryCentric", gm::vec3_bary_centric(gv3a, gv3b, gv3c, gsa, gsb), (*D3DXVec3BaryCentric(&d9v3_o1, &d9v3a, &d9v3b, &d9v3c, gsa, gsb)));

	set_zero_vs(d9v4_o1);
	check_d9("D3DXVec3Transform", gm::vec4_transform_pos3(gv3a, gm4a), (*D3DXVec3Transform(&d9v4_o1, &d9v3a, &d9m4a)));
	set_zero_vs(d9v3_o1);
	check_d9("D3DXVec3TransformCoord", gm::vec3_transform_coord(gv3a, gm4a), (*D3DXVec3TransformCoord(&d9v3_o1, &d9v3a, &d9m4a)));
	set_zero_vs(d9v3_o1);
	check_d9("D3DXVec3TransformNormal", gm::vec3_transform_normal(gv3a, gm4a), (*D3DXVec3TransformNormal(&d9v3_o1, &d9v3a, &d9m4a)));

	set_zero_vs(d9v3_o1);
	check_d9("D3DXVec3Project", gm::vec3_project(gv3a, gvwpt, gm4a, gm4b, gm4c), 
		(*D3DXVec3Project(&d9v3_o1, &d9v3a, &d9vwpt, &d9m4a, &d9m4b, &d9m4c)));
	set_zero_vs(d9v3_o1);
	check_d9("D3DXVec3Unproject", gm::vec3_unproject(gv3a, gvwpt, gm4a, gm4b, gm4c), 
		(*D3DXVec3Unproject(&d9v3_o1, &d9v3a, &d9vwpt, &d9m4a, &d9m4b, &d9m4c)));
#endif


	//VEC4
#if 0
	//--------------------------
	// 4D Vector
	//--------------------------

	check_d9("vec4 -u", -gv4a, -d9v4a);
	check_d9("vec4 +", gv4a + gv4b, d9v4a + d9v4b);
	check_d9("vec4 -", gv4a - gv4b, d9v4a - d9v4b);

	println("gm::vec4 *: {}", str(gv4a * gv4b));
	print_sep_m();
	println("gm::vec4 /: {}", str(gv4a / gv4b));
	print_sep_m();

	println("gm::vec4 +s: {}", str(gv4a + gsa));
	print_sep_m();
	println("gm::vec4 -s: {}", str(gv4a - gsa));
	print_sep_m();

	check_d9("vec4 *s",gv4a * gsa, d9v4a * gsa);
	check_d9("vec4 /s",gv4a / gsa, d9v4a / gsa);

	check_bool_d9("vec4 ==", gv4a == gv4b, gv4a == gv4a, d9v4a == d9v4b, d9v4a == d9v4a);
	check_bool_d9("vec4 !=", gv4a != gv4b, gv4a != gv4a, d9v4a != d9v4b, d9v4a != d9v4a);


	check_rv_d9("D3DXVec4Length", gm::vec4_length(gv4a), D3DXVec4Length(&d9v4a));
	check_rv_d9("D3DXVec4LengthSq", gm::vec4_length_sq(gv4a), D3DXVec4LengthSq(&d9v4a));
	check_rv_d9("D3DXVec4Dot", gm::vec4_dot(gv4a, gv4b), D3DXVec4Dot(&d9v4a, &d9v4b));
	set_zero_vs(d9v4_o1);
	check_d9("D3DXVec4Cross", gm::vec4_cross(gv4a, gv4b, gv4c), (*D3DXVec4Cross(&d9v4_o1, &d9v4a, &d9v4b, &d9v4c)));
	set_zero_vs(d9v4_o1);
	check_d9("D3DXVec4Minimize", gm::vec4_min(gv4a, gv4b), (*D3DXVec4Minimize(&d9v4_o1, &d9v4a, &d9v4b)));
	set_zero_vs(d9v4_o1);
	check_d9("D3DXVec4Maximize", gm::vec4_max(gv4a, gv4b), (*D3DXVec4Maximize(&d9v4_o1, &d9v4a, &d9v4b)));
	set_zero_vs(d9v4_o1);
	check_d9("D3DXVec4Scale", gm::vec4_scale(gv4a, gsa), (*D3DXVec4Scale(&d9v4_o1, &d9v4a, gsa)));
	set_zero_vs(d9v4_o1);
	check_d9("D3DXVec4Lerp", gm::vec4_lerp(gv4a, gv4b, gsa), (*D3DXVec4Lerp(&d9v4_o1, &d9v4a, &d9v4b, gsa)));

	set_zero_vs(d9v4_o1);
	check_d9("D3DXVec4Normalize", gm::vec4_normalize(gv4a) ,(*D3DXVec4Normalize(&d9v4_o1, &d9v4a)));
	set_zero_vs(d9v4_o1);
	check_d9("D3DXVec4Hermite", gm::vec4_hermite(gv4a, gv4c, gv4b, gv4d, gsa), (*D3DXVec4Hermite(&d9v4_o1, &d9v4a, &d9v4c,  &d9v4b, &d9v4d, gsa)));
	set_zero_vs(d9v4_o1);
	check_d9("D3DXVec4CatmullRom", gm::vec4_catmull_rom(gv4a, gv4b, gv4c, gv4d, gsa), (*D3DXVec4CatmullRom(&d9v4_o1, &d9v4a, &d9v4b, &d9v4c, &d9v4d, gsa)));
	set_zero_vs(d9v4_o1);
	check_d9("D3DXVec4BaryCentric", gm::vec4_bary_centric(gv4a, gv4b, gv4c, gsa, gsb), (*D3DXVec4BaryCentric(&d9v4_o1, &d9v4a, &d9v4b, &d9v4c, gsa, gsb)));

	set_zero_vs(d9v4_o1);
	check_d9("D3DXVec4Transform", gm::vec4_transform_pos4(gv4a, gm4a), (*D3DXVec4Transform(&d9v4_o1, &d9v4a, &d9m4a)));
#endif
	
	
	//MATRIX
#if 0
	//--------------------------
	// 4D Matrix
	//--------------------------

	check_d9("mat4 -u", -gm4a, -d9m4a);
	check_d9("mat4 +", gm4a + gm4b, d9m4a + d9m4b);
	check_d9("mat4 -", gm4a - gm4b, d9m4a - d9m4b);		

	println("gm::mat4 +s: {}", str(gm4a + gsa));
	print_sep_m();
	println("gm::mat4 -s: {}", str(gm4a - gsa));
	print_sep_m();

	check_d9("mat4 *s",gm4a * gsa, d9m4a * gsa);
	check_d9("mat4 /s",gm4a / gsa, d9m4a / gsa);

	check_bool_d9("mat4 ==", gm4a == gm4b, gm4a == gm4a, d9m4a == d9m4b, d9m4a == d9m4a);
	check_bool_d9("mat4 !=", gm4a != gm4b, gm4a != gm4a, d9m4a != d9m4b, d9m4a != d9m4a);


	println("gm::mat4 mul_cw: {}", str(gm::mat4_mul_cw(gm4a, gm4b)));
	print_sep_m();
	println("gm::mat4 div_cw: {}", str(gm::mat4_div_cw(gm4a, gm4b)));
	print_sep_m();
	
	check_d9("mat4 *", gm4a * gm4b, d9m4a * d9m4b);
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixMultiply", gm::mat4_mul(gm4a, gm4b), (*D3DXMatrixMultiply(&d9m4_o1, &d9m4a, &d9m4b)));	

	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixIdentity", gm::mat4::k_identity(), (*D3DXMatrixIdentity(&d9m4_o1)));
	check_rv_d9("D3DXMatrixIsIdentity", gm::mat4_is_identity(gm::mat4::k_identity()), scast<bool>(D3DXMatrixIsIdentity(&d9m4_o1)));


	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixTranspose", gm::mat4_transpose(gm4a), (*D3DXMatrixTranspose(&d9m4_o1, &d9m4a)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixMultiplyTranspose", gm::mat4_mul_transpose(gm4a, gm4b), (*D3DXMatrixMultiplyTranspose(&d9m4_o1, &d9m4a, &d9m4b)));
	

	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixScaling", gm::mat4_scaling(gv3a), (*D3DXMatrixScaling(&d9m4_o1, d9v3a.x, d9v3a.y, d9v3a.z)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixTranslation", gm::mat4_translation(gv3a), (*D3DXMatrixTranslation(&d9m4_o1, d9v3a.x, d9v3a.y, d9v3a.z)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixRotationX", gm::mat4_rotation_x(g_angle), (*D3DXMatrixRotationX(&d9m4_o1, g_angle)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixRotationY", gm::mat4_rotation_y(g_angle), (*D3DXMatrixRotationY(&d9m4_o1, g_angle)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixRotationZ", gm::mat4_rotation_z(g_angle), (*D3DXMatrixRotationZ(&d9m4_o1, g_angle)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixRotationAxis", gm::mat4_rotation_axis(gv3a, g_angle), (*D3DXMatrixRotationAxis(&d9m4_o1, &d9v3a, g_angle)));
#endif	

#if 0
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixLookAtRH", gm::mat4_look_at_rh(gv3a, gv3b, gv3c), (*D3DXMatrixLookAtRH(&d9m4_o1, &d9v3a, &d9v3b, &d9v3c)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixLookAtLH", gm::mat4_look_at_lh(gv3a, gv3b, gv3c), (*D3DXMatrixLookAtLH(&d9m4_o1, &d9v3a, &d9v3b, &d9v3c)));	

	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixPerspectiveFovRH", gm::mat4_perspective_fov_rh(fovy, aspect, zn, zf), 
		(*D3DXMatrixPerspectiveFovRH(&d9m4_o1, fovy, aspect, zn, zf)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixPerspectiveFovLH", gm::mat4_perspective_fov_lh(fovy, aspect, zn, zf), 
		(*D3DXMatrixPerspectiveFovLH(&d9m4_o1, fovy, aspect, zn, zf)));


	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixPerspectiveRH", gm::mat4_perspective_rh(w, h, zn, zf), 
		(*D3DXMatrixPerspectiveRH(&d9m4_o1, w, h, zn, zf)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixPerspectiveLH", gm::mat4_perspective_lh(w, h, zn, zf), 
		(*D3DXMatrixPerspectiveLH(&d9m4_o1, w, h, zn, zf)));
	
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixPerspectiveOffCenterRH", gm::mat4_perspective_offcenter_rh(l, r, b, t, zn, zf), 
		(*D3DXMatrixPerspectiveOffCenterRH(&d9m4_o1, l, r, b, t, zn, zf)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixPerspectiveOffCenterLH", gm::mat4_perspective_offcenter_lh(l, r, b, t, zn, zf), 
		(*D3DXMatrixPerspectiveOffCenterLH(&d9m4_o1, l, r, b, t, zn, zf)));

	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixOrthoRH", gm::mat4_ortho_rh(w, h, zn, zf), 
		(*D3DXMatrixOrthoRH(&d9m4_o1, w, h, zn, zf)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixOrthoLH", gm::mat4_ortho_lh(w, h, zn, zf), 
		(*D3DXMatrixOrthoLH(&d9m4_o1, w, h, zn, zf)));

	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixOrthoOffCenterRH", gm::mat4_ortho_offcenter_rh(l, r, b, t, zn, zf), 
		(*D3DXMatrixOrthoOffCenterRH(&d9m4_o1, l, r, b, t, zn, zf)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixOrthoOffCenterLH", gm::mat4_ortho_offcenter_lh(l, r, b, t, zn, zf), 
		(*D3DXMatrixOrthoOffCenterLH(&d9m4_o1, l, r, b, t, zn, zf)));

	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixShadow", gm::mat4_shadow(gv4a, gp4a), (*D3DXMatrixShadow(&d9m4_o1, &d9v4a, &d9p4a)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixReflect", gm::mat4_reflect(gp4a), (*D3DXMatrixReflect(&d9m4_o1, &d9p4a)));

	check_rv_d9("D3DXMatrixDeterminant", gm::mat4_determinant(gm4a), D3DXMatrixDeterminant(&d9m4a));
	set_zero_vs(d9m4_o1);	
	check_d9("D3DXMatrixInverse", gm::mat4_inverse(gm4a), (*D3DXMatrixInverse(&d9m4_o1, &d9_det, &d9m4a)));

	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixRotationQuaternion", gm::mat4_rotation_quat(gq4a), (*D3DXMatrixRotationQuaternion(&d9m4_o1, &d9q4a)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixRotationYawPitchRoll", gm::mat4_rotation_yaw_pitch_roll(gsa, gsb, gsc), (*D3DXMatrixRotationYawPitchRoll(&d9m4_o1, gsa, gsb, gsc)));

	// DIFFRENT RESULT
	//gm::vec3 gv3_s(0, 0, 0), gv3_t(0, 0, 0); gm::quat gq4_r(0, 0, 0, 0); 
	//gm::vec3 gv3_s2(0, 0, 0), gv3_t2(0, 0, 0); gm::quat gq4_r2(0, 0, 0, 0); 
	//D3DXVECTOR3 d9v3_s(0, 0, 0), d9v3_t(0, 0, 0); D3DXQUATERNION d9q4_r(0, 0, 0, 0); 
	//gm::mat4_decompose_d3dx9(gm4a, gv3_s, gq4_r, gv3_t);
	//D3DXMatrixDecompose(&d9v3_s, &d9q4_r, &d9v3_t, &d9m4a);
	//check_d9("gv3_s", gv3_s, d9v3_s);
	//check_d9("gq4_r", gq4_r, d9q4_r);
	//check_d9("gv3_t", gv3_t, d9v3_t);
	//gm::mat4_decompose_d3dx9_rc_2(gm4a, gv3_s2, gq4_r2, gv3_t2);
	//check_d9("gv3_s", gv3_s, gv3_s2);
	//check_d9("gq4_r", gq4_r, gq4_r2);
	//check_d9("gv3_t", gv3_t, gv3_t2);
#endif

	

#if 0
	// NOT EQUAL
	//set_zero_vs(d9m4_o1);
	//check_d9("D3DXMatrixTransformation", gm::mat4_transformation(gv3a, gq4a, gv3b, gv3c, gq4b, gv3d), 
	//	(*D3DXMatrixTransformation(&d9m4_o1, &d9v3a, &d9q4a, &d9v3b, &d9v3c, &d9q4b, &d9v3d)));

	// EQUAL
	//set_zero_vs(d9m4_o1);
	//check_d9("D3DXMatrixTransformation2D", gm::mat4_transformation_2d(gv2a, gsa, gv2b, gv2c, gsb, gv2d), 
	//	(*D3DXMatrixTransformation2D(&d9m4_o1, &d9v2a, gsa, &d9v2b, &d9v2c, gsb, &d9v2d)));
	//set_zero_vs(d9m4_o1);
	//check_d9("D3DXMatrixAffineTransformation", gm::mat4_affine_transformation(gsa, gv3a, gq4a, gv3b), 
	//	(*D3DXMatrixAffineTransformation(&d9m4_o1, gsa, &d9v3a, &d9q4a, &d9v3b)));
	//set_zero_vs(d9m4_o1);
	//check_d9("D3DXMatrixAffineTransformation2D", gm::mat4_affine_transformation_2d(gsa, gv2a, gsb, gv2b), 
	//	(*D3DXMatrixAffineTransformation2D(&d9m4_o1, gsa, &d9v2a, gsb, &d9v2b)));

	// NOT EQUAL
	//set_zero_vs(d9m4_o1);
	//check_d9("D3DXMatrixTransformation", gm::mat4_transformation_ptr(&gv3a, &gq4a, &gv3b, &gv3c, &gq4b, &gv3d), 
	//	(*D3DXMatrixTransformation(&d9m4_o1, &d9v3a, &d9q4a, &d9v3b, &d9v3c, &d9q4b, &d9v3d)));

	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixTransformation2D", gm::mat4_transformation_2d_ptr(&gv2a, gsa, &gv2b, &gv2c, gsb, &gv2d), 
		(*D3DXMatrixTransformation2D(&d9m4_o1, &d9v2a, gsa, &d9v2b, &d9v2c, gsb, &d9v2d)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixAffineTransformation", gm::mat4_affine_transformation_ptr(gsa, &gv3a, &gq4a, &gv3b), 
		(*D3DXMatrixAffineTransformation(&d9m4_o1, gsa, &d9v3a, &d9q4a, &d9v3b)));
	set_zero_vs(d9m4_o1);
	check_d9("D3DXMatrixAffineTransformation2D", gm::mat4_affine_transformation_2d_ptr(gsa, &gv2a, gsb, &gv2b), 
		(*D3DXMatrixAffineTransformation2D(&d9m4_o1, gsa, &d9v2a, gsb, &d9v2b)));

	//set_zero_vs(d9m4_o1);
	//check_d9("D3DXMatrixAffineTransformation", gm::mat4_affine_transformation_ptr_d3dx9_rc_2(gsa, &gv3a, &gq4a, &gv3b), 
	//	(*D3DXMatrixAffineTransformation(&d9m4_o1, gsa, &d9v3a, &d9q4a, &d9v3b)));
	//set_zero_vs(d9m4_o1);
	//check_d9("D3DXMatrixAffineTransformation2D", gm::mat4_affine_transformation_2d_ptr_d3dx9_rc_2(gsa, &gv2a, gsb, &gv2b), 
	//	(*D3DXMatrixAffineTransformation2D(&d9m4_o1, gsa, &d9v2a, gsb, &d9v2b)));
#endif		

	//QUAT
#if 0
	//--------------------------
	// Quaternion
	//--------------------------

	check_d9("quat -u", -gq4a, -d9q4a);
	check_d9("quat +", gq4a + gq4b, d9q4a + d9q4b);
	check_d9("quat -", gq4a - gq4b, d9q4a - d9q4b);
	check_d9("quat *", gq4a * gq4b, d9q4a * d9q4b);

	println("gm::quat +s: {}", str(gq4a + gsa));
	print_sep_m();
	println("gm::quat -s: {}", str(gq4a - gsa));
	print_sep_m();

	check_d9("quat *s",gq4a * gsa, d9q4a * gsa);
	check_d9("quat /s",gq4a / gsa, d9q4a / gsa);

	check_bool_d9("quat ==", gq4a == gq4b, gq4a == gq4a, d9q4a == d9q4b, d9q4a == d9q4a);
	check_bool_d9("quat !=", gq4a != gq4b, gq4a != gq4a, d9q4a != d9q4b, d9q4a != d9q4a);

	check_rv_d9("D3DXQuaternionLength", gm::quat_length(gq4a), D3DXQuaternionLength(&d9q4a));
	check_rv_d9("D3DXQuaternionLengthSq", gm::quat_length_sq(gq4a), D3DXQuaternionLengthSq(&d9q4a));	
	check_rv_d9("D3DXQuaternionDot", gm::quat_dot(gq4a, gq4b), D3DXQuaternionDot(&d9q4a, &d9q4b));

	set_zero_vs(d9q4_o1);
	check_d9("D3DXQuaternionIdentity", gm::quat::k_identity(), (*D3DXQuaternionIdentity(&d9q4_o1)));
	check_rv_d9("D3DXQuaternionIsIdentity", gm::quat_is_identity(gm::quat::k_identity()), scast<bool>(D3DXQuaternionIsIdentity(&d9q4_o1)));
	set_zero_vs(d9q4_o1);
	check_d9("D3DXQuaternionConjugate", gm::quat_conjugate(gq4a), (*D3DXQuaternionConjugate(&d9q4_o1, &d9q4a)));

	//---
	set_zero_vs(d9q4_o1);
	check_d9("D3DXQuaternionMultiply", gq4a * gq4b, (*D3DXQuaternionMultiply(&d9q4_o1, &d9q4a, &d9q4b)));
	set_zero_vs(d9q4_o1);
	check_d9("D3DXQuaternionNormalize", gm::quat_normalize(gq4a), (*D3DXQuaternionNormalize(&d9q4_o1, &d9q4a)));
	set_zero_vs(d9q4_o1);
	check_d9("D3DXQuaternionInverse", gm::quat_inverse(gq4a), (*D3DXQuaternionInverse(&d9q4_o1, &d9q4a)));

	gm::quat_to_axis_angle(gq4_uqa, gv3_qaa, gf_qaa);
	D3DXQuaternionToAxisAngle(&d9q4_uqa, &d9v3_qaa, &d9_qaa);
	check_rv_d9("D3DXQuaternionToAxisAngle: angle", gf_qaa, d9_qaa);
	check_d9("D3DXQuaternionToAxisAngle: axis", gv3_qaa, d9v3_qaa);

	set_zero_vs(d9q4_o1);
	check_d9("D3DXQuaternionRotationMatrix", gm::quat_rotation_mat4(gm4a), (*D3DXQuaternionRotationMatrix(&d9q4_o1, &d9m4a)));
	//set_zero_vs(d9q4_o1);
	//check_d9("D3DXQuaternionRotationMatrix wnm", gm::quat_rotation_mat4_wnm(gm4a), (*D3DXQuaternionRotationMatrix(&d9q4_o1, &d9m4a)));
	//set_zero_vs(d9q4_o1);
	//check_d9("quat_from_rotation_mat4_wnm 1 2", gm::quat_rotation_mat4_wnm(gm4a), gm::quat_rotation_mat4_wnm2(gm4a));

	set_zero_vs(d9q4_o1);
	check_d9("D3DXQuaternionSlerp", gm::quat_slerp(gq4_uqa, gq4_uqb, gsa), (*D3DXQuaternionSlerp(&d9q4_o1, &d9q4_uqa, &d9q4_uqb, gsa)));
	//set_zero_vs(d9q4_o1);
	//check_d9("D3DXQuaternionSlerp wnm", gm::quat_slerp_wnm(gq4_uqa, gq4_uqb, gsa), (*D3DXQuaternionSlerp(&d9q4_o1, &d9q4_uqa, &d9q4_uqb, gsa)));

	set_zero_vs(d9q4_o1);
	check_d9("D3DXQuaternionRotationAxis", gm::quat_from_rotation_axis(gv3a, gsa), (*D3DXQuaternionRotationAxis(&d9q4_o1, &d9v3a, gsa)));
	set_zero_vs(d9q4_o1);
	check_d9("D3DXQuaternionRotationYawPitchRoll", gm::quat_rotation_yaw_pitch_roll(gsa, gsb, gsc), (*D3DXQuaternionRotationYawPitchRoll(&d9q4_o1, gsa, gsb, gsc)));
	
	set_zero_vs(d9q4_o1);
	check_d9("D3DXQuaternionLn", gm::quat_ln(gq4a), (*D3DXQuaternionLn(&d9q4_o1, &d9q4a)));
	set_zero_vs(d9q4_o1);
	check_d9("D3DXQuaternionExp", gm::quat_exp(gq4a), (*D3DXQuaternionExp(&d9q4_o1, &d9q4a)));
	
	set_zero_vs(d9q4_o1);
	check_d9("D3DXQuaternionSquad", gm::quat_squad(gq4a, gq4b, gq4c, gq4d, gsa), (*D3DXQuaternionSquad(&d9q4_o1, &d9q4a, &d9q4b, &d9q4c, &d9q4d, gsa)));
	
	gm::quat gq4_aout, gq4_bout, gq4_cout;
	D3DXQUATERNION d9q4_aout, d9q4_bout, d9q4_cout;

	gm::quat_squad_setup(gq4_aout, gq4_bout, gq4_cout, gq4a, gq4b, gq4c, gq4d);
	D3DXQuaternionSquadSetup(&d9q4_aout, &d9q4_bout, &d9q4_cout, &d9q4a, &d9q4b, &d9q4c, &d9q4d);
	check_d9("D3DXQuaternionSquadSetup: aout", gq4_aout, d9q4_aout);
	check_d9("D3DXQuaternionSquadSetup: bout", gq4_bout, d9q4_bout);
	check_d9("D3DXQuaternionSquadSetup: cout", gq4_cout, d9q4_cout);

	
	set_zero_vs(d9q4_o1);
	check_d9("D3DXQuaternionBaryCentric", gm::quat_bary_centric(gq4a, gq4b, gq4c, gsa, gsb), (*D3DXQuaternionBaryCentric(&d9q4_o1, &d9q4a, &d9q4b, &d9q4c, gsa, gsb)));
#endif



	//PLANE
#if 0
	//--------------------------
	// Plane
	//--------------------------

	check_d9("plane -u", -gp4a, -d9p4a);

	println("gm::plane +s: {}", str(gp4a + gsa));
	print_sep_m();
	println("gm::plane -s: {}", str(gp4a - gsa));
	print_sep_m();

	check_d9("plane *s",gp4a * gsa, d9p4a * gsa);
	check_d9("plane /s",gp4a / gsa, d9p4a / gsa);

	check_bool_d9("plane ==", gp4a == gp4b, gp4a == gp4a, d9p4a == d9p4b, d9p4a == d9p4a);
	check_bool_d9("plane !=", gp4a != gp4b, gp4a != gp4a, d9p4a != d9p4b, d9p4a != d9p4a);	

	check_rv_d9("D3DXPlaneDot", gm::plane_dot_vec4(gp4a, gv4a), D3DXPlaneDot(&d9p4a, &d9v4a));
	check_rv_d9("D3DXPlaneDotCoord", gm::plane_dot_coord(gp4a, gv3a), D3DXPlaneDotCoord(&d9p4a, &d9v3a));
	check_rv_d9("D3DXPlaneDotNormal", gm::plane_dot_normal(gp4a, gv3a), D3DXPlaneDotNormal(&d9p4a, &d9v3a));

	set_zero_vs(d9p4_o1);
	check_d9("D3DXPlaneScale", gm::plane_scale(gp4a, gsa), (*D3DXPlaneScale(&d9p4_o1, &d9p4a, gsa)));
	set_zero_vs(d9p4_o1);
	check_d9("D3DXPlaneNormalize", gm::plane_normalize(gp4a), (*D3DXPlaneNormalize(&d9p4_o1, &d9p4a)));

	set_zero_vs(d9v3_o1);
	check_d9("D3DXPlaneIntersectLine", gm::plane_intersect_line(gp4a, gv3a, gv3b), (*D3DXPlaneIntersectLine(&d9v3_o1, &d9p4a, &d9v3a, &d9v3b)));
	set_zero_vs(d9p4_o1);
	check_d9("D3DXPlaneFromPointNormal", gm::plane_from_point_normal(gv3a, gv3b), (*D3DXPlaneFromPointNormal(&d9p4_o1, &d9v3a, &d9v3b)));
	set_zero_vs(d9p4_o1);
	check_d9("D3DXPlaneFromPoints", gm::plane_from_points(gv3a, gv3b, gv3c), (*D3DXPlaneFromPoints(&d9p4_o1, &d9v3a, &d9v3b, &d9v3c)));
	set_zero_vs(d9p4_o1);
	check_d9("D3DXPlaneTransform", gm::plane_transform_mat4_inverse_transposed(gp4a, gm4a), (*D3DXPlaneTransform(&d9p4_o1, &d9p4a, &d9m4a)));

#endif


	//COLOR
#if 0
	//--------------------------
	// Color
	//--------------------------

	check_d9c4("color4 -u", -gc4a, -d9c4a);
	check_d9c4("color4 +", gc4a + gc4b, d9c4a + d9c4b);
	check_d9c4("color4 -", gc4a - gc4b, d9c4a - d9c4b);

	println("gm::color4 +s: {}", str(gc4a + gsa));
	print_sep_m();
	println("gm::color4 -s: {}", str(gc4a - gsa));
	print_sep_m();

	check_d9c4("color4 *s",gc4a * gsa, d9c4a * gsa);
	check_d9c4("color4 /s",gc4a / gsa, d9c4a / gsa);

	check_bool_d9("color4 ==", gc4a == gc4b, gc4a == gc4a, d9c4a == d9c4b, d9c4a == d9c4a);
	check_bool_d9("color4 !=", gc4a != gc4b, gc4a != gc4a, d9c4a != d9c4b, d9c4a != d9c4a);


	check_d9c4("D3DX color4 from_argb", gm::color4_from_argb(argb_color_a), D3DXCOLOR(argb_color_a));
	check_rv_d9<uint>("D3DX color4 to_argb", gm::argb_from_color4_d3dx9(gc4a), (DWORD)d9c4a);
	set_zero_vs_d9c4(d9c4_o1);
	check_d9c4("D3DXColorNegative", gm::color4_negative(gc4a), (*D3DXColorNegative(&d9c4_o1, &d9c4a)));
	set_zero_vs_d9c4(d9c4_o1);
	check_d9c4("D3DXColorAdd", gc4a + gc4b, (*D3DXColorAdd(&d9c4_o1, &d9c4a, &d9c4b))); 
	set_zero_vs_d9c4(d9c4_o1);
	check_d9c4("D3DXColorSubtract", gc4a - gc4b, (*D3DXColorSubtract(&d9c4_o1, &d9c4a, &d9c4b)));  
	set_zero_vs_d9c4(d9c4_o1);
	check_d9c4("D3DXColorScale", gm::color4_scale(gc4a, gsca), (*D3DXColorScale(&d9c4_o1, &d9c4a, gsca)));
	set_zero_vs_d9c4(d9c4_o1);
	check_d9c4("D3DXColorModulate", gm::color4_modulate(gc4a, gc4b), (*D3DXColorModulate(&d9c4_o1, &d9c4a, &d9c4b)));   
	set_zero_vs_d9c4(d9c4_o1);
	check_d9c4("D3DXColorLerp", gm::color4_lerp(gc4a, gc4b, gsca), (*D3DXColorLerp(&d9c4_o1, &d9c4a, &d9c4b, gsca)));  
	set_zero_vs_d9c4(d9c4_o1);
	check_d9c4("D3DXColorAdjustSaturation", gm::color4_adjust_saturation(gc4a, gsca), (*D3DXColorAdjustSaturation(&d9c4_o1, &d9c4a, gsca)));
	set_zero_vs_d9c4(d9c4_o1);
	check_d9c4("D3DXColorAdjustContrast", gm::color4_adjust_contrast(gc4a, gsca), (*D3DXColorAdjustContrast(&d9c4_o1, &d9c4a, gsca)));
#endif

	//--------------------------
	// Misc
	//--------------------------
	//check_rv_d9("D3DXFresnelTerm", gm::fresnel_term(gsa, gsb), D3DXFresnelTerm(gsa, gsb));
  
	//-----------------

	//--------------------------
	// GLM Mat4
	//--------------------------
	printfln("----------------");
	printfln("check_glm_math");
	printfln("----------------");
	//glm::mat4 glm2m4a(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16); 
	//println("glm::mat4: {}", str(glm2m4a));
	//---

	glm::vec2 glm2v2a; 
	copy_vs(glm2v2a, gv2a);
	glm::vec2 glm2v2b;
	copy_vs(glm2v2b, gv2b);
	glm::vec2 glm2v2c;
	copy_vs(glm2v2c, gv2c);
	glm::vec2 glm2v2d;
	copy_vs(glm2v2d, gv2d);

	glm::vec3 glm2v3a; 
	copy_vs(glm2v3a, gv3a);
	glm::vec3 glm2v3b;
	copy_vs(glm2v3b, gv3b);
	glm::vec3 glm2v3c;
	copy_vs(glm2v3c, gv3c);
	glm::vec3 glm2v3d;
	copy_vs(glm2v3d, gv3d);

	glm::vec4 glm2v4a; 
	copy_vs(glm2v4a, gv4a);
	glm::vec4 glm2v4b;
	copy_vs(glm2v4b, gv4b);
	glm::vec4 glm2v4c;
	copy_vs(glm2v4c, gv4c);
	glm::vec4 glm2v4d;
	copy_vs(glm2v4d, gv4d);

	//color
	glm::vec4 glm2c4a; 
	copy_vs(glm2c4a, gc4a);
	glm::vec4 glm2c4b;
	copy_vs(glm2c4b, gc4b);

	glm::quat glm2q4a;
	copy_vs(glm2q4a, gq4a);
	glm::quat glm2q4b;
	copy_vs(glm2q4b, gq4b);

	glm::mat4 glm2m4a;		
	copy_vs_glm_m4(glm2m4a, gm4a);
	glm::mat4 glm2m4b;
	copy_vs_glm_m4(glm2m4b, gm4b);


	//----------------

#if 0
	// same order of matrices in memory for d3d & opengl but glm multiplies in reverse
	println("mat4 glm val: {}{}\n{}{}", str(gm4a), str(glm2m4a), str(gm4b), str(glm2m4b));
	print_sep_m();

	println("mat4_mul: {}", str(mat4_mul(gm4a, gm4b)));
	println("gm: ma*mb {}", str(gm4a * gm4b));
	print_sep_m();
	println("mat4_mul_gl: {}", str(mat4_mul_gl(gm4a, gm4b)));
	println("mat4_mul rev mb*ma: {}", str(gm4b * gm4a));
	println("glm_mat4_mul: {}", str(glm2m4a * glm2m4b));


	// v*m
	print_sep_m();
	println("vec4_mul_mat4 v*m: \n{}", str(gm::vec4_mul_mat4(gv4a, gm4a)));
	println("gm v*m: \n{}", str(gv4a * gm4a));
	print_sep_m();
	println("vec4_mul_mat4_gl v*m: \n{}", str(gm::vec4_mul_mat4_gl(gv4a, gm4a)));
	println("gm rev v*m: \n{}", str(gm4a * gv4a));
	println("glm_vec4_mul_mat4 v*m: \n{}", str(glm2v4a * glm2m4a));
	// m*v
	print_sep_m();
	println("mat4_mul_vec4 m*v: \n{}", str(gm::mat4_mul_vec4(gm4a, gv4a)));
	println("gm m*v: \n{}", str(gm4a * gv4a));
	print_sep_m();
	println("mat4_mul_vec4_gl m*v: \n{}", str(gm::mat4_mul_vec4_gl(gm4a, gv4a)));
	println("gm rev m*v: \n{}", str(gv4a * gm4a));
	println("glm_mat4_mul_vec4 m*v: \n{}", str(glm2m4a * glm2v4a));


#endif

	//================================================
	//println("mat3_transpose: \n{}\n{}", str(gm3a), str(gm::mat3_transpose(gm3a)));


}

//----------------------------------------------------
/*





*/