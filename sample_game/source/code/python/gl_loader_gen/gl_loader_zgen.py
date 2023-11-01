import sys
import os

original_stdout = sys.stdout

# get current working directory
path = os.getcwd()

# open output files
fo_gl_core_h = open(path + "/gl_loader_core.h","w")
fo_gl_core_cpp = open(path + "/gl_loader_core.cpp","w")
fo_gl_compat_h = open(path + "/gl_loader_compat.h","w")
fo_gl_compat_cpp = open(path + "/gl_loader_compat.cpp","w")

with_glfn_func_name = False
gl_loader_func = "load"


def printheader_in_h(profile_type):
    if (profile_type == "glcore"):
        profile_name = "core"
    elif (profile_type == "glcompat"):
        profile_name = "compat"

    print("#pragma once\n")
    if (profile_type == "glcore"):
        print("#include <glcorearb.h>\n")
    elif (profile_type == "glcompat"):
        print("#define WIN32_LEAN_AND_MEAN")
        print("#include <windows.h>")
        print("#include <gl/gl.h>")
        print("#include <glext.h>\n\n")
    print("typedef void (*PFN_apiproc)(void);")
    print("typedef PFN_apiproc (*PFN_loadfunc_gl)(const char *name);")
    print("\n//#define GL_LOADER_" + profile_name.upper() + "_PRINT_ERRORS")
# }

def printheader_in_cpp(profile_type):
    if (profile_type == "glcore"):
        profile_name = "core"
    elif (profile_type == "glcompat"):
        profile_name = "compat"
    print("#include " + '"' + "gl_loader_" + profile_name + ".h" + '"')
    print("\n#include <stdio.h>")
    print("#if defined GL_LOADER_" + profile_name.upper() + "_PRINT_ERRORS")
    print('#define print_msg(format, ...)		printf(format ' + '"\\n"' + ', __VA_ARGS__)')
    print("#else")
    print("#define print_msg")
    print("#endif")    
    print("\n")     
# }
    

gl1_func_define_list_cpp = []
gl1_init_func_versions_list_cpp = []

gl1_func_ptrtype_list_h = []

gl1_func_ptrdecl_list_h = []
gl1_func_prototype_list_h = []
gl1_func_define_list_h = []

