#include "engine.hh"
#include "fridge.hh"

class Fridge::FridgeImpl
{
public:
  void cool_down() {}

private:
  [[maybe_unused]] Engine engine_;
};

void Fridge::cool_down()
{
  impl_->cool_down();
}
