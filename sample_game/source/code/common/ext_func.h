#define fm_msg_box_ok(msg)   MessageBoxW(NULL, L##msg, L"Error", 0)
#define fm_msg_boxw_ok(msg)   MessageBoxW(NULL, msg, L"Error", 0)

// Get File Name extension
//const char *get_filename_ext(const char *filename) 
//{
//    const char *dot = strrchr(filename, '.');
//    if(!dot || dot == filename) return "";
//    return dot + 1;
//}

void get_filename_ext(char* result, const char* filename)
{
    const char* dot = strrchr(filename, '.');
	if(!dot || dot == filename) { strcpy(result, ""); }
    strcpy(result, dot + 1);
}

void get_width_height_from_window_rect(HWND hwnd, int& width, int& height)
{
	RECT rc;
	GetClientRect(hwnd, &rc);
	UINT width = rc.right - rc.left;
	UINT height = rc.bottom - rc.top;
}

//==================================================
// UTILITY
// Round up to the next highest power of 2
uint upper_pow_2_u32(uint new_size)
{
    unsigned int v = new_size; // compute the next highest power of 2 of 32-bit v
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

// Gives next higher power of 2 for power of two numbers also
size_t next_upper_pow_2(size_t new_size)
{
    if (new_size == std::numeric_limits<size_t>::max()) { return new_size; }
    size_t power = 1;
    while(power <= new_size)
    {
        power*=2;
    }
    return power;
}


#include <bit>
unsigned long upper_pow_2(unsigned long v)
{
    return std::bit_ceil(v);
}
unsigned long lower_pow_2(unsigned long v)
{
    return std::bit_floor(v);
}

// lerp, mix: a + s*(b-a)
inline float lerp(float from, float to, float ratio)
{
	//return (from + (to-from)*ratio);
	// handles unsigned values wraparound
	return (from * (1.0f - ratio) + (to * ratio));
}

//----------------------------------
// Reading text file line by line
//----------------------------------
#include <fstream>
#include <limits>
std::fstream& GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}
void read_cpp(const char * filename) {
    ifstream ifile(filename);
    string line;
    unsigned int i = 0;
    while(getline(ifile, line)) i++;
    cout << "Lines count: " << i << endl;
}
// C getline is a posix function not in C standard
void read_c(const char * filename) {
    FILE * ifile = fopen(filename, "r");
    size_t linesz = 4096+1;
    char * line = new char[linesz];
    unsigned int i = 0;
    while(getline(&line, &linesz, ifile) > 0) i++;
    delete[] line;
    cout << "Lines count: " << i << endl;
    fclose(ifile);
}
void read_c(const char * filename) {
    FILE * ifile = fopen(filename, "r");
    size_t linesz = 0;
    char * line = nullptr;
    unsigned int i = 0;
    while(getline(&line, &linesz, ifile) > 0) i++;
    free(line);
    std::cout << "Lines count: " << i << std::endl;
    fclose(ifile);
}

//--------------------------
//STRING
//check null termination //old
const wchar_t* mb_towstr(const char* src)
{
	size_t src_size = strlen(src) + 1;
	wchar_t* temp_dest = new wchar_t[src_size];
	mbstowcs(temp_dest, src, src_size);
	return temp_dest;
}
const char* mb_tostr(const wchar_t* src)
{
	size_t src_size = wcslen(src) + 1;
	char* temp_dest = new char[src_size];
	wcstombs(temp_dest, src, src_size);
	return temp_dest;
}

void get_file_ext(const char* texture_path)
{
	const char* ext;
	ext = strrchr(texture_path, '.') ;
	ext = ext + 1;
	println("{}", ext);
}

//-----------------------
template <typename... Args>
void println(fmt::CStringRef format, const Args&... args) {
  fmt::print(format, args...);
  std::putc('\n', stdout);
}
//fmt::print("{::*^5}", std::vector<int>{1, 2, 3});
std::vector<double> xx = {1.2345678901, 2, 3};
//fmt::print("{:>12.6f}\n", fmt::join(xx, ", "));
fmt::print("[{}]\n", fmt::join(xx, ", "));
std::vector<int> v = {1, 2, 3};
fmt::print("{}", fmt::join(v, ", "));
//-----------------------
size_t upper_pow_2(size_t new_size)
{
    // Beware of infinite loop if x is too large (i.e. not enough bits to represent the next power of 2).
    size_t power = 1;
    while(power < new_size)
    {
        power*=2;
    }
    return power;
}
size_t upper_pow_1_5(size_t new_size)
{
    // Beware of infinite loop if x is too large (i.e. not enough bits to represent the next power of 2).
    float power = 1.0f;
    while(power < new_size)
    {
        power*=1.5;
    }
    power= std::ceil(power);
    return scast<size_t>(power);
}

//still returns max of signed type
//size_type vector_max_size() const noexcept {
//    return (_STD min) (static_cast<size_type>((numeric_limits<difference_type>::max) ()),
//        _Alty_traits::max_size(_Getal()));
//}
// from msvc, doubles or 1.5 old capacity or sets to new size is greater (msvc)
size_t calculate_growth_1_5(size_t new_size, size_t old_capacity)
{
    // given old_capacity and new_size, calculate geometric growth
    //const size_t old_capacity = capacity();
    const size_t max_capacity = std::numeric_limits<size_t>::max();

    if (old_capacity > max_capacity - old_capacity / 2) 
    {
        return max_capacity; // geometric growth would overflow
    }

    const size_t geometric_growth = old_capacity + old_capacity / 2;

    if (geometric_growth < new_size) 
    {
        return new_size; // geometric growth would be insufficient
    }

    return geometric_growth; // geometric growth is sufficient
}

