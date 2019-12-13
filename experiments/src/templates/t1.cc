#include "widget.hh"

#include <iostream>
#include <type_traits>

struct Nontrivial
{
  Nontrivial()
  {
    std::cout << "Nontrivial()\n";
  }

  ~Nontrivial()
  {
    std::cout << "~Nontrivial()\n";
  }
};

std::ostream& operator<<(const Nontrivial&, std::ostream& out)
{
  out << "struct Nontrivial{}\n";
  return out;
}

int main()
{
  auto w = util::widget<int>();
  w.set_value(0);

  std::cout << "w.value_ = " << w.get_value() << '\n';
  std::cout << "w.num_changes_ = " << w.get_num_changes() << '\n';

  const auto w2 = util::widget<float>(4.f);
  std::cout << "w2.value_ = " << w2.get_value() << '\n';

  auto w3 = util::widget<Nontrivial>();
  std::cout << "w3.value_ = " << w2.get_value() << '\n';
}
