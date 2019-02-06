#pragma once

class Product
{
public:
  Product(double density);
  double get_density() const;

private:
  double density_;
};

class Material
{
public:
  Material(double max_pressure);
  double get_max_pressure() const;

private:
  double max_pressure_;
};

class Box
{
public:
  Box(double length, double width, double height, Material material);
  double get_volume() const;
  double get_area() const;
  double get_sides_surface() const;
  Material get_material() const;

private:
  double length_;
  double width_;
  double height_;
  Material material_;
};
