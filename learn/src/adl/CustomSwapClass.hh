#include <iostream>

namespace util
{

// Forward declare for function
class CustomSwapClass;
void swap(CustomSwapClass& one, CustomSwapClass& two);

class CustomSwapClass
{
public:
  CustomSwapClass() = default;
  CustomSwapClass(int a, int b);

  void swap(CustomSwapClass& other);
  friend void swap(CustomSwapClass& one, CustomSwapClass& two);

  void print(std::ostream& out = std::cout) const;

private:
  int a_;
  int b_;
};

}  // namespace util

std::ostream& operator<<(std::ostream& os, const util::CustomSwapClass& mc);
