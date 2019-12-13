#include <iostream>
#include <ostream>
#include <string>

template <typename Printable>
struct RepeatPrinter : Printable
{
  explicit RepeatPrinter(const Printable& printable) : Printable{printable}
  {
  }

  void repeat(unsigned int n) const
  {
    while (n-- > 0)
    {
      this->print();
    }
  }
};

template <typename Printable>
RepeatPrinter<Printable> make_repeat_printer(const Printable& printable)
{
  return RepeatPrinter<Printable>(printable);
}

class Name
{
public:
  Name(std::string first_name, std::string last_name)
      : first_name_{std::move(first_name)}, last_name_{std::move(last_name)}
  {
  }

  void print(std::ostream& os = std::cout) const
  {
    os << last_name_ << ", " << first_name_ << '\n';
  }

private:
  std::string first_name_;
  std::string last_name_;
};

int main()
{
  auto ned = Name{"Eddard", "Stark"};
  auto printer = make_repeat_printer(ned);
  printer.repeat(10);
}
