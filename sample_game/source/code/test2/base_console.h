#pragma once

//TODO: ADD COLOR PRINT & BKG

class std_console {
private:
	//HANDLE hconsole = nullptr;
	void* hconsole = nullptr;	

public:
	std_console() {}
	~std_console();

	bool create_window(const char* window_title, int xpos, int ypos, int width, int height);	

};


#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdio.h>

#include "base_def.h"
//#include "base_console.h"

inline DWORD win_enable_color_print() {
	// Set output mode to handle virtual terminal sequences
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) { return GetLastError(); }
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) { return GetLastError(); }
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode)) { return GetLastError(); }
	return ERROR_SUCCESS;
}

class std_console_local {
public:
	//static const uint color_blue = FOREGROUND_BLUE;
	//static const uint color_green = FOREGROUND_GREEN;
	//static const uint color_red = FOREGROUND_RED;
	////cyan is green+blue, magenta is red+blue, and yellow is red+green
	//static const uint color_cyan = FOREGROUND_BLUE | FOREGROUND_GREEN;
	//static const uint color_magenta = FOREGROUND_BLUE | FOREGROUND_RED;
	//static const uint color_yellow = FOREGROUND_GREEN | FOREGROUND_RED;	

	static const uint color_black			= 0;
	static const uint color_blue			= 1; 
	static const uint color_green			= 2;  
	static const uint color_cyan			= 3;  
	static const uint color_red				= 4;    
	static const uint color_magenta			= 5;
	static const uint color_yellow			= 6;
	static const uint color_white			= 7;
	static const uint color_bright_black	= 8;
	static const uint color_bright_blue		= 9;
	static const uint color_bright_green	= 10;
	static const uint color_bright_cyan		= 11;
	static const uint color_bright_red		= 12;
	static const uint color_bright_magenta	= 13;
	static const uint color_bright_yellow	= 14;
	static const uint color_bright_white	= 15;

	// default is white color
	static const uint color_default = color_white;
};


inline std_console::~std_console() {
	FreeConsole();
	//check if(hconsole)
}

inline bool std_console::create_window(const char* window_title, int xpos, int ypos, int width, int height) {
	if (!AllocConsole()) {
		MessageBoxW(nullptr, L"Couldn't create output console", L"Error", 0);
		return false; 
	}

	HWND console_window = GetConsoleWindow();
	//SetWindowPos(console_window, 0, 864, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);	
	MoveWindow(console_window, xpos, ypos, width, height, TRUE);
	//SetActiveWindow(g_av.active_window);
	//SetFocus(g_av.active_window);
	//SetWindowTextW(console_window, L"Console Window");

	wchar_t wconsole_title[256] = {};
	sdf::strf_assign_mbs(wconsole_title, sdf::strz_cap(wconsole_title), window_title, sdf::strfz_len(window_title));
	SetWindowTextW(console_window, wconsole_title);	

	// The freopen_s function closes the file currently associated with stream and reassigns stream to the file specified by path.
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);
	//printf("Debugging Window:\n");

	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hconsole, std_console_local::color_yellow);

	//set_console_colors(bg_color);

	win_enable_color_print();

	return true;
}


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

#if 0
	// Try some Set Graphics Rendition (SGR) terminal escape sequences
    printf("\x1b[31mThis text has a red foreground using SGR.31.\r\n");
    printf("\x1b[1mThis text has a bright (bold) red foreground using SGR.1 to affect the previous color setting.\r\n");
    printf("\x1b[mThis text has returned to default colors using SGR.0 implicitly.\r\n");
    printf("\x1b[34;46mThis text shows the foreground and background change at the same time.\r\n");
    printf("\x1b[0mThis text has returned to default colors using SGR.0 explicitly.\r\n");
    printf("\x1b[31;32;33;34;35;36;101;102;103;104;105;106;107mThis text attempts to apply many colors in the same command. Note the colors are applied from left to right so only the right-most option of foreground cyan (SGR.36) and background bright white (SGR.107) is effective.\r\n");
    printf("\x1b[39mThis text has restored the foreground color only.\r\n");
    printf("\x1b[49mThis text has restored the background color only.\r\n");

	printf(ANSI_COLOR_RED "This text is RED!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_GREEN "This text is GREEN!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_YELLOW "This text is YELLOW!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_BLUE "This text is BLUE!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_CYAN "This text is CYAN!" ANSI_COLOR_RESET "\n");
#endif