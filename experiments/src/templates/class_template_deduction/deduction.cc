#include "deduction_dummy.hh"

int main()
{
  auto d = util::deduction_dummy{1, true, 2.f};
  auto d2 = util::deduction_dummy{1, 2.f};
}
