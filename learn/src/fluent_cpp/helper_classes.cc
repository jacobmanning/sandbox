#include "helper_classes.hh"

#include <cmath>
#include <iostream>

Product::Product(double density) : density_{density} {};

double Product::get_density() const
{
  return density_;
}

Material::Material(double max_pressure) : max_pressure_{max_pressure} {};

double Material::get_max_pressure() const
{
  return max_pressure_;
}

Box::Box(double length, double width, double height, Material material)
    : length_{length}, width_{width}, height_{height}, material_{material} {};

double Box::get_volume() const
{
  return length_ * width_ * height_;
}

double Box::get_area() const
{
  return length_ * width_;
}

double Box::get_sides_surface() const
{
  // surface_area = 6a^2
  return 6 * pow(get_area(), 2);
}

Material Box::get_material() const
{
  return material_;
}
