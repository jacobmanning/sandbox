#include <iostream>

#include "widget.hh"

int main()
{
  auto w = util::widget<int>();
  w.set_value(0);

  std::cout << "w.value_ = " << w.get_value() << '\n';
  std::cout << "w.num_changes_ = " << w.get_num_changes() << '\n';

  auto w2 = util::widget<float>(4.f);
  std::cout << "w2.value_ = " << w2.get_value() << '\n';
}
