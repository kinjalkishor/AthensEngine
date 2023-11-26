
#if defined(_MSC_VER)		
	#pragma comment(lib, "user32.lib")
	#pragma comment(lib, "gdi32.lib")
#endif

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdio.h>

#include "base_types.h"
#include "base_def.h"
#include "base_console.h"
#include "base_print.h"
#include "base_io.h"
#include "base_win_util.h"
//#include "base_ds_vector.h"
//#include "base_ds2_unord_map.h"

#include "game_timer_qpc.h"
#include "win_app.h"


namespace wm_t3 
{

class app_vars {
public:
	bool app_quit = false;
	bool app_active = true;
	bool app_minimized = false;
};
app_vars g_av;

class wnd_data {
public:
	int width = 0;
	int height = 0;
};
wnd_data g_wd;

}

using namespace wm_t3;

//#include "t3_rs_d3d9b.h"
#include "t3_rs_d3d9c.h"
#include "t3_rs_d3d11.h"

//---------------------------------------------
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


//======================================
// WinMain
//======================================

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	BOOL dpi_success = SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);

	std_console gconstd;
	gconstd.create_window("Std Console", 864, 0, 640, 640);
	printf("SysConsole Initialized.\n");
	println("Sample program t3");	    
	//-------------------------

	//sdf::string_view b = sdf::make_sv("NEW");
	//printfln("%s", b.c_str());
	//printfln("THERE");
	//int v = 5;
	//printfln("%d", v);

    //-------------------------
    int xpos = 10;
	int ypos = 50;
	int width = 800;
	int height = 450;
	const char* wnd_title = "Sample window t3";	
	bool fullscreen = false;
	bool borderless = false;

	const char* APP_CLASS_NAME = "SAMPLE_APP_CLASS";
    HWND m_hwnd = nullptr;	

	win_app nw_app;
    nw_app.init(MainWndProc, hInstance, APP_CLASS_NAME);
	nw_app.create_window(wnd_title, xpos, ypos, width, height, fullscreen, borderless);
	//nw_app.set_ex_fullscreen_mode(true);
	//nw_app.create_window(wnd_title, xpos, ypos, 1280, 720, 1, 0);
	m_hwnd = nw_app.get_main_hwnd();

	std::unique_ptr<irenderer> rs;		
	rs = std::make_unique<rd3d9c_tri_color_cube>();	
	//rs = std::make_unique<rd3d11_tri_color>();	
	rs->init_r(hInstance, m_hwnd, width, height, fullscreen);
	rs->setup();
	//---
	game_timer_qpc nw_timer;
	int64 prev_time_qpc = nw_timer.get_time();
    
	// program main loop
    while (!g_av.app_quit) {
		nw_app.poll_events();		
		//if (nw_app.is_msg_present()) { 
			//nw_app.process_msgs(); 

			if (nw_app.is_quit_msg()) { g_av.app_quit = true; }	
		//} else {

			if (g_av.app_active && !g_av.app_minimized) {
				int64 curr_time_qpc = nw_timer.get_time();
				float delta_time_qpc = (curr_time_qpc - prev_time_qpc)*nw_timer.period();					

				//process_input();
				//calculate_frame_stats();
				//d3d9.0c remove -
				//if (!rs->is_device_lost()) { 
				//	updateScene(dt);
				//	drawScene();
				//}
				rs->render(delta_time_qpc);
				rs->swap_buffers();
    
				prev_time_qpc = curr_time_qpc;	

			} else {
    			sys_sleep(1);
				continue;
			} 
		//}
        
    } // while: not app_quit

	rs->cleanup();
	rs->deinit_r();

	//nw_app.exit_ex_fullscreen_mode(1);
	nw_app.deinit();
    
    return nw_app.msg_return();
}


//======================================
// Window Procedure
//======================================

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	RECT client_rect = {0, 0, 0, 0};

    switch (uMsg) {

    case WM_ACTIVATE:							
		g_av.app_active = scast<bool>(LOWORD(wParam) != WA_INACTIVE);
		g_av.app_minimized = scast<bool>(HIWORD(wParam));
		return 0;		

    case WM_CREATE:
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_CLOSE:
        PostQuitMessage(0);        
        return 0;

    case WM_QUIT:
        PostQuitMessage(0);        
        return 0;


	case WM_SIZE:
		g_wd.width  = LOWORD(lParam);
		g_wd.height = HIWORD(lParam);
		return 0;

	case WM_EXITSIZEMOVE:
		GetClientRect(hWnd, &client_rect);
		g_wd.width  = client_rect.right;
		g_wd.height = client_rect.bottom;
		return 0;


    case WM_KEYDOWN:
		//gkeys[wParam] = true;
        switch (wParam) {
		case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;		
        }
        return 0;								
	
	case WM_KEYUP:								
		//gkeys[wParam] = false;
		return 0;

    default: break;
    } 
    
    return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}
