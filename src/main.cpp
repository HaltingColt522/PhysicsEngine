#include <main.h>
#include <vkSetup/vkSetup.h>
#include <win32Window.h>

int main() {
	INSTANCE instance; // Instance and DebugMessenger //
	WINDOW window1, window2;
	std::vector<WINDOW*> window_list;

	window_list.push_back(&window1);
	window_list.push_back(&window2);

	Vulkan::setupInstance(&instance); // creates the instance and debugmessenger //

	Window::setup();

	Window::create(&window1, instance.instance, "test1");
	Window::create(&window2, instance.instance, "test2");

	std::vector<HWND> win_handle_list;
	win_handle_list.push_back(window1.handle);
	win_handle_list.push_back(window2.handle);

	Window::mainloop(&win_handle_list);

	Window::cleanupAllWindows(window_list, instance);

	Vulkan::destroyInstance(&instance);
}