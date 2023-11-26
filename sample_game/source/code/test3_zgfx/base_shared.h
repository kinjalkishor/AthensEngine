#pragma once

//====================================================
// MEDIA PATHS
//====================================================
#define RS_SHADER_PATH(shader_name)			"../../../source/code/test3_zgfx/shaders/" shader_name
#define RS_MEDIA_PATH(sub_path)				"../../../source/code/test3_zgfx/media/" sub_path

#define RS_SHADER_PATH_VKTUT(shader_name)		"../../../source/code/test3_zgfx/shaders/vk_glfw/shaders_spirv/" shader_name
//#define RS_SHADER_PATH_VKTUT(shader_name)		"E:/nex/AthensEngine/AscentWars/source/code/test3_zglfw_s/a_shaders/vk/shaders_spirv/" shader_name
//E:\nex\AthensEngine\AscentWars\source\code\test3_zgfx\shaders\vk_glfw
//-------------------------------------

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>

#include <type_traits>
using int16 = signed short int;
using int64 = signed long long int;
using uint8 = unsigned char;
using uint16 = unsigned short int;
using uint = unsigned int;
using uint64 = unsigned long long int;

using ldouble = long double;

using isz = ptrdiff_t;
constexpr isz ISZ_MAX = PTRDIFF_MAX;
constexpr isz ISZ_MIN = PTRDIFF_MIN;

using byte = unsigned char;	

#define scast	static_cast
#define rcast	reinterpret_cast

#define for_range(v, start, end)	for (std::decay_t<decltype(end)> v(start); v < end; ++v)

namespace std::pmr {}
namespace sdr = std::pmr;

//------------------------------
template<class T> inline void com_release(T*& t) { if(t) { t->Release(); t = nullptr; } }

namespace sdf
{

template <class T, size_t N>
inline constexpr size_t size(const T (&)[N]) noexcept { return N; }
template <class T, ptrdiff_t N>
inline constexpr ptrdiff_t arr_cap(const T (&)[N]) noexcept { return N; }

template<class T>
inline void mem_copy(T* dest, const T* src, size_t count) { memcpy(dest, src, count*sizeof(T)); }

template<class T>
inline void vec_copy(T* dest, const T* src, isz count) { for (isz i=0; i<count; ++i) { dest[i] = src[i]; } }

template<class T>
inline T* ty_malloc(size_t count) { return static_cast<T*>(malloc(sizeof(T)*count)); }
inline void ty_free(void* ptr) { free(ptr); }

template<class T> inline isz size_bytes(isz count) { return (count * sizeof(T)); }	

inline constexpr float k_aspect_16_9 = 1.77777777777777777778;
inline float get_aspect_ratio(float width, float height) { 
    // return 1:1 if height is zero.
    //1:1-1.0, 4:3-1.33, 16:9-1.77, 21:9-2.33
    return (height < 0.0001f) ? 1.0f : (width/height); 
}
//----------
template <class T, ptrdiff_t N> inline constexpr ptrdiff_t strz_cap(const T (&)[N]) noexcept { return N-1; }

inline isz strfz_len(const char* src) { return strlen(src); }
inline isz strfz_len(const wchar_t* src) { return wcslen(src); }

inline isz strf_assign_mbs(wchar_t* dest, isz dest_capacity, const char* src, isz src_len) {
    isz copy_len = src_len;
    if (copy_len > dest_capacity) { copy_len = dest_capacity; }
	const int dest_size_with_null_char = dest_capacity+1;
	int result = MultiByteToWideChar(CP_UTF8, 0, src, src_len, dest, dest_size_with_null_char);
	dest[copy_len] = L'\0';
	return copy_len;
}
inline isz strf_assign_wcs(char* dest, isz dest_capacity, const wchar_t* src, isz src_len) {
    isz copy_len = src_len;
    if (copy_len > dest_capacity) { copy_len = dest_capacity; }
	const int dest_size_with_null_char = dest_capacity+1;
	int result = WideCharToMultiByte(CP_UTF8, 0, src, src_len, dest, dest_size_with_null_char, nullptr, nullptr);	
	dest[copy_len] = '\0';
	return copy_len;
}

template<class T>
inline isz strf_assign(T* dest, isz dest_capacity, const T* src, isz src_len) {
    isz copy_len = src_len;
    if (copy_len > dest_capacity) { copy_len = dest_capacity; }
    //sdf::mem_copy(&dest[0], &src[0], copy_len);
    memcpy(&dest[0], &src[0], sizeof(T)*copy_len);
    dest[copy_len] = '\0';
    return copy_len;
}

template<class T>
inline isz strf_append(T* dest, isz dest_len, isz dest_capacity, const T* src, isz src_len) {
    isz total_len = dest_len + src_len;
    if (total_len > dest_capacity) { total_len = dest_capacity; }
    isz append_len = total_len - dest_len;
    //sdf::mem_copy(&dest[dest_len], &src[0], append_len);
    memcpy(&dest[dest_len], &src[0], sizeof(T)*append_len);
    dest[total_len] = L'\0';
    return total_len;
}

inline bool strfz_equals(const char* str1, const char* str2) { return !(strcmp(str1, str2)); }
inline bool strfz_ci_equals(const char* str1, const char* str2) { return !(stricmp(str1, str2)); }

}

