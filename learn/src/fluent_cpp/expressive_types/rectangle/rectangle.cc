#include "rectangle.hh"

namespace v1
{
Rectangle::Rectangle(double width, double height) : width_{width}, height_{height}
{
}

void Rectangle::set_height(double height)
{
  height_ = height;
}

void Rectangle::set_width(double width)
{
  width_ = width;
}

double Rectangle::get_area() const
{
  return width_ * height_;
}

double Rectangle::get_width() const
{
  return width_;
}

double Rectangle::get_height() const
{
  return height_;
}

} // namespace v1

namespace v2
{
Rectangle::Rectangle(Width width, Height height) : width_{width.get()}, height_{height.get()}
{
}

void Rectangle::set_height(double height)
{
  height_ = height;
}

void Rectangle::set_width(double width)
{
  width_ = width;
}

double Rectangle::get_area() const
{
  return width_ * height_;
}

double Rectangle::get_width() const
{
  return width_;
}

double Rectangle::get_height() const
{
  return height_;
}

} // namespace v2

namespace v3
{
Rectangle::Rectangle(Width width, Height height)
    : width_{width.get().get()}, height_{height.get().get()}
{
}

void Rectangle::set_height(double height)
{
  height_ = height;
}

void Rectangle::set_width(double width)
{
  width_ = width;
}

double Rectangle::get_area() const
{
  return width_ * height_;
}

double Rectangle::get_width() const
{
  return width_;
}

double Rectangle::get_height() const
{
  return height_;
}

} // namespace v3
