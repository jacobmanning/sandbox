#pragma once

#include <named_type.hh>
#include <units.hh>

namespace v1
{
class Rectangle
{
public:
  Rectangle(double width, double height);

  void set_height(double height);
  void set_width(double width);

  double get_area() const;
  double get_width() const;
  double get_height() const;

private:
  double width_;
  double height_;
};

} // namespace v1

namespace v2
{
struct WidthParameter
{
};
using Width = util::v1::named_type<double, WidthParameter>;
struct HeightParameter
{
};
using Height = util::v1::named_type<double, HeightParameter>;

class Rectangle
{
public:
  Rectangle(Width /*width*/, Height /*height*/);

  void set_height(double height);
  void set_width(double width);

  double get_area() const;
  double get_width() const;
  double get_height() const;

private:
  double width_;
  double height_;
};

} // namespace v2

namespace v3
{
struct WidthParameter
{
};
using Width = util::v1::named_type<units::Meter, WidthParameter>;
struct HeightParameter
{
};
using Height = util::v1::named_type<units::Meter, HeightParameter>;

class Rectangle
{
public:
  Rectangle(Width /*width*/, Height /*height*/);

  void set_height(double height);
  void set_width(double width);

  double get_area() const;
  double get_width() const;
  double get_height() const;

private:
  double width_;
  double height_;
};

} // namespace v3
