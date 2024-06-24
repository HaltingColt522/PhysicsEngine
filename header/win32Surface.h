#pragma once

#include <main.h>

class Window {
public:
	void create(VkInstance instance, LPCSTR wintext);
private:
	VkSurfaceKHR surface;

	HWND createwin32window(LPCSTR wintext);
	void createSurface(VkInstance instance, HWND hwnd);

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        switch (uMsg)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
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
};