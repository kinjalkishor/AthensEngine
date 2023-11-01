#pragma once

// TO_ARRANGE:

#include <d3d9.h>
//#pragma comment(lib,"DXSDK_Jun10/Lib/x64/d3d9.lib")
#include "DXSDK_Jun10/Include/d3dx9.h"


//#include "base_def.h"
//#include "base_print.h"
//#include "base_gmath.h"
//#include "base_gmath2.h"

#include <fstream>


#define RS_MEDIA_PATHW(sub_path)				L"E:/nex/aw_media/" sub_path

//typedef struct _D3DMATERIAL9 {
//    D3DCOLORVALUE   Diffuse;       
//    D3DCOLORVALUE   Ambient;        
//    D3DCOLORVALUE   Specular;      
//    D3DCOLORVALUE   Emissive;      
//    float           Power;          
//} D3DMATERIAL9;

// d3d9_light
#if 0
enum class d3d9_light_type_e {
    light_point          = 1,
    light_spot           = 2,
    light_directional    = 3,
    light_force_dword	 = INT_MAX, //0x7fffffff, // force 32-bit size enum
};
struct d3d9_light {
    d3d9_light_type_e    type;            // Type of light source
    gm::color4		diffuse;         // Diffuse color of light
    gm::color4		specular;        // Specular color of light
    gm::color4		ambient;         // Ambient color of light
    gm::vec3		position;         // Position in world space
    gm::vec3		direction;        // Direction in world space
    float           range;            // Cutoff range
    float           falloff;          // Falloff
    float           attenuation0;     // Constant attenuation
    float           attenuation1;     // Linear attenuation
    float           attenuation2;     // Quadratic attenuation
    float           theta;            // Inner angle of spotlight cone
    float           phi;              // Outer angle of spotlight cone
};
#endif

//---
struct vertex_pnt {
	float x, y, z;
	float nx, ny, nz;	
	float u, v; 	
};



struct VertexFL {
	VertexFL(){}
	VertexFL(float x, float y, float z, 
		   float nx, float ny, float nz,
		   float u, float v) {
		_x  = x;  _y  = y;  _z  = z;
		_nx = nx; _ny = ny; _nz = nz;
		_u  = u;  _v  = v;
	}

	float _x, _y, _z;
	float _nx, _ny, _nz;
	float _u, _v;

	static const DWORD FVF;
};
const DWORD VertexFL::FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1;


//LIGHTS
namespace d3d
{
const D3DXCOLOR      WHITE(1.0, 1.0, 1.0, 1.0);
const D3DXCOLOR      BLACK(0.0, 0.0, 0.0, 1.0);
const D3DXCOLOR        RED(1.0, 0.0, 0.0, 1.0);
const D3DXCOLOR      GREEN(0.0, 1.0, 0.0, 1.0);
const D3DXCOLOR       BLUE(0.0, 0.0, 1.0, 1.0);
const D3DXCOLOR     YELLOW(1.0, 1.0, 0.0, 1.0);
const D3DXCOLOR       CYAN(0.0, 1.0, 1.0, 1.0);
const D3DXCOLOR    MAGENTA(1.0, 0.0, 1.0, 1.0);


const D3DXCOLOR BEACH_SAND( D3DCOLOR_XRGB(255, 249, 157) );
const D3DXCOLOR DESERT_SAND( D3DCOLOR_XRGB(250, 205, 135) );

const D3DXCOLOR LIGHTGREEN( D3DCOLOR_XRGB( 60, 184, 120) );
const D3DXCOLOR  PUREGREEN( D3DCOLOR_XRGB(  0, 166,  81) );
const D3DXCOLOR  DARKGREEN( D3DCOLOR_XRGB(  0, 114,  54) );

const D3DXCOLOR LIGHT_YELLOW_GREEN( D3DCOLOR_XRGB(124, 197, 118) );
const D3DXCOLOR  PURE_YELLOW_GREEN( D3DCOLOR_XRGB( 57, 181,  74) );
const D3DXCOLOR  DARK_YELLOW_GREEN( D3DCOLOR_XRGB( 25, 123,  48) );

const D3DXCOLOR LIGHTBROWN( D3DCOLOR_XRGB(198, 156, 109) );
const D3DXCOLOR DARKBROWN( D3DCOLOR_XRGB(115, 100,  87) );

// Lights
inline D3DLIGHT9 InitDirectionalLight(D3DXVECTOR3* direction, D3DXCOLOR* color) {
	D3DLIGHT9 light = {};

	light.Type      = D3DLIGHT_DIRECTIONAL;
	light.Ambient   = *color * 0.4f;
	light.Diffuse   = *color;
	light.Specular  = *color * 0.6f;
	light.Direction = *direction;

	return light;
}

inline D3DLIGHT9 InitPointLight(D3DXVECTOR3* position, D3DXCOLOR* color) {
	D3DLIGHT9 light = {};

	light.Type      = D3DLIGHT_POINT;
	light.Ambient   = *color * 0.4f;
	light.Diffuse   = *color;
	light.Specular  = *color * 0.6f;
	light.Position  = *position;
	light.Range        = 1000.0f;
	light.Falloff      = 1.0f;
	light.Attenuation0 = 1.0f;
	light.Attenuation1 = 0.0f;
	light.Attenuation2 = 0.0f;

	return light;
}

inline D3DLIGHT9 InitSpotLight(D3DXVECTOR3* position, D3DXVECTOR3* direction, D3DXCOLOR* color) {
	D3DLIGHT9 light = {};

	light.Type      = D3DLIGHT_SPOT;
	light.Ambient   = *color * 0.4f;
	light.Diffuse   = *color;
	light.Specular  = *color * 0.6f;
	light.Position  = *position;
	light.Direction = *direction;
	light.Range        = 1000.0f;
	light.Falloff      = 1.0f;
	light.Attenuation0 = 1.0f;
	light.Attenuation1 = 0.0f;
	light.Attenuation2 = 0.0f;
	light.Theta        = 0.5f;
	light.Phi          = 0.7f;

	return light;
}

// Materials
inline D3DMATERIAL9 InitMtrl(D3DXCOLOR a, D3DXCOLOR d, D3DXCOLOR s, D3DXCOLOR e, float p) {
	D3DMATERIAL9 mtrl = {};
	mtrl.Ambient  = a;
	mtrl.Diffuse  = d;
	mtrl.Specular = s;
	mtrl.Emissive = e;
	mtrl.Power    = p;
	return mtrl;
}
	
const D3DMATERIAL9 WHITE_MTRL  = InitMtrl(WHITE, WHITE, WHITE, BLACK, 2.0f);
const D3DMATERIAL9 RED_MTRL    = InitMtrl(RED, RED, RED, BLACK, 2.0f);
const D3DMATERIAL9 GREEN_MTRL  = InitMtrl(GREEN, GREEN, GREEN, BLACK, 2.0f);
const D3DMATERIAL9 BLUE_MTRL   = InitMtrl(BLUE, BLUE, BLUE, BLACK, 2.0f);
const D3DMATERIAL9 YELLOW_MTRL = InitMtrl(YELLOW, YELLOW, YELLOW, BLACK, 2.0f);
}



