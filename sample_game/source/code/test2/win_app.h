#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdio.h>

#include "base_types.h"
#include "base_def.h"
#include "base_ds_st.h"

class win_app {
public:
	//wchar_t m_app_class_name[64] = {L'S', L'A', L'\0'};
	sdf::wstring_st<63> m_app_class_name;

	uint m_win_bg_color = RGB(25, 25, 112);

	HINSTANCE m_hInstance = nullptr;
	WNDPROC m_wnd_proc = nullptr;
	MSG m_msg = {};

	HWND m_hwnd = nullptr;	


	bool init(WNDPROC wnd_proc, HINSTANCE hInstance, const char* app_class_name) {
		//wcsncpy(m_app_class_name, app_class_name, 64-1);
		//sdf::strf_wcs_from_mbs(m_app_class_name, sdf::strz_cap(m_app_class_name), app_class_name, sdf::strfz_len(app_class_name));	
		sdf::string_st_wcs_from_mbs(m_app_class_name, app_class_name, sdf::strfz_len(app_class_name));

		// GetModuleHandle(nullptr) returns a handle to the file used to create the calling 
		// process (.exe file), if nullptr is passed for lpModuleName parameter.
		//m_hInstance = GetModuleHandleW(nullptr);
		m_hInstance = hInstance;
		m_wnd_proc = wnd_proc;

		// register window class
		WNDCLASSEX wcex = {};
		wcex.cbSize = sizeof(wcex);
		wcex.style = CS_OWNDC; //must for opengl
		//wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = m_wnd_proc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = m_hInstance;
		wcex.hIcon = LoadIconW(nullptr, IDI_APPLICATION);
		wcex.hCursor = LoadCursorW(nullptr, IDC_ARROW);
		//wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wcex.hbrBackground = CreateSolidBrush(m_win_bg_color);
		wcex.lpszMenuName = nullptr;
		wcex.lpszClassName = m_app_class_name.c_str();
		wcex.hIconSm = LoadIconW(nullptr, IDI_APPLICATION);

		if (!RegisterClassExW(&wcex)) {
			printf("Cannot Register WinApi Class.\n");
			return false;
		}
		return true;
	}

	
	//-----
	bool m_ex_fullscreen = false;

	// Remove ex_fullscreen, not needed in Windows10
	void set_ex_fullscreen_mode(bool ex_fullscreen) {
		m_ex_fullscreen = ex_fullscreen;
	}

	void enter_ex_fullscreen_mode(uint& dwStyle, uint& dwExStyle, int& xpos, int& ypos, int width, int height) {
		//---
		// Check exclusive fullscreen mode.
		int color_bits = 32;
		if (m_ex_fullscreen) {
			DEVMODE dmScreenSettings = {};
			dmScreenSettings.dmSize = sizeof(dmScreenSettings);
			dmScreenSettings.dmPelsWidth = width;
			dmScreenSettings.dmPelsHeight = height;
			dmScreenSettings.dmBitsPerPel = color_bits;
			dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

			if (ChangeDisplaySettingsW(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL) {
				printf("Cannot switch to exclusive fullscreen mode.\n");
				m_ex_fullscreen = false;
			} else {
				// switch to exclusive fullscreen mode successful
				xpos = 0;
				ypos = 0;
				dwStyle = WS_POPUP;
				//dwExStyle = WS_EX_APPWINDOW | WS_EX_TOPMOST; //fullscreen, WS_EX_TOPMOST disables Alt+Esc
				dwExStyle = WS_EX_APPWINDOW;
				//ShowCursor(FALSE);
			}
		} 
	}

	void exit_ex_fullscreen_mode() {
		if (m_ex_fullscreen) {
			//fm_msg_box_ok("exit_ex_fullscreen_mode");
			// If fullscreen mode, switch back to windowed
			ChangeDisplaySettingsW(nullptr, 0);
			//ShowCursor(true);
		}
	}
	//-----

	bool create_window(const char* wnd_title, int xpos, int ypos, int width, int height, bool fullscreen, bool borderless) {
		uint dwStyle = 0;
		uint dwExStyle = 0;
		dwStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPSIBLINGS|WS_CLIPCHILDREN;
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

		if (m_ex_fullscreen) {
			enter_ex_fullscreen_mode(dwStyle, dwExStyle, xpos, ypos, width, height);
		} else {

			// Not true fullscreen, only borderless.
			// Borderless mode is windowed mode at desktop resolution.
			if (fullscreen) {
				xpos = 0;
				ypos = 0;
				width = GetSystemMetrics(SM_CXSCREEN);
				height = GetSystemMetrics(SM_CYSCREEN);	
				// GetSystemMetrics gives only info about the primary (first) monitor.	
				// fullscreen is always borderless
				//borderless = true;	
				dwStyle = WS_POPUP;
				//dwExStyle = WS_EX_APPWINDOW | WS_EX_TOPMOST; //fullscreen, WS_EX_TOPMOST disables Alt+Esc
				dwExStyle = WS_EX_APPWINDOW;
			}

			if (borderless) {
				// GetSystemMetrics gives only info about the primary (first) monitor.				
				//dwStyle = WS_POPUP;
				dwStyle = WS_POPUP | WS_VISIBLE| WS_CLIPSIBLINGS|WS_CLIPCHILDREN; //borderless
				dwExStyle = WS_EX_APPWINDOW;
			}
		}

		int x, y, w, h;
		RECT window_rect = {0, 0, width, height};
		AdjustWindowRectEx(&window_rect, dwStyle, false, dwExStyle);
		x = xpos + window_rect.left;
		y = ypos + window_rect.top;
		w = window_rect.right - window_rect.left;
		h = window_rect.bottom - window_rect.top;	

		//wchar_t wstr_wnd_title[256] = {};
		//sdf::strf_wcs_from_mbs(wstr_wnd_title, sdf::strz_cap(wstr_wnd_title), wnd_title, sdf::strfz_len(wnd_title));
		sdf::wstring_st<255> wstr_wnd_title;
		sdf::string_st_wcs_from_mbs(wstr_wnd_title, wnd_title, sdf::strfz_len(wnd_title));

		HWND handle_wnd = CreateWindowExW(dwExStyle,					
							m_app_class_name.c_str(),			        
							wstr_wnd_title.c_str(),	 		
							dwStyle,
							x, y, w, h,
							nullptr, nullptr, m_hInstance, nullptr);									

		if (!handle_wnd) {							
			printf("Cannot Create Window.\n");
			return false;
		}  
		
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
		exit_ex_fullscreen_mode();

		if (m_hwnd) {
			DestroyWindow(m_hwnd);
			m_hwnd = nullptr;
		}
		UnregisterClassW(m_app_class_name.c_str(), m_hInstance);	
		m_hInstance = nullptr;
	}


	//--------------------
	bool is_msg_present() {
		return scast<bool>(PeekMessageW(&m_msg, nullptr, 0, 0, PM_REMOVE));
	}

	void process_msgs() {
		TranslateMessage(&m_msg);
		DispatchMessageW(&m_msg);
	}
};