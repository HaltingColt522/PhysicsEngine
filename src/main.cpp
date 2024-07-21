/*
 * ************************** PHYSICS - ENGINE ******************************
 * Project: PhysicsEngine
 * Filename: main.cpp
 * Description:
 * Author: github/tilschaller ||| github/HaltingColt522
 * Created: 2024-04-07 11:35 pm UTC 
 * Last Modified: 2024-07-17
 * Version: 1.0.X It will become 1.1 when Win32 is merged into Main
 * Dependencies: <iostream>
 * **************************************************************************
 */

#include <main.h>
#include <vkSetup/vkSetup.h>
#include <win32Window.h>

int main() {
	INSTANCE instance; // Instance and DebugMessenger //

	Vulkan::setupInstance(&instance); // creates the instance and debugmessenger // 

	Window::setup();

	std::vector<HWND> win_handle_list;

	win_handle_list.push_back(Window::create(instance.instance, "test1"));
	win_handle_list.push_back(Window::create(instance.instance, "test2"));

	Window::mainloop(&win_handle_list);

	std::cout << win_handle_list.size();

	Vulkan::destroyInstance(&instance);
}