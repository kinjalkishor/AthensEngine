#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdio.h>
#include <stdint.h>


//-------------------------------------------
// ANSI COLOR CODES
//-------------------------------------------
#define ANSI_COLOR_RED		"\x1b[31m"
#define ANSI_COLOR_GREEN	"\x1b[32m"
#define ANSI_COLOR_YELLOW	"\x1b[33m"
#define ANSI_COLOR_BLUE		"\x1b[34m"
#define ANSI_COLOR_MAGENTA	"\x1b[35m"
#define ANSI_COLOR_CYAN		"\x1b[36m"

//----------
//#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_RESET	ANSI_COLOR_YELLOW

//printf(ANSI_COLOR_RED "This text is RED!" ANSI_COLOR_RESET "\n");

inline DWORD win_console_enable_color_print() {
	// Set output mode to handle virtual terminal sequences
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) { return GetLastError(); }
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) { return GetLastError(); }
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode)) { return GetLastError(); }
	return ERROR_SUCCESS;
}

//======================================
class std_console {
private:
	void* hconsole = nullptr;	

	static const uint32_t color_black			= 0;
	static const uint32_t color_blue			= 1; 
	static const uint32_t color_green			= 2;  
	static const uint32_t color_cyan			= 3;  
	static const uint32_t color_red				= 4;    
	static const uint32_t color_magenta			= 5;
	static const uint32_t color_yellow			= 6;
	static const uint32_t color_white			= 7;


	ptrdiff_t wstr_assign_ansi(wchar_t* dest, ptrdiff_t dest_capacity, const char* src, ptrdiff_t src_len) {
		ptrdiff_t copy_len = (src_len > dest_capacity) ? dest_capacity : src_len;
		const int dest_cap_with_null_char = dest_capacity+1;
		int result = MultiByteToWideChar(CP_UTF8, 0, src, copy_len, dest, dest_cap_with_null_char);
		if (!result) { return 0; }
		dest[copy_len] = L'\0';
		return copy_len;
	}

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

		wchar_t wconsole_title[256] = {};
		//sdf::wstr_assign_ansi(wconsole_title, sdf::strz_cap(wconsole_title), window_title, sdf::strz_len(window_title));
		wstr_assign_ansi(wconsole_title, (sizeof(wconsole_title)/sizeof(wconsole_title[0])-1), window_title, strlen(window_title));
		SetWindowTextW(console_window, wconsole_title);	

		// The freopen_s function closes the file currently associated with stream and reassigns stream to the file specified by path.
		freopen("conin$", "r", stdin);
		freopen("conout$", "w", stdout);
		freopen("conout$", "w", stderr);
		//printf("Debugging Window:\n");

		hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hconsole, color_yellow);

		win_console_enable_color_print();

		return true;
	}

};