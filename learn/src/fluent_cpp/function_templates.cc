#include <type_traits>
#include <vector>

template <typename>
struct type {};

template <typename T>
T create(type<T> /*unused*/)
{
  return T{};
}

template <typename T>
std::vector<T> create(type<std::vector<T>> /*unused*/)
{
  auto v = std::vector<T>{};
  v.reserve(1000);
  return v;
}

template <typename T>
T create()
{
  return create(type<T>{});
}

int main()
{
  auto v = create<std::vector<int>>();
  auto i = create<int>();

  static_assert(std::is_same_v<decltype(v), std::vector<int>>);
  static_assert(std::is_same_v<decltype(i), int>);
}
