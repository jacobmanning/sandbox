#include <iostream>

namespace util
{

// Forward declare for swap function
class CustomHiddenSwapClass;

namespace impl
{

void swap(CustomHiddenSwapClass& one, CustomHiddenSwapClass& two);

}  // namespace impl

class CustomHiddenSwapClass
{
public:
  CustomHiddenSwapClass() = default;
  CustomHiddenSwapClass(int a, int b);

  void swap(CustomHiddenSwapClass& other);
  friend void impl::swap(CustomHiddenSwapClass& one, CustomHiddenSwapClass& two);

  void print(std::ostream& out = std::cout) const;

private:
  int a_;
  int b_;
};

// This operator is found by ADL even though it's in an enclosing namespace
std::ostream& operator<<(std::ostream& os, const util::CustomHiddenSwapClass& mc);

}  // namespace util
