#pragma once

#include <vector>
#include <string>

namespace sdf
{

bool read_file(sdr::vector<char>& out_byte_buffer, const char* file_name, bool is_text_file_strz);
char* read_file_c(const char* file_name, size_t& file_length, bool is_text_file_strz);


//---------------------------
inline bool read_text_file_strz(sdr::vector<char>& out_byte_buffer, const char* file_name) {
    return read_file(out_byte_buffer, file_name, true);
}
inline bool read_binary_file(sdr::vector<char>& out_byte_buffer, const char* file_name) {
    return read_file(out_byte_buffer, file_name, false);
}

bool read_text_file_string(sdr::string& out_string, const char* file_name);


//---------------------------
inline char* read_text_file_strz_c(const char* file_name, size_t& file_length) {
    return read_file_c(file_name, file_length, true);
}
inline char* read_binary_file_c(const char* file_name, size_t& file_length) {
    return read_file_c(file_name, file_length, false);
}

}


//============================================================