namespace d3d
{

// Constants
inline const float INFINITY_D3D9 = FLT_MAX;
inline const float EPSILON  = 0.001f;


//inline DWORD FtoDw(float f) {
//	return *((DWORD*)&f);
//}
inline DWORD float_to_dword(float const number) {
    return *rcast<DWORD const*>(&number);
}

inline float dword_to_float(DWORD const bits) {
    return *rcast<float const*>(&bits);
}

inline float Lerp(float a, float b, float t) {
	return a - (a*t) + (b*t);
}

inline float GetRandomFloat(float lowBound, float highBound) {
	// bad input
	if (lowBound >= highBound) { 
		return lowBound;
	}

	// get random float in [0, 1] interval
	float f = (rand() % 10000) * 0.0001f; 

	// return float in [lowBound, highBound] interval. 
	return (f * (highBound - lowBound)) + lowBound; 
}

inline void GetRandomVector(D3DXVECTOR3* out, D3DXVECTOR3* min, D3DXVECTOR3* max) {
	out->x = GetRandomFloat(min->x, max->x);
	out->y = GetRandomFloat(min->y, max->y);
	out->z = GetRandomFloat(min->z, max->z);
}


// Bounding Objects
struct BoundingBox {
	D3DXVECTOR3 _min;
	D3DXVECTOR3 _max;

	BoundingBox() {
		// infinite small 
		_min.x = d3d::INFINITY_D3D9;
		_min.y = d3d::INFINITY_D3D9;
		_min.z = d3d::INFINITY_D3D9;

		_max.x = -d3d::INFINITY_D3D9;
		_max.y = -d3d::INFINITY_D3D9;
		_max.z = -d3d::INFINITY_D3D9;
	}

	bool isPointInside(D3DXVECTOR3& p) {
		if (p.x >= _min.x && p.y >= _min.y && p.z >= _min.z &&
			p.x <= _max.x && p.y <= _max.y && p.z <= _max.z) {
			return true;
		} else { 
			return false;
		}
	}	
};

struct BoundingSphere {
	D3DXVECTOR3 _center;
	float       _radius;

