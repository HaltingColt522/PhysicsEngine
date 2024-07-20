#include <win32Window.h>
#include <windowproc.h>

void Window::setup() {
    //only execute once
    LPCSTR CLASS_NAME = "engine";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;
    wc.cbWndExtra = sizeof(LONG_PTR);

    RegisterClass(&wc);
}

HWND Window::create(VkInstance instance, LPCSTR winheader) {
    WINDOW* window = new WINDOW; // this is delteted in windowproc, i hope

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

    Vulkan::winsetup(window, instance, hwnd);

    SetWindowLongPtr(hwnd, 0, (LONG_PTR)window); // store window struct in hwnd

    return hwnd;
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