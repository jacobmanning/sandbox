template <typename T, typename Parameter>
named_type<T, Parameter>::named_type(const T& value) :
  value_{value} {}

template <typename T, typename Parameter>
template <typename T_,
          typename std::enable_if_t<!std::is_reference<T_>{},
          std::nullptr_t>>
named_type<T, Parameter>::named_type(T&& value) :
  value_{std::move(value)} {}

template <typename T, typename Parameter>
T& named_type<T, Parameter>::get()
{
  return value_;
}

template <typename T, typename Parameter>
const T& named_type<T, Parameter>::get() const
{
  return value_;
}
