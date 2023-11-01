import sys
import os

original_stdout = sys.stdout

path = os.getcwd()

file_out1h = open(path + "/gl_loader_core.h","w")
file_out1cpp = open(path + "/gl_loader_core.cpp","w")
file_out2h = open(path + "/gl_loader_compat.h","w")
file_out2cpp = open(path + "/gl_loader_compat.cpp","w")
# Change the standard output to the file we created.

compat_glfunc_list = []
compat_func_list = []
core_func_list = []

# func_ptr_prefix = "pf_"
func_ptr_prefix = "f"
loader_func = "get_gl_func_address_name"

def printheader_h(profile_type):
    print("#pragma once\n")
    if (profile_type == "core"):
        print("#include <glcorearb.h>\n")
    else:
        print("#define WIN32_LEAN_AND_MEAN")
        print("#include <windows.h>")
        print("#include <gl/gl.h>")
        print("#include <glext.h>\n\n")
    print("typedef void (*PFN_apiproc)(void);")
    print("typedef PFN_apiproc (*PFN_loadfunc)(const char *name);")
    print("void* get_gl_func_address_name(const char* name);")

def printheader_cpp(profile_type):
    print("#include " + '"' + "gl_loader_" + profile_type + ".h" + '"')
    print()
    print("#include " + '"../base_print.h"')
    print("#define print_msg printfln")
    print("\n//#define print_msg\n\n")

    if (profile_type == "core"):
        print("glfn_core_ver_4_6 glfn;\n")
    elif (profile_type == "compat"):
        print("glfn_compat_ver_4_6 glfn;\n")
#end

def process_gl_1_1_msvc(gfile1, out_h, out_cpp):    
    global compat_func_list

    sys.stdout = out_h 

    printheader_h("compat")

    func_typedef_list1 = []
    func_decl_list1 = []
    func_load_list1 = []
    func_load_check_list1 = []
    cpp_list1 = []

    end_count = 0
    process_func_line1 = False

    Lines1 = gfile1.readlines()
    for line in Lines1: 
        if (line == "/* EXT_vertex_array */\n"):                
            if (end_count > 0):
                # print("END REACHED")
                break
            end_count = end_count + 1    
        if line == "\n":
            # print("SKIP EMPTY LINE")
            continue

        gwords = line.split()
        if 0 <= 0 < len(gwords):
            if gwords[0] == "WINGDIAPI":
                process_func_line1 = True
            else:
                process_func_line1 = False

        if process_func_line1:
            # print(line, end="")   
            
            func_name = ""
            for i, word in enumerate(gwords):
                if (word[0] == "("):
                    func_name = gwords[i-1]
                    # print(func_name)
                    # gfunc_list.append(func_name)

            # print(gline, end="")   
            # print(func_name)
            type_line = line.replace("APIENTRY", "(APIENTRYP").replace("WINGDIAPI", "typedef")
            type_line = type_line.replace(func_name, "PFN" + func_name.upper() + "PROC)")
            type_line = type_line.replace("\n", "")
            # print(type_line, end="")    
            func_typedef_list1.append(type_line)

            gptr_decl = "PFN" + func_name.upper() + "PROC " + func_ptr_prefix + func_name + " = nullptr;"
            # print(gptr_decl)  
            func_decl_list1.append(gptr_decl)

            func_load_list1.append(func_ptr_prefix + func_name + " = (PFN" + func_name.upper() + "PROC)" + loader_func + '("' + func_name + '");')
            func_load_check_list1.append("if (!f" + func_name + ") { print_msg(" + '"' + func_name + " not loaded" + '"' + "); }")

            compat_glfunc_list.append(func_name)

        

    for ln in func_typedef_list1:
        print(ln)
    print("\n\n")

    print("class glfn_compat_ver_1_1 {\npublic:\n")
    for ln in func_decl_list1:
        print("\t", end='');
        print(ln)
    print("\n\tvoid init(PFN_loadfunc load);")
    print("\n};\n")

    cpp_list1.append("void glfn_compat_ver_1_1::init(PFN_loadfunc) {\n")
    curr_val1 = ""
    # curr_val1 = curr_val1 + ("void " + last_class_name + "::init(PFN_loadfunc load) {\n")
    for i, ln in enumerate(func_load_list1):   
        curr_val1 = curr_val1 + ("\t") 
        curr_val1 = curr_val1 + (ln + "\n")  
        curr_val1 = curr_val1 + "\t" + func_load_check_list1[i] + "\n"
    curr_val1 = curr_val1 + ("}\n")
    curr_val1 = curr_val1 + ("\n")       

    cpp_list1.append(curr_val1);

    sys.stdout = out_cpp 

    printheader_cpp("compat")
    for ln in cpp_list1:
        print(ln)

    # gfile1.close()
