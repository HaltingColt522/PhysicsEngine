#pragma once

#include <main.h>
#include <vkSetup/vkSetup.h>

namespace Window {
	void setup();
	HWND create(VkInstance instance, LPCSTR winheader);

	void mainloop(std::vector<HWND>* win_handle_list);
}