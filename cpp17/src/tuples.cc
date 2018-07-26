/**
 * @author  Jacob Manning
 * @brief   std::tuple functions
 */

#include <util.h>
#include <iostream>
#include <tuple>

int main(int argc, const char** argv) {
    // Create a tuple
    auto my_tuple = std::make_tuple(std::string("Jacob"), 20, 0);
    // Print original values
    util::print_tuple(my_tuple);

    // Access members by value
    std::string name = std::get<0>(my_tuple);
    int age = std::get<1>(my_tuple);

    // Attempt to change members by copy
    name = "Roger";
    age = 27;

    // Print our copies to show new values
    std::cout << "Name: " << name << ". Age: " << age << std::endl;

    // We only changed our copy, the tuple values haven't changed
    util::print_tuple(my_tuple);

    // Can modify directly like this
    std::get<0>(my_tuple) = "Roger";
    std::get<1>(my_tuple) = 27;
    std::get<2>(my_tuple) = 27;

    // Print to show that values have now changed
    util::print_tuple(my_tuple);

    // Or can get reference and modify that reference
    std::string& name_ref = std::get<0>(my_tuple);
    int& age_ref = std::get<1>(my_tuple);
    int& num_ref = std::get<2>(my_tuple);

    // Modify values in tuple with reference
    name_ref = "Jacob!";
    age_ref = 200;
    num_ref = 4;

    // Print to show that values have changed again
    util::print_tuple(my_tuple);

    return 0;
}
