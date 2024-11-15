#pragma once

namespace gm
{

class vec2u {
public:
	union {
		struct { unsigned int x, y; };
		unsigned int e[2];
    };	

	vec2u() = default;
	vec2u(unsigned int x, unsigned int y) : x(x), y(y) {}
    explicit vec2u(unsigned int f) : x(f), y(f) {}

	constexpr static int size() { return 2; }	

	const unsigned int* data() const				{ return &e[0]; }
	unsigned int* data()							{ return &e[0]; }
	const unsigned int& operator [](int i) const	{ return e[i]; }
    unsigned int& operator [](int i)				{ return e[i]; }	
};

class vec2i {
public:
	union {
		struct { int x, y; };
		int e[2];
    };	

	vec2i() = default;
	vec2i(int x, int y) : x(x), y(y) {}
    explicit vec2i(int f) : x(f), y(f) {}

	constexpr static int size() { return 2; }	

	const int* data() const				{ return &e[0]; }
	int* data()							{ return &e[0]; }
	const int& operator [](int i) const	{ return e[i]; }
    int& operator [](int i)				{ return e[i]; }	
};


class vec2 {
public:
	union {
		struct { float x, y; };
		float e[2];
    };	

	vec2() = default;
	vec2(float x, float y) : x(x), y(y) {}
    explicit vec2(float f) : x(f), y(f) {}

	constexpr static int size() { return 2; }	

	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }	
};

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
	color4(float r, float g, float b) : r(r), g(g), b(b), a(1.0) {}
	explicit color4(vec4 a) : v(a) {}

	constexpr static int size() { return 4; }	

	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }	
};

class mat2 {
public:
	union {
		float e[4];
		float r[2][2];
	};

	mat2() = default;
	
	mat2(float m11, float m12,
		 float m21, float m22) 
    : e{ m11, m12,
		 m21, m22 } {}

    explicit mat2(float f) 
    : e{ f, 0,	
		 0, f } {} 
   

	constexpr static int size() { return 4; }	
	constexpr int dim() const	{ return 2; }	
	
	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }	
};

class mat3 {
public:
	union {
		float e[9];
		float r[3][3];
	};

	mat3() = default;
	
	mat3(float m11, float m12, float m13,
		 float m21, float m22, float m23,
		 float m31, float m32, float m33) 
    : e{ m11, m12, m13,
		 m21, m22, m23,
         m31, m32, m33 } {}

    explicit mat3(float f) 
    : e{ f, 0, 0,	
		 0, f, 0,	
		 0, 0, f } {} 
   

	constexpr static int size() { return 9; }	
	constexpr int dim() const	{ return 3; }	
	
	const float* data() const				{ return &e[0]; }
	float* data()							{ return &e[0]; }
	const float& operator [](int i) const	{ return e[i]; }
    float& operator [](int i)				{ return e[i]; }	
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
};

}