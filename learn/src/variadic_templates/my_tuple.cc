#include <iostream>

namespace custom
{
template <class... Ts>
struct Tuple
{
};

template <class T, class... Ts>
struct Tuple<T, Ts...> : Tuple<Ts...>
{
  T tail_;

  explicit Tuple(T t, Ts... ts) : Tuple<Ts...>(ts...), tail_{t}
  {
  }
};

template <std::size_t, class>
struct elem_type_holder;

template <class T, class... Ts>
struct elem_type_holder<0, Tuple<T, Ts...>>
{
  using type = T;
};

template <std::size_t k, class T, class... Ts>
struct elem_type_holder<k, Tuple<T, Ts...>>
{
  using type = typename elem_type_holder<k - 1, Tuple<Ts...>>::type;
};

template <std::size_t k, class... Ts>
typename std::enable_if_t<k == 0, typename elem_type_holder<0, Tuple<Ts...>>::type&>
get(Tuple<Ts...>& t)
{
  return t.tail_;
}

template <std::size_t k, class T, class... Ts>
typename std::enable_if_t<k != 0, typename elem_type_holder<k, Tuple<T, Ts...>>::type&>
get(Tuple<T, Ts...>& t)
{
  Tuple<Ts...>& base = t;
  return get<k - 1>(base);
}

} // namespace custom

int main()
{
  auto t1 = custom::Tuple<double, uint64_t, const char*>(12.2, 42, "big");

  std::cout << "0th elem is " << custom::get<0>(t1) << "\n";
  std::cout << "1st elem is " << custom::get<1>(t1) << "\n";
  std::cout << "2nd elem is " << custom::get<2>(t1) << "\n";

  custom::get<1>(t1) = 103;
  std::cout << "1st elem is " << custom::get<1>(t1) << "\n";
}