	BoundingSphere() {
		_radius = 0.0f;
	}	
};

struct Ray {
	D3DXVECTOR3 _origin;
	D3DXVECTOR3 _direction;
};

inline bool ComputeBoundingSphere(ID3DXMesh* mesh, d3d::BoundingSphere* sphere) {
	HRESULT hr = 0;

	BYTE* v = 0;
	mesh->LockVertexBuffer(0, (void**)&v);

	hr = D3DXComputeBoundingSphere(
			(D3DXVECTOR3*)v,
			mesh->GetNumVertices(),
			D3DXGetFVFVertexSize(mesh->GetFVF()),
			&sphere->_center,
			&sphere->_radius);

	mesh->UnlockVertexBuffer();

	if (FAILED(hr)) {
		return false;
	}

	return true;
}

inline bool ComputeBoundingBox(ID3DXMesh* mesh, d3d::BoundingBox* box) {
	HRESULT hr = 0;

	BYTE* v = 0;
	mesh->LockVertexBuffer(0, (void**)&v);

	hr = D3DXComputeBoundingBox(
			(D3DXVECTOR3*)v,
			mesh->GetNumVertices(),
			D3DXGetFVFVertexSize(mesh->GetFVF()),
			&box->_min,
			&box->_max);

	mesh->UnlockVertexBuffer();

	if (FAILED(hr)) {
		return false;
	}

	return true;
}


// PICKING
Ray CalcPickingRay(IDirect3DDevice9* device, int x, int y) {
	float px = 0.0f;
	float py = 0.0f;

	D3DVIEWPORT9 vp;
	device->GetViewport(&vp);

	D3DXMATRIX proj;
	device->GetTransform(D3DTS_PROJECTION, &proj);

	px = ((( 2.0f*x) / vp.Width)  - 1.0f) / proj(0, 0);
	py = (((-2.0f*y) / vp.Height) + 1.0f) / proj(1, 1);

	d3d::Ray ray;
	ray._origin    = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	ray._direction = D3DXVECTOR3(px, py, 1.0f);

	return ray;
}

void TransformRay(Ray* ray, D3DXMATRIX* T) {
	// transform the ray's origin, w = 1.
	D3DXVec3TransformCoord(
		&ray->_origin,
		&ray->_origin,
		T);

	// transform the ray's direction, w = 0.
	D3DXVec3TransformNormal(
		&ray->_direction,
		&ray->_direction,
		T);

	// normalize the direction
	D3DXVec3Normalize(&ray->_direction, &ray->_direction);
}

bool RaySphereIntTest(Ray* ray, BoundingSphere* sphere) {
	D3DXVECTOR3 v = ray->_origin - sphere->_center;

	float b = 2.0f * D3DXVec3Dot(&ray->_direction, &v);
	float c = D3DXVec3Dot(&v, &v) - (sphere->_radius * sphere->_radius);

	// find the discriminant
	float discriminant = (b * b) - (4.0f * c);

	// test for imaginary number
	if (discriminant < 0.0f) {
		return false;
	}

	discriminant = sqrtf(discriminant);

	float s0 = (-b + discriminant) / 2.0f;
	float s1 = (-b - discriminant) / 2.0f;

	// if a solution is >= 0, then we intersected the sphere
	if (s0 >= 0.0f || s1 >= 0.0f) {
		return true;
	}
	
	return false;
}

// Drawing
// Function references "desert.bmp" internally.  This file must
// be in the working directory.
// Pass in 0 for device for cleanup.
// scale is uniform scale 
inline bool DrawBasicScene(IDirect3DDevice9* device, float scale) {
	static IDirect3DVertexBuffer9* floor  = 0;
	static IDirect3DTexture9*      tex    = 0;
	static ID3DXMesh*              pillar = 0;

	HRESULT hr = 0;

	if (device == 0) {
		if (floor && tex && pillar) {
			// they already exist, destroy them
			com_release(floor);
			com_release(tex);
			com_release(pillar);
		}
	} else if (!floor && !tex && !pillar) {
		// they don't exist, create them
		device->CreateVertexBuffer(
			6 * sizeof(VertexFL),
			0, 
			VertexFL::FVF,
			D3DPOOL_MANAGED,
			&floor,
			0);

		VertexFL* v = 0;
		floor->Lock(0, 0, (void**)&v, 0);

		v[0] = VertexFL(-20.0f, -2.5f, -20.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f);
		v[1] = VertexFL(-20.0f, -2.5f,  20.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
		v[2] = VertexFL( 20.0f, -2.5f,  20.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);

		v[3] = VertexFL(-20.0f, -2.5f, -20.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f);
		v[4] = VertexFL( 20.0f, -2.5f,  20.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
		v[5] = VertexFL( 20.0f, -2.5f, -20.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f);

		floor->Unlock();

		D3DXCreateCylinder(device, 0.5f, 0.5f, 5.0f, 20, 20, &pillar, 0);

		D3DXCreateTextureFromFile(
			device,
			RS_MEDIA_PATHW(L"tut/d3d_fl/tex/grass1.bmp"),
			&tex);
	} else {

		// Pre-Render Setup
		device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
		device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
		device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);

		D3DXVECTOR3 dir(0.707f, -0.707f, 0.707f);
		D3DXCOLOR col(1.0f, 1.0f, 1.0f, 1.0f);
		D3DLIGHT9 light = d3d::InitDirectionalLight(&dir, &col);

		device->SetLight(0, &light);
		device->LightEnable(0, true);
		device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
		device->SetRenderState(D3DRS_SPECULARENABLE, true);


		// Render
		D3DXMATRIX T, R, P, S;

		D3DXMatrixScaling(&S, scale, scale, scale);

		// used to rotate cylinders to be parallel with world's y-axis
		D3DXMatrixRotationX(&R, -D3DX_PI * 0.5f);

		// draw floor
		D3DXMatrixIdentity(&T);
		T = T * S;
		device->SetTransform(D3DTS_WORLD, &T);
		device->SetMaterial(&d3d::WHITE_MTRL);
		device->SetTexture(0, tex);
		device->SetStreamSource(0, floor, 0, sizeof(VertexFL));
		device->SetFVF(VertexFL::FVF);
		device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
		
		// draw pillars
		device->SetMaterial(&d3d::BLUE_MTRL);
		device->SetTexture(0, 0);
		for(int i = 0; i < 5; i++) {
			D3DXMatrixTranslation(&T, -5.0f, 0.0f, -15.0f + (i * 7.5f));
			P = R * T * S;
			device->SetTransform(D3DTS_WORLD, &P);
			pillar->DrawSubset(0);

			D3DXMatrixTranslation(&T, 5.0f, 0.0f, -15.0f + (i * 7.5f));
			P = R * T * S;
			device->SetTransform(D3DTS_WORLD, &P);
			pillar->DrawSubset(0);
		}
	}
	return true;
}



//===============================================================


}

// FPSCounter
#if 0
class FPSCounter {
public:
	FPSCounter(IDirect3DDevice9* device) {
		_device = device;

		_font = new CD3DFont("Times New Roman", 24, 0);
		_font->InitDeviceObjects( _device );
		_font->RestoreDeviceObjects();

		_frameCnt = 0;
		_timeElapsed = 0.0f;
		_fps         = 0.0f;
	}

	~FPSCounter() {
		if (_font) {
			_font->InvalidateDeviceObjects();
			_font->DeleteDeviceObjects();
			delete _font;
		}
	}

	bool render(D3DCOLOR color, float timeDelta) {
		if (_font) {
			_frameCnt++;

			_timeElapsed += timeDelta;

			if(_timeElapsed >= 1.0f) {
				_fps = (float)_frameCnt / _timeElapsed;

				sprintf(_fpsString, "%f", _fps);
				_fpsString[8] = '\0'; // mark end of string

				_timeElapsed = 0.0f;
				_frameCnt    = 0;
			}

			_font->DrawText(20, 20, color, _fpsString);	
		}
		return true;
	}


private:
	IDirect3DDevice9* _device;
	
	CD3DFont* _font;
	DWORD     _frameCnt;
	float     _timeElapsed;
	float     _fps;
	char      _fpsString[9];
	
};
#endif

//=============================================
// Terrain
//=============================================
class Terrain {
public:
	Terrain(
		IDirect3DDevice9* device,
		std::string heightmapFileName, 
		int numVertsPerRow,  
		int numVertsPerCol, 
		int cellSpacing,    // space between cells
		float heightScale) {
		_device         = device;
		_numVertsPerRow = numVertsPerRow;
		_numVertsPerCol = numVertsPerCol;
		_cellSpacing    = cellSpacing;

		_numCellsPerRow = _numVertsPerRow - 1;
		_numCellsPerCol = _numVertsPerCol - 1;

		_width = _numCellsPerRow * _cellSpacing;
		_depth = _numCellsPerCol * _cellSpacing;

		_numVertices  = _numVertsPerRow * _numVertsPerCol;
		_numTriangles = _numCellsPerRow * _numCellsPerCol * 2;

		_heightScale = heightScale;

		// load heightmap
		if (!readRawFile(heightmapFileName)) {
			MessageBox(0, L"readRawFile - FAILED", 0, 0);
		}

		// scale heights
		for(int i = 0; i < _heightmap.size(); i++)
			_heightmap[i] *= heightScale;

		// compute the vertices
		if (!computeVertices()) {
			MessageBox(0, L"computeVertices - FAILED", 0, 0);
		}

		// compute the indices
		if (!computeIndices()) {
			MessageBox(0, L"computeIndices - FAILED", 0, 0);
		}
	}