size_t calculate_growth_2(size_t new_size, size_t old_capacity)
{
    const size_t max_capacity = std::numeric_limits<size_t>::max();

    if (old_capacity > max_capacity / 2) 
    {
        return max_capacity; // geometric growth would overflow
    }

    const size_t geometric_growth = old_capacity * 2;

    if (geometric_growth < new_size) 
    {
        return new_size; // geometric growth would be insufficient
    }

    return geometric_growth; // geometric growth is sufficient
}

size_t calculate_growth_granularity(size_t new_size, size_t granularity)
{
	size_t result;
	// Get result near to next m_granularity multiple. 		
	result = new_size + granularity - 1;
	result -= result % granularity;
	// If new_size equals m_granularity multiple, return next m_granularity multiple
	//if (result == new_size) { result += granularity; }
	return result;
}


//==================================================
// 3D MATH
// POD types
//print("gm::vec3 is is_trivial: {}\n", std::is_trivial<gm::vec3>::value);
//print("gm::vec3 is is_standard_layout: {}\n", std::is_standard_layout<gm::vec3>::value);

template<class T>
class tvec3
{
public:
	union
    {
		struct { T x, y, z; };
		T e[3];
    };	

	constexpr static int size() { return 3; }	
	constexpr static int size_bytes() { return size()*sizeof(T); }	

	tvec3() = default;
	//tvec3() : e { {scast<T>(0)}, {scast<T>(0)}, {scast<T>(0)} } {}
	explicit tvec3(T f) : e {f, f, f} {}	
	tvec3(T x, T y, T z) : e {x, y, z} {}	
	
	const T* data() const				{ return &e[0]; }
	T* data()							{ return &e[0]; }
	const T& operator[] (int i) const	{ return e[i]; }
    T& operator [] (int i)				{ return e[i]; }

	constexpr static tvec3 k_zero() { return tvec3(scast<T>(0)); }
	constexpr static tvec3 k_one() { return tvec3(scast<T>(1)); }
	constexpr static tvec3 k_unit_x() { return tvec3(scast<T>(1), scast<T>(0), scast<T>(0)); }
	constexpr static tvec3 k_unit_y() { return tvec3(scast<T>(0), scast<T>(1), scast<T>(0)); }
	constexpr static tvec3 k_unit_z() { return tvec3(scast<T>(0), scast<T>(0), scast<T>(1)); }
};

using vec3 = tvec3<float>;
using vec3i = tvec3<int>;
using vec3u = tvec3<uint>;
using vec3d = tvec3<double>;

// row major matrix: d3d
// input matrix values in row major form like
// { m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33 }
class mat4
{
public:
	union
    {
		float e[16];
		float r[4][4];
	};

	constexpr static int size() { return 16; }	
	constexpr static int size_bytes() { return size()*sizeof(float); }
	constexpr int dim() const	{ return 4; }	

	mat4() = default;

	//mat4() : e { {scast<float>(0)}, {scast<float>(0)}, {scast<float>(0)}, {scast<float>(0)},
	//			 {scast<float>(0)}, {scast<float>(0)}, {scast<float>(0)}, {scast<float>(0)},
	//			 {scast<float>(0)}, {scast<float>(0)}, {scast<float>(0)}, {scast<float>(0)},
	//			 {scast<float>(0)}, {scast<float>(0)}, {scast<float>(0)}, {scast<float>(0)}, } {}


	// can make identity by: mat4 a(1.0f);
	explicit mat4(float f) 
        : e { f,                 scast<float>(0),    scast<float>(0), scast<float>(0),
			  scast<float>(0),   f,                  scast<float>(0), scast<float>(0),
			  scast<float>(0),   scast<float>(0),    f,               scast<float>(0),
			  scast<float>(0),   scast<float>(0),    scast<float>(0), f,              } {}


	mat4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33) 
		: e { m00, m01, m02, m03,
			  m10, m11, m12, m13,
			  m20, m21, m22, m23,
			  m30, m31, m32, m33, } {}		


	mat4(const float* arr)			{ q_assert(arr); for_range(i, size()) { (*this)[i] = arr[i]; } }	

	
	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator[] (int i) const	{ return e[i]; }
    float& operator [] (int i)				{ return e[i]; }

	const static mat4 k_zero() { return mat4(scast<float>(0)); }
	// default identity_matrix
	const static mat4 k_identity() { return mat4(scast<float>(1)); }

	//------------------------------------------
	////const float& operator() (int row, int col) const { return e[(row*4) + col]; }	//if only get or at function is desired
	//float& operator() (int row, int col) { return e[(row*4) + col]; }
	//float operator() (int row, int col) const { return e[(row*4) + col]; }
};

// Quaternion class for representing rotations.
// It provides cheap combinations and avoids gimbal locks. Also useful for interpolations. 

//constexpr vec2 k_vec2_zero() { return vec2(0, 0); }
//constexpr vec3 k_vec3_zero() { return vec3(0, 0, 0); }
//constexpr vec4 k_vec4_zero() { return vec4(0, 0, 0, 0); }
//constexpr color4 k_color4_zero() { return color4(0, 0, 0, 0); }
//constexpr quat k_quat_zero() { return quat(0, 0, 0, 0); }
//constexpr quat k_quat_identity() { return quat(0, 0, 0, 1); }
//constexpr mat4 k_mat4_zero() 
//{ 
//	return mat4(
//		0, 0, 0, 0,		
//		0, 0, 0, 0,		
//		0, 0, 0, 0,		
//		0, 0, 0, 0); 
//}
//constexpr mat4 k_mat4_identity() 
//{ 
//	return mat4(
//		1, 0, 0, 0,		
//		0, 1, 0, 0,		
//		0, 0, 1, 0,		
//		0, 0, 0, 1); 
//}



