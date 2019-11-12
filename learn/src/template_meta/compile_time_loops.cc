#include <iostream>
#include <string>
#include <string_view>
#include <utility>

namespace ClassMethodLooper
{

template <int N,
          template <int, typename...> class Wrapper,
          typename Parent,
          typename... Args>
struct Loop
{
  static void impl(Parent* parent, Args&&... args)
  {
    auto member = Wrapper<N, Args...>();

    member(parent, std::forward<Args>(args)...);

    Loop<N-1, Wrapper, Parent, Args...>::impl(parent, std::forward<Args>(args)...);
  }
};

template <template <int, typename...> class Wrapper,
          typename Parent,
          typename... Args>
struct Loop<0, Wrapper, Parent, Args...>
{
  static void impl([[maybe_unused]] Parent* parent, [[maybe_unused]] Args&&... args)
  {
  }
};

} // namespace ClassMethodLooper

template <int N,
          template <int, typename...> class Wrapper,
          typename Parent,
          typename... Args>
void ClassMethodLoop(Parent* parent, Args&&... args)
{
  ClassMethodLooper::Loop<N, Wrapper, Parent, Args...>::impl(parent, std::forward<Args>(args)...);
}

template <int N>
class HouseCleaner
{
public:
  template <typename... Args>
  void clean_all(Args&&... args)
  {
    ClassMethodLoop<N, CleanHouseWrapper>(this, std::forward<Args>(args)...);
  }

private:
  const std::string message_{"Cleaning house #"};

  template <int M, typename... Args>
  struct CleanHouseWrapper
  {
    void operator()(HouseCleaner* parent, Args&&... args) const
    {
      parent->clean_house<M>(std::forward<Args>(args)...);
    }
  };

  template <int M, typename... Args>
  void clean_house(std::string_view tool, Args&&...) const
  {
    std::cout << message_ << M << " with " << tool << "\n";
  }
};

int main()
{
  auto cleaner = HouseCleaner<4>();

  cleaner.clean_all("broom");
  cleaner.clean_all("vaccuum", 4);
  cleaner.clean_all("dustpan", 3.14, "i'm running out of tools");
}
