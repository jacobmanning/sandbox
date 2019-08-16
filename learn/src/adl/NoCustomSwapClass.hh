#include <iostream>

namespace util
{

class NoCustomSwapClass
{
public:
  NoCustomSwapClass() = default;
  NoCustomSwapClass(int a, int b);

  void print(std::ostream& out = std::cout) const;

private:
  int a_;
  int b_;
};

}  // namespace util

std::ostream& operator<<(std::ostream& os, const util::NoCustomSwapClass& mc);
