#include <algorithm>
#include <iostream>
#include <vector>

#include "util.h"

void transform_demo() {
  // Config parameters
  const int size = 10;
  const int fill_value = 17;

  // Create original vector and fill w/ sentinel
  auto vec = std::vector<int>(size, fill_value);

  // Create container for result of `std::transform`
  auto results = std::vector<int>();
  // Original values so we can see `back_inserter` benefits
  results.push_back(0);
  results.push_back(0);
  results.push_back(0);

  // Add each element to itself and append to results
  std::transform(std::begin(vec), std::end(vec), std::back_inserter(results),
                 [] (const auto x) { return x + x; });

  // Print results
  std::cout << "Original vector:" << '\n';
  util::print_vector(vec);
  std::cout << "Result vector:" << '\n';
  util::print_vector(results);
}

void dummy_demo() {}

// All demo functions should follow this format
using demo_function_t = decltype(&transform_demo);

void announce_and_execute(const std::string& name, demo_function_t demo_fn) {
  // Common strings to print
  const auto suffix = std::string{" Demo:\n"};
  const auto sep = std::string{"****************************\n"};

  // Print name of demo w/ separators
  std::cout << sep;
  std::cout << name << suffix;
  std::cout << sep << '\n';
  // Call demo function
  demo_fn();
  // Print separator
  std::cout << sep << '\n';
}

int main() {
  // List of demo names and related function pointer
  const auto demo_list = std::vector<std::pair<std::string, demo_function_t>>{
      {"Transform", transform_demo},
      {"Dummy", dummy_demo},
  };

  // Apply the `announce_and_execute` function to all [name, function] pairs
  // in the list of demos
  std::for_each(std::begin(demo_list), std::end(demo_list),
                [] (auto& p) { std::apply(announce_and_execute, p); });
}