//inline mat4 mat4_glm_ortho(float l, float r, float b, float t, float zn, float zf)
//{
//		return orthoLH_un(l, r, b, t, zn, zf);
//		return orthoLH_sn(l, r, b, t, zn, zf);
//		return orthoRH_un(l, r, b, t, zn, zf);
//		return orthoRH_sn(l, r, b, t, zn, zf);
//}
//
//inline mat4 mat4_glm_frustum(float l, float r, float b, float t, float zn, float zf)
//{
//		return frustumLH_un(l, r, b, t, zn, zf);
//		return frustumLH_sn(l, r, b, t, zn, zf);
//		return frustumRH_un(l, r, b, t, zn, zf);
//		return frustumRH_sn(l, r, b, t, zn, zf);
//}
//
//inline mat4 mat4_glm_perspective(float fovy, float aspect, float zn, float zf)
//{
//		return perspectiveLH_un(fovy, aspect, zn, zf);
//		return perspectiveLH_sn(fovy, aspect, zn, zf);
//		return perspectiveRH_un(fovy, aspect, zn, zf);
//		return perspectiveRH_sn(fovy, aspect, zn, zf);
//}
//
//inline mat4 mat4_glm_perspectiveFov(float fov, float w, float h, float zn, float zf)
//{
//		return perspectiveFovLH_un(fov, w, h, zn, zf);
//		return perspectiveFovLH_sn(fov, w, h, zn, zf);
//		return perspectiveFovRH_un(fov, w, h, zn, zf);
//		return perspectiveFovRH_sn(fov, w, h, zn, zf);
//}

//inline mat4 infinitePerspective(float fovy, float aspect, float zn)
//{
//		return infinitePerspectiveLH(fovy, aspect, zn);
//		return infinitePerspectiveRH(fovy, aspect, zn);
//}
//---

// TEMPLATE MATH
//---------------------------------------------------
template<class T> inline T vecnt_reflect(const T& a, const T& normal) { return (a - (2.0f * vecnt_dot(a, normal) * normal)); }

// CHECK: dimension of resulting matrix
template<class T, class U> inline T vecnt_mul_matrix_nm(const T& a, const U& b) { 
    const int r1 = a.dim_r();
    const int c1 = a.dim_c();
    const int r2 = b.dim_r();
    const int c2 = b.dim_c();  
    //if (c1!=r2) { q_debug("Error: column of first matrix not equal to row of second.\n"); }
    
    T out = T::k_zero();  
	for_range(i, r1) {
        for_range(j, c2) {
            for_range(k, c1) {
                out.r[i][j] += a.r[i][k] * b.r[k][j];
            }
		}
	}
    return out;
}

template<class T> inline T vecnt_mul_matrix(const T& a, const T& b) { 
    T out = T::k_zero();  
	for_range(i, out.dim()) {
        for_range(j, out.dim()) {
            for_range(k, out.dim()) {
                out.r[i][j] += a.r[i][k] * b.r[k][j];
            }
		}
	}
    return out;
}

template<class T> inline T vecnt_transpose_matrix(const T& a) 
{
    T out = T::k_zero();  
	for_range(i, out.dim()) { 
		for_range(j, out.dim()) { 
			out.r[i][j] = a.r[j][i];
		} 
	}
    return out;
}
//----------------------------------

template<class T>
class ttex2
{
public:
	union
    {
		struct { T u, v; };
		T e[2];
    };	

	constexpr static int size() { return 2; }	
	constexpr static int size_bytes() { return size()*sizeof(T); }	

	ttex2() = default;
	//ttex2() : e { {scast<T>(0)}, {scast<T>(0)} } {}
	explicit ttex2(T f) : e {f, f} {}	
	ttex2(T u, T v) : e {u, v} {}	
	
	const T* data() const				{ return &e[0]; }
	T* data()							{ return &e[0]; }
	const T& operator[] (int i) const	{ return e[i]; }
    T& operator [] (int i)				{ return e[i]; }

	constexpr static ttex2 k_zero() { return ttex2(scast<T>(0)); }
};

using tex2 = ttex2<float>;

inline vec3 vec3_cross(const vec3& a, const vec3& b) 
{
	vec3 out = vec3::k_zero();

	out[0] = a.y*b.z - a.z*b.y;
	out[1] = a.z*b.x - a.x*b.z;
	out[2] = a.x*b.y - a.y*b.x;

	//out[0] = a[1]*b[2] - a[2]*b[1];
	//out[1] = a[2]*b[0] - a[0]*b[2];
	//out[2] = a[0]*b[1] - a[1]*b[0];

	return out;
}

inline vec2 vec2_add(const vec2& a, const vec2& b) { return (a + b); }
inline vec2 vec2_sub(const vec2& a, const vec2& b) { return (a - b); }
inline vec2 vec2_mul(const vec2& a, const vec2& b) { return (a * b); }
inline vec2 vec2_div(const vec2& a, const vec2& b) { return (a / b); }
inline vec3 vec3_add(const vec3& a, const vec3& b) { return (a + b); }
inline vec3 vec3_sub(const vec3& a, const vec3& b) { return (a - b); }
inline vec3 vec3_mul(const vec3& a, const vec3& b) { return (a * b); }
inline vec3 vec3_div(const vec3& a, const vec3& b) { return (a / b); }
inline vec4 vec4_add(const vec4& a, const vec4& b) { return (a + b); }
inline vec4 vec4_sub(const vec4& a, const vec4& b) { return (a - b); }
inline vec4 vec4_mul(const vec4& a, const vec4& b) { return (a * b); }
inline vec4 vec4_div(const vec4& a, const vec4& b) { return (a / b); }
inline color4 colorf_add(const color4& a, const color4& b) { return (a + b); }
inline color4 colorf_sub(const color4& a, const color4& b) { return (a - b); }
inline color4 colorf_mul(const color4& a, const color4& b) { return (a * b); }
inline color4 colorf_div(const color4& a, const color4& b) { return (a / b); }
inline quat quat_add(const quat& a, const quat& b) { return (a + b); }
inline quat quat_sub(const quat& a, const quat& b) { return (a - b); }
inline quat quat_mul(const quat& a, const quat& b) { return (a * b); }
inline quat quat_div(const quat& a, const quat& b) { return (a / b); }
inline mat4 mat4_add(const mat4& a, const mat4& b) { return (a + b); }
inline mat4 mat4_sub(const mat4& a, const mat4& b) { return (a - b); }
inline mat4 mat4_mul(const mat4& a, const mat4& b) { return (a * b); }
//inline mat4 mat4_div(const mat4& a, const mat4& b) { return (a / b); }

