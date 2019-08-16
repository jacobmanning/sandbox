#include "NoCustomSwapClass.hh"

#include <algorithm>
#include <iostream>

namespace util
{

NoCustomSwapClass::NoCustomSwapClass(int a, int b) : a_{a}, b_{b}
{
}

void NoCustomSwapClass::print(std::ostream& out) const
{
  out << "[NoCustomSwapClass] a_ = " << a_ << ", b_" << b_;
}

std::ostream& operator<<(std::ostream& os, const util::NoCustomSwapClass& mc)
{
  mc.print(os);
  return os;
}

}  // namespace util
