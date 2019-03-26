#include <iostream>

#include <units.hh>

void print_distance(const units::Meter x)
{
  std::cout << x << "m\n";
}

int main()
{
  print_distance(1_kilometer + 200_meter);
}
