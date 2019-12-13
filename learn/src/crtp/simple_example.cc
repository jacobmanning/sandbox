#include <iostream>

template <typename Child>
struct Base
{
  void interface()
  {
    static_cast<Child*>(this)->impl();
  }
};

struct Derived : Base<Derived>
{
  void impl()
  {
    std::cerr << "Derived implementation"
              << "\n";
  }
};

int main()
{
  auto d = Derived();
  d.interface();
}
