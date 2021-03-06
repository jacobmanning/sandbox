#include <boost/optional.hpp>
#include <iostream>

boost::optional<int> get_int(bool flag)
{
  if (flag)
  {
    return 1;
  }

  return {};
}

int main()
{
  if (auto maybe_int = get_int(true); maybe_int)
  {
    std::cout << "Got int: " << maybe_int.value() << std::endl;
  }

  if (auto maybe_int = get_int(false); !maybe_int)
  {
    std::cout << "No int received" << std::endl;
  }
}
