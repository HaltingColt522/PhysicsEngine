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

	/*	******************* BIG TODO *******************
	*	Fix cleanup function. The  function  underneath
	*	cannot  destroy  everything.  Probably  has  to 
	*	include   in   Windowproc -> case WM_NCDESTROY.
	*/

	//Window::cleanupAllWindows(window_list, instance);

	Vulkan::destroyInstance(&instance);
}