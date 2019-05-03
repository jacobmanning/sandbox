#include "util.h"

#include <iostream>
#include <tuple>

int main() {
    // Create a tuple
    auto my_tuple = std::make_tuple(std::string{"Jacob"}, 20, 0);
    // Print original values
    util::print_tuple(my_tuple);

    // Access members by value
    auto name = std::get<0>(my_tuple);
    auto age = std::get<1>(my_tuple);

    // Attempt to change members by copy
    name = "Roger";
    age = 27;

    // Print our copies to show new values
    std::cout << "Name: " << name << ". Age: " << age << '\n';

    // We only changed our copy, the tuple values haven't changed
    util::print_tuple(my_tuple);

    // Can modify directly like this
    std::get<0>(my_tuple) = "Roger";
    std::get<1>(my_tuple) = 27;
    std::get<2>(my_tuple) = 27;

    // Print to show that values have now changed
    util::print_tuple(my_tuple);

    // Or can get reference and modify that reference
    auto& name_ref = std::get<0>(my_tuple);
    auto& age_ref = std::get<1>(my_tuple);
    auto& num_ref = std::get<2>(my_tuple);

    // Modify values in tuple with reference
    name_ref = "Jacob!";
    age_ref = 200;
    num_ref = 4;

    // Print to show that values have changed again
    util::print_tuple(my_tuple);

    // Can also use C++17 structured bindings
    auto& [name_ref_v2, age_ref_v2, num_ref_v2] = my_tuple;

    // Modify by ref again
    name_ref_v2 = "Jaaaaacob";
    age_ref_v2 = 1337;
    num_ref_v2 = 7;

    // Print to show that values have changed again
    util::print_tuple(my_tuple);

    return 0;
}
