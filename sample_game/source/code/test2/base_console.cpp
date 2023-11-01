#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdio.h>

#include "base_def.h"
#include "base_console.h"


namespace std_console_local
{
//const uint color_blue = FOREGROUND_BLUE;
//const uint color_green = FOREGROUND_GREEN;
//const uint color_red = FOREGROUND_RED;
////cyan is green+blue, magenta is red+blue, and yellow is red+green
//const uint color_cyan = FOREGROUND_BLUE | FOREGROUND_GREEN;
//const uint color_magenta = FOREGROUND_BLUE | FOREGROUND_RED;
//const uint color_yellow = FOREGROUND_GREEN | FOREGROUND_RED;	

const uint color_black			= 0;
const uint color_blue			= 1; 
const uint color_green			= 2;  
const uint color_cyan			= 3;  
const uint color_red			= 4;    
const uint color_magenta		= 5;
const uint color_yellow			= 6;
const uint color_white			= 7;
const uint color_bright_black	= 8;
const uint color_bright_blue	= 9;
const uint color_bright_green	= 10;
const uint color_bright_cyan	= 11;
const uint color_bright_red		= 12;
const uint color_bright_magenta	= 13;
const uint color_bright_yellow  = 14;
const uint color_bright_white	= 15;

// default is white color
const uint color_default = color_white;
}

std_console::~std_console() {
	FreeConsole();
	//check if(hconsole)
}

bool std_console::create_window(const char* window_title, int xpos, int ypos, int width, int height) {
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
	sdf::strf_wcs_from_mbs(wconsole_title, sdf::strz_cap(wconsole_title), window_title, sdf::strfz_len(window_title));
	SetWindowTextW(console_window, wconsole_title);	

	// The freopen_s function closes the file currently associated with stream and reassigns stream to the file specified by path.
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);
	//printf("Debugging Window:\n");

	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hconsole, std_console_local::color_yellow);

	//set_console_colors(bg_color);

	return true;
}


