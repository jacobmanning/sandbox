#include "deduction_dummy.hh"

int main()
{
  auto d = util::deduction_dummy{1, 2.f, true};
  auto d2 = util::deduction_dummy{1, true};
}
