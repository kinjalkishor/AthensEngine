#pragma once

#include "base_def.h"
#include "base_print.h"

#include <memory>

// If want to use LunarG VulkanSDK static loading.
//#define VK_STATIC

#if !defined VK_STATIC
    #include "vk_loader/vk_loader_core.h"
    #include "vk_loader/vk_loader_win32.h"
#else
    #include <vulkan/vulkan_core.h>
    #define WIN32_LEAN_AND_MEAN
    #include <Windows.h>
    #include <vulkan/vulkan_win32.h>
    #pragma comment(lib, "VulkanSDK/Lib/vulkan-1.lib")
#endif



#if !defined VK_STATIC
    #define LOAD_VULKAN_GLOBAL_FUNCTION(name)                   \
    name = (PFN_##name)vkGetInstanceProcAddr(nullptr, #name);   \
    if (!name) { printfln(#name " not loaded."); } 
#else
    #define LOAD_VULKAN_GLOBAL_FUNCTION(name)
    extern PFN_vkGetInstanceProcAddr fvkGetInstanceProcAddr;
    extern PFN_vkEnumerateInstanceExtensionProperties fvkEnumerateInstanceExtensionProperties;   
#endif

inline VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {
#if !defined VK_STATIC
    auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
#else
    auto func = (PFN_vkCreateDebugUtilsMessengerEXT)fvkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
#endif
    if (func != nullptr) {
        return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
    } else {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

inline void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
#if !defined VK_STATIC
    auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
#else
    auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)fvkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
#endif
    if (func != nullptr) {
        func(instance, debugMessenger, pAllocator);
    }
}

//#define LOAD_VULKAN_FUNCTION(name)                   \
//name = (PFN_##name)get_vk_func_address_name(#name);   \
//if (!name) { printfln(#name " not loaded."); } 

void* get_vk_func_address_name(VkInstance vk_instance, const char* name);

class vkwin32fn_lib {
public:

    // Handle to Vulkan dll.
    HMODULE hinstance_dll = nullptr;


    // Use vector
    static constexpr int extensions_count = 2;
    const char* extensions[extensions_count] = {};


    bool is_vk_KHR_surface = false;   
    bool is_vk_KHR_win32_surface = false;


    const char* get_vulkan_result_string(VkResult result) {
        switch (result) {
            case VK_SUCCESS:
                return "Success";
            case VK_NOT_READY:
                return "A fence or query has not yet completed";
            case VK_TIMEOUT:
                return "A wait operation has not completed in the specified time";
            case VK_EVENT_SET:
                return "An event is signaled";
            case VK_EVENT_RESET:
                return "An event is unsignaled";
            case VK_INCOMPLETE:
                return "A return array was too small for the result";
            case VK_ERROR_OUT_OF_HOST_MEMORY:
                return "A host memory allocation has failed";
            case VK_ERROR_OUT_OF_DEVICE_MEMORY:
                return "A device memory allocation has failed";
            case VK_ERROR_INITIALIZATION_FAILED:
                return "Initialization of an object could not be completed for implementation-specific reasons";
            case VK_ERROR_DEVICE_LOST:
                return "The logical or physical device has been lost";
            case VK_ERROR_MEMORY_MAP_FAILED:
                return "Mapping of a memory object has failed";
            case VK_ERROR_LAYER_NOT_PRESENT:
                return "A requested layer is not present or could not be loaded";
            case VK_ERROR_EXTENSION_NOT_PRESENT:
                return "A requested extension is not supported";
            case VK_ERROR_FEATURE_NOT_PRESENT:
                return "A requested feature is not supported";
            case VK_ERROR_INCOMPATIBLE_DRIVER:
                return "The requested version of Vulkan is not supported by the driver or is otherwise incompatible";
            case VK_ERROR_TOO_MANY_OBJECTS:
                return "Too many objects of the type have already been created";
            case VK_ERROR_FORMAT_NOT_SUPPORTED:
                return "A requested format is not supported on this device";
            case VK_ERROR_SURFACE_LOST_KHR:
                return "A surface is no longer available";
            case VK_SUBOPTIMAL_KHR:
                return "A swapchain no longer matches the surface properties exactly, but can still be used";
            case VK_ERROR_OUT_OF_DATE_KHR:
                return "A surface has changed in such a way that it is no longer compatible with the swapchain";
            case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:
                return "The display used by a swapchain does not use the same presentable image layout";
            case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:
                return "The requested window is already connected to a VkSurfaceKHR, or to some other non-Vulkan API";
            case VK_ERROR_VALIDATION_FAILED_EXT:
                return "A validation layer found an error";
            default:
                return "ERROR: UNKNOWN VULKAN ERROR";
        }
    }

	bool init() {    
        // Load Vulkan functions.

        // Load Vulkan dll.
        hinstance_dll = LoadLibraryW(L"vulkan-1.dll");       
        if (!hinstance_dll) {
            eprintfln("Cannot load Vulkan dll");
            return false;
        }
        
    #if !defined VK_STATIC
        // Load vkGetInstanceProcAddr from Vulkan dll first.
        vkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)GetProcAddress(scast<HMODULE>(hinstance_dll), "vkGetInstanceProcAddr");
	    if (!vkGetInstanceProcAddr) { 
            printfln("vkGetInstanceProcAddr not loaded."); 
            return false;
        }
    #else
        fvkGetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)GetProcAddress(scast<HMODULE>(hinstance_dll), "vkGetInstanceProcAddr");
    #endif

        // Load Vulkan global-level functions.
        // Load vkCreateInstance since other vulkan functions can be loaded after VkInstance is created.
        // Vulkan functions can be divided into three levels, which are global, instance, and device. 
        // Device-level functions are used to perform typical operations such as drawing, shader-modules creation, 
        // image creation, or data copying. Instance-level functions allow us to create logical devices. 
        // To do all this, and to load device and instance-level functions, we need to create an Instance. 
        // This operation is performed with global-level functions, which we need to load first.
        // In Vulkan global-level functions are: 
        // vkEnumerateInstanceExtensionProperties(), vkEnumerateInstanceLayerProperties(), and vkCreateInstance(), vkEnumerateInstanceVersion(); 
        // They are used during Instance creation to check, what instance-level extensions and layers are available and to create the Instance itself.       
        //vkCreateInstance = (vkCreateInstance)vkGetInstanceProcAddr(nullptr, "vkCreateInstance");
        //if (!vkCreateInstance) { printfln("vkCreateInstance not loaded."); }  
    #if !defined VK_STATIC
        LOAD_VULKAN_GLOBAL_FUNCTION(vkEnumerateInstanceExtensionProperties)
        LOAD_VULKAN_GLOBAL_FUNCTION(vkEnumerateInstanceLayerProperties)
        LOAD_VULKAN_GLOBAL_FUNCTION(vkCreateInstance)
        LOAD_VULKAN_GLOBAL_FUNCTION(vkEnumerateInstanceVersion)
    #else
        fvkEnumerateInstanceExtensionProperties = 
            (PFN_vkEnumerateInstanceExtensionProperties)GetProcAddress(scast<HMODULE>(hinstance_dll), "vkEnumerateInstanceExtensionProperties");
    #endif
        //---
        // Check Vulkan instance extension properties.
        VkResult vk_err_result = {};
        VkExtensionProperties* vk_ext_prop = nullptr;
        uint vk_ext_count = 0;

        // Get available Vulkan instance extensions.
        // Get vk_ext_count.
        vk_err_result = vkEnumerateInstanceExtensionProperties(nullptr, &vk_ext_count, nullptr);
        if (vk_err_result) {
            // This happens on systems with a loader but without any Vulkan ICD
            printfln("Vulkan: Failed to query instance extension count: %s", get_vulkan_result_string(vk_err_result));
            return false;
        }
        
        // Allocate vk_ext_prop array equal to size of vk_ext_count.
        vk_ext_prop = sdf::ty_malloc<VkExtensionProperties>(vk_ext_count);
        vk_err_result = vkEnumerateInstanceExtensionProperties(nullptr, &vk_ext_count, vk_ext_prop);
        if (vk_err_result) {
            printfln("Vulkan: Failed to query instance extensions: %s", get_vulkan_result_string(vk_err_result));
            free(vk_ext_prop);
            return false;
        }

        // Check if VK_KHR_surface, VK_KHR_win32_surface extensions are avialable.
        for (uint i = 0;  i < vk_ext_count;  i++) {
            if (sdf::strfz_equals(vk_ext_prop[i].extensionName, VK_KHR_SURFACE_EXTENSION_NAME)) {
                is_vk_KHR_surface = true;
            } else if (sdf::strfz_equals(vk_ext_prop[i].extensionName, VK_KHR_WIN32_SURFACE_EXTENSION_NAME)) {
                is_vk_KHR_win32_surface = true;
            }
        }
        sdf::ty_free(vk_ext_prop);


        // Fill extensions array.
        if (!is_vk_KHR_surface || !is_vk_KHR_win32_surface) {
            eprintfln("VK_KHR_SURFACE_EXTENSION_NAME, VK_KHR_WIN32_SURFACE_EXTENSION_NAME not found");
            return false;
        } else { 
            extensions[0] = VK_KHR_SURFACE_EXTENSION_NAME;
            extensions[1] = VK_KHR_WIN32_SURFACE_EXTENSION_NAME;
        }

        return true;
    }

    void deinit() {        
        if (hinstance_dll) {
            FreeLibrary(hinstance_dll);
        }
    }

    bool is_vk_extensions_empty() {
        return (!extensions[0]);
    }

	const char** get_required_instance_extensions(uint& count) {
		count = 0;
		if (is_vk_extensions_empty()) {
            eprintfln("Vulkan: Window surface creation extensions not found");
			return nullptr;
		}
		count = extensions_count;
		return (const char**) extensions;
	}


    bool get_physical_device_presentation_support(VkPhysicalDevice device, uint32_t queuefamily) {
        fm_assert(device != VK_NULL_HANDLE);    

        if (is_vk_extensions_empty()) {
            eprintfln("Vulkan: Window surface creation extensions not found");
            return false;
        }


        //PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vkGetPhysicalDeviceWin32PresentationSupportKHR = nullptr;
        //LOAD_VULKAN_FUNCTION(vkGetPhysicalDeviceWin32PresentationSupportKHR);
        
        if (!vkGetPhysicalDeviceWin32PresentationSupportKHR) {
            eprintfln("Win32: Vulkan instance missing VK_KHR_WIN32_SURFACE_EXTENSION_NAME extension");
            return false;
        }

        return vkGetPhysicalDeviceWin32PresentationSupportKHR(device, queuefamily);
    }

    void destroy_window_surface(VkInstance vk_instance, VkSurfaceKHR surface, const VkAllocationCallbacks* allocator) {
        //PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR = nullptr;
       // LOAD_VULKAN_FUNCTION(vkDestroySurfaceKHR); 

        vkDestroySurfaceKHR(vk_instance, surface, allocator);
    }


    VkResult create_window_surface(VkInstance vk_instance, HINSTANCE main_hinstance, HWND hwnd, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface) {
        fm_assert(surface != nullptr);

        *surface = VK_NULL_HANDLE;

        if (!hwnd) {
            eprintfln("Handle to window is NULL.");
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        if (is_vk_extensions_empty()) {
            eprintfln("Vulkan: Window surface creation extensions not found");
            return VK_ERROR_EXTENSION_NOT_PRESENT;
        }


        VkResult vk_err_result;
        
        //PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR = nullptr;
        //LOAD_VULKAN_FUNCTION(vkCreateWin32SurfaceKHR);

        if (!vkCreateWin32SurfaceKHR) {
            eprintfln("Win32: Vulkan instance missing VK_KHR_WIN32_SURFACE_EXTENSION_NAME extension");
            return VK_ERROR_EXTENSION_NOT_PRESENT;
        }

        VkWin32SurfaceCreateInfoKHR sci = {};
        sci.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
        sci.hinstance = main_hinstance;
        sci.hwnd = hwnd;

        vk_err_result = vkCreateWin32SurfaceKHR(vk_instance, &sci, allocator, surface);
        if (vk_err_result) {
            eprintfln("Win32: Failed to create Vulkan surface: %s", get_vulkan_result_string(vk_err_result));
        }

        return vk_err_result;
    }    


    void get_window_framebuffer_size(HWND hwnd, int& width, int& height) {
        width = 0;
        height = 0;

        RECT area;
        GetClientRect(hwnd, &area);
        width = area.right;
        height = area.bottom;
    }
};

extern vkwin32fn_lib vkwin32fn;


