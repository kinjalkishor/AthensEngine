

#if defined(_MSC_VER)		
	#pragma comment(lib, "user32.lib")
	#pragma comment(lib, "gdi32.lib")	
#endif


#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <stdio.h>

#include "base_types.h"
#include "base_print.h"
#include "base_console.h"
#include "base_def.h"

#include "base_io.h"
//#include <iostream>

#include "win_app_simple.h"
#include "game_timer_qpc.h"

//#include <memory>

class app_vars {
public:
	bool app_quit = false;
	bool app_active = true;
	bool app_minimized = false;

    void sys_quit() { app_quit = true; }
};
//extern app_vars g_av;
app_vars g_av;

//bool	gkeys[256];

//-----------
//#include <cstddef>

#include "rnd_basic_d3d12.h"
#include "rnd_basic_d3d11.h"
//
// Has rnd_basic_d3d9b also.
#include "rnd_basic_d3d9c.h"
//#include "rnd_basic_d3d10.h"
//

//#include "rnd_basic_vk.h"

////#include "rnd_basic_gl1.h"
#include "rnd_basic_gl4.h"


namespace sdf {
}




//=====================================================
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//======================================
// WinMain
//======================================

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    std_console gconstd;
	gconstd.create_window("NexWars Std Console", 864, 0, 640, 640);
	printf("SysConsole Initialized.\n");
	printfln("Sample rgfx");	

	//------------------


	
	//------------------
	// config
	i32 xpos = 10;
	i32 ypos = 50;
	i32 width = 800;
	i32 height = 450;
	bool fullscreen = false;
	bool fs_borderless = false;
	const char* wnd_title = "Sample window 1";
	//------------------	

	window_s wnd1;

	win_app_s nw_app;
	//std::unique_ptr rs = sdf::make_unique<rd3d9b>();
	sdf::unique_ptr<irenderer> rs;	
	//rs = sdf::make_unique<rd3d12_tri_color>();
	//rs = sdf::make_unique<rd3d9c_cube_tex>();
	//rs = sdf::make_unique<rd3d11_cube_tex>();
	//rs = sdf::make_unique<rgl4_tri_color0>();
	rs = sdf::make_unique<rgl4_cube_tex>();
	



	//rs = sdf::make_unique<rd3d9b>();	
	//rs = sdf::make_unique<rd3d10>();	
	//rs = sdf::make_unique<rd3d11>();
	//rs = sdf::make_unique<rd3d12>();
	//rs = sdf::make_unique<rgl1>();
	//rs = sdf::make_unique<rgl4>();
	//rs = sdf::make_unique<rvk>();
	nw_app.init(hInstance, MainWndProc);
	nw_app.create_window(wnd_title, xpos, ypos, width, height, fullscreen, fs_borderless);	
	wnd1 = nw_app.get_main_window();
	
	rs->init_r(hInstance, wnd1.hwnd, wnd1.width, wnd1.height, wnd1.fullscreen);
	rs->setup();
	//----------------------------	
	game_timer_qpc nw_timer;
	i64 prev_time_qpc = nw_timer.get_time();
	//mTimer.Reset();

	// program main loop
    while (!g_av.app_quit) {
		//poll events
		nw_app.poll_events();

		if (nw_app.is_quit_msg()) { g_av.sys_quit(); }	

		// else part of if (poll_events()) {}
		//mTimer.Tick();
		if (g_av.app_active) {
			i64 curr_time_qpc = nw_timer.get_time();
			float delta_time_qpc = (curr_time_qpc - prev_time_qpc)*nw_timer.period();					

			//process_input();
			//calculate_frame_stats();
			rs->render(delta_time_qpc);
			rs->swap_buffers();
			//if (!isDeviceLost()) { update & draw scene }
			//UpdateScene(delta_time);
			//DrawScene();
			//rn->render(delta_time);
            //rn->swap_buffers();	
    
			prev_time_qpc = curr_time_qpc;	

		} else {
			// App paused, sleep 1, 10, 20, 50, 100
    		sys_sleep(1);
			continue;
		} 
        
    } // while: not app_quit

	rs->cleanup();
	rs->deinit_r();


	nw_app.deinit();
    return nw_app.msg_return();
}


