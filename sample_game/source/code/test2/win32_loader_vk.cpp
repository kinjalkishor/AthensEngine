

#include "win32_loader_vk.h"


#include "base_types.h"

#if defined VK_STATIC
    PFN_vkGetInstanceProcAddr fvkGetInstanceProcAddr = nullptr;
    PFN_vkEnumerateInstanceExtensionProperties fvkEnumerateInstanceExtensionProperties = nullptr;   
#endif


vkwin32fn_lib vkwin32fn;


// Except Vulkan global functions other vulkan function pointers need VkInstance.
void* get_vk_func_address_name(VkInstance vk_instance, const char* name) {
    // vk_instance is the Vulkan instance that the function pointer will be compatible with, 
    // or nullptr for commands not dependent on any instance.
    void* p = (void*)vkGetInstanceProcAddr(vk_instance, name);
    if (!p) {
        p = (void*)vkGetInstanceProcAddr(nullptr, name);
    }
	return p;
}



