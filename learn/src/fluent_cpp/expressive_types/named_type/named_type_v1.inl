template <typename T, typename Parameter>
named_type<T, Parameter>::named_type(const T& value) : value_{value}
{
}

template <typename T, typename Parameter>
named_type<T, Parameter>::named_type(T&& value) : value_{std::move(value)}
{
}

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

template <typename T, typename Parameter>
named_type_ref<T, Parameter>::named_type_ref(T& t) : t_{std::ref(t)}
{
}

template <typename T, typename Parameter>
T& named_type_ref<T, Parameter>::get()
{
  return t_.get();
}

template <typename T, typename Parameter>
const T& named_type_ref<T, Parameter>::get() const
{
  return t_.get();
}
