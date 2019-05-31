#include "enumerate.hh"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

auto basic_cases() {
  auto v = std::vector<std::string>{"hello", "world", "vim",   "is",
                                    "the",   "best",  "editor"};

  util::enumerate(std::begin(v), std::end(v), [](auto&& idx, auto&& element) {
    std::cout << idx << ", " << element << '\n';
  });

  auto mult_idx_by_two = [](const int idx, const std::string& element) {
    std::cout << idx * 2 << ", " << element << '\n';
  };
  util::enumerate(std::begin(v), std::end(v), mult_idx_by_two);
}

auto modifying_cases() {
  auto v = std::vector<std::string>{"hello", "world", "vim",   "is",
                                    "the",   "best",  "editor"};

  auto printer = [](auto&& idx, auto&& element) {
    std::cout << idx << ", " << element << '\n';
  };

  auto element_reverser = []([[maybe_unused]] auto&& idx, auto&& element) {
    std::reverse(std::begin(element), std::end(element));
  };

  // `enumerate` only used here to demonstrate that it can modify elements of
  // collection
  util::enumerate(std::begin(v), std::end(v), element_reverser);
  util::enumerate(std::begin(v), std::end(v), printer);
}

auto advanced_cases() {
  auto v = std::vector<std::string>{"hello", "world", "vim",   "is",
                                    "the",   "best",  "editor"};
  auto third_necessary_parameter = int{31};

  auto ternary_operand_function = [](auto&& idx, auto&& element,
                                     auto&& magic_num) {
    std::cout << idx << ", " << element << ", " << magic_num << '\n';
  };

  auto bof = [&third_necessary_parameter, &ternary_operand_function](
                 auto&& idx, auto&& element) {
    ternary_operand_function(idx, element, third_necessary_parameter);
  };

  util::enumerate(std::begin(v), std::end(v), bof);
}

auto failure_cases() {
  auto v = std::vector<std::string>{"hello", "world", "vim",   "is",
                                    "the",   "best",  "editor"};

  /// ERROR: 3 is not callable
  // util::enumerate(std::begin(v), std::end(v), 3);

  /// ERROR: 3 is not an iterator
  // util::enumerate(3, 3, [] () {});

  /// ERROR: Lambda parameters and return type do not match iterator
  // util::enumerate(std::begin(v), std::end(v), [] (const int x, const int y) {
  //   return x + y;
  // });
}

auto main() -> int {
  basic_cases();
  modifying_cases();
  advanced_cases();
}
