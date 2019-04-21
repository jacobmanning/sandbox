template <typename T>
widget<T>::widget(const T& value) : value_{value} {}

template <typename T>
widget<T>::widget(T&& value) : value_{std::move(value)} {}

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
  value_ = std::move(value);
}

template <typename T>
T widget<T>::get_value() const
{
  return value_;
}

template <typename T>
int widget<T>::get_num_changes() const
{
  return num_changes_;
}
