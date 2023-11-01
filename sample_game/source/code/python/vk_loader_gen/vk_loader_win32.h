#pragma once

#define VK_NO_PROTOTYPES
#include <vulkan/vulkan_core.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <vulkan/vulkan_win32.h>

typedef void (*PFN_apiproc)(void);
typedef PFN_apiproc (*PFN_loadfunc_vk)(VkInstance vk_instance, const char* name);

//#define VK_LOADER_WIN32_PRINT_ERRORS


// VKAPI_ATTR VkResult VKAPI_CALL vkCreateWin32SurfaceKHR(
//     VkInstance                                  instance,
//     const VkWin32SurfaceCreateInfoKHR*          pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkSurfaceKHR*                               pSurface);
extern PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR;
// VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceWin32PresentationSupportKHR(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t                                    queueFamilyIndex);
extern PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR vkGetPhysicalDeviceWin32PresentationSupportKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandleKHR(
//     VkDevice                                    device,
//     const VkMemoryGetWin32HandleInfoKHR*        pGetWin32HandleInfo,
//     HANDLE*                                     pHandle);
extern PFN_vkGetMemoryWin32HandleKHR vkGetMemoryWin32HandleKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandlePropertiesKHR(
//     VkDevice                                    device,
//     VkExternalMemoryHandleTypeFlagBits          handleType,
//     HANDLE                                      handle,
//     VkMemoryWin32HandlePropertiesKHR*           pMemoryWin32HandleProperties);
extern PFN_vkGetMemoryWin32HandlePropertiesKHR vkGetMemoryWin32HandlePropertiesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreWin32HandleKHR(
//     VkDevice                                    device,
//     const VkImportSemaphoreWin32HandleInfoKHR*  pImportSemaphoreWin32HandleInfo);
extern PFN_vkImportSemaphoreWin32HandleKHR vkImportSemaphoreWin32HandleKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreWin32HandleKHR(
//     VkDevice                                    device,
//     const VkSemaphoreGetWin32HandleInfoKHR*     pGetWin32HandleInfo,
//     HANDLE*                                     pHandle);
extern PFN_vkGetSemaphoreWin32HandleKHR vkGetSemaphoreWin32HandleKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkImportFenceWin32HandleKHR(
//     VkDevice                                    device,
//     const VkImportFenceWin32HandleInfoKHR*      pImportFenceWin32HandleInfo);
extern PFN_vkImportFenceWin32HandleKHR vkImportFenceWin32HandleKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceWin32HandleKHR(
//     VkDevice                                    device,
//     const VkFenceGetWin32HandleInfoKHR*         pGetWin32HandleInfo,
//     HANDLE*                                     pHandle);
extern PFN_vkGetFenceWin32HandleKHR vkGetFenceWin32HandleKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandleNV(
//     VkDevice                                    device,
//     VkDeviceMemory                              memory,
//     VkExternalMemoryHandleTypeFlagsNV           handleType,
//     HANDLE*                                     pHandle);
extern PFN_vkGetMemoryWin32HandleNV vkGetMemoryWin32HandleNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfacePresentModes2EXT(
//     VkPhysicalDevice                            physicalDevice,
//     const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
//     uint32_t*                                   pPresentModeCount,
//     VkPresentModeKHR*                           pPresentModes);
extern PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT vkGetPhysicalDeviceSurfacePresentModes2EXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkAcquireFullScreenExclusiveModeEXT(
//     VkDevice                                    device,
//     VkSwapchainKHR                              swapchain);
extern PFN_vkAcquireFullScreenExclusiveModeEXT vkAcquireFullScreenExclusiveModeEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkReleaseFullScreenExclusiveModeEXT(
//     VkDevice                                    device,
//     VkSwapchainKHR                              swapchain);
extern PFN_vkReleaseFullScreenExclusiveModeEXT vkReleaseFullScreenExclusiveModeEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupSurfacePresentModes2EXT(
//     VkDevice                                    device,
//     const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
//     VkDeviceGroupPresentModeFlagsKHR*           pModes);
extern PFN_vkGetDeviceGroupSurfacePresentModes2EXT vkGetDeviceGroupSurfacePresentModes2EXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkAcquireWinrtDisplayNV(
//     VkPhysicalDevice                            physicalDevice,
//     VkDisplayKHR                                display);
extern PFN_vkAcquireWinrtDisplayNV vkAcquireWinrtDisplayNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetWinrtDisplayNV(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t                                    deviceRelativeId,
//     VkDisplayKHR*                               pDisplay);
extern PFN_vkGetWinrtDisplayNV vkGetWinrtDisplayNV;


// Loader Function
void vkfnlib_load_vkwin32(PFN_loadfunc_vk load, VkInstance vk_instance);
