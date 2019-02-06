#include <iostream>

namespace ClassMethodLooper {

template <int N,
          template <int N, typename...> class Wrapper,
          typename Parent,
          typename... Args>
struct Loop {
  static void impl(Parent* parent, Args&&... args) {
    auto member = Wrapper<N, Args...>();

    member(parent, std::forward<Args>(args)...);

    Loop<N-1, Wrapper, Parent, Args...>::impl(parent, std::forward<Args>(args)...);
  }
};

template <int N,
          template <int N, typename...> class Wrapper,
          typename Parent,
          typename... Args>
struct Loop<0, Wrapper, Parent, Args...> {
  static void impl(Parent* parent, Args&&... args) {}
};

} // namespace ClassMethodLooper

template <int N,
          template <int N, typename...> class Wrapper,
          typename Parent,
          typename... Args>
void ClassMethodLoop(Parent* parent, Args&&... args) {
  ClassMethodLooper::Loop<N, Wrapper, Parent, Args...>::impl(parent, std::forward<Args>(args)...);
}

class HouseCleaner {
public:
  void clean_all(const std::string& tool) {
    ClassMethodLoop<4, CleanHouseWrapper>(this, tool);
  }

private:
  std::string message_{"Cleaning house #"};

  template <int N>
  struct CleanHouseWrapper {
    void operator()(HouseCleaner* parent, std::string&& tool) const {
      parent->clean_house<N>(std::forward<std::string>(tool));
    }
  };

  template <int N>
  void clean_house(const std::string& tool) {
    std::cout << message_ << N << " with " << tool << "\n";
  }
};

int main() {
  // auto cleaner = std::make_unique<HouseCleaner>();
  // cleaner->clean_all("broom");
  auto cleaner = HouseCleaner();
  cleaner.clean_all("broom");
}
