template <typename T,
          template <typename> class CRTPType>
T& crtp<T, CRTPType>::underlying()
{
  return static_cast<T&>(*this);
}

template <typename T,
          template <typename> class CRTPType>
const T& crtp<T, CRTPType>::underlying() const
{
  return static_cast<const T&>(*this);
}
