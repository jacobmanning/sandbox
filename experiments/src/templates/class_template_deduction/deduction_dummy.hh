#pragma once

#include <utility>

namespace util
{

template <typename T,
          typename U,
          typename V,
          typename... Letters>
class deduction_dummy
{
public:

  deduction_dummy(T&& t,
                  V&& v,
                  Letters&&... l);

  deduction_dummy(T&& t,
                  U&& u,
                  V&& v,
                  Letters&&... l);

private:
  T t_;
  U u_;
  V v_;
};

template <typename T,
          typename U,
          typename V,
          typename... Letters>
deduction_dummy(T&& t,
                U&& u,
                V&& v,
                Letters&&... l)
  -> deduction_dummy<std::decay_t<T>,
                     std::decay_t<U>,
                     std::decay_t<V>,
                     std::decay_t<Letters>...>;

template <typename T,
          typename V,
          typename... Letters>
deduction_dummy(T&& t,
                V&& v,
                Letters&&... l)
  -> deduction_dummy<std::decay_t<T>,
                     bool,
                     std::decay_t<V>,
                     std::decay_t<Letters>...>;

}  // namespace util

#include "deduction_dummy.inl"
