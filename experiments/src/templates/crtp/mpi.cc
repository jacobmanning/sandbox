#include <iostream>

#include <matrix.hh>
#include <matrix_multiply.hh>
#include <matrix_multiply_mpi.hh>

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

  auto mpi_multiplier = util::matrix_multiply_mpi{};
  auto result = mpi_multiplier.multiply(m1, m2);
  std::cout << "\nMPI Result:" << '\n';
  result.print();
}
