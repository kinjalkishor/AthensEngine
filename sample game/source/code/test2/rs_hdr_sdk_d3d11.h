#pragma once

#if 0
//------------------------------------
#include <d3d11.h>
#include <d3d11_4.h>
//#include <dxgi.h>
#include <dxgi1_6.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dxguid.lib")
// For using Windows Imaging Component (WIC)
#pragma comment(lib, "uuid.lib")
//#pragma comment(lib,"windowscodecs.lib")

// for compiling shader files, D3DCompileFromFile
#include <D3Dcompiler.h>
//#include <D3Dcommon.h>

#pragma comment(lib, "d3dcompiler.lib")


// For D3D11TextureLoader
////#include <wrl.h>
//#include <wrl/client.h>
//using Microsoft::WRL::ComPtr;
// For RoInitializeWrapper required for CreateWICTextureFromFile
//#pragma comment(lib, "runtimeobject.lib")

//=====================================
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXMath.h"
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXPackedVector.h"
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXColors.h"
//#include "tut/d3dxlib/DirectXMath/Inc/DirectXCollision.h"

// For textures
#include "d3dxlib/TextureLoader/DDSTextureLoader11.h"
#include "d3dxlib/TextureLoader/WICTextureLoader11.h"
// Add DDSTextureLoader11.cpp to project also
//------------------------------------
#endif