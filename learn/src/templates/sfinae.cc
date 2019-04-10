#include <iostream>

namespace intro {

void foo(unsigned i) {
  std::cout << "unsigned " << i << "\n";
}

template <typename T>
void foo(const T& t) {
  std::cout << "template " << t << "\n";
}

}  // namespace intro

namespace motivating_example {

int negative(int i) {
  return -i;
}

// Compiler will consider all overloads,
// <int> has no `::value_type`, but it still
// has an acceptable overload with the function above
template <typename T>
typename T::value_type negative(const T& t) {
  return -T(t);
}

}  // namespace motivating_example

namespace custom {

template <bool, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {
  using type = T;
};

template <class T,
          typename enable_if<std::is_integral<T>::value, T>::type* = nullptr>
void do_stuff(T& /*unused*/) {
  std::cout << "do_stuff integral" << "\n";
}

template <class T,
          typename enable_if<std::is_class<T>::value, T>::type* = nullptr>
void do_stuff(T& /*unused*/) {
  std::cout << "do_stuff class types" << "\n";
}

class Dummy {};

template <bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;

template <class T,
          enable_if_t<std::is_integral<T>::value>* = nullptr>
void do_stuff_v2(T& /*unused*/) {
  std::cout << "do_stuff_v2 integral" << "\n";
}

template <class T,
          enable_if_t<std::is_class<T>::value>* = nullptr>
void do_stuff_v2(T& /*unused*/) {
  std::cout << "do_stuff_v2 class types" << "\n";
}

}  // namespace custom

int main() {
  intro::foo(42);

  auto x = motivating_example::negative(42);

  custom::do_stuff(x);
  auto d = custom::Dummy();
  custom::do_stuff(d);

  custom::do_stuff_v2(x);
  custom::do_stuff_v2(d);
}
