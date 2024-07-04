#pragma once

#include <main.h>
#include <debug.h>

namespace Const {
    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

    const std::vector<const char*> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };

    const int MAX_FRAMES_IN_FLIGHT = 2;
}

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    inline bool isComplete() const {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

struct VKSETUP {
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
};

struct WINDOW {
    HWND handle;
    VkSurfaceKHR surface;
    VkPhysicalDevice physicalDevice;
};

namespace Vulkan {
    void winsetup(WINDOW* window, VkInstance instance);
    void instance(VKSETUP* setup);
    void destroyInstance(VKSETUP* setup);
}