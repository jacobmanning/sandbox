#include <iostream>
#include <named_type.hh>
#include <string>
#include <traits.hh>
#include <unordered_map>

using SerialNumber = util::named_type<std::string,
                                      struct SerialNumberTag,
                                      traits::Comparable,
                                      traits::Hashable,
                                      traits::Printable>;

using SerialNumberV2 = util::convertible_named_type<int,
                                                    struct SerialNumberTag,
                                                    traits::Comparable,
                                                    traits::Hashable,
                                                    traits::Printable>;

template <typename T, typename U>
bool contains_key(const std::unordered_map<T, U>& my_map, const T& value)
{
  return my_map.find(value) != std::end(my_map);
}

template <typename T, typename U>
void check_key_and_print(const std::unordered_map<T, U>& my_map, const T& my_key)
{
  if (contains_key(my_map, my_key))
  {
    std::cout << "Map.at(" << my_key << ") = " << my_map.at(my_key) << '\n';
  }
  else
  {
    std::cout << "Map does not contain key '" << my_key << "'\n";
  }
}

int main()
{
  const auto my_map =
      std::unordered_map<SerialNumber, int>{{SerialNumber{"AA11"}, 10}, {SerialNumber{"BB22"}, 20}};

  // Key is in map
  check_key_and_print(my_map, SerialNumber{"BB22"});
  // Key is NOT in map
  check_key_and_print(my_map, SerialNumber{"CC33"});

  const auto my_map_v2 =
      std::unordered_map<SerialNumberV2, int>{{SerialNumberV2{30}, 10}, {SerialNumberV2{40}, 20}};

  // Key is in map
  check_key_and_print(my_map_v2, SerialNumberV2{30});
  // Key is NOT in map
  check_key_and_print(my_map_v2, SerialNumberV2{50});
}
