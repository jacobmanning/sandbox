#include <iostream>
#include <type_traits>

template <typename T>
class MyClass
{
public:
  void f([[maybe_unused]] const T& x)
  {
    std::cout << "f(const T&)" << '\n';
  }

  template <typename T_ = T, typename = std::enable_if_t<!std::is_reference_v<T_>>>
  void f([[maybe_unused]] T&& x)
  {
    std::cout << "f(T&&)" << '\n';
  }
};

using MyClassOnRef = MyClass<int&>;
using MyClassOnValue = MyClass<int>;

int main()
{
  auto x = MyClassOnRef{};
  auto y = MyClassOnValue{};

  auto i = int{0};
  x.f(i);

  y.f(4);
}
