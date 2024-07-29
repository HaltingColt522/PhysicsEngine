#pragma once

#include <main.h>
#include <vkSetup/vkSetup.h>

namespace Window {
	void setup(VkInstance instance);
	HWND create(VkInstance instance, LPCSTR winheader);
}