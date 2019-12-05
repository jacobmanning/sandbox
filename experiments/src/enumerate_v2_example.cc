#include "enumerate_v2.hh"

#include <array>
#include <iostream>
#include <string>

auto main() -> int {
  auto a = std::array<std::string, 7>{"hello", "world", "vim",   "is",
                                      "the",   "best",  "editor"};
  for (auto&& [idx, el] : enumerate(a))
  {
    std::cout << idx << ", " << el << '\n';
  }
}
