#pragma once

#include <matrix.hh>

namespace util
{

class matrix_multiply_mpi_impl : public matrix_multiply_impl<matrix_multiply_mpi_impl>
{
public:
  // TODO(jacobmanning)
  template <typename T, std::size_t N, std::size_t M, std::size_t P>
  matrix<T, N, P> multiply(const matrix<T, N, M>& a, [[maybe_unused]] const matrix<T, M, P>& b)
  {
    return a;
  }
};

using matrix_multiply_mpi = matrix_multiply_impl<matrix_multiply_mpi_impl>;

}  // namespace util
