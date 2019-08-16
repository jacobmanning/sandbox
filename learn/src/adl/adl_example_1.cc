#include "CustomSwapClass.hh"
#include "CustomHiddenSwapClass.hh"
#include "NoCustomSwapClass.hh"

#include <algorithm>
#include <iostream>

using util::CustomSwapClass;
using util::CustomHiddenSwapClass;
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
  // ADL still finds util::operator<< for CustomSwapClass
  // because it is in the enclosing namespace of CustomSwapClass
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
  // ADL still finds util::operator<< for NoCustomSwapClass
  // because it is in the enclosing namespace of NoCustomSwapClass
  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n' << '\n';

  // Will use ADL to find std::swap
  do_the_swap(x, y);

  std::cout << "\nAFTER SWAP\n";
  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n' << '\n';
}

void custom_hidden_swappable()
{
  auto x = CustomHiddenSwapClass(5, 6);
  auto y = CustomHiddenSwapClass(7, 8);

  std::cout << "BEFORE SWAP\n";
  // ADL still finds util::operator<< for CustomHiddenSwapClass
  // because it is in the enclosing namespace of CustomHiddenSwapClass
  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n' << '\n';

  // Will use ADL to find std::swap, not util::impl::swap
  // -> ADL will not look into `impl` namespace, only the
  // "innermost enclosing namespaces in the classes added
  // to the set [of associated namespaces and classes]"
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

  std::cout << "*************************\n";
  std::cout << "*************************\n\n";

  std::cout << "CustomHiddenSwapClass\n";
  custom_hidden_swappable();
}
