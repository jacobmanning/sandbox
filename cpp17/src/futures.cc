/**
 * @author  Jacob Manning
 * @brief   Test of C++11 std::future
 */

#include <future>
#include <iostream>

int my_call(void) {
    std::cout << "This is my async call!" << std::endl;
    return 1337;
}

int main(int argc, const char** argv) {
    // Create an async call to the future
    auto x = std::async(my_call);

    // Show that we are running in main
    std::cout << "Hello from main!" << std::endl;

    // Get the future
    std::cout << "Future returned: " << x.get() << std::endl;
}