//====================================================

//====================================================

#define printfln(format, ...)		printf(format "\n", ##__VA_ARGS__)
#define eprintfln(format, ...)		printf(format "\n", ##__VA_ARGS__)

inline void check_assert(const char *file, int line, const char* func, const char *expression, const char *msg) {
	printf("ASSERT FAILED: (%s), in %s: [%s: Line(%d)]\n", expression, func, file, line);
}
#define fm_assert_m(expression, msg) \
do { if (!(expression)) { check_assert(__FILE__, __LINE__, __FUNCTION__, #expression, msg); } } while (0)
#define fm_assert(expression)	fm_assert_m(expression, "")
//-------------------
#include <format>

template <class... _Types>
_NODISCARD inline void print(const std::string_view _Fmt, const _Types&... _Args) {
	std::printf("%s", std::vformat(_Fmt, std::make_format_args(_Args...)).c_str());
}
template <class... _Types>
_NODISCARD inline void println(const std::string_view _Fmt, const _Types&... _Args) {
	std::printf("%s\n", std::vformat(_Fmt, std::make_format_args(_Args...)).c_str());
}
//-------------------

class std_console {
private:
	void* hconsole = nullptr;	
	const uint color_yellow = 6;

public:
	std_console() {}
	~std_console() { FreeConsole(); }

	bool create_window(const char* window_title, int xpos, int ypos, int width, int height) {
		if (!AllocConsole()) {
			MessageBoxW(nullptr, L"Couldn't create output console", L"Error", 0);
			return false; 
		}

		HWND console_window = GetConsoleWindow();
		MoveWindow(console_window, xpos, ypos, width, height, TRUE);

		wchar_t wconsole_title[256] = {};
		sdf::strf_assign_mbs(wconsole_title, sdf::strz_cap(wconsole_title), window_title, sdf::strfz_len(window_title));
		SetWindowTextW(console_window, wconsole_title);	

		// The freopen_s function closes the file currently associated with stream and reassigns stream to the file specified by path.
		freopen("conin$", "r", stdin);
		freopen("conout$", "w", stdout);
		freopen("conout$", "w", stderr);

		hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hconsole, color_yellow);
		return true;
	}

};

#include <thread>
#include <chrono>
inline void sys_sleep(uint dwMilliseconds) {
	//Sleep(dwMilliseconds);
	std::this_thread::sleep_for(std::chrono::milliseconds(dwMilliseconds));	
}

#define fm_msg_box_ok_w(msg)	MessageBoxW(nullptr, msg, L"Error", MB_OK)

inline void sys_win_title_append(HWND hwnd, const char* text) {
	isz text_len = sdf::strfz_len(text);

	wchar_t wnd_text[256] = {};
	//nMaxCount: maximum number of characters to copy to the buffer, including the null character.
	int wnd_text_len = GetWindowTextW(hwnd, wnd_text, sdf::arr_cap(wnd_text));
	//wprintfln(L"%s: %d", prev_wnd_text, wnd_text_len);

	wchar_t wtitle[256] = {};
	isz wtitle_len = sdf::strf_assign(wtitle, sdf::strz_cap(wtitle), wnd_text, wnd_text_len);
	wchar_t wtext_to_add[256] = {};
	isz wtext_to_add_len = 0;
	wtext_to_add_len = sdf::strf_assign_mbs(wtext_to_add, sdf::strz_cap(wtext_to_add), text, text_len);
	wtitle_len = sdf::strf_append(wtitle, wtitle_len, sdf::strz_cap(wtitle), wtext_to_add, wtext_to_add_len);
	SetWindowTextW(hwnd, wtitle);
}

inline bool is_file_exists(const char* filename) {
    if (FILE *file = fopen(filename, "r")) {
		fclose(file);
		return true;
    } else {
        return false;
    }   
}

inline bool get_filename_ext(char* result, const char* filename) {
	// Get pointer to last '.' by reverse search
	const char* dot = strrchr(filename, '.');
	// if dot is nullptr or at location start pointed by filename, no extension found.
	if(!dot || dot == filename) { 
		strcpy(result, ""); 
		return false;
	}
	// Get extension by getting pointer to last '.' + 1 location and copying that substring
	strcpy(result, dot + 1);
	return true;
}


//------------------------------
inline constexpr int MAX_PATH_OS = 260;
inline constexpr int MAX_STR_PATH_OS = 259;    //260;

class game_timer_qpc {
public:

	float period() {
		int64 cnts_per_sec = 0;
		QueryPerformanceFrequency((LARGE_INTEGER*)&cnts_per_sec);
		// secs_per_cnt_qpc is 0.0000001f, 1e-07;
		float secs_per_cnt_qpc = 1.0f / scast<float>(cnts_per_sec);
		//println("{}", secs_per_cnt_qpc);
		return secs_per_cnt_qpc;
	}

	int64 get_time() {
		// Retrieves the current value of the performance counter, 
		// which is a high resolution (<1 micro second) time stamp.
		int64 prev_time_qpc = 0;
		QueryPerformanceCounter((LARGE_INTEGER*)&prev_time_qpc);
		return prev_time_qpc;
	}
};


namespace mathdef
{
inline constexpr double GM_PI				= 3.14159265358979323846; // pi - 3.1415926535897932384626433832795;

inline constexpr double GM_DEG_TO_RAD		= 0.017453292519943295769;	    // pi/180 - 0.01745329251994329576923690768489;
inline constexpr double GM_RAD_TO_DEG		= 57.295779513082320876846;     // 180/pi - 57.295779513082320876798154814105;
}
namespace mf 
{
template<class T>
inline constexpr T k_pi = scast<T>(mathdef::GM_PI);

template<class T>
inline T deg_to_rad(T a) {	
	//return (a * (k_pi / scast<T>(180)));
    return (a * scast<T>(mathdef::GM_DEG_TO_RAD));
}

template<class T>
inline T rad_to_deg(T a) {	
	//return (a * (scast<T>(180) / k_pi));
	return (a * scast<T>(mathdef::GM_RAD_TO_DEG));
}

template<class T>
inline T square(const T a) {
	return (a*a);
}

inline float yfov_from_xfov(float xfov, float aspect) {
    return (scast<float>(2) * atan(tan(xfov * float(0.5)) / aspect));
}
}
//=============================================
namespace gm 
{


class vec3 {
public:
	union {
		struct { float x, y, z; };
		float e[3];
    };	

	vec3() = default;
	vec3(float x, float y, float z) : x(x), y(y), z(z) {}
    explicit vec3(float f) : x(f), y(f), z(f) {}

	constexpr static int size() { return 3; }	

	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }

	const static vec3 k_zero() { return vec3(0); }
};

class vec4 {
public:
	union {
		struct { float x, y, z, w; };
		float e[4];
    };	

	vec4() = default;
	vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
    explicit vec4(float f) : x(f), y(f), z(f), w(f) {}

	constexpr static int size() { return 4; }	

	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }

	const static vec4 k_zero() { return vec4(0); }
};

class color4 {
public:
	union {
		struct { float r, g, b, a; };
		float e[4];
		vec4 v;
    };	

	color4() = default;
	color4(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
    explicit color4(float f) : r(f), g(f), b(f), a(f) {}
	//color4(float r, float g, float b) : r(r), g(g), b(b), a(1.0) {}
	explicit color4(vec4 a) : v(a) {}

	constexpr static int size() { return 4; }	

	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }

	const static color4 k_zero() { return color4(0); }	
};

class mat4 {
public:
	union {
		float e[16];
		float r[4][4];
	};

	mat4() = default;
	
	mat4(float m11, float m12, float m13, float m14,
		 float m21, float m22, float m23, float m24,
		 float m31, float m32, float m33, float m34,
		 float m41, float m42, float m43, float m44)
    : e{ m11, m12, m13, m14,
		 m21, m22, m23, m24,
		 m31, m32, m33, m34,
		 m41, m42, m43, m44 } {}

    explicit mat4(float f)
    : e{ f, 0, 0, 0,		
		 0, f, 0, 0,		
		 0, 0, f, 0,		
		 0, 0, 0, f } {}

	constexpr static int size() { return 16; }	
	constexpr int dim() const	{ return 4; }	
	
	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }

	const static mat4 k_zero() { return mat4(0); }
	const static mat4 k_identity() { return mat4(1); }	
};

