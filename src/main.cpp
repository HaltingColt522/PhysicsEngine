#include <main.h>
#include <vkSetup/vkSetup.h>
#include <win32Window.h>
#include <draw.h>

int main() {
	////////////////////////////
	//       SETUP            //
	///////////////////////////

	INSTANCE instance;

	Vulkan::setupInstance(&instance);

	Window::setup(instance.instance);

	///////////////////////////
	//  CREATE WINDOW/S      //
	///////////////////////////

	std::vector<HWND> win_handle_list;

	win_handle_list.push_back(Window::create(instance.instance, "Physics Engine"));

	// create graphicsPipeline //
	VkPipeline graphicsPipeline;
	Draw::createGraphicsPipeline(win_handle_list[0], "shaders/vert.spv", "shaders/frag.spv");

	////////////////////////////
	//      MAINLOOP          //
	////////////////////////////

	MSG msg = { };
	bool NOWINDOW = TRUE;
	int counter = -1;

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		//check if there is a window
		for (HWND window : win_handle_list) {
			counter += 1;
			if (IsWindow(window)) { NOWINDOW = FALSE; }
			else { win_handle_list.erase(win_handle_list.begin() + counter); }
		}
		counter = -1;

		if (NOWINDOW == FALSE) {
			Draw::drawFrame(win_handle_list[0]); //maybe this shouls 
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			PostQuitMessage(0);
		}
		NOWINDOW = TRUE;
	}

	///////////////////////////////
	//       CLEANUP             //
	///////////////////////////////

	Vulkan::destroyInstance(&instance);
}