#pragma once

#include <matrix.hh>

namespace util
{

class matrix_multiply_omp_impl : public matrix_multiply_impl<matrix_multiply_omp_impl>
{
public:
  template <typename T, std::size_t N, std::size_t M, std::size_t P>
  matrix<T, N, P> multiply(const matrix<T, N, M>& a, const matrix<T, M, P>& b)
  {
    auto result = matrix<T, N, P>(0);

    #pragma omp parallel for collapse(3)
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < M; ++j)
      {
        for (int k = 0; k < P; ++k)
        {
          result.at(i, j) += a.at(i, k) * b.at(k, j);
        }
      }
    }

    return result;
  }
};

using matrix_multiply_omp = matrix_multiply_impl<matrix_multiply_omp_impl>;

}  // namespace util
