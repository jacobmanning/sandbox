#include "util.h"

#include <iostream>
#include <vector>

int main() {
    // Sample vector
    auto v = std::vector<int>{1, 2, 3, 4, 5};

    // Square each value in v
    for (auto& a : v) {
        // Can modify the actual variable because we have a reference
        a = a * a;
    }

    // Print out each squared value
    util::print_vector(v);

    return 0;
}
