#include <circle.hh>

namespace v1
{

Radius::Radius(double value) : value_{value} {}

double Radius::get() const
{
  return value_;
}

Diameter::Diameter(double value) : value_{value} {}

double Diameter::get() const
{
  return value_;
}

Circle::Circle(Radius radius) : radius_{radius.get()} {}

Circle::Circle(Diameter diameter) : radius_{diameter.get() / 2} {}

void Circle::set_radius(double radius)
{
  radius_ = radius;
}

double Circle::get_circumference() const
{
  return 2 * PI * radius_;
}

double Circle::get_area() const
{
  return PI * radius_ * radius_;
}

}  // namespace v1

namespace v2
{

Circle::Circle(Radius radius) : radius_{radius.get()} {}

Circle::Circle(Diameter diameter) : radius_{diameter.get() / 2} {}

void Circle::set_radius(double radius)
{
  radius_ = radius;
}

double Circle::get_circumference() const
{
  return 2 * PI * radius_;
}

double Circle::get_area() const
{
  return PI * radius_ * radius_;
}

}  // namespace v2
