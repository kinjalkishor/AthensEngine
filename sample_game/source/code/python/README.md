# OpenGL and Vulkan loader generator
OpenGL and Vulkan loader for C++ using Python  
See sample_project for usage.  
Can be used with both C and C++  
Shows function signature in tooltip window when hovered over function pointer or macro name, since function prototype is above function pointer declaration as comment in generated header.  
  
For OpenGL -  
Generates loaders for both core & compatibility profiles, but only one can be used at a time due to same function pointer names.  
Uses function pointers name directly starting with gl for OpenGL, if macros are desired for glfunc names instead of function pointers of same name set:  
"with_glfn_func_name = True" in gl_loader_gen.py  
  
For Vulkan -  
Uses function pointers name directly starting with vk  
vulkan/vulkan_core.h & vulkan/vulkan_win32.h are already included by loader with VK_NO_PROTOTYPES defined.  
Loader for only core & win32 headers are generated for now. But the script can be easily extended if required. Mostly same Python function can process other vulkan headers with added if else statements.  