#include <memory>

class Instructions
{
public:
  virtual std::unique_ptr<Instructions> clone() const = 0;
  virtual ~Instructions() {};
};

class Sketch : public Instructions
{
public:
  std::unique_ptr<Instructions> clone() const
  {
    return static_cast<std::unique_ptr<Instructions>>(
        std::make_unique<Sketch>(*this));
  }
};

class Blueprint : public Instructions
{
public:
  std::unique_ptr<Instructions> clone() const
  {
    return static_cast<std::unique_ptr<Instructions>>(
        std::make_unique<Blueprint>(*this));
  }
};

using InstructionsUniquePtr =
  std::unique_ptr<const Instructions, void(*)(const Instructions*)>;

auto delete_instructions = [] (const Instructions* instr) {
  delete instr;
};

auto do_not_delete_instructions = [] ([[maybe_unused]] const Instructions* instr) {};

class House
{
public:
  // explicit House(std::unique_ptr<Instructions> instructions) :
  explicit House(InstructionsUniquePtr instructions) :
    instructions_{std::move(instructions)} {};

private:
  // std::unique_ptr<Instructions> instructions_;
  InstructionsUniquePtr instructions_;
};

enum class BuildingMethod
{
  from_sketch,
  from_blueprint
};

House build_a_house(BuildingMethod method)
{
  if (method == BuildingMethod::from_sketch)
  {
    // return House(std::make_unique<Sketch>());
    return House(InstructionsUniquePtr(new Sketch, delete_instructions));
  }

  if (method == BuildingMethod::from_blueprint)
  {
    // return House(std::make_unique<Blueprint>());
    return House(InstructionsUniquePtr(new Blueprint, delete_instructions));
  }

  throw;
}

void build_with_stack_object()
{
  auto blueprint = Blueprint{};
  auto house = House(InstructionsUniquePtr(&blueprint, do_not_delete_instructions));
}

int main() {}
