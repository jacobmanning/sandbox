/**
 * @author  Jacob Manning
 * @brief   Example usage of lambdas
 */

#include "util.h"

#include <algorithm>
#include <iostream>
#include <vector>

#define CPP14 201402L
#define CPP11 201103L

int main()
{
  // Vector with some integers
  auto v = std::vector<int>{-1, -2, 3, 4, 5};
  util::print_vector(v);

#if __cplusplus >= CPP14
  // C++14 can do auto type deduction
  // Get iterator to first positive element in v
  auto it = std::find_if(std::begin(v), std::end(v), [](auto x) { return x > 0; });
#elif __cplusplus >= CPP11
  // Explicit int parameter for lambda needed in C++11
  // Get iterator to first positive element in v
  auto it = std::find_if(std::begin(v), std::end(v), [](int x) { return x > 0; });
#else
#error Please compile with at least C++11
#endif

  if (it != std::end(v))
  {
    std::cout << "Positive value in v: " << *it << std::endl;
  }
  else
  {
    std::cout << "No positive values in v" << std::endl;
  }

  return 0;
}
