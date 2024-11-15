#pragma once

#define VK_NO_PROTOTYPES
#include <vulkan/vulkan_core.h>

typedef void (*PFN_apiproc)(void);
typedef PFN_apiproc (*PFN_loadfunc_vk)(VkInstance vk_instance, const char* name);

//#define VK_LOADER_CORE_PRINT_ERRORS


// VK_VERSION_1_0
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(
//     const VkInstanceCreateInfo*                 pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkInstance*                                 pInstance);
extern PFN_vkCreateInstance vkCreateInstance;
// VKAPI_ATTR void VKAPI_CALL vkDestroyInstance(
//     VkInstance                                  instance,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyInstance vkDestroyInstance;
// VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDevices(
//     VkInstance                                  instance,
//     uint32_t*                                   pPhysicalDeviceCount,
//     VkPhysicalDevice*                           pPhysicalDevices);
extern PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures(
//     VkPhysicalDevice                            physicalDevice,
//     VkPhysicalDeviceFeatures*                   pFeatures);
extern PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties(
//     VkPhysicalDevice                            physicalDevice,
//     VkFormat                                    format,
//     VkFormatProperties*                         pFormatProperties);
extern PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties(
//     VkPhysicalDevice                            physicalDevice,
//     VkFormat                                    format,
//     VkImageType                                 type,
//     VkImageTiling                               tiling,
//     VkImageUsageFlags                           usage,
//     VkImageCreateFlags                          flags,
//     VkImageFormatProperties*                    pImageFormatProperties);
extern PFN_vkGetPhysicalDeviceImageFormatProperties vkGetPhysicalDeviceImageFormatProperties;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties(
//     VkPhysicalDevice                            physicalDevice,
//     VkPhysicalDeviceProperties*                 pProperties);
extern PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pQueueFamilyPropertyCount,
//     VkQueueFamilyProperties*                    pQueueFamilyProperties);
extern PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties(
//     VkPhysicalDevice                            physicalDevice,
//     VkPhysicalDeviceMemoryProperties*           pMemoryProperties);
extern PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
// VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(
//     VkInstance                                  instance,
//     const char*                                 pName);
extern PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
// VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetDeviceProcAddr(
//     VkDevice                                    device,
//     const char*                                 pName);
extern PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateDevice(
//     VkPhysicalDevice                            physicalDevice,
//     const VkDeviceCreateInfo*                   pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkDevice*                                   pDevice);
extern PFN_vkCreateDevice vkCreateDevice;
// VKAPI_ATTR void VKAPI_CALL vkDestroyDevice(
//     VkDevice                                    device,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyDevice vkDestroyDevice;
// VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(
//     const char*                                 pLayerName,
//     uint32_t*                                   pPropertyCount,
//     VkExtensionProperties*                      pProperties);
extern PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties;
// VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceExtensionProperties(
//     VkPhysicalDevice                            physicalDevice,
//     const char*                                 pLayerName,
//     uint32_t*                                   pPropertyCount,
//     VkExtensionProperties*                      pProperties);
extern PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties;
// VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(
//     uint32_t*                                   pPropertyCount,
//     VkLayerProperties*                          pProperties);
extern PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties;
// VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceLayerProperties(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pPropertyCount,
//     VkLayerProperties*                          pProperties);
extern PFN_vkEnumerateDeviceLayerProperties vkEnumerateDeviceLayerProperties;
// VKAPI_ATTR void VKAPI_CALL vkGetDeviceQueue(
//     VkDevice                                    device,
//     uint32_t                                    queueFamilyIndex,
//     uint32_t                                    queueIndex,
//     VkQueue*                                    pQueue);
extern PFN_vkGetDeviceQueue vkGetDeviceQueue;
// VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit(
//     VkQueue                                     queue,
//     uint32_t                                    submitCount,
//     const VkSubmitInfo*                         pSubmits,
//     VkFence                                     fence);
extern PFN_vkQueueSubmit vkQueueSubmit;
// VKAPI_ATTR VkResult VKAPI_CALL vkQueueWaitIdle(
//     VkQueue                                     queue);
extern PFN_vkQueueWaitIdle vkQueueWaitIdle;
// VKAPI_ATTR VkResult VKAPI_CALL vkDeviceWaitIdle(
//     VkDevice                                    device);
extern PFN_vkDeviceWaitIdle vkDeviceWaitIdle;
// VKAPI_ATTR VkResult VKAPI_CALL vkAllocateMemory(
//     VkDevice                                    device,
//     const VkMemoryAllocateInfo*                 pAllocateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkDeviceMemory*                             pMemory);
extern PFN_vkAllocateMemory vkAllocateMemory;
// VKAPI_ATTR void VKAPI_CALL vkFreeMemory(
//     VkDevice                                    device,
//     VkDeviceMemory                              memory,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkFreeMemory vkFreeMemory;
// VKAPI_ATTR VkResult VKAPI_CALL vkMapMemory(
//     VkDevice                                    device,
//     VkDeviceMemory                              memory,
//     VkDeviceSize                                offset,
//     VkDeviceSize                                size,
//     VkMemoryMapFlags                            flags,
//     void**                                      ppData);
extern PFN_vkMapMemory vkMapMemory;
// VKAPI_ATTR void VKAPI_CALL vkUnmapMemory(
//     VkDevice                                    device,
//     VkDeviceMemory                              memory);
extern PFN_vkUnmapMemory vkUnmapMemory;
// VKAPI_ATTR VkResult VKAPI_CALL vkFlushMappedMemoryRanges(
//     VkDevice                                    device,
//     uint32_t                                    memoryRangeCount,
//     const VkMappedMemoryRange*                  pMemoryRanges);
extern PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges;
// VKAPI_ATTR VkResult VKAPI_CALL vkInvalidateMappedMemoryRanges(
//     VkDevice                                    device,
//     uint32_t                                    memoryRangeCount,
//     const VkMappedMemoryRange*                  pMemoryRanges);
extern PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges;
// VKAPI_ATTR void VKAPI_CALL vkGetDeviceMemoryCommitment(
//     VkDevice                                    device,
//     VkDeviceMemory                              memory,
//     VkDeviceSize*                               pCommittedMemoryInBytes);
extern PFN_vkGetDeviceMemoryCommitment vkGetDeviceMemoryCommitment;
// VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory(
//     VkDevice                                    device,
//     VkBuffer                                    buffer,
//     VkDeviceMemory                              memory,
//     VkDeviceSize                                memoryOffset);
extern PFN_vkBindBufferMemory vkBindBufferMemory;
// VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory(
//     VkDevice                                    device,
//     VkImage                                     image,
//     VkDeviceMemory                              memory,
//     VkDeviceSize                                memoryOffset);
extern PFN_vkBindImageMemory vkBindImageMemory;
// VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements(
//     VkDevice                                    device,
//     VkBuffer                                    buffer,
//     VkMemoryRequirements*                       pMemoryRequirements);
extern PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements;
// VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements(
//     VkDevice                                    device,
//     VkImage                                     image,
//     VkMemoryRequirements*                       pMemoryRequirements);
extern PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements;
// VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements(
//     VkDevice                                    device,
//     VkImage                                     image,
//     uint32_t*                                   pSparseMemoryRequirementCount,
//     VkSparseImageMemoryRequirements*            pSparseMemoryRequirements);
extern PFN_vkGetImageSparseMemoryRequirements vkGetImageSparseMemoryRequirements;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties(
//     VkPhysicalDevice                            physicalDevice,
//     VkFormat                                    format,
//     VkImageType                                 type,
//     VkSampleCountFlagBits                       samples,
//     VkImageUsageFlags                           usage,
//     VkImageTiling                               tiling,
//     uint32_t*                                   pPropertyCount,
//     VkSparseImageFormatProperties*              pProperties);
extern PFN_vkGetPhysicalDeviceSparseImageFormatProperties vkGetPhysicalDeviceSparseImageFormatProperties;
// VKAPI_ATTR VkResult VKAPI_CALL vkQueueBindSparse(
//     VkQueue                                     queue,
//     uint32_t                                    bindInfoCount,
//     const VkBindSparseInfo*                     pBindInfo,
//     VkFence                                     fence);
extern PFN_vkQueueBindSparse vkQueueBindSparse;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateFence(
//     VkDevice                                    device,
//     const VkFenceCreateInfo*                    pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkFence*                                    pFence);
extern PFN_vkCreateFence vkCreateFence;
// VKAPI_ATTR void VKAPI_CALL vkDestroyFence(
//     VkDevice                                    device,
//     VkFence                                     fence,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyFence vkDestroyFence;
// VKAPI_ATTR VkResult VKAPI_CALL vkResetFences(
//     VkDevice                                    device,
//     uint32_t                                    fenceCount,
//     const VkFence*                              pFences);
extern PFN_vkResetFences vkResetFences;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceStatus(
//     VkDevice                                    device,
//     VkFence                                     fence);
extern PFN_vkGetFenceStatus vkGetFenceStatus;
// VKAPI_ATTR VkResult VKAPI_CALL vkWaitForFences(
//     VkDevice                                    device,
//     uint32_t                                    fenceCount,
//     const VkFence*                              pFences,
//     VkBool32                                    waitAll,
//     uint64_t                                    timeout);
extern PFN_vkWaitForFences vkWaitForFences;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateSemaphore(
//     VkDevice                                    device,
//     const VkSemaphoreCreateInfo*                pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkSemaphore*                                pSemaphore);
extern PFN_vkCreateSemaphore vkCreateSemaphore;
// VKAPI_ATTR void VKAPI_CALL vkDestroySemaphore(
//     VkDevice                                    device,
//     VkSemaphore                                 semaphore,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroySemaphore vkDestroySemaphore;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateEvent(
//     VkDevice                                    device,
//     const VkEventCreateInfo*                    pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkEvent*                                    pEvent);
extern PFN_vkCreateEvent vkCreateEvent;
// VKAPI_ATTR void VKAPI_CALL vkDestroyEvent(
//     VkDevice                                    device,
//     VkEvent                                     event,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyEvent vkDestroyEvent;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetEventStatus(
//     VkDevice                                    device,
//     VkEvent                                     event);
extern PFN_vkGetEventStatus vkGetEventStatus;
// VKAPI_ATTR VkResult VKAPI_CALL vkSetEvent(
//     VkDevice                                    device,
//     VkEvent                                     event);
extern PFN_vkSetEvent vkSetEvent;
// VKAPI_ATTR VkResult VKAPI_CALL vkResetEvent(
//     VkDevice                                    device,
//     VkEvent                                     event);
extern PFN_vkResetEvent vkResetEvent;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateQueryPool(
//     VkDevice                                    device,
//     const VkQueryPoolCreateInfo*                pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkQueryPool*                                pQueryPool);
extern PFN_vkCreateQueryPool vkCreateQueryPool;
// VKAPI_ATTR void VKAPI_CALL vkDestroyQueryPool(
//     VkDevice                                    device,
//     VkQueryPool                                 queryPool,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyQueryPool vkDestroyQueryPool;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetQueryPoolResults(
//     VkDevice                                    device,
//     VkQueryPool                                 queryPool,
//     uint32_t                                    firstQuery,
//     uint32_t                                    queryCount,
//     size_t                                      dataSize,
//     void*                                       pData,
//     VkDeviceSize                                stride,
//     VkQueryResultFlags                          flags);
extern PFN_vkGetQueryPoolResults vkGetQueryPoolResults;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateBuffer(
//     VkDevice                                    device,
//     const VkBufferCreateInfo*                   pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkBuffer*                                   pBuffer);
extern PFN_vkCreateBuffer vkCreateBuffer;
// VKAPI_ATTR void VKAPI_CALL vkDestroyBuffer(
//     VkDevice                                    device,
//     VkBuffer                                    buffer,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyBuffer vkDestroyBuffer;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateBufferView(
//     VkDevice                                    device,
//     const VkBufferViewCreateInfo*               pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkBufferView*                               pView);
extern PFN_vkCreateBufferView vkCreateBufferView;
// VKAPI_ATTR void VKAPI_CALL vkDestroyBufferView(
//     VkDevice                                    device,
//     VkBufferView                                bufferView,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyBufferView vkDestroyBufferView;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateImage(
//     VkDevice                                    device,
//     const VkImageCreateInfo*                    pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkImage*                                    pImage);
extern PFN_vkCreateImage vkCreateImage;
// VKAPI_ATTR void VKAPI_CALL vkDestroyImage(
//     VkDevice                                    device,
//     VkImage                                     image,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyImage vkDestroyImage;
// VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout(
//     VkDevice                                    device,
//     VkImage                                     image,
//     const VkImageSubresource*                   pSubresource,
//     VkSubresourceLayout*                        pLayout);
extern PFN_vkGetImageSubresourceLayout vkGetImageSubresourceLayout;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateImageView(
//     VkDevice                                    device,
//     const VkImageViewCreateInfo*                pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkImageView*                                pView);
extern PFN_vkCreateImageView vkCreateImageView;
// VKAPI_ATTR void VKAPI_CALL vkDestroyImageView(
//     VkDevice                                    device,
//     VkImageView                                 imageView,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyImageView vkDestroyImageView;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateShaderModule(
//     VkDevice                                    device,
//     const VkShaderModuleCreateInfo*             pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkShaderModule*                             pShaderModule);
extern PFN_vkCreateShaderModule vkCreateShaderModule;
// VKAPI_ATTR void VKAPI_CALL vkDestroyShaderModule(
//     VkDevice                                    device,
//     VkShaderModule                              shaderModule,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyShaderModule vkDestroyShaderModule;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreatePipelineCache(
//     VkDevice                                    device,
//     const VkPipelineCacheCreateInfo*            pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkPipelineCache*                            pPipelineCache);
extern PFN_vkCreatePipelineCache vkCreatePipelineCache;
// VKAPI_ATTR void VKAPI_CALL vkDestroyPipelineCache(
//     VkDevice                                    device,
//     VkPipelineCache                             pipelineCache,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyPipelineCache vkDestroyPipelineCache;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineCacheData(
//     VkDevice                                    device,
//     VkPipelineCache                             pipelineCache,
//     size_t*                                     pDataSize,
//     void*                                       pData);
extern PFN_vkGetPipelineCacheData vkGetPipelineCacheData;
// VKAPI_ATTR VkResult VKAPI_CALL vkMergePipelineCaches(
//     VkDevice                                    device,
//     VkPipelineCache                             dstCache,
//     uint32_t                                    srcCacheCount,
//     const VkPipelineCache*                      pSrcCaches);
extern PFN_vkMergePipelineCaches vkMergePipelineCaches;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateGraphicsPipelines(
//     VkDevice                                    device,
//     VkPipelineCache                             pipelineCache,
//     uint32_t                                    createInfoCount,
//     const VkGraphicsPipelineCreateInfo*         pCreateInfos,
//     const VkAllocationCallbacks*                pAllocator,
//     VkPipeline*                                 pPipelines);
extern PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateComputePipelines(
//     VkDevice                                    device,
//     VkPipelineCache                             pipelineCache,
//     uint32_t                                    createInfoCount,
//     const VkComputePipelineCreateInfo*          pCreateInfos,
//     const VkAllocationCallbacks*                pAllocator,
//     VkPipeline*                                 pPipelines);
extern PFN_vkCreateComputePipelines vkCreateComputePipelines;
// VKAPI_ATTR void VKAPI_CALL vkDestroyPipeline(
//     VkDevice                                    device,
//     VkPipeline                                  pipeline,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyPipeline vkDestroyPipeline;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreatePipelineLayout(
//     VkDevice                                    device,
//     const VkPipelineLayoutCreateInfo*           pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkPipelineLayout*                           pPipelineLayout);
extern PFN_vkCreatePipelineLayout vkCreatePipelineLayout;
// VKAPI_ATTR void VKAPI_CALL vkDestroyPipelineLayout(
//     VkDevice                                    device,
//     VkPipelineLayout                            pipelineLayout,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyPipelineLayout vkDestroyPipelineLayout;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateSampler(
//     VkDevice                                    device,
//     const VkSamplerCreateInfo*                  pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkSampler*                                  pSampler);
extern PFN_vkCreateSampler vkCreateSampler;
// VKAPI_ATTR void VKAPI_CALL vkDestroySampler(
//     VkDevice                                    device,
//     VkSampler                                   sampler,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroySampler vkDestroySampler;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorSetLayout(
//     VkDevice                                    device,
//     const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkDescriptorSetLayout*                      pSetLayout);
extern PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout;
// VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorSetLayout(
//     VkDevice                                    device,
//     VkDescriptorSetLayout                       descriptorSetLayout,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyDescriptorSetLayout vkDestroyDescriptorSetLayout;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorPool(
//     VkDevice                                    device,
//     const VkDescriptorPoolCreateInfo*           pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkDescriptorPool*                           pDescriptorPool);
extern PFN_vkCreateDescriptorPool vkCreateDescriptorPool;
// VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorPool(
//     VkDevice                                    device,
//     VkDescriptorPool                            descriptorPool,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyDescriptorPool vkDestroyDescriptorPool;
// VKAPI_ATTR VkResult VKAPI_CALL vkResetDescriptorPool(
//     VkDevice                                    device,
//     VkDescriptorPool                            descriptorPool,
//     VkDescriptorPoolResetFlags                  flags);
extern PFN_vkResetDescriptorPool vkResetDescriptorPool;
// VKAPI_ATTR VkResult VKAPI_CALL vkAllocateDescriptorSets(
//     VkDevice                                    device,
//     const VkDescriptorSetAllocateInfo*          pAllocateInfo,
//     VkDescriptorSet*                            pDescriptorSets);
extern PFN_vkAllocateDescriptorSets vkAllocateDescriptorSets;
// VKAPI_ATTR VkResult VKAPI_CALL vkFreeDescriptorSets(
//     VkDevice                                    device,
//     VkDescriptorPool                            descriptorPool,
//     uint32_t                                    descriptorSetCount,
//     const VkDescriptorSet*                      pDescriptorSets);
extern PFN_vkFreeDescriptorSets vkFreeDescriptorSets;
// VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSets(
//     VkDevice                                    device,
//     uint32_t                                    descriptorWriteCount,
//     const VkWriteDescriptorSet*                 pDescriptorWrites,
//     uint32_t                                    descriptorCopyCount,
//     const VkCopyDescriptorSet*                  pDescriptorCopies);
extern PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateFramebuffer(
//     VkDevice                                    device,
//     const VkFramebufferCreateInfo*              pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkFramebuffer*                              pFramebuffer);
extern PFN_vkCreateFramebuffer vkCreateFramebuffer;
// VKAPI_ATTR void VKAPI_CALL vkDestroyFramebuffer(
//     VkDevice                                    device,
//     VkFramebuffer                               framebuffer,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyFramebuffer vkDestroyFramebuffer;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateRenderPass(
//     VkDevice                                    device,
//     const VkRenderPassCreateInfo*               pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkRenderPass*                               pRenderPass);
extern PFN_vkCreateRenderPass vkCreateRenderPass;
// VKAPI_ATTR void VKAPI_CALL vkDestroyRenderPass(
//     VkDevice                                    device,
//     VkRenderPass                                renderPass,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyRenderPass vkDestroyRenderPass;
// VKAPI_ATTR void VKAPI_CALL vkGetRenderAreaGranularity(
//     VkDevice                                    device,
//     VkRenderPass                                renderPass,
//     VkExtent2D*                                 pGranularity);
extern PFN_vkGetRenderAreaGranularity vkGetRenderAreaGranularity;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateCommandPool(
//     VkDevice                                    device,
//     const VkCommandPoolCreateInfo*              pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkCommandPool*                              pCommandPool);
extern PFN_vkCreateCommandPool vkCreateCommandPool;
// VKAPI_ATTR void VKAPI_CALL vkDestroyCommandPool(
//     VkDevice                                    device,
//     VkCommandPool                               commandPool,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyCommandPool vkDestroyCommandPool;
// VKAPI_ATTR VkResult VKAPI_CALL vkResetCommandPool(
//     VkDevice                                    device,
//     VkCommandPool                               commandPool,
//     VkCommandPoolResetFlags                     flags);
extern PFN_vkResetCommandPool vkResetCommandPool;
// VKAPI_ATTR VkResult VKAPI_CALL vkAllocateCommandBuffers(
//     VkDevice                                    device,
//     const VkCommandBufferAllocateInfo*          pAllocateInfo,
//     VkCommandBuffer*                            pCommandBuffers);
extern PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers;
// VKAPI_ATTR void VKAPI_CALL vkFreeCommandBuffers(
//     VkDevice                                    device,
//     VkCommandPool                               commandPool,
//     uint32_t                                    commandBufferCount,
//     const VkCommandBuffer*                      pCommandBuffers);
extern PFN_vkFreeCommandBuffers vkFreeCommandBuffers;
// VKAPI_ATTR VkResult VKAPI_CALL vkBeginCommandBuffer(
//     VkCommandBuffer                             commandBuffer,
//     const VkCommandBufferBeginInfo*             pBeginInfo);
extern PFN_vkBeginCommandBuffer vkBeginCommandBuffer;
// VKAPI_ATTR VkResult VKAPI_CALL vkEndCommandBuffer(
//     VkCommandBuffer                             commandBuffer);
extern PFN_vkEndCommandBuffer vkEndCommandBuffer;
// VKAPI_ATTR VkResult VKAPI_CALL vkResetCommandBuffer(
//     VkCommandBuffer                             commandBuffer,
//     VkCommandBufferResetFlags                   flags);
extern PFN_vkResetCommandBuffer vkResetCommandBuffer;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindPipeline(
//     VkCommandBuffer                             commandBuffer,
//     VkPipelineBindPoint                         pipelineBindPoint,
//     VkPipeline                                  pipeline);
extern PFN_vkCmdBindPipeline vkCmdBindPipeline;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetViewport(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstViewport,
//     uint32_t                                    viewportCount,
//     const VkViewport*                           pViewports);
extern PFN_vkCmdSetViewport vkCmdSetViewport;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetScissor(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstScissor,
//     uint32_t                                    scissorCount,
//     const VkRect2D*                             pScissors);
extern PFN_vkCmdSetScissor vkCmdSetScissor;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetLineWidth(
//     VkCommandBuffer                             commandBuffer,
//     float                                       lineWidth);
extern PFN_vkCmdSetLineWidth vkCmdSetLineWidth;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBias(
//     VkCommandBuffer                             commandBuffer,
//     float                                       depthBiasConstantFactor,
//     float                                       depthBiasClamp,
//     float                                       depthBiasSlopeFactor);
extern PFN_vkCmdSetDepthBias vkCmdSetDepthBias;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetBlendConstants(
//     VkCommandBuffer                             commandBuffer,
//     const float                                 blendConstants[4]);
extern PFN_vkCmdSetBlendConstants vkCmdSetBlendConstants;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBounds(
//     VkCommandBuffer                             commandBuffer,
//     float                                       minDepthBounds,
//     float                                       maxDepthBounds);
extern PFN_vkCmdSetDepthBounds vkCmdSetDepthBounds;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilCompareMask(
//     VkCommandBuffer                             commandBuffer,
//     VkStencilFaceFlags                          faceMask,
//     uint32_t                                    compareMask);
extern PFN_vkCmdSetStencilCompareMask vkCmdSetStencilCompareMask;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilWriteMask(
//     VkCommandBuffer                             commandBuffer,
//     VkStencilFaceFlags                          faceMask,
//     uint32_t                                    writeMask);
extern PFN_vkCmdSetStencilWriteMask vkCmdSetStencilWriteMask;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilReference(
//     VkCommandBuffer                             commandBuffer,
//     VkStencilFaceFlags                          faceMask,
//     uint32_t                                    reference);
extern PFN_vkCmdSetStencilReference vkCmdSetStencilReference;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorSets(
//     VkCommandBuffer                             commandBuffer,
//     VkPipelineBindPoint                         pipelineBindPoint,
//     VkPipelineLayout                            layout,
//     uint32_t                                    firstSet,
//     uint32_t                                    descriptorSetCount,
//     const VkDescriptorSet*                      pDescriptorSets,
//     uint32_t                                    dynamicOffsetCount,
//     const uint32_t*                             pDynamicOffsets);
extern PFN_vkCmdBindDescriptorSets vkCmdBindDescriptorSets;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindIndexBuffer(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset,
//     VkIndexType                                 indexType);
extern PFN_vkCmdBindIndexBuffer vkCmdBindIndexBuffer;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstBinding,
//     uint32_t                                    bindingCount,
//     const VkBuffer*                             pBuffers,
//     const VkDeviceSize*                         pOffsets);
extern PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers;
// VKAPI_ATTR void VKAPI_CALL vkCmdDraw(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    vertexCount,
//     uint32_t                                    instanceCount,
//     uint32_t                                    firstVertex,
//     uint32_t                                    firstInstance);
extern PFN_vkCmdDraw vkCmdDraw;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexed(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    indexCount,
//     uint32_t                                    instanceCount,
//     uint32_t                                    firstIndex,
//     int32_t                                     vertexOffset,
//     uint32_t                                    firstInstance);
extern PFN_vkCmdDrawIndexed vkCmdDrawIndexed;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirect(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset,
//     uint32_t                                    drawCount,
//     uint32_t                                    stride);
extern PFN_vkCmdDrawIndirect vkCmdDrawIndirect;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirect(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset,
//     uint32_t                                    drawCount,
//     uint32_t                                    stride);
extern PFN_vkCmdDrawIndexedIndirect vkCmdDrawIndexedIndirect;
// VKAPI_ATTR void VKAPI_CALL vkCmdDispatch(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    groupCountX,
//     uint32_t                                    groupCountY,
//     uint32_t                                    groupCountZ);
extern PFN_vkCmdDispatch vkCmdDispatch;
// VKAPI_ATTR void VKAPI_CALL vkCmdDispatchIndirect(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset);
extern PFN_vkCmdDispatchIndirect vkCmdDispatchIndirect;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyBuffer(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    srcBuffer,
//     VkBuffer                                    dstBuffer,
//     uint32_t                                    regionCount,
//     const VkBufferCopy*                         pRegions);
extern PFN_vkCmdCopyBuffer vkCmdCopyBuffer;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyImage(
//     VkCommandBuffer                             commandBuffer,
//     VkImage                                     srcImage,
//     VkImageLayout                               srcImageLayout,
//     VkImage                                     dstImage,
//     VkImageLayout                               dstImageLayout,
//     uint32_t                                    regionCount,
//     const VkImageCopy*                          pRegions);
extern PFN_vkCmdCopyImage vkCmdCopyImage;
// VKAPI_ATTR void VKAPI_CALL vkCmdBlitImage(
//     VkCommandBuffer                             commandBuffer,
//     VkImage                                     srcImage,
//     VkImageLayout                               srcImageLayout,
//     VkImage                                     dstImage,
//     VkImageLayout                               dstImageLayout,
//     uint32_t                                    regionCount,
//     const VkImageBlit*                          pRegions,
//     VkFilter                                    filter);
extern PFN_vkCmdBlitImage vkCmdBlitImage;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyBufferToImage(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    srcBuffer,
//     VkImage                                     dstImage,
//     VkImageLayout                               dstImageLayout,
//     uint32_t                                    regionCount,
//     const VkBufferImageCopy*                    pRegions);
extern PFN_vkCmdCopyBufferToImage vkCmdCopyBufferToImage;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToBuffer(
//     VkCommandBuffer                             commandBuffer,
//     VkImage                                     srcImage,
//     VkImageLayout                               srcImageLayout,
//     VkBuffer                                    dstBuffer,
//     uint32_t                                    regionCount,
//     const VkBufferImageCopy*                    pRegions);
extern PFN_vkCmdCopyImageToBuffer vkCmdCopyImageToBuffer;
// VKAPI_ATTR void VKAPI_CALL vkCmdUpdateBuffer(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    dstBuffer,
//     VkDeviceSize                                dstOffset,
//     VkDeviceSize                                dataSize,
//     const void*                                 pData);
extern PFN_vkCmdUpdateBuffer vkCmdUpdateBuffer;
// VKAPI_ATTR void VKAPI_CALL vkCmdFillBuffer(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    dstBuffer,
//     VkDeviceSize                                dstOffset,
//     VkDeviceSize                                size,
//     uint32_t                                    data);
extern PFN_vkCmdFillBuffer vkCmdFillBuffer;
// VKAPI_ATTR void VKAPI_CALL vkCmdClearColorImage(
//     VkCommandBuffer                             commandBuffer,
//     VkImage                                     image,
//     VkImageLayout                               imageLayout,
//     const VkClearColorValue*                    pColor,
//     uint32_t                                    rangeCount,
//     const VkImageSubresourceRange*              pRanges);
extern PFN_vkCmdClearColorImage vkCmdClearColorImage;
// VKAPI_ATTR void VKAPI_CALL vkCmdClearDepthStencilImage(
//     VkCommandBuffer                             commandBuffer,
//     VkImage                                     image,
//     VkImageLayout                               imageLayout,
//     const VkClearDepthStencilValue*             pDepthStencil,
//     uint32_t                                    rangeCount,
//     const VkImageSubresourceRange*              pRanges);
extern PFN_vkCmdClearDepthStencilImage vkCmdClearDepthStencilImage;
// VKAPI_ATTR void VKAPI_CALL vkCmdClearAttachments(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    attachmentCount,
//     const VkClearAttachment*                    pAttachments,
//     uint32_t                                    rectCount,
//     const VkClearRect*                          pRects);
extern PFN_vkCmdClearAttachments vkCmdClearAttachments;
// VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage(
//     VkCommandBuffer                             commandBuffer,
//     VkImage                                     srcImage,
//     VkImageLayout                               srcImageLayout,
//     VkImage                                     dstImage,
//     VkImageLayout                               dstImageLayout,
//     uint32_t                                    regionCount,
//     const VkImageResolve*                       pRegions);
extern PFN_vkCmdResolveImage vkCmdResolveImage;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetEvent(
//     VkCommandBuffer                             commandBuffer,
//     VkEvent                                     event,
//     VkPipelineStageFlags                        stageMask);
extern PFN_vkCmdSetEvent vkCmdSetEvent;
// VKAPI_ATTR void VKAPI_CALL vkCmdResetEvent(
//     VkCommandBuffer                             commandBuffer,
//     VkEvent                                     event,
//     VkPipelineStageFlags                        stageMask);
extern PFN_vkCmdResetEvent vkCmdResetEvent;
// VKAPI_ATTR void VKAPI_CALL vkCmdWaitEvents(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    eventCount,
//     const VkEvent*                              pEvents,
//     VkPipelineStageFlags                        srcStageMask,
//     VkPipelineStageFlags                        dstStageMask,
//     uint32_t                                    memoryBarrierCount,
//     const VkMemoryBarrier*                      pMemoryBarriers,
//     uint32_t                                    bufferMemoryBarrierCount,
//     const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
//     uint32_t                                    imageMemoryBarrierCount,
//     const VkImageMemoryBarrier*                 pImageMemoryBarriers);
extern PFN_vkCmdWaitEvents vkCmdWaitEvents;
// VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier(
//     VkCommandBuffer                             commandBuffer,
//     VkPipelineStageFlags                        srcStageMask,
//     VkPipelineStageFlags                        dstStageMask,
//     VkDependencyFlags                           dependencyFlags,
//     uint32_t                                    memoryBarrierCount,
//     const VkMemoryBarrier*                      pMemoryBarriers,
//     uint32_t                                    bufferMemoryBarrierCount,
//     const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
//     uint32_t                                    imageMemoryBarrierCount,
//     const VkImageMemoryBarrier*                 pImageMemoryBarriers);
extern PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier;
// VKAPI_ATTR void VKAPI_CALL vkCmdBeginQuery(
//     VkCommandBuffer                             commandBuffer,
//     VkQueryPool                                 queryPool,
//     uint32_t                                    query,
//     VkQueryControlFlags                         flags);
extern PFN_vkCmdBeginQuery vkCmdBeginQuery;
// VKAPI_ATTR void VKAPI_CALL vkCmdEndQuery(
//     VkCommandBuffer                             commandBuffer,
//     VkQueryPool                                 queryPool,
//     uint32_t                                    query);
extern PFN_vkCmdEndQuery vkCmdEndQuery;
// VKAPI_ATTR void VKAPI_CALL vkCmdResetQueryPool(
//     VkCommandBuffer                             commandBuffer,
//     VkQueryPool                                 queryPool,
//     uint32_t                                    firstQuery,
//     uint32_t                                    queryCount);
extern PFN_vkCmdResetQueryPool vkCmdResetQueryPool;
// VKAPI_ATTR void VKAPI_CALL vkCmdWriteTimestamp(
//     VkCommandBuffer                             commandBuffer,
//     VkPipelineStageFlagBits                     pipelineStage,
//     VkQueryPool                                 queryPool,
//     uint32_t                                    query);
extern PFN_vkCmdWriteTimestamp vkCmdWriteTimestamp;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyQueryPoolResults(
//     VkCommandBuffer                             commandBuffer,
//     VkQueryPool                                 queryPool,
//     uint32_t                                    firstQuery,
//     uint32_t                                    queryCount,
//     VkBuffer                                    dstBuffer,
//     VkDeviceSize                                dstOffset,
//     VkDeviceSize                                stride,
//     VkQueryResultFlags                          flags);
extern PFN_vkCmdCopyQueryPoolResults vkCmdCopyQueryPoolResults;
// VKAPI_ATTR void VKAPI_CALL vkCmdPushConstants(
//     VkCommandBuffer                             commandBuffer,
//     VkPipelineLayout                            layout,
//     VkShaderStageFlags                          stageFlags,
//     uint32_t                                    offset,
//     uint32_t                                    size,
//     const void*                                 pValues);
extern PFN_vkCmdPushConstants vkCmdPushConstants;
// VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderPass(
//     VkCommandBuffer                             commandBuffer,
//     const VkRenderPassBeginInfo*                pRenderPassBegin,
//     VkSubpassContents                           contents);
extern PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass;
// VKAPI_ATTR void VKAPI_CALL vkCmdNextSubpass(
//     VkCommandBuffer                             commandBuffer,
//     VkSubpassContents                           contents);
extern PFN_vkCmdNextSubpass vkCmdNextSubpass;
// VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderPass(
//     VkCommandBuffer                             commandBuffer);
extern PFN_vkCmdEndRenderPass vkCmdEndRenderPass;
// VKAPI_ATTR void VKAPI_CALL vkCmdExecuteCommands(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    commandBufferCount,
//     const VkCommandBuffer*                      pCommandBuffers);
extern PFN_vkCmdExecuteCommands vkCmdExecuteCommands;


// VK_VERSION_1_1
// VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceVersion(
//     uint32_t*                                   pApiVersion);
extern PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion;
// VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory2(
//     VkDevice                                    device,
//     uint32_t                                    bindInfoCount,
//     const VkBindBufferMemoryInfo*               pBindInfos);
extern PFN_vkBindBufferMemory2 vkBindBufferMemory2;
// VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory2(
//     VkDevice                                    device,
//     uint32_t                                    bindInfoCount,
//     const VkBindImageMemoryInfo*                pBindInfos);
extern PFN_vkBindImageMemory2 vkBindImageMemory2;
// VKAPI_ATTR void VKAPI_CALL vkGetDeviceGroupPeerMemoryFeatures(
//     VkDevice                                    device,
//     uint32_t                                    heapIndex,
//     uint32_t                                    localDeviceIndex,
//     uint32_t                                    remoteDeviceIndex,
//     VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures);
extern PFN_vkGetDeviceGroupPeerMemoryFeatures vkGetDeviceGroupPeerMemoryFeatures;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDeviceMask(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    deviceMask);
extern PFN_vkCmdSetDeviceMask vkCmdSetDeviceMask;
// VKAPI_ATTR void VKAPI_CALL vkCmdDispatchBase(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    baseGroupX,
//     uint32_t                                    baseGroupY,
//     uint32_t                                    baseGroupZ,
//     uint32_t                                    groupCountX,
//     uint32_t                                    groupCountY,
//     uint32_t                                    groupCountZ);
extern PFN_vkCmdDispatchBase vkCmdDispatchBase;
// VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceGroups(
//     VkInstance                                  instance,
//     uint32_t*                                   pPhysicalDeviceGroupCount,
//     VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties);
extern PFN_vkEnumeratePhysicalDeviceGroups vkEnumeratePhysicalDeviceGroups;
// VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements2(
//     VkDevice                                    device,
//     const VkImageMemoryRequirementsInfo2*       pInfo,
//     VkMemoryRequirements2*                      pMemoryRequirements);
extern PFN_vkGetImageMemoryRequirements2 vkGetImageMemoryRequirements2;
// VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements2(
//     VkDevice                                    device,
//     const VkBufferMemoryRequirementsInfo2*      pInfo,
//     VkMemoryRequirements2*                      pMemoryRequirements);
extern PFN_vkGetBufferMemoryRequirements2 vkGetBufferMemoryRequirements2;
// VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements2(
//     VkDevice                                    device,
//     const VkImageSparseMemoryRequirementsInfo2* pInfo,
//     uint32_t*                                   pSparseMemoryRequirementCount,
//     VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements);
extern PFN_vkGetImageSparseMemoryRequirements2 vkGetImageSparseMemoryRequirements2;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures2(
//     VkPhysicalDevice                            physicalDevice,
//     VkPhysicalDeviceFeatures2*                  pFeatures);
extern PFN_vkGetPhysicalDeviceFeatures2 vkGetPhysicalDeviceFeatures2;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties2(
//     VkPhysicalDevice                            physicalDevice,
//     VkPhysicalDeviceProperties2*                pProperties);
extern PFN_vkGetPhysicalDeviceProperties2 vkGetPhysicalDeviceProperties2;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties2(
//     VkPhysicalDevice                            physicalDevice,
//     VkFormat                                    format,
//     VkFormatProperties2*                        pFormatProperties);
extern PFN_vkGetPhysicalDeviceFormatProperties2 vkGetPhysicalDeviceFormatProperties2;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties2(
//     VkPhysicalDevice                            physicalDevice,
//     const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
//     VkImageFormatProperties2*                   pImageFormatProperties);
extern PFN_vkGetPhysicalDeviceImageFormatProperties2 vkGetPhysicalDeviceImageFormatProperties2;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties2(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pQueueFamilyPropertyCount,
//     VkQueueFamilyProperties2*                   pQueueFamilyProperties);
extern PFN_vkGetPhysicalDeviceQueueFamilyProperties2 vkGetPhysicalDeviceQueueFamilyProperties2;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties2(
//     VkPhysicalDevice                            physicalDevice,
//     VkPhysicalDeviceMemoryProperties2*          pMemoryProperties);
extern PFN_vkGetPhysicalDeviceMemoryProperties2 vkGetPhysicalDeviceMemoryProperties2;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties2(
//     VkPhysicalDevice                            physicalDevice,
//     const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
//     uint32_t*                                   pPropertyCount,
//     VkSparseImageFormatProperties2*             pProperties);
extern PFN_vkGetPhysicalDeviceSparseImageFormatProperties2 vkGetPhysicalDeviceSparseImageFormatProperties2;
// VKAPI_ATTR void VKAPI_CALL vkTrimCommandPool(
//     VkDevice                                    device,
//     VkCommandPool                               commandPool,
//     VkCommandPoolTrimFlags                      flags);
extern PFN_vkTrimCommandPool vkTrimCommandPool;
// VKAPI_ATTR void VKAPI_CALL vkGetDeviceQueue2(
//     VkDevice                                    device,
//     const VkDeviceQueueInfo2*                   pQueueInfo,
//     VkQueue*                                    pQueue);
extern PFN_vkGetDeviceQueue2 vkGetDeviceQueue2;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateSamplerYcbcrConversion(
//     VkDevice                                    device,
//     const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkSamplerYcbcrConversion*                   pYcbcrConversion);
extern PFN_vkCreateSamplerYcbcrConversion vkCreateSamplerYcbcrConversion;
// VKAPI_ATTR void VKAPI_CALL vkDestroySamplerYcbcrConversion(
//     VkDevice                                    device,
//     VkSamplerYcbcrConversion                    ycbcrConversion,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroySamplerYcbcrConversion vkDestroySamplerYcbcrConversion;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorUpdateTemplate(
//     VkDevice                                    device,
//     const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate);
extern PFN_vkCreateDescriptorUpdateTemplate vkCreateDescriptorUpdateTemplate;
// VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorUpdateTemplate(
//     VkDevice                                    device,
//     VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyDescriptorUpdateTemplate vkDestroyDescriptorUpdateTemplate;
// VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSetWithTemplate(
//     VkDevice                                    device,
//     VkDescriptorSet                             descriptorSet,
//     VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
//     const void*                                 pData);
extern PFN_vkUpdateDescriptorSetWithTemplate vkUpdateDescriptorSetWithTemplate;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalBufferProperties(
//     VkPhysicalDevice                            physicalDevice,
//     const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
//     VkExternalBufferProperties*                 pExternalBufferProperties);
extern PFN_vkGetPhysicalDeviceExternalBufferProperties vkGetPhysicalDeviceExternalBufferProperties;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalFenceProperties(
//     VkPhysicalDevice                            physicalDevice,
//     const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
//     VkExternalFenceProperties*                  pExternalFenceProperties);
extern PFN_vkGetPhysicalDeviceExternalFenceProperties vkGetPhysicalDeviceExternalFenceProperties;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalSemaphoreProperties(
//     VkPhysicalDevice                            physicalDevice,
//     const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
//     VkExternalSemaphoreProperties*              pExternalSemaphoreProperties);
extern PFN_vkGetPhysicalDeviceExternalSemaphoreProperties vkGetPhysicalDeviceExternalSemaphoreProperties;
// VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutSupport(
//     VkDevice                                    device,
//     const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
//     VkDescriptorSetLayoutSupport*               pSupport);
extern PFN_vkGetDescriptorSetLayoutSupport vkGetDescriptorSetLayoutSupport;


// VK_VERSION_1_2
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCount(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset,
//     VkBuffer                                    countBuffer,
//     VkDeviceSize                                countBufferOffset,
//     uint32_t                                    maxDrawCount,
//     uint32_t                                    stride);
extern PFN_vkCmdDrawIndirectCount vkCmdDrawIndirectCount;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCount(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset,
//     VkBuffer                                    countBuffer,
//     VkDeviceSize                                countBufferOffset,
//     uint32_t                                    maxDrawCount,
//     uint32_t                                    stride);
extern PFN_vkCmdDrawIndexedIndirectCount vkCmdDrawIndexedIndirectCount;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateRenderPass2(
//     VkDevice                                    device,
//     const VkRenderPassCreateInfo2*              pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkRenderPass*                               pRenderPass);
extern PFN_vkCreateRenderPass2 vkCreateRenderPass2;
// VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderPass2(
//     VkCommandBuffer                             commandBuffer,
//     const VkRenderPassBeginInfo*                pRenderPassBegin,
//     const VkSubpassBeginInfo*                   pSubpassBeginInfo);
extern PFN_vkCmdBeginRenderPass2 vkCmdBeginRenderPass2;
// VKAPI_ATTR void VKAPI_CALL vkCmdNextSubpass2(
//     VkCommandBuffer                             commandBuffer,
//     const VkSubpassBeginInfo*                   pSubpassBeginInfo,
//     const VkSubpassEndInfo*                     pSubpassEndInfo);
extern PFN_vkCmdNextSubpass2 vkCmdNextSubpass2;
// VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderPass2(
//     VkCommandBuffer                             commandBuffer,
//     const VkSubpassEndInfo*                     pSubpassEndInfo);
extern PFN_vkCmdEndRenderPass2 vkCmdEndRenderPass2;
// VKAPI_ATTR void VKAPI_CALL vkResetQueryPool(
//     VkDevice                                    device,
//     VkQueryPool                                 queryPool,
//     uint32_t                                    firstQuery,
//     uint32_t                                    queryCount);
extern PFN_vkResetQueryPool vkResetQueryPool;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreCounterValue(
//     VkDevice                                    device,
//     VkSemaphore                                 semaphore,
//     uint64_t*                                   pValue);
extern PFN_vkGetSemaphoreCounterValue vkGetSemaphoreCounterValue;
// VKAPI_ATTR VkResult VKAPI_CALL vkWaitSemaphores(
//     VkDevice                                    device,
//     const VkSemaphoreWaitInfo*                  pWaitInfo,
//     uint64_t                                    timeout);
extern PFN_vkWaitSemaphores vkWaitSemaphores;
// VKAPI_ATTR VkResult VKAPI_CALL vkSignalSemaphore(
//     VkDevice                                    device,
//     const VkSemaphoreSignalInfo*                pSignalInfo);
extern PFN_vkSignalSemaphore vkSignalSemaphore;
// VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddress(
//     VkDevice                                    device,
//     const VkBufferDeviceAddressInfo*            pInfo);
extern PFN_vkGetBufferDeviceAddress vkGetBufferDeviceAddress;
// VKAPI_ATTR uint64_t VKAPI_CALL vkGetBufferOpaqueCaptureAddress(
//     VkDevice                                    device,
//     const VkBufferDeviceAddressInfo*            pInfo);
extern PFN_vkGetBufferOpaqueCaptureAddress vkGetBufferOpaqueCaptureAddress;
// VKAPI_ATTR uint64_t VKAPI_CALL vkGetDeviceMemoryOpaqueCaptureAddress(
//     VkDevice                                    device,
//     const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);
extern PFN_vkGetDeviceMemoryOpaqueCaptureAddress vkGetDeviceMemoryOpaqueCaptureAddress;


// VK_VERSION_1_3
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceToolProperties(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pToolCount,
//     VkPhysicalDeviceToolProperties*             pToolProperties);
extern PFN_vkGetPhysicalDeviceToolProperties vkGetPhysicalDeviceToolProperties;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreatePrivateDataSlot(
//     VkDevice                                    device,
//     const VkPrivateDataSlotCreateInfo*          pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkPrivateDataSlot*                          pPrivateDataSlot);
extern PFN_vkCreatePrivateDataSlot vkCreatePrivateDataSlot;
// VKAPI_ATTR void VKAPI_CALL vkDestroyPrivateDataSlot(
//     VkDevice                                    device,
//     VkPrivateDataSlot                           privateDataSlot,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyPrivateDataSlot vkDestroyPrivateDataSlot;
// VKAPI_ATTR VkResult VKAPI_CALL vkSetPrivateData(
//     VkDevice                                    device,
//     VkObjectType                                objectType,
//     uint64_t                                    objectHandle,
//     VkPrivateDataSlot                           privateDataSlot,
//     uint64_t                                    data);
extern PFN_vkSetPrivateData vkSetPrivateData;
// VKAPI_ATTR void VKAPI_CALL vkGetPrivateData(
//     VkDevice                                    device,
//     VkObjectType                                objectType,
//     uint64_t                                    objectHandle,
//     VkPrivateDataSlot                           privateDataSlot,
//     uint64_t*                                   pData);
extern PFN_vkGetPrivateData vkGetPrivateData;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetEvent2(
//     VkCommandBuffer                             commandBuffer,
//     VkEvent                                     event,
//     const VkDependencyInfo*                     pDependencyInfo);
extern PFN_vkCmdSetEvent2 vkCmdSetEvent2;
// VKAPI_ATTR void VKAPI_CALL vkCmdResetEvent2(
//     VkCommandBuffer                             commandBuffer,
//     VkEvent                                     event,
//     VkPipelineStageFlags2                       stageMask);
extern PFN_vkCmdResetEvent2 vkCmdResetEvent2;
// VKAPI_ATTR void VKAPI_CALL vkCmdWaitEvents2(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    eventCount,
//     const VkEvent*                              pEvents,
//     const VkDependencyInfo*                     pDependencyInfos);
extern PFN_vkCmdWaitEvents2 vkCmdWaitEvents2;
// VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier2(
//     VkCommandBuffer                             commandBuffer,
//     const VkDependencyInfo*                     pDependencyInfo);
extern PFN_vkCmdPipelineBarrier2 vkCmdPipelineBarrier2;
// VKAPI_ATTR void VKAPI_CALL vkCmdWriteTimestamp2(
//     VkCommandBuffer                             commandBuffer,
//     VkPipelineStageFlags2                       stage,
//     VkQueryPool                                 queryPool,
//     uint32_t                                    query);
extern PFN_vkCmdWriteTimestamp2 vkCmdWriteTimestamp2;
// VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit2(
//     VkQueue                                     queue,
//     uint32_t                                    submitCount,
//     const VkSubmitInfo2*                        pSubmits,
//     VkFence                                     fence);
extern PFN_vkQueueSubmit2 vkQueueSubmit2;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyBuffer2(
//     VkCommandBuffer                             commandBuffer,
//     const VkCopyBufferInfo2*                    pCopyBufferInfo);
extern PFN_vkCmdCopyBuffer2 vkCmdCopyBuffer2;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyImage2(
//     VkCommandBuffer                             commandBuffer,
//     const VkCopyImageInfo2*                     pCopyImageInfo);
extern PFN_vkCmdCopyImage2 vkCmdCopyImage2;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyBufferToImage2(
//     VkCommandBuffer                             commandBuffer,
//     const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo);
extern PFN_vkCmdCopyBufferToImage2 vkCmdCopyBufferToImage2;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToBuffer2(
//     VkCommandBuffer                             commandBuffer,
//     const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo);
extern PFN_vkCmdCopyImageToBuffer2 vkCmdCopyImageToBuffer2;
// VKAPI_ATTR void VKAPI_CALL vkCmdBlitImage2(
//     VkCommandBuffer                             commandBuffer,
//     const VkBlitImageInfo2*                     pBlitImageInfo);
extern PFN_vkCmdBlitImage2 vkCmdBlitImage2;
// VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage2(
//     VkCommandBuffer                             commandBuffer,
//     const VkResolveImageInfo2*                  pResolveImageInfo);
extern PFN_vkCmdResolveImage2 vkCmdResolveImage2;
// VKAPI_ATTR void VKAPI_CALL vkCmdBeginRendering(
//     VkCommandBuffer                             commandBuffer,
//     const VkRenderingInfo*                      pRenderingInfo);
extern PFN_vkCmdBeginRendering vkCmdBeginRendering;
// VKAPI_ATTR void VKAPI_CALL vkCmdEndRendering(
//     VkCommandBuffer                             commandBuffer);
extern PFN_vkCmdEndRendering vkCmdEndRendering;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetCullMode(
//     VkCommandBuffer                             commandBuffer,
//     VkCullModeFlags                             cullMode);
extern PFN_vkCmdSetCullMode vkCmdSetCullMode;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetFrontFace(
//     VkCommandBuffer                             commandBuffer,
//     VkFrontFace                                 frontFace);
extern PFN_vkCmdSetFrontFace vkCmdSetFrontFace;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveTopology(
//     VkCommandBuffer                             commandBuffer,
//     VkPrimitiveTopology                         primitiveTopology);
extern PFN_vkCmdSetPrimitiveTopology vkCmdSetPrimitiveTopology;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWithCount(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    viewportCount,
//     const VkViewport*                           pViewports);
extern PFN_vkCmdSetViewportWithCount vkCmdSetViewportWithCount;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetScissorWithCount(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    scissorCount,
//     const VkRect2D*                             pScissors);
extern PFN_vkCmdSetScissorWithCount vkCmdSetScissorWithCount;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers2(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstBinding,
//     uint32_t                                    bindingCount,
//     const VkBuffer*                             pBuffers,
//     const VkDeviceSize*                         pOffsets,
//     const VkDeviceSize*                         pSizes,
//     const VkDeviceSize*                         pStrides);
extern PFN_vkCmdBindVertexBuffers2 vkCmdBindVertexBuffers2;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthTestEnable(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    depthTestEnable);
extern PFN_vkCmdSetDepthTestEnable vkCmdSetDepthTestEnable;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthWriteEnable(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    depthWriteEnable);
extern PFN_vkCmdSetDepthWriteEnable vkCmdSetDepthWriteEnable;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthCompareOp(
//     VkCommandBuffer                             commandBuffer,
//     VkCompareOp                                 depthCompareOp);
extern PFN_vkCmdSetDepthCompareOp vkCmdSetDepthCompareOp;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBoundsTestEnable(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    depthBoundsTestEnable);
extern PFN_vkCmdSetDepthBoundsTestEnable vkCmdSetDepthBoundsTestEnable;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilTestEnable(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    stencilTestEnable);
extern PFN_vkCmdSetStencilTestEnable vkCmdSetStencilTestEnable;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilOp(
//     VkCommandBuffer                             commandBuffer,
//     VkStencilFaceFlags                          faceMask,
//     VkStencilOp                                 failOp,
//     VkStencilOp                                 passOp,
//     VkStencilOp                                 depthFailOp,
//     VkCompareOp                                 compareOp);
extern PFN_vkCmdSetStencilOp vkCmdSetStencilOp;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizerDiscardEnable(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    rasterizerDiscardEnable);
extern PFN_vkCmdSetRasterizerDiscardEnable vkCmdSetRasterizerDiscardEnable;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBiasEnable(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    depthBiasEnable);
extern PFN_vkCmdSetDepthBiasEnable vkCmdSetDepthBiasEnable;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveRestartEnable(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    primitiveRestartEnable);
extern PFN_vkCmdSetPrimitiveRestartEnable vkCmdSetPrimitiveRestartEnable;
// VKAPI_ATTR void VKAPI_CALL vkGetDeviceBufferMemoryRequirements(
//     VkDevice                                    device,
//     const VkDeviceBufferMemoryRequirements*     pInfo,
//     VkMemoryRequirements2*                      pMemoryRequirements);
extern PFN_vkGetDeviceBufferMemoryRequirements vkGetDeviceBufferMemoryRequirements;
// VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageMemoryRequirements(
//     VkDevice                                    device,
//     const VkDeviceImageMemoryRequirements*      pInfo,
//     VkMemoryRequirements2*                      pMemoryRequirements);
extern PFN_vkGetDeviceImageMemoryRequirements vkGetDeviceImageMemoryRequirements;
// VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSparseMemoryRequirements(
//     VkDevice                                    device,
//     const VkDeviceImageMemoryRequirements*      pInfo,
//     uint32_t*                                   pSparseMemoryRequirementCount,
//     VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements);
extern PFN_vkGetDeviceImageSparseMemoryRequirements vkGetDeviceImageSparseMemoryRequirements;
// VKAPI_ATTR void VKAPI_CALL vkDestroySurfaceKHR(
//     VkInstance                                  instance,
//     VkSurfaceKHR                                surface,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceSupportKHR(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t                                    queueFamilyIndex,
//     VkSurfaceKHR                                surface,
//     VkBool32*                                   pSupported);
extern PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     VkSurfaceKHR                                surface,
//     VkSurfaceCapabilitiesKHR*                   pSurfaceCapabilities);
extern PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceFormatsKHR(
//     VkPhysicalDevice                            physicalDevice,
//     VkSurfaceKHR                                surface,
//     uint32_t*                                   pSurfaceFormatCount,
//     VkSurfaceFormatKHR*                         pSurfaceFormats);
extern PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfacePresentModesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     VkSurfaceKHR                                surface,
//     uint32_t*                                   pPresentModeCount,
//     VkPresentModeKHR*                           pPresentModes);
extern PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateSwapchainKHR(
//     VkDevice                                    device,
//     const VkSwapchainCreateInfoKHR*             pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkSwapchainKHR*                             pSwapchain);
extern PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR;
// VKAPI_ATTR void VKAPI_CALL vkDestroySwapchainKHR(
//     VkDevice                                    device,
//     VkSwapchainKHR                              swapchain,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainImagesKHR(
//     VkDevice                                    device,
//     VkSwapchainKHR                              swapchain,
//     uint32_t*                                   pSwapchainImageCount,
//     VkImage*                                    pSwapchainImages);
extern PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkAcquireNextImageKHR(
//     VkDevice                                    device,
//     VkSwapchainKHR                              swapchain,
//     uint64_t                                    timeout,
//     VkSemaphore                                 semaphore,
//     VkFence                                     fence,
//     uint32_t*                                   pImageIndex);
extern PFN_vkAcquireNextImageKHR vkAcquireNextImageKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkQueuePresentKHR(
//     VkQueue                                     queue,
//     const VkPresentInfoKHR*                     pPresentInfo);
extern PFN_vkQueuePresentKHR vkQueuePresentKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupPresentCapabilitiesKHR(
//     VkDevice                                    device,
//     VkDeviceGroupPresentCapabilitiesKHR*        pDeviceGroupPresentCapabilities);
extern PFN_vkGetDeviceGroupPresentCapabilitiesKHR vkGetDeviceGroupPresentCapabilitiesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupSurfacePresentModesKHR(
//     VkDevice                                    device,
//     VkSurfaceKHR                                surface,
//     VkDeviceGroupPresentModeFlagsKHR*           pModes);
extern PFN_vkGetDeviceGroupSurfacePresentModesKHR vkGetDeviceGroupSurfacePresentModesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDevicePresentRectanglesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     VkSurfaceKHR                                surface,
//     uint32_t*                                   pRectCount,
//     VkRect2D*                                   pRects);
extern PFN_vkGetPhysicalDevicePresentRectanglesKHR vkGetPhysicalDevicePresentRectanglesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkAcquireNextImage2KHR(
//     VkDevice                                    device,
//     const VkAcquireNextImageInfoKHR*            pAcquireInfo,
//     uint32_t*                                   pImageIndex);
extern PFN_vkAcquireNextImage2KHR vkAcquireNextImage2KHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPropertiesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pPropertyCount,
//     VkDisplayPropertiesKHR*                     pProperties);
extern PFN_vkGetPhysicalDeviceDisplayPropertiesKHR vkGetPhysicalDeviceDisplayPropertiesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pPropertyCount,
//     VkDisplayPlanePropertiesKHR*                pProperties);
extern PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayPlaneSupportedDisplaysKHR(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t                                    planeIndex,
//     uint32_t*                                   pDisplayCount,
//     VkDisplayKHR*                               pDisplays);
extern PFN_vkGetDisplayPlaneSupportedDisplaysKHR vkGetDisplayPlaneSupportedDisplaysKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayModePropertiesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     VkDisplayKHR                                display,
//     uint32_t*                                   pPropertyCount,
//     VkDisplayModePropertiesKHR*                 pProperties);
extern PFN_vkGetDisplayModePropertiesKHR vkGetDisplayModePropertiesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateDisplayModeKHR(
//     VkPhysicalDevice                            physicalDevice,
//     VkDisplayKHR                                display,
//     const VkDisplayModeCreateInfoKHR*           pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkDisplayModeKHR*                           pMode);
extern PFN_vkCreateDisplayModeKHR vkCreateDisplayModeKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayPlaneCapabilitiesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     VkDisplayModeKHR                            mode,
//     uint32_t                                    planeIndex,
//     VkDisplayPlaneCapabilitiesKHR*              pCapabilities);
extern PFN_vkGetDisplayPlaneCapabilitiesKHR vkGetDisplayPlaneCapabilitiesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateDisplayPlaneSurfaceKHR(
//     VkInstance                                  instance,
//     const VkDisplaySurfaceCreateInfoKHR*        pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkSurfaceKHR*                               pSurface);
extern PFN_vkCreateDisplayPlaneSurfaceKHR vkCreateDisplayPlaneSurfaceKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateSharedSwapchainsKHR(
//     VkDevice                                    device,
//     uint32_t                                    swapchainCount,
//     const VkSwapchainCreateInfoKHR*             pCreateInfos,
//     const VkAllocationCallbacks*                pAllocator,
//     VkSwapchainKHR*                             pSwapchains);
extern PFN_vkCreateSharedSwapchainsKHR vkCreateSharedSwapchainsKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceVideoCapabilitiesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     const VkVideoProfileInfoKHR*                pVideoProfile,
//     VkVideoCapabilitiesKHR*                     pCapabilities);
extern PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR vkGetPhysicalDeviceVideoCapabilitiesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceVideoFormatPropertiesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     const VkPhysicalDeviceVideoFormatInfoKHR*   pVideoFormatInfo,
//     uint32_t*                                   pVideoFormatPropertyCount,
//     VkVideoFormatPropertiesKHR*                 pVideoFormatProperties);
extern PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR vkGetPhysicalDeviceVideoFormatPropertiesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateVideoSessionKHR(
//     VkDevice                                    device,
//     const VkVideoSessionCreateInfoKHR*          pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkVideoSessionKHR*                          pVideoSession);
extern PFN_vkCreateVideoSessionKHR vkCreateVideoSessionKHR;
// VKAPI_ATTR void VKAPI_CALL vkDestroyVideoSessionKHR(
//     VkDevice                                    device,
//     VkVideoSessionKHR                           videoSession,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyVideoSessionKHR vkDestroyVideoSessionKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetVideoSessionMemoryRequirementsKHR(
//     VkDevice                                    device,
//     VkVideoSessionKHR                           videoSession,
//     uint32_t*                                   pMemoryRequirementsCount,
//     VkVideoSessionMemoryRequirementsKHR*        pMemoryRequirements);
extern PFN_vkGetVideoSessionMemoryRequirementsKHR vkGetVideoSessionMemoryRequirementsKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkBindVideoSessionMemoryKHR(
//     VkDevice                                    device,
//     VkVideoSessionKHR                           videoSession,
//     uint32_t                                    bindSessionMemoryInfoCount,
//     const VkBindVideoSessionMemoryInfoKHR*      pBindSessionMemoryInfos);
extern PFN_vkBindVideoSessionMemoryKHR vkBindVideoSessionMemoryKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateVideoSessionParametersKHR(
//     VkDevice                                    device,
//     const VkVideoSessionParametersCreateInfoKHR* pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkVideoSessionParametersKHR*                pVideoSessionParameters);
extern PFN_vkCreateVideoSessionParametersKHR vkCreateVideoSessionParametersKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkUpdateVideoSessionParametersKHR(
//     VkDevice                                    device,
//     VkVideoSessionParametersKHR                 videoSessionParameters,
//     const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo);
extern PFN_vkUpdateVideoSessionParametersKHR vkUpdateVideoSessionParametersKHR;
// VKAPI_ATTR void VKAPI_CALL vkDestroyVideoSessionParametersKHR(
//     VkDevice                                    device,
//     VkVideoSessionParametersKHR                 videoSessionParameters,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyVideoSessionParametersKHR vkDestroyVideoSessionParametersKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdBeginVideoCodingKHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkVideoBeginCodingInfoKHR*            pBeginInfo);
extern PFN_vkCmdBeginVideoCodingKHR vkCmdBeginVideoCodingKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdEndVideoCodingKHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkVideoEndCodingInfoKHR*              pEndCodingInfo);
extern PFN_vkCmdEndVideoCodingKHR vkCmdEndVideoCodingKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdControlVideoCodingKHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkVideoCodingControlInfoKHR*          pCodingControlInfo);
extern PFN_vkCmdControlVideoCodingKHR vkCmdControlVideoCodingKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdDecodeVideoKHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkVideoDecodeInfoKHR*                 pDecodeInfo);
extern PFN_vkCmdDecodeVideoKHR vkCmdDecodeVideoKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderingKHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkRenderingInfo*                      pRenderingInfo);
extern PFN_vkCmdBeginRenderingKHR vkCmdBeginRenderingKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderingKHR(
//     VkCommandBuffer                             commandBuffer);
extern PFN_vkCmdEndRenderingKHR vkCmdEndRenderingKHR;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures2KHR(
//     VkPhysicalDevice                            physicalDevice,
//     VkPhysicalDeviceFeatures2*                  pFeatures);
extern PFN_vkGetPhysicalDeviceFeatures2KHR vkGetPhysicalDeviceFeatures2KHR;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties2KHR(
//     VkPhysicalDevice                            physicalDevice,
//     VkPhysicalDeviceProperties2*                pProperties);
extern PFN_vkGetPhysicalDeviceProperties2KHR vkGetPhysicalDeviceProperties2KHR;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties2KHR(
//     VkPhysicalDevice                            physicalDevice,
//     VkFormat                                    format,
//     VkFormatProperties2*                        pFormatProperties);
extern PFN_vkGetPhysicalDeviceFormatProperties2KHR vkGetPhysicalDeviceFormatProperties2KHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties2KHR(
//     VkPhysicalDevice                            physicalDevice,
//     const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
//     VkImageFormatProperties2*                   pImageFormatProperties);
extern PFN_vkGetPhysicalDeviceImageFormatProperties2KHR vkGetPhysicalDeviceImageFormatProperties2KHR;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties2KHR(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pQueueFamilyPropertyCount,
//     VkQueueFamilyProperties2*                   pQueueFamilyProperties);
extern PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR vkGetPhysicalDeviceQueueFamilyProperties2KHR;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties2KHR(
//     VkPhysicalDevice                            physicalDevice,
//     VkPhysicalDeviceMemoryProperties2*          pMemoryProperties);
extern PFN_vkGetPhysicalDeviceMemoryProperties2KHR vkGetPhysicalDeviceMemoryProperties2KHR;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
//     VkPhysicalDevice                            physicalDevice,
//     const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
//     uint32_t*                                   pPropertyCount,
//     VkSparseImageFormatProperties2*             pProperties);
extern PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
// VKAPI_ATTR void VKAPI_CALL vkGetDeviceGroupPeerMemoryFeaturesKHR(
//     VkDevice                                    device,
//     uint32_t                                    heapIndex,
//     uint32_t                                    localDeviceIndex,
//     uint32_t                                    remoteDeviceIndex,
//     VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures);
extern PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR vkGetDeviceGroupPeerMemoryFeaturesKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDeviceMaskKHR(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    deviceMask);
extern PFN_vkCmdSetDeviceMaskKHR vkCmdSetDeviceMaskKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdDispatchBaseKHR(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    baseGroupX,
//     uint32_t                                    baseGroupY,
//     uint32_t                                    baseGroupZ,
//     uint32_t                                    groupCountX,
//     uint32_t                                    groupCountY,
//     uint32_t                                    groupCountZ);
extern PFN_vkCmdDispatchBaseKHR vkCmdDispatchBaseKHR;
// VKAPI_ATTR void VKAPI_CALL vkTrimCommandPoolKHR(
//     VkDevice                                    device,
//     VkCommandPool                               commandPool,
//     VkCommandPoolTrimFlags                      flags);
extern PFN_vkTrimCommandPoolKHR vkTrimCommandPoolKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceGroupsKHR(
//     VkInstance                                  instance,
//     uint32_t*                                   pPhysicalDeviceGroupCount,
//     VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties);
extern PFN_vkEnumeratePhysicalDeviceGroupsKHR vkEnumeratePhysicalDeviceGroupsKHR;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalBufferPropertiesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
//     VkExternalBufferProperties*                 pExternalBufferProperties);
extern PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR vkGetPhysicalDeviceExternalBufferPropertiesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryFdKHR(
//     VkDevice                                    device,
//     const VkMemoryGetFdInfoKHR*                 pGetFdInfo,
//     int*                                        pFd);
extern PFN_vkGetMemoryFdKHR vkGetMemoryFdKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryFdPropertiesKHR(
//     VkDevice                                    device,
//     VkExternalMemoryHandleTypeFlagBits          handleType,
//     int                                         fd,
//     VkMemoryFdPropertiesKHR*                    pMemoryFdProperties);
extern PFN_vkGetMemoryFdPropertiesKHR vkGetMemoryFdPropertiesKHR;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
//     VkExternalSemaphoreProperties*              pExternalSemaphoreProperties);
extern PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreFdKHR(
//     VkDevice                                    device,
//     const VkImportSemaphoreFdInfoKHR*           pImportSemaphoreFdInfo);
extern PFN_vkImportSemaphoreFdKHR vkImportSemaphoreFdKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreFdKHR(
//     VkDevice                                    device,
//     const VkSemaphoreGetFdInfoKHR*              pGetFdInfo,
//     int*                                        pFd);
extern PFN_vkGetSemaphoreFdKHR vkGetSemaphoreFdKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetKHR(
//     VkCommandBuffer                             commandBuffer,
//     VkPipelineBindPoint                         pipelineBindPoint,
//     VkPipelineLayout                            layout,
//     uint32_t                                    set,
//     uint32_t                                    descriptorWriteCount,
//     const VkWriteDescriptorSet*                 pDescriptorWrites);
extern PFN_vkCmdPushDescriptorSetKHR vkCmdPushDescriptorSetKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplateKHR(
//     VkCommandBuffer                             commandBuffer,
//     VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
//     VkPipelineLayout                            layout,
//     uint32_t                                    set,
//     const void*                                 pData);
extern PFN_vkCmdPushDescriptorSetWithTemplateKHR vkCmdPushDescriptorSetWithTemplateKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorUpdateTemplateKHR(
//     VkDevice                                    device,
//     const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate);
extern PFN_vkCreateDescriptorUpdateTemplateKHR vkCreateDescriptorUpdateTemplateKHR;
// VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorUpdateTemplateKHR(
//     VkDevice                                    device,
//     VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyDescriptorUpdateTemplateKHR vkDestroyDescriptorUpdateTemplateKHR;
// VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSetWithTemplateKHR(
//     VkDevice                                    device,
//     VkDescriptorSet                             descriptorSet,
//     VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
//     const void*                                 pData);
extern PFN_vkUpdateDescriptorSetWithTemplateKHR vkUpdateDescriptorSetWithTemplateKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateRenderPass2KHR(
//     VkDevice                                    device,
//     const VkRenderPassCreateInfo2*              pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkRenderPass*                               pRenderPass);
extern PFN_vkCreateRenderPass2KHR vkCreateRenderPass2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderPass2KHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkRenderPassBeginInfo*                pRenderPassBegin,
//     const VkSubpassBeginInfo*                   pSubpassBeginInfo);
extern PFN_vkCmdBeginRenderPass2KHR vkCmdBeginRenderPass2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdNextSubpass2KHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkSubpassBeginInfo*                   pSubpassBeginInfo,
//     const VkSubpassEndInfo*                     pSubpassEndInfo);
extern PFN_vkCmdNextSubpass2KHR vkCmdNextSubpass2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderPass2KHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkSubpassEndInfo*                     pSubpassEndInfo);
extern PFN_vkCmdEndRenderPass2KHR vkCmdEndRenderPass2KHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainStatusKHR(
//     VkDevice                                    device,
//     VkSwapchainKHR                              swapchain);
extern PFN_vkGetSwapchainStatusKHR vkGetSwapchainStatusKHR;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalFencePropertiesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
//     VkExternalFenceProperties*                  pExternalFenceProperties);
extern PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR vkGetPhysicalDeviceExternalFencePropertiesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkImportFenceFdKHR(
//     VkDevice                                    device,
//     const VkImportFenceFdInfoKHR*               pImportFenceFdInfo);
extern PFN_vkImportFenceFdKHR vkImportFenceFdKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceFdKHR(
//     VkDevice                                    device,
//     const VkFenceGetFdInfoKHR*                  pGetFdInfo,
//     int*                                        pFd);
extern PFN_vkGetFenceFdKHR vkGetFenceFdKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t                                    queueFamilyIndex,
//     uint32_t*                                   pCounterCount,
//     VkPerformanceCounterKHR*                    pCounters,
//     VkPerformanceCounterDescriptionKHR*         pCounterDescriptions);
extern PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     const VkQueryPoolPerformanceCreateInfoKHR*  pPerformanceQueryCreateInfo,
//     uint32_t*                                   pNumPasses);
extern PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkAcquireProfilingLockKHR(
//     VkDevice                                    device,
//     const VkAcquireProfilingLockInfoKHR*        pInfo);
extern PFN_vkAcquireProfilingLockKHR vkAcquireProfilingLockKHR;
// VKAPI_ATTR void VKAPI_CALL vkReleaseProfilingLockKHR(
//     VkDevice                                    device);
extern PFN_vkReleaseProfilingLockKHR vkReleaseProfilingLockKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilities2KHR(
//     VkPhysicalDevice                            physicalDevice,
//     const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
//     VkSurfaceCapabilities2KHR*                  pSurfaceCapabilities);
extern PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR vkGetPhysicalDeviceSurfaceCapabilities2KHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceFormats2KHR(
//     VkPhysicalDevice                            physicalDevice,
//     const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
//     uint32_t*                                   pSurfaceFormatCount,
//     VkSurfaceFormat2KHR*                        pSurfaceFormats);
extern PFN_vkGetPhysicalDeviceSurfaceFormats2KHR vkGetPhysicalDeviceSurfaceFormats2KHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayProperties2KHR(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pPropertyCount,
//     VkDisplayProperties2KHR*                    pProperties);
extern PFN_vkGetPhysicalDeviceDisplayProperties2KHR vkGetPhysicalDeviceDisplayProperties2KHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pPropertyCount,
//     VkDisplayPlaneProperties2KHR*               pProperties);
extern PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR vkGetPhysicalDeviceDisplayPlaneProperties2KHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayModeProperties2KHR(
//     VkPhysicalDevice                            physicalDevice,
//     VkDisplayKHR                                display,
//     uint32_t*                                   pPropertyCount,
//     VkDisplayModeProperties2KHR*                pProperties);
extern PFN_vkGetDisplayModeProperties2KHR vkGetDisplayModeProperties2KHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayPlaneCapabilities2KHR(
//     VkPhysicalDevice                            physicalDevice,
//     const VkDisplayPlaneInfo2KHR*               pDisplayPlaneInfo,
//     VkDisplayPlaneCapabilities2KHR*             pCapabilities);
extern PFN_vkGetDisplayPlaneCapabilities2KHR vkGetDisplayPlaneCapabilities2KHR;
// VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements2KHR(
//     VkDevice                                    device,
//     const VkImageMemoryRequirementsInfo2*       pInfo,
//     VkMemoryRequirements2*                      pMemoryRequirements);
extern PFN_vkGetImageMemoryRequirements2KHR vkGetImageMemoryRequirements2KHR;
// VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements2KHR(
//     VkDevice                                    device,
//     const VkBufferMemoryRequirementsInfo2*      pInfo,
//     VkMemoryRequirements2*                      pMemoryRequirements);
extern PFN_vkGetBufferMemoryRequirements2KHR vkGetBufferMemoryRequirements2KHR;
// VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements2KHR(
//     VkDevice                                    device,
//     const VkImageSparseMemoryRequirementsInfo2* pInfo,
//     uint32_t*                                   pSparseMemoryRequirementCount,
//     VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements);
extern PFN_vkGetImageSparseMemoryRequirements2KHR vkGetImageSparseMemoryRequirements2KHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateSamplerYcbcrConversionKHR(
//     VkDevice                                    device,
//     const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkSamplerYcbcrConversion*                   pYcbcrConversion);
extern PFN_vkCreateSamplerYcbcrConversionKHR vkCreateSamplerYcbcrConversionKHR;
// VKAPI_ATTR void VKAPI_CALL vkDestroySamplerYcbcrConversionKHR(
//     VkDevice                                    device,
//     VkSamplerYcbcrConversion                    ycbcrConversion,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroySamplerYcbcrConversionKHR vkDestroySamplerYcbcrConversionKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory2KHR(
//     VkDevice                                    device,
//     uint32_t                                    bindInfoCount,
//     const VkBindBufferMemoryInfo*               pBindInfos);
extern PFN_vkBindBufferMemory2KHR vkBindBufferMemory2KHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory2KHR(
//     VkDevice                                    device,
//     uint32_t                                    bindInfoCount,
//     const VkBindImageMemoryInfo*                pBindInfos);
extern PFN_vkBindImageMemory2KHR vkBindImageMemory2KHR;
// VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutSupportKHR(
//     VkDevice                                    device,
//     const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
//     VkDescriptorSetLayoutSupport*               pSupport);
extern PFN_vkGetDescriptorSetLayoutSupportKHR vkGetDescriptorSetLayoutSupportKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCountKHR(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset,
//     VkBuffer                                    countBuffer,
//     VkDeviceSize                                countBufferOffset,
//     uint32_t                                    maxDrawCount,
//     uint32_t                                    stride);
extern PFN_vkCmdDrawIndirectCountKHR vkCmdDrawIndirectCountKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCountKHR(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset,
//     VkBuffer                                    countBuffer,
//     VkDeviceSize                                countBufferOffset,
//     uint32_t                                    maxDrawCount,
//     uint32_t                                    stride);
extern PFN_vkCmdDrawIndexedIndirectCountKHR vkCmdDrawIndexedIndirectCountKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreCounterValueKHR(
//     VkDevice                                    device,
//     VkSemaphore                                 semaphore,
//     uint64_t*                                   pValue);
extern PFN_vkGetSemaphoreCounterValueKHR vkGetSemaphoreCounterValueKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkWaitSemaphoresKHR(
//     VkDevice                                    device,
//     const VkSemaphoreWaitInfo*                  pWaitInfo,
//     uint64_t                                    timeout);
extern PFN_vkWaitSemaphoresKHR vkWaitSemaphoresKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkSignalSemaphoreKHR(
//     VkDevice                                    device,
//     const VkSemaphoreSignalInfo*                pSignalInfo);
extern PFN_vkSignalSemaphoreKHR vkSignalSemaphoreKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceFragmentShadingRatesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pFragmentShadingRateCount,
//     VkPhysicalDeviceFragmentShadingRateKHR*     pFragmentShadingRates);
extern PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR vkGetPhysicalDeviceFragmentShadingRatesKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetFragmentShadingRateKHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkExtent2D*                           pFragmentSize,
//     const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]);
extern PFN_vkCmdSetFragmentShadingRateKHR vkCmdSetFragmentShadingRateKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingAttachmentLocationsKHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkRenderingAttachmentLocationInfoKHR* pLocationInfo);
extern PFN_vkCmdSetRenderingAttachmentLocationsKHR vkCmdSetRenderingAttachmentLocationsKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingInputAttachmentIndicesKHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkRenderingInputAttachmentIndexInfoKHR* pLocationInfo);
extern PFN_vkCmdSetRenderingInputAttachmentIndicesKHR vkCmdSetRenderingInputAttachmentIndicesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkWaitForPresentKHR(
//     VkDevice                                    device,
//     VkSwapchainKHR                              swapchain,
//     uint64_t                                    presentId,
//     uint64_t                                    timeout);
extern PFN_vkWaitForPresentKHR vkWaitForPresentKHR;
// VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddressKHR(
//     VkDevice                                    device,
//     const VkBufferDeviceAddressInfo*            pInfo);
extern PFN_vkGetBufferDeviceAddressKHR vkGetBufferDeviceAddressKHR;
// VKAPI_ATTR uint64_t VKAPI_CALL vkGetBufferOpaqueCaptureAddressKHR(
//     VkDevice                                    device,
//     const VkBufferDeviceAddressInfo*            pInfo);
extern PFN_vkGetBufferOpaqueCaptureAddressKHR vkGetBufferOpaqueCaptureAddressKHR;
// VKAPI_ATTR uint64_t VKAPI_CALL vkGetDeviceMemoryOpaqueCaptureAddressKHR(
//     VkDevice                                    device,
//     const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo);
extern PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR vkGetDeviceMemoryOpaqueCaptureAddressKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateDeferredOperationKHR(
//     VkDevice                                    device,
//     const VkAllocationCallbacks*                pAllocator,
//     VkDeferredOperationKHR*                     pDeferredOperation);
extern PFN_vkCreateDeferredOperationKHR vkCreateDeferredOperationKHR;
// VKAPI_ATTR void VKAPI_CALL vkDestroyDeferredOperationKHR(
//     VkDevice                                    device,
//     VkDeferredOperationKHR                      operation,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyDeferredOperationKHR vkDestroyDeferredOperationKHR;
// VKAPI_ATTR uint32_t VKAPI_CALL vkGetDeferredOperationMaxConcurrencyKHR(
//     VkDevice                                    device,
//     VkDeferredOperationKHR                      operation);
extern PFN_vkGetDeferredOperationMaxConcurrencyKHR vkGetDeferredOperationMaxConcurrencyKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetDeferredOperationResultKHR(
//     VkDevice                                    device,
//     VkDeferredOperationKHR                      operation);
extern PFN_vkGetDeferredOperationResultKHR vkGetDeferredOperationResultKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkDeferredOperationJoinKHR(
//     VkDevice                                    device,
//     VkDeferredOperationKHR                      operation);
extern PFN_vkDeferredOperationJoinKHR vkDeferredOperationJoinKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineExecutablePropertiesKHR(
//     VkDevice                                    device,
//     const VkPipelineInfoKHR*                    pPipelineInfo,
//     uint32_t*                                   pExecutableCount,
//     VkPipelineExecutablePropertiesKHR*          pProperties);
extern PFN_vkGetPipelineExecutablePropertiesKHR vkGetPipelineExecutablePropertiesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineExecutableStatisticsKHR(
//     VkDevice                                    device,
//     const VkPipelineExecutableInfoKHR*          pExecutableInfo,
//     uint32_t*                                   pStatisticCount,
//     VkPipelineExecutableStatisticKHR*           pStatistics);
extern PFN_vkGetPipelineExecutableStatisticsKHR vkGetPipelineExecutableStatisticsKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineExecutableInternalRepresentationsKHR(
//     VkDevice                                    device,
//     const VkPipelineExecutableInfoKHR*          pExecutableInfo,
//     uint32_t*                                   pInternalRepresentationCount,
//     VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations);
extern PFN_vkGetPipelineExecutableInternalRepresentationsKHR vkGetPipelineExecutableInternalRepresentationsKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkMapMemory2KHR(
//     VkDevice                                    device,
//     const VkMemoryMapInfoKHR*                   pMemoryMapInfo,
//     void**                                      ppData);
extern PFN_vkMapMemory2KHR vkMapMemory2KHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkUnmapMemory2KHR(
//     VkDevice                                    device,
//     const VkMemoryUnmapInfoKHR*                 pMemoryUnmapInfo);
extern PFN_vkUnmapMemory2KHR vkUnmapMemory2KHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* pQualityLevelInfo,
//     VkVideoEncodeQualityLevelPropertiesKHR*     pQualityLevelProperties);
extern PFN_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetEncodedVideoSessionParametersKHR(
//     VkDevice                                    device,
//     const VkVideoEncodeSessionParametersGetInfoKHR* pVideoSessionParametersInfo,
//     VkVideoEncodeSessionParametersFeedbackInfoKHR* pFeedbackInfo,
//     size_t*                                     pDataSize,
//     void*                                       pData);
extern PFN_vkGetEncodedVideoSessionParametersKHR vkGetEncodedVideoSessionParametersKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdEncodeVideoKHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkVideoEncodeInfoKHR*                 pEncodeInfo);
extern PFN_vkCmdEncodeVideoKHR vkCmdEncodeVideoKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetEvent2KHR(
//     VkCommandBuffer                             commandBuffer,
//     VkEvent                                     event,
//     const VkDependencyInfo*                     pDependencyInfo);
extern PFN_vkCmdSetEvent2KHR vkCmdSetEvent2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdResetEvent2KHR(
//     VkCommandBuffer                             commandBuffer,
//     VkEvent                                     event,
//     VkPipelineStageFlags2                       stageMask);
extern PFN_vkCmdResetEvent2KHR vkCmdResetEvent2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdWaitEvents2KHR(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    eventCount,
//     const VkEvent*                              pEvents,
//     const VkDependencyInfo*                     pDependencyInfos);
extern PFN_vkCmdWaitEvents2KHR vkCmdWaitEvents2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier2KHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkDependencyInfo*                     pDependencyInfo);
extern PFN_vkCmdPipelineBarrier2KHR vkCmdPipelineBarrier2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdWriteTimestamp2KHR(
//     VkCommandBuffer                             commandBuffer,
//     VkPipelineStageFlags2                       stage,
//     VkQueryPool                                 queryPool,
//     uint32_t                                    query);
extern PFN_vkCmdWriteTimestamp2KHR vkCmdWriteTimestamp2KHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit2KHR(
//     VkQueue                                     queue,
//     uint32_t                                    submitCount,
//     const VkSubmitInfo2*                        pSubmits,
//     VkFence                                     fence);
extern PFN_vkQueueSubmit2KHR vkQueueSubmit2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdWriteBufferMarker2AMD(
//     VkCommandBuffer                             commandBuffer,
//     VkPipelineStageFlags2                       stage,
//     VkBuffer                                    dstBuffer,
//     VkDeviceSize                                dstOffset,
//     uint32_t                                    marker);
extern PFN_vkCmdWriteBufferMarker2AMD vkCmdWriteBufferMarker2AMD;
// VKAPI_ATTR void VKAPI_CALL vkGetQueueCheckpointData2NV(
//     VkQueue                                     queue,
//     uint32_t*                                   pCheckpointDataCount,
//     VkCheckpointData2NV*                        pCheckpointData);
extern PFN_vkGetQueueCheckpointData2NV vkGetQueueCheckpointData2NV;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyBuffer2KHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkCopyBufferInfo2*                    pCopyBufferInfo);
extern PFN_vkCmdCopyBuffer2KHR vkCmdCopyBuffer2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyImage2KHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkCopyImageInfo2*                     pCopyImageInfo);
extern PFN_vkCmdCopyImage2KHR vkCmdCopyImage2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyBufferToImage2KHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo);
extern PFN_vkCmdCopyBufferToImage2KHR vkCmdCopyBufferToImage2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToBuffer2KHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo);
extern PFN_vkCmdCopyImageToBuffer2KHR vkCmdCopyImageToBuffer2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdBlitImage2KHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkBlitImageInfo2*                     pBlitImageInfo);
extern PFN_vkCmdBlitImage2KHR vkCmdBlitImage2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage2KHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkResolveImageInfo2*                  pResolveImageInfo);
extern PFN_vkCmdResolveImage2KHR vkCmdResolveImage2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysIndirect2KHR(
//     VkCommandBuffer                             commandBuffer,
//     VkDeviceAddress                             indirectDeviceAddress);
extern PFN_vkCmdTraceRaysIndirect2KHR vkCmdTraceRaysIndirect2KHR;
// VKAPI_ATTR void VKAPI_CALL vkGetDeviceBufferMemoryRequirementsKHR(
//     VkDevice                                    device,
//     const VkDeviceBufferMemoryRequirements*     pInfo,
//     VkMemoryRequirements2*                      pMemoryRequirements);
extern PFN_vkGetDeviceBufferMemoryRequirementsKHR vkGetDeviceBufferMemoryRequirementsKHR;
// VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageMemoryRequirementsKHR(
//     VkDevice                                    device,
//     const VkDeviceImageMemoryRequirements*      pInfo,
//     VkMemoryRequirements2*                      pMemoryRequirements);
extern PFN_vkGetDeviceImageMemoryRequirementsKHR vkGetDeviceImageMemoryRequirementsKHR;
// VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSparseMemoryRequirementsKHR(
//     VkDevice                                    device,
//     const VkDeviceImageMemoryRequirements*      pInfo,
//     uint32_t*                                   pSparseMemoryRequirementCount,
//     VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements);
extern PFN_vkGetDeviceImageSparseMemoryRequirementsKHR vkGetDeviceImageSparseMemoryRequirementsKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindIndexBuffer2KHR(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset,
//     VkDeviceSize                                size,
//     VkIndexType                                 indexType);
extern PFN_vkCmdBindIndexBuffer2KHR vkCmdBindIndexBuffer2KHR;
// VKAPI_ATTR void VKAPI_CALL vkGetRenderingAreaGranularityKHR(
//     VkDevice                                    device,
//     const VkRenderingAreaInfoKHR*               pRenderingAreaInfo,
//     VkExtent2D*                                 pGranularity);
extern PFN_vkGetRenderingAreaGranularityKHR vkGetRenderingAreaGranularityKHR;
// VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSubresourceLayoutKHR(
//     VkDevice                                    device,
//     const VkDeviceImageSubresourceInfoKHR*      pInfo,
//     VkSubresourceLayout2KHR*                    pLayout);
extern PFN_vkGetDeviceImageSubresourceLayoutKHR vkGetDeviceImageSubresourceLayoutKHR;
// VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout2KHR(
//     VkDevice                                    device,
//     VkImage                                     image,
//     const VkImageSubresource2KHR*               pSubresource,
//     VkSubresourceLayout2KHR*                    pLayout);
extern PFN_vkGetImageSubresourceLayout2KHR vkGetImageSubresourceLayout2KHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pPropertyCount,
//     VkCooperativeMatrixPropertiesKHR*           pProperties);
extern PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStippleKHR(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    lineStippleFactor,
//     uint16_t                                    lineStipplePattern);
extern PFN_vkCmdSetLineStippleKHR vkCmdSetLineStippleKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pTimeDomainCount,
//     VkTimeDomainKHR*                            pTimeDomains);
extern PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR vkGetPhysicalDeviceCalibrateableTimeDomainsKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetCalibratedTimestampsKHR(
//     VkDevice                                    device,
//     uint32_t                                    timestampCount,
//     const VkCalibratedTimestampInfoKHR*         pTimestampInfos,
//     uint64_t*                                   pTimestamps,
//     uint64_t*                                   pMaxDeviation);
extern PFN_vkGetCalibratedTimestampsKHR vkGetCalibratedTimestampsKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorSets2KHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkBindDescriptorSetsInfoKHR*          pBindDescriptorSetsInfo);
extern PFN_vkCmdBindDescriptorSets2KHR vkCmdBindDescriptorSets2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdPushConstants2KHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkPushConstantsInfoKHR*               pPushConstantsInfo);
extern PFN_vkCmdPushConstants2KHR vkCmdPushConstants2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSet2KHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkPushDescriptorSetInfoKHR*           pPushDescriptorSetInfo);
extern PFN_vkCmdPushDescriptorSet2KHR vkCmdPushDescriptorSet2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate2KHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo);
extern PFN_vkCmdPushDescriptorSetWithTemplate2KHR vkCmdPushDescriptorSetWithTemplate2KHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDescriptorBufferOffsets2EXT(
//     VkCommandBuffer                             commandBuffer,
//     const VkSetDescriptorBufferOffsetsInfoEXT*  pSetDescriptorBufferOffsetsInfo);
extern PFN_vkCmdSetDescriptorBufferOffsets2EXT vkCmdSetDescriptorBufferOffsets2EXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
//     VkCommandBuffer                             commandBuffer,
//     const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo);
extern PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT vkCmdBindDescriptorBufferEmbeddedSamplers2EXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugReportCallbackEXT(
//     VkInstance                                  instance,
//     const VkDebugReportCallbackCreateInfoEXT*   pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkDebugReportCallbackEXT*                   pCallback);
extern PFN_vkCreateDebugReportCallbackEXT vkCreateDebugReportCallbackEXT;
// VKAPI_ATTR void VKAPI_CALL vkDestroyDebugReportCallbackEXT(
//     VkInstance                                  instance,
//     VkDebugReportCallbackEXT                    callback,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyDebugReportCallbackEXT vkDestroyDebugReportCallbackEXT;
// VKAPI_ATTR void VKAPI_CALL vkDebugReportMessageEXT(
//     VkInstance                                  instance,
//     VkDebugReportFlagsEXT                       flags,
//     VkDebugReportObjectTypeEXT                  objectType,
//     uint64_t                                    object,
//     size_t                                      location,
//     int32_t                                     messageCode,
//     const char*                                 pLayerPrefix,
//     const char*                                 pMessage);
extern PFN_vkDebugReportMessageEXT vkDebugReportMessageEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkDebugMarkerSetObjectTagEXT(
//     VkDevice                                    device,
//     const VkDebugMarkerObjectTagInfoEXT*        pTagInfo);
extern PFN_vkDebugMarkerSetObjectTagEXT vkDebugMarkerSetObjectTagEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkDebugMarkerSetObjectNameEXT(
//     VkDevice                                    device,
//     const VkDebugMarkerObjectNameInfoEXT*       pNameInfo);
extern PFN_vkDebugMarkerSetObjectNameEXT vkDebugMarkerSetObjectNameEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerBeginEXT(
//     VkCommandBuffer                             commandBuffer,
//     const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo);
extern PFN_vkCmdDebugMarkerBeginEXT vkCmdDebugMarkerBeginEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerEndEXT(
//     VkCommandBuffer                             commandBuffer);
extern PFN_vkCmdDebugMarkerEndEXT vkCmdDebugMarkerEndEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerInsertEXT(
//     VkCommandBuffer                             commandBuffer,
//     const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo);
extern PFN_vkCmdDebugMarkerInsertEXT vkCmdDebugMarkerInsertEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindTransformFeedbackBuffersEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstBinding,
//     uint32_t                                    bindingCount,
//     const VkBuffer*                             pBuffers,
//     const VkDeviceSize*                         pOffsets,
//     const VkDeviceSize*                         pSizes);
extern PFN_vkCmdBindTransformFeedbackBuffersEXT vkCmdBindTransformFeedbackBuffersEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdBeginTransformFeedbackEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstCounterBuffer,
//     uint32_t                                    counterBufferCount,
//     const VkBuffer*                             pCounterBuffers,
//     const VkDeviceSize*                         pCounterBufferOffsets);
extern PFN_vkCmdBeginTransformFeedbackEXT vkCmdBeginTransformFeedbackEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdEndTransformFeedbackEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstCounterBuffer,
//     uint32_t                                    counterBufferCount,
//     const VkBuffer*                             pCounterBuffers,
//     const VkDeviceSize*                         pCounterBufferOffsets);
extern PFN_vkCmdEndTransformFeedbackEXT vkCmdEndTransformFeedbackEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdBeginQueryIndexedEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkQueryPool                                 queryPool,
//     uint32_t                                    query,
//     VkQueryControlFlags                         flags,
//     uint32_t                                    index);
extern PFN_vkCmdBeginQueryIndexedEXT vkCmdBeginQueryIndexedEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdEndQueryIndexedEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkQueryPool                                 queryPool,
//     uint32_t                                    query,
//     uint32_t                                    index);
extern PFN_vkCmdEndQueryIndexedEXT vkCmdEndQueryIndexedEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectByteCountEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    instanceCount,
//     uint32_t                                    firstInstance,
//     VkBuffer                                    counterBuffer,
//     VkDeviceSize                                counterBufferOffset,
//     uint32_t                                    counterOffset,
//     uint32_t                                    vertexStride);
extern PFN_vkCmdDrawIndirectByteCountEXT vkCmdDrawIndirectByteCountEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateCuModuleNVX(
//     VkDevice                                    device,
//     const VkCuModuleCreateInfoNVX*              pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkCuModuleNVX*                              pModule);
extern PFN_vkCreateCuModuleNVX vkCreateCuModuleNVX;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateCuFunctionNVX(
//     VkDevice                                    device,
//     const VkCuFunctionCreateInfoNVX*            pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkCuFunctionNVX*                            pFunction);
extern PFN_vkCreateCuFunctionNVX vkCreateCuFunctionNVX;
// VKAPI_ATTR void VKAPI_CALL vkDestroyCuModuleNVX(
//     VkDevice                                    device,
//     VkCuModuleNVX                               module,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyCuModuleNVX vkDestroyCuModuleNVX;
// VKAPI_ATTR void VKAPI_CALL vkDestroyCuFunctionNVX(
//     VkDevice                                    device,
//     VkCuFunctionNVX                             function,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyCuFunctionNVX vkDestroyCuFunctionNVX;
// VKAPI_ATTR void VKAPI_CALL vkCmdCuLaunchKernelNVX(
//     VkCommandBuffer                             commandBuffer,
//     const VkCuLaunchInfoNVX*                    pLaunchInfo);
extern PFN_vkCmdCuLaunchKernelNVX vkCmdCuLaunchKernelNVX;
// VKAPI_ATTR uint32_t VKAPI_CALL vkGetImageViewHandleNVX(
//     VkDevice                                    device,
//     const VkImageViewHandleInfoNVX*             pInfo);
extern PFN_vkGetImageViewHandleNVX vkGetImageViewHandleNVX;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetImageViewAddressNVX(
//     VkDevice                                    device,
//     VkImageView                                 imageView,
//     VkImageViewAddressPropertiesNVX*            pProperties);
extern PFN_vkGetImageViewAddressNVX vkGetImageViewAddressNVX;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCountAMD(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset,
//     VkBuffer                                    countBuffer,
//     VkDeviceSize                                countBufferOffset,
//     uint32_t                                    maxDrawCount,
//     uint32_t                                    stride);
extern PFN_vkCmdDrawIndirectCountAMD vkCmdDrawIndirectCountAMD;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCountAMD(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset,
//     VkBuffer                                    countBuffer,
//     VkDeviceSize                                countBufferOffset,
//     uint32_t                                    maxDrawCount,
//     uint32_t                                    stride);
extern PFN_vkCmdDrawIndexedIndirectCountAMD vkCmdDrawIndexedIndirectCountAMD;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetShaderInfoAMD(
//     VkDevice                                    device,
//     VkPipeline                                  pipeline,
//     VkShaderStageFlagBits                       shaderStage,
//     VkShaderInfoTypeAMD                         infoType,
//     size_t*                                     pInfoSize,
//     void*                                       pInfo);
extern PFN_vkGetShaderInfoAMD vkGetShaderInfoAMD;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
//     VkPhysicalDevice                            physicalDevice,
//     VkFormat                                    format,
//     VkImageType                                 type,
//     VkImageTiling                               tiling,
//     VkImageUsageFlags                           usage,
//     VkImageCreateFlags                          flags,
//     VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
//     VkExternalImageFormatPropertiesNV*          pExternalImageFormatProperties);
extern PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV vkGetPhysicalDeviceExternalImageFormatPropertiesNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdBeginConditionalRenderingEXT(
//     VkCommandBuffer                             commandBuffer,
//     const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin);
extern PFN_vkCmdBeginConditionalRenderingEXT vkCmdBeginConditionalRenderingEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdEndConditionalRenderingEXT(
//     VkCommandBuffer                             commandBuffer);
extern PFN_vkCmdEndConditionalRenderingEXT vkCmdEndConditionalRenderingEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWScalingNV(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstViewport,
//     uint32_t                                    viewportCount,
//     const VkViewportWScalingNV*                 pViewportWScalings);
extern PFN_vkCmdSetViewportWScalingNV vkCmdSetViewportWScalingNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkReleaseDisplayEXT(
//     VkPhysicalDevice                            physicalDevice,
//     VkDisplayKHR                                display);
extern PFN_vkReleaseDisplayEXT vkReleaseDisplayEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilities2EXT(
//     VkPhysicalDevice                            physicalDevice,
//     VkSurfaceKHR                                surface,
//     VkSurfaceCapabilities2EXT*                  pSurfaceCapabilities);
extern PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT vkGetPhysicalDeviceSurfaceCapabilities2EXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkDisplayPowerControlEXT(
//     VkDevice                                    device,
//     VkDisplayKHR                                display,
//     const VkDisplayPowerInfoEXT*                pDisplayPowerInfo);
extern PFN_vkDisplayPowerControlEXT vkDisplayPowerControlEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkRegisterDeviceEventEXT(
//     VkDevice                                    device,
//     const VkDeviceEventInfoEXT*                 pDeviceEventInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkFence*                                    pFence);
extern PFN_vkRegisterDeviceEventEXT vkRegisterDeviceEventEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkRegisterDisplayEventEXT(
//     VkDevice                                    device,
//     VkDisplayKHR                                display,
//     const VkDisplayEventInfoEXT*                pDisplayEventInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkFence*                                    pFence);
extern PFN_vkRegisterDisplayEventEXT vkRegisterDisplayEventEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainCounterEXT(
//     VkDevice                                    device,
//     VkSwapchainKHR                              swapchain,
//     VkSurfaceCounterFlagBitsEXT                 counter,
//     uint64_t*                                   pCounterValue);
extern PFN_vkGetSwapchainCounterEXT vkGetSwapchainCounterEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetRefreshCycleDurationGOOGLE(
//     VkDevice                                    device,
//     VkSwapchainKHR                              swapchain,
//     VkRefreshCycleDurationGOOGLE*               pDisplayTimingProperties);
extern PFN_vkGetRefreshCycleDurationGOOGLE vkGetRefreshCycleDurationGOOGLE;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPastPresentationTimingGOOGLE(
//     VkDevice                                    device,
//     VkSwapchainKHR                              swapchain,
//     uint32_t*                                   pPresentationTimingCount,
//     VkPastPresentationTimingGOOGLE*             pPresentationTimings);
extern PFN_vkGetPastPresentationTimingGOOGLE vkGetPastPresentationTimingGOOGLE;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDiscardRectangleEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstDiscardRectangle,
//     uint32_t                                    discardRectangleCount,
//     const VkRect2D*                             pDiscardRectangles);
extern PFN_vkCmdSetDiscardRectangleEXT vkCmdSetDiscardRectangleEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDiscardRectangleEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    discardRectangleEnable);
extern PFN_vkCmdSetDiscardRectangleEnableEXT vkCmdSetDiscardRectangleEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDiscardRectangleModeEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkDiscardRectangleModeEXT                   discardRectangleMode);
extern PFN_vkCmdSetDiscardRectangleModeEXT vkCmdSetDiscardRectangleModeEXT;
// VKAPI_ATTR void VKAPI_CALL vkSetHdrMetadataEXT(
//     VkDevice                                    device,
//     uint32_t                                    swapchainCount,
//     const VkSwapchainKHR*                       pSwapchains,
//     const VkHdrMetadataEXT*                     pMetadata);
extern PFN_vkSetHdrMetadataEXT vkSetHdrMetadataEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkSetDebugUtilsObjectNameEXT(
//     VkDevice                                    device,
//     const VkDebugUtilsObjectNameInfoEXT*        pNameInfo);
extern PFN_vkSetDebugUtilsObjectNameEXT vkSetDebugUtilsObjectNameEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkSetDebugUtilsObjectTagEXT(
//     VkDevice                                    device,
//     const VkDebugUtilsObjectTagInfoEXT*         pTagInfo);
extern PFN_vkSetDebugUtilsObjectTagEXT vkSetDebugUtilsObjectTagEXT;
// VKAPI_ATTR void VKAPI_CALL vkQueueBeginDebugUtilsLabelEXT(
//     VkQueue                                     queue,
//     const VkDebugUtilsLabelEXT*                 pLabelInfo);
extern PFN_vkQueueBeginDebugUtilsLabelEXT vkQueueBeginDebugUtilsLabelEXT;
// VKAPI_ATTR void VKAPI_CALL vkQueueEndDebugUtilsLabelEXT(
//     VkQueue                                     queue);
extern PFN_vkQueueEndDebugUtilsLabelEXT vkQueueEndDebugUtilsLabelEXT;
// VKAPI_ATTR void VKAPI_CALL vkQueueInsertDebugUtilsLabelEXT(
//     VkQueue                                     queue,
//     const VkDebugUtilsLabelEXT*                 pLabelInfo);
extern PFN_vkQueueInsertDebugUtilsLabelEXT vkQueueInsertDebugUtilsLabelEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdBeginDebugUtilsLabelEXT(
//     VkCommandBuffer                             commandBuffer,
//     const VkDebugUtilsLabelEXT*                 pLabelInfo);
extern PFN_vkCmdBeginDebugUtilsLabelEXT vkCmdBeginDebugUtilsLabelEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdEndDebugUtilsLabelEXT(
//     VkCommandBuffer                             commandBuffer);
extern PFN_vkCmdEndDebugUtilsLabelEXT vkCmdEndDebugUtilsLabelEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdInsertDebugUtilsLabelEXT(
//     VkCommandBuffer                             commandBuffer,
//     const VkDebugUtilsLabelEXT*                 pLabelInfo);
extern PFN_vkCmdInsertDebugUtilsLabelEXT vkCmdInsertDebugUtilsLabelEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugUtilsMessengerEXT(
//     VkInstance                                  instance,
//     const VkDebugUtilsMessengerCreateInfoEXT*   pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkDebugUtilsMessengerEXT*                   pMessenger);
extern PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessengerEXT;
// VKAPI_ATTR void VKAPI_CALL vkDestroyDebugUtilsMessengerEXT(
//     VkInstance                                  instance,
//     VkDebugUtilsMessengerEXT                    messenger,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyDebugUtilsMessengerEXT vkDestroyDebugUtilsMessengerEXT;
// VKAPI_ATTR void VKAPI_CALL vkSubmitDebugUtilsMessageEXT(
//     VkInstance                                  instance,
//     VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
//     VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
//     const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData);
extern PFN_vkSubmitDebugUtilsMessageEXT vkSubmitDebugUtilsMessageEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetSampleLocationsEXT(
//     VkCommandBuffer                             commandBuffer,
//     const VkSampleLocationsInfoEXT*             pSampleLocationsInfo);
extern PFN_vkCmdSetSampleLocationsEXT vkCmdSetSampleLocationsEXT;
// VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMultisamplePropertiesEXT(
//     VkPhysicalDevice                            physicalDevice,
//     VkSampleCountFlagBits                       samples,
//     VkMultisamplePropertiesEXT*                 pMultisampleProperties);
extern PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT vkGetPhysicalDeviceMultisamplePropertiesEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetImageDrmFormatModifierPropertiesEXT(
//     VkDevice                                    device,
//     VkImage                                     image,
//     VkImageDrmFormatModifierPropertiesEXT*      pProperties);
extern PFN_vkGetImageDrmFormatModifierPropertiesEXT vkGetImageDrmFormatModifierPropertiesEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateValidationCacheEXT(
//     VkDevice                                    device,
//     const VkValidationCacheCreateInfoEXT*       pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkValidationCacheEXT*                       pValidationCache);
extern PFN_vkCreateValidationCacheEXT vkCreateValidationCacheEXT;
// VKAPI_ATTR void VKAPI_CALL vkDestroyValidationCacheEXT(
//     VkDevice                                    device,
//     VkValidationCacheEXT                        validationCache,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyValidationCacheEXT vkDestroyValidationCacheEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkMergeValidationCachesEXT(
//     VkDevice                                    device,
//     VkValidationCacheEXT                        dstCache,
//     uint32_t                                    srcCacheCount,
//     const VkValidationCacheEXT*                 pSrcCaches);
extern PFN_vkMergeValidationCachesEXT vkMergeValidationCachesEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetValidationCacheDataEXT(
//     VkDevice                                    device,
//     VkValidationCacheEXT                        validationCache,
//     size_t*                                     pDataSize,
//     void*                                       pData);
extern PFN_vkGetValidationCacheDataEXT vkGetValidationCacheDataEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindShadingRateImageNV(
//     VkCommandBuffer                             commandBuffer,
//     VkImageView                                 imageView,
//     VkImageLayout                               imageLayout);
extern PFN_vkCmdBindShadingRateImageNV vkCmdBindShadingRateImageNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportShadingRatePaletteNV(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstViewport,
//     uint32_t                                    viewportCount,
//     const VkShadingRatePaletteNV*               pShadingRatePalettes);
extern PFN_vkCmdSetViewportShadingRatePaletteNV vkCmdSetViewportShadingRatePaletteNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetCoarseSampleOrderNV(
//     VkCommandBuffer                             commandBuffer,
//     VkCoarseSampleOrderTypeNV                   sampleOrderType,
//     uint32_t                                    customSampleOrderCount,
//     const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders);
extern PFN_vkCmdSetCoarseSampleOrderNV vkCmdSetCoarseSampleOrderNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateAccelerationStructureNV(
//     VkDevice                                    device,
//     const VkAccelerationStructureCreateInfoNV*  pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkAccelerationStructureNV*                  pAccelerationStructure);
extern PFN_vkCreateAccelerationStructureNV vkCreateAccelerationStructureNV;
// VKAPI_ATTR void VKAPI_CALL vkDestroyAccelerationStructureNV(
//     VkDevice                                    device,
//     VkAccelerationStructureNV                   accelerationStructure,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyAccelerationStructureNV vkDestroyAccelerationStructureNV;
// VKAPI_ATTR void VKAPI_CALL vkGetAccelerationStructureMemoryRequirementsNV(
//     VkDevice                                    device,
//     const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo,
//     VkMemoryRequirements2KHR*                   pMemoryRequirements);
extern PFN_vkGetAccelerationStructureMemoryRequirementsNV vkGetAccelerationStructureMemoryRequirementsNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkBindAccelerationStructureMemoryNV(
//     VkDevice                                    device,
//     uint32_t                                    bindInfoCount,
//     const VkBindAccelerationStructureMemoryInfoNV* pBindInfos);
extern PFN_vkBindAccelerationStructureMemoryNV vkBindAccelerationStructureMemoryNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdBuildAccelerationStructureNV(
//     VkCommandBuffer                             commandBuffer,
//     const VkAccelerationStructureInfoNV*        pInfo,
//     VkBuffer                                    instanceData,
//     VkDeviceSize                                instanceOffset,
//     VkBool32                                    update,
//     VkAccelerationStructureNV                   dst,
//     VkAccelerationStructureNV                   src,
//     VkBuffer                                    scratch,
//     VkDeviceSize                                scratchOffset);
extern PFN_vkCmdBuildAccelerationStructureNV vkCmdBuildAccelerationStructureNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyAccelerationStructureNV(
//     VkCommandBuffer                             commandBuffer,
//     VkAccelerationStructureNV                   dst,
//     VkAccelerationStructureNV                   src,
//     VkCopyAccelerationStructureModeKHR          mode);
extern PFN_vkCmdCopyAccelerationStructureNV vkCmdCopyAccelerationStructureNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysNV(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    raygenShaderBindingTableBuffer,
//     VkDeviceSize                                raygenShaderBindingOffset,
//     VkBuffer                                    missShaderBindingTableBuffer,
//     VkDeviceSize                                missShaderBindingOffset,
//     VkDeviceSize                                missShaderBindingStride,
//     VkBuffer                                    hitShaderBindingTableBuffer,
//     VkDeviceSize                                hitShaderBindingOffset,
//     VkDeviceSize                                hitShaderBindingStride,
//     VkBuffer                                    callableShaderBindingTableBuffer,
//     VkDeviceSize                                callableShaderBindingOffset,
//     VkDeviceSize                                callableShaderBindingStride,
//     uint32_t                                    width,
//     uint32_t                                    height,
//     uint32_t                                    depth);
extern PFN_vkCmdTraceRaysNV vkCmdTraceRaysNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateRayTracingPipelinesNV(
//     VkDevice                                    device,
//     VkPipelineCache                             pipelineCache,
//     uint32_t                                    createInfoCount,
//     const VkRayTracingPipelineCreateInfoNV*     pCreateInfos,
//     const VkAllocationCallbacks*                pAllocator,
//     VkPipeline*                                 pPipelines);
extern PFN_vkCreateRayTracingPipelinesNV vkCreateRayTracingPipelinesNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetRayTracingShaderGroupHandlesKHR(
//     VkDevice                                    device,
//     VkPipeline                                  pipeline,
//     uint32_t                                    firstGroup,
//     uint32_t                                    groupCount,
//     size_t                                      dataSize,
//     void*                                       pData);
extern PFN_vkGetRayTracingShaderGroupHandlesKHR vkGetRayTracingShaderGroupHandlesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetRayTracingShaderGroupHandlesNV(
//     VkDevice                                    device,
//     VkPipeline                                  pipeline,
//     uint32_t                                    firstGroup,
//     uint32_t                                    groupCount,
//     size_t                                      dataSize,
//     void*                                       pData);
extern PFN_vkGetRayTracingShaderGroupHandlesNV vkGetRayTracingShaderGroupHandlesNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetAccelerationStructureHandleNV(
//     VkDevice                                    device,
//     VkAccelerationStructureNV                   accelerationStructure,
//     size_t                                      dataSize,
//     void*                                       pData);
extern PFN_vkGetAccelerationStructureHandleNV vkGetAccelerationStructureHandleNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdWriteAccelerationStructuresPropertiesNV(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    accelerationStructureCount,
//     const VkAccelerationStructureNV*            pAccelerationStructures,
//     VkQueryType                                 queryType,
//     VkQueryPool                                 queryPool,
//     uint32_t                                    firstQuery);
extern PFN_vkCmdWriteAccelerationStructuresPropertiesNV vkCmdWriteAccelerationStructuresPropertiesNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkCompileDeferredNV(
//     VkDevice                                    device,
//     VkPipeline                                  pipeline,
//     uint32_t                                    shader);
extern PFN_vkCompileDeferredNV vkCompileDeferredNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryHostPointerPropertiesEXT(
//     VkDevice                                    device,
//     VkExternalMemoryHandleTypeFlagBits          handleType,
//     const void*                                 pHostPointer,
//     VkMemoryHostPointerPropertiesEXT*           pMemoryHostPointerProperties);
extern PFN_vkGetMemoryHostPointerPropertiesEXT vkGetMemoryHostPointerPropertiesEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdWriteBufferMarkerAMD(
//     VkCommandBuffer                             commandBuffer,
//     VkPipelineStageFlagBits                     pipelineStage,
//     VkBuffer                                    dstBuffer,
//     VkDeviceSize                                dstOffset,
//     uint32_t                                    marker);
extern PFN_vkCmdWriteBufferMarkerAMD vkCmdWriteBufferMarkerAMD;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pTimeDomainCount,
//     VkTimeDomainKHR*                            pTimeDomains);
extern PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT vkGetPhysicalDeviceCalibrateableTimeDomainsEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetCalibratedTimestampsEXT(
//     VkDevice                                    device,
//     uint32_t                                    timestampCount,
//     const VkCalibratedTimestampInfoKHR*         pTimestampInfos,
//     uint64_t*                                   pTimestamps,
//     uint64_t*                                   pMaxDeviation);
extern PFN_vkGetCalibratedTimestampsEXT vkGetCalibratedTimestampsEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksNV(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    taskCount,
//     uint32_t                                    firstTask);
extern PFN_vkCmdDrawMeshTasksNV vkCmdDrawMeshTasksNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectNV(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset,
//     uint32_t                                    drawCount,
//     uint32_t                                    stride);
extern PFN_vkCmdDrawMeshTasksIndirectNV vkCmdDrawMeshTasksIndirectNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectCountNV(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset,
//     VkBuffer                                    countBuffer,
//     VkDeviceSize                                countBufferOffset,
//     uint32_t                                    maxDrawCount,
//     uint32_t                                    stride);
extern PFN_vkCmdDrawMeshTasksIndirectCountNV vkCmdDrawMeshTasksIndirectCountNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetExclusiveScissorEnableNV(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstExclusiveScissor,
//     uint32_t                                    exclusiveScissorCount,
//     const VkBool32*                             pExclusiveScissorEnables);
extern PFN_vkCmdSetExclusiveScissorEnableNV vkCmdSetExclusiveScissorEnableNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetExclusiveScissorNV(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstExclusiveScissor,
//     uint32_t                                    exclusiveScissorCount,
//     const VkRect2D*                             pExclusiveScissors);
extern PFN_vkCmdSetExclusiveScissorNV vkCmdSetExclusiveScissorNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetCheckpointNV(
//     VkCommandBuffer                             commandBuffer,
//     const void*                                 pCheckpointMarker);
extern PFN_vkCmdSetCheckpointNV vkCmdSetCheckpointNV;
// VKAPI_ATTR void VKAPI_CALL vkGetQueueCheckpointDataNV(
//     VkQueue                                     queue,
//     uint32_t*                                   pCheckpointDataCount,
//     VkCheckpointDataNV*                         pCheckpointData);
extern PFN_vkGetQueueCheckpointDataNV vkGetQueueCheckpointDataNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkInitializePerformanceApiINTEL(
//     VkDevice                                    device,
//     const VkInitializePerformanceApiInfoINTEL*  pInitializeInfo);
extern PFN_vkInitializePerformanceApiINTEL vkInitializePerformanceApiINTEL;
// VKAPI_ATTR void VKAPI_CALL vkUninitializePerformanceApiINTEL(
//     VkDevice                                    device);
extern PFN_vkUninitializePerformanceApiINTEL vkUninitializePerformanceApiINTEL;
// VKAPI_ATTR VkResult VKAPI_CALL vkCmdSetPerformanceMarkerINTEL(
//     VkCommandBuffer                             commandBuffer,
//     const VkPerformanceMarkerInfoINTEL*         pMarkerInfo);
extern PFN_vkCmdSetPerformanceMarkerINTEL vkCmdSetPerformanceMarkerINTEL;
// VKAPI_ATTR VkResult VKAPI_CALL vkCmdSetPerformanceStreamMarkerINTEL(
//     VkCommandBuffer                             commandBuffer,
//     const VkPerformanceStreamMarkerInfoINTEL*   pMarkerInfo);
extern PFN_vkCmdSetPerformanceStreamMarkerINTEL vkCmdSetPerformanceStreamMarkerINTEL;
// VKAPI_ATTR VkResult VKAPI_CALL vkCmdSetPerformanceOverrideINTEL(
//     VkCommandBuffer                             commandBuffer,
//     const VkPerformanceOverrideInfoINTEL*       pOverrideInfo);
extern PFN_vkCmdSetPerformanceOverrideINTEL vkCmdSetPerformanceOverrideINTEL;
// VKAPI_ATTR VkResult VKAPI_CALL vkAcquirePerformanceConfigurationINTEL(
//     VkDevice                                    device,
//     const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo,
//     VkPerformanceConfigurationINTEL*            pConfiguration);
extern PFN_vkAcquirePerformanceConfigurationINTEL vkAcquirePerformanceConfigurationINTEL;
// VKAPI_ATTR VkResult VKAPI_CALL vkReleasePerformanceConfigurationINTEL(
//     VkDevice                                    device,
//     VkPerformanceConfigurationINTEL             configuration);
extern PFN_vkReleasePerformanceConfigurationINTEL vkReleasePerformanceConfigurationINTEL;
// VKAPI_ATTR VkResult VKAPI_CALL vkQueueSetPerformanceConfigurationINTEL(
//     VkQueue                                     queue,
//     VkPerformanceConfigurationINTEL             configuration);
extern PFN_vkQueueSetPerformanceConfigurationINTEL vkQueueSetPerformanceConfigurationINTEL;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPerformanceParameterINTEL(
//     VkDevice                                    device,
//     VkPerformanceParameterTypeINTEL             parameter,
//     VkPerformanceValueINTEL*                    pValue);
extern PFN_vkGetPerformanceParameterINTEL vkGetPerformanceParameterINTEL;
// VKAPI_ATTR void VKAPI_CALL vkSetLocalDimmingAMD(
//     VkDevice                                    device,
//     VkSwapchainKHR                              swapChain,
//     VkBool32                                    localDimmingEnable);
extern PFN_vkSetLocalDimmingAMD vkSetLocalDimmingAMD;
// VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddressEXT(
//     VkDevice                                    device,
//     const VkBufferDeviceAddressInfo*            pInfo);
extern PFN_vkGetBufferDeviceAddressEXT vkGetBufferDeviceAddressEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceToolPropertiesEXT(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pToolCount,
//     VkPhysicalDeviceToolProperties*             pToolProperties);
extern PFN_vkGetPhysicalDeviceToolPropertiesEXT vkGetPhysicalDeviceToolPropertiesEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pPropertyCount,
//     VkCooperativeMatrixPropertiesNV*            pProperties);
extern PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV vkGetPhysicalDeviceCooperativeMatrixPropertiesNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
//     VkPhysicalDevice                            physicalDevice,
//     uint32_t*                                   pCombinationCount,
//     VkFramebufferMixedSamplesCombinationNV*     pCombinations);
extern PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateHeadlessSurfaceEXT(
//     VkInstance                                  instance,
//     const VkHeadlessSurfaceCreateInfoEXT*       pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkSurfaceKHR*                               pSurface);
extern PFN_vkCreateHeadlessSurfaceEXT vkCreateHeadlessSurfaceEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStippleEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    lineStippleFactor,
//     uint16_t                                    lineStipplePattern);
extern PFN_vkCmdSetLineStippleEXT vkCmdSetLineStippleEXT;
// VKAPI_ATTR void VKAPI_CALL vkResetQueryPoolEXT(
//     VkDevice                                    device,
//     VkQueryPool                                 queryPool,
//     uint32_t                                    firstQuery,
//     uint32_t                                    queryCount);
extern PFN_vkResetQueryPoolEXT vkResetQueryPoolEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetCullModeEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkCullModeFlags                             cullMode);
extern PFN_vkCmdSetCullModeEXT vkCmdSetCullModeEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetFrontFaceEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkFrontFace                                 frontFace);
extern PFN_vkCmdSetFrontFaceEXT vkCmdSetFrontFaceEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveTopologyEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkPrimitiveTopology                         primitiveTopology);
extern PFN_vkCmdSetPrimitiveTopologyEXT vkCmdSetPrimitiveTopologyEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWithCountEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    viewportCount,
//     const VkViewport*                           pViewports);
extern PFN_vkCmdSetViewportWithCountEXT vkCmdSetViewportWithCountEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetScissorWithCountEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    scissorCount,
//     const VkRect2D*                             pScissors);
extern PFN_vkCmdSetScissorWithCountEXT vkCmdSetScissorWithCountEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers2EXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstBinding,
//     uint32_t                                    bindingCount,
//     const VkBuffer*                             pBuffers,
//     const VkDeviceSize*                         pOffsets,
//     const VkDeviceSize*                         pSizes,
//     const VkDeviceSize*                         pStrides);
extern PFN_vkCmdBindVertexBuffers2EXT vkCmdBindVertexBuffers2EXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthTestEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    depthTestEnable);
extern PFN_vkCmdSetDepthTestEnableEXT vkCmdSetDepthTestEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthWriteEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    depthWriteEnable);
extern PFN_vkCmdSetDepthWriteEnableEXT vkCmdSetDepthWriteEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthCompareOpEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkCompareOp                                 depthCompareOp);
extern PFN_vkCmdSetDepthCompareOpEXT vkCmdSetDepthCompareOpEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBoundsTestEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    depthBoundsTestEnable);
extern PFN_vkCmdSetDepthBoundsTestEnableEXT vkCmdSetDepthBoundsTestEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilTestEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    stencilTestEnable);
extern PFN_vkCmdSetStencilTestEnableEXT vkCmdSetStencilTestEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilOpEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkStencilFaceFlags                          faceMask,
//     VkStencilOp                                 failOp,
//     VkStencilOp                                 passOp,
//     VkStencilOp                                 depthFailOp,
//     VkCompareOp                                 compareOp);
extern PFN_vkCmdSetStencilOpEXT vkCmdSetStencilOpEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToImageEXT(
//     VkDevice                                    device,
//     const VkCopyMemoryToImageInfoEXT*           pCopyMemoryToImageInfo);
extern PFN_vkCopyMemoryToImageEXT vkCopyMemoryToImageEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToMemoryEXT(
//     VkDevice                                    device,
//     const VkCopyImageToMemoryInfoEXT*           pCopyImageToMemoryInfo);
extern PFN_vkCopyImageToMemoryEXT vkCopyImageToMemoryEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToImageEXT(
//     VkDevice                                    device,
//     const VkCopyImageToImageInfoEXT*            pCopyImageToImageInfo);
extern PFN_vkCopyImageToImageEXT vkCopyImageToImageEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkTransitionImageLayoutEXT(
//     VkDevice                                    device,
//     uint32_t                                    transitionCount,
//     const VkHostImageLayoutTransitionInfoEXT*   pTransitions);
extern PFN_vkTransitionImageLayoutEXT vkTransitionImageLayoutEXT;
// VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout2EXT(
//     VkDevice                                    device,
//     VkImage                                     image,
//     const VkImageSubresource2KHR*               pSubresource,
//     VkSubresourceLayout2KHR*                    pLayout);
extern PFN_vkGetImageSubresourceLayout2EXT vkGetImageSubresourceLayout2EXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkReleaseSwapchainImagesEXT(
//     VkDevice                                    device,
//     const VkReleaseSwapchainImagesInfoEXT*      pReleaseInfo);
extern PFN_vkReleaseSwapchainImagesEXT vkReleaseSwapchainImagesEXT;
// VKAPI_ATTR void VKAPI_CALL vkGetGeneratedCommandsMemoryRequirementsNV(
//     VkDevice                                    device,
//     const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo,
//     VkMemoryRequirements2*                      pMemoryRequirements);
extern PFN_vkGetGeneratedCommandsMemoryRequirementsNV vkGetGeneratedCommandsMemoryRequirementsNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdPreprocessGeneratedCommandsNV(
//     VkCommandBuffer                             commandBuffer,
//     const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo);
extern PFN_vkCmdPreprocessGeneratedCommandsNV vkCmdPreprocessGeneratedCommandsNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdExecuteGeneratedCommandsNV(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    isPreprocessed,
//     const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo);
extern PFN_vkCmdExecuteGeneratedCommandsNV vkCmdExecuteGeneratedCommandsNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindPipelineShaderGroupNV(
//     VkCommandBuffer                             commandBuffer,
//     VkPipelineBindPoint                         pipelineBindPoint,
//     VkPipeline                                  pipeline,
//     uint32_t                                    groupIndex);
extern PFN_vkCmdBindPipelineShaderGroupNV vkCmdBindPipelineShaderGroupNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateIndirectCommandsLayoutNV(
//     VkDevice                                    device,
//     const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkIndirectCommandsLayoutNV*                 pIndirectCommandsLayout);
extern PFN_vkCreateIndirectCommandsLayoutNV vkCreateIndirectCommandsLayoutNV;
// VKAPI_ATTR void VKAPI_CALL vkDestroyIndirectCommandsLayoutNV(
//     VkDevice                                    device,
//     VkIndirectCommandsLayoutNV                  indirectCommandsLayout,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyIndirectCommandsLayoutNV vkDestroyIndirectCommandsLayoutNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBias2EXT(
//     VkCommandBuffer                             commandBuffer,
//     const VkDepthBiasInfoEXT*                   pDepthBiasInfo);
extern PFN_vkCmdSetDepthBias2EXT vkCmdSetDepthBias2EXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkAcquireDrmDisplayEXT(
//     VkPhysicalDevice                            physicalDevice,
//     int32_t                                     drmFd,
//     VkDisplayKHR                                display);
extern PFN_vkAcquireDrmDisplayEXT vkAcquireDrmDisplayEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetDrmDisplayEXT(
//     VkPhysicalDevice                            physicalDevice,
//     int32_t                                     drmFd,
//     uint32_t                                    connectorId,
//     VkDisplayKHR*                               display);
extern PFN_vkGetDrmDisplayEXT vkGetDrmDisplayEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreatePrivateDataSlotEXT(
//     VkDevice                                    device,
//     const VkPrivateDataSlotCreateInfo*          pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkPrivateDataSlot*                          pPrivateDataSlot);
extern PFN_vkCreatePrivateDataSlotEXT vkCreatePrivateDataSlotEXT;
// VKAPI_ATTR void VKAPI_CALL vkDestroyPrivateDataSlotEXT(
//     VkDevice                                    device,
//     VkPrivateDataSlot                           privateDataSlot,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyPrivateDataSlotEXT vkDestroyPrivateDataSlotEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkSetPrivateDataEXT(
//     VkDevice                                    device,
//     VkObjectType                                objectType,
//     uint64_t                                    objectHandle,
//     VkPrivateDataSlot                           privateDataSlot,
//     uint64_t                                    data);
extern PFN_vkSetPrivateDataEXT vkSetPrivateDataEXT;
// VKAPI_ATTR void VKAPI_CALL vkGetPrivateDataEXT(
//     VkDevice                                    device,
//     VkObjectType                                objectType,
//     uint64_t                                    objectHandle,
//     VkPrivateDataSlot                           privateDataSlot,
//     uint64_t*                                   pData);
extern PFN_vkGetPrivateDataEXT vkGetPrivateDataEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateCudaModuleNV(
//     VkDevice                                    device,
//     const VkCudaModuleCreateInfoNV*             pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkCudaModuleNV*                             pModule);
extern PFN_vkCreateCudaModuleNV vkCreateCudaModuleNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetCudaModuleCacheNV(
//     VkDevice                                    device,
//     VkCudaModuleNV                              module,
//     size_t*                                     pCacheSize,
//     void*                                       pCacheData);
extern PFN_vkGetCudaModuleCacheNV vkGetCudaModuleCacheNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateCudaFunctionNV(
//     VkDevice                                    device,
//     const VkCudaFunctionCreateInfoNV*           pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkCudaFunctionNV*                           pFunction);
extern PFN_vkCreateCudaFunctionNV vkCreateCudaFunctionNV;
// VKAPI_ATTR void VKAPI_CALL vkDestroyCudaModuleNV(
//     VkDevice                                    device,
//     VkCudaModuleNV                              module,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyCudaModuleNV vkDestroyCudaModuleNV;
// VKAPI_ATTR void VKAPI_CALL vkDestroyCudaFunctionNV(
//     VkDevice                                    device,
//     VkCudaFunctionNV                            function,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyCudaFunctionNV vkDestroyCudaFunctionNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdCudaLaunchKernelNV(
//     VkCommandBuffer                             commandBuffer,
//     const VkCudaLaunchInfoNV*                   pLaunchInfo);
extern PFN_vkCmdCudaLaunchKernelNV vkCmdCudaLaunchKernelNV;
// VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutSizeEXT(
//     VkDevice                                    device,
//     VkDescriptorSetLayout                       layout,
//     VkDeviceSize*                               pLayoutSizeInBytes);
extern PFN_vkGetDescriptorSetLayoutSizeEXT vkGetDescriptorSetLayoutSizeEXT;
// VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutBindingOffsetEXT(
//     VkDevice                                    device,
//     VkDescriptorSetLayout                       layout,
//     uint32_t                                    binding,
//     VkDeviceSize*                               pOffset);
extern PFN_vkGetDescriptorSetLayoutBindingOffsetEXT vkGetDescriptorSetLayoutBindingOffsetEXT;
// VKAPI_ATTR void VKAPI_CALL vkGetDescriptorEXT(
//     VkDevice                                    device,
//     const VkDescriptorGetInfoEXT*               pDescriptorInfo,
//     size_t                                      dataSize,
//     void*                                       pDescriptor);
extern PFN_vkGetDescriptorEXT vkGetDescriptorEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorBuffersEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    bufferCount,
//     const VkDescriptorBufferBindingInfoEXT*     pBindingInfos);
extern PFN_vkCmdBindDescriptorBuffersEXT vkCmdBindDescriptorBuffersEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDescriptorBufferOffsetsEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkPipelineBindPoint                         pipelineBindPoint,
//     VkPipelineLayout                            layout,
//     uint32_t                                    firstSet,
//     uint32_t                                    setCount,
//     const uint32_t*                             pBufferIndices,
//     const VkDeviceSize*                         pOffsets);
extern PFN_vkCmdSetDescriptorBufferOffsetsEXT vkCmdSetDescriptorBufferOffsetsEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorBufferEmbeddedSamplersEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkPipelineBindPoint                         pipelineBindPoint,
//     VkPipelineLayout                            layout,
//     uint32_t                                    set);
extern PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT vkCmdBindDescriptorBufferEmbeddedSamplersEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetBufferOpaqueCaptureDescriptorDataEXT(
//     VkDevice                                    device,
//     const VkBufferCaptureDescriptorDataInfoEXT* pInfo,
//     void*                                       pData);
extern PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT vkGetBufferOpaqueCaptureDescriptorDataEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetImageOpaqueCaptureDescriptorDataEXT(
//     VkDevice                                    device,
//     const VkImageCaptureDescriptorDataInfoEXT*  pInfo,
//     void*                                       pData);
extern PFN_vkGetImageOpaqueCaptureDescriptorDataEXT vkGetImageOpaqueCaptureDescriptorDataEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetImageViewOpaqueCaptureDescriptorDataEXT(
//     VkDevice                                    device,
//     const VkImageViewCaptureDescriptorDataInfoEXT* pInfo,
//     void*                                       pData);
extern PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT vkGetImageViewOpaqueCaptureDescriptorDataEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetSamplerOpaqueCaptureDescriptorDataEXT(
//     VkDevice                                    device,
//     const VkSamplerCaptureDescriptorDataInfoEXT* pInfo,
//     void*                                       pData);
extern PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT vkGetSamplerOpaqueCaptureDescriptorDataEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(
//     VkDevice                                    device,
//     const VkAccelerationStructureCaptureDescriptorDataInfoEXT* pInfo,
//     void*                                       pData);
extern PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetFragmentShadingRateEnumNV(
//     VkCommandBuffer                             commandBuffer,
//     VkFragmentShadingRateNV                     shadingRate,
//     const VkFragmentShadingRateCombinerOpKHR    combinerOps[2]);
extern PFN_vkCmdSetFragmentShadingRateEnumNV vkCmdSetFragmentShadingRateEnumNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceFaultInfoEXT(
//     VkDevice                                    device,
//     VkDeviceFaultCountsEXT*                     pFaultCounts,
//     VkDeviceFaultInfoEXT*                       pFaultInfo);
extern PFN_vkGetDeviceFaultInfoEXT vkGetDeviceFaultInfoEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetVertexInputEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    vertexBindingDescriptionCount,
//     const VkVertexInputBindingDescription2EXT*  pVertexBindingDescriptions,
//     uint32_t                                    vertexAttributeDescriptionCount,
//     const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions);
extern PFN_vkCmdSetVertexInputEXT vkCmdSetVertexInputEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(
//     VkDevice                                    device,
//     VkRenderPass                                renderpass,
//     VkExtent2D*                                 pMaxWorkgroupSize);
extern PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI;
// VKAPI_ATTR void VKAPI_CALL vkCmdSubpassShadingHUAWEI(
//     VkCommandBuffer                             commandBuffer);
extern PFN_vkCmdSubpassShadingHUAWEI vkCmdSubpassShadingHUAWEI;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindInvocationMaskHUAWEI(
//     VkCommandBuffer                             commandBuffer,
//     VkImageView                                 imageView,
//     VkImageLayout                               imageLayout);
extern PFN_vkCmdBindInvocationMaskHUAWEI vkCmdBindInvocationMaskHUAWEI;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryRemoteAddressNV(
//     VkDevice                                    device,
//     const VkMemoryGetRemoteAddressInfoNV*       pMemoryGetRemoteAddressInfo,
//     VkRemoteAddressNV*                          pAddress);
extern PFN_vkGetMemoryRemoteAddressNV vkGetMemoryRemoteAddressNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelinePropertiesEXT(
//     VkDevice                                    device,
//     const VkPipelineInfoEXT*                    pPipelineInfo,
//     VkBaseOutStructure*                         pPipelineProperties);
extern PFN_vkGetPipelinePropertiesEXT vkGetPipelinePropertiesEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetPatchControlPointsEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    patchControlPoints);
extern PFN_vkCmdSetPatchControlPointsEXT vkCmdSetPatchControlPointsEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizerDiscardEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    rasterizerDiscardEnable);
extern PFN_vkCmdSetRasterizerDiscardEnableEXT vkCmdSetRasterizerDiscardEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBiasEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    depthBiasEnable);
extern PFN_vkCmdSetDepthBiasEnableEXT vkCmdSetDepthBiasEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetLogicOpEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkLogicOp                                   logicOp);
extern PFN_vkCmdSetLogicOpEXT vkCmdSetLogicOpEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveRestartEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    primitiveRestartEnable);
extern PFN_vkCmdSetPrimitiveRestartEnableEXT vkCmdSetPrimitiveRestartEnableEXT;
// VKAPI_ATTR void                                    VKAPI_CALL vkCmdSetColorWriteEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    attachmentCount,
//     const VkBool32*                             pColorWriteEnables);
extern PFN_vkCmdSetColorWriteEnableEXT vkCmdSetColorWriteEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawMultiEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    drawCount,
//     const VkMultiDrawInfoEXT*                   pVertexInfo,
//     uint32_t                                    instanceCount,
//     uint32_t                                    firstInstance,
//     uint32_t                                    stride);
extern PFN_vkCmdDrawMultiEXT vkCmdDrawMultiEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawMultiIndexedEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    drawCount,
//     const VkMultiDrawIndexedInfoEXT*            pIndexInfo,
//     uint32_t                                    instanceCount,
//     uint32_t                                    firstInstance,
//     uint32_t                                    stride,
//     const int32_t*                              pVertexOffset);
extern PFN_vkCmdDrawMultiIndexedEXT vkCmdDrawMultiIndexedEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateMicromapEXT(
//     VkDevice                                    device,
//     const VkMicromapCreateInfoEXT*              pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkMicromapEXT*                              pMicromap);
extern PFN_vkCreateMicromapEXT vkCreateMicromapEXT;
// VKAPI_ATTR void VKAPI_CALL vkDestroyMicromapEXT(
//     VkDevice                                    device,
//     VkMicromapEXT                               micromap,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyMicromapEXT vkDestroyMicromapEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdBuildMicromapsEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    infoCount,
//     const VkMicromapBuildInfoEXT*               pInfos);
extern PFN_vkCmdBuildMicromapsEXT vkCmdBuildMicromapsEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkBuildMicromapsEXT(
//     VkDevice                                    device,
//     VkDeferredOperationKHR                      deferredOperation,
//     uint32_t                                    infoCount,
//     const VkMicromapBuildInfoEXT*               pInfos);
extern PFN_vkBuildMicromapsEXT vkBuildMicromapsEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkCopyMicromapEXT(
//     VkDevice                                    device,
//     VkDeferredOperationKHR                      deferredOperation,
//     const VkCopyMicromapInfoEXT*                pInfo);
extern PFN_vkCopyMicromapEXT vkCopyMicromapEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkCopyMicromapToMemoryEXT(
//     VkDevice                                    device,
//     VkDeferredOperationKHR                      deferredOperation,
//     const VkCopyMicromapToMemoryInfoEXT*        pInfo);
extern PFN_vkCopyMicromapToMemoryEXT vkCopyMicromapToMemoryEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToMicromapEXT(
//     VkDevice                                    device,
//     VkDeferredOperationKHR                      deferredOperation,
//     const VkCopyMemoryToMicromapInfoEXT*        pInfo);
extern PFN_vkCopyMemoryToMicromapEXT vkCopyMemoryToMicromapEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkWriteMicromapsPropertiesEXT(
//     VkDevice                                    device,
//     uint32_t                                    micromapCount,
//     const VkMicromapEXT*                        pMicromaps,
//     VkQueryType                                 queryType,
//     size_t                                      dataSize,
//     void*                                       pData,
//     size_t                                      stride);
extern PFN_vkWriteMicromapsPropertiesEXT vkWriteMicromapsPropertiesEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyMicromapEXT(
//     VkCommandBuffer                             commandBuffer,
//     const VkCopyMicromapInfoEXT*                pInfo);
extern PFN_vkCmdCopyMicromapEXT vkCmdCopyMicromapEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyMicromapToMemoryEXT(
//     VkCommandBuffer                             commandBuffer,
//     const VkCopyMicromapToMemoryInfoEXT*        pInfo);
extern PFN_vkCmdCopyMicromapToMemoryEXT vkCmdCopyMicromapToMemoryEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToMicromapEXT(
//     VkCommandBuffer                             commandBuffer,
//     const VkCopyMemoryToMicromapInfoEXT*        pInfo);
extern PFN_vkCmdCopyMemoryToMicromapEXT vkCmdCopyMemoryToMicromapEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdWriteMicromapsPropertiesEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    micromapCount,
//     const VkMicromapEXT*                        pMicromaps,
//     VkQueryType                                 queryType,
//     VkQueryPool                                 queryPool,
//     uint32_t                                    firstQuery);
extern PFN_vkCmdWriteMicromapsPropertiesEXT vkCmdWriteMicromapsPropertiesEXT;
// VKAPI_ATTR void VKAPI_CALL vkGetDeviceMicromapCompatibilityEXT(
//     VkDevice                                    device,
//     const VkMicromapVersionInfoEXT*             pVersionInfo,
//     VkAccelerationStructureCompatibilityKHR*    pCompatibility);
extern PFN_vkGetDeviceMicromapCompatibilityEXT vkGetDeviceMicromapCompatibilityEXT;
// VKAPI_ATTR void VKAPI_CALL vkGetMicromapBuildSizesEXT(
//     VkDevice                                    device,
//     VkAccelerationStructureBuildTypeKHR         buildType,
//     const VkMicromapBuildInfoEXT*               pBuildInfo,
//     VkMicromapBuildSizesInfoEXT*                pSizeInfo);
extern PFN_vkGetMicromapBuildSizesEXT vkGetMicromapBuildSizesEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawClusterHUAWEI(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    groupCountX,
//     uint32_t                                    groupCountY,
//     uint32_t                                    groupCountZ);
extern PFN_vkCmdDrawClusterHUAWEI vkCmdDrawClusterHUAWEI;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawClusterIndirectHUAWEI(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset);
extern PFN_vkCmdDrawClusterIndirectHUAWEI vkCmdDrawClusterIndirectHUAWEI;
// VKAPI_ATTR void VKAPI_CALL vkSetDeviceMemoryPriorityEXT(
//     VkDevice                                    device,
//     VkDeviceMemory                              memory,
//     float                                       priority);
extern PFN_vkSetDeviceMemoryPriorityEXT vkSetDeviceMemoryPriorityEXT;
// VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutHostMappingInfoVALVE(
//     VkDevice                                    device,
//     const VkDescriptorSetBindingReferenceVALVE* pBindingReference,
//     VkDescriptorSetLayoutHostMappingInfoVALVE*  pHostMapping);
extern PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE vkGetDescriptorSetLayoutHostMappingInfoVALVE;
// VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetHostMappingVALVE(
//     VkDevice                                    device,
//     VkDescriptorSet                             descriptorSet,
//     void**                                      ppData);
extern PFN_vkGetDescriptorSetHostMappingVALVE vkGetDescriptorSetHostMappingVALVE;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryIndirectNV(
//     VkCommandBuffer                             commandBuffer,
//     VkDeviceAddress                             copyBufferAddress,
//     uint32_t                                    copyCount,
//     uint32_t                                    stride);
extern PFN_vkCmdCopyMemoryIndirectNV vkCmdCopyMemoryIndirectNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToImageIndirectNV(
//     VkCommandBuffer                             commandBuffer,
//     VkDeviceAddress                             copyBufferAddress,
//     uint32_t                                    copyCount,
//     uint32_t                                    stride,
//     VkImage                                     dstImage,
//     VkImageLayout                               dstImageLayout,
//     const VkImageSubresourceLayers*             pImageSubresources);
extern PFN_vkCmdCopyMemoryToImageIndirectNV vkCmdCopyMemoryToImageIndirectNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdDecompressMemoryNV(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    decompressRegionCount,
//     const VkDecompressMemoryRegionNV*           pDecompressMemoryRegions);
extern PFN_vkCmdDecompressMemoryNV vkCmdDecompressMemoryNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdDecompressMemoryIndirectCountNV(
//     VkCommandBuffer                             commandBuffer,
//     VkDeviceAddress                             indirectCommandsAddress,
//     VkDeviceAddress                             indirectCommandsCountAddress,
//     uint32_t                                    stride);
extern PFN_vkCmdDecompressMemoryIndirectCountNV vkCmdDecompressMemoryIndirectCountNV;
// VKAPI_ATTR void VKAPI_CALL vkGetPipelineIndirectMemoryRequirementsNV(
//     VkDevice                                    device,
//     const VkComputePipelineCreateInfo*          pCreateInfo,
//     VkMemoryRequirements2*                      pMemoryRequirements);
extern PFN_vkGetPipelineIndirectMemoryRequirementsNV vkGetPipelineIndirectMemoryRequirementsNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdUpdatePipelineIndirectBufferNV(
//     VkCommandBuffer                             commandBuffer,
//     VkPipelineBindPoint                         pipelineBindPoint,
//     VkPipeline                                  pipeline);
extern PFN_vkCmdUpdatePipelineIndirectBufferNV vkCmdUpdatePipelineIndirectBufferNV;
// VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetPipelineIndirectDeviceAddressNV(
//     VkDevice                                    device,
//     const VkPipelineIndirectDeviceAddressInfoNV* pInfo);
extern PFN_vkGetPipelineIndirectDeviceAddressNV vkGetPipelineIndirectDeviceAddressNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClampEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    depthClampEnable);
extern PFN_vkCmdSetDepthClampEnableEXT vkCmdSetDepthClampEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetPolygonModeEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkPolygonMode                               polygonMode);
extern PFN_vkCmdSetPolygonModeEXT vkCmdSetPolygonModeEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizationSamplesEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkSampleCountFlagBits                       rasterizationSamples);
extern PFN_vkCmdSetRasterizationSamplesEXT vkCmdSetRasterizationSamplesEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetSampleMaskEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkSampleCountFlagBits                       samples,
//     const VkSampleMask*                         pSampleMask);
extern PFN_vkCmdSetSampleMaskEXT vkCmdSetSampleMaskEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetAlphaToCoverageEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    alphaToCoverageEnable);
extern PFN_vkCmdSetAlphaToCoverageEnableEXT vkCmdSetAlphaToCoverageEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetAlphaToOneEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    alphaToOneEnable);
extern PFN_vkCmdSetAlphaToOneEnableEXT vkCmdSetAlphaToOneEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetLogicOpEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    logicOpEnable);
extern PFN_vkCmdSetLogicOpEnableEXT vkCmdSetLogicOpEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetColorBlendEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstAttachment,
//     uint32_t                                    attachmentCount,
//     const VkBool32*                             pColorBlendEnables);
extern PFN_vkCmdSetColorBlendEnableEXT vkCmdSetColorBlendEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetColorBlendEquationEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstAttachment,
//     uint32_t                                    attachmentCount,
//     const VkColorBlendEquationEXT*              pColorBlendEquations);
extern PFN_vkCmdSetColorBlendEquationEXT vkCmdSetColorBlendEquationEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetColorWriteMaskEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstAttachment,
//     uint32_t                                    attachmentCount,
//     const VkColorComponentFlags*                pColorWriteMasks);
extern PFN_vkCmdSetColorWriteMaskEXT vkCmdSetColorWriteMaskEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetTessellationDomainOriginEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkTessellationDomainOrigin                  domainOrigin);
extern PFN_vkCmdSetTessellationDomainOriginEXT vkCmdSetTessellationDomainOriginEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizationStreamEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    rasterizationStream);
extern PFN_vkCmdSetRasterizationStreamEXT vkCmdSetRasterizationStreamEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetConservativeRasterizationModeEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkConservativeRasterizationModeEXT          conservativeRasterizationMode);
extern PFN_vkCmdSetConservativeRasterizationModeEXT vkCmdSetConservativeRasterizationModeEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetExtraPrimitiveOverestimationSizeEXT(
//     VkCommandBuffer                             commandBuffer,
//     float                                       extraPrimitiveOverestimationSize);
extern PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT vkCmdSetExtraPrimitiveOverestimationSizeEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClipEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    depthClipEnable);
extern PFN_vkCmdSetDepthClipEnableEXT vkCmdSetDepthClipEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetSampleLocationsEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    sampleLocationsEnable);
extern PFN_vkCmdSetSampleLocationsEnableEXT vkCmdSetSampleLocationsEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetColorBlendAdvancedEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstAttachment,
//     uint32_t                                    attachmentCount,
//     const VkColorBlendAdvancedEXT*              pColorBlendAdvanced);
extern PFN_vkCmdSetColorBlendAdvancedEXT vkCmdSetColorBlendAdvancedEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetProvokingVertexModeEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkProvokingVertexModeEXT                    provokingVertexMode);
extern PFN_vkCmdSetProvokingVertexModeEXT vkCmdSetProvokingVertexModeEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetLineRasterizationModeEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkLineRasterizationModeEXT                  lineRasterizationMode);
extern PFN_vkCmdSetLineRasterizationModeEXT vkCmdSetLineRasterizationModeEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStippleEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    stippledLineEnable);
extern PFN_vkCmdSetLineStippleEnableEXT vkCmdSetLineStippleEnableEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClipNegativeOneToOneEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    negativeOneToOne);
extern PFN_vkCmdSetDepthClipNegativeOneToOneEXT vkCmdSetDepthClipNegativeOneToOneEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWScalingEnableNV(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    viewportWScalingEnable);
extern PFN_vkCmdSetViewportWScalingEnableNV vkCmdSetViewportWScalingEnableNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportSwizzleNV(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    firstViewport,
//     uint32_t                                    viewportCount,
//     const VkViewportSwizzleNV*                  pViewportSwizzles);
extern PFN_vkCmdSetViewportSwizzleNV vkCmdSetViewportSwizzleNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageToColorEnableNV(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    coverageToColorEnable);
extern PFN_vkCmdSetCoverageToColorEnableNV vkCmdSetCoverageToColorEnableNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageToColorLocationNV(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    coverageToColorLocation);
extern PFN_vkCmdSetCoverageToColorLocationNV vkCmdSetCoverageToColorLocationNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageModulationModeNV(
//     VkCommandBuffer                             commandBuffer,
//     VkCoverageModulationModeNV                  coverageModulationMode);
extern PFN_vkCmdSetCoverageModulationModeNV vkCmdSetCoverageModulationModeNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageModulationTableEnableNV(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    coverageModulationTableEnable);
extern PFN_vkCmdSetCoverageModulationTableEnableNV vkCmdSetCoverageModulationTableEnableNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageModulationTableNV(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    coverageModulationTableCount,
//     const float*                                pCoverageModulationTable);
extern PFN_vkCmdSetCoverageModulationTableNV vkCmdSetCoverageModulationTableNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetShadingRateImageEnableNV(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    shadingRateImageEnable);
extern PFN_vkCmdSetShadingRateImageEnableNV vkCmdSetShadingRateImageEnableNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetRepresentativeFragmentTestEnableNV(
//     VkCommandBuffer                             commandBuffer,
//     VkBool32                                    representativeFragmentTestEnable);
extern PFN_vkCmdSetRepresentativeFragmentTestEnableNV vkCmdSetRepresentativeFragmentTestEnableNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageReductionModeNV(
//     VkCommandBuffer                             commandBuffer,
//     VkCoverageReductionModeNV                   coverageReductionMode);
extern PFN_vkCmdSetCoverageReductionModeNV vkCmdSetCoverageReductionModeNV;
// VKAPI_ATTR void VKAPI_CALL vkGetShaderModuleIdentifierEXT(
//     VkDevice                                    device,
//     VkShaderModule                              shaderModule,
//     VkShaderModuleIdentifierEXT*                pIdentifier);
extern PFN_vkGetShaderModuleIdentifierEXT vkGetShaderModuleIdentifierEXT;
// VKAPI_ATTR void VKAPI_CALL vkGetShaderModuleCreateInfoIdentifierEXT(
//     VkDevice                                    device,
//     const VkShaderModuleCreateInfo*             pCreateInfo,
//     VkShaderModuleIdentifierEXT*                pIdentifier);
extern PFN_vkGetShaderModuleCreateInfoIdentifierEXT vkGetShaderModuleCreateInfoIdentifierEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceOpticalFlowImageFormatsNV(
//     VkPhysicalDevice                            physicalDevice,
//     const VkOpticalFlowImageFormatInfoNV*       pOpticalFlowImageFormatInfo,
//     uint32_t*                                   pFormatCount,
//     VkOpticalFlowImageFormatPropertiesNV*       pImageFormatProperties);
extern PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV vkGetPhysicalDeviceOpticalFlowImageFormatsNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateOpticalFlowSessionNV(
//     VkDevice                                    device,
//     const VkOpticalFlowSessionCreateInfoNV*     pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkOpticalFlowSessionNV*                     pSession);
extern PFN_vkCreateOpticalFlowSessionNV vkCreateOpticalFlowSessionNV;
// VKAPI_ATTR void VKAPI_CALL vkDestroyOpticalFlowSessionNV(
//     VkDevice                                    device,
//     VkOpticalFlowSessionNV                      session,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyOpticalFlowSessionNV vkDestroyOpticalFlowSessionNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkBindOpticalFlowSessionImageNV(
//     VkDevice                                    device,
//     VkOpticalFlowSessionNV                      session,
//     VkOpticalFlowSessionBindingPointNV          bindingPoint,
//     VkImageView                                 view,
//     VkImageLayout                               layout);
extern PFN_vkBindOpticalFlowSessionImageNV vkBindOpticalFlowSessionImageNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdOpticalFlowExecuteNV(
//     VkCommandBuffer                             commandBuffer,
//     VkOpticalFlowSessionNV                      session,
//     const VkOpticalFlowExecuteInfoNV*           pExecuteInfo);
extern PFN_vkCmdOpticalFlowExecuteNV vkCmdOpticalFlowExecuteNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateShadersEXT(
//     VkDevice                                    device,
//     uint32_t                                    createInfoCount,
//     const VkShaderCreateInfoEXT*                pCreateInfos,
//     const VkAllocationCallbacks*                pAllocator,
//     VkShaderEXT*                                pShaders);
extern PFN_vkCreateShadersEXT vkCreateShadersEXT;
// VKAPI_ATTR void VKAPI_CALL vkDestroyShaderEXT(
//     VkDevice                                    device,
//     VkShaderEXT                                 shader,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyShaderEXT vkDestroyShaderEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetShaderBinaryDataEXT(
//     VkDevice                                    device,
//     VkShaderEXT                                 shader,
//     size_t*                                     pDataSize,
//     void*                                       pData);
extern PFN_vkGetShaderBinaryDataEXT vkGetShaderBinaryDataEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdBindShadersEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    stageCount,
//     const VkShaderStageFlagBits*                pStages,
//     const VkShaderEXT*                          pShaders);
extern PFN_vkCmdBindShadersEXT vkCmdBindShadersEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetFramebufferTilePropertiesQCOM(
//     VkDevice                                    device,
//     VkFramebuffer                               framebuffer,
//     uint32_t*                                   pPropertiesCount,
//     VkTilePropertiesQCOM*                       pProperties);
extern PFN_vkGetFramebufferTilePropertiesQCOM vkGetFramebufferTilePropertiesQCOM;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetDynamicRenderingTilePropertiesQCOM(
//     VkDevice                                    device,
//     const VkRenderingInfo*                      pRenderingInfo,
//     VkTilePropertiesQCOM*                       pProperties);
extern PFN_vkGetDynamicRenderingTilePropertiesQCOM vkGetDynamicRenderingTilePropertiesQCOM;
// VKAPI_ATTR VkResult VKAPI_CALL vkSetLatencySleepModeNV(
//     VkDevice                                    device,
//     VkSwapchainKHR                              swapchain,
//     const VkLatencySleepModeInfoNV*             pSleepModeInfo);
extern PFN_vkSetLatencySleepModeNV vkSetLatencySleepModeNV;
// VKAPI_ATTR VkResult VKAPI_CALL vkLatencySleepNV(
//     VkDevice                                    device,
//     VkSwapchainKHR                              swapchain,
//     const VkLatencySleepInfoNV*                 pSleepInfo);
extern PFN_vkLatencySleepNV vkLatencySleepNV;
// VKAPI_ATTR void VKAPI_CALL vkSetLatencyMarkerNV(
//     VkDevice                                    device,
//     VkSwapchainKHR                              swapchain,
//     const VkSetLatencyMarkerInfoNV*             pLatencyMarkerInfo);
extern PFN_vkSetLatencyMarkerNV vkSetLatencyMarkerNV;
// VKAPI_ATTR void VKAPI_CALL vkGetLatencyTimingsNV(
//     VkDevice                                    device,
//     VkSwapchainKHR                              swapchain,
//     VkGetLatencyMarkerInfoNV*                   pLatencyMarkerInfo);
extern PFN_vkGetLatencyTimingsNV vkGetLatencyTimingsNV;
// VKAPI_ATTR void VKAPI_CALL vkQueueNotifyOutOfBandNV(
//     VkQueue                                     queue,
//     const VkOutOfBandQueueTypeInfoNV*           pQueueTypeInfo);
extern PFN_vkQueueNotifyOutOfBandNV vkQueueNotifyOutOfBandNV;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetAttachmentFeedbackLoopEnableEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkImageAspectFlags                          aspectMask);
extern PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT vkCmdSetAttachmentFeedbackLoopEnableEXT;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateAccelerationStructureKHR(
//     VkDevice                                    device,
//     const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
//     const VkAllocationCallbacks*                pAllocator,
//     VkAccelerationStructureKHR*                 pAccelerationStructure);
extern PFN_vkCreateAccelerationStructureKHR vkCreateAccelerationStructureKHR;
// VKAPI_ATTR void VKAPI_CALL vkDestroyAccelerationStructureKHR(
//     VkDevice                                    device,
//     VkAccelerationStructureKHR                  accelerationStructure,
//     const VkAllocationCallbacks*                pAllocator);
extern PFN_vkDestroyAccelerationStructureKHR vkDestroyAccelerationStructureKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdBuildAccelerationStructuresKHR(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    infoCount,
//     const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
//     const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);
extern PFN_vkCmdBuildAccelerationStructuresKHR vkCmdBuildAccelerationStructuresKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdBuildAccelerationStructuresIndirectKHR(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    infoCount,
//     const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
//     const VkDeviceAddress*                      pIndirectDeviceAddresses,
//     const uint32_t*                             pIndirectStrides,
//     const uint32_t* const*                      ppMaxPrimitiveCounts);
extern PFN_vkCmdBuildAccelerationStructuresIndirectKHR vkCmdBuildAccelerationStructuresIndirectKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkBuildAccelerationStructuresKHR(
//     VkDevice                                    device,
//     VkDeferredOperationKHR                      deferredOperation,
//     uint32_t                                    infoCount,
//     const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
//     const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos);
extern PFN_vkBuildAccelerationStructuresKHR vkBuildAccelerationStructuresKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkCopyAccelerationStructureKHR(
//     VkDevice                                    device,
//     VkDeferredOperationKHR                      deferredOperation,
//     const VkCopyAccelerationStructureInfoKHR*   pInfo);
extern PFN_vkCopyAccelerationStructureKHR vkCopyAccelerationStructureKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkCopyAccelerationStructureToMemoryKHR(
//     VkDevice                                    device,
//     VkDeferredOperationKHR                      deferredOperation,
//     const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);
extern PFN_vkCopyAccelerationStructureToMemoryKHR vkCopyAccelerationStructureToMemoryKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToAccelerationStructureKHR(
//     VkDevice                                    device,
//     VkDeferredOperationKHR                      deferredOperation,
//     const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);
extern PFN_vkCopyMemoryToAccelerationStructureKHR vkCopyMemoryToAccelerationStructureKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkWriteAccelerationStructuresPropertiesKHR(
//     VkDevice                                    device,
//     uint32_t                                    accelerationStructureCount,
//     const VkAccelerationStructureKHR*           pAccelerationStructures,
//     VkQueryType                                 queryType,
//     size_t                                      dataSize,
//     void*                                       pData,
//     size_t                                      stride);
extern PFN_vkWriteAccelerationStructuresPropertiesKHR vkWriteAccelerationStructuresPropertiesKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyAccelerationStructureKHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkCopyAccelerationStructureInfoKHR*   pInfo);
extern PFN_vkCmdCopyAccelerationStructureKHR vkCmdCopyAccelerationStructureKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyAccelerationStructureToMemoryKHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);
extern PFN_vkCmdCopyAccelerationStructureToMemoryKHR vkCmdCopyAccelerationStructureToMemoryKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToAccelerationStructureKHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);
extern PFN_vkCmdCopyMemoryToAccelerationStructureKHR vkCmdCopyMemoryToAccelerationStructureKHR;
// VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetAccelerationStructureDeviceAddressKHR(
//     VkDevice                                    device,
//     const VkAccelerationStructureDeviceAddressInfoKHR* pInfo);
extern PFN_vkGetAccelerationStructureDeviceAddressKHR vkGetAccelerationStructureDeviceAddressKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdWriteAccelerationStructuresPropertiesKHR(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    accelerationStructureCount,
//     const VkAccelerationStructureKHR*           pAccelerationStructures,
//     VkQueryType                                 queryType,
//     VkQueryPool                                 queryPool,
//     uint32_t                                    firstQuery);
extern PFN_vkCmdWriteAccelerationStructuresPropertiesKHR vkCmdWriteAccelerationStructuresPropertiesKHR;
// VKAPI_ATTR void VKAPI_CALL vkGetDeviceAccelerationStructureCompatibilityKHR(
//     VkDevice                                    device,
//     const VkAccelerationStructureVersionInfoKHR* pVersionInfo,
//     VkAccelerationStructureCompatibilityKHR*    pCompatibility);
extern PFN_vkGetDeviceAccelerationStructureCompatibilityKHR vkGetDeviceAccelerationStructureCompatibilityKHR;
// VKAPI_ATTR void VKAPI_CALL vkGetAccelerationStructureBuildSizesKHR(
//     VkDevice                                    device,
//     VkAccelerationStructureBuildTypeKHR         buildType,
//     const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo,
//     const uint32_t*                             pMaxPrimitiveCounts,
//     VkAccelerationStructureBuildSizesInfoKHR*   pSizeInfo);
extern PFN_vkGetAccelerationStructureBuildSizesKHR vkGetAccelerationStructureBuildSizesKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysKHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
//     const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
//     const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
//     const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
//     uint32_t                                    width,
//     uint32_t                                    height,
//     uint32_t                                    depth);
extern PFN_vkCmdTraceRaysKHR vkCmdTraceRaysKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkCreateRayTracingPipelinesKHR(
//     VkDevice                                    device,
//     VkDeferredOperationKHR                      deferredOperation,
//     VkPipelineCache                             pipelineCache,
//     uint32_t                                    createInfoCount,
//     const VkRayTracingPipelineCreateInfoKHR*    pCreateInfos,
//     const VkAllocationCallbacks*                pAllocator,
//     VkPipeline*                                 pPipelines);
extern PFN_vkCreateRayTracingPipelinesKHR vkCreateRayTracingPipelinesKHR;
// VKAPI_ATTR VkResult VKAPI_CALL vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
//     VkDevice                                    device,
//     VkPipeline                                  pipeline,
//     uint32_t                                    firstGroup,
//     uint32_t                                    groupCount,
//     size_t                                      dataSize,
//     void*                                       pData);
extern PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR vkGetRayTracingCaptureReplayShaderGroupHandlesKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysIndirectKHR(
//     VkCommandBuffer                             commandBuffer,
//     const VkStridedDeviceAddressRegionKHR*      pRaygenShaderBindingTable,
//     const VkStridedDeviceAddressRegionKHR*      pMissShaderBindingTable,
//     const VkStridedDeviceAddressRegionKHR*      pHitShaderBindingTable,
//     const VkStridedDeviceAddressRegionKHR*      pCallableShaderBindingTable,
//     VkDeviceAddress                             indirectDeviceAddress);
extern PFN_vkCmdTraceRaysIndirectKHR vkCmdTraceRaysIndirectKHR;
// VKAPI_ATTR VkDeviceSize VKAPI_CALL vkGetRayTracingShaderGroupStackSizeKHR(
//     VkDevice                                    device,
//     VkPipeline                                  pipeline,
//     uint32_t                                    group,
//     VkShaderGroupShaderKHR                      groupShader);
extern PFN_vkGetRayTracingShaderGroupStackSizeKHR vkGetRayTracingShaderGroupStackSizeKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdSetRayTracingPipelineStackSizeKHR(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    pipelineStackSize);
extern PFN_vkCmdSetRayTracingPipelineStackSizeKHR vkCmdSetRayTracingPipelineStackSizeKHR;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksEXT(
//     VkCommandBuffer                             commandBuffer,
//     uint32_t                                    groupCountX,
//     uint32_t                                    groupCountY,
//     uint32_t                                    groupCountZ);
extern PFN_vkCmdDrawMeshTasksEXT vkCmdDrawMeshTasksEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset,
//     uint32_t                                    drawCount,
//     uint32_t                                    stride);
extern PFN_vkCmdDrawMeshTasksIndirectEXT vkCmdDrawMeshTasksIndirectEXT;
// VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectCountEXT(
//     VkCommandBuffer                             commandBuffer,
//     VkBuffer                                    buffer,
//     VkDeviceSize                                offset,
//     VkBuffer                                    countBuffer,
//     VkDeviceSize                                countBufferOffset,
//     uint32_t                                    maxDrawCount,
//     uint32_t                                    stride);
extern PFN_vkCmdDrawMeshTasksIndirectCountEXT vkCmdDrawMeshTasksIndirectCountEXT;


// Loader Function
void vkfnlib_load_core(PFN_loadfunc_vk load, VkInstance vk_instance);
