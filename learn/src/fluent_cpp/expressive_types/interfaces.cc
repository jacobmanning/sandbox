#include <iostream>

#include <rectangle.hh>
#include <units.hh>

int main()
{
  auto r1 = v1::Rectangle{10, 5};
  auto r2 = v2::Rectangle{v2::Width{10}, v2::Height{5}};
  auto r3 = v3::Rectangle{v3::Width{11.5_meter}, v3::Height{5_meter}};
}