	~Terrain() {
		com_release(_vb);
		com_release(_ib);
		com_release(_tex);
	}

	int  getHeightmapEntry(int row, int col) {
		return _heightmap[row * _numVertsPerRow + col];
	}

	void setHeightmapEntry(int row, int col, int value) {
		_heightmap[row * _numVertsPerRow + col] = value;
	}

	float getHeight(float x, float z) {
		// Translate on xz-plane by the transformation that takes
		// the terrain START point to the origin.
		x = ((float)_width / 2.0f) + x;
		z = ((float)_depth / 2.0f) - z;

		// Scale down by the transformation that makes the 
		// cellspacing equal to one.  This is given by 
		// 1 / cellspacing since; cellspacing * 1 / cellspacing = 1.
		x /= (float)_cellSpacing;
		z /= (float)_cellSpacing;

		// From now on, we will interpret our positive z-axis as
		// going in the 'down' direction, rather than the 'up' direction.
		// This allows to extract the row and column simply by 'flooring'
		// x and z:

		float col = ::floorf(x);
		float row = ::floorf(z);

		// get the heights of the quad we're in:
		// 
		//  A   B
		//  *---*
		//  | / |
		//  *---*  
		//  C   D

		float A = getHeightmapEntry(row,   col);
		float B = getHeightmapEntry(row,   col+1);
		float C = getHeightmapEntry(row+1, col);
		float D = getHeightmapEntry(row+1, col+1);


		// Find the triangle we are in:
		//-----------------------------

		// Translate by the transformation that takes the upper-left
		// corner of the cell we are in to the origin.  Recall that our 
		// cellspacing was nomalized to 1.  Thus we have a unit square
		// at the origin of our +x -> 'right' and +z -> 'down' system.
		float dx = x - col;
		float dz = z - row;

		// Note the below compuations of u and v are unneccessary, we really
		// only need the height, but we compute the entire vector to emphasis
		// the books discussion.
		float height = 0.0f;
		if(dz < 1.0f - dx) {	
			// upper triangle ABC
			float uy = B - A; // A->B
			float vy = C - A; // A->C

			// Linearly interpolate on each vector.  The height is the vertex
			// height the vectors u and v originate from {A}, plus the heights
			// found by interpolating on each vector u and v.
			height = A + d3d::Lerp(0.0f, uy, dx) + d3d::Lerp(0.0f, vy, dz);
		} else {	
			// lower triangle DCB
			float uy = C - D; // D->C
			float vy = B - D; // D->B

			// Linearly interpolate on each vector.  The height is the vertex
			// height the vectors u and v originate from {D}, plus the heights
			// found by interpolating on each vector u and v.
			height = D + d3d::Lerp(0.0f, uy, 1.0f - dx) + d3d::Lerp(0.0f, vy, 1.0f - dz);
		}

		return height;
	}


	//bool  loadTexture(std::string fileName)
	bool  loadTexture(const char* fileName) {
		HRESULT hr = 0;

		sdf::wstring_st<255> wTextureFilename;
		sdf::string_st_wcs_from_mbs(wTextureFilename, fileName, sdf::strfz_len(fileName));
		
		hr = D3DXCreateTextureFromFile(
			_device,
			//fileName.c_str(),
			wTextureFilename.c_str(),
			&_tex);

		if(FAILED(hr)) {
			return false;
		}

		return true;
	}

	bool  genTexture(D3DXVECTOR3* directionToLight, int version)
	{
		// Method fills the top surface of a texture procedurally.  Then
		// lights the top surface.  Finally, it fills the other mipmap
		// surfaces based on the top surface data using D3DXFilterTexture.

		HRESULT hr = 0;

		// texel for each quad cell
		int texWidth  = _numCellsPerRow;
		int texHeight = _numCellsPerCol;

		// create an empty texture
		hr = D3DXCreateTexture(
			_device,
			texWidth, texHeight,
			0, // create a complete mipmap chain
			0, // usage
			D3DFMT_X8R8G8B8,// 32 bit XRGB format
			D3DPOOL_MANAGED, &_tex);

		if(FAILED(hr)) {
			return false;
		}

		D3DSURFACE_DESC textureDesc; 
		_tex->GetLevelDesc(0 /*level*/, &textureDesc);

		// make sure we got the requested format because our code 
		// that fills the texture is hard coded to a 32 bit pixel depth.
		if (textureDesc.Format != D3DFMT_X8R8G8B8) {
			return false;
		}
		
		D3DLOCKED_RECT lockedRect;
		_tex->LockRect(0/*lock top surface*/, &lockedRect, 
			0 /* lock entire tex*/, 0/*flags*/);         

		DWORD* imageData = (DWORD*)lockedRect.pBits;
		for(int i = 0; i < texHeight; i++) {
			for(int j = 0; j < texWidth; j++) {
				D3DXCOLOR c;

				// get height of upper left vertex of quad.
				float height = (float)getHeightmapEntry(i, j) / _heightScale;

				if ((height) < 42.5f) 			{ c = d3d::BEACH_SAND; }
				else if ((height) < 85.0f)		{ c = d3d::LIGHT_YELLOW_GREEN; }
				else if ((height) < 127.5f)		{ c = d3d::PUREGREEN; }
				else if ((height) < 170.0f)		{ c = d3d::DARK_YELLOW_GREEN; }
				else if ((height) < 212.5f)		{ c = d3d::DARKBROWN; }
				else							{ c = d3d::WHITE; }

				// fill locked data, note we divide the pitch by four because the
				// pitch is given in bytes and there are 4 bytes per DWORD.
				imageData[i * lockedRect.Pitch / 4 + j] = (D3DCOLOR)c;
			}
		}

		_tex->UnlockRect(0);

		if (version == 1) {
			if(!lightTerrain(directionToLight, 1)) {
				::MessageBox(0, L"lightTerrain1() - FAILED", 0, 0);
				return false;
			}
		} else if (version == 2) {
			if(!lightTerrain(directionToLight, 2)) {
				::MessageBox(0, L"lightTerrain2() - FAILED", 0, 0);
				return false;
			}
		}
	
		hr = D3DXFilterTexture(
			_tex,
			0, // default palette
			0, // use top level as source level
			D3DX_DEFAULT); // default filter

		if(FAILED(hr)) {
			::MessageBox(0, L"D3DXFilterTexture() - FAILED", 0, 0);
			return false;
		}

		return true;
	}

