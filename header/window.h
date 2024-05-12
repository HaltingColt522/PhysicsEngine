#pragma once

#include <main.h>
#include <struct.h>

class Window {   
public:
    Window(uint32_t width, uint32_t height);
    void run();

private:

    uint32_t WIDTH;
    uint32_t HEIGHT;

    GLFWwindow* window;

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    
    VkPhysicalDevice physicalDevice;

    VkDevice device;
    VkQueue graphicsQueue;

    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
    void createInstance();
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    void setupDebugMessenger();
    void pickPhysicalDevice();
    void createLogicalDevice();
    bool isDeviceSuitable(VkPhysicalDevice device);

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    std::vector<const char*> getRequiredExtensions();

    bool checkValidationLayerSupport();

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);

};
