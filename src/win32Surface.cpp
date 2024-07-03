#include <main.h>
#include <windowproc.h>

void Window::setup() {
    //only execute once
    LPCSTR CLASS_NAME = "engine";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);
}

WINDOW Window::create(VkInstance instance, LPCSTR winheader) {
    WINDOW window = {};

    // creating win32 window //

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        "engine",                     // Window class
        winheader,    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        GetModuleHandle(NULL),  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        throw std::runtime_error("failed to create win32 window");
    }

    ShowWindow(hwnd, 1);

    window.handle = hwnd;

    // creating VkSurface //

    VkSurfaceKHR surface = NULL;

    VkWin32SurfaceCreateInfoKHR win32createinfo = {};
    win32createinfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
    win32createinfo.pNext = NULL;
    win32createinfo.flags = NULL;
    win32createinfo.hinstance = GetModuleHandle(NULL);
    win32createinfo.hwnd = hwnd;

    if (vkCreateWin32SurfaceKHR(instance, &win32createinfo, NULL, &surface) != VK_SUCCESS) {
        throw std::runtime_error("failed to create vksurface");
    }

    window.surface = surface;

    return window;
}

void Window::mainloop(std::vector<HWND>* win_handle) {
    MSG msg = { };
    bool NOWINDOW = TRUE;

    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {   
        //check if there is a window
        for (HWND window : *win_handle) {
            if (IsWindow(window)) { NOWINDOW = FALSE; }
        }

        if (NOWINDOW == FALSE) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            PostQuitMessage(0);
        }
        NOWINDOW = TRUE;
    }
}