#pragma once
#include <main.h>

//TODO: Move Contents to windowproc.cpp

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    //getting info about window
    WINDOW* window = (WINDOW*)GetWindowLongPtr(hwnd, 0);

    switch (uMsg)
    {
    case WM_CLOSE: {
        DestroyWindow(hwnd);
    }
    return 0;
    case WM_NCDESTROY: {
        //Vulkan::cleanup(window, instance);
        delete window;
    }

    return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}