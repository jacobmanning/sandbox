#include "fridge.hh"

#include "engine.hh"

#include <iostream>

class Fridge::FridgeImpl
{
public:
  void cool_down()
  {
    std::cout << "Cooling down..." << '\n';
  }

private:
  Engine engine_;
};

Fridge::Fridge() : impl_{std::make_unique<Fridge::FridgeImpl>()}
{
}
Fridge::~Fridge() = default;

void Fridge::cool_down()
{
  impl_->cool_down();
}