//--------------------------------
template<class T> inline T vecnt_sub(const T& a, const T& b) { T out = T::k_zero(); for_range (i, 0, T::size()) { out[i] = a[i] - b[i]; } return out; }

template<class T> inline float vecnt_dot(const T& a, const T& b) {
	//a.x*b.x + a.y*b.y + a.z*b.z
	float out = scast<float>(0.0); for_range (i, 0, a.size()) { out += a[i] * b[i]; } return out;
}

template<class T> inline float vecnt_length_sq(const T& a) {
	//(square(a.x) + square(a.y) + square(a.z));
	//a.x*a.x + a.y*a.y + a.z*a.z	
	//dot(a, a);
	float out = scast<float>(0.0); for_range (i, 0, a.size()) { out += mf::square(a[i]); } return out;
}
// vector length, magnitude
template<class T> inline float vecnt_length(const T& a) { return sqrt(vecnt_length_sq(a));  }

template<class T> inline T vecnt_normalize(const T& a) {
    //a / length(a);
    T out = T::k_zero(); 
	float length = vecnt_length(a);

	if (length) {
		float inv_length = scast<float>(1.0)/length;
		//out = a * inv_length;	
		for_range (i, 0, T::size()) { out[i] = a[i] * inv_length; }
	} else {
		// out is already zero. If out is used error will propogate
		//out = T::k_zero();	
        printf("Cannot normalize zero length vector. Zero vector returned. Error will propogate.\n");			
	}
		
    return out;
	//return length;
}
//--------------------------------

