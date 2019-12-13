#include <iostream>
#include <named_type.hh>
#include <string>

struct FirstNameRefParameter
{
};
using name_ref_v1 = util::v1::named_type_ref<std::string, struct FirstNameRefParameter>;
using name_ref_v2 = util::v2::named_type<std::string&, struct FirstNameRefParameter>;

void print_name(const name_ref_v1 name)
{
  std::cout << name.get() << '\n';
}

void print_name(const name_ref_v2 name)
{
  std::cout << name.get() << '\n';
}

int main()
{
  auto username = std::string{"jacob"};
  print_name(name_ref_v1{username});
  print_name(name_ref_v2{username});

  // Should NOT compile
  // print_name(name_ref_v2{"foo"});
}
