#include "CustomSwapClass.hh"
#include "NoCustomSwapClass.hh"

#include <algorithm>
#include <iostream>

using util::CustomSwapClass;
using util::NoCustomSwapClass;

/// @brief Uses ADL to find appropriate swap
template <typename Class>
void do_the_swap(Class& one, Class& two)
{
  using std::swap;
  swap(one, two);
}

void custom_swappable()
{
  auto x = CustomSwapClass(1, 2);
  auto y = CustomSwapClass(3, 4);

  std::cout << "BEFORE SWAP\n";
  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n' << '\n';

  // Will use ADL to find util::swap
  do_the_swap(x, y);

  std::cout << "\nAFTER SWAP\n";
  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n' << '\n';
}

void no_custom_swappable()
{
  auto x = NoCustomSwapClass(5, 6);
  auto y = NoCustomSwapClass(7, 8);

  std::cout << "BEFORE SWAP\n";
  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n' << '\n';

  // Will use ADL to find std::swap
  do_the_swap(x, y);

  std::cout << "\nAFTER SWAP\n";
  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n' << '\n';
}

int main()
{
  std::cout << "CustomSwapClass\n";
  custom_swappable();

  std::cout << "*************************\n\n";

  std::cout << "NoCustomSwapClass\n";
  no_custom_swappable();
}
