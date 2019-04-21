#pragma once

#include <matrix.hh>

namespace util
{

struct matrix_multiply_naive_impl;

template <typename Runtime = matrix_multiply_naive_impl>
struct matrix_multiply_impl
{
  template <typename T, std::size_t R1, std::size_t S, std::size_t C2>
  matrix<T, R1, C2> multiply(const matrix<T, R1, S>& a, const matrix<T, S, C2>& b) const
  {
    return static_cast<const Runtime*>(this)->multiply(a, b);
  }

  template <typename T, std::size_t R1, std::size_t S, std::size_t C2>
  matrix<T, R1, C2> operator()(const matrix<T, R1, S>& a, const matrix<T, S, C2>& b) const
  {
    return static_cast<const Runtime*>(this)->multiply(a, b);
  }
};

struct matrix_multiply_naive_impl : matrix_multiply_impl<matrix_multiply_naive_impl>
{
  template <typename T, std::size_t R1, std::size_t S, std::size_t C2>
  matrix<T, R1, C2> multiply(const matrix<T, R1, S>& a, const matrix<T, S, C2>& b) const
  {
    auto result = matrix<T, R1, C2>{0};

    for (auto i = int{0}; i < R1; ++i)
    {
      for (auto j = int{0}; j < S; ++j)
      {
        for (auto k = int{0}; k < C2; ++k)
        {
          result.at(i, j) += a.at(i, k) * b.at(k, j);
        }
      }
    }

    return result;
  }
};

using matrix_multiply = matrix_multiply_impl<>;

}  // namespace util
