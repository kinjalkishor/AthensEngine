#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdio.h>
#include <stdint.h>

class winapp {
private:
	ptrdiff_t wstr_assign_ansi(wchar_t* dest, ptrdiff_t dest_capacity, const char* src, ptrdiff_t src_len) {
		ptrdiff_t copy_len = (src_len > dest_capacity) ? dest_capacity : src_len;
		const int dest_cap_with_null_char = dest_capacity+1;
		int result = MultiByteToWideChar(CP_UTF8, 0, src, copy_len, dest, dest_cap_with_null_char);
		if (!result) { return 0; }
		dest[copy_len] = L'\0';
		return copy_len;
	}

public:
	wchar_t m_app_class_name[64] = {L'S', L'A', L'\0'};
	WNDPROC m_wnd_proc = nullptr;
	HINSTANCE m_hInstance = nullptr;
	HWND m_hwnd = nullptr;
	MSG m_msg = {};

	bool init(WNDPROC wnd_proc, HINSTANCE hInstance, const char* app_class_name) {

		//sdf::wstr_assign_ansi(m_app_class_name, sdf::strz_cap(m_app_class_name), app_class_name, sdf::strz_len(app_class_name));
		wstr_assign_ansi(m_app_class_name, (sizeof(m_app_class_name)/sizeof(m_app_class_name[0])-1), app_class_name, strlen(app_class_name));

		m_wnd_proc = wnd_proc;
		m_hInstance = hInstance;

		// Register window class
		WNDCLASSEX wc = {};
		wc.cbSize = sizeof(wc);
		wc.style = CS_OWNDC; //CS_HREDRAW|CS_VREDRAW;
		wc.lpfnWndProc = m_wnd_proc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = m_hInstance;
		wc.hIcon = LoadIconW(nullptr, IDI_APPLICATION);
		wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
		//wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wc.hbrBackground = CreateSolidBrush(RGB(25, 25, 112));
		wc.lpszMenuName = nullptr;
		wc.lpszClassName = m_app_class_name;
		wc.hIconSm = LoadIconW(nullptr, IDI_APPLICATION);

		if (!RegisterClassExW(&wc)) {
			printf("Cannot Register WinApi Class.\n");
			return false;
		}
		return true;
	}

	bool create_window(const char* wnd_title, int xpos, int ypos, int width, int height, bool fullscreen, bool borderless) {
		uint32_t dwStyle = 0;
		uint32_t dwExStyle = 0;
		dwStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPSIBLINGS|WS_CLIPCHILDREN;
		dwExStyle = WS_EX_APPWINDOW|WS_EX_WINDOWEDGE;

		int x, y, w, h;
		RECT window_rect = {0, 0, width, height};
		AdjustWindowRectEx(&window_rect, dwStyle, false, dwExStyle);
		x = xpos + window_rect.left;
		y = ypos + window_rect.top;
		w = window_rect.right - window_rect.left;
		h = window_rect.bottom - window_rect.top;	

		wchar_t wstr_wnd_title[256] = {};
		//sdf::wstr_assign_ansi(wstr_wnd_title, sdf::strz_cap(wstr_wnd_title), wnd_title, sdf::strz_len(wnd_title));
		wstr_assign_ansi(wstr_wnd_title, (sizeof(wstr_wnd_title)/sizeof(wstr_wnd_title[0])-1), wnd_title, strlen(wnd_title));

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
		if (PeekMessageW(&m_msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&m_msg);
			DispatchMessageW(&m_msg);
		}
	}

	bool is_quit_msg() {
		return (m_msg.message == WM_QUIT);
	}

	int msg_return() {
		return static_cast<int>(m_msg.wParam);
	}

	void deinit() {
		DestroyWindow(m_hwnd);
		UnregisterClassW(m_app_class_name, m_hInstance);
	}
};

