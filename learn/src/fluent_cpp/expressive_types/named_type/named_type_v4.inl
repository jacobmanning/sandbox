template <typename T, typename Tag,
          typename Converter,
          template <typename> class... Skills>
named_type_impl<T, Tag, Converter, Skills...>::named_type_impl(const T& value) :
  value_{value} {}

template <typename T, typename Tag,
          typename Converter,
          template <typename> class... Skills>
template <typename T_,
          typename std::enable_if_t<!std::is_reference<T_>{},
          std::nullptr_t>>
named_type_impl<T, Tag, Converter, Skills...>::named_type_impl(T&& value) :
  value_{std::move(value)} {}

template <typename T, typename Tag,
          typename Converter,
          template <typename> class... Skills>
T& named_type_impl<T, Tag, Converter, Skills...>::get()
{
  return value_;
}

template <typename T, typename Tag,
          typename Converter,
          template <typename> class... Skills>
const T& named_type_impl<T, Tag, Converter, Skills...>::get() const
{
  return value_;
}

template <typename T, typename Tag,
          typename Converter,
          template <typename> class... Skills>
named_type_impl<T, Tag, Converter, Skills...>::operator T&()
{
  return get();
}

template <typename T, typename Tag,
          typename Converter,
          template <typename> class... Skills>
named_type_impl<T, Tag, Converter, Skills...>::operator const T&() const
{
  return get();
}

template <typename T, typename Tag,
          typename Converter,
          template <typename> class... Skills>
template <typename Converter2>
named_type_impl<T, Tag, Converter, Skills...>::operator named_type_impl<T, Tag, Converter2, Skills...>() const
{
  return named_type_impl<T, Tag, Converter2, Skills...>(Converter2::convert_from(Converter::convert_to(get())));
}
