
#if defined(_MSC_VER)		
	#pragma comment(lib, "user32.lib")
	#pragma comment(lib, "gdi32.lib")
#endif

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

//-------------------
// For D3D11TextureLoader
#include <wrl.h>
// For RoInitializeWrapper required for CreateWICTextureFromFile
#pragma comment(lib, "runtimeobject.lib")
//-------------------

#include "base_shared.h"

//#include "rs_d3d9b.h"
//#include "rs_d3d9c.h"
//#include "rs_d3d10.h"
//#include "rs_gl1.h"

//#include "rs_d3d12_2.h"
//#include "rs_vk1_2.h"

#include "rs_d3d11.h"
#include "rs_gl4.h"


//-------------------------

namespace wm_wnd2
{



class app_vars {
public:
	bool app_quit = false;
	bool app_active = true;
	bool app_minimized = false;
};
app_vars g_av;

class winapp {
public:
	wchar_t m_app_class_name[64] = {L'S', L'A', L'\0'};
	WNDPROC m_wnd_proc = nullptr;
	HINSTANCE m_hInstance = nullptr;
	HWND m_hwnd = nullptr;
	MSG m_msg = {};

	bool init(WNDPROC wnd_proc, HINSTANCE hInstance, const char* app_class_name) {
		sdf::strf_assign_mbs(m_app_class_name, sdf::strz_cap(m_app_class_name), app_class_name, sdf::strfz_len(app_class_name));
		m_wnd_proc = wnd_proc;
		m_hInstance = hInstance;

		// register window class
		WNDCLASSEX wcex = {};
		wcex.cbSize = sizeof(wcex);
		wcex.style = CS_OWNDC; //CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = m_wnd_proc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = m_hInstance;
		wcex.hIcon = LoadIconW(nullptr, IDI_APPLICATION);
		wcex.hCursor = LoadCursorW(nullptr, IDC_ARROW);
		//wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wcex.hbrBackground = CreateSolidBrush(RGB(25, 25, 112));
		wcex.lpszMenuName = nullptr;
		wcex.lpszClassName = m_app_class_name;
		wcex.hIconSm = LoadIconW(nullptr, IDI_APPLICATION);

		if (!RegisterClassExW(&wcex)) {
			printf("Cannot Register WinApi Class.\n");
			return false;
		}
		return true;
	}

	bool create_window(const char* wnd_title, int xpos, int ypos, int width, int height, bool fullscreen, bool borderless) {
		uint dwStyle = 0;
		uint dwExStyle = 0;
		dwStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPSIBLINGS|WS_CLIPCHILDREN;
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

		int x, y, w, h;
		RECT window_rect = {0, 0, width, height};
		AdjustWindowRectEx(&window_rect, dwStyle, false, dwExStyle);
		x = xpos + window_rect.left;
		y = ypos + window_rect.top;
		w = window_rect.right - window_rect.left;
		h = window_rect.bottom - window_rect.top;	

		wchar_t wstr_wnd_title[256] = {};
		sdf::strf_assign_mbs(wstr_wnd_title, sdf::strz_cap(wstr_wnd_title), wnd_title, sdf::strfz_len(wnd_title));

		HWND handle_wnd = CreateWindowExW(dwExStyle,					
							m_app_class_name,			        
							wstr_wnd_title,	 		
							dwStyle,
							x, y, w, h,
							nullptr, nullptr, m_hInstance, nullptr);									

		if (!handle_wnd) {							
			printf("Cannot Create Window.\n");
			return false;
		}  
		
		//ShowWindow(handle_wnd, iCmdShow);
		ShowWindow(handle_wnd, SW_SHOW);   	
		UpdateWindow(handle_wnd); 
		SetForegroundWindow(handle_wnd);						
		SetFocus(handle_wnd);	

		m_hwnd = handle_wnd;
		return true;
	}

	HWND get_main_hwnd() {
		return m_hwnd;
	}

	void poll_events() {
		if(PeekMessageW(&m_msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&m_msg);
			DispatchMessageW(&m_msg);
		}
	}

	bool is_quit_msg() {
		return (m_msg.message == WM_QUIT);
	}

	int msg_return() {
		return scast<int>(m_msg.wParam);
	}

	void deinit() {
		DestroyWindow(m_hwnd);
		UnregisterClassW(m_app_class_name, m_hInstance);
	}
};

}


using namespace wm_wnd2;

//---------------------------------------------
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//======================================
// WinMain
//======================================

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	std_console gconstd;
	gconstd.create_window("Std Console", 864, 0, 640, 640);
	printf("SysConsole Initialized.\n");
	println("Sample program zgfx");	    

    //-------------------------
    int xpos = 10;
	int ypos = 50;
	int width = 800;
	int height = 450;
	bool fullscreen = false;
	const char* wnd_title = "Sample window zgfx";									

	const char* APP_CLASS_NAME = "SAMPLE_APP_CLASS";
    HWND m_hwnd = nullptr;

	winapp nw_app;
    nw_app.init(MainWndProc, hInstance, APP_CLASS_NAME);
	nw_app.create_window(wnd_title, xpos, ypos, width, height, false, false);
	m_hwnd = nw_app.get_main_hwnd();

	std::unique_ptr<wm_irenderer> rs;		
	//rs = std::make_unique<wm_rgl4_tri>();	
	rs = std::make_unique<wm_rd3d11_tri>();
	//rs = std::make_unique<wm_rd3d9c_tri>();

	//rs = std::make_unique<wm_rd3d12_tri_color>();
	//rs = std::make_unique<wm_rvk_2>();
	rs->init_r(hInstance, m_hwnd, width, height, fullscreen);
	rs->setup();
	//---
	game_timer_qpc nw_timer;
	int64 prev_time_qpc = nw_timer.get_time();
    
	// program main loop
    while (!g_av.app_quit) {
		//nw_app.poll_events();
		nw_app.poll_events();		

		//if (nw_app.is_quit_msg()) { g_av.sys_quit(); }	
		if (nw_app.is_quit_msg()) { g_av.app_quit = true; }	

		if (g_av.app_active && !g_av.app_minimized) {
			int64 curr_time_qpc = nw_timer.get_time();
			float delta_time_qpc = (curr_time_qpc - prev_time_qpc)*nw_timer.period();					

			//process_input();
			//calculate_frame_stats();
			rs->render(delta_time_qpc);
			rs->swap_buffers();
    
			prev_time_qpc = curr_time_qpc;	

		} else {
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
