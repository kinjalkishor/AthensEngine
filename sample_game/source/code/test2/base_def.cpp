#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace sdf
{

//==========================================
// WideCharToMultiByte function exposes the encodings/code pages used for the conversion in the parameter list, while wcstombs does not.
// CP_ACP, means a codepage specific to the systems current locale - set in the  
// control panel Localization tool "Language to use for Non Unicode Programs".
// Windows only
// dest_num_chars is dest capacity to hold chars without null char.
int mb_wcs_from_mbs(wchar_t* dest, int dest_num_chars, const char* src, int src_len) {	
	const int dest_size_with_null_char = dest_num_chars+1;
	//mbstowcs(dest, src, copy_len);
	int result = MultiByteToWideChar(CP_UTF8, 0, src, src_len, dest, dest_size_with_null_char);	
	return result;
}
int mb_mbs_from_wcs(char* dest, int dest_num_chars, const wchar_t* src, int src_len) {
	const int dest_size_with_null_char = dest_num_chars+1;
	//wcstombs(dest, src, copy_len);
	int result = WideCharToMultiByte(CP_UTF8, 0, src, src_len, dest, dest_size_with_null_char, nullptr, nullptr);	
	return result;
}

}