	bool  draw(D3DXMATRIX* world, bool drawTris) {
		HRESULT hr = 0;

		if (_device) {
			_device->SetTransform(D3DTS_WORLD, world);

			_device->SetStreamSource(0, _vb, 0, sizeof(TerrainVertex));
			_device->SetFVF(TerrainVertex::FVF);
			_device->SetIndices(_ib);
		
			_device->SetTexture(0, _tex);

			// turn off lighting since we're lighting it ourselves
			_device->SetRenderState(D3DRS_LIGHTING, false);

			hr =_device->DrawIndexedPrimitive(
				D3DPT_TRIANGLELIST,
				0,
				0,
				_numVertices,
				0,
				_numTriangles);

			_device->SetRenderState(D3DRS_LIGHTING, true);

			if (drawTris) {
				_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
				hr =_device->DrawIndexedPrimitive(
					D3DPT_TRIANGLELIST,
					0,
					0,
					_numVertices,
					0,
					_numTriangles);

				_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
			}

			if(FAILED(hr)) {
				return false;
			}
		}

		return true;
	}

private:
	IDirect3DDevice9*       _device;
	IDirect3DTexture9*      _tex;
	IDirect3DVertexBuffer9* _vb;
	IDirect3DIndexBuffer9*  _ib;

	int _numVertsPerRow;
	int _numVertsPerCol;
	int _cellSpacing;

	int _numCellsPerRow;
	int _numCellsPerCol;
	int _width;
	int _depth;
	int _numVertices;
	int _numTriangles;

	float _heightScale;

	std::vector<int> _heightmap;

	// helper methods
	bool  readRawFile(std::string fileName) {
		// Restriction: RAW file dimensions must be >= to the
		// dimensions of the terrain.  That is a 128x128 RAW file
		// can only be used with a terrain constructed with at most
		// 128x128 vertices.

		// A height for each vertex
		std::vector<BYTE> in( _numVertices );

		std::ifstream inFile(fileName.c_str(), std::ios_base::binary);

		if (!inFile) {
			return false;
		}

		inFile.read(
			(char*)&in[0],	// buffer
			in.size());		// number of bytes to read into buffer

		inFile.close();

		// copy BYTE vector to int vector
		_heightmap.resize( _numVertices );

		for(int i = 0; i < in.size(); i++) {
			_heightmap[i] = in[i];
		}

		return true;
	}

	bool  computeVertices() {
		HRESULT hr = 0;

		hr = _device->CreateVertexBuffer(
			_numVertices * sizeof(TerrainVertex),
			D3DUSAGE_WRITEONLY,
			TerrainVertex::FVF,
			D3DPOOL_MANAGED,
			&_vb,
			0);

		if(FAILED(hr)) {
			return false;
		}

		// coordinates to start generating vertices at
		int startX = -_width / 2;
		int startZ =  _depth / 2;

		// coordinates to end generating vertices at
		int endX =  _width / 2;
		int endZ = -_depth / 2;

		// compute the increment size of the texture coordinates
		// from one vertex to the next.
		float uCoordIncrementSize = 1.0f / (float)_numCellsPerRow;
		float vCoordIncrementSize = 1.0f / (float)_numCellsPerCol;

		TerrainVertex* v = 0;
		_vb->Lock(0, 0, (void**)&v, 0);

		int i = 0;
		for(int z = startZ; z >= endZ; z -= _cellSpacing) {
			int j = 0;
			for(int x = startX; x <= endX; x += _cellSpacing) {
				// compute the correct index into the vertex buffer and heightmap
				// based on where we are in the nested loop.
				int index = i * _numVertsPerRow + j;

				v[index] = TerrainVertex(
					(float)x,
					(float)_heightmap[index],
					(float)z,
					(float)j * uCoordIncrementSize,
					(float)i * vCoordIncrementSize);

				j++; // next column
			}
			i++; // next row
		}

		_vb->Unlock();

		return true;
	}

	bool  computeIndices() {
		HRESULT hr = 0;

		//hr = _device->CreateIndexBuffer(
		//	_numTriangles * 3 * sizeof(WORD), // 3 indices per triangle
		//	D3DUSAGE_WRITEONLY,
		//	D3DFMT_INDEX16,
		//	D3DPOOL_MANAGED,
		//	&_ib,
		//	0);
		//if(FAILED(hr))
		//	return false;
		//WORD* indices = 0;


		hr = _device->CreateIndexBuffer(
		_numTriangles * 3 * sizeof(DWORD), // 3 indices per triangle
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX32,
		D3DPOOL_MANAGED,
		&_ib,
		0);
		if(FAILED(hr)) {
			return false;
		}
		DWORD* indices = 0;


		_ib->Lock(0, 0, (void**)&indices, 0);

		// index to start of a group of 6 indices that describe the
		// two triangles that make up a quad
		int baseIndex = 0;

		// loop through and compute the triangles of each quad
		for(int i = 0; i < _numCellsPerCol; i++) {
			for(int j = 0; j < _numCellsPerRow; j++) {
				indices[baseIndex]     =   i   * _numVertsPerRow + j;
				indices[baseIndex + 1] =   i   * _numVertsPerRow + j + 1;
				indices[baseIndex + 2] = (i+1) * _numVertsPerRow + j;

				indices[baseIndex + 3] = (i+1) * _numVertsPerRow + j;
				indices[baseIndex + 4] =   i   * _numVertsPerRow + j + 1;
				indices[baseIndex + 5] = (i+1) * _numVertsPerRow + j + 1;

				// next quad
				baseIndex += 6;
			}
		}

		_ib->Unlock();

		return true;
	}