inline vec3 operator - (const vec3& a, const vec3& b) { return vecnt_sub(a, b); }
inline float vec3_dot(const vec3& a, const vec3& b) { return vecnt_dot(a, b); }
inline vec3 vec3_normalize(const vec3& a) { return vecnt_normalize(a); }

inline vec3 vec3_cross(const vec3& a, const vec3& b) {
	vec3 out = vec3::k_zero();
	out.x = a.y*b.z - a.z*b.y;
	out.y = a.z*b.x - a.x*b.z;
	out.z = a.x*b.y - a.y*b.x;
	return out;
}


inline uint ftouc(float x) {
	return (x >= 1.0f ? UCHAR_MAX : x <= 0.0f ? 0x00 : (uint) (x * 255.0f));
}
inline uint packf_u32(float a, float b, float c, float d) {
	return ((ftouc(a) << 24) | (ftouc(b) << 16) | (ftouc(c) << 8) | (ftouc(d)));
}
inline uint argb_from_color4(const color4& a) {
	return packf_u32(a.a, a.r, a.g ,a.b);
}


// Multiplying in forward order like d3d
// for row order matrix storage
// The result represents the transformation B followed by the transformation A. (result = A * B)
// T(R(S(v))) = v*S*R*T = v*SRT
inline mat4 mat4_mul(const mat4& ma, const mat4& mb) {	
	return mat4(
		ma.r[0][0]*mb.r[0][0] + ma.r[0][1]*mb.r[1][0] + ma.r[0][2]*mb.r[2][0] + ma.r[0][3]*mb.r[3][0],
        ma.r[0][0]*mb.r[0][1] + ma.r[0][1]*mb.r[1][1] + ma.r[0][2]*mb.r[2][1] + ma.r[0][3]*mb.r[3][1],
        ma.r[0][0]*mb.r[0][2] + ma.r[0][1]*mb.r[1][2] + ma.r[0][2]*mb.r[2][2] + ma.r[0][3]*mb.r[3][2],
        ma.r[0][0]*mb.r[0][3] + ma.r[0][1]*mb.r[1][3] + ma.r[0][2]*mb.r[2][3] + ma.r[0][3]*mb.r[3][3],

        ma.r[1][0]*mb.r[0][0] + ma.r[1][1]*mb.r[1][0] + ma.r[1][2]*mb.r[2][0] + ma.r[1][3]*mb.r[3][0],
        ma.r[1][0]*mb.r[0][1] + ma.r[1][1]*mb.r[1][1] + ma.r[1][2]*mb.r[2][1] + ma.r[1][3]*mb.r[3][1],
        ma.r[1][0]*mb.r[0][2] + ma.r[1][1]*mb.r[1][2] + ma.r[1][2]*mb.r[2][2] + ma.r[1][3]*mb.r[3][2],
        ma.r[1][0]*mb.r[0][3] + ma.r[1][1]*mb.r[1][3] + ma.r[1][2]*mb.r[2][3] + ma.r[1][3]*mb.r[3][3],

        ma.r[2][0]*mb.r[0][0] + ma.r[2][1]*mb.r[1][0] + ma.r[2][2]*mb.r[2][0] + ma.r[2][3]*mb.r[3][0],
        ma.r[2][0]*mb.r[0][1] + ma.r[2][1]*mb.r[1][1] + ma.r[2][2]*mb.r[2][1] + ma.r[2][3]*mb.r[3][1],
        ma.r[2][0]*mb.r[0][2] + ma.r[2][1]*mb.r[1][2] + ma.r[2][2]*mb.r[2][2] + ma.r[2][3]*mb.r[3][2],
        ma.r[2][0]*mb.r[0][3] + ma.r[2][1]*mb.r[1][3] + ma.r[2][2]*mb.r[2][3] + ma.r[2][3]*mb.r[3][3],

        ma.r[3][0]*mb.r[0][0] + ma.r[3][1]*mb.r[1][0] + ma.r[3][2]*mb.r[2][0] + ma.r[3][3]*mb.r[3][0],
        ma.r[3][0]*mb.r[0][1] + ma.r[3][1]*mb.r[1][1] + ma.r[3][2]*mb.r[2][1] + ma.r[3][3]*mb.r[3][1],
        ma.r[3][0]*mb.r[0][2] + ma.r[3][1]*mb.r[1][2] + ma.r[3][2]*mb.r[2][2] + ma.r[3][3]*mb.r[3][2],
        ma.r[3][0]*mb.r[0][3] + ma.r[3][1]*mb.r[1][3] + ma.r[3][2]*mb.r[2][3] + ma.r[3][3]*mb.r[3][3]
	);
}