inline uint ColorBytes4(float r, float g, float b, float a)
{
	uint i = 0;
	((uint8*) &i)[0] = r * 255;
	((uint8*) &i)[1] = g * 255;
	((uint8*) &i)[2] = b * 255;
	((uint8*) &i)[3] = a * 255;
	return i;
}
//---

//================================================================================================

//---------------------------------------------------
// vec2
//---------------------------------------------------

inline vec2 operator - (const vec2& a) { return vec2(-a.x, -a.y); }

inline vec2 operator + (const vec2& a, const vec2& b) { return vec2(a.x + b.x, a.y + b.y); }
inline vec2 operator - (const vec2& a, const vec2& b) { return vec2(a.x - b.x, a.y - b.y); }
inline vec2 operator * (const vec2& a, const vec2& b) { return vec2(a.x * b.x, a.y * b.y); }
inline vec2 operator / (const vec2& a, const vec2& b) { return vec2(a.x / b.x, a.y / b.y); }

inline vec2 operator + (const vec2& a, float s) { return vec2(a.x + s, a.y + s); }
inline vec2 operator - (const vec2& a, float s) { return vec2(a.x - s, a.y - s); }
inline vec2 operator * (const vec2& a, float s) { return vec2(a.x * s, a.y * s); }
inline vec2 operator / (const vec2& a, float s) { const float inv_s = 1.0/s; return (a * inv_s); }

inline vec2 operator + (float s, const vec2& a) { return (a + s); }
inline vec2 operator - (float s, const vec2& a) { return (a - s); }
inline vec2 operator * (float s, const vec2& a) { return (a * s); }
inline vec2 operator / (float s, const vec2& a) { return (a / s); }

inline bool vec2_equals_ep(const vec2& a, const vec2& b, float epsilon) { 
	return (mf::equals(a.x, b.x, epsilon) && mf::equals(a.y, b.y, epsilon));
}

inline bool operator == (const vec2& a, const vec2& b)	{ return (a.x==b.x && a.y==b.y); }
inline bool operator != (const vec2& a, const vec2& b)	{ return !(a == b); }
inline bool operator < (const vec2& a, const vec2& b)	{ return (a.x<b.x && a.y<b.y); }
inline bool operator > (const vec2& a, const vec2& b)	{ return (b < a); }
inline bool operator <= (const vec2& a, const vec2& b)	{ return !(b < a); }
inline bool operator >= (const vec2& a, const vec2& b)	{ return !(a < b); }

inline float vec2_dot(const vec2& a, const vec2& b) { return (a.x*b.x + a.y*b.y); }
inline float vec2_length_sq(const vec2& a) { 
	return (mf::square(a.x) + mf::square(a.y)); 
}
inline float vec2_length(const vec2& a) { return mf::sqrt(vec2_length_sq(a)); }
inline float vec2_distance_sq(const vec2& a, const vec2& b) { 
	return (mf::square(a.x - b.x) + mf::square(a.y - b.y)); 
}
inline float vec2_distance(const vec2& a, const vec2& b) { return mf::sqrt(vec2_distance_sq(a, b)); }

inline vec2 vec2_scale(const vec2& a, float s) { return (a * s); }
inline vec2 vec2_lerp(const vec2& a, const vec2& b, float s) { 
	return vec2(mf::lerp(a.x, b.x, s), mf::lerp(a.y, b.y, s)); 
} 

inline vec2 vec2_minf(const vec2& a, const vec2& b) { 
	return vec2(sdf::minf(a.x, b.x), sdf::minf(a.y, b.y)); 
}
inline vec2 vec2_maxf(const vec2& a, const vec2& b) { 
	return vec2(sdf::maxf(a.x, b.x), sdf::maxf(a.y, b.y)); 
}
inline vec2 vec2_clamp(const vec2& a, const vec2& low, const vec2& high) { 
	return vec2(sdf::clamp(a.x, low.x, high.x), sdf::clamp(a.y, low.y, high.y));
}

inline vec2 vec2_normalize(const vec2& a) {
	vec2 out = vec2::k_zero(); 
	const float length = vec2_length(a);
	if (length > 0.0) {
		const float inv_length = 1.0/length;
		out = a * inv_length;		
	} else {
        printf("Cannot normalize zero length vector. Zero vector returned");				
	}		
    return out;
}

inline vec2 vec2_reflect(const vec2& a, const vec2& normal) { return (a - (2.0f * vec2_dot(a, normal) * normal)); }
inline float vec2_ccw(const vec2& a, const vec2& b) { return (a.x*b.y - a.y*b.x); }
//---------------------------------------------------


