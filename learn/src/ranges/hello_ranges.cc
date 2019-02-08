#include <iostream>
#include <vector>

#include <range/v3/all.hpp>

namespace util {

auto print_element = [] (const auto& element) {
  std::cout << element << " ";
};

template <class T>
void print_vector(const std::vector<T>& v) {
    ranges::for_each(v, print_element);
    std::cout << "\n\n";
}

}  // namespace util

int main() {
  auto my_vector = std::vector<int>{4, 1, 2, 6, 9, 3};

  std::cout << "Before sort:" << "\n";
  util::print_vector(my_vector);

  ranges::sort(my_vector);

  std::cout << "After sort:" << "\n";
  util::print_vector(my_vector);
}