inline mat4 operator * (const mat4& ma, const mat4& mb) { return mat4_mul(ma, mb); }

// Only difference between D3D_Math row matrix math & gl/glm matrix (column notation in docs 
// but otherwise stored as row major d3d like) is reverse multiply of mat4*mat4, vec4*mat4.
// written in reverse order as b*a or T*v, but internally does a*b or v*T resulting in same values.
inline mat4 mat4_mul_gl(const mat4& ma, const mat4& mb) {	
	return mat4_mul(mb, ma);
}

inline vec4 vec4_mul_mat4(const vec4& va, const mat4& ma) {
	return vec4(
		va[0]*ma.r[0][0] + va[1]*ma.r[1][0] + va[2]*ma.r[2][0] + va[3]*ma.r[3][0],
        va[0]*ma.r[0][1] + va[1]*ma.r[1][1] + va[2]*ma.r[2][1] + va[3]*ma.r[3][1],
        va[0]*ma.r[0][2] + va[1]*ma.r[1][2] + va[2]*ma.r[2][2] + va[3]*ma.r[3][2],
        va[0]*ma.r[0][3] + va[1]*ma.r[1][3] + va[2]*ma.r[2][3] + va[3]*ma.r[3][3]
	);
}

inline vec4 mat4_mul_vec4(const mat4& ma, const vec4& va) {
	return vec4(
		 ma.r[0][0]*va[0] + ma.r[0][1]*va[1] + ma.r[0][2]*va[2] + ma.r[0][3]*va[3],
		 ma.r[1][0]*va[0] + ma.r[1][1]*va[1] + ma.r[1][2]*va[2] + ma.r[1][3]*va[3],
		 ma.r[2][0]*va[0] + ma.r[2][1]*va[1] + ma.r[2][2]*va[2] + ma.r[2][3]*va[3],
		 ma.r[3][0]*va[0] + ma.r[3][1]*va[1] + ma.r[3][2]*va[2] + ma.r[3][3]*va[3]
	);
}

