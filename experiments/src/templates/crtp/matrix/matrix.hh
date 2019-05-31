#pragma once

#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <type_traits>

namespace util
{

template <typename T,
          std::size_t R,
          std::size_t C,
          typename = std::enable_if_t<std::is_arithmetic_v<T>>>
class matrix
{
public:
  matrix() = default;

  explicit matrix(const T& fill_value) : matrix()
  {
    fill(fill_value);
  }

  // ~matrix() = default;
  // matrix(const matrix&) = default;
  // matrix(matrix&&) noexcept = default;
  // matrix& operator=(const matrix&) = default;
  // matrix& operator=(matrix&&) noexcept = default;

  void fill(const T& fill_value)
  {
    std::fill(std::begin(data_), std::end(data_), fill_value);
  }

  template <typename = std::enable_if_t<std::is_same_v<int, T>>>
  void fill_random(const int low = 1, const int high = 10)
  {
    auto dev = std::random_device{};
    auto rng = std::mt19937{dev()};
    auto dist = std::uniform_int_distribution<std::mt19937::result_type>(low, high);
    auto random_generator = [&rng, &dist] () { return dist(rng); };

    std::generate(std::begin(data_), std::end(data_), random_generator);
  }

  T& at(const std::size_t row, const std::size_t col)
  {
    return data_.at(C * row + col);
  }

  const T& at(const std::size_t row, const std::size_t col) const
  {
    return data_.at(C * row + col);
  }

  void print(std::ostream& os = std::cout) const
  {
    auto i = int{0};

    std::for_each(std::begin(data_), std::end(data_), [&i, &os] (auto& elem) {
      os << elem << ' ';
      // Print newline after C elements
      if (++i % C == 0) { os << '\n'; }
    });
  }

private:
  std::array<T, R * C> data_;
};

}  // namespace util
