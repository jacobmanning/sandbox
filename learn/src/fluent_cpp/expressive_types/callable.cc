#include <algorithm>
#include <iostream>
#include <string>

#include <named_type.hh>
#include <traits.hh>

using Label =
  util::v3::named_type<std::string, struct LabelTag, traits::Callable>;

std::string just_return_my_string(const std::string& s)
{
  return s;
}

void display(const Label& label)
{
  std::cout << just_return_my_string(label) << '\n';
}

int main()
{
  auto my_label = Label{"my_label"};
  display(my_label);
}
