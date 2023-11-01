#include "test_config.h"

//#include "base_ord_vslotmap.h"

ank::unordered_dense::map<sdr::string, uvar> g_var_list;
ank::unordered_dense::map<sdr::string, xfunc> g_func_list;

//ank::unordered_dense::map<sdr::string, uvar> g_cfg_var_list;
//sdf::ord_vslotmap<sdr::string, uvar> g_cfg_var_list;
tsl::ordered_map_v<sdr::string, uvar> g_cfg_var_list;
ank::unordered_dense::map<sdr::string, xfunc> g_cfg_func_list;
//=====================================================

bool print_cfg_to_file(const tsl::ordered_map_v<sdr::string, uvar>& cfg_var_list, const char* file_name) {
    std::ofstream file;
	file.open(file_name);

	if (!file.is_open()) { 
        eprintfln("Cannot open file: %s", file_name); 
        return false; 
    }

	for (auto const &i: cfg_var_list) {
		//print("var {} = {};\n", i.second.name, i.second);
		switch (i.second.type) {
        case uvar_type::uv_int:
            file << std::format("var {} int = {};\n", i.second.name, i.second.ival);
            break;
        case uvar_type::uv_float:
            file << std::format("var {} float = {};\n", i.second.name, i.second.fval);
            break;
        case uvar_type::uv_bool:
            file << std::format("var {} bool = {};\n", i.second.name, scast<bool>(i.second.ival));
            break;
        //case uvar_type::uv_str:
        //    break;
        default:
            file << std::format("var {} string = {};\n", i.second.name, i.second.str);
            break;
        }    
	}

	file.close();
    return true;
}

// not declared
void parse_with_type(uvar& out, const sdr::vector<sdr::string>& token_list) {

    //1 /2/4
    out.name = token_list[1];

    if (token_list[2] == "int") {
        out.type = uvar_type::uv_int;
        out.ival = std::stoll(token_list[4].c_str());                    
    } else if (token_list[2] == "float") {
        out.type = uvar_type::uv_float;
        out.fval = std::stod(token_list[4].c_str());
    } else if (token_list[2] == "bool") {
        out.type = uvar_type::uv_bool;
        if (token_list[4] == "true") {
            out.ival = 1;
        } else {
            out.ival = 0;
        }
    } else if (token_list[2] == "string") {
        out.type = uvar_type::uv_str;
        //out.str = token_list[4];
        copy_from_string_token(out.str, token_list[4]);
    }
}
// not declared
void parse_without_type(uvar& out, const sdr::vector<sdr::string>& token_list) {

    //1 /3
    out.name = token_list[1];

    if (string_is_int(token_list[3])) {
        out.type = uvar_type::uv_int;
        out.ival = std::stoll(token_list[3].c_str());
    } else if (string_is_float(token_list[3])) {
        out.type = uvar_type::uv_float;
        out.fval = std::stod(token_list[3].c_str());
    } else if (string_is_bool(token_list[3])) {
        out.type = uvar_type::uv_bool;
        if (token_list[3] == "true") {
            out.ival = 1;
        } else {
            out.ival = 0;
        }
    } else {
        out.type = uvar_type::uv_str;
        //out.str = token_list[3];      
        copy_from_string_token(out.str, token_list[3]);
    }
}

void tokenize_var_statement(sdr::vector<sdr::string>& token_list, const sdr::string& str) {
    //print("{}", str);

    //sdr::vector<sdr::string> token_list;

    char prev_char = 'A';

    isz token_num = 0;
    sdr::string curr_token;
    curr_token.reserve(256);

    for (isz i = 0; i < str.size(); ++i) {
        //print("{}", str[i]);
        switch (str[i]) {
            case '\n':
                break;

            case '\"': 
                    // Processing doesn't come here till after closing ", so " is inserted only at start.
                    curr_token += str[i]; // Insert " at start to identify token as string

                    // Quoted strings, do not skip space
                    for (isz j = i+1; j < str.size(); ++j) {
                        if (str[j] == '\"') {
                            i = j;
                            token_list.push_back(curr_token);
                            curr_token.clear();
                            goto exit_switch;
                        } else {
                            curr_token += str[j];
                        }
                    }
                break;

            case ';':          
                if (prev_char != '\"') {
                    token_list.push_back(curr_token);
                    curr_token.clear();
                }
                token_list.push_back(";");
                //token_list.push_back(";\n");
                break;

            case ' ':
                if (prev_char != '\"') {
                    token_list.push_back(curr_token);
                    curr_token.clear();
                }
                break;

            default:
                curr_token += str[i];

            // goto label to exit switch
            exit_switch:
                break;
        }
        prev_char = str[i];
    }

    //for (isz i = 0; i < token_list.size(); ++i) {
    //    print("{}|", token_list[i]);
    //}

    //-------------
    //token_list.push_back("\n");
    //print("\n");
}

void parse_var_statement(uvar& out, sdr::string str, bool is_deduce_type_also) {
	sdr::vector<sdr::string> token_list;
	tokenize_var_statement(token_list, str);
    if (token_list[0] == "var") {
        if (token_list.size() == 6) {
            if (token_list[5] == ";") {
                parse_with_type(out, token_list);
            }
        }

        if (is_deduce_type_also) {
            if (token_list.size() == 5) {
                if (token_list[4] == ";") {
                    parse_without_type(out, token_list);
                }
            }
        }
    }

    //for (isz i = 0; i < token_list.size(); ++i) { print("{}|", token_list[i]); }
}

//void parse_cfg_file(ank::unordered_dense::map<std::string, uvar>& out_cfg_var_list, const char* file_name) {
//void parse_cfg_file(sdf::ord_vslotmap<sdr::string, uvar>& out_cfg_var_list, const char* file_name) {
void parse_cfg_file(tsl::ordered_map_v<sdr::string, uvar>& out_cfg_var_list, const char* file_name) {
    static char look;

    sdr::string curr_statement;
    curr_statement.reserve(1024);

     std::fstream newfile;   
     newfile.open(file_name, std::ios::in); 
     if (newfile.is_open()) {      
         while (newfile.get(look)) {
             uvar temp;
             //print("{}", look);

             switch (look) {
                case ';':
                    curr_statement += look;
                    //print("{}", curr_statement);
                    parse_var_statement(temp, curr_statement, false);
                    // If uvar was empty, error do not insert.
                    if (!temp.name.empty()) {
                        out_cfg_var_list.insert({temp.name.c_str(), temp});
                        //out_cfg_var_list.insert(temp.name, temp); //ord_vslotmap
                    }
                    curr_statement.clear();
                    break;
                default:
                    curr_statement += look;
                    break;
             }             
         }

         print("---\n");
         newfile.close(); 
     }
}


//=====================================================


//=======================================================

#if 0
#endif