inline mat4 mat4_mul_matrix(const mat4& a, const mat4& b)
{
    return mat4(
        // First row
        a.r[0][0] * b.r[0][0] + a.r[0][1] * b.r[1][0] + a.r[0][2] * b.r[2][0] + a.r[0][3] * b.r[3][0],
        a.r[0][0] * b.r[0][1] + a.r[0][1] * b.r[1][1] + a.r[0][2] * b.r[2][1] + a.r[0][3] * b.r[3][1],
        a.r[0][0] * b.r[0][2] + a.r[0][1] * b.r[1][2] + a.r[0][2] * b.r[2][2] + a.r[0][3] * b.r[3][2],
        a.r[0][0] * b.r[0][3] + a.r[0][1] * b.r[1][3] + a.r[0][2] * b.r[2][3] + a.r[0][3] * b.r[3][3],

        // Second row
        a.r[1][0] * b.r[0][0] + a.r[1][1] * b.r[1][0] + a.r[1][2] * b.r[2][0] + a.r[1][3] * b.r[3][0],
        a.r[1][0] * b.r[0][1] + a.r[1][1] * b.r[1][1] + a.r[1][2] * b.r[2][1] + a.r[1][3] * b.r[3][1],
        a.r[1][0] * b.r[0][2] + a.r[1][1] * b.r[1][2] + a.r[1][2] * b.r[2][2] + a.r[1][3] * b.r[3][2],
        a.r[1][0] * b.r[0][3] + a.r[1][1] * b.r[1][3] + a.r[1][2] * b.r[2][3] + a.r[1][3] * b.r[3][3],

        // Third row
        a.r[2][0] * b.r[0][0] + a.r[2][1] * b.r[1][0] + a.r[2][2] * b.r[2][0] + a.r[2][3] * b.r[3][0],
        a.r[2][0] * b.r[0][1] + a.r[2][1] * b.r[1][1] + a.r[2][2] * b.r[2][1] + a.r[2][3] * b.r[3][1],
        a.r[2][0] * b.r[0][2] + a.r[2][1] * b.r[1][2] + a.r[2][2] * b.r[2][2] + a.r[2][3] * b.r[3][2],
        a.r[2][0] * b.r[0][3] + a.r[2][1] * b.r[1][3] + a.r[2][2] * b.r[2][3] + a.r[2][3] * b.r[3][3],

        // Fourth row
        a.r[3][0] * b.r[0][0] + a.r[3][1] * b.r[1][0] + a.r[3][2] * b.r[2][0] + a.r[3][3] * b.r[3][0],
        a.r[3][0] * b.r[0][1] + a.r[3][1] * b.r[1][1] + a.r[3][2] * b.r[2][1] + a.r[3][3] * b.r[3][1],
        a.r[3][0] * b.r[0][2] + a.r[3][1] * b.r[1][2] + a.r[3][2] * b.r[2][2] + a.r[3][3] * b.r[3][2],
        a.r[3][0] * b.r[0][3] + a.r[3][1] * b.r[1][3] + a.r[3][2] * b.r[2][3] + a.r[3][3] * b.r[3][3]
    );
}
inline mat4 mat4_mul_matrix(const mat4& a, const mat4& b)
{ 
	mat4 out = mat4::k_zero();
	//for_range(j, out.dim()) { for_range(i, out.dim()) { float sum = 0; for_range(n, dim()) { sum += b.r[n][i] * a.r[j][n]; } out.r[j][i] = sum; } }
	for_range(i, out.dim()) { for_range(j, out.dim()) { out.r[i][j] = a.r[i][0] * b.r[0][j] + a.r[i][1] * b.r[1][j] + a.r[i][2] * b.r[2][j] + a.r[i][3] * b.r[3][j]; } }
	return out;
}


inline mat4 mat4_transpose(const mat4& ma)
{
    //return mat4(
    //    ma.r[0][0], ma.r[1][0], ma.r[2][0], ma.r[3][0],
    //    ma.r[0][1], ma.r[1][1], ma.r[2][1], ma.r[3][1],
    //    ma.r[0][2], ma.r[1][2], ma.r[2][2], ma.r[3][2],
    //    ma.r[0][3], ma.r[1][3], ma.r[2][3], ma.r[3][3]
    //);

	//for_range(i, out.dim()) { for_range(j, out.dim()) { out.r[i][j] = ma.r[j][i]; } }

	return vecnt_transpose_matrix(ma);
}

