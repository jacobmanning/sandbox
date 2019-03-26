#pragma once

#include <ostream>

#include <crtp.hh>
#include <named_type.hh>

namespace traits
{

template <typename T>
struct Addable : util::crtp<T, Addable>
{
  T operator+(const T& other) const;
};

template <typename T>
struct Printable : util::crtp<T, Printable>
{
  void print(std::ostream& os) const;
};

template <typename T>
struct Incrementable : util::crtp<T, Incrementable>
{
  T& operator+=(const T& other);
};

template <typename T>
struct Multiplicable : util::crtp<T, Multiplicable>
{
  T operator*(const T& other) const;
};

template <typename T>
struct Comparable : util::crtp<T, Comparable>
{
  bool operator<(const T& other) const;
  bool operator>(const T& other) const;
  bool operator<=(const T& other) const;
  bool operator>=(const T& other) const;
  bool operator==(const T& other) const;
  bool operator!=(const T& other) const;
};

template <typename T>
struct Hashable
{
  static constexpr bool is_hashable = true;
};

#include <traits.inl>

}  // namespace traits

#include <traits_operators.inl>
