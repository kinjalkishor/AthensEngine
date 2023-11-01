#pragma once

#include "base_io.h"

#include "base_ds_st.h"

#include <fstream>
//#include <iostream>
//#include <sstream>
#include <string>

#include "base_ext_unord_map.h"
//#include "base_ord_vslotmap.h"

#include "base_uvar.h"


//extern ank::unordered_dense::map<sdr::string, uvar> g_cfg_var_list;
//extern sdf::ord_vslotmap<sdr::string, uvar> g_cfg_var_list;
extern tsl::ordered_map_v<sdr::string, uvar> g_cfg_var_list;
extern ank::unordered_dense::map<sdr::string, xfunc> g_cfg_func_list;
//-----------------

bool print_cfg_to_file(const tsl::ordered_map_v<sdr::string, uvar>& cfg_var_list, const char* file_name);
//-----------------

void tokenize_var_statement(sdr::vector<sdr::string>& token_list, const sdr::string& str);

void parse_var_statement(uvar& out, sdr::string str, bool is_deduce_type_also);

//void parse_cfg_file(ank::unordered_dense::map<std::string, uvar>& out_cfg_var_list, const char* file_name);
//void parse_cfg_file(sdf::ord_vslotmap<sdr::string, uvar>& out_cfg_var_list, const char* file_name);
void parse_cfg_file(tsl::ordered_map_v<sdr::string, uvar>& out_cfg_var_list, const char* file_name);

//-----------------
//
//void parse_line(const sdr::string& str, sdr::vector<sdr::string>& token_list);
//
//void parse_file_lines(const char* file_name, sdr::vector<sdr::string>& token_list);
//
//void parse_config_token_list(sdr::vector<sdr::string>& token_list);

//---------
// copy string from in to out excluding starting " of string_token
inline void copy_from_string_token(sdr::string& out, const sdr::string& in) {
    out.resize(in.size()-1);
    for_range (i, 0, in.size()) {
        out[i] = in[i+1];
    }
}

//---------
inline bool string_is_bool(const sdr::string& str) {
	if (str == "true" || str == "false") {
		return true;
	}
	return false;
}

inline bool string_is_int(const sdr::string& str) {
	isz start_at = 0;
	if (str.size() > 1) {
		if (str[0] == '+' || str[0] == '-') { 			
			if (isdigit(str[1])) { 
				start_at = 1;
			} else {
				return false;
			}
		}
	}

	for_range (i, start_at, str.size()) {
		if (!isdigit(str[i])) {	
			return false;
		}	
	}
	return true;
}

inline bool string_is_float(const sdr::string& str) {
	bool first_dot_flag = false;
	char prev_char = ';';

	if (str[str.size()-1] == '.') {
		return false; // No last dot
	}

	isz start_at = 0;
	if (str.size() > 1) {
		if (str[0] == '+' || str[0] == '-') { 			
			if (isdigit(str[1])) { 
				start_at = 1;
			} else {
				return false;
			}
		}
	}

	for_range (i, start_at, str.size()) {
		if (!isdigit(str[i])) {
			if (first_dot_flag == true) {
				if (str[i] == '.') { return false; } // No 2 dots						
			}

			if (str[i] == '.') {
				first_dot_flag = true;
			} else {
				return false;
			}			
		}
		prev_char = str[i];
	}

	if (first_dot_flag == false) { return false; } // No dot found, it is an int
	return true;
}
