#include <iostream>

#include <matrix.hh>
#include <matrix_multiply.hh>

int main()
{
  auto m1 = util::matrix<int, 3, 3>{};
  auto m2 = util::matrix<int, 3, 3>{};

  m1.fill_random();
  m2.fill_random();

  std::cout << "Matrix 1:" << '\n';
  m1.print();
  std::cout << "\nMatrix 2:" << '\n';
  m2.print();

  auto naive_multiplier = util::matrix_multiply{};
  auto result = naive_multiplier(m1, m2);
  std::cout << "\nResult:" << '\n';
  result.print();
}
