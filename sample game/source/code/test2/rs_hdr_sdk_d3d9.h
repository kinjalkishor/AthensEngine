//DONE
#pragma once

#if 0
//-----------------------------
// path realtive to project file
#if defined(_MSC_VER)	
	// Used by d3d header
	//#pragma comment(lib, "oleaut32.lib")
	//#pragma comment(lib, "onecore.lib")

	//libcmt.lib conflicts with use of other libs warning
	#pragma comment(linker, "/NODEFAULTLIB:libcmt.lib")

	// DirectInput
	//#pragma comment(lib, "dinput8.lib")
	//#pragma comment (lib, "dxguid.lib")
#endif

// DXSDK_Jun10
#include <d3d9.h>
#pragma comment(lib,"DXSDK_Jun10/Lib/x64/d3d9.lib")

#include "DXSDK_Jun10/Include/d3dx9.h"
//#include "DXSDK_Jun10/Include/D3dx9shape.h"
#pragma comment(lib,"DXSDK_Jun10/Lib/x64/d3dx9.lib")

//#include "DXSDK_Jun10/Include/DxErr.h"
//#pragma comment(lib, "legacy_stdio_definitions.lib")
//#pragma comment(lib,"E:/osl/DXSDK_Jun10/Lib/x64/DxErr.lib")

//-----------------------------

#endif