def process_gl_1_1_msvc(fout_h, fout_cpp):
    sys.stdout = fout_h
    end_count = 0

    fin_h = open(path + "/gl.h","r")

    #---------------
    print("\n// GL_VERSION_1_0")
    Lines = fin_h.readlines()
    for line in Lines:        
        #print(line, end='')
        if (line == '/* EXT_vertex_array */\n'):
            if (end_count > 0):
                #print("\n// END REACHED")
                break
            end_count = end_count + 1    
        if line == "\n":
            #print("SKIP EMPTY LINE")
            continue

         # get list of words in current line
        words = line.split()

        if 'WINGDIAPI' in line and 'APIENTRY' in line:
            func_prototype_line_h = '// ' + line
            func_prototype_line_h = func_prototype_line_h.replace("\n", "")
            

            for i in range(0, len(words)):
                if (words[i] == 'APIENTRY' or words[i] == '*APIENTRY'):
                    func_name = words[i+1]
                    #print(func_name, end='')
                    func_name_ptr = "PFN" + func_name.upper() + "PROC"
                    func_name_glfn = "glfn_" + func_name

                    # cpp
                    func_ptrdefine_line_h = func_name_ptr + " " + func_name_glfn
                    gl1_func_define_list_cpp.append(func_ptrdefine_line_h + " = nullptr;")
                    func_init_cpp = func_name_glfn + " = (" + func_name_ptr + ")" + gl_loader_func + '("' + func_name + '");'
                    func_check_cpp = "if (!" + func_name + ') { print_msg("' + func_name + ' not loaded"); }'

            type_line = line.replace("APIENTRY", "(APIENTRYP").replace("WINGDIAPI", "typedef")
            type_line = type_line.replace(func_name, "PFN" + func_name.upper() + "PROC)")
            type_line = type_line.replace("\n", "")
            #print(type_line)     
            gl1_func_ptrtype_list_h.append(type_line)
            gl1_func_ptrdecl_list_h.append("extern " + func_name_ptr + " " + func_name_glfn + ";")
            gl1_func_prototype_list_h.append(func_prototype_line_h)
            gl1_func_define_list_h.append("#define " + func_name + " " + func_name_glfn)

            # sys.stdout = fout_cpp
            gl1_init_func_versions_list_cpp.append("\t" + func_init_cpp)
            gl1_init_func_versions_list_cpp.append("\n")
            gl1_init_func_versions_list_cpp.append("\t" + func_check_cpp)
            gl1_init_func_versions_list_cpp.append("\n")
            # sys.stdout = fout_h

    
    for i in gl1_func_ptrtype_list_h:
        print(i)

    print("\n")
    for i in range(len(gl1_func_ptrdecl_list_h)):
        print(gl1_func_ptrdecl_list_h[i])
        print(gl1_func_prototype_list_h[i])
        print(gl1_func_define_list_h[i])

    sys.stdout = fout_cpp
    print("// GL_VERSION_1_0")    
    for i in gl1_func_define_list_cpp:
        print(i)    

    print("\n")
    print("void glfnlib_init_GL_VERSION_1_0(PFN_loadfunc_gl load) {")
    for i in gl1_init_func_versions_list_cpp:
        #if (not with_glfn_func_name):
            #i = i.replace("glfn_", "")
        print(i, end='')
    print("}\n\n")
    
    
    sys.stdout = fout_h
    gl1_func_define_list_cpp.clear()
    gl1_init_func_versions_list_cpp.clear()

    gl1_func_ptrtype_list_h.clear()

    gl1_func_ptrdecl_list_h.clear()
    gl1_func_prototype_list_h.clear()
    gl1_func_define_list_h.clear()
# }



gl_core_func_define_list_cpp = []
gl_core_init_func_versions_list_cpp = []
gl_core_init_func_list_cpp = []

