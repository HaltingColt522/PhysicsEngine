#include <main.h>

void Window::create(VkInstance instance, LPCSTR wintext) {
	createSurface(instance, createwin32window(wintext));
}

HWND Window::createwin32window(LPCSTR wintext) {
    // Register the window class.
    LPCSTR CLASS_NAME = "PhysicsEngine";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        wintext,    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        GetModuleHandle(NULL),  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL) {
        std::runtime_error("failed to create win32 window");
    }

    ShowWindow(hwnd, 1);

    return hwnd;
}

void Window::createSurface(VkInstance instance, HWND hwnd) {

    VkWin32SurfaceCreateInfoKHR surfaceInfo{};
	surfaceInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
	surfaceInfo.pNext = NULL;
	surfaceInfo.flags = 0;
	surfaceInfo.hinstance = GetModuleHandle(NULL);
    surfaceInfo.hwnd = hwnd;


	if (vkCreateWin32SurfaceKHR(instance, &surfaceInfo, NULL, &surface) != VK_SUCCESS) {
		throw std::runtime_error("failed to create win32 surface");
	}
}