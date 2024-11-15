#pragma once

#if 0
#include <stdio.h>
#include <stdarg.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdint.h>
using uint = unsigned int;
using int64 = signed long long int;
using uint64 = unsigned long long int;



//-------------------
template<class T> inline void com_release(T*& t) { if(t) { t->Release(); t = nullptr; } }	

inline void sys_msg_box(const char *format, ...) {
	constexpr int buffer_size = 4096;
	char text[buffer_size];

	va_list argptr;
	va_start(argptr, format);
	vsnprintf(text, sizeof(text), format, argptr);
	va_end(argptr);

	//MessageBoxW(nullptr, text, L"Error", MB_OK);
	MessageBoxA(nullptr, text, "Error", MB_OK);
}

inline void printfln(const char *format, ...) {
	constexpr int buffer_size = 4096;
	char text[buffer_size];

	va_list argptr;
	va_start(argptr, format);
	vsnprintf(text, sizeof(text), format, argptr);
	va_end(argptr);

	printf("%s\n", text);
}

//-------------------
namespace sdf
{
template <class T, intmax_t N> inline constexpr intmax_t strz_cap(const T (&)[N]) noexcept { return N-1; }

inline intmax_t strz_len(const char* src) { return strlen(src); }
inline intmax_t strz_len(const wchar_t* src) { return wcslen(src); }

inline intmax_t strf_assign_mbs(wchar_t* dest, intmax_t dest_capacity, const char* src, intmax_t src_len) {
    intmax_t copy_len = src_len;
    if (copy_len > dest_capacity) { copy_len = dest_capacity; }
	const int dest_size_with_null_char = dest_capacity+1;
	int result = MultiByteToWideChar(CP_UTF8, 0, src, src_len, dest, dest_size_with_null_char);
	dest[copy_len] = L'\0';
	return copy_len;
}
inline intmax_t strf_assign_wcs(char* dest, intmax_t dest_capacity, const wchar_t* src, intmax_t src_len) {
    intmax_t copy_len = src_len;
    if (copy_len > dest_capacity) { copy_len = dest_capacity; }
	const int dest_size_with_null_char = dest_capacity+1;
	int result = WideCharToMultiByte(CP_UTF8, 0, src, src_len, dest, dest_size_with_null_char, nullptr, nullptr);	
	dest[copy_len] = '\0';
	return copy_len;
}
}

//-------------------
#include <format>

template <class... _Types>
_NODISCARD inline void print(const std::string_view _Fmt, const _Types&... _Args) {
	std::printf("%s", std::vformat(_Fmt, std::make_format_args(_Args...)).c_str());
}
template <class... _Types>
_NODISCARD inline void println(const std::string_view _Fmt, const _Types&... _Args) {
	std::printf("%s\n", std::vformat(_Fmt, std::make_format_args(_Args...)).c_str());
}

//-------------------
class std_console {
private:
	HANDLE hconsole = nullptr;	
	const uint color_yellow = 6;

public:
	std_console() {}
	~std_console() { FreeConsole(); }

	bool create_window(const char* window_title, int xpos, int ypos, int width, int height) {
		if (!AllocConsole()) {
			MessageBoxW(nullptr, L"Couldn't create output console", L"Error", 0);
			return false; 
		}

		HWND console_window = GetConsoleWindow();
		MoveWindow(console_window, xpos, ypos, width, height, TRUE);

		wchar_t wconsole_title[256] = {L'C', L'W', L'\0'};
		sdf::strf_assign_mbs(wconsole_title, sdf::strz_cap(wconsole_title), window_title, sdf::strz_len(window_title));
		SetWindowTextW(console_window, wconsole_title);	

		// The freopen_s function closes the file currently associated with stream and reassigns stream to the file specified by path.
		freopen("conin$", "r", stdin);
		freopen("conout$", "w", stdout);
		freopen("conout$", "w", stderr);

		hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hconsole, color_yellow);
		return true;
	}
};

//-------------------
#include <thread>
#include <chrono>
void sys_sleep(uint dwMilliseconds) {
	//Sleep(dwMilliseconds);
	std::this_thread::sleep_for(std::chrono::milliseconds(dwMilliseconds));	
}

//-------------------
#if 0
class game_timer_qpc {
public:

	float period() {
		int64 cnts_per_sec = 0;
		QueryPerformanceFrequency((LARGE_INTEGER*)&cnts_per_sec);
		// secs_per_cnt_qpc is 0.0000001f, 1e-07;
		float secs_per_cnt_qpc = 1.0f / scast<float>(cnts_per_sec);
		//println("{}", secs_per_cnt_qpc);
		return secs_per_cnt_qpc;
	}

	int64 get_time() {
		// Retrieves the current value of the performance counter, 
		// which is a high resolution (<1 micro second) time stamp.
		int64 prev_time_qpc = 0;
		QueryPerformanceCounter((LARGE_INTEGER*)&prev_time_qpc);
		return prev_time_qpc;
	}
};
#endif

//-------------------
//class wm_irenderer {
//public:
//	wm_irenderer() {}
//	virtual ~wm_irenderer() {}	
//
//	virtual bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { return false; }
//	virtual void deinit_r() {}
//
//	virtual void setup() {}
//	virtual void cleanup() {}
//	virtual void render(float dt) {}
//	virtual void swap_buffers() {}
//};

class winapp {
public:
	wchar_t m_app_class_name[64] = {L'S', L'A', L'\0'};
	WNDPROC m_wnd_proc = nullptr;
	HINSTANCE m_hInstance = nullptr;
	HWND m_hwnd = nullptr;
	MSG m_msg = {};

	int m_width = 320;
	int m_height = 240;
	bool m_fullscreen = false;

	bool init(WNDPROC wnd_proc, HINSTANCE hInstance, const char* app_class_name) {
		sdf::strf_assign_mbs(m_app_class_name, sdf::strz_cap(m_app_class_name), app_class_name, sdf::strz_len(app_class_name));
		m_wnd_proc = wnd_proc;
		m_hInstance = hInstance;

		// Register window class
		WNDCLASSEX wc = {};
		wc.cbSize = sizeof(wc);
		wc.style = CS_OWNDC; //CS_HREDRAW | CS_VREDRAW;
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
		m_width = width;
		m_height = height;
		m_fullscreen = fullscreen;

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

		wchar_t wstr_wnd_title[256] = {L'N', L'A', L'\0'};
		sdf::strf_assign_mbs(wstr_wnd_title, sdf::strz_cap(wstr_wnd_title), wnd_title, sdf::strz_len(wnd_title));

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


	HINSTANCE get_hinstance() const { return m_hInstance; }
	HWND main_hwnd() const { return m_hwnd; }	
	int width() const { return m_width; }
	int height() const { return m_height; }
	bool fullscreen() const { return m_fullscreen; }


	bool peak_message() { 
		return PeekMessageW(&m_msg, nullptr, 0, 0, PM_REMOVE); 
	}

	void process_message() {
		TranslateMessage(&m_msg);
		DispatchMessageW(&m_msg);
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
		return static_cast<int>(m_msg.wParam);
	}

	void deinit() {
		DestroyWindow(m_hwnd);
		UnregisterClassW(m_app_class_name, m_hInstance);
	}
};

#endif