inline vec4 operator * (const vec4& va, const mat4& ma) { return vec4_mul_mat4(va, ma); }
inline vec4 operator * (const mat4& ma, const vec4& va) { return mat4_mul_vec4(ma, va); }

inline vec4 vec4_mul_mat4_gl(const vec4& va, const mat4& ma) {
	return mat4_mul_vec4(ma, va);
}
inline vec4 mat4_mul_vec4_gl(const mat4& ma, const vec4& va) {
	return vec4_mul_mat4(va, ma);
}

inline mat4 mat4_transpose(const mat4& ma) {
	return mat4(
		ma.r[0][0], ma.r[1][0], ma.r[2][0], ma.r[3][0],
		ma.r[0][1], ma.r[1][1], ma.r[2][1], ma.r[3][1],
		ma.r[0][2], ma.r[1][2], ma.r[2][2], ma.r[3][2],
		ma.r[0][3], ma.r[1][3], ma.r[2][3], ma.r[3][3]
	);
}

inline mat4 mat4_rotation_x(float angle) {
    const float sin_a = std::sinf(angle);
    const float cos_a = std::cosf(angle);

    return mat4(
            scast<float>(1.0),    scast<float>(0.0),    scast<float>(0.0),    scast<float>(0.0),
            scast<float>(0.0),    cos_a,				sin_a,				scast<float>(0.0),
            scast<float>(0.0),    -sin_a,				cos_a,				scast<float>(0.0),
            scast<float>(0.0),    scast<float>(0.0),    scast<float>(0.0),    scast<float>(1.0)
	);
}

inline mat4 mat4_translation(const vec3& position) {
    return mat4(
            scast<float>(1.0),		scast<float>(0.0),		scast<float>(0.0),		scast<float>(0.0),
            scast<float>(0.0),		scast<float>(1.0),		scast<float>(0.0),		scast<float>(0.0),
            scast<float>(0.0),		scast<float>(0.0),		scast<float>(1.0),		scast<float>(0.0),
            position.x,				position.y,				position.z,				scast<float>(1.0)
	);
}