//======================================
// Window Procedure
//======================================

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// Is the application in a minimized or maximized state?
	static bool minOrMaxed = false;
	RECT clientRect = {0, 0, 0, 0};

    switch (uMsg) {

    case WM_ACTIVATE:							
		//g_av.app_active = LOWORD(wParam);
		if (LOWORD(wParam) == WA_INACTIVE) {
			g_av.app_active = false;
			//mTimer.Stop();
		} else {
			g_av.app_active = true;
			//mTimer.Start();
		}
		g_av.app_minimized = scast<bool>(HIWORD(wParam));
		// If program is minimized mark as inactive
		//g_av.app_active = !g_av.app_minimized;
		return 0;		

    case WM_CREATE:
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_CLOSE:
		//DestroyWindow(hWnd);
        PostQuitMessage(0);        
        return 0;

    case WM_QUIT:
        PostQuitMessage(0);        
        return 0;

    case WM_KEYDOWN:
		//gkeys[wParam] = true;
        switch (wParam) {
		case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;

		case VK_F1:
			// Destroy & recreate fullscreen window
			//gkeys[VK_F1] = false;
			//DestroyWindow(hwnd);
			//gfullscreen=!gfullscreen;
			//create_window(gfullscreen);
			return 0;

		case VK_F10:
			//enableFullScreenMode(wnd1.hwnd, false);
			//send_event_fullscreen(false);
			return 0;
		case VK_F11:
			//enableFullScreenMode(wnd1.hwnd, true);
			//send_event_fullscreen(true);
			return 0;
		case VK_F2:
            //Set4xMsaaState(!m4xMsaaState);
			return 0;
        }
        return 0;								
	
	case WM_KEYUP:								
		//gkeys[wParam] = false;
		return 0;

	#if 0		
	// D3D9c Resize
	// After WM_ACTIVATE.
	// WM_SIZE is sent when the user resizes the window.  
	case WM_SIZE:
		if( md3dDevice )
		{
			md3dPP.BackBufferWidth  = LOWORD(lParam);
			md3dPP.BackBufferHeight = HIWORD(lParam);

			if( wParam == SIZE_MINIMIZED )
			{
				mAppPaused = true;
				minOrMaxed = true;
			}
			else if( wParam == SIZE_MAXIMIZED )
			{
				mAppPaused = false;
				minOrMaxed = true;
				onLostDevice();
				HR(md3dDevice->Reset(&md3dPP));
				onResetDevice();
			}
			// Restored is any resize that is not a minimize or maximize.
			// For example, restoring the window to its default size
			// after a minimize or maximize, or from dragging the resize
			// bars.
			else if( wParam == SIZE_RESTORED )
			{
				mAppPaused = false;

				// Are we restoring from a mimimized or maximized state, 
				// and are in windowed mode?  Do not execute this code if 
				// we are restoring to full screen mode.
				if( minOrMaxed && md3dPP.Windowed )
				{
					onLostDevice();
					HR(md3dDevice->Reset(&md3dPP));
					onResetDevice();
				}
				else
				{
					// No, which implies the user is resizing by dragging
					// the resize bars.  However, we do not reset the device
					// here because as the user continuously drags the resize
					// bars, a stream of WM_SIZE messages is sent to the window,
					// and it would be pointless (and slow) to reset for each
					// WM_SIZE message received from dragging the resize bars.
					// So instead, we reset after the user is done resizing the
					// window and releases the resize bars, which sends a
					// WM_EXITSIZEMOVE message.
				}
				minOrMaxed = false;
			}
		}
		return 0;


	// WM_EXITSIZEMOVE is sent when the user releases the resize bars.
	// Here we reset everything based on the new window dimensions.
	case WM_EXITSIZEMOVE:
		GetClientRect(mhMainWnd, &clientRect);
		md3dPP.BackBufferWidth  = clientRect.right;
		md3dPP.BackBufferHeight = clientRect.bottom;
		onLostDevice();
		HR(md3dDevice->Reset(&md3dPP));
		onResetDevice();

		return 0;
	#endif


	#if 0
	// nehe opengl
	case WM_SYSCOMMAND:							
	// Check System Calls
	// Prevent Screensaver trying to start or Monitor trying to enter powersave,
	switch (wParam) {
		case SC_SCREENSAVE:					
		case SC_MONITORPOWER:				
		return 0;							
	}
	return 0;				

	case WM_SIZE:
		ReSizeGLScene(LOWORD(lParam),HIWORD(lParam)); 
		return 0;								


	//---------------------
	//D3D10/11/12 Resize
	// WM_SIZE is sent when the user resizes the window.  
	case WM_SIZE:
		// Save the new client area dimensions.
		mClientWidth  = LOWORD(lParam);
		mClientHeight = HIWORD(lParam);
		if( md3dDevice )
		{
			if( wParam == SIZE_MINIMIZED )
			{
				mAppPaused = true;
				mMinimized = true;
				mMaximized = false;
			}
			else if( wParam == SIZE_MAXIMIZED )
			{
				mAppPaused = false;
				mMinimized = false;
				mMaximized = true;
				OnResize();
			}
			else if( wParam == SIZE_RESTORED )
			{
				
				// Restoring from minimized state?
				if( mMinimized )
				{
					mAppPaused = false;
					mMinimized = false;
					OnResize();
				}

				// Restoring from maximized state?
				else if( mMaximized )
				{
					mAppPaused = false;
					mMaximized = false;
					OnResize();
				}
				else if( mResizing )
				{
					// If user is dragging the resize bars, we do not resize 
					// the buffers here because as the user continuously 
					// drags the resize bars, a stream of WM_SIZE messages are
					// sent to the window, and it would be pointless (and slow)
					// to resize for each WM_SIZE message received from dragging
					// the resize bars.  So instead, we reset after the user is 
					// done resizing the window and releases the resize bars, which 
					// sends a WM_EXITSIZEMOVE message.
				}
				else // API call such as SetWindowPos or mSwapChain->SetFullscreenState.
				{
					OnResize();
				}
			}
		}
		return 0;

	// WM_EXITSIZEMOVE is sent when the user grabs the resize bars.
	case WM_ENTERSIZEMOVE:
		mAppPaused = true;
		mResizing  = true;
		mTimer.Stop();
		return 0;

	// WM_EXITSIZEMOVE is sent when the user releases the resize bars.
	// Here we reset everything based on the new window dimensions.
	case WM_EXITSIZEMOVE:
		mAppPaused = false;
		mResizing  = false;
		mTimer.Start();
		OnResize();
		return 0;


	// The WM_MENUCHAR message is sent when a menu is active and the user presses 
	// a key that does not correspond to any mnemonic or accelerator key. 
	//case WM_MENUCHAR:
	//	// Don't beep when we alt-enter.
	//	return MAKELRESULT(0, MNC_CLOSE);

	// Catch this message so to prevent the window from becoming too small.
	case WM_GETMINMAXINFO:
		((MINMAXINFO*)lParam)->ptMinTrackSize.x = 160;
		((MINMAXINFO*)lParam)->ptMinTrackSize.y = 120; 
		return 0;

	case WM_LBUTTONDOWN:
	case WM_MBUTTONDOWN:
	case WM_RBUTTONDOWN:
		rn->OnMouseDown(wParam, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
		return 0;
	case WM_LBUTTONUP:
	case WM_MBUTTONUP:
	case WM_RBUTTONUP:
		rn->OnMouseUp(wParam, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
		return 0;
	case WM_MOUSEMOVE:
		rn->OnMouseMove(wParam, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
		return 0;

	#endif


    default: break;
    } 
    
    return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}