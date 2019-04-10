#pragma once

#include <functional>
#include <ratio>
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

// NOLINTNEXTLINE(google-readability-namespace-comments)
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

// NOLINTNEXTLINE(google-readability-namespace-comments)
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

  // NOLINTNEXTLINE(hicpp-explicit-conversions,google-explicit-constructor)
  operator T&();
  // NOLINTNEXTLINE(hicpp-explicit-conversions,google-explicit-constructor)
  operator const T&() const;

private:
  T value_;
};

#include <named_type_v3.inl>

// NOLINTNEXTLINE(google-readability-namespace-comments)
}  // namespace util::v3

namespace util::v4
{

template <typename T, T (*from)(T), T(*to)(T)>
struct Convert
{
  static T convert_from(T t)
  {
    return from(t);
  }

  static T convert_to(T t)
  {
    return to(t);
  }
};

template <typename T, typename Ratio>
struct ConvertWithRatio
{
  static T convert_from(T t)
  {
    return t * Ratio::den / Ratio::num;
  }

  static T convert_to(T t)
  {
    return t * Ratio::num / Ratio::den;
  }
};

template <typename T, typename Tag,
          typename Converter,
          template <typename> class... Skills>
class named_type_impl :
  public Skills<named_type_impl<T, Tag, Converter, Skills...>>...
{
public:
  explicit named_type_impl(const T& value);

  template <typename T_ = T,
            typename std::enable_if_t<!std::is_reference<T_>{},
            std::nullptr_t> = nullptr>
  explicit named_type_impl(T&& value);

  T& get();
  const T& get() const;

  // NOLINTNEXTLINE(hicpp-explicit-conversions,google-explicit-constructor)
  operator T&();
  // NOLINTNEXTLINE(hicpp-explicit-conversions,google-explicit-constructor)
  operator const T&() const;

  using UnderlyingType = T;

  template <typename Converter2>
  // NOLINTNEXTLINE(hicpp-explicit-conversions,google-explicit-constructor)
  operator named_type_impl<T, Tag, Converter2, Skills...>() const;

  template <T(*f)(T), T(*g)(T)>
  struct compose
  {
    static T func(T t)
    {
      return f(g(t));
    }
  };

  template <typename Converter1, typename Converter2>
  using ComposeConverter =
    Convert<T,
            compose<Converter1::convert_from, Converter2::convert_from>::func,
            compose<Converter1::convert_to, Converter2::convert_to>::func>;

  template <typename Converter2>
  using GetConvertible =
    named_type_impl<T, Tag, ComposeConverter<Converter, Converter2>, Skills...>;

private:
  T value_;
};

#include <named_type_v4.inl>

template <typename T, typename Tag,
          template <typename> class... Skills>
using named_type = named_type_impl<T, Tag, ConvertWithRatio<T, std::ratio<1>>, Skills...>;

template <typename StrongType, typename Ratio>
using multiple_of = typename StrongType::template GetConvertible<
  ConvertWithRatio<typename StrongType::UnderlyingType, Ratio>>;

template <typename StrongType, typename Converter>
using convertible_to = typename StrongType::template GetConvertible<Converter>;

// NOLINTNEXTLINE(google-readability-namespace-comments)
}  // namespace util::v4

namespace util
{
  template <typename T, typename Parameter,
            template <typename> class... Skills>
  using named_type = v3::named_type<T, Parameter, Skills...>;

  template <typename T, typename Parameter,
            template <typename> class... Skills>
  using convertible_named_type = v4::named_type<T, Parameter, Skills...>;

  using v4::multiple_of;
  using v4::convertible_to;
}  // namespace util
