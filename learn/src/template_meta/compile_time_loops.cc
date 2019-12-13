#include <iostream>
#include <string>
#include <string_view>
#include <utility>

namespace ClassMethodLooper
{
template <int N, template <int, typename...> class Wrapper, typename Object, typename... Args>
struct Loop
{
  constexpr static void impl(Object* obj_ptr, Args&&... args)
  {
    auto member_fn_wrapper = Wrapper<N, Args...>();
    member_fn_wrapper(obj_ptr, std::forward<Args>(args)...);

    Loop<N - 1, Wrapper, Object, Args...>::impl(obj_ptr, std::forward<Args>(args)...);
  }
};

template <template <int, typename...> class Wrapper, typename Object, typename... Args>
struct Loop<0, Wrapper, Object, Args...>
{
  constexpr static void impl(Object*, Args&&...)
  {
  }
};

} // namespace ClassMethodLooper

// Wrapper for looping on a non-const member function
template <int N, template <int, typename...> class Wrapper, typename Object, typename... Args>
constexpr void class_method_loop(Object* obj_ptr, Args&&... args)
{
  ClassMethodLooper::Loop<N, Wrapper, Object, Args...>::impl(obj_ptr, std::forward<Args>(args)...);
}

template <int N>
class HouseCleaner
{
public:
  template <typename... Args>
  void clean_all(Args&&... args) const
  {
    class_method_loop<N, CleanHouseWrapper>(this, std::forward<Args>(args)...);
  }

private:
  std::string message_{"Cleaning house #"};

  template <int M, typename... Args>
  struct CleanHouseWrapper
  {
    void operator()(const HouseCleaner* obj_ptr, Args&&... args) const
    {
      obj_ptr->clean_house<M>(std::forward<Args>(args)...);
    }
  };

  template <int M, typename... Args>
  void clean_house(std::string_view tool, Args&&...) const
  {
    std::cout << message_ << M << " with " << tool << '\n';
  }
};

template <int N>
class IntWrapper
{
public:
  template <typename... Args>
  void increment_n(Args&&... args)
  {
    class_method_loop<N, IncrementMutableDataMemberWrapper>(this, std::forward<Args>(args)...);
  }

private:
  template <int M, typename... Args>
  struct IncrementMutableDataMemberWrapper
  {
    void operator()(IntWrapper* obj_ptr, Args&&... args) const
    {
      obj_ptr->increment<M>(std::forward<Args>(args)...);
    }
  };

  template <int M, typename... Args>
  void increment(Args&&...)
  {
    mutable_data_member_ += M;
    std::cout << "mutable_data_member_ = " << mutable_data_member_ << '\n';
  }

  int mutable_data_member_{0};
};

int main()
{
  const auto cleaner = HouseCleaner<4>{};

  cleaner.clean_all("broom");
  cleaner.clean_all("vaccuum", 4);
  cleaner.clean_all("dustpan", 3.14, "i'm running out of tools");

  auto iw = IntWrapper<5>{};
  iw.increment_n();
}
