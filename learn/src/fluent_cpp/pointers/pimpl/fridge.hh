#pragma once

#include <memory>

class Fridge
{
public:
  Fridge();
  ~Fridge();

  Fridge(const Fridge&) = delete;
  Fridge(Fridge&&) = default;
  Fridge& operator=(const Fridge&) = delete;
  Fridge& operator=(Fridge&&) = default;

  void cool_down();

private:
  class FridgeImpl;
  std::unique_ptr<FridgeImpl> impl_;
};
