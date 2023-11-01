#include "vk_loader_win32.h"

#include <stdio.h>
#if defined VK_LOADER_WIN32_PRINT_ERRORS
#define print_msg(format, ...)		printf(format "\n", __VA_ARGS__)
#else
#define print_msg
#endif


PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR = nullptr;
PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vkGetPhysicalDeviceWin32PresentationSupportKHR = nullptr;
PFN_vkGetMemoryWin32HandleKHR vkGetMemoryWin32HandleKHR = nullptr;
PFN_vkGetMemoryWin32HandlePropertiesKHR vkGetMemoryWin32HandlePropertiesKHR = nullptr;
PFN_vkImportSemaphoreWin32HandleKHR vkImportSemaphoreWin32HandleKHR = nullptr;
PFN_vkGetSemaphoreWin32HandleKHR vkGetSemaphoreWin32HandleKHR = nullptr;
PFN_vkImportFenceWin32HandleKHR vkImportFenceWin32HandleKHR = nullptr;
PFN_vkGetFenceWin32HandleKHR vkGetFenceWin32HandleKHR = nullptr;
PFN_vkGetMemoryWin32HandleNV vkGetMemoryWin32HandleNV = nullptr;
PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT vkGetPhysicalDeviceSurfacePresentModes2EXT = nullptr;
PFN_vkAcquireFullScreenExclusiveModeEXT vkAcquireFullScreenExclusiveModeEXT = nullptr;
PFN_vkReleaseFullScreenExclusiveModeEXT vkReleaseFullScreenExclusiveModeEXT = nullptr;
PFN_vkGetDeviceGroupSurfacePresentModes2EXT vkGetDeviceGroupSurfacePresentModes2EXT = nullptr;
PFN_vkAcquireWinrtDisplayNV vkAcquireWinrtDisplayNV = nullptr;
PFN_vkGetWinrtDisplayNV vkGetWinrtDisplayNV = nullptr;

void vkfnlib_init_vkwin32(PFN_loadfunc_vk load, VkInstance vk_instance) {
	vkCreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR)load(vk_instance, "vkCreateWin32SurfaceKHR");
	if (!vkCreateWin32SurfaceKHR) { print_msg("vkCreateWin32SurfaceKHR not loaded"); }
	vkGetPhysicalDeviceWin32PresentationSupportKHR = (PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR)load(vk_instance, "vkGetPhysicalDeviceWin32PresentationSupportKHR");
	if (!vkGetPhysicalDeviceWin32PresentationSupportKHR) { print_msg("vkGetPhysicalDeviceWin32PresentationSupportKHR not loaded"); }
	vkGetMemoryWin32HandleKHR = (PFN_vkGetMemoryWin32HandleKHR)load(vk_instance, "vkGetMemoryWin32HandleKHR");
	if (!vkGetMemoryWin32HandleKHR) { print_msg("vkGetMemoryWin32HandleKHR not loaded"); }
	vkGetMemoryWin32HandlePropertiesKHR = (PFN_vkGetMemoryWin32HandlePropertiesKHR)load(vk_instance, "vkGetMemoryWin32HandlePropertiesKHR");
	if (!vkGetMemoryWin32HandlePropertiesKHR) { print_msg("vkGetMemoryWin32HandlePropertiesKHR not loaded"); }
	vkImportSemaphoreWin32HandleKHR = (PFN_vkImportSemaphoreWin32HandleKHR)load(vk_instance, "vkImportSemaphoreWin32HandleKHR");
	if (!vkImportSemaphoreWin32HandleKHR) { print_msg("vkImportSemaphoreWin32HandleKHR not loaded"); }
	vkGetSemaphoreWin32HandleKHR = (PFN_vkGetSemaphoreWin32HandleKHR)load(vk_instance, "vkGetSemaphoreWin32HandleKHR");
	if (!vkGetSemaphoreWin32HandleKHR) { print_msg("vkGetSemaphoreWin32HandleKHR not loaded"); }
	vkImportFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR)load(vk_instance, "vkImportFenceWin32HandleKHR");
	if (!vkImportFenceWin32HandleKHR) { print_msg("vkImportFenceWin32HandleKHR not loaded"); }
	vkGetFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR)load(vk_instance, "vkGetFenceWin32HandleKHR");
	if (!vkGetFenceWin32HandleKHR) { print_msg("vkGetFenceWin32HandleKHR not loaded"); }
	vkGetMemoryWin32HandleNV = (PFN_vkGetMemoryWin32HandleNV)load(vk_instance, "vkGetMemoryWin32HandleNV");
	if (!vkGetMemoryWin32HandleNV) { print_msg("vkGetMemoryWin32HandleNV not loaded"); }
	vkGetPhysicalDeviceSurfacePresentModes2EXT = (PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT)load(vk_instance, "vkGetPhysicalDeviceSurfacePresentModes2EXT");
	if (!vkGetPhysicalDeviceSurfacePresentModes2EXT) { print_msg("vkGetPhysicalDeviceSurfacePresentModes2EXT not loaded"); }
	vkAcquireFullScreenExclusiveModeEXT = (PFN_vkAcquireFullScreenExclusiveModeEXT)load(vk_instance, "vkAcquireFullScreenExclusiveModeEXT");
	if (!vkAcquireFullScreenExclusiveModeEXT) { print_msg("vkAcquireFullScreenExclusiveModeEXT not loaded"); }
	vkReleaseFullScreenExclusiveModeEXT = (PFN_vkReleaseFullScreenExclusiveModeEXT)load(vk_instance, "vkReleaseFullScreenExclusiveModeEXT");
	if (!vkReleaseFullScreenExclusiveModeEXT) { print_msg("vkReleaseFullScreenExclusiveModeEXT not loaded"); }
	vkGetDeviceGroupSurfacePresentModes2EXT = (PFN_vkGetDeviceGroupSurfacePresentModes2EXT)load(vk_instance, "vkGetDeviceGroupSurfacePresentModes2EXT");
	if (!vkGetDeviceGroupSurfacePresentModes2EXT) { print_msg("vkGetDeviceGroupSurfacePresentModes2EXT not loaded"); }
	vkAcquireWinrtDisplayNV = (PFN_vkAcquireWinrtDisplayNV)load(vk_instance, "vkAcquireWinrtDisplayNV");
	if (!vkAcquireWinrtDisplayNV) { print_msg("vkAcquireWinrtDisplayNV not loaded"); }
	vkGetWinrtDisplayNV = (PFN_vkGetWinrtDisplayNV)load(vk_instance, "vkGetWinrtDisplayNV");
	if (!vkGetWinrtDisplayNV) { print_msg("vkGetWinrtDisplayNV not loaded"); }
}


void vkfnlib_load_vkwin32(PFN_loadfunc_vk load, VkInstance vk_instance) {
	vkfnlib_init_vkwin32(load, vk_instance);
}
