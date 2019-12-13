#include <iostream>

template <typename Derived>
struct Comparisons
{
};

template <typename Derived>
bool operator==(const Comparisons<Derived>& o1, const Comparisons<Derived>& o2)
{
  const auto& d1 = static_cast<const Derived&>(o1);
  const auto& d2 = static_cast<const Derived&>(o2);

  std::cerr << "[DEBUG] Comparsions<Derived>::operator=="
            << "\n";

  return !(d1 < d2) && !(d2 < d1);
}

template <typename Derived>
bool operator!=(const Comparisons<Derived>& o1, const Comparisons<Derived>& o2)
{
  std::cerr << "[DEBUG] Comparsions<Derived>::operator!="
            << "\n";
  return !(o1 == o2);
}

class Person : public Comparisons<Person>
{
public:
  Person(std::string name, int age) : name_{std::move(name)}, age_{age}
  {
  }

  friend bool operator<(const Person& p1, const Person& p2);

private:
  std::string name_;
  int age_;
};

bool operator<(const Person& p1, const Person& p2)
{
  std::cerr << "[DEBUG] Person::operator<"
            << "\n";
  return p1.age_ < p2.age_;
}

int main()
{
  auto jacob = Person{"Jacob", 100};
  auto other = Person{"Other", 0};

  std::cout << std::boolalpha;
  auto are_equal = jacob == other;
  std::cout << "jacob == other: " << are_equal << "\n";
  auto not_equal = jacob != other;
  std::cout << "jacob != other: " << not_equal << "\n";
}
