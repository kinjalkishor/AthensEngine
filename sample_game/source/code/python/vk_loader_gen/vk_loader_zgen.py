import sys
import os

original_stdout = sys.stdout

# get current working directory
path = os.getcwd()

# open output files
fo_vk_core_h = open(path + "/vk_loader_core.h","w")
fo_vk_core_cpp = open(path + "/vk_loader_core.cpp","w")
fo_vk_win32_h = open(path + "/vk_loader_win32.h","w")
fo_vk_win32_cpp = open(path + "/vk_loader_win32.cpp","w")

def printheader_in_h(profile_type):
    if (profile_type == "vkcore"):
        profile_name = "core"
    elif (profile_type == "vkwin32"):
        profile_name = "win32"

    print("#pragma once\n")
    print("#define VK_NO_PROTOTYPES");
    print("#include <vulkan/vulkan_core.h>\n")
    if (profile_type == "vkwin32"):
        print("#define WIN32_LEAN_AND_MEAN")
        print("#include <windows.h>")
        print("#include <vulkan/vulkan_win32.h>\n")
    print("typedef void (*PFN_apiproc)(void);")
    print("typedef PFN_apiproc (*PFN_loadfunc_vk)(VkInstance vk_instance, const char* name);")    
    print("\n//#define VK_LOADER_" + profile_name.upper() + "_PRINT_ERRORS")
    if (profile_type != "vkcore"):
        print("\n")
# }

def printheader_in_cpp(profile_type):
    if (profile_type == "vkcore"):
        profile_name = "core"
    elif (profile_type == "vkwin32"):
        profile_name = "win32"
    print("#include " + '"' + "vk_loader_" + profile_name + ".h" + '"')
    print("\n#include <stdio.h>")
    print("#if defined VK_LOADER_" + profile_name.upper() + "_PRINT_ERRORS")
    print('#define print_msg(format, ...)		printf(format ' + '"\\n"' + ', __VA_ARGS__)')
    print("#else")
    print("#define print_msg")
    print("#endif")    
    print("\n")     
# }

vk_loader_func = "load"

is_func_def_block = False

vk_core_func_define_list_cpp = []
vk_core_init_func_versions_list_cpp = []

# gl_core_func_define_list_cpp = []
# gl_core_init_func_versions_list_cpp = []
vk_core_init_func_list_cpp = []

