#include <iostream>
#include <type_traits>

template <typename, typename = void>
struct is_incrementable : std::false_type {};

template <typename T>
struct is_incrementable<T,
  std::void_t<decltype(++std::declval<T&>())>> : std::true_type {};

template <typename T>
constexpr bool is_incrementable_v = is_incrementable<T>::value;

// Abstraction voodoo magic...

template<typename...>
using try_to_instantiate = void;

template <typename T, template<typename> class Expression, typename Attempt = void>
struct is_detected : std::false_type {};

template <typename T, template<typename> class Expression>
struct is_detected<T, Expression, try_to_instantiate<Expression<T>>> : std::true_type {};

template <typename T>
using increment_expression = decltype(++std::declval<T&>());

template <typename T>
constexpr bool is_incrementable_v2 = is_detected<T, increment_expression>::value;

// Allowing for several types in the expression

using disregard_this = void;

template <template<typename...> class Expression, typename Attempt, typename... Ts>
struct is_detected_impl : std::false_type {};

template <template<typename...> class Expression, typename... Ts>
struct is_detected_impl<Expression, try_to_instantiate<Expression<Ts...>>, Ts...> : std::true_type {};

template <template<typename...> class Expression, typename... Ts>
constexpr bool is_detected_v2 = is_detected_impl<Expression, disregard_this, Ts...>::value;

template <typename T, typename U>
using assign_expression = decltype(std::declval<T&>() = std::declval<U&>());

template <typename T, typename U>
constexpr bool is_assignable = is_detected_v2<assign_expression, T, U>;

int main() {
  static_assert(is_incrementable_v<int>);
  static_assert(!is_incrementable_v<std::string>);

  static_assert(is_incrementable_v2<int>);
  static_assert(!is_incrementable_v2<std::string>);

  static_assert(is_assignable<int, double>);
  static_assert(!is_assignable<int, std::string>);

  std::cout << std::boolalpha;
  std::cout << "is_assignable<int, double> = " << is_assignable<int, double> << std::endl;
  std::cout << "is_assignable<int, std::string> = " << is_assignable<int, std::string> << std::endl;
}
