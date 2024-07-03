#include <main.h>

int main() {
    vkInstance instance;
    Window::setup(); //should only be called once & should be called before using namespace !!

    try {
        instance.create();

        std::vector<HWND> win_handle_list;

        WINDOW window1 = Window::create(instance.instance, "test1");
        win_handle_list.push_back(window1.handle);
        WINDOW window2 = Window::create(instance.instance, "test2");
        win_handle_list.push_back(window2.handle);

        Window::mainloop(&win_handle_list);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
