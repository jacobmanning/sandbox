#include <cmath>
#include <iostream>

template <typename T,
          typename std::enable_if_t<!std::is_floating_point_v<T>>* = nullptr>
bool equals(const T& lhs, const T& rhs) {
// std::enable_if_t<!std::is_floating_point<T>::value, bool> equals(const T& lhs, const T& rhs) {
  return lhs == rhs;
}

template <typename T,
          typename std::enable_if_t<std::is_floating_point_v<T>>* = nullptr>
bool equals(const T& lhs, const T& rhs) {
// std::enable_if_t<std::is_floating_point<T>::value, bool> equals(const T& lhs, const T& rhs) {
  constexpr static double eps = 0.0001;
  return std::abs(lhs - rhs) < eps;
}

class DummyClass {
public:
  DummyClass() = default;
};

template <>
bool equals<DummyClass>(const DummyClass& /*lhs*/, const DummyClass& /*rhs*/) {
  std::cerr << "Tried to call equals() on DummyClass" << std::endl;
  return false;
}


int main() {
  std::cout << std::boolalpha;
  std::cout << "int: " << equals(1, 1) << std::endl;
  std::cout << "float: " << equals(2.f - 1.f, 1.f) << std::endl;

  const auto lhs = DummyClass();
  const auto rhs = DummyClass();
  const auto result = equals(lhs, rhs);
  std::cout << "DummyClass: " << result << std::endl;
}
