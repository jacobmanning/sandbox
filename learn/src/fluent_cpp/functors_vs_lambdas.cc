#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#include "helper_classes.hh"

class Resists
{
public:
  explicit Resists(const Product& product)
    : product_{product} {};

  bool operator()(const Box& box) {
    const double volume = box.get_volume();
    const double weight = volume * product_.get_density();
    const double sides_surface = box.get_sides_surface();
    const double pressure = weight / sides_surface;
    const double max_pressure = box.get_material().get_max_pressure();
    return pressure <= max_pressure;
  }

private:
  Product product_;
};

auto resists(const Product& product)
{
  return [product] (const Box& box)
  {
      const auto volume = box.get_volume();
      const auto weight = volume * product.get_density();
      const auto sides_surface = box.get_sides_surface();
      const auto pressure = weight / sides_surface;
      const auto max_pressure = box.get_material().get_max_pressure();
      return pressure <= max_pressure;
  };
}

int main()
{
  auto wood = Material{10};
  auto steel = Material{100};

  auto boxes = std::vector<Box>();
  boxes.emplace_back(10, 10, 10 , wood);
  boxes.emplace_back(10, 10, 10 , steel);

  auto product = Product(2.5);

  auto good_boxes_lambda = std::vector<Box>();
  std::copy_if(std::begin(boxes), std::end(boxes),
    std::back_inserter(good_boxes_lambda), resists(product));

  auto good_boxes_functor = std::vector<Box>();
  std::copy_if(std::begin(boxes), std::end(boxes),
    std::back_inserter(good_boxes_functor), Resists(product));

  // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-array-to-pointer-decay, hicpp-no-array-decay)
  assert(good_boxes_lambda.size() == good_boxes_functor.size());
  std::cout << "Both vectors are size " << good_boxes_lambda.size() << "\n";
}
