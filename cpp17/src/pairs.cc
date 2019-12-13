#include "util.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main()
{
  // Make a basic pair
  auto p = std::make_pair(10, 10);
  // Print the values
  std::cout << "First: " << p.first << ", "
            << "Second: " << p.second << '\n';

  // Vector of some strings
  auto languages = std::vector<std::string>{"C++", "C", "Python", "Java"};
  // Pair of string and vector
  auto my_pair = std::make_pair("Languages", languages);

  std::cout << "First: " << my_pair.first << ", ";
  std::cout << "Second: ";
  util::print_vector(my_pair.second);

  return 0;
}
