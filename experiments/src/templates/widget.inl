template <typename T>
widget<T>::widget(const T& value) : value_{value}
{
}

template <typename T>
widget<T>::widget(T&& value) : value_{std::move(value)}
{
}

template <typename T>
void widget<T>::set_value(const T& value)
{
  ++num_changes_;
  value_ = value;
}

template <typename T>
void widget<T>::set_value(T&& value)
{
  ++num_changes_;
  // `value` has a name so it isn't an r-value, use std::move to
  // unconditionally cast it to an r-value.
  value_ = std::move(value);
}

template <typename T>
template <typename, typename>
T widget<T>::get_value() const
{
  std::cout << "T get_value()" << '\n';
  return value_;
}

template <typename T>
template <typename, typename>
const T& widget<T>::get_value() const
{
  std::cout << "const T& get_value()" << '\n';
  return value_;
}

template <typename T>
T& widget<T>::get_value_mutable()
{
  std::cout << "T& get_value_mutable()" << '\n';
  return value_;
}

template <typename T>
int widget<T>::get_num_changes() const
{
  return num_changes_;
}
