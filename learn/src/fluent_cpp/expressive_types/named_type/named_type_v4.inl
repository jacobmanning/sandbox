template <typename T, typename Parameter,
          template <typename> class... Skills>
named_type_impl<T, Parameter, Skills...>::named_type_impl(const T& value) :
  value_{value} {}

template <typename T, typename Parameter,
          template <typename> class... Skills>
template <typename T_,
          typename std::enable_if_t<!std::is_reference<T_>{},
          std::nullptr_t>>
named_type_impl<T, Parameter, Skills...>::named_type_impl(T&& value) :
  value_{std::move(value)} {}

template <typename T, typename Parameter,
          template <typename> class... Skills>
T& named_type_impl<T, Parameter, Skills...>::get()
{
  return value_;
}

template <typename T, typename Parameter,
          template <typename> class... Skills>
const T& named_type_impl<T, Parameter, Skills...>::get() const
{
  return value_;
}
