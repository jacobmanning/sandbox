#include <iostream>

namespace a {
  int x = 7;
}

namespace b {
  int x = 8;
}

int x = 0;

int main() {
  int x = 0;

  x = 1;
  ::x = 2;
  a::x = 3;
  b::x = 4;

  std::cout << "x = " << x << ", address = " << &x << '\n';
  std::cout << "::x = " << ::x << ", address = " << &::x << '\n';
  std::cout << "a::x = " << a::x << ", address = " << &a::x << '\n';
  std::cout << "b::x = " << b::x << ", address = " << &b::x << '\n';
}