def process_gl_ext(fin_h, fout_h, fout_cpp, profile_type):
    sys.stdout = fout_h

    is_first_version_brace_cpp = True

    # print top header info
    if (profile_type == "glcore"):
        printheader_in_h("glcore")   
        sys.stdout = fout_cpp
        printheader_in_cpp("glcore")
        sys.stdout = fout_h     
    elif (profile_type == "glcompat"):
        printheader_in_h("glcompat")
        sys.stdout = fout_cpp
        printheader_in_cpp("glcompat")
        sys.stdout = fout_h
    
    # if compatibility profile process GL.h header file
    if (profile_type == "glcompat"):
        process_gl_1_1_msvc(fout_h, fout_cpp)

    # process header file
    Lines = fin_h.readlines()
    for line in Lines:        
        #print(line)
        # check for end & skip unneeded lines
        if (line == "#ifndef GL_ARB_ES2_compatibility\n"):
            #print('\n// END REACHED')
            break
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
                if 'GL_VERSION' in words[1]:
                    if (words[2] == '1'):                        
                        #print('\n// ' + words[1], end='')
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
                gl_core_init_func_versions_list_cpp.append("}\n\n")

            gl_core_init_func_versions_list_cpp.append("\nvoid glfnlib_init_" + version_name + "(PFN_loadfunc_gl load) {\n")
            gl_core_init_func_list_cpp.append("glfnlib_init_" + version_name + "(load);")     
            gl_core_func_define_list_cpp.append(version_line)
            #sys.stdout = fout_h


        # process function prototype lines
        if 'GLAPI' in line and 'APIENTRY' in line:
            func_prototype_line_h = '// ' + line
            func_prototype_line_h = func_prototype_line_h.replace("\n", "")

            for i in range(0, len(words)):
                if (words[i] == 'APIENTRY' or words[i] == '*APIENTRY'):
                    func_name = words[i+1]
                    #print(func_name, end='')
                    func_name_ptr = "PFN" + func_name.upper() + "PROC"
                    func_name_glfn = "glfn_" + func_name

                    # header
                    func_ptrdefine_line_h = func_name_ptr + " " + func_name_glfn
                    gl_core_func_define_list_cpp.append(func_ptrdefine_line_h + " = nullptr;")
                    func_ptrdecl_line_h = "extern " + func_ptrdefine_line_h  + ";" 
                    func_define_line_h = "#define " + func_name + " " + func_name_glfn                    
                    
                    # cpp
                    func_init_cpp = func_name_glfn + " = (" + func_name_ptr + ")" + gl_loader_func + '("' + func_name + '");'
                    func_check_cpp = "if (!" + func_name + ') { print_msg("' + func_name + ' not loaded"); }'
                    # fglCullFace = (PFNGLCULLFACEPROC)get_gl_func_address_name("glCullFace");
	                # if (!fglCullFace) { print_msg("glCullFace not loaded"); }                     
            #--------------------------------------

            if (with_glfn_func_name):
                print(func_ptrdecl_line_h, end='')
                print("")
                print(func_prototype_line_h, end='');
                print("")
                print(func_define_line_h, end='')
                print("")
            else:
                print(func_prototype_line_h, end='');
                print("")
                func_ptrdecl_noglfn_line_h = func_ptrdecl_line_h.replace("glfn_", "")
                print(func_ptrdecl_noglfn_line_h, end='')
                print("")

            # sys.stdout = fout_cpp
            gl_core_init_func_versions_list_cpp.append("\t" + func_init_cpp)
            gl_core_init_func_versions_list_cpp.append("\n")
            gl_core_init_func_versions_list_cpp.append("\t" + func_check_cpp)
            gl_core_init_func_versions_list_cpp.append("\n")
            # sys.stdout = fout_h


    loader_init_func_name = "glfnlib_load"
    
    print("\n\n// Loader Function")
    print("void " + loader_init_func_name + "(PFN_loadfunc_gl load);")

    sys.stdout = fout_cpp
    for i in gl_core_func_define_list_cpp:
        if (not with_glfn_func_name):
            i = i.replace("glfn_", "")
        print(i)
    print()

    for i in gl_core_init_func_versions_list_cpp:
        if (not with_glfn_func_name):
            i = i.replace("glfn_", "")
        print(i, end='')
    print("}")
    
    print("\n\nvoid " + loader_init_func_name + "(PFN_loadfunc_gl load) {")
    if (profile_type == "glcompat"):
        print("\tglfnlib_init_GL_VERSION_1_0(load);")
    for i in gl_core_init_func_list_cpp:
        print("\t" + i)    
    print("}")
    sys.stdout = fout_h

    gl_core_func_define_list_cpp.clear()
    gl_core_init_func_versions_list_cpp.clear()
    gl_core_init_func_list_cpp.clear()

# } // process_gl_ext


fin_gl_core_arb = open(path + "/glcorearb.h","r")
process_gl_ext(fin_gl_core_arb, fo_gl_core_h, fo_gl_core_cpp, "glcore")
fin_gl_core_arb.close()


fin_gl_compat_arb = open(path + "/glext.h","r")
process_gl_ext(fin_gl_compat_arb, fo_gl_compat_h, fo_gl_compat_cpp, "glcompat")
fin_gl_core_arb.close()

# close output files
fo_gl_core_h.close()
fo_gl_core_cpp.close()
fo_gl_compat_h.close()
fo_gl_compat_cpp.close()


# switch to console out
sys.stdout = original_stdout

print("\n\noutput files path: " + path)
print("FINISHED")
