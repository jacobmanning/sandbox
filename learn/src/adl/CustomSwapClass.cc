#include "CustomSwapClass.hh"

#include <algorithm>
#include <iostream>

namespace util
{

void swap(CustomSwapClass& one, CustomSwapClass& two)
{
  std::cerr << "util::swap(CustomSwapClass&, CustomSwapClass&)\n";
  one.swap(two);
}

CustomSwapClass::CustomSwapClass(int a, int b) : a_{a}, b_{b}
{
}

void CustomSwapClass::print(std::ostream& out) const
{
  out << "[CustomSwapClass] a_ = " << a_ << ", b_" << b_;
}

void CustomSwapClass::swap(CustomSwapClass& other)
{
  std::cerr << "CustomSwapClass::swap(CustomSwapClass&)\n";
  std::swap(a_, other.a_);
  std::swap(b_, other.b_);
}

}  // namespace util

std::ostream& operator<<(std::ostream& os, const util::CustomSwapClass& mc)
{
  mc.print(os);
  return os;
}
