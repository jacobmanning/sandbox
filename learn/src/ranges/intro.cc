#include <iostream>
#include <range/v3/all.hpp>
#include <vector>

namespace util
{

auto print_element = [](const auto& element) { std::cout << element << " "; };

auto is_even = [](const auto& number) { return number % 2 == 0; };

auto multiply_by_two = [](const auto& number) { return number * 2; };

} // namespace util

int main()
{
  auto numbers = std::vector<int>{1, 2, 3, 4, 5};

  auto even_numbers = numbers | ranges::views::filter(util::is_even);
  std::cout << "Even numbers:"
            << "\n";
  ranges::for_each(even_numbers, util::print_element);

  std::cout << "\n"
            << "Even numbers multiplied by two:"
            << "\n";
  auto even_numbers_by_two = numbers | ranges::views::filter(util::is_even) |
                             ranges::views::transform(util::multiply_by_two);
  ranges::for_each(even_numbers_by_two, util::print_element);
}
