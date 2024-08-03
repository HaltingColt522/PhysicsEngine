#include <vkSetup/vkSetup.h>

#include <vkSetup/physicalDevice.h>
#include <vkSetup/logicalDevice.h>
#include <vkSetup/swapchain/swapchain.h>
#include <vkSetup/imageView.h>
#include <vkSetup/debug.h>
#include <vkSetup/renderPass.h>
#include <vkSetup/framebuffer.h>
#include <vkSetup/command.h>
#include <vkSetup/syncObject.h>

void Vulkan::winsetup(WINDOW* window, VkInstance instance, HWND handle) {

	VkWin32SurfaceCreateInfoKHR surfaceCreateInfo = {};
	surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
	surfaceCreateInfo.pNext = NULL;
	surfaceCreateInfo.flags = 0;
	surfaceCreateInfo.hinstance = GetModuleHandle(NULL);
	surfaceCreateInfo.hwnd = handle;

	if (vkCreateWin32SurfaceKHR(instance, &surfaceCreateInfo, NULL, &window->surface) != VK_SUCCESS) {
		throw std::runtime_error("failed to create VkSurface for win32 window");
	}

	pickPhysicalDevice(window, instance);

	createLogicalDevice(window);

	createSwapChain(window, handle);

	createImageViews(window);

	createRenderPass(window);

	createFramebuffer(window);

	createCommandPool(window);

	createCommandBuffers(window);

	createSyncObjects(window);
}

void Vulkan::cleanup(WINDOW* window, VkInstance instance) {
	vkDeviceWaitIdle(window->device);

	cleanupSwapchain(window);
	
	vkDestroySurfaceKHR(instance, window->surface, nullptr);

	vkDestroyRenderPass(window->device, window->renderPass, nullptr);

	for (VkPipeline graphicsPipeline : window->graphicsPipeline) {
		vkDestroyPipeline(window->device, graphicsPipeline, nullptr);
	}

	vkDestroyCommandPool(window->device, window->commandPool, nullptr);

	for (size_t i = 0; i < Const::MAX_FRAMES_IN_FLIGHT; i++) {
		vkDestroySemaphore(window->device, window->renderFinishedSemaphores[i], nullptr);
		vkDestroySemaphore(window->device, window->imageAvailableSemaphores[i], nullptr);
		vkDestroyFence(window->device, window->inFlightFences[i], nullptr);
	}

	vkDestroyDevice(window->device, nullptr);
}