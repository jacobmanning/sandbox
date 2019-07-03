#include <iostream>
#include <string>
#include <utility>

namespace ClassMethodLooper
{

template <int N,
          template <int M, typename...> class Wrapper,
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

template <template <int M, typename...> class Wrapper,
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
          template <int M, typename...> class Wrapper,
          typename Parent,
          typename... Args>
void ClassMethodLoop(Parent* parent, Args&&... args)
{
  ClassMethodLooper::Loop<N, Wrapper, Parent, Args...>::impl(parent, std::forward<Args>(args)...);
}

class HouseCleaner
{
public:
  void clean_all(std::string_view tool)
  {
    ClassMethodLoop<4, CleanHouseWrapper>(this, std::forward<std::string_view>(tool));
  }

private:
  const std::string message_{"Cleaning house #"};

  template <int N, typename... Args>
  struct CleanHouseWrapper
  {
    void operator()(HouseCleaner* parent, std::string_view tool) const
    {
      parent->clean_house<N>(std::forward<std::string_view>(tool));
    }
  };

  template <int N>
  void clean_house(std::string_view tool) const
  {
    std::cout << message_ << N << " with " << tool << "\n";
  }
};

int main()
{
  auto cleaner = HouseCleaner();

  // Bind rvalue ref to std::string_view
  cleaner.clean_all("broom");

  // Bind rvalue ref to std::string_view
  cleaner.clean_all(std::string{"vaccuum"});

  // Bind const lvalue to std::string_view
  const auto dustpan = std::string{"dustpan"};
  cleaner.clean_all(dustpan);

  // Bind non-const lvalue to std::string_view
  auto my_tool = std::string{"running out of tools lol"};
  cleaner.clean_all(my_tool);
}
