#include "CustomHiddenSwapClass.hh"

#include <algorithm>
#include <iostream>

namespace util
{

namespace impl
{

void swap(CustomHiddenSwapClass& one, CustomHiddenSwapClass& two)
{
  std::cerr << "util::swap(CustomHiddenSwapClass&, CustomHiddenSwapClass&)\n";
  one.swap(two);
}

}  // namespace impl

CustomHiddenSwapClass::CustomHiddenSwapClass(int a, int b) : a_{a}, b_{b}
{
}

void CustomHiddenSwapClass::print(std::ostream& out) const
{
  out << "[CustomHiddenSwapClass] a_ = " << a_ << ", b_" << b_;
}

void CustomHiddenSwapClass::swap(CustomHiddenSwapClass& other)
{
  std::cerr << "CustomHiddenSwapClass::swap(CustomHiddenSwapClass&)\n";
  std::swap(a_, other.a_);
  std::swap(b_, other.b_);
}

std::ostream& operator<<(std::ostream& os, const util::CustomHiddenSwapClass& mc)
{
  mc.print(os);
  return os;
}

}  // namespace util
