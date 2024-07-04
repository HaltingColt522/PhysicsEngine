#include <main.h>
#include <vkSetup.h>
#include <win32Window.h>

int main() {
	VKSETUP setup; //Instance and DebugMessenger
	WINDOW window1, window2;

	Vulkan::instance(&setup); //creates the instance and debugmessenger

	Window::setup();

	Window::create(&window1, setup.instance, "test1");
	Window::create(&window2, setup.instance, "test2");

	std::vector<HWND> win_handle_list;
	win_handle_list.push_back(window1.handle);
	win_handle_list.push_back(window2.handle);

	Window::mainloop(&win_handle_list);
}