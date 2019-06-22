#include <iostream>

namespace util
{

template <typename T,
          typename U,
          typename V,
          typename... Letters>
deduction_dummy<T, U, V, Letters...>::
  deduction_dummy(T t,
                  V v,
                  Letters... l)
  : deduction_dummy(
      std::forward<T>(t),
      std::forward<U>(U{}),
      std::forward<V>(v),
      std::forward<Letters>(l)...)
{
  std::cerr << "Partial constructor" << '\n';
}

template <typename T,
          typename U,
          typename V,
          typename... Letters>
deduction_dummy<T, U, V, Letters...>::
  deduction_dummy(T t,
                  U u,
                  V v,
                  [[maybe_unused]] Letters... l)
  : t_{t}
  , u_{u}
  , v_{v}
{
  std::cerr << "Full constructor" << '\n';
}

}  // namespace util
