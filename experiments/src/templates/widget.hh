#pragma once

#include <utility>

namespace util
{

template <typename T>
class widget
{
public:
  explicit widget(const T& value);
  explicit widget(T&& value);

  widget() = default;
  ~widget() = default;
  widget(const widget&) = default;
  widget(widget&&) noexcept = default;
  widget& operator=(const widget&) = default;
  widget& operator=(widget&&) noexcept = default;

  void set_value(const T& value);
  void set_value(T&& value);

  T get_value() const;
  int get_num_changes() const;

private:
  T value_{};
  int num_changes_{0};
};

#include "widget.inl"

}  // namespace util
