#include <main.h>

int main() {
    vkInstance instance;
    Window window;

    try {
        instance.create();
        window.create(instance.instance, "Test Window");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
