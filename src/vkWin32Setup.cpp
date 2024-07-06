#include <vkSetup.h>

void Vulkan::winsetup(WINDOW* window, VkInstance instance) {
	HINSTANCE hinst = GetModuleHandleA(nullptr);

	VkSurfaceKHR surface;

	VkWin32SurfaceCreateInfoKHR surfaceCreateInfo;
	surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
	surfaceCreateInfo.pNext = NULL;
	surfaceCreateInfo.flags = 0;
	surfaceCreateInfo.hinstance = hinst;
	surfaceCreateInfo.hwnd = window->handle;
}
