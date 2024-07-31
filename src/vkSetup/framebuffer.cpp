#include <vkSetup/framebuffer.h>


void createFramebuffer(WINDOW* window) {
    window->swapChainFramebuffers.resize(window->swapChainImageViews.size());

    for (size_t i = 0; i < window->swapChainImageViews.size(); i++) {
        VkImageView attachments[] = {
            window->swapChainImageViews[i]
        };

        VkFramebufferCreateInfo framebufferInfo{};
        framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        framebufferInfo.renderPass = window->renderPass;
        framebufferInfo.attachmentCount = 1;
        framebufferInfo.pAttachments = attachments;
        framebufferInfo.width = window->swapChainExtent.width;
        framebufferInfo.height = window->swapChainExtent.height;
        framebufferInfo.layers = 1;

        if (vkCreateFramebuffer(window->device, &framebufferInfo, nullptr, &window->swapChainFramebuffers[i]) != VK_SUCCESS) {
            throw std::runtime_error("failed to create framebuffer!");
        }
    }
}