#include <circle.hh>
#include <iostream>

int main()
{
  auto c1 = v1::Circle{v1::Radius{3}};
  auto c2 = v1::Circle{v1::Diameter{1.5}};

  auto c3 = v2::Circle{v2::Radius{3}};
  auto c4 = v2::Circle{v2::Diameter{1.5}};
}
