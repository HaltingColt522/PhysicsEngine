#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <limits>
#include <algorithm>
#include <thread>
#include <string>

#include <map>
#include <optional>
#include <set>

#include <glm/common.hpp>

#include <fstream>

#ifndef Unicode
#define Unicode
#endif
#include "Windows.h"

namespace Const {
    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

    const std::vector<const char*> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };

    const int MAX_FRAMES_IN_FLIGHT = 2;
}

struct WINDOW {
    VkSurfaceKHR surface;

    VkPhysicalDevice physicalDevice;
    VkDevice device;

    VkQueue graphicsQueue;
    VkQueue presentQueue;

    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;

    VkRenderPass renderPass;
    std::vector<VkPipeline> graphicsPipeline;

    std::vector<VkFramebuffer> swapChainFramebuffers;
};
