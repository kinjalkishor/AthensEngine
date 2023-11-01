#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "base_def.h"
#include "base_ds_st.h"


// implement sys_msg_box_print function
#define fm_msg_box_ok(msg)		MessageBoxW(nullptr, L##msg, L"Error", MB_OK)
#define fm_msg_box_ok_w(msg)	MessageBoxW(nullptr, msg, L"Error", MB_OK)

inline void set_console_window_pos(int xpos, int ypos, int width, int height) {
    MoveWindow(GetConsoleWindow(), xpos, ypos, width, height, TRUE);    
}
inline void set_console_window_colors() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 /*yellow*/);
}

inline void sys_win_title_append(HWND hwnd, const char* text) {
	isz text_len = sdf::strfz_len(text);

	wchar_t wnd_text[256] = {};
	//nMaxCount: maximum number of characters to copy to the buffer, including the null character.
	int wnd_text_len = GetWindowTextW(hwnd, wnd_text, sdf::arr_cap(wnd_text));
	//wprintfln(L"%s: %d", prev_wnd_text, wnd_text_len);

	//wchar_t wtitle[256] = {};
	//isz wtitle_len = sdf::strf_assign(wtitle, sdf::strz_cap(wtitle), wnd_text, wnd_text_len);
	//wchar_t wtext_to_add[256] = {};
	//isz wtext_to_add_len = 0;
	//wtext_to_add_len = sdf::strf_wcs_from_mbs(wtext_to_add, sdf::strz_cap(wtext_to_add), text, text_len);
	//wtitle_len = sdf::strf_append(wtitle, wtitle_len, sdf::strz_cap(wtitle), wtext_to_add, wtext_to_add_len);
	//SetWindowTextW(hwnd, wtitle);

	sdf::wstring_st<255> wtitle;
	wtitle.assign_data(wnd_text, wnd_text_len);
	sdf::wstring_st<255> wtext_to_add;
	sdf::string_st_wcs_from_mbs(wtext_to_add, text, sdf::strfz_len(text));
	////wprintfln(L"%s: %d", wtext_to_add.c_str(), wtext_to_add.size());
	wtitle.append_data(wtext_to_add.data(), wtext_to_add.size());
	////wprintfln(L"%s: %d", wtitle.c_str(), wtitle.size());
	SetWindowTextW(hwnd, wtitle.c_str());
}

inline bool get_async_key_state(int vkey) {
	// high bit is set. Key is currently held down.
	return (GetAsyncKeyState(vkey) & 0x8000f);
	//return ((GetAsyncKeyState(vkey) & 0x8000) != 0); //D3D12 tut fl
	// low bit is set. Key just transitioned from released to pressed. But this unreliable.
	//return (GetAsyncKeyState(vkey) & 0x01);
}


//inline bool is_file_exists(const char* filename) {
//    ifstream ifs(filename);
//    return ifs.good();
//}
inline bool is_file_exists(const char* filename) {
    if (FILE *file = fopen(filename, "r")) {
		fclose(file);
		return true;
    } else {
        return false;
    }   
}

inline bool get_filename_ext(char* result, const char* filename) {
	// Get pointer to last '.' by reverse search
	const char* dot = strrchr(filename, '.');
	// if dot is nullptr or at location start pointed by filename, no extension found.
	if(!dot || dot == filename) { 
		strcpy(result, ""); 
		return false;
	}
	// Get extension by getting pointer to last '.' + 1 location and copying that substring
	strcpy(result, dot + 1);
	return true;
}


void sys_sleep(uint dwMilliseconds);