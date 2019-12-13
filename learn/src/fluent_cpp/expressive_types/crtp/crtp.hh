#pragma once

namespace util
{
template <typename T, template <typename> class CRTPType>
struct crtp
{
  T& underlying();
  const T& underlying() const;

private:
  crtp() = default;
  friend CRTPType<T>;
};

#include <crtp.inl>

} // namespace util
