#pragma once

#include <string>
#include "base_def.h"

#include "base_ds_ord_map.h"



enum class dvar_type {
    dvt_int,
    dvt_int64,
    dvt_float,
	dvt_double,
	dvt_bool,
	dvt_string,
};

inline const char* dvt_str_from_type(dvar_type var_type) {
	switch (var_type) {
	case dvar_type::dvt_int64:
		return "int64";
	case dvar_type::dvt_int:
		return "int";
	case dvar_type::dvt_double:
		return "double";
	case dvar_type::dvt_float:
		return "float";
	case dvar_type::dvt_bool:
		return "bool";
	default:
		return "string";
	}
}

inline dvar_type dvt_type_from_str(const char* var_type) {
	if (sdf::strfz_equals(var_type, "int64")) {
		return dvar_type::dvt_int64;
	} else if (sdf::strfz_equals(var_type, "int")) {
		return dvar_type::dvt_int;
	} else if (sdf::strfz_equals(var_type, "double")) {
		return dvar_type::dvt_double;
	} else if (sdf::strfz_equals(var_type, "float")) {
		return dvar_type::dvt_float;
	} else if (sdf::strfz_equals(var_type, "bool")) {
		return dvar_type::dvt_bool;
	} else {
		return dvar_type::dvt_string;			
	}
}

inline dvar_type dvt_type_from_strval(const char* value) {
	if (sdf::strfz_equals(value, "true") || sdf::strfz_equals(value, "false")) {
		return dvar_type::dvt_bool;
	}

	dvar_type temp = dvar_type::dvt_int64;
	int num_dot = 0;
	isz len = strlen(value);
	for_range(i, 0, len) {
		if (isdigit(value[i])) {
			// do nothing
		} else if (value[i] == '.') {
			++num_dot;
			temp = dvar_type::dvt_double;
		} else if (value[i] == 'f' && i == len-1) {
			if (temp == dvar_type::dvt_double) {
				temp = dvar_type::dvt_float;
			} else {
				temp = dvar_type::dvt_string;
			}
		}
		else {
			temp = dvar_type::dvt_string;
		}
	}

	if (temp == dvar_type::dvt_double || temp == dvar_type::dvt_float) {
		if (num_dot > 1) { temp = dvar_type::dvt_string; }
	}

	return temp;
}

class dvar {	
public:
	dvar_type type = dvar_type::dvt_int64;
	int flags = 0;
	sdr::string name;
	sdr::string strval;  
	union {
		int64 i64val = 0;
		int ival;		
		double dval;
		float fval;
		bool bval;
	} u;


	dvar() {}
	~dvar() {}	

	void set_by_type(const char* var_name, const char* value, dvar_type var_type) {
		name = var_name;
		type = var_type;
		switch (type) {
		case dvar_type::dvt_int64:
			u.i64val = atoll(value); break;
		case dvar_type::dvt_int:
			u.ival = atoi(value); break;
		case dvar_type::dvt_double:
			u.dval = atof(value); break;
		case dvar_type::dvt_float:
			u.fval = atof(value); break;
		case dvar_type::dvt_bool:
			if (sdf::strfz_equals(value, "false") || sdf::strfz_equals(value, "0")) {
				u.bval = false; 
			} else {
				u.bval = true;
			}
			break;
		default:
			break;
		}
		strval = value;
	}	

	void set_by_strval(const char* var_name, const char* value) {
		set_by_type(var_name, value, dvt_type_from_strval(value));
	}

	void set(const char* var_name, const char* value, const char* var_type) {
		set_by_type(var_name, value, dvt_type_from_str(var_type));
	}	

	//dvar(const char* var_name, const char* value, const char* var_type) {
	//	this->set(var_name, value, var_type);
	//}

	template<class T> T get() const ;
	template<> int64 get() const { return this->u.i64val; }
	template<> int get() const { return this->u.ival; }
	template<> double get() const { return this->u.dval; }
	template<> float get() const { return this->u.fval; }	
	template<> bool get() const { return this->u.bval; }
	template<> sdr::string get() const { return this->strval; }	
	
	void print() const {
		printf("%s: %s (%s)\n", name.c_str(), strval.c_str(), dvt_str_from_type(type));
	}
};



class cfg_sys {
public:
	sdf::ord_map<sdr::string, dvar> cfg_list;
};

extern cfg_sys g_cfg;

//inline void cfg_insert_dvar(dvar var) {
//	g_cfg.cfg_list.insert({var.name, var});
//}

inline void cfg_insert(const char* var_name, const char* value, const char* var_type) {	
	dvar temp;
	g_cfg.cfg_list.insert({var_name, temp});
	g_cfg.cfg_list.find(var_name)->set(var_name, value, var_type);
}
inline void cfg_insert_val(const char* var_name, const char* value) {	
	dvar temp;
	g_cfg.cfg_list.insert({var_name, temp});
	g_cfg.cfg_list.find(var_name)->set_by_strval(var_name, value);
}
inline void cfg_set_val(const char* var_name, const char* value) {	
	auto temp = g_cfg.cfg_list.find(var_name);
	if (temp != g_cfg.cfg_list.end()) {
		temp->set_by_type(var_name, value, temp->type);
	}
}
inline void cfg_print(const char* var_name) {
	auto temp = g_cfg.cfg_list.find(var_name);
	if (temp != g_cfg.cfg_list.end()) {
		temp->print();
	} else {
		printf("%s: NOT FOUND\n", var_name); 
	}	
}

template<class T>
inline T cfg_get(const char* var_name, T value_or) {
	auto temp = g_cfg.cfg_list.find(var_name);
	if (temp != g_cfg.cfg_list.end()) {
		return temp->get<T>();
	} else {
		return value_or;
	}
}




//void ini_get_string(const char* key_name, const char* default_val, char* out_str, int out_str_len);
//int ini_get_int(const char* key_name, int default_val);

//class ini_reader_bh
//{
//public:
//	int _error;
//    std::unordered_map<std::string, std::string> _values;
//    static std::string MakeKey(const std::string& section, const std::string& name);
//    static int ValueHandler(void* user, const char* section, const char* name, const char* value);
//};