# end process_gl_1_1_msvc

def process_gl_ext(file1, out_h, out_cpp, profile_type):
    sys.stdout = out_h

    if (profile_type == "core"):
        printheader_h("core")

    func_decl_list = []
    func_load_list = []
    func_load_check_list = []
    func_def_list = []
    func_def_rv_list = []

    cpp_list = []

    prev_last_class_name = ""
    last_class_name = ""
    first_time = True

    process_func_line = False
    process_ver_line = False

    def display():
        nonlocal func_decl_list
        nonlocal func_load_list
        nonlocal func_load_check_list
        nonlocal func_def_list
        nonlocal func_def_rv_list
        
        inherited = ""
        if (profile_type == "compat"):
            inherited = ": public glfn_" + profile_type + "_ver_1_1"
        if prev_last_class_name:
            inherited = " : public " + prev_last_class_name
        now = "\n\n\nclass " + last_class_name + inherited + " {\npublic:\n"
        print(now)

        for ln in func_decl_list:    
            print("\t", end='')
            print(ln) 
        print()
        # print("\n")

        # print("\tvoid init(PFN_loadfunc load) {")
        # if (prev_last_class_name):
        #     print("\t\t" + prev_last_class_name + "::init(load);")
        # for ln in func_load_list:   
        #     print("\t\t", end='') 
        #     print(ln)  
        # print("\t}")
        # print("\n\n")       

        print("\tvoid init(PFN_loadfunc load);")
        curr_val = ""
        curr_val = curr_val + ("void " + last_class_name + "::init(PFN_loadfunc load) {\n")
        if (prev_last_class_name):
            curr_val = curr_val + ("\t" + prev_last_class_name + "::init(load);\n\n")
        else:
            if (profile_type == "compat"):
                curr_val = curr_val + ("\t" + "glfn_compat_ver_1_1" + "::init(load);\n\n")

        for i, ln in enumerate(func_load_list):   
            curr_val = curr_val + ("\t") 
            curr_val = curr_val + (ln + "\n")  
            curr_val = curr_val + "\t" + func_load_check_list[i] + "\n"
        curr_val = curr_val + ("}\n")
        curr_val = curr_val + ("\n\n")       

        cpp_list.append(curr_val);

        # for ln in func_load_check_list:    
        #     print(ln) 
        # print()
        
        # for i in range(len(func_def_list)):
        #     print("\t", end='') 
        #     print(func_def_list[i])
        #     print("\t", end='') 
        #     print(func_def_rv_list[i])
        #     print("\t", end='') 
        #     print("}\n")

        print("};")
        func_decl_list = []
        func_load_list = []
        func_load_check_list = []
        func_def_list = []
        func_def_rv_list = []
        
    # end display    

    # printheader_h(profile_type)

    #--------------------------------------------------------------------------------    
    Lines = file1.readlines()
    for line in Lines:        
        # print(line)
        if (line == "#ifndef GL_ARB_ES2_compatibility\n"):
            # print("END REACHED")
            break
        if line == "\n":
            # print("SKIP EMPTY LINE")
            continue
        if (line == "#ifndef APIENTRY\n" or line == "#define APIENTRY\n" or line == "#define APIENTRYP APIENTRY *\n"):
            # print("SKIP THIS LINE")
            continue

        words = line.split()
        if 0 <= 0 < len(words):
            if words[0] == "GLAPI":
                process_func_line = True
            else:
                process_func_line = False

        if 0 <= 0 < len(words):
            if words[0] == "#ifndef":
                curr_name = ""
                for i, word in enumerate(words):
                    if 0 <= i+1 < len(words):                
                        ver_name = words[i+1]
                        ver_name_c = ver_name[:10]
                        
                        if (ver_name_c == "GL_VERSION"):
                            # print("--" + words[i])
                            curr_name = ver_name[10:]
                            # if first_time:
                            #     curr = "\n\n\nclass glfn_ver" + curr_name + "" + last_class_name + " {\npublic:\n"
                                # print(curr)
                                
                            if not first_time:
                                display()

                            prev_last_class_name = last_class_name
                            last_class_name = "glfn_" + profile_type + "_ver" + curr_name
                            first_time = False


        if process_func_line:
            func_name = ""
            params_list = []
            # print(line, end = '')
            line = line.replace("*const*", "* const* ")
            words = line.split()
            last_words_index = len(words)-1
            # in_parans = False
            for i, word in enumerate(words):
                j = 0
                last_index = len(word)-1
                # while word[len(word)-1] != ")":
                if (word[0] == "("):
                    func_name = words[i-1]
                    # print(func_name)
                    # print(words[i].replace("(void);", "void"))
                
                if (word[last_index] == ","):
                    str1 = words[i].replace(",", "")
                    # str1 = str1.replace("(void", "void")
                    # print(words[i].replace("(void", "void").replace(",", ""))    
                    # print(str1)
                    params_list.append(str1)            

                char_remov = [')', ';', '*']        
                if (word[last_index] == ";"):            
                    # for char in char_remov:
                    #     word = word.replace(char, "")
                    # word = word.replace("(", "")
                    # print(word)
                    params_list.append(word)


            func_decl_list.append("PFN" + func_name.upper() + "PROC " + func_ptr_prefix + func_name + " = nullptr;")
            # print(func_name)

            
            func_load_list.append(func_ptr_prefix + func_name + " = (PFN" + func_name.upper() + "PROC)" + loader_func + '("' + func_name + '");')

            func_load_check_list.append("if (!f" + func_name + ") { print_msg(" + '"' + func_name + " not loaded" + '"' + "); }")

            curr_load = line.replace("\n", "").replace("GLAPI ", "").replace("APIENTRY ", "").replace("*APIENTRY ", "")
            curr_load = curr_load.replace(";", " {")
            curr_load = curr_load.replace("gl", "fgl")
            curr_load = curr_load.replace(" (", "(")
            func_def_list.append(curr_load)

            curr_return_s = "\treturn " + func_ptr_prefix + func_name + "("    
            for curr_param in params_list:
                curr_param = curr_param.replace(");", "").replace("*", "");
                curr_param = curr_param.replace("(void", "")
                # print(curr_param, end=' : ')        
                curr_return_s = curr_return_s + curr_param + ", "

            curr_return_s = curr_return_s + ");"
            curr_return_s = curr_return_s.replace(", );", ");")
            # print()        
            func_def_rv_list.append(curr_return_s)
            # # print("\n")

            if (profile_type == "core"):
                core_func_list.append(func_name)
            elif (profile_type == "compat"):
                compat_func_list.append(func_name)
            
    display()       

    if (profile_type == "core"):
        print("\n\nextern glfn_core_ver_4_6 glfn;\n")
    elif (profile_type == "compat"):
        print("\n\nextern glfn_compat_ver_4_6 glfn;\n")

    # file_out2cpp.close()
    # print cpp file
    # file_out = open("E:/Documents/Downloads/web pages/drivers/gl_loader_compat.cpp","w")
    sys.stdout = out_cpp 


    if (profile_type == "core"):
        printheader_cpp("core")
        
    print("\n")
    for ln in cpp_list:    
        print(ln) 
#end   



gfile1_1 = open(path + "/gl.h","r")
file_gl_ext = open(path + "/glext.h","r")
process_gl_1_1_msvc(gfile1_1, file_out2h, file_out2cpp)
process_gl_ext(file_gl_ext, file_out2h, file_out2cpp, "compat")
gfile1_1.close()
file_gl_ext.close()

file_core_arb = open(path + "/glcorearb.h","r")
process_gl_ext(file_core_arb, file_out1h, file_out1cpp, "core")
file_core_arb.close()

file_out1h.close()
file_out1cpp.close()
file_out2h.close()
file_out2cpp.close()


file_out3h_compat = open(path + "/gl_func_def_compat.h","w")
file_out3h_core = open(path + "/gl_func_def_core.h","w")

sys.stdout = file_out3h_compat
for ln in compat_glfunc_list:
    print(ln)
for ln in compat_func_list:
    print(ln)


sys.stdout = file_out3h_core
for ln in core_func_list:
    print(ln)


    

file_out3h_compat.close()
file_out3h_core.close()

sys.stdout = original_stdout

print("\n\noutput files path: " + path)
print("FINISHED")