//----------------------
/*
	// Matrix notation used in opengl documentation does not describe in-memory layout for OpenGL matrices
	// It'll be easier if you drop/forget about the entire "row/column-major" thing. That's because in addition to row/column major, the programmer can also decide 
	// how he would want to lay out the matrix in the memory (whether adjacent elements form rows or columns), in addition to the notation, which adds to confusion.
	// OpenGL matrices have same memory layout as directx matrices. But they are treated as column major in understanding and multiplication operator multiplies
	// in reverse order inside the function and then matrices are premultiplied for correct result, which gives same result as post multiplying row-major matrices
	// multiplied in forward order inside the multiply function.

	// x.x x.y x.z 0
	// y.x y.y y.z 0
	// z.x z.y z.z 0
	// p.x p.y p.z 1

	// or

	// { x.x x.y x.z 0 y.x y.y y.z 0 z.x z.y z.z 0 p.x p.y p.z 1 }

	// x, y, z are 3-component vectors describing the matrix coordinate system (local coordinate system within relative to the global coordinate system).
	// p is a 3-component vector describing the origin of matrix coordinate system.
	// Which means that the translation matrix should be laid out in memory like this:
	// { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, transX, transY, transZ, 1 }.


	//typedef vec<4, T, Q> col_type;
	// col_type value[4];

	//x0, y0, z0, w0,	
	//x1, y1, z1, w1,
	//x2, y2, z2, w2,
	//x3, y3, z3, w3

	//m00, m01, m02, m03,	
	//m10, m11, m12, m13,
	//m20, m21, m22, m23,
	//m30, m31, m32, m33;

	union
    {
		// input matrix values in row major form like
		// { m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33 }
		struct 
		{ 
			real m00, m01, m02, m03,
				 m10, m11, m12, m13,
				 m20, m21, m22, m23,
				 m30, m31, m32, m33;
		};

		// input matrix values in column major form like
		// { m00, m10, m20, m30, m01, m11, m21, m31, m02, m12, m22, m32, m03, m13, m23, m33 }
		//struct 
		//{ 
		//	real m00, m10, m20, m30,
		//		 m01, m11, m21, m31,
		//		 m02, m12, m22, m32,
		//		 m03, m13, m23, m33;
		//};

		real e[16];

		real m[4][4];
	};

	typedef tmat4<real> base;

	tmat4() = default;
	tmat4( real m00, real m01, real m02, real m03, real m10, real m11, real m12, real m13, real m20, real m21, real m22, real m23, real m30, real m31, real m32, real m33 ) 
		:   m00(m00), m01(m01), m02(m02), m03(m03), m10(m10), m11(m11), m12(m12), m13(m13), m20(m20), m21(m21), m22(m22), m23(m23), m30(m30), m31(m31), m32(m32), m33(m33) {}	

	//tmat4( real m00, real m10, real m20, real m30, real m01, real m11, real m21, real m31, real m02, real m12, real m22, real m32, real m03, real m13, real m23, real m33 ) 
	//	:   m00(m00), m10(m10), m20(m20), m30(m30), m01(m01), m11(m11), m21(m21), m31(m31), m02(m02), m12(m12), m22(m22), m32(m32), m03(m03), m13(m13), m23(m23), m33(m33) {}	
	
	// should be default for pod types
	//tmat4( const base& m ) 
	//	:   m00(m.m00), m01(m.m01), m02(m.m02), m03(m.m03), m10(m.m10), m11(m.m11), m12(m.m12), m13(m.m13), 
	//		m20(m.m20), m21(m.m21), m22(m.m22), m23(m.m23), m30(m.m30), m31(m.m31), m32(m.m32), m33(m.m33) {}	


	// can make identity by: mat4 a(1.0f);
	tmat4( real f)  :
		m00(f),					m01(scast<real>(0.0)),	m02(scast<real>(0.0)),	m03(scast<real>(0.0)),
		m10(scast<real>(0.0)),	m11(f),					m12(scast<real>(0.0)),	m13(scast<real>(0.0)),
		m20(scast<real>(0.0)),	m21(scast<real>(0.0)),	m22(f),					m23(scast<real>(0.0)),
		m30(scast<real>(0.0)),	m31(scast<real>(0.0)),	m32(scast<real>(0.0)),	m33(f) {}

	//---------------------------
	// Matrix Multiply
	//x,   y,	z,	 w
	//m00, m01, m02, m03,			x		m00, m01, m02, m03,			
	//m10, m11, m12, m13,			y		m10, m11, m12, m13,			
	//m20, m21, m22, m23,			z		m20, m21, m22, m23,			
	//m30, m31, m32, m33;			w		m30, m31, m32, m33;			

	//m00*m00 + m01*m10 + m02*m20 + m03*m30,	m00*m01 + m01*m11 + m02*m21 + m03*m31,	m00*m02 + m01*m12 + m02*m22 + m03*m32,	m00*m03 + m01*m13 + m02*m23 + m03*m33, 
	//m10*m00 + m11*m10 + m12*m20 + m13*m30,	m10*m01 + m11*m11 + m12*m21 + m13*m31,	m10*m02 + m11*m12 + m12*m22 + m13*m32,	m10*m03 + m11*m13 + m12*m23 + m13*m33, 
	//m20*m00 + m21*m10 + m22*m20 + m23*m30,	m20*m01 + m21*m11 + m22*m21 + m23*m31,	m20*m02 + m21*m12 + m22*m22 + m23*m32,	m20*m03 + m21*m13 + m22*m23 + m23*m33, 
	//m30*m00 + m31*m10 + m32*m20 + m33*m30,	m30*m01 + m31*m11 + m32*m21 + m33*m31,	m30*m02 + m31*m12 + m32*m22 + m33*m32,	m30*m03 + m31*m13 + m32*m23 + m33*m33 );

	// Multiplying in forward order like directx
	//inline friend base operator * ( const base& a, const base& b )	
	//{ 
	//	//base t;
	//	//for_range(j, t.dim()) { for_range(i, t.dim()) { real sum = 0; for_range(n, t.dim()) { sum += b[n][i] * a[j][n]; } t[j][i] = sum; } }
	//  //for_range(i, 4) { for_range(j, 4) { result.m[i][j] = a.m[i][0] * b.m[0][j] + a.m[i][1] * b.m[1][j] + a.m[i][2] * b.m[2][j] + a.m[i][3] * b.m[3][j]; } }
	//	//return t;

	//	return tmat4(
	//		a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30,	a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31,	a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22 + a.m03*b.m32,	a.m00*b.m03 + a.m01*b.m13 + a.m02*b.m23 + a.m03*b.m33, 
	//		a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20 + a.m13*b.m30,	a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21 + a.m13*b.m31,	a.m10*b.m02 + a.m11*b.m12 + a.m12*b.m22 + a.m13*b.m32,	a.m10*b.m03 + a.m11*b.m13 + a.m12*b.m23 + a.m13*b.m33, 
	//		a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20 + a.m23*b.m30,	a.m20*b.m01 + a.m21*b.m11 + a.m22*b.m21 + a.m23*b.m31,	a.m20*b.m02 + a.m21*b.m12 + a.m22*b.m22 + a.m23*b.m32,	a.m20*b.m03 + a.m21*b.m13 + a.m22*b.m23 + a.m23*b.m33, 
	//		a.m30*b.m00 + a.m31*b.m10 + a.m32*b.m20 + a.m33*b.m30,	a.m30*b.m01 + a.m31*b.m11 + a.m32*b.m21 + a.m33*b.m31,	a.m30*b.m02 + a.m31*b.m12 + a.m32*b.m22 + a.m33*b.m32,	a.m30*b.m03 + a.m31*b.m13 + a.m32*b.m23 + a.m33*b.m33 );
	//
	//}

	// Multiplying in reverse order like in glsl and glm, for vec4*mat4 and mat4*vec4 interchange the functions definitions
	// This gives result of b * a, when you pre-multiply like (mb * ma) in source code you get result of ma * mb (as done in post-multiply)
	//inline friend base operator * ( const base& a, const base& b )	
	//{ 
	//	//base t;
	//	//for_range(j, t.dim()) { for_range(i, t.dim()) { real sum = 0; for_range(n, t.dim()) { sum += a[n][i] * b[j][n]; } t[j][i] = sum; } }
	//	//return t;
	//	return tmat4(
	//		b.m00*a.m00 + b.m01*a.m10 + b.m02*a.m20 + b.m03*a.m30,	b.m00*a.m01 + b.m01*a.m11 + b.m02*a.m21 + b.m03*a.m31,	b.m00*a.m02 + b.m01*a.m12 + b.m02*a.m22 + b.m03*a.m32,	b.m00*a.m03 + b.m01*a.m13 + b.m02*a.m23 + b.m03*a.m33, 
	//		b.m10*a.m00 + b.m11*a.m10 + b.m12*a.m20 + b.m13*a.m30,	b.m10*a.m01 + b.m11*a.m11 + b.m12*a.m21 + b.m13*a.m31,	b.m10*a.m02 + b.m11*a.m12 + b.m12*a.m22 + b.m13*a.m32,	b.m10*a.m03 + b.m11*a.m13 + b.m12*a.m23 + b.m13*a.m33, 
	//		b.m20*a.m00 + b.m21*a.m10 + b.m22*a.m20 + b.m23*a.m30,	b.m20*a.m01 + b.m21*a.m11 + b.m22*a.m21 + b.m23*a.m31,	b.m20*a.m02 + b.m21*a.m12 + b.m22*a.m22 + b.m23*a.m32,	b.m20*a.m03 + b.m21*a.m13 + b.m22*a.m23 + b.m23*a.m33, 
	//		b.m30*a.m00 + b.m31*a.m10 + b.m32*a.m20 + b.m33*a.m30,	b.m30*a.m01 + b.m31*a.m11 + b.m32*a.m21 + b.m33*a.m31,	b.m30*a.m02 + b.m31*a.m12 + b.m32*a.m22 + b.m33*a.m32,	b.m30*a.m03 + b.m31*a.m13 + b.m32*a.m23 + b.m33*a.m33 );

	//}

	// for row order matrix storage
	// The result represents the transformation B followed by the transformation A. (result = A * B)
	// T(R(S(v))) = v*S*R*T = v*SRT
	inline friend base operator * ( const base& a, const base& b )	
	{ 	
		return tmat4(
			a.m00*b.m00 + a.m01*b.m10 + a.m02*b.m20 + a.m03*b.m30, a.m10*b.m00 + a.m11*b.m10 + a.m12*b.m20 + a.m13*b.m30, a.m20*b.m00 + a.m21*b.m10 + a.m22*b.m20 + a.m23*b.m30, a.m30*b.m00 + a.m31*b.m10 + a.m32*b.m20 + a.m33*b.m30,
			a.m00*b.m01 + a.m01*b.m11 + a.m02*b.m21 + a.m03*b.m31, a.m10*b.m01 + a.m11*b.m11 + a.m12*b.m21 + a.m13*b.m31, a.m20*b.m01 + a.m21*b.m11 + a.m22*b.m21 + a.m23*b.m31, a.m30*b.m01 + a.m31*b.m11 + a.m32*b.m21 + a.m33*b.m31,
			a.m00*b.m02 + a.m01*b.m12 + a.m02*b.m22 + a.m03*b.m32, a.m10*b.m02 + a.m11*b.m12 + a.m12*b.m22 + a.m13*b.m32, a.m20*b.m02 + a.m21*b.m12 + a.m22*b.m22 + a.m23*b.m32, a.m30*b.m02 + a.m31*b.m12 + a.m32*b.m22 + a.m33*b.m32,
			a.m00*b.m03 + a.m01*b.m13 + a.m02*b.m23 + a.m03*b.m33, a.m10*b.m03 + a.m11*b.m13 + a.m12*b.m23 + a.m13*b.m33, a.m20*b.m03 + a.m21*b.m13 + a.m22*b.m23 + a.m23*b.m33, a.m30*b.m03 + a.m31*b.m13 + a.m32*b.m23 + a.m33*b.m33 
			);	
	}

*/

