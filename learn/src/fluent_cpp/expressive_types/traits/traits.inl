template <typename T>
T Addable<T>::operator+(const T& other) const
{
  return T{this->underlying().get() + other.get()};
}

template <typename T>
T Subtractable<T>::operator-(const T& other) const
{
  return T{this->underlying().get() - other.get()};
}

template <typename T>
void Printable<T>::print(std::ostream& os) const
{
  os << this->underlying().get();
}

template <typename T>
T& Incrementable<T>::operator+=(const T& other)
{
  this->underlying().get() += other.get();
  return this->underlying();
}

template <typename T>
T Multiplicable<T>::operator*(const T& other) const
{
  return T{this->underlying().get() * other.get()};
}

template <typename T>
T Divisible<T>::operator/(const T& other) const
{
  return T{this->underlying().get() / other.get()};
}

template <typename T>
bool Comparable<T>::operator<(const T& other) const
{
  return this->underlying().get() < other.get();
}

template <typename T>
bool Comparable<T>::operator>(const T& other) const
{
  return other.get() < this->underlying().get();
}

template <typename T>
bool Comparable<T>::operator<=(const T& other) const
{
  return !(other.get() < this->underlying().get());
}

template <typename T>
bool Comparable<T>::operator>=(const T& other) const
{
  return !(*this < other);
}

template <typename T>
bool Comparable<T>::operator==(const T& other) const
{
  return !(*this < other) && !(other.get() < this->underlying().get());
}

template <typename T>
bool Comparable<T>::operator!=(const T& other) const
{
  return !(*this == other);
}

template <typename T, typename Tag,
          template <typename> class... Skills>
FunctionCallable<util::v3::named_type<T, Tag, Skills...>>::operator const T&() const
{
  return this->underlying().get();
}

template <typename T, typename Tag,
          template <typename> class... Skills>
FunctionCallable<util::v3::named_type<T, Tag, Skills...>>::operator T&()
{
  return this->underlying().get();
}

template <typename T, typename Tag,
          template <typename> class... Skills>
const T* MethodCallable<util::v3::named_type<T, Tag, Skills...>>::operator->() const
{
  return std::addressof(this->underlying().get());
}

template <typename T, typename Tag,
          template <typename> class... Skills>
T* MethodCallable<util::v3::named_type<T, Tag, Skills...>>::operator->()
{
  return std::addressof(this->underlying().get());
}

template <typename T, typename Tag,
          typename Converter,
          template <typename> class... Skills>
FunctionCallable<util::v4::named_type_impl<T, Tag, Converter, Skills...>>::operator const T&() const
{
  return this->underlying().get();
}

template <typename T, typename Tag,
          typename Converter,
          template <typename> class... Skills>
FunctionCallable<util::v4::named_type_impl<T, Tag, Converter, Skills...>>::operator T&()
{
  return this->underlying().get();
}

template <typename T, typename Tag,
          typename Converter,
          template <typename> class... Skills>
const T* MethodCallable<util::v4::named_type_impl<T, Tag, Converter, Skills...>>::operator->() const
{
  return std::addressof(this->underlying().get());
}

template <typename T, typename Tag,
          typename Converter,
          template <typename> class... Skills>
T* MethodCallable<util::v4::named_type_impl<T, Tag, Converter, Skills...>>::operator->()
{
  return std::addressof(this->underlying().get());
}
