#include <type_traits>
#include <vector>

namespace util
{

template <typename Arg>
struct type_wrapper
{
};

}  // namespace util

template <typename T>
auto create(util::type_wrapper<T>)
{
  return T{};
}

template <typename T>
auto create(util::type_wrapper<std::vector<T>>)
{
  auto v = std::vector<T>{};
  v.reserve(1000);
  return v;
}

template <typename T>
auto create()
{
  return create(util::type_wrapper<T>{});
}

int main()
{
  auto v = create<std::vector<int>>();
  auto i = create<int>();

  static_assert(std::is_same_v<decltype(v), std::vector<int>>);
  static_assert(std::is_same_v<decltype(i), int>);
}