#if 0

// D3D Row Major Matrices
// Identity matrix
1, 0, 0, 0
0, 1, 0, 0
0, 0, 1, 0
0, 0, 0, 1

// Matrix Transforms -
// Translate:
1, 	0, 	0, 	0
0, 	1, 	0, 	0
0, 	0, 	1, 	0
tx, ty, tz, 1

// Scale:
sx, 0, 	0, 	0
0, 	sy, 0, 	0
0, 	0, 	sz, 0
0, 	0, 	0, 	1

// Rotate:
// x-axis
1, 	0, 		0, 		0
0, 	cos a, 	sin a, 	0
0, 	-sin a, cos a, 	0
0, 	0, 		0, 		1
// y-axis
cos a, 	0, 	-sin a, 0
0, 		1, 	0, 		0
sin a, 	0, 	cos a, 	0
0, 		0, 	0, 		1
// z-axis
cos a, 	sin a, 	0, 0
-sin a, cos a, 	0, 0
0, 		0, 		1, 0
0, 		0, 		0, 1

// D3D Viewport Transform
// Applications typically set MinZ and MaxZ to 0.0 and 1.0 respectively to 
// cause the system to  render to the entire depth range.
w/2, 		0, 			0, 			0
0, 			-h/2, 		0, 			0
0, 			0, 			maxz-minz, 	0
x + w/2, 	h/2 + y, 	minz, 		1

