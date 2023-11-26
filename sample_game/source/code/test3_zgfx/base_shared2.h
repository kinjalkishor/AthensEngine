#pragma once

#include "base_shared.h"

#include <vector>
#include <string>
#include <fstream>

namespace sdf
{
inline bool read_file(sdr::vector<char>& out_byte_buffer, const char* file_name, bool is_text_file_strz) {
    size_t file_length_v = 0;
    size_t alloc_length = 0;

    //std::ifstream file(file_name, std::ios::binary | std::ios::ate);
    std::ifstream file(file_name, std::ios::in | std::ios::binary | std::ios::ate);
    bool exists = (bool)file;
    if (!exists || !file.is_open()) { 
        eprintfln("Cannot open input file: %s", file_name); 
        return false; 
    }

    file_length_v = scast<size_t>(file.tellg());
    if (is_text_file_strz) {
        // Extra one char space for null char.
        alloc_length = file_length_v + 1;
    } else {
        alloc_length = file_length_v;
    }
    //sdr::vector<char> out_byte_buffer(fileSize);
    out_byte_buffer.resize(alloc_length);
    //file.seekg(0);
    file.seekg(0, std::ios::beg);
    file.read(out_byte_buffer.data(), file_length_v);
    //std::vector<uint8_t> blob;
    //file.read(reinterpret_cast<char*>(blob.data()), fileSize);
    if (is_text_file_strz) {
        // read doesn't set it so put a \0 in the last position and buffer is now a stringz
        out_byte_buffer[file_length_v] = '\0';
    }      
    file.close();

    //return out_byte_buffer;
    return true;
}

inline bool read_text_file_strz(sdr::vector<char>& out_byte_buffer, const char* file_name) {
    return read_file(out_byte_buffer, file_name, true);
}
inline bool read_binary_file(sdr::vector<char>& out_byte_buffer, const char* file_name) {
    return read_file(out_byte_buffer, file_name, false);
}

}

//===================================
template<class T>
inline void vec_clear_memory(sdr::vector<T>& v) {
	sdr::vector<T>().swap(v);
}
template<class T>
inline isz vec_size_bytes(const sdr::vector<T>& v) {
	return (sizeof(T) * v.size());
}