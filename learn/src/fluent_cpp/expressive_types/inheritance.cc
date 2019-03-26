#include <iostream>

#include <named_type.hh>
#include <traits.hh>

using Length = util::named_type<double, struct LengthParameter,
      traits::Addable, traits::Printable>;

int main()
{
  auto x = Length{3.4};
  auto y = Length{5.6};

  auto total = x + y;
  std::cout << "Total = " << total << '\n';
}
