#include <future>
#include <iostream>

int my_call() {
    std::cout << "This is my async call!" << std::endl;
    return 1337;
}

int main() {
    // Create an async call to the future
    auto x = std::async(my_call);

    // Show that we are running in main
    std::cout << "Hello from main!" << std::endl;

    // Get the future
    std::cout << "Future returned: " << x.get() << std::endl;
}
