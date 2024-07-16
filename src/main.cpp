#include <main.h>
#include <vkSetup/vkSetup.h>
#include <win32Window.h>

int main() {
	INSTANCE instance; //Instance and DebugMessenger
	WINDOW window1, window2;

	Vulkan::instance(&instance); //creates the instance and debugmessenger

	Window::setup();

	Window::create(&window1, instance.instance, "test1");
	Window::create(&window2, instance.instance, "test2");

	std::vector<HWND> win_handle_list;
	win_handle_list.push_back(window1.handle);
	win_handle_list.push_back(window2.handle);

	Window::mainloop(&win_handle_list);

	/*	TODO: make one func to cleanup everything at once.Maybe use a for loop to destroy all
		stuff of every single window. I guesse we just need a list of windows for it, to access 
		every element on the list -> element represents a window.

		Idea:
		std::vector<WINDOW> win_list;

		for(uint32_t i=0; win_list.size(); i++) {
			Vulkan::cleanup(&win_list[i], instance);
		}

		I have to think about it later. For now i´ll just hardcode it for every single window.
	*/

	Vulkan::cleanup(&window1, instance);
	Vulkan::cleanup(&window2, instance);

	Vulkan::destroyInstance(&instance);
}