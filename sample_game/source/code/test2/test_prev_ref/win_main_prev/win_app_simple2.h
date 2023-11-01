#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


#include "base_types.h"
#include "base_print.h"
#include "base_def.h"

inline const wchar_t* APP_CLASS_NAME = L"SAMPLE_APP_CLASS";


// In cpp to improve compile times
//#include <thread>
//#include <chrono>
//void sys_sleep(uint dwMilliseconds) {
//	//Sleep(dwMilliseconds);
//	std::this_thread::sleep_for(std::chrono::milliseconds(dwMilliseconds));	
//}
 



//===============================================================================

class window_s {
public:
	int xpos = 10;
	int ypos = 50;
	int width = 320;
	int height = 240;
	bool fullscreen = false;
	bool borderless = false;
	const char* wnd_title = "Sample window";

	HWND hwnd = nullptr;

	void set_wnd_params(const char* wnd_title, int xpos, int ypos, int width, int height, bool fullscreen, bool borderless) {
		this->xpos = xpos;
		this->ypos = ypos;
		this->width = width;
		this->height = height;
		this->fullscreen = fullscreen;
		this->borderless = borderless;
		this->wnd_title = wnd_title;
	}
};

class win_app_s {
public:
	//HWND m_hwnd = nullptr;
	window_s m_wnd_s;

	HINSTANCE m_app_instance = nullptr;
	WNDPROC m_wnd_proc = nullptr;

	uint m_win_bg_color = RGB(25, 25, 112);
	wchar_t m_app_class_name[64] = {};
	
	MSG m_msg = {};
	
	bool m_fullscreen = false;


	win_app_s() {
		//m_msg.message = WM_NULL;
	}
	~win_app_s() {}

	bool init(void* hInstance, void* wnd_proc) {
		return register_class(scast<HINSTANCE>(hInstance), scast<WNDPROC>(wnd_proc));
	}

	bool register_class(HINSTANCE hInstance, WNDPROC wnd_proc) {
		// GetModuleHandle(nullptr) returns a handle to the file used to create the calling 
		// process (.exe file), if nullptr is passed for lpModuleName parameter.
		//m_app_instance = GetModuleHandleW(nullptr);
		m_app_instance = hInstance;
		m_wnd_proc = wnd_proc;
		wcsncpy(m_app_class_name, APP_CLASS_NAME, 64-1);

		// Register window class.
		WNDCLASSEX wcex = {};
		wcex.cbSize = sizeof(wcex);
		wcex.style = CS_OWNDC; //must for opengl
		//wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = m_wnd_proc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = m_app_instance;
		wcex.hIcon = LoadIconW(nullptr, IDI_APPLICATION);
		wcex.hCursor = LoadCursorW(nullptr, IDC_ARROW);
		//wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wcex.hbrBackground = CreateSolidBrush(m_win_bg_color);
		wcex.lpszMenuName = nullptr;
		wcex.lpszClassName = m_app_class_name;
		wcex.hIconSm = LoadIconW(nullptr, IDI_APPLICATION);

		if (!RegisterClassExW(&wcex)) {
			printfln("Cannot Register WinApi Class.");
			return false;
		}
		return true;
	}

	bool create_window(const char* wnd_title, int xpos, int ypos, int width, int height, bool fullscreen, bool fs_borderless) {
		uint dwStyle = 0;
		uint dwExStyle = 0;
		//dwStyle = WS_POPUP | WS_VISIBLE| WS_CLIPSIBLINGS|WS_CLIPCHILDREN; //borderless
		dwStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPSIBLINGS|WS_CLIPCHILDREN;
		//dwExStyle = WS_EX_APPWINDOW | WS_EX_TOPMOST; //fullscreen
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

		//---
		// Check fullscreen mode.
		m_fullscreen = fullscreen;
		int color_bits = 32;
		if (m_fullscreen) {
			DEVMODE dmScreenSettings = {};
			dmScreenSettings.dmSize = sizeof(dmScreenSettings);
			dmScreenSettings.dmPelsWidth = width;
			dmScreenSettings.dmPelsHeight = height;
			dmScreenSettings.dmBitsPerPel = color_bits;
			dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

			if (ChangeDisplaySettingsW(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL) {
				printfln("Cannot switch to fullscreen mode.");
				m_fullscreen = false;
			} else {
				m_fullscreen = true;
				dwStyle = WS_POPUP;
				dwExStyle = WS_EX_APPWINDOW;
				//ShowCursor(FALSE);
			}
		}

		// Borderless mode is windowed mode at desktop resolution.
		// Use borderless only when fullscreen is false.
		if (!m_fullscreen) {
			if (fs_borderless) {
				// GetSystemMetrics gives only info about the primary (first) monitor.
				width = GetSystemMetrics(SM_CXSCREEN);
				height = GetSystemMetrics(SM_CYSCREEN);
				dwStyle = WS_POPUP;
				dwExStyle = WS_EX_APPWINDOW;
			}
		}
		//---

		wchar_t wstr_wnd_title[256] = {};
		sdf::strz_wcs_from_mbs(wstr_wnd_title, sdf::strz_cap(wstr_wnd_title), wnd_title, sdf::strz_len(wnd_title));

		int x, y, w, h;
		RECT window_rect = {0, 0, width, height};
		AdjustWindowRectEx(&window_rect, dwStyle, false, dwExStyle);
		x = xpos + window_rect.left;
		y = ypos + window_rect.top;
		w = window_rect.right - window_rect.left;
		h = window_rect.bottom - window_rect.top;

		HWND handle_wnd = CreateWindowExW(dwExStyle,
							m_app_class_name,
							wstr_wnd_title,
							dwStyle,
							x, y, w, h,
							nullptr, nullptr, m_app_instance, nullptr);

		if (!handle_wnd) {
			printfln("Cannot Create Window.");
			return false;
		}  
		
		ShowWindow(handle_wnd, SW_SHOW);
		UpdateWindow(handle_wnd);
		SetForegroundWindow(handle_wnd);
		SetFocus(handle_wnd);

		m_wnd_s.set_wnd_params(wnd_title, xpos, ypos, width, height, false, false);
		m_wnd_s.hwnd = handle_wnd;
		return true;
	}

	window_s get_main_window() {
		return m_wnd_s;
	}

	HWND get_main_window_hwnd() {
		return m_wnd_s.hwnd;
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
		if (m_fullscreen) {
			// If fullscreen mode, switch back to windowed
			ChangeDisplaySettingsW(nullptr, 0);
			//ShowCursor(true);
		}

		if (m_wnd_s.hwnd) {
			DestroyWindow(m_wnd_s.hwnd);
			m_wnd_s.hwnd = nullptr;
		}
		UnregisterClassW(m_app_class_name, m_app_instance);
		m_app_instance = nullptr;
	}


	//void center_window() {
	//	RECT primaryDisplaySize = {};
	//	// System taskbar and application desktop toolbars not included
	//	SystemParametersInfo(SPI_GETWORKAREA, 0, &primaryDisplaySize, 0);	
	//	main_window->xpos = (primaryDisplaySize.right - main_window->width) / 2;
	//	main_window->ypos = (primaryDisplaySize.bottom - main_window->height) / 2;
	//}
};

