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
struct Subtractable : util::crtp<T, Subtractable>
{
  T operator-(const T& other) const;
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
struct Divisible : util::crtp<T, Divisible>
{
  T operator/(const T& other) const;
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

template <typename NamedType_>
struct FunctionCallable;

template <typename NamedType_>
struct MethodCallable;

template <typename T, typename Tag,
          template <typename> class... Skills>
struct FunctionCallable<util::v3::named_type<T, Tag, Skills...>> :
  util::crtp<util::v3::named_type<T, Tag, Skills...>, FunctionCallable>
{

  operator const T&() const;
  operator T&();
};

template <typename T, typename Tag,
          template <typename> class... Skills>
struct MethodCallable<util::v3::named_type<T, Tag, Skills...>> :
  util::crtp<util::v3::named_type<T, Tag, Skills...>, MethodCallable>
{
  const T* operator->() const;
  T* operator->();
};

template <typename T, typename Tag,
          typename Converter,
          template <typename> class... Skills>
struct FunctionCallable<util::v4::named_type_impl<T, Tag, Converter, Skills...>> :
  util::crtp<util::v4::named_type_impl<T, Tag, Converter, Skills...>, FunctionCallable>
{

  operator const T&() const;
  operator T&();
};

template <typename T, typename Tag,
          typename Converter,
          template <typename> class... Skills>
struct MethodCallable<util::v4::named_type_impl<T, Tag, Converter, Skills...>> :
  util::crtp<util::v4::named_type_impl<T, Tag, Converter, Skills...>, MethodCallable>
{
  const T* operator->() const;
  T* operator->();
};

template <typename NamedType_>
struct Callable : FunctionCallable<NamedType_>, MethodCallable<NamedType_>
{
};

#include <traits.inl>

}  // namespace traits

#include <traits_operators.inl>
