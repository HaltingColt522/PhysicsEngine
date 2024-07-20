#pragma once

#include <main.h>

struct INSTANCE {
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
};

namespace Vulkan {
    // gets executed automatically by Window::create
    void winsetup(WINDOW* window, VkInstance instance, HWND hwnd);
    // gets executed automytically by windowproc -> case: WM_NCDESTROY
    void cleanup(WINDOW* window, INSTANCE instance);
    void setupInstance(INSTANCE* instance);
    void destroyInstance(INSTANCE* instance);
}