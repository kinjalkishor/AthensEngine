#include "base_def.h"
#include "base_print.h"

#include "base_def2.h"

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>

#include <vector>
#include <string>


namespace sdf
{

bool read_file(sdr::vector<char>& out_byte_buffer, const char* file_name, bool is_text_file_strz) {
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



bool read_text_file_string(sdr::string& out_string, const char* file_name) {
	std::ifstream filesrc_stream(file_name, std::ios::in | std::ios::binary);

	if (filesrc_stream.is_open()) {
		// fastest 
		filesrc_stream.seekg(0, std::ios::end);
        out_string.resize(filesrc_stream.tellg());
        filesrc_stream.seekg(0, std::ios::beg);
        filesrc_stream.read(&out_string[0], out_string.size());
        filesrc_stream.close();
	} else {
	    eprintfln("Cannot open input file: %s", file_name);
	    return false;
	}

	return true;
}



//-----------------------
// read_file_c will fail on greater than 2 GB files as fseek and ftell use long int.
// Use _fseeki64, _ftelli64 or posix: fseeko64, ftello64 (fopen64, freopen64)
#define fopeni64 fopen
#define fseeki64 _fseeki64
#define ftelli64 _ftelli64

char* read_file_c(const char* file_name, size_t& file_length, bool is_text_file_strz) {   
    size_t file_length_v = 0;
    size_t alloc_length = 0;

    char* buffer = nullptr;
    //sdr::string contents;
    FILE* fp = fopeni64(file_name, "rb");
    
    if (fp) {        
        // Seek the last byte of the file
        fseeki64(fp, 0, SEEK_END);
        // Offset from the first to the last byte, get the filesize
        file_length_v = ftelli64(fp);     
        // Go back to the start of the file
        //fseeki64(fptr, 0, SEEK_SET);
        rewind(fp);
        // Allocate a string that can hold it all
        if (is_text_file_strz) {
            // Extra one char space for null char.
            alloc_length = file_length_v + 1;
        } else {
            alloc_length = file_length_v;
        }
        buffer = scast<char*>(malloc(sizeof(char) * (alloc_length)));
        //contents.resize(alloc_length);
        // Read it all in one operation
        fread(buffer, sizeof(char), file_length_v, fp);
        //fread(&contents[0], sizeof(char), file_length_v, fp);
        if (is_text_file_strz) {
            // fread doesn't set it so put a \0 in the last position and buffer is now a stringz
            buffer[file_length_v] = '\0';
            //contents[file_length_v] = '\0';
        }        
        // Close the file.
        fclose(fp);        

        file_length = file_length_v;
    } else {
        file_length = 0;
	    eprintfln("Cannot open input file: %s", file_name);
	}
    //throw(errno);
    //return(contents);

    return buffer;
}

}