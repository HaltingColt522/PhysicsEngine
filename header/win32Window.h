#pragma once

#include <main.h>
#include <vkSetup/vkSetup.h>

namespace Window {
	void setup();
	void create(WINDOW* window, VkInstance instance, LPCSTR winheader);

	void mainloop(std::vector<HWND>* win_handle);
}