#include <vkSetup.h>
#include <isDeviceSuitable.h>


VkPhysicalDevice pickPhysicalDevice(VkPhysicalDevice physicalDevice, QueueFamilyIndices QIndices, VkSurfaceKHR surface, std::vector<VkPhysicalDevice> physicalDevices) {
	for (const auto& device : physicalDevices) {
		if (isDeviceSuitable(device, surface)) {
			physicalDevice = device;
			QIndices = findQueueFamilies(device, surface);
			std::cout << "SUITABLE" << std::endl;	//debug
			break;
		}
	}

	if (physicalDevice == VK_NULL_HANDLE) {
		throw std::runtime_error("failed to find right queue family");
	}

}

void Vulkan::winsetup(WINDOW* window, VkInstance instance) {

	//creating VKSURFACE //

	VkSurfaceKHR surface;

	VkWin32SurfaceCreateInfoKHR surfaceCreateInfo = {};
	surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
	surfaceCreateInfo.pNext = NULL;
	surfaceCreateInfo.flags = 0;
	surfaceCreateInfo.hinstance = GetModuleHandle(NULL);
	surfaceCreateInfo.hwnd = window->handle;

	if (vkCreateWin32SurfaceKHR(instance, &surfaceCreateInfo, NULL, &surface) != VK_SUCCESS) {
		throw std::runtime_error("failed to create VkSurface for win32 window");
	}

	window->surface = surface;

	//search for physical devices//
	
	uint32_t physicalDeviceCount = 0;
	
	if (vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, nullptr) != VK_SUCCESS) {
		throw std::runtime_error("failed to find GPU with Vulkan support");
	}

	std::vector<VkPhysicalDevice> physicalDevices(physicalDeviceCount); // vector to list all physical devices //
	if (vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, physicalDevices.data()) != VK_SUCCESS) {
		throw std::runtime_error("failed to list physical devices");
	}

	// search for right physical device with right queue families //

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	QueueFamilyIndices indices;

	pickPhysicalDevice(physicalDevice, indices, surface, physicalDevices);

	std::cout << physicalDeviceCount << std::endl;	// debug
	std::cout << physicalDevices[0] << std::endl;	// debug
}