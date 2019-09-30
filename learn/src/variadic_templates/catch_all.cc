#include <iostream>
#include <list>
#include <map>
#include <vector>

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& p) {
  out << "[" << p.first << ", " << p.second << "]";
  return out;
}

template <template <typename...> typename ContainerType, typename... Args>
void print_container(const ContainerType<Args...>& c) {
  for (const auto& v : c) {
    std::cout << v << " ";
  }
  std::cout << "\n";
}

int main() {
  auto my_vec = std::vector<double>{3.14, 8.1, 3.2, 1.0};
  print_container(my_vec);

  auto my_list = std::list<int>{1, 2, 4, 5};
  print_container(my_list);

  auto my_map = std::map<std::string, int>{{"foo", 42}, {"bar", 81}, {"baz", 4}};
  print_container(my_map);
}