	bool  lightTerrain(D3DXVECTOR3* directionToLight, int version) {
		HRESULT hr = 0;

		D3DSURFACE_DESC textureDesc; 
		_tex->GetLevelDesc(0 /*level*/, &textureDesc);

		// make sure we got the requested format because our code that fills the
		// texture is hard coded to a 32 bit pixel depth.
		if (textureDesc.Format != D3DFMT_X8R8G8B8) {
			return false;
		}
		
		D3DLOCKED_RECT lockedRect;
		_tex->LockRect(
			0,          // lock top surface level in mipmap chain
			&lockedRect,// pointer to receive locked data
			0,          // lock entire texture image
			0);         // no lock flags specified

		DWORD* imageData = (DWORD*)lockedRect.pBits;
		for(int i = 0; i < textureDesc.Height; i++) {
			for(int j = 0; j < textureDesc.Width; j++) {
				// index into texture, note we use the pitch and divide by 
				// four since the pitch is given in bytes and there are 
				// 4 bytes per DWORD.
				int index = i * lockedRect.Pitch / 4 + j;

				// get current color of quad
				D3DXCOLOR c( imageData[index] );

				if (version == 1) {
					// shade current quad
					c *= computeShade(i, j, directionToLight);
					// save shaded color
					imageData[index] = (D3DCOLOR)c;
				} else if (version == 2) {
					// shade current quad
					//c *= computeShade(i, j, directionToLight);
					// save shaded color
					//imageData[index] = (D3DCOLOR)c;
					// Ignores terrain color. Shows only light shading.
					float s = computeShade(i, j, directionToLight);
					imageData[index] = D3DXCOLOR(s,s,s,1.0f);
				}

			}
		}

		_tex->UnlockRect(0);

		return true;
	}

	float computeShade(int cellRow, int cellCol, D3DXVECTOR3* directionToLight) {
		// get heights of three vertices on the quad
		float heightA = getHeightmapEntry(cellRow,   cellCol);
		float heightB = getHeightmapEntry(cellRow,   cellCol+1);
		float heightC = getHeightmapEntry(cellRow+1, cellCol);

		// build two vectors on the quad
		D3DXVECTOR3 u(_cellSpacing, heightB - heightA, 0.0f);
		D3DXVECTOR3 v(0.0f,         heightC - heightA, -_cellSpacing);

		// find the normal by taking the cross product of two
		// vectors on the quad.
		D3DXVECTOR3 n;
		D3DXVec3Cross(&n, &u, &v);
		D3DXVec3Normalize(&n, &n);

		float cosine = D3DXVec3Dot(&n, directionToLight);

		if (cosine < 0.0f) {
			cosine = 0.0f;
		}

		return cosine;
	}


	struct TerrainVertex {
		TerrainVertex(){}
		TerrainVertex(float x, float y, float z, float u, float v) {
			_x = x; _y = y; _z = z; _u = u; _v = v;
		}
		float _x, _y, _z;
		float _u, _v;

		static const DWORD FVF;
	};
};

inline const DWORD Terrain::TerrainVertex::FVF = D3DFVF_XYZ | D3DFVF_TEX1;


//=============================================
// Particle system
//=============================================
//#include "rs_camera_la.h"
#include <list>

namespace psys
{

struct Particle {
	D3DXVECTOR3 _position;
	D3DCOLOR    _color;
	static const DWORD FVF;
};
	
const DWORD Particle::FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE;

struct Attribute {
	Attribute() {
		_lifeTime = 0.0f;
		_age      = 0.0f;
		_isAlive  = true;
	}

	D3DXVECTOR3 _position;     
	D3DXVECTOR3 _velocity;     
	D3DXVECTOR3 _acceleration; 
	float       _lifeTime;     // how long the particle lives for before dying  
	float       _age;          // current age of the particle  
	D3DXCOLOR   _color;        // current color of the particle   
	D3DXCOLOR   _colorFade;    // how the color fades with respect to time
	bool        _isAlive;    
};


class PSystem {
public:
	PSystem() {
		_device = 0;
		_vb     = 0;
		_tex    = 0;
	}

	virtual ~PSystem() {
		com_release(_vb);
		com_release(_tex);
	}


	virtual bool init(IDirect3DDevice9* device, const char* texFileName) {
		// vertex buffer's size does not equal the number of particles in our system.  We
		// use the vertex buffer to draw a portion of our particles at a time.  The arbitrary
		// size we choose for the vertex buffer is specified by the _vbSize variable.

		_device = device; // save a ptr to the device

		HRESULT hr = 0;

		hr = device->CreateVertexBuffer(
			_vbSize * sizeof(Particle),
			D3DUSAGE_DYNAMIC | D3DUSAGE_POINTS | D3DUSAGE_WRITEONLY,
			Particle::FVF,
			D3DPOOL_DEFAULT, // D3DPOOL_MANAGED can't be used with D3DUSAGE_DYNAMIC 
			&_vb,
			0);
	
		if (FAILED(hr)) {
			::MessageBox(0, L"CreateVertexBuffer() - FAILED", L"PSystem", 0);
			return false;
		}

		sdf::wstring_st<255> wTextureFilename;
		sdf::string_st_wcs_from_mbs(wTextureFilename, texFileName, sdf::strfz_len(texFileName));
	
		hr = D3DXCreateTextureFromFile(
			device,
			wTextureFilename.c_str(),
			&_tex);

		if (FAILED(hr)) {
			::MessageBox(0, L"D3DXCreateTextureFromFile() - FAILED", L"PSystem", 0);
			return false;
		}

		return true;
	}

