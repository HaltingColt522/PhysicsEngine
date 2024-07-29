#pragma once

#include <main.h>

namespace Draw{
	void createGraphicsPipeline(HWND hwnd, const std::string& vertex_shader_path, const std::string& frag_shader_path);
}