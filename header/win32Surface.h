#pragma once

#include <main.h>

struct WINDOW {
	HWND handle;
	VkSurfaceKHR surface;
};

namespace Window {
	void setup();
	WINDOW create(VkInstance instance, LPCSTR winheader);

	void mainloop(std::vector<HWND>* win_handle);
}