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

#include <named_type_v1.inl>

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

#include <named_type_v2.inl>

}  // namespace util::v2

namespace util::v3
{

template <typename T, typename Parameter,
          template <typename> class... Skills>
class named_type :
  public Skills<named_type<T, Parameter, Skills...>>...
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

#include <named_type_v3.inl>

}  // namespace util::v3

namespace util::v4
{

template <typename T, typename Parameter,
          template <typename> class... Skills>
class named_type_impl :
  public Skills<named_type_impl<T, Parameter, Skills...>>...
{
public:
  explicit named_type_impl(const T& value);

  template <typename T_ = T,
            typename std::enable_if_t<!std::is_reference<T_>{},
            std::nullptr_t> = nullptr>
  explicit named_type_impl(T&& value);

  T& get();
  const T& get() const;

private:
  T value_;
};

#include <named_type_v4.inl>

template <typename T, typename Parameter,
          template <typename> class... Skills>
using named_type = named_type_impl<T, Parameter, Skills...>;

}  // namespace util::v4

namespace util
{
  template <typename T, typename Parameter,
            template <typename> class... Skills>
  using named_type = v3::named_type<T, Parameter, Skills...>;
}  // namespace util

