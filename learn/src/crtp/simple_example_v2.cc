#include <iostream>

template <typename Derived>
class Base
{
public:
  void my_function() const
  {
    static_cast<const Derived*>(this)->my_function();
  }
};

class FirstChild : public Base<FirstChild>
{
public:
  void my_function() const
  {
    std::cout << "FirstChild::my_function impl"
              << "\n";
  }
};

class SecondChild : public Base<SecondChild>
{
public:
  void my_function() const
  {
    std::cout << "SecondChild::my_function impl"
              << "\n";
  }
};

template <typename Derived>
void call_my_function(const Base<Derived>& base)
{
  base.my_function();
}

int main()
{
  auto fc = FirstChild();
  auto sc = SecondChild();

  call_my_function(fc);
  call_my_function(sc);
}
