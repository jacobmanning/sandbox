#pragma once

#include <named_type.hh>

namespace v1
{

class Radius
{
public:
  explicit Radius(double value);

  double get() const;

private:
  double value_;
};

class Diameter
{
public:
  explicit Diameter(double value);

  double get() const;

private:
  double value_;
};

class Circle
{
public:
  explicit Circle(Radius radius);
  explicit Circle(Diameter radius);

  void set_radius(double radius);

  double get_circumference() const;
  double get_area() const;

private:
  constexpr static auto PI = double{3.14159};
  double radius_;
};

}  // namespace v1

namespace v2
{

struct RadiusParameter {};
using Radius = util::v1::named_type<double, struct RadiusParameter>;

struct DiameterParameter {};
using Diameter = util::v1::named_type<double, struct DiameterParameter>;

class Circle
{
public:
  explicit Circle(Radius radius);
  explicit Circle(Diameter radius);

  void set_radius(double radius);

  double get_circumference() const;
  double get_area() const;

private:
  constexpr static auto PI = double{3.14159};
  double radius_;
};

}  // namespace v1
