/**
 * @author  Jacob Manning
 * @brief   std::vector functions
 */

#include "util.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

int main() {
    // Create a sample vector
    auto v = std::vector<std::string>{"foo", "bar"};
    std::cout << "My word vector" << std::endl;
    util::print_vector(v);

    // Seed random number generator
    std::srand(unsigned(std::time(nullptr)));

    // Init vectors for our numbers
    auto rand_vec = std::vector<int>(8);
    auto count_vec = std::vector<int>(8);

    // Vector of random numbers w/ lambda
    std::generate(std::begin(rand_vec), std::end(rand_vec),
                  []() { return std::rand() % 100; });

    // Counter for our count_vec
    int counter = 0;
    std::generate(std::begin(count_vec), std::end(count_vec),
                  [&counter]() { return ++counter; });

    // Print random vector
    std::cout << "Random vector:" << std::endl;
    util::print_vector(rand_vec);

    // Print counter vector
    std::cout << "Counter vector:" << std::endl;
    util::print_vector(count_vec);

    return 0;
}
