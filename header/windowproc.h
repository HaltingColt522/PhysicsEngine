#pragma once
#include <main.h>

//TODO: Move Contents to windowproc.cpp

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // WNDCLASSA WndClass = {};
    // GetClassInfoA(GetModuleHandle(NULL), "Physics Engine", &WndClass);

    switch (uMsg)
    {
    case WM_CLOSE: {
        DestroyWindow(hwnd);
    }
    return 0;
    case WM_NCDESTROY: {
        //Vulkan::cleanup(window, instance);
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