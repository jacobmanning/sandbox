#include <iostream>

template <typename T>
T adder(T value) {
  std::cerr << "[INFO] " << __PRETTY_FUNCTION__ << "\n";
  return value;
}

template <typename T, typename... Args>
T adder(T value, Args... args) {
  std::cerr << "[INFO] " << __PRETTY_FUNCTION__ << "\n";
  return value + adder(args...);
}

int main() {
  long sum = adder(1, 2, 3, 8, 7);
  std::cout << "\n" << "adder(1, 2, 3, 8, 7) = " << sum << "\n\n";

  auto s1 = std::string("x");
  auto s2 = std::string("aa");
  auto s3 = std::string("bb");
  auto s4 = std::string("yy");

  auto string_sum = adder(s1, s2, s3, s4);
  std::cout << "\n" << "adder('x', 'aa', 'bb', 'yy') = " << string_sum << "\n";
}