// ZERO
mat4 out(
            scast<float>(0), scast<float>(0), scast<float>(0), scast<float>(0),
            scast<float>(0), scast<float>(0), scast<float>(0), scast<float>(0),
            scast<float>(0), scast<float>(0), scast<float>(0), scast<float>(0),
            scast<float>(0), scast<float>(0), scast<float>(0), scast<float>(0)
        );

// IDENTITY
mat4 out(
            scast<float>(1), scast<float>(0), scast<float>(0), scast<float>(0),
            scast<float>(0), scast<float>(1), scast<float>(0), scast<float>(0),
            scast<float>(0), scast<float>(0), scast<float>(1), scast<float>(0),
            scast<float>(0), scast<float>(0), scast<float>(0), scast<float>(1)
        );
#endif

//-------------------------------------------------------------
// D3D11
//-------------------------------------------------------------
#include <exception>
namespace DX {
    inline void ThrowIfFailed(HRESULT hr)     {
        if (FAILED(hr))         {
            // Set a breakpoint on this line to catch DirectX API errors
            throw std::exception();
        }
    }
}
//#define HR(x)																	\
//{																				\
//	HRESULT hr = x;																\
//	if(FAILED(hr))																\
//	{																			\
//		std::cout << "File: " << __FILE__ << "\nLine: " << __LINE__ << "\nhr: " << hr << "\nFunc: " << #x << std::endl;		\
//      //DXTrace(__FILE__, __LINE__, hr, #x, TRUE);          /
//		//dxerr_printf(hr); \
//	}																			\
//}
 
// d3d9 model loading from std::vector by index
void load_model_idx(int64 idx)
{
	//models_gl.resize(1);
	models_d3d9.push_back(d3d9_model());
	models_d3d9[idx] = *(rcast<d3d9_model*>(&models[idx]));
	//create_buffers_model(models[0]);		
	create_buffers_model_r(models_d3d9[idx]);
}	
void draw_model_idx(int64 idx)
{
	draw_model_r(models_d3d9[idx]);
}

// view matrix axis lock error fix:
// z axis is up, y depth. Change camera position also with up  
// else zero vector normalize error "vec3_cross(up, dir)".
// When the camera is vertical looking straight down or straight up, the forward axis gets very close to 
// the arbitrary axis used to compute the right axis. In extreme case the froward axis and this arbitrary axis 
// are perfectly parallel e.g. when the forward vector is either (0,1,0) or (0,-1,0). Then cross product fails 
// producing a result for the right vector. Zero vector normalize error "vec3_cross(up, dir)".
// Modify position on x axis (x axis not up in almost all renderers) by small amount to prevent this. 


//-------------------------------------------------------------
//OpenGL4
//-------------------------------------------------------------
void flip_vertices_d3d_to_gl(gmodel& m)
{
	//isz model_end = m.vertices.size()/3;
	for (isz i=0; i<m.vertices.size(); i+=3)
	{
		sdf::swap(m.vertices[i+1], m.vertices[i+2]);
	}
}

void clipz_vertex_c(sdr::vector<vertexc_t>& model)
{
	for_range32(i, model.size())
	{
		//model[i].z = model[i].z * 2.0 - 1.0f;
		model[i].z = mf::range_un_to_sn(model[i].z);			
	}
}

//-------------------------------------------------------------
//Char shaders
#if 1
	// Vertex shader
	const char* vertexShaderSource_wvp = R"glsl(
		#version 330 core
		layout (location = 0) in vec3 aPos;
		layout (location = 1) in vec4 vertexColor;

		//uniform mat4 world;
		//uniform mat4 view;
		//uniform mat4 proj;
	
		uniform mat4 wvp;

		out vec4 fragmentColor;

		void main()
		{
			//gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
			//gl_Position = proj * view * world * vec4(aPos, 1.0);
			gl_Position = wvp * vec4(aPos, 1.0);

			// End of OpenGL vertex shader
			// Correct for OpenGL clip coordinates
			// or glClipControl(GL_LOWER_LEFT, GL_ZERO_TO_ONE) in setup()
			//gl_Position.z = gl_Position.z * 2.0 - gl_Position.w;

			// End of Vulkan vertex shader
			// Correct for Vulkan clip coordinates
			// with glClipControl(GL_UPPER_LEFT, GL_ZERO_TO_ONE) for GL4.4
			gl_Position.y = -gl_Position.y; 

			fragmentColor = vertexColor;
		}
	)glsl";

	// Fragment shader
	const char* fragmentShaderSource_wvp = R"glsl(
		#version 330 core
		out vec4 color;
		in vec4 fragmentColor;
		void main()
		{
			color = fragmentColor;
		}
	)glsl";
#endif
#if 1
	//-----------
	const char* vertexShaderSource = R"glsl(
		#version 330 core
		layout(location = 0) in vec3 aPos;
		layout(location = 1) in vec4 vertexColor;
		out vec4 fragmentColor;
		void main()
		{
			gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
			fragmentColor = vertexColor;
		}
	)glsl";

	const char *fragmentShaderSource = R"glsl(
		#version 330 core
		out vec4 color;
		in vec4 fragmentColor;
		void main()
		{
			color = fragmentColor;
		}
	)glsl";
#endif
//-------------------------------------------------------------
//void set_texture_r(const char* tex_file_name, uint tex_stage, uint& texture)
//{
//	// Generate textures
//	glGenTextures(1, &texture);
//	gl_bind_texture(texture, tex_stage);
//	//gl_load_texture(m_texture, tex_file_name, false, GL_REPEAT, GL_LINEAR, GL_LINEAR, false);
//	gl_load_texture(tex_file_name, false, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR, false);	
//}
//void draw_texture_r(uint tex_stage, uint& texture)
//{
//	gl_bind_texture(texture, tex_stage);
//}