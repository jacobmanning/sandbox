#include <iostream>
#include <vector>

#include <range/v3/all.hpp>

namespace util {

auto print_element = [] (const auto& element) {
  std::cout << element << " ";
};

auto is_even = [] (const auto& number) {
  return number % 2 == 0;
};

auto multiply_by_two = [] (const auto& number) {
  return number * 2;
};

// void print_range(const ranges::view::view_interface& range_view) {
// void print_range(const ranges::view_interface<T>& range_view) {
// void print_range(const ranges::any_view<T>& range_view) {
// template <typename T, typename U>
// void print_range(const ranges::view_adaptor<T, U>& range_view) {
//   ranges::for_each(range_view, util::print_element);
//   std::cout << "\n" << "\n";
// }

}  // namespace util

int main() {
  auto numbers = std::vector<int>{1, 2, 3, 4, 5};

  auto even_numbers = numbers | ranges::view::filter(util::is_even);
  std::cout << "Even numbers:" << "\n";
  // util::print_range(even_numbers);
  ranges::for_each(even_numbers, util::print_element);

  std::cout << "\n" << "Even numbers multiplied by two:" << "\n";
  auto even_numbers_by_two = numbers | ranges::view::filter(util::is_even)
                                     | ranges::view::transform(util::multiply_by_two);
  // util::print_range(even_numbers_by_two);
  ranges::for_each(even_numbers_by_two, util::print_element);
}