inline mat4 mat4_scaling(const vec3& scales) {
    return mat4(
            scales.x,			scast<float>(0.0),	scast<float>(0.0),	scast<float>(0.0),
            scast<float>(0.0),	scales.y,			scast<float>(0.0),	scast<float>(0.0),
            scast<float>(0.0),	scast<float>(0.0),	scales.z,			scast<float>(0.0),
            scast<float>(0.0),	scast<float>(0.0),	scast<float>(0.0),	scast<float>(1.0)
	);
}


inline mat4 mat4_look_at_lh(const vec3& eye, const vec3& at, const vec3& up) {
    vec3 right = vec3::k_zero();
    vec3 upn = vec3::k_zero();
    vec3 dir = vec3::k_zero();

    dir = vec3_normalize(at - eye);
    right = vec3_cross(up, dir);
    upn = vec3_cross(dir, right);
    right = vec3_normalize(right);
    upn = vec3_normalize(upn);

    return mat4(
        right.x,			   upn.x,				dir.x,				 scast<float>(0.0),
        right.y,			   upn.y,				dir.y,				 scast<float>(0.0),
        right.z,			   upn.z,				dir.z,				 scast<float>(0.0),
        -vec3_dot(right, eye), -vec3_dot(upn, eye), -vec3_dot(dir, eye), scast<float>(1.0)
    );
}
inline mat4 mat4_look_at_rh(const vec3& eye, const vec3& at, const vec3& up) {
    vec3 right = vec3::k_zero(); 
    vec3 upn = vec3::k_zero();
    vec3 dir = vec3::k_zero();

    dir = vec3_normalize(at - eye);
    right = vec3_cross(up, dir);
    upn = vec3_cross(dir, right);
    right = vec3_normalize(right);
    upn = vec3_normalize(upn);

    return mat4(
        -right.x,			  upn.x,			   -dir.x,		       scast<float>(0.0),
        -right.y,			  upn.y,			   -dir.y,             scast<float>(0.0),
        -right.z,			  upn.z,			   -dir.z,			   scast<float>(0.0),
        vec3_dot(right, eye), -vec3_dot(upn, eye), vec3_dot(dir, eye), scast<float>(1.0)
    );
}


inline mat4 mat4_perspective_fov_lh(float fovy, float aspect, float zn, float zf) {
	const float tan_half_fovy = std::tan(fovy * scast<float>(0.5));
	const float x_scale = scast<float>(1.0)/(aspect * tan_half_fovy);
	const float y_scale = scast<float>(1.0)/tan_half_fovy;

    return mat4(
        x_scale,		 scast<float>(0.0), scast<float>(0.0), scast<float>(0.0), 
        scast<float>(0.0), y_scale,		  scast<float>(0.0), scast<float>(0.0), 
        scast<float>(0.0), scast<float>(0.0), zf/(zf-zn),	   scast<float>(1.0), 
        scast<float>(0.0), scast<float>(0.0), (zf*zn)/(zn-zf), scast<float>(0.0) 
	);    
}
inline mat4 mat4_perspective_fov_rh(float fovy, float aspect, float zn, float zf) {
	const float tan_half_fovy = std::tan(fovy * scast<float>(0.5));
	const float x_scale = scast<float>(1.0)/(aspect * tan_half_fovy);
	const float y_scale = scast<float>(1.0)/tan_half_fovy;

    return mat4(
        x_scale,		 scast<float>(0.0), scast<float>(0.0), scast<float>(0.0), 
        scast<float>(0.0), y_scale,		  scast<float>(0.0), scast<float>(0.0), 
        scast<float>(0.0), scast<float>(0.0), zf/(zn-zf),	   -scast<float>(1.0), 
        scast<float>(0.0), scast<float>(0.0), (zf*zn)/(zn-zf), scast<float>(0.0)
	);    
}


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

}