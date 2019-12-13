#include <iostream>
#include <optional>

/// std::optional makes a copy of the argument
/// std::optional explicitly disallows reference types as arguments

class MyClass
{
public:
  MyClass() : id_{0}
  {
  }
  int get_id() const
  {
    return id_;
  };
  void increment_id()
  {
    ++id_;
  }

private:
  int id_;
};

// Won't compile an optional reference
// bool maybe_increment(std::optional<MyClass>& maybe_mc) {
bool maybe_increment(std::optional<MyClass> maybe_mc)
{
  if (!maybe_mc)
  {
    return false;
  }

  (*maybe_mc).increment_id();
  return true;
}

// Won't compile an optional reference
// bool maybe_increment(std::optional<int>& maybe_my_int) {
bool maybe_increment(std::optional<int> maybe_my_int)
{
  if (!maybe_my_int)
  {
    return false;
  }

  ++(*maybe_my_int);
  return true;
}

int main()
{
  auto mc = MyClass();
  int my_int = 4;

  if (maybe_increment(mc))
  {
    std::cout << "Incremented mc" << '\n';
    std::cout << "mc.get_id() = " << mc.get_id() << '\n';
  }

  if (maybe_increment(my_int))
  {
    std::cout << "Incremented my_int" << '\n';
    std::cout << "my_int = " << my_int << '\n';
  }
}
