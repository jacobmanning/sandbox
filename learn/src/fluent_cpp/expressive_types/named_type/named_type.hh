#pragma once

#include <functional>
#include <utility>

namespace util::v1
{

template <typename T, typename Parameter>
class named_type
{
public:
  explicit named_type(const T& value);
  explicit named_type(T&& value);

  T& get();
  const T& get() const;

private:
  T value_;
};

template <typename T, typename Parameter>
class named_type_ref
{
public:
  explicit named_type_ref(T& t);

  T& get();
  const T& get() const;

private:
  std::reference_wrapper<T> t_;
};

#include "named_type_v1.inl"

}  // namespace util::v1

namespace util::v2
{

template <typename T, typename Parameter>
class named_type
{
public:
  explicit named_type(const T& value);

  template <typename T_ = T,
            typename std::enable_if_t<!std::is_reference<T_>{},
            std::nullptr_t> = nullptr>
  explicit named_type(T&& value);

  T& get();
  const T& get() const;

private:
  T value_;
};

#include "named_type_v2.inl"

}  // namespace util::v2
