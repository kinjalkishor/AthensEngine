#pragma once

#include "base_types.h"
#include "base_io.h"
#include "base_ds_st.h"

#include <fstream>
//#include <iostream>
//#include <sstream>
#include <string>

#include "base_ext_unord_map.h"

//#include <charconv> // from_char, to_char
//const std::string str { "12345678901234" };
//int value = 0;
//std::from_chars(str.data(),str.data() + str.size(), value);


//uvar uv1, uv2;
//sdr::string vs1 = "var xpos int = 10;";
//sdr::string vs2 = "var ypos = 50;";
//parse_var_statement(uv1, vs1);
//parse_var_statement(uv2, vs2);	
//print("\n");
//println("{}", uv1);
//println("{}", uv2);

//bool ae = string_is_int("456A");
//bool ae = string_is_float("456.6");
//println("{}", ae);

//--------------

//--------------

//var width int = 800;
//0	    1	2   3 4  5
//var height = 450;
//0 	1	 2 3  4

// std::stoi, std::stod

//uvar_insert_int("title1", 1);
//println("{}", uvar_get_int("title1"));
//uvar_insert_float("title2", 2.3);
//println("{}", uvar_get_float("title2"));
//uvar_insert_str("title3", "w1");
//println("{}", uvar_get_str("title3"));

//---------------------------
enum class uvar_type {
	uv_int,
	uv_float,
    uv_bool,
	uv_str
};

class uvar {
public:
    uvar_type type = uvar_type::uv_int;
	isz ival = 0;
	double fval = 0.0;
    sdr::string str;	
    sdr::string name;    
};



template <>
struct std::formatter<uvar> : std::formatter<std::string> {
	auto format(uvar v, format_context& ctx) {
        switch (v.type) {
            case uvar_type::uv_int:
                return formatter<string>::format(std::format("{}, {}, int", v.name, v.ival), ctx);
                break;
            case uvar_type::uv_float:
                return formatter<string>::format(std::format("{}, {}, float", v.name, v.fval), ctx);
                break;
            case uvar_type::uv_bool:
                if (v.ival == 1) {
                    return formatter<string>::format(std::format("{}, true, bool", v.name), ctx);
                } else {
                    return formatter<string>::format(std::format("{}, false, bool", v.name), ctx);
                }
                break;
            //case uvar_type::uv_str:
            //    break;
            default:
		        return formatter<string>::format(std::format("{}, {}, string", v.name, v.str), ctx);
                break;
        }
	}
};


using xfunc = void (*)(const char*);

extern ank::unordered_dense::map<sdr::string, uvar> g_var_list;
extern ank::unordered_dense::map<sdr::string, xfunc> g_func_list;

//---------
inline uvar create_uvar(const char* name, const char* value, uvar_type type) {
    uvar temp_var;
    temp_var.type = type;

    switch(type) {
        case uvar_type::uv_int:
            temp_var.ival = atoi(value);
            break;
        case uvar_type::uv_float:
            temp_var.fval = atof(value);
            break;
        case uvar_type::uv_str:            
            temp_var.str = value;   
            break;
    }

    temp_var.name = name;
    return temp_var;
}

inline void uvar_insert(const char* name, const char* value, uvar_type type) {
    g_var_list.insert({name, create_uvar(name, value, type)});
}

inline bool uvar_find(const char* name, uvar& data) {
    auto kv = g_var_list.find(name);
	if (kv != g_var_list.end()) { 
        data = kv->second; 
        //eprintfln("cvar_print: name = %s, value = %s", name.c_str(), kv->second.strval.c_str());
        return true;
    }
    //eprintfln("cvar_print: CVAR_NOT_FOUND: %s", name.c_str());
    return false;
}

inline void uvar_insert_int(const char* name, isz value) {
    uvar temp_var;
    temp_var.type = uvar_type::uv_int;
    temp_var.ival = value;    
    temp_var.name = name;
    g_var_list.insert({name, temp_var});    
}
inline void uvar_insert_float(const char* name, double value) {
    uvar temp_var;
    temp_var.type = uvar_type::uv_float;
    temp_var.fval = value;    
    temp_var.name = name;
    g_var_list.insert({name, temp_var});        
}
inline void uvar_insert_bool(const char* name, bool value) {
    uvar temp_var;
    temp_var.type = uvar_type::uv_bool;
    temp_var.ival = scast<int64>(value);    
    temp_var.name = name;
    g_var_list.insert({name, temp_var});    
}
inline void uvar_insert_str(const char* name, const char* value) {
    uvar temp_var;
    temp_var.type = uvar_type::uv_str;
    temp_var.str = value;    
    temp_var.name = name;
    g_var_list.insert({name, temp_var});    
}

//---------------
inline uvar uvar_get(const char* name, const char* default_val, uvar_type type) {
    uvar temp_var;
	if (uvar_find(name, temp_var)) { 
        return temp_var; 
    } else { 
        temp_var = create_uvar(name, default_val, type);
        g_var_list.insert({name, temp_var});    
        return temp_var; 
    }
}

inline isz uvar_get_int(const char* name, isz default_val) {
    uvar temp_var;
	if (uvar_find(name, temp_var)) { 
        return temp_var.ival; 
    } else { 
        uvar_insert_int(name, default_val);
        return default_val;
    }
}
inline double uvar_get_float(const char* name, double default_val) {
    uvar temp_var;
	if (uvar_find(name, temp_var)) { 
        return temp_var.fval; 
    } else { 
        uvar_insert_float(name, default_val);
        return default_val;
    }
}
inline bool uvar_get_bool(const char* name, bool default_val) {
    uvar temp_var;
	if (uvar_find(name, temp_var)) { 
        return scast<bool>(temp_var.ival); 
    } else { 
        uvar_insert_bool(name, default_val);
        return default_val;
    }
}
inline sdr::string uvar_get_str(const char* name, const char* default_val) {
    uvar temp_var;
	if (uvar_find(name, temp_var)) { 
        return temp_var.str; 
    } else { 
        uvar_insert_str(name, default_val);
        return default_val;
    }
}