#pragma once

#include <array>
#include <algorithm>
#include <iostream>
#include <random>
#include <type_traits>

namespace util
{

template <typename T,
          std::size_t N,
          std::size_t M,
          typename = std::enable_if_t<std::is_arithmetic_v<T>>>
class matrix
{
public:
  matrix() = default;

  explicit matrix(const T& fill_value) : matrix()
  {
    fill(fill_value);
  }

  ~matrix() = default;

  matrix(const matrix&) = default;
  matrix(matrix&&) noexcept= default;
  matrix& operator=(const matrix&) = default;
  matrix& operator=(matrix&&) noexcept= default;

  void fill(const T& fill_value)
  {
    std::fill(std::begin(data_), std::end(data_), fill_value);
  }

  template <typename T_ = T,
            typename = std::enable_if_t<std::is_same_v<int, T_>>>
  void fill_random()
  {
    std::random_device dev{};
    auto rng = std::mt19937{dev()};
    auto dist = std::uniform_int_distribution<std::mt19937::result_type>(1, 10);

    for (int i = 0; i < num_rows_; ++i)
    {
      for (int j = 0; j < num_cols_; ++j)
      {
        at(i, j) = dist(rng);
      }
    }
  }

  T& at(const std::size_t row, const std::size_t col)
  {
    return data_.at(num_cols_ * row + col);
  }

  const T& at(const std::size_t row, const std::size_t col) const
  {
    return data_.at(num_cols_ * row + col);
  }

  void print(std::ostream& os = std::cout)
  {
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < M; ++j)
      {
        os << at(i, j) << ' ';
      }

      os << '\n';
    }
  }

private:
  std::size_t num_rows_ = N;
  std::size_t num_cols_ = M;
  std::array<T, N * M> data_;
};

}  // namespace util
