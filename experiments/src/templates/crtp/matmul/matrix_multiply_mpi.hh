#pragma once

#include <matrix.hh>
#include <matrix_multiply.hh>

namespace util
{

struct matrix_multiply_mpi_impl : matrix_multiply_impl<matrix_multiply_mpi_impl>
{
  // TODO(jacobmanning)
  template <typename T, std::size_t R1, std::size_t S, std::size_t C2>
  matrix<T, R1, C2> multiply(const matrix<T, R1, S>& a, const matrix<T, S, C2>& b) const
  {
    auto result = matrix<T, R1, C2>{0};
    return result;
  }
};

using matrix_multiply_mpi = matrix_multiply_impl<matrix_multiply_mpi_impl>;

}  // namespace util
