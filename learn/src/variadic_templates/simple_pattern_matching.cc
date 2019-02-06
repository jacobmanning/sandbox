#include <iostream>

template <typename T>
bool pair_comparer(T a) {
  std::cerr << "[INFO] " << __PRETTY_FUNCTION__ << "\n";
  return false;
}

template <typename T>
bool pair_comparer(T a, T b) {
  std::cerr << "[INFO] " << __PRETTY_FUNCTION__ << "\n";
  return a == b;
}

template <typename T, typename... Args>
bool pair_comparer(T a, T b, Args... args) {
  std::cerr << "[INFO] " << __PRETTY_FUNCTION__ << "\n";
  return a == b && pair_comparer(args...);
}

int main() {
  std::cout << std::boolalpha;

  auto result1 = pair_comparer(1.4, 1.4, false, false, 6, 6);
  std::cout << "\n" << "pair_comparer(1.4, 1.4, false, false, 6, 6) = " << result1 << "\n\n";

  auto result2 = pair_comparer("foo", "foo", false, false, 6, 7);
  std::cout << "\n" << "pair_comparer('foo', 'foo', false, false, 6, 7) = " << result2 << "\n\n";

  auto result3 = pair_comparer("x", "x", true, true, 8, 8, 1);
  std::cout << "\n" << "pair_comparer('x', 'x', true, true, 8, 8, 1) = " << result3 << "\n";
}
