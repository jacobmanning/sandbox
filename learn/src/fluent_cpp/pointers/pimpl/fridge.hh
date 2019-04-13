#pragma once

#include <memory>

class Fridge
{
public:
  Fridge() = default;
  ~Fridge() = default;

  void cool_down();

private:
  class FridgeImpl;
  std::unique_ptr<FridgeImpl> impl_ = std::make_unique<FridgeImpl>();
};
