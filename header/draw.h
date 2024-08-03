#pragma once

#include <main.h>

namespace Draw{
	void createGraphicsPipeline(HWND hwnd, const std::string& vertex_shader_path, const std::string& frag_shader_path);
	void recordCommandBuffer(HWND hwnd, uint32_t imageIndex, uint32_t graphicsPipelineIndex);
	void drawFrame(HWND hwnd); //TODO: remove or alter when it isnt needed anymore
}