def process_vk_ext(fin_h, fout_h, fout_cpp, profile_type):
    sys.stdout = fout_h
    global is_func_def_block

    is_first_version_brace_cpp = True

    printheader_in_h(profile_type)

    # process header file
    Lines = fin_h.readlines()
    for line in Lines:        
        # print(line, end='')
        if line == "\n":
            #print("SKIP EMPTY LINE")
            continue

        # get list of words in current line
        words = line.split()

         # process VERSION lines
        is_version_line = False
        version_line = ""
        version_name = ""

        if 0 <= 0 < len(words):
            if words[0] == "#define":                
                if 'VK_VERSION' in words[1]:
                    if (words[2] == '1'):                        
                        # print('\n// ' + words[1], end='\n')
                        version_name = words[1]
                        version_line = '// ' + version_name
                        is_version_line = True
                #print(line)

        if (is_version_line):
            print("\n")
            print(version_line, end='')
            print("")
            is_version_line = False

            #sys.stdout = fout_cpp
            if (is_first_version_brace_cpp):
                is_first_version_brace_cpp = False
            else:
                vk_core_init_func_versions_list_cpp.append("}\n\n")

            vk_core_init_func_versions_list_cpp.append("\nvoid vkfnlib_init_" + version_name + "(PFN_loadfunc_vk load, VkInstance vk_instance) {\n")
            vk_core_init_func_list_cpp.append("vkfnlib_init_" + version_name + "(load, vk_instance);")     
            vk_core_func_define_list_cpp.append(version_line)
            #sys.stdout = fout_h

        
        # process function prototype lines
        if 'VKAPI_ATTR' in line and 'VKAPI_CALL' in line:
            # print(line, end='')
            is_func_def_block = True
            # func_prototype_line_h = '// ' + line

            # print(func_prototype_line_h, end='')
            for i in range(0, len(words)):
                if (words[i] == 'VKAPI_CALL'):
                    func_name = words[i+1]
                    func_name = func_name.replace("(", "")
                    # print(func_name)
                    func_name_ptr = "PFN_" + func_name

                    # header
                    func_ptrdefine_line_h = func_name_ptr + " " + func_name
                    vk_core_func_define_list_cpp.append(func_ptrdefine_line_h + " = nullptr;")
                    func_ptrdecl_line_h = "extern " + func_ptrdefine_line_h  + ";"                 
                    
                    # cpp
                    func_init_cpp = func_name + " = (" + func_name_ptr + ")" + vk_loader_func + '(vk_instance, "' + func_name + '");'
                    func_check_cpp = "if (!" + func_name + ') { print_msg("' + func_name + ' not loaded"); }'

        # Multiline function definition
        if is_func_def_block:
            print('// ' + line, end='')
            if ';' in line:
                # print(func_name)
                print(func_ptrdecl_line_h, end='')
                print("")

                # cpp
                vk_core_init_func_versions_list_cpp.append("\t" + func_init_cpp)
                vk_core_init_func_versions_list_cpp.append("\n")
                vk_core_init_func_versions_list_cpp.append("\t" + func_check_cpp)
                vk_core_init_func_versions_list_cpp.append("\n")

                is_func_def_block = False
        
    sys.stdout = fout_cpp
    printheader_in_cpp(profile_type)

    for i in vk_core_func_define_list_cpp:
        print(i)
    print()


    loader_internal_init = ""
    if (profile_type == "vkwin32"):
        loader_internal_init = "vkfnlib_init_vkwin32"
        print("void " + loader_internal_init + "(PFN_loadfunc_vk load, VkInstance vk_instance) {")

    for i in vk_core_init_func_versions_list_cpp:
        if 'vkGetInstanceProcAddr' in i  \
        or 'vkEnumerateInstanceExtensionProperties' in i or 'vkEnumerateInstanceLayerProperties' in i \
        or 'vkCreateInstance' in i or 'vkEnumerateInstanceVersion' in i:
            i = '\t//' + i.replace('\t', '')

        print(i, end='')
    print("}")
    

    loader_init_func_name = ""
    if (profile_type == "vkcore"):
        loader_init_func_name = "vkfnlib_load_core"
    elif (profile_type == "vkwin32"):
        loader_init_func_name = "vkfnlib_load_vkwin32"

    print("\n\nvoid " + loader_init_func_name + "(PFN_loadfunc_vk load, VkInstance vk_instance) {")

    if (profile_type == "vkcore"):
        for i in vk_core_init_func_list_cpp:
            print("\t" + i) 
    else:
        print("\t" + loader_internal_init + "(load, vk_instance);") 

    print("}")


    sys.stdout = fout_h    
    print("\n\n// Loader Function")
    print("void " + loader_init_func_name + "(PFN_loadfunc_vk load, VkInstance vk_instance);")
    

    vk_core_func_define_list_cpp.clear()
    vk_core_init_func_versions_list_cpp.clear()

# } // process_vk_ext


fin_vk_core = open(path + "/vulkan_core.h","r")
process_vk_ext(fin_vk_core, fo_vk_core_h, fo_vk_core_cpp, "vkcore")
fin_vk_core.close()

fin_vk_win32 = open(path + "/vulkan_win32.h","r")
process_vk_ext(fin_vk_win32, fo_vk_win32_h, fo_vk_win32_cpp, "vkwin32")
fin_vk_win32.close()

# close output files
fo_vk_core_h.close()
fo_vk_core_cpp.close()
fo_vk_win32_h.close()
fo_vk_win32_cpp.close()

# switch to console out
sys.stdout = original_stdout

print("\n\noutput files path: " + path)
print("FINISHED")