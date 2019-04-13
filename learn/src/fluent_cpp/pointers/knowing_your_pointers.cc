#include <memory>

struct Wood {};

class House
{
public:
  // House takes ownership of the wood
  explicit House([[maybe_unused]] std::unique_ptr<Wood> wood) :
    wood_{std::move(wood)} {};

private:
  std::unique_ptr<Wood> wood_;
};

// Should be the preferred pointer return for factory functions
std::unique_ptr<House> build_a_house()
{
  auto w = std::make_unique<Wood>();
  return std::make_unique<House>(std::move(w));
}

// You cannot modify the house you are building
std::unique_ptr<const House> build_a_const_house()
{
  auto w = std::make_unique<Wood>();
  return std::make_unique<const House>(std::move(w));
}

void moving_unique_pointers()
{
  auto p1 = std::make_unique<int>(42);
  // Now p2 holds the resource and p1 holds nothing
  auto p2 = std::move(p1);
}

// Ideally want to pass objects as const ref
void render_house([[maybe_unused]] const House& house) {};

// Raw pointers and references represent access to an object,
// but not ownership of it
void raw_pointers_and_references()
{
  auto house = build_a_house();
  render_house(*house);
}

// Weak pointers don't increment reference counts
void use_weak_pointer(std::weak_ptr<int> wp)
{
  // Need to check weak pointers to see if resource still here
  if (auto sp = wp.lock())
  {
    // Resource still here and ready to be used
  }
  else
  {
    // Resource no longer stored in pointer
  }
}

struct Shack
{
  std::weak_ptr<Shack> neighbor_;
};

void weak_ptr_to_avoid_circular_ref()
{
  auto s1 = std::make_shared<Shack>();
  auto s2 = std::make_shared<Shack>();

  s1->neighbor_ = s2;
  s2->neighbor_ = s1;
}

int main() {}
