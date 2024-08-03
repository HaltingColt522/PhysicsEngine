#include <vkSetup/syncObject.h>

void createSyncObjects(WINDOW* window) {
    window->imageAvailableSemaphores.resize(Const::MAX_FRAMES_IN_FLIGHT);
    window->renderFinishedSemaphores.resize(Const::MAX_FRAMES_IN_FLIGHT);
    window->inFlightFences.resize(Const::MAX_FRAMES_IN_FLIGHT);

    VkSemaphoreCreateInfo semaphoreInfo{};
    semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    VkFenceCreateInfo fenceInfo{};
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    for (size_t i = 0; i < Const::MAX_FRAMES_IN_FLIGHT; i++) {
        if (vkCreateSemaphore(window->device, &semaphoreInfo, nullptr, &window->imageAvailableSemaphores[i]) != VK_SUCCESS ||
            vkCreateSemaphore(window->device, &semaphoreInfo, nullptr, &window->renderFinishedSemaphores[i]) != VK_SUCCESS ||
            vkCreateFence(window->device, &fenceInfo, nullptr, &window->inFlightFences[i]) != VK_SUCCESS) {

            throw std::runtime_error("failed to create synchronization objects for a frame!");
        }
    }
}