template <typename T>
T Addable<T>::operator+(const T& other) const
{
  return T{this->underlying().get() + other.get()};
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
