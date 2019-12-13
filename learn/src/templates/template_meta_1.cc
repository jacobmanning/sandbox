#include <iostream>
#include <type_traits>

class DummyClass
{
public:
  DummyClass() = default;

  void foo(DummyClass /*unused*/)
  {
  }
  // Also valid:
  // void foo(DummyClass&& other) {}
};

class StupidClass
{
public:
  StupidClass() = default;

  // NOTE: The template checks will still work if we only
  //       have the function declaration and not the body
  void foo(StupidClass /*unused*/)
  {
  }
  void foo(DummyClass /*unused*/)
  {
  }
  // Also valid:
  // void foo(StupidClass&& other) {}
  // void foo(DummyClass&& other) {}
};

// std::declval<T>() -> T&& for types w/o default ctor
// decltype -> returns type of the argument
template <typename T1, typename T2>
using my_test_t = decltype(std::declval<T1>().foo(std::declval<T2>())
                           // Also valid:
                           // std::declval<T1&>().foo(std::declval<T2>())
);

template <typename T1, typename T2, typename = void>
struct is_my_thing : std::false_type
{
};

template <typename T1, typename T2>
struct is_my_thing<T1, T2, std::void_t<my_test_t<T1, T2>>> : std::true_type
{
};

int main()
{
  static_assert(is_my_thing<DummyClass, DummyClass>());
  static_assert(!is_my_thing<DummyClass, StupidClass>());
  static_assert(is_my_thing<StupidClass, StupidClass>());
  static_assert(is_my_thing<StupidClass, DummyClass>());

  auto d = DummyClass();
  auto s = StupidClass();

  if (!is_my_thing<decltype(d), decltype(s)>())
  {
    std::cout << "Cannot DummyClass::foo(StupidClass);" << std::endl;
  }

  if (is_my_thing<decltype(s), decltype(d)>())
  {
    std::cout << "Can StupidClass::foo(DummyClass);" << std::endl;
    s.foo(d);
  }

  std::cout << "Woo, template meta-programming!" << std::endl;
}
