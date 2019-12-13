#include <array>
#include <string>
#include <type_traits>
#include <vector>

namespace
{
template <typename T>
void assert_valid_remove_reference()
{
  static_assert(std::is_same_v<T, std::remove_reference_t<T>>);
  static_assert(std::is_same_v<T, std::remove_reference_t<T&>>);
  static_assert(std::is_same_v<T, std::remove_reference_t<T&&>>);
}

} // namespace

int main()
{
  assert_valid_remove_reference<int>();
  assert_valid_remove_reference<float>();
  assert_valid_remove_reference<double>();

  assert_valid_remove_reference<std::string>();

  assert_valid_remove_reference<std::array<int, 4>>();
  assert_valid_remove_reference<std::vector<int>>();
}