	virtual void reset() {
		std::list<Attribute>::iterator i;
		for(i = _particles.begin(); i != _particles.end(); i++) {
			resetParticle( &(*i) );
		}
	}
		
	// sometimes we don't want to free the memory of a dead particle,
	// but rather respawn it instead.
	virtual void resetParticle(Attribute* attribute) = 0;

	virtual void addParticle() {
		Attribute attribute;

		resetParticle(&attribute);

		_particles.push_back(attribute);
	}

	virtual void update(float timeDelta) = 0;

	virtual void preRender() {
		_device->SetRenderState(D3DRS_LIGHTING, false);
		_device->SetRenderState(D3DRS_POINTSPRITEENABLE, true);
		_device->SetRenderState(D3DRS_POINTSCALEENABLE, true); 
		_device->SetRenderState(D3DRS_POINTSIZE, d3d::float_to_dword(_size));
		_device->SetRenderState(D3DRS_POINTSIZE_MIN, d3d::float_to_dword(0.0f));

		// control the size of the particle relative to distance
		_device->SetRenderState(D3DRS_POINTSCALE_A, d3d::float_to_dword(0.0f));
		_device->SetRenderState(D3DRS_POINTSCALE_B, d3d::float_to_dword(0.0f));
		_device->SetRenderState(D3DRS_POINTSCALE_C, d3d::float_to_dword(1.0f));
		
		// use alpha from texture
		_device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
		_device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);

		_device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
		_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	}

	virtual void render() {

		// Remarks:  The render method works by filling a section of the vertex buffer with data,
		//           then we render that section.  While that section is rendering we lock a new
		//           section and begin to fill that section.  Once that sections filled we render it.
		//           This process continues until all the particles have been drawn.  The benifit
		//           of this method is that we keep the video card and the CPU busy.  

		if (!_particles.empty()) {

			// set render states
			preRender();
		
			_device->SetTexture(0, _tex);
			_device->SetFVF(Particle::FVF);
			_device->SetStreamSource(0, _vb, 0, sizeof(Particle));


			// render batches one by one

			// start at beginning if we're at the end of the vb
			if(_vbOffset >= _vbSize) {
				_vbOffset = 0;
			}

			Particle* v = 0;

			_vb->Lock(
				_vbOffset    * sizeof( Particle ),
				_vbBatchSize * sizeof( Particle ),
				(void**)&v,
				_vbOffset ? D3DLOCK_NOOVERWRITE : D3DLOCK_DISCARD);

			DWORD numParticlesInBatch = 0;


			// Until all particles have been rendered.
			std::list<Attribute>::iterator i;
			for(i = _particles.begin(); i != _particles.end(); i++) {
				if (i->_isAlive) {
					//
					// Copy a batch of the living particles to the
					// next vertex buffer segment
					//
					v->_position = i->_position;
					v->_color    = (D3DCOLOR)i->_color;
					v++; // next element;

					numParticlesInBatch++; //increase batch counter

					// if this batch full?
					if(numParticlesInBatch == _vbBatchSize) {
						//
						// Draw the last batch of particles that was
						// copied to the vertex buffer. 
						//
						_vb->Unlock();

						_device->DrawPrimitive(
							D3DPT_POINTLIST,
							_vbOffset,
							_vbBatchSize);


						// While that batch is drawing, start filling the
						// next batch with particles.

						// move the offset to the start of the next batch
						_vbOffset += _vbBatchSize; 

						// don't offset into memory thats outside the vb's range.
						// If we're at the end, start at the beginning.
						if(_vbOffset >= _vbSize) {
							_vbOffset = 0;       
						}

						_vb->Lock(
							_vbOffset    * sizeof( Particle ),
							_vbBatchSize * sizeof( Particle ),
							(void**)&v,
							_vbOffset ? D3DLOCK_NOOVERWRITE : D3DLOCK_DISCARD);

						numParticlesInBatch = 0; // reset for new batch
					}	
				}
			}

			_vb->Unlock();

			// its possible that the LAST batch being filled never 
			// got rendered because the condition 
			// (numParticlesInBatch == _vbBatchSize) would not have
			// been satisfied.  We draw the last partially filled batch now.
		
			if (numParticlesInBatch) {
				_device->DrawPrimitive(
					D3DPT_POINTLIST,
					_vbOffset,
					numParticlesInBatch);
			}

			// next block
			_vbOffset += _vbBatchSize; 


			// reset render states
			postRender();
		}
	}

	virtual void postRender() {
		_device->SetRenderState(D3DRS_LIGHTING,          true);
		_device->SetRenderState(D3DRS_POINTSPRITEENABLE, false);
		_device->SetRenderState(D3DRS_POINTSCALEENABLE,  false);
		_device->SetRenderState(D3DRS_ALPHABLENDENABLE,  false);
	}

	bool isEmpty() {
		return _particles.empty();
	}

	bool isDead() {
		std::list<Attribute>::iterator i;
		for(i = _particles.begin(); i != _particles.end(); i++) {
			// is there at least one living particle?  If yes,
			// the system is not dead.
			if (i->_isAlive) {
				return false;
			}
		}
		// no living particles found, the system must be dead.
		return true;
	}


	virtual void removeDeadParticles() {
		std::list<Attribute>::iterator i;

		i = _particles.begin();

		while( i != _particles.end()) {
			if (i->_isAlive == false) {
				// erase returns the next iterator, so no need to
				// incrememnt to the next one ourselves.
				i = _particles.erase(i); 
			} else {
				i++; // next in list
			}
		}
	}

protected:
	IDirect3DDevice9*       _device;
	D3DXVECTOR3             _origin;
	d3d::BoundingBox        _boundingBox;
	float                   _emitRate;   // rate new particles are added to system
	float                   _size;       // size of particles
	IDirect3DTexture9*      _tex;
	IDirect3DVertexBuffer9* _vb;
	std::list<Attribute>    _particles;
	int                     _maxParticles; // max allowed particles system can have

	//
	// Following three data elements used for rendering the p-system efficiently
	//

