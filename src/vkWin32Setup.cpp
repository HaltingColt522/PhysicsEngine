#include <vkSetup.h>

void Vulkan::winsetup(WINDOW* window, VkInstance instance) {

	//creating VKSURFACE //

	VkSurfaceKHR surface;

	VkWin32SurfaceCreateInfoKHR surfaceCreateInfo = {};
	surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
	surfaceCreateInfo.pNext = NULL;
	surfaceCreateInfo.flags = NULL;
	surfaceCreateInfo.hinstance = GetModuleHandle(NULL);
	surfaceCreateInfo.hwnd = window->handle;

	if (vkCreateWin32SurfaceKHR(instance, &surfaceCreateInfo, NULL, &surface) != VK_SUCCESS) {
		throw std::runtime_error("failed to create VkSurface for win32 window");
	}

	window->surface = surface;

	//picking physical device//
}
