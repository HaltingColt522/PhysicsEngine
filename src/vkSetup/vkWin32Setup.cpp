#include <vkSetup/vkSetup.h>

#include <vkSetup/physicalDevice.h>
#include <vkSetup/logicalDevice.h>
#include <vkSetup/swapchain.h>

void Vulkan::winsetup(WINDOW* window, VkInstance instance) {

	//creating VKSURFACE //
	VkWin32SurfaceCreateInfoKHR surfaceCreateInfo = {};
	surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
	surfaceCreateInfo.pNext = NULL;
	surfaceCreateInfo.flags = 0;
	surfaceCreateInfo.hinstance = GetModuleHandle(NULL);
	surfaceCreateInfo.hwnd = window->handle;

	if (vkCreateWin32SurfaceKHR(instance, &surfaceCreateInfo, NULL, &window->surface) != VK_SUCCESS) {
		throw std::runtime_error("failed to create VkSurface for win32 window");
	}

	// picking physical device //

	pickPhysicalDevice(window, instance);

	// creating logical device //

	createLogicalDevice(window);

	// creating Swapchain //

	createSwapChain(window);
}