	DWORD _vbSize;      // size of vb
	DWORD _vbOffset;    // offset in vb to lock   
	DWORD _vbBatchSize; // number of vertices to lock starting at _vbOffset
};

//***************
// Snow System
//***************

class Snow : public PSystem {
public:
	Snow(d3d::BoundingBox* boundingBox, int numParticles) {
		_boundingBox   = *boundingBox;
		_size          = 0.25f;
		_vbSize        = 2048;
		_vbOffset      = 0; 
		_vbBatchSize   = 512; 
	
		for(int i = 0; i < numParticles; i++) {
			addParticle();
		}
	}

	void resetParticle(Attribute* attribute) {
		attribute->_isAlive = true;

		// get random x, z coordinate for the position of the snow flake.
		d3d::GetRandomVector(
			&attribute->_position,
			&_boundingBox._min,
			&_boundingBox._max);

		// no randomness for height (y-coordinate).  Snow flake
		// always starts at the top of bounding box.
		attribute->_position.y = _boundingBox._max.y; 

		// snow flakes fall downwards and slightly to the left
		attribute->_velocity.x = d3d::GetRandomFloat(0.0f, 1.0f) * -3.0f;
		attribute->_velocity.y = d3d::GetRandomFloat(0.0f, 1.0f) * -10.0f;
		attribute->_velocity.z = 0.0f;

		// white snow flake
		attribute->_color = d3d::WHITE;
	}

	void update(float timeDelta)
	{
		std::list<Attribute>::iterator i;
		for(i = _particles.begin(); i != _particles.end(); i++) {
			i->_position += i->_velocity * timeDelta;

			// is the point outside bounds?
			if (_boundingBox.isPointInside( i->_position) == false) {
				// nope so kill it, but we want to recycle dead 
				// particles, so respawn it instead.
				resetParticle( &(*i) );
			}
		}
	}

};

//********************
// Explosion System
//********************
class Firework : public PSystem {
public:
	Firework(D3DXVECTOR3* origin, int numParticles) {
		_origin        = *origin;
		_size          = 0.9f;
		_vbSize        = 2048;
		_vbOffset      = 0;   
		_vbBatchSize   = 512; 

		for(int i = 0; i < numParticles; i++) {
			addParticle();
		}
	}

	void resetParticle(Attribute* attribute) {
		attribute->_isAlive  = true;
		attribute->_position = _origin;

		D3DXVECTOR3 min = D3DXVECTOR3(-1.0f, -1.0f, -1.0f);
		D3DXVECTOR3 max = D3DXVECTOR3( 1.0f,  1.0f,  1.0f);

		d3d::GetRandomVector(
			&attribute->_velocity,
			&min,
			&max);

		// normalize to make spherical
		D3DXVec3Normalize(
			&attribute->_velocity,
			&attribute->_velocity);

		attribute->_velocity *= 100.0f;

		attribute->_color = D3DXCOLOR(
			d3d::GetRandomFloat(0.0f, 1.0f),
			d3d::GetRandomFloat(0.0f, 1.0f),
			d3d::GetRandomFloat(0.0f, 1.0f),
			1.0f);

		attribute->_age      = 0.0f;
		attribute->_lifeTime = 2.0f; // lives for 2 seconds
	}

	void update(float timeDelta) {
		std::list<Attribute>::iterator i;

		for(i = _particles.begin(); i != _particles.end(); i++) {
			// only update living particles
			if (i->_isAlive) {
				i->_position += i->_velocity * timeDelta;

				i->_age += timeDelta;

				if(i->_age > i->_lifeTime) {
					// kill 
					i->_isAlive = false;
				}
			}
		}
	}

	void preRender() {
		PSystem::preRender();

		_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ONE);
		_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

		// read, but don't write particles to z-buffer
		_device->SetRenderState(D3DRS_ZWRITEENABLE, false);
	}

	void postRender() {
		PSystem::postRender();

		_device->SetRenderState(D3DRS_ZWRITEENABLE, true);
	}

};


//****************
// Laser System
//****************
class ParticleGun : public PSystem {
public:
	ParticleGun(camera_la* camera) {
		_camera          = camera;
		_size            = 0.8f;
		_vbSize          = 2048;
		_vbOffset        = 0;  
		_vbBatchSize     = 512; 
	}

	void resetParticle(Attribute* attribute) {
		attribute->_isAlive  = true;

		D3DXVECTOR3 cameraPos;		
		//_camera->get_position(&cameraPos);
		gm::vec3 cameraPos_v(cameraPos.x, cameraPos.y, cameraPos.z);
		cameraPos_v = _camera->get_position();
		// Remove if using gm::vec3, directly use this variable
		cameraPos.x = cameraPos_v.x;
		cameraPos.y = cameraPos_v.y;
		cameraPos.z = cameraPos_v.z;

		D3DXVECTOR3 cameraDir;
		//_camera->get_look(&cameraDir);
		gm::vec3 cameraDir_v(cameraDir.x, cameraDir.y, cameraDir.z);
		cameraDir_v = _camera->get_look();
		// Remove if using gm::vec3, directly use this variable
		cameraDir.x = cameraDir_v.x;
		cameraDir.y = cameraDir_v.y;
		cameraDir.z = cameraDir_v.z;

		// change to camera position
		attribute->_position = cameraPos;
		attribute->_position.y -= 1.0f; // slightly below camera
								 // so its like we're carrying a gun

		// travels in the direction the camera is looking
		attribute->_velocity = cameraDir * 100.0f;

		// green
		attribute->_color = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);

		attribute->_age      = 0.0f; 
		attribute->_lifeTime = 1.0f; // lives for 1 seconds
	}

	void update(float timeDelta) {
		std::list<Attribute>::iterator i;

		for(i = _particles.begin(); i != _particles.end(); i++) {
			i->_position += i->_velocity * timeDelta;

			i->_age += timeDelta;

			if(i->_age > i->_lifeTime) { 
				// kill 
				i->_isAlive = false;
			}
		}
		removeDeadParticles();
	}

private:
	camera_la* _camera;
};

}
