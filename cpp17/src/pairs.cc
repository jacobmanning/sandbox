#include "util.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    // Make a basic pair
    auto p1 = std::make_pair(10, 10);
    // Print the values
    std::cout << "First: " << p1.first << ", "
              << "Second: " << p1.second << std::endl;

    // Vector of some strings
    auto languages = std::vector<std::string>{"C++", "C", "Python", "Java"};
    // Pair of string and vector
    auto person = std::make_pair("Languages", languages);

    std::cout << "First: " << person.first << ", ";
    std::cout << "Second: ";
    util::print_vector(person.second);

    return 0;
}
