#pragma once

#include <iostream>
#include <type_traits>
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

  // Return trivial types by value for `const` objects
  template <typename T_t = T, typename = std::enable_if_t<std::is_trivial_v<T_t>>>
  T get_value() const;

  // Return non-trivial types by const-ref for `const` objects
  template <typename T_t = T, typename = std::enable_if_t<!std::is_trivial_v<T_t>>>
  const T& get_value() const;

  // Return value by mutable reference for mutable objects
  T& get_value_mutable();

  int get_num_changes() const;

private:
  T value_{};
  int num_changes_{0};
};

#include "widget.inl"

} // namespace util
