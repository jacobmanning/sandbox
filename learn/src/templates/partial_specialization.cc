#include <type_traits>

// template <typename T>
// struct is_pointer : std::false_type {};
//
// template <typename T>
// struct is_pointer<T*> : std::true_type {};

// template <typename T>
// bool is_pointer_v = false;
//
// template <typename T>
// bool is_pointer_v<T*> = true;

template <typename T>
struct MyTypeImpl
{
  using type = int;
};

template <typename T>
struct MyTypeImpl<T*>
{
  using type = int*;
};

template <typename T>
using my_type = typename MyTypeImpl<T>::type;

template <typename T>
struct is_pointer_impl
{
  static constexpr bool _()
  {
    return false;
  }
};

template <typename T>
struct is_pointer_impl<T*>
{
  static constexpr bool _()
  {
    return true;
  }
};

template <typename T>
constexpr bool is_pointer(const T& /*unused*/)
{
  return is_pointer_impl<T>::_();
}

int main()
{
  auto my_int = 4;
  auto my_ptr = &my_int;

  static_assert(std::is_same_v<decltype(my_ptr), int*>);
  static_assert(!is_pointer(my_int));
  static_assert(is_pointer(my_ptr));
}
