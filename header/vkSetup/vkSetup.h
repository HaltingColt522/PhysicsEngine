#pragma once

#include <main.h>

struct INSTANCE {
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
};

namespace Vulkan {
    // gets executed automatically by Window::create
    void winsetup(WINDOW* window, VkInstance instance);
    // TODO: void cleanup(); -> things like swapchain, ... : gets executed automytically by windowproc -> case: WM_NCDESTROY
    void cleanup(WINDOW* window, INSTANCE instance);
    void instance(INSTANCE* instance);
    void destroyInstance(INSTANCE* instance);
}